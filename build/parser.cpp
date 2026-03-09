/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 30 "src/parser.y"

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

// CTL-OPT values extracted by lexer
extern char ctlopt_main_proc[256];
extern char ctlopt_datfmt[64];
extern char ctlopt_timfmt[64];
extern bool ctlopt_nomain;

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

#line 121 "build/parser.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_KW_FREE = 3,                    /* KW_FREE  */
  YYSYMBOL_KW_DCL_F = 4,                   /* KW_DCL_F  */
  YYSYMBOL_KW_DCL_S = 5,                   /* KW_DCL_S  */
  YYSYMBOL_KW_DCL_C = 6,                   /* KW_DCL_C  */
  YYSYMBOL_KW_DISK = 7,                    /* KW_DISK  */
  YYSYMBOL_KW_PRINTER = 8,                 /* KW_PRINTER  */
  YYSYMBOL_KW_WORKSTN = 9,                 /* KW_WORKSTN  */
  YYSYMBOL_KW_USAGE = 10,                  /* KW_USAGE  */
  YYSYMBOL_KW_CHAR = 11,                   /* KW_CHAR  */
  YYSYMBOL_KW_VARCHAR = 12,                /* KW_VARCHAR  */
  YYSYMBOL_KW_INT = 13,                    /* KW_INT  */
  YYSYMBOL_KW_PACKED = 14,                 /* KW_PACKED  */
  YYSYMBOL_KW_ZONED = 15,                  /* KW_ZONED  */
  YYSYMBOL_KW_DATE = 16,                   /* KW_DATE  */
  YYSYMBOL_KW_TIME = 17,                   /* KW_TIME  */
  YYSYMBOL_KW_TIMESTAMP = 18,              /* KW_TIMESTAMP  */
  YYSYMBOL_KW_IND = 19,                    /* KW_IND  */
  YYSYMBOL_KW_POINTER = 20,                /* KW_POINTER  */
  YYSYMBOL_KW_NULL = 21,                   /* KW_NULL  */
  YYSYMBOL_KW_DAYS = 22,                   /* KW_DAYS  */
  YYSYMBOL_KW_MONTHS = 23,                 /* KW_MONTHS  */
  YYSYMBOL_KW_YEARS = 24,                  /* KW_YEARS  */
  YYSYMBOL_KW_HOURS = 25,                  /* KW_HOURS  */
  YYSYMBOL_KW_MINUTES = 26,                /* KW_MINUTES  */
  YYSYMBOL_KW_SECONDS = 27,                /* KW_SECONDS  */
  YYSYMBOL_KW_MSECONDS = 28,               /* KW_MSECONDS  */
  YYSYMBOL_KW_CONST = 29,                  /* KW_CONST  */
  YYSYMBOL_KW_INZ = 30,                    /* KW_INZ  */
  YYSYMBOL_KW_DSPLY = 31,                  /* KW_DSPLY  */
  YYSYMBOL_KW_EVAL = 32,                   /* KW_EVAL  */
  YYSYMBOL_KW_EVAL_CORR = 33,              /* KW_EVAL_CORR  */
  YYSYMBOL_KW_EVALR = 34,                  /* KW_EVALR  */
  YYSYMBOL_KW_CALLP = 35,                  /* KW_CALLP  */
  YYSYMBOL_KW_LEAVESR = 36,                /* KW_LEAVESR  */
  YYSYMBOL_KW_ON_EXIT = 37,                /* KW_ON_EXIT  */
  YYSYMBOL_KW_DEALLOC = 38,                /* KW_DEALLOC  */
  YYSYMBOL_KW_TEST = 39,                   /* KW_TEST  */
  YYSYMBOL_KW_STATIC = 40,                 /* KW_STATIC  */
  YYSYMBOL_KW_TEMPLATE = 41,               /* KW_TEMPLATE  */
  YYSYMBOL_KW_BASED = 42,                  /* KW_BASED  */
  YYSYMBOL_KW_OPTIONS = 43,                /* KW_OPTIONS  */
  YYSYMBOL_KW_NOPASS = 44,                 /* KW_NOPASS  */
  YYSYMBOL_KW_OMIT = 45,                   /* KW_OMIT  */
  YYSYMBOL_KW_EXPORT = 46,                 /* KW_EXPORT  */
  YYSYMBOL_KW_IMPORT = 47,                 /* KW_IMPORT  */
  YYSYMBOL_KW_EXTPGM = 48,                 /* KW_EXTPGM  */
  YYSYMBOL_KW_EXTPROC = 49,                /* KW_EXTPROC  */
  YYSYMBOL_KW_CTLOPT = 50,                 /* KW_CTLOPT  */
  YYSYMBOL_KW_RETURN = 51,                 /* KW_RETURN  */
  YYSYMBOL_KW_INLR = 52,                   /* KW_INLR  */
  YYSYMBOL_KW_ON = 53,                     /* KW_ON  */
  YYSYMBOL_KW_BLANKS = 54,                 /* KW_BLANKS  */
  YYSYMBOL_KW_ZEROS = 55,                  /* KW_ZEROS  */
  YYSYMBOL_KW_HIVAL = 56,                  /* KW_HIVAL  */
  YYSYMBOL_KW_LOVAL = 57,                  /* KW_LOVAL  */
  YYSYMBOL_KW_IF = 58,                     /* KW_IF  */
  YYSYMBOL_KW_ELSEIF = 59,                 /* KW_ELSEIF  */
  YYSYMBOL_KW_ELSE = 60,                   /* KW_ELSE  */
  YYSYMBOL_KW_ENDIF = 61,                  /* KW_ENDIF  */
  YYSYMBOL_KW_DOW = 62,                    /* KW_DOW  */
  YYSYMBOL_KW_DOU = 63,                    /* KW_DOU  */
  YYSYMBOL_KW_ENDDO = 64,                  /* KW_ENDDO  */
  YYSYMBOL_KW_FOR = 65,                    /* KW_FOR  */
  YYSYMBOL_KW_ENDFOR = 66,                 /* KW_ENDFOR  */
  YYSYMBOL_KW_TO = 67,                     /* KW_TO  */
  YYSYMBOL_KW_DOWNTO = 68,                 /* KW_DOWNTO  */
  YYSYMBOL_KW_BY = 69,                     /* KW_BY  */
  YYSYMBOL_KW_SELECT = 70,                 /* KW_SELECT  */
  YYSYMBOL_KW_WHEN = 71,                   /* KW_WHEN  */
  YYSYMBOL_KW_OTHER = 72,                  /* KW_OTHER  */
  YYSYMBOL_KW_ENDSL = 73,                  /* KW_ENDSL  */
  YYSYMBOL_KW_ITER = 74,                   /* KW_ITER  */
  YYSYMBOL_KW_LEAVE = 75,                  /* KW_LEAVE  */
  YYSYMBOL_KW_MONITOR = 76,                /* KW_MONITOR  */
  YYSYMBOL_KW_ON_ERROR = 77,               /* KW_ON_ERROR  */
  YYSYMBOL_KW_ENDMON = 78,                 /* KW_ENDMON  */
  YYSYMBOL_KW_BEGSR = 79,                  /* KW_BEGSR  */
  YYSYMBOL_KW_ENDSR = 80,                  /* KW_ENDSR  */
  YYSYMBOL_KW_EXSR = 81,                   /* KW_EXSR  */
  YYSYMBOL_KW_OFF = 82,                    /* KW_OFF  */
  YYSYMBOL_KW_RESET = 83,                  /* KW_RESET  */
  YYSYMBOL_KW_CLEAR = 84,                  /* KW_CLEAR  */
  YYSYMBOL_KW_SORTA = 85,                  /* KW_SORTA  */
  YYSYMBOL_INDICATOR = 86,                 /* INDICATOR  */
  YYSYMBOL_KW_AND = 87,                    /* KW_AND  */
  YYSYMBOL_KW_OR = 88,                     /* KW_OR  */
  YYSYMBOL_KW_NOT = 89,                    /* KW_NOT  */
  YYSYMBOL_KW_DCL_PROC = 90,               /* KW_DCL_PROC  */
  YYSYMBOL_KW_END_PROC = 91,               /* KW_END_PROC  */
  YYSYMBOL_KW_DCL_PI = 92,                 /* KW_DCL_PI  */
  YYSYMBOL_KW_END_PI = 93,                 /* KW_END_PI  */
  YYSYMBOL_KW_DCL_PR = 94,                 /* KW_DCL_PR  */
  YYSYMBOL_KW_END_PR = 95,                 /* KW_END_PR  */
  YYSYMBOL_KW_VALUE = 96,                  /* KW_VALUE  */
  YYSYMBOL_KW_DCL_DS = 97,                 /* KW_DCL_DS  */
  YYSYMBOL_KW_END_DS = 98,                 /* KW_END_DS  */
  YYSYMBOL_KW_QUALIFIED = 99,              /* KW_QUALIFIED  */
  YYSYMBOL_KW_DIM = 100,                   /* KW_DIM  */
  YYSYMBOL_KW_LIKEDS = 101,                /* KW_LIKEDS  */
  YYSYMBOL_KW_LIKE = 102,                  /* KW_LIKE  */
  YYSYMBOL_KW_DCL_SUBF = 103,              /* KW_DCL_SUBF  */
  YYSYMBOL_KW_DCL_PARM = 104,              /* KW_DCL_PARM  */
  YYSYMBOL_DOT = 105,                      /* DOT  */
  YYSYMBOL_BIF_CHAR = 106,                 /* BIF_CHAR  */
  YYSYMBOL_BIF_TRIM = 107,                 /* BIF_TRIM  */
  YYSYMBOL_BIF_TRIML = 108,                /* BIF_TRIML  */
  YYSYMBOL_BIF_TRIMR = 109,                /* BIF_TRIMR  */
  YYSYMBOL_BIF_LEN = 110,                  /* BIF_LEN  */
  YYSYMBOL_BIF_SUBST = 111,                /* BIF_SUBST  */
  YYSYMBOL_BIF_SCAN = 112,                 /* BIF_SCAN  */
  YYSYMBOL_BIF_SCANRPL = 113,              /* BIF_SCANRPL  */
  YYSYMBOL_BIF_XLATE = 114,                /* BIF_XLATE  */
  YYSYMBOL_BIF_DEC = 115,                  /* BIF_DEC  */
  YYSYMBOL_BIF_INT = 116,                  /* BIF_INT  */
  YYSYMBOL_BIF_ELEM = 117,                 /* BIF_ELEM  */
  YYSYMBOL_BIF_FOUND = 118,                /* BIF_FOUND  */
  YYSYMBOL_BIF_EOF = 119,                  /* BIF_EOF  */
  YYSYMBOL_BIF_ABS = 120,                  /* BIF_ABS  */
  YYSYMBOL_BIF_DIV = 121,                  /* BIF_DIV  */
  YYSYMBOL_BIF_REM = 122,                  /* BIF_REM  */
  YYSYMBOL_BIF_SIZE = 123,                 /* BIF_SIZE  */
  YYSYMBOL_BIF_ADDR = 124,                 /* BIF_ADDR  */
  YYSYMBOL_BIF_PARMS = 125,                /* BIF_PARMS  */
  YYSYMBOL_BIF_STATUS = 126,               /* BIF_STATUS  */
  YYSYMBOL_BIF_ERROR = 127,                /* BIF_ERROR  */
  YYSYMBOL_BIF_MAX = 128,                  /* BIF_MAX  */
  YYSYMBOL_BIF_MIN = 129,                  /* BIF_MIN  */
  YYSYMBOL_BIF_LOOKUP = 130,               /* BIF_LOOKUP  */
  YYSYMBOL_BIF_DATE = 131,                 /* BIF_DATE  */
  YYSYMBOL_BIF_TIME = 132,                 /* BIF_TIME  */
  YYSYMBOL_BIF_TIMESTAMP = 133,            /* BIF_TIMESTAMP  */
  YYSYMBOL_BIF_DIFF = 134,                 /* BIF_DIFF  */
  YYSYMBOL_BIF_DAYS = 135,                 /* BIF_DAYS  */
  YYSYMBOL_BIF_MONTHS = 136,               /* BIF_MONTHS  */
  YYSYMBOL_BIF_YEARS = 137,                /* BIF_YEARS  */
  YYSYMBOL_BIF_EDITC = 138,                /* BIF_EDITC  */
  YYSYMBOL_BIF_EDITW = 139,                /* BIF_EDITW  */
  YYSYMBOL_BIF_REPLACE = 140,              /* BIF_REPLACE  */
  YYSYMBOL_BIF_CHECK = 141,                /* BIF_CHECK  */
  YYSYMBOL_BIF_CHECKR = 142,               /* BIF_CHECKR  */
  YYSYMBOL_BIF_LOWER = 143,                /* BIF_LOWER  */
  YYSYMBOL_BIF_UPPER = 144,                /* BIF_UPPER  */
  YYSYMBOL_BIF_SUBDT = 145,                /* BIF_SUBDT  */
  YYSYMBOL_BIF_FLOAT = 146,                /* BIF_FLOAT  */
  YYSYMBOL_BIF_SQRT = 147,                 /* BIF_SQRT  */
  YYSYMBOL_BIF_ALLOC = 148,                /* BIF_ALLOC  */
  YYSYMBOL_BIF_REALLOC = 149,              /* BIF_REALLOC  */
  YYSYMBOL_BIF_XFOOT = 150,                /* BIF_XFOOT  */
  YYSYMBOL_BIF_SUBARR = 151,               /* BIF_SUBARR  */
  YYSYMBOL_BIF_SPLIT = 152,                /* BIF_SPLIT  */
  YYSYMBOL_BIF_UNS = 153,                  /* BIF_UNS  */
  YYSYMBOL_BIF_INTH = 154,                 /* BIF_INTH  */
  YYSYMBOL_BIF_DECH = 155,                 /* BIF_DECH  */
  YYSYMBOL_BIF_DECPOS = 156,               /* BIF_DECPOS  */
  YYSYMBOL_BIF_CONCATARR = 157,            /* BIF_CONCATARR  */
  YYSYMBOL_BIF_LEFT = 158,                 /* BIF_LEFT  */
  YYSYMBOL_BIF_RIGHT = 159,                /* BIF_RIGHT  */
  YYSYMBOL_BIF_STR = 160,                  /* BIF_STR  */
  YYSYMBOL_BIF_MAXARR = 161,               /* BIF_MAXARR  */
  YYSYMBOL_BIF_MINARR = 162,               /* BIF_MINARR  */
  YYSYMBOL_BIF_LIST = 163,                 /* BIF_LIST  */
  YYSYMBOL_BIF_RANGE = 164,                /* BIF_RANGE  */
  YYSYMBOL_BIF_LOOKUPLT = 165,             /* BIF_LOOKUPLT  */
  YYSYMBOL_BIF_LOOKUPGE = 166,             /* BIF_LOOKUPGE  */
  YYSYMBOL_BIF_LOOKUPLE = 167,             /* BIF_LOOKUPLE  */
  YYSYMBOL_BIF_LOOKUPGT = 168,             /* BIF_LOOKUPGT  */
  YYSYMBOL_BIF_HOURS = 169,                /* BIF_HOURS  */
  YYSYMBOL_BIF_MINUTES = 170,              /* BIF_MINUTES  */
  YYSYMBOL_BIF_SECONDS = 171,              /* BIF_SECONDS  */
  YYSYMBOL_BIF_MSECONDS = 172,             /* BIF_MSECONDS  */
  YYSYMBOL_BIF_PADDR = 173,                /* BIF_PADDR  */
  YYSYMBOL_BIF_PROC = 174,                 /* BIF_PROC  */
  YYSYMBOL_BIF_PASSED = 175,               /* BIF_PASSED  */
  YYSYMBOL_BIF_OMITTED = 176,              /* BIF_OMITTED  */
  YYSYMBOL_BIF_OCCUR = 177,                /* BIF_OCCUR  */
  YYSYMBOL_KW_ALL = 178,                   /* KW_ALL  */
  YYSYMBOL_KW_UNS = 179,                   /* KW_UNS  */
  YYSYMBOL_KW_FLOAT_TYPE = 180,            /* KW_FLOAT_TYPE  */
  YYSYMBOL_KW_BINDEC = 181,                /* KW_BINDEC  */
  YYSYMBOL_KW_UCS2 = 182,                  /* KW_UCS2  */
  YYSYMBOL_KW_GRAPH = 183,                 /* KW_GRAPH  */
  YYSYMBOL_KW_OBJECT = 184,                /* KW_OBJECT  */
  YYSYMBOL_KW_JAVA = 185,                  /* KW_JAVA  */
  YYSYMBOL_KW_OCCURS = 186,                /* KW_OCCURS  */
  YYSYMBOL_KW_OVERLAY = 187,               /* KW_OVERLAY  */
  YYSYMBOL_KW_POS = 188,                   /* KW_POS  */
  YYSYMBOL_KW_PREFIX = 189,                /* KW_PREFIX  */
  YYSYMBOL_KW_DATFMT = 190,                /* KW_DATFMT  */
  YYSYMBOL_KW_TIMFMT = 191,                /* KW_TIMFMT  */
  YYSYMBOL_KW_EXTNAME = 192,               /* KW_EXTNAME  */
  YYSYMBOL_KW_RTNPARM = 193,               /* KW_RTNPARM  */
  YYSYMBOL_KW_OPDESC = 194,                /* KW_OPDESC  */
  YYSYMBOL_KW_ASCEND = 195,                /* KW_ASCEND  */
  YYSYMBOL_KW_DESCEND = 196,               /* KW_DESCEND  */
  YYSYMBOL_KW_NULLIND = 197,               /* KW_NULLIND  */
  YYSYMBOL_KW_VARSIZE = 198,               /* KW_VARSIZE  */
  YYSYMBOL_KW_STRING_OPT = 199,            /* KW_STRING_OPT  */
  YYSYMBOL_KW_TRIM_OPT = 200,              /* KW_TRIM_OPT  */
  YYSYMBOL_KW_FOR_EACH = 201,              /* KW_FOR_EACH  */
  YYSYMBOL_KW_IN = 202,                    /* KW_IN  */
  YYSYMBOL_IDENTIFIER = 203,               /* IDENTIFIER  */
  YYSYMBOL_INTEGER_LITERAL = 204,          /* INTEGER_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 205,            /* FLOAT_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 206,           /* STRING_LITERAL  */
  YYSYMBOL_SEMICOLON = 207,                /* SEMICOLON  */
  YYSYMBOL_EQUALS = 208,                   /* EQUALS  */
  YYSYMBOL_LPAREN = 209,                   /* LPAREN  */
  YYSYMBOL_RPAREN = 210,                   /* RPAREN  */
  YYSYMBOL_COLON = 211,                    /* COLON  */
  YYSYMBOL_PLUS = 212,                     /* PLUS  */
  YYSYMBOL_MINUS = 213,                    /* MINUS  */
  YYSYMBOL_STAR = 214,                     /* STAR  */
  YYSYMBOL_SLASH = 215,                    /* SLASH  */
  YYSYMBOL_NE = 216,                       /* NE  */
  YYSYMBOL_LE = 217,                       /* LE  */
  YYSYMBOL_GE = 218,                       /* GE  */
  YYSYMBOL_LT = 219,                       /* LT  */
  YYSYMBOL_GT = 220,                       /* GT  */
  YYSYMBOL_YYACCEPT = 221,                 /* $accept  */
  YYSYMBOL_program = 222,                  /* program  */
  YYSYMBOL_statements_opt = 223,           /* statements_opt  */
  YYSYMBOL_statement_list = 224,           /* statement_list  */
  YYSYMBOL_statement = 225,                /* statement  */
  YYSYMBOL_dcl_f_stmt = 226,               /* dcl_f_stmt  */
  YYSYMBOL_dcl_s_stmt = 227,               /* dcl_s_stmt  */
  YYSYMBOL_dcl_s_keywords = 228,           /* dcl_s_keywords  */
  YYSYMBOL_dcl_c_stmt = 229,               /* dcl_c_stmt  */
  YYSYMBOL_eval_target = 230,              /* eval_target  */
  YYSYMBOL_eval_stmt = 231,                /* eval_stmt  */
  YYSYMBOL_eval_corr_stmt = 232,           /* eval_corr_stmt  */
  YYSYMBOL_evalr_stmt = 233,               /* evalr_stmt  */
  YYSYMBOL_callp_stmt = 234,               /* callp_stmt  */
  YYSYMBOL_leavesr_stmt = 235,             /* leavesr_stmt  */
  YYSYMBOL_dsply_stmt = 236,               /* dsply_stmt  */
  YYSYMBOL_inlr_stmt = 237,                /* inlr_stmt  */
  YYSYMBOL_return_stmt = 238,              /* return_stmt  */
  YYSYMBOL_expr_stmt = 239,                /* expr_stmt  */
  YYSYMBOL_dcl_pr_stmt = 240,              /* dcl_pr_stmt  */
  YYSYMBOL_dcl_proc_stmt = 241,            /* dcl_proc_stmt  */
  YYSYMBOL_proc_export = 242,              /* proc_export  */
  YYSYMBOL_pi_return_type = 243,           /* pi_return_type  */
  YYSYMBOL_pi_params = 244,                /* pi_params  */
  YYSYMBOL_pi_param = 245,                 /* pi_param  */
  YYSYMBOL_pr_params = 246,                /* pr_params  */
  YYSYMBOL_pr_param = 247,                 /* pr_param  */
  YYSYMBOL_monitor_stmt = 248,             /* monitor_stmt  */
  YYSYMBOL_begsr_stmt = 249,               /* begsr_stmt  */
  YYSYMBOL_exsr_stmt = 250,                /* exsr_stmt  */
  YYSYMBOL_sorta_stmt = 251,               /* sorta_stmt  */
  YYSYMBOL_reset_stmt = 252,               /* reset_stmt  */
  YYSYMBOL_clear_stmt = 253,               /* clear_stmt  */
  YYSYMBOL_dealloc_stmt = 254,             /* dealloc_stmt  */
  YYSYMBOL_test_stmt = 255,                /* test_stmt  */
  YYSYMBOL_dcl_ds_stmt = 256,              /* dcl_ds_stmt  */
  YYSYMBOL_ds_fields = 257,                /* ds_fields  */
  YYSYMBOL_ds_field = 258,                 /* ds_field  */
  YYSYMBOL_if_stmt = 259,                  /* if_stmt  */
  YYSYMBOL_elseif_clauses = 260,           /* elseif_clauses  */
  YYSYMBOL_elseif_clause = 261,            /* elseif_clause  */
  YYSYMBOL_else_clause = 262,              /* else_clause  */
  YYSYMBOL_dow_stmt = 263,                 /* dow_stmt  */
  YYSYMBOL_dou_stmt = 264,                 /* dou_stmt  */
  YYSYMBOL_for_stmt = 265,                 /* for_stmt  */
  YYSYMBOL_for_each_stmt = 266,            /* for_each_stmt  */
  YYSYMBOL_select_stmt = 267,              /* select_stmt  */
  YYSYMBOL_when_clauses = 268,             /* when_clauses  */
  YYSYMBOL_when_clause = 269,              /* when_clause  */
  YYSYMBOL_other_clause = 270,             /* other_clause  */
  YYSYMBOL_iter_stmt = 271,                /* iter_stmt  */
  YYSYMBOL_leave_stmt = 272,               /* leave_stmt  */
  YYSYMBOL_expression = 273,               /* expression  */
  YYSYMBOL_or_expr = 274,                  /* or_expr  */
  YYSYMBOL_and_expr = 275,                 /* and_expr  */
  YYSYMBOL_not_expr = 276,                 /* not_expr  */
  YYSYMBOL_comparison_expr = 277,          /* comparison_expr  */
  YYSYMBOL_additive_expr = 278,            /* additive_expr  */
  YYSYMBOL_multiplicative_expr = 279,      /* multiplicative_expr  */
  YYSYMBOL_unary_expr = 280,               /* unary_expr  */
  YYSYMBOL_postfix_expr = 281,             /* postfix_expr  */
  YYSYMBOL_ident = 282,                    /* ident  */
  YYSYMBOL_primary_expr = 283,             /* primary_expr  */
  YYSYMBOL_call_args_opt = 284,            /* call_args_opt  */
  YYSYMBOL_call_arg_list = 285,            /* call_arg_list  */
  YYSYMBOL_arg_list = 286                  /* arg_list  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3080

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  221
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  66
/* YYNRULES -- Number of rules.  */
#define YYNRULES  367
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1162

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   475


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   184,   184,   187,   192,   194,   199,   208,   211,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   256,   260,   264,   268,   276,   281,   286,   291,   296,
     301,   306,   311,   316,   321,   326,   331,   337,   343,   349,
     353,   357,   361,   365,   369,   373,   377,   381,   385,   392,
     397,   403,   408,   413,   418,   423,   428,   433,   438,   443,
     448,   453,   458,   466,   467,   468,   469,   470,   475,   482,
     486,   489,   495,   499,   508,   514,   523,   531,   540,   546,
     552,   558,   564,   567,   574,   585,   602,   622,   637,   661,
     686,   713,   743,   744,   749,   750,   751,   752,   753,   758,
     761,   769,   773,   777,   781,   785,   789,   793,   797,   802,
     806,   810,   814,   818,   822,   826,   830,   834,   840,   845,
     850,   855,   864,   867,   875,   879,   883,   887,   891,   895,
     899,   903,   908,   912,   916,   920,   924,   928,   932,   936,
     940,   946,   951,   956,   961,   971,   982,   992,  1000,  1008,
    1015,  1023,  1031,  1043,  1052,  1061,  1071,  1081,  1089,  1100,
    1103,  1111,  1115,  1119,  1123,  1128,  1132,  1136,  1140,  1149,
    1172,  1173,  1181,  1190,  1191,  1197,  1206,  1215,  1225,  1235,
    1245,  1258,  1268,  1287,  1291,  1298,  1307,  1308,  1314,  1318,
    1324,  1328,  1329,  1337,  1338,  1346,  1347,  1353,  1354,  1359,
    1364,  1369,  1374,  1379,  1384,  1392,  1393,  1398,  1406,  1407,
    1412,  1420,  1421,  1429,  1430,  1437,  1438,  1439,  1440,  1441,
    1442,  1443,  1444,  1445,  1446,  1447,  1448,  1449,  1450,  1454,
    1458,  1459,  1460,  1461,  1462,  1463,  1464,  1465,  1466,  1467,
    1468,  1469,  1470,  1473,  1476,  1480,  1484,  1487,  1490,  1493,
    1496,  1499,  1502,  1505,  1508,  1511,  1514,  1517,  1520,  1524,
    1527,  1530,  1533,  1536,  1539,  1542,  1545,  1548,  1554,  1560,
    1566,  1572,  1578,  1584,  1587,  1590,  1593,  1596,  1600,  1604,
    1607,  1610,  1613,  1616,  1619,  1622,  1626,  1629,  1633,  1636,
    1640,  1647,  1654,  1661,  1666,  1671,  1676,  1680,  1684,  1687,
    1690,  1693,  1696,  1699,  1702,  1705,  1708,  1711,  1714,  1717,
    1720,  1723,  1726,  1729,  1732,  1735,  1738,  1741,  1744,  1747,
    1752,  1757,  1762,  1767,  1773,  1777,  1781,  1788,  1795,  1802,
    1808,  1814,  1820,  1823,  1826,  1829,  1832,  1835,  1838,  1841,
    1844,  1847,  1854,  1855,  1859,  1863,  1871,  1875
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "KW_FREE", "KW_DCL_F",
  "KW_DCL_S", "KW_DCL_C", "KW_DISK", "KW_PRINTER", "KW_WORKSTN",
  "KW_USAGE", "KW_CHAR", "KW_VARCHAR", "KW_INT", "KW_PACKED", "KW_ZONED",
  "KW_DATE", "KW_TIME", "KW_TIMESTAMP", "KW_IND", "KW_POINTER", "KW_NULL",
  "KW_DAYS", "KW_MONTHS", "KW_YEARS", "KW_HOURS", "KW_MINUTES",
  "KW_SECONDS", "KW_MSECONDS", "KW_CONST", "KW_INZ", "KW_DSPLY", "KW_EVAL",
  "KW_EVAL_CORR", "KW_EVALR", "KW_CALLP", "KW_LEAVESR", "KW_ON_EXIT",
  "KW_DEALLOC", "KW_TEST", "KW_STATIC", "KW_TEMPLATE", "KW_BASED",
  "KW_OPTIONS", "KW_NOPASS", "KW_OMIT", "KW_EXPORT", "KW_IMPORT",
  "KW_EXTPGM", "KW_EXTPROC", "KW_CTLOPT", "KW_RETURN", "KW_INLR", "KW_ON",
  "KW_BLANKS", "KW_ZEROS", "KW_HIVAL", "KW_LOVAL", "KW_IF", "KW_ELSEIF",
  "KW_ELSE", "KW_ENDIF", "KW_DOW", "KW_DOU", "KW_ENDDO", "KW_FOR",
  "KW_ENDFOR", "KW_TO", "KW_DOWNTO", "KW_BY", "KW_SELECT", "KW_WHEN",
  "KW_OTHER", "KW_ENDSL", "KW_ITER", "KW_LEAVE", "KW_MONITOR",
  "KW_ON_ERROR", "KW_ENDMON", "KW_BEGSR", "KW_ENDSR", "KW_EXSR", "KW_OFF",
  "KW_RESET", "KW_CLEAR", "KW_SORTA", "INDICATOR", "KW_AND", "KW_OR",
  "KW_NOT", "KW_DCL_PROC", "KW_END_PROC", "KW_DCL_PI", "KW_END_PI",
  "KW_DCL_PR", "KW_END_PR", "KW_VALUE", "KW_DCL_DS", "KW_END_DS",
  "KW_QUALIFIED", "KW_DIM", "KW_LIKEDS", "KW_LIKE", "KW_DCL_SUBF",
  "KW_DCL_PARM", "DOT", "BIF_CHAR", "BIF_TRIM", "BIF_TRIML", "BIF_TRIMR",
  "BIF_LEN", "BIF_SUBST", "BIF_SCAN", "BIF_SCANRPL", "BIF_XLATE",
  "BIF_DEC", "BIF_INT", "BIF_ELEM", "BIF_FOUND", "BIF_EOF", "BIF_ABS",
  "BIF_DIV", "BIF_REM", "BIF_SIZE", "BIF_ADDR", "BIF_PARMS", "BIF_STATUS",
  "BIF_ERROR", "BIF_MAX", "BIF_MIN", "BIF_LOOKUP", "BIF_DATE", "BIF_TIME",
  "BIF_TIMESTAMP", "BIF_DIFF", "BIF_DAYS", "BIF_MONTHS", "BIF_YEARS",
  "BIF_EDITC", "BIF_EDITW", "BIF_REPLACE", "BIF_CHECK", "BIF_CHECKR",
  "BIF_LOWER", "BIF_UPPER", "BIF_SUBDT", "BIF_FLOAT", "BIF_SQRT",
  "BIF_ALLOC", "BIF_REALLOC", "BIF_XFOOT", "BIF_SUBARR", "BIF_SPLIT",
  "BIF_UNS", "BIF_INTH", "BIF_DECH", "BIF_DECPOS", "BIF_CONCATARR",
  "BIF_LEFT", "BIF_RIGHT", "BIF_STR", "BIF_MAXARR", "BIF_MINARR",
  "BIF_LIST", "BIF_RANGE", "BIF_LOOKUPLT", "BIF_LOOKUPGE", "BIF_LOOKUPLE",
  "BIF_LOOKUPGT", "BIF_HOURS", "BIF_MINUTES", "BIF_SECONDS",
  "BIF_MSECONDS", "BIF_PADDR", "BIF_PROC", "BIF_PASSED", "BIF_OMITTED",
  "BIF_OCCUR", "KW_ALL", "KW_UNS", "KW_FLOAT_TYPE", "KW_BINDEC", "KW_UCS2",
  "KW_GRAPH", "KW_OBJECT", "KW_JAVA", "KW_OCCURS", "KW_OVERLAY", "KW_POS",
  "KW_PREFIX", "KW_DATFMT", "KW_TIMFMT", "KW_EXTNAME", "KW_RTNPARM",
  "KW_OPDESC", "KW_ASCEND", "KW_DESCEND", "KW_NULLIND", "KW_VARSIZE",
  "KW_STRING_OPT", "KW_TRIM_OPT", "KW_FOR_EACH", "KW_IN", "IDENTIFIER",
  "INTEGER_LITERAL", "FLOAT_LITERAL", "STRING_LITERAL", "SEMICOLON",
  "EQUALS", "LPAREN", "RPAREN", "COLON", "PLUS", "MINUS", "STAR", "SLASH",
  "NE", "LE", "GE", "LT", "GT", "$accept", "program", "statements_opt",
  "statement_list", "statement", "dcl_f_stmt", "dcl_s_stmt",
  "dcl_s_keywords", "dcl_c_stmt", "eval_target", "eval_stmt",
  "eval_corr_stmt", "evalr_stmt", "callp_stmt", "leavesr_stmt",
  "dsply_stmt", "inlr_stmt", "return_stmt", "expr_stmt", "dcl_pr_stmt",
  "dcl_proc_stmt", "proc_export", "pi_return_type", "pi_params",
  "pi_param", "pr_params", "pr_param", "monitor_stmt", "begsr_stmt",
  "exsr_stmt", "sorta_stmt", "reset_stmt", "clear_stmt", "dealloc_stmt",
  "test_stmt", "dcl_ds_stmt", "ds_fields", "ds_field", "if_stmt",
  "elseif_clauses", "elseif_clause", "else_clause", "dow_stmt", "dou_stmt",
  "for_stmt", "for_each_stmt", "select_stmt", "when_clauses",
  "when_clause", "other_clause", "iter_stmt", "leave_stmt", "expression",
  "or_expr", "and_expr", "not_expr", "comparison_expr", "additive_expr",
  "multiplicative_expr", "unary_expr", "postfix_expr", "ident",
  "primary_expr", "call_args_opt", "call_arg_list", "arg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-691)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-208)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      78,  -691,    87,    21,    88,  -691,  -144,  -100,   -93,   -86,
    2478,   -51,  1645,   -51,  2478,   -71,  1645,   -52,  -691,  1834,
     -38,  2478,  2478,  2478,  1645,   -30,    11,    26,    31,     3,
    1645,  1645,  1645,  1645,  -691,    50,    68,    89,  1645,     8,
    -691,  -691,  -691,  -691,     7,  -691,  -691,  -691,  -691,  -691,
    -691,  -691,  -691,  -691,  -691,  -691,  -691,  -691,  -691,  -691,
    -691,  -691,  -691,  -691,  -691,  -691,  -691,  -691,  -691,  -691,
    -691,  -691,  -691,  -691,   221,    30,  2478,  -691,  -691,  -691,
    -691,  -691,  -691,  -691,  -691,  2639,    81,    92,    94,   102,
     107,   121,   123,   147,   150,   161,   164,   177,   184,   196,
     201,   211,   224,   227,   236,   240,   251,   271,   278,   294,
     303,   307,   310,   315,   323,   333,   345,   349,   358,   365,
     372,   377,   381,   388,   390,   397,   401,   406,   416,   467,
     470,   479,   486,   488,   495,   505,   506,   507,   508,   510,
     513,   514,   518,   519,   520,   521,   522,   523,   524,   525,
     527,   528,   529,   530,   531,   532,   533,   534,   276,  -691,
    -691,  -691,  -691,  -691,  -691,  -691,  -691,  -691,  -691,  -691,
    -691,   535,  -691,  -691,  -691,  2478,  2800,   321,   208,   148,
    -691,    60,  -151,    28,  -691,   439,  -691,    25,   339,  -691,
    -691,  -691,  -691,  -691,  -691,  -691,  -691,  -691,  -691,  -691,
    -691,  -691,  -691,   457,   537,   540,  -691,   542,  1645,  -691,
     543,   707,   554,   555,   556,   557,   693,  -691,  -691,  -691,
     559,   560,   561,   562,   563,   727,   245,   -24,   572,   573,
    2478,  2478,    -8,   568,   570,   571,   577,   578,   580,   582,
    -108,  -106,   574,   585,   586,   588,   589,   591,   593,   598,
     599,   600,   605,    60,  2478,  2478,  2478,  2478,  2478,  2478,
    2478,  2478,  2478,  2478,  2478,  2478,   603,   609,  2478,  2478,
    2478,  2478,  2478,   610,   611,   612,  2478,  2478,  2478,  1995,
    2156,  2317,  2478,  2478,  2478,  2478,  2478,  2478,  2478,  2478,
    2478,  2478,  2478,  2478,  2478,  2478,  2478,  2478,  2478,  2478,
    2478,  2478,  2478,  2478,  2478,  2478,  2478,  2478,  2478,  2478,
    2478,  2478,  2478,  2478,  2478,  2478,  2478,  2478,  2478,  2478,
    2478,   620,   614,  1645,  1645,  2478,  -691,  2478,   617,   439,
    -691,  2478,  2478,  2639,  2639,  2639,  2639,  2639,  2639,  2639,
    2639,  2639,  2639,  2639,   622,  2478,  2478,  1645,  2478,  -691,
    -691,   618,  -691,   608,  -691,  -691,  -691,  2478,  2478,   194,
    -691,   825,  -691,  -691,  -691,  -691,  -691,  -691,   625,   624,
     626,   627,   628,   629,   -46,    -2,   630,   631,  -691,  2478,
    -691,   632,   635,   623,   634,   637,  -691,  -691,  -691,   639,
     644,   645,   646,   648,   653,  -691,   656,  -691,  -691,  -691,
    -691,   650,   651,   662,   663,   664,   665,   685,  -691,  -691,
      59,   110,   139,   142,   166,   172,   193,   202,   212,   233,
     237,   241,  -691,  -691,   262,   273,   290,   300,   304,  -691,
    -691,  -691,   316,   319,   324,  -691,   326,  -691,   328,  -691,
     330,   660,   668,   669,   670,   335,   350,   352,   354,   360,
     362,   373,   661,   378,   384,   394,   398,   402,   412,   417,
     419,   421,   426,   428,   430,   432,   434,   445,   447,   449,
     451,   453,   459,   461,   464,   471,   671,   672,   674,   675,
     676,  -691,   679,   681,   473,  -691,   682,  -691,   148,  -691,
     474,   474,   474,   474,   474,   474,   474,    28,    28,  -691,
    -691,  -691,   632,   666,   667,   686,  1645,  -691,   356,   912,
     979,   566,   687,   689,  -691,   802,   690,  -691,  1046,   806,
     701,   703,   708,   716,   697,   715,  -691,   717,  -691,   721,
     724,    51,   722,   823,   723,  2478,  -691,   718,   725,   726,
     728,   729,   730,   731,   734,   732,   739,   742,   743,   744,
     745,   746,  -691,  2478,  -691,  -691,  -691,  -691,  -691,  -691,
    -691,  -691,  -691,  -691,  -691,  -691,  -691,  -691,  -691,  -691,
    -691,  -691,  -691,  -691,  -691,  -691,  2478,  -691,  -691,  -691,
    -691,  -691,  -691,  -691,  -691,  -691,  -691,   302,  -691,  -691,
    -691,  -691,  -691,  -691,  -691,  -691,  -691,  -691,  -691,  -691,
    -691,  -691,  -691,  -691,  -691,  -691,  -691,  -691,  -691,  -691,
    -691,  -691,  -691,  -691,  -691,  -691,  -691,  -691,  -691,  -691,
    -691,  -691,  -691,   749,   633,   751,   752,  2478,  2478,  -691,
    -691,   753,  -691,   754,     5,   755,   756,   757,   758,   761,
     733,   -37,   768,    57,   763,   769,   771,   759,   234,  -691,
    -691,   778,  -691,  -691,   779,   258,   338,   325,   785,   788,
     784,   789,   793,   272,   272,   272,   272,   272,   795,  -691,
     792,   794,   797,   798,   809,   810,   811,  -691,  2478,   815,
    -691,   870,  -691,  -691,   -64,   -59,   423,  1113,  -691,  1200,
    -691,   452,   816,  -691,  -691,  -691,   801,   817,   819,   818,
     813,   238,  -691,   822,   820,   834,     9,  -691,   456,   824,
     826,   827,   829,  1267,  -691,   831,  1004,   830,  -691,  -691,
     837,  1010,  -691,   839,   849,   848,  -691,   850,   854,  1036,
     858,   859,  1040,   862,   865,   864,   873,   868,   879,  -691,
     880,   881,   882,   883,   884,   885,   318,  -691,  -691,  -691,
    -691,  -691,  -691,   886,  -691,   887,  2478,  -691,  2478,  -691,
     889,   892,  -691,   890,  -691,   894,  -691,   465,   893,   896,
     897,   898,   901,   905,  -691,   916,   915,  -691,   919,   924,
     925,   926,   888,   899,   933,   934,   932,   931,   941,  2478,
     939,   944,   950,  -691,  2478,   951,  -691,   947,  2478,   954,
     949,   955,  -691,   334,   272,  -691,  -691,  -691,  -691,  -691,
    -691,  -691,   953,   952,   956,   957,   958,   959,   960,  -691,
    1334,  -691,   965,  1401,   966,  1468,  -691,  -691,    38,  -691,
      52,  -691,   968,   970,   972,   975,   981,   986,   987,   989,
     971,  -691,  -691,   991,   996,   998,  1005,  1007,  1002,  1003,
    1006,   997,  -691,  1008,  2478,  1009,  1011,  2478,  1012,  1013,
    1014,  2478,  1015,  1016,  2478,  1017,  1131,  1019,  1020,  1023,
    1030,  -691,  -691,  -691,  -691,  -691,  -691,  -691,   517,  -691,
    1033,  -691,  1034,    41,  1035,  1041,   250,  -691,  1038,    64,
    1039,  1042,  1044,  1049,  1045,  1047,  1050,  1043,  1051,   128,
     134,  1054,  1056,  1057,  1059,  1048,  1070,  1073,  1075,  1052,
    -691,  1077,  1081,  1082,  1083,    90,  1084,  1085,  1086,  1088,
    1097,  1098,    99,  1100,  2478,  1103,  -691,  -691,  1535,  -691,
    1602,  -691,  1104,  -691,   478,  1101,  1106,  1108,  1111,  1112,
    -691,  1105,  1114,  1116,  1117,  1102,   -63,   -32,   -31,  1118,
    1121,  1124,  1127,  1129,  1137,  1138,  1140,  1119,  -691,  -691,
    -691,  1139,  1147,  -691,  -691,  1148,  1149,  1151,  -691,  -691,
    -691,  1152,  -691,  -691,  1153,  1155,  1156,  -691,  2478,  1161,
    1164,  1168,  1169,  -691,   615,  1170,  1171,  1172,  1173,  1174,
    1179,  1180,  1183,  1185,  -691,   -28,   -27,   -26,  1186,   -23,
    -691,   -19,  -691,   -15,  -691,  1167,  -691,  -691,  -691,  -691,
    -691,  -691,  -691,  1181,  1182,  -691,  -691,  -691,  -691,  -691,
    -691,  -691,  -691,  1184,  1191,  1193,  -691,  -691,   720,  1204,
    1205,  1189,  1210,  1212,  1217,  1213,  1215,  1216,  1211,  1219,
    1220,  -691,  1223,  -691,  1231,  -691,  1232,  1234,  -691,  1235,
    -691,  1236,  -691,   -18,  1239,  -691,  1240,  -691,  -691,  1241,
    1242,  -691,  -691,  1244,  1245,  1246,  1230,   -16,    -6,    12,
    1247,  1243,  -691,  -691,  -691,    16,  1176,  1206,  1413,    -9,
    -691,  -691,  -691,  -691,  -691,  1669,    18,    20,    29,  1254,
      -7,  -691,    -5,  -691,    -4,  -691,  1250,  -691,  1255,  -691,
    1251,  1268,  1269,  1256,  -691,  1736,  1274,  1276,  -691,  1281,
    -691,  1282,  -691,  1280,  1283,  -691,  1284,  -691,  1285,  -691,
      32,  -691,  1289,  1290,  1298,  1464,  1302,  -691,  -691,  -691,
    -691,    33,  1466,  1467,  1469,    -3,  -691,  -691,  -691,  -691,
    1304,  -691,  1305,  -691,  1306,  1307,  1308,  1312,  -691,  1315,
    -691,  1316,  1317,  1318,  1471,  -691,  -691,  -691,  -691,  1319,
    1320,  -691
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       4,     4,     0,     0,     0,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    90,     0,     0,     0,     0,    89,
       5,     9,    10,    11,     0,    12,    13,    34,    35,    36,
      14,    15,    16,    39,    26,    25,    28,    29,    30,    33,
      31,    32,    37,    38,    27,    17,    18,    19,    20,    21,
      22,    23,    24,    40,     0,     0,     0,   356,   354,   357,
     358,   359,   360,   355,   353,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   345,     0,     0,     0,     0,   250,
     251,   252,   253,   259,   260,   261,   256,   257,   254,   255,
     258,   249,   262,   263,   264,     0,     0,     0,   210,   211,
     213,   215,   217,   225,   228,   231,   233,    89,     0,   236,
     237,   238,   239,   246,   247,   248,   243,   244,   240,   241,
     245,   242,   235,     0,     0,     0,    99,     0,     0,   103,
       0,     0,     0,     0,     0,     0,     0,   208,   209,     7,
       0,     0,     0,     0,     0,   112,   114,     0,     0,     0,
     362,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   216,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   349,   362,     0,   232,
     100,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    98,
     171,     0,   102,     0,     7,     7,     7,     0,     0,   206,
     203,     0,     7,   167,   169,   170,   168,   113,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   179,     0,
      91,   364,     0,   363,     0,     0,    41,    42,    43,     0,
       0,     0,     0,     0,     0,    60,     0,    61,    62,    59,
      63,     0,     0,     0,     0,     0,     0,     0,    88,   366,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   316,   317,     0,     0,     0,     0,     0,   278,
     297,   298,     0,     0,     0,   305,     0,   307,     0,   309,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   344,     0,     0,     0,   364,     0,   361,   212,   214,
     218,   219,   222,   223,   220,   221,   224,   226,   227,   229,
     230,   234,     0,     0,     0,     0,     0,   101,     0,     0,
       0,     0,     0,     0,   204,     0,     0,     8,     0,     0,
       0,     0,     0,     0,     0,     0,   142,     0,   179,     0,
       0,     0,     0,    92,     0,     0,    94,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   266,     0,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   277,   301,   302,   303,   299,   300,
     295,   296,   279,   304,   306,   308,     0,   313,   314,   315,
     280,   281,   282,   283,   284,   285,   286,     0,   293,   294,
     318,   319,   320,   330,   325,   321,   322,   323,   324,   326,
     327,   328,   329,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   341,   342,   343,   350,   351,   352,   265,
      95,    96,    97,     0,   193,     0,     0,     0,     0,     7,
       7,     0,     7,     0,   114,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   180,
       7,     0,   104,   365,     0,    83,    83,    83,     0,     0,
       0,     0,     0,    83,    83,    83,    83,    83,     0,   367,
       0,     0,     0,     0,     0,     0,     0,   172,     0,     0,
     191,     0,   195,   196,     0,     0,     0,     0,   202,     0,
     166,   114,     0,   116,   117,   115,     0,     0,     0,     0,
       0,     0,   143,     0,     0,     0,     0,   174,     0,     0,
       0,     0,     0,     0,    93,     0,     0,     0,    84,    85,
       0,    86,    87,     0,     0,     0,    86,     0,     0,     0,
       0,     0,    86,     0,     0,     0,     0,     0,     0,    68,
       0,     0,     0,     0,     0,     0,     0,   289,   288,   287,
     290,   291,   292,     0,     7,     0,     0,     7,     0,     7,
       0,     0,   119,     0,   142,     0,   105,     0,     0,     0,
       0,     0,     0,     0,   173,     0,     0,   177,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    45,     0,     0,    46,     0,     0,     0,
       0,     0,    47,    83,    83,    81,    82,    69,    70,    71,
      72,    73,     0,     0,     0,     0,     0,     0,     0,     7,
       0,   189,     0,     0,     0,     0,   165,   119,     0,   118,
       0,   142,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   179,   179,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   201,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    74,   310,   311,   312,   346,   347,   348,     0,     7,
       0,     7,     0,     0,     0,     0,     0,   120,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      44,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    48,    49,     0,   197,
       0,   199,     0,     7,     0,     0,     0,     0,     0,     0,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   182,   183,
     181,     0,     0,    54,    76,     0,     0,     0,    65,    56,
      66,     0,    53,    75,     0,     0,     0,    64,     0,     0,
       0,     0,     0,     7,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   106,     0,     0,     0,     0,     0,
     146,     0,   148,     0,   144,     0,   160,   176,   175,   178,
     186,   187,   185,     0,     0,    51,    58,    79,    80,    50,
      57,    77,    78,     0,     0,     0,   198,   200,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   154,     0,   156,     0,   152,     0,     0,   147,     0,
     149,     0,   145,     0,     0,   184,     0,    55,    67,     0,
       0,     7,   108,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   155,   157,   153,     0,     0,     0,     0,     0,
     150,   188,    52,     7,   109,     0,     0,     0,     0,     0,
       0,   123,     0,   125,     0,   121,     0,   137,     0,   158,
       0,     0,     0,     0,   151,     0,     0,     0,   131,     0,
     133,     0,   129,     0,     0,   124,     0,   126,     0,   122,
       0,   159,     0,     0,     0,     0,     0,   110,   132,   134,
     130,     0,     0,     0,     0,     0,   127,   162,   163,   161,
       0,   111,     0,   135,     0,     0,     0,     0,   128,     0,
     136,     0,     0,     0,     0,   164,   139,   140,   138,     0,
       0,   141
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -691,  -691,  1162,  -348,   699,  -691,  -691,  -470,  -691,   124,
    -691,  -691,  -691,  -691,  -691,  -691,  -691,  -691,  -691,  -691,
    -691,  -691,  -501,   387,  -691,  -690,  -691,  -691,  -691,  -691,
    -691,  -691,  -691,  -691,  -691,  -691,  -527,  -691,  -691,  -691,
    -691,  -691,  -691,  -691,  -691,  -691,  -691,  -691,  1187,  -691,
    -691,  -691,   -10,  -691,  1197,  1218,  1132,    63,   367,   368,
    1356,    -1,  -691,   891,  -691,  2755
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,   361,   517,    41,    42,   724,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,   368,   374,   828,   887,   641,   702,    56,    57,    58,
      59,    60,    61,    62,    63,    64,   531,   649,    65,   624,
     680,   681,    66,    67,    68,    69,    70,   359,   360,   515,
      71,    72,   409,   178,   179,   180,   181,   182,   183,   184,
     185,   203,   186,   382,   383,   410
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     177,   643,   385,   525,   205,   756,   508,   509,   510,   210,
     758,   212,   213,   214,   518,   207,   369,   370,   371,   372,
    1047,    -3,     6,   215,  1049,     7,     8,     9,  1051,   221,
     222,   223,   224,   999,  1103,    34,  1114,   228,  1116,  1118,
    1147,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   339,    10,    11,    12,    13,    14,    15,   699,    16,
      17,   340,   341,    73,  1001,  1003,   252,   700,  1040,  1042,
    1044,    18,    19,    20,   830,   375,   376,   377,  1079,    21,
    1090,     1,   394,    22,    23,   396,    24,     5,    -2,     6,
    1092,    25,     7,     8,     9,    26,    27,    28,   527,   395,
      29,   397,    30,    74,    31,    32,    33,    34,  1094,   776,
      75,    35,  1098,   229,  1107,    36,  1109,    76,    37,    10,
      11,    12,    13,    14,    15,  1111,    16,    17,  1135,  1142,
     229,   884,   245,   692,   932,   188,   206,   204,    18,    19,
      20,   889,   885,   757,  1000,   885,    21,   888,   759,   646,
      22,    23,   187,    24,   647,   704,   700,   208,    25,   941,
     647,   526,    26,    27,    28,   328,   701,    29,   700,    30,
     211,    31,    32,    33,    34,  1002,  1004,   216,    35,  1041,
    1043,  1045,    36,   378,  1048,    37,   728,   734,  1050,  1080,
     761,  1091,  1052,   740,   741,   742,   743,   744,  1104,   386,
    1115,  1093,  1117,  1119,  1148,   528,   220,   351,   691,   246,
     247,   248,   249,   250,   251,   231,   777,   230,   217,  1095,
     381,   384,    38,  1099,    39,  1108,   951,  1110,   232,   233,
     234,   647,   952,   218,   345,   332,  1112,   647,   219,  1136,
    1143,   886,   342,   343,   886,   709,   710,   711,   712,   768,
     769,   770,   771,   225,   648,   701,   369,   370,   371,   372,
     648,   935,   936,   937,   938,   358,   513,   701,   333,   552,
     553,   226,   441,   442,   443,   444,   334,   335,   336,   337,
     338,   686,   687,   452,   689,   966,   967,   716,   717,    38,
     254,    39,   227,   373,   975,   976,   331,   968,   718,   719,
     720,   255,   713,   256,   721,   722,   977,   476,   477,   478,
     479,   257,   718,   719,   899,   900,   258,   485,   726,   722,
     554,   553,   482,   483,   671,   672,   673,   674,   675,   676,
     259,   648,   260,   869,   870,   502,   503,   648,   505,   772,
     813,   814,   815,   816,   817,   818,   504,   511,   512,   555,
     553,   939,   556,   553,   729,   730,   261,     6,   723,   262,
       7,     8,     9,   866,   867,   718,   719,   731,   725,   532,
     263,   732,   722,   264,   718,   719,   557,   553,   718,   719,
     726,   722,   558,   553,   726,   722,   265,    10,    11,    12,
      13,    14,    15,   266,    16,    17,   490,   491,   492,   493,
     494,   495,   496,   559,   553,   267,   820,    19,    20,   823,
     268,   825,   560,   553,    21,  -190,  -190,  -190,    22,    23,
     269,    24,   561,   553,     6,   733,    25,     7,     8,     9,
      26,    27,    28,   270,   868,    29,   271,    30,   727,    31,
      32,    33,    34,   562,   553,   272,    35,   563,   553,   273,
      36,   564,   553,    37,    10,    11,    12,    13,    14,    15,
     274,    16,    17,   369,   370,   371,   372,   778,   779,   780,
     781,   878,   565,   553,    19,    20,   832,   833,   834,   835,
     275,    21,   326,   566,   553,    22,    23,   276,    24,   985,
     986,   987,   988,    25,  -205,  -205,  -205,    26,    27,    28,
     567,   553,    29,   277,    30,   623,    31,    32,    33,    34,
     568,   553,   278,    35,   569,   553,   279,    36,     6,   280,
      37,     7,     8,     9,   281,   653,   570,   553,   330,   571,
     553,   928,   282,   930,   572,   553,   573,   553,   574,   553,
     575,   553,   283,   669,   344,   580,   553,   346,    10,    11,
      12,    13,    14,    15,   284,    16,    17,    38,   285,    39,
     581,   553,   582,   553,   583,   553,   670,   286,    19,    20,
     584,   553,   585,   553,   287,    21,  -192,  -192,  -192,    22,
      23,   288,    24,   586,   553,   984,   289,    25,   588,   553,
     290,    26,    27,    28,   589,   553,    29,   291,    30,   292,
      31,    32,    33,    34,   590,   553,   293,    35,   591,   553,
     294,    36,   592,   553,    37,   295,     6,   684,   685,     7,
       8,     9,   593,   553,    38,   296,    39,   594,   553,   595,
     553,   596,   553,   627,   628,  1028,   597,   553,   598,   553,
     599,   553,   600,   553,   601,   553,    10,    11,    12,    13,
      14,    15,  1029,    16,    17,   602,   553,   603,   553,   604,
     553,   605,   553,   606,   553,   347,    19,    20,   753,   607,
     553,   608,   553,    21,   609,   553,   297,    22,    23,   298,
      24,   610,   553,   618,   553,    25,   340,   341,   299,    26,
      27,    28,   678,   679,    29,   300,    30,   301,    31,    32,
      33,    34,    40,    40,   302,    35,  1030,   497,   498,    36,
     499,   500,    37,  1085,   303,   304,   305,   306,    38,   307,
      39,     6,   308,   309,     7,     8,     9,   310,   311,   312,
     313,   314,   315,   316,   317,  1105,   318,   319,   320,   321,
     322,   323,   324,   325,   327,   348,   822,   349,   824,   350,
     352,    10,    11,    12,    13,    14,    15,  1059,    16,    17,
     353,   354,   355,   356,   358,   357,   362,   363,   364,   365,
     366,    19,    20,   367,   379,   387,   380,   388,    21,   855,
     389,   398,    22,    23,   859,    24,   390,   391,   862,   392,
      25,   393,   399,   400,    26,    27,    28,   401,   402,    29,
     403,    30,   404,    31,    32,    33,    34,   405,   406,   407,
      35,  1060,   408,   422,    36,   507,    38,    37,    39,   423,
     429,   430,   431,   480,   481,   501,     6,   487,   506,     7,
       8,     9,   519,   520,   535,   521,   522,   523,   524,   529,
     530,   536,   533,   538,   911,   534,   537,   914,   539,   540,
     541,   918,   542,   545,   921,   546,    10,    11,    12,    13,
      14,    15,   543,    16,    17,   544,   547,   548,   549,   550,
     551,   576,   587,   620,   621,   631,    19,    20,   577,   578,
     579,   611,   612,    21,   613,   614,   615,    22,    23,   616,
      24,   617,   619,   622,   629,    25,   630,   632,   634,    26,
      27,    28,   516,   639,    29,   635,    30,   636,    31,    32,
      33,    34,   637,     6,   979,    35,     7,     8,     9,    36,
     638,    38,    37,    39,   640,   644,   642,   645,   651,   650,
     652,   755,   654,   775,   660,   655,   656,   661,   657,   698,
     658,   659,   662,    10,    11,    12,    13,    14,    15,   663,
      16,    17,   664,   665,   666,   667,   677,   668,   682,   683,
     688,   690,   708,    19,    20,   693,   694,   695,  1023,   696,
      21,   697,   703,   705,    22,    23,   625,    24,   707,   706,
       6,   714,    25,     7,     8,     9,    26,    27,    28,   735,
     715,    29,   736,    30,   737,    31,    32,    33,    34,   738,
     739,   745,    35,   746,   747,   763,    36,   748,   749,    37,
      10,    11,    12,    13,    14,    15,   767,    16,    17,   750,
     751,   752,   754,   762,   764,   766,    38,   774,    39,   765,
      19,    20,   773,   782,   788,   783,   784,    21,   785,   789,
     791,    22,    23,   626,    24,   787,   790,     6,   792,    25,
       7,     8,     9,    26,    27,    28,   793,   794,    29,   795,
      30,   796,    31,    32,    33,    34,   797,   798,   799,    35,
     800,   801,   802,    36,   803,   805,    37,    10,    11,    12,
      13,    14,    15,   804,    16,    17,   806,   807,   808,   809,
     810,   811,   848,   819,   821,   812,   826,    19,    20,   827,
     829,   831,   836,   849,    21,   837,   838,   839,    22,    23,
     840,    24,   841,    38,     6,    39,    25,     7,     8,     9,
      26,    27,    28,   842,   843,    29,   633,    30,   844,    31,
      32,    33,    34,   845,   846,   847,    35,   850,   851,   852,
      36,   853,   856,    37,    10,    11,    12,    13,    14,    15,
     854,    16,    17,   857,   858,   860,   861,   863,   864,   865,
     871,   923,   872,     4,    19,    20,   873,   874,   875,   876,
     877,    21,   879,   881,   898,    22,    23,   890,    24,   891,
      38,   892,    39,    25,   893,   894,  -207,    26,    27,    28,
     895,   896,    29,   897,    30,   901,    31,    32,    33,    34,
     902,     6,   903,    35,     7,     8,     9,    36,   909,   904,
      37,   905,   906,   907,   883,   910,   908,   253,   486,   912,
    1100,   913,   915,   916,   917,   919,   920,   922,   924,   925,
     926,    10,    11,    12,    13,    14,    15,   927,    16,    17,
     929,   931,   933,   942,   934,   940,   943,    38,   944,    39,
    1101,    19,    20,   945,   949,   946,   961,   947,    21,   957,
     948,   950,    22,    23,   953,    24,   954,   955,     6,   956,
      25,     7,     8,     9,    26,    27,    28,   958,   760,    29,
     959,    30,   960,    31,    32,    33,    34,   962,   963,   964,
      35,   969,   970,   965,    36,   972,   971,    37,    10,    11,
      12,    13,    14,    15,   973,    16,    17,   980,   974,   978,
     989,   983,   994,   998,    38,   990,    39,   991,    19,    20,
     992,   993,  1005,  1013,   995,    21,   996,   997,  1006,    22,
      23,  1007,    24,   786,  1008,     6,  1009,    25,     7,     8,
       9,    26,    27,    28,  1010,  1011,    29,  1012,    30,  1014,
      31,    32,    33,    34,  1015,  1016,  1017,    35,  1018,  1019,
    1020,    36,  1021,  1022,    37,    10,    11,    12,    13,    14,
      15,  1024,    16,    17,  1025,  1026,  1027,  1053,  1035,  1031,
    1032,  1033,  1034,  1036,  1037,    19,    20,  1038,  1039,  1055,
    1046,  1054,    21,  1063,  1056,  -194,    22,    23,  1057,    24,
    1058,    38,     6,    39,    25,     7,     8,     9,    26,    27,
      28,  1061,  1062,    29,  1064,    30,  1065,    31,    32,    33,
      34,  1066,  1070,  1067,    35,  1068,  1069,  1072,    36,  1071,
    1073,    37,    10,    11,    12,    13,    14,    15,  1074,    16,
      17,  1089,  1075,  1076,  1077,  1078,  1081,  1082,  1083,  1084,
    1097,  1096,    19,    20,  1086,  1087,  1088,  1102,  1113,    21,
    1120,  1122,  1121,    22,    23,  1125,    24,   880,    38,     6,
      39,    25,     7,     8,     9,    26,    27,    28,  1123,  1124,
      29,  1127,    30,  1128,    31,    32,    33,    34,  1129,  1130,
    1131,    35,  1132,  1133,  1134,    36,  1137,  1138,    37,    10,
      11,    12,    13,    14,    15,  1139,    16,    17,  1140,  1141,
    1144,  1145,  1150,  1146,  1149,  1159,  1151,  1152,  1153,    19,
      20,  1154,  1155,  1156,  1157,  1158,    21,  1161,   488,  1160,
      22,    23,   329,    24,   882,    38,     6,    39,    25,     7,
       8,     9,    26,    27,    28,     0,   514,    29,     0,    30,
     489,    31,    32,    33,    34,     0,     0,     0,    35,     0,
       0,     0,    36,     0,     0,    37,    10,    11,    12,    13,
      14,    15,     0,    16,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    19,    20,     0,     0,
       0,     0,     0,    21,     0,     0,     0,    22,    23,     0,
      24,   981,    38,     6,    39,    25,     7,     8,     9,    26,
      27,    28,     0,     0,    29,     0,    30,     0,    31,    32,
      33,    34,     0,     0,     0,    35,     0,     0,     0,    36,
       0,     0,    37,    10,    11,    12,    13,    14,    15,     0,
      16,    17,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    19,    20,     0,     0,     0,     0,     0,
      21,     0,     0,     0,    22,    23,     0,    24,   982,    38,
       6,    39,    25,     7,     8,     9,    26,    27,    28,     0,
       0,    29,     0,    30,     0,    31,    32,    33,    34,     0,
       0,     0,    35,     0,     0,     0,    36,     0,     0,    37,
      10,    11,    12,    13,    14,    15,     0,    16,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      19,    20,     0,     0,     0,     0,     0,    21,     0,     0,
       0,    22,    23,     0,    24,     0,    38,     6,    39,    25,
       7,     8,     9,    26,    27,    28,     0,     0,    29,     0,
      30,     0,    31,    32,    33,    34,     0,     0,     0,    35,
    1106,     0,     0,    36,     0,     0,    37,    10,    11,    12,
      13,    14,    15,     0,    16,    17,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    19,    20,     0,
       0,     0,     0,     0,    21,     0,     0,     0,    22,    23,
       0,    24,     0,    38,     0,    39,    25,     0,     0,     0,
      26,    27,    28,     0,     0,    29,     0,    30,     0,    31,
      32,    33,    34,     0,   189,   190,    35,  1126,   191,     0,
      36,   192,     0,    37,     0,   193,   194,   195,   196,   197,
     198,   199,   200,     0,     0,     0,     0,   201,   202,     0,
       0,     0,     0,     0,     0,    77,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,     0,    39,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    78,    79,    80,
      81,    82,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    83,     0,     0,     0,
      84,     0,     0,    85,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,     0,    39,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,     0,    77,   161,     0,     0,
     162,     0,     0,     0,   163,   164,   165,   166,   167,   168,
     169,   170,     0,     0,     0,     0,     0,   171,   172,   173,
     174,   209,     0,   175,     0,     0,     0,   176,    78,    79,
      80,    81,    82,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    83,     0,     0,
       0,    84,     0,     0,    85,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,     0,    77,   161,     0,
       0,   162,     0,     0,     0,   163,   164,   165,   166,   167,
     168,   169,   170,     0,     0,     0,     0,     0,   171,   172,
     173,   174,     0,     0,   175,   435,     0,     0,   176,    78,
      79,    80,    81,    82,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    83,     0,
       0,     0,    84,     0,     0,    85,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,     0,    77,   161,
       0,     0,   162,     0,     0,     0,   163,   164,   165,   166,
     167,   168,   169,   170,     0,     0,     0,     0,     0,   171,
     172,   173,   174,     0,     0,   175,   437,     0,     0,   176,
      78,    79,    80,    81,    82,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    83,
       0,     0,     0,    84,     0,     0,    85,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,     0,    77,
     161,     0,     0,   162,     0,     0,     0,   163,   164,   165,
     166,   167,   168,   169,   170,     0,     0,     0,     0,     0,
     171,   172,   173,   174,     0,     0,   175,   439,     0,     0,
     176,    78,    79,    80,    81,    82,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      83,     0,     0,     0,    84,     0,     0,    85,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,     0,
      77,   161,     0,     0,   162,     0,     0,     0,   163,   164,
     165,   166,   167,   168,   169,   170,     0,     0,     0,     0,
       0,   171,   172,   173,   174,     0,     0,   175,     0,     0,
       0,   176,    78,    79,    80,    81,    82,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    83,     0,     0,     0,    84,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
       0,    77,   161,     0,     0,   162,     0,     0,     0,   163,
     164,   165,   166,   167,   168,   169,   170,     0,     0,     0,
       0,     0,   171,   172,   173,   174,     0,     0,   175,     0,
       0,     0,   176,    78,    79,    80,    81,    82,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    83,     0,     0,     0,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,     0,     0,   161,     0,     0,   162,     0,     0,     0,
     163,   164,   165,   166,   167,   168,   169,   170,     0,     0,
       0,     0,     0,   171,   172,   173,   174,     0,     0,   175,
     411,   412,   413,   414,   415,   416,   417,   418,   419,   420,
     421,     0,     0,   424,   425,   426,   427,   428,     0,     0,
       0,   432,   433,   434,   436,   438,   440,     0,     0,     0,
       0,   445,   446,   447,   448,   449,   450,   451,     0,   453,
     454,   455,   456,   457,   458,   459,   460,   461,   462,   463,
     464,   465,   466,   467,   468,   469,   470,   471,   472,   473,
     474,   475,     0,     0,     0,     0,     0,     0,     0,     0,
     484
};

