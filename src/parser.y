%code requires {
#include <memory>
#include <vector>
#include <string>
#include "ast.h"

struct StmtList {
    std::vector<rpg::Statement*> stmts;
};

struct ElseIfData {
    rpg::Expression* cond;
    std::vector<rpg::Statement*> body;
};

struct WhenData {
    rpg::Expression* cond;
    std::vector<rpg::Statement*> body;
};

struct ParamList {
    std::vector<rpg::ParamDecl> params;
};

struct DSFieldList {
    std::vector<rpg::DSField> fields;
};
}

%{
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory>
#include <vector>
#include <string>
#include "ast.h"

extern int yylex();
extern int yylineno;
extern char* yytext;
void yyerror(const char* s);

static rpg::Program* g_program = nullptr;
static int g_error_count = 0;

rpg::Program* get_parsed_program();
int get_parse_error_count();

// Set line number on AST node
#define SET_LINE(node) do { if (node) (node)->line = yylineno; } while(0)

static rpg::BIFCall* make_bif(const char* name, std::vector<rpg::Expression*>* raw_args) {
    std::vector<std::unique_ptr<rpg::Expression>> args;
    for (auto* e : *raw_args) {
        args.emplace_back(e);
    }
    delete raw_args;
    return new rpg::BIFCall(name, std::move(args));
}

static rpg::FuncCall* make_func(const char* name, std::vector<rpg::Expression*>* raw_args) {
    std::vector<std::unique_ptr<rpg::Expression>> args;
    if (raw_args) {
        for (auto* e : *raw_args) {
            args.emplace_back(e);
        }
        delete raw_args;
    }
    return new rpg::FuncCall(name, std::move(args));
}
%}

%union {
    int ival;
    double fval;
    char* sval;
    rpg::Expression* expr;
    rpg::Statement* stmt;
    rpg::Program* program;
    std::vector<rpg::Expression*>* expr_list;
    StmtList* stmt_list;
    std::vector<ElseIfData*>* elseif_list;
    ElseIfData* elseif_data;
    std::vector<WhenData*>* when_list;
    WhenData* when_data;
    ParamList* param_list;
    rpg::ParamDecl* param_decl;
    DSFieldList* ds_field_list;
    rpg::DSField* ds_field;
}

%token KW_FREE
%token KW_DCL_F KW_DCL_S KW_DCL_C
%token KW_DISK KW_PRINTER KW_WORKSTN KW_USAGE
%token KW_CHAR KW_VARCHAR KW_INT KW_PACKED KW_ZONED
%token KW_DATE KW_TIME KW_TIMESTAMP KW_POINTER KW_NULL
%token KW_DAYS KW_MONTHS KW_YEARS
%token KW_CONST KW_INZ
%token KW_DSPLY
%token KW_EVAL KW_EVAL_CORR
%token KW_RETURN
%token KW_INLR KW_ON
%token KW_IF KW_ELSEIF KW_ELSE KW_ENDIF
%token KW_DOW KW_DOU KW_ENDDO
%token KW_FOR KW_ENDFOR KW_TO KW_DOWNTO KW_BY
%token KW_SELECT KW_WHEN KW_OTHER KW_ENDSL
%token KW_ITER KW_LEAVE
%token KW_MONITOR KW_ON_ERROR KW_ENDMON
%token KW_BEGSR KW_ENDSR KW_EXSR
%token KW_OFF KW_RESET KW_CLEAR KW_SORTA
%token <ival> INDICATOR
%token KW_AND KW_OR KW_NOT
%token KW_DCL_PROC KW_END_PROC
%token KW_DCL_PI KW_END_PI
%token KW_DCL_PR KW_END_PR
%token KW_VALUE
%token KW_DCL_DS KW_END_DS KW_QUALIFIED KW_DIM KW_LIKEDS KW_LIKE KW_DCL_SUBF KW_DCL_PARM
%token DOT
%token BIF_CHAR BIF_TRIM BIF_TRIML BIF_TRIMR BIF_LEN BIF_SUBST
%token BIF_SCAN BIF_SCANRPL BIF_XLATE BIF_DEC BIF_INT BIF_ELEM BIF_FOUND BIF_EOF
%token BIF_ABS BIF_DIV BIF_REM BIF_SIZE BIF_ADDR BIF_PARMS BIF_STATUS BIF_ERROR BIF_MAX BIF_MIN BIF_LOOKUP
%token BIF_DATE BIF_TIME BIF_TIMESTAMP BIF_DIFF BIF_DAYS BIF_MONTHS BIF_YEARS
%token BIF_EDITC BIF_EDITW BIF_REPLACE BIF_CHECK BIF_CHECKR
%token <sval> IDENTIFIER
%token <ival> INTEGER_LITERAL
%token <fval> FLOAT_LITERAL
%token <sval> STRING_LITERAL

%token SEMICOLON EQUALS LPAREN RPAREN COLON
%token PLUS MINUS STAR SLASH
%token NE LE GE LT GT

%type <program> program
%type <stmt> statement dcl_f_stmt dcl_s_stmt dcl_c_stmt eval_stmt eval_corr_stmt dsply_stmt inlr_stmt return_stmt expr_stmt reset_stmt clear_stmt sorta_stmt
%type <stmt> if_stmt dow_stmt dou_stmt for_stmt select_stmt iter_stmt leave_stmt
%type <stmt> dcl_proc_stmt dcl_pr_stmt dcl_ds_stmt
%type <stmt> monitor_stmt begsr_stmt exsr_stmt
%type <expr> expression or_expr and_expr not_expr comparison_expr additive_expr multiplicative_expr unary_expr postfix_expr primary_expr eval_target
%type <expr_list> arg_list call_arg_list call_args_opt
%type <stmt_list> statement_list
%type <elseif_list> elseif_clauses
%type <elseif_data> elseif_clause
%type <stmt_list> else_clause
%type <when_list> when_clauses
%type <when_data> when_clause
%type <stmt_list> other_clause
%type <ds_field_list> ds_fields
%type <ds_field> ds_field
%type <param_list> pi_params pr_params
%type <param_decl> pi_param pr_param
%type <ival> pi_return_type

