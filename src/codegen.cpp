#include "codegen.h"
#include <iomanip>

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
    out_ << "#include \"rpg_runtime.h\"\n";
    out_ << "#include <algorithm>\n";
    out_ << "#include <array>\n";
    out_ << "#include <cmath>\n";
    out_ << "#include <iostream>\n";
    out_ << "#include <string>\n";

    // Categorize statements into DS definitions, procs/prototypes, and main body
    std::vector<Statement*> ds_stmts;
    std::vector<Statement*> main_stmts;
    std::vector<Statement*> proc_stmts;

    for (auto& stmt : node.statements) {
        if (dynamic_cast<DclProc*>(stmt.get()) || dynamic_cast<DclPR*>(stmt.get())) {
            proc_stmts.push_back(stmt.get());
        } else if (dynamic_cast<DclDS*>(stmt.get())) {
            ds_stmts.push_back(stmt.get());
        } else {
            main_stmts.push_back(stmt.get());
        }
    }

    // Emit DS struct definitions at file scope (needed for procedure params)
    indent_ = 0;
    for (auto* s : ds_stmts) {
        s->accept(*this);
    }

    // Emit prototypes and procedures
    for (auto* s : proc_stmts) {
        s->accept(*this);
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

    for (auto* s : main_stmts) {
        s->accept(*this);
    }
    out_ << "}\n";
}

void CodeGen::visit(DclPR& node) {
    // Emit C++ forward declaration
    std::string ret = node.interface.has_return
        ? typeToString(node.interface.return_type) : "void";
    out_ << ret << " " << node.name << "(";
    for (size_t i = 0; i < node.interface.params.size(); i++) {
        if (i > 0) out_ << ", ";
        out_ << paramTypeToString(node.interface.params[i])
             << " " << node.interface.params[i].name;
    }
    out_ << ");\n";
}

void CodeGen::visit(DclProc& node) {
    std::string ret = node.interface.has_return
        ? typeToString(node.interface.return_type) : "void";
    out_ << ret << " " << node.name << "(";
    for (size_t i = 0; i < node.interface.params.size(); i++) {
        if (i > 0) out_ << ", ";
        out_ << paramTypeToString(node.interface.params[i])
             << " " << node.interface.params[i].name;
    }
    out_ << ") {\n";
    indent_ = 1;
    in_procedure_ = true;
    current_proc_parm_count_ = static_cast<int>(node.interface.params.size());
    emitStatements(node.body);
    in_procedure_ = false;
    current_proc_parm_count_ = 0;
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

    // Handle LIKE - resolve type from referenced variable
    if (!node.like_var.empty()) {
        auto it = var_types_.find(node.like_var);
        if (it != var_types_.end()) {
            var_types_[node.name] = it->second;
            var_lengths_[node.name] = var_lengths_[node.like_var];
            emitIndent();
            std::string cppType = typeToString(it->second, var_lengths_[node.like_var]);
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

    emitIndent();
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
    }
    // Emit shadow variable for RESET support if INZ was specified
    if (node.inz_value) {
        emitIndent();
        out_ << "const auto _init_" << node.name << " = " << node.name << ";\n";
    }
}

void CodeGen::visit(EvalStmt& node) {
    emitIndent();
    out_ << emitExpr(*node.target) << " = " << emitExpr(*node.value) << ";";
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

void CodeGen::visit(BegSR& node) {
    // Emit as a lambda that can be called by EXSR
    emitIndent();
    out_ << "auto sr_" << node.name << " = [&]() {\n";
    indent_++;
    emitStatements(node.body);
    indent_--;
    emitIndent();
    out_ << "};\n";
}

void CodeGen::visit(ExSR& node) {
    emitIndent();
    out_ << "sr_" << node.name << "();\n";
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
    expr_ << std::fixed << std::setprecision(2) << node.value;
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
    expr_ << node.name << "(";
    for (size_t i = 0; i < node.args.size(); i++) {
        if (i > 0) expr_ << ", ";
        node.args[i]->accept(*this);
    }
    expr_ << ")";
}

void CodeGen::visit(BIFCall& node) {
    if (node.name == "CHAR") {
        expr_ << "rpg_to_char(";
        node.args[0]->accept(*this);
        expr_ << ")";
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
        expr_ << current_proc_parm_count_;
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
    } else if (node.name == "FOUND") {
        expr_ << "rpg_found()";
    } else if (node.name == "EOF") {
        expr_ << "rpg_eof()";
    } else {
        expr_ << "/* unknown BIF: %" << node.name << " */";
    }
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

} // namespace rpg
