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

// Conditional compilation
#include <set>
static std::set<std::string> cond_defines;
#define MAX_COND_DEPTH 20
static bool cond_active[MAX_COND_DEPTH]; // is this level active?
static bool cond_done[MAX_COND_DEPTH];   // has any branch been taken?
static int cond_depth = 0;

static bool cond_is_active() {
    // Active if ALL levels in the stack are active
    for (int i = 1; i <= cond_depth; i++) {
        if (!cond_active[i]) return false;
    }
    return true;
}

static std::string cond_extract_symbol(const char* text) {
    // Extract symbol from "DEFINED(SYMBOL)" pattern
    const char* p = text;
    while (*p && *p != '(') p++;
    if (*p == '(') p++;
    std::string sym;
    while (*p && *p != ')' && *p != ' ' && *p != '\t') {
        sym += toupper(*p);
        p++;
    }
    return sym;
}

static std::string cond_toupper(const std::string& s) {
    std::string r = s;
    for (auto& c : r) c = toupper(c);
    return r;
}
%}

%option noyywrap
%option case-insensitive
%option yylineno

%x SKIPPING

%%

"**FREE"            { return KW_FREE; }
"DCL-F"             { return KW_DCL_F; }
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
"POINTER"           { return KW_POINTER; }
"DISK"              { return KW_DISK; }
"PRINTER"           { return KW_PRINTER; }
"WORKSTN"           { return KW_WORKSTN; }
"USAGE"             { return KW_USAGE; }
"INZ"               { return KW_INZ; }
"DSPLY"             { return KW_DSPLY; }
"EVAL-CORR"         { return KW_EVAL_CORR; }
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
"DCL-SUBF"          { return KW_DCL_SUBF; }
"DCL-PARM"          { return KW_DCL_PARM; }
"END-DS"            { return KW_END_DS; }
"QUALIFIED"         { return KW_QUALIFIED; }
"DIM"               { return KW_DIM; }
"LIKEDS"            { return KW_LIKEDS; }
"LIKE"              { return KW_LIKE; }

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
"RESET"             { return KW_RESET; }
"SORTA"             { return KW_SORTA; }
"CLEAR"             { return KW_CLEAR; }
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
"%PARMS"            { return BIF_PARMS; }
"%STATUS"           { return BIF_STATUS; }
"%ERROR"            { return BIF_ERROR; }
"%LOOKUP"           { return BIF_LOOKUP; }
"%MAX"              { return BIF_MAX; }
"%MIN"              { return BIF_MIN; }
"%SIZE"             { return BIF_SIZE; }
"%ADDR"             { return BIF_ADDR; }
"%ABS"              { return BIF_ABS; }
"%DIV"              { return BIF_DIV; }
"%REM"              { return BIF_REM; }
"%FOUND"            { return BIF_FOUND; }
"%EDITC"            { return BIF_EDITC; }
"%EDITW"            { return BIF_EDITW; }
"%REPLACE"          { return BIF_REPLACE; }
"%CHECK"            { return BIF_CHECK; }
"%CHECKR"           { return BIF_CHECKR; }
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
"*NULL"             { return KW_NULL; }
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

 /* Conditional compilation directives - processed in both INITIAL and SKIPPING states */
<INITIAL,SKIPPING>^[ \t]*"/"[Dd][Ee][Ff][Ii][Nn][Ee][ \t]+[a-zA-Z_][a-zA-Z0-9_]* {
    if (cond_is_active()) {
        const char* p = yytext;
        while (*p == ' ' || *p == '\t') p++;
        p++;
        while (*p && *p != ' ' && *p != '\t') p++;
        while (*p == ' ' || *p == '\t') p++;
        std::string sym;
        while (*p && *p != ' ' && *p != '\t' && *p != '\n') {
            sym += toupper(*p); p++;
        }
        cond_defines.insert(sym);
    }
}

<INITIAL,SKIPPING>^[ \t]*"/"[Uu][Nn][Dd][Ee][Ff][Ii][Nn][Ee][ \t]+[a-zA-Z_][a-zA-Z0-9_]* {
    if (cond_is_active()) {
        const char* p = yytext;
        while (*p == ' ' || *p == '\t') p++;
        p++;
        while (*p && *p != ' ' && *p != '\t') p++;
        while (*p == ' ' || *p == '\t') p++;
        std::string sym;
        while (*p && *p != ' ' && *p != '\t' && *p != '\n') {
            sym += toupper(*p); p++;
        }
        cond_defines.erase(sym);
    }
}

<INITIAL,SKIPPING>^[ \t]*"/"[Ii][Ff][ \t]+[Dd][Ee][Ff][Ii][Nn][Ee][Dd][ \t]*"("[^)]*")" {
    cond_depth++;
    std::string sym = cond_extract_symbol(yytext);
    bool defined = cond_defines.count(sym) > 0;
    cond_active[cond_depth] = defined;
    cond_done[cond_depth] = defined;
    if (!cond_is_active()) BEGIN(SKIPPING);
    else BEGIN(INITIAL);
}

<INITIAL,SKIPPING>^[ \t]*"/"[Ii][Ff][ \t]+[Nn][Oo][Tt][ \t]+[Dd][Ee][Ff][Ii][Nn][Ee][Dd][ \t]*"("[^)]*")" {
    cond_depth++;
    std::string sym = cond_extract_symbol(yytext);
    bool defined = cond_defines.count(sym) > 0;
    cond_active[cond_depth] = !defined;
    cond_done[cond_depth] = !defined;
    if (!cond_is_active()) BEGIN(SKIPPING);
    else BEGIN(INITIAL);
}

<INITIAL,SKIPPING>^[ \t]*"/"[Ee][Ll][Ss][Ee][ \t]*$ {
    if (cond_depth > 0) {
        cond_active[cond_depth] = !cond_done[cond_depth];
        cond_done[cond_depth] = true;
    }
    if (!cond_is_active()) BEGIN(SKIPPING);
    else BEGIN(INITIAL);
}

<INITIAL,SKIPPING>^[ \t]*"/"[Ee][Nn][Dd][Ii][Ff][ \t]*$ {
    if (cond_depth > 0) {
        cond_depth--;
    }
    if (!cond_is_active()) BEGIN(SKIPPING);
    else BEGIN(INITIAL);
}

<SKIPPING>[^\n]*\n   { /* skip lines in inactive conditional blocks */ }
<SKIPPING>[^\n]*     { /* skip last line without newline */ }

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