%start program

%%

program:
    KW_FREE statements_opt {
        $$ = g_program;
    }
    ;

statements_opt:
    /* empty */
    | statements_opt statement {
        if ($2) {
            g_program->statements.emplace_back($2);
        }
    }
    ;

statement_list:
    /* empty */ {
        $$ = new StmtList();
    }
    | statement_list statement {
        $$ = $1;
        if ($2) {
            $$->stmts.push_back($2);
        }
    }
    ;

statement:
    dcl_f_stmt    { $$ = $1; SET_LINE($$); }
    | dcl_s_stmt  { $$ = $1; SET_LINE($$); }
    | dcl_c_stmt  { $$ = $1; SET_LINE($$); }
    | eval_stmt   { $$ = $1; SET_LINE($$); }
    | eval_corr_stmt { $$ = $1; SET_LINE($$); }
    | dsply_stmt  { $$ = $1; SET_LINE($$); }
    | inlr_stmt   { $$ = $1; SET_LINE($$); }
    | return_stmt { $$ = $1; SET_LINE($$); }
    | if_stmt     { $$ = $1; SET_LINE($$); }
    | dow_stmt    { $$ = $1; SET_LINE($$); }
    | dou_stmt    { $$ = $1; SET_LINE($$); }
    | for_stmt    { $$ = $1; SET_LINE($$); }
    | select_stmt { $$ = $1; SET_LINE($$); }
    | iter_stmt   { $$ = $1; SET_LINE($$); }
    | leave_stmt  { $$ = $1; SET_LINE($$); }
    | dcl_proc_stmt { $$ = $1; SET_LINE($$); }
    | dcl_pr_stmt   { $$ = $1; SET_LINE($$); }
    | dcl_ds_stmt   { $$ = $1; SET_LINE($$); }
    | monitor_stmt  { $$ = $1; SET_LINE($$); }
    | begsr_stmt    { $$ = $1; SET_LINE($$); }
    | exsr_stmt     { $$ = $1; SET_LINE($$); }
    | reset_stmt    { $$ = $1; SET_LINE($$); }
    | clear_stmt    { $$ = $1; SET_LINE($$); }
    | sorta_stmt    { $$ = $1; SET_LINE($$); }
    | expr_stmt   { $$ = $1; SET_LINE($$); }
    | error SEMICOLON { $$ = nullptr; yyerrok; }
    ;

/* DCL-F: file declaration */
dcl_f_stmt:
    KW_DCL_F IDENTIFIER KW_DISK SEMICOLON {
        $$ = new rpg::DclF($2, "DISK");
        free($2);
    }
    | KW_DCL_F IDENTIFIER KW_PRINTER SEMICOLON {
        $$ = new rpg::DclF($2, "PRINTER");
        free($2);
    }
    | KW_DCL_F IDENTIFIER KW_WORKSTN SEMICOLON {
        $$ = new rpg::DclF($2, "WORKSTN");
        free($2);
    }
    | KW_DCL_F IDENTIFIER KW_DISK KW_USAGE LPAREN STAR COLON STAR RPAREN SEMICOLON {
        $$ = new rpg::DclF($2, "DISK");
        free($2);
    }
    ;

/* DCL-S */
dcl_s_stmt:
    KW_DCL_S IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON {
        $$ = new rpg::DclS($2, rpg::RPGType::CHAR, $5);
        free($2);
    }
    | KW_DCL_S IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON {
        $$ = new rpg::DclS($2, rpg::RPGType::VARCHAR, $5);
        free($2);
    }
    | KW_DCL_S IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON {
        $$ = new rpg::DclS($2, rpg::RPGType::INT10, 0);
        free($2);
    }
    | KW_DCL_S IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON {
        $$ = new rpg::DclS($2, rpg::RPGType::PACKED, 0, $5, $7);
        free($2);
    }
    | KW_DCL_S IDENTIFIER KW_ZONED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON {
        $$ = new rpg::DclS($2, rpg::RPGType::ZONED, 0, $5, $7);
        free($2);
    }
    | KW_DCL_S IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_CONST KW_INZ LPAREN expression RPAREN SEMICOLON {
        $$ = new rpg::DclS($2, rpg::RPGType::INT10, 0, 0, 0, true,
                           std::unique_ptr<rpg::Expression>($10));
        free($2);
    }
    | KW_DCL_S IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_CONST KW_INZ LPAREN expression RPAREN SEMICOLON {
        $$ = new rpg::DclS($2, rpg::RPGType::CHAR, $5, 0, 0, true,
                           std::unique_ptr<rpg::Expression>($10));
        free($2);
    }
    | KW_DCL_S IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_CONST KW_INZ LPAREN expression RPAREN SEMICOLON {
        $$ = new rpg::DclS($2, rpg::RPGType::PACKED, 0, $5, $7, true,
                           std::unique_ptr<rpg::Expression>($<expr>12));
        free($2);
    }
    | KW_DCL_S IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON {
        $$ = new rpg::DclS($2, rpg::RPGType::INT10, 0, 0, 0, false,
                           std::unique_ptr<rpg::Expression>($9));
        free($2);
    }
    | KW_DCL_S IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON {
        $$ = new rpg::DclS($2, rpg::RPGType::CHAR, $5, 0, 0, false,
                           std::unique_ptr<rpg::Expression>($9));
        free($2);
    }
    | KW_DCL_S IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON {
        $$ = new rpg::DclS($2, rpg::RPGType::PACKED, 0, $5, $7, false,
                           std::unique_ptr<rpg::Expression>($<expr>11));
        free($2);
    }
    | KW_DCL_S IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON {
        $$ = new rpg::DclS($2, rpg::RPGType::VARCHAR, $5, 0, 0, false,
                           std::unique_ptr<rpg::Expression>($9));
        free($2);
    }
    | KW_DCL_S IDENTIFIER KW_DATE SEMICOLON {
        $$ = new rpg::DclS($2, rpg::RPGType::DATE, 0);
        free($2);
    }
    | KW_DCL_S IDENTIFIER KW_TIME SEMICOLON {
        $$ = new rpg::DclS($2, rpg::RPGType::TIME, 0);
        free($2);
    }
    | KW_DCL_S IDENTIFIER KW_TIMESTAMP SEMICOLON {
        $$ = new rpg::DclS($2, rpg::RPGType::TIMESTAMP, 0);
        free($2);
    }
    | KW_DCL_S IDENTIFIER KW_POINTER SEMICOLON {
        $$ = new rpg::DclS($2, rpg::RPGType::POINTER, 0);
        free($2);
    }
    | KW_DCL_S IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON {
        $$ = new rpg::DclS($2, rpg::RPGType::INT10, 0, 0, 0, false, nullptr, $9);
        free($2);
    }
    | KW_DCL_S IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON {
        $$ = new rpg::DclS($2, rpg::RPGType::CHAR, $5, 0, 0, false, nullptr, $9);
        free($2);
    }
    | KW_DCL_S IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON {
        $$ = new rpg::DclS($2, rpg::RPGType::VARCHAR, $5, 0, 0, false, nullptr, $9);
        free($2);
    }
    | KW_DCL_S IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON {
        $$ = new rpg::DclS($2, rpg::RPGType::PACKED, 0, $5, $7, false, nullptr, $<ival>11);
        free($2);
    }
    | KW_DCL_S IDENTIFIER KW_LIKE LPAREN IDENTIFIER RPAREN SEMICOLON {
        auto* node = new rpg::DclS($2, rpg::RPGType::INT10, 0);
        node->like_var = $5;
        free($2);
        free($5);
        $$ = node;
    }
    ;

