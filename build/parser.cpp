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
  YYSYMBOL_BIF_CONCAT = 157,               /* BIF_CONCAT  */
  YYSYMBOL_BIF_CONCATARR = 158,            /* BIF_CONCATARR  */
  YYSYMBOL_BIF_LEFT = 159,                 /* BIF_LEFT  */
  YYSYMBOL_BIF_RIGHT = 160,                /* BIF_RIGHT  */
  YYSYMBOL_BIF_STR = 161,                  /* BIF_STR  */
  YYSYMBOL_BIF_MAXARR = 162,               /* BIF_MAXARR  */
  YYSYMBOL_BIF_MINARR = 163,               /* BIF_MINARR  */
  YYSYMBOL_BIF_LIST = 164,                 /* BIF_LIST  */
  YYSYMBOL_BIF_RANGE = 165,                /* BIF_RANGE  */
  YYSYMBOL_BIF_LOOKUPLT = 166,             /* BIF_LOOKUPLT  */
  YYSYMBOL_BIF_LOOKUPGE = 167,             /* BIF_LOOKUPGE  */
  YYSYMBOL_BIF_LOOKUPLE = 168,             /* BIF_LOOKUPLE  */
  YYSYMBOL_BIF_LOOKUPGT = 169,             /* BIF_LOOKUPGT  */
  YYSYMBOL_BIF_TLOOKUP = 170,              /* BIF_TLOOKUP  */
  YYSYMBOL_BIF_TLOOKUPLT = 171,            /* BIF_TLOOKUPLT  */
  YYSYMBOL_BIF_TLOOKUPGT = 172,            /* BIF_TLOOKUPGT  */
  YYSYMBOL_BIF_TLOOKUPLE = 173,            /* BIF_TLOOKUPLE  */
  YYSYMBOL_BIF_TLOOKUPGE = 174,            /* BIF_TLOOKUPGE  */
  YYSYMBOL_BIF_HOURS = 175,                /* BIF_HOURS  */
  YYSYMBOL_BIF_MINUTES = 176,              /* BIF_MINUTES  */
  YYSYMBOL_BIF_SECONDS = 177,              /* BIF_SECONDS  */
  YYSYMBOL_BIF_MSECONDS = 178,             /* BIF_MSECONDS  */
  YYSYMBOL_BIF_PADDR = 179,                /* BIF_PADDR  */
  YYSYMBOL_BIF_PROC = 180,                 /* BIF_PROC  */
  YYSYMBOL_BIF_PASSED = 181,               /* BIF_PASSED  */
  YYSYMBOL_BIF_OMITTED = 182,              /* BIF_OMITTED  */
  YYSYMBOL_BIF_BITAND = 183,               /* BIF_BITAND  */
  YYSYMBOL_BIF_BITNOT = 184,               /* BIF_BITNOT  */
  YYSYMBOL_BIF_BITOR = 185,                /* BIF_BITOR  */
  YYSYMBOL_BIF_BITXOR = 186,               /* BIF_BITXOR  */
  YYSYMBOL_BIF_SCANR = 187,                /* BIF_SCANR  */
  YYSYMBOL_BIF_EDITFLT = 188,              /* BIF_EDITFLT  */
  YYSYMBOL_BIF_UNSH = 189,                 /* BIF_UNSH  */
  YYSYMBOL_BIF_PARMNUM = 190,              /* BIF_PARMNUM  */
  YYSYMBOL_KW_ALL = 191,                   /* KW_ALL  */
  YYSYMBOL_KW_UNS = 192,                   /* KW_UNS  */
  YYSYMBOL_KW_FLOAT_TYPE = 193,            /* KW_FLOAT_TYPE  */
  YYSYMBOL_KW_BINDEC = 194,                /* KW_BINDEC  */
  YYSYMBOL_KW_UCS2 = 195,                  /* KW_UCS2  */
  YYSYMBOL_KW_GRAPH = 196,                 /* KW_GRAPH  */
  YYSYMBOL_KW_OBJECT = 197,                /* KW_OBJECT  */
  YYSYMBOL_KW_JAVA = 198,                  /* KW_JAVA  */
  YYSYMBOL_KW_OVERLAY = 199,               /* KW_OVERLAY  */
  YYSYMBOL_KW_POS = 200,                   /* KW_POS  */
  YYSYMBOL_KW_PREFIX = 201,                /* KW_PREFIX  */
  YYSYMBOL_KW_DATFMT = 202,                /* KW_DATFMT  */
  YYSYMBOL_KW_TIMFMT = 203,                /* KW_TIMFMT  */
  YYSYMBOL_KW_EXTNAME = 204,               /* KW_EXTNAME  */
  YYSYMBOL_KW_RTNPARM = 205,               /* KW_RTNPARM  */
  YYSYMBOL_KW_OPDESC = 206,                /* KW_OPDESC  */
  YYSYMBOL_KW_ASCEND = 207,                /* KW_ASCEND  */
  YYSYMBOL_KW_DESCEND = 208,               /* KW_DESCEND  */
  YYSYMBOL_KW_NULLIND = 209,               /* KW_NULLIND  */
  YYSYMBOL_KW_VARSIZE = 210,               /* KW_VARSIZE  */
  YYSYMBOL_KW_STRING_OPT = 211,            /* KW_STRING_OPT  */
  YYSYMBOL_KW_TRIM_OPT = 212,              /* KW_TRIM_OPT  */
  YYSYMBOL_KW_DCL_ENUM = 213,              /* KW_DCL_ENUM  */
  YYSYMBOL_KW_END_ENUM = 214,              /* KW_END_ENUM  */
  YYSYMBOL_KW_BOOLEAN = 215,               /* KW_BOOLEAN  */
  YYSYMBOL_POWER = 216,                    /* POWER  */
  YYSYMBOL_KW_DIM_VAR = 217,               /* KW_DIM_VAR  */
  YYSYMBOL_KW_DIM_AUTO = 218,              /* KW_DIM_AUTO  */
  YYSYMBOL_KW_FOR_EACH = 219,              /* KW_FOR_EACH  */
  YYSYMBOL_KW_IN = 220,                    /* KW_IN  */
  YYSYMBOL_IDENTIFIER = 221,               /* IDENTIFIER  */
  YYSYMBOL_INTEGER_LITERAL = 222,          /* INTEGER_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 223,            /* FLOAT_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 224,           /* STRING_LITERAL  */
  YYSYMBOL_SEMICOLON = 225,                /* SEMICOLON  */
  YYSYMBOL_EQUALS = 226,                   /* EQUALS  */
  YYSYMBOL_LPAREN = 227,                   /* LPAREN  */
  YYSYMBOL_RPAREN = 228,                   /* RPAREN  */
  YYSYMBOL_COLON = 229,                    /* COLON  */
  YYSYMBOL_PLUS = 230,                     /* PLUS  */
  YYSYMBOL_MINUS = 231,                    /* MINUS  */
  YYSYMBOL_STAR = 232,                     /* STAR  */
  YYSYMBOL_SLASH = 233,                    /* SLASH  */
  YYSYMBOL_NE = 234,                       /* NE  */
  YYSYMBOL_LE = 235,                       /* LE  */
  YYSYMBOL_GE = 236,                       /* GE  */
  YYSYMBOL_LT = 237,                       /* LT  */
  YYSYMBOL_GT = 238,                       /* GT  */
  YYSYMBOL_YYACCEPT = 239,                 /* $accept  */
  YYSYMBOL_program = 240,                  /* program  */
  YYSYMBOL_statements_opt = 241,           /* statements_opt  */
  YYSYMBOL_statement_list = 242,           /* statement_list  */
  YYSYMBOL_statement = 243,                /* statement  */
  YYSYMBOL_dcl_f_stmt = 244,               /* dcl_f_stmt  */
  YYSYMBOL_dcl_s_stmt = 245,               /* dcl_s_stmt  */
  YYSYMBOL_dcl_s_keywords = 246,           /* dcl_s_keywords  */
  YYSYMBOL_dcl_c_stmt = 247,               /* dcl_c_stmt  */
  YYSYMBOL_eval_target = 248,              /* eval_target  */
  YYSYMBOL_eval_stmt = 249,                /* eval_stmt  */
  YYSYMBOL_eval_corr_stmt = 250,           /* eval_corr_stmt  */
  YYSYMBOL_evalr_stmt = 251,               /* evalr_stmt  */
  YYSYMBOL_callp_stmt = 252,               /* callp_stmt  */
  YYSYMBOL_leavesr_stmt = 253,             /* leavesr_stmt  */
  YYSYMBOL_dsply_stmt = 254,               /* dsply_stmt  */
  YYSYMBOL_inlr_stmt = 255,                /* inlr_stmt  */
  YYSYMBOL_return_stmt = 256,              /* return_stmt  */
  YYSYMBOL_expr_stmt = 257,                /* expr_stmt  */
  YYSYMBOL_dcl_pr_stmt = 258,              /* dcl_pr_stmt  */
  YYSYMBOL_dcl_proc_stmt = 259,            /* dcl_proc_stmt  */
  YYSYMBOL_proc_export = 260,              /* proc_export  */
  YYSYMBOL_pi_return_type = 261,           /* pi_return_type  */
  YYSYMBOL_pi_params = 262,                /* pi_params  */
  YYSYMBOL_pi_param = 263,                 /* pi_param  */
  YYSYMBOL_pr_params = 264,                /* pr_params  */
  YYSYMBOL_pr_param = 265,                 /* pr_param  */
  YYSYMBOL_monitor_stmt = 266,             /* monitor_stmt  */
  YYSYMBOL_begsr_stmt = 267,               /* begsr_stmt  */
  YYSYMBOL_exsr_stmt = 268,                /* exsr_stmt  */
  YYSYMBOL_sorta_stmt = 269,               /* sorta_stmt  */
  YYSYMBOL_reset_stmt = 270,               /* reset_stmt  */
  YYSYMBOL_clear_stmt = 271,               /* clear_stmt  */
  YYSYMBOL_dealloc_stmt = 272,             /* dealloc_stmt  */
  YYSYMBOL_test_stmt = 273,                /* test_stmt  */
  YYSYMBOL_dcl_enum_stmt = 274,            /* dcl_enum_stmt  */
  YYSYMBOL_enum_constants = 275,           /* enum_constants  */
  YYSYMBOL_enum_constant = 276,            /* enum_constant  */
  YYSYMBOL_dcl_ds_stmt = 277,              /* dcl_ds_stmt  */
  YYSYMBOL_ds_fields = 278,                /* ds_fields  */
  YYSYMBOL_ds_field = 279,                 /* ds_field  */
  YYSYMBOL_if_stmt = 280,                  /* if_stmt  */
  YYSYMBOL_elseif_clauses = 281,           /* elseif_clauses  */
  YYSYMBOL_elseif_clause = 282,            /* elseif_clause  */
  YYSYMBOL_else_clause = 283,              /* else_clause  */
  YYSYMBOL_dow_stmt = 284,                 /* dow_stmt  */
  YYSYMBOL_dou_stmt = 285,                 /* dou_stmt  */
  YYSYMBOL_for_stmt = 286,                 /* for_stmt  */
  YYSYMBOL_for_each_stmt = 287,            /* for_each_stmt  */
  YYSYMBOL_select_stmt = 288,              /* select_stmt  */
  YYSYMBOL_when_clauses = 289,             /* when_clauses  */
  YYSYMBOL_when_clause = 290,              /* when_clause  */
  YYSYMBOL_other_clause = 291,             /* other_clause  */
  YYSYMBOL_iter_stmt = 292,                /* iter_stmt  */
  YYSYMBOL_leave_stmt = 293,               /* leave_stmt  */
  YYSYMBOL_expression = 294,               /* expression  */
  YYSYMBOL_or_expr = 295,                  /* or_expr  */
  YYSYMBOL_and_expr = 296,                 /* and_expr  */
  YYSYMBOL_not_expr = 297,                 /* not_expr  */
  YYSYMBOL_comparison_expr = 298,          /* comparison_expr  */
  YYSYMBOL_additive_expr = 299,            /* additive_expr  */
  YYSYMBOL_multiplicative_expr = 300,      /* multiplicative_expr  */
  YYSYMBOL_power_expr = 301,               /* power_expr  */
  YYSYMBOL_unary_expr = 302,               /* unary_expr  */
  YYSYMBOL_postfix_expr = 303,             /* postfix_expr  */
  YYSYMBOL_ident = 304,                    /* ident  */
  YYSYMBOL_primary_expr = 305,             /* primary_expr  */
  YYSYMBOL_call_args_opt = 306,            /* call_args_opt  */
  YYSYMBOL_call_arg_list = 307,            /* call_arg_list  */
  YYSYMBOL_arg_list = 308                  /* arg_list  */
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
#define YYLAST   4840

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  239
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  70
/* YYNRULES -- Number of rules.  */
#define YYNRULES  443
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1449

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   493


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
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     225,   226,   227,   228,   229,   230,   231,   232,   233,   234,
     235,   236,   237,   238
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   192,   192,   195,   200,   202,   207,   216,   219,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   265,   269,   273,   277,   285,   290,   295,   300,
     305,   310,   315,   320,   325,   330,   335,   340,   346,   352,
     358,   362,   366,   370,   374,   378,   382,   386,   390,   394,
     398,   404,   410,   416,   422,   429,   434,   440,   445,   450,
     455,   460,   465,   470,   475,   480,   485,   490,   495,   503,
     504,   505,   506,   507,   512,   519,   523,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   540,   546,   550,   556,   562,   568,   577,   585,   594,
     600,   606,   612,   618,   621,   628,   639,   656,   676,   691,
     715,   740,   767,   797,   798,   803,   804,   805,   806,   807,
     812,   815,   823,   827,   831,   835,   839,   843,   847,   851,
     856,   860,   864,   868,   872,   876,   880,   884,   888,   894,
     899,   904,   909,   915,   920,   925,   930,   936,   941,   946,
     955,   958,   966,   970,   974,   978,   982,   986,   990,   994,
     999,  1003,  1007,  1011,  1015,  1019,  1023,  1027,  1031,  1037,
    1042,  1047,  1052,  1058,  1063,  1068,  1073,  1079,  1084,  1089,
    1099,  1110,  1120,  1128,  1136,  1143,  1151,  1159,  1170,  1178,
    1189,  1192,  1200,  1208,  1223,  1232,  1241,  1251,  1261,  1272,
    1283,  1294,  1305,  1313,  1322,  1332,  1343,  1354,  1366,  1369,
    1377,  1381,  1385,  1389,  1394,  1398,  1402,  1406,  1411,  1417,
    1423,  1430,  1437,  1444,  1450,  1462,  1485,  1486,  1494,  1503,
    1504,  1510,  1519,  1528,  1538,  1548,  1558,  1571,  1581,  1600,
    1604,  1611,  1620,  1621,  1627,  1631,  1637,  1641,  1642,  1650,
    1651,  1659,  1660,  1666,  1667,  1672,  1677,  1682,  1687,  1692,
    1697,  1705,  1706,  1711,  1719,  1720,  1725,  1733,  1734,  1742,
    1743,  1751,  1752,  1759,  1760,  1761,  1762,  1763,  1764,  1765,
    1766,  1767,  1768,  1769,  1770,  1771,  1772,  1773,  1774,  1778,
    1782,  1783,  1784,  1785,  1786,  1787,  1788,  1789,  1790,  1791,
    1792,  1793,  1794,  1795,  1796,  1799,  1802,  1806,  1810,  1813,
    1816,  1819,  1822,  1825,  1828,  1831,  1834,  1837,  1840,  1843,
    1846,  1850,  1853,  1856,  1859,  1862,  1865,  1868,  1871,  1874,
    1880,  1886,  1892,  1898,  1904,  1910,  1913,  1916,  1919,  1922,
    1926,  1930,  1933,  1936,  1939,  1942,  1945,  1948,  1952,  1955,
    1959,  1962,  1966,  1973,  1980,  1987,  1992,  1997,  2002,  2006,
    2010,  2013,  2016,  2019,  2022,  2025,  2028,  2031,  2034,  2037,
    2040,  2043,  2046,  2049,  2052,  2055,  2058,  2061,  2064,  2067,
    2070,  2073,  2076,  2079,  2082,  2085,  2088,  2091,  2096,  2101,
    2106,  2111,  2117,  2121,  2125,  2132,  2139,  2146,  2152,  2158,
    2164,  2167,  2170,  2173,  2176,  2179,  2182,  2185,  2191,  2194,
    2197,  2200,  2203,  2206,  2209,  2212,  2215,  2218,  2225,  2226,
    2230,  2234,  2242,  2246
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
  "BIF_UNS", "BIF_INTH", "BIF_DECH", "BIF_DECPOS", "BIF_CONCAT",
  "BIF_CONCATARR", "BIF_LEFT", "BIF_RIGHT", "BIF_STR", "BIF_MAXARR",
  "BIF_MINARR", "BIF_LIST", "BIF_RANGE", "BIF_LOOKUPLT", "BIF_LOOKUPGE",
  "BIF_LOOKUPLE", "BIF_LOOKUPGT", "BIF_TLOOKUP", "BIF_TLOOKUPLT",
  "BIF_TLOOKUPGT", "BIF_TLOOKUPLE", "BIF_TLOOKUPGE", "BIF_HOURS",
  "BIF_MINUTES", "BIF_SECONDS", "BIF_MSECONDS", "BIF_PADDR", "BIF_PROC",
  "BIF_PASSED", "BIF_OMITTED", "BIF_BITAND", "BIF_BITNOT", "BIF_BITOR",
  "BIF_BITXOR", "BIF_SCANR", "BIF_EDITFLT", "BIF_UNSH", "BIF_PARMNUM",
  "KW_ALL", "KW_UNS", "KW_FLOAT_TYPE", "KW_BINDEC", "KW_UCS2", "KW_GRAPH",
  "KW_OBJECT", "KW_JAVA", "KW_OVERLAY", "KW_POS", "KW_PREFIX", "KW_DATFMT",
  "KW_TIMFMT", "KW_EXTNAME", "KW_RTNPARM", "KW_OPDESC", "KW_ASCEND",
  "KW_DESCEND", "KW_NULLIND", "KW_VARSIZE", "KW_STRING_OPT", "KW_TRIM_OPT",
  "KW_DCL_ENUM", "KW_END_ENUM", "KW_BOOLEAN", "POWER", "KW_DIM_VAR",
  "KW_DIM_AUTO", "KW_FOR_EACH", "KW_IN", "IDENTIFIER", "INTEGER_LITERAL",
  "FLOAT_LITERAL", "STRING_LITERAL", "SEMICOLON", "EQUALS", "LPAREN",
  "RPAREN", "COLON", "PLUS", "MINUS", "STAR", "SLASH", "NE", "LE", "GE",
  "LT", "GT", "$accept", "program", "statements_opt", "statement_list",
  "statement", "dcl_f_stmt", "dcl_s_stmt", "dcl_s_keywords", "dcl_c_stmt",
  "eval_target", "eval_stmt", "eval_corr_stmt", "evalr_stmt", "callp_stmt",
  "leavesr_stmt", "dsply_stmt", "inlr_stmt", "return_stmt", "expr_stmt",
  "dcl_pr_stmt", "dcl_proc_stmt", "proc_export", "pi_return_type",
  "pi_params", "pi_param", "pr_params", "pr_param", "monitor_stmt",
  "begsr_stmt", "exsr_stmt", "sorta_stmt", "reset_stmt", "clear_stmt",
  "dealloc_stmt", "test_stmt", "dcl_enum_stmt", "enum_constants",
  "enum_constant", "dcl_ds_stmt", "ds_fields", "ds_field", "if_stmt",
  "elseif_clauses", "elseif_clause", "else_clause", "dow_stmt", "dou_stmt",
  "for_stmt", "for_each_stmt", "select_stmt", "when_clauses",
  "when_clause", "other_clause", "iter_stmt", "leave_stmt", "expression",
  "or_expr", "and_expr", "not_expr", "comparison_expr", "additive_expr",
  "multiplicative_expr", "power_expr", "unary_expr", "postfix_expr",
  "ident", "primary_expr", "call_args_opt", "call_arg_list", "arg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-830)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-264)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      74,  -830,    81,    28,   374,  -830,  -110,   -97,   316,   -89,
    4151,   -33,   316,   -33,  4151,   -68,   316,   -34,  -830,  3395,
     -11,  4151,  4151,  4151,   316,   -46,   -17,   -14,    15,    21,
     316,   316,   316,   316,  -830,    23,    45,    50,    55,  -830,
    -830,  -830,  -830,  -830,  -830,  -830,  -830,  -830,  -830,  -830,
    -830,  -830,  -830,    59,   316,    -8,  -830,  -830,  -830,  -830,
      29,  -830,  -830,  -830,  -830,  -830,  -830,  -830,  -830,  -830,
    -830,  -830,  -830,  -830,  -830,  -830,  -830,  -830,  -830,  -830,
    -830,  -830,  -830,  -830,  -830,  -830,  -830,  -830,  -830,  -830,
    -830,   282,  -830,  -830,  -830,  -830,  -830,  -830,  -830,  -830,
    -830,  -830,  -830,  -830,  -830,  -830,  -830,  -830,   123,  4151,
    -830,  -830,  -830,  -830,  -830,  -830,  -830,  -830,  -830,  4340,
      60,    77,    83,    94,   100,   103,   113,   115,   121,   131,
     137,   146,   157,   175,   177,   187,   189,   201,   204,   208,
     211,   216,   218,   227,   229,   234,   251,   254,   263,   269,
     272,   279,   305,   318,   338,   344,   359,   365,   367,   369,
     377,   391,   393,   407,   427,   434,   443,   450,   452,   457,
     459,   463,   486,   523,   541,   561,   582,   588,   590,   592,
     593,   594,   595,   596,   598,   599,   600,   602,   603,   604,
     605,   606,   607,   608,   609,   610,   612,   613,   614,   616,
     617,   621,   622,   623,   624,   243,  -830,  -830,  -830,  -830,
    -830,  -830,  -830,  -830,  -830,  -830,  -830,  -830,  -830,  -830,
     625,  -830,  -830,  -830,  4151,  4529,   628,   302,   444,  -830,
     304,    26,  -137,  -830,   638,   719,  -830,    16,   629,   630,
     632,   635,  -830,   636,   316,  -830,   637,   775,   639,   641,
     642,   643,   767,  -830,  -830,  -830,   645,   646,   653,   656,
     657,   817,   312,    47,  4151,   -48,   648,   662,  4151,  4151,
      -9,   659,   660,   661,   663,   664,   667,   668,  -115,  -109,
     671,   672,   673,   674,   675,   681,   683,   691,   692,   694,
     698,   703,   304,  4151,  4151,  4151,  4151,  4151,  4151,  4151,
    4151,  4151,  4151,  4151,  4151,   658,   701,  4151,  4151,  4151,
    4151,  4151,   702,   704,   705,  4151,  4151,  4151,  3584,  3773,
    3962,  4151,  4151,  4151,  4151,  4151,  4151,  4151,  4151,  4151,
    4151,  4151,  4151,  4151,  4151,  4151,  4151,  4151,  4151,  4151,
    4151,  4151,  4151,  4151,  4151,  4151,  4151,  4151,  4151,  4151,
    4151,  4151,  4151,  4151,  4151,  4151,  4151,  4151,  4151,  4151,
    4151,  4151,  4151,  4151,  4151,  4151,   666,   706,   316,   316,
    4151,  4151,  4151,  4151,  4151,  4151,  4151,   316,  -830,  4151,
     708,   719,  -830,  4151,  4151,  4340,  4340,  4340,  4340,  4340,
    4340,  4340,  4340,  4340,  4340,  4340,  4340,   716,  4151,  4151,
     316,  4151,  -830,  -830,   711,  -830,   715,  -830,  -830,  -830,
    4151,  4151,   125,  -830,  1395,  -830,  -830,  -830,  -830,  -830,
    -830,   717,   714,   718,   720,   721,   722,    -7,   -15,   723,
     724,   725,  -830,  -830,    73,   728,   733,  4151,  -830,   727,
     729,   730,   731,   735,  -830,  -830,  -830,   739,   741,   742,
     743,   744,   740,  -830,   745,  -830,  -830,  -830,  -830,   748,
     746,   749,   752,   753,   755,   762,  -830,  -830,   108,   148,
     153,   191,   205,   223,   237,   241,   256,   266,   276,   285,
    -830,  -830,   306,   315,   340,   356,   371,  -830,  -830,  -830,
     388,   398,   409,  -830,   411,  -830,   413,  -830,   415,   751,
     756,   758,   759,   418,   422,   424,   435,   437,   440,   460,
     754,   464,   467,   469,   471,   473,   475,   477,   479,   483,
     487,   489,   491,   493,   495,   497,   499,   501,   503,   505,
     507,   509,   512,   514,   516,   518,   520,   524,   526,   528,
     760,   761,   764,   765,   766,  -830,   768,   769,   530,   532,
     534,   536,   538,   542,   544,   770,  -830,   771,  -830,   444,
    -830,   192,   192,   192,   192,   192,   192,   192,  -137,  -137,
    -830,  -830,  -830,  -830,   727,   776,   777,   778,   316,  -830,
     597,  1605,  1672,   325,   779,   780,  -830,   816,   781,  -830,
    1882,   851,   757,   773,   785,   786,   787,   782,  -830,   783,
     788,  -830,   117,   791,   792,    52,  -830,  4151,   733,   449,
    -113,  -830,   789,   839,   793,  4151,  -830,   784,   772,   794,
     795,   790,   796,   799,   800,   798,   801,   802,   803,   804,
     807,   809,  -830,  -830,  -830,  -830,  -830,  -830,  -830,  -830,
    -830,  -830,  -830,  -830,  -830,  -830,  -830,  -830,  -830,  -830,
    -830,  -830,  -830,  -830,  -830,  4151,  -830,  -830,  -830,  -830,
    -830,  -830,  -830,  -830,  -830,  -830,   533,  -830,  -830,  -830,
    -830,  -830,  -830,  -830,  -830,  -830,  -830,  -830,  -830,  -830,
    -830,  -830,  -830,  -830,  -830,  -830,  -830,  -830,  -830,  -830,
    -830,  -830,  -830,  -830,  -830,  -830,  -830,  -830,  -830,  -830,
    -830,  -830,  -830,  -830,  -830,  -830,  -830,  -830,  -830,  -830,
    -830,  -830,  -830,  -830,  -830,   811,   451,   814,   826,  4151,
    4151,  -830,  -830,   828,  -830,   833,    24,   835,   836,   837,
     832,   838,   843,    54,   129,   806,    53,   840,   842,   844,
     845,   546,   849,   847,   515,  -830,  -830,    56,  -830,  4151,
     850,  -830,  -830,   855,  -830,  -830,   848,   303,   446,   400,
     856,   857,   852,   853,   863,   442,   442,   442,   442,   442,
     846,   862,   864,   865,   866,   867,   868,   869,  -830,  4151,
     873,  -830,   885,  -830,  -830,   -30,   -19,   841,  1949,  -830,
    2159,  -830,   550,   874,  -830,  -830,  -830,   878,   876,   877,
     879,   886,   240,  -830,   888,   889,   880,   548,   881,   893,
     898,   871,   -18,   903,   909,  -830,   577,   797,   906,   911,
     912,   915,   917,  -830,  2226,  -830,   914,   948,   916,  -830,
    -830,   920,   951,  -830,   931,   919,   932,  -830,   933,   936,
     960,   935,   937,   961,   938,   941,   939,   943,   947,   949,
    -830,   950,   952,   953,   954,   957,   945,   584,  -830,  -830,
    -830,  -830,  -830,  -830,   959,  -830,   962,  4151,  -830,  4151,
    -830,   964,   965,  -830,   958,  -830,   966,  -830,   601,   968,
     969,   971,   973,   978,   963,   984,   982,   985,   989,  -830,
     986,   988,   992,   991,  -830,  -830,   993,   995,   996,   997,
     998,  1004,  1005,  1006,  1007,  -830,  -830,   994,  1002,  1009,
    4151,   942,  1010,  1011,  -830,  4151,   139,  -830,  1012,  4151,
     999,  1013,   150,  -830,   433,   442,  -830,  -830,  -830,  -830,
    -830,  -830,  -830,  1016,  1003,  1014,  1017,  1018,  1020,  1021,
    -830,  2436,  -830,  1036,  2503,  1037,  2713,  -830,  -830,    -4,
    -830,    57,  -830,  1038,  1039,  1040,  1041,  1047,  1049,  1052,
    1053,  1042,  1045,  1048,  -830,  -830,  1050,   918,   929,  -830,
    1055,   162,  1114,  1057,  1058,  1059,  1060,  1056,  1061,  1062,
    1054,  -830,  1063,  4151,  1064,  1065,  4151,  1066,  1067,  1068,
    1069,  1071,  4151,  1072,  1073,  4151,  1074,  1075,  1077,  1202,
    1079,  1080,  1083,  1084,  -830,  -830,  -830,  -830,  -830,  -830,
    -830,  1051,  -830,  1087,  -830,  1088,    40,  1090,  1070,   294,
    -830,  1091,    58,  1106,  1108,  1113,  1116,  1112,  1115,  1117,
    1107,  1119,  1121,  1123,   164,   165,  1124,  1125,  1126,   166,
    1127,  1128,  1129,  1130,  1140,  1141,  1142,   -94,  1131,    84,
    1120,  -830,  1144,  1132,  1145,  1146,   -43,  1148,  1122,  1153,
    1151,  1149,  1156,  1157,  1150,  1161,  1162,   -16,  1158,  4151,
    1165,  -830,  -830,  2780,  -830,  2990,  -830,  1163,  -830,   611,
    1167,  1168,  1170,  1178,  1179,  -830,  1164,  1180,  1182,  1187,
    1188,   -40,   -38,   -26,  1194,  1195,  -830,  -830,  1196,  1198,
    -830,  -830,  -830,  1199,  1207,  -830,  -830,  1210,  1211,  1212,
    1216,  1213,  1214,  -830,  -830,  1215,  1217,  -830,  1220,  1218,
    -830,  -830,  1224,  1225,  1226,  -830,  -830,  1227,  1228,  -830,
    1229,  -830,  -830,  1234,  1233,  1235,  1237,  1239,  -830,  4151,
    1238,  1240,  1242,  1248,  -830,  1118,  1250,  1255,  1256,  1257,
    1230,  1253,  1264,  1265,  1081,  -830,   -47,   -44,   -42,  1266,
    1263,   -36,  -830,  1267,   -35,  -830,  1268,   -12,  -830,  1269,
    -830,   178,   190,  -830,  -830,   194,   196,   197,  -830,  -830,
     200,  -830,  -830,  -830,  1270,  1171,  1271,  1275,  1277,  -108,
    -830,  -830,  -830,  -830,  1276,  1278,  -830,  -830,  1279,  1280,
    -830,  -830,  1272,  1281,  1282,  -830,  -830,  1328,  1283,  1284,
    1288,  1289,  1291,  1292,  1274,  1287,  1290,  1262,  1294,  1298,
    -830,  1300,  -830,  1301,  -830,  1310,   734,  1312,  -830,   736,
    1313,  -830,   738,  1315,  -830,   -24,  1318,  1319,  1320,  1321,
    1323,  1325,  1326,   556,  1324,   558,  1327,  1329,  -830,  -830,
    -830,  -830,  -830,  1332,  -830,  -830,  1333,  1334,  -830,  -830,
    1335,  1336,  1337,  1331,   -23,   -22,   -20,  1295,  1341,  -830,
    -830,  -830,   -41,  1338,  1340,  1190,  1342,  1344,  1241,  1345,
    1347,  1243,  1343,    -3,  -830,  -830,  -830,  -830,  -830,  -830,
    -830,  -830,  1348,  1297,  1351,  1352,  1339,  1353,  1357,  -830,
    -830,  -830,  3057,   -31,   -27,   -25,  1358,  1354,    -2,  -830,
    1355,     1,  -830,  1356,    14,  -830,  1361,  -830,  1359,  -830,
    1193,  1360,  1362,  1251,  1367,  1365,  1296,  1380,  1379,  1307,
    1385,  -830,  -830,  1387,  -830,  -830,  1389,  -830,  1390,  3267,
    1388,  1394,  -830,  1396,  -830,  1397,  -830,  1392,   747,  1398,
    -830,   750,  1399,  -830,   763,  1400,  -830,   -13,  -830,  1401,
    -830,  1403,  1402,  -830,  1406,  1404,  -830,  1408,  1407,  1472,
    1409,  1417,  1420,  1421,  -830,  -830,  -830,  -830,   -21,  1418,
    1422,  1509,  1419,  1423,  1510,  1424,  1426,  1518,  1425,    25,
    -830,  1430,  -830,  1433,  -830,  1434,  -830,  1435,  1436,  -830,
    -830,  -830,  -830,  1437,  -830,  1524,  1440,  1438,  1541,  1446,
    1444,  1578,  1449,  1454,  1579,  1456,  -830,  -830,  -830,  -830,
    -830,  1460,  -830,  1459,  -830,  1467,  1465,  -830,  1469,  1468,
    -830,  1473,  1481,  1617,  -830,  1475,  -830,  1476,  -830,  1487,
    -830,  1488,  1486,  -830,  -830,  -830,  -830,  1490,  -830
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       4,     4,     0,     0,     0,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   110,     0,     0,     0,     0,    99,
     100,   101,    97,    96,    98,   107,   108,   109,   104,   105,
     102,   103,   106,     0,     0,    95,     5,     9,    10,    11,
       0,    12,    13,    35,    36,    37,    14,    15,    16,    40,
      26,    25,    29,    30,    31,    34,    32,    33,    38,    39,
      28,    27,    17,    18,    19,    20,    21,    22,    23,    24,
      41,     0,   294,   295,   296,   306,   307,   308,   303,   304,
     305,   300,   301,   297,   298,   302,   299,   293,     0,     0,
     431,   432,   429,   433,   434,   435,   436,   430,   428,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   413,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   310,   311,   312,   319,
     320,   321,   318,   322,   323,   315,   316,   313,   314,   317,
     309,   324,   325,   326,     0,     0,     0,   266,   267,   269,
     271,   273,   281,   284,   287,   289,   291,    95,     0,     0,
       0,     0,   120,     0,     0,   124,     0,     0,     0,     0,
       0,     0,     0,   264,   265,     7,     0,     0,     0,     0,
       0,   133,   135,     0,     0,     0,     0,     0,   438,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   272,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   417,   438,
       0,   290,   121,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   119,   206,     0,   123,     0,     7,     7,     7,
       0,     0,   262,   259,     0,     7,   202,   204,   205,   203,
     134,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   228,   442,     0,     0,     0,     0,   111,   440,
       0,   439,     0,     0,    42,    43,    44,     0,     0,     0,
       0,     0,     0,    62,     0,    63,    64,    60,    65,     0,
       0,     0,     0,     0,     0,     0,    61,    94,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     378,   379,     0,     0,     0,     0,     0,   340,   359,   360,
       0,     0,     0,   367,     0,   369,     0,   371,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   412,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   440,     0,   437,   268,
     270,   274,   275,   278,   279,   276,   277,   280,   282,   283,
     285,   286,   288,   292,     0,     0,     0,     0,     0,   122,
       0,     0,     0,     0,     0,     0,   260,     0,     0,     8,
       0,     0,     0,     0,     0,     0,     0,     0,   170,     0,
       0,   228,     0,     0,     0,     0,   114,     0,     0,     0,
       0,   210,     0,   112,     0,     0,   115,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   328,   329,   330,   331,   332,   333,   334,   335,
     336,   337,   338,   339,   363,   364,   365,   361,   362,   357,
     358,   341,   366,   368,   370,     0,   375,   376,   377,   342,
     343,   344,   345,   346,   347,   348,     0,   355,   356,   380,
     381,   382,   393,   387,   383,   384,   385,   386,   388,   389,
     390,   391,   392,   394,   395,   396,   397,   398,   399,   400,
     401,   402,   403,   404,   405,   406,   407,   408,   409,   410,
     411,   418,   419,   420,   421,   422,   423,   424,   425,   426,
     427,   327,   116,   117,   118,     0,   249,     0,     0,     0,
       0,     7,     7,     0,     7,     0,   135,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   229,   443,     0,   212,     0,
       0,   211,     7,     0,   125,   441,     0,    89,    89,    89,
       0,     0,     0,     0,     0,    89,    89,    89,    89,    89,
       0,     0,     0,     0,     0,     0,     0,     0,   207,     0,
       0,   247,     0,   251,   252,     0,     0,     0,     0,   258,
       0,   201,   135,     0,   137,   138,   136,     0,     0,     0,
       0,     0,     0,   171,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   215,     0,     0,     0,     0,
       0,     0,     0,   209,     0,   113,     0,     0,     0,    90,
      91,     0,    92,    93,     0,     0,     0,    92,     0,     0,
       0,     0,     0,    92,     0,     0,     0,     0,     0,     0,
      74,     0,     0,     0,     0,     0,     0,     0,   351,   350,
     349,   352,   353,   354,     0,     7,     0,     0,     7,     0,
       7,     0,     0,   140,     0,   170,     0,   126,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   214,
       0,     0,     0,     0,   222,   228,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   208,   213,     0,     0,     0,
       0,     0,     0,     0,    46,     0,     0,    47,     0,     0,
       0,     0,     0,    48,    89,    89,    87,    88,    75,    76,
      77,    78,    79,     0,     0,     0,     0,     0,     0,     0,
       7,     0,   245,     0,     0,     0,     0,   200,   140,     0,
     139,     0,   170,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   228,   228,     0,     0,     0,   228,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   257,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    80,   372,   373,   374,   414,   415,
     416,     0,     7,     0,     7,     0,     0,     0,     0,     0,
     141,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    45,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    49,    50,     0,   253,     0,   255,     0,     7,     0,
       0,     0,     0,     0,     0,   128,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   228,   228,     0,     0,
     228,   228,   228,     0,     0,   227,   228,     0,     0,     0,
       0,     0,     0,   231,   232,     0,     0,   230,     0,     0,
      55,    82,     0,     0,     0,    67,    57,     0,     0,    68,
       0,    54,    81,     0,     0,     0,     0,     0,    66,     0,
       0,     0,     0,     0,     7,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   127,     0,     0,     0,     0,
       0,     0,   174,     0,     0,   176,     0,     0,   172,     0,
     188,     0,     0,   217,   224,     0,     0,     0,   216,   223,
       0,   235,   236,   234,     0,     0,     0,     0,     0,     0,
      52,    59,    85,    86,     0,     0,    51,    58,     0,     0,
      83,    84,     0,     0,     0,   254,   256,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     182,     0,   184,     0,   180,     0,     0,     0,   175,     0,
       0,   177,     0,     0,   173,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   233,    72,
      73,    70,    71,     0,    56,    69,     0,     0,     7,   129,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   183,
     185,   181,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   178,   219,   221,   226,   218,   220,
     225,   237,     0,     0,     0,     0,     0,     0,     0,    53,
       7,   130,     0,     0,     0,     0,     0,     0,     0,   144,
       0,     0,   146,     0,     0,   142,     0,   158,     0,   186,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   179,   241,     0,   238,   243,     0,   239,     0,     0,
       0,     0,   152,     0,   154,     0,   150,     0,     0,     0,
     145,     0,     0,   147,     0,     0,   143,     0,   187,     0,
     194,     0,     0,   195,     0,     0,   193,     0,     0,     0,
       0,     0,     0,     0,   131,   153,   155,   151,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     148,     0,   190,     0,   191,     0,   189,     0,     0,   242,
     244,   240,   132,     0,   156,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   149,   198,   199,   197,
     196,     0,   157,     0,   164,     0,     0,   165,     0,     0,
     163,     0,     0,     0,   192,     0,   160,     0,   161,     0,
     159,     0,     0,   168,   169,   167,   166,     0,   162
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -830,  -830,  1285,  -393,   808,  -830,  -830,  -639,  -830,    34,
    -830,  -830,  -830,  -830,  -830,  -830,  -830,  -830,  -830,  -830,
    -830,  -830,  -638,   812,  -830,  -829,  -830,  -830,  -830,  -830,
    -830,  -830,  -830,  -830,  -830,  -830,   831,  -567,  -830,  -599,
    -830,  -830,  -830,  -830,  -830,  -830,  -830,  -830,  -830,  -830,
    -830,  1304,  -830,  -830,  -830,   -10,  -830,  1314,  1349,  1530,
     163,   421,     2,  -830,  1492,    -6,  -830,  1346,  -830,  4464
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,   414,   589,    57,    58,   835,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,   421,   427,   949,  1020,   733,   803,    72,    73,    74,
      75,    76,    77,    78,    79,    80,   610,   611,    81,   605,
     745,    82,   716,   781,   782,    83,    84,    85,    86,    87,
     412,   413,   587,    88,    89,   433,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   108,   236,   440,   441,   434
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     226,   443,   736,  1160,   241,  1163,   239,  1227,  1230,   246,
     243,   248,   249,   250,   580,   581,   582,  1166,   251,  1282,
    1307,  1310,   590,  1313,   257,   258,   259,   260,    -3,     6,
    1388,  1233,     7,     8,     9,   422,   423,   424,   425,   867,
    1330,  1349,   597,   751,  1352,   238,   951,   240,   266,  1219,
     869,   435,  1221,    34,  1223,  1318,  1161,  1355,  1164,    10,
      11,    12,    13,    14,    15,  1341,    16,    17,  1415,  1343,
    1167,  1345,  1283,  1308,  1311,  1403,  1314,     1,    18,    19,
      20,     5,   893,  1389,    38,   599,    21,   452,   793,  1017,
      22,    23,  1247,    24,   454,   394,   395,   267,    25,   291,
    1018,   750,    26,    27,    28,  1111,  1112,    29,   609,    30,
     453,    31,    32,    33,    34,    90,   455,  1248,    35,   839,
     845,   267,    36,  1022,    91,    37,   851,   852,   853,   854,
     855,  1113,   109,  1077,   273,   274,   275,   276,   277,   278,
     279,   280,   281,   282,  1018,    38,   428,   429,   430,   800,
     742,   808,  1021,  1086,   872,   743,   743,   242,   801,    39,
      40,   801,   801,    41,  1123,  1124,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,   436,  1220,   252,
     751,  1222,  1125,  1224,  1319,  1162,   600,  1165,   237,  1228,
    1231,  1136,  1137,   244,  1342,   868,   411,   585,  1344,  1168,
    1346,  1284,  1309,  1312,  1404,  1315,   870,   894,   253,  1138,
     601,   254,  1390,  1234,   380,   247,   444,  1019,   598,   268,
      39,    40,  1331,  1350,    41,   283,  1353,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,   404,  1356,
     255,    53,   256,   398,   261,   792,   391,    54,   431,    55,
    1416,   879,   880,   881,   882,   269,   392,   393,   439,   442,
    1041,  1019,  1098,  1099,  1103,   743,   262,   743,   743,   743,
     821,   263,   432,   744,   744,   802,  1236,   609,   802,   802,
     265,   743,   264,  1115,  1116,  1002,  1003,   293,  1237,   270,
     271,   272,  1238,   743,  1239,  1240,   971,   743,  1241,   743,
     743,   606,   607,   743,   294,  1080,  1081,  1082,  1083,  1117,
     295,   499,   500,   501,   502,   284,   285,   286,   287,   288,
     289,   296,   510,   422,   423,   424,   425,   297,   787,   788,
     298,   790,   827,   828,   737,   738,   632,   607,   290,   739,
     299,   883,   300,   829,   830,   831,   804,   805,   301,   832,
     833,   806,   540,   541,   542,   543,   989,   990,   302,   824,
     426,   991,   546,   547,   303,  1034,  1035,   996,   997,   556,
    1039,   555,   998,   304,    -2,     6,   633,   607,     7,     8,
       9,   634,   607,   744,   305,   744,   744,   744,   574,   575,
     383,   577,   719,   720,   576,  1084,   570,   571,   572,   744,
     583,   584,   306,   834,   307,    10,    11,    12,    13,    14,
      15,   744,    16,    17,   308,   744,   309,   744,   744,   635,
     607,   744,   392,   393,    18,    19,    20,   612,   310,   840,
     841,   311,    21,   636,   607,   312,    22,    23,   313,    24,
     829,   830,   842,   314,    25,   315,   843,   833,    26,    27,
      28,   637,   607,    29,   316,    30,   317,    31,    32,    33,
      34,   318,   999,  1000,    35,   638,   607,   378,    36,   639,
     607,    37,   941,   829,   830,   944,   836,   946,   319,   837,
     833,   320,   829,   830,   640,   607,   829,   830,   837,   833,
     321,    38,   837,   833,   641,   607,   322,  1171,  1172,   323,
     844,  1175,  1176,  1177,   642,   607,   324,  1180,    92,    93,
     779,   780,    94,   643,   607,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   817,   818,   819,   820,
     385,   384,   325,  1001,   644,   607,   106,   107,   386,   387,
     388,   389,   390,   645,   607,   326,   838,  1011,   561,   562,
     563,   564,   565,   566,   567,   772,   773,   774,   775,   776,
     777,   422,   423,   424,   425,   327,    39,    40,   646,   607,
      41,   328,   715,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,   647,   607,   329,    53,   897,   898,
     899,   900,   330,    54,   331,    55,   332,   746,     6,   648,
     607,     7,     8,     9,   333,   755,   934,   935,   936,   937,
     938,   939,   953,   954,   955,   956,   649,   607,   334,  1073,
     335,  1075,  1146,  1147,  1148,  1149,   650,   607,    10,    11,
      12,    13,    14,    15,   336,    16,    17,   651,   607,   652,
     607,   653,   607,   654,   607,   771,   659,   607,    19,    20,
     660,   607,   661,   607,   337,    21,  -246,  -246,  -246,    22,
      23,   338,    24,   662,   607,   663,   607,    25,   664,   607,
     339,    26,    27,    28,   748,   749,    29,   340,    30,   341,
      31,    32,    33,    34,   342,  1145,   343,    35,   665,   607,
     344,    36,   667,   607,    37,   668,   607,   669,   607,   670,
     607,   671,   607,   672,   607,   673,   607,   674,   607,   785,
     786,   675,   607,   345,    38,   676,   607,   677,   607,   678,
     607,   679,   607,   680,   607,   681,   607,   682,   607,   683,
     607,   684,   607,   685,   607,   686,   607,   687,   607,   822,
     688,   607,   689,   607,   690,   607,   691,   607,   692,   607,
     346,  1207,   693,   607,   694,   607,   695,   607,   703,   607,
     704,   607,   705,   607,   706,   607,   707,   607,   347,   864,
     708,   607,   709,   607,   813,   814,   887,   888,  1273,  1274,
    1276,  1277,  1279,  1280,  1292,  1293,  1295,  1296,   348,    39,
      40,  1379,  1380,    41,  1382,  1383,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,  1385,  1386,   349,
      53,    56,    56,   568,   569,   350,    54,   351,    55,   352,
     353,   354,   355,   356,   397,   357,   358,   359,   406,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   411,   369,
     370,   371,     6,   372,   373,     7,     8,     9,   374,   375,
     376,   377,   379,   382,   396,   399,   400,   943,   401,   945,
     402,   403,   405,   420,   407,  1302,   408,   409,   437,   410,
     415,   416,    10,    11,    12,    13,    14,    15,   417,    16,
      17,   418,   419,   438,   445,   446,   480,   544,   447,   723,
     448,   449,    19,    20,   450,   451,   456,   457,   458,    21,
     984,   459,   460,    22,    23,   988,    24,  1339,   461,   993,
     462,    25,  -261,  -261,  -261,    26,    27,    28,   463,   464,
      29,   465,    30,   466,    31,    32,    33,    34,   467,   481,
     487,    35,   488,   489,   545,    36,   558,   573,    37,   578,
     579,   592,   591,   726,   753,   593,   866,   594,   595,   596,
     602,   603,   604,   608,   609,   613,   616,   614,    38,   615,
     631,   618,   617,   619,   620,   621,   622,   623,   626,   625,
     892,   627,   624,  1052,   628,   629,  1055,   630,   909,   727,
     655,   912,  1061,   666,   656,  1064,   657,   658,   696,   697,
     918,   921,   698,   699,   700,   728,   701,   702,   710,   711,
     757,   712,   713,   714,   721,   722,   724,   729,   730,   732,
     734,   731,   740,   741,   752,   735,   756,  1037,   754,   760,
     762,   763,   758,   759,   901,   761,   764,   807,  1038,   765,
     766,   767,   768,    39,    40,   769,   778,    41,   770,   783,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,   784,     6,   789,    53,     7,     8,     9,   791,  1140,
      54,   797,    55,   794,   795,   796,   798,   799,   816,   809,
     856,   810,   811,   812,   815,   823,   825,   826,   846,   847,
     848,   849,    10,    11,    12,    13,    14,    15,   850,    16,
      17,   857,   858,   859,   860,   861,   862,   863,   865,   873,
     874,   875,    19,    20,   877,   876,   889,   878,   886,    21,
    -248,  -248,  -248,    22,    23,   890,    24,   884,   885,     6,
     891,    25,     7,     8,     9,    26,    27,    28,   895,  1202,
      29,   896,    30,   902,    31,    32,    33,    34,   903,   904,
     905,    35,   906,   910,   914,    36,   908,   911,    37,    10,
      11,    12,    13,    14,    15,  1208,    16,    17,   913,   915,
     916,   917,   919,   985,   920,   922,   923,   924,    38,    19,
      20,   925,   926,   933,   927,   928,    21,   929,   930,   931,
      22,    23,   932,    24,   940,   962,   950,   942,    25,   947,
     948,   952,    26,    27,    28,   957,   958,    29,   959,    30,
     960,    31,    32,    33,    34,   961,   963,   964,    35,  1209,
     965,   966,    36,  1042,   967,    37,   968,   969,   970,   981,
     994,   972,   973,   974,   975,   976,   977,   978,   979,   980,
     982,  1005,  1068,   987,  1322,    38,   983,   986,  1359,   992,
     995,  1004,  1006,    39,    40,  1007,  1008,    41,  1009,  1010,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,  1012,  1014,  1031,    53,  1023,  1024,  1025,  1026,  1027,
      54,  1028,    55,  1032,  1029,  1030,  1033,  1040,  1036,  1043,
    1044,  1045,  1046,  1050,  1047,  1325,     4,  1328,  1051,  1048,
    1049,  1079,  1053,  1054,  1056,  1057,  1362,  1058,  1059,  1060,
    1062,  1063,  1218,  1065,  1066,  1067,  1069,  1070,  1071,  1072,
      39,    40,  1074,  1076,    41,  1078,  1085,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,  1087,     6,
    1088,    53,     7,     8,     9,  1089,  1094,    54,  1090,    55,
    1091,  1365,  1118,  1092,  1127,  1093,  1096,  1095,  1097,  1100,
    1101,  1102,  1368,  1105,  1106,  1104,  1114,  1120,  1107,    10,
      11,    12,    13,    14,    15,  1256,    16,    17,  1108,  1109,
    1121,  1110,  1119,  1126,  1122,  1128,  1129,  1130,  1133,    19,
      20,  1131,  1132,  1134,  1135,  1139,    21,  1141,  1144,  1155,
      22,    23,  1243,    24,  1150,  1151,     6,  1152,    25,     7,
       8,     9,    26,    27,    28,  1153,  1154,    29,  1156,    30,
    1157,    31,    32,    33,    34,  1158,  1169,  1159,    35,  1257,
    1170,  1173,    36,  1174,  1178,    37,    10,    11,    12,    13,
      14,    15,  1179,    16,    17,  1181,  1182,  1183,  1184,   747,
    1185,  1186,  1187,  1190,  1188,    38,    19,    20,  1189,  1191,
    1192,  1193,  1214,    21,  1196,  1194,  1195,    22,    23,  1197,
      24,  1198,  1200,  1199,  1201,    25,  1203,  1205,  1204,    26,
      27,    28,   588,  1206,    29,  1215,    30,  1210,    31,    32,
      33,    34,  1211,  1212,  1213,    35,  1216,  1217,  1225,    36,
    1226,  1267,    37,  1244,  1229,  1232,  1245,  1235,  1242,  1246,
    1253,  1249,  1264,  1250,  1251,  1252,  1254,  1255,  1258,  1259,
    1260,  1261,    38,  1262,  1263,  1265,  1398,  1316,  1266,  1333,
      39,    40,  1268,  1269,    41,  1270,  1271,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,  1272,  1275,
    1278,    53,  1281,  1285,  1286,  1287,  1288,    54,  1289,    55,
    1290,  1291,  1294,  1407,  1410,  1297,  1298,  1299,  1300,  1301,
    1306,  1336,  1413,  1303,  1304,  1305,  1317,  1320,  1321,  1423,
    1329,  1323,  1324,  1332,  1326,  1327,  1334,  1335,  1337,  1338,
    1347,  1348,  1351,  1354,  1358,  1360,  1426,    39,    40,  1357,
    1361,    41,  1363,  1364,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,  1366,     6,  1367,    53,     7,
       8,     9,  1369,  1374,    54,  1370,    55,  1371,  1372,  1375,
    1378,  1376,  1377,  1429,  1432,  1381,  1384,  1387,  1392,  1391,
    1393,  1394,  1395,  1396,  1399,  1397,    10,    11,    12,    13,
      14,    15,  1400,    16,    17,  1401,  1402,  1405,  1408,   292,
    1406,  1409,  1414,  1411,  1412,  1417,    19,    20,  1418,  1419,
    1420,  1442,  1422,    21,  1421,  1424,  1425,    22,    23,   717,
      24,  1427,  1428,     6,  1430,    25,     7,     8,     9,    26,
      27,    28,  1431,  1433,    29,  1434,    30,  1435,    31,    32,
      33,    34,  1436,  1437,  1438,    35,  1439,   559,  1440,    36,
    1443,  1444,    37,    10,    11,    12,    13,    14,    15,  1441,
      16,    17,  1445,  1446,  1447,  1448,   586,   381,     0,     0,
       0,     0,    38,    19,    20,   557,     0,     0,     0,     0,
      21,     0,     0,   560,    22,    23,   718,    24,     0,     0,
       0,     0,    25,     0,     0,     0,    26,    27,    28,     0,
       0,    29,     0,    30,     0,    31,    32,    33,    34,     0,
    1016,     0,    35,     0,     0,     0,    36,     0,     0,    37,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
       0,     0,     0,     0,     0,     0,     0,    39,    40,     0,
       0,    41,     0,     0,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,     0,     0,     0,    53,     0,
       0,     0,     0,     0,    54,     0,    55,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    39,    40,     0,     0,    41,     0,
       0,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,     0,     6,     0,    53,     7,     8,     9,     0,
       0,    54,     0,    55,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,    12,    13,    14,    15,     0,
      16,    17,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    19,    20,     0,     0,     0,     0,     0,
      21,     0,     0,     0,    22,    23,     0,    24,     0,     0,
       6,     0,    25,     7,     8,     9,    26,    27,    28,     0,
       0,    29,   725,    30,     0,    31,    32,    33,    34,     0,
       0,     0,    35,     0,     0,     0,    36,     0,     0,    37,
      10,    11,    12,    13,    14,    15,     0,    16,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
      19,    20,     0,     0,     0,     0,     0,    21,     0,     0,
       0,    22,    23,     0,    24,     0,     0,     0,     0,    25,
       0,     0,  -263,    26,    27,    28,     0,     0,    29,     0,
      30,     0,    31,    32,    33,    34,     0,     0,     0,    35,
       0,     0,     0,    36,     0,     0,    37,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,     0,     0,     0,
       0,     0,     0,     0,    39,    40,     0,     0,    41,     0,
       0,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,     0,     0,     0,    53,     0,     0,     0,     0,
       0,    54,     0,    55,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    39,    40,     0,     0,    41,     0,     0,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,     0,
       6,     0,    53,     7,     8,     9,     0,     0,    54,     0,
      55,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,    12,    13,    14,    15,     0,    16,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      19,    20,     0,     0,     0,     0,     0,    21,     0,     0,
       0,    22,    23,     0,    24,     0,     0,     6,     0,    25,
       7,     8,     9,    26,    27,    28,     0,   871,    29,     0,
      30,     0,    31,    32,    33,    34,     0,     0,     0,    35,
       0,     0,     0,    36,     0,     0,    37,    10,    11,    12,
      13,    14,    15,     0,    16,    17,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,    19,    20,     0,
       0,     0,     0,     0,    21,     0,     0,     0,    22,    23,
       0,    24,   907,     0,     0,     0,    25,     0,     0,     0,
      26,    27,    28,     0,     0,    29,     0,    30,     0,    31,
      32,    33,    34,     0,     0,     0,    35,     0,     0,     0,
      36,     0,     0,    37,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,     0,     0,     0,     0,     0,     0,
       0,    39,    40,     0,     0,    41,     0,     0,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,     0,
       0,     0,    53,     0,     0,     0,     0,     0,    54,     0,
      55,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    39,    40,
       0,     0,    41,     0,     0,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,     0,     6,     0,    53,
       7,     8,     9,     0,     0,    54,     0,    55,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,    12,
      13,    14,    15,     0,    16,    17,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    19,    20,     0,
       0,     0,     0,     0,    21,     0,     0,  -250,    22,    23,
       0,    24,     0,     0,     6,     0,    25,     7,     8,     9,
      26,    27,    28,     0,     0,    29,     0,    30,     0,    31,
      32,    33,    34,     0,     0,     0,    35,     0,     0,     0,
      36,     0,     0,    37,    10,    11,    12,    13,    14,    15,
       0,    16,    17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,    19,    20,     0,     0,     0,     0,
       0,    21,     0,     0,     0,    22,    23,     0,    24,  1013,
       0,     0,     0,    25,     0,     0,     0,    26,    27,    28,
       0,     0,    29,     0,    30,     0,    31,    32,    33,    34,
       0,     0,     0,    35,     0,     0,     0,    36,     0,     0,
      37,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,     0,     0,     0,     0,     0,     0,     0,    39,    40,
       0,     0,    41,     0,     0,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,     0,     0,     0,    53,
       0,     0,     0,     0,     0,    54,     0,    55,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    39,    40,     0,     0,    41,
       0,     0,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,     0,     6,     0,    53,     7,     8,     9,
       0,     0,    54,     0,    55,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,    11,    12,    13,    14,    15,
       0,    16,    17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    19,    20,     0,     0,     0,     0,
       0,    21,     0,     0,     0,    22,    23,     0,    24,  1015,
       0,     6,     0,    25,     7,     8,     9,    26,    27,    28,
       0,     0,    29,     0,    30,     0,    31,    32,    33,    34,
       0,     0,     0,    35,     0,     0,     0,    36,     0,     0,
      37,    10,    11,    12,    13,    14,    15,     0,    16,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,    19,    20,     0,     0,     0,     0,     0,    21,     0,
       0,     0,    22,    23,     0,    24,  1142,     0,     0,     0,
      25,     0,     0,     0,    26,    27,    28,     0,     0,    29,
       0,    30,     0,    31,    32,    33,    34,     0,     0,     0,
      35,     0,     0,     0,    36,     0,     0,    37,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,     0,     0,
       0,     0,     0,     0,     0,    39,    40,     0,     0,    41,
       0,     0,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,     0,     0,     0,    53,     0,     0,     0,
       0,     0,    54,     0,    55,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    39,    40,     0,     0,    41,     0,     0,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
       0,     6,     0,    53,     7,     8,     9,     0,     0,    54,
       0,    55,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,    12,    13,    14,    15,     0,    16,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    19,    20,     0,     0,     0,     0,     0,    21,     0,
       0,     0,    22,    23,     0,    24,  1143,     0,     6,     0,
      25,     7,     8,     9,    26,    27,    28,     0,     0,    29,
       0,    30,     0,    31,    32,    33,    34,     0,     0,     0,
      35,     0,     0,     0,    36,     0,     0,    37,    10,    11,
      12,    13,    14,    15,     0,    16,    17,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,    19,    20,
       0,     0,     0,     0,     0,    21,     0,     0,     0,    22,
      23,     0,    24,     0,     0,     0,     0,    25,     0,     0,
       0,    26,    27,    28,     0,     0,    29,     0,    30,     0,
      31,    32,    33,    34,     0,     0,     0,    35,  1340,     0,
       0,    36,     0,     0,    37,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,     0,     0,     0,     0,     0,
       0,     0,    39,    40,     0,     0,    41,     0,     0,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
       0,     0,     0,    53,     0,     0,     0,     0,     0,    54,
       0,    55,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    39,
      40,     0,     0,    41,     0,     0,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,     0,     6,     0,
      53,     7,     8,     9,     0,     0,    54,     0,    55,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    10,    11,
      12,    13,    14,    15,     0,    16,    17,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    19,    20,
       0,     0,     0,     0,     0,    21,     0,     0,     0,    22,
      23,     0,    24,     0,     0,     0,     0,    25,     0,     0,
       0,    26,    27,    28,     0,     0,    29,     0,    30,     0,
      31,    32,    33,    34,     0,     0,     0,    35,  1373,     0,
       0,    36,     0,     0,    37,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   110,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     111,     0,     0,     0,     0,     0,     0,     0,   112,   113,
     114,   115,   116,     0,     0,     0,     0,     0,     0,    39,
      40,     0,     0,    41,     0,     0,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,   117,     0,     0,
      53,   118,     0,     0,   119,     0,    54,     0,    55,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,     0,
       0,   208,     0,     0,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   110,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   220,   221,   222,   223,
     245,     0,   224,     0,     0,     0,   225,     0,     0,   111,
       0,     0,     0,     0,     0,     0,     0,   112,   113,   114,
     115,   116,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   117,     0,     0,     0,
     118,     0,     0,   119,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,     0,     0,
     208,     0,     0,   209,   210,   211,   212,   213,   214,   215,
     216,   217,   218,   219,   110,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   220,   221,   222,   223,     0,
       0,   224,   493,     0,     0,   225,     0,     0,   111,     0,
       0,     0,     0,     0,     0,     0,   112,   113,   114,   115,
     116,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   117,     0,     0,     0,   118,
       0,     0,   119,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,     0,     0,   208,
       0,     0,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   110,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   220,   221,   222,   223,     0,     0,
     224,   495,     0,     0,   225,     0,     0,   111,     0,     0,
       0,     0,     0,     0,     0,   112,   113,   114,   115,   116,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   117,     0,     0,     0,   118,     0,
       0,   119,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,     0,     0,   208,     0,
       0,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   110,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   220,   221,   222,   223,     0,     0,   224,
     497,     0,     0,   225,     0,     0,   111,     0,     0,     0,
       0,     0,     0,     0,   112,   113,   114,   115,   116,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   117,     0,     0,     0,   118,     0,     0,
     119,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,     0,     0,   208,     0,     0,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   110,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   220,   221,   222,   223,     0,     0,   224,     0,
       0,     0,   225,     0,     0,   111,     0,     0,     0,     0,
       0,     0,     0,   112,   113,   114,   115,   116,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   117,     0,     0,     0,   118,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,     0,     0,   208,     0,     0,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,   219,
     110,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   220,   221,   222,   223,     0,     0,   224,     0,     0,
       0,   225,     0,     0,   111,     0,     0,     0,     0,     0,
       0,     0,   112,   113,   114,   115,   116,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   117,     0,     0,     0,   118,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
     195,   196,   197,   198,   199,   200,   201,   202,   203,   204,
     205,   206,   207,     0,     0,   208,     0,     0,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     220,   221,   222,   223,     0,     0,   224,   468,   469,   470,
     471,   472,   473,   474,   475,   476,   477,   478,   479,     0,
       0,   482,   483,   484,   485,   486,     0,     0,     0,   490,
     491,   492,   494,   496,   498,     0,     0,     0,     0,   503,
     504,   505,   506,   507,   508,   509,     0,   511,   512,   513,
     514,   515,   516,   517,   518,   519,   520,   521,   522,   523,
     524,   525,   526,   527,   528,   529,   530,   531,   532,   533,
     534,   535,   536,   537,   538,   539,     0,     0,     0,     0,
       0,     0,     0,     0,   548,   549,   550,   551,   552,   553,
     554
};

