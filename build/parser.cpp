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
  YYSYMBOL_BIF_GETENV = 191,               /* BIF_GETENV  */
  YYSYMBOL_BIF_XML = 192,                  /* BIF_XML  */
  YYSYMBOL_KW_ALL = 193,                   /* KW_ALL  */
  YYSYMBOL_KW_UNS = 194,                   /* KW_UNS  */
  YYSYMBOL_KW_FLOAT_TYPE = 195,            /* KW_FLOAT_TYPE  */
  YYSYMBOL_KW_BINDEC = 196,                /* KW_BINDEC  */
  YYSYMBOL_KW_UCS2 = 197,                  /* KW_UCS2  */
  YYSYMBOL_KW_GRAPH = 198,                 /* KW_GRAPH  */
  YYSYMBOL_KW_OBJECT = 199,                /* KW_OBJECT  */
  YYSYMBOL_KW_JAVA = 200,                  /* KW_JAVA  */
  YYSYMBOL_KW_OVERLAY = 201,               /* KW_OVERLAY  */
  YYSYMBOL_KW_POS = 202,                   /* KW_POS  */
  YYSYMBOL_KW_PREFIX = 203,                /* KW_PREFIX  */
  YYSYMBOL_KW_DATFMT = 204,                /* KW_DATFMT  */
  YYSYMBOL_KW_TIMFMT = 205,                /* KW_TIMFMT  */
  YYSYMBOL_KW_EXTNAME = 206,               /* KW_EXTNAME  */
  YYSYMBOL_KW_PSDS = 207,                  /* KW_PSDS  */
  YYSYMBOL_KW_SDS = 208,                   /* KW_SDS  */
  YYSYMBOL_KW_DTAARA = 209,                /* KW_DTAARA  */
  YYSYMBOL_KW_OUT = 210,                   /* KW_OUT  */
  YYSYMBOL_KW_UNLOCK = 211,                /* KW_UNLOCK  */
  YYSYMBOL_KW_RTNPARM = 212,               /* KW_RTNPARM  */
  YYSYMBOL_KW_OPDESC = 213,                /* KW_OPDESC  */
  YYSYMBOL_KW_ASCEND = 214,                /* KW_ASCEND  */
  YYSYMBOL_KW_DESCEND = 215,               /* KW_DESCEND  */
  YYSYMBOL_KW_NULLIND = 216,               /* KW_NULLIND  */
  YYSYMBOL_KW_VARSIZE = 217,               /* KW_VARSIZE  */
  YYSYMBOL_KW_STRING_OPT = 218,            /* KW_STRING_OPT  */
  YYSYMBOL_KW_TRIM_OPT = 219,              /* KW_TRIM_OPT  */
  YYSYMBOL_KW_DCL_ENUM = 220,              /* KW_DCL_ENUM  */
  YYSYMBOL_KW_END_ENUM = 221,              /* KW_END_ENUM  */
  YYSYMBOL_KW_BOOLEAN = 222,               /* KW_BOOLEAN  */
  YYSYMBOL_EXEC_SQL_TEXT = 223,            /* EXEC_SQL_TEXT  */
  YYSYMBOL_POWER = 224,                    /* POWER  */
  YYSYMBOL_KW_DIM_VAR = 225,               /* KW_DIM_VAR  */
  YYSYMBOL_KW_DIM_AUTO = 226,              /* KW_DIM_AUTO  */
  YYSYMBOL_KW_FOR_EACH = 227,              /* KW_FOR_EACH  */
  YYSYMBOL_KW_IN = 228,                    /* KW_IN  */
  YYSYMBOL_KW_XML_INTO = 229,              /* KW_XML_INTO  */
  YYSYMBOL_IDENTIFIER = 230,               /* IDENTIFIER  */
  YYSYMBOL_INTEGER_LITERAL = 231,          /* INTEGER_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 232,            /* FLOAT_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 233,           /* STRING_LITERAL  */
  YYSYMBOL_SEMICOLON = 234,                /* SEMICOLON  */
  YYSYMBOL_EQUALS = 235,                   /* EQUALS  */
  YYSYMBOL_LPAREN = 236,                   /* LPAREN  */
  YYSYMBOL_RPAREN = 237,                   /* RPAREN  */
  YYSYMBOL_COLON = 238,                    /* COLON  */
  YYSYMBOL_PLUS = 239,                     /* PLUS  */
  YYSYMBOL_MINUS = 240,                    /* MINUS  */
  YYSYMBOL_STAR = 241,                     /* STAR  */
  YYSYMBOL_SLASH = 242,                    /* SLASH  */
  YYSYMBOL_NE = 243,                       /* NE  */
  YYSYMBOL_LE = 244,                       /* LE  */
  YYSYMBOL_GE = 245,                       /* GE  */
  YYSYMBOL_LT = 246,                       /* LT  */
  YYSYMBOL_GT = 247,                       /* GT  */
  YYSYMBOL_YYACCEPT = 248,                 /* $accept  */
  YYSYMBOL_program = 249,                  /* program  */
  YYSYMBOL_statements_opt = 250,           /* statements_opt  */
  YYSYMBOL_statement_list = 251,           /* statement_list  */
  YYSYMBOL_statement = 252,                /* statement  */
  YYSYMBOL_dcl_f_stmt = 253,               /* dcl_f_stmt  */
  YYSYMBOL_dcl_s_stmt = 254,               /* dcl_s_stmt  */
  YYSYMBOL_dcl_s_keywords = 255,           /* dcl_s_keywords  */
  YYSYMBOL_dcl_c_stmt = 256,               /* dcl_c_stmt  */
  YYSYMBOL_eval_target = 257,              /* eval_target  */
  YYSYMBOL_eval_stmt = 258,                /* eval_stmt  */
  YYSYMBOL_eval_corr_stmt = 259,           /* eval_corr_stmt  */
  YYSYMBOL_xml_into_stmt = 260,            /* xml_into_stmt  */
  YYSYMBOL_in_da_stmt = 261,               /* in_da_stmt  */
  YYSYMBOL_out_da_stmt = 262,              /* out_da_stmt  */
  YYSYMBOL_unlock_da_stmt = 263,           /* unlock_da_stmt  */
  YYSYMBOL_evalr_stmt = 264,               /* evalr_stmt  */
  YYSYMBOL_callp_stmt = 265,               /* callp_stmt  */
  YYSYMBOL_leavesr_stmt = 266,             /* leavesr_stmt  */
  YYSYMBOL_dsply_stmt = 267,               /* dsply_stmt  */
  YYSYMBOL_inlr_stmt = 268,                /* inlr_stmt  */
  YYSYMBOL_return_stmt = 269,              /* return_stmt  */
  YYSYMBOL_expr_stmt = 270,                /* expr_stmt  */
  YYSYMBOL_dcl_pr_stmt = 271,              /* dcl_pr_stmt  */
  YYSYMBOL_dcl_proc_stmt = 272,            /* dcl_proc_stmt  */
  YYSYMBOL_proc_export = 273,              /* proc_export  */
  YYSYMBOL_pi_return_type = 274,           /* pi_return_type  */
  YYSYMBOL_pi_params = 275,                /* pi_params  */
  YYSYMBOL_pi_param = 276,                 /* pi_param  */
  YYSYMBOL_pr_params = 277,                /* pr_params  */
  YYSYMBOL_pr_param = 278,                 /* pr_param  */
  YYSYMBOL_monitor_stmt = 279,             /* monitor_stmt  */
  YYSYMBOL_begsr_stmt = 280,               /* begsr_stmt  */
  YYSYMBOL_exsr_stmt = 281,                /* exsr_stmt  */
  YYSYMBOL_sorta_stmt = 282,               /* sorta_stmt  */
  YYSYMBOL_reset_stmt = 283,               /* reset_stmt  */
  YYSYMBOL_clear_stmt = 284,               /* clear_stmt  */
  YYSYMBOL_dealloc_stmt = 285,             /* dealloc_stmt  */
  YYSYMBOL_test_stmt = 286,                /* test_stmt  */
  YYSYMBOL_exec_sql_stmt = 287,            /* exec_sql_stmt  */
  YYSYMBOL_dcl_enum_stmt = 288,            /* dcl_enum_stmt  */
  YYSYMBOL_enum_constants = 289,           /* enum_constants  */
  YYSYMBOL_enum_constant = 290,            /* enum_constant  */
  YYSYMBOL_dcl_ds_stmt = 291,              /* dcl_ds_stmt  */
  YYSYMBOL_ds_fields = 292,                /* ds_fields  */
  YYSYMBOL_psds_kw = 293,                  /* psds_kw  */
  YYSYMBOL_ds_field = 294,                 /* ds_field  */
  YYSYMBOL_if_stmt = 295,                  /* if_stmt  */
  YYSYMBOL_elseif_clauses = 296,           /* elseif_clauses  */
  YYSYMBOL_elseif_clause = 297,            /* elseif_clause  */
  YYSYMBOL_else_clause = 298,              /* else_clause  */
  YYSYMBOL_dow_stmt = 299,                 /* dow_stmt  */
  YYSYMBOL_dou_stmt = 300,                 /* dou_stmt  */
  YYSYMBOL_for_stmt = 301,                 /* for_stmt  */
  YYSYMBOL_for_each_stmt = 302,            /* for_each_stmt  */
  YYSYMBOL_select_stmt = 303,              /* select_stmt  */
  YYSYMBOL_when_clauses = 304,             /* when_clauses  */
  YYSYMBOL_when_clause = 305,              /* when_clause  */
  YYSYMBOL_other_clause = 306,             /* other_clause  */
  YYSYMBOL_iter_stmt = 307,                /* iter_stmt  */
  YYSYMBOL_leave_stmt = 308,               /* leave_stmt  */
  YYSYMBOL_expression = 309,               /* expression  */
  YYSYMBOL_or_expr = 310,                  /* or_expr  */
  YYSYMBOL_and_expr = 311,                 /* and_expr  */
  YYSYMBOL_not_expr = 312,                 /* not_expr  */
  YYSYMBOL_comparison_expr = 313,          /* comparison_expr  */
  YYSYMBOL_additive_expr = 314,            /* additive_expr  */
  YYSYMBOL_multiplicative_expr = 315,      /* multiplicative_expr  */
  YYSYMBOL_power_expr = 316,               /* power_expr  */
  YYSYMBOL_unary_expr = 317,               /* unary_expr  */
  YYSYMBOL_postfix_expr = 318,             /* postfix_expr  */
  YYSYMBOL_ident = 319,                    /* ident  */
  YYSYMBOL_primary_expr = 320,             /* primary_expr  */
  YYSYMBOL_call_args_opt = 321,            /* call_args_opt  */
  YYSYMBOL_call_arg_list = 322,            /* call_arg_list  */
  YYSYMBOL_arg_list = 323                  /* arg_list  */
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
#define YYLAST   5122

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  248
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  76
/* YYNRULES -- Number of rules.  */
#define YYNRULES  467
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1526

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   502


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
     245,   246,   247
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   196,   196,   199,   204,   206,   211,   220,   223,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   256,   257,   258,   259,   260,   261,   262,
     263,   264,   265,   266,   267,   268,   269,   274,   278,   282,
     286,   294,   299,   304,   309,   314,   319,   324,   329,   334,
     339,   344,   349,   355,   361,   367,   371,   375,   379,   383,
     387,   391,   395,   399,   403,   407,   413,   419,   425,   431,
     438,   443,   449,   454,   459,   464,   469,   474,   479,   484,
     489,   494,   499,   504,   509,   514,   519,   524,   532,   533,
     534,   535,   536,   541,   548,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,   563,   564,   565,   566,
     569,   575,   579,   585,   591,   597,   606,   614,   620,   629,
     636,   643,   650,   659,   665,   671,   677,   683,   686,   693,
     704,   721,   741,   756,   780,   805,   832,   862,   863,   868,
     869,   870,   871,   872,   877,   880,   888,   892,   896,   900,
     904,   908,   912,   916,   921,   925,   929,   933,   937,   941,
     945,   949,   953,   959,   964,   969,   974,   980,   985,   990,
     995,  1001,  1006,  1011,  1020,  1023,  1031,  1035,  1039,  1043,
    1047,  1051,  1055,  1059,  1064,  1068,  1072,  1076,  1080,  1084,
    1088,  1092,  1096,  1102,  1107,  1112,  1117,  1123,  1128,  1133,
    1138,  1144,  1149,  1154,  1164,  1175,  1185,  1193,  1201,  1208,
    1216,  1224,  1235,  1245,  1253,  1264,  1267,  1275,  1283,  1298,
    1307,  1316,  1326,  1336,  1347,  1358,  1369,  1380,  1388,  1397,
    1407,  1418,  1429,  1439,  1449,  1459,  1469,  1479,  1482,  1490,
    1491,  1495,  1499,  1503,  1507,  1512,  1516,  1520,  1524,  1529,
    1535,  1541,  1548,  1555,  1562,  1568,  1576,  1582,  1593,  1616,
    1617,  1625,  1634,  1635,  1641,  1650,  1659,  1669,  1679,  1689,
    1702,  1712,  1731,  1735,  1742,  1751,  1752,  1758,  1762,  1768,
    1772,  1773,  1781,  1782,  1790,  1791,  1797,  1798,  1803,  1808,
    1813,  1818,  1823,  1828,  1836,  1837,  1842,  1850,  1851,  1856,
    1864,  1865,  1873,  1874,  1882,  1883,  1890,  1891,  1892,  1893,
    1894,  1895,  1896,  1897,  1898,  1899,  1900,  1901,  1902,  1903,
    1904,  1905,  1909,  1913,  1914,  1915,  1916,  1917,  1918,  1919,
    1920,  1921,  1922,  1923,  1924,  1925,  1926,  1927,  1930,  1933,
    1937,  1941,  1944,  1947,  1950,  1953,  1956,  1959,  1962,  1965,
    1968,  1971,  1974,  1977,  1981,  1984,  1987,  1990,  1993,  1996,
    1999,  2002,  2005,  2011,  2017,  2023,  2029,  2035,  2041,  2044,
    2047,  2050,  2053,  2057,  2061,  2064,  2067,  2070,  2073,  2076,
    2079,  2083,  2086,  2090,  2093,  2097,  2104,  2111,  2118,  2123,
    2128,  2133,  2137,  2141,  2144,  2147,  2150,  2153,  2156,  2159,
    2162,  2165,  2168,  2171,  2174,  2177,  2180,  2183,  2186,  2189,
    2192,  2195,  2198,  2201,  2204,  2207,  2210,  2213,  2216,  2219,
    2222,  2227,  2232,  2237,  2242,  2248,  2252,  2256,  2263,  2270,
    2277,  2283,  2289,  2295,  2298,  2301,  2304,  2307,  2310,  2313,
    2316,  2322,  2325,  2328,  2331,  2334,  2337,  2340,  2343,  2346,
    2349,  2352,  2359,  2360,  2364,  2368,  2376,  2380
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
  "BIF_GETENV", "BIF_XML", "KW_ALL", "KW_UNS", "KW_FLOAT_TYPE",
  "KW_BINDEC", "KW_UCS2", "KW_GRAPH", "KW_OBJECT", "KW_JAVA", "KW_OVERLAY",
  "KW_POS", "KW_PREFIX", "KW_DATFMT", "KW_TIMFMT", "KW_EXTNAME", "KW_PSDS",
  "KW_SDS", "KW_DTAARA", "KW_OUT", "KW_UNLOCK", "KW_RTNPARM", "KW_OPDESC",
  "KW_ASCEND", "KW_DESCEND", "KW_NULLIND", "KW_VARSIZE", "KW_STRING_OPT",
  "KW_TRIM_OPT", "KW_DCL_ENUM", "KW_END_ENUM", "KW_BOOLEAN",
  "EXEC_SQL_TEXT", "POWER", "KW_DIM_VAR", "KW_DIM_AUTO", "KW_FOR_EACH",
  "KW_IN", "KW_XML_INTO", "IDENTIFIER", "INTEGER_LITERAL", "FLOAT_LITERAL",
  "STRING_LITERAL", "SEMICOLON", "EQUALS", "LPAREN", "RPAREN", "COLON",
  "PLUS", "MINUS", "STAR", "SLASH", "NE", "LE", "GE", "LT", "GT",
  "$accept", "program", "statements_opt", "statement_list", "statement",
  "dcl_f_stmt", "dcl_s_stmt", "dcl_s_keywords", "dcl_c_stmt",
  "eval_target", "eval_stmt", "eval_corr_stmt", "xml_into_stmt",
  "in_da_stmt", "out_da_stmt", "unlock_da_stmt", "evalr_stmt",
  "callp_stmt", "leavesr_stmt", "dsply_stmt", "inlr_stmt", "return_stmt",
  "expr_stmt", "dcl_pr_stmt", "dcl_proc_stmt", "proc_export",
  "pi_return_type", "pi_params", "pi_param", "pr_params", "pr_param",
  "monitor_stmt", "begsr_stmt", "exsr_stmt", "sorta_stmt", "reset_stmt",
  "clear_stmt", "dealloc_stmt", "test_stmt", "exec_sql_stmt",
  "dcl_enum_stmt", "enum_constants", "enum_constant", "dcl_ds_stmt",
  "ds_fields", "psds_kw", "ds_field", "if_stmt", "elseif_clauses",
  "elseif_clause", "else_clause", "dow_stmt", "dou_stmt", "for_stmt",
  "for_each_stmt", "select_stmt", "when_clauses", "when_clause",
  "other_clause", "iter_stmt", "leave_stmt", "expression", "or_expr",
  "and_expr", "not_expr", "comparison_expr", "additive_expr",
  "multiplicative_expr", "power_expr", "unary_expr", "postfix_expr",
  "ident", "primary_expr", "call_args_opt", "call_arg_list", "arg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-826)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-287)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     109,  -826,   127,    32,   473,  -826,  -113,   -87,   217,   -29,
    4422,    74,   217,    74,  4422,   -57,   217,    -8,  -826,  3665,
      22,  4422,  4422,  4422,   217,   -25,    66,    98,   100,   108,
     217,   217,   217,   217,  -826,   128,   157,   173,   140,  -826,
    -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,   176,   198,
    -826,  -826,  -826,  -826,  -826,   213,  -826,   217,   216,   217,
     -47,  -826,  -826,  -826,  -826,   110,  -826,  -826,  -826,  -826,
    -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,
    -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,
    -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,
    -826,   513,  -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,
    -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,   121,  4422,
    -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,  4611,
     177,   222,   226,   228,   230,   232,   236,   239,   261,   266,
     274,   294,   301,   303,   306,   315,   317,   319,   326,   330,
     359,   387,   429,   436,   446,   456,   463,   500,   544,   546,
     547,   551,   552,   553,   554,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   565,   567,   568,   569,   570,   571,
     574,   581,   584,   585,   586,   587,   588,   589,   590,   591,
     592,   593,   594,   597,   598,   599,   600,   601,   608,   610,
     611,   612,   613,   615,   616,   621,   622,   624,   626,   631,
     632,   633,   635,   636,   637,   639,   364,  -826,  -826,  -826,
    -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,
    -826,   640,  -826,  -826,  -826,  4422,  4800,   644,   526,   538,
    -826,   207,    43,  -142,  -826,   655,   645,  -826,    15,   573,
     646,   647,   649,  -826,   650,   217,  -826,   651,   738,   652,
     653,   654,   656,   809,  -826,  -826,  -826,   658,   659,   660,
     661,   662,   843,   377,   105,  4422,   664,   666,    47,   674,
     669,   698,   675,  4422,  4422,    -5,   670,   672,   671,   673,
     676,   677,   678,  -157,  -143,   681,   682,   683,   684,   685,
     686,   687,   688,   689,   691,   694,   695,   207,  4422,  4422,
    4422,  4422,  4422,  4422,  4422,  4422,  4422,  4422,  4422,  4422,
     693,   696,  4422,  4422,  4422,  4422,  4422,   697,   699,   700,
    4422,  4422,  4422,  3855,  4044,  4233,  4422,  4422,  4422,  4422,
    4422,  4422,  4422,  4422,  4422,  4422,  4422,  4422,  4422,  4422,
    4422,  4422,  4422,  4422,  4422,  4422,  4422,  4422,  4422,  4422,
    4422,  4422,  4422,  4422,  4422,  4422,  4422,  4422,  4422,  4422,
    4422,  4422,  4422,  4422,  4422,  4422,  4422,  4422,  4422,  4422,
    4422,   680,   701,   217,   217,  4422,  4422,  4422,  4422,  4422,
    4422,  4422,   217,  4422,  -826,  4422,   702,   645,  -826,  4422,
    4422,  4611,  4611,  4611,  4611,  4611,  4611,  4611,  4611,  4611,
    4611,  4611,  4611,   705,  4422,  4422,   217,  4422,  -826,  -826,
     703,  -826,   707,  -826,  -826,  -826,  4422,  4422,    79,  -826,
    1588,  -826,  -826,  -826,  -826,  -826,  -826,   708,   709,   710,
     711,   712,   714,    -3,    88,   716,   718,   720,  -826,  -826,
    -826,    69,  -826,    29,  -826,  -826,   723,   713,  4422,  -826,
     722,  -826,   724,   726,   706,   731,   733,  -826,  -826,  -826,
     735,   736,   739,   740,   741,   737,  -826,   743,  -826,  -826,
    -826,  -826,   721,   745,   746,   749,   756,   757,   732,  -826,
    -826,   146,   199,   218,   262,   323,   327,   331,   347,   349,
     351,   354,   356,  -826,  -826,   361,   363,   365,   367,   369,
    -826,  -826,  -826,   371,   373,   375,  -826,   378,  -826,   380,
    -826,   382,   751,   727,   760,   761,   384,   389,   391,   397,
     399,   401,   403,   763,   405,   407,   409,   411,   413,   415,
     417,   419,   421,   423,   425,   432,   443,   453,   457,   460,
     467,   469,   471,   475,   477,   479,   481,   483,   485,   487,
     489,   491,   493,   762,   765,   767,   768,   769,  -826,   774,
     775,   495,   497,   503,   505,   507,   509,   511,   776,   514,
    -826,   777,  -826,   538,  -826,    70,    70,    70,    70,    70,
      70,    70,  -142,  -142,  -826,  -826,  -826,  -826,   724,   782,
     783,   787,   217,  -826,   780,  1808,  1875,   149,   788,   789,
    -826,   835,   790,  -826,  2095,   819,   794,   795,   796,   797,
     729,   793,  -826,   798,   799,  -826,   802,   183,   801,   807,
      71,   804,   341,  -826,  4422,   713,   476,  -125,  -826,   805,
    4422,   813,   806,  4422,  -826,   690,   814,   817,   818,   820,
     821,   812,   826,   823,   824,   825,   827,   830,   831,   832,
    -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,
    -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,
    -826,  -826,  -826,  4422,  -826,  -826,  -826,  -826,  -826,  -826,
    -826,  -826,  -826,  -826,   549,  -826,  -826,  -826,  -826,  -826,
    -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,
    -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,
    -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,
    -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,
    -826,  -826,  -826,  -826,   829,   572,   837,   839,  4422,  4422,
    -826,  -826,   840,  -826,   841,    28,   844,   845,   846,   842,
     854,   810,    24,   234,   848,    75,  -826,   856,   858,   855,
     864,   516,   868,   873,   348,  -826,  -826,    77,  -826,  -120,
    -826,  4422,   871,  -826,  -826,   518,   876,  -826,  -826,   869,
     115,    84,   124,   838,   878,   875,   877,   879,   394,   394,
     394,   394,   394,   882,   872,   880,   881,   883,   884,   885,
     886,  -826,  4422,   890,  -826,   892,  -826,  -826,   -35,   -34,
    1014,  2162,  -826,  2382,  -826,   474,   891,  -826,  -826,  -826,
     888,   893,   895,   894,   899,   360,  -826,   896,   897,   900,
     520,   902,   167,   907,   908,   860,    -2,   906,   910,  -826,
     368,   909,   911,   912,   913,   914,   194,   917,   918,   919,
    -826,  2449,   920,  4422,  -826,   791,   889,   921,  -826,  -826,
     922,  1027,  -826,   923,   924,   927,   926,  -826,   928,   929,
     932,  1086,   931,   933,  1100,   934,   935,   938,   905,   936,
     940,   941,  -826,   942,   943,   944,   945,   946,   947,   555,
    -826,  -826,  -826,  -826,  -826,  -826,   948,  -826,   949,  4422,
    -826,  4422,  -826,   951,   952,  -826,   950,  -826,   954,  -826,
     504,   953,   955,   956,   957,   958,   915,   925,   961,   962,
     937,  -826,   963,   964,   966,   965,   968,  -826,  -826,   969,
     971,   974,   975,   977,   978,   959,   967,   990,   991,   903,
     989,  -826,  -826,  -826,   997,  -826,   995,   996,  1000,  4422,
     970,  1009,  1015,  1017,  -826,  4422,   245,  1018,  -826,  1013,
    4422,  1020,  1016,   288,  1021,  -826,   156,   394,  -826,  -826,
    -826,  -826,  -826,  -826,  -826,  1019,  1022,  1023,  1024,  1025,
    1026,  1034,  -826,  2669,  -826,  1030,  2736,  1040,  2956,  -826,
    -826,    54,  -826,    68,  -826,  1039,  1041,  1042,  1043,  1045,
    1049,  1050,  1051,  1028,  1046,  1047,  -826,  -826,  1052,  -826,
    1044,  1056,  -826,  1057,   196,  1064,  1059,  1060,  1067,  1069,
    1071,  1066,  1074,  1075,  1076,  1079,  -826,  -826,  1053,  1087,
    4422,  1085,  1088,  4422,  1089,  1090,  1092,  1103,  1104,  1093,
    1106,  4422,  1107,  1108,  4422,  1109,  1110,  1112,  1113,  1114,
    1118,  1119,  1120,  1123,  1124,  -826,  -826,  -826,  -826,  -826,
    -826,  -826,  1234,  -826,  1126,  -826,  1127,    55,  1128,  1116,
     388,  -826,  1131,    72,  1136,  1137,  1138,  1139,  1135,  1141,
    1142,  1143,  1146,  1140,  1154,   208,   227,  1155,  1156,  1159,
     233,  1157,  1162,  1163,  1164,  1165,  1166,  1161,  1167,   162,
    1171,   193,  1169,  1172,  -826,  -826,  1170,  1174,  1175,  1173,
    -111,  1177,  1178,  1182,  1183,  1181,  1185,  1179,  1186,  1187,
    1180,  1191,  1192,   132,  1190,  1189,  4422,  1195,  1197,  -826,
    -826,  3023,  -826,  3243,  -826,  1196,  -826,   515,  1198,  1205,
    1206,  1207,  1215,  -826,  1199,  1194,  1216,  1218,  1214,   -41,
     -40,   -36,  1225,  1224,  -826,  -826,  1226,  1231,  -826,  -826,
    -826,  1232,  1233,  -826,  -826,  1235,  1236,  1237,  1228,  1238,
    1239,  1240,  -826,  -826,  1241,  1242,  -826,  1243,  -826,  1245,
    -826,  -826,  1247,  1248,  1249,  -826,  -826,  -826,  1250,  1251,
    -826,  -826,  1252,  -826,  -826,  1255,  1253,  1254,  1258,  1259,
    -826,  -826,  4422,  1257,  1260,  1261,  1266,  1267,  -826,  1301,
    1272,  1273,  1274,  1282,  1288,  1289,  1292,  1302,  1244,  -826,
     -53,   -52,   -44,  1303,  1296,   -26,  -826,  1299,   -14,  -826,
    1300,   -13,  -826,  1304,  -826,   237,   250,  -826,  -826,   251,
     252,   253,  -826,  -826,   254,  -826,  -826,  -826,  1305,  -826,
    1307,  1308,  1310,  1312,  -141,  -826,  -826,  -826,  -826,  1311,
    1313,  -826,  -826,  1314,  1315,  -826,  -826,  1309,  1316,  1317,
    1327,  -826,  -826,  1521,  1328,  1329,  1333,  1334,  1335,  1336,
    1331,  1332,  1337,  1230,  1338,  1342,  -826,  1343,  -826,  1344,
    -826,  1345,   715,  1349,  -826,   717,  1351,  -826,   719,  1352,
    -826,   -24,  1346,  1347,  1356,  1364,  1365,  1367,  1369,   528,
    1371,   530,  1372,  1374,  -826,  -826,  -826,  -826,  -826,  1379,
    -826,  -826,  -826,  1380,  1382,  -826,  -826,  1388,  1391,  1392,
    1246,   -23,   -22,   -20,  1339,  1383,  -826,  -826,  -826,   -42,
    1306,  1393,  1210,  1394,  1396,  1211,  1397,  1399,  1212,  1395,
     -12,  -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,  1400,
    1340,  1403,  1407,  1411,  1409,  1413,  -826,  -826,  -826,  3310,
     -39,   -27,   -21,  1414,  1412,     5,  -826,  1416,     6,  -826,
    1418,     7,  -826,  1410,  -826,  1415,  -826,  1160,  1421,  1419,
    1278,  1423,  1422,  1428,  1426,  1424,  1440,  1430,  -826,  -826,
    1431,  -826,  -826,  1433,  -826,  1438,  3530,  1442,  1443,  -826,
    1445,  -826,  1446,  -826,  1444,   725,  1447,  -826,   728,  1448,
    -826,   730,  1450,  -826,   -15,  -826,  1451,  -826,  1453,  1452,
    -826,  1456,  1454,  -826,  1458,  1457,  1213,  1459,  1461,  1462,
    1463,  -826,  -826,  -826,  -826,   -16,  1460,  1464,  1494,  1465,
    1467,  1655,  1468,  1470,  1656,  1466,    16,  -826,  1474,  -826,
    1475,  -826,  1476,  -826,  1477,  1480,  -826,  -826,  -826,  -826,
    1478,  -826,  1668,  1484,  1483,  1669,  1487,  1491,  1684,  1496,
    1501,  1694,  1504,  -826,  -826,  -826,  -826,  -826,  1508,  -826,
    1506,  -826,  1511,  1509,  -826,  1513,  1515,  -826,  1519,  1517,
    1711,  -826,  1522,  -826,  1523,  -826,  1524,  -826,  1525,  1526,
    -826,  -826,  -826,  -826,  1527,  -826
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       4,     4,     0,     0,     0,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   119,     0,     0,     0,     0,   108,
     109,   110,   106,   105,   107,   116,   117,   118,     0,     0,
     113,   114,   111,   112,   115,     0,   222,     0,     0,     0,
     104,     5,     9,    10,    11,     0,    12,    13,    41,    42,
      43,    44,    35,    36,    37,    14,    15,    16,    45,    26,
      25,    29,    30,    31,    34,    32,    33,    38,    39,    40,
      28,    27,    17,    18,    19,    20,    21,    22,    23,    24,
      46,     0,   317,   318,   319,   329,   330,   331,   326,   327,
     328,   323,   324,   320,   321,   325,   322,   316,     0,     0,
     455,   456,   453,   457,   458,   459,   460,   454,   452,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   436,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   333,   334,   335,
     342,   343,   344,   341,   345,   346,   338,   339,   336,   337,
     340,   332,   347,   348,   349,     0,     0,     0,   289,   290,
     292,   294,   296,   304,   307,   310,   312,   314,   104,     0,
       0,     0,     0,   134,     0,     0,   138,     0,     0,     0,
       0,     0,     0,     0,   287,   288,     7,     0,     0,     0,
       0,     0,   147,   149,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   462,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   295,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   440,   462,     0,   313,   135,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   133,   220,
       0,   137,     0,     7,     7,     7,     0,     0,   285,   282,
       0,     7,   216,   218,   219,   217,   148,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   249,   250,
     247,     0,   466,     0,   130,   131,     0,     0,     0,   129,
       0,   120,   464,     0,   463,     0,     0,    47,    48,    49,
       0,     0,     0,     0,     0,     0,    67,     0,    68,    69,
      65,    70,     0,     0,     0,     0,     0,     0,     0,    66,
     103,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   401,   402,     0,     0,     0,     0,     0,
     363,   382,   383,     0,     0,     0,   390,     0,   392,     0,
     394,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   435,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     464,     0,   461,   291,   293,   297,   298,   301,   302,   299,
     300,   303,   305,   306,   308,   309,   311,   315,     0,     0,
       0,     0,     0,   136,     0,     0,     0,     0,     0,     0,
     283,     0,     0,     8,     0,     0,     0,     0,     0,     0,
       0,     0,   184,     0,     0,   247,     0,     0,     0,     0,
       0,     0,   246,   123,     0,     0,     0,     0,   225,     0,
       0,   121,     0,     0,   124,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   386,   387,   388,   384,   385,   380,   381,   364,
     389,   391,   393,     0,   398,   399,   400,   365,   366,   367,
     368,   369,   370,   371,     0,   378,   379,   403,   404,   405,
     416,   410,   406,   407,   408,   409,   411,   412,   413,   414,
     415,   417,   418,   419,   420,   421,   422,   423,   424,   425,
     426,   427,   428,   429,   430,   431,   432,   433,   434,   441,
     442,   443,   444,   445,   446,   447,   448,   449,   450,   451,
     350,   125,   126,   132,     0,   272,     0,     0,     0,     0,
       7,     7,     0,     7,     0,   149,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   247,     0,     0,     0,
       0,     0,     0,     0,     0,   248,   247,     0,   467,     0,
     227,     0,     0,   226,     7,     0,     0,   139,   465,     0,
      98,    98,    98,     0,     0,     0,     0,     0,    98,    98,
      98,    98,    98,     0,     0,     0,     0,     0,     0,     0,
       0,   221,     0,     0,   270,     0,   274,   275,     0,     0,
       0,     0,   281,     0,   215,   149,     0,   151,   152,   150,
       0,     0,     0,     0,     0,     0,   185,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   230,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     224,     0,     0,     0,   122,     0,     0,     0,    99,   100,
       0,   101,   102,     0,     0,     0,     0,   101,     0,     0,
       0,     0,     0,     0,   101,     0,     0,     0,     0,     0,
       0,     0,    79,     0,     0,     0,     0,     0,     0,     0,
     374,   373,   372,   375,   376,   377,     0,     7,     0,     0,
       7,     0,     7,     0,     0,   154,     0,   184,     0,   140,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   229,     0,     0,     0,     0,     0,   237,   247,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   245,   223,   228,     0,   128,     0,     0,     0,     0,
       0,     0,     0,     0,    51,     0,     0,     0,    52,     0,
       0,     0,     0,     0,     0,    53,    98,    98,    92,    93,
      80,    81,    82,    83,    84,     0,     0,     0,     0,     0,
       0,     0,     7,     0,   268,     0,     0,     0,     0,   214,
     154,     0,   153,     0,   184,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   247,   247,     0,   244,
       0,     0,   247,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   243,   280,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    85,   395,   396,   397,   437,
     438,   439,     0,     7,     0,     7,     0,     0,     0,     0,
       0,   155,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   127,    50,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    54,
      55,     0,   276,     0,   278,     0,     7,     0,     0,     0,
       0,     0,     0,   142,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   247,   247,     0,     0,   247,   247,
     247,     0,     0,   242,   247,     0,     0,     0,     0,     0,
       0,     0,   252,   253,     0,     0,   251,     0,   266,     0,
      60,    87,     0,     0,     0,    72,    94,    62,     0,     0,
      73,    95,     0,    59,    86,     0,     0,     0,     0,     0,
      71,    96,     0,     0,     0,     0,     0,     0,     7,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   141,
       0,     0,     0,     0,     0,     0,   188,     0,     0,   190,
       0,     0,   186,     0,   202,     0,     0,   232,   239,     0,
       0,     0,   231,   238,     0,   256,   257,   255,     0,   267,
       0,     0,     0,     0,     0,    57,    64,    90,    91,     0,
       0,    56,    63,     0,     0,    88,    89,     0,     0,     0,
       0,   277,   279,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   196,     0,   198,     0,
     194,     0,     0,     0,   189,     0,     0,   191,     0,     0,
     187,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   254,    77,    78,    75,    76,     0,
      61,    74,    97,     0,     0,     7,   143,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   197,   199,   195,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   192,   234,   236,   241,   233,   235,   240,   258,     0,
       0,     0,     0,     0,     0,     0,    58,     7,   144,     0,
       0,     0,     0,     0,     0,     0,   158,     0,     0,   160,
       0,     0,   156,     0,   172,     0,   200,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   193,   262,
       0,   259,   264,     0,   260,     0,     0,     0,     0,   166,
       0,   168,     0,   164,     0,     0,     0,   159,     0,     0,
     161,     0,     0,   157,     0,   201,     0,   208,     0,     0,
     209,     0,     0,   207,     0,     0,     0,     0,     0,     0,
       0,   145,   167,   169,   165,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   162,     0,   204,
       0,   205,     0,   203,     0,     0,   263,   265,   261,   146,
       0,   170,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   163,   212,   213,   211,   210,     0,   171,
       0,   178,     0,     0,   179,     0,     0,   177,     0,     0,
       0,   206,     0,   174,     0,   175,     0,   173,     0,     0,
     182,   183,   181,   180,     0,   176
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -826,  -826,  1759,  -409,   773,  -826,  -826,  -713,  -826,   310,
    -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,
    -826,  -826,  -826,  -826,  -826,  -826,  -572,   181,  -826,  -825,
    -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,  -826,
    -826,  1129,  -592,  -826,  -624,  1318,  -826,  -826,  -826,  -826,
    -826,  -826,  -826,  -826,  -826,  -826,  -826,  1341,  -826,  -826,
    -826,   -10,  -826,  1366,   973,  1637,    89,   370,   122,  -826,
    1531,    -6,  -826,  1373,  -826,  4729
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,   430,   613,    62,    63,   875,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,   437,   443,  1001,  1081,   762,
     836,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,   637,   638,    91,   630,   451,   775,    92,   745,   814,
     815,    93,    94,    95,    96,    97,   428,   429,   611,    98,
      99,   452,   238,   239,   240,   241,   242,   243,   244,   245,
     246,   118,   247,   463,   464,   453
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     237,   765,  1234,  1237,   252,   466,   250,  1240,   777,   257,
     254,   259,   260,   261,   604,   605,   606,  1303,   262,  1359,
    1384,  1387,   614,  1390,   268,   269,   270,   271,  1465,  1306,
    1309,  1407,    -3,     6,   909,   911,     7,     8,     9,   438,
     439,   440,   441,  1295,  1297,   783,   621,   475,  1426,  1429,
    1432,   279,  1299,   281,  1395,  1235,  1238,  1418,   282,  1492,
    1241,  1323,   477,    10,    11,    12,    13,    14,    15,  1420,
      16,    17,  1360,  1385,  1388,  1422,  1391,   476,   880,   887,
    1480,  1466,    18,    19,    20,   893,   894,   895,   896,   897,
      21,   478,  1003,  1324,    22,    23,   782,    24,   936,   410,
     411,   858,    25,  1193,  1194,   636,    26,    27,    28,   306,
     636,    29,     1,    30,   876,    31,    32,    33,    34,   833,
     282,   100,    35,  1195,   868,   869,    36,     5,   834,    37,
     877,   872,   288,   289,   290,   291,   292,   293,   294,   295,
     296,   297,   842,   101,   866,   867,   456,  1078,  1145,    38,
     427,   609,   856,   881,   882,   868,   869,   870,  1079,  1079,
      34,   871,   872,  1082,   868,   869,   883,  1154,   631,   772,
     884,   872,   834,   841,   773,   857,   834,   253,   773,  1083,
     773,  1296,  1298,   826,   878,  1059,  1060,   783,   623,   283,
    1300,    38,  1396,  1236,  1239,  1419,   868,   869,  1242,   910,
     912,   119,   877,   872,   444,   445,   446,  1421,  1304,   263,
    1361,  1386,  1389,  1423,  1392,   873,   748,   749,  1481,  1467,
    1307,  1310,  1408,   298,   885,   396,    39,    40,   255,   467,
      41,   622,   937,    42,    43,    44,    45,    46,    47,  1427,
    1430,  1433,    48,    49,    50,    51,    52,    53,    54,   420,
    1493,   414,    55,   914,   835,    56,  1061,   258,   825,    57,
      58,    59,    60,  1063,  1064,   932,   633,   634,    39,    40,
     773,   407,    41,   462,   465,    42,    43,    44,    45,    46,
      47,   457,   408,   409,  1080,  1080,    50,    51,    52,    53,
      54,   624,   950,   879,  1102,   448,   449,   773,   835,   773,
     264,   774,   835,   632,   248,   774,  1166,   774,   447,   408,
     409,   773,   448,   449,  1024,   299,   300,   301,   302,   303,
     304,   249,   625,   251,   874,  1167,   522,   523,   524,   525,
     773,  1171,   265,   886,   266,  1312,   773,   533,   267,   450,
     773,   820,   821,   305,   823,   284,  1208,  1209,  1313,  1314,
    1315,  1316,  1317,   773,   773,   773,   773,   773,   272,   851,
     852,   853,   854,  1180,  1181,  1062,  1210,   563,   564,   565,
     566,   921,   922,   923,   924,   861,   275,   569,   570,   940,
     941,   942,   943,   660,   634,   580,   578,   273,   438,   439,
     440,   441,  1095,  1096,  1184,  1185,  1182,   774,  1100,  1148,
    1149,  1150,  1151,   274,   598,   599,   276,   601,   767,   768,
     600,   102,   103,   308,   769,   104,   607,   608,   105,   106,
     107,   108,   109,   110,   774,   442,   774,  1186,   277,   111,
     112,   113,   114,   115,   868,   869,   661,   634,   774,  -247,
     877,   872,   401,   278,  -247,   116,   280,   117,   639,   855,
     402,   403,   404,   405,   406,   662,   634,   774,   309,   837,
     838,   925,   310,   774,   311,   839,   312,   774,   313,   944,
    1047,  1048,   314,    -2,     6,   315,  1049,     7,     8,     9,
     774,   774,   774,   774,   774,   438,   439,   440,   441,  1152,
     585,   586,   587,   588,   589,   590,   591,   316,   993,   663,
     634,   996,   317,   998,    10,    11,    12,    13,    14,    15,
     318,    16,    17,  1055,  1056,  1005,  1006,  1007,  1008,  1057,
     285,   286,   287,    18,    19,    20,  1220,  1221,  1222,  1223,
     319,    21,   594,   595,   596,    22,    23,   320,    24,   321,
    1245,  1246,   322,    25,  1249,  1250,  1251,    26,    27,    28,
    1254,   323,    29,   324,    30,   325,    31,    32,    33,    34,
     664,   634,   326,    35,   665,   634,   327,    36,   666,   634,
      37,   805,   806,   807,   808,   809,   810,   986,   987,   988,
     989,   990,   991,  1072,   667,   634,   668,   634,   669,   634,
      38,   670,   634,   671,   634,   328,   744,   394,   672,   634,
     673,   634,   674,   634,   675,   634,   676,   634,   677,   634,
     678,   634,   679,   634,   399,   680,   634,   681,   634,   682,
     634,   687,   634,   329,   778,   400,   688,   634,   689,   634,
     785,   812,   813,   788,   690,   634,   691,   634,   692,   634,
     693,   634,   695,   634,   696,   634,   697,   634,   698,   634,
     699,   634,   700,   634,   701,   634,   702,   634,   703,   634,
     704,   634,   705,   634,  1141,   330,  1143,    39,    40,   706,
     634,    41,   331,   804,    42,    43,    44,    45,    46,    47,
     707,   634,   332,    48,    49,    50,    51,    52,    53,    54,
     708,   634,   333,    55,   709,   634,    56,   710,   634,   334,
      57,    58,    59,    60,   711,   634,   712,   634,   713,   634,
     780,   781,   714,   634,   715,   634,   716,   634,   717,   634,
     718,   634,   719,   634,   720,   634,   721,   634,   722,   634,
     723,   634,   731,   634,   732,   634,   335,  1219,   818,   819,
     733,   634,   734,   634,   735,   634,   736,   634,   737,   634,
     413,   739,   634,   847,   848,   862,   863,   929,   930,  1350,
    1351,  1353,  1354,  1356,  1357,  1369,  1370,  1372,  1373,  1456,
    1457,   859,  1459,  1460,  1462,  1463,    61,    61,   592,   593,
     336,     6,   337,   338,     7,     8,     9,   339,   340,   341,
     342,   422,   343,   344,   345,   346,   347,   348,   349,   350,
     351,   352,   906,   353,   354,   355,   356,   357,   415,  1283,
     358,    10,    11,    12,    13,    14,    15,   359,    16,    17,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,    19,    20,   371,   372,   373,   374,   375,    21,  -269,
    -269,  -269,    22,    23,   376,    24,   377,   378,   379,   380,
      25,   381,   382,   956,    26,    27,    28,   383,   384,    29,
     385,    30,   386,    31,    32,    33,    34,   387,   388,   389,
      35,   390,   391,   392,    36,   393,   395,    37,   398,   412,
     427,   416,   417,   418,   419,   421,   423,   424,   425,   436,
     460,   426,   431,   432,   433,   434,   435,    38,   454,   995,
     455,   997,   458,   459,   468,   461,   469,   470,   752,   471,
     567,   755,   472,   473,   474,   479,   480,   481,   786,   958,
     482,   483,   484,   485,   486,   487,  1379,   488,   489,   490,
     503,   789,   659,   504,   510,   597,   511,   512,   568,   582,
     602,   603,   615,   636,   643,   616,   617,   618,   619,  1041,
     620,   653,   627,   908,   628,  1046,   629,   635,   640,   935,
    1052,   641,   760,   642,   684,   644,   646,   647,  1416,   645,
     648,   649,   650,   651,    39,    40,   654,   655,    41,   652,
     656,    42,    43,    44,    45,    46,    47,   657,   658,   683,
      48,    49,    50,    51,    52,    53,    54,   685,   686,   724,
      55,   694,   725,    56,   726,   727,   728,    57,    58,    59,
      60,   729,   730,   738,   740,     6,   741,   742,     7,     8,
       9,   743,   750,   751,   753,   756,   757,   758,   759,   761,
    1116,   770,   957,  1119,   763,   764,   766,   771,   776,   784,
     787,  1127,   795,   832,  1130,    10,    11,    12,    13,    14,
      15,   790,    16,    17,   791,   792,   796,   961,   793,   794,
     797,   798,   799,   811,   800,    19,    20,   801,   802,   888,
     803,   816,    21,   817,   822,   824,    22,    23,   840,    24,
     830,   827,   828,   829,    25,  -284,  -284,  -284,    26,    27,
      28,   831,   845,    29,   843,    30,   844,    31,    32,    33,
      34,   846,   849,   850,    35,   860,   864,   865,    36,   889,
     899,    37,   890,   892,   891,   898,   969,   900,   901,   916,
     902,   903,   904,   905,   907,   915,  1213,   917,   919,   920,
     972,    38,   918,  1035,   926,   927,   931,   928,   933,   934,
     938,   939,   976,  1098,  1135,   945,  1014,   946,   947,   948,
     949,   951,   952,   953,   955,  1099,  1015,   959,   960,   962,
     963,   964,   965,  1103,   966,   967,   968,   970,  1018,   971,
     973,   974,   975,   977,   978,   979,   980,   981,   982,   983,
     984,  1077,   992,   994,   985,   999,  1000,  1002,  1004,  1009,
    1031,  1010,  1011,  1012,  1013,  1016,  1017,  1019,  1032,  1022,
    1042,  1020,  1277,  1021,  1023,  1436,  1025,  1026,    39,    40,
    1027,  1028,    41,  1029,  1030,    42,    43,    44,    45,    46,
      47,  1033,  1034,  1036,    48,    49,    50,    51,    52,    53,
      54,  1037,  1038,  1039,    55,     6,  1040,    56,     7,     8,
       9,    57,    58,    59,    60,  1043,  1044,  1045,  1050,  1051,
    1053,  1058,  1054,  1065,  1399,  1402,  1405,  1475,  1092,  1066,
    1067,  1068,  1069,  1070,  1073,    10,    11,    12,    13,    14,
      15,  1071,    16,    17,  1075,  1084,  1088,  1085,  1086,  1087,
    1089,  1090,  1091,  1093,  1094,    19,    20,  1114,  1101,  1097,
    1104,  1105,    21,  -271,  -271,  -271,    22,    23,  1106,    24,
    1107,  1108,     6,  1109,    25,     7,     8,     9,    26,    27,
      28,  1110,  1111,    29,  1112,    30,  1113,    31,    32,    33,
      34,  1115,  1117,  1439,    35,  1118,  1120,  1121,    36,  1122,
    1125,    37,    10,    11,    12,    13,    14,    15,  1284,    16,
      17,  1123,  1124,  1126,  1128,  1129,  1147,  1131,  1132,  1133,
    1134,    38,    19,    20,  1136,  1137,  1138,  1139,  1140,    21,
    1142,  1144,  1146,    22,    23,  1153,    24,  1155,  1156,  1157,
    1158,    25,  1159,   584,  1164,    26,    27,    28,  1160,  1161,
      29,  1162,    30,  1163,    31,    32,    33,    34,  1165,  1168,
    1169,    35,  1285,  1170,  1172,    36,  1173,  1174,    37,  1178,
    1187,  1175,  1176,  1177,  1179,  1183,  1188,  1189,  1190,  1191,
    1192,  1196,  1197,  1198,  1199,  1200,  1202,  1205,    38,  1201,
    1203,  1204,  1206,  1207,  1211,  1212,  1214,  1215,    39,    40,
    1218,  1230,    41,  1229,  1224,    42,    43,    44,    45,    46,
      47,  1225,  1226,  1227,    48,    49,    50,    51,    52,    53,
      54,  1228,  1233,  1231,    55,  1232,  1243,    56,  1244,  1258,
    1247,    57,    58,    59,    60,  1248,  1252,  1253,  1344,  1255,
    1256,  1257,  1259,  1442,  1294,  1260,  1261,  1262,  1263,  1265,
    1264,  1266,  1267,  1268,  1383,  1445,  1271,  1269,  1270,  1272,
    1273,  1274,  1275,  1276,  1278,    39,    40,  1279,  1280,    41,
    1281,  1282,    42,    43,    44,    45,    46,    47,  1286,  1287,
    1288,    48,    49,    50,    51,    52,    53,    54,  1289,  1290,
    1291,    55,     6,  1292,    56,     7,     8,     9,    57,    58,
      59,    60,  1302,  1293,  1301,  1305,  1308,  1319,  1484,  1320,
    1321,  1311,  1318,  1322,  1397,  1325,  1329,  1326,  1327,  1328,
    1330,  1331,    10,    11,    12,    13,    14,    15,  1333,    16,
      17,  1332,  1335,  1336,  1337,  1338,  1339,  1340,  1341,  1342,
    1393,  1410,    19,    20,  1343,  1345,  1346,  1347,  1348,    21,
    1362,  1363,  1349,    22,    23,  1352,    24,  1355,  1358,     6,
    1364,    25,     7,     8,     9,    26,    27,    28,  1365,  1366,
      29,  1367,    30,  1368,    31,    32,    33,    34,  1371,  1374,
    1375,    35,  1334,  1376,  1377,    36,  1378,  1394,    37,    10,
      11,    12,    13,    14,    15,  1380,    16,    17,  1381,  1382,
    1398,  1406,  1400,  1401,  1409,  1403,  1404,  1411,    38,    19,
      20,  1412,  1413,  1414,  1415,  1424,    21,  1434,  1425,  1435,
      22,    23,  1428,    24,  1431,  1437,  1438,  1440,    25,  1441,
    1443,  1444,    26,    27,    28,   612,  1446,    29,  1447,    30,
    1448,    31,    32,    33,    34,  1449,  1451,  1452,    35,  1453,
    1454,  1455,    36,  1458,  1461,    37,  1464,  1469,  1468,  1470,
    1471,  1472,  1473,  1476,  1474,  1477,  1478,  1479,  1482,  1487,
    1490,  1483,  1491,  1485,  1486,    38,  1488,  1489,  1494,  1495,
    1496,  1497,  1499,  1500,  1503,    39,    40,  1498,  1501,    41,
    1502,  1504,    42,    43,    44,    45,    46,    47,  1505,  1506,
    1507,    48,    49,    50,    51,    52,    53,    54,  1508,  1509,
    1510,    55,  1511,  1512,    56,  1513,  1514,  1515,    57,    58,
      59,    60,  1516,  1517,  1518,  1519,  1520,  1521,  1522,  1523,
       4,  1525,   626,  1524,   779,   583,   307,   397,   581,   610,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    39,    40,     0,     0,    41,     0,     0,    42,
      43,    44,    45,    46,    47,     0,     0,     0,    48,    49,
      50,    51,    52,    53,    54,     0,     0,     0,    55,     6,
       0,    56,     7,     8,     9,    57,    58,    59,    60,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
      11,    12,    13,    14,    15,     0,    16,    17,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    19,
      20,     0,     0,     0,     0,     0,    21,     0,     0,     0,
      22,    23,   746,    24,     0,     0,     6,     0,    25,     7,
       8,     9,    26,    27,    28,     0,     0,    29,     0,    30,
       0,    31,    32,    33,    34,     0,     0,     0,    35,     0,
       0,     0,    36,     0,     0,    37,    10,    11,    12,    13,
      14,    15,     0,    16,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,    19,    20,     0,     0,
       0,     0,     0,    21,     0,     0,     0,    22,    23,   747,
      24,     0,     0,     0,     0,    25,     0,     0,     0,    26,
      27,    28,     0,     0,    29,     0,    30,     0,    31,    32,
      33,    34,     0,     0,     0,    35,     0,     0,     0,    36,
       0,     0,    37,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    39,    40,     0,     0,    41,     0,     0,    42,
      43,    44,    45,    46,    47,     0,     0,     0,    48,    49,
      50,    51,    52,    53,    54,     0,     0,     0,    55,     0,
       0,    56,     0,     0,     0,    57,    58,    59,    60,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    39,
      40,     0,     0,    41,     0,     0,    42,    43,    44,    45,
      46,    47,     0,     0,     0,    48,    49,    50,    51,    52,
      53,    54,     0,     0,     0,    55,     6,     0,    56,     7,
       8,     9,    57,    58,    59,    60,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    10,    11,    12,    13,
      14,    15,     0,    16,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    19,    20,     0,     0,
       0,     0,     0,    21,     0,     0,     0,    22,    23,     0,
      24,     0,     0,     6,     0,    25,     7,     8,     9,    26,
      27,    28,     0,     0,    29,   754,    30,     0,    31,    32,
      33,    34,     0,     0,     0,    35,     0,     0,     0,    36,
       0,     0,    37,    10,    11,    12,    13,    14,    15,     0,
      16,    17,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,    19,    20,     0,     0,     0,     0,     0,
      21,     0,     0,     0,    22,    23,     0,    24,     0,     0,
       0,     0,    25,     0,     0,  -286,    26,    27,    28,     0,
       0,    29,     0,    30,     0,    31,    32,    33,    34,     0,
       0,     0,    35,     0,     0,     0,    36,     0,     0,    37,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    39,
      40,     0,     0,    41,     0,     0,    42,    43,    44,    45,
      46,    47,     0,     0,     0,    48,    49,    50,    51,    52,
      53,    54,     0,     0,     0,    55,     0,     0,    56,     0,
       0,     0,    57,    58,    59,    60,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    39,    40,     0,     0,
      41,     0,     0,    42,    43,    44,    45,    46,    47,     0,
       0,     0,    48,    49,    50,    51,    52,    53,    54,     0,
       0,     0,    55,     6,     0,    56,     7,     8,     9,    57,
      58,    59,    60,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,    12,    13,    14,    15,     0,
      16,    17,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    19,    20,     0,     0,     0,     0,     0,
      21,     0,     0,     0,    22,    23,     0,    24,     0,     0,
       6,     0,    25,     7,     8,     9,    26,    27,    28,     0,
     913,    29,     0,    30,     0,    31,    32,    33,    34,     0,
       0,     0,    35,     0,     0,     0,    36,     0,     0,    37,
      10,    11,    12,    13,    14,    15,     0,    16,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
      19,    20,     0,     0,     0,     0,     0,    21,     0,     0,
       0,    22,    23,     0,    24,   954,     0,     0,     0,    25,
       0,     0,     0,    26,    27,    28,     0,     0,    29,     0,
      30,     0,    31,    32,    33,    34,     0,     0,     0,    35,
       0,     0,     0,    36,     0,     0,    37,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    39,    40,     0,     0,
      41,     0,     0,    42,    43,    44,    45,    46,    47,     0,
       0,     0,    48,    49,    50,    51,    52,    53,    54,     0,
       0,     0,    55,     0,     0,    56,     0,     0,     0,    57,
      58,    59,    60,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    39,    40,     0,     0,    41,     0,     0,
      42,    43,    44,    45,    46,    47,     0,     0,     0,    48,
      49,    50,    51,    52,    53,    54,     0,     0,     0,    55,
       6,     0,    56,     7,     8,     9,    57,    58,    59,    60,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,    12,    13,    14,    15,     0,    16,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      19,    20,     0,     0,     0,     0,     0,    21,     0,     0,
    -273,    22,    23,     0,    24,     0,     0,     6,     0,    25,
       7,     8,     9,    26,    27,    28,     0,     0,    29,     0,
      30,     0,    31,    32,    33,    34,     0,     0,     0,    35,
       0,     0,     0,    36,     0,     0,    37,    10,    11,    12,
      13,    14,    15,     0,    16,    17,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,    19,    20,     0,
       0,     0,     0,     0,    21,     0,     0,     0,    22,    23,
       0,    24,  1074,     0,     0,     0,    25,     0,     0,     0,
      26,    27,    28,     0,     0,    29,     0,    30,     0,    31,
      32,    33,    34,     0,     0,     0,    35,     0,     0,     0,
      36,     0,     0,    37,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    39,    40,     0,     0,    41,     0,     0,
      42,    43,    44,    45,    46,    47,     0,     0,     0,    48,
      49,    50,    51,    52,    53,    54,     0,     0,     0,    55,
       0,     0,    56,     0,     0,     0,    57,    58,    59,    60,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      39,    40,     0,     0,    41,     0,     0,    42,    43,    44,
      45,    46,    47,     0,     0,     0,    48,    49,    50,    51,
      52,    53,    54,     0,     0,     0,    55,     6,     0,    56,
       7,     8,     9,    57,    58,    59,    60,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,    12,
      13,    14,    15,     0,    16,    17,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    19,    20,     0,
       0,     0,     0,     0,    21,     0,     0,     0,    22,    23,
       0,    24,  1076,     0,     6,     0,    25,     7,     8,     9,
      26,    27,    28,     0,     0,    29,     0,    30,     0,    31,
      32,    33,    34,     0,     0,     0,    35,     0,     0,     0,
      36,     0,     0,    37,    10,    11,    12,    13,    14,    15,
       0,    16,    17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,    19,    20,     0,     0,     0,     0,
       0,    21,     0,     0,     0,    22,    23,     0,    24,  1216,
       0,     0,     0,    25,     0,     0,     0,    26,    27,    28,
       0,     0,    29,     0,    30,     0,    31,    32,    33,    34,
       0,     0,     0,    35,     0,     0,     0,    36,     0,     0,
      37,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      39,    40,     0,     0,    41,     0,     0,    42,    43,    44,
      45,    46,    47,     0,     0,     0,    48,    49,    50,    51,
      52,    53,    54,     0,     0,     0,    55,     0,     0,    56,
       0,     0,     0,    57,    58,    59,    60,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    39,    40,     0,
       0,    41,     0,     0,    42,    43,    44,    45,    46,    47,
       0,     0,     0,    48,    49,    50,    51,    52,    53,    54,
       0,     0,     0,    55,     6,     0,    56,     7,     8,     9,
      57,    58,    59,    60,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,    11,    12,    13,    14,    15,
       0,    16,    17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    19,    20,     0,     0,     0,     0,
       0,    21,     0,     0,     0,    22,    23,     0,    24,  1217,
       0,     6,     0,    25,     7,     8,     9,    26,    27,    28,
       0,     0,    29,     0,    30,     0,    31,    32,    33,    34,
       0,     0,     0,    35,     0,     0,     0,    36,     0,     0,
      37,    10,    11,    12,    13,    14,    15,     0,    16,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,    19,    20,     0,     0,     0,     0,     0,    21,     0,
       0,     0,    22,    23,     0,    24,     0,     0,     0,     0,
      25,     0,     0,     0,    26,    27,    28,     0,     0,    29,
       0,    30,     0,    31,    32,    33,    34,     0,     0,     0,
      35,  1417,     0,     0,    36,     0,     0,    37,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    39,    40,     0,
       0,    41,     0,     0,    42,    43,    44,    45,    46,    47,
       0,     0,     0,    48,    49,    50,    51,    52,    53,    54,
       0,     0,     0,    55,     0,     0,    56,     0,     0,     0,
      57,    58,    59,    60,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    39,    40,     0,     0,    41,     0,
       0,    42,    43,    44,    45,    46,    47,     0,     0,     0,
      48,    49,    50,    51,    52,    53,    54,     0,     0,     0,
      55,     6,     0,    56,     7,     8,     9,    57,    58,    59,
      60,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,    12,    13,    14,    15,     0,    16,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    19,    20,     0,     0,     0,     0,     0,    21,     0,
       0,     0,    22,    23,     0,    24,     0,     0,     0,     0,
      25,     0,     0,     0,    26,    27,    28,     0,     0,    29,
       0,    30,     0,    31,    32,    33,    34,     0,     0,     0,
      35,  1450,     0,     0,    36,     0,     0,    37,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   120,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     121,     0,     0,     0,     0,     0,     0,     0,   122,   123,
     124,   125,   126,     0,    39,    40,     0,     0,    41,     0,
       0,    42,    43,    44,    45,    46,    47,     0,     0,     0,
      48,    49,    50,    51,    52,    53,    54,   127,     0,     0,
      55,   128,     0,    56,   129,     0,     0,    57,    58,    59,
      60,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,     0,   216,   217,
     218,     0,     0,   219,     0,     0,   220,   221,   222,   223,
     224,   225,     0,     0,     0,     0,   120,   226,   227,   228,
     229,   230,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   231,   232,   233,   234,   256,
     121,   235,     0,     0,     0,   236,     0,     0,   122,   123,
     124,   125,   126,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   127,     0,     0,
       0,   128,     0,     0,   129,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   212,   213,   214,   215,     0,   216,   217,
     218,     0,     0,   219,     0,     0,   220,   221,   222,   223,
     224,   225,     0,     0,     0,   120,     0,   226,   227,   228,
     229,   230,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   231,   232,   233,   234,   121,
       0,   235,   516,     0,     0,   236,     0,   122,   123,   124,
     125,   126,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   127,     0,     0,     0,
     128,     0,     0,   129,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   213,   214,   215,     0,   216,   217,   218,
       0,     0,   219,     0,     0,   220,   221,   222,   223,   224,
     225,     0,     0,     0,   120,     0,   226,   227,   228,   229,
     230,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   231,   232,   233,   234,   121,     0,
     235,   518,     0,     0,   236,     0,   122,   123,   124,   125,
     126,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   127,     0,     0,     0,   128,
       0,     0,   129,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,     0,   216,   217,   218,     0,
       0,   219,     0,     0,   220,   221,   222,   223,   224,   225,
       0,     0,     0,   120,     0,   226,   227,   228,   229,   230,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   231,   232,   233,   234,   121,     0,   235,
     520,     0,     0,   236,     0,   122,   123,   124,   125,   126,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   127,     0,     0,     0,   128,     0,
       0,   129,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,     0,   216,   217,   218,     0,     0,
     219,     0,     0,   220,   221,   222,   223,   224,   225,     0,
       0,     0,   120,     0,   226,   227,   228,   229,   230,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   231,   232,   233,   234,   121,     0,   235,     0,
       0,     0,   236,     0,   122,   123,   124,   125,   126,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   127,     0,     0,     0,   128,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   171,   172,
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,   192,
     193,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,     0,   216,   217,   218,     0,     0,   219,
       0,     0,   220,   221,   222,   223,   224,   225,     0,     0,
       0,   120,     0,   226,   227,   228,   229,   230,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   231,   232,   233,   234,   121,     0,   235,     0,     0,
       0,   236,     0,   122,   123,   124,   125,   126,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   127,     0,     0,     0,   128,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   195,   196,   197,   198,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,   212,   213,
     214,   215,     0,   216,   217,   218,     0,     0,   219,     0,
       0,   220,   221,   222,   223,   224,   225,     0,     0,     0,
       0,     0,   226,   227,   228,   229,   230,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     231,   232,   233,   234,     0,     0,   235,   491,   492,   493,
     494,   495,   496,   497,   498,   499,   500,   501,   502,     0,
       0,   505,   506,   507,   508,   509,     0,     0,     0,   513,
     514,   515,   517,   519,   521,     0,     0,     0,     0,   526,
     527,   528,   529,   530,   531,   532,     0,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   545,   546,
     547,   548,   549,   550,   551,   552,   553,   554,   555,   556,
     557,   558,   559,   560,   561,   562,     0,     0,     0,     0,
       0,     0,     0,     0,   571,   572,   573,   574,   575,   576,
     577,     0,   579
};

