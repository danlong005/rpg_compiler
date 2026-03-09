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
#define YYLAST   4493

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  221
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  66
/* YYNRULES -- Number of rules.  */
#define YYNRULES  414
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1318

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
     486,   487,   488,   489,   490,   491,   492,   493,   494,   495,
     496,   497,   498,   499,   500,   501,   504,   510,   514,   523,
     529,   538,   546,   555,   561,   567,   573,   579,   582,   589,
     600,   617,   637,   652,   676,   701,   728,   758,   759,   764,
     765,   766,   767,   768,   773,   776,   784,   788,   792,   796,
     800,   804,   808,   812,   817,   821,   825,   829,   833,   837,
     841,   845,   849,   855,   860,   865,   870,   876,   881,   886,
     891,   897,   902,   907,   916,   919,   927,   931,   935,   939,
     943,   947,   951,   955,   960,   964,   968,   972,   976,   980,
     984,   988,   992,   998,  1003,  1008,  1013,  1019,  1024,  1029,
    1034,  1040,  1045,  1050,  1060,  1071,  1081,  1089,  1097,  1104,
    1112,  1120,  1132,  1141,  1150,  1160,  1170,  1178,  1187,  1197,
    1208,  1219,  1231,  1234,  1242,  1246,  1250,  1254,  1259,  1263,
    1267,  1271,  1276,  1282,  1288,  1295,  1302,  1309,  1315,  1327,
    1350,  1351,  1359,  1368,  1369,  1375,  1384,  1393,  1403,  1413,
    1423,  1436,  1446,  1465,  1469,  1476,  1485,  1486,  1492,  1496,
    1502,  1506,  1507,  1515,  1516,  1524,  1525,  1531,  1532,  1537,
    1542,  1547,  1552,  1557,  1562,  1570,  1571,  1576,  1584,  1585,
    1590,  1598,  1599,  1607,  1608,  1615,  1616,  1617,  1618,  1619,
    1620,  1621,  1622,  1623,  1624,  1625,  1626,  1627,  1628,  1629,
    1630,  1631,  1635,  1639,  1640,  1641,  1642,  1643,  1644,  1645,
    1646,  1647,  1648,  1649,  1650,  1651,  1652,  1653,  1654,  1657,
    1660,  1664,  1668,  1671,  1674,  1677,  1680,  1683,  1686,  1689,
    1692,  1695,  1698,  1701,  1704,  1708,  1711,  1714,  1717,  1720,
    1723,  1726,  1729,  1732,  1738,  1744,  1750,  1756,  1762,  1768,
    1771,  1774,  1777,  1780,  1784,  1788,  1791,  1794,  1797,  1800,
    1803,  1806,  1810,  1813,  1817,  1820,  1824,  1831,  1838,  1845,
    1850,  1855,  1860,  1864,  1868,  1871,  1874,  1877,  1880,  1883,
    1886,  1889,  1892,  1895,  1898,  1901,  1904,  1907,  1910,  1913,
    1916,  1919,  1922,  1925,  1928,  1931,  1936,  1941,  1946,  1951,
    1957,  1961,  1965,  1972,  1979,  1986,  1992,  1998,  2004,  2007,
    2010,  2013,  2016,  2019,  2022,  2025,  2028,  2031,  2034,  2041,
    2042,  2046,  2050,  2058,  2062
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

