%{
    #include "parser.tab.h"
    #include "string.h"
    int line_number = 0;
    char *message;
%}

%option yylineno
ID          [a-z][a-z0-9]*
DIGITS      [0-9]*
%%
"**FREE"    { return FREE; }
"dsply"     { return DISPLAY; }
"dcl-s"     { return DECLARE_STANDALONE; }
"zoned"     { return ZONED; }
"char"      { return CHAR; }
":"         { return COLON; }
"("         { return LEFT_PARENTHESIS; }
")"         { return RIGHT_PARENTHESIS; }
"="         { return EQUALS; }
[\n]        { line_number++; }
{DIGITS}    {
                message = yytext;
                return DIGITS;
            }
{ID}        { 
                message = yytext;
                return ID;
            }
['].*[']    { 
                message = yytext;
                return STR; 
            }
"*on"       { return ON; }
"*inlr"     { return INLR; }
";"         { return SEMI_COLON; }

%%

int yywrap() {
    return 1;
}