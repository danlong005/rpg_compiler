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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3092

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  221
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  66
/* YYNRULES -- Number of rules.  */
#define YYNRULES  366
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1161

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
       0,   184,   184,   189,   191,   196,   205,   208,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     253,   257,   261,   265,   273,   278,   283,   288,   293,   298,
     303,   308,   313,   318,   323,   328,   334,   340,   346,   350,
     354,   358,   362,   366,   370,   374,   378,   382,   389,   394,
     400,   405,   410,   415,   420,   425,   430,   435,   440,   445,
     450,   455,   463,   464,   465,   466,   467,   472,   479,   483,
     486,   492,   496,   505,   511,   520,   528,   537,   543,   549,
     555,   561,   564,   571,   582,   599,   619,   634,   658,   683,
     710,   740,   741,   746,   747,   748,   749,   750,   755,   758,
     766,   770,   774,   778,   782,   786,   790,   794,   799,   803,
     807,   811,   815,   819,   823,   827,   831,   837,   842,   847,
     852,   861,   864,   872,   876,   880,   884,   888,   892,   896,
     900,   905,   909,   913,   917,   921,   925,   929,   933,   937,
     943,   948,   953,   958,   968,   979,   989,   997,  1005,  1012,
    1020,  1028,  1040,  1049,  1058,  1068,  1078,  1086,  1097,  1100,
    1108,  1112,  1116,  1120,  1125,  1129,  1133,  1137,  1146,  1169,
    1170,  1178,  1187,  1188,  1194,  1203,  1212,  1222,  1232,  1242,
    1255,  1265,  1284,  1288,  1295,  1304,  1305,  1311,  1315,  1321,
    1325,  1326,  1334,  1335,  1343,  1344,  1350,  1351,  1356,  1361,
    1366,  1371,  1376,  1381,  1389,  1390,  1395,  1403,  1404,  1409,
    1417,  1418,  1426,  1427,  1434,  1435,  1436,  1437,  1438,  1439,
    1440,  1441,  1442,  1443,  1444,  1445,  1446,  1447,  1451,  1455,
    1456,  1457,  1458,  1459,  1460,  1461,  1462,  1463,  1464,  1465,
    1466,  1467,  1470,  1473,  1477,  1481,  1484,  1487,  1490,  1493,
    1496,  1499,  1502,  1505,  1508,  1511,  1514,  1517,  1521,  1524,
    1527,  1530,  1533,  1536,  1539,  1542,  1545,  1551,  1557,  1563,
    1569,  1575,  1581,  1584,  1587,  1590,  1593,  1597,  1601,  1604,
    1607,  1610,  1613,  1616,  1619,  1623,  1626,  1630,  1633,  1637,
    1644,  1651,  1658,  1663,  1668,  1673,  1677,  1681,  1684,  1687,
    1690,  1693,  1696,  1699,  1702,  1705,  1708,  1711,  1714,  1717,
    1720,  1723,  1726,  1729,  1732,  1735,  1738,  1741,  1744,  1749,
    1754,  1759,  1764,  1770,  1774,  1778,  1785,  1792,  1799,  1805,
    1811,  1817,  1820,  1823,  1826,  1829,  1832,  1835,  1838,  1841,
    1844,  1851,  1852,  1856,  1860,  1868,  1872
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

