%option noyywrap 

%{
#include <stdio.h>
#define YY_DECL int yylex()
int program_line_number = 1;
#include "rpg.tab.h"
%}

blanks       [ \t\n]+
identifier   [_a-zA-Z0-9]+

%%

"\n"         { program_line_number++; return NEW_LINE; }
"**FREE"     return FREE;
";"          return SEMI_COLON;
"DCL-F"      return DECLARE_F;
"OPTIONS"    return OPTIONS;
"("          return LEFT_PARENS;
")"          return RIGHT_PARENS;
"*INPUT"     return INPUT;
"*OUTPUT"    return OUTPUT;
"*UPDATE"    return UPDATE;
":"          return COLON;
{blanks}     {}
{identifier} return IDENTIFIER;
%%