static const yytype_int16 yycheck[] =
{
      10,   528,    10,    49,    14,    69,   354,   355,   356,    19,
      69,    21,    22,    23,   362,    16,    11,    12,    13,    14,
      43,     0,     1,    24,    43,     4,     5,     6,    43,    30,
      31,    32,    33,    96,    43,    86,    43,    38,    43,    43,
      43,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,   202,    31,    32,    33,    34,    35,    36,    95,    38,
      39,   212,   213,   207,    96,    96,    76,   104,    96,    96,
      96,    50,    51,    52,   764,    99,   100,   101,    96,    58,
      96,     3,   190,    62,    63,   191,    65,     0,     0,     1,
      96,    70,     4,     5,     6,    74,    75,    76,   100,   207,
      79,   207,    81,   203,    83,    84,    85,    86,    96,   100,
     203,    90,    96,   105,    96,    94,    96,   203,    97,    31,
      32,    33,    34,    35,    36,    96,    38,    39,    96,    96,
     105,    93,   102,   634,    93,    11,   207,    13,    50,    51,
      52,   831,   104,   207,   207,   104,    58,    95,   207,    98,
      62,    63,   203,    65,   103,    98,   104,   209,    70,    95,
     103,   207,    74,    75,    76,   175,   203,    79,   104,    81,
     208,    83,    84,    85,    86,   207,   207,   207,    90,   207,
     207,   207,    94,   207,   207,    97,   656,   657,   207,   207,
     691,   207,   207,   663,   664,   665,   666,   667,   207,   207,
     207,   207,   207,   207,   207,   207,   203,   208,   203,   179,
     180,   181,   182,   183,   184,   208,   207,   209,   207,   207,
     230,   231,   201,   207,   203,   207,    98,   207,     7,     8,
       9,   103,    98,   207,   209,    87,   207,   103,   207,   207,
     207,   203,   214,   215,   203,    11,    12,    13,    14,    11,
      12,    13,    14,   203,   203,   203,    11,    12,    13,    14,
     203,    11,    12,    13,    14,    71,    72,   203,   208,   210,
     211,   203,   282,   283,   284,   285,   216,   217,   218,   219,
     220,   629,   630,   293,   632,   195,   196,    29,    30,   201,
     209,   203,   203,    48,   195,   196,    88,   207,    40,    41,
      42,   209,   650,   209,    46,    47,   207,   317,   318,   319,
     320,   209,    40,    41,   841,   842,   209,   327,    46,    47,
     210,   211,   323,   324,    22,    23,    24,    25,    26,    27,
     209,   203,   209,   803,   804,   345,   346,   203,   348,   101,
      22,    23,    24,    25,    26,    27,   347,   357,   358,   210,
     211,   101,   210,   211,    29,    30,   209,     1,   100,   209,
       4,     5,     6,    29,    30,    40,    41,    42,    30,   379,
     209,    46,    47,   209,    40,    41,   210,   211,    40,    41,
      46,    47,   210,   211,    46,    47,   209,    31,    32,    33,
      34,    35,    36,   209,    38,    39,   333,   334,   335,   336,
     337,   338,   339,   210,   211,   209,   754,    51,    52,   757,
     209,   759,   210,   211,    58,    59,    60,    61,    62,    63,
     209,    65,   210,   211,     1,   100,    70,     4,     5,     6,
      74,    75,    76,   209,   100,    79,   209,    81,   100,    83,
      84,    85,    86,   210,   211,   209,    90,   210,   211,   209,
      94,   210,   211,    97,    31,    32,    33,    34,    35,    36,
     209,    38,    39,    11,    12,    13,    14,    11,    12,    13,
      14,   819,   210,   211,    51,    52,    11,    12,    13,    14,
     209,    58,   206,   210,   211,    62,    63,   209,    65,    11,
      12,    13,    14,    70,    71,    72,    73,    74,    75,    76,
     210,   211,    79,   209,    81,   506,    83,    84,    85,    86,
     210,   211,   209,    90,   210,   211,   209,    94,     1,   209,
      97,     4,     5,     6,   209,   535,   210,   211,   207,   210,
     211,   879,   209,   881,   210,   211,   210,   211,   210,   211,
     210,   211,   209,   553,   105,   210,   211,   208,    31,    32,
      33,    34,    35,    36,   209,    38,    39,   201,   209,   203,
     210,   211,   210,   211,   210,   211,   576,   209,    51,    52,
     210,   211,   210,   211,   209,    58,    59,    60,    61,    62,
      63,   209,    65,   210,   211,   933,   209,    70,   210,   211,
     209,    74,    75,    76,   210,   211,    79,   209,    81,   209,
      83,    84,    85,    86,   210,   211,   209,    90,   210,   211,
     209,    94,   210,   211,    97,   209,     1,   627,   628,     4,
       5,     6,   210,   211,   201,   209,   203,   210,   211,   210,
     211,   210,   211,    67,    68,   983,   210,   211,   210,   211,
     210,   211,   210,   211,   210,   211,    31,    32,    33,    34,
      35,    36,    37,    38,    39,   210,   211,   210,   211,   210,
     211,   210,   211,   210,   211,   208,    51,    52,   678,   210,
     211,   210,   211,    58,   210,   211,   209,    62,    63,   209,
      65,   210,   211,   210,   211,    70,   212,   213,   209,    74,
      75,    76,    59,    60,    79,   209,    81,   209,    83,    84,
      85,    86,     3,     4,   209,    90,    91,   340,   341,    94,
     342,   343,    97,  1061,   209,   209,   209,   209,   201,   209,
     203,     1,   209,   209,     4,     5,     6,   209,   209,   209,
     209,   209,   209,   209,   209,  1083,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   208,   756,   207,   758,   207,
     207,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      53,   207,   207,   207,    71,   208,   207,   207,   207,   207,
     207,    51,    52,    46,   202,   207,   203,   207,    58,   789,
     209,   207,    62,    63,   794,    65,   209,   209,   798,   209,
      70,   209,   207,   207,    74,    75,    76,   209,   209,    79,
     209,    81,   209,    83,    84,    85,    86,   209,   209,   209,
      90,    91,   207,   210,    94,   207,   201,    97,   203,   210,
     210,   210,   210,   203,   210,   203,     1,   210,   210,     4,
       5,     6,   207,   209,   211,   209,   209,   209,   209,   209,
     209,   207,   210,   204,   854,   210,   209,   857,   204,   204,
     204,   861,   204,   203,   864,   204,    31,    32,    33,    34,
      35,    36,   209,    38,    39,   209,   204,   204,   204,   204,
     185,   211,   211,   207,   207,    73,    51,    52,   210,   210,
     210,   210,   210,    58,   210,   210,   210,    62,    63,   210,
      65,   210,   210,   207,   207,    70,   207,   207,    92,    74,
      75,    76,    77,   206,    79,   204,    81,   204,    83,    84,
      85,    86,   204,     1,   924,    90,     4,     5,     6,    94,
     204,   201,    97,   203,   209,   204,   209,   203,   105,   207,
     207,    61,   214,    99,   203,   210,   210,   203,   210,   206,
     211,   211,   210,    31,    32,    33,    34,    35,    36,   210,
      38,    39,   210,   210,   210,   210,   207,   211,   207,   207,
     207,   207,   203,    51,    52,   210,   210,   210,   978,   211,
      58,   210,   204,   210,    62,    63,    64,    65,   207,   210,
       1,   203,    70,     4,     5,     6,    74,    75,    76,   204,
     211,    79,   204,    81,   210,    83,    84,    85,    86,   210,
     207,   206,    90,   211,   210,   204,    94,   210,   210,    97,
      31,    32,    33,    34,    35,    36,   203,    38,    39,   210,
     210,   210,   207,   207,   207,   207,   201,   207,   203,   210,
      51,    52,   210,   209,    30,   209,   209,    58,   209,   209,
      30,    62,    63,    64,    65,   214,   209,     1,   209,    70,
       4,     5,     6,    74,    75,    76,   207,   209,    79,   209,
      81,   207,    83,    84,    85,    86,    30,   209,   209,    90,
      30,   209,   207,    94,   210,   207,    97,    31,    32,    33,
      34,    35,    36,   210,    38,    39,   207,   207,   207,   207,
     207,   207,   204,   207,   207,   210,   207,    51,    52,   207,
     210,   207,   209,   204,    58,   209,   209,   209,    62,    63,
     209,    65,   207,   201,     1,   203,    70,     4,     5,     6,
      74,    75,    76,   207,   209,    79,    80,    81,   209,    83,
      84,    85,    86,   209,   209,   209,    90,   204,   204,   207,
      94,   210,   203,    97,    31,    32,    33,    34,    35,    36,
     209,    38,    39,   209,   204,   204,   209,   203,   209,   204,
     207,    30,   210,     1,    51,    52,   210,   210,   210,   210,
     210,    58,   207,   207,   203,    62,    63,   209,    65,   209,
     201,   209,   203,    70,   209,   204,    73,    74,    75,    76,
     204,   204,    79,   204,    81,   204,    83,    84,    85,    86,
     204,     1,   204,    90,     4,     5,     6,    94,   211,   204,
      97,   204,   210,   210,   827,   207,   210,    85,   327,   210,
      44,   210,   210,   210,   210,   210,   210,   210,   209,   209,
     207,    31,    32,    33,    34,    35,    36,   207,    38,    39,
     207,   207,   207,   204,   203,   207,   204,   201,   204,   203,
      44,    51,    52,   204,   211,   210,   204,   210,    58,   211,
     210,   210,    62,    63,   210,    65,   210,   210,     1,   210,
      70,     4,     5,     6,    74,    75,    76,   207,    78,    79,
     207,    81,   207,    83,    84,    85,    86,   210,   207,   207,
      90,   207,   207,   210,    94,   207,   210,    97,    31,    32,
      33,    34,    35,    36,   207,    38,    39,   204,   210,   209,
     209,   207,   207,   211,   201,   209,   203,   209,    51,    52,
     209,   209,   204,   204,   210,    58,   210,   210,   207,    62,
      63,   207,    65,    66,   207,     1,   207,    70,     4,     5,
       6,    74,    75,    76,   207,   207,    79,   207,    81,   210,
      83,    84,    85,    86,   207,   207,   207,    90,   207,   207,
     207,    94,   207,   207,    97,    31,    32,    33,    34,    35,
      36,   210,    38,    39,   210,   207,   207,   210,   204,   209,
     209,   209,   209,   204,   204,    51,    52,   204,   203,   207,
     204,   210,    58,   204,   210,    61,    62,    63,   207,    65,
     207,   201,     1,   203,    70,     4,     5,     6,    74,    75,
      76,   207,   207,    79,   204,    81,   204,    83,    84,    85,
      86,   204,   211,   210,    90,   210,   210,   207,    94,   210,
     207,    97,    31,    32,    33,    34,    35,    36,   207,    38,
      39,   211,   210,   209,   209,   209,   207,   207,   207,   207,
     207,   204,    51,    52,   210,   210,   210,    44,   204,    58,
     210,   210,   207,    62,    63,   209,    65,    66,   201,     1,
     203,    70,     4,     5,     6,    74,    75,    76,   210,   210,
      79,   207,    81,   207,    83,    84,    85,    86,   207,   207,
     210,    90,   209,   209,   209,    94,   207,   207,    97,    31,
      32,    33,    34,    35,    36,   207,    38,    39,    44,   207,
      44,    44,   207,    44,   210,    44,   210,   210,   210,    51,
      52,   209,   207,   207,   207,   207,    58,   207,   331,   210,
      62,    63,   176,    65,    66,   201,     1,   203,    70,     4,
       5,     6,    74,    75,    76,    -1,   359,    79,    -1,    81,
     332,    83,    84,    85,    86,    -1,    -1,    -1,    90,    -1,
      -1,    -1,    94,    -1,    -1,    97,    31,    32,    33,    34,
      35,    36,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    -1,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    -1,    62,    63,    -1,
      65,    66,   201,     1,   203,    70,     4,     5,     6,    74,
      75,    76,    -1,    -1,    79,    -1,    81,    -1,    83,    84,
      85,    86,    -1,    -1,    -1,    90,    -1,    -1,    -1,    94,
      -1,    -1,    97,    31,    32,    33,    34,    35,    36,    -1,
      38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    -1,    -1,    -1,    -1,    -1,
      58,    -1,    -1,    -1,    62,    63,    -1,    65,    66,   201,
       1,   203,    70,     4,     5,     6,    74,    75,    76,    -1,
      -1,    79,    -1,    81,    -1,    83,    84,    85,    86,    -1,
      -1,    -1,    90,    -1,    -1,    -1,    94,    -1,    -1,    97,
      31,    32,    33,    34,    35,    36,    -1,    38,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    52,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,
      -1,    62,    63,    -1,    65,    -1,   201,     1,   203,    70,
       4,     5,     6,    74,    75,    76,    -1,    -1,    79,    -1,
      81,    -1,    83,    84,    85,    86,    -1,    -1,    -1,    90,
      91,    -1,    -1,    94,    -1,    -1,    97,    31,    32,    33,
      34,    35,    36,    -1,    38,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    -1,
      -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,    62,    63,
      -1,    65,    -1,   201,    -1,   203,    70,    -1,    -1,    -1,
      74,    75,    76,    -1,    -1,    79,    -1,    81,    -1,    83,
      84,    85,    86,    -1,   179,   180,    90,    91,   183,    -1,
      94,   186,    -1,    97,    -1,   190,   191,   192,   193,   194,
     195,   196,   197,    -1,    -1,    -1,    -1,   202,   203,    -1,
      -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     201,    -1,   203,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,
      56,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,    -1,    -1,
      86,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,    -1,   203,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,    -1,    21,   183,    -1,    -1,
     186,    -1,    -1,    -1,   190,   191,   192,   193,   194,   195,
     196,   197,    -1,    -1,    -1,    -1,    -1,   203,   204,   205,
     206,   207,    -1,   209,    -1,    -1,    -1,   213,    53,    54,
      55,    56,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,    -1,
      -1,    86,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,    -1,    21,   183,    -1,
      -1,   186,    -1,    -1,    -1,   190,   191,   192,   193,   194,
     195,   196,   197,    -1,    -1,    -1,    -1,    -1,   203,   204,
     205,   206,    -1,    -1,   209,   210,    -1,    -1,   213,    53,
      54,    55,    56,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,
      -1,    -1,    86,    -1,    -1,    89,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,    -1,    21,   183,
      -1,    -1,   186,    -1,    -1,    -1,   190,   191,   192,   193,
     194,   195,   196,   197,    -1,    -1,    -1,    -1,    -1,   203,
     204,   205,   206,    -1,    -1,   209,   210,    -1,    -1,   213,
      53,    54,    55,    56,    57,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      -1,    -1,    -1,    86,    -1,    -1,    89,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,    -1,    21,
     183,    -1,    -1,   186,    -1,    -1,    -1,   190,   191,   192,
     193,   194,   195,   196,   197,    -1,    -1,    -1,    -1,    -1,
     203,   204,   205,   206,    -1,    -1,   209,   210,    -1,    -1,
     213,    53,    54,    55,    56,    57,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      82,    -1,    -1,    -1,    86,    -1,    -1,    89,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,    -1,
      21,   183,    -1,    -1,   186,    -1,    -1,    -1,   190,   191,
     192,   193,   194,   195,   196,   197,    -1,    -1,    -1,    -1,
      -1,   203,   204,   205,   206,    -1,    -1,   209,    -1,    -1,
      -1,   213,    53,    54,    55,    56,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    -1,    -1,    -1,    86,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
      -1,    21,   183,    -1,    -1,   186,    -1,    -1,    -1,   190,
     191,   192,   193,   194,   195,   196,   197,    -1,    -1,    -1,
      -1,    -1,   203,   204,   205,   206,    -1,    -1,   209,    -1,
      -1,    -1,   213,    53,    54,    55,    56,    57,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    82,    -1,    -1,    -1,    86,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,    -1,    -1,   183,    -1,    -1,   186,    -1,    -1,    -1,
     190,   191,   192,   193,   194,   195,   196,   197,    -1,    -1,
      -1,    -1,    -1,   203,   204,   205,   206,    -1,    -1,   209,
     255,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,    -1,    -1,   268,   269,   270,   271,   272,    -1,    -1,
      -1,   276,   277,   278,   279,   280,   281,    -1,    -1,    -1,
      -1,   286,   287,   288,   289,   290,   291,   292,    -1,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     325
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,     3,   222,   223,   223,     0,     1,     4,     5,     6,
      31,    32,    33,    34,    35,    36,    38,    39,    50,    51,
      52,    58,    62,    63,    65,    70,    74,    75,    76,    79,
      81,    83,    84,    85,    86,    90,    94,    97,   201,   203,
     225,   226,   227,   229,   230,   231,   232,   233,   234,   235,
     236,   237,   238,   239,   240,   241,   248,   249,   250,   251,
     252,   253,   254,   255,   256,   259,   263,   264,   265,   266,
     267,   271,   272,   207,   203,   203,   203,    21,    53,    54,
      55,    56,    57,    82,    86,    89,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   183,   186,   190,   191,   192,   193,   194,   195,   196,
     197,   203,   204,   205,   206,   209,   213,   273,   274,   275,
     276,   277,   278,   279,   280,   281,   283,   203,   230,   179,
     180,   183,   186,   190,   191,   192,   193,   194,   195,   196,
     197,   202,   203,   282,   230,   273,   207,   282,   209,   207,
     273,   208,   273,   273,   273,   282,   207,   207,   207,   207,
     203,   282,   282,   282,   282,   203,   203,   203,   282,   105,
     209,   208,     7,     8,     9,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,   102,   179,   180,   181,   182,
     183,   184,   273,   277,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   206,   209,   273,   281,
     207,    88,    87,   208,   216,   217,   218,   219,   220,   202,
     212,   213,   214,   215,   105,   209,   208,   208,   208,   207,
     207,   282,   207,    53,   207,   207,   207,   208,    71,   268,
     269,   224,   207,   207,   207,   207,   207,    46,   242,    11,
      12,    13,    14,    48,   243,    99,   100,   101,   207,   202,
     203,   273,   284,   285,   273,    10,   207,   207,   207,   209,
     209,   209,   209,   209,   190,   207,   191,   207,   207,   207,
     207,   209,   209,   209,   209,   209,   209,   209,   207,   273,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   210,   210,   286,   286,   286,   286,   286,   210,
     210,   210,   286,   286,   286,   210,   286,   210,   286,   210,
     286,   273,   273,   273,   273,   286,   286,   286,   286,   286,
     286,   286,   273,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   273,   273,   273,   273,
     203,   210,   282,   282,   286,   273,   284,   210,   275,   276,
     278,   278,   278,   278,   278,   278,   278,   279,   279,   280,
     280,   203,   273,   273,   282,   273,   210,   207,   224,   224,
     224,   273,   273,    72,   269,   270,    77,   225,   224,   207,
     209,   209,   209,   209,   209,    49,   207,   100,   207,   209,
     209,   257,   273,   210,   210,   211,   207,   209,   204,   204,
     204,   204,   204,   209,   209,   203,   204,   204,   204,   204,
     204,   185,   210,   211,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   211,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   211,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     207,   207,   207,   282,   260,    64,    64,    67,    68,   207,
     207,    73,   207,    80,    92,   204,   204,   204,   204,   206,
     209,   246,   209,   257,   204,   203,    98,   103,   203,   258,
     207,   105,   207,   273,   214,   210,   210,   210,   211,   211,
     203,   203,   210,   210,   210,   210,   210,   210,   211,   273,
     273,    22,    23,    24,    25,    26,    27,   207,    59,    60,
     261,   262,   207,   207,   273,   273,   224,   224,   207,   224,
     207,   203,   243,   210,   210,   210,   211,   210,   206,    95,
     104,   203,   247,   204,    98,   210,   210,   207,   203,    11,
      12,    13,    14,   224,   203,   211,    29,    30,    40,    41,
      42,    46,    47,   100,   228,    30,    46,   100,   228,    29,
      30,    42,    46,   100,   228,   204,   204,   210,   210,   207,
     228,   228,   228,   228,   228,   206,   211,   210,   210,   210,
     210,   210,   210,   273,   207,    61,    69,   207,    69,   207,
      78,   243,   207,   204,   207,   210,   207,   203,    11,    12,
      13,    14,   101,   210,   207,    99,   100,   207,    11,    12,
      13,    14,   209,   209,   209,   209,    66,   214,    30,   209,
     209,    30,   209,   207,   209,   209,   207,    30,   209,   209,
      30,   209,   207,   210,   210,   207,   207,   207,   207,   207,
     207,   207,   210,    22,    23,    24,    25,    26,    27,   207,
     224,   207,   273,   224,   273,   224,   207,   207,   244,   210,
     246,   207,    11,    12,    13,    14,   209,   209,   209,   209,
     209,   207,   207,   209,   209,   209,   209,   209,   204,   204,
     204,   204,   207,   210,   209,   273,   203,   209,   204,   273,
     204,   209,   273,   203,   209,   204,    29,    30,   100,   228,
     228,   207,   210,   210,   210,   210,   210,   210,   224,   207,
      66,   207,    66,   244,    93,   104,   203,   245,    95,   246,
     209,   209,   209,   209,   204,   204,   204,   204,   203,   257,
     257,   204,   204,   204,   204,   204,   210,   210,   210,   211,
     207,   273,   210,   210,   273,   210,   210,   210,   273,   210,
     210,   273,   210,    30,   209,   209,   207,   207,   224,   207,
     224,   207,    93,   207,   203,    11,    12,    13,    14,   101,
     207,    95,   204,   204,   204,   204,   210,   210,   210,   211,
     210,    98,    98,   210,   210,   210,   210,   211,   207,   207,
     207,   204,   210,   207,   207,   210,   195,   196,   207,   207,
     207,   210,   207,   207,   210,   195,   196,   207,   209,   273,
     204,    66,    66,   207,   224,    11,    12,    13,    14,   209,
     209,   209,   209,   209,   207,   210,   210,   210,   211,    96,
     207,    96,   207,    96,   207,   204,   207,   207,   207,   207,
     207,   207,   207,   204,   210,   207,   207,   207,   207,   207,
     207,   207,   207,   273,   210,   210,   207,   207,   224,    37,
      91,   209,   209,   209,   209,   204,   204,   204,   204,   203,
      96,   207,    96,   207,    96,   207,   204,    43,   207,    43,
     207,    43,   207,   210,   210,   207,   210,   207,   207,    37,
      91,   207,   207,   204,   204,   204,   204,   210,   210,   210,
     211,   210,   207,   207,   207,   210,   209,   209,   209,    96,
     207,   207,   207,   207,   207,   224,   210,   210,   210,   211,
      96,   207,    96,   207,    96,   207,   204,   207,    96,   207,
      44,    44,    44,    43,   207,   224,    91,    96,   207,    96,
     207,    96,   207,   204,    43,   207,    43,   207,    43,   207,
     210,   207,   210,   210,   210,   209,    91,   207,   207,   207,
     207,   210,   209,   209,   209,    96,   207,   207,   207,   207,
      44,   207,    96,   207,    44,    44,    44,    43,   207,   210,
     207,   210,   210,   210,   209,   207,   207,   207,   207,    44,
     210,   207
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   221,   222,   222,   223,   223,   223,   224,   224,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   226,   226,   226,   226,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   228,   228,   228,   228,   228,   229,   230,
     230,   230,   230,   230,   231,   231,   232,   233,   234,   235,
     236,   237,   238,   238,   239,   240,   240,   240,   241,   241,
     241,   241,   242,   242,   243,   243,   243,   243,   243,   244,
     244,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   246,   246,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   256,   256,   256,   256,   256,   257,
     257,   258,   258,   258,   258,   258,   258,   258,   258,   259,
     260,   260,   261,   262,   262,   263,   264,   265,   265,   265,
     265,   266,   267,   268,   268,   269,   270,   270,   271,   272,
     273,   274,   274,   275,   275,   276,   276,   277,   277,   277,
     277,   277,   277,   277,   277,   278,   278,   278,   279,   279,
     279,   280,   280,   281,   281,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   284,   284,   285,   285,   286,   286
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     0,     2,     2,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     4,     4,     4,    10,     8,     8,     8,    10,    10,
      12,    12,    14,    11,    11,    13,    11,    12,    12,     4,
       4,     4,     4,     4,    11,    11,    11,    13,     7,     8,
       8,     8,     8,     8,     9,    11,    11,    12,    12,    12,
      12,     8,     8,     0,     1,     1,     1,     1,     4,     1,
       1,     3,     4,     6,     4,     5,     5,     5,     3,     2,
       3,     4,     3,     2,     5,     7,    11,    10,    13,    14,
      16,    17,     0,     1,     0,     4,     4,     4,     6,     0,
       2,     6,     7,     6,     7,     6,     7,     8,     9,     7,
       8,     7,     8,     7,     8,     9,    10,     6,    11,    11,
      11,    13,     0,     2,     6,     7,     6,     7,     6,     7,
       8,     9,     7,     8,     7,     8,     7,     8,     9,    10,
       6,    11,    11,    11,    13,     8,     6,     3,     3,     3,
       3,     3,     6,     7,     6,    11,    11,     7,    11,     0,
       2,     6,     6,     6,     8,     7,     7,     7,     9,     8,
       0,     2,     4,     0,     3,     6,     6,    10,    12,    10,
      12,     8,     6,     1,     2,     4,     0,     3,     2,     2,
       1,     1,     3,     1,     3,     1,     2,     1,     3,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     2,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     3,     4,
       4,     4,     4,     4,     4,     4,     4,     6,     6,     6,
       6,     6,     6,     4,     4,     4,     4,     3,     3,     4,
       4,     4,     4,     4,     4,     3,     4,     3,     4,     3,
       8,     8,     8,     4,     4,     4,     3,     3,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     3,     1,     8,     8,     8,     2,
       4,     4,     4,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     0,     1,     1,     3,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: KW_FREE statements_opt  */
#line 184 "src/parser.y"
                           {
        (yyval.program) = g_program;
    }
#line 2541 "build/parser.cpp"
    break;

  case 3: /* program: statements_opt  */
#line 187 "src/parser.y"
                     {
        (yyval.program) = g_program;
    }
#line 2549 "build/parser.cpp"
    break;

  case 5: /* statements_opt: statements_opt statement  */
#line 194 "src/parser.y"
                               {
        if ((yyvsp[0].stmt)) {
            g_program->statements.emplace_back((yyvsp[0].stmt));
        }
    }
#line 2559 "build/parser.cpp"
    break;

  case 6: /* statements_opt: statements_opt KW_CTLOPT  */
#line 199 "src/parser.y"
                               {
        if (ctlopt_nomain) g_program->nomain = true;
        if (ctlopt_main_proc[0]) g_program->main_proc = ctlopt_main_proc;
        if (ctlopt_datfmt[0]) g_program->datfmt = ctlopt_datfmt;
        if (ctlopt_timfmt[0]) g_program->timfmt = ctlopt_timfmt;
    }
#line 2570 "build/parser.cpp"
    break;

  case 7: /* statement_list: %empty  */
#line 208 "src/parser.y"
                {
        (yyval.stmt_list) = new StmtList();
    }
#line 2578 "build/parser.cpp"
    break;

  case 8: /* statement_list: statement_list statement  */
#line 211 "src/parser.y"
                               {
        (yyval.stmt_list) = (yyvsp[-1].stmt_list);
        if ((yyvsp[0].stmt)) {
            (yyval.stmt_list)->stmts.push_back((yyvsp[0].stmt));
        }
    }
#line 2589 "build/parser.cpp"
    break;

  case 9: /* statement: dcl_f_stmt  */
#line 220 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2595 "build/parser.cpp"
    break;

  case 10: /* statement: dcl_s_stmt  */
#line 221 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2601 "build/parser.cpp"
    break;

  case 11: /* statement: dcl_c_stmt  */
#line 222 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2607 "build/parser.cpp"
    break;

  case 12: /* statement: eval_stmt  */
#line 223 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2613 "build/parser.cpp"
    break;

  case 13: /* statement: eval_corr_stmt  */
#line 224 "src/parser.y"
                     { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2619 "build/parser.cpp"
    break;

  case 14: /* statement: dsply_stmt  */
#line 225 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2625 "build/parser.cpp"
    break;

  case 15: /* statement: inlr_stmt  */
#line 226 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2631 "build/parser.cpp"
    break;

  case 16: /* statement: return_stmt  */
#line 227 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2637 "build/parser.cpp"
    break;

  case 17: /* statement: if_stmt  */
#line 228 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2643 "build/parser.cpp"
    break;

  case 18: /* statement: dow_stmt  */
#line 229 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2649 "build/parser.cpp"
    break;

  case 19: /* statement: dou_stmt  */
#line 230 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2655 "build/parser.cpp"
    break;

  case 20: /* statement: for_stmt  */
#line 231 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2661 "build/parser.cpp"
    break;

  case 21: /* statement: for_each_stmt  */
#line 232 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2667 "build/parser.cpp"
    break;

  case 22: /* statement: select_stmt  */
#line 233 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2673 "build/parser.cpp"
    break;

  case 23: /* statement: iter_stmt  */
#line 234 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2679 "build/parser.cpp"
    break;

  case 24: /* statement: leave_stmt  */
#line 235 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2685 "build/parser.cpp"
    break;

  case 25: /* statement: dcl_proc_stmt  */
#line 236 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2691 "build/parser.cpp"
    break;

  case 26: /* statement: dcl_pr_stmt  */
#line 237 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2697 "build/parser.cpp"
    break;

  case 27: /* statement: dcl_ds_stmt  */
#line 238 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2703 "build/parser.cpp"
    break;

  case 28: /* statement: monitor_stmt  */
#line 239 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2709 "build/parser.cpp"
    break;

  case 29: /* statement: begsr_stmt  */
#line 240 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2715 "build/parser.cpp"
    break;

  case 30: /* statement: exsr_stmt  */
#line 241 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2721 "build/parser.cpp"
    break;

  case 31: /* statement: reset_stmt  */
#line 242 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2727 "build/parser.cpp"
    break;

  case 32: /* statement: clear_stmt  */
#line 243 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2733 "build/parser.cpp"
    break;

  case 33: /* statement: sorta_stmt  */
#line 244 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2739 "build/parser.cpp"
    break;

  case 34: /* statement: evalr_stmt  */
#line 245 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2745 "build/parser.cpp"
    break;

  case 35: /* statement: callp_stmt  */
#line 246 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2751 "build/parser.cpp"
    break;

  case 36: /* statement: leavesr_stmt  */
#line 247 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2757 "build/parser.cpp"
    break;

  case 37: /* statement: dealloc_stmt  */
#line 248 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2763 "build/parser.cpp"
    break;

  case 38: /* statement: test_stmt  */
#line 249 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2769 "build/parser.cpp"
    break;

  case 39: /* statement: expr_stmt  */
#line 250 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2775 "build/parser.cpp"
    break;

  case 40: /* statement: error SEMICOLON  */
#line 251 "src/parser.y"
                      { (yyval.stmt) = nullptr; yyerrok; }
#line 2781 "build/parser.cpp"
    break;

  case 41: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_DISK SEMICOLON  */
#line 256 "src/parser.y"
                                          {
        (yyval.stmt) = new rpg::DclF((yyvsp[-2].sval), "DISK");
        free((yyvsp[-2].sval));
    }
#line 2790 "build/parser.cpp"
    break;

  case 42: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_PRINTER SEMICOLON  */
#line 260 "src/parser.y"
                                               {
        (yyval.stmt) = new rpg::DclF((yyvsp[-2].sval), "PRINTER");
        free((yyvsp[-2].sval));
    }
#line 2799 "build/parser.cpp"
    break;

  case 43: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_WORKSTN SEMICOLON  */
#line 264 "src/parser.y"
                                               {
        (yyval.stmt) = new rpg::DclF((yyvsp[-2].sval), "WORKSTN");
        free((yyvsp[-2].sval));
    }
#line 2808 "build/parser.cpp"
    break;

  case 44: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_DISK KW_USAGE LPAREN STAR COLON STAR RPAREN SEMICOLON  */
#line 268 "src/parser.y"
                                                                                   {
        (yyval.stmt) = new rpg::DclF((yyvsp[-8].sval), "DISK");
        free((yyvsp[-8].sval));
    }
#line 2817 "build/parser.cpp"
    break;

  case 45: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 276 "src/parser.y"
                                                                                       {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 2827 "build/parser.cpp"
    break;

  case 46: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 281 "src/parser.y"
                                                                                            {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 2837 "build/parser.cpp"
    break;

  case 47: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 286 "src/parser.y"
                                                                                        {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::INT10, 0);
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 2847 "build/parser.cpp"
    break;

  case 48: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 291 "src/parser.y"
                                                                                                                 {
        auto* n = new rpg::DclS((yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-8].sval));
    }
#line 2857 "build/parser.cpp"
    break;

  case 49: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_ZONED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 296 "src/parser.y"
                                                                                                                {
        auto* n = new rpg::DclS((yyvsp[-8].sval), rpg::RPGType::ZONED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-8].sval));
    }
#line 2867 "build/parser.cpp"
    break;

  case 50: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_CONST KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 301 "src/parser.y"
                                                                                                                  {
        (yyval.stmt) = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, true,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-10].sval));
    }