static const yytype_int16 yycheck[] =
{
      10,   625,    43,    43,    14,    10,    12,    43,   632,    19,
      16,    21,    22,    23,   423,   424,   425,    43,    24,    43,
      43,    43,   431,    43,    30,    31,    32,    33,    43,    43,
      43,    43,     0,     1,    69,    69,     4,     5,     6,    11,
      12,    13,    14,    96,    96,   637,    49,   204,    43,    43,
      43,    57,    96,    59,    96,    96,    96,    96,   105,    43,
      96,   202,   205,    31,    32,    33,    34,    35,    36,    96,
      38,    39,    96,    96,    96,    96,    96,   234,   791,   792,
      96,    96,    50,    51,    52,   798,   799,   800,   801,   802,
      58,   234,   917,   234,    62,    63,   221,    65,   100,   241,
     242,   221,    70,   214,   215,   230,    74,    75,    76,   119,
     230,    79,     3,    81,    30,    83,    84,    85,    86,    95,
     105,   234,    90,   234,    40,    41,    94,     0,   104,    97,
      46,    47,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,   766,   230,    29,    30,    99,    93,    93,   117,
      71,    72,   776,    29,    30,    40,    41,    42,   104,   104,
      86,    46,    47,    95,    40,    41,    42,    95,    99,    98,
      46,    47,   104,    98,   103,    98,   104,   234,   103,  1004,
     103,   234,   234,   755,   100,    29,    30,   779,   100,   236,
     234,   117,   234,   234,   234,   234,    40,    41,   234,   234,
     234,   230,    46,    47,    99,   100,   101,   234,   234,   234,
     234,   234,   234,   234,   234,   100,    67,    68,   234,   234,
     234,   234,   234,   102,   100,   235,   194,   195,   236,   234,
     198,   234,   234,   201,   202,   203,   204,   205,   206,   234,
     234,   234,   210,   211,   212,   213,   214,   215,   216,   255,
     234,   236,   220,   825,   230,   223,   100,   235,   230,   227,
     228,   229,   230,   976,   977,    98,   237,   238,   194,   195,
     103,   228,   198,   283,   284,   201,   202,   203,   204,   205,
     206,   234,   239,   240,   230,   230,   212,   213,   214,   215,
     216,   203,    98,   209,    98,   207,   208,   103,   230,   103,
     234,   230,   230,   234,   230,   230,    98,   230,   203,   239,
     240,   103,   207,   208,   938,   194,   195,   196,   197,   198,
     199,    11,   234,    13,   209,    98,   336,   337,   338,   339,
     103,    98,   234,   209,   234,    98,   103,   347,   230,   234,
     103,   750,   751,   222,   753,   235,   214,   215,    98,    98,
      98,    98,    98,   103,   103,   103,   103,   103,   230,    11,
      12,    13,    14,   201,   202,   209,   234,   377,   378,   379,
     380,    11,    12,    13,    14,   784,   236,   383,   384,    11,
      12,    13,    14,   237,   238,   395,   392,   230,    11,    12,
      13,    14,  1016,  1017,   201,   202,   234,   230,  1022,    11,
      12,    13,    14,   230,   414,   415,   230,   417,   225,   226,
     416,   194,   195,   236,   231,   198,   426,   427,   201,   202,
     203,   204,   205,   206,   230,    48,   230,   234,   230,   212,
     213,   214,   215,   216,    40,    41,   237,   238,   230,    98,
      46,    47,   235,   230,   103,   228,   230,   230,   458,   101,
     243,   244,   245,   246,   247,   237,   238,   230,   236,   225,
     226,   101,   236,   230,   236,   231,   236,   230,   236,   101,
     225,   226,   236,     0,     1,   236,   231,     4,     5,     6,
     230,   230,   230,   230,   230,    11,    12,    13,    14,   101,
     401,   402,   403,   404,   405,   406,   407,   236,   907,   237,
     238,   910,   236,   912,    31,    32,    33,    34,    35,    36,
     236,    38,    39,   225,   226,    11,    12,    13,    14,   231,
       7,     8,     9,    50,    51,    52,    11,    12,    13,    14,
     236,    58,   410,   411,   412,    62,    63,   236,    65,   236,
    1164,  1165,   236,    70,  1168,  1169,  1170,    74,    75,    76,
    1174,   236,    79,   236,    81,   236,    83,    84,    85,    86,
     237,   238,   236,    90,   237,   238,   236,    94,   237,   238,
      97,    22,    23,    24,    25,    26,    27,    22,    23,    24,
      25,    26,    27,   992,   237,   238,   237,   238,   237,   238,
     117,   237,   238,   237,   238,   236,   602,   233,   237,   238,
     237,   238,   237,   238,   237,   238,   237,   238,   237,   238,
     237,   238,   237,   238,    88,   237,   238,   237,   238,   237,
     238,   237,   238,   236,   634,    87,   237,   238,   237,   238,
     640,    59,    60,   643,   237,   238,   237,   238,   237,   238,
     237,   238,   237,   238,   237,   238,   237,   238,   237,   238,
     237,   238,   237,   238,   237,   238,   237,   238,   237,   238,
     237,   238,   237,   238,  1073,   236,  1075,   194,   195,   237,
     238,   198,   236,   683,   201,   202,   203,   204,   205,   206,
     237,   238,   236,   210,   211,   212,   213,   214,   215,   216,
     237,   238,   236,   220,   237,   238,   223,   237,   238,   236,
     227,   228,   229,   230,   237,   238,   237,   238,   237,   238,
     234,   235,   237,   238,   237,   238,   237,   238,   237,   238,
     237,   238,   237,   238,   237,   238,   237,   238,   237,   238,
     237,   238,   237,   238,   237,   238,   236,  1146,   748,   749,
     237,   238,   237,   238,   237,   238,   237,   238,   237,   238,
     105,   237,   238,   237,   238,   237,   238,   237,   238,    44,
      45,    44,    45,    44,    45,   237,   238,   237,   238,    44,
      45,   781,    44,    45,    44,    45,     3,     4,   408,   409,
     236,     1,   236,   236,     4,     5,     6,   236,   236,   236,
     236,    53,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   812,   236,   236,   236,   236,   236,   235,  1218,
     236,    31,    32,    33,    34,    35,    36,   236,    38,    39,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,    51,    52,   236,   236,   236,   236,   236,    58,    59,
      60,    61,    62,    63,   236,    65,   236,   236,   236,   236,
      70,   236,   236,   863,    74,    75,    76,   236,   236,    79,
     236,    81,   236,    83,    84,    85,    86,   236,   236,   236,
      90,   236,   236,   236,    94,   236,   236,    97,   234,   224,
      71,   235,   235,   234,   234,   234,   234,   234,   234,    46,
     192,   235,   234,   234,   234,   234,   234,   117,   234,   909,
     234,   911,   228,   234,   234,   230,   234,   236,    73,   236,
     230,    92,   236,   236,   236,   234,   234,   234,   105,    30,
     236,   236,   236,   236,   236,   236,  1335,   236,   234,   234,
     237,   241,   200,   237,   237,   230,   237,   237,   237,   237,
     237,   234,   234,   230,   238,   236,   236,   236,   236,   959,
     236,   230,   236,    61,   236,   965,   236,   234,   236,    99,
     970,   237,   233,   237,   237,   234,   231,   231,  1377,   236,
     231,   231,   231,   236,   194,   195,   231,   231,   198,   236,
     231,   201,   202,   203,   204,   205,   206,   231,   231,   238,
     210,   211,   212,   213,   214,   215,   216,   237,   237,   237,
     220,   238,   237,   223,   237,   237,   237,   227,   228,   229,
     230,   237,   237,   237,   237,     1,   234,   234,     4,     5,
       6,   234,   234,   234,   234,   231,   231,   231,   231,   236,
    1040,   230,   241,  1043,   236,   236,   234,   230,   234,   234,
     234,  1051,   230,   233,  1054,    31,    32,    33,    34,    35,
      36,   237,    38,    39,   237,   237,   230,    30,   238,   238,
     237,   237,   237,   234,   237,    51,    52,   237,   237,   231,
     238,   234,    58,   234,   234,   234,    62,    63,   230,    65,
     238,   237,   237,   237,    70,    71,    72,    73,    74,    75,
      76,   237,   237,    79,   238,    81,   238,    83,    84,    85,
      86,   237,   234,   230,    90,   234,   230,   238,    94,   231,
     238,    97,   237,   234,   237,   233,    30,   237,   237,   231,
     237,   237,   237,   237,   234,   234,  1136,   234,   234,   230,
      30,   117,   237,   230,   238,   238,   234,   237,   231,   231,
     234,   231,   237,    99,    30,   236,   231,   236,   236,   236,
     236,   234,   234,   234,   234,    99,   231,   236,   236,   236,
     236,   234,   236,    99,   236,   236,   234,   236,   231,   236,
     236,   236,   234,   237,   234,   234,   234,   234,   234,   234,
     234,  1000,   234,   234,   237,   234,   234,   237,   234,   236,
     231,   236,   236,   236,   236,   234,   234,   234,   231,   234,
     230,   237,  1212,   237,   236,    45,   237,   236,   194,   195,
     236,   236,   198,   236,   236,   201,   202,   203,   204,   205,
     206,   231,   231,   234,   210,   211,   212,   213,   214,   215,
     216,   234,   237,   237,   220,     1,   236,   223,     4,     5,
       6,   227,   228,   229,   230,   236,   231,   230,   230,   236,
     230,   230,   236,   234,    44,    44,    44,    44,   230,   237,
     237,   237,   237,   237,   234,    31,    32,    33,    34,    35,
      36,   237,    38,    39,   234,   236,   231,   236,   236,   236,
     231,   231,   231,   237,   237,    51,    52,   234,   231,   237,
     231,   231,    58,    59,    60,    61,    62,    63,   231,    65,
     231,   230,     1,   237,    70,     4,     5,     6,    74,    75,
      76,   237,   237,    79,   238,    81,   237,    83,    84,    85,
      86,   234,   237,    45,    90,   237,   237,   237,    94,   237,
     237,    97,    31,    32,    33,    34,    35,    36,    37,    38,
      39,   238,   238,   237,   237,   237,   230,   238,   238,   237,
     237,   117,    51,    52,   236,   236,   236,   234,   234,    58,
     234,   234,   234,    62,    63,   234,    65,   231,   231,   231,
     231,    70,   237,   400,   234,    74,    75,    76,   237,   237,
      79,   238,    81,   237,    83,    84,    85,    86,   234,   234,
     234,    90,    91,   234,   237,    94,   234,   234,    97,   238,
     231,   237,   237,   237,   237,   234,   234,   237,   234,   234,
     237,   234,   234,   231,   231,   234,   237,   237,   117,   234,
     234,   234,   231,   231,   234,   236,   231,   230,   194,   195,
     234,   237,   198,   234,   236,   201,   202,   203,   204,   205,
     206,   236,   236,   236,   210,   211,   212,   213,   214,   215,
     216,   236,   238,   237,   220,   237,   231,   223,   234,   231,
     234,   227,   228,   229,   230,   234,   234,   234,   238,   234,
     234,   234,   234,    45,   230,   236,   236,   236,   236,   234,
     237,   234,   234,   234,   238,    45,   234,   237,   237,   234,
     237,   237,   234,   234,   237,   194,   195,   237,   237,   198,
     234,   234,   201,   202,   203,   204,   205,   206,   236,   236,
     236,   210,   211,   212,   213,   214,   215,   216,   236,   231,
     231,   220,     1,   231,   223,     4,     5,     6,   227,   228,
     229,   230,   236,   231,   231,   236,   236,   230,    44,   231,
     230,   237,   237,   231,   238,   234,   237,   234,   234,   234,
     234,   234,    31,    32,    33,    34,    35,    36,    37,    38,
      39,   234,   234,   234,   231,   231,   231,   231,   237,   237,
     231,   231,    51,    52,   237,   237,   234,   234,   234,    58,
     234,   234,   237,    62,    63,   236,    65,   236,   236,     1,
     234,    70,     4,     5,     6,    74,    75,    76,   234,   234,
      79,   234,    81,   234,    83,    84,    85,    86,   237,   237,
     236,    90,    91,   234,   234,    94,   234,   234,    97,    31,
      32,    33,    34,    35,    36,   237,    38,    39,   237,   237,
     237,   236,   238,   237,   234,   238,   237,   234,   117,    51,
      52,   234,   231,   234,   231,   231,    58,   237,   236,   234,
      62,    63,   236,    65,   236,   234,   237,   234,    70,   237,
     234,   237,    74,    75,    76,    77,   236,    79,   237,    81,
     237,    83,    84,    85,    86,   237,   234,   234,    90,   234,
     234,   237,    94,   236,   236,    97,   236,   234,   237,   237,
     234,   237,   234,   234,   237,   234,   234,   234,   238,    44,
      44,   237,   236,   238,   237,   117,   238,   237,   234,   234,
     234,   234,   234,    45,    45,   194,   195,   237,   234,   198,
     237,   234,   201,   202,   203,   204,   205,   206,   237,    45,
     234,   210,   211,   212,   213,   214,   215,   216,   237,    45,
     236,   220,   234,   237,   223,   234,   237,   234,   227,   228,
     229,   230,   237,   234,   237,    44,   234,   234,   234,   234,
       1,   234,   444,   237,   635,   399,   129,   236,   395,   428,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   194,   195,    -1,    -1,   198,    -1,    -1,   201,
     202,   203,   204,   205,   206,    -1,    -1,    -1,   210,   211,
     212,   213,   214,   215,   216,    -1,    -1,    -1,   220,     1,
      -1,   223,     4,     5,     6,   227,   228,   229,   230,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    33,    34,    35,    36,    -1,    38,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,
      62,    63,    64,    65,    -1,    -1,     1,    -1,    70,     4,
       5,     6,    74,    75,    76,    -1,    -1,    79,    -1,    81,
      -1,    83,    84,    85,    86,    -1,    -1,    -1,    90,    -1,
      -1,    -1,    94,    -1,    -1,    97,    31,    32,    33,    34,
      35,    36,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   117,    51,    52,    -1,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    -1,    62,    63,    64,
      65,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    74,
      75,    76,    -1,    -1,    79,    -1,    81,    -1,    83,    84,
      85,    86,    -1,    -1,    -1,    90,    -1,    -1,    -1,    94,
      -1,    -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   194,   195,    -1,    -1,   198,    -1,    -1,   201,
     202,   203,   204,   205,   206,    -1,    -1,    -1,   210,   211,
     212,   213,   214,   215,   216,    -1,    -1,    -1,   220,    -1,
      -1,   223,    -1,    -1,    -1,   227,   228,   229,   230,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,
     195,    -1,    -1,   198,    -1,    -1,   201,   202,   203,   204,
     205,   206,    -1,    -1,    -1,   210,   211,   212,   213,   214,
     215,   216,    -1,    -1,    -1,   220,     1,    -1,   223,     4,
       5,     6,   227,   228,   229,   230,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,
      35,    36,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    -1,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    -1,    62,    63,    -1,
      65,    -1,    -1,     1,    -1,    70,     4,     5,     6,    74,
      75,    76,    -1,    -1,    79,    80,    81,    -1,    83,    84,
      85,    86,    -1,    -1,    -1,    90,    -1,    -1,    -1,    94,
      -1,    -1,    97,    31,    32,    33,    34,    35,    36,    -1,
      38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   117,    51,    52,    -1,    -1,    -1,    -1,    -1,
      58,    -1,    -1,    -1,    62,    63,    -1,    65,    -1,    -1,
      -1,    -1,    70,    -1,    -1,    73,    74,    75,    76,    -1,
      -1,    79,    -1,    81,    -1,    83,    84,    85,    86,    -1,
      -1,    -1,    90,    -1,    -1,    -1,    94,    -1,    -1,    97,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,
     195,    -1,    -1,   198,    -1,    -1,   201,   202,   203,   204,
     205,   206,    -1,    -1,    -1,   210,   211,   212,   213,   214,
     215,   216,    -1,    -1,    -1,   220,    -1,    -1,   223,    -1,
      -1,    -1,   227,   228,   229,   230,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   194,   195,    -1,    -1,
     198,    -1,    -1,   201,   202,   203,   204,   205,   206,    -1,
      -1,    -1,   210,   211,   212,   213,   214,   215,   216,    -1,
      -1,    -1,   220,     1,    -1,   223,     4,     5,     6,   227,
     228,   229,   230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    -1,
      38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    -1,    -1,    -1,    -1,    -1,
      58,    -1,    -1,    -1,    62,    63,    -1,    65,    -1,    -1,
       1,    -1,    70,     4,     5,     6,    74,    75,    76,    -1,
      78,    79,    -1,    81,    -1,    83,    84,    85,    86,    -1,
      -1,    -1,    90,    -1,    -1,    -1,    94,    -1,    -1,    97,
      31,    32,    33,    34,    35,    36,    -1,    38,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,
      51,    52,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,
      -1,    62,    63,    -1,    65,    66,    -1,    -1,    -1,    70,
      -1,    -1,    -1,    74,    75,    76,    -1,    -1,    79,    -1,
      81,    -1,    83,    84,    85,    86,    -1,    -1,    -1,    90,
      -1,    -1,    -1,    94,    -1,    -1,    97,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   117,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   194,   195,    -1,    -1,
     198,    -1,    -1,   201,   202,   203,   204,   205,   206,    -1,
      -1,    -1,   210,   211,   212,   213,   214,   215,   216,    -1,
      -1,    -1,   220,    -1,    -1,   223,    -1,    -1,    -1,   227,
     228,   229,   230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   194,   195,    -1,    -1,   198,    -1,    -1,
     201,   202,   203,   204,   205,   206,    -1,    -1,    -1,   210,
     211,   212,   213,   214,   215,   216,    -1,    -1,    -1,   220,
       1,    -1,   223,     4,     5,     6,   227,   228,   229,   230,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,    33,    34,    35,    36,    -1,    38,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    52,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,
      61,    62,    63,    -1,    65,    -1,    -1,     1,    -1,    70,
       4,     5,     6,    74,    75,    76,    -1,    -1,    79,    -1,
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
      -1,    -1,    -1,   194,   195,    -1,    -1,   198,    -1,    -1,
     201,   202,   203,   204,   205,   206,    -1,    -1,    -1,   210,
     211,   212,   213,   214,   215,   216,    -1,    -1,    -1,   220,
      -1,    -1,   223,    -1,    -1,    -1,   227,   228,   229,   230,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     194,   195,    -1,    -1,   198,    -1,    -1,   201,   202,   203,
     204,   205,   206,    -1,    -1,    -1,   210,   211,   212,   213,
     214,   215,   216,    -1,    -1,    -1,   220,     1,    -1,   223,
       4,     5,     6,   227,   228,   229,   230,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,    -1,    38,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    -1,
      -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,    62,    63,
      -1,    65,    66,    -1,     1,    -1,    70,     4,     5,     6,
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
     117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     194,   195,    -1,    -1,   198,    -1,    -1,   201,   202,   203,
     204,   205,   206,    -1,    -1,    -1,   210,   211,   212,   213,
     214,   215,   216,    -1,    -1,    -1,   220,    -1,    -1,   223,
      -1,    -1,    -1,   227,   228,   229,   230,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,   195,    -1,
      -1,   198,    -1,    -1,   201,   202,   203,   204,   205,   206,
      -1,    -1,    -1,   210,   211,   212,   213,   214,   215,   216,
      -1,    -1,    -1,   220,     1,    -1,   223,     4,     5,     6,
     227,   228,   229,   230,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,    -1,    62,    63,    -1,    65,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    74,    75,    76,    -1,    -1,    79,
      -1,    81,    -1,    83,    84,    85,    86,    -1,    -1,    -1,
      90,    91,    -1,    -1,    94,    -1,    -1,    97,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,   195,    -1,
      -1,   198,    -1,    -1,   201,   202,   203,   204,   205,   206,
      -1,    -1,    -1,   210,   211,   212,   213,   214,   215,   216,
      -1,    -1,    -1,   220,    -1,    -1,   223,    -1,    -1,    -1,
     227,   228,   229,   230,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   194,   195,    -1,    -1,   198,    -1,
      -1,   201,   202,   203,   204,   205,   206,    -1,    -1,    -1,
     210,   211,   212,   213,   214,   215,   216,    -1,    -1,    -1,
     220,     1,    -1,   223,     4,     5,     6,   227,   228,   229,
     230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    33,    34,    35,    36,    -1,    38,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,    -1,    -1,    -1,    -1,    -1,    58,    -1,
      -1,    -1,    62,    63,    -1,    65,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    -1,    74,    75,    76,    -1,    -1,    79,
      -1,    81,    -1,    83,    84,    85,    86,    -1,    -1,    -1,
      90,    91,    -1,    -1,    94,    -1,    -1,    97,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,
      55,    56,    57,    -1,   194,   195,    -1,    -1,   198,    -1,
      -1,   201,   202,   203,   204,   205,   206,    -1,    -1,    -1,
     210,   211,   212,   213,   214,   215,   216,    82,    -1,    -1,
     220,    86,    -1,   223,    89,    -1,    -1,   227,   228,   229,
     230,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,   193,   194,
     195,    -1,    -1,   198,    -1,    -1,   201,   202,   203,   204,
     205,   206,    -1,    -1,    -1,    -1,    21,   212,   213,   214,
     215,   216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   230,   231,   232,   233,   234,
      45,   236,    -1,    -1,    -1,   240,    -1,    -1,    53,    54,
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
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,    -1,   193,   194,
     195,    -1,    -1,   198,    -1,    -1,   201,   202,   203,   204,
     205,   206,    -1,    -1,    -1,    21,    -1,   212,   213,   214,
     215,   216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   230,   231,   232,   233,    45,
      -1,   236,   237,    -1,    -1,   240,    -1,    53,    54,    55,
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
     186,   187,   188,   189,   190,   191,    -1,   193,   194,   195,
      -1,    -1,   198,    -1,    -1,   201,   202,   203,   204,   205,
     206,    -1,    -1,    -1,    21,    -1,   212,   213,   214,   215,
     216,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   230,   231,   232,   233,    45,    -1,
     236,   237,    -1,    -1,   240,    -1,    53,    54,    55,    56,
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
     187,   188,   189,   190,   191,    -1,   193,   194,   195,    -1,
      -1,   198,    -1,    -1,   201,   202,   203,   204,   205,   206,
      -1,    -1,    -1,    21,    -1,   212,   213,   214,   215,   216,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   230,   231,   232,   233,    45,    -1,   236,
     237,    -1,    -1,   240,    -1,    53,    54,    55,    56,    57,
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
     188,   189,   190,   191,    -1,   193,   194,   195,    -1,    -1,
     198,    -1,    -1,   201,   202,   203,   204,   205,   206,    -1,
      -1,    -1,    21,    -1,   212,   213,   214,   215,   216,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   230,   231,   232,   233,    45,    -1,   236,    -1,
      -1,    -1,   240,    -1,    53,    54,    55,    56,    57,    -1,
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
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,    -1,   193,   194,   195,    -1,    -1,   198,
      -1,    -1,   201,   202,   203,   204,   205,   206,    -1,    -1,
      -1,    21,    -1,   212,   213,   214,   215,   216,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   230,   231,   232,   233,    45,    -1,   236,    -1,    -1,
      -1,   240,    -1,    53,    54,    55,    56,    57,    -1,    -1,
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
     190,   191,    -1,   193,   194,   195,    -1,    -1,   198,    -1,
      -1,   201,   202,   203,   204,   205,   206,    -1,    -1,    -1,
      -1,    -1,   212,   213,   214,   215,   216,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     230,   231,   232,   233,    -1,    -1,   236,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,   319,    -1,
      -1,   322,   323,   324,   325,   326,    -1,    -1,    -1,   330,
     331,   332,   333,   334,   335,    -1,    -1,    -1,    -1,   340,
     341,   342,   343,   344,   345,   346,    -1,   348,   349,   350,
     351,   352,   353,   354,   355,   356,   357,   358,   359,   360,
     361,   362,   363,   364,   365,   366,   367,   368,   369,   370,
     371,   372,   373,   374,   375,   376,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   385,   386,   387,   388,   389,   390,
     391,    -1,   393
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,     3,   249,   250,   250,     0,     1,     4,     5,     6,
      31,    32,    33,    34,    35,    36,    38,    39,    50,    51,
      52,    58,    62,    63,    65,    70,    74,    75,    76,    79,
      81,    83,    84,    85,    86,    90,    94,    97,   117,   194,
     195,   198,   201,   202,   203,   204,   205,   206,   210,   211,
     212,   213,   214,   215,   216,   220,   223,   227,   228,   229,
     230,   252,   253,   254,   256,   257,   258,   259,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   270,   271,
     272,   279,   280,   281,   282,   283,   284,   285,   286,   287,
     288,   291,   295,   299,   300,   301,   302,   303,   307,   308,
     234,   230,   194,   195,   198,   201,   202,   203,   204,   205,
     206,   212,   213,   214,   215,   216,   228,   230,   319,   230,
      21,    45,    53,    54,    55,    56,    57,    82,    86,    89,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   193,   194,   195,   198,
     201,   202,   203,   204,   205,   206,   212,   213,   214,   215,
     216,   230,   231,   232,   233,   236,   240,   309,   310,   311,
     312,   313,   314,   315,   316,   317,   318,   320,   230,   257,
     319,   257,   309,   234,   319,   236,   234,   309,   235,   309,
     309,   309,   319,   234,   234,   234,   234,   230,   319,   319,
     319,   319,   230,   230,   230,   236,   230,   230,   230,   319,
     230,   319,   105,   236,   235,     7,     8,     9,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,   102,   194,
     195,   196,   197,   198,   199,   222,   309,   313,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   236,   236,   236,   236,   236,   236,
     236,   236,   236,   236,   233,   236,   309,   318,   234,    88,
      87,   235,   243,   244,   245,   246,   247,   228,   239,   240,
     241,   242,   224,   105,   236,   235,   235,   235,   234,   234,
     319,   234,    53,   234,   234,   234,   235,    71,   304,   305,
     251,   234,   234,   234,   234,   234,    46,   273,    11,    12,
      13,    14,    48,   274,    99,   100,   101,   203,   207,   208,
     234,   293,   309,   323,   234,   234,    99,   234,   228,   234,
     192,   230,   309,   321,   322,   309,    10,   234,   234,   234,
     236,   236,   236,   236,   236,   204,   234,   205,   234,   234,
     234,   234,   236,   236,   236,   236,   236,   236,   236,   234,
     234,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   237,   237,   323,   323,   323,   323,   323,
     237,   237,   237,   323,   323,   323,   237,   323,   237,   323,
     237,   323,   309,   309,   309,   309,   323,   323,   323,   323,
     323,   323,   323,   309,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   309,   309,   309,   309,   230,   237,   319,
     319,   323,   323,   323,   323,   323,   323,   323,   319,   323,
     309,   321,   237,   311,   312,   314,   314,   314,   314,   314,
     314,   314,   315,   315,   316,   316,   316,   230,   309,   309,
     319,   309,   237,   234,   251,   251,   251,   309,   309,    72,
     305,   306,    77,   252,   251,   234,   236,   236,   236,   236,
     236,    49,   234,   100,   203,   234,   293,   236,   236,   236,
     292,    99,   234,   237,   238,   234,   230,   289,   290,   309,
     236,   237,   237,   238,   234,   236,   231,   231,   231,   231,
     231,   236,   236,   230,   231,   231,   231,   231,   231,   200,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   238,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   238,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   237,   237,   237,   237,   237,   237,   237,   237,   237,
     237,   234,   234,   234,   319,   296,    64,    64,    67,    68,
     234,   234,    73,   234,    80,    92,   231,   231,   231,   231,
     233,   236,   277,   236,   236,   292,   234,   225,   226,   231,
     230,   230,    98,   103,   230,   294,   234,   292,   309,   289,
     234,   235,   221,   290,   234,   309,   105,   234,   309,   241,
     237,   237,   237,   238,   238,   230,   230,   237,   237,   237,
     237,   237,   237,   238,   309,    22,    23,    24,    25,    26,
      27,   234,    59,    60,   297,   298,   234,   234,   309,   309,
     251,   251,   234,   251,   234,   230,   274,   237,   237,   237,
     238,   237,   233,    95,   104,   230,   278,   225,   226,   231,
     230,    98,   292,   238,   238,   237,   237,   237,   238,   234,
     230,    11,    12,    13,    14,   101,   292,    98,   221,   309,
     234,   251,   237,   238,   230,   238,    29,    30,    40,    41,
      42,    46,    47,   100,   209,   255,    30,    46,   100,   209,
     255,    29,    30,    42,    46,   100,   209,   255,   231,   231,
     237,   237,   234,   255,   255,   255,   255,   255,   233,   238,
     237,   237,   237,   237,   237,   237,   309,   234,    61,    69,
     234,    69,   234,    78,   274,   234,   231,   234,   237,   234,
     230,    11,    12,    13,    14,   101,   238,   238,   237,   237,
     238,   234,    98,   231,   231,    99,   100,   234,   234,   231,
      11,    12,    13,    14,   101,   236,   236,   236,   236,   236,
      98,   234,   234,   234,    66,   234,   309,   241,    30,   236,
     236,    30,   236,   236,   234,   236,   236,   236,   234,    30,
     236,   236,    30,   236,   236,   234,   237,   237,   234,   234,
     234,   234,   234,   234,   234,   237,    22,    23,    24,    25,
      26,    27,   234,   251,   234,   309,   251,   309,   251,   234,
     234,   275,   237,   277,   234,    11,    12,    13,    14,   236,
     236,   236,   236,   236,   231,   231,   234,   234,   231,   234,
     237,   237,   234,   236,   292,   237,   236,   236,   236,   236,
     236,   231,   231,   231,   231,   230,   234,   234,   237,   237,
     236,   309,   230,   236,   231,   230,   309,   225,   226,   231,
     230,   236,   309,   230,   236,   225,   226,   231,   230,    29,
      30,   100,   209,   255,   255,   234,   237,   237,   237,   237,
     237,   237,   251,   234,    66,   234,    66,   275,    93,   104,
     230,   276,    95,   277,   236,   236,   236,   236,   231,   231,
     231,   231,   230,   237,   237,   292,   292,   237,    99,    99,
     292,   231,    98,    99,   231,   231,   231,   231,   230,   237,
     237,   237,   238,   237,   234,   234,   309,   237,   237,   309,
     237,   237,   237,   238,   238,   237,   237,   309,   237,   237,
     309,   238,   238,   237,   237,    30,   236,   236,   236,   234,
     234,   251,   234,   251,   234,    93,   234,   230,    11,    12,
      13,    14,   101,   234,    95,   231,   231,   231,   231,   237,
     237,   237,   238,   237,   234,   234,    98,    98,   234,   234,
     234,    98,   237,   234,   234,   237,   237,   237,   238,   237,
     201,   202,   234,   234,   201,   202,   234,   231,   234,   237,
     234,   234,   237,   214,   215,   234,   234,   234,   231,   231,
     234,   234,   237,   234,   234,   237,   231,   231,   214,   215,
     234,   234,   236,   309,   231,   230,    66,    66,   234,   251,
      11,    12,    13,    14,   236,   236,   236,   236,   236,   234,
     237,   237,   237,   238,    43,    96,   234,    43,    96,   234,
      43,    96,   234,   231,   234,   292,   292,   234,   234,   292,
     292,   292,   234,   234,   292,   234,   234,   234,   231,   234,
     236,   236,   236,   236,   237,   234,   234,   234,   234,   237,
     237,   234,   234,   237,   237,   234,   234,   309,   237,   237,
     237,   234,   234,   251,    37,    91,   236,   236,   236,   236,
     231,   231,   231,   231,   230,    96,   234,    96,   234,    96,
     234,   231,   236,    43,   234,   236,    43,   234,   236,    43,
     234,   237,    98,    98,    98,    98,    98,    98,   237,   230,
     231,   230,   231,   202,   234,   234,   234,   234,   234,   237,
     234,   234,   234,    37,    91,   234,   234,   231,   231,   231,
     231,   237,   237,   237,   238,   237,   234,   234,   234,   237,
      44,    45,   236,    44,    45,   236,    44,    45,   236,    43,
      96,   234,   234,   234,   234,   234,   234,   234,   234,   237,
     238,   237,   237,   238,   237,   236,   234,   234,   234,   251,
     237,   237,   237,   238,    43,    96,   234,    43,    96,   234,
      43,    96,   234,   231,   234,    96,   234,   238,   237,    44,
     238,   237,    44,   238,   237,    44,   236,    43,   234,   234,
     231,   234,   234,   231,   234,   231,   251,    91,    96,   234,
      96,   234,    96,   234,   231,   236,    43,   234,   236,    43,
     234,   236,    43,   234,   237,   234,    45,   234,   237,    45,
     234,   237,    45,   234,   237,    45,   236,   237,   237,   237,
      91,   234,   234,   234,   234,   237,    44,    45,   236,    44,
      45,   236,    44,    45,   236,    43,    96,   234,   237,   234,
     237,   234,   237,   234,   237,    44,   234,   234,   234,   234,
      96,   234,   238,   237,    44,   238,   237,    44,   238,   237,
      44,   236,    43,   234,   234,   234,   234,   234,   237,   234,
      45,   234,   237,    45,   234,   237,    45,   234,   237,    45,
     236,   234,   237,   234,   237,   234,   237,   234,   237,    44,
     234,   234,   234,   234,   237,   234
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   248,   249,   249,   250,   250,   250,   251,   251,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   253,   253,   253,
     253,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   254,   254,
     254,   254,   254,   254,   254,   254,   254,   254,   255,   255,
     255,   255,   255,   256,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   257,   257,   257,   257,   257,   257,
     257,   257,   257,   257,   258,   258,   259,   260,   260,   261,
     262,   263,   264,   265,   266,   267,   268,   269,   269,   270,
     271,   271,   271,   272,   272,   272,   272,   273,   273,   274,
     274,   274,   274,   274,   275,   275,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   276,   276,   276,   276,   276,   276,
     276,   276,   276,   276,   277,   277,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   288,   289,   289,   290,   290,   291,
     291,   291,   291,   291,   291,   291,   291,   291,   291,   291,
     291,   291,   291,   291,   291,   291,   291,   292,   292,   293,
     293,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   295,   296,
     296,   297,   298,   298,   299,   300,   301,   301,   301,   301,
     302,   303,   304,   304,   305,   306,   306,   307,   308,   309,
     310,   310,   311,   311,   312,   312,   313,   313,   313,   313,
     313,   313,   313,   313,   314,   314,   314,   315,   315,   315,
     316,   316,   317,   317,   318,   318,   319,   319,   319,   319,
     319,   319,   319,   319,   319,   319,   319,   319,   319,   319,
     319,   319,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   320,   320,   320,   320,   320,   320,   320,   320,
     320,   320,   321,   321,   322,   322,   323,   323
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
       3,     4,     6,     4,     4,     5,     5,     9,     7,     3,
       3,     3,     5,     3,     2,     3,     4,     3,     2,     5,
       7,    11,    10,    13,    14,    16,    17,     0,     1,     0,
       4,     4,     4,     6,     0,     2,     6,     7,     6,     7,
       6,     7,     8,     9,     7,     8,     7,     8,     7,     8,
       9,    10,     6,    11,    11,    11,    13,    10,    10,    10,
      12,    12,    12,    12,     0,     2,     6,     7,     6,     7,
       6,     7,     8,     9,     7,     8,     7,     8,     7,     8,
       9,    10,     6,    11,    11,    11,    13,    10,    10,    10,
      12,    12,    12,    12,     8,     6,     3,     3,     3,     3,
       3,     6,     1,     7,     6,     1,     2,     2,     4,     7,
       6,    11,    11,    13,    13,    13,    13,     7,    11,    11,
      13,    13,    10,     8,     8,     7,     4,     0,     2,     1,
       1,     6,     6,     6,     8,     7,     7,     7,     9,    10,
      10,    12,    10,    12,    10,    12,     6,     7,     8,     0,
       2,     4,     0,     3,     6,     6,    10,    12,    10,    12,
       8,     6,     1,     2,     4,     0,     3,     2,     2,     1,
       1,     3,     1,     3,     1,     2,     1,     3,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       1,     3,     1,     2,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     3,     4,     4,     4,     4,     4,     4,
       4,     4,     6,     6,     6,     6,     6,     6,     4,     4,
       4,     4,     3,     3,     4,     4,     4,     4,     4,     4,
       3,     4,     3,     4,     3,     8,     8,     8,     4,     4,
       4,     3,     3,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     3,     1,     8,     8,     8,
       2,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     1,     1,     1,     1,     1,     1,     1,     1,
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
#line 196 "src/parser.y"
                           {
        (yyval.program) = g_program;
    }
#line 3138 "build/parser.cpp"
    break;

  case 3: /* program: statements_opt  */
#line 199 "src/parser.y"
                     {
        (yyval.program) = g_program;
    }
#line 3146 "build/parser.cpp"
    break;

  case 5: /* statements_opt: statements_opt statement  */
#line 206 "src/parser.y"
                               {
        if ((yyvsp[0].stmt)) {
            g_program->statements.emplace_back((yyvsp[0].stmt));
        }
    }
#line 3156 "build/parser.cpp"
    break;

  case 6: /* statements_opt: statements_opt KW_CTLOPT  */
#line 211 "src/parser.y"
                               {
        if (ctlopt_nomain) g_program->nomain = true;
        if (ctlopt_main_proc[0]) g_program->main_proc = ctlopt_main_proc;
        if (ctlopt_datfmt[0]) g_program->datfmt = ctlopt_datfmt;
        if (ctlopt_timfmt[0]) g_program->timfmt = ctlopt_timfmt;
    }
#line 3167 "build/parser.cpp"
    break;

  case 7: /* statement_list: %empty  */
#line 220 "src/parser.y"
                {
        (yyval.stmt_list) = new StmtList();
    }
#line 3175 "build/parser.cpp"
    break;

  case 8: /* statement_list: statement_list statement  */
#line 223 "src/parser.y"
                               {
        (yyval.stmt_list) = (yyvsp[-1].stmt_list);
        if ((yyvsp[0].stmt)) {
            (yyval.stmt_list)->stmts.push_back((yyvsp[0].stmt));
        }
    }
#line 3186 "build/parser.cpp"
    break;

  case 9: /* statement: dcl_f_stmt  */
#line 232 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3192 "build/parser.cpp"
    break;

  case 10: /* statement: dcl_s_stmt  */
#line 233 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3198 "build/parser.cpp"
    break;

  case 11: /* statement: dcl_c_stmt  */
#line 234 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3204 "build/parser.cpp"
    break;

  case 12: /* statement: eval_stmt  */
#line 235 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3210 "build/parser.cpp"
    break;

  case 13: /* statement: eval_corr_stmt  */
#line 236 "src/parser.y"
                     { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3216 "build/parser.cpp"
    break;

  case 14: /* statement: dsply_stmt  */
#line 237 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3222 "build/parser.cpp"
    break;

  case 15: /* statement: inlr_stmt  */
#line 238 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3228 "build/parser.cpp"
    break;

  case 16: /* statement: return_stmt  */
#line 239 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3234 "build/parser.cpp"
    break;

  case 17: /* statement: if_stmt  */
#line 240 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3240 "build/parser.cpp"
    break;

  case 18: /* statement: dow_stmt  */
#line 241 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3246 "build/parser.cpp"
    break;

  case 19: /* statement: dou_stmt  */
#line 242 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3252 "build/parser.cpp"
    break;

  case 20: /* statement: for_stmt  */
#line 243 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3258 "build/parser.cpp"
    break;

  case 21: /* statement: for_each_stmt  */
#line 244 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3264 "build/parser.cpp"
    break;

  case 22: /* statement: select_stmt  */
#line 245 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3270 "build/parser.cpp"
    break;

  case 23: /* statement: iter_stmt  */
#line 246 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3276 "build/parser.cpp"
    break;

  case 24: /* statement: leave_stmt  */
#line 247 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3282 "build/parser.cpp"
    break;

  case 25: /* statement: dcl_proc_stmt  */
#line 248 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3288 "build/parser.cpp"
    break;

  case 26: /* statement: dcl_pr_stmt  */
#line 249 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3294 "build/parser.cpp"
    break;

  case 27: /* statement: dcl_ds_stmt  */
#line 250 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3300 "build/parser.cpp"
    break;

  case 28: /* statement: dcl_enum_stmt  */
#line 251 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3306 "build/parser.cpp"
    break;

  case 29: /* statement: monitor_stmt  */
#line 252 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3312 "build/parser.cpp"
    break;

  case 30: /* statement: begsr_stmt  */
#line 253 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3318 "build/parser.cpp"
    break;

  case 31: /* statement: exsr_stmt  */
#line 254 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3324 "build/parser.cpp"
    break;

  case 32: /* statement: reset_stmt  */
#line 255 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3330 "build/parser.cpp"
    break;

  case 33: /* statement: clear_stmt  */
#line 256 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3336 "build/parser.cpp"
    break;

  case 34: /* statement: sorta_stmt  */
#line 257 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3342 "build/parser.cpp"
    break;

  case 35: /* statement: evalr_stmt  */
#line 258 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3348 "build/parser.cpp"
    break;

  case 36: /* statement: callp_stmt  */
#line 259 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3354 "build/parser.cpp"
    break;

  case 37: /* statement: leavesr_stmt  */
#line 260 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3360 "build/parser.cpp"
    break;

  case 38: /* statement: dealloc_stmt  */
#line 261 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3366 "build/parser.cpp"
    break;

  case 39: /* statement: test_stmt  */
#line 262 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3372 "build/parser.cpp"
    break;

  case 40: /* statement: exec_sql_stmt  */
#line 263 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3378 "build/parser.cpp"
    break;

  case 41: /* statement: xml_into_stmt  */
#line 264 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3384 "build/parser.cpp"
    break;

  case 42: /* statement: in_da_stmt  */
#line 265 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3390 "build/parser.cpp"
    break;

  case 43: /* statement: out_da_stmt  */
#line 266 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3396 "build/parser.cpp"
    break;

  case 44: /* statement: unlock_da_stmt  */
#line 267 "src/parser.y"
                     { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3402 "build/parser.cpp"
    break;

  case 45: /* statement: expr_stmt  */
#line 268 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3408 "build/parser.cpp"
    break;

  case 46: /* statement: error SEMICOLON  */
#line 269 "src/parser.y"
                      { (yyval.stmt) = nullptr; yyerrok; }
#line 3414 "build/parser.cpp"
    break;

  case 47: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_DISK SEMICOLON  */
#line 274 "src/parser.y"
                                          {
        (yyval.stmt) = new rpg::DclF((yyvsp[-2].sval), "DISK");
        free((yyvsp[-2].sval));
    }
#line 3423 "build/parser.cpp"
    break;

  case 48: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_PRINTER SEMICOLON  */
#line 278 "src/parser.y"
                                               {
        (yyval.stmt) = new rpg::DclF((yyvsp[-2].sval), "PRINTER");
        free((yyvsp[-2].sval));
    }
#line 3432 "build/parser.cpp"
    break;

  case 49: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_WORKSTN SEMICOLON  */
#line 282 "src/parser.y"
                                               {
        (yyval.stmt) = new rpg::DclF((yyvsp[-2].sval), "WORKSTN");
        free((yyvsp[-2].sval));
    }
#line 3441 "build/parser.cpp"
    break;

  case 50: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_DISK KW_USAGE LPAREN STAR COLON STAR RPAREN SEMICOLON  */
#line 286 "src/parser.y"
                                                                                   {
        (yyval.stmt) = new rpg::DclF((yyvsp[-8].sval), "DISK");
        free((yyvsp[-8].sval));
    }
#line 3450 "build/parser.cpp"
    break;

  case 51: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 294 "src/parser.y"
                                                                                  {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3460 "build/parser.cpp"
    break;

  case 52: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 299 "src/parser.y"
                                                                                       {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3470 "build/parser.cpp"
    break;

  case 53: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 304 "src/parser.y"
                                                                                   {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::INT10, 0);
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3480 "build/parser.cpp"
    break;

  case 54: /* dcl_s_stmt: KW_DCL_S ident KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 309 "src/parser.y"
                                                                                                            {
        auto* n = new rpg::DclS((yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-8].sval));
    }
#line 3490 "build/parser.cpp"
    break;

  case 55: /* dcl_s_stmt: KW_DCL_S ident KW_ZONED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 314 "src/parser.y"
                                                                                                           {
        auto* n = new rpg::DclS((yyvsp[-8].sval), rpg::RPGType::ZONED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-8].sval));
    }
#line 3500 "build/parser.cpp"
    break;

  case 56: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_CONST KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 319 "src/parser.y"
                                                                                                             {
        (yyval.stmt) = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, true,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-10].sval));
    }
#line 3510 "build/parser.cpp"
    break;

  case 57: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_CONST KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 324 "src/parser.y"
                                                                                                              {
        (yyval.stmt) = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, true,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-10].sval));
    }
#line 3520 "build/parser.cpp"
    break;

  case 58: /* dcl_s_stmt: KW_DCL_S ident KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_CONST KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 329 "src/parser.y"
                                                                                                                                      {
        (yyval.stmt) = new rpg::DclS((yyvsp[-12].sval), rpg::RPGType::PACKED, 0, (yyvsp[-9].ival), (yyvsp[-7].ival), true,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-12].sval));
    }
#line 3530 "build/parser.cpp"
    break;

  case 59: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 334 "src/parser.y"
                                                                                                    {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-9].sval));
    }
#line 3540 "build/parser.cpp"
    break;

  case 60: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 339 "src/parser.y"
                                                                                                     {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-9].sval));
    }
#line 3550 "build/parser.cpp"
    break;

  case 61: /* dcl_s_stmt: KW_DCL_S ident KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 344 "src/parser.y"
                                                                                                                             {
        (yyval.stmt) = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-11].sval));
    }
#line 3560 "build/parser.cpp"
    break;

  case 62: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 349 "src/parser.y"
                                                                                                        {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-9].sval));
    }
#line 3570 "build/parser.cpp"
    break;

  case 63: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_EXPORT KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 355 "src/parser.y"
                                                                                                              {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        n->is_export = true;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3581 "build/parser.cpp"
    break;

  case 64: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_EXPORT KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 361 "src/parser.y"
                                                                                                               {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        n->is_export = true;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3592 "build/parser.cpp"
    break;

  case 65: /* dcl_s_stmt: KW_DCL_S ident KW_IND SEMICOLON  */
#line 367 "src/parser.y"
                                      {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::IND, 0);
        free((yyvsp[-2].sval));
    }
#line 3601 "build/parser.cpp"
    break;

  case 66: /* dcl_s_stmt: KW_DCL_S ident KW_BOOLEAN SEMICOLON  */
#line 371 "src/parser.y"
                                          {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::IND, 0);
        free((yyvsp[-2].sval));
    }
#line 3610 "build/parser.cpp"
    break;

  case 67: /* dcl_s_stmt: KW_DCL_S ident KW_DATE SEMICOLON  */
#line 375 "src/parser.y"
                                       {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::DATE, 0);
        free((yyvsp[-2].sval));
    }
#line 3619 "build/parser.cpp"
    break;

  case 68: /* dcl_s_stmt: KW_DCL_S ident KW_TIME SEMICOLON  */
#line 379 "src/parser.y"
                                       {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::TIME, 0);
        free((yyvsp[-2].sval));
    }
#line 3628 "build/parser.cpp"
    break;

  case 69: /* dcl_s_stmt: KW_DCL_S ident KW_TIMESTAMP SEMICOLON  */
#line 383 "src/parser.y"
                                            {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::TIMESTAMP, 0);
        free((yyvsp[-2].sval));
    }