static const yytype_int16 yycheck[] =
{
      10,    10,   601,    43,    14,    43,    12,    43,    43,    19,
      16,    21,    22,    23,   407,   408,   409,    43,    24,    43,
      43,    43,   415,    43,    30,    31,    32,    33,     0,     1,
      43,    43,     4,     5,     6,    11,    12,    13,    14,    69,
      43,    43,    49,   610,    43,    11,   875,    13,    54,    96,
      69,    99,    96,    86,    96,    96,    96,    43,    96,    31,
      32,    33,    34,    35,    36,    96,    38,    39,    43,    96,
      96,    96,    96,    96,    96,    96,    96,     3,    50,    51,
      52,     0,   100,    96,   117,   100,    58,   202,   726,    93,
      62,    63,   200,    65,   203,   232,   233,   105,    70,   109,
     104,   214,    74,    75,    76,   199,   200,    79,   221,    81,
     225,    83,    84,    85,    86,   225,   225,   225,    90,   758,
     759,   105,    94,   952,   221,    97,   765,   766,   767,   768,
     769,   225,   221,    93,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,   104,   117,    99,   100,   101,    95,
      98,    98,    95,    95,   792,   103,   103,   225,   104,   192,
     193,   104,   104,   196,   207,   208,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   225,   225,   225,
     747,   225,   225,   225,   225,   225,   201,   225,   221,   225,
     225,   207,   208,   227,   225,   225,    71,    72,   225,   225,
     225,   225,   225,   225,   225,   225,   225,   225,   225,   225,
     225,   225,   225,   225,   224,   226,   225,   221,   225,   227,
     192,   193,   225,   225,   196,   102,   225,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   244,   225,
     225,   213,   221,   227,   221,   221,   220,   219,   201,   221,
     225,    11,    12,    13,    14,   226,   230,   231,   268,   269,
      98,   221,    98,    98,    98,   103,   221,   103,   103,   103,
     214,   221,   225,   221,   221,   221,    98,   221,   221,   221,
     221,   103,   227,   199,   200,   924,   925,   227,    98,     7,
       8,     9,    98,   103,    98,    98,   895,   103,    98,   103,
     103,   228,   229,   103,   227,    11,    12,    13,    14,   225,
     227,   321,   322,   323,   324,   192,   193,   194,   195,   196,
     197,   227,   332,    11,    12,    13,    14,   227,   721,   722,
     227,   724,    29,    30,   217,   218,   228,   229,   215,   222,
     227,   101,   227,    40,    41,    42,   217,   218,   227,    46,
      47,   222,   362,   363,   364,   365,   217,   218,   227,   752,
      48,   222,   368,   369,   227,   964,   965,   217,   218,   379,
     969,   377,   222,   227,     0,     1,   228,   229,     4,     5,
       6,   228,   229,   221,   227,   221,   221,   221,   398,   399,
      88,   401,    67,    68,   400,   101,   394,   395,   396,   221,
     410,   411,   227,   100,   227,    31,    32,    33,    34,    35,
      36,   221,    38,    39,   227,   221,   227,   221,   221,   228,
     229,   221,   230,   231,    50,    51,    52,   437,   227,    29,
      30,   227,    58,   228,   229,   227,    62,    63,   227,    65,
      40,    41,    42,   227,    70,   227,    46,    47,    74,    75,
      76,   228,   229,    79,   227,    81,   227,    83,    84,    85,
      86,   227,    29,    30,    90,   228,   229,   224,    94,   228,
     229,    97,   865,    40,    41,   868,    30,   870,   227,    46,
      47,   227,    40,    41,   228,   229,    40,    41,    46,    47,
     227,   117,    46,    47,   228,   229,   227,  1096,  1097,   227,
     100,  1100,  1101,  1102,   228,   229,   227,  1106,   192,   193,
      59,    60,   196,   228,   229,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,    11,    12,    13,    14,
     226,    87,   227,   100,   228,   229,   220,   221,   234,   235,
     236,   237,   238,   228,   229,   227,   100,   940,   385,   386,
     387,   388,   389,   390,   391,    22,    23,    24,    25,    26,
      27,    11,    12,    13,    14,   227,   192,   193,   228,   229,
     196,   227,   578,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   228,   229,   227,   213,    11,    12,
      13,    14,   227,   219,   227,   221,   227,   607,     1,   228,
     229,     4,     5,     6,   227,   615,    22,    23,    24,    25,
      26,    27,    11,    12,    13,    14,   228,   229,   227,  1012,
     227,  1014,    11,    12,    13,    14,   228,   229,    31,    32,
      33,    34,    35,    36,   227,    38,    39,   228,   229,   228,
     229,   228,   229,   228,   229,   655,   228,   229,    51,    52,
     228,   229,   228,   229,   227,    58,    59,    60,    61,    62,
      63,   227,    65,   228,   229,   228,   229,    70,   228,   229,
     227,    74,    75,    76,   225,   226,    79,   227,    81,   227,
      83,    84,    85,    86,   227,  1078,   227,    90,   228,   229,
     227,    94,   228,   229,    97,   228,   229,   228,   229,   228,
     229,   228,   229,   228,   229,   228,   229,   228,   229,   719,
     720,   228,   229,   227,   117,   228,   229,   228,   229,   228,
     229,   228,   229,   228,   229,   228,   229,   228,   229,   228,
     229,   228,   229,   228,   229,   228,   229,   228,   229,   749,
     228,   229,   228,   229,   228,   229,   228,   229,   228,   229,
     227,  1144,   228,   229,   228,   229,   228,   229,   228,   229,
     228,   229,   228,   229,   228,   229,   228,   229,   227,   779,
     228,   229,   228,   229,   228,   229,   228,   229,    44,    45,
      44,    45,    44,    45,   228,   229,   228,   229,   227,   192,
     193,    44,    45,   196,    44,    45,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,    44,    45,   227,
     213,     3,     4,   392,   393,   227,   219,   227,   221,   227,
     227,   227,   227,   227,   105,   227,   227,   227,    53,   227,
     227,   227,   227,   227,   227,   227,   227,   227,    71,   227,
     227,   227,     1,   227,   227,     4,     5,     6,   227,   227,
     227,   227,   227,   225,   216,   226,   226,   867,   226,   869,
     225,   225,   225,    46,   225,  1258,   225,   225,   220,   226,
     225,   225,    31,    32,    33,    34,    35,    36,   225,    38,
      39,   225,   225,   221,   225,   225,   228,   221,   227,    73,
     227,   227,    51,    52,   227,   227,   225,   225,   225,    58,
     910,   227,   227,    62,    63,   915,    65,  1300,   227,   919,
     227,    70,    71,    72,    73,    74,    75,    76,   227,   227,
      79,   227,    81,   225,    83,    84,    85,    86,   225,   228,
     228,    90,   228,   228,   228,    94,   228,   221,    97,   228,
     225,   227,   225,    92,   105,   227,    61,   227,   227,   227,
     227,   227,   227,   225,   221,   228,   225,   228,   117,   229,
     198,   222,   227,   222,   222,   222,   222,   227,   222,   221,
      99,   222,   227,   983,   222,   222,   986,   222,    30,   222,
     229,    30,   992,   229,   228,   995,   228,   228,   228,   228,
      30,    30,   228,   228,   228,   222,   228,   228,   228,   228,
     228,   225,   225,   225,   225,   225,   225,   222,   222,   227,
     227,   224,   221,   221,   225,   227,   232,    99,   225,   229,
     221,   221,   228,   228,   227,   229,   228,   221,    99,   228,
     228,   228,   228,   192,   193,   228,   225,   196,   229,   225,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   225,     1,   225,   213,     4,     5,     6,   225,  1069,
     219,   229,   221,   228,   228,   228,   228,   224,   221,   229,
     224,   229,   228,   228,   225,   225,   221,   229,   222,   222,
     228,   228,    31,    32,    33,    34,    35,    36,   225,    38,
      39,   229,   228,   228,   228,   228,   228,   228,   225,   225,
     222,   225,    51,    52,   225,   228,   225,   221,   228,    58,
      59,    60,    61,    62,    63,   222,    65,   229,   229,     1,
     222,    70,     4,     5,     6,    74,    75,    76,   225,  1139,
      79,   222,    81,   227,    83,    84,    85,    86,   227,   227,
     225,    90,   225,   227,   225,    94,   232,   227,    97,    31,
      32,    33,    34,    35,    36,    37,    38,    39,   227,   227,
     227,   225,   227,   221,   227,   227,   225,   228,   117,    51,
      52,   228,   225,   228,   225,   225,    58,   225,   225,   225,
      62,    63,   225,    65,   225,   222,   228,   225,    70,   225,
     225,   225,    74,    75,    76,   227,   227,    79,   227,    81,
     227,    83,    84,    85,    86,   227,   222,   225,    90,    91,
     225,   222,    94,    99,   228,    97,   228,   225,   227,   225,
     221,   228,   227,   227,   227,   227,   222,   222,   222,   222,
     228,   228,    30,   222,    44,   117,   227,   227,    45,   227,
     227,   225,   228,   192,   193,   228,   228,   196,   228,   228,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   225,   225,   221,   213,   227,   227,   227,   227,   222,
     219,   222,   221,   228,   222,   222,   228,   222,   228,   222,
     222,   222,   222,   229,   228,    44,     1,    44,   225,   228,
     228,   221,   228,   228,   228,   228,    45,   229,   229,   228,
     228,   228,   221,   229,   229,   228,   227,   227,   225,   225,
     192,   193,   225,   225,   196,   225,   225,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   222,     1,
     222,   213,     4,     5,     6,   222,   229,   219,   222,   221,
     228,    45,   222,   228,   222,   228,   225,   228,   225,   225,
     225,   225,    45,   225,   225,   228,   225,   225,   228,    31,
      32,    33,    34,    35,    36,    37,    38,    39,   228,   228,
     225,   229,   228,   225,   228,   222,   225,   228,   228,    51,
      52,   225,   225,   222,   222,   227,    58,   222,   225,   225,
      62,    63,   221,    65,   227,   227,     1,   227,    70,     4,
       5,     6,    74,    75,    76,   227,   227,    79,   228,    81,
     228,    83,    84,    85,    86,   228,   222,   229,    90,    91,
     225,   225,    94,   225,   225,    97,    31,    32,    33,    34,
      35,    36,   225,    38,    39,   225,   225,   225,   222,   608,
     227,   227,   227,   225,   227,   117,    51,    52,   228,   225,
     225,   225,   222,    58,   225,   228,   228,    62,    63,   225,
      65,   228,   225,   228,   225,    70,   228,   225,   228,    74,
      75,    76,    77,   225,    79,   222,    81,   227,    83,    84,
      85,    86,   227,   227,   227,    90,   222,   222,   222,    94,
     227,   229,    97,   222,   227,   227,   221,   228,   228,   222,
     228,   225,   228,   225,   225,   225,   225,   225,   225,   225,
     222,   222,   117,   222,   222,   228,    44,   222,   228,   222,
     192,   193,   228,   225,   196,   225,   225,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   228,   227,
     227,   213,   227,   225,   225,   225,   225,   219,   225,   221,
     225,   225,   228,    44,    44,   228,   227,   225,   225,   225,
     229,   222,    44,   228,   228,   228,   225,   229,   228,    45,
     227,   229,   228,   225,   229,   228,   225,   225,   225,   222,
     222,   227,   227,   227,   225,   225,    45,   192,   193,   228,
     228,   196,   225,   228,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   225,     1,   228,   213,     4,
       5,     6,   227,   225,   219,   228,   221,   228,   228,   225,
     228,   225,   225,    45,    45,   227,   227,   227,   225,   228,
     228,   225,   228,   225,   225,   228,    31,    32,    33,    34,
      35,    36,   225,    38,    39,   225,   225,   229,   229,   119,
     228,   228,   227,   229,   228,   225,    51,    52,   225,   225,
     225,    44,   225,    58,   228,   225,   228,    62,    63,    64,
      65,   225,   228,     1,   225,    70,     4,     5,     6,    74,
      75,    76,   228,   227,    79,   225,    81,   228,    83,    84,
      85,    86,   225,   228,   225,    90,   228,   383,   225,    94,
     225,   225,    97,    31,    32,    33,    34,    35,    36,   228,
      38,    39,   225,   225,   228,   225,   412,   225,    -1,    -1,
      -1,    -1,   117,    51,    52,   379,    -1,    -1,    -1,    -1,
      58,    -1,    -1,   384,    62,    63,    64,    65,    -1,    -1,
      -1,    -1,    70,    -1,    -1,    -1,    74,    75,    76,    -1,
      -1,    79,    -1,    81,    -1,    83,    84,    85,    86,    -1,
     948,    -1,    90,    -1,    -1,    -1,    94,    -1,    -1,    97,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,   193,    -1,
      -1,   196,    -1,    -1,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,    -1,    -1,    -1,   213,    -1,
      -1,    -1,    -1,    -1,   219,    -1,   221,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   192,   193,    -1,    -1,   196,    -1,
      -1,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,    -1,     1,    -1,   213,     4,     5,     6,    -1,
      -1,   219,    -1,   221,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    -1,
      38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    -1,    -1,    -1,    -1,    -1,
      58,    -1,    -1,    -1,    62,    63,    -1,    65,    -1,    -1,
       1,    -1,    70,     4,     5,     6,    74,    75,    76,    -1,
      -1,    79,    80,    81,    -1,    83,    84,    85,    86,    -1,
      -1,    -1,    90,    -1,    -1,    -1,    94,    -1,    -1,    97,
      31,    32,    33,    34,    35,    36,    -1,    38,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,
      51,    52,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,
      -1,    62,    63,    -1,    65,    -1,    -1,    -1,    -1,    70,
      -1,    -1,    73,    74,    75,    76,    -1,    -1,    79,    -1,
      81,    -1,    83,    84,    85,    86,    -1,    -1,    -1,    90,
      -1,    -1,    -1,    94,    -1,    -1,    97,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   117,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   192,   193,    -1,    -1,   196,    -1,
      -1,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,    -1,    -1,    -1,   213,    -1,    -1,    -1,    -1,
      -1,   219,    -1,   221,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   192,   193,    -1,    -1,   196,    -1,    -1,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,    -1,
       1,    -1,   213,     4,     5,     6,    -1,    -1,   219,    -1,
     221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,    33,    34,    35,    36,    -1,    38,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    52,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,
      -1,    62,    63,    -1,    65,    -1,    -1,     1,    -1,    70,
       4,     5,     6,    74,    75,    76,    -1,    78,    79,    -1,
      81,    -1,    83,    84,    85,    86,    -1,    -1,    -1,    90,
      -1,    -1,    -1,    94,    -1,    -1,    97,    31,    32,    33,
      34,    35,    36,    -1,    38,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   117,    51,    52,    -1,
      -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,    62,    63,
      -1,    65,    66,    -1,    -1,    -1,    70,    -1,    -1,    -1,
      74,    75,    76,    -1,    -1,    79,    -1,    81,    -1,    83,
      84,    85,    86,    -1,    -1,    -1,    90,    -1,    -1,    -1,
      94,    -1,    -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   192,   193,    -1,    -1,   196,    -1,    -1,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,    -1,
      -1,    -1,   213,    -1,    -1,    -1,    -1,    -1,   219,    -1,
     221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,   193,
      -1,    -1,   196,    -1,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,    -1,     1,    -1,   213,
       4,     5,     6,    -1,    -1,   219,    -1,   221,    -1,    -1,
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
      -1,    -1,    -1,   117,    51,    52,    -1,    -1,    -1,    -1,
      -1,    58,    -1,    -1,    -1,    62,    63,    -1,    65,    66,
      -1,    -1,    -1,    70,    -1,    -1,    -1,    74,    75,    76,
      -1,    -1,    79,    -1,    81,    -1,    83,    84,    85,    86,
      -1,    -1,    -1,    90,    -1,    -1,    -1,    94,    -1,    -1,
      97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,   193,
      -1,    -1,   196,    -1,    -1,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,    -1,    -1,    -1,   213,
      -1,    -1,    -1,    -1,    -1,   219,    -1,   221,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   192,   193,    -1,    -1,   196,
      -1,    -1,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,    -1,     1,    -1,   213,     4,     5,     6,
      -1,    -1,   219,    -1,   221,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,    36,
      -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    51,    52,    -1,    -1,    -1,    -1,
      -1,    58,    -1,    -1,    -1,    62,    63,    -1,    65,    66,
      -1,     1,    -1,    70,     4,     5,     6,    74,    75,    76,
      -1,    -1,    79,    -1,    81,    -1,    83,    84,    85,    86,
      -1,    -1,    -1,    90,    -1,    -1,    -1,    94,    -1,    -1,
      97,    31,    32,    33,    34,    35,    36,    -1,    38,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     117,    51,    52,    -1,    -1,    -1,    -1,    -1,    58,    -1,
      -1,    -1,    62,    63,    -1,    65,    66,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    74,    75,    76,    -1,    -1,    79,
      -1,    81,    -1,    83,    84,    85,    86,    -1,    -1,    -1,
      90,    -1,    -1,    -1,    94,    -1,    -1,    97,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   192,   193,    -1,    -1,   196,
      -1,    -1,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,    -1,    -1,    -1,   213,    -1,    -1,    -1,
      -1,    -1,   219,    -1,   221,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   192,   193,    -1,    -1,   196,    -1,    -1,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
      -1,     1,    -1,   213,     4,     5,     6,    -1,    -1,   219,
      -1,   221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    33,    34,    35,    36,    -1,    38,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,    -1,    -1,    -1,    -1,    -1,    58,    -1,
      -1,    -1,    62,    63,    -1,    65,    66,    -1,     1,    -1,
      70,     4,     5,     6,    74,    75,    76,    -1,    -1,    79,
      -1,    81,    -1,    83,    84,    85,    86,    -1,    -1,    -1,
      90,    -1,    -1,    -1,    94,    -1,    -1,    97,    31,    32,
      33,    34,    35,    36,    -1,    38,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,    51,    52,
      -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,    62,
      63,    -1,    65,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      -1,    74,    75,    76,    -1,    -1,    79,    -1,    81,    -1,
      83,    84,    85,    86,    -1,    -1,    -1,    90,    91,    -1,
      -1,    94,    -1,    -1,    97,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   192,   193,    -1,    -1,   196,    -1,    -1,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
      -1,    -1,    -1,   213,    -1,    -1,    -1,    -1,    -1,   219,
      -1,   221,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   192,
     193,    -1,    -1,   196,    -1,    -1,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,    -1,     1,    -1,
     213,     4,     5,     6,    -1,    -1,   219,    -1,   221,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,
      33,    34,    35,    36,    -1,    38,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,
      -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,    62,
      63,    -1,    65,    -1,    -1,    -1,    -1,    70,    -1,    -1,
      -1,    74,    75,    76,    -1,    -1,    79,    -1,    81,    -1,
      83,    84,    85,    86,    -1,    -1,    -1,    90,    91,    -1,
      -1,    94,    -1,    -1,    97,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,
      55,    56,    57,    -1,    -1,    -1,    -1,    -1,    -1,   192,
     193,    -1,    -1,   196,    -1,    -1,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,    82,    -1,    -1,
     213,    86,    -1,    -1,    89,    -1,   219,    -1,   221,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,    -1,
      -1,   196,    -1,    -1,   199,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,    21,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   221,   222,   223,   224,
     225,    -1,   227,    -1,    -1,    -1,   231,    -1,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,
      56,    57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    -1,    -1,    -1,
      86,    -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,    -1,    -1,
     196,    -1,    -1,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   221,   222,   223,   224,    -1,
      -1,   227,   228,    -1,    -1,   231,    -1,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,
      57,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    82,    -1,    -1,    -1,    86,
      -1,    -1,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,    -1,    -1,   196,
      -1,    -1,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   221,   222,   223,   224,    -1,    -1,
     227,   228,    -1,    -1,   231,    -1,    -1,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,    57,
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
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,    -1,    -1,   196,    -1,
      -1,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   221,   222,   223,   224,    -1,    -1,   227,
     228,    -1,    -1,   231,    -1,    -1,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    54,    55,    56,    57,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    -1,    -1,    -1,    86,    -1,    -1,
      89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,    -1,    -1,   196,    -1,    -1,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   221,   222,   223,   224,    -1,    -1,   227,    -1,
      -1,    -1,   231,    -1,    -1,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    54,    55,    56,    57,    -1,    -1,
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
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,    -1,    -1,   196,    -1,    -1,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   221,   222,   223,   224,    -1,    -1,   227,    -1,    -1,
      -1,   231,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    53,    54,    55,    56,    57,    -1,    -1,    -1,
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
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,    -1,    -1,   196,    -1,    -1,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     221,   222,   223,   224,    -1,    -1,   227,   293,   294,   295,
     296,   297,   298,   299,   300,   301,   302,   303,   304,    -1,
      -1,   307,   308,   309,   310,   311,    -1,    -1,    -1,   315,
     316,   317,   318,   319,   320,    -1,    -1,    -1,    -1,   325,
     326,   327,   328,   329,   330,   331,    -1,   333,   334,   335,
     336,   337,   338,   339,   340,   341,   342,   343,   344,   345,
     346,   347,   348,   349,   350,   351,   352,   353,   354,   355,
     356,   357,   358,   359,   360,   361,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   370,   371,   372,   373,   374,   375,
     376
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,     3,   240,   241,   241,     0,     1,     4,     5,     6,
      31,    32,    33,    34,    35,    36,    38,    39,    50,    51,
      52,    58,    62,    63,    65,    70,    74,    75,    76,    79,
      81,    83,    84,    85,    86,    90,    94,    97,   117,   192,
     193,   196,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   213,   219,   221,   243,   244,   245,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   266,   267,   268,   269,   270,   271,   272,   273,
     274,   277,   280,   284,   285,   286,   287,   288,   292,   293,
     225,   221,   192,   193,   196,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   220,   221,   304,   221,
      21,    45,    53,    54,    55,    56,    57,    82,    86,    89,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   196,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     221,   222,   223,   224,   227,   231,   294,   295,   296,   297,
     298,   299,   300,   301,   302,   303,   305,   221,   248,   304,
     248,   294,   225,   304,   227,   225,   294,   226,   294,   294,
     294,   304,   225,   225,   225,   225,   221,   304,   304,   304,
     304,   221,   221,   221,   227,   221,   304,   105,   227,   226,
       7,     8,     9,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,   102,   192,   193,   194,   195,   196,   197,
     215,   294,   298,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   227,   227,
     227,   227,   227,   227,   227,   227,   227,   227,   224,   227,
     294,   303,   225,    88,    87,   226,   234,   235,   236,   237,
     238,   220,   230,   231,   232,   233,   216,   105,   227,   226,
     226,   226,   225,   225,   304,   225,    53,   225,   225,   225,
     226,    71,   289,   290,   242,   225,   225,   225,   225,   225,
      46,   260,    11,    12,    13,    14,    48,   261,    99,   100,
     101,   201,   225,   294,   308,    99,   225,   220,   221,   294,
     306,   307,   294,    10,   225,   225,   225,   227,   227,   227,
     227,   227,   202,   225,   203,   225,   225,   225,   225,   227,
     227,   227,   227,   227,   227,   227,   225,   225,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     228,   228,   308,   308,   308,   308,   308,   228,   228,   228,
     308,   308,   308,   228,   308,   228,   308,   228,   308,   294,
     294,   294,   294,   308,   308,   308,   308,   308,   308,   308,
     294,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     294,   294,   294,   294,   221,   228,   304,   304,   308,   308,
     308,   308,   308,   308,   308,   304,   294,   306,   228,   296,
     297,   299,   299,   299,   299,   299,   299,   299,   300,   300,
     301,   301,   301,   221,   294,   294,   304,   294,   228,   225,
     242,   242,   242,   294,   294,    72,   290,   291,    77,   243,
     242,   225,   227,   227,   227,   227,   227,    49,   225,   100,
     201,   225,   227,   227,   227,   278,   228,   229,   225,   221,
     275,   276,   294,   228,   228,   229,   225,   227,   222,   222,
     222,   222,   222,   227,   227,   221,   222,   222,   222,   222,
     222,   198,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   229,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   229,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   228,   228,   228,   228,   228,   228,   228,   228,
     228,   228,   225,   225,   225,   304,   281,    64,    64,    67,
      68,   225,   225,    73,   225,    80,    92,   222,   222,   222,
     222,   224,   227,   264,   227,   227,   278,   217,   218,   222,
     221,   221,    98,   103,   221,   279,   294,   275,   225,   226,
     214,   276,   225,   105,   225,   294,   232,   228,   228,   228,
     229,   229,   221,   221,   228,   228,   228,   228,   228,   228,
     229,   294,    22,    23,    24,    25,    26,    27,   225,    59,
      60,   282,   283,   225,   225,   294,   294,   242,   242,   225,
     242,   225,   221,   261,   228,   228,   228,   229,   228,   224,
      95,   104,   221,   265,   217,   218,   222,   221,    98,   229,
     229,   228,   228,   228,   229,   225,   221,    11,    12,    13,
      14,   214,   294,   225,   242,   221,   229,    29,    30,    40,
      41,    42,    46,    47,   100,   246,    30,    46,   100,   246,
      29,    30,    42,    46,   100,   246,   222,   222,   228,   228,
     225,   246,   246,   246,   246,   246,   224,   229,   228,   228,
     228,   228,   228,   228,   294,   225,    61,    69,   225,    69,
     225,    78,   261,   225,   222,   225,   228,   225,   221,    11,
      12,    13,    14,   101,   229,   229,   228,   228,   229,   225,
     222,   222,    99,   100,   225,   225,   222,    11,    12,    13,
      14,   227,   227,   227,   227,   225,   225,    66,   232,    30,
     227,   227,    30,   227,   225,   227,   227,   225,    30,   227,
     227,    30,   227,   225,   228,   228,   225,   225,   225,   225,
     225,   225,   225,   228,    22,    23,    24,    25,    26,    27,
     225,   242,   225,   294,   242,   294,   242,   225,   225,   262,
     228,   264,   225,    11,    12,    13,    14,   227,   227,   227,
     227,   227,   222,   222,   225,   225,   222,   228,   228,   225,
     227,   278,   228,   227,   227,   227,   227,   222,   222,   222,
     222,   225,   228,   227,   294,   221,   227,   222,   294,   217,
     218,   222,   227,   294,   221,   227,   217,   218,   222,    29,
      30,   100,   246,   246,   225,   228,   228,   228,   228,   228,
     228,   242,   225,    66,   225,    66,   262,    93,   104,   221,
     263,    95,   264,   227,   227,   227,   227,   222,   222,   222,
     222,   221,   228,   228,   278,   278,   228,    99,    99,   278,
     222,    98,    99,   222,   222,   222,   222,   228,   228,   228,
     229,   225,   294,   228,   228,   294,   228,   228,   229,   229,
     228,   294,   228,   228,   294,   229,   229,   228,    30,   227,
     227,   225,   225,   242,   225,   242,   225,    93,   225,   221,
      11,    12,    13,    14,   101,   225,    95,   222,   222,   222,
     222,   228,   228,   228,   229,   228,   225,   225,    98,    98,
     225,   225,   225,    98,   228,   225,   225,   228,   228,   228,
     229,   199,   200,   225,   225,   199,   200,   225,   222,   228,
     225,   225,   228,   207,   208,   225,   225,   222,   222,   225,
     228,   225,   225,   228,   222,   222,   207,   208,   225,   227,
     294,   222,    66,    66,   225,   242,    11,    12,    13,    14,
     227,   227,   227,   227,   227,   225,   228,   228,   228,   229,
      43,    96,   225,    43,    96,   225,    43,    96,   225,   222,
     225,   278,   278,   225,   225,   278,   278,   278,   225,   225,
     278,   225,   225,   225,   222,   227,   227,   227,   227,   228,
     225,   225,   225,   225,   228,   228,   225,   225,   228,   228,
     225,   225,   294,   228,   228,   225,   225,   242,    37,    91,
     227,   227,   227,   227,   222,   222,   222,   222,   221,    96,
     225,    96,   225,    96,   225,   222,   227,    43,   225,   227,
      43,   225,   227,    43,   225,   228,    98,    98,    98,    98,
      98,    98,   228,   221,   222,   221,   222,   200,   225,   225,
     225,   225,   225,   228,   225,   225,    37,    91,   225,   225,
     222,   222,   222,   222,   228,   228,   228,   229,   228,   225,
     225,   225,   228,    44,    45,   227,    44,    45,   227,    44,
      45,   227,    43,    96,   225,   225,   225,   225,   225,   225,
     225,   225,   228,   229,   228,   228,   229,   228,   227,   225,
     225,   225,   242,   228,   228,   228,   229,    43,    96,   225,
      43,    96,   225,    43,    96,   225,   222,   225,    96,   225,
     229,   228,    44,   229,   228,    44,   229,   228,    44,   227,
      43,   225,   225,   222,   225,   225,   222,   225,   222,   242,
      91,    96,   225,    96,   225,    96,   225,   222,   227,    43,
     225,   227,    43,   225,   227,    43,   225,   228,   225,    45,
     225,   228,    45,   225,   228,    45,   225,   228,    45,   227,
     228,   228,   228,    91,   225,   225,   225,   225,   228,    44,
      45,   227,    44,    45,   227,    44,    45,   227,    43,    96,
     225,   228,   225,   228,   225,   228,   225,   228,    44,   225,
     225,   225,   225,    96,   225,   229,   228,    44,   229,   228,
      44,   229,   228,    44,   227,    43,   225,   225,   225,   225,
     225,   228,   225,    45,   225,   228,    45,   225,   228,    45,
     225,   228,    45,   227,   225,   228,   225,   228,   225,   228,
     225,   228,    44,   225,   225,   225,   225,   228,   225
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   239,   240,   240,   241,   241,   241,   242,   242,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   243,   243,   243,   243,   243,   243,   243,   243,
     243,   243,   244,   244,   244,   244,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   246,
     246,   246,   246,   246,   247,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   248,   248,   248,   248,   248,
     248,   248,   248,   248,   248,   249,   249,   250,   251,   252,
     253,   254,   255,   256,   256,   257,   258,   258,   258,   259,
     259,   259,   259,   260,   260,   261,   261,   261,   261,   261,
     262,   262,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     263,   263,   263,   263,   263,   263,   263,   263,   263,   263,
     264,   264,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     266,   267,   268,   269,   270,   271,   272,   273,   274,   274,
     275,   275,   276,   276,   277,   277,   277,   277,   277,   277,
     277,   277,   277,   277,   277,   277,   277,   277,   278,   278,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   280,   281,   281,   282,   283,
     283,   284,   285,   286,   286,   286,   286,   287,   288,   289,
     289,   290,   291,   291,   292,   293,   294,   295,   295,   296,
     296,   297,   297,   298,   298,   298,   298,   298,   298,   298,
     298,   299,   299,   299,   300,   300,   300,   301,   301,   302,
     302,   303,   303,   304,   304,   304,   304,   304,   304,   304,
     304,   304,   304,   304,   304,   304,   304,   304,   304,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   305,   305,
     305,   305,   305,   305,   305,   305,   305,   305,   306,   306,
     307,   307,   308,   308
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     0,     2,     2,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     4,     4,     4,    10,     8,     8,     8,    10,
      10,    12,    12,    14,    11,    11,    13,    11,    12,    12,
       4,     4,     4,     4,     4,     4,    11,    11,    11,    13,
      13,    13,    13,    13,     7,     8,     8,     8,     8,     8,
       9,    11,    11,    12,    12,    12,    12,     8,     8,     0,
       1,     1,     1,     1,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     4,     6,     4,     4,     5,     5,     5,     3,
       2,     3,     4,     3,     2,     5,     7,    11,    10,    13,
      14,    16,    17,     0,     1,     0,     4,     4,     4,     6,
       0,     2,     6,     7,     6,     7,     6,     7,     8,     9,
       7,     8,     7,     8,     7,     8,     9,    10,     6,    11,
      11,    11,    13,    10,    10,    10,    12,    12,    12,    12,
       0,     2,     6,     7,     6,     7,     6,     7,     8,     9,
       7,     8,     7,     8,     7,     8,     9,    10,     6,    11,
      11,    11,    13,    10,    10,    10,    12,    12,    12,    12,
       8,     6,     3,     3,     3,     3,     3,     6,     7,     6,
       1,     2,     2,     4,     7,     6,    11,    11,    13,    13,
      13,    13,     7,    11,    11,    13,    13,    10,     0,     2,
       6,     6,     6,     8,     7,     7,     7,     9,    10,    10,
      12,    10,    12,    10,    12,     8,     0,     2,     4,     0,
       3,     6,     6,    10,    12,    10,    12,     8,     6,     1,
       2,     4,     0,     3,     2,     2,     1,     1,     3,     1,
       3,     1,     2,     1,     3,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     1,     3,     1,
       2,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       3,     4,     4,     4,     4,     4,     4,     4,     4,     6,
       6,     6,     6,     6,     6,     4,     4,     4,     4,     3,
       3,     4,     4,     4,     4,     4,     4,     3,     4,     3,
       4,     3,     8,     8,     8,     4,     4,     4,     3,     3,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     3,     1,     8,     8,     8,     2,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     0,     1,
       1,     3,     1,     3
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
#line 192 "src/parser.y"
                           {
        (yyval.program) = g_program;
    }
#line 3029 "build/parser.cpp"
    break;

  case 3: /* program: statements_opt  */
#line 195 "src/parser.y"
                     {
        (yyval.program) = g_program;
    }
#line 3037 "build/parser.cpp"
    break;

  case 5: /* statements_opt: statements_opt statement  */
#line 202 "src/parser.y"
                               {
        if ((yyvsp[0].stmt)) {
            g_program->statements.emplace_back((yyvsp[0].stmt));
        }
    }
#line 3047 "build/parser.cpp"
    break;

  case 6: /* statements_opt: statements_opt KW_CTLOPT  */
#line 207 "src/parser.y"
                               {
        if (ctlopt_nomain) g_program->nomain = true;
        if (ctlopt_main_proc[0]) g_program->main_proc = ctlopt_main_proc;
        if (ctlopt_datfmt[0]) g_program->datfmt = ctlopt_datfmt;
        if (ctlopt_timfmt[0]) g_program->timfmt = ctlopt_timfmt;
    }
#line 3058 "build/parser.cpp"
    break;

  case 7: /* statement_list: %empty  */
#line 216 "src/parser.y"
                {
        (yyval.stmt_list) = new StmtList();
    }
#line 3066 "build/parser.cpp"
    break;

  case 8: /* statement_list: statement_list statement  */
#line 219 "src/parser.y"
                               {
        (yyval.stmt_list) = (yyvsp[-1].stmt_list);
        if ((yyvsp[0].stmt)) {
            (yyval.stmt_list)->stmts.push_back((yyvsp[0].stmt));
        }
    }
#line 3077 "build/parser.cpp"
    break;

  case 9: /* statement: dcl_f_stmt  */
#line 228 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3083 "build/parser.cpp"
    break;

  case 10: /* statement: dcl_s_stmt  */
#line 229 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3089 "build/parser.cpp"
    break;

  case 11: /* statement: dcl_c_stmt  */
#line 230 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3095 "build/parser.cpp"
    break;

  case 12: /* statement: eval_stmt  */
#line 231 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3101 "build/parser.cpp"
    break;

  case 13: /* statement: eval_corr_stmt  */
#line 232 "src/parser.y"
                     { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3107 "build/parser.cpp"
    break;

  case 14: /* statement: dsply_stmt  */
#line 233 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3113 "build/parser.cpp"
    break;

  case 15: /* statement: inlr_stmt  */
#line 234 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3119 "build/parser.cpp"
    break;

  case 16: /* statement: return_stmt  */
#line 235 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3125 "build/parser.cpp"
    break;

  case 17: /* statement: if_stmt  */
#line 236 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3131 "build/parser.cpp"
    break;

  case 18: /* statement: dow_stmt  */
#line 237 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3137 "build/parser.cpp"
    break;

  case 19: /* statement: dou_stmt  */
#line 238 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3143 "build/parser.cpp"
    break;

  case 20: /* statement: for_stmt  */
#line 239 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3149 "build/parser.cpp"
    break;

  case 21: /* statement: for_each_stmt  */
#line 240 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3155 "build/parser.cpp"
    break;

  case 22: /* statement: select_stmt  */
#line 241 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3161 "build/parser.cpp"
    break;

  case 23: /* statement: iter_stmt  */
#line 242 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3167 "build/parser.cpp"
    break;

  case 24: /* statement: leave_stmt  */
#line 243 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3173 "build/parser.cpp"
    break;

  case 25: /* statement: dcl_proc_stmt  */
#line 244 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3179 "build/parser.cpp"
    break;

  case 26: /* statement: dcl_pr_stmt  */
#line 245 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3185 "build/parser.cpp"
    break;

  case 27: /* statement: dcl_ds_stmt  */
#line 246 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3191 "build/parser.cpp"
    break;

  case 28: /* statement: dcl_enum_stmt  */
#line 247 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3197 "build/parser.cpp"
    break;

  case 29: /* statement: monitor_stmt  */
#line 248 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3203 "build/parser.cpp"
    break;

  case 30: /* statement: begsr_stmt  */
#line 249 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3209 "build/parser.cpp"
    break;

  case 31: /* statement: exsr_stmt  */
#line 250 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3215 "build/parser.cpp"
    break;

  case 32: /* statement: reset_stmt  */
#line 251 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3221 "build/parser.cpp"
    break;

  case 33: /* statement: clear_stmt  */
#line 252 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3227 "build/parser.cpp"
    break;

  case 34: /* statement: sorta_stmt  */
#line 253 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3233 "build/parser.cpp"
    break;

  case 35: /* statement: evalr_stmt  */
#line 254 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3239 "build/parser.cpp"
    break;

  case 36: /* statement: callp_stmt  */
#line 255 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3245 "build/parser.cpp"
    break;

  case 37: /* statement: leavesr_stmt  */
#line 256 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3251 "build/parser.cpp"
    break;

  case 38: /* statement: dealloc_stmt  */
#line 257 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3257 "build/parser.cpp"
    break;

  case 39: /* statement: test_stmt  */
#line 258 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3263 "build/parser.cpp"
    break;

  case 40: /* statement: expr_stmt  */
#line 259 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3269 "build/parser.cpp"
    break;

  case 41: /* statement: error SEMICOLON  */
#line 260 "src/parser.y"
                      { (yyval.stmt) = nullptr; yyerrok; }
#line 3275 "build/parser.cpp"
    break;

  case 42: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_DISK SEMICOLON  */
#line 265 "src/parser.y"
                                          {
        (yyval.stmt) = new rpg::DclF((yyvsp[-2].sval), "DISK");
        free((yyvsp[-2].sval));
    }
#line 3284 "build/parser.cpp"
    break;

  case 43: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_PRINTER SEMICOLON  */
#line 269 "src/parser.y"
                                               {
        (yyval.stmt) = new rpg::DclF((yyvsp[-2].sval), "PRINTER");
        free((yyvsp[-2].sval));
    }
#line 3293 "build/parser.cpp"
    break;

  case 44: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_WORKSTN SEMICOLON  */
#line 273 "src/parser.y"
                                               {
        (yyval.stmt) = new rpg::DclF((yyvsp[-2].sval), "WORKSTN");
        free((yyvsp[-2].sval));
    }
#line 3302 "build/parser.cpp"
    break;

  case 45: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_DISK KW_USAGE LPAREN STAR COLON STAR RPAREN SEMICOLON  */
#line 277 "src/parser.y"
                                                                                   {
        (yyval.stmt) = new rpg::DclF((yyvsp[-8].sval), "DISK");
        free((yyvsp[-8].sval));
    }
#line 3311 "build/parser.cpp"
    break;

  case 46: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 285 "src/parser.y"
                                                                                  {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3321 "build/parser.cpp"
    break;

  case 47: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 290 "src/parser.y"
                                                                                       {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3331 "build/parser.cpp"
    break;

  case 48: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 295 "src/parser.y"
                                                                                   {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::INT10, 0);
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3341 "build/parser.cpp"
    break;

  case 49: /* dcl_s_stmt: KW_DCL_S ident KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 300 "src/parser.y"
                                                                                                            {
        auto* n = new rpg::DclS((yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-8].sval));
    }
#line 3351 "build/parser.cpp"
    break;

  case 50: /* dcl_s_stmt: KW_DCL_S ident KW_ZONED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 305 "src/parser.y"
                                                                                                           {
        auto* n = new rpg::DclS((yyvsp[-8].sval), rpg::RPGType::ZONED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-8].sval));
    }
#line 3361 "build/parser.cpp"
    break;

  case 51: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_CONST KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 310 "src/parser.y"
                                                                                                             {
        (yyval.stmt) = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, true,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-10].sval));
    }
#line 3371 "build/parser.cpp"
    break;

  case 52: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_CONST KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 315 "src/parser.y"
                                                                                                              {
        (yyval.stmt) = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, true,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-10].sval));
    }
#line 3381 "build/parser.cpp"
    break;

  case 53: /* dcl_s_stmt: KW_DCL_S ident KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_CONST KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 320 "src/parser.y"
                                                                                                                                      {
        (yyval.stmt) = new rpg::DclS((yyvsp[-12].sval), rpg::RPGType::PACKED, 0, (yyvsp[-9].ival), (yyvsp[-7].ival), true,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-12].sval));
    }
#line 3391 "build/parser.cpp"
    break;

  case 54: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 325 "src/parser.y"
                                                                                                    {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-9].sval));
    }
#line 3401 "build/parser.cpp"
    break;

  case 55: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 330 "src/parser.y"
                                                                                                     {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-9].sval));
    }
#line 3411 "build/parser.cpp"
    break;

  case 56: /* dcl_s_stmt: KW_DCL_S ident KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 335 "src/parser.y"
                                                                                                                             {
        (yyval.stmt) = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-11].sval));
    }
#line 3421 "build/parser.cpp"
    break;

  case 57: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 340 "src/parser.y"
                                                                                                        {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-9].sval));
    }
#line 3431 "build/parser.cpp"
    break;

  case 58: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_EXPORT KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 346 "src/parser.y"
                                                                                                              {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        n->is_export = true;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3442 "build/parser.cpp"
    break;

  case 59: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_EXPORT KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 352 "src/parser.y"
                                                                                                               {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        n->is_export = true;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3453 "build/parser.cpp"
    break;

  case 60: /* dcl_s_stmt: KW_DCL_S ident KW_IND SEMICOLON  */
#line 358 "src/parser.y"
                                      {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::IND, 0);
        free((yyvsp[-2].sval));
    }
#line 3462 "build/parser.cpp"
    break;

  case 61: /* dcl_s_stmt: KW_DCL_S ident KW_BOOLEAN SEMICOLON  */
#line 362 "src/parser.y"
                                          {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::IND, 0);
        free((yyvsp[-2].sval));
    }
#line 3471 "build/parser.cpp"
    break;

  case 62: /* dcl_s_stmt: KW_DCL_S ident KW_DATE SEMICOLON  */
#line 366 "src/parser.y"
                                       {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::DATE, 0);
        free((yyvsp[-2].sval));
    }
#line 3480 "build/parser.cpp"
    break;

  case 63: /* dcl_s_stmt: KW_DCL_S ident KW_TIME SEMICOLON  */
#line 370 "src/parser.y"
                                       {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::TIME, 0);
        free((yyvsp[-2].sval));
    }