#line 2877 "build/parser.cpp"
    break;

  case 51: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_CONST KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 306 "src/parser.y"
                                                                                                                   {
        (yyval.stmt) = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, true,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-10].sval));
    }
#line 2887 "build/parser.cpp"
    break;

  case 52: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_CONST KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 311 "src/parser.y"
                                                                                                                                           {
        (yyval.stmt) = new rpg::DclS((yyvsp[-12].sval), rpg::RPGType::PACKED, 0, (yyvsp[-9].ival), (yyvsp[-7].ival), true,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-12].sval));
    }
#line 2897 "build/parser.cpp"
    break;

  case 53: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 316 "src/parser.y"
                                                                                                         {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-9].sval));
    }
#line 2907 "build/parser.cpp"
    break;

  case 54: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 321 "src/parser.y"
                                                                                                          {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-9].sval));
    }
#line 2917 "build/parser.cpp"
    break;

  case 55: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 326 "src/parser.y"
                                                                                                                                  {
        (yyval.stmt) = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-11].sval));
    }
#line 2927 "build/parser.cpp"
    break;

  case 56: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 331 "src/parser.y"
                                                                                                             {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-9].sval));
    }
#line 2937 "build/parser.cpp"
    break;

  case 57: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_EXPORT KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 337 "src/parser.y"
                                                                                                                   {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        n->is_export = true;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 2948 "build/parser.cpp"
    break;

  case 58: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_EXPORT KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 343 "src/parser.y"
                                                                                                                    {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        n->is_export = true;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 2959 "build/parser.cpp"
    break;

  case 59: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_IND SEMICOLON  */
#line 349 "src/parser.y"
                                           {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::IND, 0);
        free((yyvsp[-2].sval));
    }
#line 2968 "build/parser.cpp"
    break;

  case 60: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_DATE SEMICOLON  */
#line 353 "src/parser.y"
                                            {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::DATE, 0);
        free((yyvsp[-2].sval));
    }
