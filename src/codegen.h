#ifndef CODEGEN_H
#define CODEGEN_H

#include "ast.h"
#include <map>
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
    void visit(IndicatorExpr& node) override;
    void visit(Program& node) override;

private:
    std::ostringstream out_;
    std::ostringstream expr_;
    int indent_ = 1;
    bool in_procedure_ = false;
    bool uses_indicators_ = false;

    void emitIndent();
    void emitStatements(std::vector<std::unique_ptr<Statement>>& stmts);
    std::string emitExpr(Expression& expr);
    std::string typeToString(RPGType type, int length = 0);
    std::string paramTypeToString(const ParamDecl& p);
    std::string fieldTypeDefault(RPGType type, int length);

    // Track DS definitions for LIKEDS resolution
    std::map<std::string, DclDS*> ds_defs_;
};

} // namespace rpg

#endif // CODEGEN_H