#line 3489 "build/parser.cpp"
    break;

  case 64: /* dcl_s_stmt: KW_DCL_S ident KW_TIMESTAMP SEMICOLON  */
#line 374 "src/parser.y"
                                            {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::TIMESTAMP, 0);
        free((yyvsp[-2].sval));
    }
#line 3498 "build/parser.cpp"
    break;

  case 65: /* dcl_s_stmt: KW_DCL_S ident KW_POINTER SEMICOLON  */
#line 378 "src/parser.y"
                                          {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::POINTER, 0);
        free((yyvsp[-2].sval));
    }
#line 3507 "build/parser.cpp"
    break;

  case 66: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 382 "src/parser.y"
                                                                                                         {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-9].sval));
    }
#line 3516 "build/parser.cpp"
    break;

  case 67: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 386 "src/parser.y"
                                                                                                          {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-9].sval));
    }
#line 3525 "build/parser.cpp"
    break;

  case 68: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 390 "src/parser.y"
                                                                                                             {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-9].sval));
    }
#line 3534 "build/parser.cpp"
    break;

  case 69: /* dcl_s_stmt: KW_DCL_S ident KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 394 "src/parser.y"
                                                                                                                                  {
        (yyval.stmt) = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-11].sval));
    }
#line 3543 "build/parser.cpp"
    break;

  case 70: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN KW_DIM_VAR COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 398 "src/parser.y"
                                                                                                                          {
        auto* node = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-2].ival));
        node->dim_type = 1;
        free((yyvsp[-11].sval));
        (yyval.stmt) = node;
    }
#line 3554 "build/parser.cpp"
    break;

  case 71: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN KW_DIM_AUTO COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 404 "src/parser.y"
                                                                                                                           {
        auto* node = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-2].ival));
        node->dim_type = 2;
        free((yyvsp[-11].sval));
        (yyval.stmt) = node;
    }
#line 3565 "build/parser.cpp"
    break;

  case 72: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN KW_DIM_VAR COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 410 "src/parser.y"
                                                                                                                              {
        auto* node = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::VARCHAR, (yyvsp[-8].ival), 0, 0, false, nullptr, (yyvsp[-2].ival));
        node->dim_type = 1;
        free((yyvsp[-11].sval));
        (yyval.stmt) = node;
    }
#line 3576 "build/parser.cpp"
    break;

  case 73: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN KW_DIM_AUTO COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 416 "src/parser.y"
                                                                                                                               {
        auto* node = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::VARCHAR, (yyvsp[-8].ival), 0, 0, false, nullptr, (yyvsp[-2].ival));
        node->dim_type = 2;
        free((yyvsp[-11].sval));
        (yyval.stmt) = node;
    }
#line 3587 "build/parser.cpp"
    break;

  case 74: /* dcl_s_stmt: KW_DCL_S ident KW_LIKE LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 422 "src/parser.y"
                                                                {
        auto* node = new rpg::DclS((yyvsp[-5].sval), rpg::RPGType::INT10, 0);
        node->like_var = (yyvsp[-2].sval);
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
        (yyval.stmt) = node;
    }
#line 3599 "build/parser.cpp"
    break;

  case 75: /* dcl_s_stmt: KW_DCL_S ident KW_UNS LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 429 "src/parser.y"
                                                                                   {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::UNS, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3609 "build/parser.cpp"
    break;

  case 76: /* dcl_s_stmt: KW_DCL_S ident KW_FLOAT_TYPE LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 434 "src/parser.y"
                                                                                          {
        auto type = ((yyvsp[-3].ival) <= 4) ? rpg::RPGType::FLOAT4 : rpg::RPGType::FLOAT8;
        auto* n = new rpg::DclS((yyvsp[-6].sval), type, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3620 "build/parser.cpp"
    break;

  case 77: /* dcl_s_stmt: KW_DCL_S ident KW_BINDEC LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 440 "src/parser.y"
                                                                                      {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::BINDEC, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3630 "build/parser.cpp"
    break;

  case 78: /* dcl_s_stmt: KW_DCL_S ident KW_UCS2 LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 445 "src/parser.y"
                                                                                    {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::UCS2, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3640 "build/parser.cpp"
    break;

  case 79: /* dcl_s_stmt: KW_DCL_S ident KW_GRAPH LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 450 "src/parser.y"
                                                                                     {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::UCS2, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3650 "build/parser.cpp"
    break;

  case 80: /* dcl_s_stmt: KW_DCL_S ident KW_OBJECT LPAREN KW_JAVA COLON STRING_LITERAL RPAREN SEMICOLON  */