dcl_s_keywords:
    /* empty */
    ;

/* DCL-C: named constants */
dcl_c_stmt:
    KW_DCL_C IDENTIFIER expression SEMICOLON {
        $$ = new rpg::DclC($2, std::unique_ptr<rpg::Expression>($3));
        free($2);
    }
    ;

eval_target:
    IDENTIFIER {
        $$ = new rpg::Identifier($1);
        free($1);
    }
    | INDICATOR {
        $$ = new rpg::IndicatorExpr($1);
    }
    | IDENTIFIER DOT IDENTIFIER {
        auto obj = std::unique_ptr<rpg::Expression>(new rpg::Identifier($1));
        $$ = new rpg::DotExpr(std::move(obj), $3);
        free($1);
        free($3);
    }
    | IDENTIFIER LPAREN expression RPAREN {
        $$ = new rpg::ArrayAccess($1, std::unique_ptr<rpg::Expression>($3));
        free($1);
    }
    | IDENTIFIER LPAREN expression RPAREN DOT IDENTIFIER {
        auto* arr = new rpg::ArrayAccess($1, std::unique_ptr<rpg::Expression>($3));
        $$ = new rpg::DotExpr(std::unique_ptr<rpg::Expression>(arr), $6);
        free($1);
        free($6);
    }
    ;

eval_stmt:
    eval_target EQUALS expression SEMICOLON {
        $$ = new rpg::EvalStmt(
            std::unique_ptr<rpg::Expression>($1),
            std::unique_ptr<rpg::Expression>($3)
        );
    }
    | KW_EVAL eval_target EQUALS expression SEMICOLON {
        $$ = new rpg::EvalStmt(
            std::unique_ptr<rpg::Expression>($2),
            std::unique_ptr<rpg::Expression>($4)
        );
    }
    ;

eval_corr_stmt:
    KW_EVAL_CORR IDENTIFIER EQUALS IDENTIFIER SEMICOLON {
        $$ = new rpg::EvalCorrStmt(std::string($2), std::string($4));
        free($2);
        free($4);
    }
    ;

dsply_stmt:
    KW_DSPLY expression SEMICOLON {
        $$ = new rpg::DsplyStmt(std::unique_ptr<rpg::Expression>($2));
    }
    ;

inlr_stmt:
    KW_INLR EQUALS KW_ON SEMICOLON {
        $$ = new rpg::ReturnStmt(0);
    }
    ;

return_stmt:
    KW_RETURN expression SEMICOLON {
        $$ = new rpg::ReturnStmt(std::unique_ptr<rpg::Expression>($2));
    }
    | KW_RETURN SEMICOLON {
        $$ = new rpg::ReturnStmt(0);
    }
    ;

/* Expression as statement (for procedure calls) */
expr_stmt:
    IDENTIFIER LPAREN call_args_opt RPAREN SEMICOLON {
        auto* fc = make_func($1, $3);
        free($1);
        $$ = new rpg::ExprStmt(std::unique_ptr<rpg::Expression>(fc));
    }
    ;

/* --- Procedures --- */

/* DCL-PR: prototype/forward declaration */
dcl_pr_stmt:
    KW_DCL_PR IDENTIFIER pi_return_type SEMICOLON pr_params KW_END_PR SEMICOLON {
        rpg::ProcInterface iface;
        if ($3 >= 0) {
            iface.has_return = true;
            iface.return_type = static_cast<rpg::RPGType>($3);
            iface.return_length = 0;
            iface.return_digits = 0;
            iface.return_decimals = 0;
        } else {
            iface.has_return = false;
        }
        iface.params = std::move($5->params);
        delete $5;
        $$ = new rpg::DclPR($2, std::move(iface));
        free($2);
    }
    ;