#line 2977 "build/parser.cpp"
    break;

  case 61: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_TIME SEMICOLON  */
#line 357 "src/parser.y"
                                            {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::TIME, 0);
        free((yyvsp[-2].sval));
    }
#line 2986 "build/parser.cpp"
    break;

  case 62: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_TIMESTAMP SEMICOLON  */
#line 361 "src/parser.y"
                                                 {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::TIMESTAMP, 0);
        free((yyvsp[-2].sval));
    }
#line 2995 "build/parser.cpp"
    break;

  case 63: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_POINTER SEMICOLON  */
#line 365 "src/parser.y"
                                               {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::POINTER, 0);
        free((yyvsp[-2].sval));
    }
#line 3004 "build/parser.cpp"
    break;

  case 64: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 369 "src/parser.y"
                                                                                                              {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-9].sval));
    }
#line 3013 "build/parser.cpp"
    break;

  case 65: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 373 "src/parser.y"
                                                                                                               {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-9].sval));
    }
#line 3022 "build/parser.cpp"
    break;

  case 66: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 377 "src/parser.y"
                                                                                                                  {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-9].sval));
    }
#line 3031 "build/parser.cpp"
    break;

  case 67: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 381 "src/parser.y"
                                                                                                                                       {
        (yyval.stmt) = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-11].sval));
    }