#define YYPACT_NINF (-690)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-207)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      78,  -690,   103,    21,  -690,  -119,   -87,   -49,   -33,  2490,
     -51,   259,   -51,  2490,   -30,   259,     6,  -690,  1846,   -25,
    2490,  2490,  2490,   259,    28,    31,    59,    81,    82,   259,
     259,   259,   259,  -690,    87,    93,    97,   259,     8,  -690,
    -690,  -690,  -690,    84,  -690,  -690,  -690,  -690,  -690,  -690,
    -690,  -690,  -690,  -690,  -690,  -690,  -690,  -690,  -690,  -690,
    -690,  -690,  -690,  -690,  -690,  -690,  -690,  -690,  -690,  -690,
    -690,  -690,  -690,   254,    30,  2490,  -690,  -690,  -690,  -690,
    -690,  -690,  -690,  -690,  2651,   112,   130,   136,   141,   149,
     166,   171,   196,   198,   201,   205,   223,   228,   232,   234,
     237,   251,   295,   315,   323,   331,   333,   343,   356,   361,
     368,   375,   381,   388,   395,   400,   411,   413,   420,   424,
     427,   440,   447,   448,   451,   452,   453,   454,   455,   457,
     458,   462,   464,   466,   467,   470,   471,   475,   476,   478,
     480,   485,   486,   487,   490,   491,   493,   494,   496,   497,
     498,   499,   500,   501,   502,   503,   505,   100,  -690,  -690,
    -690,  -690,  -690,  -690,  -690,  -690,  -690,  -690,  -690,  -690,
     506,  -690,  -690,  -690,  2490,  2812,   241,   110,   443,  -690,
     108,    99,  -152,  -690,   569,  -690,    25,   352,  -690,  -690,
    -690,  -690,  -690,  -690,  -690,  -690,  -690,  -690,  -690,  -690,
    -690,  -690,   359,   508,   510,  -690,   511,   259,  -690,   512,
     625,   513,   514,   515,   516,   652,  -690,  -690,  -690,   518,
     519,   520,   521,   522,   684,   265,     9,   529,   530,  2490,
    2490,    -8,   525,   527,   528,   531,   533,   535,   536,  -129,
     -93,   532,   542,   543,   538,   544,   545,   546,   547,   548,
     549,   552,   108,  2490,  2490,  2490,  2490,  2490,  2490,  2490,
    2490,  2490,  2490,  2490,  2490,   526,   541,  2490,  2490,  2490,
    2490,  2490,   550,   551,   553,  2490,  2490,  2490,  2007,  2168,
    2329,  2490,  2490,  2490,  2490,  2490,  2490,  2490,  2490,  2490,
    2490,  2490,  2490,  2490,  2490,  2490,  2490,  2490,  2490,  2490,
    2490,  2490,  2490,  2490,  2490,  2490,  2490,  2490,  2490,  2490,
    2490,  2490,  2490,  2490,  2490,  2490,  2490,  2490,  2490,  2490,
     559,   554,   259,   259,  2490,  -690,  2490,   555,   569,  -690,
    2490,  2490,  2651,  2651,  2651,  2651,  2651,  2651,  2651,  2651,
    2651,  2651,  2651,   563,  2490,  2490,   259,  2490,  -690,  -690,
     557,  -690,   561,  -690,  -690,  -690,  2490,  2490,    85,  -690,
     857,  -690,  -690,  -690,  -690,  -690,  -690,   562,   564,   565,
     566,   567,   568,   -46,   -90,   571,   572,  -690,  2490,  -690,
     560,   573,   574,   575,   577,  -690,  -690,  -690,   534,   583,
     585,   586,   588,   584,  -690,   589,  -690,  -690,  -690,  -690,
     594,   595,   596,   597,   598,   599,   587,  -690,  -690,    20,
      35,    60,   109,   132,   142,   153,   163,   168,   189,   217,
     248,  -690,  -690,   274,   276,   278,   280,   282,  -690,  -690,
    -690,   284,   286,   288,  -690,   290,  -690,   292,  -690,   296,
     600,   602,   603,   604,   298,   300,   302,   304,   306,   308,
     310,   605,   312,   316,   318,   324,   326,   328,   337,   339,
     344,   346,   348,   351,   353,   358,   370,   372,   376,   378,
     383,   385,   396,   417,   421,   608,   609,   610,   620,   621,
    -690,   622,   623,   437,  -690,   624,  -690,   443,  -690,   438,
     438,   438,   438,   438,   438,   438,  -152,  -152,  -690,  -690,
    -690,   560,   628,   629,   630,   259,  -690,    88,   924,   991,
     402,   631,   632,  -690,   679,   633,  -690,  1058,   686,   601,
     611,   613,   639,   640,   636,  -690,   641,  -690,   645,   606,
      57,   649,   666,   650,  2490,  -690,   590,   657,   658,   660,
     648,   661,   674,   675,   669,   672,   673,   676,   687,   688,
     683,  -690,  2490,  -690,  -690,  -690,  -690,  -690,  -690,  -690,
    -690,  -690,  -690,  -690,  -690,  -690,  -690,  -690,  -690,  -690,
    -690,  -690,  -690,  -690,  -690,  2490,  -690,  -690,  -690,  -690,
    -690,  -690,  -690,  -690,  -690,  -690,   307,  -690,  -690,  -690,
    -690,  -690,  -690,  -690,  -690,  -690,  -690,  -690,  -690,  -690,
    -690,  -690,  -690,  -690,  -690,  -690,  -690,  -690,  -690,  -690,
    -690,  -690,  -690,  -690,  -690,  -690,  -690,  -690,  -690,  -690,
    -690,  -690,   678,   593,   692,   693,  2490,  2490,  -690,  -690,
     694,  -690,   695,     5,   696,   697,   700,   701,   703,   698,
     -37,   699,    92,   706,   707,   704,   702,   124,  -690,  -690,
     715,  -690,  -690,   710,   257,   357,   330,   719,   720,   716,
     725,   730,   321,   321,   321,   321,   321,   733,  -690,   734,
     736,   738,   739,   740,   742,   743,  -690,  2490,   737,  -690,
     745,  -690,  -690,   -64,   -18,   350,  1125,  -690,  1212,  -690,
     405,   754,  -690,  -690,  -690,   760,   758,   756,   762,   764,
     239,  -690,   761,   763,   708,   -13,  -690,   461,   765,   768,
     769,   770,  1279,  -690,   759,   942,   771,  -690,  -690,   772,
     953,  -690,   775,   778,   781,  -690,   792,   795,   974,   797,
     802,   982,   804,   808,   806,   807,   812,   813,  -690,   821,
     824,   825,   826,   827,   828,   441,  -690,  -690,  -690,  -690,
    -690,  -690,   829,  -690,   830,  2490,  -690,  2490,  -690,   832,
     833,  -690,   831,  -690,   837,  -690,   465,   836,   838,   839,
     841,   842,   845,  -690,   850,   859,  -690,   860,   862,   864,
     869,   875,   876,   878,   879,   877,   885,   889,  2490,   843,
     890,   882,  -690,  2490,   883,  -690,   891,  2490,   898,   893,
     899,  -690,   218,   321,  -690,  -690,  -690,  -690,  -690,  -690,
    -690,   897,   895,   896,   901,   902,   903,   904,  -690,  1346,
    -690,   900,  1413,   908,  1480,  -690,  -690,    38,  -690,    64,
    -690,   909,   910,   913,   915,   931,   932,   936,   941,   905,
    -690,  -690,   943,   945,   946,   947,   949,   907,   944,   952,
     935,  -690,   958,  2490,   956,   957,  2490,   959,   960,   961,
    2490,   962,   963,  2490,   964,  1005,   966,   969,   972,   973,
    -690,  -690,  -690,  -690,  -690,  -690,  -690,   540,  -690,   975,
    -690,   977,    40,   978,   965,   243,  -690,   979,   138,   985,
     987,   989,   992,   971,   993,   995,   986,   997,   134,   146,
    1002,  1004,  1010,  1011,  1012,  1017,  1018,  1019,   998,  -690,
    1020,  1021,  1022,  1023,    73,  1024,  1025,  1026,  1027,  1028,
    1029,    98,  1031,  2490,  1033,  -690,  -690,  1547,  -690,  1614,
    -690,  1034,  -690,   469,  1040,  1043,  1044,  1045,  1046,  -690,
    1035,  1047,  1048,  1050,  1016,   -62,   -32,   -31,  1052,  1055,
    1059,  1060,  1061,  1062,  1064,  1065,  1069,  -690,  -690,  -690,
    1066,  1071,  -690,  -690,  1072,  1074,  1082,  -690,  -690,  -690,
    1085,  -690,  -690,  1087,  1092,  1093,  -690,  2490,  1091,  1094,
    1096,  1098,  -690,   607,  1056,  1099,  1107,  1110,  1103,  1116,
    1117,  1118,  1120,  -690,   -28,   -27,   -26,  1121,   -23,  -690,
     -19,  -690,   -15,  -690,  1114,  -690,  -690,  -690,  -690,  -690,
    -690,  -690,  1119,  1126,  -690,  -690,  -690,  -690,  -690,  -690,
    -690,  -690,  1122,  1127,  1128,  -690,  -690,   790,  1129,  1131,
    1123,  1135,  1136,  1139,  1138,  1146,  1147,  1148,  1151,  1159,
    -690,  1160,  -690,  1161,  -690,  1162,  1137,  -690,  1165,  -690,
    1166,  -690,   -21,  1163,  -690,  1164,  -690,  -690,  1176,  1179,
    -690,  -690,  1177,  1178,  1180,  1181,   -20,   -16,   -14,  1185,
    1184,  -690,  -690,  -690,   -11,  1194,  1349,  1350,   -10,  -690,
    -690,  -690,  -690,  -690,  1681,    -6,    16,    29,  1191,    -7,
    -690,    -5,  -690,    -4,  -690,  1186,  -690,  1192,  -690,  1190,
    1193,  1195,  1197,  -690,  1748,  1203,  1205,  -690,  1216,  -690,
    1217,  -690,  1218,  1224,  -690,  1225,  -690,  1226,  -690,    32,
    -690,  1219,  1230,  1231,  1357,  1232,  -690,  -690,  -690,  -690,
      33,  1358,  1397,  1398,    -3,  -690,  -690,  -690,  -690,  1240,
    -690,  1246,  -690,  1244,  1245,  1247,  1249,  -690,  1252,  -690,
    1253,  1254,  1255,  1412,  -690,  -690,  -690,  -690,  1256,  1260,
    -690
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       0,     3,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     5,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    89,     0,     0,     0,     0,    88,     4,
       8,     9,    10,     0,    11,    12,    33,    34,    35,    13,
      14,    15,    38,    25,    24,    27,    28,    29,    32,    30,
      31,    36,    37,    26,    16,    17,    18,    19,    20,    21,
      22,    23,    39,     0,     0,     0,   355,   353,   356,   357,
     358,   359,   354,   352,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   344,     0,     0,     0,     0,   249,   250,
     251,   252,   258,   259,   260,   255,   256,   253,   254,   257,
     248,   261,   262,   263,     0,     0,     0,   209,   210,   212,
     214,   216,   224,   227,   230,   232,    88,     0,   235,   236,
     237,   238,   245,   246,   247,   242,   243,   239,   240,   244,
     241,   234,     0,     0,     0,    98,     0,     0,   102,     0,
       0,     0,     0,     0,     0,     0,   207,   208,     6,     0,
       0,     0,     0,     0,   111,   113,     0,     0,     0,   361,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   215,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   348,   361,     0,   231,    99,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    97,   170,
       0,   101,     0,     6,     6,     6,     0,     0,   205,   202,
       0,     6,   166,   168,   169,   167,   112,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   178,     0,    90,
     363,     0,   362,     0,     0,    40,    41,    42,     0,     0,
       0,     0,     0,     0,    59,     0,    60,    61,    58,    62,
       0,     0,     0,     0,     0,     0,     0,    87,   365,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   315,   316,     0,     0,     0,     0,     0,   277,   296,
     297,     0,     0,     0,   304,     0,   306,     0,   308,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     343,     0,     0,     0,   363,     0,   360,   211,   213,   217,
     218,   221,   222,   219,   220,   223,   225,   226,   228,   229,
     233,     0,     0,     0,     0,     0,   100,     0,     0,     0,
       0,     0,     0,   203,     0,     0,     7,     0,     0,     0,
       0,     0,     0,     0,     0,   141,     0,   178,     0,     0,
       0,     0,    91,     0,     0,    93,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   265,     0,   266,   267,   268,   269,   270,   271,   272,
     273,   274,   275,   276,   300,   301,   302,   298,   299,   294,
     295,   278,   303,   305,   307,     0,   312,   313,   314,   279,
     280,   281,   282,   283,   284,   285,     0,   292,   293,   317,
     318,   319,   329,   324,   320,   321,   322,   323,   325,   326,
     327,   328,   330,   331,   332,   333,   334,   335,   336,   337,
     338,   339,   340,   341,   342,   349,   350,   351,   264,    94,
      95,    96,     0,   192,     0,     0,     0,     0,     6,     6,
       0,     6,     0,   113,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   179,     6,
       0,   103,   364,     0,    82,    82,    82,     0,     0,     0,
       0,     0,    82,    82,    82,    82,    82,     0,   366,     0,
       0,     0,     0,     0,     0,     0,   171,     0,     0,   190,
       0,   194,   195,     0,     0,     0,     0,   201,     0,   165,
     113,     0,   115,   116,   114,     0,     0,     0,     0,     0,
       0,   142,     0,     0,     0,     0,   173,     0,     0,     0,
       0,     0,     0,    92,     0,     0,     0,    83,    84,     0,
      85,    86,     0,     0,     0,    85,     0,     0,     0,     0,
       0,    85,     0,     0,     0,     0,     0,     0,    67,     0,
       0,     0,     0,     0,     0,     0,   288,   287,   286,   289,
     290,   291,     0,     6,     0,     0,     6,     0,     6,     0,
       0,   118,     0,   141,     0,   104,     0,     0,     0,     0,
       0,     0,     0,   172,     0,     0,   176,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    44,     0,     0,    45,     0,     0,     0,     0,
       0,    46,    82,    82,    80,    81,    68,    69,    70,    71,
      72,     0,     0,     0,     0,     0,     0,     0,     6,     0,
     188,     0,     0,     0,     0,   164,   118,     0,   117,     0,
     141,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     178,   178,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   200,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      73,   309,   310,   311,   345,   346,   347,     0,     6,     0,
       6,     0,     0,     0,     0,     0,   119,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    43,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    47,    48,     0,   196,     0,
     198,     0,     6,     0,     0,     0,     0,     0,     0,   106,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   181,   182,   180,
       0,     0,    53,    75,     0,     0,     0,    64,    55,    65,
       0,    52,    74,     0,     0,     0,    63,     0,     0,     0,
       0,     0,     6,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   105,     0,     0,     0,     0,     0,   145,
       0,   147,     0,   143,     0,   159,   175,   174,   177,   185,
     186,   184,     0,     0,    50,    57,    78,    79,    49,    56,
      76,    77,     0,     0,     0,   197,   199,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     153,     0,   155,     0,   151,     0,     0,   146,     0,   148,
       0,   144,     0,     0,   183,     0,    54,    66,     0,     0,
       6,   107,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   154,   156,   152,     0,     0,     0,     0,     0,   149,
     187,    51,     6,   108,     0,     0,     0,     0,     0,     0,
     122,     0,   124,     0,   120,     0,   136,     0,   157,     0,
       0,     0,     0,   150,     0,     0,     0,   130,     0,   132,
       0,   128,     0,     0,   123,     0,   125,     0,   121,     0,
     158,     0,     0,     0,     0,     0,   109,   131,   133,   129,
       0,     0,     0,     0,     0,   126,   161,   162,   160,     0,
     110,     0,   134,     0,     0,     0,     0,   127,     0,   135,
       0,     0,     0,     0,   163,   138,   139,   137,     0,     0,
     140
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -690,  -690,  -690,  -347,  1460,  -690,  -690,  -437,  -690,    89,
    -690,  -690,  -690,  -690,  -690,  -690,  -690,  -690,  -690,  -690,
    -690,  -690,  -556,   642,  -690,  -689,  -690,  -690,  -690,  -690,
    -690,  -690,  -690,  -690,  -690,  -690,  -526,  -690,  -690,  -690,
    -690,  -690,  -690,  -690,  -690,  -690,  -690,  -690,  1111,  -690,
    -690,  -690,    -9,  -690,  1140,  1141,  1389,    58,  -134,   313,
    1299,     0,  -690,  1167,  -690,  2768
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,   360,   516,    40,    41,   723,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,   367,   373,   827,   886,   640,   701,    55,    56,    57,
      58,    59,    60,    61,    62,    63,   530,   648,    64,   623,
     679,   680,    65,    66,    67,    68,    69,   358,   359,   514,
      70,    71,   408,   177,   178,   179,   180,   181,   182,   183,
     184,   202,   185,   381,   382,   409
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     176,   642,   384,   524,   204,   755,   507,   508,   509,   209,
     526,   211,   212,   213,   517,   206,   368,   369,   370,   371,
    1046,    -2,     5,   214,  1048,     6,     7,     8,  1050,   220,
     221,   222,   223,  1102,   998,    33,  1113,   227,  1115,  1117,
    1146,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   757,     9,    10,    11,    12,    13,    14,   698,    15,
      16,   393,   341,   342,  1000,  1002,   251,   699,  1039,  1041,
    1043,    17,    18,    19,   829,  1078,  1089,   691,   394,    20,
    1091,     1,  1093,    21,    22,  1097,    23,   775,    72,     5,
    1106,    24,     6,     7,     8,    25,    26,    27,   395,   187,
      28,   203,    29,     4,    30,    31,    32,    33,   374,   375,
     376,    34,  1108,   228,   396,    35,    73,   527,    36,     9,
      10,    11,    12,    13,    14,  1110,    15,    16,  1134,  1141,
     228,   883,   244,   931,   760,   708,   709,   710,   711,    18,
      19,   888,   884,   756,   884,   999,    20,  -189,  -189,  -189,
      21,    22,   186,    23,    74,   645,   357,   512,    24,   887,
     646,   525,    25,    26,    27,   327,   700,    28,   699,    29,
      75,    30,    31,    32,    33,  1001,  1003,   205,    34,  1040,
    1042,  1044,    35,   210,  1047,    36,  1079,  1090,  1049,   758,
     703,  1092,  1051,  1094,   776,   646,  1098,  1103,   330,   385,
    1114,  1107,  1116,  1118,  1147,   496,   497,   350,   690,   245,
     246,   247,   248,   249,   250,   207,   377,   229,   727,   733,
     380,   383,    37,  1109,    38,   739,   740,   741,   742,   743,
     551,   552,   950,   940,   344,   215,  1111,   646,   216,  1135,
    1142,   885,   699,   885,   951,   553,   552,   865,   866,   646,
     767,   768,   769,   770,   934,   935,   936,   937,   717,   718,
     647,   231,   232,   233,   725,   721,   217,   700,   965,   966,
     554,   552,   440,   441,   442,   443,   368,   369,   370,   371,
     967,   685,   686,   451,   688,   219,   715,   716,   218,    37,
     224,    38,   230,   974,   975,   647,   225,   717,   718,   719,
     226,   338,   712,   720,   721,   976,   325,   475,   476,   477,
     478,   339,   340,   372,   898,   899,   332,   484,   867,   555,
     552,   253,   481,   482,   333,   334,   335,   336,   337,   670,
     671,   672,   673,   674,   675,   501,   502,   647,   504,   254,
     771,   700,   556,   552,   938,   255,   503,   510,   511,   647,
     256,     5,   557,   552,     6,     7,     8,   722,   257,   728,
     729,   717,   718,   558,   552,   868,   869,   725,   721,   531,
     717,   718,   730,   559,   552,   258,   731,   721,   560,   552,
     259,     9,    10,    11,    12,    13,    14,   724,    15,    16,
     489,   490,   491,   492,   493,   494,   495,   717,   718,   561,
     552,    18,    19,   725,   721,   260,   819,   261,    20,   822,
     262,   824,    21,    22,   263,    23,   368,   369,   370,   371,
      24,  -204,  -204,  -204,    25,    26,    27,   562,   552,    28,
     732,    29,   264,    30,    31,    32,    33,   265,   188,   189,
      34,   266,   190,   267,    35,   191,   268,    36,   329,   192,
     193,   194,   195,   196,   197,   198,   199,   726,   563,   552,
     269,   200,   201,   812,   813,   814,   815,   816,   817,   626,
     627,   877,   777,   778,   779,   780,   831,   832,   833,   834,
     984,   985,   986,   987,   564,   552,   565,   552,   566,   552,
     567,   552,   568,   552,   569,   552,   570,   552,   571,   552,
     572,   552,   573,   552,   270,   622,   574,   552,   579,   552,
     580,   552,   581,   552,   582,   552,   583,   552,   584,   552,
     585,   552,   587,   552,   271,   652,   588,   552,   589,   552,
     331,   927,   272,   929,   590,   552,   591,   552,   592,   552,
     273,     5,   274,   668,     6,     7,     8,   593,   552,   594,
     552,    37,   275,    38,   595,   552,   596,   552,   597,   552,
     345,   598,   552,   599,   552,   276,   669,   346,   600,   552,
     277,     9,    10,    11,    12,    13,    14,   278,    15,    16,
     601,   552,   602,   552,   279,   983,   603,   552,   604,   552,
     280,    18,    19,   605,   552,   606,   552,   281,    20,  -191,
    -191,  -191,    21,    22,   282,    23,   607,   552,     5,   283,
      24,     6,     7,     8,    25,    26,    27,   683,   684,    28,
     284,    29,   285,    30,    31,    32,    33,   608,   552,   286,
      34,   609,   552,   287,    35,  1027,   288,    36,     9,    10,
      11,    12,    13,    14,  1028,    15,    16,   617,   552,   289,
     339,   340,   677,   678,   498,   499,   290,   291,    18,    19,
     292,   293,   294,   295,   296,    20,   297,   298,   752,    21,
      22,   299,    23,   300,   343,   301,   302,    24,   352,   303,
     304,    25,    26,    27,   305,   306,    28,   307,    29,   308,
      30,    31,    32,    33,   309,   310,   311,    34,  1029,   312,
     313,    35,   314,   315,    36,   316,   317,   318,   319,   320,
     321,   322,   323,  1084,   324,   326,   347,   348,   349,   351,
     353,   354,   355,   357,   356,   361,   362,   363,   364,   365,
     366,   378,   386,   379,   387,  1104,   421,   388,   537,   397,
     389,    37,   390,    38,   391,   392,   821,   400,   823,   398,
     399,   422,   630,   401,   402,   403,   404,   405,   406,   407,
     428,   429,   479,   430,   480,   486,   500,   505,   506,   518,
     532,   650,   550,   519,   520,   521,   522,   523,   633,   854,
     528,   529,   535,   533,   858,   534,   536,   538,   861,   539,
     540,     5,   541,   542,     6,     7,     8,   544,   543,   545,
     546,   547,   548,   549,   653,   634,   754,   774,    37,   644,
      38,   575,   576,   577,   578,   635,   586,   636,   610,   611,
     612,     9,    10,    11,    12,    13,    14,  1058,    15,    16,
     613,   614,   615,   616,   618,   619,   620,   621,   628,   629,
     631,    18,    19,   637,   910,   639,   638,   913,    20,   643,
     641,   917,    21,    22,   920,    23,   649,   651,     5,   657,
      24,     6,     7,     8,    25,    26,    27,   654,   655,    28,
     656,    29,   658,    30,    31,    32,    33,   659,   660,   661,
      34,  1059,   662,   663,    35,   676,   664,    36,     9,    10,
      11,    12,    13,    14,   667,    15,    16,   665,   666,   681,
     682,   687,   689,   702,   697,   707,   692,   693,    18,    19,
     694,   706,   695,   696,   978,    20,   704,   705,   713,    21,
      22,   714,    23,   734,   735,     5,   736,    24,     6,     7,
       8,    25,    26,    27,   515,   737,    28,   738,    29,   744,
      30,    31,    32,    33,   753,   745,   746,    34,   747,   748,
     749,    35,   750,   751,    36,     9,    10,    11,    12,    13,
      14,   761,    15,    16,   762,   763,   764,   766,  1022,   765,
     773,   772,   787,   786,   781,    18,    19,   782,   783,   784,
     788,   789,    20,   790,   791,   792,    21,    22,   624,    23,
     793,    37,     5,    38,    24,     6,     7,     8,    25,    26,
      27,   794,   795,    28,   796,    29,   797,    30,    31,    32,
      33,   798,   799,   800,    34,   801,   802,   803,    35,   804,
     805,    36,     9,    10,    11,    12,    13,    14,   806,    15,
      16,   807,   808,   809,   810,   922,   818,   820,   811,   825,
     826,   828,    18,    19,   830,   835,   855,   836,   837,    20,
     838,   839,   840,    21,    22,   625,    23,   841,    37,     5,
      38,    24,     6,     7,     8,    25,    26,    27,   842,   843,
      28,   844,    29,   845,    30,    31,    32,    33,   846,   847,
     848,    34,   849,   850,   851,    35,   857,   859,    36,     9,
      10,    11,    12,    13,    14,   852,    15,    16,   853,   856,
     860,   862,   863,   864,   870,   871,   872,   878,   897,    18,
      19,   873,   874,   875,   876,   880,    20,   905,   889,   890,
      21,    22,   891,    23,   892,    37,     5,    38,    24,     6,
       7,     8,    25,    26,    27,   893,   894,    28,   632,    29,
     895,    30,    31,    32,    33,   896,   908,   900,    34,   901,
     902,   903,    35,   904,   906,    36,     9,    10,    11,    12,
      13,    14,   907,    15,    16,   909,   911,   912,   933,   914,
     915,   916,   918,   919,   921,   923,    18,    19,   924,   925,
     926,   945,   928,    20,   930,   932,   939,    21,    22,   941,
      23,   942,    37,   943,    38,    24,   944,   948,  -206,    25,
      26,    27,   960,   946,    28,   947,    29,   949,    30,    31,
      32,    33,   952,     5,   953,    34,     6,     7,     8,    35,
     954,   955,    36,   956,   957,   958,   959,   997,   962,   963,
     961,   968,   969,   964,   971,   972,   970,   979,  1099,   973,
     977,   982,   993,     9,    10,    11,    12,    13,    14,   988,
      15,    16,   989,   990,   991,   992,  1004,   994,   995,    37,
     996,    38,  1005,    18,    19,  1030,  1006,  1007,  1008,  1009,
      20,  1010,  1011,  1012,    21,    22,  1013,    23,  1014,  1015,
       5,  1016,    24,     6,     7,     8,    25,    26,    27,  1017,
     759,    28,  1018,    29,  1019,    30,    31,    32,    33,  1020,
    1021,  1023,    34,  1025,  1024,  1026,    35,  1034,  1031,    36,
       9,    10,    11,    12,    13,    14,  1032,    15,    16,  1033,
    1035,  1036,  1037,  1038,  1052,  1045,    37,  1062,    38,  1053,
      18,    19,  1055,  1054,  1056,  1057,  1060,    20,  1061,  1063,
    1064,    21,    22,  1065,    23,   785,  1075,     5,  1066,    24,
       6,     7,     8,    25,    26,    27,  1067,  1068,    28,  1069,
      29,  1070,    30,    31,    32,    33,  1071,  1072,  1073,    34,
    1080,  1081,  1074,    35,  1076,  1077,    36,     9,    10,    11,
      12,    13,    14,  1082,    15,    16,  1083,  1085,  1086,  1095,
    1087,  1096,  1088,  1100,  1101,  1112,  1119,    18,    19,  1120,
    1121,  1139,  1143,  1122,    20,  1123,  1124,  -193,    21,    22,
    1126,    23,  1127,    37,     5,    38,    24,     6,     7,     8,
      25,    26,    27,  1128,  1129,    28,  1136,    29,  1130,    30,
      31,    32,    33,  1131,  1132,  1133,    34,  1137,  1138,  1140,
      35,  1144,  1145,    36,     9,    10,    11,    12,    13,    14,
    1148,    15,    16,  1149,  1150,  1151,  1158,  1152,  1153,  1154,
    1155,  1156,  1157,    39,    18,    19,  1159,  1160,   882,   513,
     487,    20,   488,   252,   328,    21,    22,     0,    23,   879,
      37,     5,    38,    24,     6,     7,     8,    25,    26,    27,
       0,     0,    28,   485,    29,     0,    30,    31,    32,    33,
       0,     0,     0,    34,     0,     0,     0,    35,     0,     0,
      36,     9,    10,    11,    12,    13,    14,     0,    15,    16,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    18,    19,     0,     0,     0,     0,     0,    20,     0,
       0,     0,    21,    22,     0,    23,   881,    37,     5,    38,
      24,     6,     7,     8,    25,    26,    27,     0,     0,    28,
       0,    29,     0,    30,    31,    32,    33,     0,     0,     0,
      34,     0,     0,     0,    35,     0,     0,    36,     9,    10,
      11,    12,    13,    14,     0,    15,    16,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    18,    19,
       0,     0,     0,     0,     0,    20,     0,     0,     0,    21,
      22,     0,    23,   980,    37,     5,    38,    24,     6,     7,
       8,    25,    26,    27,     0,     0,    28,     0,    29,     0,
      30,    31,    32,    33,     0,     0,     0,    34,     0,     0,
       0,    35,     0,     0,    36,     9,    10,    11,    12,    13,
      14,     0,    15,    16,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,    19,     0,     0,     0,
       0,     0,    20,     0,     0,     0,    21,    22,     0,    23,
     981,    37,     5,    38,    24,     6,     7,     8,    25,    26,
      27,     0,     0,    28,     0,    29,     0,    30,    31,    32,
      33,     0,     0,     0,    34,     0,     0,     0,    35,     0,
       0,    36,     9,    10,    11,    12,    13,    14,     0,    15,
      16,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    18,    19,     0,     0,     0,     0,     0,    20,
       0,     0,     0,    21,    22,     0,    23,     0,    37,     5,
      38,    24,     6,     7,     8,    25,    26,    27,     0,     0,
      28,     0,    29,     0,    30,    31,    32,    33,     0,     0,
       0,    34,  1105,     0,     0,    35,     0,     0,    36,     9,
      10,    11,    12,    13,    14,     0,    15,    16,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    18,
      19,     0,     0,     0,     0,     0,    20,     0,     0,     0,
      21,    22,     0,    23,     0,    37,     0,    38,    24,     0,
       0,     0,    25,    26,    27,     0,     0,    28,     0,    29,
       0,    30,    31,    32,    33,     0,     0,     0,    34,  1125,
       0,     0,    35,     0,     0,    36,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    76,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    37,     0,    38,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    77,
      78,    79,    80,    81,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    82,     0,
       0,     0,    83,     0,     0,    84,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    37,
       0,    38,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,     0,    76,   160,
       0,     0,   161,     0,     0,     0,   162,   163,   164,   165,
     166,   167,   168,   169,     0,     0,     0,     0,     0,   170,
     171,   172,   173,   208,     0,   174,     0,     0,     0,   175,
      77,    78,    79,    80,    81,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    82,
       0,     0,     0,    83,     0,     0,    84,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,     0,    76,
     160,     0,     0,   161,     0,     0,     0,   162,   163,   164,
     165,   166,   167,   168,   169,     0,     0,     0,     0,     0,
     170,   171,   172,   173,     0,     0,   174,   434,     0,     0,
     175,    77,    78,    79,    80,    81,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      82,     0,     0,     0,    83,     0,     0,    84,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,     0,
      76,   160,     0,     0,   161,     0,     0,     0,   162,   163,
     164,   165,   166,   167,   168,   169,     0,     0,     0,     0,
       0,   170,   171,   172,   173,     0,     0,   174,   436,     0,
       0,   175,    77,    78,    79,    80,    81,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    82,     0,     0,     0,    83,     0,     0,    84,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    85,    86,    87,    88,    89,
      90,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
       0,    76,   160,     0,     0,   161,     0,     0,     0,   162,
     163,   164,   165,   166,   167,   168,   169,     0,     0,     0,
       0,     0,   170,   171,   172,   173,     0,     0,   174,   438,
       0,     0,   175,    77,    78,    79,    80,    81,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    82,     0,     0,     0,    83,     0,     0,    84,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,     0,    76,   160,     0,     0,   161,     0,     0,     0,
     162,   163,   164,   165,   166,   167,   168,   169,     0,     0,
       0,     0,     0,   170,   171,   172,   173,     0,     0,   174,
       0,     0,     0,   175,    77,    78,    79,    80,    81,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    82,     0,     0,     0,    83,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,     0,    76,   160,     0,     0,   161,     0,     0,
       0,   162,   163,   164,   165,   166,   167,   168,   169,     0,
       0,     0,     0,     0,   170,   171,   172,   173,     0,     0,
     174,     0,     0,     0,   175,    77,    78,    79,    80,    81,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    82,     0,     0,     0,    83,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    85,    86,
      87,    88,    89,    90,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,     0,     0,   160,     0,     0,   161,     0,
       0,     0,   162,   163,   164,   165,   166,   167,   168,   169,
       0,     0,     0,     0,     0,   170,   171,   172,   173,     0,
       0,   174,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   419,   420,     0,     0,   423,   424,   425,   426,   427,
       0,     0,     0,   431,   432,   433,   435,   437,   439,     0,
       0,     0,     0,   444,   445,   446,   447,   448,   449,   450,
       0,   452,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464,   465,   466,   467,   468,   469,   470,
     471,   472,   473,   474,     0,     0,     0,     0,     0,     0,
       0,     0,   483
};