/* DCL-PROC with embedded DCL-PI */
dcl_proc_stmt:
    KW_DCL_PROC IDENTIFIER SEMICOLON
    KW_DCL_PI pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON
    statement_list
    KW_END_PROC SEMICOLON {
        rpg::ProcInterface iface;
        if ($5 >= 0) {
            iface.has_return = true;
            // Decode type from pi_return_type
            iface.return_type = static_cast<rpg::RPGType>($5);
            iface.return_length = 0;
            iface.return_digits = 0;
            iface.return_decimals = 0;
        } else {
            iface.has_return = false;
        }
        iface.params = std::move($7->params);
        delete $7;
        auto* proc = new rpg::DclProc($2, std::move(iface));
        for (auto* s : $10->stmts) proc->body.emplace_back(s);
        delete $10;
        free($2);
        $$ = proc;
    }
    /* DCL-PI with explicit name instead of *N */
    | KW_DCL_PROC IDENTIFIER SEMICOLON
      KW_DCL_PI IDENTIFIER pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON
      statement_list
      KW_END_PROC SEMICOLON {
        rpg::ProcInterface iface;
        if ($6 >= 0) {
            iface.has_return = true;
            iface.return_type = static_cast<rpg::RPGType>($6);
            iface.return_length = 0;
            iface.return_digits = 0;
            iface.return_decimals = 0;
        } else {
            iface.has_return = false;
        }
        iface.params = std::move($8->params);
        delete $8;
        auto* proc = new rpg::DclProc($2, std::move(iface));
        for (auto* s : $<stmt_list>11->stmts) proc->body.emplace_back(s);
        delete $<stmt_list>11;
        free($2);
        free($5);
        $$ = proc;
    }
    ;

/* Return type for PI/PR: returns -1 if void, or RPGType enum value */
pi_return_type:
    /* void */ { $$ = -1; }
    | KW_INT LPAREN INTEGER_LITERAL RPAREN { $$ = (int)rpg::RPGType::INT10; }
    | KW_CHAR LPAREN INTEGER_LITERAL RPAREN { $$ = (int)rpg::RPGType::CHAR; }
    | KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN { $$ = (int)rpg::RPGType::VARCHAR; }
    | KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN { $$ = (int)rpg::RPGType::PACKED; }
    ;

/* Parameters for DCL-PI */
pi_params:
    /* empty */ {
        $$ = new ParamList();
    }
    | pi_params pi_param {
        $$ = $1;
        $$->params.push_back(*$2);
        delete $2;
    }
    ;

pi_param:
    IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON {
        $$ = new rpg::ParamDecl{$1, rpg::RPGType::INT10, 0, 0, 0, false};
        free($1);
    }
    | IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON {
        $$ = new rpg::ParamDecl{$1, rpg::RPGType::INT10, 0, 0, 0, true};
        free($1);
    }
    | IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON {
        $$ = new rpg::ParamDecl{$1, rpg::RPGType::CHAR, $4, 0, 0, false};
        free($1);
    }
    | IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON {
        $$ = new rpg::ParamDecl{$1, rpg::RPGType::CHAR, $4, 0, 0, true};
        free($1);
    }
    | IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON {
        $$ = new rpg::ParamDecl{$1, rpg::RPGType::VARCHAR, $4, 0, 0, false};
        free($1);
    }
    | IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON {
        $$ = new rpg::ParamDecl{$1, rpg::RPGType::VARCHAR, $4, 0, 0, true};
        free($1);
    }
    | IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON {
        $$ = new rpg::ParamDecl{$1, rpg::RPGType::PACKED, 0, $4, $6, false};
        free($1);
    }
    | IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON {
        $$ = new rpg::ParamDecl{$1, rpg::RPGType::PACKED, 0, $4, $6, true};
        free($1);
    }
    /* DCL-PARM alternatives */
    | KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON {
        $$ = new rpg::ParamDecl{$2, rpg::RPGType::INT10, 0, 0, 0, false};
        free($2);
    }
    | KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON {
        $$ = new rpg::ParamDecl{$2, rpg::RPGType::INT10, 0, 0, 0, true};
        free($2);
    }
    | KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON {
        $$ = new rpg::ParamDecl{$2, rpg::RPGType::CHAR, $5, 0, 0, false};
        free($2);
    }
    | KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON {
        $$ = new rpg::ParamDecl{$2, rpg::RPGType::CHAR, $5, 0, 0, true};
        free($2);
    }
    | KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON {
        $$ = new rpg::ParamDecl{$2, rpg::RPGType::VARCHAR, $5, 0, 0, false};
        free($2);
    }
    | KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON {
        $$ = new rpg::ParamDecl{$2, rpg::RPGType::VARCHAR, $5, 0, 0, true};
        free($2);
    }
    | KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON {
        $$ = new rpg::ParamDecl{$2, rpg::RPGType::PACKED, 0, $5, $7, false};
        free($2);
    }
    | KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON {
        $$ = new rpg::ParamDecl{$2, rpg::RPGType::PACKED, 0, $5, $7, true};
        free($2);
    }
    | IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON {
        $$ = new rpg::ParamDecl{$1, rpg::RPGType::CHAR, 0, 0, 0, false, std::string($4)};
        free($1);
        free($4);
    }
    ;

/* Parameters for DCL-PR (same structure) */
pr_params:
    /* empty */ {
        $$ = new ParamList();
    }
    | pr_params pr_param {
        $$ = $1;
        $$->params.push_back(*$2);
        delete $2;
    }
    ;