#line 3040 "build/parser.cpp"
    break;

  case 68: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_LIKE LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 385 "src/parser.y"
                                                                     {
        auto* node = new rpg::DclS((yyvsp[-5].sval), rpg::RPGType::INT10, 0);
        node->like_var = (yyvsp[-2].sval);
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
        (yyval.stmt) = node;
    }
#line 3052 "build/parser.cpp"
    break;

  case 69: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_UNS LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 392 "src/parser.y"
                                                                                        {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::UNS, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3062 "build/parser.cpp"
    break;

  case 70: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_FLOAT_TYPE LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 397 "src/parser.y"
                                                                                               {
        auto type = ((yyvsp[-3].ival) <= 4) ? rpg::RPGType::FLOAT4 : rpg::RPGType::FLOAT8;
        auto* n = new rpg::DclS((yyvsp[-6].sval), type, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3073 "build/parser.cpp"
    break;

  case 71: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_BINDEC LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 403 "src/parser.y"
                                                                                           {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::BINDEC, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3083 "build/parser.cpp"
    break;

  case 72: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_UCS2 LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 408 "src/parser.y"
                                                                                         {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::UCS2, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3093 "build/parser.cpp"
    break;

  case 73: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_GRAPH LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 413 "src/parser.y"
                                                                                          {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::UCS2, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3103 "build/parser.cpp"
    break;

  case 74: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_OBJECT LPAREN KW_JAVA COLON STRING_LITERAL RPAREN SEMICOLON  */
#line 418 "src/parser.y"
                                                                                         {
        auto* n = new rpg::DclS((yyvsp[-7].sval), rpg::RPGType::OBJECT, 0);
        n->java_class = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-7].sval)); free((yyvsp[-2].sval));
    }
#line 3113 "build/parser.cpp"
    break;

  case 75: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_BASED LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 423 "src/parser.y"
                                                                                                           {
        auto* n = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::INT10, 0);
        n->based_ptr = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
    }
#line 3123 "build/parser.cpp"
    break;

  case 76: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_BASED LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 428 "src/parser.y"
                                                                                                            {
        auto* n = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival));
        n->based_ptr = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
    }
#line 3133 "build/parser.cpp"
    break;

  case 77: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_ASCEND SEMICOLON  */
#line 433 "src/parser.y"
                                                                                                                        {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = 1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3143 "build/parser.cpp"
    break;

  case 78: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_DESCEND SEMICOLON  */
#line 438 "src/parser.y"
                                                                                                                         {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = -1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3153 "build/parser.cpp"
    break;

  case 79: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_ASCEND SEMICOLON  */
#line 443 "src/parser.y"
                                                                                                                         {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = 1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3163 "build/parser.cpp"
    break;

  case 80: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_DESCEND SEMICOLON  */
#line 448 "src/parser.y"
                                                                                                                          {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = -1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3173 "build/parser.cpp"
    break;

  case 81: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_DATE KW_DATFMT LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 453 "src/parser.y"
                                                                               {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::DATE, 0);
        n->datfmt = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-6].sval)); free((yyvsp[-2].sval));
    }
#line 3183 "build/parser.cpp"
    break;

  case 82: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_TIME KW_TIMFMT LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 458 "src/parser.y"
                                                                               {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::TIME, 0);
        n->timfmt = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-6].sval)); free((yyvsp[-2].sval));
    }
#line 3193 "build/parser.cpp"
    break;

  case 83: /* dcl_s_keywords: %empty  */
#line 466 "src/parser.y"
                  { (yyval.ival) = 0; }
#line 3199 "build/parser.cpp"
    break;

  case 84: /* dcl_s_keywords: KW_STATIC  */
#line 467 "src/parser.y"
                  { (yyval.ival) = 1; }
#line 3205 "build/parser.cpp"
    break;

  case 85: /* dcl_s_keywords: KW_TEMPLATE  */
#line 468 "src/parser.y"
                  { (yyval.ival) = 2; }
#line 3211 "build/parser.cpp"
    break;

  case 86: /* dcl_s_keywords: KW_EXPORT  */
#line 469 "src/parser.y"
                  { (yyval.ival) = 4; }
#line 3217 "build/parser.cpp"
    break;

  case 87: /* dcl_s_keywords: KW_IMPORT  */
#line 470 "src/parser.y"
                  { (yyval.ival) = 8; }
#line 3223 "build/parser.cpp"
    break;

  case 88: /* dcl_c_stmt: KW_DCL_C IDENTIFIER expression SEMICOLON  */