static const yytype_int16 yycheck[] =
{
       9,   527,    10,    49,    13,    69,   353,   354,   355,    18,
     100,    20,    21,    22,   361,    15,    11,    12,    13,    14,
      43,     0,     1,    23,    43,     4,     5,     6,    43,    29,
      30,    31,    32,    43,    96,    86,    43,    37,    43,    43,
      43,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    69,    31,    32,    33,    34,    35,    36,    95,    38,
      39,   190,   214,   215,    96,    96,    75,   104,    96,    96,
      96,    50,    51,    52,   763,    96,    96,   633,   207,    58,
      96,     3,    96,    62,    63,    96,    65,   100,   207,     1,
      96,    70,     4,     5,     6,    74,    75,    76,   191,    10,
      79,    12,    81,     0,    83,    84,    85,    86,    99,   100,
     101,    90,    96,   105,   207,    94,   203,   207,    97,    31,
      32,    33,    34,    35,    36,    96,    38,    39,    96,    96,
     105,    93,   102,    93,   690,    11,    12,    13,    14,    51,
      52,   830,   104,   207,   104,   207,    58,    59,    60,    61,
      62,    63,   203,    65,   203,    98,    71,    72,    70,    95,
     103,   207,    74,    75,    76,   174,   203,    79,   104,    81,
     203,    83,    84,    85,    86,   207,   207,   207,    90,   207,
     207,   207,    94,   208,   207,    97,   207,   207,   207,   207,
      98,   207,   207,   207,   207,   103,   207,   207,    88,   207,
     207,   207,   207,   207,   207,   339,   340,   207,   203,   179,
     180,   181,   182,   183,   184,   209,   207,   209,   655,   656,
     229,   230,   201,   207,   203,   662,   663,   664,   665,   666,
     210,   211,    98,    95,   209,   207,   207,   103,   207,   207,
     207,   203,   104,   203,    98,   210,   211,    29,    30,   103,
      11,    12,    13,    14,    11,    12,    13,    14,    40,    41,
     203,     7,     8,     9,    46,    47,   207,   203,   195,   196,
     210,   211,   281,   282,   283,   284,    11,    12,    13,    14,
     207,   628,   629,   292,   631,   203,    29,    30,   207,   201,
     203,   203,   208,   195,   196,   203,   203,    40,    41,    42,
     203,   202,   649,    46,    47,   207,   206,   316,   317,   318,
     319,   212,   213,    48,   840,   841,   208,   326,   100,   210,
     211,   209,   322,   323,   216,   217,   218,   219,   220,    22,
      23,    24,    25,    26,    27,   344,   345,   203,   347,   209,
     101,   203,   210,   211,   101,   209,   346,   356,   357,   203,
     209,     1,   210,   211,     4,     5,     6,   100,   209,    29,
      30,    40,    41,   210,   211,   802,   803,    46,    47,   378,
      40,    41,    42,   210,   211,   209,    46,    47,   210,   211,
     209,    31,    32,    33,    34,    35,    36,    30,    38,    39,
     332,   333,   334,   335,   336,   337,   338,    40,    41,   210,
     211,    51,    52,    46,    47,   209,   753,   209,    58,   756,
     209,   758,    62,    63,   209,    65,    11,    12,    13,    14,
      70,    71,    72,    73,    74,    75,    76,   210,   211,    79,
     100,    81,   209,    83,    84,    85,    86,   209,   179,   180,
      90,   209,   183,   209,    94,   186,   209,    97,   207,   190,
     191,   192,   193,   194,   195,   196,   197,   100,   210,   211,
     209,   202,   203,    22,    23,    24,    25,    26,    27,    67,
      68,   818,    11,    12,    13,    14,    11,    12,    13,    14,
      11,    12,    13,    14,   210,   211,   210,   211,   210,   211,
     210,   211,   210,   211,   210,   211,   210,   211,   210,   211,
     210,   211,   210,   211,   209,   505,   210,   211,   210,   211,
     210,   211,   210,   211,   210,   211,   210,   211,   210,   211,
     210,   211,   210,   211,   209,   534,   210,   211,   210,   211,
      87,   878,   209,   880,   210,   211,   210,   211,   210,   211,
     209,     1,   209,   552,     4,     5,     6,   210,   211,   210,
     211,   201,   209,   203,   210,   211,   210,   211,   210,   211,
     208,   210,   211,   210,   211,   209,   575,   208,   210,   211,
     209,    31,    32,    33,    34,    35,    36,   209,    38,    39,
     210,   211,   210,   211,   209,   932,   210,   211,   210,   211,
     209,    51,    52,   210,   211,   210,   211,   209,    58,    59,
      60,    61,    62,    63,   209,    65,   210,   211,     1,   209,
      70,     4,     5,     6,    74,    75,    76,   626,   627,    79,
     209,    81,   209,    83,    84,    85,    86,   210,   211,   209,
      90,   210,   211,   209,    94,   982,   209,    97,    31,    32,
      33,    34,    35,    36,    37,    38,    39,   210,   211,   209,
     212,   213,    59,    60,   341,   342,   209,   209,    51,    52,
     209,   209,   209,   209,   209,    58,   209,   209,   677,    62,
      63,   209,    65,   209,   105,   209,   209,    70,    53,   209,
     209,    74,    75,    76,   209,   209,    79,   209,    81,   209,
      83,    84,    85,    86,   209,   209,   209,    90,    91,   209,
     209,    94,   209,   209,    97,   209,   209,   209,   209,   209,
     209,   209,   209,  1060,   209,   209,   208,   207,   207,   207,
     207,   207,   207,    71,   208,   207,   207,   207,   207,   207,
      46,   202,   207,   203,   207,  1082,   210,   209,   204,   207,
     209,   201,   209,   203,   209,   209,   755,   209,   757,   207,
     207,   210,    73,   209,   209,   209,   209,   209,   209,   207,
     210,   210,   203,   210,   210,   210,   203,   210,   207,   207,
     210,   105,   185,   209,   209,   209,   209,   209,    92,   788,
     209,   209,   207,   210,   793,   211,   209,   204,   797,   204,
     204,     1,   204,   209,     4,     5,     6,   203,   209,   204,
     204,   204,   204,   204,   214,   204,    61,    99,   201,   203,
     203,   211,   210,   210,   210,   204,   211,   204,   210,   210,
     210,    31,    32,    33,    34,    35,    36,    37,    38,    39,
     210,   210,   210,   210,   210,   207,   207,   207,   207,   207,
     207,    51,    52,   204,   853,   209,   206,   856,    58,   204,
     209,   860,    62,    63,   863,    65,   207,   207,     1,   211,
      70,     4,     5,     6,    74,    75,    76,   210,   210,    79,
     210,    81,   211,    83,    84,    85,    86,   203,   203,   210,
      90,    91,   210,   210,    94,   207,   210,    97,    31,    32,
      33,    34,    35,    36,   211,    38,    39,   210,   210,   207,
     207,   207,   207,   204,   206,   203,   210,   210,    51,    52,
     210,   207,   211,   210,   923,    58,   210,   210,   203,    62,
      63,   211,    65,   204,   204,     1,   210,    70,     4,     5,
       6,    74,    75,    76,    77,   210,    79,   207,    81,   206,
      83,    84,    85,    86,   207,   211,   210,    90,   210,   210,
     210,    94,   210,   210,    97,    31,    32,    33,    34,    35,
      36,   207,    38,    39,   204,   207,   210,   203,   977,   207,
     207,   210,    30,   214,   209,    51,    52,   209,   209,   209,
     209,   209,    58,    30,   209,   207,    62,    63,    64,    65,
     209,   201,     1,   203,    70,     4,     5,     6,    74,    75,
      76,   209,   207,    79,    30,    81,   209,    83,    84,    85,
      86,   209,    30,   209,    90,   207,   210,   210,    94,   207,
     207,    97,    31,    32,    33,    34,    35,    36,   207,    38,
      39,   207,   207,   207,   207,    30,   207,   207,   210,   207,
     207,   210,    51,    52,   207,   209,   203,   209,   209,    58,
     209,   209,   207,    62,    63,    64,    65,   207,   201,     1,
     203,    70,     4,     5,     6,    74,    75,    76,   209,   209,
      79,   209,    81,   209,    83,    84,    85,    86,   209,   204,
     204,    90,   204,   204,   207,    94,   204,   204,    97,    31,
      32,    33,    34,    35,    36,   210,    38,    39,   209,   209,
     209,   203,   209,   204,   207,   210,   210,   207,   203,    51,
      52,   210,   210,   210,   210,   207,    58,   210,   209,   209,
      62,    63,   209,    65,   209,   201,     1,   203,    70,     4,
       5,     6,    74,    75,    76,   204,   204,    79,    80,    81,
     204,    83,    84,    85,    86,   204,   211,   204,    90,   204,
     204,   204,    94,   204,   210,    97,    31,    32,    33,    34,
      35,    36,   210,    38,    39,   207,   210,   210,   203,   210,
     210,   210,   210,   210,   210,   209,    51,    52,   209,   207,
     207,   210,   207,    58,   207,   207,   207,    62,    63,   204,
      65,   204,   201,   204,   203,    70,   204,   211,    73,    74,
      75,    76,   204,   210,    79,   210,    81,   210,    83,    84,
      85,    86,   210,     1,   210,    90,     4,     5,     6,    94,
     210,   210,    97,   211,   207,   207,   207,   211,   207,   207,
     210,   207,   207,   210,   207,   207,   210,   204,    44,   210,
     209,   207,   207,    31,    32,    33,    34,    35,    36,   209,
      38,    39,   209,   209,   209,   209,   204,   210,   210,   201,
     210,   203,   207,    51,    52,   209,   207,   207,   207,   207,
      58,   207,   207,   204,    62,    63,   210,    65,   207,   207,
       1,   207,    70,     4,     5,     6,    74,    75,    76,   207,
      78,    79,   207,    81,   207,    83,    84,    85,    86,   207,
     207,   210,    90,   207,   210,   207,    94,   204,   209,    97,
      31,    32,    33,    34,    35,    36,   209,    38,    39,   209,
     204,   204,   204,   203,   210,   204,   201,   204,   203,   210,
      51,    52,   210,   207,   207,   207,   207,    58,   207,   204,
     204,    62,    63,   204,    65,    66,   209,     1,   210,    70,
       4,     5,     6,    74,    75,    76,   210,   210,    79,   211,
      81,   210,    83,    84,    85,    86,   207,   207,   207,    90,
     207,   207,   210,    94,   209,   209,    97,    31,    32,    33,
      34,    35,    36,   207,    38,    39,   207,   210,   210,   204,
     210,   207,   211,    44,    44,   204,   210,    51,    52,   207,
     210,    44,    44,   210,    58,   210,   209,    61,    62,    63,
     207,    65,   207,   201,     1,   203,    70,     4,     5,     6,
      74,    75,    76,   207,   207,    79,   207,    81,   210,    83,
      84,    85,    86,   209,   209,   209,    90,   207,   207,   207,
      94,    44,    44,    97,    31,    32,    33,    34,    35,    36,
     210,    38,    39,   207,   210,   210,    44,   210,   209,   207,
     207,   207,   207,     3,    51,    52,   210,   207,   826,   358,
     330,    58,   331,    84,   175,    62,    63,    -1,    65,    66,
     201,     1,   203,    70,     4,     5,     6,    74,    75,    76,
      -1,    -1,    79,   326,    81,    -1,    83,    84,    85,    86,
      -1,    -1,    -1,    90,    -1,    -1,    -1,    94,    -1,    -1,
      97,    31,    32,    33,    34,    35,    36,    -1,    38,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,    -1,    -1,    -1,    -1,    -1,    58,    -1,
      -1,    -1,    62,    63,    -1,    65,    66,   201,     1,   203,
      70,     4,     5,     6,    74,    75,    76,    -1,    -1,    79,
      -1,    81,    -1,    83,    84,    85,    86,    -1,    -1,    -1,
      90,    -1,    -1,    -1,    94,    -1,    -1,    97,    31,    32,
      33,    34,    35,    36,    -1,    38,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,
      -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,    62,
      63,    -1,    65,    66,   201,     1,   203,    70,     4,     5,
       6,    74,    75,    76,    -1,    -1,    79,    -1,    81,    -1,
      83,    84,    85,    86,    -1,    -1,    -1,    90,    -1,    -1,
      -1,    94,    -1,    -1,    97,    31,    32,    33,    34,    35,
      36,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    -1,    -1,    -1,
      -1,    -1,    58,    -1,    -1,    -1,    62,    63,    -1,    65,
      66,   201,     1,   203,    70,     4,     5,     6,    74,    75,
      76,    -1,    -1,    79,    -1,    81,    -1,    83,    84,    85,
      86,    -1,    -1,    -1,    90,    -1,    -1,    -1,    94,    -1,
      -1,    97,    31,    32,    33,    34,    35,    36,    -1,    38,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,    -1,    -1,    -1,    -1,    -1,    58,
      -1,    -1,    -1,    62,    63,    -1,    65,    -1,   201,     1,
     203,    70,     4,     5,     6,    74,    75,    76,    -1,    -1,
      79,    -1,    81,    -1,    83,    84,    85,    86,    -1,    -1,
      -1,    90,    91,    -1,    -1,    94,    -1,    -1,    97,    31,
      32,    33,    34,    35,    36,    -1,    38,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,
      62,    63,    -1,    65,    -1,   201,    -1,   203,    70,    -1,
      -1,    -1,    74,    75,    76,    -1,    -1,    79,    -1,    81,
      -1,    83,    84,    85,    86,    -1,    -1,    -1,    90,    91,
      -1,    -1,    94,    -1,    -1,    97,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   201,    -1,   203,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      54,    55,    56,    57,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,
      -1,    -1,    86,    -1,    -1,    89,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   201,
      -1,   203,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,    -1,    21,   183,
      -1,    -1,   186,    -1,    -1,    -1,   190,   191,   192,   193,
     194,   195,   196,   197,    -1,    -1,    -1,    -1,    -1,   203,
     204,   205,   206,   207,    -1,   209,    -1,    -1,    -1,   213,
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
      -1,   203,   204,   205,   206,    -1,    -1,   209,   210,    -1,
      -1,   213,    53,    54,    55,    56,    57,    -1,    -1,    -1,
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
      -1,    21,   183,    -1,    -1,   186,    -1,    -1,    -1,   190,
     191,   192,   193,   194,   195,   196,   197,    -1,    -1,    -1,
      -1,    -1,   203,   204,   205,   206,    -1,    -1,   209,   210,
      -1,    -1,   213,    53,    54,    55,    56,    57,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    82,    -1,    -1,    -1,    86,    -1,    -1,    89,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,    -1,    21,   183,    -1,    -1,   186,    -1,    -1,    -1,
     190,   191,   192,   193,   194,   195,   196,   197,    -1,    -1,
      -1,    -1,    -1,   203,   204,   205,   206,    -1,    -1,   209,
      -1,    -1,    -1,   213,    53,    54,    55,    56,    57,    -1,
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
     179,   180,    -1,    21,   183,    -1,    -1,   186,    -1,    -1,
      -1,   190,   191,   192,   193,   194,   195,   196,   197,    -1,
      -1,    -1,    -1,    -1,   203,   204,   205,   206,    -1,    -1,
     209,    -1,    -1,    -1,   213,    53,    54,    55,    56,    57,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    82,    -1,    -1,    -1,    86,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,    -1,    -1,   183,    -1,    -1,   186,    -1,
      -1,    -1,   190,   191,   192,   193,   194,   195,   196,   197,
      -1,    -1,    -1,    -1,    -1,   203,   204,   205,   206,    -1,
      -1,   209,   254,   255,   256,   257,   258,   259,   260,   261,
     262,   263,   264,    -1,    -1,   267,   268,   269,   270,   271,
      -1,    -1,    -1,   275,   276,   277,   278,   279,   280,    -1,
      -1,    -1,    -1,   285,   286,   287,   288,   289,   290,   291,
      -1,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   303,   304,   305,   306,   307,   308,   309,   310,   311,
     312,   313,   314,   315,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   324
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,     3,   222,   223,     0,     1,     4,     5,     6,    31,
      32,    33,    34,    35,    36,    38,    39,    50,    51,    52,
      58,    62,    63,    65,    70,    74,    75,    76,    79,    81,
      83,    84,    85,    86,    90,    94,    97,   201,   203,   225,
     226,   227,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   238,   239,   240,   241,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   259,   263,   264,   265,   266,   267,
     271,   272,   207,   203,   203,   203,    21,    53,    54,    55,
      56,    57,    82,    86,    89,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     183,   186,   190,   191,   192,   193,   194,   195,   196,   197,
     203,   204,   205,   206,   209,   213,   273,   274,   275,   276,
     277,   278,   279,   280,   281,   283,   203,   230,   179,   180,
     183,   186,   190,   191,   192,   193,   194,   195,   196,   197,
     202,   203,   282,   230,   273,   207,   282,   209,   207,   273,
     208,   273,   273,   273,   282,   207,   207,   207,   207,   203,
     282,   282,   282,   282,   203,   203,   203,   282,   105,   209,
     208,     7,     8,     9,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,   102,   179,   180,   181,   182,   183,
     184,   273,   277,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   209,   209,   209,   209,   209,
     209,   209,   209,   209,   209,   206,   209,   273,   281,   207,
      88,    87,   208,   216,   217,   218,   219,   220,   202,   212,
     213,   214,   215,   105,   209,   208,   208,   208,   207,   207,
     282,   207,    53,   207,   207,   207,   208,    71,   268,   269,
     224,   207,   207,   207,   207,   207,    46,   242,    11,    12,
      13,    14,    48,   243,    99,   100,   101,   207,   202,   203,
     273,   284,   285,   273,    10,   207,   207,   207,   209,   209,
     209,   209,   209,   190,   207,   191,   207,   207,   207,   207,
     209,   209,   209,   209,   209,   209,   209,   207,   273,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   210,   210,   286,   286,   286,   286,   286,   210,   210,
     210,   286,   286,   286,   210,   286,   210,   286,   210,   286,
     273,   273,   273,   273,   286,   286,   286,   286,   286,   286,
     286,   273,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   286,   286,   286,   286,   286,
     286,   286,   286,   286,   286,   273,   273,   273,   273,   203,
     210,   282,   282,   286,   273,   284,   210,   275,   276,   278,
     278,   278,   278,   278,   278,   278,   279,   279,   280,   280,
     203,   273,   273,   282,   273,   210,   207,   224,   224,   224,
     273,   273,    72,   269,   270,    77,   225,   224,   207,   209,
     209,   209,   209,   209,    49,   207,   100,   207,   209,   209,
     257,   273,   210,   210,   211,   207,   209,   204,   204,   204,
     204,   204,   209,   209,   203,   204,   204,   204,   204,   204,
     185,   210,   211,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   211,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   211,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   210,
     210,   210,   210,   210,   210,   210,   210,   210,   210,   207,
     207,   207,   282,   260,    64,    64,    67,    68,   207,   207,
      73,   207,    80,    92,   204,   204,   204,   204,   206,   209,
     246,   209,   257,   204,   203,    98,   103,   203,   258,   207,
     105,   207,   273,   214,   210,   210,   210,   211,   211,   203,
     203,   210,   210,   210,   210,   210,   210,   211,   273,   273,
      22,    23,    24,    25,    26,    27,   207,    59,    60,   261,
     262,   207,   207,   273,   273,   224,   224,   207,   224,   207,
     203,   243,   210,   210,   210,   211,   210,   206,    95,   104,
     203,   247,   204,    98,   210,   210,   207,   203,    11,    12,
      13,    14,   224,   203,   211,    29,    30,    40,    41,    42,
      46,    47,   100,   228,    30,    46,   100,   228,    29,    30,
      42,    46,   100,   228,   204,   204,   210,   210,   207,   228,
     228,   228,   228,   228,   206,   211,   210,   210,   210,   210,
     210,   210,   273,   207,    61,    69,   207,    69,   207,    78,
     243,   207,   204,   207,   210,   207,   203,    11,    12,    13,
      14,   101,   210,   207,    99,   100,   207,    11,    12,    13,
      14,   209,   209,   209,   209,    66,   214,    30,   209,   209,
      30,   209,   207,   209,   209,   207,    30,   209,   209,    30,
     209,   207,   210,   210,   207,   207,   207,   207,   207,   207,
     207,   210,    22,    23,    24,    25,    26,    27,   207,   224,
     207,   273,   224,   273,   224,   207,   207,   244,   210,   246,
     207,    11,    12,    13,    14,   209,   209,   209,   209,   209,
     207,   207,   209,   209,   209,   209,   209,   204,   204,   204,
     204,   207,   210,   209,   273,   203,   209,   204,   273,   204,
     209,   273,   203,   209,   204,    29,    30,   100,   228,   228,
     207,   210,   210,   210,   210,   210,   210,   224,   207,    66,
     207,    66,   244,    93,   104,   203,   245,    95,   246,   209,
     209,   209,   209,   204,   204,   204,   204,   203,   257,   257,
     204,   204,   204,   204,   204,   210,   210,   210,   211,   207,
     273,   210,   210,   273,   210,   210,   210,   273,   210,   210,
     273,   210,    30,   209,   209,   207,   207,   224,   207,   224,
     207,    93,   207,   203,    11,    12,    13,    14,   101,   207,
      95,   204,   204,   204,   204,   210,   210,   210,   211,   210,
      98,    98,   210,   210,   210,   210,   211,   207,   207,   207,
     204,   210,   207,   207,   210,   195,   196,   207,   207,   207,
     210,   207,   207,   210,   195,   196,   207,   209,   273,   204,
      66,    66,   207,   224,    11,    12,    13,    14,   209,   209,
     209,   209,   209,   207,   210,   210,   210,   211,    96,   207,
      96,   207,    96,   207,   204,   207,   207,   207,   207,   207,
     207,   207,   204,   210,   207,   207,   207,   207,   207,   207,
     207,   207,   273,   210,   210,   207,   207,   224,    37,    91,
     209,   209,   209,   209,   204,   204,   204,   204,   203,    96,
     207,    96,   207,    96,   207,   204,    43,   207,    43,   207,
      43,   207,   210,   210,   207,   210,   207,   207,    37,    91,
     207,   207,   204,   204,   204,   204,   210,   210,   210,   211,
     210,   207,   207,   207,   210,   209,   209,   209,    96,   207,
     207,   207,   207,   207,   224,   210,   210,   210,   211,    96,
     207,    96,   207,    96,   207,   204,   207,    96,   207,    44,
      44,    44,    43,   207,   224,    91,    96,   207,    96,   207,
      96,   207,   204,    43,   207,    43,   207,    43,   207,   210,
     207,   210,   210,   210,   209,    91,   207,   207,   207,   207,
     210,   209,   209,   209,    96,   207,   207,   207,   207,    44,
     207,    96,   207,    44,    44,    44,    43,   207,   210,   207,
     210,   210,   210,   209,   207,   207,   207,   207,    44,   210,
     207
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   221,   222,   223,   223,   223,   224,   224,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     226,   226,   226,   226,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   228,   228,   228,   228,   228,   229,   230,   230,
     230,   230,   230,   231,   231,   232,   233,   234,   235,   236,
     237,   238,   238,   239,   240,   240,   240,   241,   241,   241,
     241,   242,   242,   243,   243,   243,   243,   243,   244,   244,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   246,   246,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   256,   256,   256,   256,   256,   257,   257,
     258,   258,   258,   258,   258,   258,   258,   258,   259,   260,
     260,   261,   262,   262,   263,   264,   265,   265,   265,   265,
     266,   267,   268,   268,   269,   270,   270,   271,   272,   273,
     274,   274,   275,   275,   276,   276,   277,   277,   277,   277,
     277,   277,   277,   277,   278,   278,   278,   279,   279,   279,
     280,   280,   281,   281,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   282,   283,   283,
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
     283,   284,   284,   285,   285,   286,   286
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     2,     2,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       4,     4,     4,    10,     8,     8,     8,    10,    10,    12,
      12,    14,    11,    11,    13,    11,    12,    12,     4,     4,
       4,     4,     4,    11,    11,    11,    13,     7,     8,     8,
       8,     8,     8,     9,    11,    11,    12,    12,    12,    12,
       8,     8,     0,     1,     1,     1,     1,     4,     1,     1,
       3,     4,     6,     4,     5,     5,     5,     3,     2,     3,
       4,     3,     2,     5,     7,    11,    10,    13,    14,    16,
      17,     0,     1,     0,     4,     4,     4,     6,     0,     2,
       6,     7,     6,     7,     6,     7,     8,     9,     7,     8,
       7,     8,     7,     8,     9,    10,     6,    11,    11,    11,
      13,     0,     2,     6,     7,     6,     7,     6,     7,     8,
       9,     7,     8,     7,     8,     7,     8,     9,    10,     6,
      11,    11,    11,    13,     8,     6,     3,     3,     3,     3,
       3,     6,     7,     6,    11,    11,     7,    11,     0,     2,
       6,     6,     6,     8,     7,     7,     7,     9,     8,     0,
       2,     4,     0,     3,     6,     6,    10,    12,    10,    12,
       8,     6,     1,     2,     4,     0,     3,     2,     2,     1,
       1,     3,     1,     3,     1,     2,     1,     3,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     2,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     3,     4,     4,
       4,     4,     4,     4,     4,     4,     6,     6,     6,     6,
       6,     6,     4,     4,     4,     4,     3,     3,     4,     4,
       4,     4,     4,     4,     3,     4,     3,     4,     3,     8,
       8,     8,     4,     4,     4,     3,     3,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     3,     1,     8,     8,     8,     2,     4,
       4,     4,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     0,     1,     1,     3,     1,     3
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
#line 2543 "build/parser.cpp"
    break;

  case 4: /* statements_opt: statements_opt statement  */
#line 191 "src/parser.y"
                               {
        if ((yyvsp[0].stmt)) {
            g_program->statements.emplace_back((yyvsp[0].stmt));
        }
    }
#line 2553 "build/parser.cpp"
    break;

  case 5: /* statements_opt: statements_opt KW_CTLOPT  */
#line 196 "src/parser.y"
                               {
        if (ctlopt_nomain) g_program->nomain = true;
        if (ctlopt_main_proc[0]) g_program->main_proc = ctlopt_main_proc;
        if (ctlopt_datfmt[0]) g_program->datfmt = ctlopt_datfmt;
        if (ctlopt_timfmt[0]) g_program->timfmt = ctlopt_timfmt;
    }
#line 2564 "build/parser.cpp"
    break;

  case 6: /* statement_list: %empty  */
#line 205 "src/parser.y"
                {
        (yyval.stmt_list) = new StmtList();
    }
#line 2572 "build/parser.cpp"
    break;

  case 7: /* statement_list: statement_list statement  */
#line 208 "src/parser.y"
                               {
        (yyval.stmt_list) = (yyvsp[-1].stmt_list);
        if ((yyvsp[0].stmt)) {
            (yyval.stmt_list)->stmts.push_back((yyvsp[0].stmt));
        }
    }
#line 2583 "build/parser.cpp"
    break;

  case 8: /* statement: dcl_f_stmt  */
#line 217 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2589 "build/parser.cpp"
    break;

  case 9: /* statement: dcl_s_stmt  */
#line 218 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2595 "build/parser.cpp"
    break;

  case 10: /* statement: dcl_c_stmt  */
#line 219 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2601 "build/parser.cpp"
    break;

  case 11: /* statement: eval_stmt  */
#line 220 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2607 "build/parser.cpp"
    break;

  case 12: /* statement: eval_corr_stmt  */
#line 221 "src/parser.y"
                     { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2613 "build/parser.cpp"
    break;

  case 13: /* statement: dsply_stmt  */
#line 222 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2619 "build/parser.cpp"
    break;

  case 14: /* statement: inlr_stmt  */
#line 223 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2625 "build/parser.cpp"
    break;

  case 15: /* statement: return_stmt  */
#line 224 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2631 "build/parser.cpp"
    break;

  case 16: /* statement: if_stmt  */
#line 225 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2637 "build/parser.cpp"
    break;

  case 17: /* statement: dow_stmt  */
#line 226 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2643 "build/parser.cpp"
    break;

  case 18: /* statement: dou_stmt  */
#line 227 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2649 "build/parser.cpp"
    break;

  case 19: /* statement: for_stmt  */
#line 228 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2655 "build/parser.cpp"
    break;

  case 20: /* statement: for_each_stmt  */
#line 229 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2661 "build/parser.cpp"
    break;

  case 21: /* statement: select_stmt  */
#line 230 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2667 "build/parser.cpp"
    break;

  case 22: /* statement: iter_stmt  */
#line 231 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2673 "build/parser.cpp"
    break;

  case 23: /* statement: leave_stmt  */
#line 232 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2679 "build/parser.cpp"
    break;

  case 24: /* statement: dcl_proc_stmt  */
#line 233 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2685 "build/parser.cpp"
    break;

  case 25: /* statement: dcl_pr_stmt  */
#line 234 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2691 "build/parser.cpp"
    break;

  case 26: /* statement: dcl_ds_stmt  */
#line 235 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2697 "build/parser.cpp"
    break;

  case 27: /* statement: monitor_stmt  */
#line 236 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2703 "build/parser.cpp"
    break;

  case 28: /* statement: begsr_stmt  */
#line 237 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2709 "build/parser.cpp"
    break;

  case 29: /* statement: exsr_stmt  */
#line 238 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2715 "build/parser.cpp"
    break;

  case 30: /* statement: reset_stmt  */
#line 239 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2721 "build/parser.cpp"
    break;

  case 31: /* statement: clear_stmt  */
#line 240 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2727 "build/parser.cpp"
    break;

  case 32: /* statement: sorta_stmt  */
#line 241 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2733 "build/parser.cpp"
    break;

  case 33: /* statement: evalr_stmt  */
#line 242 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2739 "build/parser.cpp"
    break;

  case 34: /* statement: callp_stmt  */
#line 243 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2745 "build/parser.cpp"
    break;

  case 35: /* statement: leavesr_stmt  */
#line 244 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2751 "build/parser.cpp"
    break;

  case 36: /* statement: dealloc_stmt  */
#line 245 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2757 "build/parser.cpp"
    break;

  case 37: /* statement: test_stmt  */
#line 246 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2763 "build/parser.cpp"
    break;

  case 38: /* statement: expr_stmt  */
#line 247 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 2769 "build/parser.cpp"
    break;

  case 39: /* statement: error SEMICOLON  */
#line 248 "src/parser.y"
                      { (yyval.stmt) = nullptr; yyerrok; }
#line 2775 "build/parser.cpp"
    break;

  case 40: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_DISK SEMICOLON  */
#line 253 "src/parser.y"
                                          {
        (yyval.stmt) = new rpg::DclF((yyvsp[-2].sval), "DISK");
        free((yyvsp[-2].sval));
    }
#line 2784 "build/parser.cpp"
    break;

  case 41: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_PRINTER SEMICOLON  */
#line 257 "src/parser.y"
                                               {
        (yyval.stmt) = new rpg::DclF((yyvsp[-2].sval), "PRINTER");
        free((yyvsp[-2].sval));
    }
#line 2793 "build/parser.cpp"
    break;

  case 42: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_WORKSTN SEMICOLON  */
#line 261 "src/parser.y"
                                               {
        (yyval.stmt) = new rpg::DclF((yyvsp[-2].sval), "WORKSTN");
        free((yyvsp[-2].sval));
    }
#line 2802 "build/parser.cpp"
    break;

  case 43: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_DISK KW_USAGE LPAREN STAR COLON STAR RPAREN SEMICOLON  */
#line 265 "src/parser.y"
                                                                                   {
        (yyval.stmt) = new rpg::DclF((yyvsp[-8].sval), "DISK");
        free((yyvsp[-8].sval));
    }
#line 2811 "build/parser.cpp"
    break;

  case 44: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 273 "src/parser.y"
                                                                                       {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 2821 "build/parser.cpp"
    break;

  case 45: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 278 "src/parser.y"
                                                                                            {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 2831 "build/parser.cpp"
    break;

  case 46: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 283 "src/parser.y"
                                                                                        {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::INT10, 0);
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 2841 "build/parser.cpp"
    break;

  case 47: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 288 "src/parser.y"
                                                                                                                 {
        auto* n = new rpg::DclS((yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-8].sval));
    }
#line 2851 "build/parser.cpp"
    break;

  case 48: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_ZONED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 293 "src/parser.y"
                                                                                                                {
        auto* n = new rpg::DclS((yyvsp[-8].sval), rpg::RPGType::ZONED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-8].sval));
    }
#line 2861 "build/parser.cpp"
    break;

  case 49: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_CONST KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 298 "src/parser.y"
                                                                                                                  {
        (yyval.stmt) = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, true,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-10].sval));
    }
