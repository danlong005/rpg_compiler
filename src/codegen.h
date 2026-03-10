#ifndef CODEGEN_H
#define CODEGEN_H

#include "ast.h"
#include "sql_utils.h"
#include <map>
#include <set>
#include <sstream>
#include <string>

namespace rpg {

class CodeGen : public ASTVisitor {
public:
    std::string generate(Program& program);

    void visit(Identifier& node) override;
    void visit(IntLiteral& node) override;
    void visit(FloatLiteral& node) override;
    void visit(StringLiteral& node) override;
    void visit(BinaryExpr& node) override;
    void visit(NotExpr& node) override;
    void visit(BIFCall& node) override;
    void visit(FuncCall& node) override;
    void visit(DclF& node) override;
    void visit(DclC& node) override;
    void visit(DclS& node) override;
    void visit(EvalStmt& node) override;
    void visit(DsplyStmt& node) override;
    void visit(ReturnStmt& node) override;
    void visit(IfStmt& node) override;
    void visit(DowStmt& node) override;
    void visit(DouStmt& node) override;
    void visit(ForStmt& node) override;
    void visit(SelectStmt& node) override;
    void visit(IterStmt& node) override;
    void visit(LeaveStmt& node) override;
    void visit(DclPR& node) override;
    void visit(DclProc& node) override;
    void visit(ExprStmt& node) override;
    void visit(DclDS& node) override;
    void visit(DotExpr& node) override;
    void visit(ArrayAccess& node) override;
    void visit(MonitorStmt& node) override;
    void visit(BegSR& node) override;
    void visit(ExSR& node) override;
    void visit(SortAStmt& node) override;
    void visit(ResetStmt& node) override;
    void visit(ClearStmt& node) override;
    void visit(IndicatorExpr& node) override;
    void visit(EvalCorrStmt& node) override;
    void visit(EvalRStmt& node) override;
    void visit(LeaveSRStmt& node) override;
    void visit(DeallocStmt& node) override;
    void visit(TestStmt& node) override;
    void visit(ForEachStmt& node) override;
    void visit(InExpr& node) override;
    void visit(DclEnum& node) override;
    void visit(ExecSqlStmt& node) override;
    void visit(XmlIntoStmt& node) override;
    void visit(Program& node) override;

private:
    std::ostringstream out_;
    std::ostringstream expr_;
    int indent_ = 1;
    bool in_procedure_ = false;
    bool uses_indicators_ = false;
    int current_proc_parm_count_ = 0;
    bool has_nopass_params_ = false;
    std::string current_proc_name_;
    std::string datfmt_; // default date format (e.g., "*ISO", "*USA", "*MDY")
    std::string timfmt_; // default time format
    bool uses_sql_ = false; // program contains EXEC SQL statements
    bool uses_xml_ = false; // program contains XML-INTO statements

    void emitIndent();
    void emitStatements(std::vector<std::unique_ptr<Statement>>& stmts);
    std::string emitExpr(Expression& expr);
    std::string typeToString(RPGType type, int length = 0);
    std::string paramTypeToString(const ParamDecl& p);
    std::string paramTypeDefault(const ParamDecl& p);
    int countRequiredParams(const std::vector<ParamDecl>& params);
    std::string fieldTypeDefault(RPGType type, int length);
    std::string figConstValue(const std::string& name, RPGType type, const std::string& var_name);

    // XML-INTO codegen helpers
    void emitXmlFieldAssignments(DclDS* ds, const std::string& target, const std::string& xml_src);

    // SQL codegen helpers
    void emitSqlBindParam(const std::string& var, int index, const std::string& handle = "__hstmt");
    void emitSqlBindCol(const std::string& var, int index, const std::string& handle = "__hstmt");
    // Expand DS host variables into qualified field names (e.g., :row → ROW.ID, ROW.NAME, ...)
    std::vector<std::string> expandSqlIntoVars(const std::vector<std::string>& vars);
    static std::string escapeSqlForCpp(const std::string& sql);
    static std::string sqlCommentText(const std::string& sql);

    // Track DS definitions for LIKEDS resolution
    std::map<std::string, DclDS*> ds_defs_;

    // Track variable types and whether they have INZ for RESET/CLEAR
    std::map<std::string, RPGType> var_types_;
    std::map<std::string, int> var_lengths_; // for CHAR length
    std::set<std::string> has_inz_; // variables with INZ values
    std::set<std::string> array_vars_; // DIM array variables
    std::set<std::string> nopass_procs_; // procs with *NOPASS params
    std::map<std::string, std::vector<ParamDecl>> nopass_proc_params_; // full param info
    std::map<std::string, std::string> extproc_map_; // RPG name → C++ name (EXTPROC/EXTPGM)
    std::map<std::string, std::vector<std::string>> cursor_host_vars_; // cursor name → host vars for binding at OPEN
};

} // namespace rpg

#endif // CODEGEN_H