#line 3637 "build/parser.cpp"
    break;

  case 70: /* dcl_s_stmt: KW_DCL_S ident KW_POINTER SEMICOLON  */
#line 387 "src/parser.y"
                                          {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::POINTER, 0);
        free((yyvsp[-2].sval));
    }
#line 3646 "build/parser.cpp"
    break;

  case 71: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 391 "src/parser.y"
                                                                                                         {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-9].sval));
    }
#line 3655 "build/parser.cpp"
    break;

  case 72: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 395 "src/parser.y"
                                                                                                          {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-9].sval));
    }
#line 3664 "build/parser.cpp"
    break;

  case 73: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 399 "src/parser.y"
                                                                                                             {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-9].sval));
    }
#line 3673 "build/parser.cpp"
    break;

  case 74: /* dcl_s_stmt: KW_DCL_S ident KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 403 "src/parser.y"
                                                                                                                                  {
        (yyval.stmt) = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-11].sval));
    }
#line 3682 "build/parser.cpp"
    break;

  case 75: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN KW_DIM_VAR COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 407 "src/parser.y"
                                                                                                                          {
        auto* node = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-2].ival));
        node->dim_type = 1;
        free((yyvsp[-11].sval));
        (yyval.stmt) = node;
    }
#line 3693 "build/parser.cpp"
    break;

  case 76: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN KW_DIM_AUTO COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 413 "src/parser.y"
                                                                                                                           {
        auto* node = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-2].ival));
        node->dim_type = 2;
        free((yyvsp[-11].sval));
        (yyval.stmt) = node;
    }
#line 3704 "build/parser.cpp"
    break;

  case 77: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN KW_DIM_VAR COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 419 "src/parser.y"
                                                                                                                              {
        auto* node = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::VARCHAR, (yyvsp[-8].ival), 0, 0, false, nullptr, (yyvsp[-2].ival));
        node->dim_type = 1;
        free((yyvsp[-11].sval));
        (yyval.stmt) = node;
    }
#line 3715 "build/parser.cpp"
    break;

  case 78: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN KW_DIM_AUTO COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 425 "src/parser.y"
                                                                                                                               {
        auto* node = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::VARCHAR, (yyvsp[-8].ival), 0, 0, false, nullptr, (yyvsp[-2].ival));
        node->dim_type = 2;
        free((yyvsp[-11].sval));
        (yyval.stmt) = node;
    }
#line 3726 "build/parser.cpp"
    break;

  case 79: /* dcl_s_stmt: KW_DCL_S ident KW_LIKE LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 431 "src/parser.y"
                                                                {
        auto* node = new rpg::DclS((yyvsp[-5].sval), rpg::RPGType::INT10, 0);
        node->like_var = (yyvsp[-2].sval);
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
        (yyval.stmt) = node;
    }
#line 3738 "build/parser.cpp"
    break;

  case 80: /* dcl_s_stmt: KW_DCL_S ident KW_UNS LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 438 "src/parser.y"
                                                                                   {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::UNS, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3748 "build/parser.cpp"
    break;

  case 81: /* dcl_s_stmt: KW_DCL_S ident KW_FLOAT_TYPE LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 443 "src/parser.y"
                                                                                          {
        auto type = ((yyvsp[-3].ival) <= 4) ? rpg::RPGType::FLOAT4 : rpg::RPGType::FLOAT8;
        auto* n = new rpg::DclS((yyvsp[-6].sval), type, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3759 "build/parser.cpp"
    break;

  case 82: /* dcl_s_stmt: KW_DCL_S ident KW_BINDEC LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 449 "src/parser.y"
                                                                                      {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::BINDEC, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3769 "build/parser.cpp"
    break;

  case 83: /* dcl_s_stmt: KW_DCL_S ident KW_UCS2 LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 454 "src/parser.y"
                                                                                    {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::UCS2, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3779 "build/parser.cpp"
    break;

  case 84: /* dcl_s_stmt: KW_DCL_S ident KW_GRAPH LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 459 "src/parser.y"
                                                                                     {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::UCS2, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3789 "build/parser.cpp"
    break;

  case 85: /* dcl_s_stmt: KW_DCL_S ident KW_OBJECT LPAREN KW_JAVA COLON STRING_LITERAL RPAREN SEMICOLON  */