#line 2871 "build/parser.cpp"
    break;

  case 50: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_CONST KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 303 "src/parser.y"
                                                                                                                   {
        (yyval.stmt) = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, true,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-10].sval));
    }
#line 2881 "build/parser.cpp"
    break;

  case 51: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_CONST KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 308 "src/parser.y"
                                                                                                                                           {
        (yyval.stmt) = new rpg::DclS((yyvsp[-12].sval), rpg::RPGType::PACKED, 0, (yyvsp[-9].ival), (yyvsp[-7].ival), true,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-12].sval));
    }
#line 2891 "build/parser.cpp"
    break;

  case 52: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 313 "src/parser.y"
                                                                                                         {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-9].sval));
    }
#line 2901 "build/parser.cpp"
    break;

  case 53: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 318 "src/parser.y"
                                                                                                          {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-9].sval));
    }
#line 2911 "build/parser.cpp"
    break;

  case 54: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 323 "src/parser.y"
                                                                                                                                  {
        (yyval.stmt) = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-11].sval));
    }
#line 2921 "build/parser.cpp"
    break;

  case 55: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 328 "src/parser.y"
                                                                                                             {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-9].sval));
    }
#line 2931 "build/parser.cpp"
    break;

  case 56: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_EXPORT KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 334 "src/parser.y"
                                                                                                                   {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        n->is_export = true;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 2942 "build/parser.cpp"
    break;

  case 57: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_EXPORT KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 340 "src/parser.y"
                                                                                                                    {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        n->is_export = true;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 2953 "build/parser.cpp"
    break;

  case 58: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_IND SEMICOLON  */
#line 346 "src/parser.y"
                                           {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::IND, 0);
        free((yyvsp[-2].sval));
    }
#line 2962 "build/parser.cpp"
    break;

  case 59: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_DATE SEMICOLON  */
#line 350 "src/parser.y"
                                            {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::DATE, 0);
        free((yyvsp[-2].sval));
    }