pr_param:
    IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON {
        $$ = new rpg::ParamDecl{$1, rpg::RPGType::INT10, 0, 0, 0, false};
        free($1);
    }
    | IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON {
        $$ = new rpg::ParamDecl{$1, rpg::RPGType::INT10, 0, 0, 0, true};
        free($1);
    }
    | IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON {
        $$ = new rpg::ParamDecl{$1, rpg::RPGType::CHAR, $4, 0, 0, false};
        free($1);
    }
    | IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON {
        $$ = new rpg::ParamDecl{$1, rpg::RPGType::CHAR, $4, 0, 0, true};
        free($1);
    }
    | IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON {
        $$ = new rpg::ParamDecl{$1, rpg::RPGType::VARCHAR, $4, 0, 0, false};
        free($1);
    }
    | IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON {
        $$ = new rpg::ParamDecl{$1, rpg::RPGType::VARCHAR, $4, 0, 0, true};
        free($1);
    }
    | IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON {
        $$ = new rpg::ParamDecl{$1, rpg::RPGType::PACKED, 0, $4, $6, false};
        free($1);
    }
    | IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON {
        $$ = new rpg::ParamDecl{$1, rpg::RPGType::PACKED, 0, $4, $6, true};
        free($1);
    }
    /* DCL-PARM alternatives */
    | KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON {
        $$ = new rpg::ParamDecl{$2, rpg::RPGType::INT10, 0, 0, 0, false};
        free($2);
    }
    | KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON {
        $$ = new rpg::ParamDecl{$2, rpg::RPGType::INT10, 0, 0, 0, true};
        free($2);
    }
    | KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON {
        $$ = new rpg::ParamDecl{$2, rpg::RPGType::CHAR, $5, 0, 0, false};
        free($2);
    }
    | KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON {
        $$ = new rpg::ParamDecl{$2, rpg::RPGType::CHAR, $5, 0, 0, true};
        free($2);
    }
    | KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON {
        $$ = new rpg::ParamDecl{$2, rpg::RPGType::VARCHAR, $5, 0, 0, false};
        free($2);
    }
    | KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON {
        $$ = new rpg::ParamDecl{$2, rpg::RPGType::VARCHAR, $5, 0, 0, true};
        free($2);
    }
    | KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON {
        $$ = new rpg::ParamDecl{$2, rpg::RPGType::PACKED, 0, $5, $7, false};
        free($2);
    }
    | KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON {
        $$ = new rpg::ParamDecl{$2, rpg::RPGType::PACKED, 0, $5, $7, true};
        free($2);
    }
    | IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON {
        $$ = new rpg::ParamDecl{$1, rpg::RPGType::CHAR, 0, 0, 0, false, std::string($4)};
        free($1);
        free($4);
    }
    ;

/* --- Monitor / Subroutines --- */

monitor_stmt:
    KW_MONITOR SEMICOLON statement_list KW_ON_ERROR SEMICOLON statement_list KW_ENDMON SEMICOLON {
        auto* node = new rpg::MonitorStmt();
        for (auto* s : $3->stmts) node->try_body.emplace_back(s);
        delete $3;
        for (auto* s : $6->stmts) node->on_error_body.emplace_back(s);
        delete $6;
        $$ = node;
    }
    ;

begsr_stmt:
    KW_BEGSR IDENTIFIER SEMICOLON statement_list KW_ENDSR SEMICOLON {
        auto* node = new rpg::BegSR($2);
        for (auto* s : $4->stmts) node->body.emplace_back(s);
        delete $4;
        free($2);
        $$ = node;
    }
    ;

exsr_stmt:
    KW_EXSR IDENTIFIER SEMICOLON {
        $$ = new rpg::ExSR($2);
        free($2);
    }
    ;

/* SORTA */
sorta_stmt:
    KW_SORTA IDENTIFIER SEMICOLON {
        $$ = new rpg::SortAStmt($2);
        free($2);
    }
    ;

/* RESET and CLEAR */
reset_stmt:
    KW_RESET IDENTIFIER SEMICOLON {
        $$ = new rpg::ResetStmt($2);
        free($2);
    }
    ;

clear_stmt:
    KW_CLEAR IDENTIFIER SEMICOLON {
        $$ = new rpg::ClearStmt($2);
        free($2);
    }
    ;

/* --- Data Structures --- */

dcl_ds_stmt:
    /* DCL-DS name QUALIFIED; fields END-DS; */
    KW_DCL_DS IDENTIFIER KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON {
        auto* ds = new rpg::DclDS($2);
        ds->qualified = true;
        ds->fields = std::move($5->fields);
        delete $5;
        free($2);
        $$ = ds;
    }
    /* DCL-DS name; fields END-DS; (not qualified) */
    | KW_DCL_DS IDENTIFIER SEMICOLON ds_fields KW_END_DS SEMICOLON {
        auto* ds = new rpg::DclDS($2);
        ds->qualified = false;
        ds->fields = std::move($4->fields);
        delete $4;
        free($2);
        $$ = ds;
    }
    /* DCL-DS name DIM(n) QUALIFIED; fields END-DS; */
    | KW_DCL_DS IDENTIFIER KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON {
        auto* ds = new rpg::DclDS($2);
        ds->dim = $5;
        ds->qualified = true;
        ds->fields = std::move($9->fields);
        delete $9;
        free($2);
        $$ = ds;
    }
    /* DCL-DS name QUALIFIED DIM(n); fields END-DS; */
    | KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON {
        auto* ds = new rpg::DclDS($2);
        ds->dim = $6;
        ds->qualified = true;
        ds->fields = std::move($9->fields);
        delete $9;
        free($2);
        $$ = ds;
    }
    /* DCL-DS name LIKEDS(other); */
    | KW_DCL_DS IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON {
        auto* ds = new rpg::DclDS($2);
        ds->like_ds = $5;
        free($2);
        free($5);
        $$ = ds;
    }
    /* DCL-DS name LIKEDS(other) DIM(n); */
    | KW_DCL_DS IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON {
        auto* ds = new rpg::DclDS($2);
        ds->like_ds = $5;
        ds->dim = $9;
        free($2);
        free($5);
        $$ = ds;
    }
    ;

ds_fields:
    /* empty */ {
        $$ = new DSFieldList();
    }
    | ds_fields ds_field {
        $$ = $1;
        $$->fields.push_back(*$2);
        delete $2;
    }
    ;

ds_field:
    IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON {
        $$ = new rpg::DSField{$1, rpg::RPGType::INT10, 0, 0, 0};
        free($1);
    }
    | IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON {
        $$ = new rpg::DSField{$1, rpg::RPGType::CHAR, $4, 0, 0};
        free($1);
    }
    | IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON {
        $$ = new rpg::DSField{$1, rpg::RPGType::VARCHAR, $4, 0, 0};
        free($1);
    }
    | IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON {
        $$ = new rpg::DSField{$1, rpg::RPGType::PACKED, 0, $4, $6};
        free($1);
    }
    /* DCL-SUBF alternatives */
    | KW_DCL_SUBF IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON {
        $$ = new rpg::DSField{$2, rpg::RPGType::INT10, 0, 0, 0};
        free($2);
    }
    | KW_DCL_SUBF IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON {
        $$ = new rpg::DSField{$2, rpg::RPGType::CHAR, $5, 0, 0};
        free($2);
    }
    | KW_DCL_SUBF IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON {
        $$ = new rpg::DSField{$2, rpg::RPGType::VARCHAR, $5, 0, 0};
        free($2);
    }
    | KW_DCL_SUBF IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON {
        $$ = new rpg::DSField{$2, rpg::RPGType::PACKED, 0, $5, $7};
        free($2);
    }
    ;