#line 464 "src/parser.y"
                                                                                    {
        auto* n = new rpg::DclS((yyvsp[-7].sval), rpg::RPGType::OBJECT, 0);
        n->java_class = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-7].sval)); free((yyvsp[-2].sval));
    }
#line 3799 "build/parser.cpp"
    break;

  case 86: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_BASED LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 469 "src/parser.y"
                                                                                                      {
        auto* n = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::INT10, 0);
        n->based_ptr = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
    }
#line 3809 "build/parser.cpp"
    break;

  case 87: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_BASED LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 474 "src/parser.y"
                                                                                                       {
        auto* n = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival));
        n->based_ptr = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
    }
#line 3819 "build/parser.cpp"
    break;

  case 88: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_ASCEND SEMICOLON  */
#line 479 "src/parser.y"
                                                                                                                   {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = 1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3829 "build/parser.cpp"
    break;

  case 89: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_DESCEND SEMICOLON  */
#line 484 "src/parser.y"
                                                                                                                    {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = -1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3839 "build/parser.cpp"
    break;

  case 90: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_ASCEND SEMICOLON  */
#line 489 "src/parser.y"
                                                                                                                    {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = 1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3849 "build/parser.cpp"
    break;

  case 91: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_DESCEND SEMICOLON  */
#line 494 "src/parser.y"
                                                                                                                     {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = -1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3859 "build/parser.cpp"
    break;

  case 92: /* dcl_s_stmt: KW_DCL_S ident KW_DATE KW_DATFMT LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 499 "src/parser.y"
                                                                          {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::DATE, 0);
        n->datfmt = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-6].sval)); free((yyvsp[-2].sval));
    }
#line 3869 "build/parser.cpp"
    break;

  case 93: /* dcl_s_stmt: KW_DCL_S ident KW_TIME KW_TIMFMT LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 504 "src/parser.y"
                                                                          {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::TIME, 0);
        n->timfmt = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-6].sval)); free((yyvsp[-2].sval));
    }
#line 3879 "build/parser.cpp"
    break;

  case 94: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_DTAARA LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 509 "src/parser.y"
                                                                                                        {
        auto* n = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival));
        n->dtaara_name = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
    }
#line 3889 "build/parser.cpp"
    break;

  case 95: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_DTAARA LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 514 "src/parser.y"
                                                                                                           {
        auto* n = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival));
        n->dtaara_name = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
    }
#line 3899 "build/parser.cpp"
    break;

  case 96: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DTAARA LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 519 "src/parser.y"
                                                                                                       {
        auto* n = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::INT10, 0);
        n->dtaara_name = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
    }
#line 3909 "build/parser.cpp"
    break;

  case 97: /* dcl_s_stmt: KW_DCL_S ident KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_DTAARA LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 524 "src/parser.y"
                                                                                                                                {
        auto* n = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival));
        n->dtaara_name = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-11].sval)); free((yyvsp[-2].sval));
    }
#line 3919 "build/parser.cpp"
    break;

  case 98: /* dcl_s_keywords: %empty  */
#line 532 "src/parser.y"
                  { (yyval.ival) = 0; }
#line 3925 "build/parser.cpp"
    break;

  case 99: /* dcl_s_keywords: KW_STATIC  */
#line 533 "src/parser.y"
                  { (yyval.ival) = 1; }
#line 3931 "build/parser.cpp"
    break;

  case 100: /* dcl_s_keywords: KW_TEMPLATE  */
#line 534 "src/parser.y"
                  { (yyval.ival) = 2; }
#line 3937 "build/parser.cpp"
    break;

  case 101: /* dcl_s_keywords: KW_EXPORT  */
#line 535 "src/parser.y"
                  { (yyval.ival) = 4; }
#line 3943 "build/parser.cpp"
    break;

  case 102: /* dcl_s_keywords: KW_IMPORT  */
#line 536 "src/parser.y"
                  { (yyval.ival) = 8; }
#line 3949 "build/parser.cpp"
    break;

  case 103: /* dcl_c_stmt: KW_DCL_C IDENTIFIER expression SEMICOLON  */
#line 541 "src/parser.y"
                                             {
        (yyval.stmt) = new rpg::DclC((yyvsp[-2].sval), std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
        free((yyvsp[-2].sval));
    }
#line 3958 "build/parser.cpp"
    break;

  case 104: /* eval_target: IDENTIFIER  */
#line 548 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier((yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 3967 "build/parser.cpp"
    break;

  case 105: /* eval_target: KW_POS  */
#line 552 "src/parser.y"
             { (yyval.expr) = new rpg::Identifier("POS"); }
#line 3973 "build/parser.cpp"
    break;

  case 106: /* eval_target: KW_OVERLAY  */
#line 553 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("OVERLAY"); }
#line 3979 "build/parser.cpp"
    break;

  case 107: /* eval_target: KW_PREFIX  */
#line 554 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("PREFIX"); }
#line 3985 "build/parser.cpp"
    break;

  case 108: /* eval_target: KW_UNS  */
#line 555 "src/parser.y"
             { (yyval.expr) = new rpg::Identifier("UNS"); }
#line 3991 "build/parser.cpp"
    break;

  case 109: /* eval_target: KW_FLOAT_TYPE  */
#line 556 "src/parser.y"
                    { (yyval.expr) = new rpg::Identifier("FLOAT"); }
#line 3997 "build/parser.cpp"
    break;

  case 110: /* eval_target: KW_GRAPH  */
#line 557 "src/parser.y"
               { (yyval.expr) = new rpg::Identifier("GRAPH"); }
#line 4003 "build/parser.cpp"
    break;

  case 111: /* eval_target: KW_ASCEND  */
#line 558 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("ASCEND"); }
#line 4009 "build/parser.cpp"
    break;

  case 112: /* eval_target: KW_DESCEND  */
#line 559 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("DESCEND"); }
#line 4015 "build/parser.cpp"
    break;

  case 113: /* eval_target: KW_RTNPARM  */
#line 560 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("RTNPARM"); }
#line 4021 "build/parser.cpp"
    break;

  case 114: /* eval_target: KW_OPDESC  */
#line 561 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("OPDESC"); }
#line 4027 "build/parser.cpp"
    break;

  case 115: /* eval_target: KW_NULLIND  */
#line 562 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("NULLIND"); }
#line 4033 "build/parser.cpp"
    break;

  case 116: /* eval_target: KW_DATFMT  */
#line 563 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("DATFMT"); }
#line 4039 "build/parser.cpp"
    break;

  case 117: /* eval_target: KW_TIMFMT  */
#line 564 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("TIMFMT"); }
#line 4045 "build/parser.cpp"
    break;

  case 118: /* eval_target: KW_EXTNAME  */
#line 565 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("EXTNAME"); }
#line 4051 "build/parser.cpp"
    break;

  case 119: /* eval_target: INDICATOR  */
#line 566 "src/parser.y"
                {
        (yyval.expr) = new rpg::IndicatorExpr((yyvsp[0].ival));
    }
#line 4059 "build/parser.cpp"
    break;

  case 120: /* eval_target: IDENTIFIER DOT IDENTIFIER  */
#line 569 "src/parser.y"
                                {
        auto obj = std::unique_ptr<rpg::Expression>(new rpg::Identifier((yyvsp[-2].sval)));
        (yyval.expr) = new rpg::DotExpr(std::move(obj), (yyvsp[0].sval));
        free((yyvsp[-2].sval));
        free((yyvsp[0].sval));
    }
#line 4070 "build/parser.cpp"
    break;

  case 121: /* eval_target: IDENTIFIER LPAREN expression RPAREN  */
#line 575 "src/parser.y"
                                          {
        (yyval.expr) = new rpg::ArrayAccess((yyvsp[-3].sval), std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
        free((yyvsp[-3].sval));
    }
#line 4079 "build/parser.cpp"
    break;

  case 122: /* eval_target: IDENTIFIER LPAREN expression RPAREN DOT IDENTIFIER  */
#line 579 "src/parser.y"
                                                         {
        auto* arr = new rpg::ArrayAccess((yyvsp[-5].sval), std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)));
        (yyval.expr) = new rpg::DotExpr(std::unique_ptr<rpg::Expression>(arr), (yyvsp[0].sval));
        free((yyvsp[-5].sval));
        free((yyvsp[0].sval));
    }
#line 4090 "build/parser.cpp"
    break;

  case 123: /* eval_target: BIF_ELEM LPAREN arg_list RPAREN  */
#line 585 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("ELEM", (yyvsp[-1].expr_list));
    }
#line 4098 "build/parser.cpp"
    break;

  case 124: /* eval_stmt: eval_target EQUALS expression SEMICOLON  */
#line 591 "src/parser.y"
                                            {
        (yyval.stmt) = new rpg::EvalStmt(
            std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-1].expr))
        );
    }