#define YYPACT_NINF (-718)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-248)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      56,  -718,   103,    16,   423,  -718,  -111,   -87,   383,   -74,
    3958,    61,   383,    61,  3958,   -64,   383,   -48,  -718,  3306,
     -31,  3958,  3958,  3958,   383,   -27,   -23,   -20,   -16,    13,
     383,   383,   383,   383,  -718,    24,    28,    35,  -718,  -718,
    -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,
    -718,  -718,  -718,   383,   -12,  -718,  -718,  -718,  -718,    14,
    -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,
    -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,
    -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,   390,
    -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,
    -718,  -718,  -718,  -718,  -718,  -718,  -718,   119,  3958,  -718,
    -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  4121,    11,
      70,    74,    77,    82,    97,   125,   129,   135,   150,   152,
     156,   159,   162,   164,   173,   182,   186,   209,   213,   238,
     244,   263,   271,   273,   275,   278,   287,   294,   307,   322,
     339,   352,   358,   392,   395,   414,   416,   431,   442,   453,
     461,   468,   475,   487,   488,   495,   499,   500,   502,   508,
     509,   511,   513,   518,   519,   520,   522,   523,   524,   526,
     527,   529,   530,   531,   532,   533,   534,   535,   536,   537,
     538,    83,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,
    -718,  -718,  -718,  -718,  -718,  -718,  -718,   539,  -718,  -718,
    -718,  3958,  4284,   121,   451,   418,  -718,    96,    80,    62,
    -718,   405,  -718,   -11,   336,   388,   421,   542,  -718,   543,
     383,  -718,   544,   699,   546,   547,   548,   549,   685,  -718,
    -718,  -718,   551,   552,   553,   555,   556,   718,   297,    25,
     563,   564,  3958,  3958,    -7,   559,   561,   560,   562,   565,
     566,   568,   -63,   -84,   572,   573,   574,   575,   576,   577,
     578,   579,   580,   581,   584,    96,  3958,  3958,  3958,  3958,
    3958,  3958,  3958,  3958,  3958,  3958,  3958,  3958,   582,   583,
    3958,  3958,  3958,  3958,  3958,   585,   586,   588,  3958,  3958,
    3958,  3469,  3632,  3795,  3958,  3958,  3958,  3958,  3958,  3958,
    3958,  3958,  3958,  3958,  3958,  3958,  3958,  3958,  3958,  3958,
    3958,  3958,  3958,  3958,  3958,  3958,  3958,  3958,  3958,  3958,
    3958,  3958,  3958,  3958,  3958,  3958,  3958,  3958,  3958,  3958,
    3958,  3958,  3958,   567,   590,   383,   383,  3958,  -718,  3958,
     591,   405,  -718,  3958,  3958,  4121,  4121,  4121,  4121,  4121,
    4121,  4121,  4121,  4121,  4121,  4121,   569,  3958,  3958,   383,
    3958,  -718,  -718,   592,  -718,   596,  -718,  -718,  -718,  3958,
    3958,    86,  -718,  1381,  -718,  -718,  -718,  -718,  -718,  -718,
     598,   595,   599,   600,   601,   602,   -18,   -47,   603,   605,
     606,  -718,  3958,  -718,   607,   611,   571,   609,   615,  -718,
    -718,  -718,   593,   621,   634,   635,   636,   633,  -718,   638,
    -718,  -718,  -718,  -718,   570,   644,   648,   649,   650,   651,
     659,  -718,  -718,   183,   205,   210,   215,   225,   232,   235,
     239,   241,   260,   266,   268,  -718,  -718,   279,   281,   284,
     290,   301,  -718,  -718,  -718,   304,   308,   311,  -718,   313,
    -718,   315,  -718,   317,   646,   652,   653,   654,   319,   323,
     325,   327,   330,   332,   335,   647,   341,   343,   345,   347,
     349,   354,   371,   373,   377,   379,   382,   384,   387,   389,
     397,   411,   417,   420,   422,   424,   426,   428,   437,   655,
     656,   657,   658,   660,  -718,   661,   662,   439,  -718,   663,
    -718,   418,  -718,   440,   440,   440,   440,   440,   440,   440,
      62,    62,  -718,  -718,  -718,   607,   668,   679,   680,   383,
    -718,   640,  1582,  1649,   587,   681,   683,  -718,   710,   684,
    -718,  1850,   702,   665,   670,   689,   691,   639,   692,  -718,
     693,   695,  -718,   694,   604,   696,    42,   687,   701,   698,
    3958,  -718,   642,   703,   704,   712,   700,   714,   697,   706,
     713,   717,   722,   723,   724,   726,   727,  -718,  3958,  -718,
    -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,
    -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,
    -718,  3958,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,
    -718,  -718,   329,  -718,  -718,  -718,  -718,  -718,  -718,  -718,
    -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,
    -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,
    -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,   705,   597,
     730,   733,  3958,  3958,  -718,  -718,   734,  -718,   736,    12,
     745,   752,   753,   760,   754,   766,    64,   769,   771,    43,
     772,   796,   448,   800,   805,   306,  -718,  -718,   806,  -718,
    -718,   799,   334,   296,   337,   807,   808,   803,   809,   810,
     300,   300,   300,   300,   300,   814,  -718,   804,   811,   812,
     813,   816,   817,   819,  -718,  3958,   823,  -718,   798,  -718,
    -718,   -37,   -32,   845,  1917,  -718,  2118,  -718,   374,   836,
    -718,  -718,  -718,   840,   838,   839,   846,   851,   249,  -718,
     847,   450,   848,   761,   -43,   849,   854,  -718,   391,   850,
     852,   853,   855,  2185,  -718,   802,   831,   856,  -718,  -718,
     857,   876,  -718,   858,   861,   860,  -718,   862,   863,  1030,
     864,   865,  1033,   866,   869,   873,   877,   879,   881,  -718,
     882,   883,   884,   885,   886,   889,   386,  -718,  -718,  -718,
    -718,  -718,  -718,   887,  -718,   888,  3958,  -718,  3958,  -718,
     893,   894,  -718,   892,  -718,   896,  -718,   419,   901,   903,
     904,   906,   914,   917,   919,   868,  -718,   921,   924,  -718,
    -718,   925,   928,   929,   930,   932,   938,   949,   950,   951,
     927,   946,   948,  3958,   955,   952,   956,  -718,  3958,   958,
    -718,   954,  3958,   963,   959,   965,  -718,   360,   300,  -718,
    -718,  -718,  -718,  -718,  -718,  -718,   960,   962,   964,   967,
     969,   970,   971,  -718,  2386,  -718,   966,  2453,   975,  2654,
    -718,  -718,   -24,  -718,    67,  -718,   961,   976,   977,   981,
     980,   987,   989,   991,   997,  -718,  -718,   992,  -718,  1001,
      75,  1060,  1002,  1004,  1005,  1007,  1003,  1006,  1008,   990,
    -718,  1010,  3958,  1009,  1011,  3958,  1012,  1013,  1014,  3958,
    1017,  1018,  3958,  1020,  1066,  1022,  1035,  1038,  1039,  -718,
    -718,  -718,  -718,  -718,  -718,  -718,  1046,  -718,  1041,  -718,
    1043,   -17,  1044,  1049,   261,  -718,  1047,    68,  1016,  1051,
    1052,  1053,  1048,  1050,  1054,  1042,  1055,    78,    85,  1056,
      87,  1057,  1059,  1061,  1062,  1063,  1064,  1058,  -103,  1068,
     -99,  1067,  -718,  1069,  1070,  1071,  1072,    73,  1073,  1074,
    1075,  1076,  1077,  1078,   126,  1080,  3958,  1082,  -718,  -718,
    2721,  -718,  2922,  -718,  1083,  -718,   427,  1085,  1086,  1088,
    1089,  1102,  -718,  1084,  1103,  1107,  1111,  1065,   -38,   -33,
     -25,  1108,  1115,  1116,  1117,  -718,  1118,  1119,  -718,  -718,
    1120,  1121,  1122,  1126,  1123,  1124,  -718,  -718,  1125,  1127,
    -718,  1128,  1130,  -718,  -718,  1132,  1133,  1134,  -718,  -718,
    -718,  1135,  -718,  -718,  1136,  1137,  1147,  -718,  3958,  1145,
    1146,  1150,  1151,  -718,  1113,  1152,  1153,  1154,  1155,  1131,
    1156,  1163,  1164,  1166,  -718,   -58,   -57,   -56,  1167,  1161,
     -41,  -718,  1165,   -15,  -718,  1169,    17,  -718,  1149,  -718,
    -718,  -718,   120,  -718,  -718,   132,  -718,  -718,  -718,  1170,
    1172,  1177,  1180,  1187,   -79,  -718,  -718,  -718,  -718,  -718,
    -718,  -718,  -718,  1182,  1189,  1194,  -718,  -718,  1314,  1195,
    1196,  1190,  1202,  1203,  1205,  1200,  1208,  1211,  1162,  1212,
    1216,  -718,  1217,  -718,  1218,  -718,  1219,   620,  1221,  -718,
     622,  1222,  -718,   624,  1225,  -718,   -14,  1220,  1228,  1229,
     470,  1227,   472,  1230,  1232,  -718,  1231,  -718,  -718,  1235,
    1238,  -718,  -718,  1237,  1239,  1240,  1215,   -13,    18,    19,
    1224,  1241,  -718,  -718,  -718,   -55,  1242,  1244,  1168,  1248,
    1251,  1171,  1252,  1258,  1226,  1243,    22,  -718,  -718,  -718,
    -718,  1262,  1266,  1265,  1267,  1269,  1270,  1272,  -718,  -718,
    -718,  2989,   -54,   -53,   -52,  1275,  1271,    27,  -718,  1273,
      29,  -718,  1274,    30,  -718,  1276,  -718,  1277,  -718,  1214,
    1278,  1279,  1286,  1280,  1281,  1436,  1283,  1282,  1443,  1287,
    -718,  -718,  1285,  -718,  -718,  1288,  -718,  1289,  3190,  1305,
    1306,  -718,  1307,  -718,  1309,  -718,  1308,   641,  1310,  -718,
     643,  1311,  -718,   645,  1312,  -718,    21,  -718,  1313,  -718,
    1315,  1316,  -718,  1317,  1318,  -718,  1320,  1319,  1481,  1323,
    1324,  1325,  1326,  -718,  -718,  -718,  -718,   -51,  1327,  1329,
    1490,  1330,  1332,  1491,  1333,  1335,  1492,  1328,    32,  -718,
    1336,  -718,  1339,  -718,  1340,  -718,  1341,  1342,  -718,  -718,
    -718,  -718,  1343,  -718,  1495,  1344,  1345,  1504,  1346,  1347,
    1509,  1349,  1348,  1514,  1353,  -718,  -718,  -718,  -718,  -718,
    1356,  -718,  1355,  -718,  1359,  1369,  -718,  1373,  1371,  -718,
    1378,  1379,  1546,  -718,  1384,  -718,  1385,  -718,  1386,  -718,
    1387,  1388,  -718,  -718,  -718,  -718,  1389,  -718
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       4,     4,     0,     0,     0,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   105,     0,     0,     0,    93,    94,
      95,    96,    91,    90,    92,   102,   103,   104,    99,   100,
      97,    98,   101,     0,    89,     5,     9,    10,    11,     0,
      12,    13,    34,    35,    36,    14,    15,    16,    39,    26,
      25,    28,    29,    30,    33,    31,    32,    37,    38,    27,
      17,    18,    19,    20,    21,    22,    23,    24,    40,     0,
     276,   277,   278,   279,   289,   290,   291,   286,   287,   288,
     283,   284,   280,   281,   285,   282,   275,     0,     0,   402,
     403,   400,   404,   405,   406,   407,   401,   399,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   391,     0,     0,
       0,     0,   293,   294,   295,   296,   303,   304,   305,   302,
     306,   307,   299,   300,   297,   298,   301,   292,   308,   309,
     310,     0,     0,     0,   250,   251,   253,   255,   257,   265,
     268,   271,   273,    89,     0,     0,     0,     0,   114,     0,
       0,   118,     0,     0,     0,     0,     0,     0,     0,   248,
     249,     7,     0,     0,     0,     0,     0,   127,   129,     0,
       0,     0,   409,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   256,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   395,   409,
       0,   272,   115,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   113,   200,     0,   117,     0,     7,     7,     7,     0,
       0,   246,   243,     0,     7,   196,   198,   199,   197,   128,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   212,     0,   106,   411,     0,   410,     0,     0,    41,
      42,    43,     0,     0,     0,     0,     0,     0,    60,     0,
      61,    62,    59,    63,     0,     0,     0,     0,     0,     0,
       0,    88,   413,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   362,   363,     0,     0,     0,
       0,     0,   324,   343,   344,     0,     0,     0,   351,     0,
     353,     0,   355,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   390,     0,     0,     0,   411,     0,
     408,   252,   254,   258,   259,   262,   263,   260,   261,   264,
     266,   267,   269,   270,   274,     0,     0,     0,     0,     0,
     116,     0,     0,     0,     0,     0,     0,   244,     0,     0,
       8,     0,     0,     0,     0,     0,     0,     0,     0,   164,
       0,     0,   212,     0,     0,     0,     0,     0,   107,     0,
       0,   109,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   312,     0,   313,
     314,   315,   316,   317,   318,   319,   320,   321,   322,   323,
     347,   348,   349,   345,   346,   341,   342,   325,   350,   352,
     354,     0,   359,   360,   361,   326,   327,   328,   329,   330,
     331,   332,     0,   339,   340,   364,   365,   366,   376,   371,
     367,   368,   369,   370,   372,   373,   374,   375,   377,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   396,   397,   398,   311,   110,   111,   112,     0,   233,
       0,     0,     0,     0,     7,     7,     0,     7,     0,   129,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   213,     7,     0,   119,
     412,     0,    83,    83,    83,     0,     0,     0,     0,     0,
      83,    83,    83,    83,    83,     0,   414,     0,     0,     0,
       0,     0,     0,     0,   201,     0,     0,   231,     0,   235,
     236,     0,     0,     0,     0,   242,     0,   195,   129,     0,
     131,   132,   130,     0,     0,     0,     0,     0,     0,   165,
       0,     0,     0,     0,     0,     0,     0,   203,     0,     0,
       0,     0,     0,     0,   108,     0,     0,     0,    84,    85,
       0,    86,    87,     0,     0,     0,    86,     0,     0,     0,
       0,     0,    86,     0,     0,     0,     0,     0,     0,    68,
       0,     0,     0,     0,     0,     0,     0,   335,   334,   333,
     336,   337,   338,     0,     7,     0,     0,     7,     0,     7,
       0,     0,   134,     0,   164,     0,   120,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   202,     0,     0,   206,
     212,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    45,     0,     0,
      46,     0,     0,     0,     0,     0,    47,    83,    83,    81,
      82,    69,    70,    71,    72,    73,     0,     0,     0,     0,
       0,     0,     0,     7,     0,   229,     0,     0,     0,     0,
     194,   134,     0,   133,     0,   164,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   212,   212,     0,   212,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     241,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    74,
     356,   357,   358,   392,   393,   394,     0,     7,     0,     7,
       0,     0,     0,     0,     0,   135,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    44,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    48,    49,
       0,   237,     0,   239,     0,     7,     0,     0,     0,     0,
       0,     0,   122,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   212,     0,     0,   211,   212,
       0,     0,     0,     0,     0,     0,   215,   216,     0,     0,
     214,     0,     0,    54,    76,     0,     0,     0,    65,    56,
      66,     0,    53,    75,     0,     0,     0,    64,     0,     0,
       0,     0,     0,     7,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,     0,     0,     0,     0,     0,
       0,   168,     0,     0,   170,     0,     0,   166,     0,   182,
     205,   208,     0,   204,   207,     0,   219,   220,   218,     0,
       0,     0,     0,     0,     0,    51,    58,    79,    80,    50,
      57,    77,    78,     0,     0,     0,   238,   240,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   176,     0,   178,     0,   174,     0,     0,     0,   169,
       0,     0,   171,     0,     0,   167,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   217,     0,    55,    67,     0,
       0,     7,   123,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   177,   179,   175,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   172,   210,   209,
     221,     0,     0,     0,     0,     0,     0,     0,    52,     7,
     124,     0,     0,     0,     0,     0,     0,     0,   138,     0,
       0,   140,     0,     0,   136,     0,   152,     0,   180,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     173,   225,     0,   222,   227,     0,   223,     0,     0,     0,
       0,   146,     0,   148,     0,   144,     0,     0,     0,   139,
       0,     0,   141,     0,     0,   137,     0,   181,     0,   188,
       0,     0,   189,     0,     0,   187,     0,     0,     0,     0,
       0,     0,     0,   125,   147,   149,   145,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   142,
       0,   184,     0,   185,     0,   183,     0,     0,   226,   228,
     224,   126,     0,   150,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   143,   192,   193,   191,   190,
       0,   151,     0,   158,     0,     0,   159,     0,     0,   157,
       0,     0,     0,   186,     0,   154,     0,   155,     0,   153,
       0,     0,   162,   163,   161,   160,     0,   156
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -718,  -718,  1213,  -370,   690,  -718,  -718,  -572,  -718,   154,
    -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,
    -718,  -718,  -613,   400,  -718,  -717,  -718,  -718,  -718,  -718,
    -718,  -718,  -718,  -718,  -718,  -718,  -551,  -718,  -718,  -718,
    -718,  -718,  -718,  -718,  -718,  -718,  -718,  -718,  1223,  -718,
    -718,  -718,   -10,  -718,   909,   933,  1477,   108,   344,   348,
    1390,     3,  -718,  1250,  -718,   667
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,   383,   540,    56,    57,   754,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,   390,   396,   862,   925,   666,   729,    71,    72,    73,
      74,    75,    76,    77,    78,    79,   556,   676,    80,   649,
     707,   708,    81,    82,    83,    84,    85,   381,   382,   538,
      86,    87,   432,   214,   215,   216,   217,   218,   219,   220,
     221,   107,   222,   405,   406,   433
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     213,   669,  1108,   408,   227,  1049,   531,   532,   533,   232,
    1052,   234,   235,   236,   541,   225,    -3,     6,  1055,   229,
       7,     8,     9,   391,   392,   393,   394,   237,  1111,  1155,
    1176,   548,   786,   243,   244,   245,   246,   788,  1100,  1102,
    1104,  1187,  1210,  1212,  1214,  1272,   719,    10,    11,    12,
      13,    14,    15,   550,    16,    17,   250,   808,  1050,     1,
    1114,  1179,  1182,  1053,  1257,  1199,    18,    19,    20,   922,
    1218,  1056,  1221,  1224,    21,  1284,   974,   864,    22,    23,
     923,    24,  1156,  1177,  1004,  1005,    25,   923,  1008,  1009,
      26,    27,    28,   251,   251,    29,    88,    30,   274,    31,
      32,    33,    34,     5,  1006,   791,    35,   419,  1010,  1124,
      36,   758,   764,    37,  1180,  1183,    89,  1258,   770,   771,
     772,   773,   774,   420,   397,   398,   399,   417,  1125,   108,
     257,   258,   259,   260,   261,   262,   263,   264,   265,   266,
     673,   732,   551,   228,   418,   674,   674,    34,   927,  1101,
    1103,  1105,  1188,  1211,  1213,  1215,  1273,   380,   536,   726,
     552,   230,   926,   983,   809,   224,  1109,   226,   727,  1051,
     787,   727,   727,   942,  1054,   789,   993,   233,   674,   924,
     238,   674,  1057,   994,   239,   996,   924,   240,   674,   549,
     674,   241,  1112,  1157,  1178,    38,    39,   252,   367,    40,
     409,   350,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,   400,   718,   242,    53,  1117,    54,
     276,   267,   253,   674,  1115,  1181,  1184,   247,  1259,  1200,
    1118,   248,   401,   373,  1219,   674,  1222,  1225,   249,  1285,
      38,    39,   404,   407,    40,   675,   675,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,   880,
     798,   799,   800,   801,   223,   907,   908,   728,  1016,  1017,
     728,   728,   977,   978,   979,   980,   364,   365,   675,   277,
    1018,   675,   361,   278,   713,   714,   279,   716,   675,   348,
     675,   280,   362,   363,   464,   465,   466,   467,   268,   269,
     270,   271,   272,   273,   355,   475,   281,   743,   391,   392,
     393,   394,   356,   357,   358,   359,   360,   739,   740,   741,
     742,  1025,  1026,   675,   937,   938,   755,   940,   352,   499,
     500,   501,   502,  1027,   282,   675,   748,   749,   283,   508,
     748,   749,   756,   752,   284,   395,   756,   752,   505,   506,
     802,   698,   699,   700,   701,   702,   703,   525,   526,   285,
     528,   286,   981,   746,   747,   287,   759,   760,   288,   534,
     535,   289,   527,   290,   748,   749,   750,   748,   749,   761,
     751,   752,   291,   762,   752,   391,   392,   393,   394,   904,
     905,   292,   557,   577,   578,   293,   757,   254,   255,   256,
     748,   749,   812,   813,   814,   815,   756,   752,   847,   848,
     849,   850,   851,   852,   854,   579,   578,   857,   294,   859,
     580,   578,   295,    -2,     6,   581,   578,     7,     8,     9,
     866,   867,   868,   869,   753,   582,   578,   763,  1035,  1036,
    1037,  1038,   583,   578,  1062,   584,   578,   296,  1065,   585,
     578,   586,   578,   297,    10,    11,    12,    13,    14,    15,
     906,    16,    17,   513,   514,   515,   516,   517,   518,   519,
     587,   578,   298,    18,    19,    20,   588,   578,   589,   578,
     299,    21,   300,   916,   301,    22,    23,   302,    24,   590,
     578,   591,   578,    25,   592,   578,   303,    26,    27,    28,
     593,   578,    29,   304,    30,   354,    31,    32,    33,    34,
     366,   594,   578,    35,   595,   578,   305,    36,   596,   578,
      37,   597,   578,   598,   578,   599,   578,   600,   578,   605,
     578,   306,   648,   606,   578,   607,   578,   608,   578,   353,
     609,   578,   610,   578,   368,   611,   578,   970,   307,   972,
     680,   613,   578,   614,   578,   615,   578,   616,   578,   617,
     578,   308,    90,    91,   618,   578,    92,   309,   696,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   619,   578,   620,   578,   105,   106,   621,   578,   622,
     578,   697,   623,   578,   624,   578,   369,   625,   578,   626,
     578,   310,    38,    39,   311,  1034,    40,   627,   578,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,   628,   578,   312,    53,   313,    54,   629,   578,   370,
     630,   578,   631,   578,   632,   578,   633,   578,   634,   578,
     314,     6,   711,   712,     7,     8,     9,   635,   578,   643,
     578,   315,   362,   363,   652,   653,   705,   706,   735,   736,
     804,   805,   316,  1088,  1146,  1147,  1149,  1150,  1152,  1153,
     317,    10,    11,    12,    13,    14,    15,   318,    16,    17,
    1161,  1162,  1164,  1165,   319,  1248,  1249,  1251,  1252,  1254,
    1255,    19,    20,    55,    55,   783,   320,   321,    21,  -230,
    -230,  -230,    22,    23,   322,    24,   520,   521,   323,   324,
      25,   325,   522,   523,    26,    27,    28,   326,   327,    29,
     328,    30,   329,    31,    32,    33,    34,   330,   331,   332,
      35,   333,   334,   335,    36,   336,   337,    37,   338,   339,
     340,   341,   342,   343,   344,   345,   346,   347,   349,   371,
     372,   374,   375,   376,   377,   378,   380,   379,   384,   385,
     386,  1171,   387,   388,   389,   402,   410,   403,   411,   412,
     503,   413,   524,   570,   414,   415,   856,   416,   858,   421,
     422,   423,   560,   656,   424,   425,   426,   427,   428,   429,
     430,   431,   445,   446,   659,   452,   453,   563,   454,  1208,
     504,   510,   529,   530,   543,   542,   678,   671,   544,   545,
     546,   547,   553,   893,   554,   555,   561,   558,   897,    38,
      39,   559,   900,    40,   562,   564,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,   565,   566,
     567,    53,   568,    54,   576,   664,     6,   569,   571,     7,
       8,     9,   572,   573,   574,   575,   681,   601,   612,   785,
     807,   822,   602,   603,   604,   636,   637,   638,   639,   660,
     640,   641,   642,   644,   661,   645,    10,    11,    12,    13,
      14,    15,   953,    16,    17,   956,   646,   647,   654,   960,
     655,   657,   963,   662,   677,   663,    19,    20,   670,   672,
     687,   665,   667,    21,   668,   679,   825,    22,    23,   688,
      24,   685,   704,   682,   683,    25,  -245,  -245,  -245,    26,
      27,    28,   684,   689,    29,   686,    30,   690,    31,    32,
      33,    34,   691,   692,   693,    35,   694,   709,   695,    36,
     710,   715,    37,   717,   434,   435,   436,   437,   438,   439,
     440,   441,   442,   443,   444,   720,  1029,   447,   448,   449,
     450,   451,   721,   722,   724,   455,   456,   457,   459,   461,
     463,   723,   725,   730,   731,   468,   469,   470,   471,   472,
     473,   474,   733,   476,   477,   478,   479,   480,   481,   482,
     483,   484,   485,   486,   487,   488,   489,   490,   491,   492,
     493,   494,   495,   496,   497,   498,   734,   737,   738,   744,
     745,   765,   766,   767,   507,   776,   821,   769,  1083,   768,
     775,   777,   778,   779,    38,    39,   780,   781,    40,   782,
     784,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,   792,   793,   794,    53,     6,    54,   795,
       7,     8,     9,   796,   797,   806,   810,   803,   811,   816,
     831,   817,   818,   834,   819,   823,   824,   826,   827,   828,
     830,   829,   877,   832,   833,   835,   836,    10,    11,    12,
      13,    14,    15,   837,    16,    17,   839,   838,   840,   841,
     842,   843,   844,   845,   853,   855,   965,    19,    20,   846,
     860,   861,   863,   865,    21,  -232,  -232,  -232,    22,    23,
     870,    24,   871,   872,     6,   873,    25,     7,     8,     9,
      26,    27,    28,   874,   875,    29,   876,    30,   878,    31,
      32,    33,    34,   879,   890,   881,    35,   882,   883,   884,
      36,   885,   886,    37,    10,    11,    12,    13,    14,    15,
    1089,    16,    17,   887,   888,   889,   891,   892,   894,   943,
     896,   895,   898,   899,    19,    20,   901,   909,   902,   903,
     928,    21,   910,   917,   911,    22,    23,   912,    24,   913,
     914,   915,   919,    25,   932,   929,   930,    26,    27,    28,
     931,   933,    29,   934,    30,   935,    31,    32,    33,    34,
     936,   951,   939,    35,  1090,   941,   944,    36,   945,   946,
      37,   947,  1191,   948,     4,  1194,   949,   952,   950,   954,
     984,   955,   957,   958,   959,    38,    39,   961,   962,    40,
     964,   966,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,   967,   968,   969,    53,   971,    54,
     973,   975,   976,   991,   982,   985,   986,   987,   988,  1228,
     989,   921,   511,   995,   990,   992,   998,   997,   999,  1003,
    1197,  1011,  1000,  1001,  1002,  1007,  1048,  1013,  1014,  1012,
    1019,  1020,  1015,  1022,  1023,  1021,  1030,   512,  1024,  1028,
    1033,  1044,    38,    39,  1039,  1040,    40,  1041,  1042,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,  1043,  1058,  1045,    53,     6,    54,  1046,     7,     8,
       9,  1047,  1059,  1060,  1061,  1063,  1064,  1066,  1067,  1068,
    1069,  1231,  1070,  1071,  1072,  1095,  1073,  1075,  1074,  1076,
    1077,  1078,  1079,  1080,  1081,    10,    11,    12,    13,    14,
      15,  1129,    16,    17,  1082,  1084,  1085,  1086,  1087,  1116,
    1096,  1091,  1092,  1093,  1094,    19,    20,  1097,  1098,  1099,
    1107,  1106,    21,  1140,  1110,  1120,    22,    23,  1113,    24,
    1119,  1121,     6,  1122,    25,     7,     8,     9,    26,    27,
      28,  1123,  1126,    29,  1133,    30,  1127,    31,    32,    33,
      34,  1128,  1131,  1132,    35,  1130,  1134,  1135,    36,  1136,
    1137,    37,    10,    11,    12,    13,    14,    15,  1138,    16,
      17,  1139,  1141,  1142,  1143,  1144,  1175,  1158,  1185,  1145,
    1148,  1151,    19,    20,  1154,  1159,  1160,  1163,  1168,    21,
    1166,  1167,  1169,    22,    23,  1170,    24,  1172,  1186,  1173,
    1174,    25,  1198,  1189,  1190,    26,    27,    28,   539,  1192,
      29,  1193,    30,  1195,    31,    32,    33,    34,  1196,  1201,
    1202,    35,  1203,  1205,  1204,    36,  1207,  1206,    37,  1216,
    1217,  1234,  1220,  1223,  1227,  1229,  1226,  1232,  1237,  1230,
    1235,  1233,  1236,    38,    39,  1239,  1238,    40,  1240,  1241,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,  1243,  1244,  1245,    53,  1246,    54,  1247,  1250,
    1253,  1256,  1261,  1260,  1263,  1267,  1262,  1265,  1264,  1266,
    1268,  1269,  1270,  1271,  1276,  1279,  1282,  1283,  1274,  1275,
    1292,  1277,  1278,  1286,  1280,  1281,  1287,  1288,  1289,  1295,
    1291,  1293,  1290,  1296,  1298,  1294,  1299,  1297,  1300,  1301,
      38,    39,  1302,  1303,    40,  1304,  1305,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,  1306,
    1307,  1308,    53,     6,    54,  1309,     7,     8,     9,  1310,
    1311,  1312,  1313,  1314,  1315,   275,  1317,     0,  1316,   509,
       0,     0,   351,     0,   537,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,    12,    13,    14,    15,     0,
      16,    17,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    19,    20,     0,     0,     0,     0,     0,
      21,     0,     0,     0,    22,    23,   650,    24,     0,     0,
       6,     0,    25,     7,     8,     9,    26,    27,    28,     0,
       0,    29,     0,    30,     0,    31,    32,    33,    34,     0,
       0,     0,    35,     0,     0,     0,    36,     0,     0,    37,
      10,    11,    12,    13,    14,    15,     0,    16,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      19,    20,     0,     0,     0,     0,     0,    21,     0,     0,
       0,    22,    23,   651,    24,     0,     0,     0,     0,    25,
       0,     0,     0,    26,    27,    28,     0,     0,    29,     0,
      30,     0,    31,    32,    33,    34,     0,     0,     0,    35,
       0,     0,     0,    36,     0,     0,    37,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    38,    39,     0,     0,    40,     0,     0,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
       0,     0,     0,    53,     0,    54,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,    39,
       0,     0,    40,     0,     0,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,     0,     0,     0,
      53,     6,    54,     0,     7,     8,     9,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,    12,    13,    14,    15,     0,    16,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    19,    20,     0,     0,     0,     0,     0,    21,     0,
       0,     0,    22,    23,     0,    24,     0,     0,     6,     0,
      25,     7,     8,     9,    26,    27,    28,     0,     0,    29,
     658,    30,     0,    31,    32,    33,    34,     0,     0,     0,
      35,     0,     0,     0,    36,     0,     0,    37,    10,    11,
      12,    13,    14,    15,     0,    16,    17,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    19,    20,
       0,     0,     0,     0,     0,    21,     0,     0,     0,    22,
      23,     0,    24,     0,     0,     0,     0,    25,     0,     0,
    -247,    26,    27,    28,     0,     0,    29,     0,    30,     0,
      31,    32,    33,    34,     0,     0,     0,    35,     0,     0,
       0,    36,     0,     0,    37,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
      39,     0,     0,    40,     0,     0,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,     0,     0,
       0,    53,     0,    54,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,    39,     0,     0,
      40,     0,     0,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,     0,     0,     0,    53,     6,
      54,     0,     7,     8,     9,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
      11,    12,    13,    14,    15,     0,    16,    17,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    19,
      20,     0,     0,     0,     0,     0,    21,     0,     0,     0,
      22,    23,     0,    24,     0,     0,     6,     0,    25,     7,
       8,     9,    26,    27,    28,     0,   790,    29,     0,    30,
       0,    31,    32,    33,    34,     0,     0,     0,    35,     0,
       0,     0,    36,     0,     0,    37,    10,    11,    12,    13,
      14,    15,     0,    16,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    19,    20,     0,     0,
       0,     0,     0,    21,     0,     0,     0,    22,    23,     0,
      24,   820,     0,     0,     0,    25,     0,     0,     0,    26,
      27,    28,     0,     0,    29,     0,    30,     0,    31,    32,
      33,    34,     0,     0,     0,    35,     0,     0,     0,    36,
       0,     0,    37,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,    39,     0,
       0,    40,     0,     0,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,     0,     0,     0,    53,
       0,    54,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,    39,     0,     0,    40,     0,
       0,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,     0,     0,     0,    53,     6,    54,     0,
       7,     8,     9,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,    12,
      13,    14,    15,     0,    16,    17,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    19,    20,     0,
       0,     0,     0,     0,    21,     0,     0,  -234,    22,    23,
       0,    24,     0,     0,     6,     0,    25,     7,     8,     9,
      26,    27,    28,     0,     0,    29,     0,    30,     0,    31,
      32,    33,    34,     0,     0,     0,    35,     0,     0,     0,
      36,     0,     0,    37,    10,    11,    12,    13,    14,    15,
       0,    16,    17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    19,    20,     0,     0,     0,     0,
       0,    21,     0,     0,     0,    22,    23,     0,    24,   918,
       0,     0,     0,    25,     0,     0,     0,    26,    27,    28,
       0,     0,    29,     0,    30,     0,    31,    32,    33,    34,
       0,     0,     0,    35,     0,     0,     0,    36,     0,     0,
      37,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,    39,     0,     0,    40,
       0,     0,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,     0,     0,     0,    53,     0,    54,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,    39,     0,     0,    40,     0,     0,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,     0,     0,     0,    53,     6,    54,     0,     7,     8,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,    11,    12,    13,    14,
      15,     0,    16,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    19,    20,     0,     0,     0,
       0,     0,    21,     0,     0,     0,    22,    23,     0,    24,
     920,     0,     6,     0,    25,     7,     8,     9,    26,    27,
      28,     0,     0,    29,     0,    30,     0,    31,    32,    33,
      34,     0,     0,     0,    35,     0,     0,     0,    36,     0,
       0,    37,    10,    11,    12,    13,    14,    15,     0,    16,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    19,    20,     0,     0,     0,     0,     0,    21,
       0,     0,     0,    22,    23,     0,    24,  1031,     0,     0,
       0,    25,     0,     0,     0,    26,    27,    28,     0,     0,
      29,     0,    30,     0,    31,    32,    33,    34,     0,     0,
       0,    35,     0,     0,     0,    36,     0,     0,    37,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,    39,     0,     0,    40,     0,     0,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,     0,     0,     0,    53,     0,    54,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,    39,     0,     0,    40,     0,     0,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,     0,
       0,     0,    53,     6,    54,     0,     7,     8,     9,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,    12,    13,    14,    15,     0,
      16,    17,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    19,    20,     0,     0,     0,     0,     0,
      21,     0,     0,     0,    22,    23,     0,    24,  1032,     0,
       6,     0,    25,     7,     8,     9,    26,    27,    28,     0,
       0,    29,     0,    30,     0,    31,    32,    33,    34,     0,
       0,     0,    35,     0,     0,     0,    36,     0,     0,    37,
      10,    11,    12,    13,    14,    15,     0,    16,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      19,    20,     0,     0,     0,     0,     0,    21,     0,     0,
       0,    22,    23,     0,    24,     0,     0,     0,     0,    25,
       0,     0,     0,    26,    27,    28,     0,     0,    29,     0,
      30,     0,    31,    32,    33,    34,     0,     0,     0,    35,
    1209,     0,     0,    36,     0,     0,    37,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    38,    39,     0,     0,    40,     0,     0,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
       0,     0,     0,    53,     0,    54,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,    39,
       0,     0,    40,     0,     0,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,     0,     0,     0,
      53,     6,    54,     0,     7,     8,     9,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,    12,    13,    14,    15,     0,    16,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    19,    20,     0,     0,     0,     0,     0,    21,     0,
       0,     0,    22,    23,     0,    24,     0,     0,     0,     0,
      25,     0,     0,     0,    26,    27,    28,     0,     0,    29,
       0,    30,     0,    31,    32,    33,    34,     0,     0,     0,
      35,  1242,     0,     0,    36,     0,     0,    37,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   109,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   110,     0,     0,     0,     0,     0,     0,     0,   111,
     112,   113,   114,   115,     0,     0,     0,     0,     0,    38,
      39,     0,     0,    40,     0,     0,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,   116,     0,
       0,    53,   117,    54,     0,   118,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,     0,     0,   194,
     109,     0,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,     0,     0,     0,     0,     0,   207,
     208,   209,   210,   231,   110,   211,     0,     0,     0,   212,
       0,     0,   111,   112,   113,   114,   115,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   116,     0,     0,     0,   117,     0,     0,   118,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
       0,     0,   194,   109,     0,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,     0,     0,     0,
       0,     0,   207,   208,   209,   210,     0,   110,   211,   458,
       0,     0,   212,     0,     0,   111,   112,   113,   114,   115,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   116,     0,     0,     0,   117,     0,
       0,   118,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,     0,     0,   194,   109,     0,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
       0,     0,     0,     0,     0,   207,   208,   209,   210,     0,
     110,   211,   460,     0,     0,   212,     0,     0,   111,   112,
     113,   114,   115,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   116,     0,     0,
       0,   117,     0,     0,   118,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,     0,     0,   194,   109,
       0,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,     0,     0,     0,     0,     0,   207,   208,
     209,   210,     0,   110,   211,   462,     0,     0,   212,     0,
       0,   111,   112,   113,   114,   115,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     116,     0,     0,     0,   117,     0,     0,   118,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,     0,
       0,   194,   109,     0,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,     0,     0,     0,     0,
       0,   207,   208,   209,   210,     0,   110,   211,     0,     0,
       0,   212,     0,     0,   111,   112,   113,   114,   115,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   116,     0,     0,     0,   117,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,     0,     0,   194,   109,     0,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,     0,
       0,     0,     0,     0,   207,   208,   209,   210,     0,   110,
     211,     0,     0,     0,   212,     0,     0,   111,   112,   113,
     114,   115,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   116,     0,     0,     0,
     117,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,     0,     0,   194,     0,     0,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,     0,     0,     0,     0,     0,   207,   208,   209,
     210,     0,     0,   211
};