#line 2971 "build/parser.cpp"
    break;

  case 60: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_TIME SEMICOLON  */
#line 354 "src/parser.y"
                                            {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::TIME, 0);
        free((yyvsp[-2].sval));
    }
#line 2980 "build/parser.cpp"
    break;

  case 61: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_TIMESTAMP SEMICOLON  */
#line 358 "src/parser.y"
                                                 {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::TIMESTAMP, 0);
        free((yyvsp[-2].sval));
    }
#line 2989 "build/parser.cpp"
    break;

  case 62: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_POINTER SEMICOLON  */
#line 362 "src/parser.y"
                                               {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::POINTER, 0);
        free((yyvsp[-2].sval));
    }
#line 2998 "build/parser.cpp"
    break;

  case 63: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 366 "src/parser.y"
                                                                                                              {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-9].sval));
    }
#line 3007 "build/parser.cpp"
    break;

  case 64: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 370 "src/parser.y"
                                                                                                               {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-9].sval));
    }
#line 3016 "build/parser.cpp"
    break;

  case 65: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 374 "src/parser.y"
                                                                                                                  {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-9].sval));
    }
#line 3025 "build/parser.cpp"
    break;

  case 66: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 378 "src/parser.y"
                                                                                                                                       {
        (yyval.stmt) = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-11].sval));
    }
#line 3034 "build/parser.cpp"
    break;

  case 67: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_LIKE LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 382 "src/parser.y"
                                                                     {
        auto* node = new rpg::DclS((yyvsp[-5].sval), rpg::RPGType::INT10, 0);
        node->like_var = (yyvsp[-2].sval);
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
        (yyval.stmt) = node;
    }
#line 3046 "build/parser.cpp"
    break;

  case 68: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_UNS LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 389 "src/parser.y"
                                                                                        {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::UNS, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3056 "build/parser.cpp"
    break;

  case 69: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_FLOAT_TYPE LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 394 "src/parser.y"
                                                                                               {
        auto type = ((yyvsp[-3].ival) <= 4) ? rpg::RPGType::FLOAT4 : rpg::RPGType::FLOAT8;
        auto* n = new rpg::DclS((yyvsp[-6].sval), type, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3067 "build/parser.cpp"
    break;

  case 70: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_BINDEC LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 400 "src/parser.y"
                                                                                           {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::BINDEC, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3077 "build/parser.cpp"
    break;

  case 71: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_UCS2 LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 405 "src/parser.y"
                                                                                         {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::UCS2, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3087 "build/parser.cpp"
    break;

  case 72: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_GRAPH LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 410 "src/parser.y"
                                                                                          {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::UCS2, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3097 "build/parser.cpp"
    break;

  case 73: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_OBJECT LPAREN KW_JAVA COLON STRING_LITERAL RPAREN SEMICOLON  */
#line 415 "src/parser.y"
                                                                                         {
        auto* n = new rpg::DclS((yyvsp[-7].sval), rpg::RPGType::OBJECT, 0);
        n->java_class = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-7].sval)); free((yyvsp[-2].sval));
    }
#line 3107 "build/parser.cpp"
    break;

  case 74: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_BASED LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 420 "src/parser.y"
                                                                                                           {
        auto* n = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::INT10, 0);
        n->based_ptr = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
    }
#line 3117 "build/parser.cpp"
    break;

  case 75: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_BASED LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 425 "src/parser.y"
                                                                                                            {
        auto* n = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival));
        n->based_ptr = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
    }
#line 3127 "build/parser.cpp"
    break;

  case 76: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_ASCEND SEMICOLON  */
#line 430 "src/parser.y"
                                                                                                                        {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = 1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3137 "build/parser.cpp"
    break;

  case 77: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_DESCEND SEMICOLON  */
#line 435 "src/parser.y"
                                                                                                                         {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = -1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3147 "build/parser.cpp"
    break;

  case 78: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_ASCEND SEMICOLON  */
#line 440 "src/parser.y"
                                                                                                                         {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = 1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3157 "build/parser.cpp"
    break;

  case 79: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_DESCEND SEMICOLON  */
#line 445 "src/parser.y"
                                                                                                                          {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = -1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3167 "build/parser.cpp"
    break;

  case 80: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_DATE KW_DATFMT LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 450 "src/parser.y"
                                                                               {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::DATE, 0);
        n->datfmt = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-6].sval)); free((yyvsp[-2].sval));
    }
#line 3177 "build/parser.cpp"
    break;

  case 81: /* dcl_s_stmt: KW_DCL_S IDENTIFIER KW_TIME KW_TIMFMT LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 455 "src/parser.y"
                                                                               {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::TIME, 0);
        n->timfmt = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-6].sval)); free((yyvsp[-2].sval));
    }
#line 3187 "build/parser.cpp"
    break;

  case 82: /* dcl_s_keywords: %empty  */
#line 463 "src/parser.y"
                  { (yyval.ival) = 0; }
#line 3193 "build/parser.cpp"
    break;

  case 83: /* dcl_s_keywords: KW_STATIC  */
#line 464 "src/parser.y"
                  { (yyval.ival) = 1; }
#line 3199 "build/parser.cpp"
    break;

  case 84: /* dcl_s_keywords: KW_TEMPLATE  */
#line 465 "src/parser.y"
                  { (yyval.ival) = 2; }
#line 3205 "build/parser.cpp"
    break;

  case 85: /* dcl_s_keywords: KW_EXPORT  */
#line 466 "src/parser.y"
                  { (yyval.ival) = 4; }
#line 3211 "build/parser.cpp"
    break;

  case 86: /* dcl_s_keywords: KW_IMPORT  */
#line 467 "src/parser.y"
                  { (yyval.ival) = 8; }
#line 3217 "build/parser.cpp"
    break;

  case 87: /* dcl_c_stmt: KW_DCL_C IDENTIFIER expression SEMICOLON  */
#line 472 "src/parser.y"
                                             {
        (yyval.stmt) = new rpg::DclC((yyvsp[-2].sval), std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
        free((yyvsp[-2].sval));
    }
#line 3226 "build/parser.cpp"
    break;

  case 88: /* eval_target: IDENTIFIER  */
#line 479 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier((yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 3235 "build/parser.cpp"
    break;

  case 89: /* eval_target: INDICATOR  */
#line 483 "src/parser.y"
                {
        (yyval.expr) = new rpg::IndicatorExpr((yyvsp[0].ival));
    }
#line 3243 "build/parser.cpp"
    break;

  case 90: /* eval_target: IDENTIFIER DOT IDENTIFIER  */
#line 486 "src/parser.y"
                                {
        auto obj = std::unique_ptr<rpg::Expression>(new rpg::Identifier((yyvsp[-2].sval)));
        (yyval.expr) = new rpg::DotExpr(std::move(obj), (yyvsp[0].sval));
        free((yyvsp[-2].sval));
        free((yyvsp[0].sval));
    }
#line 3254 "build/parser.cpp"
    break;

  case 91: /* eval_target: IDENTIFIER LPAREN expression RPAREN  */
#line 492 "src/parser.y"
                                          {
        (yyval.expr) = new rpg::ArrayAccess((yyvsp[-3].sval), std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
        free((yyvsp[-3].sval));
    }
#line 3263 "build/parser.cpp"
    break;

  case 92: /* eval_target: IDENTIFIER LPAREN expression RPAREN DOT IDENTIFIER  */
#line 496 "src/parser.y"
                                                         {
        auto* arr = new rpg::ArrayAccess((yyvsp[-5].sval), std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)));
        (yyval.expr) = new rpg::DotExpr(std::unique_ptr<rpg::Expression>(arr), (yyvsp[0].sval));
        free((yyvsp[-5].sval));
        free((yyvsp[0].sval));
    }
#line 3274 "build/parser.cpp"
    break;

  case 93: /* eval_stmt: eval_target EQUALS expression SEMICOLON  */
#line 505 "src/parser.y"
                                            {
        (yyval.stmt) = new rpg::EvalStmt(
            std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-1].expr))
        );
    }
#line 3285 "build/parser.cpp"
    break;

  case 94: /* eval_stmt: KW_EVAL eval_target EQUALS expression SEMICOLON  */
#line 511 "src/parser.y"
                                                      {
        (yyval.stmt) = new rpg::EvalStmt(
            std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-1].expr))
        );
    }
#line 3296 "build/parser.cpp"
    break;

  case 95: /* eval_corr_stmt: KW_EVAL_CORR ident EQUALS ident SEMICOLON  */
#line 520 "src/parser.y"
                                              {
        (yyval.stmt) = new rpg::EvalCorrStmt(std::string((yyvsp[-3].sval)), std::string((yyvsp[-1].sval)));
        free((yyvsp[-3].sval));
        free((yyvsp[-1].sval));
    }
#line 3306 "build/parser.cpp"
    break;

  case 96: /* evalr_stmt: KW_EVALR eval_target EQUALS expression SEMICOLON  */
#line 528 "src/parser.y"
                                                     {
        (yyval.stmt) = new rpg::EvalRStmt(
            std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-1].expr))
        );
    }
#line 3317 "build/parser.cpp"
    break;

  case 97: /* callp_stmt: KW_CALLP expression SEMICOLON  */
