#ifndef AST_H
#define AST_H

#include <memory>
#include <string>
#include <vector>

namespace rpg {

class ASTVisitor;

class ASTNode {
public:
    int line = 0; // source line number
    virtual ~ASTNode() = default;
    virtual void accept(ASTVisitor& visitor) = 0;
};

class Expression : public ASTNode {
public:
    virtual ~Expression() = default;
};

class Statement : public ASTNode {
public:
    virtual ~Statement() = default;
};

// --- Expressions ---

class Identifier : public Expression {
public:
    std::string name;
    explicit Identifier(std::string name);
    void accept(ASTVisitor& visitor) override;
};

class IntLiteral : public Expression {
public:
    int value;
    explicit IntLiteral(int value);
    void accept(ASTVisitor& visitor) override;
};

class FloatLiteral : public Expression {
public:
    double value;
    explicit FloatLiteral(double value);
    void accept(ASTVisitor& visitor) override;
};

class StringLiteral : public Expression {
public:
    std::string value;
    explicit StringLiteral(std::string value);
    void accept(ASTVisitor& visitor) override;
};

enum class BinOp {
    ADD, SUB, MUL, DIV, POWER,
    EQ, NE, LT, GT, LE, GE,
    AND, OR
};

class BinaryExpr : public Expression {
public:
    BinOp op;
    std::unique_ptr<Expression> left;
    std::unique_ptr<Expression> right;
    BinaryExpr(BinOp op, std::unique_ptr<Expression> left, std::unique_ptr<Expression> right);
    void accept(ASTVisitor& visitor) override;
};

class NotExpr : public Expression {
public:
    std::unique_ptr<Expression> operand;
    explicit NotExpr(std::unique_ptr<Expression> operand);
    void accept(ASTVisitor& visitor) override;
};

class BIFCall : public Expression {
public:
    std::string name;
    std::vector<std::unique_ptr<Expression>> args;
    BIFCall(std::string name, std::vector<std::unique_ptr<Expression>> args);
    void accept(ASTVisitor& visitor) override;
};

// Function call expression (user-defined procedures)
class FuncCall : public Expression {
public:
    std::string name;
    std::vector<std::unique_ptr<Expression>> args;
    FuncCall(std::string name, std::vector<std::unique_ptr<Expression>> args);
    void accept(ASTVisitor& visitor) override;
};

// --- Statements ---

enum class RPGType {
    CHAR,
    VARCHAR,
    INT10,
    PACKED,
    ZONED,
    IND,       // indicator type (boolean)
    DATE,      // date type
    TIME,      // time type
    TIMESTAMP, // timestamp type
    POINTER,   // pointer type
    UNS,       // unsigned integer
    FLOAT4,    // IEEE float (4 bytes)
    FLOAT8,    // IEEE double (8 bytes)
    BINDEC,    // binary decimal (legacy)
    UCS2,      // Unicode UCS-2
    OBJECT     // Java object reference (stub)
};

// File declaration (DCL-F) - stub
class DclF : public Statement {
public:
    std::string name;
    std::string usage; // DISK, PRINTER, etc.
    DclF(std::string name, std::string usage);
    void accept(ASTVisitor& visitor) override;
};

// Named constant (DCL-C)
class DclC : public Statement {
public:
    std::string name;
    std::unique_ptr<Expression> value;
    DclC(std::string name, std::unique_ptr<Expression> value);
    void accept(ASTVisitor& visitor) override;
};

class DclS : public Statement {
public:
    std::string name;
    RPGType type;
    int length;
    int digits;
    int decimals;
    bool is_const;
    bool is_static = false;   // STATIC keyword
    bool is_template = false; // TEMPLATE keyword
    bool is_export = false;   // EXPORT keyword
    bool is_import = false;   // IMPORT keyword
    std::string based_ptr;    // BASED(ptrname)
    int dim;  // DIM(n), 0 = not an array
    int dim_type = 0;  // 0=fixed, 1=*VAR, 2=*AUTO
    std::string like_var; // LIKE(varname)
    int sort_order = 0;  // 0=none, 1=ASCEND, -1=DESCEND
    std::string datfmt;  // per-field DATFMT
    std::string timfmt;  // per-field TIMFMT
    std::string nullind; // NULLIND(field)
    std::string java_class; // OBJECT(*JAVA:'class')
    std::unique_ptr<Expression> inz_value;
    DclS(std::string name, RPGType type, int length, int digits = 0, int decimals = 0,
         bool is_const = false, std::unique_ptr<Expression> inz_value = nullptr, int dim = 0);
    void accept(ASTVisitor& visitor) override;
};

class EvalStmt : public Statement {
public:
    std::unique_ptr<Expression> target;
    std::unique_ptr<Expression> value;
    EvalStmt(std::unique_ptr<Expression> target, std::unique_ptr<Expression> value);
    void accept(ASTVisitor& visitor) override;
};

class DsplyStmt : public Statement {
public:
    std::unique_ptr<Expression> expr;
    explicit DsplyStmt(std::unique_ptr<Expression> expr);
    void accept(ASTVisitor& visitor) override;
};

class ReturnStmt : public Statement {
public:
    int code;                              // used for *INLR = *ON (code=0)
    std::unique_ptr<Expression> expr;      // used for RETURN expr;
    bool has_expr;
    explicit ReturnStmt(int code);
    explicit ReturnStmt(std::unique_ptr<Expression> expr);
    void accept(ASTVisitor& visitor) override;
};

// --- Control Flow ---

struct ElseIfBranch {
    std::unique_ptr<Expression> condition;
    std::vector<std::unique_ptr<Statement>> body;
};

class IfStmt : public Statement {
public:
    std::unique_ptr<Expression> condition;
    std::vector<std::unique_ptr<Statement>> then_body;
    std::vector<ElseIfBranch> elseif_branches;
    std::vector<std::unique_ptr<Statement>> else_body;
    IfStmt(std::unique_ptr<Expression> condition);
    void accept(ASTVisitor& visitor) override;
};

class DowStmt : public Statement {
public:
    std::unique_ptr<Expression> condition;
    std::vector<std::unique_ptr<Statement>> body;
    DowStmt(std::unique_ptr<Expression> condition);
    void accept(ASTVisitor& visitor) override;
};

class DouStmt : public Statement {
public:
    std::unique_ptr<Expression> condition;
    std::vector<std::unique_ptr<Statement>> body;
    DouStmt(std::unique_ptr<Expression> condition);
    void accept(ASTVisitor& visitor) override;
};

class ForStmt : public Statement {
public:
    std::string var;
    std::unique_ptr<Expression> start;
    std::unique_ptr<Expression> end;
    std::unique_ptr<Expression> by;
    bool downto;
    std::vector<std::unique_ptr<Statement>> body;
    ForStmt(std::string var, std::unique_ptr<Expression> start,
            std::unique_ptr<Expression> end, std::unique_ptr<Expression> by, bool downto);
    void accept(ASTVisitor& visitor) override;
};

struct WhenBranch {
    std::unique_ptr<Expression> condition;
    std::vector<std::unique_ptr<Statement>> body;
};

class SelectStmt : public Statement {
public:
    std::vector<WhenBranch> when_branches;
    std::vector<std::unique_ptr<Statement>> other_body;
    SelectStmt();
    void accept(ASTVisitor& visitor) override;
};

class IterStmt : public Statement {
public:
    void accept(ASTVisitor& visitor) override;
};

class LeaveStmt : public Statement {
public:
    void accept(ASTVisitor& visitor) override;
};

// --- Procedures ---

struct ParamDecl {
    std::string name;
    RPGType type;
    int length;
    int digits;
    int decimals;
    bool by_value;  // VALUE keyword
    std::string likeds; // LIKEDS(dsname)
    bool nopass = false;  // OPTIONS(*NOPASS)
    bool omit = false;    // OPTIONS(*OMIT)
    bool varsize = false; // OPTIONS(*VARSIZE)
    bool string_opt = false; // OPTIONS(*STRING)
    bool trim_opt = false;   // OPTIONS(*TRIM)
};

// Procedure interface (DCL-PI)
struct ProcInterface {
    RPGType return_type;
    int return_length;
    int return_digits;
    int return_decimals;
    bool has_return;
    std::vector<ParamDecl> params;
};

// Prototype (DCL-PR) - forward declaration
class DclPR : public Statement {
public:
    std::string name;
    ProcInterface interface;
    std::string extpgm;   // EXTPGM('name') — external program
    std::string extproc;  // EXTPROC('name') — external procedure
    bool rtnparm = false; // RTNPARM keyword
    bool opdesc = false;  // OPDESC keyword
    DclPR(std::string name, ProcInterface iface);
    void accept(ASTVisitor& visitor) override;
};

// Procedure (DCL-PROC / END-PROC)
class DclProc : public Statement {
public:
    std::string name;
    ProcInterface interface;
    bool is_export = false; // EXPORT keyword
    std::vector<std::unique_ptr<Statement>> body;
    std::vector<std::unique_ptr<Statement>> on_exit_body;
    DclProc(std::string name, ProcInterface iface);
    void accept(ASTVisitor& visitor) override;
};

// Expression statement (function call as statement)
class ExprStmt : public Statement {
public:
    std::unique_ptr<Expression> expr;
    explicit ExprStmt(std::unique_ptr<Expression> expr);
    void accept(ASTVisitor& visitor) override;
};

// --- Phase 8: Monitor, Subroutines, Indicators ---

class MonitorStmt : public Statement {
public:
    std::vector<std::unique_ptr<Statement>> try_body;
    std::vector<std::unique_ptr<Statement>> on_error_body;
    MonitorStmt();
    void accept(ASTVisitor& visitor) override;
};

class BegSR : public Statement {
public:
    std::string name;
    std::vector<std::unique_ptr<Statement>> body;
    BegSR(std::string name);
    void accept(ASTVisitor& visitor) override;
};

class ExSR : public Statement {
public:
    std::string name;
    explicit ExSR(std::string name);
    void accept(ASTVisitor& visitor) override;
};

// Indicator access (*INxx)
class IndicatorExpr : public Expression {
public:
    int number; // 1-99
    explicit IndicatorExpr(int number);
    void accept(ASTVisitor& visitor) override;
};

// SORTA statement
class SortAStmt : public Statement {
public:
    std::string array_name;
    explicit SortAStmt(std::string name);
    void accept(ASTVisitor& visitor) override;
};

// RESET and CLEAR statements
class ResetStmt : public Statement {
public:
    std::string var_name;
    explicit ResetStmt(std::string name);
    void accept(ASTVisitor& visitor) override;
};

class ClearStmt : public Statement {
public:
    std::string var_name;
    explicit ClearStmt(std::string name);
    void accept(ASTVisitor& visitor) override;
};

// DEALLOC statement
class DeallocStmt : public Statement {
public:
    std::string var_name;
    explicit DeallocStmt(std::string name);
    void accept(ASTVisitor& visitor) override;
};

// TEST statement (validate date/time)
class TestStmt : public Statement {
public:
    char type; // 'D', 'T', 'Z' for date, time, timestamp
    std::string var_name;
    TestStmt(char type, std::string name);
    void accept(ASTVisitor& visitor) override;
};

// EVALR statement (right-adjust)
class EvalRStmt : public Statement {
public:
    std::unique_ptr<Expression> target;
    std::unique_ptr<Expression> value;
    EvalRStmt(std::unique_ptr<Expression> target, std::unique_ptr<Expression> value);
    void accept(ASTVisitor& visitor) override;
};

// LEAVESR statement
class LeaveSRStmt : public Statement {
public:
    void accept(ASTVisitor& visitor) override;
};

// EVAL-CORR statement
class EvalCorrStmt : public Statement {
public:
    std::string target;
    std::string source;
    EvalCorrStmt(std::string target, std::string source);
    void accept(ASTVisitor& visitor) override;
};

// --- Data Structures ---

struct DSField {
    std::string name;
    RPGType type;
    int length;
    int digits;
    int decimals;
    std::string overlay_field;
    int overlay_pos = 0;
    int pos = 0;
};

class DclDS : public Statement {
public:
    std::string name;
    bool qualified;
    int dim;  // DIM(n), 0 = not an array
    int dim_type = 0;  // 0=fixed, 1=*VAR, 2=*AUTO
    std::string like_ds; // LIKEDS(name)
    std::string extname; // EXTNAME(filename)
    std::string prefix;  // PREFIX(pfx)
    int prefix_nbr = 0;
    int occurs = 0;      // OCCURS(n), 0 = not multi-occurrence
    std::vector<DSField> fields;
    DclDS(std::string name);
    void accept(ASTVisitor& visitor) override;
};

// Dot-qualified access: ds.field
class DotExpr : public Expression {
public:
    std::unique_ptr<Expression> object;
    std::string field;
    DotExpr(std::unique_ptr<Expression> object, std::string field);
    void accept(ASTVisitor& visitor) override;
};

// Array index access: arr(i)
class ArrayAccess : public Expression {
public:
    std::string name;
    std::unique_ptr<Expression> index;
    ArrayAccess(std::string name, std::unique_ptr<Expression> index);
    void accept(ASTVisitor& visitor) override;
};

// FOR-EACH statement
class ForEachStmt : public Statement {
public:
    std::string var;
    std::unique_ptr<Expression> collection;
    std::vector<std::unique_ptr<Statement>> body;
    ForEachStmt(std::string var, std::unique_ptr<Expression> collection);
    void accept(ASTVisitor& visitor) override;
};

// IN operator expression (x IN %LIST(...) or x IN %RANGE(...))
class InExpr : public Expression {
public:
    std::unique_ptr<Expression> value;
    std::unique_ptr<Expression> collection;
    InExpr(std::unique_ptr<Expression> value, std::unique_ptr<Expression> collection);
    void accept(ASTVisitor& visitor) override;
};

// --- Program ---

class Program : public ASTNode {
public:
    bool nomain = false; // CTL-OPT NOMAIN
    std::string main_proc; // CTL-OPT MAIN(procname)
    std::string datfmt; // CTL-OPT DATFMT(fmt)
    std::string timfmt; // CTL-OPT TIMFMT(fmt)
    std::vector<std::unique_ptr<Statement>> statements;
    void accept(ASTVisitor& visitor) override;
};

// DCL-ENUM / END-ENUM
struct EnumConstant {
    std::string name;
    std::unique_ptr<Expression> value; // optional explicit value
};

class DclEnum : public Statement {
public:
    std::string name;
    bool qualified = false;
    std::vector<EnumConstant> constants;
    DclEnum(std::string name) : name(std::move(name)) {}
    void accept(ASTVisitor& visitor) override;
};

// --- Visitor ---

class ASTVisitor {
public:
    virtual ~ASTVisitor() = default;
    virtual void visit(Identifier& node) = 0;
    virtual void visit(IntLiteral& node) = 0;
    virtual void visit(FloatLiteral& node) = 0;
    virtual void visit(StringLiteral& node) = 0;
    virtual void visit(BinaryExpr& node) = 0;
    virtual void visit(NotExpr& node) = 0;
    virtual void visit(BIFCall& node) = 0;
    virtual void visit(FuncCall& node) = 0;
    virtual void visit(DclF& node) = 0;
    virtual void visit(DclC& node) = 0;
    virtual void visit(DclS& node) = 0;
    virtual void visit(EvalStmt& node) = 0;
    virtual void visit(DsplyStmt& node) = 0;
    virtual void visit(ReturnStmt& node) = 0;
    virtual void visit(IfStmt& node) = 0;
    virtual void visit(DowStmt& node) = 0;
    virtual void visit(DouStmt& node) = 0;
    virtual void visit(ForStmt& node) = 0;
    virtual void visit(SelectStmt& node) = 0;
    virtual void visit(IterStmt& node) = 0;
    virtual void visit(LeaveStmt& node) = 0;
    virtual void visit(DclPR& node) = 0;
    virtual void visit(DclProc& node) = 0;
    virtual void visit(ExprStmt& node) = 0;
    virtual void visit(DclDS& node) = 0;
    virtual void visit(DotExpr& node) = 0;
    virtual void visit(ArrayAccess& node) = 0;
    virtual void visit(MonitorStmt& node) = 0;
    virtual void visit(BegSR& node) = 0;
    virtual void visit(ExSR& node) = 0;
    virtual void visit(SortAStmt& node) = 0;
    virtual void visit(ResetStmt& node) = 0;
    virtual void visit(ClearStmt& node) = 0;
    virtual void visit(IndicatorExpr& node) = 0;
    virtual void visit(EvalCorrStmt& node) = 0;
    virtual void visit(EvalRStmt& node) = 0;
    virtual void visit(LeaveSRStmt& node) = 0;
    virtual void visit(DeallocStmt& node) = 0;
    virtual void visit(TestStmt& node) = 0;
    virtual void visit(ForEachStmt& node) = 0;
    virtual void visit(InExpr& node) = 0;
    virtual void visit(DclEnum& node) = 0;
    virtual void visit(Program& node) = 0;
};

} // namespace rpg

#endif // AST_H