#line 455 "src/parser.y"
                                                                                    {
        auto* n = new rpg::DclS((yyvsp[-7].sval), rpg::RPGType::OBJECT, 0);
        n->java_class = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-7].sval)); free((yyvsp[-2].sval));
    }
#line 3660 "build/parser.cpp"
    break;

  case 81: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_BASED LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 460 "src/parser.y"
                                                                                                      {
        auto* n = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::INT10, 0);
        n->based_ptr = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
    }
#line 3670 "build/parser.cpp"
    break;

  case 82: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_BASED LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 465 "src/parser.y"
                                                                                                       {
        auto* n = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival));
        n->based_ptr = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
    }
#line 3680 "build/parser.cpp"
    break;

  case 83: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_ASCEND SEMICOLON  */
#line 470 "src/parser.y"
                                                                                                                   {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = 1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3690 "build/parser.cpp"
    break;

  case 84: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_DESCEND SEMICOLON  */
#line 475 "src/parser.y"
                                                                                                                    {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = -1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3700 "build/parser.cpp"
    break;

  case 85: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_ASCEND SEMICOLON  */
#line 480 "src/parser.y"
                                                                                                                    {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = 1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3710 "build/parser.cpp"
    break;

  case 86: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_DESCEND SEMICOLON  */
#line 485 "src/parser.y"
                                                                                                                     {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = -1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3720 "build/parser.cpp"
    break;

  case 87: /* dcl_s_stmt: KW_DCL_S ident KW_DATE KW_DATFMT LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 490 "src/parser.y"
                                                                          {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::DATE, 0);
        n->datfmt = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-6].sval)); free((yyvsp[-2].sval));
    }
#line 3730 "build/parser.cpp"
    break;

  case 88: /* dcl_s_stmt: KW_DCL_S ident KW_TIME KW_TIMFMT LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 495 "src/parser.y"
                                                                          {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::TIME, 0);
        n->timfmt = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-6].sval)); free((yyvsp[-2].sval));
    }
#line 3740 "build/parser.cpp"
    break;

  case 89: /* dcl_s_keywords: %empty  */
#line 503 "src/parser.y"
                  { (yyval.ival) = 0; }
#line 3746 "build/parser.cpp"
    break;

  case 90: /* dcl_s_keywords: KW_STATIC  */
#line 504 "src/parser.y"
                  { (yyval.ival) = 1; }
#line 3752 "build/parser.cpp"
    break;

  case 91: /* dcl_s_keywords: KW_TEMPLATE  */
#line 505 "src/parser.y"
                  { (yyval.ival) = 2; }
#line 3758 "build/parser.cpp"
    break;

  case 92: /* dcl_s_keywords: KW_EXPORT  */
#line 506 "src/parser.y"
                  { (yyval.ival) = 4; }
#line 3764 "build/parser.cpp"
    break;

  case 93: /* dcl_s_keywords: KW_IMPORT  */
#line 507 "src/parser.y"
                  { (yyval.ival) = 8; }
#line 3770 "build/parser.cpp"
    break;

  case 94: /* dcl_c_stmt: KW_DCL_C IDENTIFIER expression SEMICOLON  */
#line 512 "src/parser.y"
                                             {
        (yyval.stmt) = new rpg::DclC((yyvsp[-2].sval), std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
        free((yyvsp[-2].sval));
    }
#line 3779 "build/parser.cpp"
    break;

  case 95: /* eval_target: IDENTIFIER  */
#line 519 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier((yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 3788 "build/parser.cpp"
    break;

  case 96: /* eval_target: KW_POS  */
#line 523 "src/parser.y"
             { (yyval.expr) = new rpg::Identifier("POS"); }
#line 3794 "build/parser.cpp"
    break;

  case 97: /* eval_target: KW_OVERLAY  */
#line 524 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("OVERLAY"); }
#line 3800 "build/parser.cpp"
    break;

  case 98: /* eval_target: KW_PREFIX  */
#line 525 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("PREFIX"); }
#line 3806 "build/parser.cpp"
    break;

  case 99: /* eval_target: KW_UNS  */
#line 526 "src/parser.y"
             { (yyval.expr) = new rpg::Identifier("UNS"); }
#line 3812 "build/parser.cpp"
    break;

  case 100: /* eval_target: KW_FLOAT_TYPE  */
#line 527 "src/parser.y"
                    { (yyval.expr) = new rpg::Identifier("FLOAT"); }
#line 3818 "build/parser.cpp"
    break;

  case 101: /* eval_target: KW_GRAPH  */
#line 528 "src/parser.y"
               { (yyval.expr) = new rpg::Identifier("GRAPH"); }
#line 3824 "build/parser.cpp"
    break;

  case 102: /* eval_target: KW_ASCEND  */
#line 529 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("ASCEND"); }
#line 3830 "build/parser.cpp"
    break;

  case 103: /* eval_target: KW_DESCEND  */
#line 530 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("DESCEND"); }
#line 3836 "build/parser.cpp"
    break;

  case 104: /* eval_target: KW_RTNPARM  */
#line 531 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("RTNPARM"); }
#line 3842 "build/parser.cpp"
    break;

  case 105: /* eval_target: KW_OPDESC  */
#line 532 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("OPDESC"); }
#line 3848 "build/parser.cpp"
    break;

  case 106: /* eval_target: KW_NULLIND  */
#line 533 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("NULLIND"); }
#line 3854 "build/parser.cpp"
    break;

  case 107: /* eval_target: KW_DATFMT  */
#line 534 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("DATFMT"); }
#line 3860 "build/parser.cpp"
    break;

  case 108: /* eval_target: KW_TIMFMT  */
#line 535 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("TIMFMT"); }
#line 3866 "build/parser.cpp"
    break;

  case 109: /* eval_target: KW_EXTNAME  */
#line 536 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("EXTNAME"); }
#line 3872 "build/parser.cpp"
    break;

  case 110: /* eval_target: INDICATOR  */
#line 537 "src/parser.y"
                {
        (yyval.expr) = new rpg::IndicatorExpr((yyvsp[0].ival));
    }
#line 3880 "build/parser.cpp"
    break;

  case 111: /* eval_target: IDENTIFIER DOT IDENTIFIER  */
#line 540 "src/parser.y"
                                {
        auto obj = std::unique_ptr<rpg::Expression>(new rpg::Identifier((yyvsp[-2].sval)));
        (yyval.expr) = new rpg::DotExpr(std::move(obj), (yyvsp[0].sval));
        free((yyvsp[-2].sval));
        free((yyvsp[0].sval));
    }
#line 3891 "build/parser.cpp"
    break;

  case 112: /* eval_target: IDENTIFIER LPAREN expression RPAREN  */
#line 546 "src/parser.y"
                                          {
        (yyval.expr) = new rpg::ArrayAccess((yyvsp[-3].sval), std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
        free((yyvsp[-3].sval));
    }
#line 3900 "build/parser.cpp"
    break;

  case 113: /* eval_target: IDENTIFIER LPAREN expression RPAREN DOT IDENTIFIER  */
#line 550 "src/parser.y"
                                                         {
        auto* arr = new rpg::ArrayAccess((yyvsp[-5].sval), std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)));
        (yyval.expr) = new rpg::DotExpr(std::unique_ptr<rpg::Expression>(arr), (yyvsp[0].sval));
        free((yyvsp[-5].sval));
        free((yyvsp[0].sval));
    }
#line 3911 "build/parser.cpp"
    break;

  case 114: /* eval_target: BIF_ELEM LPAREN arg_list RPAREN  */
#line 556 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("ELEM", (yyvsp[-1].expr_list));
    }
#line 3919 "build/parser.cpp"
    break;

  case 115: /* eval_stmt: eval_target EQUALS expression SEMICOLON  */
#line 562 "src/parser.y"
                                            {
        (yyval.stmt) = new rpg::EvalStmt(
            std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-1].expr))
        );
    }