static const yytype_int16 yycheck[] =
{
      10,   552,    43,    10,    14,    43,   376,   377,   378,    19,
      43,    21,    22,    23,   384,    12,     0,     1,    43,    16,
       4,     5,     6,    11,    12,    13,    14,    24,    43,    43,
      43,    49,    69,    30,    31,    32,    33,    69,    96,    96,
      96,    96,    96,    96,    96,    96,   659,    31,    32,    33,
      34,    35,    36,   100,    38,    39,    53,   100,    96,     3,
      43,    43,    43,    96,    43,    43,    50,    51,    52,    93,
      43,    96,    43,    43,    58,    43,    93,   794,    62,    63,
     104,    65,    96,    96,   187,   188,    70,   104,   187,   188,
      74,    75,    76,   105,   105,    79,   207,    81,   108,    83,
      84,    85,    86,     0,   207,   718,    90,   191,   207,   188,
      94,   683,   684,    97,    96,    96,   203,    96,   690,   691,
     692,   693,   694,   207,    99,   100,   101,   190,   207,   203,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      98,    98,   189,   207,   207,   103,   103,    86,   865,   207,
     207,   207,   207,   207,   207,   207,   207,    71,    72,    95,
     207,   209,    95,    95,   207,    11,   207,    13,   104,   207,
     207,   104,   104,    98,   207,   207,    98,   208,   103,   203,
     207,   103,   207,    98,   207,    98,   203,   207,   103,   207,
     103,   207,   207,   207,   207,   179,   180,   209,   209,   183,
     207,   211,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   189,   203,   203,   201,    98,   203,
     209,   102,   208,   103,   207,   207,   207,   203,   207,   207,
      98,   203,   207,   230,   207,   103,   207,   207,   203,   207,
     179,   180,   252,   253,   183,   203,   203,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   810,
      11,    12,    13,    14,   203,   837,   838,   203,   195,   196,
     203,   203,    11,    12,    13,    14,   214,   215,   203,   209,
     207,   203,   202,   209,   654,   655,   209,   657,   203,   206,
     203,   209,   212,   213,   304,   305,   306,   307,   179,   180,
     181,   182,   183,   184,   208,   315,   209,   677,    11,    12,
      13,    14,   216,   217,   218,   219,   220,    11,    12,    13,
      14,   195,   196,   203,   875,   876,    30,   878,   207,   339,
     340,   341,   342,   207,   209,   203,    40,    41,   209,   349,
      40,    41,    46,    47,   209,    48,    46,    47,   345,   346,
     101,    22,    23,    24,    25,    26,    27,   367,   368,   209,
     370,   209,   101,    29,    30,   209,    29,    30,   209,   379,
     380,   209,   369,   209,    40,    41,    42,    40,    41,    42,
      46,    47,   209,    46,    47,    11,    12,    13,    14,    29,
      30,   209,   402,   210,   211,   209,   100,     7,     8,     9,
      40,    41,    11,    12,    13,    14,    46,    47,    22,    23,
      24,    25,    26,    27,   784,   210,   211,   787,   209,   789,
     210,   211,   209,     0,     1,   210,   211,     4,     5,     6,
      11,    12,    13,    14,   100,   210,   211,   100,    11,    12,
      13,    14,   210,   211,   995,   210,   211,   209,   999,   210,
     211,   210,   211,   209,    31,    32,    33,    34,    35,    36,
     100,    38,    39,   355,   356,   357,   358,   359,   360,   361,
     210,   211,   209,    50,    51,    52,   210,   211,   210,   211,
     209,    58,   209,   853,   209,    62,    63,   209,    65,   210,
     211,   210,   211,    70,   210,   211,   209,    74,    75,    76,
     210,   211,    79,   209,    81,    87,    83,    84,    85,    86,
     105,   210,   211,    90,   210,   211,   209,    94,   210,   211,
      97,   210,   211,   210,   211,   210,   211,   210,   211,   210,
     211,   209,   529,   210,   211,   210,   211,   210,   211,    88,
     210,   211,   210,   211,   208,   210,   211,   917,   209,   919,
     560,   210,   211,   210,   211,   210,   211,   210,   211,   210,
     211,   209,   179,   180,   210,   211,   183,   209,   578,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   210,   211,   210,   211,   202,   203,   210,   211,   210,
     211,   601,   210,   211,   210,   211,   208,   210,   211,   210,
     211,   209,   179,   180,   209,   975,   183,   210,   211,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   210,   211,   209,   201,   209,   203,   210,   211,   208,
     210,   211,   210,   211,   210,   211,   210,   211,   210,   211,
     209,     1,   652,   653,     4,     5,     6,   210,   211,   210,
     211,   209,   212,   213,    67,    68,    59,    60,   210,   211,
     210,   211,   209,  1033,    44,    45,    44,    45,    44,    45,
     209,    31,    32,    33,    34,    35,    36,   209,    38,    39,
     210,   211,   210,   211,   209,    44,    45,    44,    45,    44,
      45,    51,    52,     3,     4,   705,   209,   209,    58,    59,
      60,    61,    62,    63,   209,    65,   362,   363,   209,   209,
      70,   209,   364,   365,    74,    75,    76,   209,   209,    79,
     209,    81,   209,    83,    84,    85,    86,   209,   209,   209,
      90,   209,   209,   209,    94,   209,   209,    97,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   207,
     207,   207,    53,   207,   207,   207,    71,   208,   207,   207,
     207,  1131,   207,   207,    46,   202,   207,   203,   207,   209,
     203,   209,   203,   203,   209,   209,   786,   209,   788,   207,
     207,   207,   211,    73,   209,   209,   209,   209,   209,   209,
     209,   207,   210,   210,    92,   210,   210,   204,   210,  1169,
     210,   210,   210,   207,   209,   207,   105,   203,   209,   209,
     209,   209,   209,   823,   209,   209,   207,   210,   828,   179,
     180,   210,   832,   183,   209,   204,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   204,   204,
     204,   201,   209,   203,   185,   206,     1,   209,   204,     4,
       5,     6,   204,   204,   204,   204,   214,   211,   211,    61,
      99,    30,   210,   210,   210,   210,   210,   210,   210,   204,
     210,   210,   210,   210,   204,   207,    31,    32,    33,    34,
      35,    36,   892,    38,    39,   895,   207,   207,   207,   899,
     207,   207,   902,   204,   207,   204,    51,    52,   204,   203,
     203,   209,   209,    58,   209,   207,    30,    62,    63,   203,
      65,   211,   207,   210,   210,    70,    71,    72,    73,    74,
      75,    76,   210,   210,    79,   211,    81,   210,    83,    84,
      85,    86,   210,   210,   210,    90,   210,   207,   211,    94,
     207,   207,    97,   207,   277,   278,   279,   280,   281,   282,
     283,   284,   285,   286,   287,   210,   966,   290,   291,   292,
     293,   294,   210,   210,   210,   298,   299,   300,   301,   302,
     303,   211,   206,   204,   203,   308,   309,   310,   311,   312,
     313,   314,   210,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,   326,   327,   328,   329,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   210,   207,   203,   203,
     211,   204,   204,   210,   347,   211,   214,   207,  1028,   210,
     206,   210,   210,   210,   179,   180,   210,   210,   183,   210,
     207,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   207,   204,   207,   201,     1,   203,   210,
       4,     5,     6,   207,   203,   207,   207,   210,   204,   209,
      30,   209,   209,    30,   209,   209,   209,   209,   207,   209,
     207,   209,   204,   209,   209,   209,   207,    31,    32,    33,
      34,    35,    36,   210,    38,    39,   207,   210,   207,   207,
     207,   207,   207,   207,   207,   207,    30,    51,    52,   210,
     207,   207,   210,   207,    58,    59,    60,    61,    62,    63,
     209,    65,   209,   209,     1,   209,    70,     4,     5,     6,
      74,    75,    76,   209,   207,    79,   207,    81,   207,    83,
      84,    85,    86,   209,   207,   210,    90,   209,   209,   209,
      94,   209,   204,    97,    31,    32,    33,    34,    35,    36,
      37,    38,    39,   204,   204,   204,   210,   209,   203,    99,
     204,   209,   204,   209,    51,    52,   203,   207,   209,   204,
     209,    58,   210,   207,   210,    62,    63,   210,    65,   210,
     210,   210,   207,    70,   204,   209,   209,    74,    75,    76,
     209,   204,    79,   204,    81,   204,    83,    84,    85,    86,
     203,   211,   210,    90,    91,   204,   204,    94,   204,   204,
      97,   204,    44,   210,     1,    44,   210,   207,   210,   210,
     204,   210,   210,   210,   210,   179,   180,   210,   210,   183,
     210,   209,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   209,   207,   207,   201,   207,   203,
     207,   207,   203,   211,   207,   204,   204,   204,   210,    45,
     210,   861,   353,   207,   210,   210,   207,   210,   207,   211,
      44,   204,   210,   210,   210,   207,   211,   207,   207,   210,
     207,   207,   210,   207,   207,   210,   204,   354,   210,   209,
     207,   207,   179,   180,   209,   209,   183,   209,   209,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   209,   204,   210,   201,     1,   203,   210,     4,     5,
       6,   210,   207,   207,   207,   207,   207,   207,   207,   207,
     204,    45,   209,   209,   209,   204,   209,   207,   210,   207,
     207,   207,   207,   207,   207,    31,    32,    33,    34,    35,
      36,    37,    38,    39,   207,   210,   210,   207,   207,   210,
     204,   209,   209,   209,   209,    51,    52,   204,   204,   203,
     209,   204,    58,   211,   209,   203,    62,    63,   209,    65,
     210,   204,     1,   203,    70,     4,     5,     6,    74,    75,
      76,   204,   210,    79,   204,    81,   207,    83,    84,    85,
      86,   207,   207,   207,    90,    91,   204,   204,    94,   204,
     210,    97,    31,    32,    33,    34,    35,    36,   210,    38,
      39,   210,   210,   207,   207,   207,   211,   207,   204,   210,
     209,   209,    51,    52,   209,   207,   207,   210,   207,    58,
     210,   209,   207,    62,    63,   207,    65,   210,   207,   210,
     210,    70,   209,   211,   210,    74,    75,    76,    77,   211,
      79,   210,    81,   211,    83,    84,    85,    86,   210,   207,
     204,    90,   207,   204,   207,    94,   204,   207,    97,   204,
     209,    45,   209,   209,   207,   207,   210,   207,    45,   210,
     207,   210,   210,   179,   180,   210,   209,   183,   210,   210,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   207,   207,   207,   201,   207,   203,   210,   209,
     209,   209,   207,   210,   207,    44,   210,   207,   210,   210,
     207,   207,   207,   207,    44,    44,    44,   209,   211,   210,
      45,   211,   210,   207,   211,   210,   207,   207,   207,    45,
     207,   207,   210,   207,    45,   210,   207,   210,   210,    45,
     179,   180,   209,   207,   183,   210,   207,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   210,
     207,   210,   201,     1,   203,   207,     4,     5,     6,   210,
      44,   207,   207,   207,   207,   118,   207,    -1,   210,   349,
      -1,    -1,   212,    -1,   381,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    -1,
      38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    -1,    -1,    -1,    -1,    -1,
      58,    -1,    -1,    -1,    62,    63,    64,    65,    -1,    -1,
       1,    -1,    70,     4,     5,     6,    74,    75,    76,    -1,
      -1,    79,    -1,    81,    -1,    83,    84,    85,    86,    -1,
      -1,    -1,    90,    -1,    -1,    -1,    94,    -1,    -1,    97,
      31,    32,    33,    34,    35,    36,    -1,    38,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    52,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,
      -1,    62,    63,    64,    65,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    74,    75,    76,    -1,    -1,    79,    -1,
      81,    -1,    83,    84,    85,    86,    -1,    -1,    -1,    90,
      -1,    -1,    -1,    94,    -1,    -1,    97,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   179,   180,    -1,    -1,   183,    -1,    -1,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
      -1,    -1,    -1,   201,    -1,   203,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,
      -1,    -1,   183,    -1,    -1,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,    -1,    -1,    -1,
     201,     1,   203,    -1,     4,     5,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    33,    34,    35,    36,    -1,    38,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,    -1,    -1,    -1,    -1,    -1,    58,    -1,
      -1,    -1,    62,    63,    -1,    65,    -1,    -1,     1,    -1,
      70,     4,     5,     6,    74,    75,    76,    -1,    -1,    79,
      80,    81,    -1,    83,    84,    85,    86,    -1,    -1,    -1,
      90,    -1,    -1,    -1,    94,    -1,    -1,    97,    31,    32,
      33,    34,    35,    36,    -1,    38,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,
      -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,    62,
      63,    -1,    65,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      73,    74,    75,    76,    -1,    -1,    79,    -1,    81,    -1,
      83,    84,    85,    86,    -1,    -1,    -1,    90,    -1,    -1,
      -1,    94,    -1,    -1,    97,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,
     180,    -1,    -1,   183,    -1,    -1,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,    -1,    -1,
      -1,   201,    -1,   203,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   179,   180,    -1,    -1,
     183,    -1,    -1,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,    -1,    -1,    -1,   201,     1,
     203,    -1,     4,     5,     6,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    33,    34,    35,    36,    -1,    38,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,
      62,    63,    -1,    65,    -1,    -1,     1,    -1,    70,     4,
       5,     6,    74,    75,    76,    -1,    78,    79,    -1,    81,
      -1,    83,    84,    85,    86,    -1,    -1,    -1,    90,    -1,
      -1,    -1,    94,    -1,    -1,    97,    31,    32,    33,    34,
      35,    36,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    -1,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    -1,    62,    63,    -1,
      65,    66,    -1,    -1,    -1,    70,    -1,    -1,    -1,    74,
      75,    76,    -1,    -1,    79,    -1,    81,    -1,    83,    84,
      85,    86,    -1,    -1,    -1,    90,    -1,    -1,    -1,    94,
      -1,    -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,    -1,
      -1,   183,    -1,    -1,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,    -1,    -1,    -1,   201,
      -1,   203,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   179,   180,    -1,    -1,   183,    -1,
      -1,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,    -1,    -1,    -1,   201,     1,   203,    -1,
       4,     5,     6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,    -1,    38,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    -1,
      -1,    -1,    -1,    -1,    58,    -1,    -1,    61,    62,    63,
      -1,    65,    -1,    -1,     1,    -1,    70,     4,     5,     6,
      74,    75,    76,    -1,    -1,    79,    -1,    81,    -1,    83,
      84,    85,    86,    -1,    -1,    -1,    90,    -1,    -1,    -1,
      94,    -1,    -1,    97,    31,    32,    33,    34,    35,    36,
      -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    52,    -1,    -1,    -1,    -1,
      -1,    58,    -1,    -1,    -1,    62,    63,    -1,    65,    66,
      -1,    -1,    -1,    70,    -1,    -1,    -1,    74,    75,    76,
      -1,    -1,    79,    -1,    81,    -1,    83,    84,    85,    86,
      -1,    -1,    -1,    90,    -1,    -1,    -1,    94,    -1,    -1,
      97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   179,   180,    -1,    -1,   183,
      -1,    -1,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,    -1,    -1,    -1,   201,    -1,   203,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   179,   180,    -1,    -1,   183,    -1,    -1,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,    -1,    -1,    -1,   201,     1,   203,    -1,     4,     5,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,
      36,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    -1,    -1,    -1,
      -1,    -1,    58,    -1,    -1,    -1,    62,    63,    -1,    65,
      66,    -1,     1,    -1,    70,     4,     5,     6,    74,    75,
      76,    -1,    -1,    79,    -1,    81,    -1,    83,    84,    85,
      86,    -1,    -1,    -1,    90,    -1,    -1,    -1,    94,    -1,
      -1,    97,    31,    32,    33,    34,    35,    36,    -1,    38,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,    -1,    -1,    -1,    -1,    -1,    58,
      -1,    -1,    -1,    62,    63,    -1,    65,    66,    -1,    -1,
      -1,    70,    -1,    -1,    -1,    74,    75,    76,    -1,    -1,
      79,    -1,    81,    -1,    83,    84,    85,    86,    -1,    -1,
      -1,    90,    -1,    -1,    -1,    94,    -1,    -1,    97,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   179,   180,    -1,    -1,   183,    -1,    -1,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,    -1,    -1,    -1,   201,    -1,   203,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     179,   180,    -1,    -1,   183,    -1,    -1,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,    -1,
      -1,    -1,   201,     1,   203,    -1,     4,     5,     6,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    -1,
      38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    -1,    -1,    -1,    -1,    -1,
      58,    -1,    -1,    -1,    62,    63,    -1,    65,    66,    -1,
       1,    -1,    70,     4,     5,     6,    74,    75,    76,    -1,
      -1,    79,    -1,    81,    -1,    83,    84,    85,    86,    -1,
      -1,    -1,    90,    -1,    -1,    -1,    94,    -1,    -1,    97,
      31,    32,    33,    34,    35,    36,    -1,    38,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    52,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,
      -1,    62,    63,    -1,    65,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    74,    75,    76,    -1,    -1,    79,    -1,
      81,    -1,    83,    84,    85,    86,    -1,    -1,    -1,    90,
      91,    -1,    -1,    94,    -1,    -1,    97,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   179,   180,    -1,    -1,   183,    -1,    -1,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
      -1,    -1,    -1,   201,    -1,   203,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   179,   180,
      -1,    -1,   183,    -1,    -1,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,    -1,    -1,    -1,
     201,     1,   203,    -1,     4,     5,     6,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    33,    34,    35,    36,    -1,    38,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,    -1,    -1,    -1,    -1,    -1,    58,    -1,
      -1,    -1,    62,    63,    -1,    65,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    74,    75,    76,    -1,    -1,    79,
      -1,    81,    -1,    83,    84,    85,    86,    -1,    -1,    -1,
      90,    91,    -1,    -1,    94,    -1,    -1,    97,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      54,    55,    56,    57,    -1,    -1,    -1,    -1,    -1,   179,
     180,    -1,    -1,   183,    -1,    -1,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,    82,    -1,
      -1,   201,    86,   203,    -1,    89,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,    -1,    -1,   183,
      21,    -1,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,    -1,    -1,    -1,    -1,    -1,   203,
     204,   205,   206,   207,    45,   209,    -1,    -1,    -1,   213,
      -1,    -1,    53,    54,    55,    56,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    82,    -1,    -1,    -1,    86,    -1,    -1,    89,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
      -1,    -1,   183,    21,    -1,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,    -1,    -1,    -1,
      -1,    -1,   203,   204,   205,   206,    -1,    45,   209,   210,
      -1,    -1,   213,    -1,    -1,    53,    54,    55,    56,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    82,    -1,    -1,    -1,    86,    -1,
      -1,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,    -1,    -1,   183,    21,    -1,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
      -1,    -1,    -1,    -1,    -1,   203,   204,   205,   206,    -1,
      45,   209,   210,    -1,    -1,   213,    -1,    -1,    53,    54,
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
     175,   176,   177,   178,   179,   180,    -1,    -1,   183,    21,
      -1,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,    -1,    -1,    -1,    -1,    -1,   203,   204,
     205,   206,    -1,    45,   209,   210,    -1,    -1,   213,    -1,
      -1,    53,    54,    55,    56,    57,    -1,    -1,    -1,    -1,
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
      -1,   183,    21,    -1,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,    -1,    -1,    -1,    -1,
      -1,   203,   204,   205,   206,    -1,    45,   209,    -1,    -1,
      -1,   213,    -1,    -1,    53,    54,    55,    56,    57,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    -1,    -1,    -1,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,    -1,    -1,   183,    21,    -1,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,    -1,
      -1,    -1,    -1,    -1,   203,   204,   205,   206,    -1,    45,
     209,    -1,    -1,    -1,   213,    -1,    -1,    53,    54,    55,
      56,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,    -1,    -1,
      86,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,    -1,    -1,   183,    -1,    -1,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,    -1,    -1,    -1,    -1,    -1,   203,   204,   205,
     206,    -1,    -1,   209
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,     3,   222,   223,   223,     0,     1,     4,     5,     6,
      31,    32,    33,    34,    35,    36,    38,    39,    50,    51,
      52,    58,    62,    63,    65,    70,    74,    75,    76,    79,
      81,    83,    84,    85,    86,    90,    94,    97,   179,   180,
     183,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   201,   203,   225,   226,   227,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   248,   249,   250,   251,   252,   253,   254,   255,   256,
     259,   263,   264,   265,   266,   267,   271,   272,   207,   203,
     179,   180,   183,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   202,   203,   282,   203,    21,
      45,    53,    54,    55,    56,    57,    82,    86,    89,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   183,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   203,   204,   205,
     206,   209,   213,   273,   274,   275,   276,   277,   278,   279,
     280,   281,   283,   203,   230,   282,   230,   273,   207,   282,
     209,   207,   273,   208,   273,   273,   273,   282,   207,   207,
     207,   207,   203,   282,   282,   282,   282,   203,   203,   203,
     282,   105,   209,   208,     7,     8,     9,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,   102,   179,   180,
     181,   182,   183,   184,   273,   277,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   206,   209,
     273,   281,   207,    88,    87,   208,   216,   217,   218,   219,
     220,   202,   212,   213,   214,   215,   105,   209,   208,   208,
     208,   207,   207,   282,   207,    53,   207,   207,   207,   208,
      71,   268,   269,   224,   207,   207,   207,   207,   207,    46,
     242,    11,    12,    13,    14,    48,   243,    99,   100,   101,
     189,   207,   202,   203,   273,   284,   285,   273,    10,   207,
     207,   207,   209,   209,   209,   209,   209,   190,   207,   191,
     207,   207,   207,   207,   209,   209,   209,   209,   209,   209,
     209,   207,   273,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   210,   210,   286,   286,   286,
     286,   286,   210,   210,   210,   286,   286,   286,   210,   286,
     210,   286,   210,   286,   273,   273,   273,   273,   286,   286,
     286,   286,   286,   286,   286,   273,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   273,
     273,   273,   273,   203,   210,   282,   282,   286,   273,   284,
     210,   275,   276,   278,   278,   278,   278,   278,   278,   278,
     279,   279,   280,   280,   203,   273,   273,   282,   273,   210,
     207,   224,   224,   224,   273,   273,    72,   269,   270,    77,
     225,   224,   207,   209,   209,   209,   209,   209,    49,   207,
     100,   189,   207,   209,   209,   209,   257,   273,   210,   210,
     211,   207,   209,   204,   204,   204,   204,   204,   209,   209,
     203,   204,   204,   204,   204,   204,   185,   210,   211,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   211,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   211,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   207,   207,   207,   282,   260,
      64,    64,    67,    68,   207,   207,    73,   207,    80,    92,
     204,   204,   204,   204,   206,   209,   246,   209,   209,   257,
     204,   203,   203,    98,   103,   203,   258,   207,   105,   207,
     273,   214,   210,   210,   210,   211,   211,   203,   203,   210,
     210,   210,   210,   210,   210,   211,   273,   273,    22,    23,
      24,    25,    26,    27,   207,    59,    60,   261,   262,   207,
     207,   273,   273,   224,   224,   207,   224,   207,   203,   243,
     210,   210,   210,   211,   210,   206,    95,   104,   203,   247,
     204,   203,    98,   210,   210,   210,   211,   207,   203,    11,
      12,    13,    14,   224,   203,   211,    29,    30,    40,    41,
      42,    46,    47,   100,   228,    30,    46,   100,   228,    29,
      30,    42,    46,   100,   228,   204,   204,   210,   210,   207,
     228,   228,   228,   228,   228,   206,   211,   210,   210,   210,
     210,   210,   210,   273,   207,    61,    69,   207,    69,   207,
      78,   243,   207,   204,   207,   210,   207,   203,    11,    12,
      13,    14,   101,   210,   210,   211,   207,    99,   100,   207,
     207,   204,    11,    12,    13,    14,   209,   209,   209,   209,
      66,   214,    30,   209,   209,    30,   209,   207,   209,   209,
     207,    30,   209,   209,    30,   209,   207,   210,   210,   207,
     207,   207,   207,   207,   207,   207,   210,    22,    23,    24,
      25,    26,    27,   207,   224,   207,   273,   224,   273,   224,
     207,   207,   244,   210,   246,   207,    11,    12,    13,    14,
     209,   209,   209,   209,   209,   207,   207,   204,   207,   209,
     257,   210,   209,   209,   209,   209,   204,   204,   204,   204,
     207,   210,   209,   273,   203,   209,   204,   273,   204,   209,
     273,   203,   209,   204,    29,    30,   100,   228,   228,   207,
     210,   210,   210,   210,   210,   210,   224,   207,    66,   207,
      66,   244,    93,   104,   203,   245,    95,   246,   209,   209,
     209,   209,   204,   204,   204,   204,   203,   257,   257,   210,
     257,   204,    98,    99,   204,   204,   204,   204,   210,   210,
     210,   211,   207,   273,   210,   210,   273,   210,   210,   210,
     273,   210,   210,   273,   210,    30,   209,   209,   207,   207,
     224,   207,   224,   207,    93,   207,   203,    11,    12,    13,
      14,   101,   207,    95,   204,   204,   204,   204,   210,   210,
     210,   211,   210,    98,    98,   207,    98,   210,   207,   207,
     210,   210,   210,   211,   187,   188,   207,   207,   187,   188,
     207,   204,   210,   207,   207,   210,   195,   196,   207,   207,
     207,   210,   207,   207,   210,   195,   196,   207,   209,   273,
     204,    66,    66,   207,   224,    11,    12,    13,    14,   209,
     209,   209,   209,   209,   207,   210,   210,   210,   211,    43,
      96,   207,    43,    96,   207,    43,    96,   207,   204,   207,
     207,   207,   257,   207,   207,   257,   207,   207,   207,   204,
     209,   209,   209,   209,   210,   207,   207,   207,   207,   207,
     207,   207,   207,   273,   210,   210,   207,   207,   224,    37,
      91,   209,   209,   209,   209,   204,   204,   204,   204,   203,
      96,   207,    96,   207,    96,   207,   204,   209,    43,   207,
     209,    43,   207,   209,    43,   207,   210,    98,    98,   210,
     203,   204,   203,   204,   188,   207,   210,   207,   207,    37,
      91,   207,   207,   204,   204,   204,   204,   210,   210,   210,
     211,   210,   207,   207,   207,   210,    44,    45,   209,    44,
      45,   209,    44,    45,   209,    43,    96,   207,   207,   207,
     207,   210,   211,   210,   210,   211,   210,   209,   207,   207,
     207,   224,   210,   210,   210,   211,    43,    96,   207,    43,
      96,   207,    43,    96,   207,   204,   207,    96,   207,   211,
     210,    44,   211,   210,    44,   211,   210,    44,   209,    43,
     207,   207,   204,   207,   207,   204,   207,   204,   224,    91,
      96,   207,    96,   207,    96,   207,   204,   209,    43,   207,
     209,    43,   207,   209,    43,   207,   210,   207,    45,   207,
     210,    45,   207,   210,    45,   207,   210,    45,   209,   210,
     210,   210,    91,   207,   207,   207,   207,   210,    44,    45,
     209,    44,    45,   209,    44,    45,   209,    43,    96,   207,
     210,   207,   210,   207,   210,   207,   210,    44,   207,   207,
     207,   207,    96,   207,   211,   210,    44,   211,   210,    44,
     211,   210,    44,   209,    43,   207,   207,   207,   207,   207,
     210,   207,    45,   207,   210,    45,   207,   210,    45,   207,
     210,    45,   209,   207,   210,   207,   210,   207,   210,   207,
     210,    44,   207,   207,   207,   207,   210,   207
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
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   231,
     231,   232,   233,   234,   235,   236,   237,   238,   238,   239,
     240,   240,   240,   241,   241,   241,   241,   242,   242,   243,
     243,   243,   243,   243,   244,   244,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   246,   246,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   256,   256,   256,   256,   256,   256,   256,
     256,   256,   257,   257,   258,   258,   258,   258,   258,   258,
     258,   258,   258,   258,   258,   258,   258,   258,   258,   259,
     260,   260,   261,   262,   262,   263,   264,   265,   265,   265,
     265,   266,   267,   268,   268,   269,   270,   270,   271,   272,
     273,   274,   274,   275,   275,   276,   276,   277,   277,   277,
     277,   277,   277,   277,   277,   278,   278,   278,   279,   279,
     279,   280,   280,   281,   281,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   283,   283,   283,   283,   283,   283,   283,   283,
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
     283,   283,   283,   283,   283,   283,   283,   283,   283,   284,
     284,   285,   285,   286,   286
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
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     4,     6,     4,
       5,     5,     5,     3,     2,     3,     4,     3,     2,     5,
       7,    11,    10,    13,    14,    16,    17,     0,     1,     0,
       4,     4,     4,     6,     0,     2,     6,     7,     6,     7,
       6,     7,     8,     9,     7,     8,     7,     8,     7,     8,
       9,    10,     6,    11,    11,    11,    13,    10,    10,    10,
      12,    12,    12,    12,     0,     2,     6,     7,     6,     7,
       6,     7,     8,     9,     7,     8,     7,     8,     7,     8,
       9,    10,     6,    11,    11,    11,    13,    10,    10,    10,
      12,    12,    12,    12,     8,     6,     3,     3,     3,     3,
       3,     6,     7,     6,    11,    11,     7,    11,    11,    13,
      13,    10,     0,     2,     6,     6,     6,     8,     7,     7,
       7,     9,    10,    10,    12,    10,    12,    10,    12,     8,
       0,     2,     4,     0,     3,     6,     6,    10,    12,    10,
      12,     8,     6,     1,     2,     4,     0,     3,     2,     2,
       1,     1,     3,     1,     3,     1,     2,     1,     3,     3,
       3,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     1,     2,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     3,     4,     4,     4,     4,     4,
       4,     4,     4,     6,     6,     6,     6,     6,     6,     4,
       4,     4,     4,     3,     3,     4,     4,     4,     4,     4,
       4,     3,     4,     3,     4,     3,     8,     8,     8,     4,
       4,     4,     3,     3,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       3,     1,     8,     8,     8,     2,     4,     4,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     0,
       1,     1,     3,     1,     3
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
#line 2883 "build/parser.cpp"
    break;

  case 3: /* program: statements_opt  */
#line 187 "src/parser.y"
                     {
        (yyval.program) = g_program;
    }
#line 2891 "build/parser.cpp"
    break;

  case 5: /* statements_opt: statements_opt statement  */
#line 194 "src/parser.y"
                               {
        if ((yyvsp[0].stmt)) {
            g_program->statements.emplace_back((yyvsp[0].stmt));
        }
    }
#line 2901 "build/parser.cpp"
    break;

  case 6: /* statements_opt: statements_opt KW_CTLOPT  */
#line 199 "src/parser.y"
                               {
        if (ctlopt_nomain) g_program->nomain = true;
        if (ctlopt_main_proc[0]) g_program->main_proc = ctlopt_main_proc;
        if (ctlopt_datfmt[0]) g_program->datfmt = ctlopt_datfmt;
        if (ctlopt_timfmt[0]) g_program->timfmt = ctlopt_timfmt;
    }
#line 2912 "build/parser.cpp"
    break;

  case 7: /* statement_list: %empty  */
#line 208 "src/parser.y"
                {
        (yyval.stmt_list) = new StmtList();
    }
#line 2920 "build/parser.cpp"
    break;

  case 8: /* statement_list: statement_list statement  */
#line 211 "src/parser.y"
                               {
        (yyval.stmt_list) = (yyvsp[-1].stmt_list);
        if ((yyvsp[0].stmt)) {
            (yyval.stmt_list)->stmts.push_back((yyvsp[0].stmt));
        }
    }
#line 2931 "build/parser.cpp"
    break;

  case 9: /* statement: dcl_f_stmt  */
#line 220 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2937 "build/parser.cpp"
    break;

  case 10: /* statement: dcl_s_stmt  */
#line 221 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2943 "build/parser.cpp"
    break;

  case 11: /* statement: dcl_c_stmt  */
#line 222 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2949 "build/parser.cpp"
    break;

  case 12: /* statement: eval_stmt  */
#line 223 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2955 "build/parser.cpp"
    break;

  case 13: /* statement: eval_corr_stmt  */
#line 224 "src/parser.y"
                     { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2961 "build/parser.cpp"
    break;

  case 14: /* statement: dsply_stmt  */
#line 225 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2967 "build/parser.cpp"
    break;

  case 15: /* statement: inlr_stmt  */
#line 226 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2973 "build/parser.cpp"
    break;

  case 16: /* statement: return_stmt  */
#line 227 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2979 "build/parser.cpp"
    break;

  case 17: /* statement: if_stmt  */
#line 228 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2985 "build/parser.cpp"
    break;

  case 18: /* statement: dow_stmt  */
#line 229 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2991 "build/parser.cpp"
    break;

  case 19: /* statement: dou_stmt  */
#line 230 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2997 "build/parser.cpp"
    break;

  case 20: /* statement: for_stmt  */
#line 231 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3003 "build/parser.cpp"
    break;

  case 21: /* statement: for_each_stmt  */
#line 232 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3009 "build/parser.cpp"
    break;

  case 22: /* statement: select_stmt  */
#line 233 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3015 "build/parser.cpp"
    break;

  case 23: /* statement: iter_stmt  */
#line 234 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3021 "build/parser.cpp"
    break;

  case 24: /* statement: leave_stmt  */
#line 235 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3027 "build/parser.cpp"
    break;

  case 25: /* statement: dcl_proc_stmt  */
#line 236 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3033 "build/parser.cpp"
    break;

  case 26: /* statement: dcl_pr_stmt  */
#line 237 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3039 "build/parser.cpp"
    break;

  case 27: /* statement: dcl_ds_stmt  */
#line 238 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3045 "build/parser.cpp"
    break;

  case 28: /* statement: monitor_stmt  */
#line 239 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3051 "build/parser.cpp"
    break;

  case 29: /* statement: begsr_stmt  */
#line 240 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3057 "build/parser.cpp"
    break;

  case 30: /* statement: exsr_stmt  */
#line 241 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3063 "build/parser.cpp"
    break;

  case 31: /* statement: reset_stmt  */
#line 242 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3069 "build/parser.cpp"
    break;

  case 32: /* statement: clear_stmt  */
#line 243 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3075 "build/parser.cpp"
    break;

  case 33: /* statement: sorta_stmt  */
#line 244 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3081 "build/parser.cpp"
    break;

  case 34: /* statement: evalr_stmt  */
#line 245 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3087 "build/parser.cpp"
    break;

  case 35: /* statement: callp_stmt  */
#line 246 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3093 "build/parser.cpp"
    break;

  case 36: /* statement: leavesr_stmt  */
#line 247 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3099 "build/parser.cpp"
    break;

  case 37: /* statement: dealloc_stmt  */
#line 248 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3105 "build/parser.cpp"
    break;

  case 38: /* statement: test_stmt  */
#line 249 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3111 "build/parser.cpp"
    break;

  case 39: /* statement: expr_stmt  */
#line 250 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3117 "build/parser.cpp"
    break;

  case 40: /* statement: error SEMICOLON  */
#line 251 "src/parser.y"
                      { (yyval.stmt) = nullptr; yyerrok; }
#line 3123 "build/parser.cpp"
    break;

  case 41: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_DISK SEMICOLON  */
#line 256 "src/parser.y"
                                          {
        (yyval.stmt) = new rpg::DclF((yyvsp[-2].sval), "DISK");
        free((yyvsp[-2].sval));
    }
#line 3132 "build/parser.cpp"
    break;

  case 42: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_PRINTER SEMICOLON  */
#line 260 "src/parser.y"
                                               {
        (yyval.stmt) = new rpg::DclF((yyvsp[-2].sval), "PRINTER");
        free((yyvsp[-2].sval));
    }
#line 3141 "build/parser.cpp"
    break;

  case 43: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_WORKSTN SEMICOLON  */
#line 264 "src/parser.y"
                                               {
        (yyval.stmt) = new rpg::DclF((yyvsp[-2].sval), "WORKSTN");
        free((yyvsp[-2].sval));
    }
#line 3150 "build/parser.cpp"
    break;

  case 44: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_DISK KW_USAGE LPAREN STAR COLON STAR RPAREN SEMICOLON  */
#line 268 "src/parser.y"
                                                                                   {
        (yyval.stmt) = new rpg::DclF((yyvsp[-8].sval), "DISK");
        free((yyvsp[-8].sval));
    }
#line 3159 "build/parser.cpp"
    break;

  case 45: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 276 "src/parser.y"
                                                                                  {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3169 "build/parser.cpp"
    break;

  case 46: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 281 "src/parser.y"
                                                                                       {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3179 "build/parser.cpp"
    break;

  case 47: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 286 "src/parser.y"
                                                                                   {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::INT10, 0);
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3189 "build/parser.cpp"
    break;

  case 48: /* dcl_s_stmt: KW_DCL_S ident KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 291 "src/parser.y"
                                                                                                            {
        auto* n = new rpg::DclS((yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-8].sval));
    }
#line 3199 "build/parser.cpp"
    break;

  case 49: /* dcl_s_stmt: KW_DCL_S ident KW_ZONED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 296 "src/parser.y"
                                                                                                           {
        auto* n = new rpg::DclS((yyvsp[-8].sval), rpg::RPGType::ZONED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-8].sval));
    }
#line 3209 "build/parser.cpp"
    break;

  case 50: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_CONST KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 301 "src/parser.y"
                                                                                                             {
        (yyval.stmt) = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, true,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-10].sval));
    }
#line 3219 "build/parser.cpp"
    break;

  case 51: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_CONST KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 306 "src/parser.y"
                                                                                                              {
        (yyval.stmt) = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, true,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-10].sval));
    }
#line 3229 "build/parser.cpp"
    break;

  case 52: /* dcl_s_stmt: KW_DCL_S ident KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_CONST KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 311 "src/parser.y"
                                                                                                                                      {
        (yyval.stmt) = new rpg::DclS((yyvsp[-12].sval), rpg::RPGType::PACKED, 0, (yyvsp[-9].ival), (yyvsp[-7].ival), true,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-12].sval));
    }
#line 3239 "build/parser.cpp"
    break;

  case 53: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 316 "src/parser.y"
                                                                                                    {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-9].sval));
    }
#line 3249 "build/parser.cpp"
    break;

  case 54: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 321 "src/parser.y"
                                                                                                     {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-9].sval));
    }
#line 3259 "build/parser.cpp"
    break;

  case 55: /* dcl_s_stmt: KW_DCL_S ident KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 326 "src/parser.y"
                                                                                                                             {
        (yyval.stmt) = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-11].sval));
    }
#line 3269 "build/parser.cpp"
    break;

  case 56: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 331 "src/parser.y"
                                                                                                        {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-9].sval));
    }
#line 3279 "build/parser.cpp"
    break;

  case 57: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_EXPORT KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 337 "src/parser.y"
                                                                                                              {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        n->is_export = true;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3290 "build/parser.cpp"
    break;

  case 58: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_EXPORT KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 343 "src/parser.y"
                                                                                                               {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        n->is_export = true;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3301 "build/parser.cpp"
    break;

  case 59: /* dcl_s_stmt: KW_DCL_S ident KW_IND SEMICOLON  */
#line 349 "src/parser.y"
                                      {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::IND, 0);
        free((yyvsp[-2].sval));
    }
#line 3310 "build/parser.cpp"
    break;

  case 60: /* dcl_s_stmt: KW_DCL_S ident KW_DATE SEMICOLON  */
#line 353 "src/parser.y"
                                       {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::DATE, 0);
        free((yyvsp[-2].sval));
    }
#line 3319 "build/parser.cpp"
    break;

  case 61: /* dcl_s_stmt: KW_DCL_S ident KW_TIME SEMICOLON  */
#line 357 "src/parser.y"
                                       {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::TIME, 0);
        free((yyvsp[-2].sval));
    }
#line 3328 "build/parser.cpp"
    break;

  case 62: /* dcl_s_stmt: KW_DCL_S ident KW_TIMESTAMP SEMICOLON  */
#line 361 "src/parser.y"
                                            {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::TIMESTAMP, 0);
        free((yyvsp[-2].sval));
    }
