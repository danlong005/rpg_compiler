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
#include "sql_utils.h"

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

#line 122 "build/parser.cpp"

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
  YYSYMBOL_KW_EVAL_EXT = 40,               /* KW_EVAL_EXT  */
  YYSYMBOL_KW_EVALR_EXT = 41,              /* KW_EVALR_EXT  */
  YYSYMBOL_KW_CALLP_EXT = 42,              /* KW_CALLP_EXT  */
  YYSYMBOL_KW_STATIC = 43,                 /* KW_STATIC  */
  YYSYMBOL_KW_TEMPLATE = 44,               /* KW_TEMPLATE  */
  YYSYMBOL_KW_BASED = 45,                  /* KW_BASED  */
  YYSYMBOL_KW_OPTIONS = 46,                /* KW_OPTIONS  */
  YYSYMBOL_KW_NOPASS = 47,                 /* KW_NOPASS  */
  YYSYMBOL_KW_OMIT = 48,                   /* KW_OMIT  */
  YYSYMBOL_KW_EXPORT = 49,                 /* KW_EXPORT  */
  YYSYMBOL_KW_IMPORT = 50,                 /* KW_IMPORT  */
  YYSYMBOL_KW_EXTPGM = 51,                 /* KW_EXTPGM  */
  YYSYMBOL_KW_EXTPROC = 52,                /* KW_EXTPROC  */
  YYSYMBOL_KW_CTLOPT = 53,                 /* KW_CTLOPT  */
  YYSYMBOL_KW_RETURN = 54,                 /* KW_RETURN  */
  YYSYMBOL_KW_INLR = 55,                   /* KW_INLR  */
  YYSYMBOL_KW_ON = 56,                     /* KW_ON  */
  YYSYMBOL_KW_BLANKS = 57,                 /* KW_BLANKS  */
  YYSYMBOL_KW_ZEROS = 58,                  /* KW_ZEROS  */
  YYSYMBOL_KW_HIVAL = 59,                  /* KW_HIVAL  */
  YYSYMBOL_KW_LOVAL = 60,                  /* KW_LOVAL  */
  YYSYMBOL_KW_IF = 61,                     /* KW_IF  */
  YYSYMBOL_KW_ELSEIF = 62,                 /* KW_ELSEIF  */
  YYSYMBOL_KW_ELSE = 63,                   /* KW_ELSE  */
  YYSYMBOL_KW_ENDIF = 64,                  /* KW_ENDIF  */
  YYSYMBOL_KW_DOW = 65,                    /* KW_DOW  */
  YYSYMBOL_KW_DOU = 66,                    /* KW_DOU  */
  YYSYMBOL_KW_ENDDO = 67,                  /* KW_ENDDO  */
  YYSYMBOL_KW_FOR = 68,                    /* KW_FOR  */
  YYSYMBOL_KW_ENDFOR = 69,                 /* KW_ENDFOR  */
  YYSYMBOL_KW_TO = 70,                     /* KW_TO  */
  YYSYMBOL_KW_DOWNTO = 71,                 /* KW_DOWNTO  */
  YYSYMBOL_KW_BY = 72,                     /* KW_BY  */
  YYSYMBOL_KW_SELECT = 73,                 /* KW_SELECT  */
  YYSYMBOL_KW_WHEN = 74,                   /* KW_WHEN  */
  YYSYMBOL_KW_OTHER = 75,                  /* KW_OTHER  */
  YYSYMBOL_KW_ENDSL = 76,                  /* KW_ENDSL  */
  YYSYMBOL_KW_ITER = 77,                   /* KW_ITER  */
  YYSYMBOL_KW_LEAVE = 78,                  /* KW_LEAVE  */
  YYSYMBOL_KW_MONITOR = 79,                /* KW_MONITOR  */
  YYSYMBOL_KW_ON_ERROR = 80,               /* KW_ON_ERROR  */
  YYSYMBOL_KW_ENDMON = 81,                 /* KW_ENDMON  */
  YYSYMBOL_KW_BEGSR = 82,                  /* KW_BEGSR  */
  YYSYMBOL_KW_ENDSR = 83,                  /* KW_ENDSR  */
  YYSYMBOL_KW_EXSR = 84,                   /* KW_EXSR  */
  YYSYMBOL_KW_OFF = 85,                    /* KW_OFF  */
  YYSYMBOL_KW_RESET = 86,                  /* KW_RESET  */
  YYSYMBOL_KW_CLEAR = 87,                  /* KW_CLEAR  */
  YYSYMBOL_KW_SORTA = 88,                  /* KW_SORTA  */
  YYSYMBOL_INDICATOR = 89,                 /* INDICATOR  */
  YYSYMBOL_KW_AND = 90,                    /* KW_AND  */
  YYSYMBOL_KW_OR = 91,                     /* KW_OR  */
  YYSYMBOL_KW_NOT = 92,                    /* KW_NOT  */
  YYSYMBOL_KW_DCL_PROC = 93,               /* KW_DCL_PROC  */
  YYSYMBOL_KW_END_PROC = 94,               /* KW_END_PROC  */
  YYSYMBOL_KW_DCL_PI = 95,                 /* KW_DCL_PI  */
  YYSYMBOL_KW_END_PI = 96,                 /* KW_END_PI  */
  YYSYMBOL_KW_DCL_PR = 97,                 /* KW_DCL_PR  */
  YYSYMBOL_KW_END_PR = 98,                 /* KW_END_PR  */
  YYSYMBOL_KW_VALUE = 99,                  /* KW_VALUE  */
  YYSYMBOL_KW_DCL_DS = 100,                /* KW_DCL_DS  */
  YYSYMBOL_KW_END_DS = 101,                /* KW_END_DS  */
  YYSYMBOL_KW_QUALIFIED = 102,             /* KW_QUALIFIED  */
  YYSYMBOL_KW_DIM = 103,                   /* KW_DIM  */
  YYSYMBOL_KW_LIKEDS = 104,                /* KW_LIKEDS  */
  YYSYMBOL_KW_LIKE = 105,                  /* KW_LIKE  */
  YYSYMBOL_KW_DCL_SUBF = 106,              /* KW_DCL_SUBF  */
  YYSYMBOL_KW_DCL_PARM = 107,              /* KW_DCL_PARM  */
  YYSYMBOL_DOT = 108,                      /* DOT  */
  YYSYMBOL_BIF_CHAR = 109,                 /* BIF_CHAR  */
  YYSYMBOL_BIF_TRIM = 110,                 /* BIF_TRIM  */
  YYSYMBOL_BIF_TRIML = 111,                /* BIF_TRIML  */
  YYSYMBOL_BIF_TRIMR = 112,                /* BIF_TRIMR  */
  YYSYMBOL_BIF_LEN = 113,                  /* BIF_LEN  */
  YYSYMBOL_BIF_SUBST = 114,                /* BIF_SUBST  */
  YYSYMBOL_BIF_SCAN = 115,                 /* BIF_SCAN  */
  YYSYMBOL_BIF_SCANRPL = 116,              /* BIF_SCANRPL  */
  YYSYMBOL_BIF_XLATE = 117,                /* BIF_XLATE  */
  YYSYMBOL_BIF_DEC = 118,                  /* BIF_DEC  */
  YYSYMBOL_BIF_INT = 119,                  /* BIF_INT  */
  YYSYMBOL_BIF_ELEM = 120,                 /* BIF_ELEM  */
  YYSYMBOL_BIF_FOUND = 121,                /* BIF_FOUND  */
  YYSYMBOL_BIF_EOF = 122,                  /* BIF_EOF  */
  YYSYMBOL_BIF_ABS = 123,                  /* BIF_ABS  */
  YYSYMBOL_BIF_DIV = 124,                  /* BIF_DIV  */
  YYSYMBOL_BIF_REM = 125,                  /* BIF_REM  */
  YYSYMBOL_BIF_SIZE = 126,                 /* BIF_SIZE  */
  YYSYMBOL_BIF_ADDR = 127,                 /* BIF_ADDR  */
  YYSYMBOL_BIF_PARMS = 128,                /* BIF_PARMS  */
  YYSYMBOL_BIF_STATUS = 129,               /* BIF_STATUS  */
  YYSYMBOL_BIF_ERROR = 130,                /* BIF_ERROR  */
  YYSYMBOL_BIF_MAX = 131,                  /* BIF_MAX  */
  YYSYMBOL_BIF_MIN = 132,                  /* BIF_MIN  */
  YYSYMBOL_BIF_LOOKUP = 133,               /* BIF_LOOKUP  */
  YYSYMBOL_BIF_DATE = 134,                 /* BIF_DATE  */
  YYSYMBOL_BIF_TIME = 135,                 /* BIF_TIME  */
  YYSYMBOL_BIF_TIMESTAMP = 136,            /* BIF_TIMESTAMP  */
  YYSYMBOL_BIF_DIFF = 137,                 /* BIF_DIFF  */
  YYSYMBOL_BIF_DAYS = 138,                 /* BIF_DAYS  */
  YYSYMBOL_BIF_MONTHS = 139,               /* BIF_MONTHS  */
  YYSYMBOL_BIF_YEARS = 140,                /* BIF_YEARS  */
  YYSYMBOL_BIF_EDITC = 141,                /* BIF_EDITC  */
  YYSYMBOL_BIF_EDITW = 142,                /* BIF_EDITW  */
  YYSYMBOL_BIF_REPLACE = 143,              /* BIF_REPLACE  */
  YYSYMBOL_BIF_CHECK = 144,                /* BIF_CHECK  */
  YYSYMBOL_BIF_CHECKR = 145,               /* BIF_CHECKR  */
  YYSYMBOL_BIF_LOWER = 146,                /* BIF_LOWER  */
  YYSYMBOL_BIF_UPPER = 147,                /* BIF_UPPER  */
  YYSYMBOL_BIF_SUBDT = 148,                /* BIF_SUBDT  */
  YYSYMBOL_BIF_FLOAT = 149,                /* BIF_FLOAT  */
  YYSYMBOL_BIF_SQRT = 150,                 /* BIF_SQRT  */
  YYSYMBOL_BIF_ALLOC = 151,                /* BIF_ALLOC  */
  YYSYMBOL_BIF_REALLOC = 152,              /* BIF_REALLOC  */
  YYSYMBOL_BIF_XFOOT = 153,                /* BIF_XFOOT  */
  YYSYMBOL_BIF_SUBARR = 154,               /* BIF_SUBARR  */
  YYSYMBOL_BIF_SPLIT = 155,                /* BIF_SPLIT  */
  YYSYMBOL_BIF_UNS = 156,                  /* BIF_UNS  */
  YYSYMBOL_BIF_INTH = 157,                 /* BIF_INTH  */
  YYSYMBOL_BIF_DECH = 158,                 /* BIF_DECH  */
  YYSYMBOL_BIF_DECPOS = 159,               /* BIF_DECPOS  */
  YYSYMBOL_BIF_CONCAT = 160,               /* BIF_CONCAT  */
  YYSYMBOL_BIF_CONCATARR = 161,            /* BIF_CONCATARR  */
  YYSYMBOL_BIF_LEFT = 162,                 /* BIF_LEFT  */
  YYSYMBOL_BIF_RIGHT = 163,                /* BIF_RIGHT  */
  YYSYMBOL_BIF_STR = 164,                  /* BIF_STR  */
  YYSYMBOL_BIF_MAXARR = 165,               /* BIF_MAXARR  */
  YYSYMBOL_BIF_MINARR = 166,               /* BIF_MINARR  */
  YYSYMBOL_BIF_LIST = 167,                 /* BIF_LIST  */
  YYSYMBOL_BIF_RANGE = 168,                /* BIF_RANGE  */
  YYSYMBOL_BIF_LOOKUPLT = 169,             /* BIF_LOOKUPLT  */
  YYSYMBOL_BIF_LOOKUPGE = 170,             /* BIF_LOOKUPGE  */
  YYSYMBOL_BIF_LOOKUPLE = 171,             /* BIF_LOOKUPLE  */
  YYSYMBOL_BIF_LOOKUPGT = 172,             /* BIF_LOOKUPGT  */
  YYSYMBOL_BIF_TLOOKUP = 173,              /* BIF_TLOOKUP  */
  YYSYMBOL_BIF_TLOOKUPLT = 174,            /* BIF_TLOOKUPLT  */
  YYSYMBOL_BIF_TLOOKUPGT = 175,            /* BIF_TLOOKUPGT  */
  YYSYMBOL_BIF_TLOOKUPLE = 176,            /* BIF_TLOOKUPLE  */
  YYSYMBOL_BIF_TLOOKUPGE = 177,            /* BIF_TLOOKUPGE  */
  YYSYMBOL_BIF_HOURS = 178,                /* BIF_HOURS  */
  YYSYMBOL_BIF_MINUTES = 179,              /* BIF_MINUTES  */
  YYSYMBOL_BIF_SECONDS = 180,              /* BIF_SECONDS  */
  YYSYMBOL_BIF_MSECONDS = 181,             /* BIF_MSECONDS  */
  YYSYMBOL_BIF_PADDR = 182,                /* BIF_PADDR  */
  YYSYMBOL_BIF_PROC = 183,                 /* BIF_PROC  */
  YYSYMBOL_BIF_PASSED = 184,               /* BIF_PASSED  */
  YYSYMBOL_BIF_OMITTED = 185,              /* BIF_OMITTED  */
  YYSYMBOL_BIF_BITAND = 186,               /* BIF_BITAND  */
  YYSYMBOL_BIF_BITNOT = 187,               /* BIF_BITNOT  */
  YYSYMBOL_BIF_BITOR = 188,                /* BIF_BITOR  */
  YYSYMBOL_BIF_BITXOR = 189,               /* BIF_BITXOR  */
  YYSYMBOL_BIF_SCANR = 190,                /* BIF_SCANR  */
  YYSYMBOL_BIF_EDITFLT = 191,              /* BIF_EDITFLT  */
  YYSYMBOL_BIF_UNSH = 192,                 /* BIF_UNSH  */
  YYSYMBOL_BIF_PARMNUM = 193,              /* BIF_PARMNUM  */
  YYSYMBOL_BIF_GETENV = 194,               /* BIF_GETENV  */
  YYSYMBOL_BIF_XML = 195,                  /* BIF_XML  */
  YYSYMBOL_KW_ALL = 196,                   /* KW_ALL  */
  YYSYMBOL_KW_UNS = 197,                   /* KW_UNS  */
  YYSYMBOL_KW_FLOAT_TYPE = 198,            /* KW_FLOAT_TYPE  */
  YYSYMBOL_KW_BINDEC = 199,                /* KW_BINDEC  */
  YYSYMBOL_KW_UCS2 = 200,                  /* KW_UCS2  */
  YYSYMBOL_KW_GRAPH = 201,                 /* KW_GRAPH  */
  YYSYMBOL_KW_OBJECT = 202,                /* KW_OBJECT  */
  YYSYMBOL_KW_JAVA = 203,                  /* KW_JAVA  */
  YYSYMBOL_KW_OVERLAY = 204,               /* KW_OVERLAY  */
  YYSYMBOL_KW_POS = 205,                   /* KW_POS  */
  YYSYMBOL_KW_PREFIX = 206,                /* KW_PREFIX  */
  YYSYMBOL_KW_DATFMT = 207,                /* KW_DATFMT  */
  YYSYMBOL_KW_TIMFMT = 208,                /* KW_TIMFMT  */
  YYSYMBOL_KW_EXTNAME = 209,               /* KW_EXTNAME  */
  YYSYMBOL_KW_PSDS = 210,                  /* KW_PSDS  */
  YYSYMBOL_KW_SDS = 211,                   /* KW_SDS  */
  YYSYMBOL_KW_DTAARA = 212,                /* KW_DTAARA  */
  YYSYMBOL_KW_OUT = 213,                   /* KW_OUT  */
  YYSYMBOL_KW_UNLOCK = 214,                /* KW_UNLOCK  */
  YYSYMBOL_KW_RTNPARM = 215,               /* KW_RTNPARM  */
  YYSYMBOL_KW_OPDESC = 216,                /* KW_OPDESC  */
  YYSYMBOL_KW_ASCEND = 217,                /* KW_ASCEND  */
  YYSYMBOL_KW_DESCEND = 218,               /* KW_DESCEND  */
  YYSYMBOL_KW_NULLIND = 219,               /* KW_NULLIND  */
  YYSYMBOL_KW_VARSIZE = 220,               /* KW_VARSIZE  */
  YYSYMBOL_KW_STRING_OPT = 221,            /* KW_STRING_OPT  */
  YYSYMBOL_KW_TRIM_OPT = 222,              /* KW_TRIM_OPT  */
  YYSYMBOL_KW_DCL_ENUM = 223,              /* KW_DCL_ENUM  */
  YYSYMBOL_KW_END_ENUM = 224,              /* KW_END_ENUM  */
  YYSYMBOL_KW_BOOLEAN = 225,               /* KW_BOOLEAN  */
  YYSYMBOL_EXEC_SQL_TEXT = 226,            /* EXEC_SQL_TEXT  */
  YYSYMBOL_POWER = 227,                    /* POWER  */
  YYSYMBOL_KW_DIM_VAR = 228,               /* KW_DIM_VAR  */
  YYSYMBOL_KW_DIM_AUTO = 229,              /* KW_DIM_AUTO  */
  YYSYMBOL_KW_FOR_EACH = 230,              /* KW_FOR_EACH  */
  YYSYMBOL_KW_IN = 231,                    /* KW_IN  */
  YYSYMBOL_KW_XML_INTO = 232,              /* KW_XML_INTO  */
  YYSYMBOL_IDENTIFIER = 233,               /* IDENTIFIER  */
  YYSYMBOL_INTEGER_LITERAL = 234,          /* INTEGER_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 235,            /* FLOAT_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 236,           /* STRING_LITERAL  */
  YYSYMBOL_SEMICOLON = 237,                /* SEMICOLON  */
  YYSYMBOL_EQUALS = 238,                   /* EQUALS  */
  YYSYMBOL_LPAREN = 239,                   /* LPAREN  */
  YYSYMBOL_RPAREN = 240,                   /* RPAREN  */
  YYSYMBOL_COLON = 241,                    /* COLON  */
  YYSYMBOL_PLUS = 242,                     /* PLUS  */
  YYSYMBOL_MINUS = 243,                    /* MINUS  */
  YYSYMBOL_STAR = 244,                     /* STAR  */
  YYSYMBOL_SLASH = 245,                    /* SLASH  */
  YYSYMBOL_NE = 246,                       /* NE  */
  YYSYMBOL_LE = 247,                       /* LE  */
  YYSYMBOL_GE = 248,                       /* GE  */
  YYSYMBOL_LT = 249,                       /* LT  */
  YYSYMBOL_GT = 250,                       /* GT  */
  YYSYMBOL_YYACCEPT = 251,                 /* $accept  */
  YYSYMBOL_program = 252,                  /* program  */
  YYSYMBOL_statements_opt = 253,           /* statements_opt  */
  YYSYMBOL_statement_list = 254,           /* statement_list  */
  YYSYMBOL_statement = 255,                /* statement  */
  YYSYMBOL_dcl_f_stmt = 256,               /* dcl_f_stmt  */
  YYSYMBOL_dcl_s_stmt = 257,               /* dcl_s_stmt  */
  YYSYMBOL_dcl_s_keywords = 258,           /* dcl_s_keywords  */
  YYSYMBOL_dcl_c_stmt = 259,               /* dcl_c_stmt  */
  YYSYMBOL_eval_target = 260,              /* eval_target  */
  YYSYMBOL_eval_stmt = 261,                /* eval_stmt  */
  YYSYMBOL_eval_corr_stmt = 262,           /* eval_corr_stmt  */
  YYSYMBOL_xml_into_stmt = 263,            /* xml_into_stmt  */
  YYSYMBOL_in_da_stmt = 264,               /* in_da_stmt  */
  YYSYMBOL_out_da_stmt = 265,              /* out_da_stmt  */
  YYSYMBOL_unlock_da_stmt = 266,           /* unlock_da_stmt  */
  YYSYMBOL_evalr_stmt = 267,               /* evalr_stmt  */
  YYSYMBOL_callp_stmt = 268,               /* callp_stmt  */
  YYSYMBOL_leavesr_stmt = 269,             /* leavesr_stmt  */
  YYSYMBOL_dsply_stmt = 270,               /* dsply_stmt  */
  YYSYMBOL_inlr_stmt = 271,                /* inlr_stmt  */
  YYSYMBOL_return_stmt = 272,              /* return_stmt  */
  YYSYMBOL_expr_stmt = 273,                /* expr_stmt  */
  YYSYMBOL_dcl_pr_stmt = 274,              /* dcl_pr_stmt  */
  YYSYMBOL_dcl_proc_stmt = 275,            /* dcl_proc_stmt  */
  YYSYMBOL_proc_export = 276,              /* proc_export  */
  YYSYMBOL_pi_return_type = 277,           /* pi_return_type  */
  YYSYMBOL_pi_params = 278,                /* pi_params  */
  YYSYMBOL_pi_param = 279,                 /* pi_param  */
  YYSYMBOL_pr_params = 280,                /* pr_params  */
  YYSYMBOL_pr_param = 281,                 /* pr_param  */
  YYSYMBOL_monitor_stmt = 282,             /* monitor_stmt  */
  YYSYMBOL_begsr_stmt = 283,               /* begsr_stmt  */
  YYSYMBOL_exsr_stmt = 284,                /* exsr_stmt  */
  YYSYMBOL_sorta_stmt = 285,               /* sorta_stmt  */
  YYSYMBOL_reset_stmt = 286,               /* reset_stmt  */
  YYSYMBOL_clear_stmt = 287,               /* clear_stmt  */
  YYSYMBOL_dealloc_stmt = 288,             /* dealloc_stmt  */
  YYSYMBOL_test_stmt = 289,                /* test_stmt  */
  YYSYMBOL_exec_sql_stmt = 290,            /* exec_sql_stmt  */
  YYSYMBOL_dcl_enum_stmt = 291,            /* dcl_enum_stmt  */
  YYSYMBOL_enum_constants = 292,           /* enum_constants  */
  YYSYMBOL_enum_constant = 293,            /* enum_constant  */
  YYSYMBOL_dcl_ds_stmt = 294,              /* dcl_ds_stmt  */
  YYSYMBOL_ds_fields = 295,                /* ds_fields  */
  YYSYMBOL_psds_kw = 296,                  /* psds_kw  */
  YYSYMBOL_ds_field = 297,                 /* ds_field  */
  YYSYMBOL_if_stmt = 298,                  /* if_stmt  */
  YYSYMBOL_elseif_clauses = 299,           /* elseif_clauses  */
  YYSYMBOL_elseif_clause = 300,            /* elseif_clause  */
  YYSYMBOL_else_clause = 301,              /* else_clause  */
  YYSYMBOL_dow_stmt = 302,                 /* dow_stmt  */
  YYSYMBOL_dou_stmt = 303,                 /* dou_stmt  */
  YYSYMBOL_for_stmt = 304,                 /* for_stmt  */
  YYSYMBOL_for_each_stmt = 305,            /* for_each_stmt  */
  YYSYMBOL_select_stmt = 306,              /* select_stmt  */
  YYSYMBOL_when_clauses = 307,             /* when_clauses  */
  YYSYMBOL_when_clause = 308,              /* when_clause  */
  YYSYMBOL_other_clause = 309,             /* other_clause  */
  YYSYMBOL_iter_stmt = 310,                /* iter_stmt  */
  YYSYMBOL_leave_stmt = 311,               /* leave_stmt  */
  YYSYMBOL_expression = 312,               /* expression  */
  YYSYMBOL_or_expr = 313,                  /* or_expr  */
  YYSYMBOL_and_expr = 314,                 /* and_expr  */
  YYSYMBOL_not_expr = 315,                 /* not_expr  */
  YYSYMBOL_comparison_expr = 316,          /* comparison_expr  */
  YYSYMBOL_additive_expr = 317,            /* additive_expr  */
  YYSYMBOL_multiplicative_expr = 318,      /* multiplicative_expr  */
  YYSYMBOL_power_expr = 319,               /* power_expr  */
  YYSYMBOL_unary_expr = 320,               /* unary_expr  */
  YYSYMBOL_postfix_expr = 321,             /* postfix_expr  */
  YYSYMBOL_ident = 322,                    /* ident  */
  YYSYMBOL_primary_expr = 323,             /* primary_expr  */
  YYSYMBOL_call_args_opt = 324,            /* call_args_opt  */
  YYSYMBOL_call_arg_list = 325,            /* call_arg_list  */
  YYSYMBOL_arg_list = 326                  /* arg_list  */
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
#define YYLAST   4986

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  251
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  76
/* YYNRULES -- Number of rules.  */
#define YYNRULES  470
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1539

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   505


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
     235,   236,   237,   238,   239,   240,   241,   242,   243,   244,
     245,   246,   247,   248,   249,   250
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   197,   197,   200,   205,   207,   212,   221,   224,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   275,   279,   283,
     287,   295,   300,   305,   310,   315,   320,   325,   330,   335,
     340,   345,   350,   356,   362,   368,   372,   376,   380,   384,
     388,   392,   396,   400,   404,   408,   414,   420,   426,   432,
     439,   444,   450,   455,   460,   465,   470,   475,   480,   485,
     490,   495,   500,   505,   510,   515,   520,   525,   533,   534,
     535,   536,   537,   542,   549,   553,   554,   555,   556,   557,
     558,   559,   560,   561,   562,   563,   564,   565,   566,   567,
     570,   576,   580,   586,   592,   598,   604,   615,   623,   629,
     638,   645,   652,   659,   665,   676,   679,   686,   692,   698,
     704,   707,   714,   725,   742,   762,   777,   801,   826,   853,
     883,   884,   889,   890,   891,   892,   893,   898,   901,   909,
     913,   917,   921,   925,   929,   933,   937,   942,   946,   950,
     954,   958,   962,   966,   970,   974,   980,   985,   990,   995,
    1001,  1006,  1011,  1016,  1022,  1027,  1032,  1041,  1044,  1052,
    1056,  1060,  1064,  1068,  1072,  1076,  1080,  1085,  1089,  1093,
    1097,  1101,  1105,  1109,  1113,  1117,  1123,  1128,  1133,  1138,
    1144,  1149,  1154,  1159,  1165,  1170,  1175,  1185,  1196,  1206,
    1214,  1222,  1229,  1237,  1245,  1256,  1266,  1274,  1285,  1288,
    1296,  1304,  1319,  1328,  1337,  1347,  1357,  1368,  1379,  1390,
    1401,  1409,  1418,  1428,  1439,  1450,  1460,  1470,  1480,  1490,
    1500,  1503,  1511,  1512,  1516,  1520,  1524,  1528,  1533,  1537,
    1541,  1545,  1550,  1556,  1562,  1569,  1576,  1583,  1589,  1597,
    1603,  1614,  1637,  1638,  1646,  1655,  1656,  1662,  1671,  1680,
    1690,  1700,  1710,  1723,  1733,  1752,  1756,  1763,  1772,  1773,
    1779,  1783,  1789,  1793,  1794,  1802,  1803,  1811,  1812,  1818,
    1819,  1824,  1829,  1834,  1839,  1844,  1849,  1857,  1858,  1863,
    1871,  1872,  1877,  1885,  1886,  1894,  1895,  1903,  1904,  1911,
    1912,  1913,  1914,  1915,  1916,  1917,  1918,  1919,  1920,  1921,
    1922,  1923,  1924,  1925,  1926,  1930,  1934,  1935,  1936,  1937,
    1938,  1939,  1940,  1941,  1942,  1943,  1944,  1945,  1946,  1947,
    1948,  1951,  1954,  1958,  1962,  1965,  1968,  1971,  1974,  1977,
    1980,  1983,  1986,  1989,  1992,  1995,  1998,  2002,  2005,  2008,
    2011,  2014,  2017,  2020,  2023,  2026,  2032,  2038,  2044,  2050,
    2056,  2062,  2065,  2068,  2071,  2074,  2078,  2082,  2085,  2088,
    2091,  2094,  2097,  2100,  2104,  2107,  2111,  2114,  2118,  2125,
    2132,  2139,  2144,  2149,  2154,  2158,  2162,  2165,  2168,  2171,
    2174,  2177,  2180,  2183,  2186,  2189,  2192,  2195,  2198,  2201,
    2204,  2207,  2210,  2213,  2216,  2219,  2222,  2225,  2228,  2231,
    2234,  2237,  2240,  2243,  2248,  2253,  2258,  2263,  2269,  2273,
    2277,  2284,  2291,  2298,  2304,  2310,  2316,  2319,  2322,  2325,
    2328,  2331,  2334,  2337,  2343,  2346,  2349,  2352,  2355,  2358,
    2361,  2364,  2367,  2370,  2373,  2380,  2381,  2385,  2389,  2397,
    2401
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
  "KW_DEALLOC", "KW_TEST", "KW_EVAL_EXT", "KW_EVALR_EXT", "KW_CALLP_EXT",
  "KW_STATIC", "KW_TEMPLATE", "KW_BASED", "KW_OPTIONS", "KW_NOPASS",
  "KW_OMIT", "KW_EXPORT", "KW_IMPORT", "KW_EXTPGM", "KW_EXTPROC",
  "KW_CTLOPT", "KW_RETURN", "KW_INLR", "KW_ON", "KW_BLANKS", "KW_ZEROS",
  "KW_HIVAL", "KW_LOVAL", "KW_IF", "KW_ELSEIF", "KW_ELSE", "KW_ENDIF",
  "KW_DOW", "KW_DOU", "KW_ENDDO", "KW_FOR", "KW_ENDFOR", "KW_TO",
  "KW_DOWNTO", "KW_BY", "KW_SELECT", "KW_WHEN", "KW_OTHER", "KW_ENDSL",
  "KW_ITER", "KW_LEAVE", "KW_MONITOR", "KW_ON_ERROR", "KW_ENDMON",
  "KW_BEGSR", "KW_ENDSR", "KW_EXSR", "KW_OFF", "KW_RESET", "KW_CLEAR",
  "KW_SORTA", "INDICATOR", "KW_AND", "KW_OR", "KW_NOT", "KW_DCL_PROC",
  "KW_END_PROC", "KW_DCL_PI", "KW_END_PI", "KW_DCL_PR", "KW_END_PR",
  "KW_VALUE", "KW_DCL_DS", "KW_END_DS", "KW_QUALIFIED", "KW_DIM",
  "KW_LIKEDS", "KW_LIKE", "KW_DCL_SUBF", "KW_DCL_PARM", "DOT", "BIF_CHAR",
  "BIF_TRIM", "BIF_TRIML", "BIF_TRIMR", "BIF_LEN", "BIF_SUBST", "BIF_SCAN",
  "BIF_SCANRPL", "BIF_XLATE", "BIF_DEC", "BIF_INT", "BIF_ELEM",
  "BIF_FOUND", "BIF_EOF", "BIF_ABS", "BIF_DIV", "BIF_REM", "BIF_SIZE",
  "BIF_ADDR", "BIF_PARMS", "BIF_STATUS", "BIF_ERROR", "BIF_MAX", "BIF_MIN",
  "BIF_LOOKUP", "BIF_DATE", "BIF_TIME", "BIF_TIMESTAMP", "BIF_DIFF",
  "BIF_DAYS", "BIF_MONTHS", "BIF_YEARS", "BIF_EDITC", "BIF_EDITW",
  "BIF_REPLACE", "BIF_CHECK", "BIF_CHECKR", "BIF_LOWER", "BIF_UPPER",
  "BIF_SUBDT", "BIF_FLOAT", "BIF_SQRT", "BIF_ALLOC", "BIF_REALLOC",
  "BIF_XFOOT", "BIF_SUBARR", "BIF_SPLIT", "BIF_UNS", "BIF_INTH",
  "BIF_DECH", "BIF_DECPOS", "BIF_CONCAT", "BIF_CONCATARR", "BIF_LEFT",
  "BIF_RIGHT", "BIF_STR", "BIF_MAXARR", "BIF_MINARR", "BIF_LIST",
  "BIF_RANGE", "BIF_LOOKUPLT", "BIF_LOOKUPGE", "BIF_LOOKUPLE",
  "BIF_LOOKUPGT", "BIF_TLOOKUP", "BIF_TLOOKUPLT", "BIF_TLOOKUPGT",
  "BIF_TLOOKUPLE", "BIF_TLOOKUPGE", "BIF_HOURS", "BIF_MINUTES",
  "BIF_SECONDS", "BIF_MSECONDS", "BIF_PADDR", "BIF_PROC", "BIF_PASSED",
  "BIF_OMITTED", "BIF_BITAND", "BIF_BITNOT", "BIF_BITOR", "BIF_BITXOR",
  "BIF_SCANR", "BIF_EDITFLT", "BIF_UNSH", "BIF_PARMNUM", "BIF_GETENV",
  "BIF_XML", "KW_ALL", "KW_UNS", "KW_FLOAT_TYPE", "KW_BINDEC", "KW_UCS2",
  "KW_GRAPH", "KW_OBJECT", "KW_JAVA", "KW_OVERLAY", "KW_POS", "KW_PREFIX",
  "KW_DATFMT", "KW_TIMFMT", "KW_EXTNAME", "KW_PSDS", "KW_SDS", "KW_DTAARA",
  "KW_OUT", "KW_UNLOCK", "KW_RTNPARM", "KW_OPDESC", "KW_ASCEND",
  "KW_DESCEND", "KW_NULLIND", "KW_VARSIZE", "KW_STRING_OPT", "KW_TRIM_OPT",
  "KW_DCL_ENUM", "KW_END_ENUM", "KW_BOOLEAN", "EXEC_SQL_TEXT", "POWER",
  "KW_DIM_VAR", "KW_DIM_AUTO", "KW_FOR_EACH", "KW_IN", "KW_XML_INTO",
  "IDENTIFIER", "INTEGER_LITERAL", "FLOAT_LITERAL", "STRING_LITERAL",
  "SEMICOLON", "EQUALS", "LPAREN", "RPAREN", "COLON", "PLUS", "MINUS",
  "STAR", "SLASH", "NE", "LE", "GE", "LT", "GT", "$accept", "program",
  "statements_opt", "statement_list", "statement", "dcl_f_stmt",
  "dcl_s_stmt", "dcl_s_keywords", "dcl_c_stmt", "eval_target", "eval_stmt",
  "eval_corr_stmt", "xml_into_stmt", "in_da_stmt", "out_da_stmt",
  "unlock_da_stmt", "evalr_stmt", "callp_stmt", "leavesr_stmt",
  "dsply_stmt", "inlr_stmt", "return_stmt", "expr_stmt", "dcl_pr_stmt",
  "dcl_proc_stmt", "proc_export", "pi_return_type", "pi_params",
  "pi_param", "pr_params", "pr_param", "monitor_stmt", "begsr_stmt",
  "exsr_stmt", "sorta_stmt", "reset_stmt", "clear_stmt", "dealloc_stmt",
  "test_stmt", "exec_sql_stmt", "dcl_enum_stmt", "enum_constants",
  "enum_constant", "dcl_ds_stmt", "ds_fields", "psds_kw", "ds_field",
  "if_stmt", "elseif_clauses", "elseif_clause", "else_clause", "dow_stmt",
  "dou_stmt", "for_stmt", "for_each_stmt", "select_stmt", "when_clauses",
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

