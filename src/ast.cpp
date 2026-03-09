#include "ast.h"

namespace rpg {

Identifier::Identifier(std::string name) : name(std::move(name)) {}
void Identifier::accept(ASTVisitor& visitor) { visitor.visit(*this); }

IntLiteral::IntLiteral(int value) : value(value) {}
void IntLiteral::accept(ASTVisitor& visitor) { visitor.visit(*this); }

FloatLiteral::FloatLiteral(double value) : value(value) {}
void FloatLiteral::accept(ASTVisitor& visitor) { visitor.visit(*this); }

StringLiteral::StringLiteral(std::string value) : value(std::move(value)) {}
void StringLiteral::accept(ASTVisitor& visitor) { visitor.visit(*this); }

BinaryExpr::BinaryExpr(BinOp op, std::unique_ptr<Expression> left, std::unique_ptr<Expression> right)
    : op(op), left(std::move(left)), right(std::move(right)) {}
void BinaryExpr::accept(ASTVisitor& visitor) { visitor.visit(*this); }

NotExpr::NotExpr(std::unique_ptr<Expression> operand) : operand(std::move(operand)) {}
void NotExpr::accept(ASTVisitor& visitor) { visitor.visit(*this); }

BIFCall::BIFCall(std::string name, std::vector<std::unique_ptr<Expression>> args)
    : name(std::move(name)), args(std::move(args)) {}
void BIFCall::accept(ASTVisitor& visitor) { visitor.visit(*this); }

FuncCall::FuncCall(std::string name, std::vector<std::unique_ptr<Expression>> args)
    : name(std::move(name)), args(std::move(args)) {}
void FuncCall::accept(ASTVisitor& visitor) { visitor.visit(*this); }

DclC::DclC(std::string name, std::unique_ptr<Expression> value)
    : name(std::move(name)), value(std::move(value)) {}
void DclC::accept(ASTVisitor& visitor) { visitor.visit(*this); }

DclS::DclS(std::string name, RPGType type, int length, int digits, int decimals,
           bool is_const, std::unique_ptr<Expression> inz_value)
    : name(std::move(name)), type(type), length(length), digits(digits), decimals(decimals),
      is_const(is_const), inz_value(std::move(inz_value)) {}
void DclS::accept(ASTVisitor& visitor) { visitor.visit(*this); }

EvalStmt::EvalStmt(std::unique_ptr<Expression> target, std::unique_ptr<Expression> value)
    : target(std::move(target)), value(std::move(value)) {}
void EvalStmt::accept(ASTVisitor& visitor) { visitor.visit(*this); }

DsplyStmt::DsplyStmt(std::unique_ptr<Expression> expr) : expr(std::move(expr)) {}
void DsplyStmt::accept(ASTVisitor& visitor) { visitor.visit(*this); }

ReturnStmt::ReturnStmt(int code) : code(code), has_expr(false) {}
ReturnStmt::ReturnStmt(std::unique_ptr<Expression> expr)
    : code(0), expr(std::move(expr)), has_expr(true) {}
void ReturnStmt::accept(ASTVisitor& visitor) { visitor.visit(*this); }

IfStmt::IfStmt(std::unique_ptr<Expression> condition)
    : condition(std::move(condition)) {}
void IfStmt::accept(ASTVisitor& visitor) { visitor.visit(*this); }

DowStmt::DowStmt(std::unique_ptr<Expression> condition)
    : condition(std::move(condition)) {}
void DowStmt::accept(ASTVisitor& visitor) { visitor.visit(*this); }

DouStmt::DouStmt(std::unique_ptr<Expression> condition)
    : condition(std::move(condition)) {}
void DouStmt::accept(ASTVisitor& visitor) { visitor.visit(*this); }

ForStmt::ForStmt(std::string var, std::unique_ptr<Expression> start,
                 std::unique_ptr<Expression> end, std::unique_ptr<Expression> by, bool downto)
    : var(std::move(var)), start(std::move(start)), end(std::move(end)),
      by(std::move(by)), downto(downto) {}
void ForStmt::accept(ASTVisitor& visitor) { visitor.visit(*this); }

SelectStmt::SelectStmt() {}
void SelectStmt::accept(ASTVisitor& visitor) { visitor.visit(*this); }

void IterStmt::accept(ASTVisitor& visitor) { visitor.visit(*this); }
void LeaveStmt::accept(ASTVisitor& visitor) { visitor.visit(*this); }

DclPR::DclPR(std::string name, ProcInterface iface)
    : name(std::move(name)), interface(std::move(iface)) {}
void DclPR::accept(ASTVisitor& visitor) { visitor.visit(*this); }

DclProc::DclProc(std::string name, ProcInterface iface)
    : name(std::move(name)), interface(std::move(iface)) {}
void DclProc::accept(ASTVisitor& visitor) { visitor.visit(*this); }

ExprStmt::ExprStmt(std::unique_ptr<Expression> expr) : expr(std::move(expr)) {}
void ExprStmt::accept(ASTVisitor& visitor) { visitor.visit(*this); }

MonitorStmt::MonitorStmt() {}
void MonitorStmt::accept(ASTVisitor& visitor) { visitor.visit(*this); }

BegSR::BegSR(std::string name) : name(std::move(name)) {}
void BegSR::accept(ASTVisitor& visitor) { visitor.visit(*this); }

ExSR::ExSR(std::string name) : name(std::move(name)) {}
void ExSR::accept(ASTVisitor& visitor) { visitor.visit(*this); }

IndicatorExpr::IndicatorExpr(int number) : number(number) {}
void IndicatorExpr::accept(ASTVisitor& visitor) { visitor.visit(*this); }

DclDS::DclDS(std::string name)
    : name(std::move(name)), qualified(false), dim(0) {}
void DclDS::accept(ASTVisitor& visitor) { visitor.visit(*this); }

DotExpr::DotExpr(std::unique_ptr<Expression> object, std::string field)
    : object(std::move(object)), field(std::move(field)) {}
void DotExpr::accept(ASTVisitor& visitor) { visitor.visit(*this); }

ArrayAccess::ArrayAccess(std::string name, std::unique_ptr<Expression> index)
    : name(std::move(name)), index(std::move(index)) {}
void ArrayAccess::accept(ASTVisitor& visitor) { visitor.visit(*this); }

void Program::accept(ASTVisitor& visitor) { visitor.visit(*this); }

} // namespace rpg