#line 3930 "build/parser.cpp"
    break;

  case 116: /* eval_stmt: KW_EVAL eval_target EQUALS expression SEMICOLON  */
#line 568 "src/parser.y"
                                                      {
        (yyval.stmt) = new rpg::EvalStmt(
            std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-1].expr))
        );
    }
#line 3941 "build/parser.cpp"
    break;

  case 117: /* eval_corr_stmt: KW_EVAL_CORR ident EQUALS ident SEMICOLON  */
#line 577 "src/parser.y"
                                              {
        (yyval.stmt) = new rpg::EvalCorrStmt(std::string((yyvsp[-3].sval)), std::string((yyvsp[-1].sval)));
        free((yyvsp[-3].sval));
        free((yyvsp[-1].sval));
    }
#line 3951 "build/parser.cpp"
    break;

  case 118: /* evalr_stmt: KW_EVALR eval_target EQUALS expression SEMICOLON  */
#line 585 "src/parser.y"
                                                     {
        (yyval.stmt) = new rpg::EvalRStmt(
            std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-1].expr))
        );
    }
#line 3962 "build/parser.cpp"
    break;

  case 119: /* callp_stmt: KW_CALLP expression SEMICOLON  */
#line 594 "src/parser.y"
                                  {
        (yyval.stmt) = new rpg::ExprStmt(std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
    }
#line 3970 "build/parser.cpp"
    break;

  case 120: /* leavesr_stmt: KW_LEAVESR SEMICOLON  */
#line 600 "src/parser.y"
                         {
        (yyval.stmt) = new rpg::LeaveSRStmt();
    }
#line 3978 "build/parser.cpp"
    break;

  case 121: /* dsply_stmt: KW_DSPLY expression SEMICOLON  */
#line 606 "src/parser.y"
                                  {
        (yyval.stmt) = new rpg::DsplyStmt(std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
    }
#line 3986 "build/parser.cpp"
    break;

  case 122: /* inlr_stmt: KW_INLR EQUALS KW_ON SEMICOLON  */
#line 612 "src/parser.y"
                                   {
        (yyval.stmt) = new rpg::ReturnStmt(0);
    }
#line 3994 "build/parser.cpp"
    break;

  case 123: /* return_stmt: KW_RETURN expression SEMICOLON  */
#line 618 "src/parser.y"
                                   {
        (yyval.stmt) = new rpg::ReturnStmt(std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
    }
#line 4002 "build/parser.cpp"
    break;

  case 124: /* return_stmt: KW_RETURN SEMICOLON  */
#line 621 "src/parser.y"
                          {
        (yyval.stmt) = new rpg::ReturnStmt(0);
    }
#line 4010 "build/parser.cpp"
    break;

  case 125: /* expr_stmt: IDENTIFIER LPAREN call_args_opt RPAREN SEMICOLON  */
#line 628 "src/parser.y"
                                                     {
        auto* fc = make_func((yyvsp[-4].sval), (yyvsp[-2].expr_list));
        free((yyvsp[-4].sval));
        (yyval.stmt) = new rpg::ExprStmt(std::unique_ptr<rpg::Expression>(fc));
    }
#line 4020 "build/parser.cpp"
    break;

  case 126: /* dcl_pr_stmt: KW_DCL_PR IDENTIFIER pi_return_type SEMICOLON pr_params KW_END_PR SEMICOLON  */
#line 639 "src/parser.y"
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
#line 4041 "build/parser.cpp"
    break;

  case 127: /* dcl_pr_stmt: KW_DCL_PR IDENTIFIER pi_return_type KW_EXTPROC LPAREN STRING_LITERAL RPAREN SEMICOLON pr_params KW_END_PR SEMICOLON  */
#line 656 "src/parser.y"
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
#line 4065 "build/parser.cpp"
    break;

  case 128: /* dcl_pr_stmt: KW_DCL_PR IDENTIFIER KW_EXTPGM LPAREN STRING_LITERAL RPAREN SEMICOLON pr_params KW_END_PR SEMICOLON  */
#line 676 "src/parser.y"
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
#line 4081 "build/parser.cpp"
    break;

  case 129: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER proc_export SEMICOLON KW_DCL_PI pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 694 "src/parser.y"
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
#line 4106 "build/parser.cpp"
    break;

  case 130: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER proc_export SEMICOLON KW_DCL_PI IDENTIFIER pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 718 "src/parser.y"
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
#line 4132 "build/parser.cpp"
    break;

  case 131: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER proc_export SEMICOLON KW_DCL_PI pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_ON_EXIT SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 744 "src/parser.y"
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
#line 4159 "build/parser.cpp"
    break;

  case 132: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER proc_export SEMICOLON KW_DCL_PI IDENTIFIER pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_ON_EXIT SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 771 "src/parser.y"
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
#line 4187 "build/parser.cpp"
    break;

  case 133: /* proc_export: %empty  */
#line 797 "src/parser.y"
                { (yyval.ival) = 0; }
#line 4193 "build/parser.cpp"
    break;

  case 134: /* proc_export: KW_EXPORT  */
#line 798 "src/parser.y"
                { (yyval.ival) = 1; }
#line 4199 "build/parser.cpp"
    break;

  case 135: /* pi_return_type: %empty  */
#line 803 "src/parser.y"
               { (yyval.ival) = -1; }
#line 4205 "build/parser.cpp"
    break;

  case 136: /* pi_return_type: KW_INT LPAREN INTEGER_LITERAL RPAREN  */
#line 804 "src/parser.y"
                                           { (yyval.ival) = (int)rpg::RPGType::INT10; }
#line 4211 "build/parser.cpp"
    break;

  case 137: /* pi_return_type: KW_CHAR LPAREN INTEGER_LITERAL RPAREN  */
#line 805 "src/parser.y"
                                            { (yyval.ival) = (int)rpg::RPGType::CHAR; }
#line 4217 "build/parser.cpp"
    break;

  case 138: /* pi_return_type: KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN  */
#line 806 "src/parser.y"
                                               { (yyval.ival) = (int)rpg::RPGType::VARCHAR; }
#line 4223 "build/parser.cpp"
    break;

  case 139: /* pi_return_type: KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN  */
#line 807 "src/parser.y"
                                                                    { (yyval.ival) = (int)rpg::RPGType::PACKED; }
#line 4229 "build/parser.cpp"
    break;

  case 140: /* pi_params: %empty  */
#line 812 "src/parser.y"
                {
        (yyval.param_list) = new ParamList();
    }
#line 4237 "build/parser.cpp"
    break;

  case 141: /* pi_params: pi_params pi_param  */
#line 815 "src/parser.y"
                         {
        (yyval.param_list) = (yyvsp[-1].param_list);
        (yyval.param_list)->params.push_back(*(yyvsp[0].param_decl));
        delete (yyvsp[0].param_decl);
    }
#line 4247 "build/parser.cpp"
    break;

  case 142: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 823 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4256 "build/parser.cpp"
    break;

  case 143: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 827 "src/parser.y"
                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4265 "build/parser.cpp"
    break;

  case 144: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 831 "src/parser.y"
                                                                 {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4274 "build/parser.cpp"
    break;

  case 145: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 835 "src/parser.y"
                                                                          {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4283 "build/parser.cpp"
    break;

  case 146: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 839 "src/parser.y"
                                                                    {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4292 "build/parser.cpp"
    break;

  case 147: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 843 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4301 "build/parser.cpp"
    break;

  case 148: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 847 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 4310 "build/parser.cpp"
    break;

  case 149: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 851 "src/parser.y"
                                                                                                  {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 4319 "build/parser.cpp"
    break;

  case 150: /* pi_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 856 "src/parser.y"
                                                                            {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4328 "build/parser.cpp"
    break;

  case 151: /* pi_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 860 "src/parser.y"
                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4337 "build/parser.cpp"
    break;

  case 152: /* pi_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 864 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4346 "build/parser.cpp"
    break;

  case 153: /* pi_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 868 "src/parser.y"
                                                                                      {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4355 "build/parser.cpp"
    break;

  case 154: /* pi_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 872 "src/parser.y"
                                                                                {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4364 "build/parser.cpp"
    break;

  case 155: /* pi_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 876 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4373 "build/parser.cpp"
    break;

  case 156: /* pi_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 880 "src/parser.y"
                                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 4382 "build/parser.cpp"
    break;

  case 157: /* pi_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 884 "src/parser.y"
                                                                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 4391 "build/parser.cpp"
    break;

  case 158: /* pi_param: IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 888 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, 0, 0, 0, false, std::string((yyvsp[-2].sval))};
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
    }
#line 4401 "build/parser.cpp"
    break;

  case 159: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 894 "src/parser.y"
                                                                                                            {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4411 "build/parser.cpp"
    break;

  case 160: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 899 "src/parser.y"
                                                                                                             {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4421 "build/parser.cpp"
    break;

  case 161: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 904 "src/parser.y"
                                                                                                                {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::VARCHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4431 "build/parser.cpp"
    break;

  case 162: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 909 "src/parser.y"
                                                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-12].sval), rpg::RPGType::PACKED, 0, (yyvsp[-9].ival), (yyvsp[-7].ival), true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-12].sval));
    }
#line 4441 "build/parser.cpp"
    break;

  case 163: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 915 "src/parser.y"
                                                                                                 {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4451 "build/parser.cpp"
    break;

  case 164: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 920 "src/parser.y"
                                                                                                  {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4461 "build/parser.cpp"
    break;

  case 165: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 925 "src/parser.y"
                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4471 "build/parser.cpp"
    break;

  case 166: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 930 "src/parser.y"
                                                                                                                          {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4481 "build/parser.cpp"
    break;

  case 167: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 936 "src/parser.y"
                                                                                                                 {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4491 "build/parser.cpp"
    break;

  case 168: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 941 "src/parser.y"
                                                                                                                  {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::CHAR, (yyvsp[-8].ival), 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4501 "build/parser.cpp"
    break;

  case 169: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 946 "src/parser.y"
                                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::VARCHAR, (yyvsp[-8].ival), 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4511 "build/parser.cpp"
    break;

  case 170: /* pr_params: %empty  */
#line 955 "src/parser.y"
                {
        (yyval.param_list) = new ParamList();
    }
#line 4519 "build/parser.cpp"
    break;

  case 171: /* pr_params: pr_params pr_param  */
#line 958 "src/parser.y"
                         {
        (yyval.param_list) = (yyvsp[-1].param_list);
        (yyval.param_list)->params.push_back(*(yyvsp[0].param_decl));
        delete (yyvsp[0].param_decl);
    }
#line 4529 "build/parser.cpp"
    break;

  case 172: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 966 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4538 "build/parser.cpp"
    break;

  case 173: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 970 "src/parser.y"
                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4547 "build/parser.cpp"
    break;

  case 174: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 974 "src/parser.y"
                                                                 {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4556 "build/parser.cpp"
    break;

  case 175: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 978 "src/parser.y"
                                                                          {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4565 "build/parser.cpp"
    break;

  case 176: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 982 "src/parser.y"
                                                                    {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4574 "build/parser.cpp"
    break;

  case 177: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 986 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4583 "build/parser.cpp"
    break;

  case 178: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 990 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 4592 "build/parser.cpp"
    break;

  case 179: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 994 "src/parser.y"
                                                                                                  {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 4601 "build/parser.cpp"
    break;

  case 180: /* pr_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 999 "src/parser.y"
                                                                            {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4610 "build/parser.cpp"
    break;

  case 181: /* pr_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1003 "src/parser.y"
                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4619 "build/parser.cpp"
    break;

  case 182: /* pr_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1007 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4628 "build/parser.cpp"
    break;

  case 183: /* pr_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1011 "src/parser.y"
                                                                                      {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4637 "build/parser.cpp"
    break;

  case 184: /* pr_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1015 "src/parser.y"
                                                                                {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4646 "build/parser.cpp"
    break;

  case 185: /* pr_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1019 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4655 "build/parser.cpp"
    break;

  case 186: /* pr_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1023 "src/parser.y"
                                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 4664 "build/parser.cpp"
    break;

  case 187: /* pr_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1027 "src/parser.y"
                                                                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 4673 "build/parser.cpp"
    break;

  case 188: /* pr_param: IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1031 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, 0, 0, 0, false, std::string((yyvsp[-2].sval))};
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
    }
#line 4683 "build/parser.cpp"
    break;

  case 189: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1037 "src/parser.y"
                                                                                                            {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4693 "build/parser.cpp"
    break;

  case 190: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1042 "src/parser.y"
                                                                                                             {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4703 "build/parser.cpp"
    break;

  case 191: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1047 "src/parser.y"
                                                                                                                {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::VARCHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4713 "build/parser.cpp"
    break;

  case 192: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1052 "src/parser.y"
                                                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-12].sval), rpg::RPGType::PACKED, 0, (yyvsp[-9].ival), (yyvsp[-7].ival), true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-12].sval));
    }
#line 4723 "build/parser.cpp"
    break;

  case 193: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1058 "src/parser.y"
                                                                                                 {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4733 "build/parser.cpp"
    break;

  case 194: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1063 "src/parser.y"
                                                                                                  {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4743 "build/parser.cpp"
    break;

  case 195: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1068 "src/parser.y"
                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4753 "build/parser.cpp"
    break;

  case 196: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1073 "src/parser.y"
                                                                                                                          {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4763 "build/parser.cpp"
    break;

  case 197: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 1079 "src/parser.y"
                                                                                                                 {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4773 "build/parser.cpp"
    break;

  case 198: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 1084 "src/parser.y"
                                                                                                                  {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::CHAR, (yyvsp[-8].ival), 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4783 "build/parser.cpp"
    break;

  case 199: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 1089 "src/parser.y"
                                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::VARCHAR, (yyvsp[-8].ival), 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4793 "build/parser.cpp"
    break;

  case 200: /* monitor_stmt: KW_MONITOR SEMICOLON statement_list KW_ON_ERROR SEMICOLON statement_list KW_ENDMON SEMICOLON  */
#line 1099 "src/parser.y"
                                                                                                 {
        auto* node = new rpg::MonitorStmt();
        for (auto* s : (yyvsp[-5].stmt_list)->stmts) node->try_body.emplace_back(s);
        delete (yyvsp[-5].stmt_list);
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->on_error_body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        (yyval.stmt) = node;
    }
#line 4806 "build/parser.cpp"
    break;

  case 201: /* begsr_stmt: KW_BEGSR IDENTIFIER SEMICOLON statement_list KW_ENDSR SEMICOLON  */
#line 1110 "src/parser.y"
                                                                    {
        auto* node = new rpg::BegSR((yyvsp[-4].sval));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        free((yyvsp[-4].sval));
        (yyval.stmt) = node;
    }
#line 4818 "build/parser.cpp"
    break;

  case 202: /* exsr_stmt: KW_EXSR ident SEMICOLON  */
#line 1120 "src/parser.y"
                            {
        (yyval.stmt) = new rpg::ExSR((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4827 "build/parser.cpp"
    break;

  case 203: /* sorta_stmt: KW_SORTA ident SEMICOLON  */
#line 1128 "src/parser.y"
                             {
        (yyval.stmt) = new rpg::SortAStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4836 "build/parser.cpp"
    break;

  case 204: /* reset_stmt: KW_RESET ident SEMICOLON  */
#line 1136 "src/parser.y"
                             {
        (yyval.stmt) = new rpg::ResetStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4845 "build/parser.cpp"
    break;

  case 205: /* clear_stmt: KW_CLEAR ident SEMICOLON  */
#line 1143 "src/parser.y"
                             {
        (yyval.stmt) = new rpg::ClearStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4854 "build/parser.cpp"
    break;

  case 206: /* dealloc_stmt: KW_DEALLOC ident SEMICOLON  */
#line 1151 "src/parser.y"
                               {
        (yyval.stmt) = new rpg::DeallocStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4863 "build/parser.cpp"
    break;

  case 207: /* test_stmt: KW_TEST LPAREN ident RPAREN ident SEMICOLON  */
#line 1159 "src/parser.y"
                                                {
        char type = toupper((yyvsp[-3].sval)[0]);
        (yyval.stmt) = new rpg::TestStmt(type, std::string((yyvsp[-1].sval)));
        free((yyvsp[-3].sval));
        free((yyvsp[-1].sval));
    }
#line 4874 "build/parser.cpp"
    break;

  case 208: /* dcl_enum_stmt: KW_DCL_ENUM IDENTIFIER KW_QUALIFIED SEMICOLON enum_constants KW_END_ENUM SEMICOLON  */
#line 1170 "src/parser.y"
                                                                                       {
        auto* e = new rpg::DclEnum((yyvsp[-5].sval));
        e->qualified = true;
        e->constants = std::move(*(yyvsp[-2].enum_const_list));
        delete (yyvsp[-2].enum_const_list);
        free((yyvsp[-5].sval));
        (yyval.stmt) = e;
    }
#line 4887 "build/parser.cpp"
    break;

  case 209: /* dcl_enum_stmt: KW_DCL_ENUM IDENTIFIER SEMICOLON enum_constants KW_END_ENUM SEMICOLON  */
#line 1178 "src/parser.y"
                                                                            {
        auto* e = new rpg::DclEnum((yyvsp[-4].sval));
        e->qualified = false;
        e->constants = std::move(*(yyvsp[-2].enum_const_list));
        delete (yyvsp[-2].enum_const_list);
        free((yyvsp[-4].sval));
        (yyval.stmt) = e;
    }
#line 4900 "build/parser.cpp"
    break;

  case 210: /* enum_constants: enum_constant  */
#line 1189 "src/parser.y"
                  {
        (yyval.enum_const_list) = (yyvsp[0].enum_const_list);
    }
#line 4908 "build/parser.cpp"
    break;

  case 211: /* enum_constants: enum_constants enum_constant  */
#line 1192 "src/parser.y"
                                   {
        (yyvsp[-1].enum_const_list)->insert((yyvsp[-1].enum_const_list)->end(), std::make_move_iterator((yyvsp[0].enum_const_list)->begin()), std::make_move_iterator((yyvsp[0].enum_const_list)->end()));
        delete (yyvsp[0].enum_const_list);
        (yyval.enum_const_list) = (yyvsp[-1].enum_const_list);
    }
#line 4918 "build/parser.cpp"
    break;

  case 212: /* enum_constant: IDENTIFIER SEMICOLON  */
#line 1200 "src/parser.y"
                         {
        auto* v = new std::vector<rpg::EnumConstant>();
        rpg::EnumConstant ec;
        ec.name = (yyvsp[-1].sval);
        free((yyvsp[-1].sval));
        v->push_back(std::move(ec));
        (yyval.enum_const_list) = v;
    }
#line 4931 "build/parser.cpp"
    break;

  case 213: /* enum_constant: IDENTIFIER EQUALS expression SEMICOLON  */
#line 1208 "src/parser.y"
                                             {
        auto* v = new std::vector<rpg::EnumConstant>();
        rpg::EnumConstant ec;
        ec.name = (yyvsp[-3].sval);
        ec.value.reset((yyvsp[-1].expr));
        free((yyvsp[-3].sval));
        v->push_back(std::move(ec));
        (yyval.enum_const_list) = v;
    }
#line 4945 "build/parser.cpp"
    break;

  case 214: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1223 "src/parser.y"
                                                                              {
        auto* ds = new rpg::DclDS((yyvsp[-5].sval));
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-5].sval));
        (yyval.stmt) = ds;
    }
#line 4958 "build/parser.cpp"
    break;

  case 215: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1232 "src/parser.y"
                                                                   {
        auto* ds = new rpg::DclDS((yyvsp[-4].sval));
        ds->qualified = false;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-4].sval));
        (yyval.stmt) = ds;
    }
#line 4971 "build/parser.cpp"
    break;

  case 216: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1241 "src/parser.y"
                                                                                                                     {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->dim = (yyvsp[-6].ival);
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-9].sval));
        (yyval.stmt) = ds;
    }
#line 4985 "build/parser.cpp"
    break;

  case 217: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1251 "src/parser.y"
                                                                                                                     {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->dim = (yyvsp[-5].ival);
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-9].sval));
        (yyval.stmt) = ds;
    }
#line 4999 "build/parser.cpp"
    break;

  case 218: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_DIM LPAREN KW_DIM_VAR COLON INTEGER_LITERAL RPAREN KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1261 "src/parser.y"
                                                                                                                                      {
        auto* ds = new rpg::DclDS((yyvsp[-11].sval));
        ds->dim = (yyvsp[-6].ival);
        ds->dim_type = 1;
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-11].sval));
        (yyval.stmt) = ds;
    }
#line 5014 "build/parser.cpp"
    break;

  case 219: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_DIM LPAREN KW_DIM_VAR COLON INTEGER_LITERAL RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1272 "src/parser.y"
                                                                                                                                      {
        auto* ds = new rpg::DclDS((yyvsp[-11].sval));
        ds->dim = (yyvsp[-5].ival);
        ds->dim_type = 1;
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-11].sval));
        (yyval.stmt) = ds;
    }
