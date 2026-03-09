%{
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <string>
#include "ast.h"
#include "parser.h"

static char* process_rpg_string(const char* text) {
    size_t len = strlen(text);
    char* result = (char*)malloc(len);
    size_t j = 0;
    for (size_t i = 1; i < len - 1; i++) {
        if (text[i] == '\'' && i + 1 < len - 1 && text[i+1] == '\'') {
            result[j++] = '\'';
            i++;
        } else {
            result[j++] = text[i];
        }
    }
    result[j] = '\0';
    return result;
}

// Buffer stack for /COPY and /INCLUDE
#define MAX_INCLUDE_DEPTH 10
static YY_BUFFER_STATE include_stack[MAX_INCLUDE_DEPTH];
static int include_stack_ptr = 0;
%}

%option noyywrap
%option case-insensitive
%option yylineno

%%

"**FREE"            { return KW_FREE; }
"DCL-S"             { return KW_DCL_S; }
"DCL-C"             { return KW_DCL_C; }
"CHAR"              { return KW_CHAR; }
"VARCHAR"           { return KW_VARCHAR; }
"INT"               { return KW_INT; }
"PACKED"            { return KW_PACKED; }
"ZONED"             { return KW_ZONED; }
"CONST"             { return KW_CONST; }
"DATE"              { return KW_DATE; }
"TIME"              { return KW_TIME; }
"TIMESTAMP"         { return KW_TIMESTAMP; }
"INZ"               { return KW_INZ; }
"DSPLY"             { return KW_DSPLY; }
"EVAL"              { return KW_EVAL; }
"RETURN"            { return KW_RETURN; }
"DCL-PROC"          { return KW_DCL_PROC; }
"END-PROC"          { return KW_END_PROC; }
"DCL-PI"            { return KW_DCL_PI; }
"END-PI"            { return KW_END_PI; }
"DCL-PR"            { return KW_DCL_PR; }
"END-PR"            { return KW_END_PR; }
"VALUE"             { return KW_VALUE; }
"DCL-DS"            { return KW_DCL_DS; }
"END-DS"            { return KW_END_DS; }
"QUALIFIED"         { return KW_QUALIFIED; }
"DIM"               { return KW_DIM; }
"LIKEDS"            { return KW_LIKEDS; }

"IF"                { return KW_IF; }
"ELSEIF"            { return KW_ELSEIF; }
"ELSE"              { return KW_ELSE; }
"ENDIF"             { return KW_ENDIF; }
"DOU"               { return KW_DOU; }
"DOW"               { return KW_DOW; }
"ENDDO"             { return KW_ENDDO; }
"FOR"               { return KW_FOR; }
"ENDFOR"            { return KW_ENDFOR; }
"TO"                { return KW_TO; }
"DOWNTO"            { return KW_DOWNTO; }
"BY"                { return KW_BY; }
"SELECT"            { return KW_SELECT; }
"WHEN"              { return KW_WHEN; }
"OTHER"             { return KW_OTHER; }
"ENDSL"             { return KW_ENDSL; }
"ITER"              { return KW_ITER; }
"LEAVE"             { return KW_LEAVE; }
"MONITOR"           { return KW_MONITOR; }
"ON-ERROR"          { return KW_ON_ERROR; }
"ENDMON"            { return KW_ENDMON; }
"BEGSR"             { return KW_BEGSR; }
"ENDSR"             { return KW_ENDSR; }
"EXSR"              { return KW_EXSR; }
"AND"               { return KW_AND; }
"OR"                { return KW_OR; }
"NOT"               { return KW_NOT; }

"%CHAR"             { return BIF_CHAR; }
"%TRIM"             { return BIF_TRIM; }
"%TRIML"            { return BIF_TRIML; }
"%TRIMR"            { return BIF_TRIMR; }
"%LEN"              { return BIF_LEN; }
"%SUBST"            { return BIF_SUBST; }
"%SCAN"             { return BIF_SCAN; }
"%SCANRPL"          { return BIF_SCANRPL; }
"%XLATE"            { return BIF_XLATE; }
"%DEC"              { return BIF_DEC; }
"%INT"              { return BIF_INT; }
"%ELEM"             { return BIF_ELEM; }
"%FOUND"            { return BIF_FOUND; }
"%EOF"              { return BIF_EOF; }
"%DATE"             { return BIF_DATE; }
"%TIME"             { return BIF_TIME; }
"%TIMESTAMP"        { return BIF_TIMESTAMP; }
"%DIFF"             { return BIF_DIFF; }
"%DAYS"             { return BIF_DAYS; }
"%MONTHS"           { return BIF_MONTHS; }
"%YEARS"            { return BIF_YEARS; }
"*INLR"             { return KW_INLR; }
"*ON"               { return KW_ON; }
"*OFF"              { return KW_OFF; }
"*DAYS"             { return KW_DAYS; }
"*MONTHS"           { return KW_MONTHS; }
"*YEARS"            { return KW_YEARS; }
"*IN"[0-9][0-9]     { yylval.ival = atoi(yytext + 3); return INDICATOR; }