#line 537 "src/parser.y"
                                  {
        (yyval.stmt) = new rpg::ExprStmt(std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
    }
#line 3325 "build/parser.cpp"
    break;

  case 98: /* leavesr_stmt: KW_LEAVESR SEMICOLON  */
#line 543 "src/parser.y"
                         {
        (yyval.stmt) = new rpg::LeaveSRStmt();
    }
#line 3333 "build/parser.cpp"
    break;

  case 99: /* dsply_stmt: KW_DSPLY expression SEMICOLON  */
#line 549 "src/parser.y"
                                  {
        (yyval.stmt) = new rpg::DsplyStmt(std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
    }
#line 3341 "build/parser.cpp"
    break;

  case 100: /* inlr_stmt: KW_INLR EQUALS KW_ON SEMICOLON  */
#line 555 "src/parser.y"
                                   {
        (yyval.stmt) = new rpg::ReturnStmt(0);
    }
#line 3349 "build/parser.cpp"
    break;

  case 101: /* return_stmt: KW_RETURN expression SEMICOLON  */
#line 561 "src/parser.y"
                                   {
        (yyval.stmt) = new rpg::ReturnStmt(std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
    }
#line 3357 "build/parser.cpp"
    break;

  case 102: /* return_stmt: KW_RETURN SEMICOLON  */
#line 564 "src/parser.y"
                          {
        (yyval.stmt) = new rpg::ReturnStmt(0);
    }
#line 3365 "build/parser.cpp"
    break;

  case 103: /* expr_stmt: IDENTIFIER LPAREN call_args_opt RPAREN SEMICOLON  */
#line 571 "src/parser.y"
                                                     {
        auto* fc = make_func((yyvsp[-4].sval), (yyvsp[-2].expr_list));
        free((yyvsp[-4].sval));
        (yyval.stmt) = new rpg::ExprStmt(std::unique_ptr<rpg::Expression>(fc));
    }
#line 3375 "build/parser.cpp"
    break;

  case 104: /* dcl_pr_stmt: KW_DCL_PR IDENTIFIER pi_return_type SEMICOLON pr_params KW_END_PR SEMICOLON  */
#line 582 "src/parser.y"
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
#line 3396 "build/parser.cpp"
    break;

  case 105: /* dcl_pr_stmt: KW_DCL_PR IDENTIFIER pi_return_type KW_EXTPROC LPAREN STRING_LITERAL RPAREN SEMICOLON pr_params KW_END_PR SEMICOLON  */
#line 599 "src/parser.y"
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
#line 3420 "build/parser.cpp"
    break;

  case 106: /* dcl_pr_stmt: KW_DCL_PR IDENTIFIER KW_EXTPGM LPAREN STRING_LITERAL RPAREN SEMICOLON pr_params KW_END_PR SEMICOLON  */
#line 619 "src/parser.y"
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
#line 3436 "build/parser.cpp"
    break;

  case 107: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER proc_export SEMICOLON KW_DCL_PI pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 637 "src/parser.y"
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
#line 3461 "build/parser.cpp"
    break;

  case 108: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER proc_export SEMICOLON KW_DCL_PI IDENTIFIER pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 661 "src/parser.y"
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
#line 3487 "build/parser.cpp"
    break;

  case 109: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER proc_export SEMICOLON KW_DCL_PI pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_ON_EXIT SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 687 "src/parser.y"
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
#line 3514 "build/parser.cpp"
    break;

  case 110: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER proc_export SEMICOLON KW_DCL_PI IDENTIFIER pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_ON_EXIT SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 714 "src/parser.y"
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
#line 3542 "build/parser.cpp"
    break;

  case 111: /* proc_export: %empty  */
#line 740 "src/parser.y"
                { (yyval.ival) = 0; }
#line 3548 "build/parser.cpp"
    break;

  case 112: /* proc_export: KW_EXPORT  */
#line 741 "src/parser.y"
                { (yyval.ival) = 1; }
#line 3554 "build/parser.cpp"
    break;

  case 113: /* pi_return_type: %empty  */
#line 746 "src/parser.y"
               { (yyval.ival) = -1; }
#line 3560 "build/parser.cpp"
    break;

  case 114: /* pi_return_type: KW_INT LPAREN INTEGER_LITERAL RPAREN  */
#line 747 "src/parser.y"
                                           { (yyval.ival) = (int)rpg::RPGType::INT10; }
#line 3566 "build/parser.cpp"
    break;

  case 115: /* pi_return_type: KW_CHAR LPAREN INTEGER_LITERAL RPAREN  */
#line 748 "src/parser.y"
                                            { (yyval.ival) = (int)rpg::RPGType::CHAR; }
#line 3572 "build/parser.cpp"
    break;

  case 116: /* pi_return_type: KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN  */
#line 749 "src/parser.y"
                                               { (yyval.ival) = (int)rpg::RPGType::VARCHAR; }
#line 3578 "build/parser.cpp"
    break;

  case 117: /* pi_return_type: KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN  */
#line 750 "src/parser.y"
                                                                    { (yyval.ival) = (int)rpg::RPGType::PACKED; }
#line 3584 "build/parser.cpp"
    break;

  case 118: /* pi_params: %empty  */
#line 755 "src/parser.y"
                {
        (yyval.param_list) = new ParamList();
    }
#line 3592 "build/parser.cpp"
    break;

  case 119: /* pi_params: pi_params pi_param  */
#line 758 "src/parser.y"
                         {
        (yyval.param_list) = (yyvsp[-1].param_list);
        (yyval.param_list)->params.push_back(*(yyvsp[0].param_decl));
        delete (yyvsp[0].param_decl);
    }
#line 3602 "build/parser.cpp"
    break;

  case 120: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 766 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 3611 "build/parser.cpp"
    break;

  case 121: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 770 "src/parser.y"
                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 3620 "build/parser.cpp"
    break;

  case 122: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 774 "src/parser.y"
                                                                 {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 3629 "build/parser.cpp"
    break;

  case 123: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 778 "src/parser.y"
                                                                          {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 3638 "build/parser.cpp"
    break;

  case 124: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 782 "src/parser.y"
                                                                    {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 3647 "build/parser.cpp"
    break;

  case 125: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 786 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 3656 "build/parser.cpp"
    break;

  case 126: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 790 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 3665 "build/parser.cpp"
    break;

  case 127: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 794 "src/parser.y"
                                                                                                  {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 3674 "build/parser.cpp"
    break;

  case 128: /* pi_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 799 "src/parser.y"
                                                                            {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 3683 "build/parser.cpp"
    break;

  case 129: /* pi_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 803 "src/parser.y"
                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 3692 "build/parser.cpp"
    break;

  case 130: /* pi_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 807 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 3701 "build/parser.cpp"
    break;

  case 131: /* pi_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 811 "src/parser.y"
                                                                                      {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 3710 "build/parser.cpp"
    break;

  case 132: /* pi_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 815 "src/parser.y"
                                                                                {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 3719 "build/parser.cpp"
    break;

  case 133: /* pi_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 819 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 3728 "build/parser.cpp"
    break;

  case 134: /* pi_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 823 "src/parser.y"
                                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 3737 "build/parser.cpp"
    break;

  case 135: /* pi_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 827 "src/parser.y"
                                                                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 3746 "build/parser.cpp"
    break;

  case 136: /* pi_param: IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 831 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, 0, 0, 0, false, std::string((yyvsp[-2].sval))};
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
    }
#line 3756 "build/parser.cpp"
    break;

  case 137: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 837 "src/parser.y"
                                                                                                            {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 3766 "build/parser.cpp"
    break;

  case 138: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 842 "src/parser.y"
                                                                                                             {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 3776 "build/parser.cpp"
    break;

  case 139: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 847 "src/parser.y"
                                                                                                                {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::VARCHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 3786 "build/parser.cpp"
    break;

  case 140: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 852 "src/parser.y"
                                                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-12].sval), rpg::RPGType::PACKED, 0, (yyvsp[-9].ival), (yyvsp[-7].ival), true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-12].sval));
    }
#line 3796 "build/parser.cpp"
    break;

  case 141: /* pr_params: %empty  */
#line 861 "src/parser.y"
                {
        (yyval.param_list) = new ParamList();
    }
#line 3804 "build/parser.cpp"
    break;

  case 142: /* pr_params: pr_params pr_param  */
#line 864 "src/parser.y"
                         {
        (yyval.param_list) = (yyvsp[-1].param_list);
        (yyval.param_list)->params.push_back(*(yyvsp[0].param_decl));
        delete (yyvsp[0].param_decl);
    }
#line 3814 "build/parser.cpp"
    break;

  case 143: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 872 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 3823 "build/parser.cpp"
    break;

  case 144: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 876 "src/parser.y"
                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 3832 "build/parser.cpp"
    break;

  case 145: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 880 "src/parser.y"
                                                                 {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 3841 "build/parser.cpp"
    break;

  case 146: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 884 "src/parser.y"
                                                                          {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 3850 "build/parser.cpp"
    break;

  case 147: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 888 "src/parser.y"
                                                                    {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 3859 "build/parser.cpp"
    break;

  case 148: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 892 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 3868 "build/parser.cpp"
    break;

  case 149: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 896 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 3877 "build/parser.cpp"
    break;

  case 150: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 900 "src/parser.y"
                                                                                                  {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 3886 "build/parser.cpp"
    break;

  case 151: /* pr_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 905 "src/parser.y"
                                                                            {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 3895 "build/parser.cpp"
    break;

  case 152: /* pr_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 909 "src/parser.y"
                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 3904 "build/parser.cpp"
    break;

  case 153: /* pr_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 913 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 3913 "build/parser.cpp"
    break;

  case 154: /* pr_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 917 "src/parser.y"
                                                                                      {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 3922 "build/parser.cpp"
    break;

  case 155: /* pr_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 921 "src/parser.y"
                                                                                {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 3931 "build/parser.cpp"
    break;

  case 156: /* pr_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 925 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 3940 "build/parser.cpp"
    break;

  case 157: /* pr_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 929 "src/parser.y"
                                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 3949 "build/parser.cpp"
    break;

  case 158: /* pr_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 933 "src/parser.y"
                                                                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 3958 "build/parser.cpp"
    break;

  case 159: /* pr_param: IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 937 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, 0, 0, 0, false, std::string((yyvsp[-2].sval))};
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
    }
#line 3968 "build/parser.cpp"
    break;

  case 160: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 943 "src/parser.y"
                                                                                                            {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 3978 "build/parser.cpp"
    break;

  case 161: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 948 "src/parser.y"
                                                                                                             {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 3988 "build/parser.cpp"
    break;

  case 162: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 953 "src/parser.y"
                                                                                                                {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::VARCHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 3998 "build/parser.cpp"
    break;

  case 163: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 958 "src/parser.y"
                                                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-12].sval), rpg::RPGType::PACKED, 0, (yyvsp[-9].ival), (yyvsp[-7].ival), true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-12].sval));
    }
#line 4008 "build/parser.cpp"
    break;

  case 164: /* monitor_stmt: KW_MONITOR SEMICOLON statement_list KW_ON_ERROR SEMICOLON statement_list KW_ENDMON SEMICOLON  */
#line 968 "src/parser.y"
                                                                                                 {
        auto* node = new rpg::MonitorStmt();
        for (auto* s : (yyvsp[-5].stmt_list)->stmts) node->try_body.emplace_back(s);
        delete (yyvsp[-5].stmt_list);
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->on_error_body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        (yyval.stmt) = node;
    }
#line 4021 "build/parser.cpp"
    break;

  case 165: /* begsr_stmt: KW_BEGSR IDENTIFIER SEMICOLON statement_list KW_ENDSR SEMICOLON  */
#line 979 "src/parser.y"
                                                                    {
        auto* node = new rpg::BegSR((yyvsp[-4].sval));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        free((yyvsp[-4].sval));
        (yyval.stmt) = node;
    }
#line 4033 "build/parser.cpp"
    break;

  case 166: /* exsr_stmt: KW_EXSR ident SEMICOLON  */
#line 989 "src/parser.y"
                            {
        (yyval.stmt) = new rpg::ExSR((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4042 "build/parser.cpp"
    break;

  case 167: /* sorta_stmt: KW_SORTA ident SEMICOLON  */
#line 997 "src/parser.y"
                             {
        (yyval.stmt) = new rpg::SortAStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4051 "build/parser.cpp"
    break;

  case 168: /* reset_stmt: KW_RESET ident SEMICOLON  */
#line 1005 "src/parser.y"
                             {
        (yyval.stmt) = new rpg::ResetStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4060 "build/parser.cpp"
    break;

  case 169: /* clear_stmt: KW_CLEAR ident SEMICOLON  */
#line 1012 "src/parser.y"
                             {
        (yyval.stmt) = new rpg::ClearStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4069 "build/parser.cpp"
    break;

  case 170: /* dealloc_stmt: KW_DEALLOC ident SEMICOLON  */
#line 1020 "src/parser.y"
                               {
        (yyval.stmt) = new rpg::DeallocStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4078 "build/parser.cpp"
    break;

  case 171: /* test_stmt: KW_TEST LPAREN ident RPAREN ident SEMICOLON  */
#line 1028 "src/parser.y"
                                                {
        char type = toupper((yyvsp[-3].sval)[0]);
        (yyval.stmt) = new rpg::TestStmt(type, std::string((yyvsp[-1].sval)));
        free((yyvsp[-3].sval));
        free((yyvsp[-1].sval));
    }
#line 4089 "build/parser.cpp"
    break;

  case 172: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1040 "src/parser.y"
                                                                              {
        auto* ds = new rpg::DclDS((yyvsp[-5].sval));
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-5].sval));
        (yyval.stmt) = ds;
    }
#line 4102 "build/parser.cpp"
    break;

  case 173: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1049 "src/parser.y"
                                                                   {
        auto* ds = new rpg::DclDS((yyvsp[-4].sval));
        ds->qualified = false;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-4].sval));
        (yyval.stmt) = ds;
    }
#line 4115 "build/parser.cpp"
    break;

  case 174: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1058 "src/parser.y"
                                                                                                                     {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->dim = (yyvsp[-6].ival);
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-9].sval));
        (yyval.stmt) = ds;
    }
#line 4129 "build/parser.cpp"
    break;

  case 175: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1068 "src/parser.y"
                                                                                                                     {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->dim = (yyvsp[-5].ival);
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-9].sval));
        (yyval.stmt) = ds;
    }
#line 4143 "build/parser.cpp"
    break;

  case 176: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1078 "src/parser.y"
                                                                        {
        auto* ds = new rpg::DclDS((yyvsp[-5].sval));
        ds->like_ds = (yyvsp[-2].sval);
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
        (yyval.stmt) = ds;
    }
#line 4155 "build/parser.cpp"
    break;

  case 177: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1086 "src/parser.y"
                                                                                                             {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->like_ds = (yyvsp[-6].sval);
        ds->dim = (yyvsp[-2].ival);
        free((yyvsp[-9].sval));
        free((yyvsp[-6].sval));
        (yyval.stmt) = ds;
    }
#line 4168 "build/parser.cpp"
    break;

  case 178: /* ds_fields: %empty  */
#line 1097 "src/parser.y"
                {
        (yyval.ds_field_list) = new DSFieldList();
    }
#line 4176 "build/parser.cpp"
    break;

  case 179: /* ds_fields: ds_fields ds_field  */
#line 1100 "src/parser.y"
                         {
        (yyval.ds_field_list) = (yyvsp[-1].ds_field_list);
        (yyval.ds_field_list)->fields.push_back(*(yyvsp[0].ds_field));
        delete (yyvsp[0].ds_field);
    }
#line 4186 "build/parser.cpp"
    break;

  case 180: /* ds_field: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1108 "src/parser.y"
                                                              {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0};
        free((yyvsp[-5].sval));
    }
#line 4195 "build/parser.cpp"
    break;

  case 181: /* ds_field: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1112 "src/parser.y"
                                                                 {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 4204 "build/parser.cpp"
    break;

  case 182: /* ds_field: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1116 "src/parser.y"
                                                                    {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 4213 "build/parser.cpp"
    break;

  case 183: /* ds_field: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1120 "src/parser.y"
                                                                                         {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival)};
        free((yyvsp[-7].sval));
    }
#line 4222 "build/parser.cpp"
    break;

  case 184: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1125 "src/parser.y"
                                                                            {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0};
        free((yyvsp[-5].sval));
    }
#line 4231 "build/parser.cpp"
    break;

  case 185: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1129 "src/parser.y"
                                                                             {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 4240 "build/parser.cpp"
    break;

  case 186: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1133 "src/parser.y"
                                                                                {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 4249 "build/parser.cpp"
    break;

  case 187: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1137 "src/parser.y"
                                                                                                     {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival)};
        free((yyvsp[-7].sval));
    }
#line 4258 "build/parser.cpp"
    break;

  case 188: /* if_stmt: KW_IF expression SEMICOLON statement_list elseif_clauses else_clause KW_ENDIF SEMICOLON  */
#line 1146 "src/parser.y"
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
#line 4283 "build/parser.cpp"
    break;

  case 189: /* elseif_clauses: %empty  */
#line 1169 "src/parser.y"
                { (yyval.elseif_list) = nullptr; }
#line 4289 "build/parser.cpp"
    break;

  case 190: /* elseif_clauses: elseif_clauses elseif_clause  */
#line 1170 "src/parser.y"
                                   {
        if (!(yyvsp[-1].elseif_list)) (yyvsp[-1].elseif_list) = new std::vector<ElseIfData*>();
        (yyval.elseif_list) = (yyvsp[-1].elseif_list);
        (yyval.elseif_list)->push_back((yyvsp[0].elseif_data));
    }
#line 4299 "build/parser.cpp"
    break;

  case 191: /* elseif_clause: KW_ELSEIF expression SEMICOLON statement_list  */
#line 1178 "src/parser.y"
                                                  {
        (yyval.elseif_data) = new ElseIfData();
        (yyval.elseif_data)->cond = (yyvsp[-2].expr);
        (yyval.elseif_data)->body = std::move((yyvsp[0].stmt_list)->stmts);
        delete (yyvsp[0].stmt_list);
    }
#line 4310 "build/parser.cpp"
    break;

  case 192: /* else_clause: %empty  */
#line 1187 "src/parser.y"
                { (yyval.stmt_list) = nullptr; }
#line 4316 "build/parser.cpp"
    break;

  case 193: /* else_clause: KW_ELSE SEMICOLON statement_list  */
#line 1188 "src/parser.y"
                                       {
        (yyval.stmt_list) = (yyvsp[0].stmt_list);
    }
#line 4324 "build/parser.cpp"
    break;

  case 194: /* dow_stmt: KW_DOW expression SEMICOLON statement_list KW_ENDDO SEMICOLON  */
#line 1194 "src/parser.y"
                                                                  {
        auto* node = new rpg::DowStmt(std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        (yyval.stmt) = node;
    }
#line 4335 "build/parser.cpp"
    break;

  case 195: /* dou_stmt: KW_DOU expression SEMICOLON statement_list KW_ENDDO SEMICOLON  */
#line 1203 "src/parser.y"
                                                                  {
        auto* node = new rpg::DouStmt(std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        (yyval.stmt) = node;
    }
#line 4346 "build/parser.cpp"
    break;

  case 196: /* for_stmt: KW_FOR ident EQUALS expression KW_TO expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1212 "src/parser.y"
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
#line 4361 "build/parser.cpp"
    break;

  case 197: /* for_stmt: KW_FOR ident EQUALS expression KW_TO expression KW_BY expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1222 "src/parser.y"
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
#line 4376 "build/parser.cpp"
    break;

  case 198: /* for_stmt: KW_FOR ident EQUALS expression KW_DOWNTO expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1232 "src/parser.y"
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
#line 4391 "build/parser.cpp"
    break;

  case 199: /* for_stmt: KW_FOR ident EQUALS expression KW_DOWNTO expression KW_BY expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1242 "src/parser.y"
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
#line 4406 "build/parser.cpp"
    break;

  case 200: /* for_each_stmt: KW_FOR_EACH ident KW_IN expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1255 "src/parser.y"
                                                                                    {
        auto* node = new rpg::ForEachStmt((yyvsp[-6].sval), std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        free((yyvsp[-6].sval));
        (yyval.stmt) = node;
    }
#line 4418 "build/parser.cpp"
    break;

  case 201: /* select_stmt: KW_SELECT SEMICOLON when_clauses other_clause KW_ENDSL SEMICOLON  */
#line 1265 "src/parser.y"
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
#line 4439 "build/parser.cpp"
    break;

  case 202: /* when_clauses: when_clause  */
#line 1284 "src/parser.y"
                {
        (yyval.when_list) = new std::vector<WhenData*>();
        (yyval.when_list)->push_back((yyvsp[0].when_data));
    }
#line 4448 "build/parser.cpp"
    break;

  case 203: /* when_clauses: when_clauses when_clause  */
#line 1288 "src/parser.y"
                               {
        (yyval.when_list) = (yyvsp[-1].when_list);
        (yyval.when_list)->push_back((yyvsp[0].when_data));
    }
#line 4457 "build/parser.cpp"
    break;

  case 204: /* when_clause: KW_WHEN expression SEMICOLON statement_list  */
#line 1295 "src/parser.y"
                                                {
        (yyval.when_data) = new WhenData();
        (yyval.when_data)->cond = (yyvsp[-2].expr);
        (yyval.when_data)->body = std::move((yyvsp[0].stmt_list)->stmts);
        delete (yyvsp[0].stmt_list);
    }
#line 4468 "build/parser.cpp"
    break;

  case 205: /* other_clause: %empty  */
#line 1304 "src/parser.y"
                { (yyval.stmt_list) = nullptr; }
#line 4474 "build/parser.cpp"
    break;

  case 206: /* other_clause: KW_OTHER SEMICOLON statement_list  */
#line 1305 "src/parser.y"
                                        {
        (yyval.stmt_list) = (yyvsp[0].stmt_list);
    }
#line 4482 "build/parser.cpp"
    break;

  case 207: /* iter_stmt: KW_ITER SEMICOLON  */
#line 1311 "src/parser.y"
                      { (yyval.stmt) = new rpg::IterStmt(); }
#line 4488 "build/parser.cpp"
    break;

  case 208: /* leave_stmt: KW_LEAVE SEMICOLON  */
#line 1315 "src/parser.y"
                       { (yyval.stmt) = new rpg::LeaveStmt(); }
#line 4494 "build/parser.cpp"
    break;

  case 209: /* expression: or_expr  */
#line 1321 "src/parser.y"
            { (yyval.expr) = (yyvsp[0].expr); }
#line 4500 "build/parser.cpp"
    break;

  case 210: /* or_expr: and_expr  */
#line 1325 "src/parser.y"
             { (yyval.expr) = (yyvsp[0].expr); }
#line 4506 "build/parser.cpp"
    break;

  case 211: /* or_expr: or_expr KW_OR and_expr  */
#line 1326 "src/parser.y"
                             {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::OR,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 4516 "build/parser.cpp"
    break;

  case 212: /* and_expr: not_expr  */
#line 1334 "src/parser.y"
             { (yyval.expr) = (yyvsp[0].expr); }
#line 4522 "build/parser.cpp"
    break;

  case 213: /* and_expr: and_expr KW_AND not_expr  */
#line 1335 "src/parser.y"
                               {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::AND,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 4532 "build/parser.cpp"
    break;

  case 214: /* not_expr: comparison_expr  */
#line 1343 "src/parser.y"
                    { (yyval.expr) = (yyvsp[0].expr); }
#line 4538 "build/parser.cpp"
    break;

  case 215: /* not_expr: KW_NOT comparison_expr  */
#line 1344 "src/parser.y"
                             {
        (yyval.expr) = new rpg::NotExpr(std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 4546 "build/parser.cpp"
    break;

  case 216: /* comparison_expr: additive_expr  */
#line 1350 "src/parser.y"
                  { (yyval.expr) = (yyvsp[0].expr); }
#line 4552 "build/parser.cpp"
    break;

  case 217: /* comparison_expr: comparison_expr EQUALS additive_expr  */
#line 1351 "src/parser.y"
                                           {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::EQ,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 4562 "build/parser.cpp"
    break;

  case 218: /* comparison_expr: comparison_expr NE additive_expr  */
#line 1356 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::NE,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 4572 "build/parser.cpp"
    break;

  case 219: /* comparison_expr: comparison_expr LT additive_expr  */
#line 1361 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::LT,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 4582 "build/parser.cpp"
    break;

  case 220: /* comparison_expr: comparison_expr GT additive_expr  */
#line 1366 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::GT,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 4592 "build/parser.cpp"
    break;

  case 221: /* comparison_expr: comparison_expr LE additive_expr  */
#line 1371 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::LE,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 4602 "build/parser.cpp"
    break;

  case 222: /* comparison_expr: comparison_expr GE additive_expr  */
#line 1376 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::GE,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 4612 "build/parser.cpp"
    break;

  case 223: /* comparison_expr: additive_expr KW_IN additive_expr  */
#line 1381 "src/parser.y"
                                        {
        (yyval.expr) = new rpg::InExpr(
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 4622 "build/parser.cpp"
    break;

  case 224: /* additive_expr: multiplicative_expr  */
#line 1389 "src/parser.y"
                        { (yyval.expr) = (yyvsp[0].expr); }
#line 4628 "build/parser.cpp"
    break;

  case 225: /* additive_expr: additive_expr PLUS multiplicative_expr  */
#line 1390 "src/parser.y"
                                             {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::ADD,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 4638 "build/parser.cpp"
    break;

  case 226: /* additive_expr: additive_expr MINUS multiplicative_expr  */
#line 1395 "src/parser.y"
                                              {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::SUB,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 4648 "build/parser.cpp"
    break;

  case 227: /* multiplicative_expr: unary_expr  */
#line 1403 "src/parser.y"
               { (yyval.expr) = (yyvsp[0].expr); }
#line 4654 "build/parser.cpp"
    break;

  case 228: /* multiplicative_expr: multiplicative_expr STAR unary_expr  */
#line 1404 "src/parser.y"
                                          {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::MUL,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 4664 "build/parser.cpp"
    break;

  case 229: /* multiplicative_expr: multiplicative_expr SLASH unary_expr  */
#line 1409 "src/parser.y"
                                           {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::DIV,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 4674 "build/parser.cpp"
    break;

  case 230: /* unary_expr: postfix_expr  */
#line 1417 "src/parser.y"
                 { (yyval.expr) = (yyvsp[0].expr); }
#line 4680 "build/parser.cpp"
    break;

  case 231: /* unary_expr: MINUS postfix_expr  */
#line 1418 "src/parser.y"
                         {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::SUB,
            std::unique_ptr<rpg::Expression>(new rpg::IntLiteral(0)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 4690 "build/parser.cpp"
    break;

  case 232: /* postfix_expr: primary_expr  */
#line 1426 "src/parser.y"
                 { (yyval.expr) = (yyvsp[0].expr); }
#line 4696 "build/parser.cpp"
    break;

  case 233: /* postfix_expr: postfix_expr DOT IDENTIFIER  */
#line 1427 "src/parser.y"
                                  {
        (yyval.expr) = new rpg::DotExpr(std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)), (yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 4705 "build/parser.cpp"
    break;

  case 234: /* ident: IDENTIFIER  */
#line 1434 "src/parser.y"
               { (yyval.sval) = (yyvsp[0].sval); }
#line 4711 "build/parser.cpp"
    break;

  case 235: /* ident: KW_UNS  */
#line 1435 "src/parser.y"
             { (yyval.sval) = strdup("UNS"); }
#line 4717 "build/parser.cpp"
    break;

  case 236: /* ident: KW_FLOAT_TYPE  */
#line 1436 "src/parser.y"
                    { (yyval.sval) = strdup("FLOAT"); }
#line 4723 "build/parser.cpp"
    break;

  case 237: /* ident: KW_GRAPH  */
#line 1437 "src/parser.y"
               { (yyval.sval) = strdup("GRAPH"); }
#line 4729 "build/parser.cpp"
    break;

  case 238: /* ident: KW_OCCURS  */
#line 1438 "src/parser.y"
                { (yyval.sval) = strdup("OCCURS"); }
#line 4735 "build/parser.cpp"
    break;

  case 239: /* ident: KW_ASCEND  */
#line 1439 "src/parser.y"
                { (yyval.sval) = strdup("ASCEND"); }
#line 4741 "build/parser.cpp"
    break;

  case 240: /* ident: KW_DESCEND  */
#line 1440 "src/parser.y"
                 { (yyval.sval) = strdup("DESCEND"); }
#line 4747 "build/parser.cpp"
    break;

  case 241: /* ident: KW_IN  */
#line 1441 "src/parser.y"
            { (yyval.sval) = strdup("IN"); }
#line 4753 "build/parser.cpp"
    break;

  case 242: /* ident: KW_RTNPARM  */
#line 1442 "src/parser.y"
                 { (yyval.sval) = strdup("RTNPARM"); }
#line 4759 "build/parser.cpp"
    break;

  case 243: /* ident: KW_OPDESC  */
#line 1443 "src/parser.y"
                { (yyval.sval) = strdup("OPDESC"); }
#line 4765 "build/parser.cpp"
    break;

  case 244: /* ident: KW_NULLIND  */
#line 1444 "src/parser.y"
                 { (yyval.sval) = strdup("NULLIND"); }
#line 4771 "build/parser.cpp"
    break;

  case 245: /* ident: KW_DATFMT  */
#line 1445 "src/parser.y"
                { (yyval.sval) = strdup("DATFMT"); }
#line 4777 "build/parser.cpp"
    break;

  case 246: /* ident: KW_TIMFMT  */
#line 1446 "src/parser.y"
                { (yyval.sval) = strdup("TIMFMT"); }
#line 4783 "build/parser.cpp"
    break;

  case 247: /* ident: KW_EXTNAME  */
#line 1447 "src/parser.y"
                 { (yyval.sval) = strdup("EXTNAME"); }
#line 4789 "build/parser.cpp"
    break;

  case 248: /* primary_expr: IDENTIFIER  */
#line 1451 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier((yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 4798 "build/parser.cpp"
    break;

  case 249: /* primary_expr: KW_UNS  */
#line 1455 "src/parser.y"
             { (yyval.expr) = new rpg::Identifier("UNS"); }
#line 4804 "build/parser.cpp"
    break;

  case 250: /* primary_expr: KW_FLOAT_TYPE  */
#line 1456 "src/parser.y"
                    { (yyval.expr) = new rpg::Identifier("FLOAT"); }
#line 4810 "build/parser.cpp"
    break;

  case 251: /* primary_expr: KW_GRAPH  */
#line 1457 "src/parser.y"
               { (yyval.expr) = new rpg::Identifier("GRAPH"); }
#line 4816 "build/parser.cpp"
    break;

  case 252: /* primary_expr: KW_OCCURS  */
#line 1458 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("OCCURS"); }
#line 4822 "build/parser.cpp"
    break;

  case 253: /* primary_expr: KW_ASCEND  */
#line 1459 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("ASCEND"); }
#line 4828 "build/parser.cpp"
    break;

  case 254: /* primary_expr: KW_DESCEND  */
#line 1460 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("DESCEND"); }
#line 4834 "build/parser.cpp"
    break;

  case 255: /* primary_expr: KW_RTNPARM  */
#line 1461 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("RTNPARM"); }
#line 4840 "build/parser.cpp"
    break;

  case 256: /* primary_expr: KW_OPDESC  */
#line 1462 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("OPDESC"); }
#line 4846 "build/parser.cpp"
    break;

  case 257: /* primary_expr: KW_NULLIND  */
#line 1463 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("NULLIND"); }
#line 4852 "build/parser.cpp"
    break;

  case 258: /* primary_expr: KW_DATFMT  */
#line 1464 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("DATFMT"); }
#line 4858 "build/parser.cpp"
    break;

  case 259: /* primary_expr: KW_TIMFMT  */
#line 1465 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("TIMFMT"); }
#line 4864 "build/parser.cpp"
    break;

  case 260: /* primary_expr: KW_EXTNAME  */
#line 1466 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("EXTNAME"); }
#line 4870 "build/parser.cpp"
    break;

  case 261: /* primary_expr: INTEGER_LITERAL  */
#line 1467 "src/parser.y"
                      {
        (yyval.expr) = new rpg::IntLiteral((yyvsp[0].ival));
    }
#line 4878 "build/parser.cpp"
    break;

  case 262: /* primary_expr: FLOAT_LITERAL  */
#line 1470 "src/parser.y"
                    {
        (yyval.expr) = new rpg::FloatLiteral((yyvsp[0].fval));
    }
#line 4886 "build/parser.cpp"
    break;

  case 263: /* primary_expr: STRING_LITERAL  */
#line 1473 "src/parser.y"
                     {
        (yyval.expr) = new rpg::StringLiteral((yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 4895 "build/parser.cpp"
    break;

  case 264: /* primary_expr: IDENTIFIER LPAREN call_args_opt RPAREN  */
#line 1477 "src/parser.y"
                                             {
        (yyval.expr) = make_func((yyvsp[-3].sval), (yyvsp[-1].expr_list));
        free((yyvsp[-3].sval));
    }
#line 4904 "build/parser.cpp"
    break;

  case 265: /* primary_expr: BIF_CHAR LPAREN arg_list RPAREN  */
#line 1481 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("CHAR", (yyvsp[-1].expr_list));
    }
#line 4912 "build/parser.cpp"
    break;

  case 266: /* primary_expr: BIF_TRIM LPAREN arg_list RPAREN  */
#line 1484 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("TRIM", (yyvsp[-1].expr_list));
    }
#line 4920 "build/parser.cpp"
    break;

  case 267: /* primary_expr: BIF_TRIML LPAREN arg_list RPAREN  */
#line 1487 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("TRIML", (yyvsp[-1].expr_list));
    }
#line 4928 "build/parser.cpp"
    break;

  case 268: /* primary_expr: BIF_TRIMR LPAREN arg_list RPAREN  */
#line 1490 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("TRIMR", (yyvsp[-1].expr_list));
    }
#line 4936 "build/parser.cpp"
    break;

  case 269: /* primary_expr: BIF_LEN LPAREN arg_list RPAREN  */
#line 1493 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("LEN", (yyvsp[-1].expr_list));
    }
#line 4944 "build/parser.cpp"
    break;

  case 270: /* primary_expr: BIF_SUBST LPAREN arg_list RPAREN  */
#line 1496 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("SUBST", (yyvsp[-1].expr_list));
    }
#line 4952 "build/parser.cpp"
    break;

  case 271: /* primary_expr: BIF_SCAN LPAREN arg_list RPAREN  */
#line 1499 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("SCAN", (yyvsp[-1].expr_list));
    }
#line 4960 "build/parser.cpp"
    break;

  case 272: /* primary_expr: BIF_SCANRPL LPAREN arg_list RPAREN  */
#line 1502 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("SCANRPL", (yyvsp[-1].expr_list));
    }
#line 4968 "build/parser.cpp"
    break;

  case 273: /* primary_expr: BIF_XLATE LPAREN arg_list RPAREN  */
#line 1505 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("XLATE", (yyvsp[-1].expr_list));
    }
#line 4976 "build/parser.cpp"
    break;

  case 274: /* primary_expr: BIF_DEC LPAREN arg_list RPAREN  */
#line 1508 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("DEC", (yyvsp[-1].expr_list));
    }
#line 4984 "build/parser.cpp"
    break;

  case 275: /* primary_expr: BIF_INT LPAREN arg_list RPAREN  */
#line 1511 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("INT", (yyvsp[-1].expr_list));
    }
#line 4992 "build/parser.cpp"
    break;

  case 276: /* primary_expr: BIF_ELEM LPAREN arg_list RPAREN  */
#line 1514 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("ELEM", (yyvsp[-1].expr_list));
    }
#line 5000 "build/parser.cpp"
    break;

  case 277: /* primary_expr: BIF_PARMS LPAREN RPAREN  */
#line 1517 "src/parser.y"
                              {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("PARMS", empty);
    }
#line 5009 "build/parser.cpp"
    break;

  case 278: /* primary_expr: BIF_LOOKUP LPAREN arg_list RPAREN  */
#line 1521 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("LOOKUP", (yyvsp[-1].expr_list));
    }
#line 5017 "build/parser.cpp"
    break;

  case 279: /* primary_expr: BIF_EDITC LPAREN arg_list RPAREN  */
#line 1524 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("EDITC", (yyvsp[-1].expr_list));
    }
#line 5025 "build/parser.cpp"
    break;

  case 280: /* primary_expr: BIF_EDITW LPAREN arg_list RPAREN  */
#line 1527 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("EDITW", (yyvsp[-1].expr_list));
    }
#line 5033 "build/parser.cpp"
    break;

  case 281: /* primary_expr: BIF_REPLACE LPAREN arg_list RPAREN  */
#line 1530 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("REPLACE", (yyvsp[-1].expr_list));
    }
#line 5041 "build/parser.cpp"
    break;

  case 282: /* primary_expr: BIF_CHECK LPAREN arg_list RPAREN  */
#line 1533 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("CHECK", (yyvsp[-1].expr_list));
    }
#line 5049 "build/parser.cpp"
    break;

  case 283: /* primary_expr: BIF_CHECKR LPAREN arg_list RPAREN  */
#line 1536 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("CHECKR", (yyvsp[-1].expr_list));
    }
#line 5057 "build/parser.cpp"
    break;

  case 284: /* primary_expr: BIF_LOWER LPAREN arg_list RPAREN  */
#line 1539 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("LOWER", (yyvsp[-1].expr_list));
    }
#line 5065 "build/parser.cpp"
    break;

  case 285: /* primary_expr: BIF_UPPER LPAREN arg_list RPAREN  */
#line 1542 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("UPPER", (yyvsp[-1].expr_list));
    }
#line 5073 "build/parser.cpp"
    break;

  case 286: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_YEARS RPAREN  */
#line 1545 "src/parser.y"
                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("YEARS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 5084 "build/parser.cpp"
    break;

  case 287: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_MONTHS RPAREN  */
#line 1551 "src/parser.y"
                                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MONTHS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 5095 "build/parser.cpp"
    break;

  case 288: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_DAYS RPAREN  */
#line 1557 "src/parser.y"
                                                       {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("DAYS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 5106 "build/parser.cpp"
    break;

  case 289: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_HOURS RPAREN  */
#line 1563 "src/parser.y"
                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("HOURS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 5117 "build/parser.cpp"
    break;

  case 290: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_MINUTES RPAREN  */
#line 1569 "src/parser.y"
                                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MINUTES"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 5128 "build/parser.cpp"
    break;

  case 291: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_SECONDS RPAREN  */
#line 1575 "src/parser.y"
                                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("SECONDS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 5139 "build/parser.cpp"
    break;

  case 292: /* primary_expr: BIF_FLOAT LPAREN arg_list RPAREN  */
#line 1581 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("FLOAT", (yyvsp[-1].expr_list));
    }
#line 5147 "build/parser.cpp"
    break;

  case 293: /* primary_expr: BIF_SQRT LPAREN arg_list RPAREN  */
#line 1584 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("SQRT", (yyvsp[-1].expr_list));
    }
#line 5155 "build/parser.cpp"
    break;

  case 294: /* primary_expr: BIF_MAX LPAREN arg_list RPAREN  */
#line 1587 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("MAX", (yyvsp[-1].expr_list));
    }
#line 5163 "build/parser.cpp"
    break;

  case 295: /* primary_expr: BIF_MIN LPAREN arg_list RPAREN  */
#line 1590 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("MIN", (yyvsp[-1].expr_list));
    }
#line 5171 "build/parser.cpp"
    break;

  case 296: /* primary_expr: BIF_STATUS LPAREN RPAREN  */
#line 1593 "src/parser.y"
                               {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("STATUS", empty);
    }
#line 5180 "build/parser.cpp"
    break;

  case 297: /* primary_expr: BIF_ERROR LPAREN RPAREN  */
#line 1597 "src/parser.y"
                              {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("ERROR", empty);
    }
#line 5189 "build/parser.cpp"
    break;

  case 298: /* primary_expr: BIF_SIZE LPAREN arg_list RPAREN  */
#line 1601 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("SIZE", (yyvsp[-1].expr_list));
    }
#line 5197 "build/parser.cpp"
    break;

  case 299: /* primary_expr: BIF_ADDR LPAREN arg_list RPAREN  */
#line 1604 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("ADDR", (yyvsp[-1].expr_list));
    }
#line 5205 "build/parser.cpp"
    break;

  case 300: /* primary_expr: BIF_ABS LPAREN arg_list RPAREN  */
#line 1607 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("ABS", (yyvsp[-1].expr_list));
    }
#line 5213 "build/parser.cpp"
    break;

  case 301: /* primary_expr: BIF_DIV LPAREN arg_list RPAREN  */
#line 1610 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("DIV", (yyvsp[-1].expr_list));
    }
#line 5221 "build/parser.cpp"
    break;

  case 302: /* primary_expr: BIF_REM LPAREN arg_list RPAREN  */
#line 1613 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("REM", (yyvsp[-1].expr_list));
    }
#line 5229 "build/parser.cpp"
    break;

  case 303: /* primary_expr: BIF_DATE LPAREN arg_list RPAREN  */
#line 1616 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("DATE", (yyvsp[-1].expr_list));
    }