#line 475 "src/parser.y"
                                             {
        (yyval.stmt) = new rpg::DclC((yyvsp[-2].sval), std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
        free((yyvsp[-2].sval));
    }
#line 3232 "build/parser.cpp"
    break;

  case 89: /* eval_target: IDENTIFIER  */
#line 482 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier((yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 3241 "build/parser.cpp"
    break;

  case 90: /* eval_target: INDICATOR  */
#line 486 "src/parser.y"
                {
        (yyval.expr) = new rpg::IndicatorExpr((yyvsp[0].ival));
    }
#line 3249 "build/parser.cpp"
    break;

  case 91: /* eval_target: IDENTIFIER DOT IDENTIFIER  */
#line 489 "src/parser.y"
                                {
        auto obj = std::unique_ptr<rpg::Expression>(new rpg::Identifier((yyvsp[-2].sval)));
        (yyval.expr) = new rpg::DotExpr(std::move(obj), (yyvsp[0].sval));
        free((yyvsp[-2].sval));
        free((yyvsp[0].sval));
    }
#line 3260 "build/parser.cpp"
    break;

  case 92: /* eval_target: IDENTIFIER LPAREN expression RPAREN  */
#line 495 "src/parser.y"
                                          {
        (yyval.expr) = new rpg::ArrayAccess((yyvsp[-3].sval), std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
        free((yyvsp[-3].sval));
    }
#line 3269 "build/parser.cpp"
    break;

  case 93: /* eval_target: IDENTIFIER LPAREN expression RPAREN DOT IDENTIFIER  */
#line 499 "src/parser.y"
                                                         {
        auto* arr = new rpg::ArrayAccess((yyvsp[-5].sval), std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)));
        (yyval.expr) = new rpg::DotExpr(std::unique_ptr<rpg::Expression>(arr), (yyvsp[0].sval));
        free((yyvsp[-5].sval));
        free((yyvsp[0].sval));
    }
#line 3280 "build/parser.cpp"
    break;

  case 94: /* eval_stmt: eval_target EQUALS expression SEMICOLON  */
#line 508 "src/parser.y"
                                            {
        (yyval.stmt) = new rpg::EvalStmt(
            std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-1].expr))
        );
    }
#line 3291 "build/parser.cpp"
    break;

  case 95: /* eval_stmt: KW_EVAL eval_target EQUALS expression SEMICOLON  */
#line 514 "src/parser.y"
                                                      {
        (yyval.stmt) = new rpg::EvalStmt(
            std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-1].expr))
        );
    }
#line 3302 "build/parser.cpp"
    break;

  case 96: /* eval_corr_stmt: KW_EVAL_CORR ident EQUALS ident SEMICOLON  */
#line 523 "src/parser.y"
                                              {
        (yyval.stmt) = new rpg::EvalCorrStmt(std::string((yyvsp[-3].sval)), std::string((yyvsp[-1].sval)));
        free((yyvsp[-3].sval));
        free((yyvsp[-1].sval));
    }
#line 3312 "build/parser.cpp"
    break;

  case 97: /* evalr_stmt: KW_EVALR eval_target EQUALS expression SEMICOLON  */
#line 531 "src/parser.y"
                                                     {
        (yyval.stmt) = new rpg::EvalRStmt(
            std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-1].expr))
        );
    }
#line 3323 "build/parser.cpp"
    break;

  case 98: /* callp_stmt: KW_CALLP expression SEMICOLON  */
#line 540 "src/parser.y"
                                  {
        (yyval.stmt) = new rpg::ExprStmt(std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
    }
#line 3331 "build/parser.cpp"
    break;

  case 99: /* leavesr_stmt: KW_LEAVESR SEMICOLON  */
#line 546 "src/parser.y"
                         {
        (yyval.stmt) = new rpg::LeaveSRStmt();
    }
#line 3339 "build/parser.cpp"
    break;

  case 100: /* dsply_stmt: KW_DSPLY expression SEMICOLON  */
#line 552 "src/parser.y"
                                  {
        (yyval.stmt) = new rpg::DsplyStmt(std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
    }
#line 3347 "build/parser.cpp"
    break;

  case 101: /* inlr_stmt: KW_INLR EQUALS KW_ON SEMICOLON  */
#line 558 "src/parser.y"
                                   {
        (yyval.stmt) = new rpg::ReturnStmt(0);
    }
#line 3355 "build/parser.cpp"
    break;

  case 102: /* return_stmt: KW_RETURN expression SEMICOLON  */
#line 564 "src/parser.y"
                                   {
        (yyval.stmt) = new rpg::ReturnStmt(std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
    }
#line 3363 "build/parser.cpp"
    break;

  case 103: /* return_stmt: KW_RETURN SEMICOLON  */
#line 567 "src/parser.y"
                          {
        (yyval.stmt) = new rpg::ReturnStmt(0);
    }
#line 3371 "build/parser.cpp"
    break;

  case 104: /* expr_stmt: IDENTIFIER LPAREN call_args_opt RPAREN SEMICOLON  */
#line 574 "src/parser.y"
                                                     {
        auto* fc = make_func((yyvsp[-4].sval), (yyvsp[-2].expr_list));
        free((yyvsp[-4].sval));
        (yyval.stmt) = new rpg::ExprStmt(std::unique_ptr<rpg::Expression>(fc));
    }
#line 3381 "build/parser.cpp"
    break;

  case 105: /* dcl_pr_stmt: KW_DCL_PR IDENTIFIER pi_return_type SEMICOLON pr_params KW_END_PR SEMICOLON  */
#line 585 "src/parser.y"
                                                                                {
        rpg::ProcInterface iface;
        if ((yyvsp[-4].ival) >= 0) {
            iface.has_return = true;
            iface.return_type = static_cast<rpg::RPGType>((yyvsp[-4].ival));
            iface.return_length = 0;
            iface.return_digits = 0;
            iface.return_decimals = 0;
        } else {
            iface.has_return = false;
        }
        iface.params = std::move((yyvsp[-2].param_list)->params);
        delete (yyvsp[-2].param_list);
        (yyval.stmt) = new rpg::DclPR((yyvsp[-5].sval), std::move(iface));
        free((yyvsp[-5].sval));
    }
#line 3402 "build/parser.cpp"
    break;

  case 106: /* dcl_pr_stmt: KW_DCL_PR IDENTIFIER pi_return_type KW_EXTPROC LPAREN STRING_LITERAL RPAREN SEMICOLON pr_params KW_END_PR SEMICOLON  */
#line 602 "src/parser.y"
                                                                                                                          {
        rpg::ProcInterface iface;
        if ((yyvsp[-8].ival) >= 0) {
            iface.has_return = true;
            iface.return_type = static_cast<rpg::RPGType>((yyvsp[-8].ival));
            iface.return_length = 0;
            iface.return_digits = 0;
            iface.return_decimals = 0;
        } else {
            iface.has_return = false;
        }
        iface.params = std::move((yyvsp[-2].param_list)->params);
        delete (yyvsp[-2].param_list);
        auto* pr = new rpg::DclPR((yyvsp[-9].sval), std::move(iface));
        pr->extproc = (yyvsp[-5].sval);
        free((yyvsp[-9].sval));
        free((yyvsp[-5].sval));
        (yyval.stmt) = pr;
    }
#line 3426 "build/parser.cpp"
    break;

  case 107: /* dcl_pr_stmt: KW_DCL_PR IDENTIFIER KW_EXTPGM LPAREN STRING_LITERAL RPAREN SEMICOLON pr_params KW_END_PR SEMICOLON  */
#line 622 "src/parser.y"
                                                                                                          {
        rpg::ProcInterface iface;
        iface.has_return = false;
        iface.params = std::move((yyvsp[-2].param_list)->params);
        delete (yyvsp[-2].param_list);
        auto* pr = new rpg::DclPR((yyvsp[-8].sval), std::move(iface));
        pr->extpgm = (yyvsp[-5].sval);
        free((yyvsp[-8].sval));
        free((yyvsp[-5].sval));
        (yyval.stmt) = pr;
    }
#line 3442 "build/parser.cpp"
    break;

  case 108: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER proc_export SEMICOLON KW_DCL_PI pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 640 "src/parser.y"
                          {
        rpg::ProcInterface iface;
        if ((yyvsp[-7].ival) >= 0) {
            iface.has_return = true;
            iface.return_type = static_cast<rpg::RPGType>((yyvsp[-7].ival));
            iface.return_length = 0;
            iface.return_digits = 0;
            iface.return_decimals = 0;
        } else {
            iface.has_return = false;
        }
        iface.params = std::move((yyvsp[-5].param_list)->params);
        delete (yyvsp[-5].param_list);
        auto* proc = new rpg::DclProc((yyvsp[-11].sval), std::move(iface));
        proc->is_export = ((yyvsp[-10].ival) != 0);
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) proc->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        free((yyvsp[-11].sval));
        (yyval.stmt) = proc;
    }
#line 3467 "build/parser.cpp"
    break;

  case 109: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER proc_export SEMICOLON KW_DCL_PI IDENTIFIER pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 664 "src/parser.y"
                            {
        rpg::ProcInterface iface;
        if ((yyvsp[-7].ival) >= 0) {
            iface.has_return = true;
            iface.return_type = static_cast<rpg::RPGType>((yyvsp[-7].ival));
            iface.return_length = 0;
            iface.return_digits = 0;
            iface.return_decimals = 0;
        } else {
            iface.has_return = false;
        }
        iface.params = std::move((yyvsp[-5].param_list)->params);
        delete (yyvsp[-5].param_list);
        auto* proc = new rpg::DclProc((yyvsp[-12].sval), std::move(iface));
        proc->is_export = ((yyvsp[-11].ival) != 0);
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) proc->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        free((yyvsp[-12].sval));
        free((yyvsp[-8].sval));
        (yyval.stmt) = proc;
    }
#line 3493 "build/parser.cpp"
    break;

  case 110: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER proc_export SEMICOLON KW_DCL_PI pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_ON_EXIT SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 690 "src/parser.y"
                            {
        rpg::ProcInterface iface;
        if ((yyvsp[-10].ival) >= 0) {
            iface.has_return = true;
            iface.return_type = static_cast<rpg::RPGType>((yyvsp[-10].ival));
            iface.return_length = 0;
            iface.return_digits = 0;
            iface.return_decimals = 0;
        } else {
            iface.has_return = false;
        }
        iface.params = std::move((yyvsp[-8].param_list)->params);
        delete (yyvsp[-8].param_list);
        auto* proc = new rpg::DclProc((yyvsp[-14].sval), std::move(iface));
        proc->is_export = ((yyvsp[-13].ival) != 0);
        for (auto* s : (yyvsp[-5].stmt_list)->stmts) proc->body.emplace_back(s);
        delete (yyvsp[-5].stmt_list);
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) proc->on_exit_body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        free((yyvsp[-14].sval));
        (yyval.stmt) = proc;
    }
#line 3520 "build/parser.cpp"
    break;

  case 111: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER proc_export SEMICOLON KW_DCL_PI IDENTIFIER pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_ON_EXIT SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 717 "src/parser.y"
                            {
        rpg::ProcInterface iface;
        if ((yyvsp[-10].ival) >= 0) {
            iface.has_return = true;
            iface.return_type = static_cast<rpg::RPGType>((yyvsp[-10].ival));
            iface.return_length = 0;
            iface.return_digits = 0;
            iface.return_decimals = 0;
        } else {
            iface.has_return = false;
        }
        iface.params = std::move((yyvsp[-8].param_list)->params);
        delete (yyvsp[-8].param_list);
        auto* proc = new rpg::DclProc((yyvsp[-15].sval), std::move(iface));
        proc->is_export = ((yyvsp[-14].ival) != 0);
        for (auto* s : (yyvsp[-5].stmt_list)->stmts) proc->body.emplace_back(s);
        delete (yyvsp[-5].stmt_list);
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) proc->on_exit_body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        free((yyvsp[-15].sval));
        free((yyvsp[-11].sval));
        (yyval.stmt) = proc;
    }
#line 3548 "build/parser.cpp"
    break;

  case 112: /* proc_export: %empty  */
#line 743 "src/parser.y"
                { (yyval.ival) = 0; }
#line 3554 "build/parser.cpp"
    break;

  case 113: /* proc_export: KW_EXPORT  */
#line 744 "src/parser.y"
                { (yyval.ival) = 1; }
#line 3560 "build/parser.cpp"
    break;

  case 114: /* pi_return_type: %empty  */
#line 749 "src/parser.y"
               { (yyval.ival) = -1; }
#line 3566 "build/parser.cpp"
    break;

  case 115: /* pi_return_type: KW_INT LPAREN INTEGER_LITERAL RPAREN  */
#line 750 "src/parser.y"
                                           { (yyval.ival) = (int)rpg::RPGType::INT10; }
#line 3572 "build/parser.cpp"
    break;

  case 116: /* pi_return_type: KW_CHAR LPAREN INTEGER_LITERAL RPAREN  */
#line 751 "src/parser.y"
                                            { (yyval.ival) = (int)rpg::RPGType::CHAR; }
#line 3578 "build/parser.cpp"
    break;

  case 117: /* pi_return_type: KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN  */
#line 752 "src/parser.y"
                                               { (yyval.ival) = (int)rpg::RPGType::VARCHAR; }
#line 3584 "build/parser.cpp"
    break;

  case 118: /* pi_return_type: KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN  */
#line 753 "src/parser.y"
                                                                    { (yyval.ival) = (int)rpg::RPGType::PACKED; }
#line 3590 "build/parser.cpp"
    break;

  case 119: /* pi_params: %empty  */
#line 758 "src/parser.y"
                {
        (yyval.param_list) = new ParamList();
    }
#line 3598 "build/parser.cpp"
    break;

  case 120: /* pi_params: pi_params pi_param  */
#line 761 "src/parser.y"
                         {
        (yyval.param_list) = (yyvsp[-1].param_list);
        (yyval.param_list)->params.push_back(*(yyvsp[0].param_decl));
        delete (yyvsp[0].param_decl);
    }