";"                 { return SEMICOLON; }
"="                 { return EQUALS; }
"("                 { return LPAREN; }
")"                 { return RPAREN; }
":"                 { return COLON; }
"+"                 { return PLUS; }
"-"                 { return MINUS; }
"*"                 { return STAR; }
"/"                 { return SLASH; }
"<>"                { return NE; }
"<="                { return LE; }
">="                { return GE; }
"<"                 { return LT; }
">"                 { return GT; }
"."                 { return DOT; }

 /* /COPY and /INCLUDE directives */
^[ \t]*"/"[Cc][Oo][Pp][Yy][ \t]+[^\n]+ {
    /* Extract filename from /COPY directive */
    const char* p = yytext;
    while (*p == ' ' || *p == '\t') p++;
    p++; /* skip '/' */
    while (*p && *p != ' ' && *p != '\t') p++; /* skip COPY */
    while (*p == ' ' || *p == '\t') p++;
    /* p now points to filename; trim trailing whitespace */
    char filename[256];
    int k = 0;
    while (*p && *p != '\n' && *p != '\r' && k < 255) {
        filename[k++] = *p++;
    }
    filename[k] = '\0';
    /* Trim trailing whitespace */
    while (k > 0 && (filename[k-1] == ' ' || filename[k-1] == '\t')) {
        filename[--k] = '\0';
    }

    if (include_stack_ptr >= MAX_INCLUDE_DEPTH) {
        fprintf(stderr, "Error: /COPY nesting too deep\n");
    } else {
        FILE* f = fopen(filename, "r");
        if (!f) {
            fprintf(stderr, "Error: cannot open /COPY file '%s'\n", filename);
        } else {
            include_stack[include_stack_ptr++] = YY_CURRENT_BUFFER;
            yy_switch_to_buffer(yy_create_buffer(f, YY_BUF_SIZE));
        }
    }
}

^[ \t]*"/"[Ii][Nn][Cc][Ll][Uu][Dd][Ee][ \t]+[^\n]+ {
    /* Same as /COPY */
    const char* p = yytext;
    while (*p == ' ' || *p == '\t') p++;
    p++;
    while (*p && *p != ' ' && *p != '\t') p++;
    while (*p == ' ' || *p == '\t') p++;
    char filename[256];
    int k = 0;
    while (*p && *p != '\n' && *p != '\r' && k < 255) {
        filename[k++] = *p++;
    }
    filename[k] = '\0';
    while (k > 0 && (filename[k-1] == ' ' || filename[k-1] == '\t')) {
        filename[--k] = '\0';
    }

    if (include_stack_ptr >= MAX_INCLUDE_DEPTH) {
        fprintf(stderr, "Error: /INCLUDE nesting too deep\n");
    } else {
        FILE* f = fopen(filename, "r");
        if (!f) {
            fprintf(stderr, "Error: cannot open /INCLUDE file '%s'\n", filename);
        } else {
            include_stack[include_stack_ptr++] = YY_CURRENT_BUFFER;
            yy_switch_to_buffer(yy_create_buffer(f, YY_BUF_SIZE));
        }
    }
}

<<EOF>> {
    if (include_stack_ptr > 0) {
        yy_delete_buffer(YY_CURRENT_BUFFER);
        yy_switch_to_buffer(include_stack[--include_stack_ptr]);
    } else {
        yyterminate();
    }
}

[0-9]+\.[0-9]+      { yylval.fval = atof(yytext); return FLOAT_LITERAL; }
[0-9]+              { yylval.ival = atoi(yytext); return INTEGER_LITERAL; }

'([^']|'')*'        { yylval.sval = process_rpg_string(yytext); return STRING_LITERAL; }

[a-zA-Z_][a-zA-Z0-9_]* {
    yylval.sval = strdup(yytext);
    return IDENTIFIER;
}

"//".*              { /* single-line comment, ignore */ }
[ \t\r\n]+          { /* whitespace, ignore */ }

.                   { fprintf(stderr, "Unexpected character: '%c' at line %d\n", *yytext, yylineno); }

%%