#define YYPACT_NINF (-854)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-290)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      43,  -854,    82,    18,   449,  -854,  -138,  -130,   346,   -86,
    4283,    84,   346,    84,  4283,   -85,   346,   -74,    84,    84,
    4283,  -854,  3526,   -67,  4283,  4283,  4283,   346,   -46,   -44,
     -36,   -34,   -25,   346,   346,   346,   346,  -854,    12,    53,
      62,   -29,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,    85,    98,  -854,  -854,  -854,  -854,  -854,   118,  -854,
     346,   120,   346,   -65,  -854,  -854,  -854,  -854,     4,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,   198,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,   113,  4283,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  4472,   -22,   122,   125,   127,   130,   139,   141,
     144,   150,   160,   177,   180,   185,   193,   212,   217,   219,
     236,   258,   273,   277,   282,   293,   302,   306,   309,   321,
     329,   401,   406,   421,   432,   439,   444,   492,   532,   544,
     562,   564,   567,   575,   578,   580,   587,   591,   602,   612,
     618,   625,   632,   648,   650,   657,   659,   660,   661,   663,
     664,   666,   667,   668,   669,   670,   671,   672,   674,   676,
     677,   678,   679,   680,   681,   683,   684,   686,   687,   688,
     689,   690,   691,   694,   695,   697,   698,   705,   706,    40,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,   707,  -854,  -854,  -854,  4283,  4661,
      19,   305,   410,  -854,   195,  -133,    25,  -854,   252,   417,
    -854,   -63,   280,   296,   547,   557,  -854,   717,   346,   718,
     720,   722,  -854,   724,   899,   732,   733,   735,   736,   897,
    -854,  -854,  -854,   738,   739,   740,   741,   742,   931,   450,
     194,  4283,   744,   745,   -60,   752,   747,   790,   753,  4283,
    4283,    -8,   750,   751,   754,   755,   756,   757,   758,  -120,
    -114,   761,   763,   766,   760,   765,   767,   768,   775,   776,
     777,   787,   788,   195,  4283,  4283,  4283,  4283,  4283,  4283,
    4283,  4283,  4283,  4283,  4283,  4283,   749,   786,  4283,  4283,
    4283,  4283,  4283,   789,   798,   799,  4283,  4283,  4283,  3716,
    3905,  4094,  4283,  4283,  4283,  4283,  4283,  4283,  4283,  4283,
    4283,  4283,  4283,  4283,  4283,  4283,  4283,  4283,  4283,  4283,
    4283,  4283,  4283,  4283,  4283,  4283,  4283,  4283,  4283,  4283,
    4283,  4283,  4283,  4283,  4283,  4283,  4283,  4283,  4283,  4283,
    4283,  4283,  4283,  4283,  4283,  4283,  4283,   759,   800,   346,
     346,  4283,  4283,  4283,  4283,  4283,  4283,  4283,   346,  4283,
    -854,  4283,   801,   417,  -854,  4283,  4283,  4472,  4472,  4472,
    4472,  4472,  4472,  4472,  4472,  4472,  4472,  4472,  4472,   809,
    4283,  4283,   346,  4283,  -854,  -854,   807,  4283,  4283,  -854,
    -854,   811,  -854,  -854,  -854,  4283,  4283,   250,  -854,  1410,
    -854,  -854,  -854,  -854,  -854,  -854,   812,   806,   813,   814,
     816,   817,   -17,   175,   825,   831,   832,  -854,  -854,  -854,
     -58,  -854,   117,  -854,  -854,   835,   818,  4283,  -854,   834,
    -854,   810,   836,   803,   837,   838,  -854,  -854,  -854,   841,
     844,   845,   846,   849,   847,  -854,   848,  -854,  -854,  -854,
    -854,   851,   860,   862,   863,   864,   865,   882,  -854,  -854,
     131,   189,   237,   265,   299,   326,   332,   368,   370,   372,
     374,   377,  -854,  -854,   379,   381,   383,   385,   387,  -854,
    -854,  -854,   389,   391,   393,  -854,   396,  -854,   398,  -854,
     402,   861,   867,   868,   870,   408,   411,   429,   433,   436,
     445,   447,   871,   451,   453,   455,   457,   459,   461,   463,
     465,   467,   469,   471,   473,   475,   477,   479,   481,   483,
     485,   487,   489,   493,   496,   501,   503,   505,   507,   509,
     513,   515,   877,   879,   885,   886,   888,  -854,   889,   890,
     517,   519,   521,   523,   537,   539,   541,   891,   546,  -854,
     892,  -854,   410,  -854,   548,   548,   548,   548,   548,   548,
     548,    25,    25,  -854,  -854,  -854,  -854,   810,   866,   896,
     898,   346,   900,   901,  -854,   734,  1633,  1703,   619,   903,
     904,  -854,   914,   905,  -854,  1926,  1006,   902,   909,   910,
     911,   924,   895,  -854,   907,   922,  -854,   925,   218,   930,
     932,   -21,   927,   -13,  -854,  4283,   818,   555,   -75,  -854,
     929,  4283,   883,   933,  4283,  -854,   923,   928,   934,   935,
     936,   938,   940,   943,   941,   944,   946,   947,   948,   949,
     939,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  4283,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,   566,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,   954,  -854,  -854,   762,   955,
     956,  4283,  4283,  -854,  -854,   960,  -854,   961,    14,   962,
     967,   968,   959,   969,   976,    90,   242,   980,    50,  -854,
     975,   977,   979,   981,   588,   983,   989,   294,  -854,  -854,
     203,  -854,    44,  -854,  4283,   986,  -854,  -854,   592,   993,
    -854,  -854,   988,   110,   223,   140,   996,  1004,   987,   999,
    1010,   416,   416,   416,   416,   416,  1012,  1008,  1011,  1014,
    1015,  1016,  1021,  1022,  -854,  4283,  1026,  -854,  1105,  -854,
    -854,   -41,   -39,   804,  1996,  -854,  2219,  -854,   545,  1028,
    -854,  -854,  -854,  1018,  1029,  1024,  1030,  1035,   316,  -854,
    1031,  1032,  1034,   607,  1033,   215,  1037,  1041,  1167,   -28,
    1039,  1043,  -854,   395,  1040,  1042,  1044,  1045,  1046,   239,
    1049,  1050,  1051,  -854,  2289,  1052,  4283,  -854,  1036,  1248,
    1053,  -854,  -854,  1054,  1252,  -854,  1055,  1056,  1059,  1058,
    -854,  1060,  1061,  1064,  1260,  1063,  1065,  1261,  1066,  1067,
    1070,  1068,  1069,  1073,  1074,  -854,  1075,  1076,  1079,  1080,
    1082,  1087,   572,  -854,  -854,  -854,  -854,  -854,  -854,  1083,
    -854,  1091,  4283,  -854,  4283,  -854,  1092,  1100,  -854,  1098,
    -854,  1102,  -854,   589,  1103,  1112,  1113,  1114,  1115,  1121,
    1122,  1120,  1123,  1124,  -854,  1125,  1119,  1126,  1127,  1128,
    -854,  -854,  1129,  1131,  1144,  1145,  1146,  1147,  1134,  1153,
    1154,  1155,  1130,  1156,  -854,  -854,  -854,  1159,  -854,  1150,
    1151,  1158,  4283,  1132,  1160,  1164,  1169,  -854,  4283,   279,
    1170,  -854,  1161,  4283,  1171,  1168,   295,  1176,  -854,   137,
     416,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  1173,  1152,
    1172,  1180,  1181,  1183,  1185,  -854,  2512,  -854,  1193,  2582,
    1194,  2805,  -854,  -854,    54,  -854,   157,  -854,  1196,  1197,
    1199,  1200,  1198,  1213,  1219,  1220,  1222,  1216,  1217,  -854,
    -854,  1218,  -854,  1201,  1259,  -854,  1225,   240,  1359,  1228,
    1229,  1232,  1233,  1235,  1230,  1234,  1237,  1057,  1239,  -854,
    -854,  1236,  1243,  4283,  1241,  1242,  4283,  1244,  1245,  1246,
    1231,  1250,  1253,  1255,  4283,  1262,  1264,  4283,  1265,  1267,
    1269,  1271,  1439,  1266,  1273,  1274,  1263,  1277,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  1027,  -854,  1278,  -854,  1279,
      61,  1280,  1268,   426,  -854,  1281,   164,  1285,  1286,  1287,
    1288,  1283,  1284,  1289,  1290,  1292,  1291,  1296,   241,   253,
    1297,  1298,  1299,   259,  1300,  1302,  1305,  1303,  1310,  1311,
    1319,  1312,  -115,  1324,   -42,  1293,  1325,  -854,  -854,  1327,
    1328,  1331,  1329,   184,  1337,  1338,  1330,  1342,  1341,  1343,
    1339,  1344,  1345,  1346,  1349,  1350,   197,  1348,  1351,  4283,
    1353,  1355,  -854,  -854,  2875,  -854,  3098,  -854,  1352,  -854,
     593,  1354,  1356,  1357,  1358,  1360,  -854,  1361,  1362,  1363,
    1364,  1336,   -38,   -37,   -35,  1366,  1368,  -854,  -854,  1369,
    1372,  -854,  -854,  -854,  1373,  1375,  -854,  -854,  1376,  1383,
    1384,  1367,  1385,  1391,  1392,  -854,  -854,  1393,  1396,  -854,
    1404,  -854,  1408,  -854,  -854,  1409,  1411,  1412,  -854,  -854,
    -854,  1407,  1413,  -854,  -854,  1414,  -854,  -854,  1415,  1416,
    1417,  1418,  1421,  -854,  -854,  4283,  1419,  1420,  1422,  1424,
    1426,  -854,  1117,  1431,  1437,  1438,  1440,  1444,  1446,  1447,
    1448,  1450,  -854,   -62,   -23,    -7,  1451,  1445,   -45,  -854,
    1452,   -43,  -854,  1453,   -26,  -854,  1449,  -854,   261,   262,
    -854,  -854,   276,   278,   286,  -854,  -854,   287,  -854,  -854,
    -854,  1455,  -854,  1457,  1459,  1463,  1468,  -124,  -854,  -854,
    -854,  -854,  1460,  1466,  -854,  -854,  1476,  1477,  -854,  -854,
    1465,  1479,  1481,  1486,  -854,  -854,  1340,  1487,  1488,  1493,
    1494,  1495,  1497,  1492,  1500,  1506,  1507,  1509,  1510,  -854,
    1513,  -854,  1514,  -854,  1512,   802,  1515,  -854,   805,  1516,
    -854,   808,  1517,  -854,     2,  1522,  1523,  1524,  1525,  1526,
    1528,  1529,   620,  1527,   622,  1532,  1534,  -854,  -854,  -854,
    -854,  -854,  1537,  -854,  -854,  -854,  1538,  1540,  -854,  -854,
    1539,  1543,  1544,  1545,     9,    17,    20,  1554,  1541,  -854,
    -854,  -854,    15,  1552,  1555,  1478,  1553,  1557,  1547,  1558,
    1561,  1603,  1559,   -16,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  1565,  1570,  1568,  1569,  1573,  1571,  1575,  -854,
    -854,  -854,  3168,    21,    37,    38,  1576,  1572,     1,  -854,
    1574,    23,  -854,  1577,    24,  -854,  1578,  -854,  1580,  -854,
    1606,  1582,  1581,  1638,  1583,  1584,  1764,  1585,  1586,  1766,
    1588,  -854,  -854,  1589,  -854,  -854,  1592,  -854,  1593,  3391,
    1591,  1598,  -854,  1599,  -854,  1607,  -854,  1605,   820,  1604,
    -854,   826,  1614,  -854,   828,  1615,  -854,    22,  -854,  1617,
    -854,  1618,  1620,  -854,  1621,  1622,  -854,  1624,  1627,  1768,
    1631,  1632,  1634,  1635,  -854,  -854,  -854,  -854,    47,  1629,
    1636,  1778,  1637,  1639,  1826,  1640,  1642,  1827,  1641,    28,
    -854,  1646,  -854,  1647,  -854,  1648,  -854,  1649,  1650,  -854,
    -854,  -854,  -854,  1651,  -854,  1829,  1652,  1653,  1839,  1654,
    1655,  1844,  1657,  1656,  1849,  1659,  -854,  -854,  -854,  -854,
    -854,  1662,  -854,  1663,  -854,  1665,  1666,  -854,  1668,  1673,
    -854,  1677,  1675,  1828,  -854,  1686,  -854,  1687,  -854,  1688,
    -854,  1691,  1697,  -854,  -854,  -854,  -854,  1701,  -854
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       4,     4,     0,     0,     0,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     6,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   119,     0,     0,
       0,     0,   108,   109,   110,   106,   105,   107,   116,   117,
     118,     0,     0,   113,   114,   111,   112,   115,     0,   225,
       0,     0,     0,   104,     5,     9,    10,    11,     0,    12,
      13,    41,    42,    43,    44,    35,    36,    37,    14,    15,
      16,    45,    26,    25,    29,    30,    31,    34,    32,    33,
      38,    39,    40,    28,    27,    17,    18,    19,    20,    21,
      22,    23,    24,    46,     0,   320,   321,   322,   332,   333,
     334,   329,   330,   331,   326,   327,   323,   324,   328,   325,
     319,     0,     0,   458,   459,   456,   460,   461,   462,   463,
     457,   455,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   439,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     336,   337,   338,   345,   346,   347,   344,   348,   349,   341,
     342,   339,   340,   343,   335,   350,   351,   352,     0,     0,
       0,   292,   293,   295,   297,   299,   307,   310,   313,   315,
     317,   104,     0,     0,     0,     0,   137,     0,     0,     0,
       0,     0,   141,     0,     0,     0,     0,     0,     0,     0,
     290,   291,     7,     0,     0,     0,     0,     0,   150,   152,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   465,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   298,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     443,   465,     0,   316,   138,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   135,   223,     0,     0,     0,   136,
     140,     0,     7,     7,     7,     0,     0,   288,   285,     0,
       7,   219,   221,   222,   220,   151,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   252,   253,   250,
       0,   469,     0,   131,   132,     0,     0,     0,   130,     0,
     120,   467,     0,   466,     0,     0,    47,    48,    49,     0,
       0,     0,     0,     0,     0,    67,     0,    68,    69,    65,
      70,     0,     0,     0,     0,     0,     0,     0,    66,   103,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   404,   405,     0,     0,     0,     0,     0,   366,
     385,   386,     0,     0,     0,   393,     0,   395,     0,   397,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   438,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   467,
       0,   464,   294,   296,   300,   301,   304,   305,   302,   303,
     306,   308,   309,   311,   312,   314,   318,     0,     0,     0,
       0,     0,     0,     0,   139,     0,     0,     0,     0,     0,
       0,   286,     0,     0,     8,     0,     0,     0,     0,     0,
       0,     0,     0,   187,     0,     0,   250,     0,     0,     0,
       0,     0,     0,   249,   123,     0,     0,     0,     0,   228,
       0,     0,   121,     0,     0,   124,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   389,   390,   391,   387,   388,   383,   384,
     367,   392,   394,   396,     0,   401,   402,   403,   368,   369,
     370,   371,   372,   373,   374,     0,   381,   382,   406,   407,
     408,   419,   413,   409,   410,   411,   412,   414,   415,   416,
     417,   418,   420,   421,   422,   423,   424,   425,   426,   427,
     428,   429,   430,   431,   432,   433,   434,   435,   436,   437,
     444,   445,   446,   447,   448,   449,   450,   451,   452,   453,
     454,   353,   125,   127,   133,     0,   126,   134,   275,     0,
       0,     0,     0,     7,     7,     0,     7,     0,   152,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   250,
       0,     0,     0,     0,     0,     0,     0,     0,   251,   250,
       0,   470,     0,   230,     0,     0,   229,     7,     0,     0,
     142,   468,     0,    98,    98,    98,     0,     0,     0,     0,
       0,    98,    98,    98,    98,    98,     0,     0,     0,     0,
       0,     0,     0,     0,   224,     0,     0,   273,     0,   277,
     278,     0,     0,     0,     0,   284,     0,   218,   152,     0,
     154,   155,   153,     0,     0,     0,     0,     0,     0,   188,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   233,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   227,     0,     0,     0,   122,     0,     0,
       0,    99,   100,     0,   101,   102,     0,     0,     0,     0,
     101,     0,     0,     0,     0,     0,     0,   101,     0,     0,
       0,     0,     0,     0,     0,    79,     0,     0,     0,     0,
       0,     0,     0,   377,   376,   375,   378,   379,   380,     0,
       7,     0,     0,     7,     0,     7,     0,     0,   157,     0,
     187,     0,   143,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   232,     0,     0,     0,     0,     0,
     240,   250,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   248,   226,   231,     0,   129,     0,
       0,     0,     0,     0,     0,     0,     0,    51,     0,     0,
       0,    52,     0,     0,     0,     0,     0,     0,    53,    98,
      98,    92,    93,    80,    81,    82,    83,    84,     0,     0,
       0,     0,     0,     0,     0,     7,     0,   271,     0,     0,
       0,     0,   217,   157,     0,   156,     0,   187,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   250,
     250,     0,   247,     0,     0,   250,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   246,
     283,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    85,   398,
     399,   400,   440,   441,   442,     0,     7,     0,     7,     0,
       0,     0,     0,     0,   158,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   128,    50,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    54,    55,     0,   279,     0,   281,     0,     7,
       0,     0,     0,     0,     0,     0,   145,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   250,   250,     0,
       0,   250,   250,   250,     0,     0,   245,   250,     0,     0,
       0,     0,     0,     0,     0,   255,   256,     0,     0,   254,
       0,   269,     0,    60,    87,     0,     0,     0,    72,    94,
      62,     0,     0,    73,    95,     0,    59,    86,     0,     0,
       0,     0,     0,    71,    96,     0,     0,     0,     0,     0,
       0,     7,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   144,     0,     0,     0,     0,     0,     0,   191,
       0,     0,   193,     0,     0,   189,     0,   205,     0,     0,
     235,   242,     0,     0,     0,   234,   241,     0,   259,   260,
     258,     0,   270,     0,     0,     0,     0,     0,    57,    64,
      90,    91,     0,     0,    56,    63,     0,     0,    88,    89,
       0,     0,     0,     0,   280,   282,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   199,
       0,   201,     0,   197,     0,     0,     0,   192,     0,     0,
     194,     0,     0,   190,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   257,    77,    78,
      75,    76,     0,    61,    74,    97,     0,     0,     7,   146,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   200,
     202,   198,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   195,   237,   239,   244,   236,   238,
     243,   261,     0,     0,     0,     0,     0,     0,     0,    58,
       7,   147,     0,     0,     0,     0,     0,     0,     0,   161,
       0,     0,   163,     0,     0,   159,     0,   175,     0,   203,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   196,   265,     0,   262,   267,     0,   263,     0,     0,
       0,     0,   169,     0,   171,     0,   167,     0,     0,     0,
     162,     0,     0,   164,     0,     0,   160,     0,   204,     0,
     211,     0,     0,   212,     0,     0,   210,     0,     0,     0,
       0,     0,     0,     0,   148,   170,   172,   168,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     165,     0,   207,     0,   208,     0,   206,     0,     0,   266,
     268,   264,   149,     0,   173,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   166,   215,   216,   214,
     213,     0,   174,     0,   181,     0,     0,   182,     0,     0,
     180,     0,     0,     0,   209,     0,   177,     0,   178,     0,
     176,     0,     0,   185,   186,   184,   183,     0,   179
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -854,  -854,  1590,  -427,   881,  -854,  -854,  -670,  -854,   337,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -690,   579,  -854,  -853,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,  -854,
    -854,   880,  -614,  -854,  -607,  1489,  -854,  -854,  -854,  -854,
    -854,  -854,  -854,  -854,  -854,  -854,  -854,  1502,  -854,  -854,
    -854,   -10,  -854,  1535,  1542,  1809,   174,   480,    51,  -854,
    1704,     5,  -854,  1546,  -854,  4587
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,   439,   624,    65,    66,   888,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,   446,   452,  1014,  1094,   775,
     849,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,   648,   649,    94,   641,   460,   788,    95,   758,   827,
     828,    96,    97,    98,    99,   100,   437,   438,   622,   101,
     102,   461,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   121,   250,   472,   473,   462
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     240,  1316,   475,  1319,   255,   615,   616,   617,  1247,  1250,
     261,  1253,   263,   625,   265,   266,   267,   253,    -3,     6,
    1322,   257,     7,     8,     9,   447,   448,   449,   450,   778,
    1420,   922,   268,   924,   796,   632,   790,  1308,   274,   275,
     276,   277,   465,   288,   642,   288,     1,  1439,  1372,    10,
      11,    12,    13,    14,    15,  1397,    16,    17,    18,    19,
      20,  1248,  1251,  1400,  1254,   285,  1403,   287,  1478,  1442,
    1445,    21,    22,    23,  1505,   949,  1310,  1016,   839,    24,
     785,  1336,     5,    25,    26,   786,    27,   484,  -250,  1193,
    1194,    28,  1312,  -250,   486,    29,    30,    31,   413,   103,
      32,  1373,    33,   104,    34,    35,    36,    37,  1398,   414,
     415,    38,   312,  1337,  1408,    39,  1401,   485,    40,  1404,
    1431,  1479,  1195,   487,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   893,   900,  1433,  1435,    41,   879,
     880,   906,   907,   908,   909,   910,  1493,   122,   927,   795,
    1091,   854,   256,   881,   882,   883,   786,  1158,   647,   884,
     885,  1092,  1197,  1198,  1096,   258,  1072,  1073,  1092,   894,
     895,   264,   855,    37,   289,  1309,   420,   466,   796,   643,
     881,   882,   869,   881,   882,   896,   890,   885,   846,   897,
     885,   269,  1317,   270,  1320,  1199,   923,   847,   925,  1249,
    1252,   271,  1255,   272,    41,   291,   292,   293,   273,   950,
     281,  1323,   787,   886,  1311,    42,    43,   314,   304,    44,
     633,  1421,    45,    46,    47,    48,    49,    50,   402,   476,
    1313,    51,    52,    53,    54,    55,    56,    57,  1440,  1374,
    1074,    58,   290,   898,    59,   278,  1399,   838,    60,    61,
      62,    63,  1409,   889,  1402,  1095,   404,  1405,  1432,  1480,
    1443,  1446,  1167,   426,   847,  1506,   881,   882,   871,   416,
     417,   847,   890,   885,  1434,  1436,   400,   647,   634,   471,
     474,    42,    43,   787,  1494,    44,   279,  1093,    45,    46,
      47,    48,    49,    50,  1093,   280,   453,   454,   455,    53,
      54,    55,    56,    57,   870,   864,   865,   866,   867,   786,
     305,   306,   307,   308,   309,   310,   945,   251,   282,  1076,
    1077,   786,   887,   848,   436,   620,   891,   934,   935,   936,
     937,   283,   531,   532,   533,   534,   833,   834,   311,   836,
     963,  1115,  1179,   542,  1037,   786,   786,   786,   252,  1075,
     254,   284,   899,   286,  1180,   259,   260,   644,   645,   786,
    1184,   315,  1325,  1326,   316,   786,   317,   786,   786,   318,
     874,   671,   645,   572,   573,   574,   575,  1327,   319,  1328,
     320,   635,   786,   321,   786,   457,   458,  1329,  1330,   322,
     848,   589,   786,   786,   578,   579,   405,   848,   868,   323,
     456,  1206,  1207,   587,   457,   458,   953,   954,   955,   956,
     607,   608,   636,   610,  1221,  1222,   324,   612,   613,   325,
     938,  1208,  1108,  1109,   326,   618,   619,   609,  1113,   672,
     645,   459,   327,   407,  1223,   892,   787,  1161,  1162,  1163,
    1164,   408,   409,   410,   411,   412,   780,   781,   787,    -2,
       6,   328,   782,     7,     8,     9,   329,   650,   330,   881,
     882,   447,   448,   449,   450,   890,   885,   603,   604,   605,
     850,   851,   787,   787,   787,   331,   852,   673,   645,   418,
      10,    11,    12,    13,    14,    15,   787,    16,    17,    18,
      19,    20,   787,  1006,   787,   787,  1009,   332,  1011,   957,
     406,   451,    21,    22,    23,   674,   645,  1060,  1061,   787,
      24,   787,   333,  1062,    25,    26,   334,    27,   421,   787,
     787,   335,    28,  1068,  1069,   419,    29,    30,    31,  1070,
    1165,    32,   336,    33,   422,    34,    35,    36,    37,   675,
     645,   337,    38,   105,   106,   338,    39,   107,   339,    40,
     108,   109,   110,   111,   112,   113,   447,   448,   449,   450,
     340,   114,   115,   116,   117,   118,   676,   645,   341,    41,
    1258,  1259,   677,   645,  1262,  1263,  1264,   119,  1085,   120,
    1267,   594,   595,   596,   597,   598,   599,   600,   818,   819,
     820,   821,   822,   823,   999,  1000,  1001,  1002,  1003,  1004,
    1018,  1019,  1020,  1021,  1233,  1234,  1235,  1236,   678,   645,
     679,   645,   680,   645,   681,   645,   755,   682,   645,   683,
     645,   684,   645,   685,   645,   686,   645,   687,   645,   688,
     645,   689,   645,   690,   645,   791,   691,   645,   692,   645,
     342,   798,   693,   645,   801,   343,    42,    43,   698,   645,
      44,   699,   645,    45,    46,    47,    48,    49,    50,  1154,
     344,  1156,    51,    52,    53,    54,    55,    56,    57,   700,
     645,   345,    58,   701,   645,    59,   702,   645,   346,    60,
      61,    62,    63,   347,   817,   703,   645,   704,   645,   761,
     762,   706,   645,   707,   645,   708,   645,   709,   645,   710,
     645,   711,   645,   712,   645,   713,   645,   714,   645,   715,
     645,   716,   645,   717,   645,   718,   645,   719,   645,   720,
     645,   721,   645,   722,   645,   723,   645,   724,   645,   725,
     645,   348,  1232,   726,   645,     6,   727,   645,     7,     8,
       9,   728,   645,   729,   645,   730,   645,   731,   645,   732,
     645,   831,   832,   733,   645,   734,   645,   742,   645,   743,
     645,   744,   645,   745,   645,    10,    11,    12,    13,    14,
      15,   349,    16,    17,    18,    19,    20,   746,   645,   747,
     645,   748,   645,   350,   872,   423,   750,   645,    22,    23,
     414,   415,   793,   794,   424,    24,  -272,  -272,  -272,    25,
      26,   351,    27,   352,  1296,     6,   353,    28,     7,     8,
       9,    29,    30,    31,   354,   919,    32,   355,    33,   356,
      34,    35,    36,    37,   825,   826,   357,    38,   860,   861,
     358,    39,   875,   876,    40,    10,    11,    12,    13,    14,
      15,   359,    16,    17,    18,    19,    20,   942,   943,  1363,
    1364,   360,  1366,  1367,    41,  1369,  1370,   361,    22,    23,
    1382,  1383,  1385,  1386,   362,    24,   969,  1469,  1470,    25,
      26,   363,    27,  1472,  1473,  1475,  1476,    28,  -287,  -287,
    -287,    29,    30,    31,    64,    64,    32,   364,    33,   365,
      34,    35,    36,    37,   601,   602,   366,    38,   367,   368,
     369,    39,   370,   371,    40,   372,   373,   374,   375,   376,
     377,   378,  1008,   379,  1010,   380,   381,   382,   383,   384,
     385,  1392,   386,   387,    41,   388,   389,   390,   391,   392,
     393,    42,    43,   394,   395,    44,   396,   397,    45,    46,
      47,    48,    49,    50,   398,   399,   401,    51,    52,    53,
      54,    55,    56,    57,   425,   431,   427,    58,   428,   429,
      59,   430,  1054,  1429,    60,    61,    62,    63,  1059,   432,
     433,   436,   434,  1065,   435,   440,   441,   442,   443,   444,
     445,   463,   464,   467,   468,   469,   470,   477,   478,   512,
     765,   799,   576,   479,   480,   481,   482,   483,   488,   491,
     489,    42,    43,   490,   492,    44,   493,   494,    45,    46,
      47,    48,    49,    50,   495,   496,   497,    51,    52,    53,
      54,    55,    56,    57,   498,   499,   513,    58,     6,   519,
      59,     7,     8,     9,    60,    61,    62,    63,   520,   521,
     577,   591,   606,  1129,   654,   627,  1132,   611,   614,   626,
     652,   647,   628,   629,  1140,   630,   631,  1143,    10,    11,
      12,    13,    14,    15,   638,    16,    17,    18,    19,    20,
     639,   640,   646,   651,   655,   657,   653,   656,   658,   659,
     660,    22,    23,   661,   664,   670,   662,   663,    24,  -274,
    -274,  -274,    25,    26,   665,    27,   666,   667,   668,   669,
      28,   768,   694,   752,    29,    30,    31,   695,   696,    32,
     697,    33,   705,    34,    35,    36,    37,   735,     6,   736,
      38,     7,     8,     9,    39,   737,   738,    40,   739,   740,
     741,   749,   751,   753,   774,   754,   769,   756,   757,  1226,
     763,   764,   766,   770,   771,   772,   776,    41,    10,    11,
      12,    13,    14,    15,  1297,    16,    17,    18,    19,    20,
     773,   777,   779,   783,   789,   784,   797,   802,   803,   921,
     800,    22,    23,   808,   804,   805,   809,   806,    24,   807,
     816,   810,    25,    26,   811,    27,   812,   813,   814,   815,
      28,   824,   829,   830,    29,    30,    31,   835,   837,    32,
     843,    33,   840,    34,    35,    36,    37,   841,   842,   844,
      38,  1298,   845,   853,    39,  1290,   856,    40,   857,   858,
     862,   859,   863,   873,    42,    43,   877,   903,    44,   878,
     901,    45,    46,    47,    48,    49,    50,    41,   902,   904,
      51,    52,    53,    54,    55,    56,    57,   905,   911,   912,
      58,   913,   929,    59,   914,   915,   916,    60,    61,    62,
      63,   917,   918,   920,   931,   928,   930,   932,   933,   948,
     944,   946,   939,   940,   941,   947,   951,   952,   971,   958,
     970,   959,   974,   960,   961,   962,   964,   965,   966,   968,
     982,   985,   972,   973,   975,   976,   977,   978,  1125,   979,
     980,   981,   983,  1111,   984,   986,   987,   988,   989,   990,
     991,   992,   993,   994,    42,    43,   995,   996,    44,   997,
    1005,    45,    46,    47,    48,    49,    50,   998,  1007,  1012,
      51,    52,    53,    54,    55,    56,    57,  1013,  1015,  1017,
      58,     6,  1022,    59,     7,     8,     9,    60,    61,    62,
      63,  1023,  1024,  1025,  1026,  1027,  1028,  1029,  1031,  1033,
    1030,  1112,  1032,  1048,  1035,  1055,  1034,  1036,  1044,  1038,
    1039,    10,    11,    12,    13,    14,    15,  1346,    16,    17,
      18,    19,    20,  1040,  1041,  1042,  1043,  1045,  1046,  1047,
    1051,  1052,  1079,  1049,    22,    23,  1050,  1053,  1057,  1056,
    1064,    24,  1058,  1063,  1066,    25,    26,  1067,    27,  1071,
    1078,     6,  1080,    28,     7,     8,     9,    29,    30,    31,
    1081,  1082,    32,  1083,    33,  1084,    34,    35,    36,    37,
    1086,  1088,  1101,    38,  1347,  1097,  1098,    39,  1099,  1100,
      40,    10,    11,    12,    13,    14,    15,  1102,    16,    17,
      18,    19,    20,  1103,  1104,  1105,  1106,  1107,  1110,  1114,
      41,  1116,  1117,  1118,    22,    23,  1119,  1120,  1121,  1148,
    1122,    24,  1136,  1127,  1123,    25,    26,  1124,    27,  1126,
    1128,  1130,  1131,    28,  1133,  1134,  1135,    29,    30,    31,
     623,  1137,    32,  1138,    33,  1139,    34,    35,    36,    37,
    1152,  1160,  1141,    38,  1142,  1149,  1144,    39,  1145,  1146,
      40,  1147,  1150,  1151,  1153,  1155,  1157,  1159,  1166,  1168,
    1169,  1170,  1171,  1172,  1173,  1412,   792,  1200,  1177,  1174,
      41,  1175,  1176,  1178,  1181,  1182,  1183,    42,    43,  1186,
    1185,    44,  1187,  1188,    45,    46,    47,    48,    49,    50,
    1189,  1190,  1192,    51,    52,    53,    54,    55,    56,    57,
    1191,  1196,  1201,    58,  1211,  1203,    59,  1202,  1204,  1205,
      60,    61,    62,    63,  1209,  1210,  1212,  1246,  1213,  1215,
    1214,  1216,  1217,  1219,  1220,  1224,  1218,  1227,  1228,  1231,
    1225,     4,  1090,  1237,  1415,  1238,  1239,  1240,  1242,  1241,
    1256,  1271,  1243,  1244,  1245,  1257,  1260,    42,    43,  1261,
    1265,    44,  1266,  1268,    45,    46,    47,    48,    49,    50,
    1269,  1270,  1272,    51,    52,    53,    54,    55,    56,    57,
    1273,  1274,  1275,    58,     6,  1276,    59,     7,     8,     9,
      60,    61,    62,    63,  1277,  1278,  1279,  1282,  1280,  1281,
    1418,  1284,  1285,  1283,  1449,  1288,  1286,  1287,  1289,  1291,
    1292,  1294,  1293,  1295,    10,    11,    12,    13,    14,    15,
    1299,    16,    17,    18,    19,    20,  1300,  1301,  1303,  1302,
    1304,  1305,  1306,  1307,  1315,  1314,  1452,    22,    23,  1324,
    1332,  1318,  1321,  1333,    24,  1331,  1334,  1338,    25,    26,
     759,    27,  1335,  1339,     6,  1342,    28,     7,     8,     9,
      29,    30,    31,  1340,  1341,    32,  1343,    33,  1344,    34,
      35,    36,    37,  1345,  1348,  1349,    38,  1350,  1351,  1352,
      39,  1353,  1354,    40,    10,    11,    12,    13,    14,    15,
    1355,    16,    17,    18,    19,    20,  1356,  1359,  1357,  1358,
    1360,  1361,  1362,    41,  1365,  1368,  1371,    22,    23,  1375,
    1376,  1377,  1378,  1379,    24,  1380,  1381,  1384,    25,    26,
     760,    27,  1387,  1388,  1389,  1390,    28,  1391,  1407,  1393,
      29,    30,    31,  1394,  1395,    32,  1396,    33,  1406,    34,
      35,    36,    37,  1410,  1413,  1411,    38,  1414,  1419,  1416,
      39,  1417,  1422,    40,  1423,  1424,  1425,  1426,  1427,  1428,
    1437,  1438,  1455,  1441,  1458,  1488,  1444,  1448,  1447,  1450,
    1453,  1451,  1456,    41,  1454,  1497,  1457,  1459,  1464,  1460,
      42,    43,  1461,  1462,    44,  1465,  1466,    45,    46,    47,
      48,    49,    50,  1471,  1467,  1468,    51,    52,    53,    54,
      55,    56,    57,  1474,  1477,  1482,    58,  1481,  1484,    59,
    1483,  1486,  1485,    60,    61,    62,    63,  1487,  1489,  1490,
    1495,  1491,  1492,  1500,  1503,  1532,  1496,  1513,  1498,  1499,
    1504,  1501,  1502,  1507,  1508,  1509,  1510,  1516,  1512,  1514,
    1511,  1517,  1519,  1515,  1520,  1518,  1521,  1522,  1523,  1524,
      42,    43,  1526,  1525,    44,  1528,  1527,    45,    46,    47,
      48,    49,    50,  1529,  1530,  1531,    51,    52,    53,    54,
      55,    56,    57,  1533,  1534,  1535,    58,     6,  1536,    59,
       7,     8,     9,    60,    61,    62,    63,  1537,  1538,   621,
     592,   313,   637,   403,     0,     0,     0,   590,   593,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,    12,
      13,    14,    15,     0,    16,    17,    18,    19,    20,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      22,    23,     0,     0,     0,     0,     0,    24,     0,     0,
       0,    25,    26,     0,    27,     0,     0,     6,     0,    28,
       7,     8,     9,    29,    30,    31,     0,     0,    32,   767,
      33,     0,    34,    35,    36,    37,     0,     0,     0,    38,
       0,     0,     0,    39,     0,     0,    40,    10,    11,    12,
      13,    14,    15,     0,    16,    17,    18,    19,    20,     0,
       0,     0,     0,     0,     0,     0,    41,     0,     0,     0,
      22,    23,     0,     0,     0,     0,     0,    24,     0,     0,
       0,    25,    26,     0,    27,     0,     0,     0,     0,    28,
       0,     0,  -289,    29,    30,    31,     0,     0,    32,     0,
      33,     0,    34,    35,    36,    37,     0,     0,     0,    38,
       0,     0,     0,    39,     0,     0,    40,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    41,     0,     0,     0,
       0,     0,     0,    42,    43,     0,     0,    44,     0,     0,
      45,    46,    47,    48,    49,    50,     0,     0,     0,    51,
      52,    53,    54,    55,    56,    57,     0,     0,     0,    58,
       0,     0,    59,     0,     0,     0,    60,    61,    62,    63,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    42,    43,     0,     0,    44,     0,     0,
      45,    46,    47,    48,    49,    50,     0,     0,     0,    51,
      52,    53,    54,    55,    56,    57,     0,     0,     0,    58,
       6,     0,    59,     7,     8,     9,    60,    61,    62,    63,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,    12,    13,    14,    15,     0,    16,    17,    18,
      19,    20,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,    23,     0,     0,     0,     0,     0,
      24,     0,     0,     0,    25,    26,     0,    27,     0,     0,
       6,     0,    28,     7,     8,     9,    29,    30,    31,     0,
     926,    32,     0,    33,     0,    34,    35,    36,    37,     0,
       0,     0,    38,     0,     0,     0,    39,     0,     0,    40,
      10,    11,    12,    13,    14,    15,     0,    16,    17,    18,
      19,    20,     0,     0,     0,     0,     0,     0,     0,    41,
       0,     0,     0,    22,    23,     0,     0,     0,     0,     0,
      24,     0,     0,     0,    25,    26,     0,    27,   967,     0,
       0,     0,    28,     0,     0,     0,    29,    30,    31,     0,
       0,    32,     0,    33,     0,    34,    35,    36,    37,     0,
       0,     0,    38,     0,     0,     0,    39,     0,     0,    40,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    41,
       0,     0,     0,     0,     0,     0,    42,    43,     0,     0,
      44,     0,     0,    45,    46,    47,    48,    49,    50,     0,
       0,     0,    51,    52,    53,    54,    55,    56,    57,     0,
       0,     0,    58,     0,     0,    59,     0,     0,     0,    60,
      61,    62,    63,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    42,    43,     0,     0,
      44,     0,     0,    45,    46,    47,    48,    49,    50,     0,
       0,     0,    51,    52,    53,    54,    55,    56,    57,     0,
       0,     0,    58,     6,     0,    59,     7,     8,     9,    60,
      61,    62,    63,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,    12,    13,    14,    15,     0,
      16,    17,    18,    19,    20,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    22,    23,     0,     0,
       0,     0,     0,    24,     0,     0,  -276,    25,    26,     0,
      27,     0,     0,     6,     0,    28,     7,     8,     9,    29,
      30,    31,     0,     0,    32,     0,    33,     0,    34,    35,
      36,    37,     0,     0,     0,    38,     0,     0,     0,    39,
       0,     0,    40,    10,    11,    12,    13,    14,    15,     0,
      16,    17,    18,    19,    20,     0,     0,     0,     0,     0,
       0,     0,    41,     0,     0,     0,    22,    23,     0,     0,
       0,     0,     0,    24,     0,     0,     0,    25,    26,     0,
      27,  1087,     0,     0,     0,    28,     0,     0,     0,    29,
      30,    31,     0,     0,    32,     0,    33,     0,    34,    35,
      36,    37,     0,     0,     0,    38,     0,     0,     0,    39,
       0,     0,    40,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    41,     0,     0,     0,     0,     0,     0,    42,
      43,     0,     0,    44,     0,     0,    45,    46,    47,    48,
      49,    50,     0,     0,     0,    51,    52,    53,    54,    55,
      56,    57,     0,     0,     0,    58,     0,     0,    59,     0,
       0,     0,    60,    61,    62,    63,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    42,
      43,     0,     0,    44,     0,     0,    45,    46,    47,    48,
      49,    50,     0,     0,     0,    51,    52,    53,    54,    55,
      56,    57,     0,     0,     0,    58,     6,     0,    59,     7,
       8,     9,    60,    61,    62,    63,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,    12,    13,
      14,    15,     0,    16,    17,    18,    19,    20,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    22,
      23,     0,     0,     0,     0,     0,    24,     0,     0,     0,
      25,    26,     0,    27,  1089,     0,     6,     0,    28,     7,
       8,     9,    29,    30,    31,     0,     0,    32,     0,    33,
       0,    34,    35,    36,    37,     0,     0,     0,    38,     0,
       0,     0,    39,     0,     0,    40,    10,    11,    12,    13,
      14,    15,     0,    16,    17,    18,    19,    20,     0,     0,
       0,     0,     0,     0,     0,    41,     0,     0,     0,    22,
      23,     0,     0,     0,     0,     0,    24,     0,     0,     0,
      25,    26,     0,    27,  1229,     0,     0,     0,    28,     0,
       0,     0,    29,    30,    31,     0,     0,    32,     0,    33,
       0,    34,    35,    36,    37,     0,     0,     0,    38,     0,
       0,     0,    39,     0,     0,    40,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    41,     0,     0,     0,     0,
       0,     0,    42,    43,     0,     0,    44,     0,     0,    45,
      46,    47,    48,    49,    50,     0,     0,     0,    51,    52,
      53,    54,    55,    56,    57,     0,     0,     0,    58,     0,
       0,    59,     0,     0,     0,    60,    61,    62,    63,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    42,    43,     0,     0,    44,     0,     0,    45,
      46,    47,    48,    49,    50,     0,     0,     0,    51,    52,
      53,    54,    55,    56,    57,     0,     0,     0,    58,     6,
       0,    59,     7,     8,     9,    60,    61,    62,    63,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
      11,    12,    13,    14,    15,     0,    16,    17,    18,    19,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    22,    23,     0,     0,     0,     0,     0,    24,
       0,     0,     0,    25,    26,     0,    27,  1230,     0,     6,
       0,    28,     7,     8,     9,    29,    30,    31,     0,     0,
      32,     0,    33,     0,    34,    35,    36,    37,     0,     0,
       0,    38,     0,     0,     0,    39,     0,     0,    40,    10,
      11,    12,    13,    14,    15,     0,    16,    17,    18,    19,
      20,     0,     0,     0,     0,     0,     0,     0,    41,     0,
       0,     0,    22,    23,     0,     0,     0,     0,     0,    24,
       0,     0,     0,    25,    26,     0,    27,     0,     0,     0,
       0,    28,     0,     0,     0,    29,    30,    31,     0,     0,
      32,     0,    33,     0,    34,    35,    36,    37,     0,     0,
       0,    38,  1430,     0,     0,    39,     0,     0,    40,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    41,     0,
       0,     0,     0,     0,     0,    42,    43,     0,     0,    44,
       0,     0,    45,    46,    47,    48,    49,    50,     0,     0,
       0,    51,    52,    53,    54,    55,    56,    57,     0,     0,
       0,    58,     0,     0,    59,     0,     0,     0,    60,    61,
      62,    63,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    42,    43,     0,     0,    44,
       0,     0,    45,    46,    47,    48,    49,    50,     0,     0,
       0,    51,    52,    53,    54,    55,    56,    57,     0,     0,
       0,    58,     6,     0,    59,     7,     8,     9,    60,    61,
      62,    63,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,    11,    12,    13,    14,    15,     0,    16,
      17,    18,    19,    20,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    22,    23,     0,     0,     0,
       0,     0,    24,     0,     0,     0,    25,    26,     0,    27,
       0,     0,     0,     0,    28,     0,     0,     0,    29,    30,
      31,     0,     0,    32,     0,    33,     0,    34,    35,    36,
      37,     0,     0,     0,    38,  1463,     0,     0,    39,     0,
       0,    40,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    41,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   123,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   124,     0,     0,     0,     0,     0,
       0,     0,   125,   126,   127,   128,   129,     0,    42,    43,
       0,     0,    44,     0,     0,    45,    46,    47,    48,    49,
      50,     0,     0,     0,    51,    52,    53,    54,    55,    56,
      57,   130,     0,     0,    58,   131,     0,    59,   132,     0,
       0,    60,    61,    62,    63,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,     0,   219,   220,   221,     0,     0,   222,     0,     0,
     223,   224,   225,   226,   227,   228,     0,   123,     0,     0,
       0,   229,   230,   231,   232,   233,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   234,
     235,   236,   237,   262,   124,   238,     0,     0,     0,   239,
       0,     0,   125,   126,   127,   128,   129,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   130,     0,     0,     0,   131,     0,     0,   132,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   212,   213,   214,   215,   216,   217,
     218,     0,   219,   220,   221,     0,     0,   222,     0,     0,
     223,   224,   225,   226,   227,   228,   123,     0,     0,     0,
       0,   229,   230,   231,   232,   233,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   234,
     235,   236,   237,   124,     0,   238,   525,     0,     0,   239,
       0,   125,   126,   127,   128,   129,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     130,     0,     0,     0,   131,     0,     0,   132,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
       0,   219,   220,   221,     0,     0,   222,     0,     0,   223,
     224,   225,   226,   227,   228,   123,     0,     0,     0,     0,
     229,   230,   231,   232,   233,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   234,   235,
     236,   237,   124,     0,   238,   527,     0,     0,   239,     0,
     125,   126,   127,   128,   129,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   130,
       0,     0,     0,   131,     0,     0,   132,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,   216,   217,   218,     0,
     219,   220,   221,     0,     0,   222,     0,     0,   223,   224,
     225,   226,   227,   228,   123,     0,     0,     0,     0,   229,
     230,   231,   232,   233,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   234,   235,   236,
     237,   124,     0,   238,   529,     0,     0,   239,     0,   125,
     126,   127,   128,   129,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   130,     0,
       0,     0,   131,     0,     0,   132,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,     0,   219,
     220,   221,     0,     0,   222,     0,     0,   223,   224,   225,
     226,   227,   228,   123,     0,     0,     0,     0,   229,   230,
     231,   232,   233,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   234,   235,   236,   237,
     124,     0,   238,     0,     0,     0,   239,     0,   125,   126,
     127,   128,   129,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   130,     0,     0,
       0,   131,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   217,   218,     0,   219,   220,
     221,     0,     0,   222,     0,     0,   223,   224,   225,   226,
     227,   228,   123,     0,     0,     0,     0,   229,   230,   231,
     232,   233,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   234,   235,   236,   237,   124,
       0,   238,     0,     0,     0,   239,     0,   125,   126,   127,
     128,   129,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   130,     0,     0,     0,
     131,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,     0,   219,   220,   221,
       0,     0,   222,     0,     0,   223,   224,   225,   226,   227,
     228,     0,     0,     0,     0,     0,   229,   230,   231,   232,
     233,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   234,   235,   236,   237,     0,     0,
     238,   500,   501,   502,   503,   504,   505,   506,   507,   508,
     509,   510,   511,     0,     0,   514,   515,   516,   517,   518,
       0,     0,     0,   522,   523,   524,   526,   528,   530,     0,
       0,     0,     0,   535,   536,   537,   538,   539,   540,   541,
       0,   543,   544,   545,   546,   547,   548,   549,   550,   551,
     552,   553,   554,   555,   556,   557,   558,   559,   560,   561,
     562,   563,   564,   565,   566,   567,   568,   569,   570,   571,
       0,     0,     0,     0,     0,     0,     0,     0,   580,   581,
     582,   583,   584,   585,   586,     0,   588
};