#line 5029 "build/parser.cpp"
    break;

  case 220: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_DIM LPAREN KW_DIM_AUTO COLON INTEGER_LITERAL RPAREN KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1283 "src/parser.y"
                                                                                                                                       {
        auto* ds = new rpg::DclDS((yyvsp[-11].sval));
        ds->dim = (yyvsp[-6].ival);
        ds->dim_type = 2;
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-11].sval));
        (yyval.stmt) = ds;
    }
#line 5044 "build/parser.cpp"
    break;

  case 221: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_DIM LPAREN KW_DIM_AUTO COLON INTEGER_LITERAL RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1294 "src/parser.y"
                                                                                                                                       {
        auto* ds = new rpg::DclDS((yyvsp[-11].sval));
        ds->dim = (yyvsp[-5].ival);
        ds->dim_type = 2;
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-11].sval));
        (yyval.stmt) = ds;
    }
#line 5059 "build/parser.cpp"
    break;

  case 222: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1305 "src/parser.y"
                                                                        {
        auto* ds = new rpg::DclDS((yyvsp[-5].sval));
        ds->like_ds = (yyvsp[-2].sval);
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
        (yyval.stmt) = ds;
    }
#line 5071 "build/parser.cpp"
    break;

  case 223: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1313 "src/parser.y"
                                                                                                             {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->like_ds = (yyvsp[-6].sval);
        ds->dim = (yyvsp[-2].ival);
        free((yyvsp[-9].sval));
        free((yyvsp[-6].sval));
        (yyval.stmt) = ds;
    }
#line 5084 "build/parser.cpp"
    break;

  case 224: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_PREFIX LPAREN IDENTIFIER RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1322 "src/parser.y"
                                                                                                                   {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->qualified = true;
        ds->prefix = (yyvsp[-5].sval);
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-9].sval)); free((yyvsp[-5].sval));
        (yyval.stmt) = ds;
    }