#line 5237 "build/parser.cpp"
    break;

  case 304: /* primary_expr: BIF_DATE LPAREN RPAREN  */
#line 1619 "src/parser.y"
                             {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("DATE", empty);
    }
#line 5246 "build/parser.cpp"
    break;

  case 305: /* primary_expr: BIF_TIME LPAREN arg_list RPAREN  */
#line 1623 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("TIME", (yyvsp[-1].expr_list));
    }
#line 5254 "build/parser.cpp"
    break;

  case 306: /* primary_expr: BIF_TIME LPAREN RPAREN  */
#line 1626 "src/parser.y"
                             {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("TIME", empty);
    }
#line 5263 "build/parser.cpp"
    break;

  case 307: /* primary_expr: BIF_TIMESTAMP LPAREN arg_list RPAREN  */
#line 1630 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TIMESTAMP", (yyvsp[-1].expr_list));
    }
#line 5271 "build/parser.cpp"
    break;

  case 308: /* primary_expr: BIF_TIMESTAMP LPAREN RPAREN  */
#line 1633 "src/parser.y"
                                  {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("TIMESTAMP", empty);
    }
#line 5280 "build/parser.cpp"
    break;

  case 309: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_DAYS RPAREN  */
#line 1637 "src/parser.y"
                                                                       {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("DAYS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 5292 "build/parser.cpp"
    break;

  case 310: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_MONTHS RPAREN  */
#line 1644 "src/parser.y"
                                                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MONTHS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 5304 "build/parser.cpp"
    break;

  case 311: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_YEARS RPAREN  */
#line 1651 "src/parser.y"
                                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("YEARS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 5316 "build/parser.cpp"
    break;

  case 312: /* primary_expr: BIF_DAYS LPAREN expression RPAREN  */
#line 1658 "src/parser.y"
                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("DAYS", args);
    }
#line 5326 "build/parser.cpp"
    break;

  case 313: /* primary_expr: BIF_MONTHS LPAREN expression RPAREN  */
#line 1663 "src/parser.y"
                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("MONTHS", args);
    }
#line 5336 "build/parser.cpp"
    break;

  case 314: /* primary_expr: BIF_YEARS LPAREN expression RPAREN  */
#line 1668 "src/parser.y"
                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("YEARS", args);
    }