static const yytype_int16 yycheck[] =
{
      10,    46,    10,    46,    14,   432,   433,   434,    46,    46,
      20,    46,    22,   440,    24,    25,    26,    12,     0,     1,
      46,    16,     4,     5,     6,    11,    12,    13,    14,   636,
      46,    72,    27,    72,   648,    52,   643,    99,    33,    34,
      35,    36,   102,   108,   102,   108,     3,    46,    46,    31,
      32,    33,    34,    35,    36,    46,    38,    39,    40,    41,
      42,    99,    99,    46,    99,    60,    46,    62,    46,    46,
      46,    53,    54,    55,    46,   103,    99,   930,   768,    61,
     101,   205,     0,    65,    66,   106,    68,   207,   101,   204,
     205,    73,    99,   106,   208,    77,    78,    79,   231,   237,
      82,    99,    84,   233,    86,    87,    88,    89,    99,   242,
     243,    93,   122,   237,    99,    97,    99,   237,   100,    99,
      99,    99,   237,   237,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,   804,   805,    99,    99,   120,    29,
      30,   811,   812,   813,   814,   815,    99,   233,   838,   224,
      96,   101,   237,    43,    44,    45,   106,    96,   233,    49,
      50,   107,   204,   205,  1017,   239,    29,    30,   107,    29,
      30,   238,   779,    89,   239,   237,   239,   237,   792,   237,
      43,    44,   789,    43,    44,    45,    49,    50,    98,    49,
      50,   237,   237,   237,   237,   237,   237,   107,   237,   237,
     237,   237,   237,   237,   120,     7,     8,     9,   233,   237,
     239,   237,   233,   103,   237,   197,   198,   239,   105,   201,
     237,   237,   204,   205,   206,   207,   208,   209,   238,   237,
     237,   213,   214,   215,   216,   217,   218,   219,   237,   237,
     103,   223,   238,   103,   226,   233,   237,   233,   230,   231,
     232,   233,   237,    30,   237,    98,   237,   237,   237,   237,
     237,   237,    98,   258,   107,   237,    43,    44,   224,   244,
     245,   107,    49,    50,   237,   237,   236,   233,   103,   289,
     290,   197,   198,   233,   237,   201,   233,   233,   204,   205,
     206,   207,   208,   209,   233,   233,   102,   103,   104,   215,
     216,   217,   218,   219,   101,    11,    12,    13,    14,   106,
     197,   198,   199,   200,   201,   202,   101,   233,   233,   989,
     990,   106,   212,   233,    74,    75,   103,    11,    12,    13,
      14,   233,   342,   343,   344,   345,   763,   764,   225,   766,
     101,   101,   101,   353,   951,   106,   106,   106,    11,   212,
      13,   233,   212,   233,   101,    18,    19,   240,   241,   106,
     101,   239,   101,   101,   239,   106,   239,   106,   106,   239,
     797,   240,   241,   383,   384,   385,   386,   101,   239,   101,
     239,   206,   106,   239,   106,   210,   211,   101,   101,   239,
     233,   401,   106,   106,   389,   390,    91,   233,   104,   239,
     206,   217,   218,   398,   210,   211,    11,    12,    13,    14,
     420,   421,   237,   423,   217,   218,   239,   427,   428,   239,
     104,   237,  1029,  1030,   239,   435,   436,   422,  1035,   240,
     241,   237,   239,   238,   237,   212,   233,    11,    12,    13,
      14,   246,   247,   248,   249,   250,   228,   229,   233,     0,
       1,   239,   234,     4,     5,     6,   239,   467,   239,    43,
      44,    11,    12,    13,    14,    49,    50,   416,   417,   418,
     228,   229,   233,   233,   233,   239,   234,   240,   241,   227,
      31,    32,    33,    34,    35,    36,   233,    38,    39,    40,
      41,    42,   233,   920,   233,   233,   923,   239,   925,   104,
      90,    51,    53,    54,    55,   240,   241,   228,   229,   233,
      61,   233,   239,   234,    65,    66,   239,    68,   238,   233,
     233,   239,    73,   228,   229,   108,    77,    78,    79,   234,
     104,    82,   239,    84,   238,    86,    87,    88,    89,   240,
     241,   239,    93,   197,   198,   239,    97,   201,   239,   100,
     204,   205,   206,   207,   208,   209,    11,    12,    13,    14,
     239,   215,   216,   217,   218,   219,   240,   241,   239,   120,
    1177,  1178,   240,   241,  1181,  1182,  1183,   231,  1005,   233,
    1187,   407,   408,   409,   410,   411,   412,   413,    22,    23,
      24,    25,    26,    27,    22,    23,    24,    25,    26,    27,
      11,    12,    13,    14,    11,    12,    13,    14,   240,   241,
     240,   241,   240,   241,   240,   241,   611,   240,   241,   240,
     241,   240,   241,   240,   241,   240,   241,   240,   241,   240,
     241,   240,   241,   240,   241,   645,   240,   241,   240,   241,
     239,   651,   240,   241,   654,   239,   197,   198,   240,   241,
     201,   240,   241,   204,   205,   206,   207,   208,   209,  1086,
     239,  1088,   213,   214,   215,   216,   217,   218,   219,   240,
     241,   239,   223,   240,   241,   226,   240,   241,   239,   230,
     231,   232,   233,   239,   694,   240,   241,   240,   241,    70,
      71,   240,   241,   240,   241,   240,   241,   240,   241,   240,
     241,   240,   241,   240,   241,   240,   241,   240,   241,   240,
     241,   240,   241,   240,   241,   240,   241,   240,   241,   240,
     241,   240,   241,   240,   241,   240,   241,   240,   241,   240,
     241,   239,  1159,   240,   241,     1,   240,   241,     4,     5,
       6,   240,   241,   240,   241,   240,   241,   240,   241,   240,
     241,   761,   762,   240,   241,   240,   241,   240,   241,   240,
     241,   240,   241,   240,   241,    31,    32,    33,    34,    35,
      36,   239,    38,    39,    40,    41,    42,   240,   241,   240,
     241,   240,   241,   239,   794,   238,   240,   241,    54,    55,
     242,   243,   237,   238,   237,    61,    62,    63,    64,    65,
      66,   239,    68,   239,  1231,     1,   239,    73,     4,     5,
       6,    77,    78,    79,   239,   825,    82,   239,    84,   239,
      86,    87,    88,    89,    62,    63,   239,    93,   240,   241,
     239,    97,   240,   241,   100,    31,    32,    33,    34,    35,
      36,   239,    38,    39,    40,    41,    42,   240,   241,    47,
      48,   239,    47,    48,   120,    47,    48,   239,    54,    55,
     240,   241,   240,   241,   239,    61,   876,    47,    48,    65,
      66,   239,    68,    47,    48,    47,    48,    73,    74,    75,
      76,    77,    78,    79,     3,     4,    82,   239,    84,   239,
      86,    87,    88,    89,   414,   415,   239,    93,   239,   239,
     239,    97,   239,   239,   100,   239,   239,   239,   239,   239,
     239,   239,   922,   239,   924,   239,   239,   239,   239,   239,
     239,  1348,   239,   239,   120,   239,   239,   239,   239,   239,
     239,   197,   198,   239,   239,   201,   239,   239,   204,   205,
     206,   207,   208,   209,   239,   239,   239,   213,   214,   215,
     216,   217,   218,   219,   237,    56,   238,   223,   238,   237,
     226,   237,   972,  1390,   230,   231,   232,   233,   978,   237,
     237,    74,   237,   983,   238,   237,   237,   237,   237,   237,
      49,   237,   237,   231,   237,   195,   233,   237,   237,   240,
      76,   108,   233,   239,   239,   239,   239,   239,   237,   239,
     237,   197,   198,   237,   239,   201,   239,   239,   204,   205,
     206,   207,   208,   209,   239,   239,   239,   213,   214,   215,
     216,   217,   218,   219,   237,   237,   240,   223,     1,   240,
     226,     4,     5,     6,   230,   231,   232,   233,   240,   240,
     240,   240,   233,  1053,   241,   239,  1056,   240,   237,   237,
     240,   233,   239,   239,  1064,   239,   239,  1067,    31,    32,
      33,    34,    35,    36,   239,    38,    39,    40,    41,    42,
     239,   239,   237,   239,   237,   234,   240,   239,   234,   234,
     234,    54,    55,   234,   233,   203,   239,   239,    61,    62,
      63,    64,    65,    66,   234,    68,   234,   234,   234,   234,
      73,    95,   241,   237,    77,    78,    79,   240,   240,    82,
     240,    84,   241,    86,    87,    88,    89,   240,     1,   240,
      93,     4,     5,     6,    97,   240,   240,   100,   240,   240,
     240,   240,   240,   237,   239,   237,   234,   237,   237,  1149,
     237,   237,   237,   234,   234,   234,   239,   120,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
     236,   239,   237,   233,   237,   233,   237,   244,   240,    64,
     237,    54,    55,   233,   240,   240,   233,   241,    61,   241,
     241,   240,    65,    66,   240,    68,   240,   240,   240,   240,
      73,   237,   237,   237,    77,    78,    79,   237,   237,    82,
     241,    84,   240,    86,    87,    88,    89,   240,   240,   240,
      93,    94,   236,   233,    97,  1225,   241,   100,   241,   240,
     237,   240,   233,   237,   197,   198,   233,   240,   201,   241,
     234,   204,   205,   206,   207,   208,   209,   120,   234,   240,
     213,   214,   215,   216,   217,   218,   219,   237,   236,   241,
     223,   240,   234,   226,   240,   240,   240,   230,   231,   232,
     233,   240,   240,   237,   240,   237,   237,   237,   233,   102,
     237,   234,   241,   241,   240,   234,   237,   234,    30,   239,
     244,   239,    30,   239,   239,   239,   237,   237,   237,   237,
      30,    30,   239,   239,   239,   239,   237,   239,   241,   239,
     239,   237,   239,   102,   239,   239,   239,   237,   240,   240,
     237,   237,   237,   237,   197,   198,   237,   237,   201,   237,
     237,   204,   205,   206,   207,   208,   209,   240,   237,   237,
     213,   214,   215,   216,   217,   218,   219,   237,   240,   237,
     223,     1,   239,   226,     4,     5,     6,   230,   231,   232,
     233,   239,   239,   239,   239,   234,   234,   237,   234,   240,
     237,   102,   237,   233,   237,   233,   240,   239,   234,   240,
     239,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,   239,   239,   239,   239,   234,   234,   234,
     240,   240,   240,   237,    54,    55,   237,   239,   234,   239,
     239,    61,   233,   233,   233,    65,    66,   239,    68,   233,
     237,     1,   240,    73,     4,     5,     6,    77,    78,    79,
     240,   240,    82,   240,    84,   240,    86,    87,    88,    89,
     237,   237,   234,    93,    94,   239,   239,    97,   239,   239,
     100,    31,    32,    33,    34,    35,    36,   234,    38,    39,
      40,    41,    42,   234,   234,   233,   240,   240,   240,   234,
     120,   102,   234,   234,    54,    55,   234,   234,   233,    30,
     240,    61,   241,   237,   240,    65,    66,   240,    68,   240,
     237,   240,   240,    73,   240,   240,   240,    77,    78,    79,
      80,   241,    82,   240,    84,   240,    86,    87,    88,    89,
     237,   233,   240,    93,   240,   239,   241,    97,   241,   240,
     100,   240,   239,   239,   237,   237,   237,   237,   237,   234,
     234,   234,   234,   240,   240,    47,   646,   234,   237,   240,
     120,   241,   240,   237,   237,   237,   237,   197,   198,   237,
     240,   201,   237,   240,   204,   205,   206,   207,   208,   209,
     240,   240,   240,   213,   214,   215,   216,   217,   218,   219,
     241,   237,   237,   223,   234,   237,   226,   240,   237,   240,
     230,   231,   232,   233,   237,   237,   234,   241,   237,   240,
     237,   237,   237,   234,   234,   237,   240,   234,   233,   237,
     239,     1,  1013,   239,    47,   239,   239,   239,   237,   239,
     234,   234,   240,   240,   240,   237,   237,   197,   198,   237,
     237,   201,   237,   237,   204,   205,   206,   207,   208,   209,
     237,   237,   237,   213,   214,   215,   216,   217,   218,   219,
     239,   239,   239,   223,     1,   239,   226,     4,     5,     6,
     230,   231,   232,   233,   240,   237,   237,   240,   237,   237,
      47,   237,   237,   240,    48,   237,   240,   240,   237,   240,
     240,   237,   240,   237,    31,    32,    33,    34,    35,    36,
     239,    38,    39,    40,    41,    42,   239,   239,   234,   239,
     234,   234,   234,   233,   239,   234,    48,    54,    55,   240,
     233,   239,   239,   234,    61,   240,   233,   237,    65,    66,
      67,    68,   234,   237,     1,   240,    73,     4,     5,     6,
      77,    78,    79,   237,   237,    82,   237,    84,   237,    86,
      87,    88,    89,   237,   237,   237,    93,   234,   234,   234,
      97,   234,   240,   100,    31,    32,    33,    34,    35,    36,
     240,    38,    39,    40,    41,    42,   240,   237,   241,   240,
     237,   237,   240,   120,   239,   239,   239,    54,    55,   237,
     237,   237,   237,   237,    61,   237,   237,   240,    65,    66,
      67,    68,   240,   239,   237,   237,    73,   237,   237,   240,
      77,    78,    79,   240,   240,    82,   241,    84,   234,    86,
      87,    88,    89,   241,   241,   240,    93,   240,   239,   241,
      97,   240,   237,   100,   234,   237,   237,   234,   237,   234,
     234,   239,    48,   239,    48,    47,   239,   237,   240,   237,
     237,   240,   237,   120,   240,    47,   240,   239,   237,   240,
     197,   198,   240,   240,   201,   237,   237,   204,   205,   206,
     207,   208,   209,   239,   237,   240,   213,   214,   215,   216,
     217,   218,   219,   239,   239,   237,   223,   240,   237,   226,
     240,   237,   240,   230,   231,   232,   233,   240,   237,   237,
     241,   237,   237,    47,    47,    47,   240,    48,   241,   240,
     239,   241,   240,   237,   237,   237,   237,    48,   237,   237,
     240,   237,    48,   240,   237,   240,   240,    48,   239,   237,
     197,   198,   237,   240,   201,   237,   240,   204,   205,   206,
     207,   208,   209,   240,   237,   240,   213,   214,   215,   216,
     217,   218,   219,   237,   237,   237,   223,     1,   237,   226,
       4,     5,     6,   230,   231,   232,   233,   240,   237,   437,
     405,   132,   453,   239,    -1,    -1,    -1,   401,   406,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    55,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    65,    66,    -1,    68,    -1,    -1,     1,    -1,    73,
       4,     5,     6,    77,    78,    79,    -1,    -1,    82,    83,
      84,    -1,    86,    87,    88,    89,    -1,    -1,    -1,    93,
      -1,    -1,    -1,    97,    -1,    -1,   100,    31,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,    -1,    -1,
      54,    55,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    65,    66,    -1,    68,    -1,    -1,    -1,    -1,    73,
      -1,    -1,    76,    77,    78,    79,    -1,    -1,    82,    -1,
      84,    -1,    86,    87,    88,    89,    -1,    -1,    -1,    93,
      -1,    -1,    -1,    97,    -1,    -1,   100,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,    -1,    -1,
      -1,    -1,    -1,   197,   198,    -1,    -1,   201,    -1,    -1,
     204,   205,   206,   207,   208,   209,    -1,    -1,    -1,   213,
     214,   215,   216,   217,   218,   219,    -1,    -1,    -1,   223,
      -1,    -1,   226,    -1,    -1,    -1,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   197,   198,    -1,    -1,   201,    -1,    -1,
     204,   205,   206,   207,   208,   209,    -1,    -1,    -1,   213,
     214,   215,   216,   217,   218,   219,    -1,    -1,    -1,   223,
       1,    -1,   226,     4,     5,     6,   230,   231,   232,   233,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    65,    66,    -1,    68,    -1,    -1,
       1,    -1,    73,     4,     5,     6,    77,    78,    79,    -1,
      81,    82,    -1,    84,    -1,    86,    87,    88,    89,    -1,
      -1,    -1,    93,    -1,    -1,    -1,    97,    -1,    -1,   100,
      31,    32,    33,    34,    35,    36,    -1,    38,    39,    40,
      41,    42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,
      -1,    -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    -1,
      61,    -1,    -1,    -1,    65,    66,    -1,    68,    69,    -1,
      -1,    -1,    73,    -1,    -1,    -1,    77,    78,    79,    -1,
      -1,    82,    -1,    84,    -1,    86,    87,    88,    89,    -1,
      -1,    -1,    93,    -1,    -1,    -1,    97,    -1,    -1,   100,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,
      -1,    -1,    -1,    -1,    -1,    -1,   197,   198,    -1,    -1,
     201,    -1,    -1,   204,   205,   206,   207,   208,   209,    -1,
      -1,    -1,   213,   214,   215,   216,   217,   218,   219,    -1,
      -1,    -1,   223,    -1,    -1,   226,    -1,    -1,    -1,   230,
     231,   232,   233,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   197,   198,    -1,    -1,
     201,    -1,    -1,   204,   205,   206,   207,   208,   209,    -1,
      -1,    -1,   213,   214,   215,   216,   217,   218,   219,    -1,
      -1,    -1,   223,     1,    -1,   226,     4,     5,     6,   230,
     231,   232,   233,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    -1,    -1,
      -1,    -1,    -1,    61,    -1,    -1,    64,    65,    66,    -1,
      68,    -1,    -1,     1,    -1,    73,     4,     5,     6,    77,
      78,    79,    -1,    -1,    82,    -1,    84,    -1,    86,    87,
      88,    89,    -1,    -1,    -1,    93,    -1,    -1,    -1,    97,
      -1,    -1,   100,    31,    32,    33,    34,    35,    36,    -1,
      38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   120,    -1,    -1,    -1,    54,    55,    -1,    -1,
      -1,    -1,    -1,    61,    -1,    -1,    -1,    65,    66,    -1,
      68,    69,    -1,    -1,    -1,    73,    -1,    -1,    -1,    77,
      78,    79,    -1,    -1,    82,    -1,    84,    -1,    86,    87,
      88,    89,    -1,    -1,    -1,    93,    -1,    -1,    -1,    97,
      -1,    -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,   197,
     198,    -1,    -1,   201,    -1,    -1,   204,   205,   206,   207,
     208,   209,    -1,    -1,    -1,   213,   214,   215,   216,   217,
     218,   219,    -1,    -1,    -1,   223,    -1,    -1,   226,    -1,
      -1,    -1,   230,   231,   232,   233,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   197,
     198,    -1,    -1,   201,    -1,    -1,   204,   205,   206,   207,
     208,   209,    -1,    -1,    -1,   213,   214,   215,   216,   217,
     218,   219,    -1,    -1,    -1,   223,     1,    -1,   226,     4,
       5,     6,   230,   231,   232,   233,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54,
      55,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      65,    66,    -1,    68,    69,    -1,     1,    -1,    73,     4,
       5,     6,    77,    78,    79,    -1,    -1,    82,    -1,    84,
      -1,    86,    87,    88,    89,    -1,    -1,    -1,    93,    -1,
      -1,    -1,    97,    -1,    -1,   100,    31,    32,    33,    34,
      35,    36,    -1,    38,    39,    40,    41,    42,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   120,    -1,    -1,    -1,    54,
      55,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      65,    66,    -1,    68,    69,    -1,    -1,    -1,    73,    -1,
      -1,    -1,    77,    78,    79,    -1,    -1,    82,    -1,    84,
      -1,    86,    87,    88,    89,    -1,    -1,    -1,    93,    -1,
      -1,    -1,    97,    -1,    -1,   100,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   120,    -1,    -1,    -1,    -1,
      -1,    -1,   197,   198,    -1,    -1,   201,    -1,    -1,   204,
     205,   206,   207,   208,   209,    -1,    -1,    -1,   213,   214,
     215,   216,   217,   218,   219,    -1,    -1,    -1,   223,    -1,
      -1,   226,    -1,    -1,    -1,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   197,   198,    -1,    -1,   201,    -1,    -1,   204,
     205,   206,   207,   208,   209,    -1,    -1,    -1,   213,   214,
     215,   216,   217,   218,   219,    -1,    -1,    -1,   223,     1,
      -1,   226,     4,     5,     6,   230,   231,   232,   233,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    65,    66,    -1,    68,    69,    -1,     1,
      -1,    73,     4,     5,     6,    77,    78,    79,    -1,    -1,
      82,    -1,    84,    -1,    86,    87,    88,    89,    -1,    -1,
      -1,    93,    -1,    -1,    -1,    97,    -1,    -1,   100,    31,
      32,    33,    34,    35,    36,    -1,    38,    39,    40,    41,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,
      -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    65,    66,    -1,    68,    -1,    -1,    -1,
      -1,    73,    -1,    -1,    -1,    77,    78,    79,    -1,    -1,
      82,    -1,    84,    -1,    86,    87,    88,    89,    -1,    -1,
      -1,    93,    94,    -1,    -1,    97,    -1,    -1,   100,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   120,    -1,
      -1,    -1,    -1,    -1,    -1,   197,   198,    -1,    -1,   201,
      -1,    -1,   204,   205,   206,   207,   208,   209,    -1,    -1,
      -1,   213,   214,   215,   216,   217,   218,   219,    -1,    -1,
      -1,   223,    -1,    -1,   226,    -1,    -1,    -1,   230,   231,
     232,   233,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   197,   198,    -1,    -1,   201,
      -1,    -1,   204,   205,   206,   207,   208,   209,    -1,    -1,
      -1,   213,   214,   215,   216,   217,   218,   219,    -1,    -1,
      -1,   223,     1,    -1,   226,     4,     5,     6,   230,   231,
     232,   233,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    33,    34,    35,    36,    -1,    38,
      39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    55,    -1,    -1,    -1,
      -1,    -1,    61,    -1,    -1,    -1,    65,    66,    -1,    68,
      -1,    -1,    -1,    -1,    73,    -1,    -1,    -1,    77,    78,
      79,    -1,    -1,    82,    -1,    84,    -1,    86,    87,    88,
      89,    -1,    -1,    -1,    93,    94,    -1,    -1,    97,    -1,
      -1,   100,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   120,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    57,    58,    59,    60,    -1,   197,   198,
      -1,    -1,   201,    -1,    -1,   204,   205,   206,   207,   208,
     209,    -1,    -1,    -1,   213,   214,   215,   216,   217,   218,
     219,    85,    -1,    -1,   223,    89,    -1,   226,    92,    -1,
      -1,   230,   231,   232,   233,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,    -1,   196,   197,   198,    -1,    -1,   201,    -1,    -1,
     204,   205,   206,   207,   208,   209,    -1,    21,    -1,    -1,
      -1,   215,   216,   217,   218,   219,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   233,
     234,   235,   236,   237,    48,   239,    -1,    -1,    -1,   243,
      -1,    -1,    56,    57,    58,    59,    60,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85,    -1,    -1,    -1,    89,    -1,    -1,    92,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,    -1,   196,   197,   198,    -1,    -1,   201,    -1,    -1,
     204,   205,   206,   207,   208,   209,    21,    -1,    -1,    -1,
      -1,   215,   216,   217,   218,   219,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   233,
     234,   235,   236,    48,    -1,   239,   240,    -1,    -1,   243,
      -1,    56,    57,    58,    59,    60,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      85,    -1,    -1,    -1,    89,    -1,    -1,    92,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   193,   194,
      -1,   196,   197,   198,    -1,    -1,   201,    -1,    -1,   204,
     205,   206,   207,   208,   209,    21,    -1,    -1,    -1,    -1,
     215,   216,   217,   218,   219,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   233,   234,
     235,   236,    48,    -1,   239,   240,    -1,    -1,   243,    -1,
      56,    57,    58,    59,    60,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,
      -1,    -1,    -1,    89,    -1,    -1,    92,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,    -1,
     196,   197,   198,    -1,    -1,   201,    -1,    -1,   204,   205,
     206,   207,   208,   209,    21,    -1,    -1,    -1,    -1,   215,
     216,   217,   218,   219,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   233,   234,   235,
     236,    48,    -1,   239,   240,    -1,    -1,   243,    -1,    56,
      57,    58,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,
      -1,    -1,    89,    -1,    -1,    92,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,    -1,   196,
     197,   198,    -1,    -1,   201,    -1,    -1,   204,   205,   206,
     207,   208,   209,    21,    -1,    -1,    -1,    -1,   215,   216,
     217,   218,   219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   233,   234,   235,   236,
      48,    -1,   239,    -1,    -1,    -1,   243,    -1,    56,    57,
      58,    59,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,
      -1,    89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,    -1,   196,   197,
     198,    -1,    -1,   201,    -1,    -1,   204,   205,   206,   207,
     208,   209,    21,    -1,    -1,    -1,    -1,   215,   216,   217,
     218,   219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   233,   234,   235,   236,    48,
      -1,   239,    -1,    -1,    -1,   243,    -1,    56,    57,    58,
      59,    60,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    85,    -1,    -1,    -1,
      89,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,    -1,   196,   197,   198,
      -1,    -1,   201,    -1,    -1,   204,   205,   206,   207,   208,
     209,    -1,    -1,    -1,    -1,    -1,   215,   216,   217,   218,
     219,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   233,   234,   235,   236,    -1,    -1,
     239,   314,   315,   316,   317,   318,   319,   320,   321,   322,
     323,   324,   325,    -1,    -1,   328,   329,   330,   331,   332,
      -1,    -1,    -1,   336,   337,   338,   339,   340,   341,    -1,
      -1,    -1,    -1,   346,   347,   348,   349,   350,   351,   352,
      -1,   354,   355,   356,   357,   358,   359,   360,   361,   362,
     363,   364,   365,   366,   367,   368,   369,   370,   371,   372,
     373,   374,   375,   376,   377,   378,   379,   380,   381,   382,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   391,   392,
     393,   394,   395,   396,   397,    -1,   399
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,     3,   252,   253,   253,     0,     1,     4,     5,     6,
      31,    32,    33,    34,    35,    36,    38,    39,    40,    41,
      42,    53,    54,    55,    61,    65,    66,    68,    73,    77,
      78,    79,    82,    84,    86,    87,    88,    89,    93,    97,
     100,   120,   197,   198,   201,   204,   205,   206,   207,   208,
     209,   213,   214,   215,   216,   217,   218,   219,   223,   226,
     230,   231,   232,   233,   255,   256,   257,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   273,   274,   275,   282,   283,   284,   285,   286,   287,
     288,   289,   290,   291,   294,   298,   302,   303,   304,   305,
     306,   310,   311,   237,   233,   197,   198,   201,   204,   205,
     206,   207,   208,   209,   215,   216,   217,   218,   219,   231,
     233,   322,   233,    21,    48,    56,    57,    58,    59,    60,
      85,    89,    92,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   196,
     197,   198,   201,   204,   205,   206,   207,   208,   209,   215,
     216,   217,   218,   219,   233,   234,   235,   236,   239,   243,
     312,   313,   314,   315,   316,   317,   318,   319,   320,   321,
     323,   233,   260,   322,   260,   312,   237,   322,   239,   260,
     260,   312,   237,   312,   238,   312,   312,   312,   322,   237,
     237,   237,   237,   233,   322,   322,   322,   322,   233,   233,
     233,   239,   233,   233,   233,   322,   233,   322,   108,   239,
     238,     7,     8,     9,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,   105,   197,   198,   199,   200,   201,
     202,   225,   312,   316,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     239,   239,   239,   239,   239,   239,   239,   239,   239,   239,
     236,   239,   312,   321,   237,    91,    90,   238,   246,   247,
     248,   249,   250,   231,   242,   243,   244,   245,   227,   108,
     239,   238,   238,   238,   237,   237,   322,   238,   238,   237,
     237,    56,   237,   237,   237,   238,    74,   307,   308,   254,
     237,   237,   237,   237,   237,    49,   276,    11,    12,    13,
      14,    51,   277,   102,   103,   104,   206,   210,   211,   237,
     296,   312,   326,   237,   237,   102,   237,   231,   237,   195,
     233,   312,   324,   325,   312,    10,   237,   237,   237,   239,
     239,   239,   239,   239,   207,   237,   208,   237,   237,   237,
     237,   239,   239,   239,   239,   239,   239,   239,   237,   237,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   240,   240,   326,   326,   326,   326,   326,   240,
     240,   240,   326,   326,   326,   240,   326,   240,   326,   240,
     326,   312,   312,   312,   312,   326,   326,   326,   326,   326,
     326,   326,   312,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   326,   326,   326,   326,   326,   326,   326,   326,
     326,   326,   312,   312,   312,   312,   233,   240,   322,   322,
     326,   326,   326,   326,   326,   326,   326,   322,   326,   312,
     324,   240,   314,   315,   317,   317,   317,   317,   317,   317,
     317,   318,   318,   319,   319,   319,   233,   312,   312,   322,
     312,   240,   312,   312,   237,   254,   254,   254,   312,   312,
      75,   308,   309,    80,   255,   254,   237,   239,   239,   239,
     239,   239,    52,   237,   103,   206,   237,   296,   239,   239,
     239,   295,   102,   237,   240,   241,   237,   233,   292,   293,
     312,   239,   240,   240,   241,   237,   239,   234,   234,   234,
     234,   234,   239,   239,   233,   234,   234,   234,   234,   234,
     203,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   241,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   241,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   240,   240,   240,   240,   240,   240,   240,   240,
     240,   240,   237,   237,   237,   322,   237,   237,   299,    67,
      67,    70,    71,   237,   237,    76,   237,    83,    95,   234,
     234,   234,   234,   236,   239,   280,   239,   239,   295,   237,
     228,   229,   234,   233,   233,   101,   106,   233,   297,   237,
     295,   312,   292,   237,   238,   224,   293,   237,   312,   108,
     237,   312,   244,   240,   240,   240,   241,   241,   233,   233,
     240,   240,   240,   240,   240,   240,   241,   312,    22,    23,
      24,    25,    26,    27,   237,    62,    63,   300,   301,   237,
     237,   312,   312,   254,   254,   237,   254,   237,   233,   277,
     240,   240,   240,   241,   240,   236,    98,   107,   233,   281,
     228,   229,   234,   233,   101,   295,   241,   241,   240,   240,
     240,   241,   237,   233,    11,    12,    13,    14,   104,   295,
     101,   224,   312,   237,   254,   240,   241,   233,   241,    29,
      30,    43,    44,    45,    49,    50,   103,   212,   258,    30,
      49,   103,   212,   258,    29,    30,    45,    49,   103,   212,
     258,   234,   234,   240,   240,   237,   258,   258,   258,   258,
     258,   236,   241,   240,   240,   240,   240,   240,   240,   312,
     237,    64,    72,   237,    72,   237,    81,   277,   237,   234,
     237,   240,   237,   233,    11,    12,    13,    14,   104,   241,
     241,   240,   240,   241,   237,   101,   234,   234,   102,   103,
     237,   237,   234,    11,    12,    13,    14,   104,   239,   239,
     239,   239,   239,   101,   237,   237,   237,    69,   237,   312,
     244,    30,   239,   239,    30,   239,   239,   237,   239,   239,
     239,   237,    30,   239,   239,    30,   239,   239,   237,   240,
     240,   237,   237,   237,   237,   237,   237,   237,   240,    22,
      23,    24,    25,    26,    27,   237,   254,   237,   312,   254,
     312,   254,   237,   237,   278,   240,   280,   237,    11,    12,
      13,    14,   239,   239,   239,   239,   239,   234,   234,   237,
     237,   234,   237,   240,   240,   237,   239,   295,   240,   239,
     239,   239,   239,   239,   234,   234,   234,   234,   233,   237,
     237,   240,   240,   239,   312,   233,   239,   234,   233,   312,
     228,   229,   234,   233,   239,   312,   233,   239,   228,   229,
     234,   233,    29,    30,   103,   212,   258,   258,   237,   240,
     240,   240,   240,   240,   240,   254,   237,    69,   237,    69,
     278,    96,   107,   233,   279,    98,   280,   239,   239,   239,
     239,   234,   234,   234,   234,   233,   240,   240,   295,   295,
     240,   102,   102,   295,   234,   101,   102,   234,   234,   234,
     234,   233,   240,   240,   240,   241,   240,   237,   237,   312,
     240,   240,   312,   240,   240,   240,   241,   241,   240,   240,
     312,   240,   240,   312,   241,   241,   240,   240,    30,   239,
     239,   239,   237,   237,   254,   237,   254,   237,    96,   237,
     233,    11,    12,    13,    14,   104,   237,    98,   234,   234,
     234,   234,   240,   240,   240,   241,   240,   237,   237,   101,
     101,   237,   237,   237,   101,   240,   237,   237,   240,   240,
     240,   241,   240,   204,   205,   237,   237,   204,   205,   237,
     234,   237,   240,   237,   237,   240,   217,   218,   237,   237,
     237,   234,   234,   237,   237,   240,   237,   237,   240,   234,
     234,   217,   218,   237,   237,   239,   312,   234,   233,    69,
      69,   237,   254,    11,    12,    13,    14,   239,   239,   239,
     239,   239,   237,   240,   240,   240,   241,    46,    99,   237,
      46,    99,   237,    46,    99,   237,   234,   237,   295,   295,
     237,   237,   295,   295,   295,   237,   237,   295,   237,   237,
     237,   234,   237,   239,   239,   239,   239,   240,   237,   237,
     237,   237,   240,   240,   237,   237,   240,   240,   237,   237,
     312,   240,   240,   240,   237,   237,   254,    37,    94,   239,
     239,   239,   239,   234,   234,   234,   234,   233,    99,   237,
      99,   237,    99,   237,   234,   239,    46,   237,   239,    46,
     237,   239,    46,   237,   240,   101,   101,   101,   101,   101,
     101,   240,   233,   234,   233,   234,   205,   237,   237,   237,
     237,   237,   240,   237,   237,   237,    37,    94,   237,   237,
     234,   234,   234,   234,   240,   240,   240,   241,   240,   237,
     237,   237,   240,    47,    48,   239,    47,    48,   239,    47,
      48,   239,    46,    99,   237,   237,   237,   237,   237,   237,
     237,   237,   240,   241,   240,   240,   241,   240,   239,   237,
     237,   237,   254,   240,   240,   240,   241,    46,    99,   237,
      46,    99,   237,    46,    99,   237,   234,   237,    99,   237,
     241,   240,    47,   241,   240,    47,   241,   240,    47,   239,
      46,   237,   237,   234,   237,   237,   234,   237,   234,   254,
      94,    99,   237,    99,   237,    99,   237,   234,   239,    46,
     237,   239,    46,   237,   239,    46,   237,   240,   237,    48,
     237,   240,    48,   237,   240,    48,   237,   240,    48,   239,
     240,   240,   240,    94,   237,   237,   237,   237,   240,    47,
      48,   239,    47,    48,   239,    47,    48,   239,    46,    99,
     237,   240,   237,   240,   237,   240,   237,   240,    47,   237,
     237,   237,   237,    99,   237,   241,   240,    47,   241,   240,
      47,   241,   240,    47,   239,    46,   237,   237,   237,   237,
     237,   240,   237,    48,   237,   240,    48,   237,   240,    48,
     237,   240,    48,   239,   237,   240,   237,   240,   237,   240,
     237,   240,    47,   237,   237,   237,   237,   240,   237
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   251,   252,   252,   253,   253,   253,   254,   254,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   255,   255,   255,
     255,   255,   255,   255,   255,   255,   255,   256,   256,   256,
     256,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   258,   258,
     258,   258,   258,   259,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   260,   260,   260,   260,   260,   260,
     260,   260,   260,   260,   261,   261,   261,   262,   263,   263,
     264,   265,   266,   267,   267,   268,   268,   269,   270,   271,
     272,   272,   273,   274,   274,   274,   275,   275,   275,   275,
     276,   276,   277,   277,   277,   277,   277,   278,   278,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   279,   279,   279,
     279,   279,   279,   279,   279,   279,   279,   280,   280,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   291,   292,   292,
     293,   293,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     295,   295,   296,   296,   297,   297,   297,   297,   297,   297,
     297,   297,   297,   297,   297,   297,   297,   297,   297,   297,
     297,   298,   299,   299,   300,   301,   301,   302,   303,   304,
     304,   304,   304,   305,   306,   307,   307,   308,   309,   309,
     310,   311,   312,   313,   313,   314,   314,   315,   315,   316,
     316,   316,   316,   316,   316,   316,   316,   317,   317,   317,
     318,   318,   318,   319,   319,   320,   320,   321,   321,   322,
     322,   322,   322,   322,   322,   322,   322,   322,   322,   322,
     322,   322,   322,   322,   322,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   324,   324,   325,   325,   326,
     326
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     0,     2,     2,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     4,     4,     4,
      10,     8,     8,     8,    10,    10,    12,    12,    14,    11,
      11,    13,    11,    12,    12,     4,     4,     4,     4,     4,
       4,    11,    11,    11,    13,    13,    13,    13,    13,     7,
       8,     8,     8,     8,     8,     9,    11,    11,    12,    12,
      12,    12,     8,     8,    11,    11,    11,    13,     0,     1,
       1,     1,     1,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     4,     6,     4,     4,     5,     5,     5,     9,     7,
       3,     3,     3,     5,     5,     3,     3,     2,     3,     4,
       3,     2,     5,     7,    11,    10,    13,    14,    16,    17,
       0,     1,     0,     4,     4,     4,     6,     0,     2,     6,
       7,     6,     7,     6,     7,     8,     9,     7,     8,     7,
       8,     7,     8,     9,    10,     6,    11,    11,    11,    13,
      10,    10,    10,    12,    12,    12,    12,     0,     2,     6,
       7,     6,     7,     6,     7,     8,     9,     7,     8,     7,
       8,     7,     8,     9,    10,     6,    11,    11,    11,    13,
      10,    10,    10,    12,    12,    12,    12,     8,     6,     3,
       3,     3,     3,     3,     6,     1,     7,     6,     1,     2,
       2,     4,     7,     6,    11,    11,    13,    13,    13,    13,
       7,    11,    11,    13,    13,    10,     8,     8,     7,     4,
       0,     2,     1,     1,     6,     6,     6,     8,     7,     7,
       7,     9,    10,    10,    12,    10,    12,    10,    12,     6,
       7,     8,     0,     2,     4,     0,     3,     6,     6,    10,
      12,    10,    12,     8,     6,     1,     2,     4,     0,     3,
       2,     2,     1,     1,     3,     1,     3,     1,     2,     1,
       3,     3,     3,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     3,     1,     3,     1,     2,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     3,     4,     4,     4,
       4,     4,     4,     4,     4,     6,     6,     6,     6,     6,
       6,     4,     4,     4,     4,     3,     3,     4,     4,     4,
       4,     4,     4,     3,     4,     3,     4,     3,     8,     8,
       8,     4,     4,     4,     3,     3,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     3,     1,
       8,     8,     8,     2,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     0,     1,     1,     3,     1,
       3
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
#line 197 "src/parser.y"
                           {
        (yyval.program) = g_program;
    }
#line 3119 "build/parser.cpp"
    break;

  case 3: /* program: statements_opt  */
#line 200 "src/parser.y"
                     {
        (yyval.program) = g_program;
    }
#line 3127 "build/parser.cpp"
    break;

  case 5: /* statements_opt: statements_opt statement  */
#line 207 "src/parser.y"
                               {
        if ((yyvsp[0].stmt)) {
            g_program->statements.emplace_back((yyvsp[0].stmt));
        }
    }
#line 3137 "build/parser.cpp"
    break;

  case 6: /* statements_opt: statements_opt KW_CTLOPT  */
#line 212 "src/parser.y"
                               {
        if (ctlopt_nomain) g_program->nomain = true;
        if (ctlopt_main_proc[0]) g_program->main_proc = ctlopt_main_proc;
        if (ctlopt_datfmt[0]) g_program->datfmt = ctlopt_datfmt;
        if (ctlopt_timfmt[0]) g_program->timfmt = ctlopt_timfmt;
    }
#line 3148 "build/parser.cpp"
    break;

  case 7: /* statement_list: %empty  */
#line 221 "src/parser.y"
                {
        (yyval.stmt_list) = new StmtList();
    }
#line 3156 "build/parser.cpp"
    break;

  case 8: /* statement_list: statement_list statement  */
#line 224 "src/parser.y"
                               {
        (yyval.stmt_list) = (yyvsp[-1].stmt_list);
        if ((yyvsp[0].stmt)) {
            (yyval.stmt_list)->stmts.push_back((yyvsp[0].stmt));
        }
    }
#line 3167 "build/parser.cpp"
    break;

  case 9: /* statement: dcl_f_stmt  */
#line 233 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3173 "build/parser.cpp"
    break;

  case 10: /* statement: dcl_s_stmt  */
#line 234 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3179 "build/parser.cpp"
    break;

  case 11: /* statement: dcl_c_stmt  */
#line 235 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3185 "build/parser.cpp"
    break;

  case 12: /* statement: eval_stmt  */
#line 236 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3191 "build/parser.cpp"
    break;

  case 13: /* statement: eval_corr_stmt  */
#line 237 "src/parser.y"
                     { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3197 "build/parser.cpp"
    break;

  case 14: /* statement: dsply_stmt  */
#line 238 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3203 "build/parser.cpp"
    break;

  case 15: /* statement: inlr_stmt  */
#line 239 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3209 "build/parser.cpp"
    break;

  case 16: /* statement: return_stmt  */
#line 240 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3215 "build/parser.cpp"
    break;

  case 17: /* statement: if_stmt  */
#line 241 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3221 "build/parser.cpp"
    break;

  case 18: /* statement: dow_stmt  */
#line 242 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3227 "build/parser.cpp"
    break;

  case 19: /* statement: dou_stmt  */
#line 243 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3233 "build/parser.cpp"
    break;

  case 20: /* statement: for_stmt  */
#line 244 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3239 "build/parser.cpp"
    break;

  case 21: /* statement: for_each_stmt  */
#line 245 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3245 "build/parser.cpp"
    break;

  case 22: /* statement: select_stmt  */
#line 246 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3251 "build/parser.cpp"
    break;

  case 23: /* statement: iter_stmt  */
#line 247 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3257 "build/parser.cpp"
    break;

  case 24: /* statement: leave_stmt  */
#line 248 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3263 "build/parser.cpp"
    break;

  case 25: /* statement: dcl_proc_stmt  */
#line 249 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3269 "build/parser.cpp"
    break;

  case 26: /* statement: dcl_pr_stmt  */
#line 250 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3275 "build/parser.cpp"
    break;

  case 27: /* statement: dcl_ds_stmt  */
#line 251 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3281 "build/parser.cpp"
    break;

  case 28: /* statement: dcl_enum_stmt  */
#line 252 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3287 "build/parser.cpp"
    break;

  case 29: /* statement: monitor_stmt  */
#line 253 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3293 "build/parser.cpp"
    break;

  case 30: /* statement: begsr_stmt  */
#line 254 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3299 "build/parser.cpp"
    break;

  case 31: /* statement: exsr_stmt  */
#line 255 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3305 "build/parser.cpp"
    break;

  case 32: /* statement: reset_stmt  */
#line 256 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3311 "build/parser.cpp"
    break;

  case 33: /* statement: clear_stmt  */
#line 257 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3317 "build/parser.cpp"
    break;

  case 34: /* statement: sorta_stmt  */
#line 258 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3323 "build/parser.cpp"
    break;

  case 35: /* statement: evalr_stmt  */
#line 259 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3329 "build/parser.cpp"
    break;

  case 36: /* statement: callp_stmt  */
#line 260 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3335 "build/parser.cpp"
    break;

  case 37: /* statement: leavesr_stmt  */
#line 261 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3341 "build/parser.cpp"
    break;

  case 38: /* statement: dealloc_stmt  */
#line 262 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3347 "build/parser.cpp"
    break;

  case 39: /* statement: test_stmt  */
#line 263 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3353 "build/parser.cpp"
    break;

  case 40: /* statement: exec_sql_stmt  */
#line 264 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3359 "build/parser.cpp"
    break;

  case 41: /* statement: xml_into_stmt  */
#line 265 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3365 "build/parser.cpp"
    break;

  case 42: /* statement: in_da_stmt  */
#line 266 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3371 "build/parser.cpp"
    break;

  case 43: /* statement: out_da_stmt  */
#line 267 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3377 "build/parser.cpp"
    break;

  case 44: /* statement: unlock_da_stmt  */
#line 268 "src/parser.y"
                     { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3383 "build/parser.cpp"
    break;

  case 45: /* statement: expr_stmt  */
#line 269 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3389 "build/parser.cpp"
    break;

  case 46: /* statement: error SEMICOLON  */
#line 270 "src/parser.y"
                      { (yyval.stmt) = nullptr; yyerrok; }
#line 3395 "build/parser.cpp"
    break;

  case 47: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_DISK SEMICOLON  */
#line 275 "src/parser.y"
                                          {
        (yyval.stmt) = new rpg::DclF((yyvsp[-2].sval), "DISK");
        free((yyvsp[-2].sval));
    }
#line 3404 "build/parser.cpp"
    break;

  case 48: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_PRINTER SEMICOLON  */
#line 279 "src/parser.y"
                                               {
        (yyval.stmt) = new rpg::DclF((yyvsp[-2].sval), "PRINTER");
        free((yyvsp[-2].sval));
    }
#line 3413 "build/parser.cpp"
    break;

  case 49: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_WORKSTN SEMICOLON  */
#line 283 "src/parser.y"
                                               {
        (yyval.stmt) = new rpg::DclF((yyvsp[-2].sval), "WORKSTN");
        free((yyvsp[-2].sval));
    }
#line 3422 "build/parser.cpp"
    break;

  case 50: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_DISK KW_USAGE LPAREN STAR COLON STAR RPAREN SEMICOLON  */
#line 287 "src/parser.y"
                                                                                   {
        (yyval.stmt) = new rpg::DclF((yyvsp[-8].sval), "DISK");
        free((yyvsp[-8].sval));
    }
#line 3431 "build/parser.cpp"
    break;

  case 51: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 295 "src/parser.y"
                                                                                  {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3441 "build/parser.cpp"
    break;

  case 52: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 300 "src/parser.y"
                                                                                       {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3451 "build/parser.cpp"
    break;

  case 53: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 305 "src/parser.y"
                                                                                   {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::INT10, 0);
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3461 "build/parser.cpp"
    break;

  case 54: /* dcl_s_stmt: KW_DCL_S ident KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 310 "src/parser.y"
                                                                                                            {
        auto* n = new rpg::DclS((yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-8].sval));
    }
#line 3471 "build/parser.cpp"
    break;

  case 55: /* dcl_s_stmt: KW_DCL_S ident KW_ZONED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 315 "src/parser.y"
                                                                                                           {
        auto* n = new rpg::DclS((yyvsp[-8].sval), rpg::RPGType::ZONED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-8].sval));
    }
#line 3481 "build/parser.cpp"
    break;

  case 56: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_CONST KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 320 "src/parser.y"
                                                                                                             {
        (yyval.stmt) = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, true,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-10].sval));
    }
#line 3491 "build/parser.cpp"
    break;

  case 57: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_CONST KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 325 "src/parser.y"
                                                                                                              {
        (yyval.stmt) = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, true,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-10].sval));
    }
#line 3501 "build/parser.cpp"
    break;

  case 58: /* dcl_s_stmt: KW_DCL_S ident KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_CONST KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 330 "src/parser.y"
                                                                                                                                      {
        (yyval.stmt) = new rpg::DclS((yyvsp[-12].sval), rpg::RPGType::PACKED, 0, (yyvsp[-9].ival), (yyvsp[-7].ival), true,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-12].sval));
    }
#line 3511 "build/parser.cpp"
    break;

  case 59: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 335 "src/parser.y"
                                                                                                    {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-9].sval));
    }
#line 3521 "build/parser.cpp"
    break;

  case 60: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 340 "src/parser.y"
                                                                                                     {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-9].sval));
    }
#line 3531 "build/parser.cpp"
    break;

  case 61: /* dcl_s_stmt: KW_DCL_S ident KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 345 "src/parser.y"
                                                                                                                             {
        (yyval.stmt) = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-11].sval));
    }
#line 3541 "build/parser.cpp"
    break;

  case 62: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 350 "src/parser.y"
                                                                                                        {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-9].sval));
    }
#line 3551 "build/parser.cpp"
    break;

  case 63: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_EXPORT KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 356 "src/parser.y"
                                                                                                              {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        n->is_export = true;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3562 "build/parser.cpp"
    break;

  case 64: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_EXPORT KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 362 "src/parser.y"
                                                                                                               {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        n->is_export = true;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3573 "build/parser.cpp"
    break;

  case 65: /* dcl_s_stmt: KW_DCL_S ident KW_IND SEMICOLON  */
#line 368 "src/parser.y"
                                      {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::IND, 0);
        free((yyvsp[-2].sval));
    }
#line 3582 "build/parser.cpp"
    break;

  case 66: /* dcl_s_stmt: KW_DCL_S ident KW_BOOLEAN SEMICOLON  */
#line 372 "src/parser.y"
                                          {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::IND, 0);
        free((yyvsp[-2].sval));
    }
#line 3591 "build/parser.cpp"
    break;

  case 67: /* dcl_s_stmt: KW_DCL_S ident KW_DATE SEMICOLON  */
#line 376 "src/parser.y"
                                       {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::DATE, 0);
        free((yyvsp[-2].sval));
    }
#line 3600 "build/parser.cpp"
    break;

  case 68: /* dcl_s_stmt: KW_DCL_S ident KW_TIME SEMICOLON  */
#line 380 "src/parser.y"
                                       {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::TIME, 0);
        free((yyvsp[-2].sval));
    }
#line 3609 "build/parser.cpp"
    break;

  case 69: /* dcl_s_stmt: KW_DCL_S ident KW_TIMESTAMP SEMICOLON  */
#line 384 "src/parser.y"
                                            {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::TIMESTAMP, 0);
        free((yyvsp[-2].sval));
    }