#line 3337 "build/parser.cpp"
    break;

  case 63: /* dcl_s_stmt: KW_DCL_S ident KW_POINTER SEMICOLON  */
#line 365 "src/parser.y"
                                          {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::POINTER, 0);
        free((yyvsp[-2].sval));
    }
#line 3346 "build/parser.cpp"
    break;

  case 64: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 369 "src/parser.y"
                                                                                                         {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-9].sval));
    }
#line 3355 "build/parser.cpp"
    break;

  case 65: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 373 "src/parser.y"
                                                                                                          {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-9].sval));
    }
#line 3364 "build/parser.cpp"
    break;

  case 66: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 377 "src/parser.y"
                                                                                                             {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-9].sval));
    }
#line 3373 "build/parser.cpp"
    break;

  case 67: /* dcl_s_stmt: KW_DCL_S ident KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 381 "src/parser.y"
                                                                                                                                  {
        (yyval.stmt) = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-11].sval));
    }
#line 3382 "build/parser.cpp"
    break;

  case 68: /* dcl_s_stmt: KW_DCL_S ident KW_LIKE LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 385 "src/parser.y"
                                                                {
        auto* node = new rpg::DclS((yyvsp[-5].sval), rpg::RPGType::INT10, 0);
        node->like_var = (yyvsp[-2].sval);
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
        (yyval.stmt) = node;
    }
#line 3394 "build/parser.cpp"
    break;

  case 69: /* dcl_s_stmt: KW_DCL_S ident KW_UNS LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 392 "src/parser.y"
                                                                                   {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::UNS, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3404 "build/parser.cpp"
    break;

  case 70: /* dcl_s_stmt: KW_DCL_S ident KW_FLOAT_TYPE LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 397 "src/parser.y"
                                                                                          {
        auto type = ((yyvsp[-3].ival) <= 4) ? rpg::RPGType::FLOAT4 : rpg::RPGType::FLOAT8;
        auto* n = new rpg::DclS((yyvsp[-6].sval), type, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3415 "build/parser.cpp"
    break;

  case 71: /* dcl_s_stmt: KW_DCL_S ident KW_BINDEC LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 403 "src/parser.y"
                                                                                      {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::BINDEC, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3425 "build/parser.cpp"
    break;

  case 72: /* dcl_s_stmt: KW_DCL_S ident KW_UCS2 LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 408 "src/parser.y"
                                                                                    {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::UCS2, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3435 "build/parser.cpp"
    break;

  case 73: /* dcl_s_stmt: KW_DCL_S ident KW_GRAPH LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 413 "src/parser.y"
                                                                                     {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::UCS2, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3445 "build/parser.cpp"
    break;

  case 74: /* dcl_s_stmt: KW_DCL_S ident KW_OBJECT LPAREN KW_JAVA COLON STRING_LITERAL RPAREN SEMICOLON  */
