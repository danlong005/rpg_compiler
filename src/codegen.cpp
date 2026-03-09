#include "codegen.h"
#include <iomanip>
#include <algorithm>

namespace rpg {

std::string CodeGen::generate(Program& program) {
    out_.str("");
    indent_ = 1;
    in_procedure_ = false;
    program.accept(*this);
    return out_.str();
}

void CodeGen::emitIndent() {
    for (int i = 0; i < indent_; i++) out_ << "    ";
}

std::string CodeGen::emitExpr(Expression& expr) {
    expr_.str("");
    expr.accept(*this);
    return expr_.str();
}

static std::string stripOuterParens(const std::string& s) {
    if (s.size() >= 2 && s.front() == '(' && s.back() == ')') {
        int depth = 0;
        for (size_t i = 0; i < s.size(); i++) {
            if (s[i] == '(') depth++;
            else if (s[i] == ')') depth--;
            if (depth == 0 && i < s.size() - 1) return s;
        }
        return s.substr(1, s.size() - 2);
    }
    return s;
}

void CodeGen::emitStatements(std::vector<std::unique_ptr<Statement>>& stmts) {
    for (auto& s : stmts) {
        s->accept(*this);
    }
}

std::string CodeGen::typeToString(RPGType type, int /*length*/) {
    switch (type) {
        case RPGType::CHAR: return "std::string";
        case RPGType::VARCHAR: return "std::string";
        case RPGType::INT10: return "int";
        case RPGType::PACKED:
        case RPGType::ZONED: return "double";
        case RPGType::IND: return "bool";
        case RPGType::DATE: return "RpgDate";
        case RPGType::TIME: return "RpgTime";
        case RPGType::TIMESTAMP: return "RpgTimestamp";
        case RPGType::POINTER: return "void*";
        case RPGType::UNS: return "unsigned int";
        case RPGType::FLOAT4: return "float";
        case RPGType::FLOAT8: return "double";
        case RPGType::BINDEC: return "int";
        case RPGType::UCS2: return "std::string";
        case RPGType::OBJECT: return "void*";
    }
    return "int";
}

std::string CodeGen::paramTypeToString(const ParamDecl& p) {
    std::string base;
    if (!p.likeds.empty()) {
        // LIKEDS parameter: use the struct type name
        base = p.likeds + "_t";
    } else {
        base = typeToString(p.type, p.length);
    }
    if (p.by_value) {
        return base;
    } else {
        return base + "&";
    }
}

void CodeGen::visit(Program& node) {
    // Store date/time format settings
    datfmt_ = node.datfmt;
    timfmt_ = node.timfmt;

    out_ << "#include \"rpg_runtime.h\"\n";
    out_ << "#include <algorithm>\n";
    out_ << "#include <array>\n";
    out_ << "#include <cmath>\n";
    out_ << "#include <iostream>\n";
    out_ << "#include <string>\n";

    // Emit date/time format configuration if non-default
    if (!datfmt_.empty()) {
        out_ << "static const std::string RPG_DATFMT = \"" << datfmt_ << "\";\n";
    }
    if (!timfmt_.empty()) {
        out_ << "static const std::string RPG_TIMFMT = \"" << timfmt_ << "\";\n";
    }

    // Categorize statements into DS definitions, procs/prototypes, and main body
    std::vector<Statement*> ds_stmts;
    std::vector<Statement*> main_stmts;
    std::vector<Statement*> proc_stmts;
    std::vector<Statement*> export_decls; // EXPORT/IMPORT vars go at file scope

    for (auto& stmt : node.statements) {
        if (dynamic_cast<DclProc*>(stmt.get()) || dynamic_cast<DclPR*>(stmt.get())) {
            proc_stmts.push_back(stmt.get());
        } else if (dynamic_cast<DclDS*>(stmt.get())) {
            ds_stmts.push_back(stmt.get());
        } else {
            // Check if this is an EXPORT or IMPORT DclS — goes at file scope
            auto* dcls = dynamic_cast<DclS*>(stmt.get());
            if (dcls && (dcls->is_export || dcls->is_import)) {
                export_decls.push_back(stmt.get());
            } else {
                main_stmts.push_back(stmt.get());
            }
        }
    }

    // Emit DS struct definitions at file scope (needed for procedure params)
    indent_ = 0;
    for (auto* s : ds_stmts) {
        s->accept(*this);
    }

    // Emit EXPORT/IMPORT declarations at file scope
    for (auto* s : export_decls) {
        s->accept(*this);
    }

    // Emit prototypes and procedures
    for (auto* s : proc_stmts) {
        s->accept(*this);
    }

    // NOMAIN: no main() function
    if (node.nomain) {
        return;
    }

    // MAIN(procname): emit a main() that calls the named procedure
    if (!node.main_proc.empty()) {
        out_ << "int main() {\n";
        out_ << "    " << node.main_proc << "();\n";
        out_ << "    return 0;\n";
        out_ << "}\n";
        return;
    }

    // Emit main
    out_ << "int main() {\n";
    out_ << "    bool rpg_indicators[100] = {};\n";
    indent_ = 1;

    // Emit DS instance declarations in main
    for (auto* s : ds_stmts) {
        auto* ds = dynamic_cast<DclDS*>(s);
        std::string type_name = ds->like_ds.empty() ? ds->name + "_t" : ds->like_ds + "_t";
        emitIndent();
        if (ds->dim > 0) {
            out_ << "std::array<" << type_name << ", " << ds->dim << "> " << ds->name << ";\n";
        } else {
            out_ << type_name << " " << ds->name << ";\n";
        }
    }

    // Separate declarations, subroutines, and executable statements
    std::vector<Statement*> decl_stmts;
    std::vector<Statement*> sr_stmts;   // subroutines (lambdas, emit before use)
    std::vector<Statement*> exec_stmts;
    Statement* inzsr_stmt = nullptr;
    for (auto* s : main_stmts) {
        auto* bsr = dynamic_cast<BegSR*>(s);
        if (bsr && bsr->name == "*INZSR") {
            inzsr_stmt = s;
        } else if (bsr) {
            sr_stmts.push_back(s);
        } else if (dynamic_cast<DclS*>(s) || dynamic_cast<DclC*>(s) || dynamic_cast<DclF*>(s)) {
            decl_stmts.push_back(s);
        } else {
            exec_stmts.push_back(s);
        }
    }

    // 1. Emit declarations
    for (auto* s : decl_stmts) {
        s->accept(*this);
    }

    // 2. Emit subroutine lambdas (so they can be called later)
    for (auto* s : sr_stmts) {
        s->accept(*this);
    }

    // 3. Emit *INZSR and auto-call it
    if (inzsr_stmt) {
        inzsr_stmt->accept(*this);
        emitIndent();
        out_ << "sr__INZSR();\n";
    }

    // 4. Emit remaining executable statements
    for (auto* s : exec_stmts) {
        s->accept(*this);
    }
    out_ << "}\n";
}

void CodeGen::visit(DclPR& node) {
    bool has_nopass = std::any_of(node.interface.params.begin(), node.interface.params.end(),
                                  [](const ParamDecl& p) { return p.nopass; });
    if (has_nopass) {
        nopass_procs_.insert(node.name);
        nopass_proc_params_[node.name] = node.interface.params;
    }

    // Determine the C++ function name
    std::string cppName = node.name;
    if (!node.extproc.empty()) {
        cppName = node.extproc;
        // Track the mapping: RPG name → C++ name
        extproc_map_[node.name] = node.extproc;
    } else if (!node.extpgm.empty()) {
        cppName = node.extpgm;
        extproc_map_[node.name] = node.extpgm;
    }

    // Emit C++ forward declaration
    std::string ret = node.interface.has_return
        ? typeToString(node.interface.return_type) : "void";
    out_ << ret << " " << cppName << "(";
    for (size_t i = 0; i < node.interface.params.size(); i++) {
        if (i > 0) out_ << ", ";
        out_ << paramTypeToString(node.interface.params[i])
             << " " << node.interface.params[i].name;
        if (node.interface.params[i].nopass) {
            out_ << " = " << paramTypeDefault(node.interface.params[i]);
        }
    }
    if (has_nopass) {
        out_ << ", int _rpg_parms = " << countRequiredParams(node.interface.params);
    }
    out_ << ");\n";
    if (!node.extpgm.empty()) {
        out_ << "// EXTPGM: " << node.name << " → " << node.extpgm << "\n";
    }
}

void CodeGen::visit(DclProc& node) {
    bool has_nopass = std::any_of(node.interface.params.begin(), node.interface.params.end(),
                                  [](const ParamDecl& p) { return p.nopass; });

    std::string ret = node.interface.has_return
        ? typeToString(node.interface.return_type) : "void";
    out_ << ret << " " << node.name << "(";
    for (size_t i = 0; i < node.interface.params.size(); i++) {
        if (i > 0) out_ << ", ";
        out_ << paramTypeToString(node.interface.params[i])
             << " " << node.interface.params[i].name;
        // Don't emit default values here - they go in the prototype (DclPR)
    }
    if (has_nopass) {
        out_ << ", int _rpg_parms";
    }
    out_ << ") {\n";
    indent_ = 1;
    in_procedure_ = true;
    current_proc_parm_count_ = static_cast<int>(node.interface.params.size());
    has_nopass_params_ = has_nopass;
    current_proc_name_ = node.name;
    if (has_nopass) {
        nopass_procs_.insert(node.name);
    }

    if (!node.on_exit_body.empty()) {
        // Emit declarations first, then scope guard, then executable statements
        for (auto& s : node.body) {
            if (dynamic_cast<DclS*>(s.get()) || dynamic_cast<DclC*>(s.get()) || dynamic_cast<DclDS*>(s.get())) {
                s->accept(*this);
            }
        }
        emitIndent();
        out_ << "auto _on_exit_fn = rpg_make_scope_guard([&]() {\n";
        indent_++;
        emitStatements(node.on_exit_body);
        indent_--;
        emitIndent();
        out_ << "});\n";
        for (auto& s : node.body) {
            if (!dynamic_cast<DclS*>(s.get()) && !dynamic_cast<DclC*>(s.get()) && !dynamic_cast<DclDS*>(s.get())) {
                s->accept(*this);
            }
        }
    } else {
        emitStatements(node.body);
    }
    in_procedure_ = false;
    current_proc_parm_count_ = 0;
    has_nopass_params_ = false;
    current_proc_name_.clear();
    out_ << "}\n";
}

void CodeGen::visit(ExprStmt& node) {
    emitIndent();
    out_ << emitExpr(*node.expr) << ";\n";
}

void CodeGen::visit(DclF& node) {
    emitIndent();
    out_ << "// DCL-F " << node.name << " " << node.usage << " (file I/O not yet implemented)\n";
}

void CodeGen::visit(DclC& node) {
    emitIndent();
    // Determine type from value expression
    if (dynamic_cast<StringLiteral*>(node.value.get())) {
        out_ << "const std::string " << node.name << " = " << emitExpr(*node.value) << ";\n";
    } else if (dynamic_cast<FloatLiteral*>(node.value.get())) {
        out_ << "constexpr double " << node.name << " = " << emitExpr(*node.value) << ";\n";
    } else {
        out_ << "constexpr int " << node.name << " = " << emitExpr(*node.value) << ";\n";
    }
}

void CodeGen::visit(DclS& node) {
    // Track variable info for RESET/CLEAR
    var_types_[node.name] = node.type;
    var_lengths_[node.name] = node.length;
    if (node.inz_value) has_inz_.insert(node.name);
    if (node.dim > 0) array_vars_.insert(node.name);

    // TEMPLATE: skip emission (type definition only, no variable)
    if (node.is_template) return;

    // IMPORT: emit as extern declaration
    if (node.is_import) {
        emitIndent();
        out_ << "extern " << typeToString(node.type, node.length) << " " << node.name << ";\n";
        return;
    }

    // Handle LIKE - resolve type from referenced variable
    if (!node.like_var.empty()) {
        auto it = var_types_.find(node.like_var);
        if (it != var_types_.end()) {
            var_types_[node.name] = it->second;
            var_lengths_[node.name] = var_lengths_[node.like_var];
            emitIndent();
            std::string cppType = typeToString(it->second, var_lengths_[node.like_var]);
            if (node.is_static) out_ << "static ";
            out_ << cppType << " " << node.name;
            switch (it->second) {
                case RPGType::INT10: out_ << " = 0"; break;
                case RPGType::PACKED: case RPGType::ZONED: out_ << " = 0.0"; break;
                default: break;
            }
            out_ << ";\n";
            return;
        }
    }

    // Handle BASED(pointer) — reference via pointer
    if (!node.based_ptr.empty()) {
        emitIndent();
        out_ << typeToString(node.type, node.length) << "& " << node.name
             << " = *reinterpret_cast<" << typeToString(node.type, node.length)
             << "*>(" << node.based_ptr << ");\n";
        return;
    }

    emitIndent();
    // Emit static keyword if needed
    if (node.is_static) out_ << "static ";
    // Handle DIM arrays
    if (node.dim > 0) {
        out_ << "std::array<" << typeToString(node.type, node.length) << ", " << node.dim << "> " << node.name << ";\n";
        return;
    }
    switch (node.type) {
        case RPGType::CHAR:
            if (node.is_const) {
                out_ << "const std::string " << node.name << " = " << emitExpr(*node.inz_value) << ";\n";
            } else if (node.inz_value) {
                out_ << "std::string " << node.name << " = " << emitExpr(*node.inz_value) << ";\n";
            } else {
                out_ << "std::string " << node.name << "(" << node.length << ", ' ');\n";
            }
            break;
        case RPGType::VARCHAR:
            if (node.inz_value) {
                out_ << "std::string " << node.name << " = " << emitExpr(*node.inz_value) << ";\n";
            } else {
                out_ << "std::string " << node.name << ";\n";
            }
            break;
        case RPGType::INT10:
            if (node.is_const) {
                out_ << "const int " << node.name << " = " << emitExpr(*node.inz_value) << ";\n";
            } else if (node.inz_value) {
                out_ << "int " << node.name << " = " << emitExpr(*node.inz_value) << ";\n";
            } else {
                out_ << "int " << node.name << " = 0;\n";
            }
            break;
        case RPGType::PACKED:
        case RPGType::ZONED:
            if (node.is_const) {
                out_ << "const double " << node.name << " = " << emitExpr(*node.inz_value) << ";\n";
            } else if (node.inz_value) {
                out_ << "double " << node.name << " = " << emitExpr(*node.inz_value) << ";\n";
            } else {
                out_ << "double " << node.name << " = 0.0;\n";
            }
            break;
        case RPGType::IND:
            out_ << "bool " << node.name << " = false;\n";
            break;
        case RPGType::DATE:
            out_ << "RpgDate " << node.name << ";\n";
            break;
        case RPGType::TIME:
            out_ << "RpgTime " << node.name << ";\n";
            break;
        case RPGType::TIMESTAMP:
            out_ << "RpgTimestamp " << node.name << ";\n";
            break;
        case RPGType::POINTER:
            out_ << "void* " << node.name << " = nullptr;\n";
            break;
        case RPGType::UNS:
            if (node.inz_value) {
                out_ << "unsigned int " << node.name << " = " << emitExpr(*node.inz_value) << ";\n";
            } else {
                out_ << "unsigned int " << node.name << " = 0;\n";
            }
            break;
        case RPGType::FLOAT4:
            if (node.inz_value) {
                out_ << "float " << node.name << " = " << emitExpr(*node.inz_value) << ";\n";
            } else {
                out_ << "float " << node.name << " = 0.0f;\n";
            }
            break;
        case RPGType::FLOAT8:
            if (node.inz_value) {
                out_ << "double " << node.name << " = " << emitExpr(*node.inz_value) << ";\n";
            } else {
                out_ << "double " << node.name << " = 0.0;\n";
            }
            break;
        case RPGType::BINDEC:
            if (node.inz_value) {
                out_ << "int " << node.name << " = " << emitExpr(*node.inz_value) << ";\n";
            } else {
                out_ << "int " << node.name << " = 0;\n";
            }
            break;
        case RPGType::UCS2:
            if (node.inz_value) {
                out_ << "std::string " << node.name << " = " << emitExpr(*node.inz_value) << ";\n";
            } else {
                out_ << "std::string " << node.name << ";\n";
            }
            break;
        case RPGType::OBJECT:
            out_ << "void* " << node.name << " = nullptr; // OBJECT(*JAVA:'" << node.java_class << "')\n";
            break;
    }
    // Emit shadow variable for RESET support if INZ was specified
    if (node.inz_value) {
        emitIndent();
        out_ << "const auto _init_" << node.name << " = " << node.name << ";\n";
    }
}

std::string CodeGen::figConstValue(const std::string& name, RPGType type, const std::string& var_name) {
    if (name == "RPG_BLANKS") {
        if (type == RPGType::CHAR) {
            auto it = var_lengths_.find(var_name);
            if (it != var_lengths_.end() && it->second > 0)
                return "std::string(" + std::to_string(it->second) + ", ' ')";
            return "\"\"";
        }
        if (type == RPGType::VARCHAR) return "\"\"";
        return "0";
    } else if (name == "RPG_ZEROS") {
        if (type == RPGType::CHAR || type == RPGType::VARCHAR) return "\"\"";
        if (type == RPGType::PACKED || type == RPGType::ZONED) return "0.0";
        return "0";
    } else if (name == "RPG_HIVAL") {
        if (type == RPGType::INT10) return "INT_MAX";
        if (type == RPGType::PACKED || type == RPGType::ZONED) return "DBL_MAX";
        return "std::string(9999, '\\xFF')";
    } else if (name == "RPG_LOVAL") {
        if (type == RPGType::INT10) return "INT_MIN";
        if (type == RPGType::PACKED || type == RPGType::ZONED) return "-DBL_MAX";
        return "\"\"";
    }
    return "";
}

void CodeGen::visit(EvalStmt& node) {
    emitIndent();
    std::string target_str = emitExpr(*node.target);

    // Check for *ALL'x' on RHS
    auto* rhs_bif = dynamic_cast<BIFCall*>(node.value.get());
    if (rhs_bif && rhs_bif->name == "ALL" && !rhs_bif->args.empty()) {
        auto* tgt_id = dynamic_cast<Identifier*>(node.target.get());
        int len = 50; // default
        if (tgt_id && var_lengths_.count(tgt_id->name)) {
            len = var_lengths_[tgt_id->name];
        }
        auto* sl = dynamic_cast<StringLiteral*>(rhs_bif->args[0].get());
        if (sl) {
            out_ << target_str << " = rpg_all(\"" << sl->value << "\", " << len << ");";
        } else {
            out_ << target_str << " = rpg_all(" << emitExpr(*rhs_bif->args[0]) << ", " << len << ");";
        }
        if (node.line > 0) out_ << " // line " << node.line;
        out_ << "\n";
        return;
    }

    // Check for figurative constant on RHS
    auto* rhs_id = dynamic_cast<Identifier*>(node.value.get());
    if (rhs_id) {
        std::string var_name;
        RPGType ttype = RPGType::INT10;
        auto* tgt_id = dynamic_cast<Identifier*>(node.target.get());
        if (tgt_id && var_types_.count(tgt_id->name)) {
            ttype = var_types_[tgt_id->name];
            var_name = tgt_id->name;
        }
        std::string fc = figConstValue(rhs_id->name, ttype, var_name);
        if (!fc.empty()) {
            out_ << target_str << " = " << fc << ";";
            if (node.line > 0) out_ << " // line " << node.line;
            out_ << "\n";
            return;
        }
    }

    out_ << target_str << " = " << emitExpr(*node.value) << ";";
    if (node.line > 0) out_ << " // line " << node.line;
    out_ << "\n";
}

void CodeGen::visit(DsplyStmt& node) {
    emitIndent();
    out_ << "std::cout << " << emitExpr(*node.expr) << " << std::endl;\n";
}

void CodeGen::visit(ReturnStmt& node) {
    emitIndent();
    if (node.has_expr) {
        out_ << "return " << emitExpr(*node.expr) << ";\n";
    } else {
        out_ << "return " << node.code << ";\n";
    }
}

void CodeGen::visit(IfStmt& node) {
    emitIndent();
    out_ << "if (" << stripOuterParens(emitExpr(*node.condition)) << ") {\n";
    indent_++;
    emitStatements(node.then_body);
    indent_--;
    for (auto& branch : node.elseif_branches) {
        emitIndent();
        out_ << "} else if (" << stripOuterParens(emitExpr(*branch.condition)) << ") {\n";
        indent_++;
        emitStatements(branch.body);
        indent_--;
    }
    if (!node.else_body.empty()) {
        emitIndent();
        out_ << "} else {\n";
        indent_++;
        emitStatements(node.else_body);
        indent_--;
    }
    emitIndent();
    out_ << "}\n";
}

void CodeGen::visit(DowStmt& node) {
    emitIndent();
    out_ << "while (" << stripOuterParens(emitExpr(*node.condition)) << ") {\n";
    indent_++;
    emitStatements(node.body);
    indent_--;
    emitIndent();
    out_ << "}\n";
}

void CodeGen::visit(DouStmt& node) {
    emitIndent();
    out_ << "do {\n";
    indent_++;
    emitStatements(node.body);
    indent_--;
    emitIndent();
    out_ << "} while (!(" << stripOuterParens(emitExpr(*node.condition)) << "));\n";
}

void CodeGen::visit(ForStmt& node) {
    emitIndent();
    std::string var = node.var;
    std::string start_val = emitExpr(*node.start);
    std::string end_val = emitExpr(*node.end);
    std::string by_val = node.by ? emitExpr(*node.by) : "1";

    if (node.downto) {
        out_ << "for (" << var << " = " << start_val << "; "
             << var << " >= " << end_val << "; "
             << var << " -= " << by_val << ") {\n";
    } else {
        out_ << "for (" << var << " = " << start_val << "; "
             << var << " <= " << end_val << "; "
             << var << " += " << by_val << ") {\n";
    }
    indent_++;
    emitStatements(node.body);
    indent_--;
    emitIndent();
    out_ << "}\n";
}

void CodeGen::visit(SelectStmt& node) {
    for (size_t i = 0; i < node.when_branches.size(); i++) {
        emitIndent();
        if (i == 0) {
            out_ << "if (" << stripOuterParens(emitExpr(*node.when_branches[i].condition)) << ") {\n";
        } else {
            out_ << "} else if (" << stripOuterParens(emitExpr(*node.when_branches[i].condition)) << ") {\n";
        }
        indent_++;
        emitStatements(node.when_branches[i].body);
        indent_--;
    }
    if (!node.other_body.empty()) {
        emitIndent();
        out_ << "} else {\n";
        indent_++;
        emitStatements(node.other_body);
        indent_--;
    }
    emitIndent();
    out_ << "}\n";
}

void CodeGen::visit(IterStmt&) {
    emitIndent();
    out_ << "continue;\n";
}

void CodeGen::visit(LeaveStmt&) {
    emitIndent();
    out_ << "break;\n";
}

std::string CodeGen::fieldTypeDefault(RPGType type, int length) {
    switch (type) {
        case RPGType::INT10: return "0";
        case RPGType::CHAR: return "std::string(" + std::to_string(length) + ", ' ')";
        case RPGType::VARCHAR: return "\"\"";
        case RPGType::PACKED:
        case RPGType::ZONED: return "0.0";
        case RPGType::IND: return "false";
        case RPGType::DATE: return "RpgDate{}";
        case RPGType::TIME: return "RpgTime{}";
        case RPGType::TIMESTAMP: return "RpgTimestamp{}";
        case RPGType::POINTER: return "nullptr";
        case RPGType::UNS: return "0u";
        case RPGType::FLOAT4: return "0.0f";
        case RPGType::FLOAT8: return "0.0";
        case RPGType::BINDEC: return "0";
        case RPGType::UCS2: return "\"\"";
        case RPGType::OBJECT: return "nullptr";
    }
    return "0";
}

void CodeGen::visit(DclDS& node) {
    // Store for LIKEDS lookup
    ds_defs_[node.name] = &node;
    if (node.dim > 0) array_vars_.insert(node.name);

    if (!node.like_ds.empty()) {
        // LIKEDS: no struct to emit, just store reference
        return;
    }

    if (!node.extname.empty()) {
        // EXTNAME: externally described DS (stub)
        out_ << "struct " << node.name << "_t { /* EXTNAME(" << node.extname << ") - fields from file */ };\n";
        return;
    }

    // Emit struct definition at file scope
    out_ << "struct " << node.name << "_t {\n";
    for (auto& f : node.fields) {
        out_ << "    " << typeToString(f.type, f.length) << " " << f.name;
        // Default init
        if (f.type == RPGType::INT10) out_ << " = 0";
        else if (f.type == RPGType::PACKED || f.type == RPGType::ZONED) out_ << " = 0.0";
        out_ << ";\n";
    }
    out_ << "};\n";
}

void CodeGen::visit(DotExpr& node) {
    // Check if object is a FuncCall — treat as array(idx).field
    auto* fc = dynamic_cast<FuncCall*>(node.object.get());
    if (fc && fc->args.size() == 1) {
        expr_ << fc->name << "[";
        fc->args[0]->accept(*this);
        expr_ << " - 1]." << node.field;
    } else {
        node.object->accept(*this);
        expr_ << "." << node.field;
    }
}

void CodeGen::visit(ArrayAccess& node) {
    expr_ << node.name << "[";
    node.index->accept(*this);
    expr_ << " - 1]";  // RPG arrays are 1-based
}

void CodeGen::visit(MonitorStmt& node) {
    emitIndent();
    out_ << "try {\n";
    indent_++;
    emitStatements(node.try_body);
    indent_--;
    emitIndent();
    out_ << "} catch (...) {\n";
    indent_++;
    emitStatements(node.on_error_body);
    indent_--;
    emitIndent();
    out_ << "}\n";
}

static std::string sanitizeSRName(const std::string& name) {
    std::string result;
    for (char c : name) {
        result += (c == '*') ? '_' : c;
    }
    return result;
}

void CodeGen::visit(BegSR& node) {
    // Emit as a lambda that can be called by EXSR
    emitIndent();
    out_ << "auto sr_" << sanitizeSRName(node.name) << " = [&]() {\n";
    indent_++;
    emitStatements(node.body);
    indent_--;
    emitIndent();
    out_ << "};\n";
}

void CodeGen::visit(ExSR& node) {
    emitIndent();
    out_ << "sr_" << sanitizeSRName(node.name) << "();\n";
}

void CodeGen::visit(ResetStmt& node) {
    emitIndent();
    if (has_inz_.count(node.var_name)) {
        out_ << node.var_name << " = _init_" << node.var_name << ";\n";
    } else {
        // No INZ — reset to type default
        auto it = var_types_.find(node.var_name);
        if (it != var_types_.end()) {
            out_ << node.var_name << " = " << fieldTypeDefault(it->second, var_lengths_[node.var_name]) << ";\n";
        }
    }
}

void CodeGen::visit(ClearStmt& node) {
    emitIndent();
    auto it = var_types_.find(node.var_name);
    if (it != var_types_.end()) {
        switch (it->second) {
            case RPGType::INT10: out_ << node.var_name << " = 0;\n"; break;
            case RPGType::PACKED:
            case RPGType::ZONED: out_ << node.var_name << " = 0.0;\n"; break;
            case RPGType::CHAR:
            case RPGType::VARCHAR: out_ << node.var_name << " = \"\";\n"; break;
            case RPGType::IND: out_ << node.var_name << " = false;\n"; break;
            case RPGType::DATE: out_ << node.var_name << " = RpgDate{};\n"; break;
            case RPGType::TIME: out_ << node.var_name << " = RpgTime{};\n"; break;
            case RPGType::TIMESTAMP: out_ << node.var_name << " = RpgTimestamp{};\n"; break;
            case RPGType::POINTER: out_ << node.var_name << " = nullptr;\n"; break;
        }
    }
}

void CodeGen::visit(IndicatorExpr& node) {
    uses_indicators_ = true;
    expr_ << "rpg_indicators[" << node.number << "]";
}

void CodeGen::visit(Identifier& node) {
    expr_ << node.name;
}

void CodeGen::visit(IntLiteral& node) {
    expr_ << node.value;
}

void CodeGen::visit(FloatLiteral& node) {
    // Use enough precision to preserve the literal value
    std::ostringstream tmp;
    tmp << std::fixed << std::setprecision(10) << node.value;
    std::string s = tmp.str();
    // Trim trailing zeros but keep at least one decimal
    auto dot = s.find('.');
    if (dot != std::string::npos) {
        auto last = s.find_last_not_of('0');
        if (last == dot) last++; // keep at least one digit after dot
        s = s.substr(0, last + 1);
    }
    expr_ << s;
}

void CodeGen::visit(StringLiteral& node) {
    expr_ << "\"" << node.value << "\"";
}

void CodeGen::visit(BinaryExpr& node) {
    expr_ << "(";
    node.left->accept(*this);
    switch (node.op) {
        case BinOp::ADD: expr_ << " + "; break;
        case BinOp::SUB: expr_ << " - "; break;
        case BinOp::MUL: expr_ << " * "; break;
        case BinOp::DIV: expr_ << " / "; break;
        case BinOp::EQ:  expr_ << " == "; break;
        case BinOp::NE:  expr_ << " != "; break;
        case BinOp::LT:  expr_ << " < "; break;
        case BinOp::GT:  expr_ << " > "; break;
        case BinOp::LE:  expr_ << " <= "; break;
        case BinOp::GE:  expr_ << " >= "; break;
        case BinOp::AND: expr_ << " && "; break;
        case BinOp::OR:  expr_ << " || "; break;
    }
    node.right->accept(*this);
    expr_ << ")";
}

void CodeGen::visit(NotExpr& node) {
    expr_ << "!(";
    node.operand->accept(*this);
    expr_ << ")";
}

void CodeGen::visit(FuncCall& node) {
    // Check if this is actually an array access
    if (array_vars_.count(node.name) && node.args.size() == 1) {
        expr_ << node.name << "[";
        node.args[0]->accept(*this);
        expr_ << " - 1]";
        return;
    }
    // Resolve EXTPROC/EXTPGM name mapping
    std::string callName = node.name;
    auto eit = extproc_map_.find(node.name);
    if (eit != extproc_map_.end()) callName = eit->second;
    expr_ << callName << "(";
    for (size_t i = 0; i < node.args.size(); i++) {
        if (i > 0) expr_ << ", ";
        node.args[i]->accept(*this);
    }
    // If this function has NOPASS params, fill defaults for skipped params and append parm count
    if (nopass_procs_.count(node.name)) {
        auto it = nopass_proc_params_.find(node.name);
        if (it != nopass_proc_params_.end()) {
            for (size_t i = node.args.size(); i < it->second.size(); i++) {
                expr_ << ", " << paramTypeDefault(it->second[i]);
            }
        }
        expr_ << ", " << node.args.size();
    }
    expr_ << ")";
}

void CodeGen::visit(BIFCall& node) {
    if (node.name == "CHAR") {
        // Check if arg is a date/time variable and DATFMT/TIMFMT is set
        auto* arg_id = dynamic_cast<Identifier*>(node.args[0].get());
        bool is_date_var = false, is_time_var = false;
        if (arg_id) {
            auto vit = var_types_.find(arg_id->name);
            if (vit != var_types_.end()) {
                if (vit->second == RPGType::DATE) is_date_var = true;
                if (vit->second == RPGType::TIME) is_time_var = true;
            }
        }
        if (is_date_var && !datfmt_.empty()) {
            expr_ << "rpg_to_char(";
            node.args[0]->accept(*this);
            expr_ << ", RPG_DATFMT)";
        } else if (is_time_var && !timfmt_.empty()) {
            expr_ << "rpg_to_char(";
            node.args[0]->accept(*this);
            expr_ << ", RPG_TIMFMT)";
        } else {
            expr_ << "rpg_to_char(";
            node.args[0]->accept(*this);
            expr_ << ")";
        }
    } else if (node.name == "TRIM") {
        expr_ << "rpg_trim(";
        node.args[0]->accept(*this);
        expr_ << ")";
    } else if (node.name == "TRIML") {
        expr_ << "rpg_triml(";
        node.args[0]->accept(*this);
        expr_ << ")";
    } else if (node.name == "TRIMR") {
        expr_ << "rpg_trimr(";
        node.args[0]->accept(*this);
        expr_ << ")";
    } else if (node.name == "LEN") {
        expr_ << "static_cast<int>(";
        node.args[0]->accept(*this);
        expr_ << ".size())";
    } else if (node.name == "SUBST") {
        node.args[0]->accept(*this);
        expr_ << ".substr(";
        node.args[1]->accept(*this);
        expr_ << " - 1";
        if (node.args.size() > 2) {
            expr_ << ", ";
            node.args[2]->accept(*this);
        }
        expr_ << ")";
    } else if (node.name == "SCAN") {
        // %SCAN(needle : haystack) → returns 1-based position
        expr_ << "rpg_scan(";
        node.args[0]->accept(*this);
        expr_ << ", ";
        node.args[1]->accept(*this);
        if (node.args.size() > 2) {
            expr_ << ", ";
            node.args[2]->accept(*this);
        }
        expr_ << ")";
    } else if (node.name == "SCANRPL") {
        // %SCANRPL(find : replace : string)
        expr_ << "rpg_scanrpl(";
        node.args[0]->accept(*this);
        expr_ << ", ";
        node.args[1]->accept(*this);
        expr_ << ", ";
        node.args[2]->accept(*this);
        expr_ << ")";
    } else if (node.name == "XLATE") {
        // %XLATE(from : to : string)
        expr_ << "rpg_xlate(";
        node.args[0]->accept(*this);
        expr_ << ", ";
        node.args[1]->accept(*this);
        expr_ << ", ";
        node.args[2]->accept(*this);
        expr_ << ")";
    } else if (node.name == "DEC") {
        // %DEC(expr) → convert to double
        expr_ << "static_cast<double>(";
        node.args[0]->accept(*this);
        expr_ << ")";
    } else if (node.name == "INT") {
        // %INT(expr) → convert to int
        expr_ << "static_cast<int>(";
        node.args[0]->accept(*this);
        expr_ << ")";
    } else if (node.name == "ELEM") {
        // %ELEM(array) → array size
        expr_ << "static_cast<int>(";
        node.args[0]->accept(*this);
        expr_ << ".size())";
    } else if (node.name == "MAX") {
        if (node.args.size() == 2) {
            expr_ << "std::max(";
            node.args[0]->accept(*this);
            expr_ << ", ";
            node.args[1]->accept(*this);
            expr_ << ")";
        } else {
            expr_ << "std::max({";
            for (size_t i = 0; i < node.args.size(); i++) {
                if (i > 0) expr_ << ", ";
                node.args[i]->accept(*this);
            }
            expr_ << "})";
        }
    } else if (node.name == "MIN") {
        if (node.args.size() == 2) {
            expr_ << "std::min(";
            node.args[0]->accept(*this);
            expr_ << ", ";
            node.args[1]->accept(*this);
            expr_ << ")";
        } else {
            expr_ << "std::min({";
            for (size_t i = 0; i < node.args.size(); i++) {
                if (i > 0) expr_ << ", ";
                node.args[i]->accept(*this);
            }
            expr_ << "})";
        }
    } else if (node.name == "STATUS") {
        expr_ << "rpg_status()";
    } else if (node.name == "ERROR") {
        expr_ << "rpg_error()";
    } else if (node.name == "PARMS") {
        if (has_nopass_params_) {
            expr_ << "_rpg_parms";
        } else {
            expr_ << current_proc_parm_count_;
        }
    } else if (node.name == "SIZE") {
        expr_ << "static_cast<int>(sizeof(";
        node.args[0]->accept(*this);
        expr_ << "))";
    } else if (node.name == "ADDR") {
        expr_ << "static_cast<void*>(&";
        node.args[0]->accept(*this);
        expr_ << ")";
    } else if (node.name == "ABS") {
        expr_ << "std::abs(";
        node.args[0]->accept(*this);
        expr_ << ")";
    } else if (node.name == "DIV") {
        expr_ << "(";
        node.args[0]->accept(*this);
        expr_ << " / ";
        node.args[1]->accept(*this);
        expr_ << ")";
    } else if (node.name == "REM") {
        expr_ << "(";
        node.args[0]->accept(*this);
        expr_ << " % ";
        node.args[1]->accept(*this);
        expr_ << ")";
    } else if (node.name == "DATE") {
        if (node.args.empty()) {
            expr_ << "rpg_current_date()";
        } else {
            expr_ << "rpg_make_date(";
            node.args[0]->accept(*this);
            expr_ << ")";
        }
    } else if (node.name == "TIME") {
        if (node.args.empty()) {
            expr_ << "rpg_current_time()";
        } else {
            expr_ << "rpg_make_time(";
            node.args[0]->accept(*this);
            expr_ << ")";
        }
    } else if (node.name == "TIMESTAMP") {
        if (node.args.empty()) {
            expr_ << "rpg_current_timestamp()";
        } else {
            expr_ << "rpg_make_timestamp(";
            node.args[0]->accept(*this);
            expr_ << ")";
        }
    } else if (node.name == "DIFF") {
        // args: date1, date2, unit_string
        auto unit = dynamic_cast<StringLiteral*>(node.args[2].get());
        std::string func = "rpg_diff_days";
        if (unit && unit->value == "MONTHS") func = "rpg_diff_months";
        else if (unit && unit->value == "YEARS") func = "rpg_diff_years";
        else if (unit && unit->value == "HOURS") func = "rpg_diff_hours";
        else if (unit && unit->value == "MINUTES") func = "rpg_diff_minutes";
        else if (unit && unit->value == "SECONDS") func = "rpg_diff_seconds";
        expr_ << func << "(";
        node.args[0]->accept(*this);
        expr_ << ", ";
        node.args[1]->accept(*this);
        expr_ << ")";
    } else if (node.name == "DAYS") {
        expr_ << "RpgDuration{";
        node.args[0]->accept(*this);
        expr_ << ", 'D'}";
    } else if (node.name == "MONTHS") {
        expr_ << "RpgDuration{";
        node.args[0]->accept(*this);
        expr_ << ", 'M'}";
    } else if (node.name == "YEARS") {
        expr_ << "RpgDuration{";
        node.args[0]->accept(*this);
        expr_ << ", 'Y'}";
    } else if (node.name == "LOWER") {
        expr_ << "rpg_lower(";
        node.args[0]->accept(*this);
        expr_ << ")";
    } else if (node.name == "UPPER") {
        expr_ << "rpg_upper(";
        node.args[0]->accept(*this);
        expr_ << ")";
    } else if (node.name == "SUBDT") {
        // %SUBDT(date : unit) — extract part
        auto unit = dynamic_cast<StringLiteral*>(node.args[1].get());
        std::string func = "rpg_subdt_days";
        if (unit && unit->value == "YEARS") func = "rpg_subdt_years";
        else if (unit && unit->value == "MONTHS") func = "rpg_subdt_months";
        else if (unit && unit->value == "HOURS") func = "rpg_subdt_hours";
        else if (unit && unit->value == "MINUTES") func = "rpg_subdt_minutes";
        else if (unit && unit->value == "SECONDS") func = "rpg_subdt_seconds";
        expr_ << func << "(";
        node.args[0]->accept(*this);
        expr_ << ")";
    } else if (node.name == "FLOAT") {
        expr_ << "static_cast<double>(";
        node.args[0]->accept(*this);
        expr_ << ")";
    } else if (node.name == "SQRT") {
        expr_ << "std::sqrt(static_cast<double>(";
        node.args[0]->accept(*this);
        expr_ << "))";
    } else if (node.name == "CHECK") {
        // %CHECK(comparator : base {: start})
        expr_ << "rpg_check(";
        node.args[0]->accept(*this);
        expr_ << ", ";
        node.args[1]->accept(*this);
        if (node.args.size() > 2) {
            expr_ << ", ";
            node.args[2]->accept(*this);
        }
        expr_ << ")";
    } else if (node.name == "CHECKR") {
        // %CHECKR(comparator : base {: start})
        expr_ << "rpg_checkr(";
        node.args[0]->accept(*this);
        expr_ << ", ";
        node.args[1]->accept(*this);
        if (node.args.size() > 2) {
            expr_ << ", ";
            node.args[2]->accept(*this);
        }
        expr_ << ")";
    } else if (node.name == "REPLACE") {
        // %REPLACE(new : source : start {: length})
        expr_ << "rpg_replace(";
        node.args[0]->accept(*this);
        expr_ << ", ";
        node.args[1]->accept(*this);
        expr_ << ", ";
        node.args[2]->accept(*this);
        if (node.args.size() > 3) {
            expr_ << ", ";
            node.args[3]->accept(*this);
        }
        expr_ << ")";
    } else if (node.name == "EDITC") {
        // %EDITC(number : editcode)
        expr_ << "rpg_editc(";
        node.args[0]->accept(*this);
        expr_ << ", ";
        node.args[1]->accept(*this);
        expr_ << ")";
    } else if (node.name == "EDITW") {
        // %EDITW(number : editword)
        expr_ << "rpg_editw(";
        node.args[0]->accept(*this);
        expr_ << ", ";
        node.args[1]->accept(*this);
        expr_ << ")";
    } else if (node.name == "LOOKUP") {
        // %LOOKUP(arg : array) → 1-based index, 0 if not found
        expr_ << "rpg_lookup(";
        node.args[0]->accept(*this);
        expr_ << ", ";
        node.args[1]->accept(*this);
        expr_ << ")";
    } else if (node.name == "ALLOC") {
        expr_ << "std::malloc(";
        node.args[0]->accept(*this);
        expr_ << ")";
    } else if (node.name == "REALLOC") {
        expr_ << "std::realloc(";
        node.args[0]->accept(*this);
        expr_ << ", ";
        node.args[1]->accept(*this);
        expr_ << ")";
    } else if (node.name == "XFOOT") {
        expr_ << "rpg_xfoot(";
        node.args[0]->accept(*this);
        expr_ << ")";
    } else if (node.name == "UNS") {
        expr_ << "static_cast<unsigned int>(";
        node.args[0]->accept(*this);
        expr_ << ")";
    } else if (node.name == "INTH") {
        expr_ << "static_cast<int>(std::round(static_cast<double>(";
        node.args[0]->accept(*this);
        expr_ << ")))";
    } else if (node.name == "DECH") {
        // %DECH(expr:digits:decimals) — round to decimals then cast
        expr_ << "rpg_dech(";
        node.args[0]->accept(*this);
        if (node.args.size() > 2) {
            expr_ << ", ";
            node.args[2]->accept(*this);
        } else {
            expr_ << ", 0";
        }
        expr_ << ")";
    } else if (node.name == "DECPOS") {
        expr_ << "rpg_decpos(";
        node.args[0]->accept(*this);
        expr_ << ")";
    } else if (node.name == "SPLIT") {
        expr_ << "rpg_split(";
        node.args[0]->accept(*this);
        if (node.args.size() > 1) {
            expr_ << ", ";
            node.args[1]->accept(*this);
        }
        expr_ << ")";
    } else if (node.name == "CONCATARR") {
        expr_ << "rpg_concatarr(";
        node.args[0]->accept(*this);
        expr_ << ", ";
        node.args[1]->accept(*this);
        expr_ << ")";
    } else if (node.name == "LEFT") {
        node.args[0]->accept(*this);
        expr_ << ".substr(0, ";
        node.args[1]->accept(*this);
        expr_ << ")";
    } else if (node.name == "RIGHT") {
        expr_ << "rpg_right(";
        node.args[0]->accept(*this);
        expr_ << ", ";
        node.args[1]->accept(*this);
        expr_ << ")";
    } else if (node.name == "STR") {
        expr_ << "rpg_str(";
        node.args[0]->accept(*this);
        if (node.args.size() > 1) {
            expr_ << ", ";
            node.args[1]->accept(*this);
        }
        expr_ << ")";
    } else if (node.name == "SUBARR") {
        expr_ << "rpg_subarr(";
        node.args[0]->accept(*this);
        expr_ << ", ";
        node.args[1]->accept(*this);
        if (node.args.size() > 2) {
            expr_ << ", ";
            node.args[2]->accept(*this);
        }
        expr_ << ")";
    } else if (node.name == "MAXARR") {
        expr_ << "rpg_maxarr(";
        node.args[0]->accept(*this);
        expr_ << ")";
    } else if (node.name == "MINARR") {
        expr_ << "rpg_minarr(";
        node.args[0]->accept(*this);
        expr_ << ")";
    } else if (node.name == "LIST") {
        // %LIST(v1:v2:...) → initializer list — emits as rpg_list(...)
        expr_ << "rpg_list(";
        for (size_t i = 0; i < node.args.size(); i++) {
            if (i > 0) expr_ << ", ";
            node.args[i]->accept(*this);
        }
        expr_ << ")";
    } else if (node.name == "RANGE") {
        expr_ << "rpg_range(";
        node.args[0]->accept(*this);
        expr_ << ", ";
        node.args[1]->accept(*this);
        expr_ << ")";
    } else if (node.name == "LOOKUPLT") {
        expr_ << "rpg_lookup_lt(";
        node.args[0]->accept(*this);
        expr_ << ", ";
        node.args[1]->accept(*this);
        expr_ << ")";
    } else if (node.name == "LOOKUPGE") {
        expr_ << "rpg_lookup_ge(";
        node.args[0]->accept(*this);
        expr_ << ", ";
        node.args[1]->accept(*this);
        expr_ << ")";
    } else if (node.name == "LOOKUPLE") {
        expr_ << "rpg_lookup_le(";
        node.args[0]->accept(*this);
        expr_ << ", ";
        node.args[1]->accept(*this);
        expr_ << ")";
    } else if (node.name == "LOOKUPGT") {
        expr_ << "rpg_lookup_gt(";
        node.args[0]->accept(*this);
        expr_ << ", ";
        node.args[1]->accept(*this);
        expr_ << ")";
    } else if (node.name == "HOURS") {
        expr_ << "RpgDuration{";
        node.args[0]->accept(*this);
        expr_ << ", 'H'}";
    } else if (node.name == "MINUTES") {
        expr_ << "RpgDuration{";
        node.args[0]->accept(*this);
        expr_ << ", 'I'}";
    } else if (node.name == "SECONDS") {
        expr_ << "RpgDuration{";
        node.args[0]->accept(*this);
        expr_ << ", 'S'}";
    } else if (node.name == "MSECONDS") {
        expr_ << "RpgDuration{";
        node.args[0]->accept(*this);
        expr_ << ", 'U'}";
    } else if (node.name == "PADDR") {
        auto* sl = dynamic_cast<StringLiteral*>(node.args[0].get());
        if (sl) {
            expr_ << "reinterpret_cast<void*>(&" << sl->value << ")";
        } else {
            expr_ << "reinterpret_cast<void*>(&";
            node.args[0]->accept(*this);
            expr_ << ")";
        }
    } else if (node.name == "PROC") {
        if (!current_proc_name_.empty()) {
            expr_ << "std::string(\"" << current_proc_name_ << "\")";
        } else {
            expr_ << "std::string(\"main\")";
        }
    } else if (node.name == "ALL") {
        // Will be resolved in EvalStmt context; for now emit rpg_all helper
        auto* sl = dynamic_cast<StringLiteral*>(node.args[0].get());
        if (sl) {
            expr_ << "rpg_all(\"" << sl->value << "\")";
        } else {
            expr_ << "rpg_all(";
            node.args[0]->accept(*this);
            expr_ << ")";
        }
    } else if (node.name == "PASSED") {
        // %PASSED(parmname) — check if optional param was passed
        // Find the param position in the current proc's param list
        auto* arg_id = dynamic_cast<Identifier*>(node.args[0].get());
        if (arg_id && !current_proc_name_.empty()) {
            auto pit = nopass_proc_params_.find(current_proc_name_);
            if (pit != nopass_proc_params_.end()) {
                int pos = 0;
                for (size_t i = 0; i < pit->second.size(); i++) {
                    if (pit->second[i].name == arg_id->name) {
                        pos = static_cast<int>(i) + 1;
                        break;
                    }
                }
                expr_ << "(_rpg_parms >= " << pos << ")";
            } else {
                expr_ << "true";
            }
        } else {
            expr_ << "true";
        }
    } else if (node.name == "OMITTED") {
        // %OMITTED(parmname) — opposite of %PASSED
        auto* arg_id = dynamic_cast<Identifier*>(node.args[0].get());
        if (arg_id && !current_proc_name_.empty()) {
            auto pit = nopass_proc_params_.find(current_proc_name_);
            if (pit != nopass_proc_params_.end()) {
                int pos = 0;
                for (size_t i = 0; i < pit->second.size(); i++) {
                    if (pit->second[i].name == arg_id->name) {
                        pos = static_cast<int>(i) + 1;
                        break;
                    }
                }
                expr_ << "(_rpg_parms < " << pos << ")";
            } else {
                expr_ << "false";
            }
        } else {
            expr_ << "false";
        }
    } else if (node.name == "OCCUR") {
        // %OCCUR(dsname) — get/set current occurrence of multiple-occurrence DS
        if (node.args.size() == 1) {
            expr_ << "rpg_get_occur(";
            node.args[0]->accept(*this);
            expr_ << ")";
        } else {
            // Set occurrence: %OCCUR(ds : n)
            expr_ << "rpg_set_occur(";
            node.args[0]->accept(*this);
            expr_ << ", ";
            node.args[1]->accept(*this);
            expr_ << ")";
        }
    } else if (node.name == "FOUND") {
        expr_ << "rpg_found()";
    } else if (node.name == "EOF") {
        expr_ << "rpg_eof()";
    } else {
        expr_ << "/* unknown BIF: %" << node.name << " */";
    }
}

void CodeGen::visit(EvalRStmt& node) {
    // Right-adjust: pad left with spaces
    emitIndent();
    std::string target = emitExpr(*node.target);
    std::string value = emitExpr(*node.value);
    out_ << target << " = rpg_evalr(" << target << ", " << value << ");\n";
}

void CodeGen::visit(LeaveSRStmt& node) {
    (void)node;
    emitIndent();
    out_ << "return;\n";
}

void CodeGen::visit(EvalCorrStmt& node) {
    // Find both DS definitions and emit assignments for matching field names
    auto tit = ds_defs_.find(node.target);
    auto sit = ds_defs_.find(node.source);
    if (tit != ds_defs_.end() && sit != ds_defs_.end()) {
        DclDS* tds = tit->second;
        DclDS* sds = sit->second;
        for (auto& tf : tds->fields) {
            for (auto& sf : sds->fields) {
                if (tf.name == sf.name) {
                    emitIndent();
                    out_ << node.target << "." << tf.name << " = "
                         << node.source << "." << sf.name << ";\n";
                    break;
                }
            }
        }
    }
}

void CodeGen::visit(SortAStmt& node) {
    emitIndent();
    out_ << "std::sort(" << node.array_name << ".begin(), " << node.array_name << ".end());\n";
}

void CodeGen::visit(DeallocStmt& node) {
    emitIndent();
    out_ << "std::free(" << node.var_name << ");\n";
    emitIndent();
    out_ << node.var_name << " = nullptr;\n";
}

void CodeGen::visit(TestStmt& node) {
    emitIndent();
    out_ << "rpg_error_flag() = !rpg_test_";
    switch (node.type) {
        case 'D': out_ << "date"; break;
        case 'T': out_ << "time"; break;
        case 'Z': out_ << "timestamp"; break;
    }
    out_ << "(" << node.var_name << ");\n";
}

std::string CodeGen::paramTypeDefault(const ParamDecl& p) {
    if (!p.likeds.empty()) return p.likeds + "_t{}";
    switch (p.type) {
        case RPGType::CHAR:
        case RPGType::VARCHAR: return "std::string()";
        case RPGType::INT10: return "0";
        case RPGType::PACKED:
        case RPGType::ZONED: return "0.0";
        case RPGType::IND: return "false";
        default: return "{}";
    }
}

int CodeGen::countRequiredParams(const std::vector<ParamDecl>& params) {
    int count = 0;
    for (auto& p : params) {
        if (!p.nopass) count++;
    }
    return count;
}

void CodeGen::visit(ForEachStmt& node) {
    emitIndent();
    std::string coll = emitExpr(*node.collection);
    out_ << "for (auto& " << node.var << " : " << coll << ") {\n";
    indent_++;
    emitStatements(node.body);
    indent_--;
    emitIndent();
    out_ << "}\n";
}

void CodeGen::visit(InExpr& node) {
    auto* bif = dynamic_cast<BIFCall*>(node.collection.get());
    if (bif && bif->name == "LIST") {
        expr_ << "rpg_in_list(";
        node.value->accept(*this);
        expr_ << ", rpg_list(";
        for (size_t i = 0; i < bif->args.size(); i++) {
            if (i > 0) expr_ << ", ";
            bif->args[i]->accept(*this);
        }
        expr_ << "))";
    } else if (bif && bif->name == "RANGE") {
        expr_ << "rpg_in_range(";
        node.value->accept(*this);
        expr_ << ", rpg_range(";
        bif->args[0]->accept(*this);
        expr_ << ", ";
        bif->args[1]->accept(*this);
        expr_ << "))";
    } else {
        // Generic: assume collection is iterable
        expr_ << "rpg_in_list(";
        node.value->accept(*this);
        expr_ << ", ";
        node.collection->accept(*this);
        expr_ << ")";
    }
}

} // namespace rpg