#line 3618 "build/parser.cpp"
    break;

  case 70: /* dcl_s_stmt: KW_DCL_S ident KW_POINTER SEMICOLON  */
#line 388 "src/parser.y"
                                          {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::POINTER, 0);
        free((yyvsp[-2].sval));
    }
#line 3627 "build/parser.cpp"
    break;

  case 71: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 392 "src/parser.y"
                                                                                                         {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-9].sval));
    }
#line 3636 "build/parser.cpp"
    break;

  case 72: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 396 "src/parser.y"
                                                                                                          {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-9].sval));
    }
#line 3645 "build/parser.cpp"
    break;

  case 73: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 400 "src/parser.y"
                                                                                                             {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-9].sval));
    }
#line 3654 "build/parser.cpp"
    break;

  case 74: /* dcl_s_stmt: KW_DCL_S ident KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 404 "src/parser.y"
                                                                                                                                  {
        (yyval.stmt) = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-11].sval));
    }
#line 3663 "build/parser.cpp"
    break;

  case 75: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN KW_DIM_VAR COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 408 "src/parser.y"
                                                                                                                          {
        auto* node = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-2].ival));
        node->dim_type = 1;
        free((yyvsp[-11].sval));
        (yyval.stmt) = node;
    }
#line 3674 "build/parser.cpp"
    break;

  case 76: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN KW_DIM_AUTO COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 414 "src/parser.y"
                                                                                                                           {
        auto* node = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-2].ival));
        node->dim_type = 2;
        free((yyvsp[-11].sval));
        (yyval.stmt) = node;
    }
#line 3685 "build/parser.cpp"
    break;

  case 77: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN KW_DIM_VAR COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 420 "src/parser.y"
                                                                                                                              {
        auto* node = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::VARCHAR, (yyvsp[-8].ival), 0, 0, false, nullptr, (yyvsp[-2].ival));
        node->dim_type = 1;
        free((yyvsp[-11].sval));
        (yyval.stmt) = node;
    }
#line 3696 "build/parser.cpp"
    break;

  case 78: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN KW_DIM_AUTO COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 426 "src/parser.y"
                                                                                                                               {
        auto* node = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::VARCHAR, (yyvsp[-8].ival), 0, 0, false, nullptr, (yyvsp[-2].ival));
        node->dim_type = 2;
        free((yyvsp[-11].sval));
        (yyval.stmt) = node;
    }
#line 3707 "build/parser.cpp"
    break;

  case 79: /* dcl_s_stmt: KW_DCL_S ident KW_LIKE LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 432 "src/parser.y"
                                                                {
        auto* node = new rpg::DclS((yyvsp[-5].sval), rpg::RPGType::INT10, 0);
        node->like_var = (yyvsp[-2].sval);
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
        (yyval.stmt) = node;
    }
#line 3719 "build/parser.cpp"
    break;

  case 80: /* dcl_s_stmt: KW_DCL_S ident KW_UNS LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 439 "src/parser.y"
                                                                                   {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::UNS, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3729 "build/parser.cpp"
    break;

  case 81: /* dcl_s_stmt: KW_DCL_S ident KW_FLOAT_TYPE LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 444 "src/parser.y"
                                                                                          {
        auto type = ((yyvsp[-3].ival) <= 4) ? rpg::RPGType::FLOAT4 : rpg::RPGType::FLOAT8;
        auto* n = new rpg::DclS((yyvsp[-6].sval), type, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3740 "build/parser.cpp"
    break;

  case 82: /* dcl_s_stmt: KW_DCL_S ident KW_BINDEC LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 450 "src/parser.y"
                                                                                      {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::BINDEC, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3750 "build/parser.cpp"
    break;

  case 83: /* dcl_s_stmt: KW_DCL_S ident KW_UCS2 LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 455 "src/parser.y"
                                                                                    {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::UCS2, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3760 "build/parser.cpp"
    break;

  case 84: /* dcl_s_stmt: KW_DCL_S ident KW_GRAPH LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 460 "src/parser.y"
                                                                                     {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::UCS2, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3770 "build/parser.cpp"
    break;

  case 85: /* dcl_s_stmt: KW_DCL_S ident KW_OBJECT LPAREN KW_JAVA COLON STRING_LITERAL RPAREN SEMICOLON  */