#line 418 "src/parser.y"
                                                                                    {
        auto* n = new rpg::DclS((yyvsp[-7].sval), rpg::RPGType::OBJECT, 0);
        n->java_class = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-7].sval)); free((yyvsp[-2].sval));
    }
#line 3455 "build/parser.cpp"
    break;

  case 75: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_BASED LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 423 "src/parser.y"
                                                                                                      {
        auto* n = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::INT10, 0);
        n->based_ptr = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
    }
#line 3465 "build/parser.cpp"
    break;

  case 76: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_BASED LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 428 "src/parser.y"
                                                                                                       {
        auto* n = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival));
        n->based_ptr = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
    }
#line 3475 "build/parser.cpp"
    break;

  case 77: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_ASCEND SEMICOLON  */
#line 433 "src/parser.y"
                                                                                                                   {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = 1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3485 "build/parser.cpp"
    break;

  case 78: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_DESCEND SEMICOLON  */
#line 438 "src/parser.y"
                                                                                                                    {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = -1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3495 "build/parser.cpp"
    break;

  case 79: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_ASCEND SEMICOLON  */
#line 443 "src/parser.y"
                                                                                                                    {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = 1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3505 "build/parser.cpp"
    break;

  case 80: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_DESCEND SEMICOLON  */
#line 448 "src/parser.y"
                                                                                                                     {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = -1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3515 "build/parser.cpp"
    break;

  case 81: /* dcl_s_stmt: KW_DCL_S ident KW_DATE KW_DATFMT LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 453 "src/parser.y"
                                                                          {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::DATE, 0);
        n->datfmt = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-6].sval)); free((yyvsp[-2].sval));
    }
#line 3525 "build/parser.cpp"
    break;

  case 82: /* dcl_s_stmt: KW_DCL_S ident KW_TIME KW_TIMFMT LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 458 "src/parser.y"
                                                                          {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::TIME, 0);
        n->timfmt = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-6].sval)); free((yyvsp[-2].sval));
    }
#line 3535 "build/parser.cpp"
    break;

  case 83: /* dcl_s_keywords: %empty  */
#line 466 "src/parser.y"
                  { (yyval.ival) = 0; }
#line 3541 "build/parser.cpp"
    break;

  case 84: /* dcl_s_keywords: KW_STATIC  */
#line 467 "src/parser.y"
                  { (yyval.ival) = 1; }
#line 3547 "build/parser.cpp"
    break;

  case 85: /* dcl_s_keywords: KW_TEMPLATE  */
#line 468 "src/parser.y"
                  { (yyval.ival) = 2; }
#line 3553 "build/parser.cpp"
    break;

  case 86: /* dcl_s_keywords: KW_EXPORT  */
#line 469 "src/parser.y"
                  { (yyval.ival) = 4; }
#line 3559 "build/parser.cpp"
    break;

  case 87: /* dcl_s_keywords: KW_IMPORT  */
#line 470 "src/parser.y"
                  { (yyval.ival) = 8; }
#line 3565 "build/parser.cpp"
    break;

  case 88: /* dcl_c_stmt: KW_DCL_C IDENTIFIER expression SEMICOLON  */
#line 475 "src/parser.y"
                                             {
        (yyval.stmt) = new rpg::DclC((yyvsp[-2].sval), std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
        free((yyvsp[-2].sval));
    }
#line 3574 "build/parser.cpp"
    break;

  case 89: /* eval_target: IDENTIFIER  */
#line 482 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier((yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 3583 "build/parser.cpp"
    break;

  case 90: /* eval_target: KW_POS  */
#line 486 "src/parser.y"
             { (yyval.expr) = new rpg::Identifier("POS"); }
#line 3589 "build/parser.cpp"
    break;

  case 91: /* eval_target: KW_OVERLAY  */
#line 487 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("OVERLAY"); }
#line 3595 "build/parser.cpp"
    break;

  case 92: /* eval_target: KW_PREFIX  */
#line 488 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("PREFIX"); }
#line 3601 "build/parser.cpp"
    break;

  case 93: /* eval_target: KW_UNS  */
#line 489 "src/parser.y"
             { (yyval.expr) = new rpg::Identifier("UNS"); }
#line 3607 "build/parser.cpp"
    break;

  case 94: /* eval_target: KW_FLOAT_TYPE  */
#line 490 "src/parser.y"
                    { (yyval.expr) = new rpg::Identifier("FLOAT"); }
#line 3613 "build/parser.cpp"
    break;

  case 95: /* eval_target: KW_GRAPH  */
#line 491 "src/parser.y"
               { (yyval.expr) = new rpg::Identifier("GRAPH"); }
#line 3619 "build/parser.cpp"
    break;

  case 96: /* eval_target: KW_OCCURS  */
#line 492 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("OCCURS"); }
#line 3625 "build/parser.cpp"
    break;

  case 97: /* eval_target: KW_ASCEND  */
#line 493 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("ASCEND"); }
#line 3631 "build/parser.cpp"
    break;

  case 98: /* eval_target: KW_DESCEND  */
#line 494 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("DESCEND"); }
#line 3637 "build/parser.cpp"
    break;

  case 99: /* eval_target: KW_RTNPARM  */
#line 495 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("RTNPARM"); }
#line 3643 "build/parser.cpp"
    break;

  case 100: /* eval_target: KW_OPDESC  */
#line 496 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("OPDESC"); }
#line 3649 "build/parser.cpp"
    break;

  case 101: /* eval_target: KW_NULLIND  */
#line 497 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("NULLIND"); }
#line 3655 "build/parser.cpp"
    break;

  case 102: /* eval_target: KW_DATFMT  */
#line 498 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("DATFMT"); }
#line 3661 "build/parser.cpp"
    break;

  case 103: /* eval_target: KW_TIMFMT  */
#line 499 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("TIMFMT"); }
#line 3667 "build/parser.cpp"
    break;

  case 104: /* eval_target: KW_EXTNAME  */
#line 500 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("EXTNAME"); }
#line 3673 "build/parser.cpp"
    break;

  case 105: /* eval_target: INDICATOR  */
#line 501 "src/parser.y"
                {
        (yyval.expr) = new rpg::IndicatorExpr((yyvsp[0].ival));
    }
#line 3681 "build/parser.cpp"
    break;

  case 106: /* eval_target: IDENTIFIER DOT IDENTIFIER  */
#line 504 "src/parser.y"
                                {
        auto obj = std::unique_ptr<rpg::Expression>(new rpg::Identifier((yyvsp[-2].sval)));
        (yyval.expr) = new rpg::DotExpr(std::move(obj), (yyvsp[0].sval));
        free((yyvsp[-2].sval));
        free((yyvsp[0].sval));
    }
#line 3692 "build/parser.cpp"
    break;

  case 107: /* eval_target: IDENTIFIER LPAREN expression RPAREN  */
#line 510 "src/parser.y"
                                          {
        (yyval.expr) = new rpg::ArrayAccess((yyvsp[-3].sval), std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
        free((yyvsp[-3].sval));
    }
#line 3701 "build/parser.cpp"
    break;

  case 108: /* eval_target: IDENTIFIER LPAREN expression RPAREN DOT IDENTIFIER  */
#line 514 "src/parser.y"
                                                         {
        auto* arr = new rpg::ArrayAccess((yyvsp[-5].sval), std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)));
        (yyval.expr) = new rpg::DotExpr(std::unique_ptr<rpg::Expression>(arr), (yyvsp[0].sval));
        free((yyvsp[-5].sval));
        free((yyvsp[0].sval));
    }
#line 3712 "build/parser.cpp"
    break;

  case 109: /* eval_stmt: eval_target EQUALS expression SEMICOLON  */
#line 523 "src/parser.y"
                                            {
        (yyval.stmt) = new rpg::EvalStmt(
            std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-1].expr))
        );
    }
#line 3723 "build/parser.cpp"
    break;

  case 110: /* eval_stmt: KW_EVAL eval_target EQUALS expression SEMICOLON  */
#line 529 "src/parser.y"
                                                      {
        (yyval.stmt) = new rpg::EvalStmt(
            std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-1].expr))
        );
    }
#line 3734 "build/parser.cpp"
    break;

  case 111: /* eval_corr_stmt: KW_EVAL_CORR ident EQUALS ident SEMICOLON  */
#line 538 "src/parser.y"
                                              {
        (yyval.stmt) = new rpg::EvalCorrStmt(std::string((yyvsp[-3].sval)), std::string((yyvsp[-1].sval)));
        free((yyvsp[-3].sval));
        free((yyvsp[-1].sval));
    }
#line 3744 "build/parser.cpp"
    break;

  case 112: /* evalr_stmt: KW_EVALR eval_target EQUALS expression SEMICOLON  */
#line 546 "src/parser.y"
                                                     {
        (yyval.stmt) = new rpg::EvalRStmt(
            std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-1].expr))
        );
    }
#line 3755 "build/parser.cpp"
    break;

  case 113: /* callp_stmt: KW_CALLP expression SEMICOLON  */