#line 4109 "build/parser.cpp"
    break;

  case 125: /* eval_stmt: KW_EVAL eval_target EQUALS expression SEMICOLON  */
#line 597 "src/parser.y"
                                                      {
        (yyval.stmt) = new rpg::EvalStmt(
            std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-1].expr))
        );
    }
#line 4120 "build/parser.cpp"
    break;

  case 126: /* eval_corr_stmt: KW_EVAL_CORR ident EQUALS ident SEMICOLON  */
#line 606 "src/parser.y"
                                              {
        (yyval.stmt) = new rpg::EvalCorrStmt(std::string((yyvsp[-3].sval)), std::string((yyvsp[-1].sval)));
        free((yyvsp[-3].sval));
        free((yyvsp[-1].sval));
    }
#line 4130 "build/parser.cpp"
    break;

  case 127: /* xml_into_stmt: KW_XML_INTO ident BIF_XML LPAREN expression COLON expression RPAREN SEMICOLON  */
#line 614 "src/parser.y"
                                                                                  {
        (yyval.stmt) = new rpg::XmlIntoStmt(std::string((yyvsp[-7].sval)),
            std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-7].sval));
    }
#line 4141 "build/parser.cpp"
    break;

  case 128: /* xml_into_stmt: KW_XML_INTO ident BIF_XML LPAREN expression RPAREN SEMICOLON  */