#line 465 "src/parser.y"
                                                                                    {
        auto* n = new rpg::DclS((yyvsp[-7].sval), rpg::RPGType::OBJECT, 0);
        n->java_class = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-7].sval)); free((yyvsp[-2].sval));
    }
#line 3780 "build/parser.cpp"
    break;

  case 86: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_BASED LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 470 "src/parser.y"
                                                                                                      {
        auto* n = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::INT10, 0);
        n->based_ptr = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
    }
#line 3790 "build/parser.cpp"
    break;

  case 87: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_BASED LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 475 "src/parser.y"
                                                                                                       {
        auto* n = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival));
        n->based_ptr = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
    }
#line 3800 "build/parser.cpp"
    break;

  case 88: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_ASCEND SEMICOLON  */
#line 480 "src/parser.y"
                                                                                                                   {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = 1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3810 "build/parser.cpp"
    break;

  case 89: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_DESCEND SEMICOLON  */
#line 485 "src/parser.y"
                                                                                                                    {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = -1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3820 "build/parser.cpp"
    break;

  case 90: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_ASCEND SEMICOLON  */
#line 490 "src/parser.y"
                                                                                                                    {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = 1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3830 "build/parser.cpp"
    break;

  case 91: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_DESCEND SEMICOLON  */
#line 495 "src/parser.y"
                                                                                                                     {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = -1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3840 "build/parser.cpp"
    break;

  case 92: /* dcl_s_stmt: KW_DCL_S ident KW_DATE KW_DATFMT LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 500 "src/parser.y"
                                                                          {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::DATE, 0);
        n->datfmt = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-6].sval)); free((yyvsp[-2].sval));
    }
#line 3850 "build/parser.cpp"
    break;

  case 93: /* dcl_s_stmt: KW_DCL_S ident KW_TIME KW_TIMFMT LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 505 "src/parser.y"
                                                                          {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::TIME, 0);
        n->timfmt = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-6].sval)); free((yyvsp[-2].sval));
    }
#line 3860 "build/parser.cpp"
    break;

  case 94: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_DTAARA LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 510 "src/parser.y"
                                                                                                        {
        auto* n = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival));
        n->dtaara_name = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
    }
#line 3870 "build/parser.cpp"
    break;

  case 95: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_DTAARA LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 515 "src/parser.y"
                                                                                                           {
        auto* n = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival));
        n->dtaara_name = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
    }
#line 3880 "build/parser.cpp"
    break;

  case 96: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DTAARA LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 520 "src/parser.y"
                                                                                                       {
        auto* n = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::INT10, 0);
        n->dtaara_name = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
    }
#line 3890 "build/parser.cpp"
    break;

  case 97: /* dcl_s_stmt: KW_DCL_S ident KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_DTAARA LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 525 "src/parser.y"
                                                                                                                                {
        auto* n = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival));
        n->dtaara_name = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-11].sval)); free((yyvsp[-2].sval));
    }
#line 3900 "build/parser.cpp"
    break;

  case 98: /* dcl_s_keywords: %empty  */
#line 533 "src/parser.y"
                  { (yyval.ival) = 0; }
#line 3906 "build/parser.cpp"
    break;

  case 99: /* dcl_s_keywords: KW_STATIC  */
#line 534 "src/parser.y"
                  { (yyval.ival) = 1; }
#line 3912 "build/parser.cpp"
    break;

  case 100: /* dcl_s_keywords: KW_TEMPLATE  */
#line 535 "src/parser.y"
                  { (yyval.ival) = 2; }
#line 3918 "build/parser.cpp"
    break;

  case 101: /* dcl_s_keywords: KW_EXPORT  */
#line 536 "src/parser.y"
                  { (yyval.ival) = 4; }
#line 3924 "build/parser.cpp"
    break;

  case 102: /* dcl_s_keywords: KW_IMPORT  */
#line 537 "src/parser.y"
                  { (yyval.ival) = 8; }
#line 3930 "build/parser.cpp"
    break;

  case 103: /* dcl_c_stmt: KW_DCL_C IDENTIFIER expression SEMICOLON  */
#line 542 "src/parser.y"
                                             {
        (yyval.stmt) = new rpg::DclC((yyvsp[-2].sval), std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
        free((yyvsp[-2].sval));
    }
#line 3939 "build/parser.cpp"
    break;

  case 104: /* eval_target: IDENTIFIER  */
#line 549 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier((yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 3948 "build/parser.cpp"
    break;

  case 105: /* eval_target: KW_POS  */
#line 553 "src/parser.y"
             { (yyval.expr) = new rpg::Identifier("POS"); }
#line 3954 "build/parser.cpp"
    break;

  case 106: /* eval_target: KW_OVERLAY  */
#line 554 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("OVERLAY"); }
#line 3960 "build/parser.cpp"
    break;

  case 107: /* eval_target: KW_PREFIX  */
#line 555 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("PREFIX"); }
#line 3966 "build/parser.cpp"
    break;

  case 108: /* eval_target: KW_UNS  */
#line 556 "src/parser.y"
             { (yyval.expr) = new rpg::Identifier("UNS"); }
#line 3972 "build/parser.cpp"
    break;

  case 109: /* eval_target: KW_FLOAT_TYPE  */
#line 557 "src/parser.y"
                    { (yyval.expr) = new rpg::Identifier("FLOAT"); }
#line 3978 "build/parser.cpp"
    break;

  case 110: /* eval_target: KW_GRAPH  */
#line 558 "src/parser.y"
               { (yyval.expr) = new rpg::Identifier("GRAPH"); }
#line 3984 "build/parser.cpp"
    break;

  case 111: /* eval_target: KW_ASCEND  */
#line 559 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("ASCEND"); }
#line 3990 "build/parser.cpp"
    break;

  case 112: /* eval_target: KW_DESCEND  */
#line 560 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("DESCEND"); }
#line 3996 "build/parser.cpp"
    break;

  case 113: /* eval_target: KW_RTNPARM  */
#line 561 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("RTNPARM"); }
#line 4002 "build/parser.cpp"
    break;

  case 114: /* eval_target: KW_OPDESC  */
#line 562 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("OPDESC"); }
#line 4008 "build/parser.cpp"
    break;

  case 115: /* eval_target: KW_NULLIND  */
#line 563 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("NULLIND"); }
#line 4014 "build/parser.cpp"
    break;

  case 116: /* eval_target: KW_DATFMT  */
#line 564 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("DATFMT"); }
#line 4020 "build/parser.cpp"
    break;

  case 117: /* eval_target: KW_TIMFMT  */
#line 565 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("TIMFMT"); }
#line 4026 "build/parser.cpp"
    break;

  case 118: /* eval_target: KW_EXTNAME  */
#line 566 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("EXTNAME"); }
#line 4032 "build/parser.cpp"
    break;

  case 119: /* eval_target: INDICATOR  */
#line 567 "src/parser.y"
                {
        (yyval.expr) = new rpg::IndicatorExpr((yyvsp[0].ival));
    }
#line 4040 "build/parser.cpp"
    break;

  case 120: /* eval_target: IDENTIFIER DOT IDENTIFIER  */
#line 570 "src/parser.y"
                                {
        auto obj = std::unique_ptr<rpg::Expression>(new rpg::Identifier((yyvsp[-2].sval)));
        (yyval.expr) = new rpg::DotExpr(std::move(obj), (yyvsp[0].sval));
        free((yyvsp[-2].sval));
        free((yyvsp[0].sval));
    }
#line 4051 "build/parser.cpp"
    break;

  case 121: /* eval_target: IDENTIFIER LPAREN expression RPAREN  */
#line 576 "src/parser.y"
                                          {
        (yyval.expr) = new rpg::ArrayAccess((yyvsp[-3].sval), std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
        free((yyvsp[-3].sval));
    }
#line 4060 "build/parser.cpp"
    break;

  case 122: /* eval_target: IDENTIFIER LPAREN expression RPAREN DOT IDENTIFIER  */
#line 580 "src/parser.y"
                                                         {
        auto* arr = new rpg::ArrayAccess((yyvsp[-5].sval), std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)));
        (yyval.expr) = new rpg::DotExpr(std::unique_ptr<rpg::Expression>(arr), (yyvsp[0].sval));
        free((yyvsp[-5].sval));
        free((yyvsp[0].sval));
    }
#line 4071 "build/parser.cpp"
    break;

  case 123: /* eval_target: BIF_ELEM LPAREN arg_list RPAREN  */
#line 586 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("ELEM", (yyvsp[-1].expr_list));
    }
#line 4079 "build/parser.cpp"
    break;

  case 124: /* eval_stmt: eval_target EQUALS expression SEMICOLON  */
#line 592 "src/parser.y"
                                            {
        (yyval.stmt) = new rpg::EvalStmt(
            std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-1].expr))
        );
    }
