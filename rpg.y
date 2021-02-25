%{

#include <stdio.h>
#include <stdlib.h>

extern int yylex();
extern int yyparse();
extern FILE* yyin;
extern int program_line_number;

void yyerror(const char* s);
%}

%token SEMI_COLON FREE DECLARE_F NEW_LINE IDENTIFIER LEFT_PARENS RIGHT_PARENS OPTIONS
       INPUT OUTPUT UPDATE COLON

%%
program: 
       | FREE NEW_LINE specs
       ;

specs: 
       | f_specs specs
       ;

f_specs: DECLARE_F IDENTIFIER SEMI_COLON NEW_LINE
       | DECLARE_F IDENTIFIER OPTIONS LEFT_PARENS f_spec_options RIGHT_PARENS SEMI_COLON NEW_LINE
       ;

f_spec_options: 
       | INPUT f_spec_options
       | INPUT COLON f_spec_options
       | OUTPUT f_spec_options
       | OUTPUT COLON f_spec_options
       | UPDATE f_spec_options
       | UPDATE COLON f_spec_options
       ;
%%

int main(void) {
     yyparse();
}

void yyerror(const char* s) {
  printf("Parse error: %s on line %d\n", s, program_line_number);
}