/* --- Control Flow --- */

if_stmt:
    KW_IF expression SEMICOLON statement_list elseif_clauses else_clause KW_ENDIF SEMICOLON {
        auto* node = new rpg::IfStmt(std::unique_ptr<rpg::Expression>($2));
        for (auto* s : $4->stmts) node->then_body.emplace_back(s);
        delete $4;
        if ($5) {
            for (auto* eif : *$5) {
                rpg::ElseIfBranch branch;
                branch.condition.reset(eif->cond);
                for (auto* s : eif->body) branch.body.emplace_back(s);
                node->elseif_branches.push_back(std::move(branch));
                delete eif;
            }
            delete $5;
        }
        if ($6) {
            for (auto* s : $6->stmts) node->else_body.emplace_back(s);
            delete $6;
        }
        $$ = node;
    }
    ;

elseif_clauses:
    /* empty */ { $$ = nullptr; }
    | elseif_clauses elseif_clause {
        if (!$1) $1 = new std::vector<ElseIfData*>();
        $$ = $1;
        $$->push_back($2);
    }
    ;

elseif_clause:
    KW_ELSEIF expression SEMICOLON statement_list {
        $$ = new ElseIfData();
        $$->cond = $2;
        $$->body = std::move($4->stmts);
        delete $4;
    }
    ;

else_clause:
    /* empty */ { $$ = nullptr; }
    | KW_ELSE SEMICOLON statement_list {
        $$ = $3;
    }
    ;

dow_stmt:
    KW_DOW expression SEMICOLON statement_list KW_ENDDO SEMICOLON {
        auto* node = new rpg::DowStmt(std::unique_ptr<rpg::Expression>($2));
        for (auto* s : $4->stmts) node->body.emplace_back(s);
        delete $4;
        $$ = node;
    }
    ;

dou_stmt:
    KW_DOU expression SEMICOLON statement_list KW_ENDDO SEMICOLON {
        auto* node = new rpg::DouStmt(std::unique_ptr<rpg::Expression>($2));
        for (auto* s : $4->stmts) node->body.emplace_back(s);
        delete $4;
        $$ = node;
    }
    ;

for_stmt:
    KW_FOR IDENTIFIER EQUALS expression KW_TO expression SEMICOLON statement_list KW_ENDFOR SEMICOLON {
        auto* node = new rpg::ForStmt($2,
            std::unique_ptr<rpg::Expression>($4),
            std::unique_ptr<rpg::Expression>($6),
            nullptr, false);
        for (auto* s : $8->stmts) node->body.emplace_back(s);
        delete $8;
        free($2);
        $$ = node;
    }
    | KW_FOR IDENTIFIER EQUALS expression KW_TO expression KW_BY expression SEMICOLON statement_list KW_ENDFOR SEMICOLON {
        auto* node = new rpg::ForStmt($2,
            std::unique_ptr<rpg::Expression>($4),
            std::unique_ptr<rpg::Expression>($6),
            std::unique_ptr<rpg::Expression>($8), false);
        for (auto* s : $10->stmts) node->body.emplace_back(s);
        delete $10;
        free($2);
        $$ = node;
    }
    | KW_FOR IDENTIFIER EQUALS expression KW_DOWNTO expression SEMICOLON statement_list KW_ENDFOR SEMICOLON {
        auto* node = new rpg::ForStmt($2,
            std::unique_ptr<rpg::Expression>($4),
            std::unique_ptr<rpg::Expression>($6),
            nullptr, true);
        for (auto* s : $8->stmts) node->body.emplace_back(s);
        delete $8;
        free($2);
        $$ = node;
    }
    | KW_FOR IDENTIFIER EQUALS expression KW_DOWNTO expression KW_BY expression SEMICOLON statement_list KW_ENDFOR SEMICOLON {
        auto* node = new rpg::ForStmt($2,
            std::unique_ptr<rpg::Expression>($4),
            std::unique_ptr<rpg::Expression>($6),
            std::unique_ptr<rpg::Expression>($8), true);
        for (auto* s : $10->stmts) node->body.emplace_back(s);
        delete $10;
        free($2);
        $$ = node;
    }
    ;

select_stmt:
    KW_SELECT SEMICOLON when_clauses other_clause KW_ENDSL SEMICOLON {
        auto* node = new rpg::SelectStmt();
        for (auto* w : *$3) {
            rpg::WhenBranch branch;
            branch.condition.reset(w->cond);
            for (auto* s : w->body) branch.body.emplace_back(s);
            node->when_branches.push_back(std::move(branch));
            delete w;
        }
        delete $3;
        if ($4) {
            for (auto* s : $4->stmts) node->other_body.emplace_back(s);
            delete $4;
        }
        $$ = node;
    }
    ;

when_clauses:
    when_clause {
        $$ = new std::vector<WhenData*>();
        $$->push_back($1);
    }
    | when_clauses when_clause {
        $$ = $1;
        $$->push_back($2);
    }
    ;

when_clause:
    KW_WHEN expression SEMICOLON statement_list {
        $$ = new WhenData();
        $$->cond = $2;
        $$->body = std::move($4->stmts);
        delete $4;
    }
    ;

other_clause:
    /* empty */ { $$ = nullptr; }
    | KW_OTHER SEMICOLON statement_list {
        $$ = $3;
    }
    ;

iter_stmt:
    KW_ITER SEMICOLON { $$ = new rpg::IterStmt(); }
    ;