#line 4090 "build/parser.cpp"
    break;

  case 125: /* eval_stmt: KW_EVAL eval_target EQUALS expression SEMICOLON  */
#line 598 "src/parser.y"
                                                      {
        (yyval.stmt) = new rpg::EvalStmt(
            std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-1].expr))
        );
    }
#line 4101 "build/parser.cpp"
    break;

  case 126: /* eval_stmt: KW_EVAL_EXT eval_target EQUALS expression SEMICOLON  */
#line 604 "src/parser.y"
                                                          {
        auto* s = new rpg::EvalStmt(
            std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-1].expr))
        );
        s->extenders = (yyvsp[-4].sval); free((yyvsp[-4].sval));
        (yyval.stmt) = s;
    }
#line 4114 "build/parser.cpp"
    break;

  case 127: /* eval_corr_stmt: KW_EVAL_CORR ident EQUALS ident SEMICOLON  */
#line 615 "src/parser.y"
                                              {
        (yyval.stmt) = new rpg::EvalCorrStmt(std::string((yyvsp[-3].sval)), std::string((yyvsp[-1].sval)));
        free((yyvsp[-3].sval));
        free((yyvsp[-1].sval));
    }
#line 4124 "build/parser.cpp"
    break;

  case 128: /* xml_into_stmt: KW_XML_INTO ident BIF_XML LPAREN expression COLON expression RPAREN SEMICOLON  */
#line 623 "src/parser.y"
                                                                                  {
        (yyval.stmt) = new rpg::XmlIntoStmt(std::string((yyvsp[-7].sval)),
            std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-7].sval));
    }
#line 4135 "build/parser.cpp"
    break;

  case 129: /* xml_into_stmt: KW_XML_INTO ident BIF_XML LPAREN expression RPAREN SEMICOLON  */
#line 629 "src/parser.y"
                                                                   {
        (yyval.stmt) = new rpg::XmlIntoStmt(std::string((yyvsp[-5].sval)),
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            nullptr);
        free((yyvsp[-5].sval));
    }
#line 4146 "build/parser.cpp"
    break;

  case 130: /* in_da_stmt: KW_IN IDENTIFIER SEMICOLON  */
#line 638 "src/parser.y"
                               {
        (yyval.stmt) = new rpg::DataInStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4155 "build/parser.cpp"
    break;

  case 131: /* out_da_stmt: KW_OUT IDENTIFIER SEMICOLON  */
#line 645 "src/parser.y"
                                {
        (yyval.stmt) = new rpg::DataOutStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4164 "build/parser.cpp"
    break;

  case 132: /* unlock_da_stmt: KW_UNLOCK IDENTIFIER SEMICOLON  */
#line 652 "src/parser.y"
                                   {
        (yyval.stmt) = new rpg::DataUnlockStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4173 "build/parser.cpp"
    break;

  case 133: /* evalr_stmt: KW_EVALR eval_target EQUALS expression SEMICOLON  */
#line 659 "src/parser.y"
                                                     {
        (yyval.stmt) = new rpg::EvalRStmt(
            std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-1].expr))
        );
    }
#line 4184 "build/parser.cpp"
    break;

  case 134: /* evalr_stmt: KW_EVALR_EXT eval_target EQUALS expression SEMICOLON  */
#line 665 "src/parser.y"
                                                           {
        auto* s = new rpg::EvalRStmt(
            std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-1].expr))
        );
        s->extenders = (yyvsp[-4].sval); free((yyvsp[-4].sval));
        (yyval.stmt) = s;
    }
#line 4197 "build/parser.cpp"
    break;

  case 135: /* callp_stmt: KW_CALLP expression SEMICOLON  */
#line 676 "src/parser.y"
                                  {
        (yyval.stmt) = new rpg::CallpStmt(std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)), "");
    }
#line 4205 "build/parser.cpp"
    break;

  case 136: /* callp_stmt: KW_CALLP_EXT expression SEMICOLON  */
#line 679 "src/parser.y"
                                        {
        (yyval.stmt) = new rpg::CallpStmt(std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)), (yyvsp[-2].sval));
        free((yyvsp[-2].sval));
    }
#line 4214 "build/parser.cpp"
    break;

  case 137: /* leavesr_stmt: KW_LEAVESR SEMICOLON  */
#line 686 "src/parser.y"
                         {
        (yyval.stmt) = new rpg::LeaveSRStmt();
    }
#line 4222 "build/parser.cpp"
    break;

  case 138: /* dsply_stmt: KW_DSPLY expression SEMICOLON  */
#line 692 "src/parser.y"
                                  {
        (yyval.stmt) = new rpg::DsplyStmt(std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
    }
#line 4230 "build/parser.cpp"
    break;

  case 139: /* inlr_stmt: KW_INLR EQUALS KW_ON SEMICOLON  */
#line 698 "src/parser.y"
                                   {
        (yyval.stmt) = new rpg::ReturnStmt(0);
    }
#line 4238 "build/parser.cpp"
    break;

  case 140: /* return_stmt: KW_RETURN expression SEMICOLON  */
#line 704 "src/parser.y"
                                   {
        (yyval.stmt) = new rpg::ReturnStmt(std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
    }
#line 4246 "build/parser.cpp"
    break;

  case 141: /* return_stmt: KW_RETURN SEMICOLON  */
#line 707 "src/parser.y"
                          {
        (yyval.stmt) = new rpg::ReturnStmt(0);
    }
#line 4254 "build/parser.cpp"
    break;

  case 142: /* expr_stmt: IDENTIFIER LPAREN call_args_opt RPAREN SEMICOLON  */
#line 714 "src/parser.y"
                                                     {
        auto* fc = make_func((yyvsp[-4].sval), (yyvsp[-2].expr_list));
        free((yyvsp[-4].sval));
        (yyval.stmt) = new rpg::ExprStmt(std::unique_ptr<rpg::Expression>(fc));
    }
#line 4264 "build/parser.cpp"
    break;

  case 143: /* dcl_pr_stmt: KW_DCL_PR IDENTIFIER pi_return_type SEMICOLON pr_params KW_END_PR SEMICOLON  */
#line 725 "src/parser.y"
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
#line 4285 "build/parser.cpp"
    break;

  case 144: /* dcl_pr_stmt: KW_DCL_PR IDENTIFIER pi_return_type KW_EXTPROC LPAREN STRING_LITERAL RPAREN SEMICOLON pr_params KW_END_PR SEMICOLON  */
#line 742 "src/parser.y"
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
#line 4309 "build/parser.cpp"
    break;

  case 145: /* dcl_pr_stmt: KW_DCL_PR IDENTIFIER KW_EXTPGM LPAREN STRING_LITERAL RPAREN SEMICOLON pr_params KW_END_PR SEMICOLON  */
#line 762 "src/parser.y"
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
#line 4325 "build/parser.cpp"
    break;

  case 146: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER proc_export SEMICOLON KW_DCL_PI pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 780 "src/parser.y"
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
#line 4350 "build/parser.cpp"
    break;

  case 147: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER proc_export SEMICOLON KW_DCL_PI IDENTIFIER pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 804 "src/parser.y"
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
#line 4376 "build/parser.cpp"
    break;

  case 148: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER proc_export SEMICOLON KW_DCL_PI pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_ON_EXIT SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 830 "src/parser.y"
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
#line 4403 "build/parser.cpp"
    break;

  case 149: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER proc_export SEMICOLON KW_DCL_PI IDENTIFIER pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_ON_EXIT SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 857 "src/parser.y"
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
#line 4431 "build/parser.cpp"
    break;

  case 150: /* proc_export: %empty  */
#line 883 "src/parser.y"
                { (yyval.ival) = 0; }
#line 4437 "build/parser.cpp"
    break;

  case 151: /* proc_export: KW_EXPORT  */
#line 884 "src/parser.y"
                { (yyval.ival) = 1; }
#line 4443 "build/parser.cpp"
    break;

  case 152: /* pi_return_type: %empty  */
#line 889 "src/parser.y"
               { (yyval.ival) = -1; }
#line 4449 "build/parser.cpp"
    break;

  case 153: /* pi_return_type: KW_INT LPAREN INTEGER_LITERAL RPAREN  */
#line 890 "src/parser.y"
                                           { (yyval.ival) = (int)rpg::RPGType::INT10; }
#line 4455 "build/parser.cpp"
    break;

  case 154: /* pi_return_type: KW_CHAR LPAREN INTEGER_LITERAL RPAREN  */
#line 891 "src/parser.y"
                                            { (yyval.ival) = (int)rpg::RPGType::CHAR; }
#line 4461 "build/parser.cpp"
    break;

  case 155: /* pi_return_type: KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN  */
#line 892 "src/parser.y"
                                               { (yyval.ival) = (int)rpg::RPGType::VARCHAR; }
#line 4467 "build/parser.cpp"
    break;

  case 156: /* pi_return_type: KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN  */
#line 893 "src/parser.y"
                                                                    { (yyval.ival) = (int)rpg::RPGType::PACKED; }
#line 4473 "build/parser.cpp"
    break;

  case 157: /* pi_params: %empty  */
#line 898 "src/parser.y"
                {
        (yyval.param_list) = new ParamList();
    }
#line 4481 "build/parser.cpp"
    break;

  case 158: /* pi_params: pi_params pi_param  */
#line 901 "src/parser.y"
                         {
        (yyval.param_list) = (yyvsp[-1].param_list);
        (yyval.param_list)->params.push_back(*(yyvsp[0].param_decl));
        delete (yyvsp[0].param_decl);
    }
#line 4491 "build/parser.cpp"
    break;

  case 159: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 909 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4500 "build/parser.cpp"
    break;

  case 160: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 913 "src/parser.y"
                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4509 "build/parser.cpp"
    break;

  case 161: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 917 "src/parser.y"
                                                                 {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4518 "build/parser.cpp"
    break;

  case 162: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 921 "src/parser.y"
                                                                          {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4527 "build/parser.cpp"
    break;

  case 163: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 925 "src/parser.y"
                                                                    {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4536 "build/parser.cpp"
    break;

  case 164: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 929 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4545 "build/parser.cpp"
    break;

  case 165: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 933 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 4554 "build/parser.cpp"
    break;

  case 166: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 937 "src/parser.y"
                                                                                                  {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 4563 "build/parser.cpp"
    break;

  case 167: /* pi_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 942 "src/parser.y"
                                                                            {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4572 "build/parser.cpp"
    break;

  case 168: /* pi_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 946 "src/parser.y"
                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4581 "build/parser.cpp"
    break;

  case 169: /* pi_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 950 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4590 "build/parser.cpp"
    break;

  case 170: /* pi_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 954 "src/parser.y"
                                                                                      {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4599 "build/parser.cpp"
    break;

  case 171: /* pi_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 958 "src/parser.y"
                                                                                {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4608 "build/parser.cpp"
    break;

  case 172: /* pi_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 962 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4617 "build/parser.cpp"
    break;

  case 173: /* pi_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 966 "src/parser.y"
                                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 4626 "build/parser.cpp"
    break;

  case 174: /* pi_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 970 "src/parser.y"
                                                                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 4635 "build/parser.cpp"
    break;

  case 175: /* pi_param: IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 974 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, 0, 0, 0, false, std::string((yyvsp[-2].sval))};
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
    }
#line 4645 "build/parser.cpp"
    break;

  case 176: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 980 "src/parser.y"
                                                                                                            {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4655 "build/parser.cpp"
    break;

  case 177: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 985 "src/parser.y"
                                                                                                             {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4665 "build/parser.cpp"
    break;

  case 178: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 990 "src/parser.y"
                                                                                                                {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::VARCHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4675 "build/parser.cpp"
    break;

  case 179: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 995 "src/parser.y"
                                                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-12].sval), rpg::RPGType::PACKED, 0, (yyvsp[-9].ival), (yyvsp[-7].ival), true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-12].sval));
    }
#line 4685 "build/parser.cpp"
    break;

  case 180: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1001 "src/parser.y"
                                                                                                 {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4695 "build/parser.cpp"
    break;

  case 181: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1006 "src/parser.y"
                                                                                                  {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4705 "build/parser.cpp"
    break;

  case 182: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1011 "src/parser.y"
                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4715 "build/parser.cpp"
    break;

  case 183: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1016 "src/parser.y"
                                                                                                                          {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4725 "build/parser.cpp"
    break;

  case 184: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 1022 "src/parser.y"
                                                                                                                 {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4735 "build/parser.cpp"
    break;

  case 185: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 1027 "src/parser.y"
                                                                                                                  {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::CHAR, (yyvsp[-8].ival), 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4745 "build/parser.cpp"
    break;

  case 186: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 1032 "src/parser.y"
                                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::VARCHAR, (yyvsp[-8].ival), 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4755 "build/parser.cpp"
    break;

  case 187: /* pr_params: %empty  */
#line 1041 "src/parser.y"
                {
        (yyval.param_list) = new ParamList();
    }
#line 4763 "build/parser.cpp"
    break;

  case 188: /* pr_params: pr_params pr_param  */
#line 1044 "src/parser.y"
                         {
        (yyval.param_list) = (yyvsp[-1].param_list);
        (yyval.param_list)->params.push_back(*(yyvsp[0].param_decl));
        delete (yyvsp[0].param_decl);
    }
#line 4773 "build/parser.cpp"
    break;

  case 189: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1052 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4782 "build/parser.cpp"
    break;

  case 190: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1056 "src/parser.y"
                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4791 "build/parser.cpp"
    break;

  case 191: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1060 "src/parser.y"
                                                                 {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4800 "build/parser.cpp"
    break;

  case 192: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1064 "src/parser.y"
                                                                          {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4809 "build/parser.cpp"
    break;

  case 193: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1068 "src/parser.y"
                                                                    {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4818 "build/parser.cpp"
    break;

  case 194: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1072 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4827 "build/parser.cpp"
    break;

  case 195: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1076 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 4836 "build/parser.cpp"
    break;

  case 196: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1080 "src/parser.y"
                                                                                                  {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 4845 "build/parser.cpp"
    break;

  case 197: /* pr_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1085 "src/parser.y"
                                                                            {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4854 "build/parser.cpp"
    break;

  case 198: /* pr_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1089 "src/parser.y"
                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4863 "build/parser.cpp"
    break;

  case 199: /* pr_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1093 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4872 "build/parser.cpp"
    break;

  case 200: /* pr_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1097 "src/parser.y"
                                                                                      {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4881 "build/parser.cpp"
    break;

  case 201: /* pr_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1101 "src/parser.y"
                                                                                {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4890 "build/parser.cpp"
    break;

  case 202: /* pr_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1105 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4899 "build/parser.cpp"
    break;

  case 203: /* pr_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1109 "src/parser.y"
                                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 4908 "build/parser.cpp"
    break;

  case 204: /* pr_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1113 "src/parser.y"
                                                                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 4917 "build/parser.cpp"
    break;

  case 205: /* pr_param: IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1117 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, 0, 0, 0, false, std::string((yyvsp[-2].sval))};
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
    }
#line 4927 "build/parser.cpp"
    break;

  case 206: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1123 "src/parser.y"
                                                                                                            {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4937 "build/parser.cpp"
    break;

  case 207: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1128 "src/parser.y"
                                                                                                             {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4947 "build/parser.cpp"
    break;

  case 208: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1133 "src/parser.y"
                                                                                                                {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::VARCHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4957 "build/parser.cpp"
    break;

  case 209: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1138 "src/parser.y"
                                                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-12].sval), rpg::RPGType::PACKED, 0, (yyvsp[-9].ival), (yyvsp[-7].ival), true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-12].sval));
    }
#line 4967 "build/parser.cpp"
    break;

  case 210: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1144 "src/parser.y"
                                                                                                 {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4977 "build/parser.cpp"
    break;

  case 211: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1149 "src/parser.y"
                                                                                                  {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4987 "build/parser.cpp"
    break;

  case 212: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1154 "src/parser.y"
                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4997 "build/parser.cpp"
    break;

  case 213: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1159 "src/parser.y"
                                                                                                                          {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 5007 "build/parser.cpp"
    break;

  case 214: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 1165 "src/parser.y"
                                                                                                                 {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 5017 "build/parser.cpp"
    break;

  case 215: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 1170 "src/parser.y"
                                                                                                                  {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::CHAR, (yyvsp[-8].ival), 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 5027 "build/parser.cpp"
    break;

  case 216: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 1175 "src/parser.y"
                                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::VARCHAR, (yyvsp[-8].ival), 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 5037 "build/parser.cpp"
    break;

  case 217: /* monitor_stmt: KW_MONITOR SEMICOLON statement_list KW_ON_ERROR SEMICOLON statement_list KW_ENDMON SEMICOLON  */
#line 1185 "src/parser.y"
                                                                                                 {
        auto* node = new rpg::MonitorStmt();
        for (auto* s : (yyvsp[-5].stmt_list)->stmts) node->try_body.emplace_back(s);
        delete (yyvsp[-5].stmt_list);
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->on_error_body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        (yyval.stmt) = node;
    }
#line 5050 "build/parser.cpp"
    break;

  case 218: /* begsr_stmt: KW_BEGSR IDENTIFIER SEMICOLON statement_list KW_ENDSR SEMICOLON  */
#line 1196 "src/parser.y"
                                                                    {
        auto* node = new rpg::BegSR((yyvsp[-4].sval));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        free((yyvsp[-4].sval));
        (yyval.stmt) = node;
    }
#line 5062 "build/parser.cpp"
    break;

  case 219: /* exsr_stmt: KW_EXSR ident SEMICOLON  */
#line 1206 "src/parser.y"
                            {
        (yyval.stmt) = new rpg::ExSR((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 5071 "build/parser.cpp"
    break;

  case 220: /* sorta_stmt: KW_SORTA ident SEMICOLON  */
#line 1214 "src/parser.y"
                             {
        (yyval.stmt) = new rpg::SortAStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 5080 "build/parser.cpp"
    break;

  case 221: /* reset_stmt: KW_RESET ident SEMICOLON  */
#line 1222 "src/parser.y"
                             {
        (yyval.stmt) = new rpg::ResetStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 5089 "build/parser.cpp"
    break;

  case 222: /* clear_stmt: KW_CLEAR ident SEMICOLON  */
#line 1229 "src/parser.y"
                             {
        (yyval.stmt) = new rpg::ClearStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 5098 "build/parser.cpp"
    break;

  case 223: /* dealloc_stmt: KW_DEALLOC ident SEMICOLON  */
#line 1237 "src/parser.y"
                               {
        (yyval.stmt) = new rpg::DeallocStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 5107 "build/parser.cpp"
    break;

  case 224: /* test_stmt: KW_TEST LPAREN ident RPAREN ident SEMICOLON  */
#line 1245 "src/parser.y"
                                                {
        char type = toupper((yyvsp[-3].sval)[0]);
        (yyval.stmt) = new rpg::TestStmt(type, std::string((yyvsp[-1].sval)));
        free((yyvsp[-3].sval));
        free((yyvsp[-1].sval));
    }
#line 5118 "build/parser.cpp"
    break;

  case 225: /* exec_sql_stmt: EXEC_SQL_TEXT  */
#line 1256 "src/parser.y"
                  {
        rpg::SqlStmtKind kind = rpg::classifySqlStmt((yyvsp[0].sval));
        (yyval.stmt) = new rpg::ExecSqlStmt(std::string((yyvsp[0].sval)), kind);
        free((yyvsp[0].sval));
    }
#line 5128 "build/parser.cpp"
    break;

  case 226: /* dcl_enum_stmt: KW_DCL_ENUM IDENTIFIER KW_QUALIFIED SEMICOLON enum_constants KW_END_ENUM SEMICOLON  */
#line 1266 "src/parser.y"
                                                                                       {
        auto* e = new rpg::DclEnum((yyvsp[-5].sval));
        e->qualified = true;
        e->constants = std::move(*(yyvsp[-2].enum_const_list));
        delete (yyvsp[-2].enum_const_list);
        free((yyvsp[-5].sval));
        (yyval.stmt) = e;
    }
#line 5141 "build/parser.cpp"
    break;

  case 227: /* dcl_enum_stmt: KW_DCL_ENUM IDENTIFIER SEMICOLON enum_constants KW_END_ENUM SEMICOLON  */
#line 1274 "src/parser.y"
                                                                            {
        auto* e = new rpg::DclEnum((yyvsp[-4].sval));
        e->qualified = false;
        e->constants = std::move(*(yyvsp[-2].enum_const_list));
        delete (yyvsp[-2].enum_const_list);
        free((yyvsp[-4].sval));
        (yyval.stmt) = e;
    }
#line 5154 "build/parser.cpp"
    break;

  case 228: /* enum_constants: enum_constant  */
#line 1285 "src/parser.y"
                  {
        (yyval.enum_const_list) = (yyvsp[0].enum_const_list);
    }
#line 5162 "build/parser.cpp"
    break;

  case 229: /* enum_constants: enum_constants enum_constant  */
#line 1288 "src/parser.y"
                                   {
        (yyvsp[-1].enum_const_list)->insert((yyvsp[-1].enum_const_list)->end(), std::make_move_iterator((yyvsp[0].enum_const_list)->begin()), std::make_move_iterator((yyvsp[0].enum_const_list)->end()));
        delete (yyvsp[0].enum_const_list);
        (yyval.enum_const_list) = (yyvsp[-1].enum_const_list);
    }
#line 5172 "build/parser.cpp"
    break;

  case 230: /* enum_constant: IDENTIFIER SEMICOLON  */
#line 1296 "src/parser.y"
                         {
        auto* v = new std::vector<rpg::EnumConstant>();
        rpg::EnumConstant ec;
        ec.name = (yyvsp[-1].sval);
        free((yyvsp[-1].sval));
        v->push_back(std::move(ec));
        (yyval.enum_const_list) = v;
    }
#line 5185 "build/parser.cpp"
    break;

  case 231: /* enum_constant: IDENTIFIER EQUALS expression SEMICOLON  */
#line 1304 "src/parser.y"
                                             {
        auto* v = new std::vector<rpg::EnumConstant>();
        rpg::EnumConstant ec;
        ec.name = (yyvsp[-3].sval);
        ec.value.reset((yyvsp[-1].expr));
        free((yyvsp[-3].sval));
        v->push_back(std::move(ec));
        (yyval.enum_const_list) = v;
    }
#line 5199 "build/parser.cpp"
    break;

  case 232: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1319 "src/parser.y"
                                                                              {
        auto* ds = new rpg::DclDS((yyvsp[-5].sval));
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-5].sval));
        (yyval.stmt) = ds;
    }
#line 5212 "build/parser.cpp"
    break;

  case 233: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1328 "src/parser.y"
                                                                   {
        auto* ds = new rpg::DclDS((yyvsp[-4].sval));
        ds->qualified = false;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-4].sval));
        (yyval.stmt) = ds;
    }
#line 5225 "build/parser.cpp"
    break;

  case 234: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1337 "src/parser.y"
                                                                                                                     {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->dim = (yyvsp[-6].ival);
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-9].sval));
        (yyval.stmt) = ds;
    }
#line 5239 "build/parser.cpp"
    break;

  case 235: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1347 "src/parser.y"
                                                                                                                     {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->dim = (yyvsp[-5].ival);
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-9].sval));
        (yyval.stmt) = ds;
    }
#line 5253 "build/parser.cpp"
    break;

  case 236: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_DIM LPAREN KW_DIM_VAR COLON INTEGER_LITERAL RPAREN KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1357 "src/parser.y"
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
#line 5268 "build/parser.cpp"
    break;

  case 237: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_DIM LPAREN KW_DIM_VAR COLON INTEGER_LITERAL RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1368 "src/parser.y"
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
#line 5283 "build/parser.cpp"
    break;

  case 238: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_DIM LPAREN KW_DIM_AUTO COLON INTEGER_LITERAL RPAREN KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1379 "src/parser.y"
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
#line 5298 "build/parser.cpp"
    break;

  case 239: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_DIM LPAREN KW_DIM_AUTO COLON INTEGER_LITERAL RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1390 "src/parser.y"
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
#line 5313 "build/parser.cpp"
    break;

  case 240: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1401 "src/parser.y"
                                                                        {
        auto* ds = new rpg::DclDS((yyvsp[-5].sval));
        ds->like_ds = (yyvsp[-2].sval);
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
        (yyval.stmt) = ds;
    }
#line 5325 "build/parser.cpp"
    break;

  case 241: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1409 "src/parser.y"
                                                                                                             {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->like_ds = (yyvsp[-6].sval);
        ds->dim = (yyvsp[-2].ival);
        free((yyvsp[-9].sval));
        free((yyvsp[-6].sval));
        (yyval.stmt) = ds;
    }
#line 5338 "build/parser.cpp"
    break;

  case 242: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_PREFIX LPAREN IDENTIFIER RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1418 "src/parser.y"
                                                                                                                   {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->qualified = true;
        ds->prefix = (yyvsp[-5].sval);
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-9].sval)); free((yyvsp[-5].sval));
        (yyval.stmt) = ds;
    }
#line 5352 "build/parser.cpp"
    break;

  case 243: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_PREFIX LPAREN IDENTIFIER COLON INTEGER_LITERAL RPAREN KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1428 "src/parser.y"
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
#line 5367 "build/parser.cpp"
    break;

  case 244: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_PREFIX LPAREN IDENTIFIER COLON INTEGER_LITERAL RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1439 "src/parser.y"
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
#line 5382 "build/parser.cpp"
    break;

  case 245: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_PREFIX LPAREN IDENTIFIER RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1450 "src/parser.y"
                                                                                                      {
        auto* ds = new rpg::DclDS((yyvsp[-8].sval));
        ds->qualified = false;
        ds->prefix = (yyvsp[-5].sval);
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-8].sval)); free((yyvsp[-5].sval));
        (yyval.stmt) = ds;
    }