#line 555 "src/parser.y"
                                  {
        (yyval.stmt) = new rpg::ExprStmt(std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
    }
#line 3763 "build/parser.cpp"
    break;

  case 114: /* leavesr_stmt: KW_LEAVESR SEMICOLON  */
#line 561 "src/parser.y"
                         {
        (yyval.stmt) = new rpg::LeaveSRStmt();
    }
#line 3771 "build/parser.cpp"
    break;

  case 115: /* dsply_stmt: KW_DSPLY expression SEMICOLON  */
#line 567 "src/parser.y"
                                  {
        (yyval.stmt) = new rpg::DsplyStmt(std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
    }
#line 3779 "build/parser.cpp"
    break;

  case 116: /* inlr_stmt: KW_INLR EQUALS KW_ON SEMICOLON  */
#line 573 "src/parser.y"
                                   {
        (yyval.stmt) = new rpg::ReturnStmt(0);
    }
#line 3787 "build/parser.cpp"
    break;

  case 117: /* return_stmt: KW_RETURN expression SEMICOLON  */
#line 579 "src/parser.y"
                                   {
        (yyval.stmt) = new rpg::ReturnStmt(std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
    }
#line 3795 "build/parser.cpp"
    break;

  case 118: /* return_stmt: KW_RETURN SEMICOLON  */
#line 582 "src/parser.y"
                          {
        (yyval.stmt) = new rpg::ReturnStmt(0);
    }
#line 3803 "build/parser.cpp"
    break;

  case 119: /* expr_stmt: IDENTIFIER LPAREN call_args_opt RPAREN SEMICOLON  */
#line 589 "src/parser.y"
                                                     {
        auto* fc = make_func((yyvsp[-4].sval), (yyvsp[-2].expr_list));
        free((yyvsp[-4].sval));
        (yyval.stmt) = new rpg::ExprStmt(std::unique_ptr<rpg::Expression>(fc));
    }
#line 3813 "build/parser.cpp"
    break;

  case 120: /* dcl_pr_stmt: KW_DCL_PR IDENTIFIER pi_return_type SEMICOLON pr_params KW_END_PR SEMICOLON  */
#line 600 "src/parser.y"
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
#line 3834 "build/parser.cpp"
    break;

  case 121: /* dcl_pr_stmt: KW_DCL_PR IDENTIFIER pi_return_type KW_EXTPROC LPAREN STRING_LITERAL RPAREN SEMICOLON pr_params KW_END_PR SEMICOLON  */
#line 617 "src/parser.y"
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
#line 3858 "build/parser.cpp"
    break;

  case 122: /* dcl_pr_stmt: KW_DCL_PR IDENTIFIER KW_EXTPGM LPAREN STRING_LITERAL RPAREN SEMICOLON pr_params KW_END_PR SEMICOLON  */
#line 637 "src/parser.y"
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
#line 3874 "build/parser.cpp"
    break;

  case 123: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER proc_export SEMICOLON KW_DCL_PI pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 655 "src/parser.y"
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
#line 3899 "build/parser.cpp"
    break;

  case 124: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER proc_export SEMICOLON KW_DCL_PI IDENTIFIER pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 679 "src/parser.y"
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
#line 3925 "build/parser.cpp"
    break;

  case 125: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER proc_export SEMICOLON KW_DCL_PI pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_ON_EXIT SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 705 "src/parser.y"
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
#line 3952 "build/parser.cpp"
    break;

  case 126: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER proc_export SEMICOLON KW_DCL_PI IDENTIFIER pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_ON_EXIT SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 732 "src/parser.y"
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
#line 3980 "build/parser.cpp"
    break;

  case 127: /* proc_export: %empty  */
#line 758 "src/parser.y"
                { (yyval.ival) = 0; }
#line 3986 "build/parser.cpp"
    break;

  case 128: /* proc_export: KW_EXPORT  */
#line 759 "src/parser.y"
                { (yyval.ival) = 1; }
#line 3992 "build/parser.cpp"
    break;

  case 129: /* pi_return_type: %empty  */
#line 764 "src/parser.y"
               { (yyval.ival) = -1; }
#line 3998 "build/parser.cpp"
    break;

  case 130: /* pi_return_type: KW_INT LPAREN INTEGER_LITERAL RPAREN  */
#line 765 "src/parser.y"
                                           { (yyval.ival) = (int)rpg::RPGType::INT10; }
#line 4004 "build/parser.cpp"
    break;

  case 131: /* pi_return_type: KW_CHAR LPAREN INTEGER_LITERAL RPAREN  */
#line 766 "src/parser.y"
                                            { (yyval.ival) = (int)rpg::RPGType::CHAR; }
#line 4010 "build/parser.cpp"
    break;

  case 132: /* pi_return_type: KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN  */
#line 767 "src/parser.y"
                                               { (yyval.ival) = (int)rpg::RPGType::VARCHAR; }
#line 4016 "build/parser.cpp"
    break;

  case 133: /* pi_return_type: KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN  */
#line 768 "src/parser.y"
                                                                    { (yyval.ival) = (int)rpg::RPGType::PACKED; }
#line 4022 "build/parser.cpp"
    break;

  case 134: /* pi_params: %empty  */
#line 773 "src/parser.y"
                {
        (yyval.param_list) = new ParamList();
    }
#line 4030 "build/parser.cpp"
    break;

  case 135: /* pi_params: pi_params pi_param  */
#line 776 "src/parser.y"
                         {
        (yyval.param_list) = (yyvsp[-1].param_list);
        (yyval.param_list)->params.push_back(*(yyvsp[0].param_decl));
        delete (yyvsp[0].param_decl);
    }
#line 4040 "build/parser.cpp"
    break;

  case 136: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 784 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4049 "build/parser.cpp"
    break;

  case 137: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 788 "src/parser.y"
                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4058 "build/parser.cpp"
    break;

  case 138: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 792 "src/parser.y"
                                                                 {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4067 "build/parser.cpp"
    break;

  case 139: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 796 "src/parser.y"
                                                                          {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4076 "build/parser.cpp"
    break;

  case 140: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 800 "src/parser.y"
                                                                    {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4085 "build/parser.cpp"
    break;

  case 141: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 804 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4094 "build/parser.cpp"
    break;

  case 142: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 808 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 4103 "build/parser.cpp"
    break;

  case 143: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 812 "src/parser.y"
                                                                                                  {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 4112 "build/parser.cpp"
    break;

  case 144: /* pi_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 817 "src/parser.y"
                                                                            {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4121 "build/parser.cpp"
    break;

  case 145: /* pi_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 821 "src/parser.y"
                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4130 "build/parser.cpp"
    break;

  case 146: /* pi_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 825 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4139 "build/parser.cpp"
    break;

  case 147: /* pi_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 829 "src/parser.y"
                                                                                      {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4148 "build/parser.cpp"
    break;

  case 148: /* pi_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 833 "src/parser.y"
                                                                                {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4157 "build/parser.cpp"
    break;

  case 149: /* pi_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 837 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4166 "build/parser.cpp"
    break;

  case 150: /* pi_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 841 "src/parser.y"
                                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 4175 "build/parser.cpp"
    break;

  case 151: /* pi_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 845 "src/parser.y"
                                                                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 4184 "build/parser.cpp"
    break;

  case 152: /* pi_param: IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 849 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, 0, 0, 0, false, std::string((yyvsp[-2].sval))};
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
    }
#line 4194 "build/parser.cpp"
    break;

  case 153: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 855 "src/parser.y"
                                                                                                            {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4204 "build/parser.cpp"
    break;

  case 154: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 860 "src/parser.y"
                                                                                                             {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4214 "build/parser.cpp"
    break;

  case 155: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 865 "src/parser.y"
                                                                                                                {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::VARCHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4224 "build/parser.cpp"
    break;

  case 156: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 870 "src/parser.y"
                                                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-12].sval), rpg::RPGType::PACKED, 0, (yyvsp[-9].ival), (yyvsp[-7].ival), true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-12].sval));
    }
#line 4234 "build/parser.cpp"
    break;

  case 157: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 876 "src/parser.y"
                                                                                                 {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4244 "build/parser.cpp"
    break;

  case 158: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 881 "src/parser.y"
                                                                                                  {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4254 "build/parser.cpp"
    break;

  case 159: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 886 "src/parser.y"
                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4264 "build/parser.cpp"
    break;

  case 160: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 891 "src/parser.y"
                                                                                                                          {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4274 "build/parser.cpp"
    break;

  case 161: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 897 "src/parser.y"
                                                                                                                 {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4284 "build/parser.cpp"
    break;

  case 162: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 902 "src/parser.y"
                                                                                                                  {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::CHAR, (yyvsp[-8].ival), 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4294 "build/parser.cpp"
    break;

  case 163: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 907 "src/parser.y"
                                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::VARCHAR, (yyvsp[-8].ival), 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4304 "build/parser.cpp"
    break;

  case 164: /* pr_params: %empty  */
#line 916 "src/parser.y"
                {
        (yyval.param_list) = new ParamList();
    }
#line 4312 "build/parser.cpp"
    break;

  case 165: /* pr_params: pr_params pr_param  */
#line 919 "src/parser.y"
                         {
        (yyval.param_list) = (yyvsp[-1].param_list);
        (yyval.param_list)->params.push_back(*(yyvsp[0].param_decl));
        delete (yyvsp[0].param_decl);
    }
#line 4322 "build/parser.cpp"
    break;

  case 166: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 927 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4331 "build/parser.cpp"
    break;

  case 167: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 931 "src/parser.y"
                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4340 "build/parser.cpp"
    break;

  case 168: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 935 "src/parser.y"
                                                                 {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4349 "build/parser.cpp"
    break;

  case 169: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 939 "src/parser.y"
                                                                          {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4358 "build/parser.cpp"
    break;

  case 170: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 943 "src/parser.y"
                                                                    {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4367 "build/parser.cpp"
    break;

  case 171: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 947 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4376 "build/parser.cpp"
    break;

  case 172: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 951 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 4385 "build/parser.cpp"
    break;

  case 173: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 955 "src/parser.y"
                                                                                                  {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 4394 "build/parser.cpp"
    break;

  case 174: /* pr_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 960 "src/parser.y"
                                                                            {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4403 "build/parser.cpp"
    break;

  case 175: /* pr_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 964 "src/parser.y"
                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4412 "build/parser.cpp"
    break;

  case 176: /* pr_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 968 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4421 "build/parser.cpp"
    break;

  case 177: /* pr_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 972 "src/parser.y"
                                                                                      {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4430 "build/parser.cpp"
    break;

  case 178: /* pr_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 976 "src/parser.y"
                                                                                {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4439 "build/parser.cpp"
    break;

  case 179: /* pr_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 980 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4448 "build/parser.cpp"
    break;

  case 180: /* pr_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 984 "src/parser.y"
                                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 4457 "build/parser.cpp"
    break;

  case 181: /* pr_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 988 "src/parser.y"
                                                                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 4466 "build/parser.cpp"
    break;

  case 182: /* pr_param: IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 992 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, 0, 0, 0, false, std::string((yyvsp[-2].sval))};
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
    }
#line 4476 "build/parser.cpp"
    break;

  case 183: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 998 "src/parser.y"
                                                                                                            {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4486 "build/parser.cpp"
    break;

  case 184: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1003 "src/parser.y"
                                                                                                             {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4496 "build/parser.cpp"
    break;

  case 185: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1008 "src/parser.y"
                                                                                                                {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::VARCHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4506 "build/parser.cpp"
    break;

  case 186: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1013 "src/parser.y"
                                                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-12].sval), rpg::RPGType::PACKED, 0, (yyvsp[-9].ival), (yyvsp[-7].ival), true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-12].sval));
    }
#line 4516 "build/parser.cpp"
    break;

  case 187: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1019 "src/parser.y"
                                                                                                 {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4526 "build/parser.cpp"
    break;

  case 188: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1024 "src/parser.y"
                                                                                                  {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4536 "build/parser.cpp"
    break;

  case 189: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1029 "src/parser.y"
                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4546 "build/parser.cpp"
    break;

  case 190: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1034 "src/parser.y"
                                                                                                                          {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4556 "build/parser.cpp"
    break;

  case 191: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 1040 "src/parser.y"
                                                                                                                 {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4566 "build/parser.cpp"
    break;

  case 192: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 1045 "src/parser.y"
                                                                                                                  {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::CHAR, (yyvsp[-8].ival), 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4576 "build/parser.cpp"
    break;

  case 193: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 1050 "src/parser.y"
                                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::VARCHAR, (yyvsp[-8].ival), 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4586 "build/parser.cpp"
    break;

  case 194: /* monitor_stmt: KW_MONITOR SEMICOLON statement_list KW_ON_ERROR SEMICOLON statement_list KW_ENDMON SEMICOLON  */
#line 1060 "src/parser.y"
                                                                                                 {
        auto* node = new rpg::MonitorStmt();
        for (auto* s : (yyvsp[-5].stmt_list)->stmts) node->try_body.emplace_back(s);
        delete (yyvsp[-5].stmt_list);
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->on_error_body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        (yyval.stmt) = node;
    }
#line 4599 "build/parser.cpp"
    break;

  case 195: /* begsr_stmt: KW_BEGSR IDENTIFIER SEMICOLON statement_list KW_ENDSR SEMICOLON  */
#line 1071 "src/parser.y"
                                                                    {
        auto* node = new rpg::BegSR((yyvsp[-4].sval));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        free((yyvsp[-4].sval));
        (yyval.stmt) = node;
    }
#line 4611 "build/parser.cpp"
    break;

  case 196: /* exsr_stmt: KW_EXSR ident SEMICOLON  */
#line 1081 "src/parser.y"
                            {
        (yyval.stmt) = new rpg::ExSR((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4620 "build/parser.cpp"
    break;

  case 197: /* sorta_stmt: KW_SORTA ident SEMICOLON  */
#line 1089 "src/parser.y"
                             {
        (yyval.stmt) = new rpg::SortAStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4629 "build/parser.cpp"
    break;

  case 198: /* reset_stmt: KW_RESET ident SEMICOLON  */
#line 1097 "src/parser.y"
                             {
        (yyval.stmt) = new rpg::ResetStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4638 "build/parser.cpp"
    break;

  case 199: /* clear_stmt: KW_CLEAR ident SEMICOLON  */
#line 1104 "src/parser.y"
                             {
        (yyval.stmt) = new rpg::ClearStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4647 "build/parser.cpp"
    break;

  case 200: /* dealloc_stmt: KW_DEALLOC ident SEMICOLON  */
#line 1112 "src/parser.y"
                               {
        (yyval.stmt) = new rpg::DeallocStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4656 "build/parser.cpp"
    break;

  case 201: /* test_stmt: KW_TEST LPAREN ident RPAREN ident SEMICOLON  */
#line 1120 "src/parser.y"
                                                {
        char type = toupper((yyvsp[-3].sval)[0]);
        (yyval.stmt) = new rpg::TestStmt(type, std::string((yyvsp[-1].sval)));
        free((yyvsp[-3].sval));
        free((yyvsp[-1].sval));
    }
#line 4667 "build/parser.cpp"
    break;

  case 202: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1132 "src/parser.y"
                                                                              {
        auto* ds = new rpg::DclDS((yyvsp[-5].sval));
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-5].sval));
        (yyval.stmt) = ds;
    }
#line 4680 "build/parser.cpp"
    break;

  case 203: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1141 "src/parser.y"
                                                                   {
        auto* ds = new rpg::DclDS((yyvsp[-4].sval));
        ds->qualified = false;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-4].sval));
        (yyval.stmt) = ds;
    }
#line 4693 "build/parser.cpp"
    break;

  case 204: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1150 "src/parser.y"
                                                                                                                     {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->dim = (yyvsp[-6].ival);
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-9].sval));
        (yyval.stmt) = ds;
    }
#line 4707 "build/parser.cpp"
    break;

  case 205: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1160 "src/parser.y"
                                                                                                                     {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->dim = (yyvsp[-5].ival);
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-9].sval));
        (yyval.stmt) = ds;
    }
#line 4721 "build/parser.cpp"
    break;

  case 206: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1170 "src/parser.y"
                                                                        {
        auto* ds = new rpg::DclDS((yyvsp[-5].sval));
        ds->like_ds = (yyvsp[-2].sval);
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
        (yyval.stmt) = ds;
    }
#line 4733 "build/parser.cpp"
    break;

  case 207: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1178 "src/parser.y"
                                                                                                             {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->like_ds = (yyvsp[-6].sval);
        ds->dim = (yyvsp[-2].ival);
        free((yyvsp[-9].sval));
        free((yyvsp[-6].sval));
        (yyval.stmt) = ds;
    }
#line 4746 "build/parser.cpp"
    break;

  case 208: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_PREFIX LPAREN IDENTIFIER RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1187 "src/parser.y"
                                                                                                                   {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->qualified = true;
        ds->prefix = (yyvsp[-5].sval);
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-9].sval)); free((yyvsp[-5].sval));
        (yyval.stmt) = ds;
    }
#line 4760 "build/parser.cpp"
    break;

  case 209: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_PREFIX LPAREN IDENTIFIER COLON INTEGER_LITERAL RPAREN KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1197 "src/parser.y"
                                                                                                                                         {
        auto* ds = new rpg::DclDS((yyvsp[-11].sval));
        ds->qualified = true;
        ds->prefix = (yyvsp[-8].sval);
        ds->prefix_nbr = (yyvsp[-6].ival);
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-11].sval)); free((yyvsp[-8].sval));
        (yyval.stmt) = ds;
    }
#line 4775 "build/parser.cpp"
    break;

  case 210: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_PREFIX LPAREN IDENTIFIER COLON INTEGER_LITERAL RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1208 "src/parser.y"
                                                                                                                                         {
        auto* ds = new rpg::DclDS((yyvsp[-11].sval));
        ds->qualified = true;
        ds->prefix = (yyvsp[-7].sval);
        ds->prefix_nbr = (yyvsp[-5].ival);
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-11].sval)); free((yyvsp[-7].sval));
        (yyval.stmt) = ds;
    }
#line 4790 "build/parser.cpp"
    break;

  case 211: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_PREFIX LPAREN IDENTIFIER RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1219 "src/parser.y"
                                                                                                      {
        auto* ds = new rpg::DclDS((yyvsp[-8].sval));
        ds->qualified = false;
        ds->prefix = (yyvsp[-5].sval);
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-8].sval)); free((yyvsp[-5].sval));
        (yyval.stmt) = ds;
    }
#line 4804 "build/parser.cpp"
    break;

  case 212: /* ds_fields: %empty  */
#line 1231 "src/parser.y"
                {
        (yyval.ds_field_list) = new DSFieldList();
    }
#line 4812 "build/parser.cpp"
    break;

  case 213: /* ds_fields: ds_fields ds_field  */
#line 1234 "src/parser.y"
                         {
        (yyval.ds_field_list) = (yyvsp[-1].ds_field_list);
        (yyval.ds_field_list)->fields.push_back(*(yyvsp[0].ds_field));
        delete (yyvsp[0].ds_field);
    }
#line 4822 "build/parser.cpp"
    break;

  case 214: /* ds_field: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1242 "src/parser.y"
                                                              {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0};
        free((yyvsp[-5].sval));
    }
#line 4831 "build/parser.cpp"
    break;

  case 215: /* ds_field: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1246 "src/parser.y"
                                                                 {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 4840 "build/parser.cpp"
    break;

  case 216: /* ds_field: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1250 "src/parser.y"
                                                                    {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 4849 "build/parser.cpp"
    break;

  case 217: /* ds_field: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1254 "src/parser.y"
                                                                                         {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival)};
        free((yyvsp[-7].sval));
    }
#line 4858 "build/parser.cpp"
    break;

  case 218: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1259 "src/parser.y"
                                                                            {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0};
        free((yyvsp[-5].sval));
    }
#line 4867 "build/parser.cpp"
    break;

  case 219: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1263 "src/parser.y"
                                                                             {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 4876 "build/parser.cpp"
    break;

  case 220: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1267 "src/parser.y"
                                                                                {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 4885 "build/parser.cpp"
    break;

  case 221: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1271 "src/parser.y"
                                                                                                     {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival)};
        free((yyvsp[-7].sval));
    }
#line 4894 "build/parser.cpp"
    break;

  case 222: /* ds_field: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_POS LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1276 "src/parser.y"
                                                                                                      {
        auto* f = new rpg::DSField{(yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0};
        f->pos = (yyvsp[-2].ival);
        free((yyvsp[-9].sval));
        (yyval.ds_field) = f;
    }
#line 4905 "build/parser.cpp"
    break;

  case 223: /* ds_field: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_POS LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1282 "src/parser.y"
                                                                                                     {
        auto* f = new rpg::DSField{(yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0};
        f->pos = (yyvsp[-2].ival);
        free((yyvsp[-9].sval));
        (yyval.ds_field) = f;
    }
#line 4916 "build/parser.cpp"
    break;

  case 224: /* ds_field: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_POS LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1288 "src/parser.y"
                                                                                                                              {
        auto* f = new rpg::DSField{(yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival)};
        f->pos = (yyvsp[-2].ival);
        free((yyvsp[-11].sval));
        (yyval.ds_field) = f;
    }
#line 4927 "build/parser.cpp"
    break;

  case 225: /* ds_field: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OVERLAY LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1295 "src/parser.y"
                                                                                                     {
        auto* f = new rpg::DSField{(yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0};
        f->overlay_field = (yyvsp[-2].sval);
        free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
        (yyval.ds_field) = f;
    }
#line 4938 "build/parser.cpp"
    break;

  case 226: /* ds_field: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OVERLAY LPAREN IDENTIFIER COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1302 "src/parser.y"
                                                                                                                           {
        auto* f = new rpg::DSField{(yyvsp[-11].sval), rpg::RPGType::CHAR, (yyvsp[-8].ival), 0, 0};
        f->overlay_field = (yyvsp[-4].sval);
        f->overlay_pos = (yyvsp[-2].ival);
        free((yyvsp[-11].sval)); free((yyvsp[-4].sval));
        (yyval.ds_field) = f;
    }
#line 4950 "build/parser.cpp"
    break;

  case 227: /* ds_field: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OVERLAY LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1309 "src/parser.y"
                                                                                                    {
        auto* f = new rpg::DSField{(yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0};
        f->overlay_field = (yyvsp[-2].sval);
        free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
        (yyval.ds_field) = f;
    }
#line 4961 "build/parser.cpp"
    break;

  case 228: /* ds_field: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OVERLAY LPAREN IDENTIFIER COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1315 "src/parser.y"
                                                                                                                          {
        auto* f = new rpg::DSField{(yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0};
        f->overlay_field = (yyvsp[-4].sval);
        f->overlay_pos = (yyvsp[-2].ival);
        free((yyvsp[-11].sval)); free((yyvsp[-4].sval));
        (yyval.ds_field) = f;
    }
#line 4973 "build/parser.cpp"
    break;

  case 229: /* if_stmt: KW_IF expression SEMICOLON statement_list elseif_clauses else_clause KW_ENDIF SEMICOLON  */
#line 1327 "src/parser.y"
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
#line 4998 "build/parser.cpp"
    break;

  case 230: /* elseif_clauses: %empty  */
#line 1350 "src/parser.y"
                { (yyval.elseif_list) = nullptr; }
#line 5004 "build/parser.cpp"
    break;

  case 231: /* elseif_clauses: elseif_clauses elseif_clause  */
#line 1351 "src/parser.y"
                                   {
        if (!(yyvsp[-1].elseif_list)) (yyvsp[-1].elseif_list) = new std::vector<ElseIfData*>();
        (yyval.elseif_list) = (yyvsp[-1].elseif_list);
        (yyval.elseif_list)->push_back((yyvsp[0].elseif_data));
    }
