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

"\n"         { program_line_number = program_line_number + 1; }
"**FREE"     return FREE;
";"          return SEMI_COLON;
"DCL-S"      return DECLARE_S;
"DCL-DS"     return DECLARE_DS;
"END-DS"     return END_DS;
"QUALIFIED"  return QUALIFIED;
"OPTIONS"    return OPTIONS;
"INT"        return INT;
"INZ"        return INZ;
"*ON"        return ON;
"RETURN"     return RETURN;
"*INLR"      return INLR;
"="          return EQUALS;
"CHAR"       return CHAR;
"ZONED"      return ZONED;
"EXEC SQL"   return EXEC_SQL;
"/*"         return BEG_COMMENT;
"*/"         return END_COMMENT;
"("          return LEFT_PARENS;
")"          return RIGHT_PARENS;
":"          return COLON;
[ \t\n]+     {}
{identifier} return IDENTIFIER;
%%