#line 5396 "build/parser.cpp"
    break;

  case 246: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER psds_kw KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1460 "src/parser.y"
                                                                                        {
        auto* ds = new rpg::DclDS((yyvsp[-6].sval));
        ds->is_psds = true;
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-6].sval));
        (yyval.stmt) = ds;
    }
#line 5410 "build/parser.cpp"
    break;

  case 247: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED psds_kw SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1470 "src/parser.y"
                                                                                        {
        auto* ds = new rpg::DclDS((yyvsp[-6].sval));
        ds->is_psds = true;
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-6].sval));
        (yyval.stmt) = ds;
    }
#line 5424 "build/parser.cpp"
    break;

  case 248: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER psds_kw SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1480 "src/parser.y"
                                                                           {
        auto* ds = new rpg::DclDS((yyvsp[-5].sval));
        ds->is_psds = true;
        ds->qualified = false;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-5].sval));
        (yyval.stmt) = ds;
    }
#line 5438 "build/parser.cpp"
    break;

  case 249: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER psds_kw SEMICOLON  */
#line 1490 "src/parser.y"
                                             {
        auto* ds = new rpg::DclDS((yyvsp[-2].sval));
        ds->is_psds = true;
        ds->qualified = false;
        free((yyvsp[-2].sval));
        (yyval.stmt) = ds;
    }
#line 5450 "build/parser.cpp"
    break;

  case 250: /* ds_fields: %empty  */
#line 1500 "src/parser.y"
                {
        (yyval.ds_field_list) = new DSFieldList();
    }
#line 5458 "build/parser.cpp"
    break;

  case 251: /* ds_fields: ds_fields ds_field  */
#line 1503 "src/parser.y"
                         {
        (yyval.ds_field_list) = (yyvsp[-1].ds_field_list);
        (yyval.ds_field_list)->fields.push_back(*(yyvsp[0].ds_field));
        delete (yyvsp[0].ds_field);
    }
#line 5468 "build/parser.cpp"
    break;

  case 252: /* psds_kw: KW_PSDS  */
#line 1511 "src/parser.y"
            {}
#line 5474 "build/parser.cpp"
    break;

  case 253: /* psds_kw: KW_SDS  */
#line 1512 "src/parser.y"
             {}
#line 5480 "build/parser.cpp"
    break;

  case 254: /* ds_field: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1516 "src/parser.y"
                                                              {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5489 "build/parser.cpp"
    break;

  case 255: /* ds_field: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1520 "src/parser.y"
                                                                 {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5498 "build/parser.cpp"
    break;

  case 256: /* ds_field: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1524 "src/parser.y"
                                                                    {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5507 "build/parser.cpp"
    break;

  case 257: /* ds_field: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1528 "src/parser.y"
                                                                                         {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival)};
        free((yyvsp[-7].sval));
    }
#line 5516 "build/parser.cpp"
    break;

  case 258: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1533 "src/parser.y"
                                                                            {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5525 "build/parser.cpp"
    break;

  case 259: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1537 "src/parser.y"
                                                                             {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5534 "build/parser.cpp"
    break;

  case 260: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1541 "src/parser.y"
                                                                                {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5543 "build/parser.cpp"
    break;

  case 261: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1545 "src/parser.y"
                                                                                                     {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival)};
        free((yyvsp[-7].sval));
    }
#line 5552 "build/parser.cpp"
    break;

  case 262: /* ds_field: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_POS LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1550 "src/parser.y"
                                                                                                      {
        auto* f = new rpg::DSField{(yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0};
        f->pos = (yyvsp[-2].ival);
        free((yyvsp[-9].sval));
        (yyval.ds_field) = f;
    }
#line 5563 "build/parser.cpp"
    break;

  case 263: /* ds_field: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_POS LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1556 "src/parser.y"
                                                                                                     {
        auto* f = new rpg::DSField{(yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0};
        f->pos = (yyvsp[-2].ival);
        free((yyvsp[-9].sval));
        (yyval.ds_field) = f;
    }
#line 5574 "build/parser.cpp"
    break;

  case 264: /* ds_field: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_POS LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1562 "src/parser.y"
                                                                                                                              {
        auto* f = new rpg::DSField{(yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival)};
        f->pos = (yyvsp[-2].ival);
        free((yyvsp[-11].sval));
        (yyval.ds_field) = f;
    }
#line 5585 "build/parser.cpp"
    break;

  case 265: /* ds_field: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OVERLAY LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1569 "src/parser.y"
                                                                                                     {
        auto* f = new rpg::DSField{(yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0};
        f->overlay_field = (yyvsp[-2].sval);
        free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
        (yyval.ds_field) = f;
    }
#line 5596 "build/parser.cpp"
    break;

  case 266: /* ds_field: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OVERLAY LPAREN IDENTIFIER COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1576 "src/parser.y"
                                                                                                                           {
        auto* f = new rpg::DSField{(yyvsp[-11].sval), rpg::RPGType::CHAR, (yyvsp[-8].ival), 0, 0};
        f->overlay_field = (yyvsp[-4].sval);
        f->overlay_pos = (yyvsp[-2].ival);
        free((yyvsp[-11].sval)); free((yyvsp[-4].sval));
        (yyval.ds_field) = f;
    }
#line 5608 "build/parser.cpp"
    break;

  case 267: /* ds_field: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OVERLAY LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1583 "src/parser.y"
                                                                                                    {
        auto* f = new rpg::DSField{(yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0};
        f->overlay_field = (yyvsp[-2].sval);
        free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
        (yyval.ds_field) = f;
    }
#line 5619 "build/parser.cpp"
    break;

  case 268: /* ds_field: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OVERLAY LPAREN IDENTIFIER COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1589 "src/parser.y"
                                                                                                                          {
        auto* f = new rpg::DSField{(yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0};
        f->overlay_field = (yyvsp[-4].sval);
        f->overlay_pos = (yyvsp[-2].ival);
        free((yyvsp[-11].sval)); free((yyvsp[-4].sval));
        (yyval.ds_field) = f;
    }
#line 5631 "build/parser.cpp"
    break;

  case 269: /* ds_field: IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1597 "src/parser.y"
                                                              {
        auto* f = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::CHAR, 0, 0, 0};
        f->likeds = (yyvsp[-2].sval);
        free((yyvsp[-5].sval)); free((yyvsp[-2].sval));
        (yyval.ds_field) = f;
    }
#line 5642 "build/parser.cpp"
    break;

  case 270: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1603 "src/parser.y"
                                                                          {
        auto* f = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::CHAR, 0, 0, 0};
        f->likeds = (yyvsp[-2].sval);
        free((yyvsp[-5].sval)); free((yyvsp[-2].sval));
        (yyval.ds_field) = f;
    }
#line 5653 "build/parser.cpp"
    break;

  case 271: /* if_stmt: KW_IF expression SEMICOLON statement_list elseif_clauses else_clause KW_ENDIF SEMICOLON  */
#line 1614 "src/parser.y"
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
#line 5678 "build/parser.cpp"
    break;

  case 272: /* elseif_clauses: %empty  */
#line 1637 "src/parser.y"
                { (yyval.elseif_list) = nullptr; }
#line 5684 "build/parser.cpp"
    break;

  case 273: /* elseif_clauses: elseif_clauses elseif_clause  */
#line 1638 "src/parser.y"
                                   {
        if (!(yyvsp[-1].elseif_list)) (yyvsp[-1].elseif_list) = new std::vector<ElseIfData*>();
        (yyval.elseif_list) = (yyvsp[-1].elseif_list);
        (yyval.elseif_list)->push_back((yyvsp[0].elseif_data));
    }
#line 5694 "build/parser.cpp"
    break;

  case 274: /* elseif_clause: KW_ELSEIF expression SEMICOLON statement_list  */
#line 1646 "src/parser.y"
                                                  {
        (yyval.elseif_data) = new ElseIfData();
        (yyval.elseif_data)->cond = (yyvsp[-2].expr);
        (yyval.elseif_data)->body = std::move((yyvsp[0].stmt_list)->stmts);
        delete (yyvsp[0].stmt_list);
    }
#line 5705 "build/parser.cpp"
    break;

  case 275: /* else_clause: %empty  */
#line 1655 "src/parser.y"
                { (yyval.stmt_list) = nullptr; }
#line 5711 "build/parser.cpp"
    break;

  case 276: /* else_clause: KW_ELSE SEMICOLON statement_list  */
#line 1656 "src/parser.y"
                                       {
        (yyval.stmt_list) = (yyvsp[0].stmt_list);
    }
#line 5719 "build/parser.cpp"
    break;

  case 277: /* dow_stmt: KW_DOW expression SEMICOLON statement_list KW_ENDDO SEMICOLON  */
#line 1662 "src/parser.y"
                                                                  {
        auto* node = new rpg::DowStmt(std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        (yyval.stmt) = node;
    }
#line 5730 "build/parser.cpp"
    break;

  case 278: /* dou_stmt: KW_DOU expression SEMICOLON statement_list KW_ENDDO SEMICOLON  */
#line 1671 "src/parser.y"
                                                                  {
        auto* node = new rpg::DouStmt(std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        (yyval.stmt) = node;
    }
#line 5741 "build/parser.cpp"
    break;

  case 279: /* for_stmt: KW_FOR ident EQUALS expression KW_TO expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1680 "src/parser.y"
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
#line 5756 "build/parser.cpp"
    break;

  case 280: /* for_stmt: KW_FOR ident EQUALS expression KW_TO expression KW_BY expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1690 "src/parser.y"
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
#line 5771 "build/parser.cpp"
    break;

  case 281: /* for_stmt: KW_FOR ident EQUALS expression KW_DOWNTO expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1700 "src/parser.y"
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
#line 5786 "build/parser.cpp"
    break;

  case 282: /* for_stmt: KW_FOR ident EQUALS expression KW_DOWNTO expression KW_BY expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1710 "src/parser.y"
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
#line 5801 "build/parser.cpp"
    break;

  case 283: /* for_each_stmt: KW_FOR_EACH ident KW_IN expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1723 "src/parser.y"
                                                                                    {
        auto* node = new rpg::ForEachStmt((yyvsp[-6].sval), std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        free((yyvsp[-6].sval));
        (yyval.stmt) = node;
    }
#line 5813 "build/parser.cpp"
    break;

  case 284: /* select_stmt: KW_SELECT SEMICOLON when_clauses other_clause KW_ENDSL SEMICOLON  */
#line 1733 "src/parser.y"
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
#line 5834 "build/parser.cpp"
    break;

  case 285: /* when_clauses: when_clause  */
#line 1752 "src/parser.y"
                {
        (yyval.when_list) = new std::vector<WhenData*>();
        (yyval.when_list)->push_back((yyvsp[0].when_data));
    }
#line 5843 "build/parser.cpp"
    break;

  case 286: /* when_clauses: when_clauses when_clause  */
#line 1756 "src/parser.y"
                               {
        (yyval.when_list) = (yyvsp[-1].when_list);
        (yyval.when_list)->push_back((yyvsp[0].when_data));
    }
#line 5852 "build/parser.cpp"
    break;

  case 287: /* when_clause: KW_WHEN expression SEMICOLON statement_list  */
#line 1763 "src/parser.y"
                                                {
        (yyval.when_data) = new WhenData();
        (yyval.when_data)->cond = (yyvsp[-2].expr);
        (yyval.when_data)->body = std::move((yyvsp[0].stmt_list)->stmts);
        delete (yyvsp[0].stmt_list);
    }
#line 5863 "build/parser.cpp"
    break;

  case 288: /* other_clause: %empty  */
#line 1772 "src/parser.y"
                { (yyval.stmt_list) = nullptr; }
#line 5869 "build/parser.cpp"
    break;

  case 289: /* other_clause: KW_OTHER SEMICOLON statement_list  */
#line 1773 "src/parser.y"
                                        {
        (yyval.stmt_list) = (yyvsp[0].stmt_list);
    }
#line 5877 "build/parser.cpp"
    break;

  case 290: /* iter_stmt: KW_ITER SEMICOLON  */
#line 1779 "src/parser.y"
                      { (yyval.stmt) = new rpg::IterStmt(); }
#line 5883 "build/parser.cpp"
    break;

  case 291: /* leave_stmt: KW_LEAVE SEMICOLON  */
#line 1783 "src/parser.y"
                       { (yyval.stmt) = new rpg::LeaveStmt(); }
#line 5889 "build/parser.cpp"
    break;

  case 292: /* expression: or_expr  */
#line 1789 "src/parser.y"
            { (yyval.expr) = (yyvsp[0].expr); }
#line 5895 "build/parser.cpp"
    break;

  case 293: /* or_expr: and_expr  */
#line 1793 "src/parser.y"
             { (yyval.expr) = (yyvsp[0].expr); }
#line 5901 "build/parser.cpp"
    break;

  case 294: /* or_expr: or_expr KW_OR and_expr  */
#line 1794 "src/parser.y"
                             {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::OR,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5911 "build/parser.cpp"
    break;

  case 295: /* and_expr: not_expr  */
#line 1802 "src/parser.y"
             { (yyval.expr) = (yyvsp[0].expr); }
#line 5917 "build/parser.cpp"
    break;

  case 296: /* and_expr: and_expr KW_AND not_expr  */
#line 1803 "src/parser.y"
                               {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::AND,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5927 "build/parser.cpp"
    break;

  case 297: /* not_expr: comparison_expr  */
#line 1811 "src/parser.y"
                    { (yyval.expr) = (yyvsp[0].expr); }
#line 5933 "build/parser.cpp"
    break;

  case 298: /* not_expr: KW_NOT comparison_expr  */
#line 1812 "src/parser.y"
                             {
        (yyval.expr) = new rpg::NotExpr(std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5941 "build/parser.cpp"
    break;

  case 299: /* comparison_expr: additive_expr  */
#line 1818 "src/parser.y"
                  { (yyval.expr) = (yyvsp[0].expr); }
#line 5947 "build/parser.cpp"
    break;

  case 300: /* comparison_expr: comparison_expr EQUALS additive_expr  */
#line 1819 "src/parser.y"
                                           {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::EQ,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5957 "build/parser.cpp"
    break;

  case 301: /* comparison_expr: comparison_expr NE additive_expr  */
#line 1824 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::NE,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5967 "build/parser.cpp"
    break;

  case 302: /* comparison_expr: comparison_expr LT additive_expr  */
#line 1829 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::LT,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5977 "build/parser.cpp"
    break;

  case 303: /* comparison_expr: comparison_expr GT additive_expr  */
#line 1834 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::GT,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5987 "build/parser.cpp"
    break;

  case 304: /* comparison_expr: comparison_expr LE additive_expr  */
#line 1839 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::LE,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5997 "build/parser.cpp"
    break;

  case 305: /* comparison_expr: comparison_expr GE additive_expr  */
#line 1844 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::GE,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6007 "build/parser.cpp"
    break;

  case 306: /* comparison_expr: additive_expr KW_IN additive_expr  */
#line 1849 "src/parser.y"
                                        {
        (yyval.expr) = new rpg::InExpr(
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6017 "build/parser.cpp"
    break;

  case 307: /* additive_expr: multiplicative_expr  */
#line 1857 "src/parser.y"
                        { (yyval.expr) = (yyvsp[0].expr); }
#line 6023 "build/parser.cpp"
    break;

  case 308: /* additive_expr: additive_expr PLUS multiplicative_expr  */
#line 1858 "src/parser.y"
                                             {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::ADD,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6033 "build/parser.cpp"
    break;

  case 309: /* additive_expr: additive_expr MINUS multiplicative_expr  */
#line 1863 "src/parser.y"
                                              {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::SUB,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6043 "build/parser.cpp"
    break;

  case 310: /* multiplicative_expr: power_expr  */
#line 1871 "src/parser.y"
               { (yyval.expr) = (yyvsp[0].expr); }
#line 6049 "build/parser.cpp"
    break;

  case 311: /* multiplicative_expr: multiplicative_expr STAR power_expr  */
#line 1872 "src/parser.y"
                                          {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::MUL,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6059 "build/parser.cpp"
    break;

  case 312: /* multiplicative_expr: multiplicative_expr SLASH power_expr  */
#line 1877 "src/parser.y"
                                           {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::DIV,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6069 "build/parser.cpp"
    break;

  case 313: /* power_expr: unary_expr  */
#line 1885 "src/parser.y"
               { (yyval.expr) = (yyvsp[0].expr); }
#line 6075 "build/parser.cpp"
    break;

  case 314: /* power_expr: unary_expr POWER power_expr  */
#line 1886 "src/parser.y"
                                  {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::POWER,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6085 "build/parser.cpp"
    break;

  case 315: /* unary_expr: postfix_expr  */
#line 1894 "src/parser.y"
                 { (yyval.expr) = (yyvsp[0].expr); }
#line 6091 "build/parser.cpp"
    break;

  case 316: /* unary_expr: MINUS postfix_expr  */
#line 1895 "src/parser.y"
                         {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::SUB,
            std::unique_ptr<rpg::Expression>(new rpg::IntLiteral(0)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6101 "build/parser.cpp"
    break;

  case 317: /* postfix_expr: primary_expr  */
#line 1903 "src/parser.y"
                 { (yyval.expr) = (yyvsp[0].expr); }
#line 6107 "build/parser.cpp"
    break;

  case 318: /* postfix_expr: postfix_expr DOT IDENTIFIER  */
#line 1904 "src/parser.y"
                                  {
        (yyval.expr) = new rpg::DotExpr(std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)), (yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 6116 "build/parser.cpp"
    break;

  case 319: /* ident: IDENTIFIER  */
#line 1911 "src/parser.y"
               { (yyval.sval) = (yyvsp[0].sval); }
#line 6122 "build/parser.cpp"
    break;

  case 320: /* ident: KW_UNS  */
#line 1912 "src/parser.y"
             { (yyval.sval) = strdup("UNS"); }
#line 6128 "build/parser.cpp"
    break;

  case 321: /* ident: KW_FLOAT_TYPE  */
#line 1913 "src/parser.y"
                    { (yyval.sval) = strdup("FLOAT"); }
#line 6134 "build/parser.cpp"
    break;

  case 322: /* ident: KW_GRAPH  */
#line 1914 "src/parser.y"
               { (yyval.sval) = strdup("GRAPH"); }
#line 6140 "build/parser.cpp"
    break;

  case 323: /* ident: KW_ASCEND  */
#line 1915 "src/parser.y"
                { (yyval.sval) = strdup("ASCEND"); }
#line 6146 "build/parser.cpp"
    break;

  case 324: /* ident: KW_DESCEND  */
#line 1916 "src/parser.y"
                 { (yyval.sval) = strdup("DESCEND"); }
#line 6152 "build/parser.cpp"
    break;

  case 325: /* ident: KW_IN  */
#line 1917 "src/parser.y"
            { (yyval.sval) = strdup("IN"); }
#line 6158 "build/parser.cpp"
    break;

  case 326: /* ident: KW_RTNPARM  */
#line 1918 "src/parser.y"
                 { (yyval.sval) = strdup("RTNPARM"); }
#line 6164 "build/parser.cpp"
    break;

  case 327: /* ident: KW_OPDESC  */
#line 1919 "src/parser.y"
                { (yyval.sval) = strdup("OPDESC"); }
#line 6170 "build/parser.cpp"
    break;

  case 328: /* ident: KW_NULLIND  */
#line 1920 "src/parser.y"
                 { (yyval.sval) = strdup("NULLIND"); }
#line 6176 "build/parser.cpp"
    break;

  case 329: /* ident: KW_DATFMT  */
#line 1921 "src/parser.y"
                { (yyval.sval) = strdup("DATFMT"); }
#line 6182 "build/parser.cpp"
    break;

  case 330: /* ident: KW_TIMFMT  */
#line 1922 "src/parser.y"
                { (yyval.sval) = strdup("TIMFMT"); }
#line 6188 "build/parser.cpp"
    break;

  case 331: /* ident: KW_EXTNAME  */
#line 1923 "src/parser.y"
                 { (yyval.sval) = strdup("EXTNAME"); }
#line 6194 "build/parser.cpp"
    break;

  case 332: /* ident: KW_OVERLAY  */
#line 1924 "src/parser.y"
                 { (yyval.sval) = strdup("OVERLAY"); }
#line 6200 "build/parser.cpp"
    break;

  case 333: /* ident: KW_POS  */
#line 1925 "src/parser.y"
             { (yyval.sval) = strdup("POS"); }
#line 6206 "build/parser.cpp"
    break;

  case 334: /* ident: KW_PREFIX  */
#line 1926 "src/parser.y"
                { (yyval.sval) = strdup("PREFIX"); }
#line 6212 "build/parser.cpp"
    break;

  case 335: /* primary_expr: IDENTIFIER  */
#line 1930 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier((yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 6221 "build/parser.cpp"
    break;

  case 336: /* primary_expr: KW_UNS  */
#line 1934 "src/parser.y"
             { (yyval.expr) = new rpg::Identifier("UNS"); }
#line 6227 "build/parser.cpp"
    break;

  case 337: /* primary_expr: KW_FLOAT_TYPE  */
#line 1935 "src/parser.y"
                    { (yyval.expr) = new rpg::Identifier("FLOAT"); }
#line 6233 "build/parser.cpp"
    break;

  case 338: /* primary_expr: KW_GRAPH  */
#line 1936 "src/parser.y"
               { (yyval.expr) = new rpg::Identifier("GRAPH"); }
#line 6239 "build/parser.cpp"
    break;

  case 339: /* primary_expr: KW_ASCEND  */
#line 1937 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("ASCEND"); }
#line 6245 "build/parser.cpp"
    break;

  case 340: /* primary_expr: KW_DESCEND  */
#line 1938 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("DESCEND"); }
#line 6251 "build/parser.cpp"
    break;

  case 341: /* primary_expr: KW_RTNPARM  */
#line 1939 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("RTNPARM"); }
#line 6257 "build/parser.cpp"
    break;

  case 342: /* primary_expr: KW_OPDESC  */
#line 1940 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("OPDESC"); }
#line 6263 "build/parser.cpp"
    break;

  case 343: /* primary_expr: KW_NULLIND  */
#line 1941 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("NULLIND"); }
#line 6269 "build/parser.cpp"
    break;

  case 344: /* primary_expr: KW_DATFMT  */
#line 1942 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("DATFMT"); }
#line 6275 "build/parser.cpp"
    break;

  case 345: /* primary_expr: KW_OVERLAY  */
#line 1943 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("OVERLAY"); }
#line 6281 "build/parser.cpp"
    break;

  case 346: /* primary_expr: KW_POS  */
#line 1944 "src/parser.y"
             { (yyval.expr) = new rpg::Identifier("POS"); }
#line 6287 "build/parser.cpp"
    break;

  case 347: /* primary_expr: KW_PREFIX  */
#line 1945 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("PREFIX"); }
#line 6293 "build/parser.cpp"
    break;

  case 348: /* primary_expr: KW_TIMFMT  */
#line 1946 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("TIMFMT"); }
#line 6299 "build/parser.cpp"
    break;

  case 349: /* primary_expr: KW_EXTNAME  */
#line 1947 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("EXTNAME"); }
#line 6305 "build/parser.cpp"
    break;

  case 350: /* primary_expr: INTEGER_LITERAL  */
#line 1948 "src/parser.y"
                      {
        (yyval.expr) = new rpg::IntLiteral((yyvsp[0].ival));
    }
#line 6313 "build/parser.cpp"
    break;

  case 351: /* primary_expr: FLOAT_LITERAL  */
#line 1951 "src/parser.y"
                    {
        (yyval.expr) = new rpg::FloatLiteral((yyvsp[0].fval));
    }
#line 6321 "build/parser.cpp"
    break;

  case 352: /* primary_expr: STRING_LITERAL  */
#line 1954 "src/parser.y"
                     {
        (yyval.expr) = new rpg::StringLiteral((yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 6330 "build/parser.cpp"
    break;

  case 353: /* primary_expr: IDENTIFIER LPAREN call_args_opt RPAREN  */
#line 1958 "src/parser.y"
                                             {
        (yyval.expr) = make_func((yyvsp[-3].sval), (yyvsp[-1].expr_list));
        free((yyvsp[-3].sval));
    }
#line 6339 "build/parser.cpp"
    break;

  case 354: /* primary_expr: BIF_CHAR LPAREN arg_list RPAREN  */
#line 1962 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("CHAR", (yyvsp[-1].expr_list));
    }
#line 6347 "build/parser.cpp"
    break;

  case 355: /* primary_expr: BIF_TRIM LPAREN arg_list RPAREN  */
#line 1965 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("TRIM", (yyvsp[-1].expr_list));
    }
#line 6355 "build/parser.cpp"
    break;

  case 356: /* primary_expr: BIF_TRIML LPAREN arg_list RPAREN  */
#line 1968 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("TRIML", (yyvsp[-1].expr_list));
    }
#line 6363 "build/parser.cpp"
    break;

  case 357: /* primary_expr: BIF_TRIMR LPAREN arg_list RPAREN  */
#line 1971 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("TRIMR", (yyvsp[-1].expr_list));
    }
#line 6371 "build/parser.cpp"
    break;

  case 358: /* primary_expr: BIF_LEN LPAREN arg_list RPAREN  */
#line 1974 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("LEN", (yyvsp[-1].expr_list));
    }
#line 6379 "build/parser.cpp"
    break;

  case 359: /* primary_expr: BIF_SUBST LPAREN arg_list RPAREN  */
#line 1977 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("SUBST", (yyvsp[-1].expr_list));
    }
#line 6387 "build/parser.cpp"
    break;

  case 360: /* primary_expr: BIF_SCAN LPAREN arg_list RPAREN  */
#line 1980 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("SCAN", (yyvsp[-1].expr_list));
    }
#line 6395 "build/parser.cpp"
    break;

  case 361: /* primary_expr: BIF_SCANRPL LPAREN arg_list RPAREN  */
#line 1983 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("SCANRPL", (yyvsp[-1].expr_list));
    }
#line 6403 "build/parser.cpp"
    break;

  case 362: /* primary_expr: BIF_XLATE LPAREN arg_list RPAREN  */
#line 1986 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("XLATE", (yyvsp[-1].expr_list));
    }
#line 6411 "build/parser.cpp"
    break;

  case 363: /* primary_expr: BIF_DEC LPAREN arg_list RPAREN  */
#line 1989 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("DEC", (yyvsp[-1].expr_list));
    }
#line 6419 "build/parser.cpp"
    break;

  case 364: /* primary_expr: BIF_INT LPAREN arg_list RPAREN  */
#line 1992 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("INT", (yyvsp[-1].expr_list));
    }
#line 6427 "build/parser.cpp"
    break;

  case 365: /* primary_expr: BIF_ELEM LPAREN arg_list RPAREN  */
#line 1995 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("ELEM", (yyvsp[-1].expr_list));
    }
#line 6435 "build/parser.cpp"
    break;

  case 366: /* primary_expr: BIF_PARMS LPAREN RPAREN  */
#line 1998 "src/parser.y"
                              {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("PARMS", empty);
    }
#line 6444 "build/parser.cpp"
    break;

  case 367: /* primary_expr: BIF_LOOKUP LPAREN arg_list RPAREN  */
#line 2002 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("LOOKUP", (yyvsp[-1].expr_list));
    }
#line 6452 "build/parser.cpp"
    break;

  case 368: /* primary_expr: BIF_EDITC LPAREN arg_list RPAREN  */
#line 2005 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("EDITC", (yyvsp[-1].expr_list));
    }
#line 6460 "build/parser.cpp"
    break;

  case 369: /* primary_expr: BIF_EDITW LPAREN arg_list RPAREN  */
#line 2008 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("EDITW", (yyvsp[-1].expr_list));
    }
#line 6468 "build/parser.cpp"
    break;

  case 370: /* primary_expr: BIF_REPLACE LPAREN arg_list RPAREN  */
#line 2011 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("REPLACE", (yyvsp[-1].expr_list));
    }
#line 6476 "build/parser.cpp"
    break;

  case 371: /* primary_expr: BIF_CHECK LPAREN arg_list RPAREN  */
#line 2014 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("CHECK", (yyvsp[-1].expr_list));
    }
#line 6484 "build/parser.cpp"
    break;

  case 372: /* primary_expr: BIF_CHECKR LPAREN arg_list RPAREN  */
#line 2017 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("CHECKR", (yyvsp[-1].expr_list));
    }
#line 6492 "build/parser.cpp"
    break;

  case 373: /* primary_expr: BIF_LOWER LPAREN arg_list RPAREN  */
#line 2020 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("LOWER", (yyvsp[-1].expr_list));
    }
#line 6500 "build/parser.cpp"
    break;

  case 374: /* primary_expr: BIF_UPPER LPAREN arg_list RPAREN  */
#line 2023 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("UPPER", (yyvsp[-1].expr_list));
    }