#line 620 "src/parser.y"
                                                                   {
        (yyval.stmt) = new rpg::XmlIntoStmt(std::string((yyvsp[-5].sval)),
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            nullptr);
        free((yyvsp[-5].sval));
    }
#line 4152 "build/parser.cpp"
    break;

  case 129: /* in_da_stmt: KW_IN IDENTIFIER SEMICOLON  */
#line 629 "src/parser.y"
                               {
        (yyval.stmt) = new rpg::DataInStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4161 "build/parser.cpp"
    break;

  case 130: /* out_da_stmt: KW_OUT IDENTIFIER SEMICOLON  */
#line 636 "src/parser.y"
                                {
        (yyval.stmt) = new rpg::DataOutStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4170 "build/parser.cpp"
    break;

  case 131: /* unlock_da_stmt: KW_UNLOCK IDENTIFIER SEMICOLON  */
#line 643 "src/parser.y"
                                   {
        (yyval.stmt) = new rpg::DataUnlockStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4179 "build/parser.cpp"
    break;

  case 132: /* evalr_stmt: KW_EVALR eval_target EQUALS expression SEMICOLON  */
#line 650 "src/parser.y"
                                                     {
        (yyval.stmt) = new rpg::EvalRStmt(
            std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-1].expr))
        );
    }
#line 4190 "build/parser.cpp"
    break;

  case 133: /* callp_stmt: KW_CALLP expression SEMICOLON  */
#line 659 "src/parser.y"
                                  {
        (yyval.stmt) = new rpg::ExprStmt(std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
    }
#line 4198 "build/parser.cpp"
    break;

  case 134: /* leavesr_stmt: KW_LEAVESR SEMICOLON  */
#line 665 "src/parser.y"
                         {
        (yyval.stmt) = new rpg::LeaveSRStmt();
    }
#line 4206 "build/parser.cpp"
    break;

  case 135: /* dsply_stmt: KW_DSPLY expression SEMICOLON  */
#line 671 "src/parser.y"
                                  {
        (yyval.stmt) = new rpg::DsplyStmt(std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
    }
#line 4214 "build/parser.cpp"
    break;

  case 136: /* inlr_stmt: KW_INLR EQUALS KW_ON SEMICOLON  */
#line 677 "src/parser.y"
                                   {
        (yyval.stmt) = new rpg::ReturnStmt(0);
    }
#line 4222 "build/parser.cpp"
    break;

  case 137: /* return_stmt: KW_RETURN expression SEMICOLON  */
#line 683 "src/parser.y"
                                   {
        (yyval.stmt) = new rpg::ReturnStmt(std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
    }
#line 4230 "build/parser.cpp"
    break;

  case 138: /* return_stmt: KW_RETURN SEMICOLON  */
#line 686 "src/parser.y"
                          {
        (yyval.stmt) = new rpg::ReturnStmt(0);
    }
#line 4238 "build/parser.cpp"
    break;

  case 139: /* expr_stmt: IDENTIFIER LPAREN call_args_opt RPAREN SEMICOLON  */
#line 693 "src/parser.y"
                                                     {
        auto* fc = make_func((yyvsp[-4].sval), (yyvsp[-2].expr_list));
        free((yyvsp[-4].sval));
        (yyval.stmt) = new rpg::ExprStmt(std::unique_ptr<rpg::Expression>(fc));
    }
#line 4248 "build/parser.cpp"
    break;

  case 140: /* dcl_pr_stmt: KW_DCL_PR IDENTIFIER pi_return_type SEMICOLON pr_params KW_END_PR SEMICOLON  */
#line 704 "src/parser.y"
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
#line 4269 "build/parser.cpp"
    break;

  case 141: /* dcl_pr_stmt: KW_DCL_PR IDENTIFIER pi_return_type KW_EXTPROC LPAREN STRING_LITERAL RPAREN SEMICOLON pr_params KW_END_PR SEMICOLON  */
#line 721 "src/parser.y"
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
#line 4293 "build/parser.cpp"
    break;

  case 142: /* dcl_pr_stmt: KW_DCL_PR IDENTIFIER KW_EXTPGM LPAREN STRING_LITERAL RPAREN SEMICOLON pr_params KW_END_PR SEMICOLON  */
#line 741 "src/parser.y"
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
#line 4309 "build/parser.cpp"
    break;

  case 143: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER proc_export SEMICOLON KW_DCL_PI pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 759 "src/parser.y"
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
#line 4334 "build/parser.cpp"
    break;

  case 144: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER proc_export SEMICOLON KW_DCL_PI IDENTIFIER pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 783 "src/parser.y"
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
#line 4360 "build/parser.cpp"
    break;

  case 145: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER proc_export SEMICOLON KW_DCL_PI pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_ON_EXIT SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 809 "src/parser.y"
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
#line 4387 "build/parser.cpp"
    break;

  case 146: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER proc_export SEMICOLON KW_DCL_PI IDENTIFIER pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_ON_EXIT SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 836 "src/parser.y"
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
#line 4415 "build/parser.cpp"
    break;

  case 147: /* proc_export: %empty  */
#line 862 "src/parser.y"
                { (yyval.ival) = 0; }
#line 4421 "build/parser.cpp"
    break;

  case 148: /* proc_export: KW_EXPORT  */
#line 863 "src/parser.y"
                { (yyval.ival) = 1; }
#line 4427 "build/parser.cpp"
    break;

  case 149: /* pi_return_type: %empty  */
#line 868 "src/parser.y"
               { (yyval.ival) = -1; }
#line 4433 "build/parser.cpp"
    break;

  case 150: /* pi_return_type: KW_INT LPAREN INTEGER_LITERAL RPAREN  */
#line 869 "src/parser.y"
                                           { (yyval.ival) = (int)rpg::RPGType::INT10; }
#line 4439 "build/parser.cpp"
    break;

  case 151: /* pi_return_type: KW_CHAR LPAREN INTEGER_LITERAL RPAREN  */
#line 870 "src/parser.y"
                                            { (yyval.ival) = (int)rpg::RPGType::CHAR; }
#line 4445 "build/parser.cpp"
    break;

  case 152: /* pi_return_type: KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN  */
#line 871 "src/parser.y"
                                               { (yyval.ival) = (int)rpg::RPGType::VARCHAR; }
#line 4451 "build/parser.cpp"
    break;

  case 153: /* pi_return_type: KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN  */
#line 872 "src/parser.y"
                                                                    { (yyval.ival) = (int)rpg::RPGType::PACKED; }
#line 4457 "build/parser.cpp"
    break;

  case 154: /* pi_params: %empty  */
#line 877 "src/parser.y"
                {
        (yyval.param_list) = new ParamList();
    }
#line 4465 "build/parser.cpp"
    break;

  case 155: /* pi_params: pi_params pi_param  */
#line 880 "src/parser.y"
                         {
        (yyval.param_list) = (yyvsp[-1].param_list);
        (yyval.param_list)->params.push_back(*(yyvsp[0].param_decl));
        delete (yyvsp[0].param_decl);
    }
#line 4475 "build/parser.cpp"
    break;

  case 156: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 888 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4484 "build/parser.cpp"
    break;

  case 157: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 892 "src/parser.y"
                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4493 "build/parser.cpp"
    break;

  case 158: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 896 "src/parser.y"
                                                                 {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4502 "build/parser.cpp"
    break;

  case 159: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 900 "src/parser.y"
                                                                          {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4511 "build/parser.cpp"
    break;

  case 160: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 904 "src/parser.y"
                                                                    {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4520 "build/parser.cpp"
    break;

  case 161: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 908 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4529 "build/parser.cpp"
    break;

  case 162: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 912 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 4538 "build/parser.cpp"
    break;

  case 163: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 916 "src/parser.y"
                                                                                                  {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 4547 "build/parser.cpp"
    break;

  case 164: /* pi_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 921 "src/parser.y"
                                                                            {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4556 "build/parser.cpp"
    break;

  case 165: /* pi_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 925 "src/parser.y"
                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4565 "build/parser.cpp"
    break;

  case 166: /* pi_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 929 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4574 "build/parser.cpp"
    break;

  case 167: /* pi_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 933 "src/parser.y"
                                                                                      {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4583 "build/parser.cpp"
    break;

  case 168: /* pi_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 937 "src/parser.y"
                                                                                {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4592 "build/parser.cpp"
    break;

  case 169: /* pi_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 941 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4601 "build/parser.cpp"
    break;

  case 170: /* pi_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 945 "src/parser.y"
                                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 4610 "build/parser.cpp"
    break;

  case 171: /* pi_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 949 "src/parser.y"
                                                                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 4619 "build/parser.cpp"
    break;

  case 172: /* pi_param: IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 953 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, 0, 0, 0, false, std::string((yyvsp[-2].sval))};
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
    }
#line 4629 "build/parser.cpp"
    break;

  case 173: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 959 "src/parser.y"
                                                                                                            {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4639 "build/parser.cpp"
    break;

  case 174: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 964 "src/parser.y"
                                                                                                             {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4649 "build/parser.cpp"
    break;

  case 175: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 969 "src/parser.y"
                                                                                                                {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::VARCHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4659 "build/parser.cpp"
    break;

  case 176: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 974 "src/parser.y"
                                                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-12].sval), rpg::RPGType::PACKED, 0, (yyvsp[-9].ival), (yyvsp[-7].ival), true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-12].sval));
    }
#line 4669 "build/parser.cpp"
    break;

  case 177: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 980 "src/parser.y"
                                                                                                 {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4679 "build/parser.cpp"
    break;

  case 178: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 985 "src/parser.y"
                                                                                                  {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4689 "build/parser.cpp"
    break;

  case 179: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 990 "src/parser.y"
                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4699 "build/parser.cpp"
    break;

  case 180: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 995 "src/parser.y"
                                                                                                                          {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4709 "build/parser.cpp"
    break;

  case 181: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 1001 "src/parser.y"
                                                                                                                 {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4719 "build/parser.cpp"
    break;

  case 182: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 1006 "src/parser.y"
                                                                                                                  {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::CHAR, (yyvsp[-8].ival), 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4729 "build/parser.cpp"
    break;

  case 183: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 1011 "src/parser.y"
                                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::VARCHAR, (yyvsp[-8].ival), 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4739 "build/parser.cpp"
    break;

  case 184: /* pr_params: %empty  */
#line 1020 "src/parser.y"
                {
        (yyval.param_list) = new ParamList();
    }
#line 4747 "build/parser.cpp"
    break;

  case 185: /* pr_params: pr_params pr_param  */
#line 1023 "src/parser.y"
                         {
        (yyval.param_list) = (yyvsp[-1].param_list);
        (yyval.param_list)->params.push_back(*(yyvsp[0].param_decl));
        delete (yyvsp[0].param_decl);
    }
#line 4757 "build/parser.cpp"
    break;

  case 186: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1031 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4766 "build/parser.cpp"
    break;

  case 187: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1035 "src/parser.y"
                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4775 "build/parser.cpp"
    break;

  case 188: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1039 "src/parser.y"
                                                                 {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4784 "build/parser.cpp"
    break;

  case 189: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1043 "src/parser.y"
                                                                          {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4793 "build/parser.cpp"
    break;

  case 190: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1047 "src/parser.y"
                                                                    {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4802 "build/parser.cpp"
    break;

  case 191: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1051 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4811 "build/parser.cpp"
    break;

  case 192: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1055 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 4820 "build/parser.cpp"
    break;

  case 193: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1059 "src/parser.y"
                                                                                                  {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 4829 "build/parser.cpp"
    break;

  case 194: /* pr_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1064 "src/parser.y"
                                                                            {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4838 "build/parser.cpp"
    break;

  case 195: /* pr_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1068 "src/parser.y"
                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4847 "build/parser.cpp"
    break;

  case 196: /* pr_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1072 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4856 "build/parser.cpp"
    break;

  case 197: /* pr_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1076 "src/parser.y"
                                                                                      {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4865 "build/parser.cpp"
    break;

  case 198: /* pr_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1080 "src/parser.y"
                                                                                {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4874 "build/parser.cpp"
    break;

  case 199: /* pr_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1084 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4883 "build/parser.cpp"
    break;

  case 200: /* pr_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1088 "src/parser.y"
                                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 4892 "build/parser.cpp"
    break;

  case 201: /* pr_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1092 "src/parser.y"
                                                                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 4901 "build/parser.cpp"
    break;

  case 202: /* pr_param: IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1096 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, 0, 0, 0, false, std::string((yyvsp[-2].sval))};
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
    }
#line 4911 "build/parser.cpp"
    break;

  case 203: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1102 "src/parser.y"
                                                                                                            {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4921 "build/parser.cpp"
    break;

  case 204: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1107 "src/parser.y"
                                                                                                             {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4931 "build/parser.cpp"
    break;

  case 205: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1112 "src/parser.y"
                                                                                                                {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::VARCHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4941 "build/parser.cpp"
    break;

  case 206: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1117 "src/parser.y"
                                                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-12].sval), rpg::RPGType::PACKED, 0, (yyvsp[-9].ival), (yyvsp[-7].ival), true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-12].sval));
    }
#line 4951 "build/parser.cpp"
    break;

  case 207: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1123 "src/parser.y"
                                                                                                 {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4961 "build/parser.cpp"
    break;

  case 208: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1128 "src/parser.y"
                                                                                                  {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4971 "build/parser.cpp"
    break;

  case 209: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1133 "src/parser.y"
                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4981 "build/parser.cpp"
    break;

  case 210: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1138 "src/parser.y"
                                                                                                                          {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4991 "build/parser.cpp"
    break;

  case 211: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 1144 "src/parser.y"
                                                                                                                 {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 5001 "build/parser.cpp"
    break;

  case 212: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 1149 "src/parser.y"
                                                                                                                  {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::CHAR, (yyvsp[-8].ival), 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 5011 "build/parser.cpp"
    break;

  case 213: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 1154 "src/parser.y"
                                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::VARCHAR, (yyvsp[-8].ival), 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 5021 "build/parser.cpp"
    break;

  case 214: /* monitor_stmt: KW_MONITOR SEMICOLON statement_list KW_ON_ERROR SEMICOLON statement_list KW_ENDMON SEMICOLON  */
#line 1164 "src/parser.y"
                                                                                                 {
        auto* node = new rpg::MonitorStmt();
        for (auto* s : (yyvsp[-5].stmt_list)->stmts) node->try_body.emplace_back(s);
        delete (yyvsp[-5].stmt_list);
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->on_error_body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        (yyval.stmt) = node;
    }
#line 5034 "build/parser.cpp"
    break;

  case 215: /* begsr_stmt: KW_BEGSR IDENTIFIER SEMICOLON statement_list KW_ENDSR SEMICOLON  */
#line 1175 "src/parser.y"
                                                                    {
        auto* node = new rpg::BegSR((yyvsp[-4].sval));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        free((yyvsp[-4].sval));
        (yyval.stmt) = node;
    }
#line 5046 "build/parser.cpp"
    break;

  case 216: /* exsr_stmt: KW_EXSR ident SEMICOLON  */
#line 1185 "src/parser.y"
                            {
        (yyval.stmt) = new rpg::ExSR((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 5055 "build/parser.cpp"
    break;

  case 217: /* sorta_stmt: KW_SORTA ident SEMICOLON  */
#line 1193 "src/parser.y"
                             {
        (yyval.stmt) = new rpg::SortAStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 5064 "build/parser.cpp"
    break;

  case 218: /* reset_stmt: KW_RESET ident SEMICOLON  */
#line 1201 "src/parser.y"
                             {
        (yyval.stmt) = new rpg::ResetStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 5073 "build/parser.cpp"
    break;

  case 219: /* clear_stmt: KW_CLEAR ident SEMICOLON  */
#line 1208 "src/parser.y"
                             {
        (yyval.stmt) = new rpg::ClearStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 5082 "build/parser.cpp"
    break;

  case 220: /* dealloc_stmt: KW_DEALLOC ident SEMICOLON  */
#line 1216 "src/parser.y"
                               {
        (yyval.stmt) = new rpg::DeallocStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 5091 "build/parser.cpp"
    break;

  case 221: /* test_stmt: KW_TEST LPAREN ident RPAREN ident SEMICOLON  */
#line 1224 "src/parser.y"
                                                {
        char type = toupper((yyvsp[-3].sval)[0]);
        (yyval.stmt) = new rpg::TestStmt(type, std::string((yyvsp[-1].sval)));
        free((yyvsp[-3].sval));
        free((yyvsp[-1].sval));
    }
#line 5102 "build/parser.cpp"
    break;

  case 222: /* exec_sql_stmt: EXEC_SQL_TEXT  */
#line 1235 "src/parser.y"
                  {
        rpg::SqlStmtKind kind = rpg::classifySqlStmt((yyvsp[0].sval));
        (yyval.stmt) = new rpg::ExecSqlStmt(std::string((yyvsp[0].sval)), kind);
        free((yyvsp[0].sval));
    }
#line 5112 "build/parser.cpp"
    break;

  case 223: /* dcl_enum_stmt: KW_DCL_ENUM IDENTIFIER KW_QUALIFIED SEMICOLON enum_constants KW_END_ENUM SEMICOLON  */
#line 1245 "src/parser.y"
                                                                                       {
        auto* e = new rpg::DclEnum((yyvsp[-5].sval));
        e->qualified = true;
        e->constants = std::move(*(yyvsp[-2].enum_const_list));
        delete (yyvsp[-2].enum_const_list);
        free((yyvsp[-5].sval));
        (yyval.stmt) = e;
    }
#line 5125 "build/parser.cpp"
    break;

  case 224: /* dcl_enum_stmt: KW_DCL_ENUM IDENTIFIER SEMICOLON enum_constants KW_END_ENUM SEMICOLON  */
#line 1253 "src/parser.y"
                                                                            {
        auto* e = new rpg::DclEnum((yyvsp[-4].sval));
        e->qualified = false;
        e->constants = std::move(*(yyvsp[-2].enum_const_list));
        delete (yyvsp[-2].enum_const_list);
        free((yyvsp[-4].sval));
        (yyval.stmt) = e;
    }
#line 5138 "build/parser.cpp"
    break;

  case 225: /* enum_constants: enum_constant  */
#line 1264 "src/parser.y"
                  {
        (yyval.enum_const_list) = (yyvsp[0].enum_const_list);
    }
#line 5146 "build/parser.cpp"
    break;

  case 226: /* enum_constants: enum_constants enum_constant  */
#line 1267 "src/parser.y"
                                   {
        (yyvsp[-1].enum_const_list)->insert((yyvsp[-1].enum_const_list)->end(), std::make_move_iterator((yyvsp[0].enum_const_list)->begin()), std::make_move_iterator((yyvsp[0].enum_const_list)->end()));
        delete (yyvsp[0].enum_const_list);
        (yyval.enum_const_list) = (yyvsp[-1].enum_const_list);
    }
#line 5156 "build/parser.cpp"
    break;

  case 227: /* enum_constant: IDENTIFIER SEMICOLON  */
#line 1275 "src/parser.y"
                         {
        auto* v = new std::vector<rpg::EnumConstant>();
        rpg::EnumConstant ec;
        ec.name = (yyvsp[-1].sval);
        free((yyvsp[-1].sval));
        v->push_back(std::move(ec));
        (yyval.enum_const_list) = v;
    }
#line 5169 "build/parser.cpp"
    break;

  case 228: /* enum_constant: IDENTIFIER EQUALS expression SEMICOLON  */
#line 1283 "src/parser.y"
                                             {
        auto* v = new std::vector<rpg::EnumConstant>();
        rpg::EnumConstant ec;
        ec.name = (yyvsp[-3].sval);
        ec.value.reset((yyvsp[-1].expr));
        free((yyvsp[-3].sval));
        v->push_back(std::move(ec));
        (yyval.enum_const_list) = v;
    }
#line 5183 "build/parser.cpp"
    break;

  case 229: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1298 "src/parser.y"
                                                                              {
        auto* ds = new rpg::DclDS((yyvsp[-5].sval));
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-5].sval));
        (yyval.stmt) = ds;
    }
#line 5196 "build/parser.cpp"
    break;

  case 230: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1307 "src/parser.y"
                                                                   {
        auto* ds = new rpg::DclDS((yyvsp[-4].sval));
        ds->qualified = false;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-4].sval));
        (yyval.stmt) = ds;
    }
#line 5209 "build/parser.cpp"
    break;

  case 231: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1316 "src/parser.y"
                                                                                                                     {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->dim = (yyvsp[-6].ival);
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-9].sval));
        (yyval.stmt) = ds;
    }
#line 5223 "build/parser.cpp"
    break;

  case 232: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1326 "src/parser.y"
                                                                                                                     {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->dim = (yyvsp[-5].ival);
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-9].sval));
        (yyval.stmt) = ds;
    }
#line 5237 "build/parser.cpp"
    break;

  case 233: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_DIM LPAREN KW_DIM_VAR COLON INTEGER_LITERAL RPAREN KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1336 "src/parser.y"
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
#line 5252 "build/parser.cpp"
    break;

  case 234: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_DIM LPAREN KW_DIM_VAR COLON INTEGER_LITERAL RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1347 "src/parser.y"
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
#line 5267 "build/parser.cpp"
    break;

  case 235: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_DIM LPAREN KW_DIM_AUTO COLON INTEGER_LITERAL RPAREN KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1358 "src/parser.y"
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
#line 5282 "build/parser.cpp"
    break;

  case 236: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_DIM LPAREN KW_DIM_AUTO COLON INTEGER_LITERAL RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1369 "src/parser.y"
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
#line 5297 "build/parser.cpp"
    break;

  case 237: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1380 "src/parser.y"
                                                                        {
        auto* ds = new rpg::DclDS((yyvsp[-5].sval));
        ds->like_ds = (yyvsp[-2].sval);
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
        (yyval.stmt) = ds;
    }
#line 5309 "build/parser.cpp"
    break;

  case 238: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1388 "src/parser.y"
                                                                                                             {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->like_ds = (yyvsp[-6].sval);
        ds->dim = (yyvsp[-2].ival);
        free((yyvsp[-9].sval));
        free((yyvsp[-6].sval));
        (yyval.stmt) = ds;
    }
#line 5322 "build/parser.cpp"
    break;

  case 239: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_PREFIX LPAREN IDENTIFIER RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1397 "src/parser.y"
                                                                                                                   {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->qualified = true;
        ds->prefix = (yyvsp[-5].sval);
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-9].sval)); free((yyvsp[-5].sval));
        (yyval.stmt) = ds;
    }
#line 5336 "build/parser.cpp"
    break;

  case 240: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_PREFIX LPAREN IDENTIFIER COLON INTEGER_LITERAL RPAREN KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1407 "src/parser.y"
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
#line 5351 "build/parser.cpp"
    break;

  case 241: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_PREFIX LPAREN IDENTIFIER COLON INTEGER_LITERAL RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1418 "src/parser.y"
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
#line 5366 "build/parser.cpp"
    break;

  case 242: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_PREFIX LPAREN IDENTIFIER RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1429 "src/parser.y"
                                                                                                      {
        auto* ds = new rpg::DclDS((yyvsp[-8].sval));
        ds->qualified = false;
        ds->prefix = (yyvsp[-5].sval);
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-8].sval)); free((yyvsp[-5].sval));
        (yyval.stmt) = ds;
    }
