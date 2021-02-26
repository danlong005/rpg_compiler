%{

#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern int yyparse();
extern FILE* yyin;
extern int program_line_number;

void yyerror(const char* s);
%}

%token SEMI_COLON FREE IDENTIFIER LEFT_PARENS RIGHT_PARENS OPTIONS
       COLON DECLARE_S BEG_COMMENT END_COMMENT INT ZONED INZ CHAR RETURN INLR EQUALS ON DECLARE_DS END_DS
       QUALIFIED EXEC_SQL

%%
program: 
       | FREE specs
       ;

specs: 
       | d_specs specs
       | c_specs specs
       | RETURN SEMI_COLON
       ;

d_specs: DECLARE_S IDENTIFIER d_spec_options SEMI_COLON
       | DECLARE_DS IDENTIFIER QUALIFIED SEMI_COLON ds_specs END_DS SEMI_COLON
       ;

ds_specs: 
       | IDENTIFIER d_spec_options SEMI_COLON ds_specs;
       ;

d_spec_options:
       | INT LEFT_PARENS IDENTIFIER COLON IDENTIFIER RIGHT_PARENS
       | INT LEFT_PARENS IDENTIFIER COLON IDENTIFIER RIGHT_PARENS INZ
       | ZONED LEFT_PARENS IDENTIFIER COLON IDENTIFIER RIGHT_PARENS
       | ZONED LEFT_PARENS IDENTIFIER COLON IDENTIFIER RIGHT_PARENS INZ
       | CHAR LEFT_PARENS IDENTIFIER RIGHT_PARENS 
       | CHAR LEFT_PARENS IDENTIFIER RIGHT_PARENS INZ
       ;

c_specs: IDENTIFIER EQUALS IDENTIFIER SEMI_COLON
       | EXEC_SQL SEMI_COLON
       ;

%%

int main(void) {
     yyparse();
}

void yyerror(const char* s) {
  printf("Parse error: %s\n", s);
}