#line 6508 "build/parser.cpp"
    break;

  case 375: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_YEARS RPAREN  */
#line 2026 "src/parser.y"
                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("YEARS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6519 "build/parser.cpp"
    break;

  case 376: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_MONTHS RPAREN  */
#line 2032 "src/parser.y"
                                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MONTHS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6530 "build/parser.cpp"
    break;

  case 377: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_DAYS RPAREN  */
#line 2038 "src/parser.y"
                                                       {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("DAYS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6541 "build/parser.cpp"
    break;

  case 378: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_HOURS RPAREN  */
#line 2044 "src/parser.y"
                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("HOURS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6552 "build/parser.cpp"
    break;

  case 379: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_MINUTES RPAREN  */
#line 2050 "src/parser.y"
                                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MINUTES"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6563 "build/parser.cpp"
    break;

  case 380: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_SECONDS RPAREN  */
#line 2056 "src/parser.y"
                                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("SECONDS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6574 "build/parser.cpp"
    break;

  case 381: /* primary_expr: BIF_FLOAT LPAREN arg_list RPAREN  */
#line 2062 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("FLOAT", (yyvsp[-1].expr_list));
    }
#line 6582 "build/parser.cpp"
    break;

  case 382: /* primary_expr: BIF_SQRT LPAREN arg_list RPAREN  */
#line 2065 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("SQRT", (yyvsp[-1].expr_list));
    }
#line 6590 "build/parser.cpp"
    break;

  case 383: /* primary_expr: BIF_MAX LPAREN arg_list RPAREN  */
#line 2068 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("MAX", (yyvsp[-1].expr_list));
    }
#line 6598 "build/parser.cpp"
    break;

  case 384: /* primary_expr: BIF_MIN LPAREN arg_list RPAREN  */
#line 2071 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("MIN", (yyvsp[-1].expr_list));
    }
#line 6606 "build/parser.cpp"
    break;

  case 385: /* primary_expr: BIF_STATUS LPAREN RPAREN  */
#line 2074 "src/parser.y"
                               {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("STATUS", empty);
    }
#line 6615 "build/parser.cpp"
    break;

  case 386: /* primary_expr: BIF_ERROR LPAREN RPAREN  */
#line 2078 "src/parser.y"
                              {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("ERROR", empty);
    }
#line 6624 "build/parser.cpp"
    break;

  case 387: /* primary_expr: BIF_SIZE LPAREN arg_list RPAREN  */
#line 2082 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("SIZE", (yyvsp[-1].expr_list));
    }
#line 6632 "build/parser.cpp"
    break;

  case 388: /* primary_expr: BIF_ADDR LPAREN arg_list RPAREN  */
#line 2085 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("ADDR", (yyvsp[-1].expr_list));
    }
#line 6640 "build/parser.cpp"
    break;

  case 389: /* primary_expr: BIF_ABS LPAREN arg_list RPAREN  */
#line 2088 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("ABS", (yyvsp[-1].expr_list));
    }
#line 6648 "build/parser.cpp"
    break;

  case 390: /* primary_expr: BIF_DIV LPAREN arg_list RPAREN  */
#line 2091 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("DIV", (yyvsp[-1].expr_list));
    }
#line 6656 "build/parser.cpp"
    break;

  case 391: /* primary_expr: BIF_REM LPAREN arg_list RPAREN  */
#line 2094 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("REM", (yyvsp[-1].expr_list));
    }
#line 6664 "build/parser.cpp"
    break;

  case 392: /* primary_expr: BIF_DATE LPAREN arg_list RPAREN  */
#line 2097 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("DATE", (yyvsp[-1].expr_list));
    }
#line 6672 "build/parser.cpp"
    break;

  case 393: /* primary_expr: BIF_DATE LPAREN RPAREN  */
#line 2100 "src/parser.y"
                             {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("DATE", empty);
    }
#line 6681 "build/parser.cpp"
    break;

  case 394: /* primary_expr: BIF_TIME LPAREN arg_list RPAREN  */
#line 2104 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("TIME", (yyvsp[-1].expr_list));
    }
#line 6689 "build/parser.cpp"
    break;

  case 395: /* primary_expr: BIF_TIME LPAREN RPAREN  */
#line 2107 "src/parser.y"
                             {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("TIME", empty);
    }
#line 6698 "build/parser.cpp"
    break;

  case 396: /* primary_expr: BIF_TIMESTAMP LPAREN arg_list RPAREN  */
#line 2111 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TIMESTAMP", (yyvsp[-1].expr_list));
    }
#line 6706 "build/parser.cpp"
    break;

  case 397: /* primary_expr: BIF_TIMESTAMP LPAREN RPAREN  */
#line 2114 "src/parser.y"
                                  {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("TIMESTAMP", empty);
    }
#line 6715 "build/parser.cpp"
    break;

  case 398: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_DAYS RPAREN  */
#line 2118 "src/parser.y"
                                                                       {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("DAYS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 6727 "build/parser.cpp"
    break;

  case 399: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_MONTHS RPAREN  */
#line 2125 "src/parser.y"
                                                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MONTHS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 6739 "build/parser.cpp"
    break;

  case 400: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_YEARS RPAREN  */
#line 2132 "src/parser.y"
                                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("YEARS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 6751 "build/parser.cpp"
    break;

  case 401: /* primary_expr: BIF_DAYS LPAREN expression RPAREN  */
#line 2139 "src/parser.y"
                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("DAYS", args);
    }
#line 6761 "build/parser.cpp"
    break;

  case 402: /* primary_expr: BIF_MONTHS LPAREN expression RPAREN  */
#line 2144 "src/parser.y"
                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("MONTHS", args);
    }
#line 6771 "build/parser.cpp"
    break;

  case 403: /* primary_expr: BIF_YEARS LPAREN expression RPAREN  */
#line 2149 "src/parser.y"
                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("YEARS", args);
    }
#line 6781 "build/parser.cpp"
    break;

  case 404: /* primary_expr: BIF_FOUND LPAREN RPAREN  */
#line 2154 "src/parser.y"
                              {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("FOUND", empty);
    }
#line 6790 "build/parser.cpp"
    break;

  case 405: /* primary_expr: BIF_EOF LPAREN RPAREN  */
#line 2158 "src/parser.y"
                            {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("EOF", empty);
    }
#line 6799 "build/parser.cpp"
    break;

  case 406: /* primary_expr: BIF_ALLOC LPAREN arg_list RPAREN  */
#line 2162 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("ALLOC", (yyvsp[-1].expr_list));
    }
#line 6807 "build/parser.cpp"
    break;

  case 407: /* primary_expr: BIF_REALLOC LPAREN arg_list RPAREN  */
#line 2165 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("REALLOC", (yyvsp[-1].expr_list));
    }
#line 6815 "build/parser.cpp"
    break;

  case 408: /* primary_expr: BIF_XFOOT LPAREN arg_list RPAREN  */
#line 2168 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("XFOOT", (yyvsp[-1].expr_list));
    }
#line 6823 "build/parser.cpp"
    break;

  case 409: /* primary_expr: BIF_UNS LPAREN arg_list RPAREN  */
#line 2171 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("UNS", (yyvsp[-1].expr_list));
    }
#line 6831 "build/parser.cpp"
    break;

  case 410: /* primary_expr: BIF_INTH LPAREN arg_list RPAREN  */
#line 2174 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("INTH", (yyvsp[-1].expr_list));
    }
#line 6839 "build/parser.cpp"
    break;

  case 411: /* primary_expr: BIF_DECH LPAREN arg_list RPAREN  */
#line 2177 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("DECH", (yyvsp[-1].expr_list));
    }
#line 6847 "build/parser.cpp"
    break;

  case 412: /* primary_expr: BIF_DECPOS LPAREN arg_list RPAREN  */
#line 2180 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("DECPOS", (yyvsp[-1].expr_list));
    }
#line 6855 "build/parser.cpp"
    break;

  case 413: /* primary_expr: BIF_SPLIT LPAREN arg_list RPAREN  */
#line 2183 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("SPLIT", (yyvsp[-1].expr_list));
    }
#line 6863 "build/parser.cpp"
    break;

  case 414: /* primary_expr: BIF_CONCAT LPAREN arg_list RPAREN  */
#line 2186 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("CONCAT", (yyvsp[-1].expr_list));
    }
#line 6871 "build/parser.cpp"
    break;

  case 415: /* primary_expr: BIF_CONCATARR LPAREN arg_list RPAREN  */
#line 2189 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("CONCATARR", (yyvsp[-1].expr_list));
    }
#line 6879 "build/parser.cpp"
    break;

  case 416: /* primary_expr: BIF_LEFT LPAREN arg_list RPAREN  */
#line 2192 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("LEFT", (yyvsp[-1].expr_list));
    }
#line 6887 "build/parser.cpp"
    break;

  case 417: /* primary_expr: BIF_RIGHT LPAREN arg_list RPAREN  */
#line 2195 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("RIGHT", (yyvsp[-1].expr_list));
    }
#line 6895 "build/parser.cpp"
    break;

  case 418: /* primary_expr: BIF_STR LPAREN arg_list RPAREN  */
#line 2198 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("STR", (yyvsp[-1].expr_list));
    }
#line 6903 "build/parser.cpp"
    break;

  case 419: /* primary_expr: BIF_SUBARR LPAREN arg_list RPAREN  */
#line 2201 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("SUBARR", (yyvsp[-1].expr_list));
    }
#line 6911 "build/parser.cpp"
    break;

  case 420: /* primary_expr: BIF_MAXARR LPAREN arg_list RPAREN  */
#line 2204 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("MAXARR", (yyvsp[-1].expr_list));
    }
#line 6919 "build/parser.cpp"
    break;

  case 421: /* primary_expr: BIF_MINARR LPAREN arg_list RPAREN  */
#line 2207 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("MINARR", (yyvsp[-1].expr_list));
    }
#line 6927 "build/parser.cpp"
    break;

  case 422: /* primary_expr: BIF_LIST LPAREN arg_list RPAREN  */
#line 2210 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("LIST", (yyvsp[-1].expr_list));
    }
#line 6935 "build/parser.cpp"
    break;

  case 423: /* primary_expr: BIF_RANGE LPAREN arg_list RPAREN  */
#line 2213 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("RANGE", (yyvsp[-1].expr_list));
    }
#line 6943 "build/parser.cpp"
    break;

  case 424: /* primary_expr: BIF_LOOKUPLT LPAREN arg_list RPAREN  */
#line 2216 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPLT", (yyvsp[-1].expr_list));
    }
#line 6951 "build/parser.cpp"
    break;

  case 425: /* primary_expr: BIF_LOOKUPGE LPAREN arg_list RPAREN  */
#line 2219 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPGE", (yyvsp[-1].expr_list));
    }
#line 6959 "build/parser.cpp"
    break;

  case 426: /* primary_expr: BIF_LOOKUPLE LPAREN arg_list RPAREN  */
#line 2222 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPLE", (yyvsp[-1].expr_list));
    }
#line 6967 "build/parser.cpp"
    break;

  case 427: /* primary_expr: BIF_LOOKUPGT LPAREN arg_list RPAREN  */
#line 2225 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPGT", (yyvsp[-1].expr_list));
    }
#line 6975 "build/parser.cpp"
    break;

  case 428: /* primary_expr: BIF_TLOOKUP LPAREN arg_list RPAREN  */
#line 2228 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("TLOOKUP", (yyvsp[-1].expr_list));
    }
#line 6983 "build/parser.cpp"
    break;

  case 429: /* primary_expr: BIF_TLOOKUPLT LPAREN arg_list RPAREN  */
#line 2231 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TLOOKUPLT", (yyvsp[-1].expr_list));
    }
#line 6991 "build/parser.cpp"
    break;

  case 430: /* primary_expr: BIF_TLOOKUPGT LPAREN arg_list RPAREN  */
#line 2234 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TLOOKUPGT", (yyvsp[-1].expr_list));
    }
#line 6999 "build/parser.cpp"
    break;

  case 431: /* primary_expr: BIF_TLOOKUPLE LPAREN arg_list RPAREN  */
#line 2237 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TLOOKUPLE", (yyvsp[-1].expr_list));
    }
#line 7007 "build/parser.cpp"
    break;

  case 432: /* primary_expr: BIF_TLOOKUPGE LPAREN arg_list RPAREN  */
#line 2240 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TLOOKUPGE", (yyvsp[-1].expr_list));
    }
#line 7015 "build/parser.cpp"
    break;

  case 433: /* primary_expr: BIF_HOURS LPAREN expression RPAREN  */
#line 2243 "src/parser.y"
                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("HOURS", args);
    }
#line 7025 "build/parser.cpp"
    break;

  case 434: /* primary_expr: BIF_MINUTES LPAREN expression RPAREN  */
#line 2248 "src/parser.y"
                                           {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("MINUTES", args);
    }
#line 7035 "build/parser.cpp"
    break;

  case 435: /* primary_expr: BIF_SECONDS LPAREN expression RPAREN  */
#line 2253 "src/parser.y"
                                           {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("SECONDS", args);
    }
#line 7045 "build/parser.cpp"
    break;

  case 436: /* primary_expr: BIF_MSECONDS LPAREN expression RPAREN  */
#line 2258 "src/parser.y"
                                            {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("MSECONDS", args);
    }
#line 7055 "build/parser.cpp"
    break;

  case 437: /* primary_expr: BIF_PADDR LPAREN IDENTIFIER RPAREN  */
#line 2263 "src/parser.y"
                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::StringLiteral((yyvsp[-1].sval)));
        free((yyvsp[-1].sval));
        (yyval.expr) = make_bif("PADDR", args);
    }
#line 7066 "build/parser.cpp"
    break;

  case 438: /* primary_expr: BIF_PROC LPAREN RPAREN  */
#line 2269 "src/parser.y"
                             {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("PROC", empty);
    }
#line 7075 "build/parser.cpp"
    break;

  case 439: /* primary_expr: BIF_PROC  */
#line 2273 "src/parser.y"
               {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("PROC", empty);
    }
#line 7084 "build/parser.cpp"
    break;

  case 440: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_HOURS RPAREN  */
#line 2277 "src/parser.y"
                                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("HOURS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 7096 "build/parser.cpp"
    break;

  case 441: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_MINUTES RPAREN  */
#line 2284 "src/parser.y"
                                                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MINUTES"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 7108 "build/parser.cpp"
    break;

  case 442: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_SECONDS RPAREN  */
#line 2291 "src/parser.y"
                                                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("SECONDS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 7120 "build/parser.cpp"
    break;

  case 443: /* primary_expr: KW_ALL STRING_LITERAL  */
#line 2298 "src/parser.y"
                            {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::StringLiteral((yyvsp[0].sval)));
        free((yyvsp[0].sval));
        (yyval.expr) = make_bif("ALL", args);
    }
#line 7131 "build/parser.cpp"
    break;

  case 444: /* primary_expr: BIF_PASSED LPAREN ident RPAREN  */
#line 2304 "src/parser.y"
                                     {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::Identifier((yyvsp[-1].sval)));
        free((yyvsp[-1].sval));
        (yyval.expr) = make_bif("PASSED", args);
    }
#line 7142 "build/parser.cpp"
    break;

  case 445: /* primary_expr: BIF_OMITTED LPAREN ident RPAREN  */
#line 2310 "src/parser.y"
                                      {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::Identifier((yyvsp[-1].sval)));
        free((yyvsp[-1].sval));
        (yyval.expr) = make_bif("OMITTED", args);
    }
#line 7153 "build/parser.cpp"
    break;

  case 446: /* primary_expr: BIF_BITAND LPAREN arg_list RPAREN  */
#line 2316 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("BITAND", (yyvsp[-1].expr_list));
    }
#line 7161 "build/parser.cpp"
    break;

  case 447: /* primary_expr: BIF_BITNOT LPAREN arg_list RPAREN  */
#line 2319 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("BITNOT", (yyvsp[-1].expr_list));
    }
#line 7169 "build/parser.cpp"
    break;

  case 448: /* primary_expr: BIF_BITOR LPAREN arg_list RPAREN  */
#line 2322 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("BITOR", (yyvsp[-1].expr_list));
    }
#line 7177 "build/parser.cpp"
    break;

  case 449: /* primary_expr: BIF_BITXOR LPAREN arg_list RPAREN  */
#line 2325 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("BITXOR", (yyvsp[-1].expr_list));
    }
#line 7185 "build/parser.cpp"
    break;

  case 450: /* primary_expr: BIF_SCANR LPAREN arg_list RPAREN  */
#line 2328 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("SCANR", (yyvsp[-1].expr_list));
    }
#line 7193 "build/parser.cpp"
    break;

  case 451: /* primary_expr: BIF_EDITFLT LPAREN arg_list RPAREN  */
#line 2331 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("EDITFLT", (yyvsp[-1].expr_list));
    }
#line 7201 "build/parser.cpp"
    break;

  case 452: /* primary_expr: BIF_UNSH LPAREN arg_list RPAREN  */
#line 2334 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("UNSH", (yyvsp[-1].expr_list));
    }
#line 7209 "build/parser.cpp"
    break;

  case 453: /* primary_expr: BIF_PARMNUM LPAREN ident RPAREN  */
#line 2337 "src/parser.y"
                                      {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::Identifier((yyvsp[-1].sval)));
        free((yyvsp[-1].sval));
        (yyval.expr) = make_bif("PARMNUM", args);
    }
#line 7220 "build/parser.cpp"
    break;

  case 454: /* primary_expr: BIF_GETENV LPAREN arg_list RPAREN  */
#line 2343 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("GETENV", (yyvsp[-1].expr_list));
    }
#line 7228 "build/parser.cpp"
    break;

  case 455: /* primary_expr: INDICATOR  */
#line 2346 "src/parser.y"
                {
        (yyval.expr) = new rpg::IndicatorExpr((yyvsp[0].ival));
    }
#line 7236 "build/parser.cpp"
    break;

  case 456: /* primary_expr: KW_ON  */
#line 2349 "src/parser.y"
            {
        (yyval.expr) = new rpg::IntLiteral(1);  // *ON → true
    }
#line 7244 "build/parser.cpp"
    break;

  case 457: /* primary_expr: KW_OFF  */
#line 2352 "src/parser.y"
             {
        (yyval.expr) = new rpg::IntLiteral(0);  // *OFF → false
    }
#line 7252 "build/parser.cpp"
    break;

  case 458: /* primary_expr: KW_NULL  */
#line 2355 "src/parser.y"
              {
        (yyval.expr) = new rpg::Identifier("nullptr");
    }
#line 7260 "build/parser.cpp"
    break;

  case 459: /* primary_expr: KW_OMIT  */
#line 2358 "src/parser.y"
              {
        (yyval.expr) = new rpg::Identifier("nullptr");
    }
#line 7268 "build/parser.cpp"
    break;

  case 460: /* primary_expr: KW_BLANKS  */
#line 2361 "src/parser.y"
                {
        (yyval.expr) = new rpg::Identifier("RPG_BLANKS");
    }
#line 7276 "build/parser.cpp"
    break;

  case 461: /* primary_expr: KW_ZEROS  */
#line 2364 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier("RPG_ZEROS");
    }
#line 7284 "build/parser.cpp"
    break;

  case 462: /* primary_expr: KW_HIVAL  */
#line 2367 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier("RPG_HIVAL");
    }
#line 7292 "build/parser.cpp"
    break;

  case 463: /* primary_expr: KW_LOVAL  */
#line 2370 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier("RPG_LOVAL");
    }
#line 7300 "build/parser.cpp"
    break;

  case 464: /* primary_expr: LPAREN expression RPAREN  */
#line 2373 "src/parser.y"
                               {
        (yyval.expr) = (yyvsp[-1].expr);
    }
#line 7308 "build/parser.cpp"
    break;

  case 465: /* call_args_opt: %empty  */
#line 2380 "src/parser.y"
                { (yyval.expr_list) = nullptr; }
#line 7314 "build/parser.cpp"
    break;

  case 466: /* call_args_opt: call_arg_list  */
#line 2381 "src/parser.y"
                    { (yyval.expr_list) = (yyvsp[0].expr_list); }
#line 7320 "build/parser.cpp"
    break;

  case 467: /* call_arg_list: expression  */
#line 2385 "src/parser.y"
               {
        (yyval.expr_list) = new std::vector<rpg::Expression*>();
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 7329 "build/parser.cpp"
    break;

  case 468: /* call_arg_list: call_arg_list COLON expression  */
#line 2389 "src/parser.y"
                                     {
        (yyval.expr_list) = (yyvsp[-2].expr_list);
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 7338 "build/parser.cpp"
    break;

  case 469: /* arg_list: expression  */
#line 2397 "src/parser.y"
               {
        (yyval.expr_list) = new std::vector<rpg::Expression*>();
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 7347 "build/parser.cpp"
    break;

  case 470: /* arg_list: arg_list COLON expression  */
#line 2401 "src/parser.y"
                                {
        (yyval.expr_list) = (yyvsp[-2].expr_list);
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 7356 "build/parser.cpp"
    break;


#line 7360 "build/parser.cpp"

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

#line 2407 "src/parser.y"


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