#line 3608 "build/parser.cpp"
    break;

  case 121: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 769 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 3617 "build/parser.cpp"
    break;

  case 122: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 773 "src/parser.y"
                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 3626 "build/parser.cpp"
    break;

  case 123: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 777 "src/parser.y"
                                                                 {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 3635 "build/parser.cpp"
    break;

  case 124: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 781 "src/parser.y"
                                                                          {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 3644 "build/parser.cpp"
    break;

  case 125: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 785 "src/parser.y"
                                                                    {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 3653 "build/parser.cpp"
    break;

  case 126: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 789 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 3662 "build/parser.cpp"
    break;

  case 127: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 793 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 3671 "build/parser.cpp"
    break;

  case 128: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 797 "src/parser.y"
                                                                                                  {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 3680 "build/parser.cpp"
    break;

  case 129: /* pi_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 802 "src/parser.y"
                                                                            {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 3689 "build/parser.cpp"
    break;

  case 130: /* pi_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 806 "src/parser.y"
                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 3698 "build/parser.cpp"
    break;

  case 131: /* pi_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 810 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 3707 "build/parser.cpp"
    break;

  case 132: /* pi_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 814 "src/parser.y"
                                                                                      {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 3716 "build/parser.cpp"
    break;

  case 133: /* pi_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 818 "src/parser.y"
                                                                                {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 3725 "build/parser.cpp"
    break;

  case 134: /* pi_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 822 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 3734 "build/parser.cpp"
    break;

  case 135: /* pi_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 826 "src/parser.y"
                                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 3743 "build/parser.cpp"
    break;

  case 136: /* pi_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 830 "src/parser.y"
                                                                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 3752 "build/parser.cpp"
    break;

  case 137: /* pi_param: IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 834 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, 0, 0, 0, false, std::string((yyvsp[-2].sval))};
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
    }
#line 3762 "build/parser.cpp"
    break;

  case 138: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 840 "src/parser.y"
                                                                                                            {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 3772 "build/parser.cpp"
    break;

  case 139: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 845 "src/parser.y"
                                                                                                             {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 3782 "build/parser.cpp"
    break;

  case 140: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 850 "src/parser.y"
                                                                                                                {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::VARCHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 3792 "build/parser.cpp"
    break;

  case 141: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 855 "src/parser.y"
                                                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-12].sval), rpg::RPGType::PACKED, 0, (yyvsp[-9].ival), (yyvsp[-7].ival), true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-12].sval));
    }
#line 3802 "build/parser.cpp"
    break;

  case 142: /* pr_params: %empty  */
#line 864 "src/parser.y"
                {
        (yyval.param_list) = new ParamList();
    }
#line 3810 "build/parser.cpp"
    break;

  case 143: /* pr_params: pr_params pr_param  */
#line 867 "src/parser.y"
                         {
        (yyval.param_list) = (yyvsp[-1].param_list);
        (yyval.param_list)->params.push_back(*(yyvsp[0].param_decl));
        delete (yyvsp[0].param_decl);
    }
#line 3820 "build/parser.cpp"
    break;

  case 144: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 875 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 3829 "build/parser.cpp"
    break;

  case 145: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 879 "src/parser.y"
                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 3838 "build/parser.cpp"
    break;

  case 146: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 883 "src/parser.y"
                                                                 {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 3847 "build/parser.cpp"
    break;

  case 147: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 887 "src/parser.y"
                                                                          {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 3856 "build/parser.cpp"
    break;

  case 148: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 891 "src/parser.y"
                                                                    {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 3865 "build/parser.cpp"
    break;

  case 149: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 895 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 3874 "build/parser.cpp"
    break;

  case 150: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 899 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 3883 "build/parser.cpp"
    break;

  case 151: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 903 "src/parser.y"
                                                                                                  {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 3892 "build/parser.cpp"
    break;

  case 152: /* pr_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 908 "src/parser.y"
                                                                            {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 3901 "build/parser.cpp"
    break;

  case 153: /* pr_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 912 "src/parser.y"
                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 3910 "build/parser.cpp"
    break;

  case 154: /* pr_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 916 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 3919 "build/parser.cpp"
    break;

  case 155: /* pr_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 920 "src/parser.y"
                                                                                      {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 3928 "build/parser.cpp"
    break;

  case 156: /* pr_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 924 "src/parser.y"
                                                                                {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 3937 "build/parser.cpp"
    break;

  case 157: /* pr_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 928 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 3946 "build/parser.cpp"
    break;

  case 158: /* pr_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 932 "src/parser.y"
                                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 3955 "build/parser.cpp"
    break;

  case 159: /* pr_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 936 "src/parser.y"
                                                                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 3964 "build/parser.cpp"
    break;

  case 160: /* pr_param: IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 940 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, 0, 0, 0, false, std::string((yyvsp[-2].sval))};
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
    }
#line 3974 "build/parser.cpp"
    break;

  case 161: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 946 "src/parser.y"
                                                                                                            {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 3984 "build/parser.cpp"
    break;

  case 162: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 951 "src/parser.y"
                                                                                                             {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 3994 "build/parser.cpp"
    break;

  case 163: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 956 "src/parser.y"
                                                                                                                {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::VARCHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4004 "build/parser.cpp"
    break;

  case 164: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 961 "src/parser.y"
                                                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-12].sval), rpg::RPGType::PACKED, 0, (yyvsp[-9].ival), (yyvsp[-7].ival), true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-12].sval));
    }
#line 4014 "build/parser.cpp"
    break;

  case 165: /* monitor_stmt: KW_MONITOR SEMICOLON statement_list KW_ON_ERROR SEMICOLON statement_list KW_ENDMON SEMICOLON  */
#line 971 "src/parser.y"
                                                                                                 {
        auto* node = new rpg::MonitorStmt();
        for (auto* s : (yyvsp[-5].stmt_list)->stmts) node->try_body.emplace_back(s);
        delete (yyvsp[-5].stmt_list);
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->on_error_body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        (yyval.stmt) = node;
    }
#line 4027 "build/parser.cpp"
    break;

  case 166: /* begsr_stmt: KW_BEGSR IDENTIFIER SEMICOLON statement_list KW_ENDSR SEMICOLON  */
#line 982 "src/parser.y"
                                                                    {
        auto* node = new rpg::BegSR((yyvsp[-4].sval));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        free((yyvsp[-4].sval));
        (yyval.stmt) = node;
    }
#line 4039 "build/parser.cpp"
    break;

  case 167: /* exsr_stmt: KW_EXSR ident SEMICOLON  */
#line 992 "src/parser.y"
                            {
        (yyval.stmt) = new rpg::ExSR((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4048 "build/parser.cpp"
    break;

  case 168: /* sorta_stmt: KW_SORTA ident SEMICOLON  */
#line 1000 "src/parser.y"
                             {
        (yyval.stmt) = new rpg::SortAStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4057 "build/parser.cpp"
    break;

  case 169: /* reset_stmt: KW_RESET ident SEMICOLON  */
#line 1008 "src/parser.y"
                             {
        (yyval.stmt) = new rpg::ResetStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4066 "build/parser.cpp"
    break;

  case 170: /* clear_stmt: KW_CLEAR ident SEMICOLON  */
#line 1015 "src/parser.y"
                             {
        (yyval.stmt) = new rpg::ClearStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4075 "build/parser.cpp"
    break;

  case 171: /* dealloc_stmt: KW_DEALLOC ident SEMICOLON  */
#line 1023 "src/parser.y"
                               {
        (yyval.stmt) = new rpg::DeallocStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4084 "build/parser.cpp"
    break;

  case 172: /* test_stmt: KW_TEST LPAREN ident RPAREN ident SEMICOLON  */
#line 1031 "src/parser.y"
                                                {
        char type = toupper((yyvsp[-3].sval)[0]);
        (yyval.stmt) = new rpg::TestStmt(type, std::string((yyvsp[-1].sval)));
        free((yyvsp[-3].sval));
        free((yyvsp[-1].sval));
    }
#line 4095 "build/parser.cpp"
    break;

  case 173: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1043 "src/parser.y"
                                                                              {
        auto* ds = new rpg::DclDS((yyvsp[-5].sval));
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-5].sval));
        (yyval.stmt) = ds;
    }
#line 4108 "build/parser.cpp"
    break;

  case 174: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1052 "src/parser.y"
                                                                   {
        auto* ds = new rpg::DclDS((yyvsp[-4].sval));
        ds->qualified = false;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-4].sval));
        (yyval.stmt) = ds;
    }
#line 4121 "build/parser.cpp"
    break;

  case 175: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1061 "src/parser.y"
                                                                                                                     {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->dim = (yyvsp[-6].ival);
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-9].sval));
        (yyval.stmt) = ds;
    }
#line 4135 "build/parser.cpp"
    break;

  case 176: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1071 "src/parser.y"
                                                                                                                     {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->dim = (yyvsp[-5].ival);
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-9].sval));
        (yyval.stmt) = ds;
    }
#line 4149 "build/parser.cpp"
    break;

  case 177: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1081 "src/parser.y"
                                                                        {
        auto* ds = new rpg::DclDS((yyvsp[-5].sval));
        ds->like_ds = (yyvsp[-2].sval);
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
        (yyval.stmt) = ds;
    }
#line 4161 "build/parser.cpp"
    break;

  case 178: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1089 "src/parser.y"
                                                                                                             {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->like_ds = (yyvsp[-6].sval);
        ds->dim = (yyvsp[-2].ival);
        free((yyvsp[-9].sval));
        free((yyvsp[-6].sval));
        (yyval.stmt) = ds;
    }
#line 4174 "build/parser.cpp"
    break;

  case 179: /* ds_fields: %empty  */
#line 1100 "src/parser.y"
                {
        (yyval.ds_field_list) = new DSFieldList();
    }
#line 4182 "build/parser.cpp"
    break;

  case 180: /* ds_fields: ds_fields ds_field  */
#line 1103 "src/parser.y"
                         {
        (yyval.ds_field_list) = (yyvsp[-1].ds_field_list);
        (yyval.ds_field_list)->fields.push_back(*(yyvsp[0].ds_field));
        delete (yyvsp[0].ds_field);
    }
#line 4192 "build/parser.cpp"
    break;

  case 181: /* ds_field: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1111 "src/parser.y"
                                                              {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0};
        free((yyvsp[-5].sval));
    }
#line 4201 "build/parser.cpp"
    break;

  case 182: /* ds_field: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1115 "src/parser.y"
                                                                 {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 4210 "build/parser.cpp"
    break;

  case 183: /* ds_field: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1119 "src/parser.y"
                                                                    {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 4219 "build/parser.cpp"
    break;

  case 184: /* ds_field: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1123 "src/parser.y"
                                                                                         {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival)};
        free((yyvsp[-7].sval));
    }
#line 4228 "build/parser.cpp"
    break;

  case 185: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1128 "src/parser.y"
                                                                            {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0};
        free((yyvsp[-5].sval));
    }
#line 4237 "build/parser.cpp"
    break;

  case 186: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1132 "src/parser.y"
                                                                             {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 4246 "build/parser.cpp"
    break;

  case 187: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1136 "src/parser.y"
                                                                                {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 4255 "build/parser.cpp"
    break;

  case 188: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1140 "src/parser.y"
                                                                                                     {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival)};
        free((yyvsp[-7].sval));
    }
#line 4264 "build/parser.cpp"
    break;

  case 189: /* if_stmt: KW_IF expression SEMICOLON statement_list elseif_clauses else_clause KW_ENDIF SEMICOLON  */
#line 1149 "src/parser.y"
                                                                                            {
        auto* node = new rpg::IfStmt(std::unique_ptr<rpg::Expression>((yyvsp[-6].expr)));
        for (auto* s : (yyvsp[-4].stmt_list)->stmts) node->then_body.emplace_back(s);
        delete (yyvsp[-4].stmt_list);
        if ((yyvsp[-3].elseif_list)) {
            for (auto* eif : *(yyvsp[-3].elseif_list)) {
                rpg::ElseIfBranch branch;
                branch.condition.reset(eif->cond);
                for (auto* s : eif->body) branch.body.emplace_back(s);
                node->elseif_branches.push_back(std::move(branch));
                delete eif;
            }
            delete (yyvsp[-3].elseif_list);
        }
        if ((yyvsp[-2].stmt_list)) {
            for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->else_body.emplace_back(s);
            delete (yyvsp[-2].stmt_list);
        }
        (yyval.stmt) = node;
    }
#line 4289 "build/parser.cpp"
    break;

  case 190: /* elseif_clauses: %empty  */
#line 1172 "src/parser.y"
                { (yyval.elseif_list) = nullptr; }
#line 4295 "build/parser.cpp"
    break;

  case 191: /* elseif_clauses: elseif_clauses elseif_clause  */
#line 1173 "src/parser.y"
                                   {
        if (!(yyvsp[-1].elseif_list)) (yyvsp[-1].elseif_list) = new std::vector<ElseIfData*>();
        (yyval.elseif_list) = (yyvsp[-1].elseif_list);
        (yyval.elseif_list)->push_back((yyvsp[0].elseif_data));
    }
#line 4305 "build/parser.cpp"
    break;

  case 192: /* elseif_clause: KW_ELSEIF expression SEMICOLON statement_list  */
#line 1181 "src/parser.y"
                                                  {
        (yyval.elseif_data) = new ElseIfData();
        (yyval.elseif_data)->cond = (yyvsp[-2].expr);
        (yyval.elseif_data)->body = std::move((yyvsp[0].stmt_list)->stmts);
        delete (yyvsp[0].stmt_list);
    }
#line 4316 "build/parser.cpp"
    break;

  case 193: /* else_clause: %empty  */
#line 1190 "src/parser.y"
                { (yyval.stmt_list) = nullptr; }
#line 4322 "build/parser.cpp"
    break;

  case 194: /* else_clause: KW_ELSE SEMICOLON statement_list  */
#line 1191 "src/parser.y"
                                       {
        (yyval.stmt_list) = (yyvsp[0].stmt_list);
    }
#line 4330 "build/parser.cpp"
    break;

  case 195: /* dow_stmt: KW_DOW expression SEMICOLON statement_list KW_ENDDO SEMICOLON  */
#line 1197 "src/parser.y"
                                                                  {
        auto* node = new rpg::DowStmt(std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        (yyval.stmt) = node;
    }
#line 4341 "build/parser.cpp"
    break;

  case 196: /* dou_stmt: KW_DOU expression SEMICOLON statement_list KW_ENDDO SEMICOLON  */
#line 1206 "src/parser.y"
                                                                  {
        auto* node = new rpg::DouStmt(std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        (yyval.stmt) = node;
    }
#line 4352 "build/parser.cpp"
    break;

  case 197: /* for_stmt: KW_FOR ident EQUALS expression KW_TO expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1215 "src/parser.y"
                                                                                                 {
        auto* node = new rpg::ForStmt((yyvsp[-8].sval),
            std::unique_ptr<rpg::Expression>((yyvsp[-6].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)),
            nullptr, false);
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        free((yyvsp[-8].sval));
        (yyval.stmt) = node;
    }
#line 4367 "build/parser.cpp"
    break;

  case 198: /* for_stmt: KW_FOR ident EQUALS expression KW_TO expression KW_BY expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1225 "src/parser.y"
                                                                                                                    {
        auto* node = new rpg::ForStmt((yyvsp[-10].sval),
            std::unique_ptr<rpg::Expression>((yyvsp[-8].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-6].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)), false);
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        free((yyvsp[-10].sval));
        (yyval.stmt) = node;
    }
#line 4382 "build/parser.cpp"
    break;

  case 199: /* for_stmt: KW_FOR ident EQUALS expression KW_DOWNTO expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1235 "src/parser.y"
                                                                                                       {
        auto* node = new rpg::ForStmt((yyvsp[-8].sval),
            std::unique_ptr<rpg::Expression>((yyvsp[-6].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)),
            nullptr, true);
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        free((yyvsp[-8].sval));
        (yyval.stmt) = node;
    }
#line 4397 "build/parser.cpp"
    break;

  case 200: /* for_stmt: KW_FOR ident EQUALS expression KW_DOWNTO expression KW_BY expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1245 "src/parser.y"
                                                                                                                        {
        auto* node = new rpg::ForStmt((yyvsp[-10].sval),
            std::unique_ptr<rpg::Expression>((yyvsp[-8].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-6].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)), true);
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        free((yyvsp[-10].sval));
        (yyval.stmt) = node;
    }
#line 4412 "build/parser.cpp"
    break;

  case 201: /* for_each_stmt: KW_FOR_EACH ident KW_IN expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1258 "src/parser.y"
                                                                                    {
        auto* node = new rpg::ForEachStmt((yyvsp[-6].sval), std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        free((yyvsp[-6].sval));
        (yyval.stmt) = node;
    }
#line 4424 "build/parser.cpp"
    break;

  case 202: /* select_stmt: KW_SELECT SEMICOLON when_clauses other_clause KW_ENDSL SEMICOLON  */
#line 1268 "src/parser.y"
                                                                     {
        auto* node = new rpg::SelectStmt();
        for (auto* w : *(yyvsp[-3].when_list)) {
            rpg::WhenBranch branch;
            branch.condition.reset(w->cond);
            for (auto* s : w->body) branch.body.emplace_back(s);
            node->when_branches.push_back(std::move(branch));
            delete w;
        }
        delete (yyvsp[-3].when_list);
        if ((yyvsp[-2].stmt_list)) {
            for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->other_body.emplace_back(s);
            delete (yyvsp[-2].stmt_list);
        }
        (yyval.stmt) = node;
    }
#line 4445 "build/parser.cpp"
    break;

  case 203: /* when_clauses: when_clause  */
#line 1287 "src/parser.y"
                {
        (yyval.when_list) = new std::vector<WhenData*>();
        (yyval.when_list)->push_back((yyvsp[0].when_data));
    }
#line 4454 "build/parser.cpp"
    break;

  case 204: /* when_clauses: when_clauses when_clause  */
#line 1291 "src/parser.y"
                               {
        (yyval.when_list) = (yyvsp[-1].when_list);
        (yyval.when_list)->push_back((yyvsp[0].when_data));
    }
#line 4463 "build/parser.cpp"
    break;

  case 205: /* when_clause: KW_WHEN expression SEMICOLON statement_list  */
#line 1298 "src/parser.y"
                                                {
        (yyval.when_data) = new WhenData();
        (yyval.when_data)->cond = (yyvsp[-2].expr);
        (yyval.when_data)->body = std::move((yyvsp[0].stmt_list)->stmts);
        delete (yyvsp[0].stmt_list);
    }
#line 4474 "build/parser.cpp"
    break;

  case 206: /* other_clause: %empty  */
#line 1307 "src/parser.y"
                { (yyval.stmt_list) = nullptr; }
#line 4480 "build/parser.cpp"
    break;

  case 207: /* other_clause: KW_OTHER SEMICOLON statement_list  */
#line 1308 "src/parser.y"
                                        {
        (yyval.stmt_list) = (yyvsp[0].stmt_list);
    }
#line 4488 "build/parser.cpp"
    break;

  case 208: /* iter_stmt: KW_ITER SEMICOLON  */
#line 1314 "src/parser.y"
                      { (yyval.stmt) = new rpg::IterStmt(); }
#line 4494 "build/parser.cpp"
    break;

  case 209: /* leave_stmt: KW_LEAVE SEMICOLON  */
#line 1318 "src/parser.y"
                       { (yyval.stmt) = new rpg::LeaveStmt(); }
#line 4500 "build/parser.cpp"
    break;

  case 210: /* expression: or_expr  */
#line 1324 "src/parser.y"
            { (yyval.expr) = (yyvsp[0].expr); }
#line 4506 "build/parser.cpp"
    break;

  case 211: /* or_expr: and_expr  */
#line 1328 "src/parser.y"
             { (yyval.expr) = (yyvsp[0].expr); }
#line 4512 "build/parser.cpp"
    break;

  case 212: /* or_expr: or_expr KW_OR and_expr  */
#line 1329 "src/parser.y"
                             {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::OR,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 4522 "build/parser.cpp"
    break;

  case 213: /* and_expr: not_expr  */
#line 1337 "src/parser.y"
             { (yyval.expr) = (yyvsp[0].expr); }
#line 4528 "build/parser.cpp"
    break;

  case 214: /* and_expr: and_expr KW_AND not_expr  */
#line 1338 "src/parser.y"
                               {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::AND,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 4538 "build/parser.cpp"
    break;

  case 215: /* not_expr: comparison_expr  */
#line 1346 "src/parser.y"
                    { (yyval.expr) = (yyvsp[0].expr); }
#line 4544 "build/parser.cpp"
    break;

  case 216: /* not_expr: KW_NOT comparison_expr  */
#line 1347 "src/parser.y"
                             {
        (yyval.expr) = new rpg::NotExpr(std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 4552 "build/parser.cpp"
    break;

  case 217: /* comparison_expr: additive_expr  */
#line 1353 "src/parser.y"
                  { (yyval.expr) = (yyvsp[0].expr); }
#line 4558 "build/parser.cpp"
    break;

  case 218: /* comparison_expr: comparison_expr EQUALS additive_expr  */
#line 1354 "src/parser.y"
                                           {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::EQ,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 4568 "build/parser.cpp"
    break;

  case 219: /* comparison_expr: comparison_expr NE additive_expr  */
#line 1359 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::NE,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 4578 "build/parser.cpp"
    break;

  case 220: /* comparison_expr: comparison_expr LT additive_expr  */
#line 1364 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::LT,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 4588 "build/parser.cpp"
    break;

  case 221: /* comparison_expr: comparison_expr GT additive_expr  */
#line 1369 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::GT,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 4598 "build/parser.cpp"
    break;

  case 222: /* comparison_expr: comparison_expr LE additive_expr  */
#line 1374 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::LE,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 4608 "build/parser.cpp"
    break;

  case 223: /* comparison_expr: comparison_expr GE additive_expr  */
#line 1379 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::GE,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 4618 "build/parser.cpp"
    break;

  case 224: /* comparison_expr: additive_expr KW_IN additive_expr  */
#line 1384 "src/parser.y"
                                        {
        (yyval.expr) = new rpg::InExpr(
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 4628 "build/parser.cpp"
    break;

  case 225: /* additive_expr: multiplicative_expr  */
#line 1392 "src/parser.y"
                        { (yyval.expr) = (yyvsp[0].expr); }
#line 4634 "build/parser.cpp"
    break;

  case 226: /* additive_expr: additive_expr PLUS multiplicative_expr  */
#line 1393 "src/parser.y"
                                             {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::ADD,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 4644 "build/parser.cpp"
    break;

  case 227: /* additive_expr: additive_expr MINUS multiplicative_expr  */
#line 1398 "src/parser.y"
                                              {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::SUB,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 4654 "build/parser.cpp"
    break;

  case 228: /* multiplicative_expr: unary_expr  */
#line 1406 "src/parser.y"
               { (yyval.expr) = (yyvsp[0].expr); }
#line 4660 "build/parser.cpp"
    break;

  case 229: /* multiplicative_expr: multiplicative_expr STAR unary_expr  */
#line 1407 "src/parser.y"
                                          {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::MUL,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 4670 "build/parser.cpp"
    break;

  case 230: /* multiplicative_expr: multiplicative_expr SLASH unary_expr  */
#line 1412 "src/parser.y"
                                           {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::DIV,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 4680 "build/parser.cpp"
    break;

  case 231: /* unary_expr: postfix_expr  */
#line 1420 "src/parser.y"
                 { (yyval.expr) = (yyvsp[0].expr); }
#line 4686 "build/parser.cpp"
    break;

  case 232: /* unary_expr: MINUS postfix_expr  */
#line 1421 "src/parser.y"
                         {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::SUB,
            std::unique_ptr<rpg::Expression>(new rpg::IntLiteral(0)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 4696 "build/parser.cpp"
    break;

  case 233: /* postfix_expr: primary_expr  */
#line 1429 "src/parser.y"
                 { (yyval.expr) = (yyvsp[0].expr); }
#line 4702 "build/parser.cpp"
    break;

  case 234: /* postfix_expr: postfix_expr DOT IDENTIFIER  */
#line 1430 "src/parser.y"
                                  {
        (yyval.expr) = new rpg::DotExpr(std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)), (yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 4711 "build/parser.cpp"
    break;

  case 235: /* ident: IDENTIFIER  */
#line 1437 "src/parser.y"
               { (yyval.sval) = (yyvsp[0].sval); }
#line 4717 "build/parser.cpp"
    break;

  case 236: /* ident: KW_UNS  */
#line 1438 "src/parser.y"
             { (yyval.sval) = strdup("UNS"); }
#line 4723 "build/parser.cpp"
    break;

  case 237: /* ident: KW_FLOAT_TYPE  */
#line 1439 "src/parser.y"
                    { (yyval.sval) = strdup("FLOAT"); }
#line 4729 "build/parser.cpp"
    break;

  case 238: /* ident: KW_GRAPH  */
#line 1440 "src/parser.y"
               { (yyval.sval) = strdup("GRAPH"); }
#line 4735 "build/parser.cpp"
    break;

  case 239: /* ident: KW_OCCURS  */
#line 1441 "src/parser.y"
                { (yyval.sval) = strdup("OCCURS"); }
#line 4741 "build/parser.cpp"
    break;

  case 240: /* ident: KW_ASCEND  */
#line 1442 "src/parser.y"
                { (yyval.sval) = strdup("ASCEND"); }
#line 4747 "build/parser.cpp"
    break;

  case 241: /* ident: KW_DESCEND  */
#line 1443 "src/parser.y"
                 { (yyval.sval) = strdup("DESCEND"); }
#line 4753 "build/parser.cpp"
    break;

  case 242: /* ident: KW_IN  */
#line 1444 "src/parser.y"
            { (yyval.sval) = strdup("IN"); }
#line 4759 "build/parser.cpp"
    break;

  case 243: /* ident: KW_RTNPARM  */
#line 1445 "src/parser.y"
                 { (yyval.sval) = strdup("RTNPARM"); }
#line 4765 "build/parser.cpp"
    break;

  case 244: /* ident: KW_OPDESC  */
#line 1446 "src/parser.y"
                { (yyval.sval) = strdup("OPDESC"); }
#line 4771 "build/parser.cpp"
    break;

  case 245: /* ident: KW_NULLIND  */
#line 1447 "src/parser.y"
                 { (yyval.sval) = strdup("NULLIND"); }
#line 4777 "build/parser.cpp"
    break;

  case 246: /* ident: KW_DATFMT  */
#line 1448 "src/parser.y"
                { (yyval.sval) = strdup("DATFMT"); }
#line 4783 "build/parser.cpp"
    break;

  case 247: /* ident: KW_TIMFMT  */
#line 1449 "src/parser.y"
                { (yyval.sval) = strdup("TIMFMT"); }
#line 4789 "build/parser.cpp"
    break;

  case 248: /* ident: KW_EXTNAME  */
#line 1450 "src/parser.y"
                 { (yyval.sval) = strdup("EXTNAME"); }
#line 4795 "build/parser.cpp"
    break;

  case 249: /* primary_expr: IDENTIFIER  */
#line 1454 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier((yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 4804 "build/parser.cpp"
    break;

  case 250: /* primary_expr: KW_UNS  */
#line 1458 "src/parser.y"
             { (yyval.expr) = new rpg::Identifier("UNS"); }
#line 4810 "build/parser.cpp"
    break;

  case 251: /* primary_expr: KW_FLOAT_TYPE  */
#line 1459 "src/parser.y"
                    { (yyval.expr) = new rpg::Identifier("FLOAT"); }
#line 4816 "build/parser.cpp"
    break;

  case 252: /* primary_expr: KW_GRAPH  */
#line 1460 "src/parser.y"
               { (yyval.expr) = new rpg::Identifier("GRAPH"); }
#line 4822 "build/parser.cpp"
    break;

  case 253: /* primary_expr: KW_OCCURS  */
#line 1461 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("OCCURS"); }
#line 4828 "build/parser.cpp"
    break;

  case 254: /* primary_expr: KW_ASCEND  */
#line 1462 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("ASCEND"); }
#line 4834 "build/parser.cpp"
    break;

  case 255: /* primary_expr: KW_DESCEND  */
#line 1463 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("DESCEND"); }
#line 4840 "build/parser.cpp"
    break;

  case 256: /* primary_expr: KW_RTNPARM  */
#line 1464 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("RTNPARM"); }
#line 4846 "build/parser.cpp"
    break;

  case 257: /* primary_expr: KW_OPDESC  */
#line 1465 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("OPDESC"); }
#line 4852 "build/parser.cpp"
    break;

  case 258: /* primary_expr: KW_NULLIND  */
#line 1466 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("NULLIND"); }
#line 4858 "build/parser.cpp"
    break;

  case 259: /* primary_expr: KW_DATFMT  */
#line 1467 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("DATFMT"); }
#line 4864 "build/parser.cpp"
    break;

  case 260: /* primary_expr: KW_TIMFMT  */
#line 1468 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("TIMFMT"); }
#line 4870 "build/parser.cpp"
    break;

  case 261: /* primary_expr: KW_EXTNAME  */
#line 1469 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("EXTNAME"); }
#line 4876 "build/parser.cpp"
    break;

  case 262: /* primary_expr: INTEGER_LITERAL  */
#line 1470 "src/parser.y"
                      {
        (yyval.expr) = new rpg::IntLiteral((yyvsp[0].ival));
    }
#line 4884 "build/parser.cpp"
    break;

  case 263: /* primary_expr: FLOAT_LITERAL  */
#line 1473 "src/parser.y"
                    {
        (yyval.expr) = new rpg::FloatLiteral((yyvsp[0].fval));
    }
#line 4892 "build/parser.cpp"
    break;

  case 264: /* primary_expr: STRING_LITERAL  */
#line 1476 "src/parser.y"
                     {
        (yyval.expr) = new rpg::StringLiteral((yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 4901 "build/parser.cpp"
    break;

  case 265: /* primary_expr: IDENTIFIER LPAREN call_args_opt RPAREN  */
#line 1480 "src/parser.y"
                                             {
        (yyval.expr) = make_func((yyvsp[-3].sval), (yyvsp[-1].expr_list));
        free((yyvsp[-3].sval));
    }
#line 4910 "build/parser.cpp"
    break;

  case 266: /* primary_expr: BIF_CHAR LPAREN arg_list RPAREN  */
#line 1484 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("CHAR", (yyvsp[-1].expr_list));
    }
#line 4918 "build/parser.cpp"
    break;

  case 267: /* primary_expr: BIF_TRIM LPAREN arg_list RPAREN  */
#line 1487 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("TRIM", (yyvsp[-1].expr_list));
    }
#line 4926 "build/parser.cpp"
    break;

  case 268: /* primary_expr: BIF_TRIML LPAREN arg_list RPAREN  */
#line 1490 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("TRIML", (yyvsp[-1].expr_list));
    }
#line 4934 "build/parser.cpp"
    break;

  case 269: /* primary_expr: BIF_TRIMR LPAREN arg_list RPAREN  */
#line 1493 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("TRIMR", (yyvsp[-1].expr_list));
    }
#line 4942 "build/parser.cpp"
    break;

  case 270: /* primary_expr: BIF_LEN LPAREN arg_list RPAREN  */
#line 1496 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("LEN", (yyvsp[-1].expr_list));
    }
#line 4950 "build/parser.cpp"
    break;

  case 271: /* primary_expr: BIF_SUBST LPAREN arg_list RPAREN  */
#line 1499 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("SUBST", (yyvsp[-1].expr_list));
    }
#line 4958 "build/parser.cpp"
    break;

  case 272: /* primary_expr: BIF_SCAN LPAREN arg_list RPAREN  */
#line 1502 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("SCAN", (yyvsp[-1].expr_list));
    }
#line 4966 "build/parser.cpp"
    break;

  case 273: /* primary_expr: BIF_SCANRPL LPAREN arg_list RPAREN  */
#line 1505 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("SCANRPL", (yyvsp[-1].expr_list));
    }
#line 4974 "build/parser.cpp"
    break;

  case 274: /* primary_expr: BIF_XLATE LPAREN arg_list RPAREN  */
#line 1508 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("XLATE", (yyvsp[-1].expr_list));
    }
#line 4982 "build/parser.cpp"
    break;

  case 275: /* primary_expr: BIF_DEC LPAREN arg_list RPAREN  */
#line 1511 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("DEC", (yyvsp[-1].expr_list));
    }
#line 4990 "build/parser.cpp"
    break;

  case 276: /* primary_expr: BIF_INT LPAREN arg_list RPAREN  */
#line 1514 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("INT", (yyvsp[-1].expr_list));
    }
#line 4998 "build/parser.cpp"
    break;

  case 277: /* primary_expr: BIF_ELEM LPAREN arg_list RPAREN  */
#line 1517 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("ELEM", (yyvsp[-1].expr_list));
    }
#line 5006 "build/parser.cpp"
    break;

  case 278: /* primary_expr: BIF_PARMS LPAREN RPAREN  */
#line 1520 "src/parser.y"
                              {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("PARMS", empty);
    }
#line 5015 "build/parser.cpp"
    break;

  case 279: /* primary_expr: BIF_LOOKUP LPAREN arg_list RPAREN  */
#line 1524 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("LOOKUP", (yyvsp[-1].expr_list));
    }
#line 5023 "build/parser.cpp"
    break;

  case 280: /* primary_expr: BIF_EDITC LPAREN arg_list RPAREN  */
#line 1527 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("EDITC", (yyvsp[-1].expr_list));
    }
#line 5031 "build/parser.cpp"
    break;

  case 281: /* primary_expr: BIF_EDITW LPAREN arg_list RPAREN  */
#line 1530 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("EDITW", (yyvsp[-1].expr_list));
    }
#line 5039 "build/parser.cpp"
    break;

  case 282: /* primary_expr: BIF_REPLACE LPAREN arg_list RPAREN  */
#line 1533 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("REPLACE", (yyvsp[-1].expr_list));
    }
#line 5047 "build/parser.cpp"
    break;

  case 283: /* primary_expr: BIF_CHECK LPAREN arg_list RPAREN  */
#line 1536 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("CHECK", (yyvsp[-1].expr_list));
    }
#line 5055 "build/parser.cpp"
    break;

  case 284: /* primary_expr: BIF_CHECKR LPAREN arg_list RPAREN  */
#line 1539 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("CHECKR", (yyvsp[-1].expr_list));
    }
#line 5063 "build/parser.cpp"
    break;

  case 285: /* primary_expr: BIF_LOWER LPAREN arg_list RPAREN  */
#line 1542 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("LOWER", (yyvsp[-1].expr_list));
    }
#line 5071 "build/parser.cpp"
    break;

  case 286: /* primary_expr: BIF_UPPER LPAREN arg_list RPAREN  */
#line 1545 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("UPPER", (yyvsp[-1].expr_list));
    }
#line 5079 "build/parser.cpp"
    break;

  case 287: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_YEARS RPAREN  */
#line 1548 "src/parser.y"
                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("YEARS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 5090 "build/parser.cpp"
    break;

  case 288: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_MONTHS RPAREN  */
#line 1554 "src/parser.y"
                                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MONTHS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 5101 "build/parser.cpp"
    break;

  case 289: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_DAYS RPAREN  */
#line 1560 "src/parser.y"
                                                       {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("DAYS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 5112 "build/parser.cpp"
    break;

  case 290: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_HOURS RPAREN  */
#line 1566 "src/parser.y"
                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("HOURS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 5123 "build/parser.cpp"
    break;

  case 291: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_MINUTES RPAREN  */
#line 1572 "src/parser.y"
                                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MINUTES"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 5134 "build/parser.cpp"
    break;

  case 292: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_SECONDS RPAREN  */
#line 1578 "src/parser.y"
                                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("SECONDS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 5145 "build/parser.cpp"
    break;

  case 293: /* primary_expr: BIF_FLOAT LPAREN arg_list RPAREN  */
#line 1584 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("FLOAT", (yyvsp[-1].expr_list));
    }
#line 5153 "build/parser.cpp"
    break;

  case 294: /* primary_expr: BIF_SQRT LPAREN arg_list RPAREN  */
#line 1587 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("SQRT", (yyvsp[-1].expr_list));
    }
#line 5161 "build/parser.cpp"
    break;

  case 295: /* primary_expr: BIF_MAX LPAREN arg_list RPAREN  */
#line 1590 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("MAX", (yyvsp[-1].expr_list));
    }
#line 5169 "build/parser.cpp"
    break;

  case 296: /* primary_expr: BIF_MIN LPAREN arg_list RPAREN  */
#line 1593 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("MIN", (yyvsp[-1].expr_list));
    }
#line 5177 "build/parser.cpp"
    break;

  case 297: /* primary_expr: BIF_STATUS LPAREN RPAREN  */
#line 1596 "src/parser.y"
                               {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("STATUS", empty);
    }
#line 5186 "build/parser.cpp"
    break;

  case 298: /* primary_expr: BIF_ERROR LPAREN RPAREN  */
#line 1600 "src/parser.y"
                              {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("ERROR", empty);
    }
#line 5195 "build/parser.cpp"
    break;

  case 299: /* primary_expr: BIF_SIZE LPAREN arg_list RPAREN  */
#line 1604 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("SIZE", (yyvsp[-1].expr_list));
    }
#line 5203 "build/parser.cpp"
    break;

  case 300: /* primary_expr: BIF_ADDR LPAREN arg_list RPAREN  */
#line 1607 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("ADDR", (yyvsp[-1].expr_list));
    }
#line 5211 "build/parser.cpp"
    break;

  case 301: /* primary_expr: BIF_ABS LPAREN arg_list RPAREN  */
#line 1610 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("ABS", (yyvsp[-1].expr_list));
    }
