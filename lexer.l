%{
    #include "parser.tab.h"
    #include "string.h"
    int line_number = 0;
    char *message;
%}

%option yylineno

%%
"**FREE"    { return FREE; }
"dsply"     { return DISPLAY; }
"="         { return EQUALS; }
[\n]        { line_number++; }
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