#line 5098 "build/parser.cpp"
    break;

  case 225: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_PREFIX LPAREN IDENTIFIER COLON INTEGER_LITERAL RPAREN KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1332 "src/parser.y"
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
#line 5113 "build/parser.cpp"
    break;

  case 226: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_PREFIX LPAREN IDENTIFIER COLON INTEGER_LITERAL RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1343 "src/parser.y"
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
#line 5128 "build/parser.cpp"
    break;

  case 227: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_PREFIX LPAREN IDENTIFIER RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1354 "src/parser.y"
                                                                                                      {
        auto* ds = new rpg::DclDS((yyvsp[-8].sval));
        ds->qualified = false;
        ds->prefix = (yyvsp[-5].sval);
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-8].sval)); free((yyvsp[-5].sval));
        (yyval.stmt) = ds;
    }
#line 5142 "build/parser.cpp"
    break;

  case 228: /* ds_fields: %empty  */
#line 1366 "src/parser.y"
                {
        (yyval.ds_field_list) = new DSFieldList();
    }
#line 5150 "build/parser.cpp"
    break;

  case 229: /* ds_fields: ds_fields ds_field  */
#line 1369 "src/parser.y"
                         {
        (yyval.ds_field_list) = (yyvsp[-1].ds_field_list);
        (yyval.ds_field_list)->fields.push_back(*(yyvsp[0].ds_field));
        delete (yyvsp[0].ds_field);
    }
#line 5160 "build/parser.cpp"
    break;

  case 230: /* ds_field: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1377 "src/parser.y"
                                                              {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5169 "build/parser.cpp"
    break;

  case 231: /* ds_field: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1381 "src/parser.y"
                                                                 {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5178 "build/parser.cpp"
    break;

  case 232: /* ds_field: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1385 "src/parser.y"
                                                                    {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5187 "build/parser.cpp"
    break;

  case 233: /* ds_field: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1389 "src/parser.y"
                                                                                         {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival)};
        free((yyvsp[-7].sval));
    }
#line 5196 "build/parser.cpp"
    break;

  case 234: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1394 "src/parser.y"
                                                                            {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5205 "build/parser.cpp"
    break;

  case 235: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1398 "src/parser.y"
                                                                             {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5214 "build/parser.cpp"
    break;

  case 236: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1402 "src/parser.y"
                                                                                {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5223 "build/parser.cpp"
    break;

  case 237: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1406 "src/parser.y"
                                                                                                     {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival)};
        free((yyvsp[-7].sval));
    }
#line 5232 "build/parser.cpp"
    break;

  case 238: /* ds_field: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_POS LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1411 "src/parser.y"
                                                                                                      {
        auto* f = new rpg::DSField{(yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0};
        f->pos = (yyvsp[-2].ival);
        free((yyvsp[-9].sval));
        (yyval.ds_field) = f;
    }
#line 5243 "build/parser.cpp"
    break;

  case 239: /* ds_field: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_POS LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1417 "src/parser.y"
                                                                                                     {
        auto* f = new rpg::DSField{(yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0};
        f->pos = (yyvsp[-2].ival);
        free((yyvsp[-9].sval));
        (yyval.ds_field) = f;
    }
#line 5254 "build/parser.cpp"
    break;

  case 240: /* ds_field: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_POS LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1423 "src/parser.y"
                                                                                                                              {
        auto* f = new rpg::DSField{(yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival)};
        f->pos = (yyvsp[-2].ival);
        free((yyvsp[-11].sval));
        (yyval.ds_field) = f;
    }
#line 5265 "build/parser.cpp"
    break;

  case 241: /* ds_field: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OVERLAY LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1430 "src/parser.y"
                                                                                                     {
        auto* f = new rpg::DSField{(yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0};
        f->overlay_field = (yyvsp[-2].sval);
        free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
        (yyval.ds_field) = f;
    }
#line 5276 "build/parser.cpp"
    break;

  case 242: /* ds_field: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OVERLAY LPAREN IDENTIFIER COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1437 "src/parser.y"
                                                                                                                           {
        auto* f = new rpg::DSField{(yyvsp[-11].sval), rpg::RPGType::CHAR, (yyvsp[-8].ival), 0, 0};
        f->overlay_field = (yyvsp[-4].sval);
        f->overlay_pos = (yyvsp[-2].ival);
        free((yyvsp[-11].sval)); free((yyvsp[-4].sval));
        (yyval.ds_field) = f;
    }
#line 5288 "build/parser.cpp"
    break;

  case 243: /* ds_field: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OVERLAY LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1444 "src/parser.y"
                                                                                                    {
        auto* f = new rpg::DSField{(yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0};
        f->overlay_field = (yyvsp[-2].sval);
        free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
        (yyval.ds_field) = f;
    }
#line 5299 "build/parser.cpp"
    break;

  case 244: /* ds_field: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OVERLAY LPAREN IDENTIFIER COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1450 "src/parser.y"
                                                                                                                          {
        auto* f = new rpg::DSField{(yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0};
        f->overlay_field = (yyvsp[-4].sval);
        f->overlay_pos = (yyvsp[-2].ival);
        free((yyvsp[-11].sval)); free((yyvsp[-4].sval));
        (yyval.ds_field) = f;
    }
#line 5311 "build/parser.cpp"
    break;

  case 245: /* if_stmt: KW_IF expression SEMICOLON statement_list elseif_clauses else_clause KW_ENDIF SEMICOLON  */
#line 1462 "src/parser.y"
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
#line 5336 "build/parser.cpp"
    break;

  case 246: /* elseif_clauses: %empty  */
#line 1485 "src/parser.y"
                { (yyval.elseif_list) = nullptr; }
#line 5342 "build/parser.cpp"
    break;

  case 247: /* elseif_clauses: elseif_clauses elseif_clause  */
#line 1486 "src/parser.y"
                                   {
        if (!(yyvsp[-1].elseif_list)) (yyvsp[-1].elseif_list) = new std::vector<ElseIfData*>();
        (yyval.elseif_list) = (yyvsp[-1].elseif_list);
        (yyval.elseif_list)->push_back((yyvsp[0].elseif_data));
    }
#line 5352 "build/parser.cpp"
    break;

  case 248: /* elseif_clause: KW_ELSEIF expression SEMICOLON statement_list  */
#line 1494 "src/parser.y"
                                                  {
        (yyval.elseif_data) = new ElseIfData();
        (yyval.elseif_data)->cond = (yyvsp[-2].expr);
        (yyval.elseif_data)->body = std::move((yyvsp[0].stmt_list)->stmts);
        delete (yyvsp[0].stmt_list);
    }
#line 5363 "build/parser.cpp"
    break;

  case 249: /* else_clause: %empty  */
#line 1503 "src/parser.y"
                { (yyval.stmt_list) = nullptr; }
#line 5369 "build/parser.cpp"
    break;

  case 250: /* else_clause: KW_ELSE SEMICOLON statement_list  */
#line 1504 "src/parser.y"
                                       {
        (yyval.stmt_list) = (yyvsp[0].stmt_list);
    }
#line 5377 "build/parser.cpp"
    break;

  case 251: /* dow_stmt: KW_DOW expression SEMICOLON statement_list KW_ENDDO SEMICOLON  */
#line 1510 "src/parser.y"
                                                                  {
        auto* node = new rpg::DowStmt(std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        (yyval.stmt) = node;
    }
#line 5388 "build/parser.cpp"
    break;

  case 252: /* dou_stmt: KW_DOU expression SEMICOLON statement_list KW_ENDDO SEMICOLON  */
#line 1519 "src/parser.y"
                                                                  {
        auto* node = new rpg::DouStmt(std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        (yyval.stmt) = node;
    }
#line 5399 "build/parser.cpp"
    break;

  case 253: /* for_stmt: KW_FOR ident EQUALS expression KW_TO expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1528 "src/parser.y"
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
#line 5414 "build/parser.cpp"
    break;

  case 254: /* for_stmt: KW_FOR ident EQUALS expression KW_TO expression KW_BY expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1538 "src/parser.y"
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
#line 5429 "build/parser.cpp"
    break;

  case 255: /* for_stmt: KW_FOR ident EQUALS expression KW_DOWNTO expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1548 "src/parser.y"
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
#line 5444 "build/parser.cpp"
    break;

  case 256: /* for_stmt: KW_FOR ident EQUALS expression KW_DOWNTO expression KW_BY expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1558 "src/parser.y"
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
#line 5459 "build/parser.cpp"
    break;

  case 257: /* for_each_stmt: KW_FOR_EACH ident KW_IN expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1571 "src/parser.y"
                                                                                    {
        auto* node = new rpg::ForEachStmt((yyvsp[-6].sval), std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        free((yyvsp[-6].sval));
        (yyval.stmt) = node;
    }
#line 5471 "build/parser.cpp"
    break;

  case 258: /* select_stmt: KW_SELECT SEMICOLON when_clauses other_clause KW_ENDSL SEMICOLON  */
#line 1581 "src/parser.y"
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
#line 5492 "build/parser.cpp"
    break;

  case 259: /* when_clauses: when_clause  */
#line 1600 "src/parser.y"
                {
        (yyval.when_list) = new std::vector<WhenData*>();
        (yyval.when_list)->push_back((yyvsp[0].when_data));
    }
#line 5501 "build/parser.cpp"
    break;

  case 260: /* when_clauses: when_clauses when_clause  */
#line 1604 "src/parser.y"
                               {
        (yyval.when_list) = (yyvsp[-1].when_list);
        (yyval.when_list)->push_back((yyvsp[0].when_data));
    }
#line 5510 "build/parser.cpp"
    break;

  case 261: /* when_clause: KW_WHEN expression SEMICOLON statement_list  */
#line 1611 "src/parser.y"
                                                {
        (yyval.when_data) = new WhenData();
        (yyval.when_data)->cond = (yyvsp[-2].expr);
        (yyval.when_data)->body = std::move((yyvsp[0].stmt_list)->stmts);
        delete (yyvsp[0].stmt_list);
    }
#line 5521 "build/parser.cpp"
    break;

  case 262: /* other_clause: %empty  */
#line 1620 "src/parser.y"
                { (yyval.stmt_list) = nullptr; }
#line 5527 "build/parser.cpp"
    break;

  case 263: /* other_clause: KW_OTHER SEMICOLON statement_list  */
#line 1621 "src/parser.y"
                                        {
        (yyval.stmt_list) = (yyvsp[0].stmt_list);
    }
#line 5535 "build/parser.cpp"
    break;

  case 264: /* iter_stmt: KW_ITER SEMICOLON  */
#line 1627 "src/parser.y"
                      { (yyval.stmt) = new rpg::IterStmt(); }
#line 5541 "build/parser.cpp"
    break;

  case 265: /* leave_stmt: KW_LEAVE SEMICOLON  */
#line 1631 "src/parser.y"
                       { (yyval.stmt) = new rpg::LeaveStmt(); }
#line 5547 "build/parser.cpp"
    break;

  case 266: /* expression: or_expr  */
#line 1637 "src/parser.y"
            { (yyval.expr) = (yyvsp[0].expr); }
#line 5553 "build/parser.cpp"
    break;

  case 267: /* or_expr: and_expr  */
#line 1641 "src/parser.y"
             { (yyval.expr) = (yyvsp[0].expr); }
#line 5559 "build/parser.cpp"
    break;

  case 268: /* or_expr: or_expr KW_OR and_expr  */
#line 1642 "src/parser.y"
                             {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::OR,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5569 "build/parser.cpp"
    break;

  case 269: /* and_expr: not_expr  */
#line 1650 "src/parser.y"
             { (yyval.expr) = (yyvsp[0].expr); }
#line 5575 "build/parser.cpp"
    break;

  case 270: /* and_expr: and_expr KW_AND not_expr  */
#line 1651 "src/parser.y"
                               {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::AND,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5585 "build/parser.cpp"
    break;

  case 271: /* not_expr: comparison_expr  */
#line 1659 "src/parser.y"
                    { (yyval.expr) = (yyvsp[0].expr); }
#line 5591 "build/parser.cpp"
    break;

  case 272: /* not_expr: KW_NOT comparison_expr  */
#line 1660 "src/parser.y"
                             {
        (yyval.expr) = new rpg::NotExpr(std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5599 "build/parser.cpp"
    break;

  case 273: /* comparison_expr: additive_expr  */
#line 1666 "src/parser.y"
                  { (yyval.expr) = (yyvsp[0].expr); }
#line 5605 "build/parser.cpp"
    break;

  case 274: /* comparison_expr: comparison_expr EQUALS additive_expr  */
#line 1667 "src/parser.y"
                                           {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::EQ,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5615 "build/parser.cpp"
    break;

  case 275: /* comparison_expr: comparison_expr NE additive_expr  */
#line 1672 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::NE,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5625 "build/parser.cpp"
    break;

  case 276: /* comparison_expr: comparison_expr LT additive_expr  */
#line 1677 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::LT,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5635 "build/parser.cpp"
    break;

  case 277: /* comparison_expr: comparison_expr GT additive_expr  */
#line 1682 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::GT,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5645 "build/parser.cpp"
    break;

  case 278: /* comparison_expr: comparison_expr LE additive_expr  */
#line 1687 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::LE,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5655 "build/parser.cpp"
    break;

  case 279: /* comparison_expr: comparison_expr GE additive_expr  */
#line 1692 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::GE,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5665 "build/parser.cpp"
    break;

  case 280: /* comparison_expr: additive_expr KW_IN additive_expr  */
#line 1697 "src/parser.y"
                                        {
        (yyval.expr) = new rpg::InExpr(
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5675 "build/parser.cpp"
    break;

  case 281: /* additive_expr: multiplicative_expr  */
#line 1705 "src/parser.y"
                        { (yyval.expr) = (yyvsp[0].expr); }
#line 5681 "build/parser.cpp"
    break;

  case 282: /* additive_expr: additive_expr PLUS multiplicative_expr  */
#line 1706 "src/parser.y"
                                             {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::ADD,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5691 "build/parser.cpp"
    break;

  case 283: /* additive_expr: additive_expr MINUS multiplicative_expr  */
#line 1711 "src/parser.y"
                                              {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::SUB,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5701 "build/parser.cpp"
    break;

  case 284: /* multiplicative_expr: power_expr  */
#line 1719 "src/parser.y"
               { (yyval.expr) = (yyvsp[0].expr); }
#line 5707 "build/parser.cpp"
    break;

  case 285: /* multiplicative_expr: multiplicative_expr STAR power_expr  */
#line 1720 "src/parser.y"
                                          {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::MUL,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5717 "build/parser.cpp"
    break;

  case 286: /* multiplicative_expr: multiplicative_expr SLASH power_expr  */
#line 1725 "src/parser.y"
                                           {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::DIV,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5727 "build/parser.cpp"
    break;

  case 287: /* power_expr: unary_expr  */
#line 1733 "src/parser.y"
               { (yyval.expr) = (yyvsp[0].expr); }
#line 5733 "build/parser.cpp"
    break;

  case 288: /* power_expr: unary_expr POWER power_expr  */
#line 1734 "src/parser.y"
                                  {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::POWER,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5743 "build/parser.cpp"
    break;

  case 289: /* unary_expr: postfix_expr  */
#line 1742 "src/parser.y"
                 { (yyval.expr) = (yyvsp[0].expr); }
#line 5749 "build/parser.cpp"
    break;

  case 290: /* unary_expr: MINUS postfix_expr  */
#line 1743 "src/parser.y"
                         {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::SUB,
            std::unique_ptr<rpg::Expression>(new rpg::IntLiteral(0)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5759 "build/parser.cpp"
    break;

  case 291: /* postfix_expr: primary_expr  */
#line 1751 "src/parser.y"
                 { (yyval.expr) = (yyvsp[0].expr); }
#line 5765 "build/parser.cpp"
    break;

  case 292: /* postfix_expr: postfix_expr DOT IDENTIFIER  */
#line 1752 "src/parser.y"
                                  {
        (yyval.expr) = new rpg::DotExpr(std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)), (yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 5774 "build/parser.cpp"
    break;

  case 293: /* ident: IDENTIFIER  */
#line 1759 "src/parser.y"
               { (yyval.sval) = (yyvsp[0].sval); }
#line 5780 "build/parser.cpp"
    break;

  case 294: /* ident: KW_UNS  */
#line 1760 "src/parser.y"
             { (yyval.sval) = strdup("UNS"); }
#line 5786 "build/parser.cpp"
    break;

  case 295: /* ident: KW_FLOAT_TYPE  */
#line 1761 "src/parser.y"
                    { (yyval.sval) = strdup("FLOAT"); }
#line 5792 "build/parser.cpp"
    break;

  case 296: /* ident: KW_GRAPH  */
#line 1762 "src/parser.y"
               { (yyval.sval) = strdup("GRAPH"); }
#line 5798 "build/parser.cpp"
    break;

  case 297: /* ident: KW_ASCEND  */
#line 1763 "src/parser.y"
                { (yyval.sval) = strdup("ASCEND"); }
#line 5804 "build/parser.cpp"
    break;

  case 298: /* ident: KW_DESCEND  */
#line 1764 "src/parser.y"
                 { (yyval.sval) = strdup("DESCEND"); }
#line 5810 "build/parser.cpp"
    break;

  case 299: /* ident: KW_IN  */
#line 1765 "src/parser.y"
            { (yyval.sval) = strdup("IN"); }
#line 5816 "build/parser.cpp"
    break;

  case 300: /* ident: KW_RTNPARM  */
#line 1766 "src/parser.y"
                 { (yyval.sval) = strdup("RTNPARM"); }
#line 5822 "build/parser.cpp"
    break;

  case 301: /* ident: KW_OPDESC  */
#line 1767 "src/parser.y"
                { (yyval.sval) = strdup("OPDESC"); }
#line 5828 "build/parser.cpp"
    break;

  case 302: /* ident: KW_NULLIND  */
#line 1768 "src/parser.y"
                 { (yyval.sval) = strdup("NULLIND"); }
#line 5834 "build/parser.cpp"
    break;

  case 303: /* ident: KW_DATFMT  */
#line 1769 "src/parser.y"
                { (yyval.sval) = strdup("DATFMT"); }
#line 5840 "build/parser.cpp"
    break;

  case 304: /* ident: KW_TIMFMT  */
#line 1770 "src/parser.y"
                { (yyval.sval) = strdup("TIMFMT"); }
#line 5846 "build/parser.cpp"
    break;

  case 305: /* ident: KW_EXTNAME  */
#line 1771 "src/parser.y"
                 { (yyval.sval) = strdup("EXTNAME"); }
#line 5852 "build/parser.cpp"
    break;

  case 306: /* ident: KW_OVERLAY  */
#line 1772 "src/parser.y"
                 { (yyval.sval) = strdup("OVERLAY"); }
#line 5858 "build/parser.cpp"
    break;

  case 307: /* ident: KW_POS  */
#line 1773 "src/parser.y"
             { (yyval.sval) = strdup("POS"); }
#line 5864 "build/parser.cpp"
    break;

  case 308: /* ident: KW_PREFIX  */
#line 1774 "src/parser.y"
                { (yyval.sval) = strdup("PREFIX"); }
#line 5870 "build/parser.cpp"
    break;

  case 309: /* primary_expr: IDENTIFIER  */
#line 1778 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier((yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 5879 "build/parser.cpp"
    break;

  case 310: /* primary_expr: KW_UNS  */
#line 1782 "src/parser.y"
             { (yyval.expr) = new rpg::Identifier("UNS"); }
#line 5885 "build/parser.cpp"
    break;

  case 311: /* primary_expr: KW_FLOAT_TYPE  */
#line 1783 "src/parser.y"
                    { (yyval.expr) = new rpg::Identifier("FLOAT"); }
#line 5891 "build/parser.cpp"
    break;

  case 312: /* primary_expr: KW_GRAPH  */
#line 1784 "src/parser.y"
               { (yyval.expr) = new rpg::Identifier("GRAPH"); }
#line 5897 "build/parser.cpp"
    break;

  case 313: /* primary_expr: KW_ASCEND  */
#line 1785 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("ASCEND"); }
#line 5903 "build/parser.cpp"
    break;

  case 314: /* primary_expr: KW_DESCEND  */
#line 1786 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("DESCEND"); }
#line 5909 "build/parser.cpp"
    break;

  case 315: /* primary_expr: KW_RTNPARM  */
#line 1787 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("RTNPARM"); }
#line 5915 "build/parser.cpp"
    break;

  case 316: /* primary_expr: KW_OPDESC  */
#line 1788 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("OPDESC"); }
#line 5921 "build/parser.cpp"
    break;

  case 317: /* primary_expr: KW_NULLIND  */
#line 1789 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("NULLIND"); }
#line 5927 "build/parser.cpp"
    break;

  case 318: /* primary_expr: KW_DATFMT  */
#line 1790 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("DATFMT"); }
#line 5933 "build/parser.cpp"
    break;

  case 319: /* primary_expr: KW_OVERLAY  */
#line 1791 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("OVERLAY"); }
#line 5939 "build/parser.cpp"
    break;

  case 320: /* primary_expr: KW_POS  */
#line 1792 "src/parser.y"
             { (yyval.expr) = new rpg::Identifier("POS"); }
#line 5945 "build/parser.cpp"
    break;

  case 321: /* primary_expr: KW_PREFIX  */
#line 1793 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("PREFIX"); }
#line 5951 "build/parser.cpp"
    break;

  case 322: /* primary_expr: KW_TIMFMT  */
#line 1794 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("TIMFMT"); }
#line 5957 "build/parser.cpp"
    break;

  case 323: /* primary_expr: KW_EXTNAME  */
#line 1795 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("EXTNAME"); }
#line 5963 "build/parser.cpp"
    break;

  case 324: /* primary_expr: INTEGER_LITERAL  */
#line 1796 "src/parser.y"
                      {
        (yyval.expr) = new rpg::IntLiteral((yyvsp[0].ival));
    }
#line 5971 "build/parser.cpp"
    break;

  case 325: /* primary_expr: FLOAT_LITERAL  */
#line 1799 "src/parser.y"
                    {
        (yyval.expr) = new rpg::FloatLiteral((yyvsp[0].fval));
    }
#line 5979 "build/parser.cpp"
    break;

  case 326: /* primary_expr: STRING_LITERAL  */
#line 1802 "src/parser.y"
                     {
        (yyval.expr) = new rpg::StringLiteral((yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 5988 "build/parser.cpp"
    break;

  case 327: /* primary_expr: IDENTIFIER LPAREN call_args_opt RPAREN  */
#line 1806 "src/parser.y"
                                             {
        (yyval.expr) = make_func((yyvsp[-3].sval), (yyvsp[-1].expr_list));
        free((yyvsp[-3].sval));
    }
#line 5997 "build/parser.cpp"
    break;

  case 328: /* primary_expr: BIF_CHAR LPAREN arg_list RPAREN  */
#line 1810 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("CHAR", (yyvsp[-1].expr_list));
    }
#line 6005 "build/parser.cpp"
    break;

  case 329: /* primary_expr: BIF_TRIM LPAREN arg_list RPAREN  */
#line 1813 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("TRIM", (yyvsp[-1].expr_list));
    }
#line 6013 "build/parser.cpp"
    break;

  case 330: /* primary_expr: BIF_TRIML LPAREN arg_list RPAREN  */
#line 1816 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("TRIML", (yyvsp[-1].expr_list));
    }
#line 6021 "build/parser.cpp"
    break;

  case 331: /* primary_expr: BIF_TRIMR LPAREN arg_list RPAREN  */
#line 1819 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("TRIMR", (yyvsp[-1].expr_list));
    }
#line 6029 "build/parser.cpp"
    break;

  case 332: /* primary_expr: BIF_LEN LPAREN arg_list RPAREN  */
#line 1822 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("LEN", (yyvsp[-1].expr_list));
    }
#line 6037 "build/parser.cpp"
    break;

  case 333: /* primary_expr: BIF_SUBST LPAREN arg_list RPAREN  */
#line 1825 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("SUBST", (yyvsp[-1].expr_list));
    }
#line 6045 "build/parser.cpp"
    break;

  case 334: /* primary_expr: BIF_SCAN LPAREN arg_list RPAREN  */
#line 1828 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("SCAN", (yyvsp[-1].expr_list));
    }
#line 6053 "build/parser.cpp"
    break;

  case 335: /* primary_expr: BIF_SCANRPL LPAREN arg_list RPAREN  */
#line 1831 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("SCANRPL", (yyvsp[-1].expr_list));
    }
#line 6061 "build/parser.cpp"
    break;

  case 336: /* primary_expr: BIF_XLATE LPAREN arg_list RPAREN  */
#line 1834 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("XLATE", (yyvsp[-1].expr_list));
    }
#line 6069 "build/parser.cpp"
    break;

  case 337: /* primary_expr: BIF_DEC LPAREN arg_list RPAREN  */
#line 1837 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("DEC", (yyvsp[-1].expr_list));
    }
#line 6077 "build/parser.cpp"
    break;

  case 338: /* primary_expr: BIF_INT LPAREN arg_list RPAREN  */
#line 1840 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("INT", (yyvsp[-1].expr_list));
    }
#line 6085 "build/parser.cpp"
    break;

  case 339: /* primary_expr: BIF_ELEM LPAREN arg_list RPAREN  */
#line 1843 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("ELEM", (yyvsp[-1].expr_list));
    }
#line 6093 "build/parser.cpp"
    break;

  case 340: /* primary_expr: BIF_PARMS LPAREN RPAREN  */
#line 1846 "src/parser.y"
                              {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("PARMS", empty);
    }
#line 6102 "build/parser.cpp"
    break;

  case 341: /* primary_expr: BIF_LOOKUP LPAREN arg_list RPAREN  */
#line 1850 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("LOOKUP", (yyvsp[-1].expr_list));
    }
#line 6110 "build/parser.cpp"
    break;

  case 342: /* primary_expr: BIF_EDITC LPAREN arg_list RPAREN  */
#line 1853 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("EDITC", (yyvsp[-1].expr_list));
    }
#line 6118 "build/parser.cpp"
    break;

  case 343: /* primary_expr: BIF_EDITW LPAREN arg_list RPAREN  */
#line 1856 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("EDITW", (yyvsp[-1].expr_list));
    }
#line 6126 "build/parser.cpp"
    break;

  case 344: /* primary_expr: BIF_REPLACE LPAREN arg_list RPAREN  */
#line 1859 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("REPLACE", (yyvsp[-1].expr_list));
    }
#line 6134 "build/parser.cpp"
    break;

  case 345: /* primary_expr: BIF_CHECK LPAREN arg_list RPAREN  */
#line 1862 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("CHECK", (yyvsp[-1].expr_list));
    }
#line 6142 "build/parser.cpp"
    break;

  case 346: /* primary_expr: BIF_CHECKR LPAREN arg_list RPAREN  */
#line 1865 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("CHECKR", (yyvsp[-1].expr_list));
    }
#line 6150 "build/parser.cpp"
    break;

  case 347: /* primary_expr: BIF_LOWER LPAREN arg_list RPAREN  */
#line 1868 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("LOWER", (yyvsp[-1].expr_list));
    }
#line 6158 "build/parser.cpp"
    break;

  case 348: /* primary_expr: BIF_UPPER LPAREN arg_list RPAREN  */
#line 1871 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("UPPER", (yyvsp[-1].expr_list));
    }