leave_stmt:
    KW_LEAVE SEMICOLON { $$ = new rpg::LeaveStmt(); }
    ;

/* --- Expressions --- */

expression:
    or_expr { $$ = $1; }
    ;

or_expr:
    and_expr { $$ = $1; }
    | or_expr KW_OR and_expr {
        $$ = new rpg::BinaryExpr(rpg::BinOp::OR,
            std::unique_ptr<rpg::Expression>($1),
            std::unique_ptr<rpg::Expression>($3));
    }
    ;

and_expr:
    not_expr { $$ = $1; }
    | and_expr KW_AND not_expr {
        $$ = new rpg::BinaryExpr(rpg::BinOp::AND,
            std::unique_ptr<rpg::Expression>($1),
            std::unique_ptr<rpg::Expression>($3));
    }
    ;

not_expr:
    comparison_expr { $$ = $1; }
    | KW_NOT comparison_expr {
        $$ = new rpg::NotExpr(std::unique_ptr<rpg::Expression>($2));
    }
    ;

comparison_expr:
    additive_expr { $$ = $1; }
    | comparison_expr EQUALS additive_expr {
        $$ = new rpg::BinaryExpr(rpg::BinOp::EQ,
            std::unique_ptr<rpg::Expression>($1),
            std::unique_ptr<rpg::Expression>($3));
    }
    | comparison_expr NE additive_expr {
        $$ = new rpg::BinaryExpr(rpg::BinOp::NE,
            std::unique_ptr<rpg::Expression>($1),
            std::unique_ptr<rpg::Expression>($3));
    }
    | comparison_expr LT additive_expr {
        $$ = new rpg::BinaryExpr(rpg::BinOp::LT,
            std::unique_ptr<rpg::Expression>($1),
            std::unique_ptr<rpg::Expression>($3));
    }
    | comparison_expr GT additive_expr {
        $$ = new rpg::BinaryExpr(rpg::BinOp::GT,
            std::unique_ptr<rpg::Expression>($1),
            std::unique_ptr<rpg::Expression>($3));
    }
    | comparison_expr LE additive_expr {
        $$ = new rpg::BinaryExpr(rpg::BinOp::LE,
            std::unique_ptr<rpg::Expression>($1),
            std::unique_ptr<rpg::Expression>($3));
    }
    | comparison_expr GE additive_expr {
        $$ = new rpg::BinaryExpr(rpg::BinOp::GE,
            std::unique_ptr<rpg::Expression>($1),
            std::unique_ptr<rpg::Expression>($3));
    }
    ;

additive_expr:
    multiplicative_expr { $$ = $1; }
    | additive_expr PLUS multiplicative_expr {
        $$ = new rpg::BinaryExpr(rpg::BinOp::ADD,
            std::unique_ptr<rpg::Expression>($1),
            std::unique_ptr<rpg::Expression>($3));
    }
    | additive_expr MINUS multiplicative_expr {
        $$ = new rpg::BinaryExpr(rpg::BinOp::SUB,
            std::unique_ptr<rpg::Expression>($1),
            std::unique_ptr<rpg::Expression>($3));
    }
    ;

multiplicative_expr:
    unary_expr { $$ = $1; }
    | multiplicative_expr STAR unary_expr {
        $$ = new rpg::BinaryExpr(rpg::BinOp::MUL,
            std::unique_ptr<rpg::Expression>($1),
            std::unique_ptr<rpg::Expression>($3));
    }
    | multiplicative_expr SLASH unary_expr {
        $$ = new rpg::BinaryExpr(rpg::BinOp::DIV,
            std::unique_ptr<rpg::Expression>($1),
            std::unique_ptr<rpg::Expression>($3));
    }
    ;

unary_expr:
    postfix_expr { $$ = $1; }
    | MINUS postfix_expr {
        $$ = new rpg::BinaryExpr(rpg::BinOp::SUB,
            std::unique_ptr<rpg::Expression>(new rpg::IntLiteral(0)),
            std::unique_ptr<rpg::Expression>($2));
    }
    ;

postfix_expr:
    primary_expr { $$ = $1; }
    | postfix_expr DOT IDENTIFIER {
        $$ = new rpg::DotExpr(std::unique_ptr<rpg::Expression>($1), $3);
        free($3);
    }
    ;