#line 5014 "build/parser.cpp"
    break;

  case 232: /* elseif_clause: KW_ELSEIF expression SEMICOLON statement_list  */
#line 1359 "src/parser.y"
                                                  {
        (yyval.elseif_data) = new ElseIfData();
        (yyval.elseif_data)->cond = (yyvsp[-2].expr);
        (yyval.elseif_data)->body = std::move((yyvsp[0].stmt_list)->stmts);
        delete (yyvsp[0].stmt_list);
    }
#line 5025 "build/parser.cpp"
    break;

  case 233: /* else_clause: %empty  */
#line 1368 "src/parser.y"
                { (yyval.stmt_list) = nullptr; }
#line 5031 "build/parser.cpp"
    break;

  case 234: /* else_clause: KW_ELSE SEMICOLON statement_list  */
#line 1369 "src/parser.y"
                                       {
        (yyval.stmt_list) = (yyvsp[0].stmt_list);
    }
#line 5039 "build/parser.cpp"
    break;

  case 235: /* dow_stmt: KW_DOW expression SEMICOLON statement_list KW_ENDDO SEMICOLON  */
#line 1375 "src/parser.y"
                                                                  {
        auto* node = new rpg::DowStmt(std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        (yyval.stmt) = node;
    }
#line 5050 "build/parser.cpp"
    break;

  case 236: /* dou_stmt: KW_DOU expression SEMICOLON statement_list KW_ENDDO SEMICOLON  */
#line 1384 "src/parser.y"
                                                                  {
        auto* node = new rpg::DouStmt(std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        (yyval.stmt) = node;
    }
#line 5061 "build/parser.cpp"
    break;

  case 237: /* for_stmt: KW_FOR ident EQUALS expression KW_TO expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1393 "src/parser.y"
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
#line 5076 "build/parser.cpp"
    break;

  case 238: /* for_stmt: KW_FOR ident EQUALS expression KW_TO expression KW_BY expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1403 "src/parser.y"
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
#line 5091 "build/parser.cpp"
    break;

  case 239: /* for_stmt: KW_FOR ident EQUALS expression KW_DOWNTO expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1413 "src/parser.y"
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
#line 5106 "build/parser.cpp"
    break;

  case 240: /* for_stmt: KW_FOR ident EQUALS expression KW_DOWNTO expression KW_BY expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1423 "src/parser.y"
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
#line 5121 "build/parser.cpp"
    break;

  case 241: /* for_each_stmt: KW_FOR_EACH ident KW_IN expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1436 "src/parser.y"
                                                                                    {
        auto* node = new rpg::ForEachStmt((yyvsp[-6].sval), std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        free((yyvsp[-6].sval));
        (yyval.stmt) = node;
    }
#line 5133 "build/parser.cpp"
    break;

  case 242: /* select_stmt: KW_SELECT SEMICOLON when_clauses other_clause KW_ENDSL SEMICOLON  */
#line 1446 "src/parser.y"
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
#line 5154 "build/parser.cpp"
    break;

  case 243: /* when_clauses: when_clause  */
#line 1465 "src/parser.y"
                {
        (yyval.when_list) = new std::vector<WhenData*>();
        (yyval.when_list)->push_back((yyvsp[0].when_data));
    }
#line 5163 "build/parser.cpp"
    break;

  case 244: /* when_clauses: when_clauses when_clause  */
#line 1469 "src/parser.y"
                               {
        (yyval.when_list) = (yyvsp[-1].when_list);
        (yyval.when_list)->push_back((yyvsp[0].when_data));
    }
#line 5172 "build/parser.cpp"
    break;

  case 245: /* when_clause: KW_WHEN expression SEMICOLON statement_list  */
#line 1476 "src/parser.y"
                                                {
        (yyval.when_data) = new WhenData();
        (yyval.when_data)->cond = (yyvsp[-2].expr);
        (yyval.when_data)->body = std::move((yyvsp[0].stmt_list)->stmts);
        delete (yyvsp[0].stmt_list);
    }
#line 5183 "build/parser.cpp"
    break;

  case 246: /* other_clause: %empty  */
#line 1485 "src/parser.y"
                { (yyval.stmt_list) = nullptr; }
#line 5189 "build/parser.cpp"
    break;

  case 247: /* other_clause: KW_OTHER SEMICOLON statement_list  */
#line 1486 "src/parser.y"
                                        {
        (yyval.stmt_list) = (yyvsp[0].stmt_list);
    }
#line 5197 "build/parser.cpp"
    break;

  case 248: /* iter_stmt: KW_ITER SEMICOLON  */
#line 1492 "src/parser.y"
                      { (yyval.stmt) = new rpg::IterStmt(); }
#line 5203 "build/parser.cpp"
    break;

  case 249: /* leave_stmt: KW_LEAVE SEMICOLON  */
#line 1496 "src/parser.y"
                       { (yyval.stmt) = new rpg::LeaveStmt(); }
#line 5209 "build/parser.cpp"
    break;

  case 250: /* expression: or_expr  */
#line 1502 "src/parser.y"
            { (yyval.expr) = (yyvsp[0].expr); }
#line 5215 "build/parser.cpp"
    break;

  case 251: /* or_expr: and_expr  */
#line 1506 "src/parser.y"
             { (yyval.expr) = (yyvsp[0].expr); }
#line 5221 "build/parser.cpp"
    break;

  case 252: /* or_expr: or_expr KW_OR and_expr  */
#line 1507 "src/parser.y"
                             {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::OR,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5231 "build/parser.cpp"
    break;

  case 253: /* and_expr: not_expr  */
#line 1515 "src/parser.y"
             { (yyval.expr) = (yyvsp[0].expr); }
#line 5237 "build/parser.cpp"
    break;

  case 254: /* and_expr: and_expr KW_AND not_expr  */
#line 1516 "src/parser.y"
                               {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::AND,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5247 "build/parser.cpp"
    break;

  case 255: /* not_expr: comparison_expr  */
#line 1524 "src/parser.y"
                    { (yyval.expr) = (yyvsp[0].expr); }
#line 5253 "build/parser.cpp"
    break;

  case 256: /* not_expr: KW_NOT comparison_expr  */
#line 1525 "src/parser.y"
                             {
        (yyval.expr) = new rpg::NotExpr(std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5261 "build/parser.cpp"
    break;

  case 257: /* comparison_expr: additive_expr  */
#line 1531 "src/parser.y"
                  { (yyval.expr) = (yyvsp[0].expr); }
#line 5267 "build/parser.cpp"
    break;

  case 258: /* comparison_expr: comparison_expr EQUALS additive_expr  */
#line 1532 "src/parser.y"
                                           {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::EQ,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5277 "build/parser.cpp"
    break;

  case 259: /* comparison_expr: comparison_expr NE additive_expr  */
#line 1537 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::NE,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5287 "build/parser.cpp"
    break;

  case 260: /* comparison_expr: comparison_expr LT additive_expr  */
#line 1542 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::LT,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5297 "build/parser.cpp"
    break;

  case 261: /* comparison_expr: comparison_expr GT additive_expr  */
#line 1547 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::GT,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5307 "build/parser.cpp"
    break;

  case 262: /* comparison_expr: comparison_expr LE additive_expr  */
#line 1552 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::LE,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5317 "build/parser.cpp"
    break;

  case 263: /* comparison_expr: comparison_expr GE additive_expr  */
#line 1557 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::GE,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5327 "build/parser.cpp"
    break;

  case 264: /* comparison_expr: additive_expr KW_IN additive_expr  */
#line 1562 "src/parser.y"
                                        {
        (yyval.expr) = new rpg::InExpr(
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5337 "build/parser.cpp"
    break;

  case 265: /* additive_expr: multiplicative_expr  */
#line 1570 "src/parser.y"
                        { (yyval.expr) = (yyvsp[0].expr); }
#line 5343 "build/parser.cpp"
    break;

  case 266: /* additive_expr: additive_expr PLUS multiplicative_expr  */
#line 1571 "src/parser.y"
                                             {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::ADD,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5353 "build/parser.cpp"
    break;

  case 267: /* additive_expr: additive_expr MINUS multiplicative_expr  */
#line 1576 "src/parser.y"
                                              {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::SUB,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5363 "build/parser.cpp"
    break;

  case 268: /* multiplicative_expr: unary_expr  */
#line 1584 "src/parser.y"
               { (yyval.expr) = (yyvsp[0].expr); }
#line 5369 "build/parser.cpp"
    break;

  case 269: /* multiplicative_expr: multiplicative_expr STAR unary_expr  */
#line 1585 "src/parser.y"
                                          {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::MUL,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5379 "build/parser.cpp"
    break;

  case 270: /* multiplicative_expr: multiplicative_expr SLASH unary_expr  */
#line 1590 "src/parser.y"
                                           {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::DIV,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5389 "build/parser.cpp"
    break;

  case 271: /* unary_expr: postfix_expr  */
#line 1598 "src/parser.y"
                 { (yyval.expr) = (yyvsp[0].expr); }
#line 5395 "build/parser.cpp"
    break;

  case 272: /* unary_expr: MINUS postfix_expr  */
#line 1599 "src/parser.y"
                         {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::SUB,
            std::unique_ptr<rpg::Expression>(new rpg::IntLiteral(0)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5405 "build/parser.cpp"
    break;

  case 273: /* postfix_expr: primary_expr  */
#line 1607 "src/parser.y"
                 { (yyval.expr) = (yyvsp[0].expr); }
#line 5411 "build/parser.cpp"
    break;

  case 274: /* postfix_expr: postfix_expr DOT IDENTIFIER  */
#line 1608 "src/parser.y"
                                  {
        (yyval.expr) = new rpg::DotExpr(std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)), (yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 5420 "build/parser.cpp"
    break;

  case 275: /* ident: IDENTIFIER  */
#line 1615 "src/parser.y"
               { (yyval.sval) = (yyvsp[0].sval); }
#line 5426 "build/parser.cpp"
    break;

  case 276: /* ident: KW_UNS  */
#line 1616 "src/parser.y"
             { (yyval.sval) = strdup("UNS"); }
#line 5432 "build/parser.cpp"
    break;

  case 277: /* ident: KW_FLOAT_TYPE  */
#line 1617 "src/parser.y"
                    { (yyval.sval) = strdup("FLOAT"); }
#line 5438 "build/parser.cpp"
    break;

  case 278: /* ident: KW_GRAPH  */
#line 1618 "src/parser.y"
               { (yyval.sval) = strdup("GRAPH"); }
#line 5444 "build/parser.cpp"
    break;

  case 279: /* ident: KW_OCCURS  */
#line 1619 "src/parser.y"
                { (yyval.sval) = strdup("OCCURS"); }
#line 5450 "build/parser.cpp"
    break;

  case 280: /* ident: KW_ASCEND  */
#line 1620 "src/parser.y"
                { (yyval.sval) = strdup("ASCEND"); }
#line 5456 "build/parser.cpp"
    break;

  case 281: /* ident: KW_DESCEND  */
#line 1621 "src/parser.y"
                 { (yyval.sval) = strdup("DESCEND"); }
#line 5462 "build/parser.cpp"
    break;

  case 282: /* ident: KW_IN  */
#line 1622 "src/parser.y"
            { (yyval.sval) = strdup("IN"); }
#line 5468 "build/parser.cpp"
    break;

  case 283: /* ident: KW_RTNPARM  */
#line 1623 "src/parser.y"
                 { (yyval.sval) = strdup("RTNPARM"); }
#line 5474 "build/parser.cpp"
    break;

  case 284: /* ident: KW_OPDESC  */
#line 1624 "src/parser.y"
                { (yyval.sval) = strdup("OPDESC"); }
#line 5480 "build/parser.cpp"
    break;

  case 285: /* ident: KW_NULLIND  */
#line 1625 "src/parser.y"
                 { (yyval.sval) = strdup("NULLIND"); }
#line 5486 "build/parser.cpp"
    break;

  case 286: /* ident: KW_DATFMT  */
#line 1626 "src/parser.y"
                { (yyval.sval) = strdup("DATFMT"); }
#line 5492 "build/parser.cpp"
    break;

  case 287: /* ident: KW_TIMFMT  */
#line 1627 "src/parser.y"
                { (yyval.sval) = strdup("TIMFMT"); }
#line 5498 "build/parser.cpp"
    break;

  case 288: /* ident: KW_EXTNAME  */
#line 1628 "src/parser.y"
                 { (yyval.sval) = strdup("EXTNAME"); }
#line 5504 "build/parser.cpp"
    break;

  case 289: /* ident: KW_OVERLAY  */
#line 1629 "src/parser.y"
                 { (yyval.sval) = strdup("OVERLAY"); }
#line 5510 "build/parser.cpp"
    break;

  case 290: /* ident: KW_POS  */
#line 1630 "src/parser.y"
             { (yyval.sval) = strdup("POS"); }
#line 5516 "build/parser.cpp"
    break;

  case 291: /* ident: KW_PREFIX  */
#line 1631 "src/parser.y"
                { (yyval.sval) = strdup("PREFIX"); }
#line 5522 "build/parser.cpp"
    break;

  case 292: /* primary_expr: IDENTIFIER  */
#line 1635 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier((yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 5531 "build/parser.cpp"
    break;

  case 293: /* primary_expr: KW_UNS  */
#line 1639 "src/parser.y"
             { (yyval.expr) = new rpg::Identifier("UNS"); }
#line 5537 "build/parser.cpp"
    break;

  case 294: /* primary_expr: KW_FLOAT_TYPE  */
#line 1640 "src/parser.y"
                    { (yyval.expr) = new rpg::Identifier("FLOAT"); }
#line 5543 "build/parser.cpp"
    break;

  case 295: /* primary_expr: KW_GRAPH  */
#line 1641 "src/parser.y"
               { (yyval.expr) = new rpg::Identifier("GRAPH"); }
#line 5549 "build/parser.cpp"
    break;

  case 296: /* primary_expr: KW_OCCURS  */
#line 1642 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("OCCURS"); }
#line 5555 "build/parser.cpp"
    break;

  case 297: /* primary_expr: KW_ASCEND  */
#line 1643 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("ASCEND"); }
#line 5561 "build/parser.cpp"
    break;

  case 298: /* primary_expr: KW_DESCEND  */
#line 1644 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("DESCEND"); }
#line 5567 "build/parser.cpp"
    break;

  case 299: /* primary_expr: KW_RTNPARM  */
#line 1645 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("RTNPARM"); }
#line 5573 "build/parser.cpp"
    break;

  case 300: /* primary_expr: KW_OPDESC  */
#line 1646 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("OPDESC"); }
#line 5579 "build/parser.cpp"
    break;

  case 301: /* primary_expr: KW_NULLIND  */
#line 1647 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("NULLIND"); }
#line 5585 "build/parser.cpp"
    break;

  case 302: /* primary_expr: KW_DATFMT  */
#line 1648 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("DATFMT"); }
#line 5591 "build/parser.cpp"
    break;

  case 303: /* primary_expr: KW_OVERLAY  */
#line 1649 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("OVERLAY"); }
#line 5597 "build/parser.cpp"
    break;

  case 304: /* primary_expr: KW_POS  */
#line 1650 "src/parser.y"
             { (yyval.expr) = new rpg::Identifier("POS"); }
#line 5603 "build/parser.cpp"
    break;

  case 305: /* primary_expr: KW_PREFIX  */
#line 1651 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("PREFIX"); }
#line 5609 "build/parser.cpp"
    break;

  case 306: /* primary_expr: KW_TIMFMT  */
#line 1652 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("TIMFMT"); }
#line 5615 "build/parser.cpp"
    break;

  case 307: /* primary_expr: KW_EXTNAME  */
#line 1653 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("EXTNAME"); }
#line 5621 "build/parser.cpp"
    break;

  case 308: /* primary_expr: INTEGER_LITERAL  */
#line 1654 "src/parser.y"
                      {
        (yyval.expr) = new rpg::IntLiteral((yyvsp[0].ival));
    }
#line 5629 "build/parser.cpp"
    break;

  case 309: /* primary_expr: FLOAT_LITERAL  */
#line 1657 "src/parser.y"
                    {
        (yyval.expr) = new rpg::FloatLiteral((yyvsp[0].fval));
    }
#line 5637 "build/parser.cpp"
    break;

  case 310: /* primary_expr: STRING_LITERAL  */
#line 1660 "src/parser.y"
                     {
        (yyval.expr) = new rpg::StringLiteral((yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 5646 "build/parser.cpp"
    break;

  case 311: /* primary_expr: IDENTIFIER LPAREN call_args_opt RPAREN  */
#line 1664 "src/parser.y"
                                             {
        (yyval.expr) = make_func((yyvsp[-3].sval), (yyvsp[-1].expr_list));
        free((yyvsp[-3].sval));
    }
#line 5655 "build/parser.cpp"
    break;

  case 312: /* primary_expr: BIF_CHAR LPAREN arg_list RPAREN  */
#line 1668 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("CHAR", (yyvsp[-1].expr_list));
    }
#line 5663 "build/parser.cpp"
    break;

  case 313: /* primary_expr: BIF_TRIM LPAREN arg_list RPAREN  */
#line 1671 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("TRIM", (yyvsp[-1].expr_list));
    }
#line 5671 "build/parser.cpp"
    break;

  case 314: /* primary_expr: BIF_TRIML LPAREN arg_list RPAREN  */
#line 1674 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("TRIML", (yyvsp[-1].expr_list));
    }
#line 5679 "build/parser.cpp"
    break;

  case 315: /* primary_expr: BIF_TRIMR LPAREN arg_list RPAREN  */
#line 1677 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("TRIMR", (yyvsp[-1].expr_list));
    }
#line 5687 "build/parser.cpp"
    break;

  case 316: /* primary_expr: BIF_LEN LPAREN arg_list RPAREN  */
#line 1680 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("LEN", (yyvsp[-1].expr_list));
    }
#line 5695 "build/parser.cpp"
    break;

  case 317: /* primary_expr: BIF_SUBST LPAREN arg_list RPAREN  */
#line 1683 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("SUBST", (yyvsp[-1].expr_list));
    }
#line 5703 "build/parser.cpp"
    break;

  case 318: /* primary_expr: BIF_SCAN LPAREN arg_list RPAREN  */
#line 1686 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("SCAN", (yyvsp[-1].expr_list));
    }
#line 5711 "build/parser.cpp"
    break;

  case 319: /* primary_expr: BIF_SCANRPL LPAREN arg_list RPAREN  */
#line 1689 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("SCANRPL", (yyvsp[-1].expr_list));
    }
#line 5719 "build/parser.cpp"
    break;

  case 320: /* primary_expr: BIF_XLATE LPAREN arg_list RPAREN  */
#line 1692 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("XLATE", (yyvsp[-1].expr_list));
    }
#line 5727 "build/parser.cpp"
    break;

  case 321: /* primary_expr: BIF_DEC LPAREN arg_list RPAREN  */
#line 1695 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("DEC", (yyvsp[-1].expr_list));
    }
#line 5735 "build/parser.cpp"
    break;

  case 322: /* primary_expr: BIF_INT LPAREN arg_list RPAREN  */
#line 1698 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("INT", (yyvsp[-1].expr_list));
    }
#line 5743 "build/parser.cpp"
    break;

  case 323: /* primary_expr: BIF_ELEM LPAREN arg_list RPAREN  */
#line 1701 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("ELEM", (yyvsp[-1].expr_list));
    }
#line 5751 "build/parser.cpp"
    break;

  case 324: /* primary_expr: BIF_PARMS LPAREN RPAREN  */
#line 1704 "src/parser.y"
                              {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("PARMS", empty);
    }
#line 5760 "build/parser.cpp"
    break;

  case 325: /* primary_expr: BIF_LOOKUP LPAREN arg_list RPAREN  */
#line 1708 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("LOOKUP", (yyvsp[-1].expr_list));
    }
#line 5768 "build/parser.cpp"
    break;

  case 326: /* primary_expr: BIF_EDITC LPAREN arg_list RPAREN  */
#line 1711 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("EDITC", (yyvsp[-1].expr_list));
    }
#line 5776 "build/parser.cpp"
    break;

  case 327: /* primary_expr: BIF_EDITW LPAREN arg_list RPAREN  */
#line 1714 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("EDITW", (yyvsp[-1].expr_list));
    }
#line 5784 "build/parser.cpp"
    break;

  case 328: /* primary_expr: BIF_REPLACE LPAREN arg_list RPAREN  */
#line 1717 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("REPLACE", (yyvsp[-1].expr_list));
    }
#line 5792 "build/parser.cpp"
    break;

  case 329: /* primary_expr: BIF_CHECK LPAREN arg_list RPAREN  */
#line 1720 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("CHECK", (yyvsp[-1].expr_list));
    }
#line 5800 "build/parser.cpp"
    break;

  case 330: /* primary_expr: BIF_CHECKR LPAREN arg_list RPAREN  */
#line 1723 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("CHECKR", (yyvsp[-1].expr_list));
    }
#line 5808 "build/parser.cpp"
    break;

  case 331: /* primary_expr: BIF_LOWER LPAREN arg_list RPAREN  */
#line 1726 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("LOWER", (yyvsp[-1].expr_list));
    }