#line 6166 "build/parser.cpp"
    break;

  case 349: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_YEARS RPAREN  */
#line 1874 "src/parser.y"
                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("YEARS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6177 "build/parser.cpp"
    break;

  case 350: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_MONTHS RPAREN  */
#line 1880 "src/parser.y"
                                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MONTHS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6188 "build/parser.cpp"
    break;

  case 351: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_DAYS RPAREN  */
#line 1886 "src/parser.y"
                                                       {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("DAYS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6199 "build/parser.cpp"
    break;

  case 352: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_HOURS RPAREN  */
#line 1892 "src/parser.y"
                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("HOURS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6210 "build/parser.cpp"
    break;

  case 353: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_MINUTES RPAREN  */
#line 1898 "src/parser.y"
                                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MINUTES"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6221 "build/parser.cpp"
    break;

  case 354: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_SECONDS RPAREN  */
#line 1904 "src/parser.y"
                                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("SECONDS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6232 "build/parser.cpp"
    break;

  case 355: /* primary_expr: BIF_FLOAT LPAREN arg_list RPAREN  */
#line 1910 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("FLOAT", (yyvsp[-1].expr_list));
    }
#line 6240 "build/parser.cpp"
    break;

  case 356: /* primary_expr: BIF_SQRT LPAREN arg_list RPAREN  */
#line 1913 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("SQRT", (yyvsp[-1].expr_list));
    }
#line 6248 "build/parser.cpp"
    break;

  case 357: /* primary_expr: BIF_MAX LPAREN arg_list RPAREN  */
#line 1916 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("MAX", (yyvsp[-1].expr_list));
    }
#line 6256 "build/parser.cpp"
    break;

  case 358: /* primary_expr: BIF_MIN LPAREN arg_list RPAREN  */
#line 1919 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("MIN", (yyvsp[-1].expr_list));
    }
#line 6264 "build/parser.cpp"
    break;

  case 359: /* primary_expr: BIF_STATUS LPAREN RPAREN  */
#line 1922 "src/parser.y"
                               {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("STATUS", empty);
    }
#line 6273 "build/parser.cpp"
    break;

  case 360: /* primary_expr: BIF_ERROR LPAREN RPAREN  */
#line 1926 "src/parser.y"
                              {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("ERROR", empty);
    }
#line 6282 "build/parser.cpp"
    break;

  case 361: /* primary_expr: BIF_SIZE LPAREN arg_list RPAREN  */
#line 1930 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("SIZE", (yyvsp[-1].expr_list));
    }
#line 6290 "build/parser.cpp"
    break;

  case 362: /* primary_expr: BIF_ADDR LPAREN arg_list RPAREN  */
#line 1933 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("ADDR", (yyvsp[-1].expr_list));
    }
#line 6298 "build/parser.cpp"
    break;

  case 363: /* primary_expr: BIF_ABS LPAREN arg_list RPAREN  */
#line 1936 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("ABS", (yyvsp[-1].expr_list));
    }
#line 6306 "build/parser.cpp"
    break;

  case 364: /* primary_expr: BIF_DIV LPAREN arg_list RPAREN  */
#line 1939 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("DIV", (yyvsp[-1].expr_list));
    }
#line 6314 "build/parser.cpp"
    break;

  case 365: /* primary_expr: BIF_REM LPAREN arg_list RPAREN  */
#line 1942 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("REM", (yyvsp[-1].expr_list));
    }
#line 6322 "build/parser.cpp"
    break;

  case 366: /* primary_expr: BIF_DATE LPAREN arg_list RPAREN  */
#line 1945 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("DATE", (yyvsp[-1].expr_list));
    }
#line 6330 "build/parser.cpp"
    break;

  case 367: /* primary_expr: BIF_DATE LPAREN RPAREN  */
#line 1948 "src/parser.y"
                             {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("DATE", empty);
    }
#line 6339 "build/parser.cpp"
    break;

  case 368: /* primary_expr: BIF_TIME LPAREN arg_list RPAREN  */
#line 1952 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("TIME", (yyvsp[-1].expr_list));
    }
#line 6347 "build/parser.cpp"
    break;

  case 369: /* primary_expr: BIF_TIME LPAREN RPAREN  */
#line 1955 "src/parser.y"
                             {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("TIME", empty);
    }
#line 6356 "build/parser.cpp"
    break;

  case 370: /* primary_expr: BIF_TIMESTAMP LPAREN arg_list RPAREN  */
#line 1959 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TIMESTAMP", (yyvsp[-1].expr_list));
    }
#line 6364 "build/parser.cpp"
    break;

  case 371: /* primary_expr: BIF_TIMESTAMP LPAREN RPAREN  */
#line 1962 "src/parser.y"
                                  {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("TIMESTAMP", empty);
    }
#line 6373 "build/parser.cpp"
    break;

  case 372: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_DAYS RPAREN  */
#line 1966 "src/parser.y"
                                                                       {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("DAYS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 6385 "build/parser.cpp"
    break;

  case 373: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_MONTHS RPAREN  */
#line 1973 "src/parser.y"
                                                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MONTHS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 6397 "build/parser.cpp"
    break;

  case 374: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_YEARS RPAREN  */
#line 1980 "src/parser.y"
                                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("YEARS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 6409 "build/parser.cpp"
    break;

  case 375: /* primary_expr: BIF_DAYS LPAREN expression RPAREN  */
#line 1987 "src/parser.y"
                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("DAYS", args);
    }
#line 6419 "build/parser.cpp"
    break;

  case 376: /* primary_expr: BIF_MONTHS LPAREN expression RPAREN  */
#line 1992 "src/parser.y"
                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("MONTHS", args);
    }
#line 6429 "build/parser.cpp"
    break;

  case 377: /* primary_expr: BIF_YEARS LPAREN expression RPAREN  */
#line 1997 "src/parser.y"
                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("YEARS", args);
    }
#line 6439 "build/parser.cpp"
    break;

  case 378: /* primary_expr: BIF_FOUND LPAREN RPAREN  */
#line 2002 "src/parser.y"
                              {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("FOUND", empty);
    }
#line 6448 "build/parser.cpp"
    break;

  case 379: /* primary_expr: BIF_EOF LPAREN RPAREN  */
#line 2006 "src/parser.y"
                            {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("EOF", empty);
    }
#line 6457 "build/parser.cpp"
    break;

  case 380: /* primary_expr: BIF_ALLOC LPAREN arg_list RPAREN  */
#line 2010 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("ALLOC", (yyvsp[-1].expr_list));
    }
#line 6465 "build/parser.cpp"
    break;

  case 381: /* primary_expr: BIF_REALLOC LPAREN arg_list RPAREN  */
#line 2013 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("REALLOC", (yyvsp[-1].expr_list));
    }
#line 6473 "build/parser.cpp"
    break;

  case 382: /* primary_expr: BIF_XFOOT LPAREN arg_list RPAREN  */
#line 2016 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("XFOOT", (yyvsp[-1].expr_list));
    }
#line 6481 "build/parser.cpp"
    break;

  case 383: /* primary_expr: BIF_UNS LPAREN arg_list RPAREN  */
#line 2019 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("UNS", (yyvsp[-1].expr_list));
    }
#line 6489 "build/parser.cpp"
    break;

  case 384: /* primary_expr: BIF_INTH LPAREN arg_list RPAREN  */
#line 2022 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("INTH", (yyvsp[-1].expr_list));
    }
#line 6497 "build/parser.cpp"
    break;

  case 385: /* primary_expr: BIF_DECH LPAREN arg_list RPAREN  */
#line 2025 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("DECH", (yyvsp[-1].expr_list));
    }
#line 6505 "build/parser.cpp"
    break;

  case 386: /* primary_expr: BIF_DECPOS LPAREN arg_list RPAREN  */
#line 2028 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("DECPOS", (yyvsp[-1].expr_list));
    }
#line 6513 "build/parser.cpp"
    break;

  case 387: /* primary_expr: BIF_SPLIT LPAREN arg_list RPAREN  */
#line 2031 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("SPLIT", (yyvsp[-1].expr_list));
    }
#line 6521 "build/parser.cpp"
    break;

  case 388: /* primary_expr: BIF_CONCAT LPAREN arg_list RPAREN  */
#line 2034 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("CONCAT", (yyvsp[-1].expr_list));
    }
#line 6529 "build/parser.cpp"
    break;

  case 389: /* primary_expr: BIF_CONCATARR LPAREN arg_list RPAREN  */
#line 2037 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("CONCATARR", (yyvsp[-1].expr_list));
    }
#line 6537 "build/parser.cpp"
    break;

  case 390: /* primary_expr: BIF_LEFT LPAREN arg_list RPAREN  */
#line 2040 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("LEFT", (yyvsp[-1].expr_list));
    }
#line 6545 "build/parser.cpp"
    break;

  case 391: /* primary_expr: BIF_RIGHT LPAREN arg_list RPAREN  */
#line 2043 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("RIGHT", (yyvsp[-1].expr_list));
    }
#line 6553 "build/parser.cpp"
    break;

  case 392: /* primary_expr: BIF_STR LPAREN arg_list RPAREN  */
#line 2046 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("STR", (yyvsp[-1].expr_list));
    }
#line 6561 "build/parser.cpp"
    break;

  case 393: /* primary_expr: BIF_SUBARR LPAREN arg_list RPAREN  */
#line 2049 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("SUBARR", (yyvsp[-1].expr_list));
    }
#line 6569 "build/parser.cpp"
    break;

  case 394: /* primary_expr: BIF_MAXARR LPAREN arg_list RPAREN  */
#line 2052 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("MAXARR", (yyvsp[-1].expr_list));
    }
#line 6577 "build/parser.cpp"
    break;

  case 395: /* primary_expr: BIF_MINARR LPAREN arg_list RPAREN  */
#line 2055 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("MINARR", (yyvsp[-1].expr_list));
    }
#line 6585 "build/parser.cpp"
    break;

  case 396: /* primary_expr: BIF_LIST LPAREN arg_list RPAREN  */
#line 2058 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("LIST", (yyvsp[-1].expr_list));
    }
#line 6593 "build/parser.cpp"
    break;

  case 397: /* primary_expr: BIF_RANGE LPAREN arg_list RPAREN  */
#line 2061 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("RANGE", (yyvsp[-1].expr_list));
    }
#line 6601 "build/parser.cpp"
    break;

  case 398: /* primary_expr: BIF_LOOKUPLT LPAREN arg_list RPAREN  */
#line 2064 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPLT", (yyvsp[-1].expr_list));
    }
#line 6609 "build/parser.cpp"
    break;

  case 399: /* primary_expr: BIF_LOOKUPGE LPAREN arg_list RPAREN  */
#line 2067 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPGE", (yyvsp[-1].expr_list));
    }
#line 6617 "build/parser.cpp"
    break;

  case 400: /* primary_expr: BIF_LOOKUPLE LPAREN arg_list RPAREN  */
#line 2070 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPLE", (yyvsp[-1].expr_list));
    }
#line 6625 "build/parser.cpp"
    break;

  case 401: /* primary_expr: BIF_LOOKUPGT LPAREN arg_list RPAREN  */
#line 2073 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPGT", (yyvsp[-1].expr_list));
    }
#line 6633 "build/parser.cpp"
    break;

  case 402: /* primary_expr: BIF_TLOOKUP LPAREN arg_list RPAREN  */
#line 2076 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("TLOOKUP", (yyvsp[-1].expr_list));
    }
#line 6641 "build/parser.cpp"
    break;

  case 403: /* primary_expr: BIF_TLOOKUPLT LPAREN arg_list RPAREN  */
#line 2079 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TLOOKUPLT", (yyvsp[-1].expr_list));
    }
#line 6649 "build/parser.cpp"
    break;

  case 404: /* primary_expr: BIF_TLOOKUPGT LPAREN arg_list RPAREN  */
#line 2082 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TLOOKUPGT", (yyvsp[-1].expr_list));
    }
#line 6657 "build/parser.cpp"
    break;

  case 405: /* primary_expr: BIF_TLOOKUPLE LPAREN arg_list RPAREN  */
#line 2085 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TLOOKUPLE", (yyvsp[-1].expr_list));
    }
#line 6665 "build/parser.cpp"
    break;

  case 406: /* primary_expr: BIF_TLOOKUPGE LPAREN arg_list RPAREN  */
#line 2088 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TLOOKUPGE", (yyvsp[-1].expr_list));
    }
#line 6673 "build/parser.cpp"
    break;

  case 407: /* primary_expr: BIF_HOURS LPAREN expression RPAREN  */
#line 2091 "src/parser.y"
                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("HOURS", args);
    }
#line 6683 "build/parser.cpp"
    break;

  case 408: /* primary_expr: BIF_MINUTES LPAREN expression RPAREN  */
#line 2096 "src/parser.y"
                                           {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("MINUTES", args);
    }
#line 6693 "build/parser.cpp"
    break;

  case 409: /* primary_expr: BIF_SECONDS LPAREN expression RPAREN  */
#line 2101 "src/parser.y"
                                           {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("SECONDS", args);
    }
#line 6703 "build/parser.cpp"
    break;

  case 410: /* primary_expr: BIF_MSECONDS LPAREN expression RPAREN  */
#line 2106 "src/parser.y"
                                            {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("MSECONDS", args);
    }
#line 6713 "build/parser.cpp"
    break;

  case 411: /* primary_expr: BIF_PADDR LPAREN IDENTIFIER RPAREN  */
#line 2111 "src/parser.y"
                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::StringLiteral((yyvsp[-1].sval)));
        free((yyvsp[-1].sval));
        (yyval.expr) = make_bif("PADDR", args);
    }
#line 6724 "build/parser.cpp"
    break;

  case 412: /* primary_expr: BIF_PROC LPAREN RPAREN  */
#line 2117 "src/parser.y"
                             {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("PROC", empty);
    }
#line 6733 "build/parser.cpp"
    break;

  case 413: /* primary_expr: BIF_PROC  */
#line 2121 "src/parser.y"
               {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("PROC", empty);
    }
#line 6742 "build/parser.cpp"
    break;

  case 414: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_HOURS RPAREN  */
#line 2125 "src/parser.y"
                                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("HOURS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 6754 "build/parser.cpp"
    break;

  case 415: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_MINUTES RPAREN  */
#line 2132 "src/parser.y"
                                                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MINUTES"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 6766 "build/parser.cpp"
    break;

  case 416: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_SECONDS RPAREN  */
#line 2139 "src/parser.y"
                                                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("SECONDS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 6778 "build/parser.cpp"
    break;

  case 417: /* primary_expr: KW_ALL STRING_LITERAL  */
#line 2146 "src/parser.y"
                            {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::StringLiteral((yyvsp[0].sval)));
        free((yyvsp[0].sval));
        (yyval.expr) = make_bif("ALL", args);
    }
#line 6789 "build/parser.cpp"
    break;

  case 418: /* primary_expr: BIF_PASSED LPAREN ident RPAREN  */
#line 2152 "src/parser.y"
                                     {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::Identifier((yyvsp[-1].sval)));
        free((yyvsp[-1].sval));
        (yyval.expr) = make_bif("PASSED", args);
    }
#line 6800 "build/parser.cpp"
    break;

  case 419: /* primary_expr: BIF_OMITTED LPAREN ident RPAREN  */
#line 2158 "src/parser.y"
                                      {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::Identifier((yyvsp[-1].sval)));
        free((yyvsp[-1].sval));
        (yyval.expr) = make_bif("OMITTED", args);
    }
#line 6811 "build/parser.cpp"
    break;

  case 420: /* primary_expr: BIF_BITAND LPAREN arg_list RPAREN  */
#line 2164 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("BITAND", (yyvsp[-1].expr_list));
    }
#line 6819 "build/parser.cpp"
    break;

  case 421: /* primary_expr: BIF_BITNOT LPAREN arg_list RPAREN  */
#line 2167 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("BITNOT", (yyvsp[-1].expr_list));
    }
#line 6827 "build/parser.cpp"
    break;

  case 422: /* primary_expr: BIF_BITOR LPAREN arg_list RPAREN  */
#line 2170 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("BITOR", (yyvsp[-1].expr_list));
    }
#line 6835 "build/parser.cpp"
    break;

  case 423: /* primary_expr: BIF_BITXOR LPAREN arg_list RPAREN  */
#line 2173 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("BITXOR", (yyvsp[-1].expr_list));
    }
#line 6843 "build/parser.cpp"
    break;

  case 424: /* primary_expr: BIF_SCANR LPAREN arg_list RPAREN  */
#line 2176 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("SCANR", (yyvsp[-1].expr_list));
    }
#line 6851 "build/parser.cpp"
    break;

  case 425: /* primary_expr: BIF_EDITFLT LPAREN arg_list RPAREN  */
#line 2179 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("EDITFLT", (yyvsp[-1].expr_list));
    }
#line 6859 "build/parser.cpp"
    break;

  case 426: /* primary_expr: BIF_UNSH LPAREN arg_list RPAREN  */
#line 2182 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("UNSH", (yyvsp[-1].expr_list));
    }
#line 6867 "build/parser.cpp"
    break;

  case 427: /* primary_expr: BIF_PARMNUM LPAREN ident RPAREN  */
#line 2185 "src/parser.y"
                                      {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::Identifier((yyvsp[-1].sval)));
        free((yyvsp[-1].sval));
        (yyval.expr) = make_bif("PARMNUM", args);
    }
#line 6878 "build/parser.cpp"
    break;

  case 428: /* primary_expr: INDICATOR  */
#line 2191 "src/parser.y"
                {
        (yyval.expr) = new rpg::IndicatorExpr((yyvsp[0].ival));
    }
#line 6886 "build/parser.cpp"
    break;

  case 429: /* primary_expr: KW_ON  */
#line 2194 "src/parser.y"
            {
        (yyval.expr) = new rpg::IntLiteral(1);  // *ON → true
    }
#line 6894 "build/parser.cpp"
    break;

  case 430: /* primary_expr: KW_OFF  */
#line 2197 "src/parser.y"
             {
        (yyval.expr) = new rpg::IntLiteral(0);  // *OFF → false
    }
#line 6902 "build/parser.cpp"
    break;

  case 431: /* primary_expr: KW_NULL  */
#line 2200 "src/parser.y"
              {
        (yyval.expr) = new rpg::Identifier("nullptr");
    }
#line 6910 "build/parser.cpp"
    break;

  case 432: /* primary_expr: KW_OMIT  */
#line 2203 "src/parser.y"
              {
        (yyval.expr) = new rpg::Identifier("nullptr");
    }
#line 6918 "build/parser.cpp"
    break;

  case 433: /* primary_expr: KW_BLANKS  */
#line 2206 "src/parser.y"
                {
        (yyval.expr) = new rpg::Identifier("RPG_BLANKS");
    }
#line 6926 "build/parser.cpp"
    break;

  case 434: /* primary_expr: KW_ZEROS  */
#line 2209 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier("RPG_ZEROS");
    }
#line 6934 "build/parser.cpp"
    break;

  case 435: /* primary_expr: KW_HIVAL  */
#line 2212 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier("RPG_HIVAL");
    }
#line 6942 "build/parser.cpp"
    break;

  case 436: /* primary_expr: KW_LOVAL  */
#line 2215 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier("RPG_LOVAL");
    }
#line 6950 "build/parser.cpp"
    break;

  case 437: /* primary_expr: LPAREN expression RPAREN  */
#line 2218 "src/parser.y"
                               {
        (yyval.expr) = (yyvsp[-1].expr);
    }
#line 6958 "build/parser.cpp"
    break;

  case 438: /* call_args_opt: %empty  */
#line 2225 "src/parser.y"
                { (yyval.expr_list) = nullptr; }
#line 6964 "build/parser.cpp"
    break;

  case 439: /* call_args_opt: call_arg_list  */
#line 2226 "src/parser.y"
                    { (yyval.expr_list) = (yyvsp[0].expr_list); }
#line 6970 "build/parser.cpp"
    break;

  case 440: /* call_arg_list: expression  */
#line 2230 "src/parser.y"
               {
        (yyval.expr_list) = new std::vector<rpg::Expression*>();
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 6979 "build/parser.cpp"
    break;

  case 441: /* call_arg_list: call_arg_list COLON expression  */
#line 2234 "src/parser.y"
                                     {
        (yyval.expr_list) = (yyvsp[-2].expr_list);
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 6988 "build/parser.cpp"
    break;

  case 442: /* arg_list: expression  */
#line 2242 "src/parser.y"
               {
        (yyval.expr_list) = new std::vector<rpg::Expression*>();
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 6997 "build/parser.cpp"
    break;

  case 443: /* arg_list: arg_list COLON expression  */
#line 2246 "src/parser.y"
                                {
        (yyval.expr_list) = (yyvsp[-2].expr_list);
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 7006 "build/parser.cpp"
    break;


#line 7010 "build/parser.cpp"

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

#line 2252 "src/parser.y"


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