primary_expr:
    IDENTIFIER {
        $$ = new rpg::Identifier($1);
        free($1);
    }
    | INTEGER_LITERAL {
        $$ = new rpg::IntLiteral($1);
    }
    | FLOAT_LITERAL {
        $$ = new rpg::FloatLiteral($1);
    }
    | STRING_LITERAL {
        $$ = new rpg::StringLiteral($1);
        free($1);
    }
    | IDENTIFIER LPAREN call_args_opt RPAREN {
        $$ = make_func($1, $3);
        free($1);
    }
    | BIF_CHAR LPAREN arg_list RPAREN {
        $$ = make_bif("CHAR", $3);
    }
    | BIF_TRIM LPAREN arg_list RPAREN {
        $$ = make_bif("TRIM", $3);
    }
    | BIF_TRIML LPAREN arg_list RPAREN {
        $$ = make_bif("TRIML", $3);
    }
    | BIF_TRIMR LPAREN arg_list RPAREN {
        $$ = make_bif("TRIMR", $3);
    }
    | BIF_LEN LPAREN arg_list RPAREN {
        $$ = make_bif("LEN", $3);
    }
    | BIF_SUBST LPAREN arg_list RPAREN {
        $$ = make_bif("SUBST", $3);
    }
    | BIF_SCAN LPAREN arg_list RPAREN {
        $$ = make_bif("SCAN", $3);
    }
    | BIF_SCANRPL LPAREN arg_list RPAREN {
        $$ = make_bif("SCANRPL", $3);
    }
    | BIF_XLATE LPAREN arg_list RPAREN {
        $$ = make_bif("XLATE", $3);
    }
    | BIF_DEC LPAREN arg_list RPAREN {
        $$ = make_bif("DEC", $3);
    }
    | BIF_INT LPAREN arg_list RPAREN {
        $$ = make_bif("INT", $3);
    }
    | BIF_ELEM LPAREN arg_list RPAREN {
        $$ = make_bif("ELEM", $3);
    }
    | BIF_PARMS LPAREN RPAREN {
        auto* empty = new std::vector<rpg::Expression*>();
        $$ = make_bif("PARMS", empty);
    }
    | BIF_LOOKUP LPAREN arg_list RPAREN {
        $$ = make_bif("LOOKUP", $3);
    }
    | BIF_EDITC LPAREN arg_list RPAREN {
        $$ = make_bif("EDITC", $3);
    }
    | BIF_EDITW LPAREN arg_list RPAREN {
        $$ = make_bif("EDITW", $3);
    }
    | BIF_REPLACE LPAREN arg_list RPAREN {
        $$ = make_bif("REPLACE", $3);
    }
    | BIF_CHECK LPAREN arg_list RPAREN {
        $$ = make_bif("CHECK", $3);
    }
    | BIF_CHECKR LPAREN arg_list RPAREN {
        $$ = make_bif("CHECKR", $3);
    }
    | BIF_MAX LPAREN arg_list RPAREN {
        $$ = make_bif("MAX", $3);
    }
    | BIF_MIN LPAREN arg_list RPAREN {
        $$ = make_bif("MIN", $3);
    }
    | BIF_STATUS LPAREN RPAREN {
        auto* empty = new std::vector<rpg::Expression*>();
        $$ = make_bif("STATUS", empty);
    }
    | BIF_ERROR LPAREN RPAREN {
        auto* empty = new std::vector<rpg::Expression*>();
        $$ = make_bif("ERROR", empty);
    }
    | BIF_SIZE LPAREN arg_list RPAREN {
        $$ = make_bif("SIZE", $3);
    }
    | BIF_ADDR LPAREN arg_list RPAREN {
        $$ = make_bif("ADDR", $3);
    }
    | BIF_ABS LPAREN arg_list RPAREN {
        $$ = make_bif("ABS", $3);
    }
    | BIF_DIV LPAREN arg_list RPAREN {
        $$ = make_bif("DIV", $3);
    }
    | BIF_REM LPAREN arg_list RPAREN {
        $$ = make_bif("REM", $3);
    }
    | BIF_DATE LPAREN arg_list RPAREN {
        $$ = make_bif("DATE", $3);
    }
    | BIF_DATE LPAREN RPAREN {
        auto* empty = new std::vector<rpg::Expression*>();
        $$ = make_bif("DATE", empty);
    }
    | BIF_TIME LPAREN arg_list RPAREN {
        $$ = make_bif("TIME", $3);
    }
    | BIF_TIME LPAREN RPAREN {
        auto* empty = new std::vector<rpg::Expression*>();
        $$ = make_bif("TIME", empty);
    }
    | BIF_TIMESTAMP LPAREN arg_list RPAREN {
        $$ = make_bif("TIMESTAMP", $3);
    }
    | BIF_TIMESTAMP LPAREN RPAREN {
        auto* empty = new std::vector<rpg::Expression*>();
        $$ = make_bif("TIMESTAMP", empty);
    }
    | BIF_DIFF LPAREN expression COLON expression COLON KW_DAYS RPAREN {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back($3);
        args->push_back($5);
        args->push_back(new rpg::StringLiteral("DAYS"));
        $$ = make_bif("DIFF", args);
    }
    | BIF_DIFF LPAREN expression COLON expression COLON KW_MONTHS RPAREN {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back($3);
        args->push_back($5);
        args->push_back(new rpg::StringLiteral("MONTHS"));
        $$ = make_bif("DIFF", args);
    }
    | BIF_DIFF LPAREN expression COLON expression COLON KW_YEARS RPAREN {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back($3);
        args->push_back($5);
        args->push_back(new rpg::StringLiteral("YEARS"));
        $$ = make_bif("DIFF", args);
    }
    | BIF_DAYS LPAREN expression RPAREN {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back($3);
        $$ = make_bif("DAYS", args);
    }
    | BIF_MONTHS LPAREN expression RPAREN {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back($3);
        $$ = make_bif("MONTHS", args);
    }
    | BIF_YEARS LPAREN expression RPAREN {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back($3);
        $$ = make_bif("YEARS", args);
    }
    | BIF_FOUND LPAREN RPAREN {
        auto* empty = new std::vector<rpg::Expression*>();
        $$ = make_bif("FOUND", empty);
    }
    | BIF_EOF LPAREN RPAREN {
        auto* empty = new std::vector<rpg::Expression*>();
        $$ = make_bif("EOF", empty);
    }
    | INDICATOR {
        $$ = new rpg::IndicatorExpr($1);
    }
    | KW_ON {
        $$ = new rpg::IntLiteral(1);  // *ON → true
    }
    | KW_OFF {
        $$ = new rpg::IntLiteral(0);  // *OFF → false
    }
    | KW_NULL {
        $$ = new rpg::Identifier("nullptr");
    }
    | LPAREN expression RPAREN {
        $$ = $2;
    }
    ;

/* Function call arguments use comma separator */
call_args_opt:
    /* empty */ { $$ = nullptr; }
    | call_arg_list { $$ = $1; }
    ;

call_arg_list:
    expression {
        $$ = new std::vector<rpg::Expression*>();
        $$->push_back($1);
    }
    | call_arg_list COLON expression {
        $$ = $1;
        $$->push_back($3);
    }
    ;

/* BIF arguments use colon separator */
arg_list:
    expression {
        $$ = new std::vector<rpg::Expression*>();
        $$->push_back($1);
    }
    | arg_list COLON expression {
        $$ = $1;
        $$->push_back($3);
    }
    ;

%%

void yyerror(const char* s) {
    g_error_count++;
    fprintf(stderr, "Error at line %d: %s (near '%s')\n", yylineno, s, yytext);
}

rpg::Program* get_parsed_program() {
    g_program = new rpg::Program();
    g_error_count = 0;
    yyparse();
    return g_program;
}

int get_parse_error_count() {
    return g_error_count;
}