#line 5346 "build/parser.cpp"
    break;

  case 315: /* primary_expr: BIF_FOUND LPAREN RPAREN  */
#line 1673 "src/parser.y"
                              {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("FOUND", empty);
    }
#line 5355 "build/parser.cpp"
    break;

  case 316: /* primary_expr: BIF_EOF LPAREN RPAREN  */
#line 1677 "src/parser.y"
                            {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("EOF", empty);
    }
#line 5364 "build/parser.cpp"
    break;

  case 317: /* primary_expr: BIF_ALLOC LPAREN arg_list RPAREN  */
#line 1681 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("ALLOC", (yyvsp[-1].expr_list));
    }
#line 5372 "build/parser.cpp"
    break;

  case 318: /* primary_expr: BIF_REALLOC LPAREN arg_list RPAREN  */
#line 1684 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("REALLOC", (yyvsp[-1].expr_list));
    }
#line 5380 "build/parser.cpp"
    break;

  case 319: /* primary_expr: BIF_XFOOT LPAREN arg_list RPAREN  */
#line 1687 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("XFOOT", (yyvsp[-1].expr_list));
    }
#line 5388 "build/parser.cpp"
    break;

  case 320: /* primary_expr: BIF_UNS LPAREN arg_list RPAREN  */
#line 1690 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("UNS", (yyvsp[-1].expr_list));
    }
#line 5396 "build/parser.cpp"
    break;

  case 321: /* primary_expr: BIF_INTH LPAREN arg_list RPAREN  */
#line 1693 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("INTH", (yyvsp[-1].expr_list));
    }
#line 5404 "build/parser.cpp"
    break;

  case 322: /* primary_expr: BIF_DECH LPAREN arg_list RPAREN  */
#line 1696 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("DECH", (yyvsp[-1].expr_list));
    }
#line 5412 "build/parser.cpp"
    break;

  case 323: /* primary_expr: BIF_DECPOS LPAREN arg_list RPAREN  */
#line 1699 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("DECPOS", (yyvsp[-1].expr_list));
    }
#line 5420 "build/parser.cpp"
    break;

  case 324: /* primary_expr: BIF_SPLIT LPAREN arg_list RPAREN  */
#line 1702 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("SPLIT", (yyvsp[-1].expr_list));
    }
#line 5428 "build/parser.cpp"
    break;

  case 325: /* primary_expr: BIF_CONCATARR LPAREN arg_list RPAREN  */
#line 1705 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("CONCATARR", (yyvsp[-1].expr_list));
    }
#line 5436 "build/parser.cpp"
    break;

  case 326: /* primary_expr: BIF_LEFT LPAREN arg_list RPAREN  */
#line 1708 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("LEFT", (yyvsp[-1].expr_list));
    }
#line 5444 "build/parser.cpp"
    break;

  case 327: /* primary_expr: BIF_RIGHT LPAREN arg_list RPAREN  */
#line 1711 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("RIGHT", (yyvsp[-1].expr_list));
    }
#line 5452 "build/parser.cpp"
    break;

  case 328: /* primary_expr: BIF_STR LPAREN arg_list RPAREN  */
#line 1714 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("STR", (yyvsp[-1].expr_list));
    }
#line 5460 "build/parser.cpp"
    break;

  case 329: /* primary_expr: BIF_SUBARR LPAREN arg_list RPAREN  */
#line 1717 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("SUBARR", (yyvsp[-1].expr_list));
    }
#line 5468 "build/parser.cpp"
    break;

  case 330: /* primary_expr: BIF_MAXARR LPAREN arg_list RPAREN  */
#line 1720 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("MAXARR", (yyvsp[-1].expr_list));
    }
#line 5476 "build/parser.cpp"
    break;

  case 331: /* primary_expr: BIF_MINARR LPAREN arg_list RPAREN  */
#line 1723 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("MINARR", (yyvsp[-1].expr_list));
    }
#line 5484 "build/parser.cpp"
    break;

  case 332: /* primary_expr: BIF_LIST LPAREN arg_list RPAREN  */
#line 1726 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("LIST", (yyvsp[-1].expr_list));
    }
#line 5492 "build/parser.cpp"
    break;

  case 333: /* primary_expr: BIF_RANGE LPAREN arg_list RPAREN  */
#line 1729 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("RANGE", (yyvsp[-1].expr_list));
    }
#line 5500 "build/parser.cpp"
    break;

  case 334: /* primary_expr: BIF_LOOKUPLT LPAREN arg_list RPAREN  */
#line 1732 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPLT", (yyvsp[-1].expr_list));
    }
#line 5508 "build/parser.cpp"
    break;

  case 335: /* primary_expr: BIF_LOOKUPGE LPAREN arg_list RPAREN  */
#line 1735 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPGE", (yyvsp[-1].expr_list));
    }
#line 5516 "build/parser.cpp"
    break;

  case 336: /* primary_expr: BIF_LOOKUPLE LPAREN arg_list RPAREN  */
#line 1738 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPLE", (yyvsp[-1].expr_list));
    }
#line 5524 "build/parser.cpp"
    break;

  case 337: /* primary_expr: BIF_LOOKUPGT LPAREN arg_list RPAREN  */
#line 1741 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPGT", (yyvsp[-1].expr_list));
    }
#line 5532 "build/parser.cpp"
    break;

  case 338: /* primary_expr: BIF_HOURS LPAREN expression RPAREN  */
#line 1744 "src/parser.y"
                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("HOURS", args);
    }
#line 5542 "build/parser.cpp"
    break;

  case 339: /* primary_expr: BIF_MINUTES LPAREN expression RPAREN  */
#line 1749 "src/parser.y"
                                           {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("MINUTES", args);
    }
#line 5552 "build/parser.cpp"
    break;

  case 340: /* primary_expr: BIF_SECONDS LPAREN expression RPAREN  */
#line 1754 "src/parser.y"
                                           {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("SECONDS", args);
    }
#line 5562 "build/parser.cpp"
    break;

  case 341: /* primary_expr: BIF_MSECONDS LPAREN expression RPAREN  */
#line 1759 "src/parser.y"
                                            {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("MSECONDS", args);
    }
#line 5572 "build/parser.cpp"
    break;

  case 342: /* primary_expr: BIF_PADDR LPAREN IDENTIFIER RPAREN  */
#line 1764 "src/parser.y"
                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::StringLiteral((yyvsp[-1].sval)));
        free((yyvsp[-1].sval));
        (yyval.expr) = make_bif("PADDR", args);
    }
#line 5583 "build/parser.cpp"
    break;

  case 343: /* primary_expr: BIF_PROC LPAREN RPAREN  */
#line 1770 "src/parser.y"
                             {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("PROC", empty);
    }
#line 5592 "build/parser.cpp"
    break;

  case 344: /* primary_expr: BIF_PROC  */
#line 1774 "src/parser.y"
               {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("PROC", empty);
    }
#line 5601 "build/parser.cpp"
    break;

  case 345: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_HOURS RPAREN  */
#line 1778 "src/parser.y"
                                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("HOURS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 5613 "build/parser.cpp"
    break;

  case 346: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_MINUTES RPAREN  */
#line 1785 "src/parser.y"
                                                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MINUTES"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 5625 "build/parser.cpp"
    break;

  case 347: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_SECONDS RPAREN  */
#line 1792 "src/parser.y"
                                                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("SECONDS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 5637 "build/parser.cpp"
    break;

  case 348: /* primary_expr: KW_ALL STRING_LITERAL  */
#line 1799 "src/parser.y"
                            {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::StringLiteral((yyvsp[0].sval)));
        free((yyvsp[0].sval));
        (yyval.expr) = make_bif("ALL", args);
    }
#line 5648 "build/parser.cpp"
    break;

  case 349: /* primary_expr: BIF_PASSED LPAREN ident RPAREN  */
#line 1805 "src/parser.y"
                                     {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::Identifier((yyvsp[-1].sval)));
        free((yyvsp[-1].sval));
        (yyval.expr) = make_bif("PASSED", args);
    }
#line 5659 "build/parser.cpp"
    break;

  case 350: /* primary_expr: BIF_OMITTED LPAREN ident RPAREN  */
#line 1811 "src/parser.y"
                                      {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::Identifier((yyvsp[-1].sval)));
        free((yyvsp[-1].sval));
        (yyval.expr) = make_bif("OMITTED", args);
    }
#line 5670 "build/parser.cpp"
    break;

  case 351: /* primary_expr: BIF_OCCUR LPAREN arg_list RPAREN  */
#line 1817 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("OCCUR", (yyvsp[-1].expr_list));
    }
#line 5678 "build/parser.cpp"
    break;

  case 352: /* primary_expr: INDICATOR  */
#line 1820 "src/parser.y"
                {
        (yyval.expr) = new rpg::IndicatorExpr((yyvsp[0].ival));
    }
#line 5686 "build/parser.cpp"
    break;

  case 353: /* primary_expr: KW_ON  */
#line 1823 "src/parser.y"
            {
        (yyval.expr) = new rpg::IntLiteral(1);  // *ON → true
    }
#line 5694 "build/parser.cpp"
    break;

  case 354: /* primary_expr: KW_OFF  */
#line 1826 "src/parser.y"
             {
        (yyval.expr) = new rpg::IntLiteral(0);  // *OFF → false
    }
#line 5702 "build/parser.cpp"
    break;

  case 355: /* primary_expr: KW_NULL  */
#line 1829 "src/parser.y"
              {
        (yyval.expr) = new rpg::Identifier("nullptr");
    }
#line 5710 "build/parser.cpp"
    break;

  case 356: /* primary_expr: KW_BLANKS  */
#line 1832 "src/parser.y"
                {
        (yyval.expr) = new rpg::Identifier("RPG_BLANKS");
    }
#line 5718 "build/parser.cpp"
    break;

  case 357: /* primary_expr: KW_ZEROS  */
#line 1835 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier("RPG_ZEROS");
    }
#line 5726 "build/parser.cpp"
    break;

  case 358: /* primary_expr: KW_HIVAL  */
#line 1838 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier("RPG_HIVAL");
    }
#line 5734 "build/parser.cpp"
    break;

  case 359: /* primary_expr: KW_LOVAL  */
#line 1841 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier("RPG_LOVAL");
    }
#line 5742 "build/parser.cpp"
    break;

  case 360: /* primary_expr: LPAREN expression RPAREN  */
#line 1844 "src/parser.y"
                               {
        (yyval.expr) = (yyvsp[-1].expr);
    }
#line 5750 "build/parser.cpp"
    break;

  case 361: /* call_args_opt: %empty  */
#line 1851 "src/parser.y"
                { (yyval.expr_list) = nullptr; }
#line 5756 "build/parser.cpp"
    break;

  case 362: /* call_args_opt: call_arg_list  */
#line 1852 "src/parser.y"
                    { (yyval.expr_list) = (yyvsp[0].expr_list); }
#line 5762 "build/parser.cpp"
    break;

  case 363: /* call_arg_list: expression  */
#line 1856 "src/parser.y"
               {
        (yyval.expr_list) = new std::vector<rpg::Expression*>();
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 5771 "build/parser.cpp"
    break;

  case 364: /* call_arg_list: call_arg_list COLON expression  */
#line 1860 "src/parser.y"
                                     {
        (yyval.expr_list) = (yyvsp[-2].expr_list);
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 5780 "build/parser.cpp"
    break;

  case 365: /* arg_list: expression  */
#line 1868 "src/parser.y"
               {
        (yyval.expr_list) = new std::vector<rpg::Expression*>();
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 5789 "build/parser.cpp"
    break;

  case 366: /* arg_list: arg_list COLON expression  */
#line 1872 "src/parser.y"
                                {
        (yyval.expr_list) = (yyvsp[-2].expr_list);
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 5798 "build/parser.cpp"
    break;


#line 5802 "build/parser.cpp"

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

#line 1878 "src/parser.y"


void yyerror(const char* s) {
    g_error_count++;
    fprintf(stderr, "Error at line %d: %s (near '%s')\n", yylineno, s, yytext);
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