#line 5816 "build/parser.cpp"
    break;

  case 332: /* primary_expr: BIF_UPPER LPAREN arg_list RPAREN  */
#line 1729 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("UPPER", (yyvsp[-1].expr_list));
    }
#line 5824 "build/parser.cpp"
    break;

  case 333: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_YEARS RPAREN  */
#line 1732 "src/parser.y"
                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("YEARS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 5835 "build/parser.cpp"
    break;

  case 334: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_MONTHS RPAREN  */
#line 1738 "src/parser.y"
                                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MONTHS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 5846 "build/parser.cpp"
    break;

  case 335: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_DAYS RPAREN  */
#line 1744 "src/parser.y"
                                                       {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("DAYS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 5857 "build/parser.cpp"
    break;

  case 336: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_HOURS RPAREN  */
#line 1750 "src/parser.y"
                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("HOURS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 5868 "build/parser.cpp"
    break;

  case 337: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_MINUTES RPAREN  */
#line 1756 "src/parser.y"
                                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MINUTES"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 5879 "build/parser.cpp"
    break;

  case 338: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_SECONDS RPAREN  */
#line 1762 "src/parser.y"
                                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("SECONDS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 5890 "build/parser.cpp"
    break;

  case 339: /* primary_expr: BIF_FLOAT LPAREN arg_list RPAREN  */
#line 1768 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("FLOAT", (yyvsp[-1].expr_list));
    }
#line 5898 "build/parser.cpp"
    break;

  case 340: /* primary_expr: BIF_SQRT LPAREN arg_list RPAREN  */
#line 1771 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("SQRT", (yyvsp[-1].expr_list));
    }
#line 5906 "build/parser.cpp"
    break;

  case 341: /* primary_expr: BIF_MAX LPAREN arg_list RPAREN  */
#line 1774 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("MAX", (yyvsp[-1].expr_list));
    }
#line 5914 "build/parser.cpp"
    break;

  case 342: /* primary_expr: BIF_MIN LPAREN arg_list RPAREN  */
#line 1777 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("MIN", (yyvsp[-1].expr_list));
    }
#line 5922 "build/parser.cpp"
    break;

  case 343: /* primary_expr: BIF_STATUS LPAREN RPAREN  */
#line 1780 "src/parser.y"
                               {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("STATUS", empty);
    }
#line 5931 "build/parser.cpp"
    break;

  case 344: /* primary_expr: BIF_ERROR LPAREN RPAREN  */
#line 1784 "src/parser.y"
                              {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("ERROR", empty);
    }
#line 5940 "build/parser.cpp"
    break;

  case 345: /* primary_expr: BIF_SIZE LPAREN arg_list RPAREN  */
#line 1788 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("SIZE", (yyvsp[-1].expr_list));
    }
#line 5948 "build/parser.cpp"
    break;

  case 346: /* primary_expr: BIF_ADDR LPAREN arg_list RPAREN  */
#line 1791 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("ADDR", (yyvsp[-1].expr_list));
    }
#line 5956 "build/parser.cpp"
    break;

  case 347: /* primary_expr: BIF_ABS LPAREN arg_list RPAREN  */
#line 1794 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("ABS", (yyvsp[-1].expr_list));
    }
#line 5964 "build/parser.cpp"
    break;

  case 348: /* primary_expr: BIF_DIV LPAREN arg_list RPAREN  */
#line 1797 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("DIV", (yyvsp[-1].expr_list));
    }
#line 5972 "build/parser.cpp"
    break;

  case 349: /* primary_expr: BIF_REM LPAREN arg_list RPAREN  */
#line 1800 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("REM", (yyvsp[-1].expr_list));
    }
#line 5980 "build/parser.cpp"
    break;

  case 350: /* primary_expr: BIF_DATE LPAREN arg_list RPAREN  */
#line 1803 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("DATE", (yyvsp[-1].expr_list));
    }
#line 5988 "build/parser.cpp"
    break;

  case 351: /* primary_expr: BIF_DATE LPAREN RPAREN  */
#line 1806 "src/parser.y"
                             {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("DATE", empty);
    }
#line 5997 "build/parser.cpp"
    break;

  case 352: /* primary_expr: BIF_TIME LPAREN arg_list RPAREN  */
#line 1810 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("TIME", (yyvsp[-1].expr_list));
    }
#line 6005 "build/parser.cpp"
    break;

  case 353: /* primary_expr: BIF_TIME LPAREN RPAREN  */
#line 1813 "src/parser.y"
                             {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("TIME", empty);
    }
#line 6014 "build/parser.cpp"
    break;

  case 354: /* primary_expr: BIF_TIMESTAMP LPAREN arg_list RPAREN  */
#line 1817 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TIMESTAMP", (yyvsp[-1].expr_list));
    }
#line 6022 "build/parser.cpp"
    break;

  case 355: /* primary_expr: BIF_TIMESTAMP LPAREN RPAREN  */
#line 1820 "src/parser.y"
                                  {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("TIMESTAMP", empty);
    }
#line 6031 "build/parser.cpp"
    break;

  case 356: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_DAYS RPAREN  */
#line 1824 "src/parser.y"
                                                                       {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("DAYS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 6043 "build/parser.cpp"
    break;

  case 357: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_MONTHS RPAREN  */
#line 1831 "src/parser.y"
                                                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MONTHS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 6055 "build/parser.cpp"
    break;

  case 358: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_YEARS RPAREN  */
#line 1838 "src/parser.y"
                                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("YEARS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 6067 "build/parser.cpp"
    break;

  case 359: /* primary_expr: BIF_DAYS LPAREN expression RPAREN  */
#line 1845 "src/parser.y"
                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("DAYS", args);
    }
#line 6077 "build/parser.cpp"
    break;

  case 360: /* primary_expr: BIF_MONTHS LPAREN expression RPAREN  */
#line 1850 "src/parser.y"
                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("MONTHS", args);
    }
#line 6087 "build/parser.cpp"
    break;

  case 361: /* primary_expr: BIF_YEARS LPAREN expression RPAREN  */
#line 1855 "src/parser.y"
                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("YEARS", args);
    }
#line 6097 "build/parser.cpp"
    break;

  case 362: /* primary_expr: BIF_FOUND LPAREN RPAREN  */
#line 1860 "src/parser.y"
                              {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("FOUND", empty);
    }
#line 6106 "build/parser.cpp"
    break;

  case 363: /* primary_expr: BIF_EOF LPAREN RPAREN  */
#line 1864 "src/parser.y"
                            {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("EOF", empty);
    }
#line 6115 "build/parser.cpp"
    break;

  case 364: /* primary_expr: BIF_ALLOC LPAREN arg_list RPAREN  */
#line 1868 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("ALLOC", (yyvsp[-1].expr_list));
    }
#line 6123 "build/parser.cpp"
    break;

  case 365: /* primary_expr: BIF_REALLOC LPAREN arg_list RPAREN  */
#line 1871 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("REALLOC", (yyvsp[-1].expr_list));
    }
#line 6131 "build/parser.cpp"
    break;

  case 366: /* primary_expr: BIF_XFOOT LPAREN arg_list RPAREN  */
#line 1874 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("XFOOT", (yyvsp[-1].expr_list));
    }
#line 6139 "build/parser.cpp"
    break;

  case 367: /* primary_expr: BIF_UNS LPAREN arg_list RPAREN  */
#line 1877 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("UNS", (yyvsp[-1].expr_list));
    }
#line 6147 "build/parser.cpp"
    break;

  case 368: /* primary_expr: BIF_INTH LPAREN arg_list RPAREN  */
#line 1880 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("INTH", (yyvsp[-1].expr_list));
    }
#line 6155 "build/parser.cpp"
    break;

  case 369: /* primary_expr: BIF_DECH LPAREN arg_list RPAREN  */
#line 1883 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("DECH", (yyvsp[-1].expr_list));
    }
#line 6163 "build/parser.cpp"
    break;

  case 370: /* primary_expr: BIF_DECPOS LPAREN arg_list RPAREN  */
#line 1886 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("DECPOS", (yyvsp[-1].expr_list));
    }
#line 6171 "build/parser.cpp"
    break;

  case 371: /* primary_expr: BIF_SPLIT LPAREN arg_list RPAREN  */
#line 1889 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("SPLIT", (yyvsp[-1].expr_list));
    }
#line 6179 "build/parser.cpp"
    break;

  case 372: /* primary_expr: BIF_CONCATARR LPAREN arg_list RPAREN  */
#line 1892 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("CONCATARR", (yyvsp[-1].expr_list));
    }
#line 6187 "build/parser.cpp"
    break;

  case 373: /* primary_expr: BIF_LEFT LPAREN arg_list RPAREN  */
#line 1895 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("LEFT", (yyvsp[-1].expr_list));
    }
#line 6195 "build/parser.cpp"
    break;

  case 374: /* primary_expr: BIF_RIGHT LPAREN arg_list RPAREN  */
#line 1898 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("RIGHT", (yyvsp[-1].expr_list));
    }
#line 6203 "build/parser.cpp"
    break;

  case 375: /* primary_expr: BIF_STR LPAREN arg_list RPAREN  */
#line 1901 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("STR", (yyvsp[-1].expr_list));
    }
#line 6211 "build/parser.cpp"
    break;

  case 376: /* primary_expr: BIF_SUBARR LPAREN arg_list RPAREN  */
#line 1904 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("SUBARR", (yyvsp[-1].expr_list));
    }
#line 6219 "build/parser.cpp"
    break;

  case 377: /* primary_expr: BIF_MAXARR LPAREN arg_list RPAREN  */
#line 1907 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("MAXARR", (yyvsp[-1].expr_list));
    }
#line 6227 "build/parser.cpp"
    break;

  case 378: /* primary_expr: BIF_MINARR LPAREN arg_list RPAREN  */
#line 1910 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("MINARR", (yyvsp[-1].expr_list));
    }
#line 6235 "build/parser.cpp"
    break;

  case 379: /* primary_expr: BIF_LIST LPAREN arg_list RPAREN  */
#line 1913 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("LIST", (yyvsp[-1].expr_list));
    }
#line 6243 "build/parser.cpp"
    break;

  case 380: /* primary_expr: BIF_RANGE LPAREN arg_list RPAREN  */
#line 1916 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("RANGE", (yyvsp[-1].expr_list));
    }
#line 6251 "build/parser.cpp"
    break;

  case 381: /* primary_expr: BIF_LOOKUPLT LPAREN arg_list RPAREN  */
#line 1919 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPLT", (yyvsp[-1].expr_list));
    }
#line 6259 "build/parser.cpp"
    break;

  case 382: /* primary_expr: BIF_LOOKUPGE LPAREN arg_list RPAREN  */
#line 1922 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPGE", (yyvsp[-1].expr_list));
    }
#line 6267 "build/parser.cpp"
    break;

  case 383: /* primary_expr: BIF_LOOKUPLE LPAREN arg_list RPAREN  */
#line 1925 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPLE", (yyvsp[-1].expr_list));
    }
#line 6275 "build/parser.cpp"
    break;

  case 384: /* primary_expr: BIF_LOOKUPGT LPAREN arg_list RPAREN  */
#line 1928 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPGT", (yyvsp[-1].expr_list));
    }
#line 6283 "build/parser.cpp"
    break;

  case 385: /* primary_expr: BIF_HOURS LPAREN expression RPAREN  */
#line 1931 "src/parser.y"
                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("HOURS", args);
    }
#line 6293 "build/parser.cpp"
    break;

  case 386: /* primary_expr: BIF_MINUTES LPAREN expression RPAREN  */
#line 1936 "src/parser.y"
                                           {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("MINUTES", args);
    }
#line 6303 "build/parser.cpp"
    break;

  case 387: /* primary_expr: BIF_SECONDS LPAREN expression RPAREN  */
#line 1941 "src/parser.y"
                                           {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("SECONDS", args);
    }
#line 6313 "build/parser.cpp"
    break;

  case 388: /* primary_expr: BIF_MSECONDS LPAREN expression RPAREN  */
#line 1946 "src/parser.y"
                                            {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("MSECONDS", args);
    }
#line 6323 "build/parser.cpp"
    break;

  case 389: /* primary_expr: BIF_PADDR LPAREN IDENTIFIER RPAREN  */
#line 1951 "src/parser.y"
                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::StringLiteral((yyvsp[-1].sval)));
        free((yyvsp[-1].sval));
        (yyval.expr) = make_bif("PADDR", args);
    }
#line 6334 "build/parser.cpp"
    break;

  case 390: /* primary_expr: BIF_PROC LPAREN RPAREN  */
#line 1957 "src/parser.y"
                             {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("PROC", empty);
    }
#line 6343 "build/parser.cpp"
    break;

  case 391: /* primary_expr: BIF_PROC  */
#line 1961 "src/parser.y"
               {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("PROC", empty);
    }
#line 6352 "build/parser.cpp"
    break;

  case 392: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_HOURS RPAREN  */
#line 1965 "src/parser.y"
                                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("HOURS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 6364 "build/parser.cpp"
    break;

  case 393: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_MINUTES RPAREN  */
#line 1972 "src/parser.y"
                                                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MINUTES"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 6376 "build/parser.cpp"
    break;

  case 394: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_SECONDS RPAREN  */
#line 1979 "src/parser.y"
                                                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("SECONDS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 6388 "build/parser.cpp"
    break;

  case 395: /* primary_expr: KW_ALL STRING_LITERAL  */
#line 1986 "src/parser.y"
                            {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::StringLiteral((yyvsp[0].sval)));
        free((yyvsp[0].sval));
        (yyval.expr) = make_bif("ALL", args);
    }
#line 6399 "build/parser.cpp"
    break;

  case 396: /* primary_expr: BIF_PASSED LPAREN ident RPAREN  */
#line 1992 "src/parser.y"
                                     {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::Identifier((yyvsp[-1].sval)));
        free((yyvsp[-1].sval));
        (yyval.expr) = make_bif("PASSED", args);
    }
#line 6410 "build/parser.cpp"
    break;

  case 397: /* primary_expr: BIF_OMITTED LPAREN ident RPAREN  */
#line 1998 "src/parser.y"
                                      {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::Identifier((yyvsp[-1].sval)));
        free((yyvsp[-1].sval));
        (yyval.expr) = make_bif("OMITTED", args);
    }
#line 6421 "build/parser.cpp"
    break;

  case 398: /* primary_expr: BIF_OCCUR LPAREN arg_list RPAREN  */
#line 2004 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("OCCUR", (yyvsp[-1].expr_list));
    }
#line 6429 "build/parser.cpp"
    break;

  case 399: /* primary_expr: INDICATOR  */
#line 2007 "src/parser.y"
                {
        (yyval.expr) = new rpg::IndicatorExpr((yyvsp[0].ival));
    }
#line 6437 "build/parser.cpp"
    break;

  case 400: /* primary_expr: KW_ON  */
#line 2010 "src/parser.y"
            {
        (yyval.expr) = new rpg::IntLiteral(1);  // *ON → true
    }
#line 6445 "build/parser.cpp"
    break;

  case 401: /* primary_expr: KW_OFF  */
#line 2013 "src/parser.y"
             {
        (yyval.expr) = new rpg::IntLiteral(0);  // *OFF → false
    }
#line 6453 "build/parser.cpp"
    break;

  case 402: /* primary_expr: KW_NULL  */
#line 2016 "src/parser.y"
              {
        (yyval.expr) = new rpg::Identifier("nullptr");
    }
#line 6461 "build/parser.cpp"
    break;

  case 403: /* primary_expr: KW_OMIT  */
#line 2019 "src/parser.y"
              {
        (yyval.expr) = new rpg::Identifier("nullptr");
    }
#line 6469 "build/parser.cpp"
    break;

  case 404: /* primary_expr: KW_BLANKS  */
#line 2022 "src/parser.y"
                {
        (yyval.expr) = new rpg::Identifier("RPG_BLANKS");
    }
#line 6477 "build/parser.cpp"
    break;

  case 405: /* primary_expr: KW_ZEROS  */
#line 2025 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier("RPG_ZEROS");
    }
#line 6485 "build/parser.cpp"
    break;

  case 406: /* primary_expr: KW_HIVAL  */
#line 2028 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier("RPG_HIVAL");
    }
#line 6493 "build/parser.cpp"
    break;

  case 407: /* primary_expr: KW_LOVAL  */
#line 2031 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier("RPG_LOVAL");
    }
#line 6501 "build/parser.cpp"
    break;

  case 408: /* primary_expr: LPAREN expression RPAREN  */
#line 2034 "src/parser.y"
                               {
        (yyval.expr) = (yyvsp[-1].expr);
    }
#line 6509 "build/parser.cpp"
    break;

  case 409: /* call_args_opt: %empty  */
#line 2041 "src/parser.y"
                { (yyval.expr_list) = nullptr; }
#line 6515 "build/parser.cpp"
    break;

  case 410: /* call_args_opt: call_arg_list  */
#line 2042 "src/parser.y"
                    { (yyval.expr_list) = (yyvsp[0].expr_list); }
#line 6521 "build/parser.cpp"
    break;

  case 411: /* call_arg_list: expression  */
#line 2046 "src/parser.y"
               {
        (yyval.expr_list) = new std::vector<rpg::Expression*>();
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 6530 "build/parser.cpp"
    break;

  case 412: /* call_arg_list: call_arg_list COLON expression  */
#line 2050 "src/parser.y"
                                     {
        (yyval.expr_list) = (yyvsp[-2].expr_list);
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 6539 "build/parser.cpp"
    break;

  case 413: /* arg_list: expression  */
#line 2058 "src/parser.y"
               {
        (yyval.expr_list) = new std::vector<rpg::Expression*>();
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 6548 "build/parser.cpp"
    break;

  case 414: /* arg_list: arg_list COLON expression  */
#line 2062 "src/parser.y"
                                {
        (yyval.expr_list) = (yyvsp[-2].expr_list);
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 6557 "build/parser.cpp"
    break;


#line 6561 "build/parser.cpp"

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

#line 2068 "src/parser.y"


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