#line 5380 "build/parser.cpp"
    break;

  case 243: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER psds_kw KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1439 "src/parser.y"
                                                                                        {
        auto* ds = new rpg::DclDS((yyvsp[-6].sval));
        ds->is_psds = true;
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-6].sval));
        (yyval.stmt) = ds;
    }
#line 5394 "build/parser.cpp"
    break;

  case 244: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED psds_kw SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1449 "src/parser.y"
                                                                                        {
        auto* ds = new rpg::DclDS((yyvsp[-6].sval));
        ds->is_psds = true;
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-6].sval));
        (yyval.stmt) = ds;
    }
#line 5408 "build/parser.cpp"
    break;

  case 245: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER psds_kw SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1459 "src/parser.y"
                                                                           {
        auto* ds = new rpg::DclDS((yyvsp[-5].sval));
        ds->is_psds = true;
        ds->qualified = false;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-5].sval));
        (yyval.stmt) = ds;
    }
#line 5422 "build/parser.cpp"
    break;

  case 246: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER psds_kw SEMICOLON  */
#line 1469 "src/parser.y"
                                             {
        auto* ds = new rpg::DclDS((yyvsp[-2].sval));
        ds->is_psds = true;
        ds->qualified = false;
        free((yyvsp[-2].sval));
        (yyval.stmt) = ds;
    }
#line 5434 "build/parser.cpp"
    break;

  case 247: /* ds_fields: %empty  */
#line 1479 "src/parser.y"
                {
        (yyval.ds_field_list) = new DSFieldList();
    }
#line 5442 "build/parser.cpp"
    break;

  case 248: /* ds_fields: ds_fields ds_field  */
#line 1482 "src/parser.y"
                         {
        (yyval.ds_field_list) = (yyvsp[-1].ds_field_list);
        (yyval.ds_field_list)->fields.push_back(*(yyvsp[0].ds_field));
        delete (yyvsp[0].ds_field);
    }
#line 5452 "build/parser.cpp"
    break;

  case 249: /* psds_kw: KW_PSDS  */
#line 1490 "src/parser.y"
            {}
#line 5458 "build/parser.cpp"
    break;

  case 250: /* psds_kw: KW_SDS  */
#line 1491 "src/parser.y"
             {}
#line 5464 "build/parser.cpp"
    break;

  case 251: /* ds_field: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1495 "src/parser.y"
                                                              {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5473 "build/parser.cpp"
    break;

  case 252: /* ds_field: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1499 "src/parser.y"
                                                                 {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5482 "build/parser.cpp"
    break;

  case 253: /* ds_field: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1503 "src/parser.y"
                                                                    {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5491 "build/parser.cpp"
    break;

  case 254: /* ds_field: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1507 "src/parser.y"
                                                                                         {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival)};
        free((yyvsp[-7].sval));
    }
#line 5500 "build/parser.cpp"
    break;

  case 255: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1512 "src/parser.y"
                                                                            {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5509 "build/parser.cpp"
    break;

  case 256: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1516 "src/parser.y"
                                                                             {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5518 "build/parser.cpp"
    break;

  case 257: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1520 "src/parser.y"
                                                                                {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5527 "build/parser.cpp"
    break;

  case 258: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1524 "src/parser.y"
                                                                                                     {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival)};
        free((yyvsp[-7].sval));
    }
#line 5536 "build/parser.cpp"
    break;

  case 259: /* ds_field: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_POS LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1529 "src/parser.y"
                                                                                                      {
        auto* f = new rpg::DSField{(yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0};
        f->pos = (yyvsp[-2].ival);
        free((yyvsp[-9].sval));
        (yyval.ds_field) = f;
    }
#line 5547 "build/parser.cpp"
    break;

  case 260: /* ds_field: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_POS LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1535 "src/parser.y"
                                                                                                     {
        auto* f = new rpg::DSField{(yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0};
        f->pos = (yyvsp[-2].ival);
        free((yyvsp[-9].sval));
        (yyval.ds_field) = f;
    }
#line 5558 "build/parser.cpp"
    break;

  case 261: /* ds_field: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_POS LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1541 "src/parser.y"
                                                                                                                              {
        auto* f = new rpg::DSField{(yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival)};
        f->pos = (yyvsp[-2].ival);
        free((yyvsp[-11].sval));
        (yyval.ds_field) = f;
    }
#line 5569 "build/parser.cpp"
    break;

  case 262: /* ds_field: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OVERLAY LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1548 "src/parser.y"
                                                                                                     {
        auto* f = new rpg::DSField{(yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0};
        f->overlay_field = (yyvsp[-2].sval);
        free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
        (yyval.ds_field) = f;
    }
#line 5580 "build/parser.cpp"
    break;

  case 263: /* ds_field: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OVERLAY LPAREN IDENTIFIER COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1555 "src/parser.y"
                                                                                                                           {
        auto* f = new rpg::DSField{(yyvsp[-11].sval), rpg::RPGType::CHAR, (yyvsp[-8].ival), 0, 0};
        f->overlay_field = (yyvsp[-4].sval);
        f->overlay_pos = (yyvsp[-2].ival);
        free((yyvsp[-11].sval)); free((yyvsp[-4].sval));
        (yyval.ds_field) = f;
    }
#line 5592 "build/parser.cpp"
    break;

  case 264: /* ds_field: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OVERLAY LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1562 "src/parser.y"
                                                                                                    {
        auto* f = new rpg::DSField{(yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0};
        f->overlay_field = (yyvsp[-2].sval);
        free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
        (yyval.ds_field) = f;
    }
#line 5603 "build/parser.cpp"
    break;

  case 265: /* ds_field: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OVERLAY LPAREN IDENTIFIER COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1568 "src/parser.y"
                                                                                                                          {
        auto* f = new rpg::DSField{(yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0};
        f->overlay_field = (yyvsp[-4].sval);
        f->overlay_pos = (yyvsp[-2].ival);
        free((yyvsp[-11].sval)); free((yyvsp[-4].sval));
        (yyval.ds_field) = f;
    }
#line 5615 "build/parser.cpp"
    break;

  case 266: /* ds_field: IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1576 "src/parser.y"
                                                              {
        auto* f = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::CHAR, 0, 0, 0};
        f->likeds = (yyvsp[-2].sval);
        free((yyvsp[-5].sval)); free((yyvsp[-2].sval));
        (yyval.ds_field) = f;
    }
#line 5626 "build/parser.cpp"
    break;

  case 267: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1582 "src/parser.y"
                                                                          {
        auto* f = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::CHAR, 0, 0, 0};
        f->likeds = (yyvsp[-2].sval);
        free((yyvsp[-5].sval)); free((yyvsp[-2].sval));
        (yyval.ds_field) = f;
    }
#line 5637 "build/parser.cpp"
    break;

  case 268: /* if_stmt: KW_IF expression SEMICOLON statement_list elseif_clauses else_clause KW_ENDIF SEMICOLON  */
#line 1593 "src/parser.y"
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
#line 5662 "build/parser.cpp"
    break;

  case 269: /* elseif_clauses: %empty  */
#line 1616 "src/parser.y"
                { (yyval.elseif_list) = nullptr; }
#line 5668 "build/parser.cpp"
    break;

  case 270: /* elseif_clauses: elseif_clauses elseif_clause  */
#line 1617 "src/parser.y"
                                   {
        if (!(yyvsp[-1].elseif_list)) (yyvsp[-1].elseif_list) = new std::vector<ElseIfData*>();
        (yyval.elseif_list) = (yyvsp[-1].elseif_list);
        (yyval.elseif_list)->push_back((yyvsp[0].elseif_data));
    }
#line 5678 "build/parser.cpp"
    break;

  case 271: /* elseif_clause: KW_ELSEIF expression SEMICOLON statement_list  */
#line 1625 "src/parser.y"
                                                  {
        (yyval.elseif_data) = new ElseIfData();
        (yyval.elseif_data)->cond = (yyvsp[-2].expr);
        (yyval.elseif_data)->body = std::move((yyvsp[0].stmt_list)->stmts);
        delete (yyvsp[0].stmt_list);
    }
#line 5689 "build/parser.cpp"
    break;

  case 272: /* else_clause: %empty  */
#line 1634 "src/parser.y"
                { (yyval.stmt_list) = nullptr; }
#line 5695 "build/parser.cpp"
    break;

  case 273: /* else_clause: KW_ELSE SEMICOLON statement_list  */
#line 1635 "src/parser.y"
                                       {
        (yyval.stmt_list) = (yyvsp[0].stmt_list);
    }
#line 5703 "build/parser.cpp"
    break;

  case 274: /* dow_stmt: KW_DOW expression SEMICOLON statement_list KW_ENDDO SEMICOLON  */
#line 1641 "src/parser.y"
                                                                  {
        auto* node = new rpg::DowStmt(std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        (yyval.stmt) = node;
    }
#line 5714 "build/parser.cpp"
    break;

  case 275: /* dou_stmt: KW_DOU expression SEMICOLON statement_list KW_ENDDO SEMICOLON  */
#line 1650 "src/parser.y"
                                                                  {
        auto* node = new rpg::DouStmt(std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        (yyval.stmt) = node;
    }
#line 5725 "build/parser.cpp"
    break;

  case 276: /* for_stmt: KW_FOR ident EQUALS expression KW_TO expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1659 "src/parser.y"
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
#line 5740 "build/parser.cpp"
    break;

  case 277: /* for_stmt: KW_FOR ident EQUALS expression KW_TO expression KW_BY expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1669 "src/parser.y"
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
#line 5755 "build/parser.cpp"
    break;

  case 278: /* for_stmt: KW_FOR ident EQUALS expression KW_DOWNTO expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1679 "src/parser.y"
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
#line 5770 "build/parser.cpp"
    break;

  case 279: /* for_stmt: KW_FOR ident EQUALS expression KW_DOWNTO expression KW_BY expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1689 "src/parser.y"
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
#line 5785 "build/parser.cpp"
    break;

  case 280: /* for_each_stmt: KW_FOR_EACH ident KW_IN expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1702 "src/parser.y"
                                                                                    {
        auto* node = new rpg::ForEachStmt((yyvsp[-6].sval), std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        free((yyvsp[-6].sval));
        (yyval.stmt) = node;
    }
#line 5797 "build/parser.cpp"
    break;

  case 281: /* select_stmt: KW_SELECT SEMICOLON when_clauses other_clause KW_ENDSL SEMICOLON  */
#line 1712 "src/parser.y"
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
#line 5818 "build/parser.cpp"
    break;

  case 282: /* when_clauses: when_clause  */
#line 1731 "src/parser.y"
                {
        (yyval.when_list) = new std::vector<WhenData*>();
        (yyval.when_list)->push_back((yyvsp[0].when_data));
    }
#line 5827 "build/parser.cpp"
    break;

  case 283: /* when_clauses: when_clauses when_clause  */
#line 1735 "src/parser.y"
                               {
        (yyval.when_list) = (yyvsp[-1].when_list);
        (yyval.when_list)->push_back((yyvsp[0].when_data));
    }
#line 5836 "build/parser.cpp"
    break;

  case 284: /* when_clause: KW_WHEN expression SEMICOLON statement_list  */
#line 1742 "src/parser.y"
                                                {
        (yyval.when_data) = new WhenData();
        (yyval.when_data)->cond = (yyvsp[-2].expr);
        (yyval.when_data)->body = std::move((yyvsp[0].stmt_list)->stmts);
        delete (yyvsp[0].stmt_list);
    }
#line 5847 "build/parser.cpp"
    break;

  case 285: /* other_clause: %empty  */
#line 1751 "src/parser.y"
                { (yyval.stmt_list) = nullptr; }
#line 5853 "build/parser.cpp"
    break;

  case 286: /* other_clause: KW_OTHER SEMICOLON statement_list  */
#line 1752 "src/parser.y"
                                        {
        (yyval.stmt_list) = (yyvsp[0].stmt_list);
    }
#line 5861 "build/parser.cpp"
    break;

  case 287: /* iter_stmt: KW_ITER SEMICOLON  */
#line 1758 "src/parser.y"
                      { (yyval.stmt) = new rpg::IterStmt(); }
#line 5867 "build/parser.cpp"
    break;

  case 288: /* leave_stmt: KW_LEAVE SEMICOLON  */
#line 1762 "src/parser.y"
                       { (yyval.stmt) = new rpg::LeaveStmt(); }
#line 5873 "build/parser.cpp"
    break;

  case 289: /* expression: or_expr  */
#line 1768 "src/parser.y"
            { (yyval.expr) = (yyvsp[0].expr); }
#line 5879 "build/parser.cpp"
    break;

  case 290: /* or_expr: and_expr  */
#line 1772 "src/parser.y"
             { (yyval.expr) = (yyvsp[0].expr); }
#line 5885 "build/parser.cpp"
    break;

  case 291: /* or_expr: or_expr KW_OR and_expr  */
#line 1773 "src/parser.y"
                             {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::OR,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5895 "build/parser.cpp"
    break;

  case 292: /* and_expr: not_expr  */
#line 1781 "src/parser.y"
             { (yyval.expr) = (yyvsp[0].expr); }
#line 5901 "build/parser.cpp"
    break;

  case 293: /* and_expr: and_expr KW_AND not_expr  */
#line 1782 "src/parser.y"
                               {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::AND,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5911 "build/parser.cpp"
    break;

  case 294: /* not_expr: comparison_expr  */
#line 1790 "src/parser.y"
                    { (yyval.expr) = (yyvsp[0].expr); }
#line 5917 "build/parser.cpp"
    break;

  case 295: /* not_expr: KW_NOT comparison_expr  */
#line 1791 "src/parser.y"
                             {
        (yyval.expr) = new rpg::NotExpr(std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5925 "build/parser.cpp"
    break;

  case 296: /* comparison_expr: additive_expr  */
#line 1797 "src/parser.y"
                  { (yyval.expr) = (yyvsp[0].expr); }
#line 5931 "build/parser.cpp"
    break;

  case 297: /* comparison_expr: comparison_expr EQUALS additive_expr  */
#line 1798 "src/parser.y"
                                           {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::EQ,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5941 "build/parser.cpp"
    break;

  case 298: /* comparison_expr: comparison_expr NE additive_expr  */
#line 1803 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::NE,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5951 "build/parser.cpp"
    break;

  case 299: /* comparison_expr: comparison_expr LT additive_expr  */
#line 1808 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::LT,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5961 "build/parser.cpp"
    break;

  case 300: /* comparison_expr: comparison_expr GT additive_expr  */
#line 1813 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::GT,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5971 "build/parser.cpp"
    break;

  case 301: /* comparison_expr: comparison_expr LE additive_expr  */
#line 1818 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::LE,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5981 "build/parser.cpp"
    break;

  case 302: /* comparison_expr: comparison_expr GE additive_expr  */
#line 1823 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::GE,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5991 "build/parser.cpp"
    break;

  case 303: /* comparison_expr: additive_expr KW_IN additive_expr  */
#line 1828 "src/parser.y"
                                        {
        (yyval.expr) = new rpg::InExpr(
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6001 "build/parser.cpp"
    break;

  case 304: /* additive_expr: multiplicative_expr  */
#line 1836 "src/parser.y"
                        { (yyval.expr) = (yyvsp[0].expr); }
#line 6007 "build/parser.cpp"
    break;

  case 305: /* additive_expr: additive_expr PLUS multiplicative_expr  */
#line 1837 "src/parser.y"
                                             {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::ADD,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6017 "build/parser.cpp"
    break;

  case 306: /* additive_expr: additive_expr MINUS multiplicative_expr  */
#line 1842 "src/parser.y"
                                              {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::SUB,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6027 "build/parser.cpp"
    break;

  case 307: /* multiplicative_expr: power_expr  */
#line 1850 "src/parser.y"
               { (yyval.expr) = (yyvsp[0].expr); }
#line 6033 "build/parser.cpp"
    break;

  case 308: /* multiplicative_expr: multiplicative_expr STAR power_expr  */
#line 1851 "src/parser.y"
                                          {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::MUL,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6043 "build/parser.cpp"
    break;

  case 309: /* multiplicative_expr: multiplicative_expr SLASH power_expr  */
#line 1856 "src/parser.y"
                                           {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::DIV,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6053 "build/parser.cpp"
    break;

  case 310: /* power_expr: unary_expr  */
#line 1864 "src/parser.y"
               { (yyval.expr) = (yyvsp[0].expr); }
#line 6059 "build/parser.cpp"
    break;

  case 311: /* power_expr: unary_expr POWER power_expr  */
#line 1865 "src/parser.y"
                                  {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::POWER,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6069 "build/parser.cpp"
    break;

  case 312: /* unary_expr: postfix_expr  */
#line 1873 "src/parser.y"
                 { (yyval.expr) = (yyvsp[0].expr); }
#line 6075 "build/parser.cpp"
    break;

  case 313: /* unary_expr: MINUS postfix_expr  */
#line 1874 "src/parser.y"
                         {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::SUB,
            std::unique_ptr<rpg::Expression>(new rpg::IntLiteral(0)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 6085 "build/parser.cpp"
    break;

  case 314: /* postfix_expr: primary_expr  */
#line 1882 "src/parser.y"
                 { (yyval.expr) = (yyvsp[0].expr); }
#line 6091 "build/parser.cpp"
    break;

  case 315: /* postfix_expr: postfix_expr DOT IDENTIFIER  */
#line 1883 "src/parser.y"
                                  {
        (yyval.expr) = new rpg::DotExpr(std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)), (yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 6100 "build/parser.cpp"
    break;

  case 316: /* ident: IDENTIFIER  */
#line 1890 "src/parser.y"
               { (yyval.sval) = (yyvsp[0].sval); }
#line 6106 "build/parser.cpp"
    break;

  case 317: /* ident: KW_UNS  */
#line 1891 "src/parser.y"
             { (yyval.sval) = strdup("UNS"); }
#line 6112 "build/parser.cpp"
    break;

  case 318: /* ident: KW_FLOAT_TYPE  */
#line 1892 "src/parser.y"
                    { (yyval.sval) = strdup("FLOAT"); }
#line 6118 "build/parser.cpp"
    break;

  case 319: /* ident: KW_GRAPH  */
#line 1893 "src/parser.y"
               { (yyval.sval) = strdup("GRAPH"); }
#line 6124 "build/parser.cpp"
    break;

  case 320: /* ident: KW_ASCEND  */
#line 1894 "src/parser.y"
                { (yyval.sval) = strdup("ASCEND"); }
#line 6130 "build/parser.cpp"
    break;

  case 321: /* ident: KW_DESCEND  */
#line 1895 "src/parser.y"
                 { (yyval.sval) = strdup("DESCEND"); }
#line 6136 "build/parser.cpp"
    break;

  case 322: /* ident: KW_IN  */
#line 1896 "src/parser.y"
            { (yyval.sval) = strdup("IN"); }
#line 6142 "build/parser.cpp"
    break;

  case 323: /* ident: KW_RTNPARM  */
#line 1897 "src/parser.y"
                 { (yyval.sval) = strdup("RTNPARM"); }
#line 6148 "build/parser.cpp"
    break;

  case 324: /* ident: KW_OPDESC  */
#line 1898 "src/parser.y"
                { (yyval.sval) = strdup("OPDESC"); }
#line 6154 "build/parser.cpp"
    break;

  case 325: /* ident: KW_NULLIND  */
#line 1899 "src/parser.y"
                 { (yyval.sval) = strdup("NULLIND"); }
#line 6160 "build/parser.cpp"
    break;

  case 326: /* ident: KW_DATFMT  */
#line 1900 "src/parser.y"
                { (yyval.sval) = strdup("DATFMT"); }
#line 6166 "build/parser.cpp"
    break;

  case 327: /* ident: KW_TIMFMT  */
#line 1901 "src/parser.y"
                { (yyval.sval) = strdup("TIMFMT"); }
#line 6172 "build/parser.cpp"
    break;

  case 328: /* ident: KW_EXTNAME  */
#line 1902 "src/parser.y"
                 { (yyval.sval) = strdup("EXTNAME"); }
#line 6178 "build/parser.cpp"
    break;

  case 329: /* ident: KW_OVERLAY  */
#line 1903 "src/parser.y"
                 { (yyval.sval) = strdup("OVERLAY"); }
#line 6184 "build/parser.cpp"
    break;

  case 330: /* ident: KW_POS  */
#line 1904 "src/parser.y"
             { (yyval.sval) = strdup("POS"); }
#line 6190 "build/parser.cpp"
    break;

  case 331: /* ident: KW_PREFIX  */
#line 1905 "src/parser.y"
                { (yyval.sval) = strdup("PREFIX"); }
#line 6196 "build/parser.cpp"
    break;

  case 332: /* primary_expr: IDENTIFIER  */
#line 1909 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier((yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 6205 "build/parser.cpp"
    break;

  case 333: /* primary_expr: KW_UNS  */
#line 1913 "src/parser.y"
             { (yyval.expr) = new rpg::Identifier("UNS"); }
#line 6211 "build/parser.cpp"
    break;

  case 334: /* primary_expr: KW_FLOAT_TYPE  */
#line 1914 "src/parser.y"
                    { (yyval.expr) = new rpg::Identifier("FLOAT"); }
#line 6217 "build/parser.cpp"
    break;

  case 335: /* primary_expr: KW_GRAPH  */
#line 1915 "src/parser.y"
               { (yyval.expr) = new rpg::Identifier("GRAPH"); }
#line 6223 "build/parser.cpp"
    break;

  case 336: /* primary_expr: KW_ASCEND  */
#line 1916 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("ASCEND"); }
#line 6229 "build/parser.cpp"
    break;

  case 337: /* primary_expr: KW_DESCEND  */
#line 1917 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("DESCEND"); }
#line 6235 "build/parser.cpp"
    break;

  case 338: /* primary_expr: KW_RTNPARM  */
#line 1918 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("RTNPARM"); }
#line 6241 "build/parser.cpp"
    break;

  case 339: /* primary_expr: KW_OPDESC  */
#line 1919 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("OPDESC"); }
#line 6247 "build/parser.cpp"
    break;

  case 340: /* primary_expr: KW_NULLIND  */
#line 1920 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("NULLIND"); }
#line 6253 "build/parser.cpp"
    break;

  case 341: /* primary_expr: KW_DATFMT  */
#line 1921 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("DATFMT"); }
#line 6259 "build/parser.cpp"
    break;

  case 342: /* primary_expr: KW_OVERLAY  */
#line 1922 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("OVERLAY"); }
#line 6265 "build/parser.cpp"
    break;

  case 343: /* primary_expr: KW_POS  */
#line 1923 "src/parser.y"
             { (yyval.expr) = new rpg::Identifier("POS"); }
#line 6271 "build/parser.cpp"
    break;

  case 344: /* primary_expr: KW_PREFIX  */
#line 1924 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("PREFIX"); }
#line 6277 "build/parser.cpp"
    break;

  case 345: /* primary_expr: KW_TIMFMT  */
#line 1925 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("TIMFMT"); }
#line 6283 "build/parser.cpp"
    break;

  case 346: /* primary_expr: KW_EXTNAME  */
#line 1926 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("EXTNAME"); }
#line 6289 "build/parser.cpp"
    break;

  case 347: /* primary_expr: INTEGER_LITERAL  */
#line 1927 "src/parser.y"
                      {
        (yyval.expr) = new rpg::IntLiteral((yyvsp[0].ival));
    }
#line 6297 "build/parser.cpp"
    break;

  case 348: /* primary_expr: FLOAT_LITERAL  */
#line 1930 "src/parser.y"
                    {
        (yyval.expr) = new rpg::FloatLiteral((yyvsp[0].fval));
    }
#line 6305 "build/parser.cpp"
    break;

  case 349: /* primary_expr: STRING_LITERAL  */
#line 1933 "src/parser.y"
                     {
        (yyval.expr) = new rpg::StringLiteral((yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 6314 "build/parser.cpp"
    break;

  case 350: /* primary_expr: IDENTIFIER LPAREN call_args_opt RPAREN  */
#line 1937 "src/parser.y"
                                             {
        (yyval.expr) = make_func((yyvsp[-3].sval), (yyvsp[-1].expr_list));
        free((yyvsp[-3].sval));
    }
#line 6323 "build/parser.cpp"
    break;

  case 351: /* primary_expr: BIF_CHAR LPAREN arg_list RPAREN  */
#line 1941 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("CHAR", (yyvsp[-1].expr_list));
    }
#line 6331 "build/parser.cpp"
    break;

  case 352: /* primary_expr: BIF_TRIM LPAREN arg_list RPAREN  */
#line 1944 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("TRIM", (yyvsp[-1].expr_list));
    }
#line 6339 "build/parser.cpp"
    break;

  case 353: /* primary_expr: BIF_TRIML LPAREN arg_list RPAREN  */
#line 1947 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("TRIML", (yyvsp[-1].expr_list));
    }
#line 6347 "build/parser.cpp"
    break;

  case 354: /* primary_expr: BIF_TRIMR LPAREN arg_list RPAREN  */
#line 1950 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("TRIMR", (yyvsp[-1].expr_list));
    }
#line 6355 "build/parser.cpp"
    break;

  case 355: /* primary_expr: BIF_LEN LPAREN arg_list RPAREN  */
#line 1953 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("LEN", (yyvsp[-1].expr_list));
    }
#line 6363 "build/parser.cpp"
    break;

  case 356: /* primary_expr: BIF_SUBST LPAREN arg_list RPAREN  */
#line 1956 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("SUBST", (yyvsp[-1].expr_list));
    }
#line 6371 "build/parser.cpp"
    break;

  case 357: /* primary_expr: BIF_SCAN LPAREN arg_list RPAREN  */
#line 1959 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("SCAN", (yyvsp[-1].expr_list));
    }
#line 6379 "build/parser.cpp"
    break;

  case 358: /* primary_expr: BIF_SCANRPL LPAREN arg_list RPAREN  */
#line 1962 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("SCANRPL", (yyvsp[-1].expr_list));
    }
#line 6387 "build/parser.cpp"
    break;

  case 359: /* primary_expr: BIF_XLATE LPAREN arg_list RPAREN  */
#line 1965 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("XLATE", (yyvsp[-1].expr_list));
    }
#line 6395 "build/parser.cpp"
    break;

  case 360: /* primary_expr: BIF_DEC LPAREN arg_list RPAREN  */
#line 1968 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("DEC", (yyvsp[-1].expr_list));
    }
#line 6403 "build/parser.cpp"
    break;

  case 361: /* primary_expr: BIF_INT LPAREN arg_list RPAREN  */
#line 1971 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("INT", (yyvsp[-1].expr_list));
    }
#line 6411 "build/parser.cpp"
    break;

  case 362: /* primary_expr: BIF_ELEM LPAREN arg_list RPAREN  */
#line 1974 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("ELEM", (yyvsp[-1].expr_list));
    }
#line 6419 "build/parser.cpp"
    break;

  case 363: /* primary_expr: BIF_PARMS LPAREN RPAREN  */
#line 1977 "src/parser.y"
                              {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("PARMS", empty);
    }
#line 6428 "build/parser.cpp"
    break;

  case 364: /* primary_expr: BIF_LOOKUP LPAREN arg_list RPAREN  */
#line 1981 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("LOOKUP", (yyvsp[-1].expr_list));
    }
#line 6436 "build/parser.cpp"
    break;

  case 365: /* primary_expr: BIF_EDITC LPAREN arg_list RPAREN  */
#line 1984 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("EDITC", (yyvsp[-1].expr_list));
    }
#line 6444 "build/parser.cpp"
    break;

  case 366: /* primary_expr: BIF_EDITW LPAREN arg_list RPAREN  */
#line 1987 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("EDITW", (yyvsp[-1].expr_list));
    }
#line 6452 "build/parser.cpp"
    break;

  case 367: /* primary_expr: BIF_REPLACE LPAREN arg_list RPAREN  */
#line 1990 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("REPLACE", (yyvsp[-1].expr_list));
    }
#line 6460 "build/parser.cpp"
    break;

  case 368: /* primary_expr: BIF_CHECK LPAREN arg_list RPAREN  */
#line 1993 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("CHECK", (yyvsp[-1].expr_list));
    }
#line 6468 "build/parser.cpp"
    break;

  case 369: /* primary_expr: BIF_CHECKR LPAREN arg_list RPAREN  */
#line 1996 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("CHECKR", (yyvsp[-1].expr_list));
    }
#line 6476 "build/parser.cpp"
    break;

  case 370: /* primary_expr: BIF_LOWER LPAREN arg_list RPAREN  */
#line 1999 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("LOWER", (yyvsp[-1].expr_list));
    }
#line 6484 "build/parser.cpp"
    break;

  case 371: /* primary_expr: BIF_UPPER LPAREN arg_list RPAREN  */
#line 2002 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("UPPER", (yyvsp[-1].expr_list));
    }