#line 5219 "build/parser.cpp"
    break;

  case 302: /* primary_expr: BIF_DIV LPAREN arg_list RPAREN  */
#line 1613 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("DIV", (yyvsp[-1].expr_list));
    }
#line 5227 "build/parser.cpp"
    break;

  case 303: /* primary_expr: BIF_REM LPAREN arg_list RPAREN  */
#line 1616 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("REM", (yyvsp[-1].expr_list));
    }
#line 5235 "build/parser.cpp"
    break;

  case 304: /* primary_expr: BIF_DATE LPAREN arg_list RPAREN  */
#line 1619 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("DATE", (yyvsp[-1].expr_list));
    }
#line 5243 "build/parser.cpp"
    break;

  case 305: /* primary_expr: BIF_DATE LPAREN RPAREN  */
#line 1622 "src/parser.y"
                             {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("DATE", empty);
    }
#line 5252 "build/parser.cpp"
    break;

  case 306: /* primary_expr: BIF_TIME LPAREN arg_list RPAREN  */
#line 1626 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("TIME", (yyvsp[-1].expr_list));
    }
#line 5260 "build/parser.cpp"
    break;

  case 307: /* primary_expr: BIF_TIME LPAREN RPAREN  */
#line 1629 "src/parser.y"
                             {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("TIME", empty);
    }
#line 5269 "build/parser.cpp"
    break;

  case 308: /* primary_expr: BIF_TIMESTAMP LPAREN arg_list RPAREN  */
#line 1633 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TIMESTAMP", (yyvsp[-1].expr_list));
    }
#line 5277 "build/parser.cpp"
    break;

  case 309: /* primary_expr: BIF_TIMESTAMP LPAREN RPAREN  */
#line 1636 "src/parser.y"
                                  {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("TIMESTAMP", empty);
    }
#line 5286 "build/parser.cpp"
    break;

  case 310: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_DAYS RPAREN  */
#line 1640 "src/parser.y"
                                                                       {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("DAYS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 5298 "build/parser.cpp"
    break;

  case 311: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_MONTHS RPAREN  */
#line 1647 "src/parser.y"
                                                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MONTHS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 5310 "build/parser.cpp"
    break;

  case 312: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_YEARS RPAREN  */
#line 1654 "src/parser.y"
                                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("YEARS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 5322 "build/parser.cpp"
    break;

  case 313: /* primary_expr: BIF_DAYS LPAREN expression RPAREN  */
#line 1661 "src/parser.y"
                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("DAYS", args);
    }
#line 5332 "build/parser.cpp"
    break;

  case 314: /* primary_expr: BIF_MONTHS LPAREN expression RPAREN  */
#line 1666 "src/parser.y"
                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("MONTHS", args);
    }
#line 5342 "build/parser.cpp"
    break;

  case 315: /* primary_expr: BIF_YEARS LPAREN expression RPAREN  */
#line 1671 "src/parser.y"
                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("YEARS", args);
    }
#line 5352 "build/parser.cpp"
    break;

  case 316: /* primary_expr: BIF_FOUND LPAREN RPAREN  */
#line 1676 "src/parser.y"
                              {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("FOUND", empty);
    }
#line 5361 "build/parser.cpp"
    break;

  case 317: /* primary_expr: BIF_EOF LPAREN RPAREN  */
#line 1680 "src/parser.y"
                            {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("EOF", empty);
    }
#line 5370 "build/parser.cpp"
    break;

  case 318: /* primary_expr: BIF_ALLOC LPAREN arg_list RPAREN  */
#line 1684 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("ALLOC", (yyvsp[-1].expr_list));
    }
#line 5378 "build/parser.cpp"
    break;

  case 319: /* primary_expr: BIF_REALLOC LPAREN arg_list RPAREN  */
#line 1687 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("REALLOC", (yyvsp[-1].expr_list));
    }
#line 5386 "build/parser.cpp"
    break;

  case 320: /* primary_expr: BIF_XFOOT LPAREN arg_list RPAREN  */
#line 1690 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("XFOOT", (yyvsp[-1].expr_list));
    }
#line 5394 "build/parser.cpp"
    break;

  case 321: /* primary_expr: BIF_UNS LPAREN arg_list RPAREN  */
#line 1693 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("UNS", (yyvsp[-1].expr_list));
    }
#line 5402 "build/parser.cpp"
    break;

  case 322: /* primary_expr: BIF_INTH LPAREN arg_list RPAREN  */
#line 1696 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("INTH", (yyvsp[-1].expr_list));
    }
#line 5410 "build/parser.cpp"
    break;

  case 323: /* primary_expr: BIF_DECH LPAREN arg_list RPAREN  */
#line 1699 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("DECH", (yyvsp[-1].expr_list));
    }
#line 5418 "build/parser.cpp"
    break;

  case 324: /* primary_expr: BIF_DECPOS LPAREN arg_list RPAREN  */
#line 1702 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("DECPOS", (yyvsp[-1].expr_list));
    }
#line 5426 "build/parser.cpp"
    break;

  case 325: /* primary_expr: BIF_SPLIT LPAREN arg_list RPAREN  */
#line 1705 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("SPLIT", (yyvsp[-1].expr_list));
    }
#line 5434 "build/parser.cpp"
    break;

  case 326: /* primary_expr: BIF_CONCATARR LPAREN arg_list RPAREN  */
#line 1708 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("CONCATARR", (yyvsp[-1].expr_list));
    }
#line 5442 "build/parser.cpp"
    break;

  case 327: /* primary_expr: BIF_LEFT LPAREN arg_list RPAREN  */
#line 1711 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("LEFT", (yyvsp[-1].expr_list));
    }
#line 5450 "build/parser.cpp"
    break;

  case 328: /* primary_expr: BIF_RIGHT LPAREN arg_list RPAREN  */
#line 1714 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("RIGHT", (yyvsp[-1].expr_list));
    }
#line 5458 "build/parser.cpp"
    break;

  case 329: /* primary_expr: BIF_STR LPAREN arg_list RPAREN  */
#line 1717 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("STR", (yyvsp[-1].expr_list));
    }
#line 5466 "build/parser.cpp"
    break;

  case 330: /* primary_expr: BIF_SUBARR LPAREN arg_list RPAREN  */
#line 1720 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("SUBARR", (yyvsp[-1].expr_list));
    }
#line 5474 "build/parser.cpp"
    break;

  case 331: /* primary_expr: BIF_MAXARR LPAREN arg_list RPAREN  */
#line 1723 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("MAXARR", (yyvsp[-1].expr_list));
    }
#line 5482 "build/parser.cpp"
    break;

  case 332: /* primary_expr: BIF_MINARR LPAREN arg_list RPAREN  */
#line 1726 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("MINARR", (yyvsp[-1].expr_list));
    }
#line 5490 "build/parser.cpp"
    break;

  case 333: /* primary_expr: BIF_LIST LPAREN arg_list RPAREN  */
#line 1729 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("LIST", (yyvsp[-1].expr_list));
    }
#line 5498 "build/parser.cpp"
    break;

  case 334: /* primary_expr: BIF_RANGE LPAREN arg_list RPAREN  */
#line 1732 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("RANGE", (yyvsp[-1].expr_list));
    }
#line 5506 "build/parser.cpp"
    break;

  case 335: /* primary_expr: BIF_LOOKUPLT LPAREN arg_list RPAREN  */
#line 1735 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPLT", (yyvsp[-1].expr_list));
    }
#line 5514 "build/parser.cpp"
    break;

  case 336: /* primary_expr: BIF_LOOKUPGE LPAREN arg_list RPAREN  */
#line 1738 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPGE", (yyvsp[-1].expr_list));
    }
#line 5522 "build/parser.cpp"
    break;

  case 337: /* primary_expr: BIF_LOOKUPLE LPAREN arg_list RPAREN  */
#line 1741 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPLE", (yyvsp[-1].expr_list));
    }
#line 5530 "build/parser.cpp"
    break;

  case 338: /* primary_expr: BIF_LOOKUPGT LPAREN arg_list RPAREN  */
#line 1744 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPGT", (yyvsp[-1].expr_list));
    }
#line 5538 "build/parser.cpp"
    break;

  case 339: /* primary_expr: BIF_HOURS LPAREN expression RPAREN  */
#line 1747 "src/parser.y"
                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("HOURS", args);
    }
#line 5548 "build/parser.cpp"
    break;

  case 340: /* primary_expr: BIF_MINUTES LPAREN expression RPAREN  */
#line 1752 "src/parser.y"
                                           {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("MINUTES", args);
    }
#line 5558 "build/parser.cpp"
    break;

  case 341: /* primary_expr: BIF_SECONDS LPAREN expression RPAREN  */
#line 1757 "src/parser.y"
                                           {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("SECONDS", args);
    }
#line 5568 "build/parser.cpp"
    break;

  case 342: /* primary_expr: BIF_MSECONDS LPAREN expression RPAREN  */
#line 1762 "src/parser.y"
                                            {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("MSECONDS", args);
    }
#line 5578 "build/parser.cpp"
    break;

  case 343: /* primary_expr: BIF_PADDR LPAREN IDENTIFIER RPAREN  */
#line 1767 "src/parser.y"
                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::StringLiteral((yyvsp[-1].sval)));
        free((yyvsp[-1].sval));
        (yyval.expr) = make_bif("PADDR", args);
    }
#line 5589 "build/parser.cpp"
    break;

  case 344: /* primary_expr: BIF_PROC LPAREN RPAREN  */
#line 1773 "src/parser.y"
                             {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("PROC", empty);
    }
#line 5598 "build/parser.cpp"
    break;

  case 345: /* primary_expr: BIF_PROC  */
#line 1777 "src/parser.y"
               {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("PROC", empty);
    }
#line 5607 "build/parser.cpp"
    break;

  case 346: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_HOURS RPAREN  */
#line 1781 "src/parser.y"
                                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("HOURS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 5619 "build/parser.cpp"
    break;

  case 347: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_MINUTES RPAREN  */
#line 1788 "src/parser.y"
                                                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MINUTES"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 5631 "build/parser.cpp"
    break;

  case 348: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_SECONDS RPAREN  */
#line 1795 "src/parser.y"
                                                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("SECONDS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 5643 "build/parser.cpp"
    break;

  case 349: /* primary_expr: KW_ALL STRING_LITERAL  */
#line 1802 "src/parser.y"
                            {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::StringLiteral((yyvsp[0].sval)));
        free((yyvsp[0].sval));
        (yyval.expr) = make_bif("ALL", args);
    }
#line 5654 "build/parser.cpp"
    break;

  case 350: /* primary_expr: BIF_PASSED LPAREN ident RPAREN  */
#line 1808 "src/parser.y"
                                     {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::Identifier((yyvsp[-1].sval)));
        free((yyvsp[-1].sval));
        (yyval.expr) = make_bif("PASSED", args);
    }
#line 5665 "build/parser.cpp"
    break;

  case 351: /* primary_expr: BIF_OMITTED LPAREN ident RPAREN  */
#line 1814 "src/parser.y"
                                      {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::Identifier((yyvsp[-1].sval)));
        free((yyvsp[-1].sval));
        (yyval.expr) = make_bif("OMITTED", args);
    }
#line 5676 "build/parser.cpp"
    break;

  case 352: /* primary_expr: BIF_OCCUR LPAREN arg_list RPAREN  */
#line 1820 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("OCCUR", (yyvsp[-1].expr_list));
    }
#line 5684 "build/parser.cpp"
    break;

  case 353: /* primary_expr: INDICATOR  */
#line 1823 "src/parser.y"
                {
        (yyval.expr) = new rpg::IndicatorExpr((yyvsp[0].ival));
    }
#line 5692 "build/parser.cpp"
    break;

  case 354: /* primary_expr: KW_ON  */
#line 1826 "src/parser.y"
            {
        (yyval.expr) = new rpg::IntLiteral(1);  // *ON → true
    }
#line 5700 "build/parser.cpp"
    break;

  case 355: /* primary_expr: KW_OFF  */
#line 1829 "src/parser.y"
             {
        (yyval.expr) = new rpg::IntLiteral(0);  // *OFF → false
    }
#line 5708 "build/parser.cpp"
    break;

  case 356: /* primary_expr: KW_NULL  */
#line 1832 "src/parser.y"
              {
        (yyval.expr) = new rpg::Identifier("nullptr");
    }
#line 5716 "build/parser.cpp"
    break;

  case 357: /* primary_expr: KW_BLANKS  */
#line 1835 "src/parser.y"
                {
        (yyval.expr) = new rpg::Identifier("RPG_BLANKS");
    }
#line 5724 "build/parser.cpp"
    break;

  case 358: /* primary_expr: KW_ZEROS  */
#line 1838 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier("RPG_ZEROS");
    }
#line 5732 "build/parser.cpp"
    break;

  case 359: /* primary_expr: KW_HIVAL  */
#line 1841 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier("RPG_HIVAL");
    }
#line 5740 "build/parser.cpp"
    break;

  case 360: /* primary_expr: KW_LOVAL  */
#line 1844 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier("RPG_LOVAL");
    }
#line 5748 "build/parser.cpp"
    break;

  case 361: /* primary_expr: LPAREN expression RPAREN  */
#line 1847 "src/parser.y"
                               {
        (yyval.expr) = (yyvsp[-1].expr);
    }
#line 5756 "build/parser.cpp"
    break;

  case 362: /* call_args_opt: %empty  */
#line 1854 "src/parser.y"
                { (yyval.expr_list) = nullptr; }
#line 5762 "build/parser.cpp"
    break;

  case 363: /* call_args_opt: call_arg_list  */
#line 1855 "src/parser.y"
                    { (yyval.expr_list) = (yyvsp[0].expr_list); }
#line 5768 "build/parser.cpp"
    break;

  case 364: /* call_arg_list: expression  */
#line 1859 "src/parser.y"
               {
        (yyval.expr_list) = new std::vector<rpg::Expression*>();
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 5777 "build/parser.cpp"
    break;

  case 365: /* call_arg_list: call_arg_list COLON expression  */
#line 1863 "src/parser.y"
                                     {
        (yyval.expr_list) = (yyvsp[-2].expr_list);
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 5786 "build/parser.cpp"
    break;

  case 366: /* arg_list: expression  */
#line 1871 "src/parser.y"
               {
        (yyval.expr_list) = new std::vector<rpg::Expression*>();
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 5795 "build/parser.cpp"
    break;

  case 367: /* arg_list: arg_list COLON expression  */
#line 1875 "src/parser.y"
                                {
        (yyval.expr_list) = (yyvsp[-2].expr_list);
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 5804 "build/parser.cpp"
    break;


#line 5808 "build/parser.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 1881 "src/parser.y"


void yyerror(const char* s) {
    g_error_count++;
    const char* token = yytext;
    if (token == NULL || token[0] == '\0') {
        fprintf(stderr, "Error at line %d: %s (unexpected end of file)\n", yylineno, s);
    } else {
        fprintf(stderr, "Error at line %d: %s (near '%s')\n", yylineno, s, token);
    }
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