#line 6492 "build/parser.cpp"
    break;

  case 372: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_YEARS RPAREN  */
#line 2005 "src/parser.y"
                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("YEARS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6503 "build/parser.cpp"
    break;

  case 373: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_MONTHS RPAREN  */
#line 2011 "src/parser.y"
                                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MONTHS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6514 "build/parser.cpp"
    break;

  case 374: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_DAYS RPAREN  */
#line 2017 "src/parser.y"
                                                       {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("DAYS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6525 "build/parser.cpp"
    break;

  case 375: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_HOURS RPAREN  */
#line 2023 "src/parser.y"
                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("HOURS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6536 "build/parser.cpp"
    break;

  case 376: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_MINUTES RPAREN  */
#line 2029 "src/parser.y"
                                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MINUTES"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6547 "build/parser.cpp"
    break;

  case 377: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_SECONDS RPAREN  */
#line 2035 "src/parser.y"
                                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("SECONDS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6558 "build/parser.cpp"
    break;

  case 378: /* primary_expr: BIF_FLOAT LPAREN arg_list RPAREN  */
#line 2041 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("FLOAT", (yyvsp[-1].expr_list));
    }
#line 6566 "build/parser.cpp"
    break;

  case 379: /* primary_expr: BIF_SQRT LPAREN arg_list RPAREN  */
#line 2044 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("SQRT", (yyvsp[-1].expr_list));
    }
#line 6574 "build/parser.cpp"
    break;

  case 380: /* primary_expr: BIF_MAX LPAREN arg_list RPAREN  */
#line 2047 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("MAX", (yyvsp[-1].expr_list));
    }
#line 6582 "build/parser.cpp"
    break;

  case 381: /* primary_expr: BIF_MIN LPAREN arg_list RPAREN  */
#line 2050 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("MIN", (yyvsp[-1].expr_list));
    }
#line 6590 "build/parser.cpp"
    break;

  case 382: /* primary_expr: BIF_STATUS LPAREN RPAREN  */
#line 2053 "src/parser.y"
                               {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("STATUS", empty);
    }
#line 6599 "build/parser.cpp"
    break;

  case 383: /* primary_expr: BIF_ERROR LPAREN RPAREN  */
#line 2057 "src/parser.y"
                              {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("ERROR", empty);
    }
#line 6608 "build/parser.cpp"
    break;

  case 384: /* primary_expr: BIF_SIZE LPAREN arg_list RPAREN  */
#line 2061 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("SIZE", (yyvsp[-1].expr_list));
    }
#line 6616 "build/parser.cpp"
    break;

  case 385: /* primary_expr: BIF_ADDR LPAREN arg_list RPAREN  */
#line 2064 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("ADDR", (yyvsp[-1].expr_list));
    }
#line 6624 "build/parser.cpp"
    break;

  case 386: /* primary_expr: BIF_ABS LPAREN arg_list RPAREN  */
#line 2067 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("ABS", (yyvsp[-1].expr_list));
    }
#line 6632 "build/parser.cpp"
    break;

  case 387: /* primary_expr: BIF_DIV LPAREN arg_list RPAREN  */
#line 2070 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("DIV", (yyvsp[-1].expr_list));
    }
#line 6640 "build/parser.cpp"
    break;

  case 388: /* primary_expr: BIF_REM LPAREN arg_list RPAREN  */
#line 2073 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("REM", (yyvsp[-1].expr_list));
    }
#line 6648 "build/parser.cpp"
    break;

  case 389: /* primary_expr: BIF_DATE LPAREN arg_list RPAREN  */
#line 2076 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("DATE", (yyvsp[-1].expr_list));
    }
#line 6656 "build/parser.cpp"
    break;

  case 390: /* primary_expr: BIF_DATE LPAREN RPAREN  */
#line 2079 "src/parser.y"
                             {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("DATE", empty);
    }
#line 6665 "build/parser.cpp"
    break;

  case 391: /* primary_expr: BIF_TIME LPAREN arg_list RPAREN  */
#line 2083 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("TIME", (yyvsp[-1].expr_list));
    }
#line 6673 "build/parser.cpp"
    break;

  case 392: /* primary_expr: BIF_TIME LPAREN RPAREN  */
#line 2086 "src/parser.y"
                             {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("TIME", empty);
    }
#line 6682 "build/parser.cpp"
    break;

  case 393: /* primary_expr: BIF_TIMESTAMP LPAREN arg_list RPAREN  */
#line 2090 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TIMESTAMP", (yyvsp[-1].expr_list));
    }
#line 6690 "build/parser.cpp"
    break;

  case 394: /* primary_expr: BIF_TIMESTAMP LPAREN RPAREN  */
#line 2093 "src/parser.y"
                                  {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("TIMESTAMP", empty);
    }
#line 6699 "build/parser.cpp"
    break;

  case 395: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_DAYS RPAREN  */
#line 2097 "src/parser.y"
                                                                       {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("DAYS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 6711 "build/parser.cpp"
    break;

  case 396: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_MONTHS RPAREN  */
#line 2104 "src/parser.y"
                                                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MONTHS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 6723 "build/parser.cpp"
    break;

  case 397: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_YEARS RPAREN  */
#line 2111 "src/parser.y"
                                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("YEARS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 6735 "build/parser.cpp"
    break;

  case 398: /* primary_expr: BIF_DAYS LPAREN expression RPAREN  */
#line 2118 "src/parser.y"
                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("DAYS", args);
    }
#line 6745 "build/parser.cpp"
    break;

  case 399: /* primary_expr: BIF_MONTHS LPAREN expression RPAREN  */
#line 2123 "src/parser.y"
                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("MONTHS", args);
    }
#line 6755 "build/parser.cpp"
    break;

  case 400: /* primary_expr: BIF_YEARS LPAREN expression RPAREN  */
#line 2128 "src/parser.y"
                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("YEARS", args);
    }
#line 6765 "build/parser.cpp"
    break;

  case 401: /* primary_expr: BIF_FOUND LPAREN RPAREN  */
#line 2133 "src/parser.y"
                              {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("FOUND", empty);
    }
#line 6774 "build/parser.cpp"
    break;

  case 402: /* primary_expr: BIF_EOF LPAREN RPAREN  */
#line 2137 "src/parser.y"
                            {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("EOF", empty);
    }
#line 6783 "build/parser.cpp"
    break;

  case 403: /* primary_expr: BIF_ALLOC LPAREN arg_list RPAREN  */
#line 2141 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("ALLOC", (yyvsp[-1].expr_list));
    }
#line 6791 "build/parser.cpp"
    break;

  case 404: /* primary_expr: BIF_REALLOC LPAREN arg_list RPAREN  */
#line 2144 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("REALLOC", (yyvsp[-1].expr_list));
    }
#line 6799 "build/parser.cpp"
    break;

  case 405: /* primary_expr: BIF_XFOOT LPAREN arg_list RPAREN  */
#line 2147 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("XFOOT", (yyvsp[-1].expr_list));
    }
#line 6807 "build/parser.cpp"
    break;

  case 406: /* primary_expr: BIF_UNS LPAREN arg_list RPAREN  */
#line 2150 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("UNS", (yyvsp[-1].expr_list));
    }
#line 6815 "build/parser.cpp"
    break;

  case 407: /* primary_expr: BIF_INTH LPAREN arg_list RPAREN  */
#line 2153 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("INTH", (yyvsp[-1].expr_list));
    }
#line 6823 "build/parser.cpp"
    break;

  case 408: /* primary_expr: BIF_DECH LPAREN arg_list RPAREN  */
#line 2156 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("DECH", (yyvsp[-1].expr_list));
    }
#line 6831 "build/parser.cpp"
    break;

  case 409: /* primary_expr: BIF_DECPOS LPAREN arg_list RPAREN  */
#line 2159 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("DECPOS", (yyvsp[-1].expr_list));
    }
#line 6839 "build/parser.cpp"
    break;

  case 410: /* primary_expr: BIF_SPLIT LPAREN arg_list RPAREN  */
#line 2162 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("SPLIT", (yyvsp[-1].expr_list));
    }
#line 6847 "build/parser.cpp"
    break;

  case 411: /* primary_expr: BIF_CONCAT LPAREN arg_list RPAREN  */
#line 2165 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("CONCAT", (yyvsp[-1].expr_list));
    }
#line 6855 "build/parser.cpp"
    break;

  case 412: /* primary_expr: BIF_CONCATARR LPAREN arg_list RPAREN  */
#line 2168 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("CONCATARR", (yyvsp[-1].expr_list));
    }
#line 6863 "build/parser.cpp"
    break;

  case 413: /* primary_expr: BIF_LEFT LPAREN arg_list RPAREN  */
#line 2171 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("LEFT", (yyvsp[-1].expr_list));
    }
#line 6871 "build/parser.cpp"
    break;

  case 414: /* primary_expr: BIF_RIGHT LPAREN arg_list RPAREN  */
#line 2174 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("RIGHT", (yyvsp[-1].expr_list));
    }
#line 6879 "build/parser.cpp"
    break;

  case 415: /* primary_expr: BIF_STR LPAREN arg_list RPAREN  */
#line 2177 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("STR", (yyvsp[-1].expr_list));
    }
#line 6887 "build/parser.cpp"
    break;

  case 416: /* primary_expr: BIF_SUBARR LPAREN arg_list RPAREN  */
#line 2180 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("SUBARR", (yyvsp[-1].expr_list));
    }
#line 6895 "build/parser.cpp"
    break;

  case 417: /* primary_expr: BIF_MAXARR LPAREN arg_list RPAREN  */
#line 2183 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("MAXARR", (yyvsp[-1].expr_list));
    }
#line 6903 "build/parser.cpp"
    break;

  case 418: /* primary_expr: BIF_MINARR LPAREN arg_list RPAREN  */
#line 2186 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("MINARR", (yyvsp[-1].expr_list));
    }
#line 6911 "build/parser.cpp"
    break;

  case 419: /* primary_expr: BIF_LIST LPAREN arg_list RPAREN  */
#line 2189 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("LIST", (yyvsp[-1].expr_list));
    }
#line 6919 "build/parser.cpp"
    break;

  case 420: /* primary_expr: BIF_RANGE LPAREN arg_list RPAREN  */
#line 2192 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("RANGE", (yyvsp[-1].expr_list));
    }
#line 6927 "build/parser.cpp"
    break;

  case 421: /* primary_expr: BIF_LOOKUPLT LPAREN arg_list RPAREN  */
#line 2195 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPLT", (yyvsp[-1].expr_list));
    }
#line 6935 "build/parser.cpp"
    break;

  case 422: /* primary_expr: BIF_LOOKUPGE LPAREN arg_list RPAREN  */
#line 2198 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPGE", (yyvsp[-1].expr_list));
    }
#line 6943 "build/parser.cpp"
    break;

  case 423: /* primary_expr: BIF_LOOKUPLE LPAREN arg_list RPAREN  */
#line 2201 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPLE", (yyvsp[-1].expr_list));
    }
#line 6951 "build/parser.cpp"
    break;

  case 424: /* primary_expr: BIF_LOOKUPGT LPAREN arg_list RPAREN  */
#line 2204 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPGT", (yyvsp[-1].expr_list));
    }
#line 6959 "build/parser.cpp"
    break;

  case 425: /* primary_expr: BIF_TLOOKUP LPAREN arg_list RPAREN  */
#line 2207 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("TLOOKUP", (yyvsp[-1].expr_list));
    }
#line 6967 "build/parser.cpp"
    break;

  case 426: /* primary_expr: BIF_TLOOKUPLT LPAREN arg_list RPAREN  */
#line 2210 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TLOOKUPLT", (yyvsp[-1].expr_list));
    }
#line 6975 "build/parser.cpp"
    break;

  case 427: /* primary_expr: BIF_TLOOKUPGT LPAREN arg_list RPAREN  */
#line 2213 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TLOOKUPGT", (yyvsp[-1].expr_list));
    }
#line 6983 "build/parser.cpp"
    break;

  case 428: /* primary_expr: BIF_TLOOKUPLE LPAREN arg_list RPAREN  */
#line 2216 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TLOOKUPLE", (yyvsp[-1].expr_list));
    }
#line 6991 "build/parser.cpp"
    break;

  case 429: /* primary_expr: BIF_TLOOKUPGE LPAREN arg_list RPAREN  */
#line 2219 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TLOOKUPGE", (yyvsp[-1].expr_list));
    }
#line 6999 "build/parser.cpp"
    break;

  case 430: /* primary_expr: BIF_HOURS LPAREN expression RPAREN  */
#line 2222 "src/parser.y"
                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("HOURS", args);
    }
#line 7009 "build/parser.cpp"
    break;

  case 431: /* primary_expr: BIF_MINUTES LPAREN expression RPAREN  */
#line 2227 "src/parser.y"
                                           {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("MINUTES", args);
    }
#line 7019 "build/parser.cpp"
    break;

  case 432: /* primary_expr: BIF_SECONDS LPAREN expression RPAREN  */
#line 2232 "src/parser.y"
                                           {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("SECONDS", args);
    }
#line 7029 "build/parser.cpp"
    break;

  case 433: /* primary_expr: BIF_MSECONDS LPAREN expression RPAREN  */
#line 2237 "src/parser.y"
                                            {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("MSECONDS", args);
    }
#line 7039 "build/parser.cpp"
    break;

  case 434: /* primary_expr: BIF_PADDR LPAREN IDENTIFIER RPAREN  */
#line 2242 "src/parser.y"
                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::StringLiteral((yyvsp[-1].sval)));
        free((yyvsp[-1].sval));
        (yyval.expr) = make_bif("PADDR", args);
    }
#line 7050 "build/parser.cpp"
    break;

  case 435: /* primary_expr: BIF_PROC LPAREN RPAREN  */
#line 2248 "src/parser.y"
                             {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("PROC", empty);
    }
#line 7059 "build/parser.cpp"
    break;

  case 436: /* primary_expr: BIF_PROC  */
#line 2252 "src/parser.y"
               {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("PROC", empty);
    }
#line 7068 "build/parser.cpp"
    break;

  case 437: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_HOURS RPAREN  */
#line 2256 "src/parser.y"
                                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("HOURS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 7080 "build/parser.cpp"
    break;

  case 438: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_MINUTES RPAREN  */
#line 2263 "src/parser.y"
                                                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MINUTES"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 7092 "build/parser.cpp"
    break;

  case 439: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_SECONDS RPAREN  */
#line 2270 "src/parser.y"
                                                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("SECONDS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 7104 "build/parser.cpp"
    break;

  case 440: /* primary_expr: KW_ALL STRING_LITERAL  */
#line 2277 "src/parser.y"
                            {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::StringLiteral((yyvsp[0].sval)));
        free((yyvsp[0].sval));
        (yyval.expr) = make_bif("ALL", args);
    }
#line 7115 "build/parser.cpp"
    break;

  case 441: /* primary_expr: BIF_PASSED LPAREN ident RPAREN  */
#line 2283 "src/parser.y"
                                     {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::Identifier((yyvsp[-1].sval)));
        free((yyvsp[-1].sval));
        (yyval.expr) = make_bif("PASSED", args);
    }
#line 7126 "build/parser.cpp"
    break;

  case 442: /* primary_expr: BIF_OMITTED LPAREN ident RPAREN  */
#line 2289 "src/parser.y"
                                      {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::Identifier((yyvsp[-1].sval)));
        free((yyvsp[-1].sval));
        (yyval.expr) = make_bif("OMITTED", args);
    }
#line 7137 "build/parser.cpp"
    break;

  case 443: /* primary_expr: BIF_BITAND LPAREN arg_list RPAREN  */
#line 2295 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("BITAND", (yyvsp[-1].expr_list));
    }
#line 7145 "build/parser.cpp"
    break;

  case 444: /* primary_expr: BIF_BITNOT LPAREN arg_list RPAREN  */
#line 2298 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("BITNOT", (yyvsp[-1].expr_list));
    }
#line 7153 "build/parser.cpp"
    break;

  case 445: /* primary_expr: BIF_BITOR LPAREN arg_list RPAREN  */
#line 2301 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("BITOR", (yyvsp[-1].expr_list));
    }
#line 7161 "build/parser.cpp"
    break;

  case 446: /* primary_expr: BIF_BITXOR LPAREN arg_list RPAREN  */
#line 2304 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("BITXOR", (yyvsp[-1].expr_list));
    }
#line 7169 "build/parser.cpp"
    break;

  case 447: /* primary_expr: BIF_SCANR LPAREN arg_list RPAREN  */
#line 2307 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("SCANR", (yyvsp[-1].expr_list));
    }
#line 7177 "build/parser.cpp"
    break;

  case 448: /* primary_expr: BIF_EDITFLT LPAREN arg_list RPAREN  */
#line 2310 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("EDITFLT", (yyvsp[-1].expr_list));
    }
#line 7185 "build/parser.cpp"
    break;

  case 449: /* primary_expr: BIF_UNSH LPAREN arg_list RPAREN  */
#line 2313 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("UNSH", (yyvsp[-1].expr_list));
    }
#line 7193 "build/parser.cpp"
    break;

  case 450: /* primary_expr: BIF_PARMNUM LPAREN ident RPAREN  */
#line 2316 "src/parser.y"
                                      {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::Identifier((yyvsp[-1].sval)));
        free((yyvsp[-1].sval));
        (yyval.expr) = make_bif("PARMNUM", args);
    }
#line 7204 "build/parser.cpp"
    break;

  case 451: /* primary_expr: BIF_GETENV LPAREN arg_list RPAREN  */
#line 2322 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("GETENV", (yyvsp[-1].expr_list));
    }
#line 7212 "build/parser.cpp"
    break;

  case 452: /* primary_expr: INDICATOR  */
#line 2325 "src/parser.y"
                {
        (yyval.expr) = new rpg::IndicatorExpr((yyvsp[0].ival));
    }
#line 7220 "build/parser.cpp"
    break;

  case 453: /* primary_expr: KW_ON  */
#line 2328 "src/parser.y"
            {
        (yyval.expr) = new rpg::IntLiteral(1);  // *ON → true
    }
#line 7228 "build/parser.cpp"
    break;

  case 454: /* primary_expr: KW_OFF  */
#line 2331 "src/parser.y"
             {
        (yyval.expr) = new rpg::IntLiteral(0);  // *OFF → false
    }
#line 7236 "build/parser.cpp"
    break;

  case 455: /* primary_expr: KW_NULL  */
#line 2334 "src/parser.y"
              {
        (yyval.expr) = new rpg::Identifier("nullptr");
    }
#line 7244 "build/parser.cpp"
    break;

  case 456: /* primary_expr: KW_OMIT  */
#line 2337 "src/parser.y"
              {
        (yyval.expr) = new rpg::Identifier("nullptr");
    }
#line 7252 "build/parser.cpp"
    break;

  case 457: /* primary_expr: KW_BLANKS  */
#line 2340 "src/parser.y"
                {
        (yyval.expr) = new rpg::Identifier("RPG_BLANKS");
    }
#line 7260 "build/parser.cpp"
    break;

  case 458: /* primary_expr: KW_ZEROS  */
#line 2343 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier("RPG_ZEROS");
    }
#line 7268 "build/parser.cpp"
    break;

  case 459: /* primary_expr: KW_HIVAL  */
#line 2346 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier("RPG_HIVAL");
    }
#line 7276 "build/parser.cpp"
    break;

  case 460: /* primary_expr: KW_LOVAL  */
#line 2349 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier("RPG_LOVAL");
    }
#line 7284 "build/parser.cpp"
    break;

  case 461: /* primary_expr: LPAREN expression RPAREN  */
#line 2352 "src/parser.y"
                               {
        (yyval.expr) = (yyvsp[-1].expr);
    }
#line 7292 "build/parser.cpp"
    break;

  case 462: /* call_args_opt: %empty  */
#line 2359 "src/parser.y"
                { (yyval.expr_list) = nullptr; }
#line 7298 "build/parser.cpp"
    break;

  case 463: /* call_args_opt: call_arg_list  */
#line 2360 "src/parser.y"
                    { (yyval.expr_list) = (yyvsp[0].expr_list); }
#line 7304 "build/parser.cpp"
    break;

  case 464: /* call_arg_list: expression  */
#line 2364 "src/parser.y"
               {
        (yyval.expr_list) = new std::vector<rpg::Expression*>();
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 7313 "build/parser.cpp"
    break;

  case 465: /* call_arg_list: call_arg_list COLON expression  */
#line 2368 "src/parser.y"
                                     {
        (yyval.expr_list) = (yyvsp[-2].expr_list);
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 7322 "build/parser.cpp"
    break;

  case 466: /* arg_list: expression  */
#line 2376 "src/parser.y"
               {
        (yyval.expr_list) = new std::vector<rpg::Expression*>();
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 7331 "build/parser.cpp"
    break;

  case 467: /* arg_list: arg_list COLON expression  */
#line 2380 "src/parser.y"
                                {
        (yyval.expr_list) = (yyvsp[-2].expr_list);
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 7340 "build/parser.cpp"
    break;


#line 7344 "build/parser.cpp"

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

#line 2386 "src/parser.y"


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
