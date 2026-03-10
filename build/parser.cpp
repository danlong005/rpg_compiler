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
  YYSYMBOL_KW_ALL = 192,                   /* KW_ALL  */
  YYSYMBOL_KW_UNS = 193,                   /* KW_UNS  */
  YYSYMBOL_KW_FLOAT_TYPE = 194,            /* KW_FLOAT_TYPE  */
  YYSYMBOL_KW_BINDEC = 195,                /* KW_BINDEC  */
  YYSYMBOL_KW_UCS2 = 196,                  /* KW_UCS2  */
  YYSYMBOL_KW_GRAPH = 197,                 /* KW_GRAPH  */
  YYSYMBOL_KW_OBJECT = 198,                /* KW_OBJECT  */
  YYSYMBOL_KW_JAVA = 199,                  /* KW_JAVA  */
  YYSYMBOL_KW_OVERLAY = 200,               /* KW_OVERLAY  */
  YYSYMBOL_KW_POS = 201,                   /* KW_POS  */
  YYSYMBOL_KW_PREFIX = 202,                /* KW_PREFIX  */
  YYSYMBOL_KW_DATFMT = 203,                /* KW_DATFMT  */
  YYSYMBOL_KW_TIMFMT = 204,                /* KW_TIMFMT  */
  YYSYMBOL_KW_EXTNAME = 205,               /* KW_EXTNAME  */
  YYSYMBOL_KW_RTNPARM = 206,               /* KW_RTNPARM  */
  YYSYMBOL_KW_OPDESC = 207,                /* KW_OPDESC  */
  YYSYMBOL_KW_ASCEND = 208,                /* KW_ASCEND  */
  YYSYMBOL_KW_DESCEND = 209,               /* KW_DESCEND  */
  YYSYMBOL_KW_NULLIND = 210,               /* KW_NULLIND  */
  YYSYMBOL_KW_VARSIZE = 211,               /* KW_VARSIZE  */
  YYSYMBOL_KW_STRING_OPT = 212,            /* KW_STRING_OPT  */
  YYSYMBOL_KW_TRIM_OPT = 213,              /* KW_TRIM_OPT  */
  YYSYMBOL_KW_DCL_ENUM = 214,              /* KW_DCL_ENUM  */
  YYSYMBOL_KW_END_ENUM = 215,              /* KW_END_ENUM  */
  YYSYMBOL_KW_BOOLEAN = 216,               /* KW_BOOLEAN  */
  YYSYMBOL_EXEC_SQL_TEXT = 217,            /* EXEC_SQL_TEXT  */
  YYSYMBOL_POWER = 218,                    /* POWER  */
  YYSYMBOL_KW_DIM_VAR = 219,               /* KW_DIM_VAR  */
  YYSYMBOL_KW_DIM_AUTO = 220,              /* KW_DIM_AUTO  */
  YYSYMBOL_KW_FOR_EACH = 221,              /* KW_FOR_EACH  */
  YYSYMBOL_KW_IN = 222,                    /* KW_IN  */
  YYSYMBOL_IDENTIFIER = 223,               /* IDENTIFIER  */
  YYSYMBOL_INTEGER_LITERAL = 224,          /* INTEGER_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 225,            /* FLOAT_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 226,           /* STRING_LITERAL  */
  YYSYMBOL_SEMICOLON = 227,                /* SEMICOLON  */
  YYSYMBOL_EQUALS = 228,                   /* EQUALS  */
  YYSYMBOL_LPAREN = 229,                   /* LPAREN  */
  YYSYMBOL_RPAREN = 230,                   /* RPAREN  */
  YYSYMBOL_COLON = 231,                    /* COLON  */
  YYSYMBOL_PLUS = 232,                     /* PLUS  */
  YYSYMBOL_MINUS = 233,                    /* MINUS  */
  YYSYMBOL_STAR = 234,                     /* STAR  */
  YYSYMBOL_SLASH = 235,                    /* SLASH  */
  YYSYMBOL_NE = 236,                       /* NE  */
  YYSYMBOL_LE = 237,                       /* LE  */
  YYSYMBOL_GE = 238,                       /* GE  */
  YYSYMBOL_LT = 239,                       /* LT  */
  YYSYMBOL_GT = 240,                       /* GT  */
  YYSYMBOL_YYACCEPT = 241,                 /* $accept  */
  YYSYMBOL_program = 242,                  /* program  */
  YYSYMBOL_statements_opt = 243,           /* statements_opt  */
  YYSYMBOL_statement_list = 244,           /* statement_list  */
  YYSYMBOL_statement = 245,                /* statement  */
  YYSYMBOL_dcl_f_stmt = 246,               /* dcl_f_stmt  */
  YYSYMBOL_dcl_s_stmt = 247,               /* dcl_s_stmt  */
  YYSYMBOL_dcl_s_keywords = 248,           /* dcl_s_keywords  */
  YYSYMBOL_dcl_c_stmt = 249,               /* dcl_c_stmt  */
  YYSYMBOL_eval_target = 250,              /* eval_target  */
  YYSYMBOL_eval_stmt = 251,                /* eval_stmt  */
  YYSYMBOL_eval_corr_stmt = 252,           /* eval_corr_stmt  */
  YYSYMBOL_evalr_stmt = 253,               /* evalr_stmt  */
  YYSYMBOL_callp_stmt = 254,               /* callp_stmt  */
  YYSYMBOL_leavesr_stmt = 255,             /* leavesr_stmt  */
  YYSYMBOL_dsply_stmt = 256,               /* dsply_stmt  */
  YYSYMBOL_inlr_stmt = 257,                /* inlr_stmt  */
  YYSYMBOL_return_stmt = 258,              /* return_stmt  */
  YYSYMBOL_expr_stmt = 259,                /* expr_stmt  */
  YYSYMBOL_dcl_pr_stmt = 260,              /* dcl_pr_stmt  */
  YYSYMBOL_dcl_proc_stmt = 261,            /* dcl_proc_stmt  */
  YYSYMBOL_proc_export = 262,              /* proc_export  */
  YYSYMBOL_pi_return_type = 263,           /* pi_return_type  */
  YYSYMBOL_pi_params = 264,                /* pi_params  */
  YYSYMBOL_pi_param = 265,                 /* pi_param  */
  YYSYMBOL_pr_params = 266,                /* pr_params  */
  YYSYMBOL_pr_param = 267,                 /* pr_param  */
  YYSYMBOL_monitor_stmt = 268,             /* monitor_stmt  */
  YYSYMBOL_begsr_stmt = 269,               /* begsr_stmt  */
  YYSYMBOL_exsr_stmt = 270,                /* exsr_stmt  */
  YYSYMBOL_sorta_stmt = 271,               /* sorta_stmt  */
  YYSYMBOL_reset_stmt = 272,               /* reset_stmt  */
  YYSYMBOL_clear_stmt = 273,               /* clear_stmt  */
  YYSYMBOL_dealloc_stmt = 274,             /* dealloc_stmt  */
  YYSYMBOL_test_stmt = 275,                /* test_stmt  */
  YYSYMBOL_exec_sql_stmt = 276,            /* exec_sql_stmt  */
  YYSYMBOL_dcl_enum_stmt = 277,            /* dcl_enum_stmt  */
  YYSYMBOL_enum_constants = 278,           /* enum_constants  */
  YYSYMBOL_enum_constant = 279,            /* enum_constant  */
  YYSYMBOL_dcl_ds_stmt = 280,              /* dcl_ds_stmt  */
  YYSYMBOL_ds_fields = 281,                /* ds_fields  */
  YYSYMBOL_ds_field = 282,                 /* ds_field  */
  YYSYMBOL_if_stmt = 283,                  /* if_stmt  */
  YYSYMBOL_elseif_clauses = 284,           /* elseif_clauses  */
  YYSYMBOL_elseif_clause = 285,            /* elseif_clause  */
  YYSYMBOL_else_clause = 286,              /* else_clause  */
  YYSYMBOL_dow_stmt = 287,                 /* dow_stmt  */
  YYSYMBOL_dou_stmt = 288,                 /* dou_stmt  */
  YYSYMBOL_for_stmt = 289,                 /* for_stmt  */
  YYSYMBOL_for_each_stmt = 290,            /* for_each_stmt  */
  YYSYMBOL_select_stmt = 291,              /* select_stmt  */
  YYSYMBOL_when_clauses = 292,             /* when_clauses  */
  YYSYMBOL_when_clause = 293,              /* when_clause  */
  YYSYMBOL_other_clause = 294,             /* other_clause  */
  YYSYMBOL_iter_stmt = 295,                /* iter_stmt  */
  YYSYMBOL_leave_stmt = 296,               /* leave_stmt  */
  YYSYMBOL_expression = 297,               /* expression  */
  YYSYMBOL_or_expr = 298,                  /* or_expr  */
  YYSYMBOL_and_expr = 299,                 /* and_expr  */
  YYSYMBOL_not_expr = 300,                 /* not_expr  */
  YYSYMBOL_comparison_expr = 301,          /* comparison_expr  */
  YYSYMBOL_additive_expr = 302,            /* additive_expr  */
  YYSYMBOL_multiplicative_expr = 303,      /* multiplicative_expr  */
  YYSYMBOL_power_expr = 304,               /* power_expr  */
  YYSYMBOL_unary_expr = 305,               /* unary_expr  */
  YYSYMBOL_postfix_expr = 306,             /* postfix_expr  */
  YYSYMBOL_ident = 307,                    /* ident  */
  YYSYMBOL_primary_expr = 308,             /* primary_expr  */
  YYSYMBOL_call_args_opt = 309,            /* call_args_opt  */
  YYSYMBOL_call_arg_list = 310,            /* call_arg_list  */
  YYSYMBOL_arg_list = 311                  /* arg_list  */
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
#define YYLAST   4823

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  241
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  71
/* YYNRULES -- Number of rules.  */
#define YYNRULES  446
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1455

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   495


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
     235,   236,   237,   238,   239,   240
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   194,   194,   197,   202,   204,   209,   218,   221,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   268,   272,   276,   280,   288,   293,   298,
     303,   308,   313,   318,   323,   328,   333,   338,   343,   349,
     355,   361,   365,   369,   373,   377,   381,   385,   389,   393,
     397,   401,   407,   413,   419,   425,   432,   437,   443,   448,
     453,   458,   463,   468,   473,   478,   483,   488,   493,   498,
     506,   507,   508,   509,   510,   515,   522,   526,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   543,   549,   553,   559,   565,   571,   580,   588,
     597,   603,   609,   615,   621,   624,   631,   642,   659,   679,
     694,   718,   743,   770,   800,   801,   806,   807,   808,   809,
     810,   815,   818,   826,   830,   834,   838,   842,   846,   850,
     854,   859,   863,   867,   871,   875,   879,   883,   887,   891,
     897,   902,   907,   912,   918,   923,   928,   933,   939,   944,
     949,   958,   961,   969,   973,   977,   981,   985,   989,   993,
     997,  1002,  1006,  1010,  1014,  1018,  1022,  1026,  1030,  1034,
    1040,  1045,  1050,  1055,  1061,  1066,  1071,  1076,  1082,  1087,
    1092,  1102,  1113,  1123,  1131,  1139,  1146,  1154,  1162,  1173,
    1183,  1191,  1202,  1205,  1213,  1221,  1236,  1245,  1254,  1264,
    1274,  1285,  1296,  1307,  1318,  1326,  1335,  1345,  1356,  1367,
    1379,  1382,  1390,  1394,  1398,  1402,  1407,  1411,  1415,  1419,
    1424,  1430,  1436,  1443,  1450,  1457,  1463,  1475,  1498,  1499,
    1507,  1516,  1517,  1523,  1532,  1541,  1551,  1561,  1571,  1584,
    1594,  1613,  1617,  1624,  1633,  1634,  1640,  1644,  1650,  1654,
    1655,  1663,  1664,  1672,  1673,  1679,  1680,  1685,  1690,  1695,
    1700,  1705,  1710,  1718,  1719,  1724,  1732,  1733,  1738,  1746,
    1747,  1755,  1756,  1764,  1765,  1772,  1773,  1774,  1775,  1776,
    1777,  1778,  1779,  1780,  1781,  1782,  1783,  1784,  1785,  1786,
    1787,  1791,  1795,  1796,  1797,  1798,  1799,  1800,  1801,  1802,
    1803,  1804,  1805,  1806,  1807,  1808,  1809,  1812,  1815,  1819,
    1823,  1826,  1829,  1832,  1835,  1838,  1841,  1844,  1847,  1850,
    1853,  1856,  1859,  1863,  1866,  1869,  1872,  1875,  1878,  1881,
    1884,  1887,  1893,  1899,  1905,  1911,  1917,  1923,  1926,  1929,
    1932,  1935,  1939,  1943,  1946,  1949,  1952,  1955,  1958,  1961,
    1965,  1968,  1972,  1975,  1979,  1986,  1993,  2000,  2005,  2010,
    2015,  2019,  2023,  2026,  2029,  2032,  2035,  2038,  2041,  2044,
    2047,  2050,  2053,  2056,  2059,  2062,  2065,  2068,  2071,  2074,
    2077,  2080,  2083,  2086,  2089,  2092,  2095,  2098,  2101,  2104,
    2109,  2114,  2119,  2124,  2130,  2134,  2138,  2145,  2152,  2159,
    2165,  2171,  2177,  2180,  2183,  2186,  2189,  2192,  2195,  2198,
    2204,  2207,  2210,  2213,  2216,  2219,  2222,  2225,  2228,  2231,
    2234,  2241,  2242,  2246,  2250,  2258,  2262
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
  "BIF_GETENV", "KW_ALL", "KW_UNS", "KW_FLOAT_TYPE", "KW_BINDEC",
  "KW_UCS2", "KW_GRAPH", "KW_OBJECT", "KW_JAVA", "KW_OVERLAY", "KW_POS",
  "KW_PREFIX", "KW_DATFMT", "KW_TIMFMT", "KW_EXTNAME", "KW_RTNPARM",
  "KW_OPDESC", "KW_ASCEND", "KW_DESCEND", "KW_NULLIND", "KW_VARSIZE",
  "KW_STRING_OPT", "KW_TRIM_OPT", "KW_DCL_ENUM", "KW_END_ENUM",
  "KW_BOOLEAN", "EXEC_SQL_TEXT", "POWER", "KW_DIM_VAR", "KW_DIM_AUTO",
  "KW_FOR_EACH", "KW_IN", "IDENTIFIER", "INTEGER_LITERAL", "FLOAT_LITERAL",
  "STRING_LITERAL", "SEMICOLON", "EQUALS", "LPAREN", "RPAREN", "COLON",
  "PLUS", "MINUS", "STAR", "SLASH", "NE", "LE", "GE", "LT", "GT",
  "$accept", "program", "statements_opt", "statement_list", "statement",
  "dcl_f_stmt", "dcl_s_stmt", "dcl_s_keywords", "dcl_c_stmt",
  "eval_target", "eval_stmt", "eval_corr_stmt", "evalr_stmt", "callp_stmt",
  "leavesr_stmt", "dsply_stmt", "inlr_stmt", "return_stmt", "expr_stmt",
  "dcl_pr_stmt", "dcl_proc_stmt", "proc_export", "pi_return_type",
  "pi_params", "pi_param", "pr_params", "pr_param", "monitor_stmt",
  "begsr_stmt", "exsr_stmt", "sorta_stmt", "reset_stmt", "clear_stmt",
  "dealloc_stmt", "test_stmt", "exec_sql_stmt", "dcl_enum_stmt",
  "enum_constants", "enum_constant", "dcl_ds_stmt", "ds_fields",
  "ds_field", "if_stmt", "elseif_clauses", "elseif_clause", "else_clause",
  "dow_stmt", "dou_stmt", "for_stmt", "for_each_stmt", "select_stmt",
  "when_clauses", "when_clause", "other_clause", "iter_stmt", "leave_stmt",
  "expression", "or_expr", "and_expr", "not_expr", "comparison_expr",
  "additive_expr", "multiplicative_expr", "power_expr", "unary_expr",
  "postfix_expr", "ident", "primary_expr", "call_args_opt",
  "call_arg_list", "arg_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-787)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-266)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      66,  -787,    54,    28,   378,  -787,  -142,  -123,   313,  -117,
    4128,    99,   313,    99,  4128,  -106,   313,   -96,  -787,  3368,
     -75,  4128,  4128,  4128,   313,   -48,   -40,   -37,   -34,  -113,
     313,   313,   313,   313,  -787,    25,    35,    40,   -32,  -787,
    -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,
    -787,  -787,  -787,    43,  -787,   313,    27,  -787,  -787,  -787,
    -787,   -18,  -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,
    -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,
    -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,
    -787,  -787,  -787,   394,  -787,  -787,  -787,  -787,  -787,  -787,
    -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,
     144,  4128,  -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,
    -787,  4318,    41,    60,    92,   103,   105,   116,   122,   147,
     165,   170,   179,   206,   208,   213,   229,   238,   242,   244,
     247,   249,   269,   279,   295,   305,   310,   341,   347,   362,
     369,   371,   380,   391,   393,   408,   415,   420,   428,   435,
     451,   460,   467,   471,   494,   523,   538,   543,   576,   577,
     589,   590,   591,   593,   594,   596,   597,   598,   600,   602,
     604,   605,   606,   608,   609,   610,   611,   612,   613,   614,
     615,   616,   617,   618,   619,   620,   621,   622,   623,   624,
     625,   626,   627,   628,   629,   630,   631,   632,    47,  -787,
    -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,
    -787,  -787,  -787,   633,  -787,  -787,  -787,  4128,  4508,    -7,
     190,   210,  -787,   187,    55,   -59,  -787,    77,   259,  -787,
      39,   131,   153,   379,   444,  -787,   637,   313,  -787,   639,
     571,   641,   642,   644,   530,   761,  -787,  -787,  -787,   645,
     649,   650,   651,   652,   790,   315,    37,  4128,   -47,   658,
     659,  4128,  4128,    -9,   654,   656,   655,   657,   660,   661,
     662,  -128,  -110,   665,   666,   667,   668,   669,   670,   681,
     683,   684,   685,   689,   690,   187,  4128,  4128,  4128,  4128,
    4128,  4128,  4128,  4128,  4128,  4128,  4128,  4128,   688,   692,
    4128,  4128,  4128,  4128,  4128,   693,   694,   695,  4128,  4128,
    4128,  3558,  3748,  3938,  4128,  4128,  4128,  4128,  4128,  4128,
    4128,  4128,  4128,  4128,  4128,  4128,  4128,  4128,  4128,  4128,
    4128,  4128,  4128,  4128,  4128,  4128,  4128,  4128,  4128,  4128,
    4128,  4128,  4128,  4128,  4128,  4128,  4128,  4128,  4128,  4128,
    4128,  4128,  4128,  4128,  4128,  4128,  4128,  4128,  4128,   664,
     696,   313,   313,  4128,  4128,  4128,  4128,  4128,  4128,  4128,
     313,  4128,  -787,  4128,   698,   259,  -787,  4128,  4128,  4318,
    4318,  4318,  4318,  4318,  4318,  4318,  4318,  4318,  4318,  4318,
    4318,   672,  4128,  4128,   313,  4128,  -787,  -787,   699,  -787,
     706,  -787,  -787,  -787,  4128,  4128,   172,  -787,  1458,  -787,
    -787,  -787,  -787,  -787,  -787,   708,   701,   707,   709,   718,
     720,    -8,   -29,   722,   727,   728,  -787,  -787,    45,   710,
     673,  4128,  -787,   716,   730,   731,   734,   729,  -787,  -787,
    -787,   741,   746,   747,   749,   751,   743,  -787,   745,  -787,
    -787,  -787,  -787,   753,   754,   756,   757,   759,   760,   686,
    -787,  -787,    53,    88,    93,   140,   156,   235,   254,   260,
     263,   266,   271,   281,  -787,  -787,   302,   307,   317,   338,
     343,  -787,  -787,  -787,   359,   363,   366,  -787,   388,  -787,
     395,  -787,   397,   758,   755,   762,   763,   399,   401,   403,
     405,   417,   421,   423,   769,   425,   430,   432,   443,   445,
     448,   454,   464,   468,   472,   475,   477,   479,   481,   483,
     487,   489,   491,   495,   497,   499,   501,   503,   505,   507,
     509,   511,   513,   516,   773,   774,   775,   776,   777,  -787,
     778,   779,   518,   520,   524,   526,   529,   531,   533,   780,
     535,  -787,   781,  -787,   210,  -787,   536,   536,   536,   536,
     536,   536,   536,   -59,   -59,  -787,  -787,  -787,  -787,   716,
     785,   786,   789,   313,  -787,   607,  1525,  1739,   703,   791,
     792,  -787,   815,   793,  -787,  1806,   827,   766,   803,   805,
     806,   808,   788,  -787,   802,   807,  -787,   130,   764,   809,
     -14,  -787,  4128,   673,   546,  -127,  -787,   813,   872,   814,
    4128,  -787,   801,   820,   821,   822,   812,   823,   832,   833,
     828,   829,   831,   834,   837,   838,   850,  -787,  -787,  -787,
    -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,
    -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,
    4128,  -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,
    -787,   519,  -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,
    -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,
    -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,
    -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,
    -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,
    -787,   818,   717,   855,   857,  4128,  4128,  -787,  -787,   858,
    -787,   860,    24,   859,   861,   863,   864,   866,   862,    36,
     225,   871,   -11,   867,   868,   870,   873,   548,   874,   879,
     545,  -787,  -787,  -118,  -787,  4128,   877,  -787,  -787,   882,
    -787,  -787,   875,   306,   350,   392,   883,   884,   880,   881,
     885,   442,   442,   442,   442,   442,   887,   878,   886,   888,
     889,   890,   891,   892,  -787,  4128,   896,  -787,  1036,  -787,
    -787,   -25,   -21,   869,  2020,  -787,  2114,  -787,   549,   897,
    -787,  -787,  -787,   893,   898,   899,   900,   903,   268,  -787,
     901,   902,   904,   550,   909,   906,   907,  1015,   -19,   910,
     914,  -787,   553,   911,   912,   913,   915,   916,   918,  -787,
    2328,  -787,   894,  1085,   917,  -787,  -787,   919,  1109,  -787,
     920,   923,   922,  -787,   924,   925,  1117,   926,   929,  1124,
     930,   934,   932,   944,   948,   949,  -787,   952,   958,   960,
     961,   962,   964,   528,  -787,  -787,  -787,  -787,  -787,  -787,
     965,  -787,   966,  4128,  -787,  4128,  -787,   968,   969,  -787,
     967,  -787,   971,  -787,   592,   970,   972,   973,   974,   975,
     976,   981,   979,   980,   993,  -787,   988,   989,   994,   991,
    -787,  -787,   992,   995,   996,   997,   998,   999,  1006,  1007,
    1008,  -787,  -787,  1009,  1003,  1005,  4128,  1014,  1012,  1019,
    -787,  4128,   227,  -787,  1017,  4128,  1021,  1025,   236,  -787,
     440,   442,  -787,  -787,  -787,  -787,  -787,  -787,  -787,  1011,
    1027,  1029,  1034,  1035,  1039,  1040,  -787,  2395,  -787,  1028,
    2609,  1045,  2676,  -787,  -787,    30,  -787,    44,  -787,  1037,
    1044,  1055,  1056,  1062,  1063,  1064,  1065,  1067,  1061,  1068,
    -787,  -787,  1069,  1091,  1092,  -787,  1073,    48,  1193,  1076,
    1077,  1079,  1080,  1075,  1078,  1081,  1082,  -787,  1066,  4128,
    1086,  1087,  4128,  1094,  1096,  1084,  1090,  1101,  4128,  1102,
    1103,  4128,  1105,  1106,  1110,  1280,  1083,  1093,  1112,  1115,
    -787,  -787,  -787,  -787,  -787,  -787,  -787,   963,  -787,  1116,
    -787,  1118,    31,  1119,  1121,   299,  -787,  1120,    46,  1125,
    1126,  1127,  1128,  1123,  1129,  1130,  1131,  1133,  1137,  1138,
      49,    51,  1139,  1140,  1141,    67,  1142,  1146,  1148,  1158,
    1159,  1160,  1145,   -85,  1165,   -33,  1132,  -787,  1163,  1168,
    1169,  1167,   135,  1172,  1134,  1178,  1174,  1173,  1179,  1180,
    1175,  1184,  1185,   180,  1181,  4128,  1187,  -787,  -787,  2890,
    -787,  2957,  -787,  1186,  -787,   603,  1183,  1188,  1189,  1190,
    1191,  -787,  1194,  1192,  1195,  1196,  1197,   -41,   -38,   -26,
    1199,  1200,  -787,  -787,  1202,  1203,  -787,  -787,  -787,  1204,
    1205,  -787,  -787,  1206,  1207,  1208,  1212,  1210,  1211,  -787,
    -787,  1213,  1214,  -787,  1225,  1229,  -787,  -787,  1230,  1233,
    1239,  -787,  -787,  1238,  1240,  -787,  1242,  -787,  -787,  1245,
    1241,  1243,  1247,  1248,  -787,  4128,  1246,  1249,  1250,  1251,
    -787,  1177,  1252,  1253,  1254,  1255,  1256,  1261,  1262,  1263,
    1201,  -787,   -50,   -49,   -46,  1264,  1266,   -36,  -787,  1269,
     -35,  -787,  1270,   -12,  -787,  1271,  -787,    68,    71,  -787,
    -787,    97,   152,   154,  -787,  -787,   162,  -787,  -787,  -787,
    1272,  1277,  1279,  1281,  1282,  -119,  -787,  -787,  -787,  -787,
    1278,  1284,  -787,  -787,  1285,  1286,  -787,  -787,  1287,  1288,
    1291,  -787,  -787,  1244,  1292,  1295,  1283,  1290,  1300,  1301,
    1297,  1306,  1308,  1309,  1315,  1319,  -787,  1320,  -787,  1322,
    -787,  1321,   738,  1324,  -787,   740,  1325,  -787,   742,  1333,
    -787,   -24,  1323,  1338,  1339,  1340,  1341,  1342,  1343,   558,
    1344,   560,  1348,  1350,  -787,  -787,  -787,  -787,  -787,  1345,
    -787,  -787,  1346,  1353,  -787,  -787,  1351,  1352,  1354,  1355,
     -23,   -22,   -20,  1347,  1358,  -787,  -787,  -787,   -45,  1360,
    1362,  1304,  1363,  1366,  1310,  1367,  1372,  1311,  1364,    -4,
    -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,  1370,  1379,
    1378,  1380,  1388,  1386,  1390,  -787,  -787,  -787,  3171,   -43,
     -39,   -31,  1392,  1389,    -3,  -787,  1391,    -1,  -787,  1394,
       0,  -787,  1387,  -787,  1397,  -787,  1312,  1398,  1396,  1359,
    1400,  1399,  1369,  1401,  1402,  1371,  1404,  -787,  -787,  1405,
    -787,  -787,  1406,  -787,  1407,  3238,  1403,  1411,  -787,  1412,
    -787,  1413,  -787,  1414,   748,  1416,  -787,   750,  1417,  -787,
     752,  1418,  -787,   -13,  -787,  1419,  -787,  1421,  1420,  -787,
    1426,  1424,  -787,  1429,  1427,  1464,  1442,  1443,  1444,  1446,
    -787,  -787,  -787,  -787,   -28,  1410,  1447,  1577,  1445,  1448,
    1587,  1449,  1452,  1590,  1454,    13,  -787,  1457,  -787,  1459,
    -787,  1460,  -787,  1461,  1455,  -787,  -787,  -787,  -787,  1462,
    -787,  1598,  1463,  1465,  1629,  1466,  1467,  1646,  1469,  1468,
    1647,  1470,  -787,  -787,  -787,  -787,  -787,  1473,  -787,  1471,
    -787,  1475,  1474,  -787,  1476,  1477,  -787,  1478,  1479,  1650,
    -787,  1481,  -787,  1483,  -787,  1484,  -787,  1485,  1486,  -787,
    -787,  -787,  -787,  1487,  -787
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       4,     4,     0,     0,     0,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   111,     0,     0,     0,     0,   100,
     101,   102,    98,    97,    99,   108,   109,   110,   105,   106,
     103,   104,   107,     0,   209,     0,    96,     5,     9,    10,
      11,     0,    12,    13,    35,    36,    37,    14,    15,    16,
      41,    26,    25,    29,    30,    31,    34,    32,    33,    38,
      39,    40,    28,    27,    17,    18,    19,    20,    21,    22,
      23,    24,    42,     0,   296,   297,   298,   308,   309,   310,
     305,   306,   307,   302,   303,   299,   300,   304,   301,   295,
       0,     0,   434,   435,   432,   436,   437,   438,   439,   433,
     431,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   415,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   312,
     313,   314,   321,   322,   323,   320,   324,   325,   317,   318,
     315,   316,   319,   311,   326,   327,   328,     0,     0,     0,
     268,   269,   271,   273,   275,   283,   286,   289,   291,   293,
      96,     0,     0,     0,     0,   121,     0,     0,   125,     0,
       0,     0,     0,     0,     0,     0,   266,   267,     7,     0,
       0,     0,     0,     0,   134,   136,     0,     0,     0,     0,
       0,   441,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   274,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   419,   441,     0,   292,   122,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   120,   207,     0,   124,
       0,     7,     7,     7,     0,     0,   264,   261,     0,     7,
     203,   205,   206,   204,   135,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   230,   445,     0,     0,
       0,     0,   112,   443,     0,   442,     0,     0,    43,    44,
      45,     0,     0,     0,     0,     0,     0,    63,     0,    64,
      65,    61,    66,     0,     0,     0,     0,     0,     0,     0,
      62,    95,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   380,   381,     0,     0,     0,     0,
       0,   342,   361,   362,     0,     0,     0,   369,     0,   371,
       0,   373,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   414,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   443,     0,   440,   270,   272,   276,   277,   280,   281,
     278,   279,   282,   284,   285,   287,   288,   290,   294,     0,
       0,     0,     0,     0,   123,     0,     0,     0,     0,     0,
       0,   262,     0,     0,     8,     0,     0,     0,     0,     0,
       0,     0,     0,   171,     0,     0,   230,     0,     0,     0,
       0,   115,     0,     0,     0,     0,   212,     0,   113,     0,
       0,   116,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   330,   331,   332,
     333,   334,   335,   336,   337,   338,   339,   340,   341,   365,
     366,   367,   363,   364,   359,   360,   343,   368,   370,   372,
       0,   377,   378,   379,   344,   345,   346,   347,   348,   349,
     350,     0,   357,   358,   382,   383,   384,   395,   389,   385,
     386,   387,   388,   390,   391,   392,   393,   394,   396,   397,
     398,   399,   400,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   420,   421,   422,   423,
     424,   425,   426,   427,   428,   429,   430,   329,   117,   118,
     119,     0,   251,     0,     0,     0,     0,     7,     7,     0,
       7,     0,   136,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   231,   446,     0,   214,     0,     0,   213,     7,     0,
     126,   444,     0,    90,    90,    90,     0,     0,     0,     0,
       0,    90,    90,    90,    90,    90,     0,     0,     0,     0,
       0,     0,     0,     0,   208,     0,     0,   249,     0,   253,
     254,     0,     0,     0,     0,   260,     0,   202,   136,     0,
     138,   139,   137,     0,     0,     0,     0,     0,     0,   172,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   217,     0,     0,     0,     0,     0,     0,     0,   211,
       0,   114,     0,     0,     0,    91,    92,     0,    93,    94,
       0,     0,     0,    93,     0,     0,     0,     0,     0,    93,
       0,     0,     0,     0,     0,     0,    75,     0,     0,     0,
       0,     0,     0,     0,   353,   352,   351,   354,   355,   356,
       0,     7,     0,     0,     7,     0,     7,     0,     0,   141,
       0,   171,     0,   127,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   216,     0,     0,     0,     0,
     224,   230,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   210,   215,     0,     0,     0,     0,     0,     0,     0,
      47,     0,     0,    48,     0,     0,     0,     0,     0,    49,
      90,    90,    88,    89,    76,    77,    78,    79,    80,     0,
       0,     0,     0,     0,     0,     0,     7,     0,   247,     0,
       0,     0,     0,   201,   141,     0,   140,     0,   171,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     230,   230,     0,     0,     0,   230,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   259,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      81,   374,   375,   376,   416,   417,   418,     0,     7,     0,
       7,     0,     0,     0,     0,     0,   142,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    46,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    50,    51,     0,
     255,     0,   257,     0,     7,     0,     0,     0,     0,     0,
       0,   129,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   230,   230,     0,     0,   230,   230,   230,     0,
       0,   229,   230,     0,     0,     0,     0,     0,     0,   233,
     234,     0,     0,   232,     0,     0,    56,    83,     0,     0,
       0,    68,    58,     0,     0,    69,     0,    55,    82,     0,
       0,     0,     0,     0,    67,     0,     0,     0,     0,     0,
       7,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   128,     0,     0,     0,     0,     0,     0,   175,     0,
       0,   177,     0,     0,   173,     0,   189,     0,     0,   219,
     226,     0,     0,     0,   218,   225,     0,   237,   238,   236,
       0,     0,     0,     0,     0,     0,    53,    60,    86,    87,
       0,     0,    52,    59,     0,     0,    84,    85,     0,     0,
       0,   256,   258,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   183,     0,   185,     0,
     181,     0,     0,     0,   176,     0,     0,   178,     0,     0,
     174,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   235,    73,    74,    71,    72,     0,
      57,    70,     0,     0,     7,   130,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   184,   186,   182,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     179,   221,   223,   228,   220,   222,   227,   239,     0,     0,
       0,     0,     0,     0,     0,    54,     7,   131,     0,     0,
       0,     0,     0,     0,     0,   145,     0,     0,   147,     0,
       0,   143,     0,   159,     0,   187,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   180,   243,     0,
     240,   245,     0,   241,     0,     0,     0,     0,   153,     0,
     155,     0,   151,     0,     0,     0,   146,     0,     0,   148,
       0,     0,   144,     0,   188,     0,   195,     0,     0,   196,
       0,     0,   194,     0,     0,     0,     0,     0,     0,     0,
     132,   154,   156,   152,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   149,     0,   191,     0,
     192,     0,   190,     0,     0,   244,   246,   242,   133,     0,
     157,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   150,   199,   200,   198,   197,     0,   158,     0,
     165,     0,     0,   166,     0,     0,   164,     0,     0,     0,
     193,     0,   161,     0,   162,     0,   160,     0,     0,   169,
     170,   168,   167,     0,   163
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -787,  -787,  1368,  -397,   795,  -787,  -787,  -645,  -787,   200,
    -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,
    -787,  -787,  -655,   461,  -787,  -786,  -787,  -787,  -787,  -787,
    -787,  -787,  -787,  -787,  -787,  -787,  -787,  1100,  -570,  -787,
    -603,  -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,  -787,
    -787,  -787,  1299,  -787,  -787,  -787,   -10,  -787,  1330,  1318,
    1599,   136,   406,    20,  -787,  1493,    -6,  -787,  1373,  -787,
    4442
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,   418,   594,    58,    59,   841,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,   425,   431,   955,  1026,   739,   809,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,   615,   616,    83,
     610,   751,    84,   722,   787,   788,    85,    86,    87,    88,
      89,   416,   417,   592,    90,    91,   437,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   110,   239,   444,   445,
     438
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     229,   447,  1166,   742,   244,  1169,   242,  1233,  1236,   249,
     246,   251,   252,   253,   585,   586,   587,  1172,   254,  1288,
    1313,  1316,   595,  1319,   260,   261,   262,   263,    -3,     6,
    1394,  1239,     7,     8,     9,   426,   427,   428,   429,  1336,
    1355,   602,  1358,  1361,   873,   757,  1225,  1227,   875,   269,
    1229,  1324,   439,  1347,     5,  1167,  1421,  1349,  1170,    10,
      11,    12,    13,    14,    15,  1351,    16,    17,  1409,     1,
    1173,   604,  1289,  1314,  1317,   456,  1320,   799,    18,    19,
      20,   899,  1253,  1395,   748,    92,    21,   814,   756,   749,
      22,    23,   749,    24,   458,   957,   614,   827,    25,   457,
      93,   294,    26,    27,    28,   614,   111,    29,  1254,    30,
     259,    31,    32,    33,    34,  1117,  1118,   459,    35,   845,
     851,   245,    36,  1023,  1083,    37,   857,   858,   859,   860,
     861,   806,   270,   247,  1024,  1024,   432,   433,   434,  1027,
     807,  1092,  1119,   878,   270,    38,  1047,  1104,   807,  1105,
     807,   749,   749,   250,   749,   276,   277,   278,   279,   280,
     281,   282,   283,   284,   285,  1109,  1242,  1121,  1122,  1243,
     749,   749,  1028,   605,   749,   398,   399,  1226,  1228,   255,
     440,  1230,  1325,   757,  1348,    34,  1168,   256,  1350,  1171,
     257,  1234,  1237,   258,  1123,  1244,  1352,   267,   606,  1410,
     749,  1174,   874,  1290,  1315,  1318,   876,  1321,   900,   750,
     272,   241,   750,   243,  1396,  1240,    38,   384,   448,   603,
     386,    39,    40,  1337,  1356,    41,  1359,  1362,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,   435,
    1422,   408,    53,   415,   590,    54,   286,   798,   264,    55,
    1245,    56,  1246,  1025,  1025,   749,   271,   749,   265,   808,
    1247,   443,   446,   266,   436,   749,   268,   808,   402,   808,
     296,   750,   750,   382,   750,   611,   612,   395,   387,   885,
     886,   887,   888,   637,   612,  1008,  1009,   396,   397,   297,
     750,   750,    39,    40,   750,   400,    41,   388,   977,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
    1086,  1087,  1088,  1089,   503,   504,   505,   506,   638,   612,
     750,   298,   240,   639,   612,   514,   426,   427,   428,   429,
     793,   794,   299,   796,   300,   833,   834,   287,   288,   289,
     290,   291,   292,  1129,  1130,   301,   835,   836,   837,   743,
     744,   302,   838,   839,   745,   544,   545,   546,   547,   403,
     293,   830,  1131,   430,   401,   550,   551,  1040,  1041,   889,
     640,   612,  1045,   561,   559,   750,   303,   750,    -2,     6,
     842,   404,     7,     8,     9,   750,   641,   612,  1142,  1143,
     835,   836,   579,   580,   304,   582,   843,   839,   581,   305,
    1090,   273,   274,   275,   588,   589,   840,  1144,   306,    10,
      11,    12,    13,    14,    15,   389,    16,    17,   575,   576,
     577,   846,   847,   390,   391,   392,   393,   394,    18,    19,
      20,   617,   835,   836,   848,   307,    21,   308,   849,   839,
      22,    23,   309,    24,   810,   811,   995,   996,    25,   812,
     844,   997,    26,    27,    28,  1002,  1003,    29,   310,    30,
    1004,    31,    32,    33,    34,   642,   612,   311,    35,  1005,
    1006,   312,    36,   313,   947,    37,   314,   950,   315,   952,
     835,   836,   835,   836,   643,   612,   843,   839,   843,   839,
     644,   612,   850,   645,   612,    38,   646,   612,   316,  1177,
    1178,   647,   612,  1181,  1182,  1183,    94,    95,   317,  1186,
      96,   648,   612,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   318,   566,   567,   568,   569,   570,
     571,   572,   649,   612,   319,   108,   109,   650,   612,   320,
    1007,   778,   779,   780,   781,   782,   783,   651,   612,  1017,
     940,   941,   942,   943,   944,   945,   823,   824,   825,   826,
     426,   427,   428,   429,   903,   904,   905,   906,   652,   612,
     321,    39,    40,   653,   612,    41,   322,   721,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,   654,
     612,   323,    53,   655,   612,    54,   656,   612,   324,    55,
     325,    56,   752,   959,   960,   961,   962,   405,     6,   326,
     761,     7,     8,     9,  1152,  1153,  1154,  1155,   657,   612,
     327,  1079,   328,  1081,   410,   658,   612,   659,   612,   664,
     612,   665,   612,   666,   612,   667,   612,   329,    10,    11,
      12,    13,    14,    15,   330,    16,    17,   668,   612,   331,
     777,   669,   612,   670,   612,   672,   612,   332,    19,    20,
     673,   612,   674,   612,   333,    21,  -248,  -248,  -248,    22,
      23,   406,    24,   675,   612,   676,   612,    25,   677,   612,
     334,    26,    27,    28,   678,   612,    29,  1151,    30,   335,
      31,    32,    33,    34,   679,   612,   336,    35,   680,   612,
     337,    36,   681,   612,    37,   682,   612,   683,   612,   684,
     612,   685,   612,   686,   612,   791,   792,   687,   612,   688,
     612,   689,   612,   338,    38,   690,   612,   691,   612,   692,
     612,   693,   612,   694,   612,   695,   612,   696,   612,   697,
     612,   698,   612,   699,   612,   828,   700,   612,   708,   612,
     709,   612,   339,  1213,   710,   612,   711,   612,   414,   712,
     612,   713,   612,   714,   612,   716,   612,   340,   396,   397,
     725,   726,   341,   754,   755,   870,   785,   786,   819,   820,
     893,   894,  1279,  1280,  1282,  1283,  1285,  1286,  1298,  1299,
    1301,  1302,  1385,  1386,  1388,  1389,  1391,  1392,    57,    57,
      39,    40,   573,   574,    41,   342,   343,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,   344,   345,
     346,    53,   347,   348,    54,   349,   350,   351,    55,   352,
      56,   353,   415,   354,   355,   356,   424,   357,   358,   359,
     360,   361,   362,   363,   364,   365,   366,   367,   368,   369,
     370,   371,   372,   373,   374,   375,   376,   377,   378,   379,
     380,   381,   383,   949,   407,   951,   409,  1308,   411,   412,
       6,   413,   419,     7,     8,     9,   420,   421,   422,   423,
     441,   449,   442,   450,   451,   636,   452,   548,   729,   453,
     454,   455,   460,   461,   462,   578,   614,   463,   464,   465,
      10,    11,    12,    13,    14,    15,   990,    16,    17,  1345,
     466,   994,   467,   468,   469,   999,   470,   471,   484,   732,
      19,    20,   485,   491,   492,   493,   549,    21,   563,   583,
     597,    22,    23,   584,    24,   596,   598,   613,   599,    25,
    -263,  -263,  -263,    26,    27,    28,   618,   600,    29,   601,
      30,   607,    31,    32,    33,    34,   608,   609,   622,    35,
     619,   621,   620,    36,     6,   623,    37,     7,     8,     9,
     624,   625,   628,   626,   629,   627,   630,   759,   631,  1058,
     632,   633,  1061,   634,   635,   661,    38,   746,  1067,   660,
     733,  1070,   662,   663,    10,    11,    12,    13,    14,    15,
     671,    16,    17,   701,   702,   703,   704,   705,   706,   707,
     715,   717,   718,   719,    19,    20,   720,   738,   727,   728,
     730,    21,  -250,  -250,  -250,    22,    23,   734,    24,   735,
     736,   740,   747,    25,   737,   762,   741,    26,    27,    28,
     758,   760,    29,   766,    30,   784,    31,    32,    33,    34,
     763,   764,   765,    35,   767,   768,   769,    36,   770,   771,
      37,   772,    39,    40,   773,  1146,    41,   774,   775,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      38,   776,   789,    53,   790,   795,    54,   797,   805,   800,
      55,   801,    56,   802,   813,   803,   804,   872,   815,   816,
     817,   821,   822,   818,   829,   831,   832,   852,   853,   863,
     854,   855,   856,   862,   898,   915,   864,   880,   865,   866,
     867,   868,   869,   871,   879,   881,   884,   883,   914,   882,
     896,   897,   890,   891,   892,  1208,   895,   901,   902,   918,
     907,   908,   909,   911,   910,   912,   916,   924,   917,   919,
     920,   921,   923,   922,   927,   925,    39,    40,   926,   928,
      41,   929,   930,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,   931,   932,   933,    53,     6,   934,
      54,     7,     8,     9,    55,   935,    56,   936,   937,   938,
    1043,  1044,   946,   948,   939,   953,   954,   956,   958,   963,
     968,   964,   965,   966,   967,   969,   970,   971,    10,    11,
      12,    13,    14,    15,  1214,    16,    17,   972,   973,   974,
     976,   975,   978,   983,   979,   980,   981,   982,    19,    20,
     984,   985,   986,   988,   989,    21,   987,   991,  1010,    22,
      23,   992,    24,   993,  1000,     6,   998,    25,     7,     8,
       9,    26,    27,    28,  1001,  1018,    29,  1011,    30,  1012,
      31,    32,    33,    34,  1013,  1014,  1029,    35,  1215,  1015,
    1016,    36,  1020,  1030,    37,    10,    11,    12,    13,    14,
      15,  1262,    16,    17,  1031,  1032,  1033,  1034,  1035,  1036,
    1037,  1038,  1048,  1057,    38,    19,    20,  1046,  1039,  1042,
    1049,  1050,    21,  1051,  1052,  1053,    22,    23,  1054,    24,
    1074,  1055,  1075,  1056,    25,  1064,  1059,  1060,    26,    27,
      28,  1065,  1076,    29,  1062,    30,  1063,    31,    32,    33,
      34,  1066,  1068,  1069,    35,  1263,  1071,  1072,    36,  1077,
    1073,    37,  1078,  1080,  1085,  1082,  1084,  1091,  1328,  1093,
    1094,  1095,  1096,  1097,  1331,  1334,  1124,  1365,  1133,  1098,
    1099,    38,  1100,  1101,  1102,  1103,  1106,  1107,  1108,     4,
      39,    40,  1110,  1111,    41,  1112,  1116,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,  1113,  1114,
    1115,    53,  1120,  1125,    54,  1126,  1127,  1128,    55,  1132,
      56,  1135,  1134,  1136,  1368,  1139,  1137,  1138,  1140,  1141,
    1145,  1147,  1156,  1150,  1371,  1022,  1374,  1157,  1158,  1159,
    1160,  1161,  1162,  1175,  1224,  1163,  1164,  1176,  1165,  1179,
    1180,  1184,  1185,  1187,  1188,  1189,  1190,    39,    40,  1191,
    1192,    41,  1193,  1194,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,  1195,  1196,  1197,    53,     6,
    1198,    54,     7,     8,     9,    55,  1199,    56,  1200,  1202,
    1201,  1204,  1203,  1205,  1206,  1207,  1209,  1211,  1212,  1210,
    1220,  1216,  1217,  1218,  1219,  1221,  1222,  1223,  1231,    10,
      11,    12,    13,    14,    15,  1232,    16,    17,  1235,  1238,
    1249,  1241,  1248,  1250,  1251,  1255,  1252,  1266,  1404,    19,
      20,  1256,  1257,  1258,  1267,  1260,    21,  1259,  1261,  1264,
      22,    23,  1265,    24,  1268,  1269,     6,  1270,    25,     7,
       8,     9,    26,    27,    28,   593,  1271,    29,  1272,    30,
    1273,    31,    32,    33,    34,  1274,  1275,  1276,    35,  1277,
    1291,  1278,    36,  1281,  1284,    37,    10,    11,    12,    13,
      14,    15,  1287,    16,    17,  1292,  1293,  1294,  1295,  1296,
    1297,  1322,  1305,  1306,  1300,    38,    19,    20,  1303,  1304,
    1307,  1309,  1310,    21,  1311,  1323,  1312,    22,    23,   723,
      24,  1326,  1327,  1335,  1329,    25,  1330,  1338,  1332,    26,
      27,    28,  1333,  1339,    29,  1340,    30,  1341,    31,    32,
      33,    34,  1342,  1343,  1344,    35,  1353,  1363,  1354,    36,
    1357,  1413,    37,  1360,  1364,  1366,  1367,  1369,  1372,  1370,
    1380,  1416,  1373,  1375,  1419,  1376,  1377,  1378,  1381,  1382,
    1383,  1411,    38,  1429,  1384,  1387,  1390,  1393,  1398,  1397,
    1399,    39,    40,  1400,  1401,    41,  1402,  1403,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,  1405,
    1406,  1407,    53,  1408,  1432,    54,  1414,  1412,  1415,    55,
    1417,    56,  1418,  1420,  1423,  1427,  1424,  1425,  1426,  1428,
    1430,  1435,  1438,  1433,  1448,  1431,  1436,  1434,  1437,  1439,
    1440,  1441,  1442,  1444,  1443,  1446,   565,  1445,  1449,  1447,
    1450,  1451,  1452,   753,  1454,   591,  1453,   564,    39,    40,
     295,   385,    41,     0,     0,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,     0,     0,     0,    53,
       6,     0,    54,     7,     8,     9,    55,     0,    56,     0,
       0,     0,     0,     0,     0,     0,   562,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,    12,    13,    14,    15,     0,    16,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      19,    20,     0,     0,     0,     0,     0,    21,     0,     0,
       0,    22,    23,   724,    24,     0,     0,     6,     0,    25,
       7,     8,     9,    26,    27,    28,     0,     0,    29,     0,
      30,     0,    31,    32,    33,    34,     0,     0,     0,    35,
       0,     0,     0,    36,     0,     0,    37,    10,    11,    12,
      13,    14,    15,     0,    16,    17,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,    19,    20,     0,
       0,     0,     0,     0,    21,     0,     0,     0,    22,    23,
       0,    24,     0,     0,     0,     0,    25,     0,     0,     0,
      26,    27,    28,     0,     0,    29,   731,    30,     0,    31,
      32,    33,    34,     0,     0,     0,    35,     0,     0,     0,
      36,     0,     0,    37,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,     0,     0,     0,     0,     0,     0,
       0,     0,    39,    40,     0,     0,    41,     0,     0,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
       0,     0,     0,    53,     0,     0,    54,     0,     0,     0,
      55,     0,    56,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    39,
      40,     0,     0,    41,     0,     0,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,     0,     0,     0,
      53,     6,     0,    54,     7,     8,     9,    55,     0,    56,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,    12,    13,    14,    15,     0,    16,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    19,    20,     0,     0,     0,     0,     0,    21,     0,
       0,     0,    22,    23,     0,    24,     0,     0,     0,     0,
      25,     0,     0,  -265,    26,    27,    28,     0,     0,    29,
       0,    30,     0,    31,    32,    33,    34,     0,     0,     0,
      35,     0,     0,     0,    36,     6,     0,    37,     7,     8,
       9,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,     0,     0,
       0,     0,     0,     0,     0,    10,    11,    12,    13,    14,
      15,     0,    16,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    19,    20,     0,     0,     0,
       0,     0,    21,     0,     0,     0,    22,    23,     0,    24,
       0,     0,     0,     0,    25,     0,     0,     0,    26,    27,
      28,     0,   877,    29,     0,    30,     0,    31,    32,    33,
      34,     0,     0,     0,    35,     0,     0,     0,    36,     0,
       0,    37,     0,    39,    40,     0,     0,    41,     0,     0,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    38,     0,     0,    53,     0,     0,    54,     0,     0,
       0,    55,     0,    56,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    39,    40,     0,
       0,    41,     0,     0,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,     0,     0,     0,    53,     6,
       0,    54,     7,     8,     9,    55,     0,    56,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
      11,    12,    13,    14,    15,     0,    16,    17,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    19,
      20,     0,     0,     0,     0,     0,    21,     0,     0,     0,
      22,    23,     0,    24,   913,     0,     6,     0,    25,     7,
       8,     9,    26,    27,    28,     0,     0,    29,     0,    30,
       0,    31,    32,    33,    34,     0,     0,     0,    35,     0,
       0,     0,    36,     0,     0,    37,    10,    11,    12,    13,
      14,    15,     0,    16,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,    19,    20,     0,     0,
       0,     0,     0,    21,     0,     0,  -252,    22,    23,     0,
      24,     0,     0,     0,     0,    25,     0,     0,     0,    26,
      27,    28,     0,     0,    29,     0,    30,     0,    31,    32,
      33,    34,     0,     0,     0,    35,     0,     0,     0,    36,
       0,     0,    37,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,     0,     0,     0,     0,     0,
       0,    39,    40,     0,     0,    41,     0,     0,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,     0,
       0,     0,    53,     0,     0,    54,     0,     0,     0,    55,
       0,    56,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    39,    40,
       0,     0,    41,     0,     0,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,     0,     0,     0,    53,
       6,     0,    54,     7,     8,     9,    55,     0,    56,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      10,    11,    12,    13,    14,    15,     0,    16,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      19,    20,     0,     0,     0,     0,     0,    21,     0,     0,
       0,    22,    23,     0,    24,  1019,     0,     6,     0,    25,
       7,     8,     9,    26,    27,    28,     0,     0,    29,     0,
      30,     0,    31,    32,    33,    34,     0,     0,     0,    35,
       0,     0,     0,    36,     0,     0,    37,    10,    11,    12,
      13,    14,    15,     0,    16,    17,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,    19,    20,     0,
       0,     0,     0,     0,    21,     0,     0,     0,    22,    23,
       0,    24,  1021,     0,     0,     0,    25,     0,     0,     0,
      26,    27,    28,     0,     0,    29,     0,    30,     0,    31,
      32,    33,    34,     0,     0,     0,    35,     0,     0,     0,
      36,     0,     0,    37,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,     0,     0,     0,     0,     0,     0,
       0,     0,    39,    40,     0,     0,    41,     0,     0,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
       0,     0,     0,    53,     0,     0,    54,     0,     0,     0,
      55,     0,    56,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    39,
      40,     0,     0,    41,     0,     0,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,     0,     0,     0,
      53,     6,     0,    54,     7,     8,     9,    55,     0,    56,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,    12,    13,    14,    15,     0,    16,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    19,    20,     0,     0,     0,     0,     0,    21,     0,
       0,     0,    22,    23,     0,    24,  1148,     0,     6,     0,
      25,     7,     8,     9,    26,    27,    28,     0,     0,    29,
       0,    30,     0,    31,    32,    33,    34,     0,     0,     0,
      35,     0,     0,     0,    36,     0,     0,    37,    10,    11,
      12,    13,    14,    15,     0,    16,    17,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,    19,    20,
       0,     0,     0,     0,     0,    21,     0,     0,     0,    22,
      23,     0,    24,  1149,     0,     0,     0,    25,     0,     0,
       0,    26,    27,    28,     0,     0,    29,     0,    30,     0,
      31,    32,    33,    34,     0,     0,     0,    35,     0,     0,
       0,    36,     0,     0,    37,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,     0,     0,     0,     0,     0,
       0,     0,     0,    39,    40,     0,     0,    41,     0,     0,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,     0,     0,     0,    53,     0,     0,    54,     0,     0,
       0,    55,     0,    56,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      39,    40,     0,     0,    41,     0,     0,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,     0,     0,
       0,    53,     6,     0,    54,     7,     8,     9,    55,     0,
      56,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,    11,    12,    13,    14,    15,     0,    16,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    19,    20,     0,     0,     0,     0,     0,    21,
       0,     0,     0,    22,    23,     0,    24,     0,     0,     6,
       0,    25,     7,     8,     9,    26,    27,    28,     0,     0,
      29,     0,    30,     0,    31,    32,    33,    34,     0,     0,
       0,    35,  1346,     0,     0,    36,     0,     0,    37,    10,
      11,    12,    13,    14,    15,     0,    16,    17,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,    19,
      20,     0,     0,     0,     0,     0,    21,     0,     0,     0,
      22,    23,     0,    24,     0,     0,     0,     0,    25,     0,
       0,     0,    26,    27,    28,     0,     0,    29,     0,    30,
       0,    31,    32,    33,    34,     0,     0,     0,    35,  1379,
       0,     0,    36,     0,     0,    37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,     0,     0,     0,     0,
       0,     0,     0,     0,    39,    40,     0,     0,    41,     0,
       0,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,     0,     0,     0,    53,     0,     0,    54,   112,
       0,     0,    55,     0,    56,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   113,     0,     0,     0,     0,     0,     0,
       0,   114,   115,   116,   117,   118,     0,     0,     0,     0,
       0,    39,    40,     0,     0,    41,     0,     0,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,     0,
     119,     0,    53,     0,   120,    54,     0,   121,     0,    55,
       0,    56,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,     0,     0,   211,     0,     0,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   112,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   223,   224,   225,   226,   248,     0,   227,     0,     0,
       0,   228,     0,   113,     0,     0,     0,     0,     0,     0,
       0,   114,   115,   116,   117,   118,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     119,     0,     0,     0,   120,     0,     0,   121,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,     0,     0,   211,     0,     0,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   112,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   223,   224,   225,   226,     0,     0,   227,   497,     0,
       0,   228,     0,   113,     0,     0,     0,     0,     0,     0,
       0,   114,   115,   116,   117,   118,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     119,     0,     0,     0,   120,     0,     0,   121,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,     0,     0,   211,     0,     0,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   112,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   223,   224,   225,   226,     0,     0,   227,   499,     0,
       0,   228,     0,   113,     0,     0,     0,     0,     0,     0,
       0,   114,   115,   116,   117,   118,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     119,     0,     0,     0,   120,     0,     0,   121,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,     0,     0,   211,     0,     0,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   112,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   223,   224,   225,   226,     0,     0,   227,   501,     0,
       0,   228,     0,   113,     0,     0,     0,     0,     0,     0,
       0,   114,   115,   116,   117,   118,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     119,     0,     0,     0,   120,     0,     0,   121,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,     0,     0,   211,     0,     0,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   112,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   223,   224,   225,   226,     0,     0,   227,     0,     0,
       0,   228,     0,   113,     0,     0,     0,     0,     0,     0,
       0,   114,   115,   116,   117,   118,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     119,     0,     0,     0,   120,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,     0,     0,   211,     0,     0,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   112,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   223,   224,   225,   226,     0,     0,   227,     0,     0,
       0,   228,     0,   113,     0,     0,     0,     0,     0,     0,
       0,   114,   115,   116,   117,   118,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     119,     0,     0,     0,   120,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   122,   123,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,     0,     0,   211,     0,     0,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   223,   224,   225,   226,     0,     0,   227,   472,   473,
     474,   475,   476,   477,   478,   479,   480,   481,   482,   483,
       0,     0,   486,   487,   488,   489,   490,     0,     0,     0,
     494,   495,   496,   498,   500,   502,     0,     0,     0,     0,
     507,   508,   509,   510,   511,   512,   513,     0,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,     0,     0,     0,
       0,     0,     0,     0,     0,   552,   553,   554,   555,   556,
     557,   558,     0,   560
};

static const yytype_int16 yycheck[] =
{
      10,    10,    43,   606,    14,    43,    12,    43,    43,    19,
      16,    21,    22,    23,   411,   412,   413,    43,    24,    43,
      43,    43,   419,    43,    30,    31,    32,    33,     0,     1,
      43,    43,     4,     5,     6,    11,    12,    13,    14,    43,
      43,    49,    43,    43,    69,   615,    96,    96,    69,    55,
      96,    96,    99,    96,     0,    96,    43,    96,    96,    31,
      32,    33,    34,    35,    36,    96,    38,    39,    96,     3,
      96,   100,    96,    96,    96,   203,    96,   732,    50,    51,
      52,   100,   201,    96,    98,   227,    58,    98,   215,   103,
      62,    63,   103,    65,   204,   881,   223,   215,    70,   227,
     223,   111,    74,    75,    76,   223,   223,    79,   227,    81,
     223,    83,    84,    85,    86,   200,   201,   227,    90,   764,
     765,   227,    94,    93,    93,    97,   771,   772,   773,   774,
     775,    95,   105,   229,   104,   104,    99,   100,   101,    95,
     104,    95,   227,   798,   105,   117,    98,    98,   104,    98,
     104,   103,   103,   228,   103,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    98,    98,   200,   201,    98,
     103,   103,   958,   202,   103,   234,   235,   227,   227,   227,
     227,   227,   227,   753,   227,    86,   227,   227,   227,   227,
     227,   227,   227,   227,   227,    98,   227,   229,   227,   227,
     103,   227,   227,   227,   227,   227,   227,   227,   227,   223,
     228,    11,   223,    13,   227,   227,   117,   227,   227,   227,
     227,   193,   194,   227,   227,   197,   227,   227,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   202,
     227,   247,   214,    71,    72,   217,   102,   223,   223,   221,
      98,   223,    98,   223,   223,   103,   229,   103,   223,   223,
      98,   271,   272,   223,   227,   103,   223,   223,   229,   223,
     229,   223,   223,   226,   223,   230,   231,   222,    88,    11,
      12,    13,    14,   230,   231,   930,   931,   232,   233,   229,
     223,   223,   193,   194,   223,   218,   197,    87,   901,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
      11,    12,    13,    14,   324,   325,   326,   327,   230,   231,
     223,   229,   223,   230,   231,   335,    11,    12,    13,    14,
     727,   728,   229,   730,   229,    29,    30,   193,   194,   195,
     196,   197,   198,   208,   209,   229,    40,    41,    42,   219,
     220,   229,    46,    47,   224,   365,   366,   367,   368,   228,
     216,   758,   227,    48,   105,   371,   372,   970,   971,   101,
     230,   231,   975,   383,   380,   223,   229,   223,     0,     1,
      30,   228,     4,     5,     6,   223,   230,   231,   208,   209,
      40,    41,   402,   403,   229,   405,    46,    47,   404,   229,
     101,     7,     8,     9,   414,   415,   100,   227,   229,    31,
      32,    33,    34,    35,    36,   228,    38,    39,   398,   399,
     400,    29,    30,   236,   237,   238,   239,   240,    50,    51,
      52,   441,    40,    41,    42,   229,    58,   229,    46,    47,
      62,    63,   229,    65,   219,   220,   219,   220,    70,   224,
     100,   224,    74,    75,    76,   219,   220,    79,   229,    81,
     224,    83,    84,    85,    86,   230,   231,   229,    90,    29,
      30,   229,    94,   229,   871,    97,   229,   874,   229,   876,
      40,    41,    40,    41,   230,   231,    46,    47,    46,    47,
     230,   231,   100,   230,   231,   117,   230,   231,   229,  1102,
    1103,   230,   231,  1106,  1107,  1108,   193,   194,   229,  1112,
     197,   230,   231,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   229,   389,   390,   391,   392,   393,
     394,   395,   230,   231,   229,   222,   223,   230,   231,   229,
     100,    22,    23,    24,    25,    26,    27,   230,   231,   946,
      22,    23,    24,    25,    26,    27,    11,    12,    13,    14,
      11,    12,    13,    14,    11,    12,    13,    14,   230,   231,
     229,   193,   194,   230,   231,   197,   229,   583,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   230,
     231,   229,   214,   230,   231,   217,   230,   231,   229,   221,
     229,   223,   612,    11,    12,    13,    14,   228,     1,   229,
     620,     4,     5,     6,    11,    12,    13,    14,   230,   231,
     229,  1018,   229,  1020,    53,   230,   231,   230,   231,   230,
     231,   230,   231,   230,   231,   230,   231,   229,    31,    32,
      33,    34,    35,    36,   229,    38,    39,   230,   231,   229,
     660,   230,   231,   230,   231,   230,   231,   229,    51,    52,
     230,   231,   230,   231,   229,    58,    59,    60,    61,    62,
      63,   227,    65,   230,   231,   230,   231,    70,   230,   231,
     229,    74,    75,    76,   230,   231,    79,  1084,    81,   229,
      83,    84,    85,    86,   230,   231,   229,    90,   230,   231,
     229,    94,   230,   231,    97,   230,   231,   230,   231,   230,
     231,   230,   231,   230,   231,   725,   726,   230,   231,   230,
     231,   230,   231,   229,   117,   230,   231,   230,   231,   230,
     231,   230,   231,   230,   231,   230,   231,   230,   231,   230,
     231,   230,   231,   230,   231,   755,   230,   231,   230,   231,
     230,   231,   229,  1150,   230,   231,   230,   231,   228,   230,
     231,   230,   231,   230,   231,   230,   231,   229,   232,   233,
      67,    68,   229,   227,   228,   785,    59,    60,   230,   231,
     230,   231,    44,    45,    44,    45,    44,    45,   230,   231,
     230,   231,    44,    45,    44,    45,    44,    45,     3,     4,
     193,   194,   396,   397,   197,   229,   229,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   229,   229,
     229,   214,   229,   229,   217,   229,   229,   229,   221,   229,
     223,   229,    71,   229,   229,   229,    46,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   873,   227,   875,   227,  1264,   227,   227,
       1,   227,   227,     4,     5,     6,   227,   227,   227,   227,
     222,   227,   223,   227,   229,   199,   229,   223,    73,   229,
     229,   229,   227,   227,   227,   223,   223,   229,   229,   229,
      31,    32,    33,    34,    35,    36,   916,    38,    39,  1306,
     229,   921,   229,   229,   229,   925,   227,   227,   230,    92,
      51,    52,   230,   230,   230,   230,   230,    58,   230,   230,
     229,    62,    63,   227,    65,   227,   229,   227,   229,    70,
      71,    72,    73,    74,    75,    76,   230,   229,    79,   229,
      81,   229,    83,    84,    85,    86,   229,   229,   229,    90,
     230,   227,   231,    94,     1,   224,    97,     4,     5,     6,
     224,   224,   229,   224,   229,   224,   223,   105,   224,   989,
     224,   224,   992,   224,   224,   230,   117,   223,   998,   231,
     224,  1001,   230,   230,    31,    32,    33,    34,    35,    36,
     231,    38,    39,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   227,   227,    51,    52,   227,   229,   227,   227,
     227,    58,    59,    60,    61,    62,    63,   224,    65,   224,
     224,   229,   223,    70,   226,   234,   229,    74,    75,    76,
     227,   227,    79,   231,    81,   227,    83,    84,    85,    86,
     230,   230,   230,    90,   231,   223,   223,    94,   230,   230,
      97,   230,   193,   194,   230,  1075,   197,   230,   230,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     117,   231,   227,   214,   227,   227,   217,   227,   226,   230,
     221,   230,   223,   230,   223,   231,   230,    61,   231,   231,
     230,   227,   223,   230,   227,   223,   231,   224,   224,   231,
     230,   230,   227,   226,    99,    30,   230,   224,   230,   230,
     230,   230,   230,   227,   227,   227,   223,   227,   234,   230,
     224,   224,   231,   231,   230,  1145,   227,   227,   224,    30,
     229,   229,   229,   227,   229,   227,   229,    30,   229,   229,
     227,   229,   227,   229,    30,   229,   193,   194,   229,   229,
     197,   227,   230,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   230,   227,   227,   214,     1,   227,
     217,     4,     5,     6,   221,   227,   223,   227,   227,   227,
      99,    99,   227,   227,   230,   227,   227,   230,   227,   229,
     224,   229,   229,   229,   229,   224,   227,   227,    31,    32,
      33,    34,    35,    36,    37,    38,    39,   224,   230,   230,
     229,   227,   230,   224,   229,   229,   229,   229,    51,    52,
     224,   224,   224,   230,   229,    58,   227,   223,   227,    62,
      63,   229,    65,   224,   223,     1,   229,    70,     4,     5,
       6,    74,    75,    76,   229,   227,    79,   230,    81,   230,
      83,    84,    85,    86,   230,   230,   229,    90,    91,   230,
     230,    94,   227,   229,    97,    31,    32,    33,    34,    35,
      36,    37,    38,    39,   229,   229,   224,   224,   224,   224,
     223,   230,    99,   227,   117,    51,    52,   224,   230,   230,
     224,   224,    58,   224,   224,   230,    62,    63,   230,    65,
      30,   230,   229,   231,    70,   231,   230,   230,    74,    75,
      76,   231,   229,    79,   230,    81,   230,    83,    84,    85,
      86,   230,   230,   230,    90,    91,   231,   231,    94,   227,
     230,    97,   227,   227,   223,   227,   227,   227,    44,   224,
     224,   224,   224,   230,    44,    44,   224,    45,   224,   230,
     230,   117,   231,   230,   227,   227,   227,   227,   227,     1,
     193,   194,   230,   227,   197,   227,   231,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   230,   230,
     230,   214,   227,   230,   217,   227,   227,   230,   221,   227,
     223,   227,   224,   230,    45,   230,   227,   227,   224,   224,
     229,   224,   229,   227,    45,   954,    45,   229,   229,   229,
     229,   227,   230,   224,   223,   230,   230,   227,   231,   227,
     227,   227,   227,   227,   227,   227,   224,   193,   194,   229,
     229,   197,   229,   229,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   230,   227,   227,   214,     1,
     227,   217,     4,     5,     6,   221,   227,   223,   230,   227,
     230,   230,   227,   230,   227,   227,   230,   227,   227,   230,
     224,   229,   229,   229,   229,   224,   224,   224,   224,    31,
      32,    33,    34,    35,    36,   229,    38,    39,   229,   229,
     223,   230,   230,   224,   223,   227,   224,   224,    44,    51,
      52,   227,   227,   227,   224,   227,    58,   230,   227,   227,
      62,    63,   227,    65,   224,   224,     1,   230,    70,     4,
       5,     6,    74,    75,    76,    77,   230,    79,   230,    81,
     231,    83,    84,    85,    86,   230,   227,   227,    90,   227,
     227,   230,    94,   229,   229,    97,    31,    32,    33,    34,
      35,    36,   229,    38,    39,   227,   227,   227,   227,   227,
     227,   224,   227,   227,   230,   117,    51,    52,   230,   229,
     227,   230,   230,    58,   230,   227,   231,    62,    63,    64,
      65,   231,   230,   229,   231,    70,   230,   227,   231,    74,
      75,    76,   230,   224,    79,   227,    81,   227,    83,    84,
      85,    86,   224,   227,   224,    90,   224,   230,   229,    94,
     229,    44,    97,   229,   227,   227,   230,   227,   227,   230,
     227,    44,   230,   229,    44,   230,   230,   230,   227,   227,
     227,   231,   117,    45,   230,   229,   229,   229,   227,   230,
     230,   193,   194,   227,   230,   197,   227,   230,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   227,
     227,   227,   214,   227,    45,   217,   231,   230,   230,   221,
     231,   223,   230,   229,   227,   230,   227,   227,   227,   227,
     227,    45,    45,   227,    44,   230,   227,   230,   230,   229,
     227,   230,   227,   227,   230,   227,   388,   230,   227,   230,
     227,   227,   227,   613,   227,   416,   230,   387,   193,   194,
     121,   228,   197,    -1,    -1,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,    -1,    -1,    -1,   214,
       1,    -1,   217,     4,     5,     6,   221,    -1,   223,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   383,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,    33,    34,    35,    36,    -1,    38,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    52,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,
      -1,    62,    63,    64,    65,    -1,    -1,     1,    -1,    70,
       4,     5,     6,    74,    75,    76,    -1,    -1,    79,    -1,
      81,    -1,    83,    84,    85,    86,    -1,    -1,    -1,    90,
      -1,    -1,    -1,    94,    -1,    -1,    97,    31,    32,    33,
      34,    35,    36,    -1,    38,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   117,    51,    52,    -1,
      -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,    62,    63,
      -1,    65,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,
      74,    75,    76,    -1,    -1,    79,    80,    81,    -1,    83,
      84,    85,    86,    -1,    -1,    -1,    90,    -1,    -1,    -1,
      94,    -1,    -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   193,   194,    -1,    -1,   197,    -1,    -1,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
      -1,    -1,    -1,   214,    -1,    -1,   217,    -1,    -1,    -1,
     221,    -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   193,
     194,    -1,    -1,   197,    -1,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,    -1,
     214,     1,    -1,   217,     4,     5,     6,   221,    -1,   223,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    33,    34,    35,    36,    -1,    38,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,    -1,    -1,    -1,    -1,    -1,    58,    -1,
      -1,    -1,    62,    63,    -1,    65,    -1,    -1,    -1,    -1,
      70,    -1,    -1,    73,    74,    75,    76,    -1,    -1,    79,
      -1,    81,    -1,    83,    84,    85,    86,    -1,    -1,    -1,
      90,    -1,    -1,    -1,    94,     1,    -1,    97,     4,     5,
       6,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    31,    32,    33,    34,    35,
      36,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    51,    52,    -1,    -1,    -1,
      -1,    -1,    58,    -1,    -1,    -1,    62,    63,    -1,    65,
      -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    74,    75,
      76,    -1,    78,    79,    -1,    81,    -1,    83,    84,    85,
      86,    -1,    -1,    -1,    90,    -1,    -1,    -1,    94,    -1,
      -1,    97,    -1,   193,   194,    -1,    -1,   197,    -1,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   117,    -1,    -1,   214,    -1,    -1,   217,    -1,    -1,
      -1,   221,    -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   193,   194,    -1,
      -1,   197,    -1,    -1,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,    -1,    -1,    -1,   214,     1,
      -1,   217,     4,     5,     6,   221,    -1,   223,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,
      32,    33,    34,    35,    36,    -1,    38,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      52,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,
      62,    63,    -1,    65,    66,    -1,     1,    -1,    70,     4,
       5,     6,    74,    75,    76,    -1,    -1,    79,    -1,    81,
      -1,    83,    84,    85,    86,    -1,    -1,    -1,    90,    -1,
      -1,    -1,    94,    -1,    -1,    97,    31,    32,    33,    34,
      35,    36,    -1,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   117,    51,    52,    -1,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    61,    62,    63,    -1,
      65,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,    74,
      75,    76,    -1,    -1,    79,    -1,    81,    -1,    83,    84,
      85,    86,    -1,    -1,    -1,    90,    -1,    -1,    -1,    94,
      -1,    -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   193,   194,    -1,    -1,   197,    -1,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,    -1,   214,    -1,    -1,   217,    -1,    -1,    -1,   221,
      -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   193,   194,
      -1,    -1,   197,    -1,    -1,   200,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,    -1,    -1,    -1,   214,
       1,    -1,   217,     4,     5,     6,   221,    -1,   223,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,    33,    34,    35,    36,    -1,    38,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      51,    52,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,
      -1,    62,    63,    -1,    65,    66,    -1,     1,    -1,    70,
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
      -1,    -1,   193,   194,    -1,    -1,   197,    -1,    -1,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
      -1,    -1,    -1,   214,    -1,    -1,   217,    -1,    -1,    -1,
     221,    -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   193,
     194,    -1,    -1,   197,    -1,    -1,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,    -1,    -1,    -1,
     214,     1,    -1,   217,     4,     5,     6,   221,    -1,   223,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
      63,    -1,    65,    66,    -1,    -1,    -1,    70,    -1,    -1,
      -1,    74,    75,    76,    -1,    -1,    79,    -1,    81,    -1,
      83,    84,    85,    86,    -1,    -1,    -1,    90,    -1,    -1,
      -1,    94,    -1,    -1,    97,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   117,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   193,   194,    -1,    -1,   197,    -1,    -1,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,    -1,    -1,    -1,   214,    -1,    -1,   217,    -1,    -1,
      -1,   221,    -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     193,   194,    -1,    -1,   197,    -1,    -1,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,    -1,    -1,
      -1,   214,     1,    -1,   217,     4,     5,     6,   221,    -1,
     223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    31,    32,    33,    34,    35,    36,    -1,    38,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    51,    52,    -1,    -1,    -1,    -1,    -1,    58,
      -1,    -1,    -1,    62,    63,    -1,    65,    -1,    -1,     1,
      -1,    70,     4,     5,     6,    74,    75,    76,    -1,    -1,
      79,    -1,    81,    -1,    83,    84,    85,    86,    -1,    -1,
      -1,    90,    91,    -1,    -1,    94,    -1,    -1,    97,    31,
      32,    33,    34,    35,    36,    -1,    38,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,    51,
      52,    -1,    -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,
      62,    63,    -1,    65,    -1,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    74,    75,    76,    -1,    -1,    79,    -1,    81,
      -1,    83,    84,    85,    86,    -1,    -1,    -1,    90,    91,
      -1,    -1,    94,    -1,    -1,    97,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   117,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   193,   194,    -1,    -1,   197,    -1,
      -1,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,    -1,    -1,    -1,   214,    -1,    -1,   217,    21,
      -1,    -1,   221,    -1,   223,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    54,    55,    56,    57,    -1,    -1,    -1,    -1,
      -1,   193,   194,    -1,    -1,   197,    -1,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      82,    -1,   214,    -1,    86,   217,    -1,    89,    -1,   221,
      -1,   223,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,    -1,    -1,   197,    -1,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   223,   224,   225,   226,   227,    -1,   229,    -1,    -1,
      -1,   233,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
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
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,    -1,    -1,   197,    -1,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   223,   224,   225,   226,    -1,    -1,   229,   230,    -1,
      -1,   233,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
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
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,    -1,    -1,   197,    -1,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   223,   224,   225,   226,    -1,    -1,   229,   230,    -1,
      -1,   233,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
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
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,    -1,    -1,   197,    -1,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   223,   224,   225,   226,    -1,    -1,   229,   230,    -1,
      -1,   233,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
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
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,    -1,    -1,   197,    -1,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   223,   224,   225,   226,    -1,    -1,   229,    -1,    -1,
      -1,   233,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    54,    55,    56,    57,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      82,    -1,    -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,    -1,    -1,   197,    -1,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   223,   224,   225,   226,    -1,    -1,   229,    -1,    -1,
      -1,   233,    -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    53,    54,    55,    56,    57,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      82,    -1,    -1,    -1,    86,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,    -1,    -1,   197,    -1,    -1,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   223,   224,   225,   226,    -1,    -1,   229,   296,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   307,
      -1,    -1,   310,   311,   312,   313,   314,    -1,    -1,    -1,
     318,   319,   320,   321,   322,   323,    -1,    -1,    -1,    -1,
     328,   329,   330,   331,   332,   333,   334,    -1,   336,   337,
     338,   339,   340,   341,   342,   343,   344,   345,   346,   347,
     348,   349,   350,   351,   352,   353,   354,   355,   356,   357,
     358,   359,   360,   361,   362,   363,   364,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   373,   374,   375,   376,   377,
     378,   379,    -1,   381
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,     3,   242,   243,   243,     0,     1,     4,     5,     6,
      31,    32,    33,    34,    35,    36,    38,    39,    50,    51,
      52,    58,    62,    63,    65,    70,    74,    75,    76,    79,
      81,    83,    84,    85,    86,    90,    94,    97,   117,   193,
     194,   197,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   214,   217,   221,   223,   245,   246,   247,
     249,   250,   251,   252,   253,   254,   255,   256,   257,   258,
     259,   260,   261,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   280,   283,   287,   288,   289,   290,   291,
     295,   296,   227,   223,   193,   194,   197,   200,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   222,   223,
     307,   223,    21,    45,    53,    54,    55,    56,    57,    82,
      86,    89,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,   192,   193,
     194,   197,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   223,   224,   225,   226,   229,   233,   297,
     298,   299,   300,   301,   302,   303,   304,   305,   306,   308,
     223,   250,   307,   250,   297,   227,   307,   229,   227,   297,
     228,   297,   297,   297,   307,   227,   227,   227,   227,   223,
     307,   307,   307,   307,   223,   223,   223,   229,   223,   307,
     105,   229,   228,     7,     8,     9,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,   102,   193,   194,   195,
     196,   197,   198,   216,   297,   301,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   226,   229,   297,   306,   227,    88,    87,   228,
     236,   237,   238,   239,   240,   222,   232,   233,   234,   235,
     218,   105,   229,   228,   228,   228,   227,   227,   307,   227,
      53,   227,   227,   227,   228,    71,   292,   293,   244,   227,
     227,   227,   227,   227,    46,   262,    11,    12,    13,    14,
      48,   263,    99,   100,   101,   202,   227,   297,   311,    99,
     227,   222,   223,   297,   309,   310,   297,    10,   227,   227,
     227,   229,   229,   229,   229,   229,   203,   227,   204,   227,
     227,   227,   227,   229,   229,   229,   229,   229,   229,   229,
     227,   227,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   230,   230,   311,   311,   311,   311,
     311,   230,   230,   230,   311,   311,   311,   230,   311,   230,
     311,   230,   311,   297,   297,   297,   297,   311,   311,   311,
     311,   311,   311,   311,   297,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   297,   297,   297,   297,   223,   230,
     307,   307,   311,   311,   311,   311,   311,   311,   311,   307,
     311,   297,   309,   230,   299,   300,   302,   302,   302,   302,
     302,   302,   302,   303,   303,   304,   304,   304,   223,   297,
     297,   307,   297,   230,   227,   244,   244,   244,   297,   297,
      72,   293,   294,    77,   245,   244,   227,   229,   229,   229,
     229,   229,    49,   227,   100,   202,   227,   229,   229,   229,
     281,   230,   231,   227,   223,   278,   279,   297,   230,   230,
     231,   227,   229,   224,   224,   224,   224,   224,   229,   229,
     223,   224,   224,   224,   224,   224,   199,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     231,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   231,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   230,   230,
     230,   230,   230,   230,   230,   230,   230,   230,   227,   227,
     227,   307,   284,    64,    64,    67,    68,   227,   227,    73,
     227,    80,    92,   224,   224,   224,   224,   226,   229,   266,
     229,   229,   281,   219,   220,   224,   223,   223,    98,   103,
     223,   282,   297,   278,   227,   228,   215,   279,   227,   105,
     227,   297,   234,   230,   230,   230,   231,   231,   223,   223,
     230,   230,   230,   230,   230,   230,   231,   297,    22,    23,
      24,    25,    26,    27,   227,    59,    60,   285,   286,   227,
     227,   297,   297,   244,   244,   227,   244,   227,   223,   263,
     230,   230,   230,   231,   230,   226,    95,   104,   223,   267,
     219,   220,   224,   223,    98,   231,   231,   230,   230,   230,
     231,   227,   223,    11,    12,    13,    14,   215,   297,   227,
     244,   223,   231,    29,    30,    40,    41,    42,    46,    47,
     100,   248,    30,    46,   100,   248,    29,    30,    42,    46,
     100,   248,   224,   224,   230,   230,   227,   248,   248,   248,
     248,   248,   226,   231,   230,   230,   230,   230,   230,   230,
     297,   227,    61,    69,   227,    69,   227,    78,   263,   227,
     224,   227,   230,   227,   223,    11,    12,    13,    14,   101,
     231,   231,   230,   230,   231,   227,   224,   224,    99,   100,
     227,   227,   224,    11,    12,    13,    14,   229,   229,   229,
     229,   227,   227,    66,   234,    30,   229,   229,    30,   229,
     227,   229,   229,   227,    30,   229,   229,    30,   229,   227,
     230,   230,   227,   227,   227,   227,   227,   227,   227,   230,
      22,    23,    24,    25,    26,    27,   227,   244,   227,   297,
     244,   297,   244,   227,   227,   264,   230,   266,   227,    11,
      12,    13,    14,   229,   229,   229,   229,   229,   224,   224,
     227,   227,   224,   230,   230,   227,   229,   281,   230,   229,
     229,   229,   229,   224,   224,   224,   224,   227,   230,   229,
     297,   223,   229,   224,   297,   219,   220,   224,   229,   297,
     223,   229,   219,   220,   224,    29,    30,   100,   248,   248,
     227,   230,   230,   230,   230,   230,   230,   244,   227,    66,
     227,    66,   264,    93,   104,   223,   265,    95,   266,   229,
     229,   229,   229,   224,   224,   224,   224,   223,   230,   230,
     281,   281,   230,    99,    99,   281,   224,    98,    99,   224,
     224,   224,   224,   230,   230,   230,   231,   227,   297,   230,
     230,   297,   230,   230,   231,   231,   230,   297,   230,   230,
     297,   231,   231,   230,    30,   229,   229,   227,   227,   244,
     227,   244,   227,    93,   227,   223,    11,    12,    13,    14,
     101,   227,    95,   224,   224,   224,   224,   230,   230,   230,
     231,   230,   227,   227,    98,    98,   227,   227,   227,    98,
     230,   227,   227,   230,   230,   230,   231,   200,   201,   227,
     227,   200,   201,   227,   224,   230,   227,   227,   230,   208,
     209,   227,   227,   224,   224,   227,   230,   227,   227,   230,
     224,   224,   208,   209,   227,   229,   297,   224,    66,    66,
     227,   244,    11,    12,    13,    14,   229,   229,   229,   229,
     229,   227,   230,   230,   230,   231,    43,    96,   227,    43,
      96,   227,    43,    96,   227,   224,   227,   281,   281,   227,
     227,   281,   281,   281,   227,   227,   281,   227,   227,   227,
     224,   229,   229,   229,   229,   230,   227,   227,   227,   227,
     230,   230,   227,   227,   230,   230,   227,   227,   297,   230,
     230,   227,   227,   244,    37,    91,   229,   229,   229,   229,
     224,   224,   224,   224,   223,    96,   227,    96,   227,    96,
     227,   224,   229,    43,   227,   229,    43,   227,   229,    43,
     227,   230,    98,    98,    98,    98,    98,    98,   230,   223,
     224,   223,   224,   201,   227,   227,   227,   227,   227,   230,
     227,   227,    37,    91,   227,   227,   224,   224,   224,   224,
     230,   230,   230,   231,   230,   227,   227,   227,   230,    44,
      45,   229,    44,    45,   229,    44,    45,   229,    43,    96,
     227,   227,   227,   227,   227,   227,   227,   227,   230,   231,
     230,   230,   231,   230,   229,   227,   227,   227,   244,   230,
     230,   230,   231,    43,    96,   227,    43,    96,   227,    43,
      96,   227,   224,   227,    96,   227,   231,   230,    44,   231,
     230,    44,   231,   230,    44,   229,    43,   227,   227,   224,
     227,   227,   224,   227,   224,   244,    91,    96,   227,    96,
     227,    96,   227,   224,   229,    43,   227,   229,    43,   227,
     229,    43,   227,   230,   227,    45,   227,   230,    45,   227,
     230,    45,   227,   230,    45,   229,   230,   230,   230,    91,
     227,   227,   227,   227,   230,    44,    45,   229,    44,    45,
     229,    44,    45,   229,    43,    96,   227,   230,   227,   230,
     227,   230,   227,   230,    44,   227,   227,   227,   227,    96,
     227,   231,   230,    44,   231,   230,    44,   231,   230,    44,
     229,    43,   227,   227,   227,   227,   227,   230,   227,    45,
     227,   230,    45,   227,   230,    45,   227,   230,    45,   229,
     227,   230,   227,   230,   227,   230,   227,   230,    44,   227,
     227,   227,   227,   230,   227
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   241,   242,   242,   243,   243,   243,   244,   244,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   245,   245,   245,   245,   245,   245,   245,
     245,   245,   245,   246,   246,   246,   246,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     248,   248,   248,   248,   248,   249,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   250,   250,   250,   250,
     250,   250,   250,   250,   250,   250,   251,   251,   252,   253,
     254,   255,   256,   257,   258,   258,   259,   260,   260,   260,
     261,   261,   261,   261,   262,   262,   263,   263,   263,   263,
     263,   264,   264,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   265,   265,   265,   265,   265,   265,   265,   265,   265,
     265,   266,   266,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   267,   267,   267,   267,   267,   267,   267,   267,   267,
     267,   268,   269,   270,   271,   272,   273,   274,   275,   276,
     277,   277,   278,   278,   279,   279,   280,   280,   280,   280,
     280,   280,   280,   280,   280,   280,   280,   280,   280,   280,
     281,   281,   282,   282,   282,   282,   282,   282,   282,   282,
     282,   282,   282,   282,   282,   282,   282,   283,   284,   284,
     285,   286,   286,   287,   288,   289,   289,   289,   289,   290,
     291,   292,   292,   293,   294,   294,   295,   296,   297,   298,
     298,   299,   299,   300,   300,   301,   301,   301,   301,   301,
     301,   301,   301,   302,   302,   302,   303,   303,   303,   304,
     304,   305,   305,   306,   306,   307,   307,   307,   307,   307,
     307,   307,   307,   307,   307,   307,   307,   307,   307,   307,
     307,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   308,   308,   308,   308,   308,   308,   308,   308,   308,
     308,   309,   309,   310,   310,   311,   311
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     0,     2,     2,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     4,     4,     4,    10,     8,     8,     8,
      10,    10,    12,    12,    14,    11,    11,    13,    11,    12,
      12,     4,     4,     4,     4,     4,     4,    11,    11,    11,
      13,    13,    13,    13,    13,     7,     8,     8,     8,     8,
       8,     9,    11,    11,    12,    12,    12,    12,     8,     8,
       0,     1,     1,     1,     1,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     4,     6,     4,     4,     5,     5,     5,
       3,     2,     3,     4,     3,     2,     5,     7,    11,    10,
      13,    14,    16,    17,     0,     1,     0,     4,     4,     4,
       6,     0,     2,     6,     7,     6,     7,     6,     7,     8,
       9,     7,     8,     7,     8,     7,     8,     9,    10,     6,
      11,    11,    11,    13,    10,    10,    10,    12,    12,    12,
      12,     0,     2,     6,     7,     6,     7,     6,     7,     8,
       9,     7,     8,     7,     8,     7,     8,     9,    10,     6,
      11,    11,    11,    13,    10,    10,    10,    12,    12,    12,
      12,     8,     6,     3,     3,     3,     3,     3,     6,     1,
       7,     6,     1,     2,     2,     4,     7,     6,    11,    11,
      13,    13,    13,    13,     7,    11,    11,    13,    13,    10,
       0,     2,     6,     6,     6,     8,     7,     7,     7,     9,
      10,    10,    12,    10,    12,    10,    12,     8,     0,     2,
       4,     0,     3,     6,     6,    10,    12,    10,    12,     8,
       6,     1,     2,     4,     0,     3,     2,     2,     1,     1,
       3,     1,     3,     1,     2,     1,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     1,     2,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     3,     4,     4,     4,     4,     4,     4,     4,
       4,     6,     6,     6,     6,     6,     6,     4,     4,     4,
       4,     3,     3,     4,     4,     4,     4,     4,     4,     3,
       4,     3,     4,     3,     8,     8,     8,     4,     4,     4,
       3,     3,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     3,     1,     8,     8,     8,     2,
       4,     4,     4,     4,     4,     4,     4,     4,     4,     4,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
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
#line 194 "src/parser.y"
                           {
        (yyval.program) = g_program;
    }
#line 3036 "build/parser.cpp"
    break;

  case 3: /* program: statements_opt  */
#line 197 "src/parser.y"
                     {
        (yyval.program) = g_program;
    }
#line 3044 "build/parser.cpp"
    break;

  case 5: /* statements_opt: statements_opt statement  */
#line 204 "src/parser.y"
                               {
        if ((yyvsp[0].stmt)) {
            g_program->statements.emplace_back((yyvsp[0].stmt));
        }
    }
#line 3054 "build/parser.cpp"
    break;

  case 6: /* statements_opt: statements_opt KW_CTLOPT  */
#line 209 "src/parser.y"
                               {
        if (ctlopt_nomain) g_program->nomain = true;
        if (ctlopt_main_proc[0]) g_program->main_proc = ctlopt_main_proc;
        if (ctlopt_datfmt[0]) g_program->datfmt = ctlopt_datfmt;
        if (ctlopt_timfmt[0]) g_program->timfmt = ctlopt_timfmt;
    }
#line 3065 "build/parser.cpp"
    break;

  case 7: /* statement_list: %empty  */
#line 218 "src/parser.y"
                {
        (yyval.stmt_list) = new StmtList();
    }
#line 3073 "build/parser.cpp"
    break;

  case 8: /* statement_list: statement_list statement  */
#line 221 "src/parser.y"
                               {
        (yyval.stmt_list) = (yyvsp[-1].stmt_list);
        if ((yyvsp[0].stmt)) {
            (yyval.stmt_list)->stmts.push_back((yyvsp[0].stmt));
        }
    }
#line 3084 "build/parser.cpp"
    break;

  case 9: /* statement: dcl_f_stmt  */
#line 230 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3090 "build/parser.cpp"
    break;

  case 10: /* statement: dcl_s_stmt  */
#line 231 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3096 "build/parser.cpp"
    break;

  case 11: /* statement: dcl_c_stmt  */
#line 232 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3102 "build/parser.cpp"
    break;

  case 12: /* statement: eval_stmt  */
#line 233 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3108 "build/parser.cpp"
    break;

  case 13: /* statement: eval_corr_stmt  */
#line 234 "src/parser.y"
                     { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3114 "build/parser.cpp"
    break;

  case 14: /* statement: dsply_stmt  */
#line 235 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3120 "build/parser.cpp"
    break;

  case 15: /* statement: inlr_stmt  */
#line 236 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3126 "build/parser.cpp"
    break;

  case 16: /* statement: return_stmt  */
#line 237 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3132 "build/parser.cpp"
    break;

  case 17: /* statement: if_stmt  */
#line 238 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3138 "build/parser.cpp"
    break;

  case 18: /* statement: dow_stmt  */
#line 239 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3144 "build/parser.cpp"
    break;

  case 19: /* statement: dou_stmt  */
#line 240 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3150 "build/parser.cpp"
    break;

  case 20: /* statement: for_stmt  */
#line 241 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3156 "build/parser.cpp"
    break;

  case 21: /* statement: for_each_stmt  */
#line 242 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3162 "build/parser.cpp"
    break;

  case 22: /* statement: select_stmt  */
#line 243 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3168 "build/parser.cpp"
    break;

  case 23: /* statement: iter_stmt  */
#line 244 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3174 "build/parser.cpp"
    break;

  case 24: /* statement: leave_stmt  */
#line 245 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3180 "build/parser.cpp"
    break;

  case 25: /* statement: dcl_proc_stmt  */
#line 246 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3186 "build/parser.cpp"
    break;

  case 26: /* statement: dcl_pr_stmt  */
#line 247 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3192 "build/parser.cpp"
    break;

  case 27: /* statement: dcl_ds_stmt  */
#line 248 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3198 "build/parser.cpp"
    break;

  case 28: /* statement: dcl_enum_stmt  */
#line 249 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3204 "build/parser.cpp"
    break;

  case 29: /* statement: monitor_stmt  */
#line 250 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3210 "build/parser.cpp"
    break;

  case 30: /* statement: begsr_stmt  */
#line 251 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3216 "build/parser.cpp"
    break;

  case 31: /* statement: exsr_stmt  */
#line 252 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3222 "build/parser.cpp"
    break;

  case 32: /* statement: reset_stmt  */
#line 253 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3228 "build/parser.cpp"
    break;

  case 33: /* statement: clear_stmt  */
#line 254 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3234 "build/parser.cpp"
    break;

  case 34: /* statement: sorta_stmt  */
#line 255 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3240 "build/parser.cpp"
    break;

  case 35: /* statement: evalr_stmt  */
#line 256 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3246 "build/parser.cpp"
    break;

  case 36: /* statement: callp_stmt  */
#line 257 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3252 "build/parser.cpp"
    break;

  case 37: /* statement: leavesr_stmt  */
#line 258 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3258 "build/parser.cpp"
    break;

  case 38: /* statement: dealloc_stmt  */
#line 259 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3264 "build/parser.cpp"
    break;

  case 39: /* statement: test_stmt  */
#line 260 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3270 "build/parser.cpp"
    break;

  case 40: /* statement: exec_sql_stmt  */
#line 261 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3276 "build/parser.cpp"
    break;

  case 41: /* statement: expr_stmt  */
#line 262 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3282 "build/parser.cpp"
    break;

  case 42: /* statement: error SEMICOLON  */
#line 263 "src/parser.y"
                      { (yyval.stmt) = nullptr; yyerrok; }
#line 3288 "build/parser.cpp"
    break;

  case 43: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_DISK SEMICOLON  */
#line 268 "src/parser.y"
                                          {
        (yyval.stmt) = new rpg::DclF((yyvsp[-2].sval), "DISK");
        free((yyvsp[-2].sval));
    }
#line 3297 "build/parser.cpp"
    break;

  case 44: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_PRINTER SEMICOLON  */
#line 272 "src/parser.y"
                                               {
        (yyval.stmt) = new rpg::DclF((yyvsp[-2].sval), "PRINTER");
        free((yyvsp[-2].sval));
    }
#line 3306 "build/parser.cpp"
    break;

  case 45: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_WORKSTN SEMICOLON  */
#line 276 "src/parser.y"
                                               {
        (yyval.stmt) = new rpg::DclF((yyvsp[-2].sval), "WORKSTN");
        free((yyvsp[-2].sval));
    }
#line 3315 "build/parser.cpp"
    break;

  case 46: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_DISK KW_USAGE LPAREN STAR COLON STAR RPAREN SEMICOLON  */
#line 280 "src/parser.y"
                                                                                   {
        (yyval.stmt) = new rpg::DclF((yyvsp[-8].sval), "DISK");
        free((yyvsp[-8].sval));
    }
#line 3324 "build/parser.cpp"
    break;

  case 47: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 288 "src/parser.y"
                                                                                  {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3334 "build/parser.cpp"
    break;

  case 48: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 293 "src/parser.y"
                                                                                       {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3344 "build/parser.cpp"
    break;

  case 49: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 298 "src/parser.y"
                                                                                   {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::INT10, 0);
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3354 "build/parser.cpp"
    break;

  case 50: /* dcl_s_stmt: KW_DCL_S ident KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 303 "src/parser.y"
                                                                                                            {
        auto* n = new rpg::DclS((yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-8].sval));
    }
#line 3364 "build/parser.cpp"
    break;

  case 51: /* dcl_s_stmt: KW_DCL_S ident KW_ZONED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 308 "src/parser.y"
                                                                                                           {
        auto* n = new rpg::DclS((yyvsp[-8].sval), rpg::RPGType::ZONED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-8].sval));
    }
#line 3374 "build/parser.cpp"
    break;

  case 52: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_CONST KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 313 "src/parser.y"
                                                                                                             {
        (yyval.stmt) = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, true,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-10].sval));
    }
#line 3384 "build/parser.cpp"
    break;

  case 53: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_CONST KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 318 "src/parser.y"
                                                                                                              {
        (yyval.stmt) = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, true,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-10].sval));
    }
#line 3394 "build/parser.cpp"
    break;

  case 54: /* dcl_s_stmt: KW_DCL_S ident KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_CONST KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 323 "src/parser.y"
                                                                                                                                      {
        (yyval.stmt) = new rpg::DclS((yyvsp[-12].sval), rpg::RPGType::PACKED, 0, (yyvsp[-9].ival), (yyvsp[-7].ival), true,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-12].sval));
    }
#line 3404 "build/parser.cpp"
    break;

  case 55: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 328 "src/parser.y"
                                                                                                    {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-9].sval));
    }
#line 3414 "build/parser.cpp"
    break;

  case 56: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 333 "src/parser.y"
                                                                                                     {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-9].sval));
    }
#line 3424 "build/parser.cpp"
    break;

  case 57: /* dcl_s_stmt: KW_DCL_S ident KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 338 "src/parser.y"
                                                                                                                             {
        (yyval.stmt) = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-11].sval));
    }
#line 3434 "build/parser.cpp"
    break;

  case 58: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 343 "src/parser.y"
                                                                                                        {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-9].sval));
    }
#line 3444 "build/parser.cpp"
    break;

  case 59: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_EXPORT KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 349 "src/parser.y"
                                                                                                              {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        n->is_export = true;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3455 "build/parser.cpp"
    break;

  case 60: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_EXPORT KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 355 "src/parser.y"
                                                                                                               {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        n->is_export = true;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3466 "build/parser.cpp"
    break;

  case 61: /* dcl_s_stmt: KW_DCL_S ident KW_IND SEMICOLON  */
#line 361 "src/parser.y"
                                      {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::IND, 0);
        free((yyvsp[-2].sval));
    }
#line 3475 "build/parser.cpp"
    break;

  case 62: /* dcl_s_stmt: KW_DCL_S ident KW_BOOLEAN SEMICOLON  */
#line 365 "src/parser.y"
                                          {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::IND, 0);
        free((yyvsp[-2].sval));
    }
#line 3484 "build/parser.cpp"
    break;

  case 63: /* dcl_s_stmt: KW_DCL_S ident KW_DATE SEMICOLON  */
#line 369 "src/parser.y"
                                       {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::DATE, 0);
        free((yyvsp[-2].sval));
    }
#line 3493 "build/parser.cpp"
    break;

  case 64: /* dcl_s_stmt: KW_DCL_S ident KW_TIME SEMICOLON  */
#line 373 "src/parser.y"
                                       {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::TIME, 0);
        free((yyvsp[-2].sval));
    }
#line 3502 "build/parser.cpp"
    break;

  case 65: /* dcl_s_stmt: KW_DCL_S ident KW_TIMESTAMP SEMICOLON  */
#line 377 "src/parser.y"
                                            {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::TIMESTAMP, 0);
        free((yyvsp[-2].sval));
    }
#line 3511 "build/parser.cpp"
    break;

  case 66: /* dcl_s_stmt: KW_DCL_S ident KW_POINTER SEMICOLON  */
#line 381 "src/parser.y"
                                          {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::POINTER, 0);
        free((yyvsp[-2].sval));
    }
#line 3520 "build/parser.cpp"
    break;

  case 67: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 385 "src/parser.y"
                                                                                                         {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-9].sval));
    }
#line 3529 "build/parser.cpp"
    break;

  case 68: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 389 "src/parser.y"
                                                                                                          {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-9].sval));
    }
#line 3538 "build/parser.cpp"
    break;

  case 69: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 393 "src/parser.y"
                                                                                                             {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-9].sval));
    }
#line 3547 "build/parser.cpp"
    break;

  case 70: /* dcl_s_stmt: KW_DCL_S ident KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 397 "src/parser.y"
                                                                                                                                  {
        (yyval.stmt) = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-11].sval));
    }
#line 3556 "build/parser.cpp"
    break;

  case 71: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN KW_DIM_VAR COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 401 "src/parser.y"
                                                                                                                          {
        auto* node = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-2].ival));
        node->dim_type = 1;
        free((yyvsp[-11].sval));
        (yyval.stmt) = node;
    }
#line 3567 "build/parser.cpp"
    break;

  case 72: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN KW_DIM_AUTO COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 407 "src/parser.y"
                                                                                                                           {
        auto* node = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-2].ival));
        node->dim_type = 2;
        free((yyvsp[-11].sval));
        (yyval.stmt) = node;
    }
#line 3578 "build/parser.cpp"
    break;

  case 73: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN KW_DIM_VAR COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 413 "src/parser.y"
                                                                                                                              {
        auto* node = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::VARCHAR, (yyvsp[-8].ival), 0, 0, false, nullptr, (yyvsp[-2].ival));
        node->dim_type = 1;
        free((yyvsp[-11].sval));
        (yyval.stmt) = node;
    }
#line 3589 "build/parser.cpp"
    break;

  case 74: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN KW_DIM_AUTO COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 419 "src/parser.y"
                                                                                                                               {
        auto* node = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::VARCHAR, (yyvsp[-8].ival), 0, 0, false, nullptr, (yyvsp[-2].ival));
        node->dim_type = 2;
        free((yyvsp[-11].sval));
        (yyval.stmt) = node;
    }
#line 3600 "build/parser.cpp"
    break;

  case 75: /* dcl_s_stmt: KW_DCL_S ident KW_LIKE LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 425 "src/parser.y"
                                                                {
        auto* node = new rpg::DclS((yyvsp[-5].sval), rpg::RPGType::INT10, 0);
        node->like_var = (yyvsp[-2].sval);
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
        (yyval.stmt) = node;
    }
#line 3612 "build/parser.cpp"
    break;

  case 76: /* dcl_s_stmt: KW_DCL_S ident KW_UNS LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 432 "src/parser.y"
                                                                                   {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::UNS, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3622 "build/parser.cpp"
    break;

  case 77: /* dcl_s_stmt: KW_DCL_S ident KW_FLOAT_TYPE LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 437 "src/parser.y"
                                                                                          {
        auto type = ((yyvsp[-3].ival) <= 4) ? rpg::RPGType::FLOAT4 : rpg::RPGType::FLOAT8;
        auto* n = new rpg::DclS((yyvsp[-6].sval), type, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3633 "build/parser.cpp"
    break;

  case 78: /* dcl_s_stmt: KW_DCL_S ident KW_BINDEC LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 443 "src/parser.y"
                                                                                      {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::BINDEC, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3643 "build/parser.cpp"
    break;

  case 79: /* dcl_s_stmt: KW_DCL_S ident KW_UCS2 LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 448 "src/parser.y"
                                                                                    {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::UCS2, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3653 "build/parser.cpp"
    break;

  case 80: /* dcl_s_stmt: KW_DCL_S ident KW_GRAPH LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 453 "src/parser.y"
                                                                                     {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::UCS2, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3663 "build/parser.cpp"
    break;

  case 81: /* dcl_s_stmt: KW_DCL_S ident KW_OBJECT LPAREN KW_JAVA COLON STRING_LITERAL RPAREN SEMICOLON  */
#line 458 "src/parser.y"
                                                                                    {
        auto* n = new rpg::DclS((yyvsp[-7].sval), rpg::RPGType::OBJECT, 0);
        n->java_class = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-7].sval)); free((yyvsp[-2].sval));
    }
#line 3673 "build/parser.cpp"
    break;

  case 82: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_BASED LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 463 "src/parser.y"
                                                                                                      {
        auto* n = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::INT10, 0);
        n->based_ptr = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
    }
#line 3683 "build/parser.cpp"
    break;

  case 83: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_BASED LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 468 "src/parser.y"
                                                                                                       {
        auto* n = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival));
        n->based_ptr = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
    }
#line 3693 "build/parser.cpp"
    break;

  case 84: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_ASCEND SEMICOLON  */
#line 473 "src/parser.y"
                                                                                                                   {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = 1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3703 "build/parser.cpp"
    break;

  case 85: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_DESCEND SEMICOLON  */
#line 478 "src/parser.y"
                                                                                                                    {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = -1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3713 "build/parser.cpp"
    break;

  case 86: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_ASCEND SEMICOLON  */
#line 483 "src/parser.y"
                                                                                                                    {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = 1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3723 "build/parser.cpp"
    break;

  case 87: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_DESCEND SEMICOLON  */
#line 488 "src/parser.y"
                                                                                                                     {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = -1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3733 "build/parser.cpp"
    break;

  case 88: /* dcl_s_stmt: KW_DCL_S ident KW_DATE KW_DATFMT LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 493 "src/parser.y"
                                                                          {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::DATE, 0);
        n->datfmt = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-6].sval)); free((yyvsp[-2].sval));
    }
#line 3743 "build/parser.cpp"
    break;

  case 89: /* dcl_s_stmt: KW_DCL_S ident KW_TIME KW_TIMFMT LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 498 "src/parser.y"
                                                                          {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::TIME, 0);
        n->timfmt = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-6].sval)); free((yyvsp[-2].sval));
    }
#line 3753 "build/parser.cpp"
    break;

  case 90: /* dcl_s_keywords: %empty  */
#line 506 "src/parser.y"
                  { (yyval.ival) = 0; }
#line 3759 "build/parser.cpp"
    break;

  case 91: /* dcl_s_keywords: KW_STATIC  */
#line 507 "src/parser.y"
                  { (yyval.ival) = 1; }
#line 3765 "build/parser.cpp"
    break;

  case 92: /* dcl_s_keywords: KW_TEMPLATE  */
#line 508 "src/parser.y"
                  { (yyval.ival) = 2; }
#line 3771 "build/parser.cpp"
    break;

  case 93: /* dcl_s_keywords: KW_EXPORT  */
#line 509 "src/parser.y"
                  { (yyval.ival) = 4; }
#line 3777 "build/parser.cpp"
    break;

  case 94: /* dcl_s_keywords: KW_IMPORT  */
#line 510 "src/parser.y"
                  { (yyval.ival) = 8; }
#line 3783 "build/parser.cpp"
    break;

  case 95: /* dcl_c_stmt: KW_DCL_C IDENTIFIER expression SEMICOLON  */
#line 515 "src/parser.y"
                                             {
        (yyval.stmt) = new rpg::DclC((yyvsp[-2].sval), std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
        free((yyvsp[-2].sval));
    }
#line 3792 "build/parser.cpp"
    break;

  case 96: /* eval_target: IDENTIFIER  */
#line 522 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier((yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 3801 "build/parser.cpp"
    break;

  case 97: /* eval_target: KW_POS  */
#line 526 "src/parser.y"
             { (yyval.expr) = new rpg::Identifier("POS"); }
#line 3807 "build/parser.cpp"
    break;

  case 98: /* eval_target: KW_OVERLAY  */
#line 527 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("OVERLAY"); }
#line 3813 "build/parser.cpp"
    break;

  case 99: /* eval_target: KW_PREFIX  */
#line 528 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("PREFIX"); }
#line 3819 "build/parser.cpp"
    break;

  case 100: /* eval_target: KW_UNS  */
#line 529 "src/parser.y"
             { (yyval.expr) = new rpg::Identifier("UNS"); }
#line 3825 "build/parser.cpp"
    break;

  case 101: /* eval_target: KW_FLOAT_TYPE  */
#line 530 "src/parser.y"
                    { (yyval.expr) = new rpg::Identifier("FLOAT"); }
#line 3831 "build/parser.cpp"
    break;

  case 102: /* eval_target: KW_GRAPH  */
#line 531 "src/parser.y"
               { (yyval.expr) = new rpg::Identifier("GRAPH"); }
#line 3837 "build/parser.cpp"
    break;

  case 103: /* eval_target: KW_ASCEND  */
#line 532 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("ASCEND"); }
#line 3843 "build/parser.cpp"
    break;

  case 104: /* eval_target: KW_DESCEND  */
#line 533 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("DESCEND"); }
#line 3849 "build/parser.cpp"
    break;

  case 105: /* eval_target: KW_RTNPARM  */
#line 534 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("RTNPARM"); }
#line 3855 "build/parser.cpp"
    break;

  case 106: /* eval_target: KW_OPDESC  */
#line 535 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("OPDESC"); }
#line 3861 "build/parser.cpp"
    break;

  case 107: /* eval_target: KW_NULLIND  */
#line 536 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("NULLIND"); }
#line 3867 "build/parser.cpp"
    break;

  case 108: /* eval_target: KW_DATFMT  */
#line 537 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("DATFMT"); }
#line 3873 "build/parser.cpp"
    break;

  case 109: /* eval_target: KW_TIMFMT  */
#line 538 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("TIMFMT"); }
#line 3879 "build/parser.cpp"
    break;

  case 110: /* eval_target: KW_EXTNAME  */
#line 539 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("EXTNAME"); }
#line 3885 "build/parser.cpp"
    break;

  case 111: /* eval_target: INDICATOR  */
#line 540 "src/parser.y"
                {
        (yyval.expr) = new rpg::IndicatorExpr((yyvsp[0].ival));
    }
#line 3893 "build/parser.cpp"
    break;

  case 112: /* eval_target: IDENTIFIER DOT IDENTIFIER  */
#line 543 "src/parser.y"
                                {
        auto obj = std::unique_ptr<rpg::Expression>(new rpg::Identifier((yyvsp[-2].sval)));
        (yyval.expr) = new rpg::DotExpr(std::move(obj), (yyvsp[0].sval));
        free((yyvsp[-2].sval));
        free((yyvsp[0].sval));
    }
#line 3904 "build/parser.cpp"
    break;

  case 113: /* eval_target: IDENTIFIER LPAREN expression RPAREN  */
#line 549 "src/parser.y"
                                          {
        (yyval.expr) = new rpg::ArrayAccess((yyvsp[-3].sval), std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
        free((yyvsp[-3].sval));
    }
#line 3913 "build/parser.cpp"
    break;

  case 114: /* eval_target: IDENTIFIER LPAREN expression RPAREN DOT IDENTIFIER  */
#line 553 "src/parser.y"
                                                         {
        auto* arr = new rpg::ArrayAccess((yyvsp[-5].sval), std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)));
        (yyval.expr) = new rpg::DotExpr(std::unique_ptr<rpg::Expression>(arr), (yyvsp[0].sval));
        free((yyvsp[-5].sval));
        free((yyvsp[0].sval));
    }
#line 3924 "build/parser.cpp"
    break;

  case 115: /* eval_target: BIF_ELEM LPAREN arg_list RPAREN  */
#line 559 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("ELEM", (yyvsp[-1].expr_list));
    }
#line 3932 "build/parser.cpp"
    break;

  case 116: /* eval_stmt: eval_target EQUALS expression SEMICOLON  */
#line 565 "src/parser.y"
                                            {
        (yyval.stmt) = new rpg::EvalStmt(
            std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-1].expr))
        );
    }
#line 3943 "build/parser.cpp"
    break;

  case 117: /* eval_stmt: KW_EVAL eval_target EQUALS expression SEMICOLON  */
#line 571 "src/parser.y"
                                                      {
        (yyval.stmt) = new rpg::EvalStmt(
            std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-1].expr))
        );
    }
#line 3954 "build/parser.cpp"
    break;

  case 118: /* eval_corr_stmt: KW_EVAL_CORR ident EQUALS ident SEMICOLON  */
#line 580 "src/parser.y"
                                              {
        (yyval.stmt) = new rpg::EvalCorrStmt(std::string((yyvsp[-3].sval)), std::string((yyvsp[-1].sval)));
        free((yyvsp[-3].sval));
        free((yyvsp[-1].sval));
    }
#line 3964 "build/parser.cpp"
    break;

  case 119: /* evalr_stmt: KW_EVALR eval_target EQUALS expression SEMICOLON  */
#line 588 "src/parser.y"
                                                     {
        (yyval.stmt) = new rpg::EvalRStmt(
            std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-1].expr))
        );
    }
#line 3975 "build/parser.cpp"
    break;

  case 120: /* callp_stmt: KW_CALLP expression SEMICOLON  */
#line 597 "src/parser.y"
                                  {
        (yyval.stmt) = new rpg::ExprStmt(std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
    }
#line 3983 "build/parser.cpp"
    break;

  case 121: /* leavesr_stmt: KW_LEAVESR SEMICOLON  */
#line 603 "src/parser.y"
                         {
        (yyval.stmt) = new rpg::LeaveSRStmt();
    }
#line 3991 "build/parser.cpp"
    break;

  case 122: /* dsply_stmt: KW_DSPLY expression SEMICOLON  */
#line 609 "src/parser.y"
                                  {
        (yyval.stmt) = new rpg::DsplyStmt(std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
    }
#line 3999 "build/parser.cpp"
    break;

  case 123: /* inlr_stmt: KW_INLR EQUALS KW_ON SEMICOLON  */
#line 615 "src/parser.y"
                                   {
        (yyval.stmt) = new rpg::ReturnStmt(0);
    }
#line 4007 "build/parser.cpp"
    break;

  case 124: /* return_stmt: KW_RETURN expression SEMICOLON  */
#line 621 "src/parser.y"
                                   {
        (yyval.stmt) = new rpg::ReturnStmt(std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
    }
#line 4015 "build/parser.cpp"
    break;

  case 125: /* return_stmt: KW_RETURN SEMICOLON  */
#line 624 "src/parser.y"
                          {
        (yyval.stmt) = new rpg::ReturnStmt(0);
    }
#line 4023 "build/parser.cpp"
    break;

  case 126: /* expr_stmt: IDENTIFIER LPAREN call_args_opt RPAREN SEMICOLON  */
#line 631 "src/parser.y"
                                                     {
        auto* fc = make_func((yyvsp[-4].sval), (yyvsp[-2].expr_list));
        free((yyvsp[-4].sval));
        (yyval.stmt) = new rpg::ExprStmt(std::unique_ptr<rpg::Expression>(fc));
    }
#line 4033 "build/parser.cpp"
    break;

  case 127: /* dcl_pr_stmt: KW_DCL_PR IDENTIFIER pi_return_type SEMICOLON pr_params KW_END_PR SEMICOLON  */
#line 642 "src/parser.y"
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
#line 4054 "build/parser.cpp"
    break;

  case 128: /* dcl_pr_stmt: KW_DCL_PR IDENTIFIER pi_return_type KW_EXTPROC LPAREN STRING_LITERAL RPAREN SEMICOLON pr_params KW_END_PR SEMICOLON  */
#line 659 "src/parser.y"
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
#line 4078 "build/parser.cpp"
    break;

  case 129: /* dcl_pr_stmt: KW_DCL_PR IDENTIFIER KW_EXTPGM LPAREN STRING_LITERAL RPAREN SEMICOLON pr_params KW_END_PR SEMICOLON  */
#line 679 "src/parser.y"
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
#line 4094 "build/parser.cpp"
    break;

  case 130: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER proc_export SEMICOLON KW_DCL_PI pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 697 "src/parser.y"
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
#line 4119 "build/parser.cpp"
    break;

  case 131: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER proc_export SEMICOLON KW_DCL_PI IDENTIFIER pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 721 "src/parser.y"
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
#line 4145 "build/parser.cpp"
    break;

  case 132: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER proc_export SEMICOLON KW_DCL_PI pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_ON_EXIT SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 747 "src/parser.y"
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
#line 4172 "build/parser.cpp"
    break;

  case 133: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER proc_export SEMICOLON KW_DCL_PI IDENTIFIER pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_ON_EXIT SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 774 "src/parser.y"
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
#line 4200 "build/parser.cpp"
    break;

  case 134: /* proc_export: %empty  */
#line 800 "src/parser.y"
                { (yyval.ival) = 0; }
#line 4206 "build/parser.cpp"
    break;

  case 135: /* proc_export: KW_EXPORT  */
#line 801 "src/parser.y"
                { (yyval.ival) = 1; }
#line 4212 "build/parser.cpp"
    break;

  case 136: /* pi_return_type: %empty  */
#line 806 "src/parser.y"
               { (yyval.ival) = -1; }
#line 4218 "build/parser.cpp"
    break;

  case 137: /* pi_return_type: KW_INT LPAREN INTEGER_LITERAL RPAREN  */
#line 807 "src/parser.y"
                                           { (yyval.ival) = (int)rpg::RPGType::INT10; }
#line 4224 "build/parser.cpp"
    break;

  case 138: /* pi_return_type: KW_CHAR LPAREN INTEGER_LITERAL RPAREN  */
#line 808 "src/parser.y"
                                            { (yyval.ival) = (int)rpg::RPGType::CHAR; }
#line 4230 "build/parser.cpp"
    break;

  case 139: /* pi_return_type: KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN  */
#line 809 "src/parser.y"
                                               { (yyval.ival) = (int)rpg::RPGType::VARCHAR; }
#line 4236 "build/parser.cpp"
    break;

  case 140: /* pi_return_type: KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN  */
#line 810 "src/parser.y"
                                                                    { (yyval.ival) = (int)rpg::RPGType::PACKED; }
#line 4242 "build/parser.cpp"
    break;

  case 141: /* pi_params: %empty  */
#line 815 "src/parser.y"
                {
        (yyval.param_list) = new ParamList();
    }
#line 4250 "build/parser.cpp"
    break;

  case 142: /* pi_params: pi_params pi_param  */
#line 818 "src/parser.y"
                         {
        (yyval.param_list) = (yyvsp[-1].param_list);
        (yyval.param_list)->params.push_back(*(yyvsp[0].param_decl));
        delete (yyvsp[0].param_decl);
    }
#line 4260 "build/parser.cpp"
    break;

  case 143: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 826 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4269 "build/parser.cpp"
    break;

  case 144: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 830 "src/parser.y"
                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4278 "build/parser.cpp"
    break;

  case 145: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 834 "src/parser.y"
                                                                 {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4287 "build/parser.cpp"
    break;

  case 146: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 838 "src/parser.y"
                                                                          {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4296 "build/parser.cpp"
    break;

  case 147: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 842 "src/parser.y"
                                                                    {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4305 "build/parser.cpp"
    break;

  case 148: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 846 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4314 "build/parser.cpp"
    break;

  case 149: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 850 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 4323 "build/parser.cpp"
    break;

  case 150: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 854 "src/parser.y"
                                                                                                  {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 4332 "build/parser.cpp"
    break;

  case 151: /* pi_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 859 "src/parser.y"
                                                                            {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4341 "build/parser.cpp"
    break;

  case 152: /* pi_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 863 "src/parser.y"
                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4350 "build/parser.cpp"
    break;

  case 153: /* pi_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 867 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4359 "build/parser.cpp"
    break;

  case 154: /* pi_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 871 "src/parser.y"
                                                                                      {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4368 "build/parser.cpp"
    break;

  case 155: /* pi_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 875 "src/parser.y"
                                                                                {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4377 "build/parser.cpp"
    break;

  case 156: /* pi_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 879 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4386 "build/parser.cpp"
    break;

  case 157: /* pi_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 883 "src/parser.y"
                                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 4395 "build/parser.cpp"
    break;

  case 158: /* pi_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 887 "src/parser.y"
                                                                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 4404 "build/parser.cpp"
    break;

  case 159: /* pi_param: IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 891 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, 0, 0, 0, false, std::string((yyvsp[-2].sval))};
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
    }
#line 4414 "build/parser.cpp"
    break;

  case 160: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 897 "src/parser.y"
                                                                                                            {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4424 "build/parser.cpp"
    break;

  case 161: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 902 "src/parser.y"
                                                                                                             {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4434 "build/parser.cpp"
    break;

  case 162: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 907 "src/parser.y"
                                                                                                                {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::VARCHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4444 "build/parser.cpp"
    break;

  case 163: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 912 "src/parser.y"
                                                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-12].sval), rpg::RPGType::PACKED, 0, (yyvsp[-9].ival), (yyvsp[-7].ival), true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-12].sval));
    }
#line 4454 "build/parser.cpp"
    break;

  case 164: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 918 "src/parser.y"
                                                                                                 {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4464 "build/parser.cpp"
    break;

  case 165: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 923 "src/parser.y"
                                                                                                  {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4474 "build/parser.cpp"
    break;

  case 166: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 928 "src/parser.y"
                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4484 "build/parser.cpp"
    break;

  case 167: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 933 "src/parser.y"
                                                                                                                          {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4494 "build/parser.cpp"
    break;

  case 168: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 939 "src/parser.y"
                                                                                                                 {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4504 "build/parser.cpp"
    break;

  case 169: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 944 "src/parser.y"
                                                                                                                  {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::CHAR, (yyvsp[-8].ival), 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4514 "build/parser.cpp"
    break;

  case 170: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 949 "src/parser.y"
                                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::VARCHAR, (yyvsp[-8].ival), 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4524 "build/parser.cpp"
    break;

  case 171: /* pr_params: %empty  */
#line 958 "src/parser.y"
                {
        (yyval.param_list) = new ParamList();
    }
#line 4532 "build/parser.cpp"
    break;

  case 172: /* pr_params: pr_params pr_param  */
#line 961 "src/parser.y"
                         {
        (yyval.param_list) = (yyvsp[-1].param_list);
        (yyval.param_list)->params.push_back(*(yyvsp[0].param_decl));
        delete (yyvsp[0].param_decl);
    }
#line 4542 "build/parser.cpp"
    break;

  case 173: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 969 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4551 "build/parser.cpp"
    break;

  case 174: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 973 "src/parser.y"
                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4560 "build/parser.cpp"
    break;

  case 175: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 977 "src/parser.y"
                                                                 {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4569 "build/parser.cpp"
    break;

  case 176: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 981 "src/parser.y"
                                                                          {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4578 "build/parser.cpp"
    break;

  case 177: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 985 "src/parser.y"
                                                                    {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4587 "build/parser.cpp"
    break;

  case 178: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 989 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4596 "build/parser.cpp"
    break;

  case 179: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 993 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 4605 "build/parser.cpp"
    break;

  case 180: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 997 "src/parser.y"
                                                                                                  {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 4614 "build/parser.cpp"
    break;

  case 181: /* pr_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1002 "src/parser.y"
                                                                            {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4623 "build/parser.cpp"
    break;

  case 182: /* pr_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1006 "src/parser.y"
                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4632 "build/parser.cpp"
    break;

  case 183: /* pr_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1010 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4641 "build/parser.cpp"
    break;

  case 184: /* pr_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1014 "src/parser.y"
                                                                                      {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4650 "build/parser.cpp"
    break;

  case 185: /* pr_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1018 "src/parser.y"
                                                                                {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4659 "build/parser.cpp"
    break;

  case 186: /* pr_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1022 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4668 "build/parser.cpp"
    break;

  case 187: /* pr_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1026 "src/parser.y"
                                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 4677 "build/parser.cpp"
    break;

  case 188: /* pr_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1030 "src/parser.y"
                                                                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 4686 "build/parser.cpp"
    break;

  case 189: /* pr_param: IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1034 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, 0, 0, 0, false, std::string((yyvsp[-2].sval))};
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
    }
#line 4696 "build/parser.cpp"
    break;

  case 190: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1040 "src/parser.y"
                                                                                                            {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4706 "build/parser.cpp"
    break;

  case 191: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1045 "src/parser.y"
                                                                                                             {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4716 "build/parser.cpp"
    break;

  case 192: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1050 "src/parser.y"
                                                                                                                {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::VARCHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4726 "build/parser.cpp"
    break;

  case 193: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1055 "src/parser.y"
                                                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-12].sval), rpg::RPGType::PACKED, 0, (yyvsp[-9].ival), (yyvsp[-7].ival), true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-12].sval));
    }
#line 4736 "build/parser.cpp"
    break;

  case 194: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1061 "src/parser.y"
                                                                                                 {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4746 "build/parser.cpp"
    break;

  case 195: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1066 "src/parser.y"
                                                                                                  {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4756 "build/parser.cpp"
    break;

  case 196: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1071 "src/parser.y"
                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4766 "build/parser.cpp"
    break;

  case 197: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1076 "src/parser.y"
                                                                                                                          {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4776 "build/parser.cpp"
    break;

  case 198: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 1082 "src/parser.y"
                                                                                                                 {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4786 "build/parser.cpp"
    break;

  case 199: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 1087 "src/parser.y"
                                                                                                                  {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::CHAR, (yyvsp[-8].ival), 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4796 "build/parser.cpp"
    break;

  case 200: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 1092 "src/parser.y"
                                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::VARCHAR, (yyvsp[-8].ival), 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4806 "build/parser.cpp"
    break;

  case 201: /* monitor_stmt: KW_MONITOR SEMICOLON statement_list KW_ON_ERROR SEMICOLON statement_list KW_ENDMON SEMICOLON  */
#line 1102 "src/parser.y"
                                                                                                 {
        auto* node = new rpg::MonitorStmt();
        for (auto* s : (yyvsp[-5].stmt_list)->stmts) node->try_body.emplace_back(s);
        delete (yyvsp[-5].stmt_list);
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->on_error_body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        (yyval.stmt) = node;
    }
#line 4819 "build/parser.cpp"
    break;

  case 202: /* begsr_stmt: KW_BEGSR IDENTIFIER SEMICOLON statement_list KW_ENDSR SEMICOLON  */
#line 1113 "src/parser.y"
                                                                    {
        auto* node = new rpg::BegSR((yyvsp[-4].sval));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        free((yyvsp[-4].sval));
        (yyval.stmt) = node;
    }
#line 4831 "build/parser.cpp"
    break;

  case 203: /* exsr_stmt: KW_EXSR ident SEMICOLON  */
#line 1123 "src/parser.y"
                            {
        (yyval.stmt) = new rpg::ExSR((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4840 "build/parser.cpp"
    break;

  case 204: /* sorta_stmt: KW_SORTA ident SEMICOLON  */
#line 1131 "src/parser.y"
                             {
        (yyval.stmt) = new rpg::SortAStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4849 "build/parser.cpp"
    break;

  case 205: /* reset_stmt: KW_RESET ident SEMICOLON  */
#line 1139 "src/parser.y"
                             {
        (yyval.stmt) = new rpg::ResetStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4858 "build/parser.cpp"
    break;

  case 206: /* clear_stmt: KW_CLEAR ident SEMICOLON  */
#line 1146 "src/parser.y"
                             {
        (yyval.stmt) = new rpg::ClearStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4867 "build/parser.cpp"
    break;

  case 207: /* dealloc_stmt: KW_DEALLOC ident SEMICOLON  */
#line 1154 "src/parser.y"
                               {
        (yyval.stmt) = new rpg::DeallocStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4876 "build/parser.cpp"
    break;

  case 208: /* test_stmt: KW_TEST LPAREN ident RPAREN ident SEMICOLON  */
#line 1162 "src/parser.y"
                                                {
        char type = toupper((yyvsp[-3].sval)[0]);
        (yyval.stmt) = new rpg::TestStmt(type, std::string((yyvsp[-1].sval)));
        free((yyvsp[-3].sval));
        free((yyvsp[-1].sval));
    }
#line 4887 "build/parser.cpp"
    break;

  case 209: /* exec_sql_stmt: EXEC_SQL_TEXT  */
#line 1173 "src/parser.y"
                  {
        rpg::SqlStmtKind kind = rpg::classifySqlStmt((yyvsp[0].sval));
        (yyval.stmt) = new rpg::ExecSqlStmt(std::string((yyvsp[0].sval)), kind);
        free((yyvsp[0].sval));
    }
#line 4897 "build/parser.cpp"
    break;

  case 210: /* dcl_enum_stmt: KW_DCL_ENUM IDENTIFIER KW_QUALIFIED SEMICOLON enum_constants KW_END_ENUM SEMICOLON  */
#line 1183 "src/parser.y"
                                                                                       {
        auto* e = new rpg::DclEnum((yyvsp[-5].sval));
        e->qualified = true;
        e->constants = std::move(*(yyvsp[-2].enum_const_list));
        delete (yyvsp[-2].enum_const_list);
        free((yyvsp[-5].sval));
        (yyval.stmt) = e;
    }
#line 4910 "build/parser.cpp"
    break;

  case 211: /* dcl_enum_stmt: KW_DCL_ENUM IDENTIFIER SEMICOLON enum_constants KW_END_ENUM SEMICOLON  */
#line 1191 "src/parser.y"
                                                                            {
        auto* e = new rpg::DclEnum((yyvsp[-4].sval));
        e->qualified = false;
        e->constants = std::move(*(yyvsp[-2].enum_const_list));
        delete (yyvsp[-2].enum_const_list);
        free((yyvsp[-4].sval));
        (yyval.stmt) = e;
    }
#line 4923 "build/parser.cpp"
    break;

  case 212: /* enum_constants: enum_constant  */
#line 1202 "src/parser.y"
                  {
        (yyval.enum_const_list) = (yyvsp[0].enum_const_list);
    }
#line 4931 "build/parser.cpp"
    break;

  case 213: /* enum_constants: enum_constants enum_constant  */
#line 1205 "src/parser.y"
                                   {
        (yyvsp[-1].enum_const_list)->insert((yyvsp[-1].enum_const_list)->end(), std::make_move_iterator((yyvsp[0].enum_const_list)->begin()), std::make_move_iterator((yyvsp[0].enum_const_list)->end()));
        delete (yyvsp[0].enum_const_list);
        (yyval.enum_const_list) = (yyvsp[-1].enum_const_list);
    }
#line 4941 "build/parser.cpp"
    break;

  case 214: /* enum_constant: IDENTIFIER SEMICOLON  */
#line 1213 "src/parser.y"
                         {
        auto* v = new std::vector<rpg::EnumConstant>();
        rpg::EnumConstant ec;
        ec.name = (yyvsp[-1].sval);
        free((yyvsp[-1].sval));
        v->push_back(std::move(ec));
        (yyval.enum_const_list) = v;
    }
#line 4954 "build/parser.cpp"
    break;

  case 215: /* enum_constant: IDENTIFIER EQUALS expression SEMICOLON  */
#line 1221 "src/parser.y"
                                             {
        auto* v = new std::vector<rpg::EnumConstant>();
        rpg::EnumConstant ec;
        ec.name = (yyvsp[-3].sval);
        ec.value.reset((yyvsp[-1].expr));
        free((yyvsp[-3].sval));
        v->push_back(std::move(ec));
        (yyval.enum_const_list) = v;
    }
#line 4968 "build/parser.cpp"
    break;

  case 216: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1236 "src/parser.y"
                                                                              {
        auto* ds = new rpg::DclDS((yyvsp[-5].sval));
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-5].sval));
        (yyval.stmt) = ds;
    }
#line 4981 "build/parser.cpp"
    break;

  case 217: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1245 "src/parser.y"
                                                                   {
        auto* ds = new rpg::DclDS((yyvsp[-4].sval));
        ds->qualified = false;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-4].sval));
        (yyval.stmt) = ds;
    }
#line 4994 "build/parser.cpp"
    break;

  case 218: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1254 "src/parser.y"
                                                                                                                     {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->dim = (yyvsp[-6].ival);
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-9].sval));
        (yyval.stmt) = ds;
    }
#line 5008 "build/parser.cpp"
    break;

  case 219: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1264 "src/parser.y"
                                                                                                                     {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->dim = (yyvsp[-5].ival);
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-9].sval));
        (yyval.stmt) = ds;
    }
#line 5022 "build/parser.cpp"
    break;

  case 220: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_DIM LPAREN KW_DIM_VAR COLON INTEGER_LITERAL RPAREN KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1274 "src/parser.y"
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
#line 5037 "build/parser.cpp"
    break;

  case 221: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_DIM LPAREN KW_DIM_VAR COLON INTEGER_LITERAL RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1285 "src/parser.y"
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
#line 5052 "build/parser.cpp"
    break;

  case 222: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_DIM LPAREN KW_DIM_AUTO COLON INTEGER_LITERAL RPAREN KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1296 "src/parser.y"
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
#line 5067 "build/parser.cpp"
    break;

  case 223: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_DIM LPAREN KW_DIM_AUTO COLON INTEGER_LITERAL RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1307 "src/parser.y"
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
#line 5082 "build/parser.cpp"
    break;

  case 224: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1318 "src/parser.y"
                                                                        {
        auto* ds = new rpg::DclDS((yyvsp[-5].sval));
        ds->like_ds = (yyvsp[-2].sval);
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
        (yyval.stmt) = ds;
    }
#line 5094 "build/parser.cpp"
    break;

  case 225: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1326 "src/parser.y"
                                                                                                             {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->like_ds = (yyvsp[-6].sval);
        ds->dim = (yyvsp[-2].ival);
        free((yyvsp[-9].sval));
        free((yyvsp[-6].sval));
        (yyval.stmt) = ds;
    }
#line 5107 "build/parser.cpp"
    break;

  case 226: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_PREFIX LPAREN IDENTIFIER RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1335 "src/parser.y"
                                                                                                                   {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->qualified = true;
        ds->prefix = (yyvsp[-5].sval);
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-9].sval)); free((yyvsp[-5].sval));
        (yyval.stmt) = ds;
    }
#line 5121 "build/parser.cpp"
    break;

  case 227: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_PREFIX LPAREN IDENTIFIER COLON INTEGER_LITERAL RPAREN KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1345 "src/parser.y"
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
#line 5136 "build/parser.cpp"
    break;

  case 228: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_PREFIX LPAREN IDENTIFIER COLON INTEGER_LITERAL RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1356 "src/parser.y"
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
#line 5151 "build/parser.cpp"
    break;

  case 229: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_PREFIX LPAREN IDENTIFIER RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1367 "src/parser.y"
                                                                                                      {
        auto* ds = new rpg::DclDS((yyvsp[-8].sval));
        ds->qualified = false;
        ds->prefix = (yyvsp[-5].sval);
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-8].sval)); free((yyvsp[-5].sval));
        (yyval.stmt) = ds;
    }
#line 5165 "build/parser.cpp"
    break;

  case 230: /* ds_fields: %empty  */
#line 1379 "src/parser.y"
                {
        (yyval.ds_field_list) = new DSFieldList();
    }
#line 5173 "build/parser.cpp"
    break;

  case 231: /* ds_fields: ds_fields ds_field  */
#line 1382 "src/parser.y"
                         {
        (yyval.ds_field_list) = (yyvsp[-1].ds_field_list);
        (yyval.ds_field_list)->fields.push_back(*(yyvsp[0].ds_field));
        delete (yyvsp[0].ds_field);
    }
#line 5183 "build/parser.cpp"
    break;

  case 232: /* ds_field: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1390 "src/parser.y"
                                                              {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5192 "build/parser.cpp"
    break;

  case 233: /* ds_field: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1394 "src/parser.y"
                                                                 {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5201 "build/parser.cpp"
    break;

  case 234: /* ds_field: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1398 "src/parser.y"
                                                                    {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5210 "build/parser.cpp"
    break;

  case 235: /* ds_field: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1402 "src/parser.y"
                                                                                         {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival)};
        free((yyvsp[-7].sval));
    }
#line 5219 "build/parser.cpp"
    break;

  case 236: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1407 "src/parser.y"
                                                                            {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5228 "build/parser.cpp"
    break;

  case 237: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1411 "src/parser.y"
                                                                             {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5237 "build/parser.cpp"
    break;

  case 238: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1415 "src/parser.y"
                                                                                {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5246 "build/parser.cpp"
    break;

  case 239: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1419 "src/parser.y"
                                                                                                     {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival)};
        free((yyvsp[-7].sval));
    }
#line 5255 "build/parser.cpp"
    break;

  case 240: /* ds_field: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_POS LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1424 "src/parser.y"
                                                                                                      {
        auto* f = new rpg::DSField{(yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0};
        f->pos = (yyvsp[-2].ival);
        free((yyvsp[-9].sval));
        (yyval.ds_field) = f;
    }
#line 5266 "build/parser.cpp"
    break;

  case 241: /* ds_field: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_POS LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1430 "src/parser.y"
                                                                                                     {
        auto* f = new rpg::DSField{(yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0};
        f->pos = (yyvsp[-2].ival);
        free((yyvsp[-9].sval));
        (yyval.ds_field) = f;
    }
#line 5277 "build/parser.cpp"
    break;

  case 242: /* ds_field: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_POS LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1436 "src/parser.y"
                                                                                                                              {
        auto* f = new rpg::DSField{(yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival)};
        f->pos = (yyvsp[-2].ival);
        free((yyvsp[-11].sval));
        (yyval.ds_field) = f;
    }
#line 5288 "build/parser.cpp"
    break;

  case 243: /* ds_field: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OVERLAY LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1443 "src/parser.y"
                                                                                                     {
        auto* f = new rpg::DSField{(yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0};
        f->overlay_field = (yyvsp[-2].sval);
        free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
        (yyval.ds_field) = f;
    }
#line 5299 "build/parser.cpp"
    break;

  case 244: /* ds_field: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OVERLAY LPAREN IDENTIFIER COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1450 "src/parser.y"
                                                                                                                           {
        auto* f = new rpg::DSField{(yyvsp[-11].sval), rpg::RPGType::CHAR, (yyvsp[-8].ival), 0, 0};
        f->overlay_field = (yyvsp[-4].sval);
        f->overlay_pos = (yyvsp[-2].ival);
        free((yyvsp[-11].sval)); free((yyvsp[-4].sval));
        (yyval.ds_field) = f;
    }
#line 5311 "build/parser.cpp"
    break;

  case 245: /* ds_field: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OVERLAY LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1457 "src/parser.y"
                                                                                                    {
        auto* f = new rpg::DSField{(yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0};
        f->overlay_field = (yyvsp[-2].sval);
        free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
        (yyval.ds_field) = f;
    }
#line 5322 "build/parser.cpp"
    break;

  case 246: /* ds_field: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OVERLAY LPAREN IDENTIFIER COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1463 "src/parser.y"
                                                                                                                          {
        auto* f = new rpg::DSField{(yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0};
        f->overlay_field = (yyvsp[-4].sval);
        f->overlay_pos = (yyvsp[-2].ival);
        free((yyvsp[-11].sval)); free((yyvsp[-4].sval));
        (yyval.ds_field) = f;
    }
#line 5334 "build/parser.cpp"
    break;

  case 247: /* if_stmt: KW_IF expression SEMICOLON statement_list elseif_clauses else_clause KW_ENDIF SEMICOLON  */
#line 1475 "src/parser.y"
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
#line 5359 "build/parser.cpp"
    break;

  case 248: /* elseif_clauses: %empty  */
#line 1498 "src/parser.y"
                { (yyval.elseif_list) = nullptr; }
#line 5365 "build/parser.cpp"
    break;

  case 249: /* elseif_clauses: elseif_clauses elseif_clause  */
#line 1499 "src/parser.y"
                                   {
        if (!(yyvsp[-1].elseif_list)) (yyvsp[-1].elseif_list) = new std::vector<ElseIfData*>();
        (yyval.elseif_list) = (yyvsp[-1].elseif_list);
        (yyval.elseif_list)->push_back((yyvsp[0].elseif_data));
    }
#line 5375 "build/parser.cpp"
    break;

  case 250: /* elseif_clause: KW_ELSEIF expression SEMICOLON statement_list  */
#line 1507 "src/parser.y"
                                                  {
        (yyval.elseif_data) = new ElseIfData();
        (yyval.elseif_data)->cond = (yyvsp[-2].expr);
        (yyval.elseif_data)->body = std::move((yyvsp[0].stmt_list)->stmts);
        delete (yyvsp[0].stmt_list);
    }
#line 5386 "build/parser.cpp"
    break;

  case 251: /* else_clause: %empty  */
#line 1516 "src/parser.y"
                { (yyval.stmt_list) = nullptr; }
#line 5392 "build/parser.cpp"
    break;

  case 252: /* else_clause: KW_ELSE SEMICOLON statement_list  */
#line 1517 "src/parser.y"
                                       {
        (yyval.stmt_list) = (yyvsp[0].stmt_list);
    }
#line 5400 "build/parser.cpp"
    break;

  case 253: /* dow_stmt: KW_DOW expression SEMICOLON statement_list KW_ENDDO SEMICOLON  */
#line 1523 "src/parser.y"
                                                                  {
        auto* node = new rpg::DowStmt(std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        (yyval.stmt) = node;
    }
#line 5411 "build/parser.cpp"
    break;

  case 254: /* dou_stmt: KW_DOU expression SEMICOLON statement_list KW_ENDDO SEMICOLON  */
#line 1532 "src/parser.y"
                                                                  {
        auto* node = new rpg::DouStmt(std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        (yyval.stmt) = node;
    }
#line 5422 "build/parser.cpp"
    break;

  case 255: /* for_stmt: KW_FOR ident EQUALS expression KW_TO expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1541 "src/parser.y"
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
#line 5437 "build/parser.cpp"
    break;

  case 256: /* for_stmt: KW_FOR ident EQUALS expression KW_TO expression KW_BY expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1551 "src/parser.y"
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
#line 5452 "build/parser.cpp"
    break;

  case 257: /* for_stmt: KW_FOR ident EQUALS expression KW_DOWNTO expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1561 "src/parser.y"
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
#line 5467 "build/parser.cpp"
    break;

  case 258: /* for_stmt: KW_FOR ident EQUALS expression KW_DOWNTO expression KW_BY expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1571 "src/parser.y"
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
#line 5482 "build/parser.cpp"
    break;

  case 259: /* for_each_stmt: KW_FOR_EACH ident KW_IN expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1584 "src/parser.y"
                                                                                    {
        auto* node = new rpg::ForEachStmt((yyvsp[-6].sval), std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        free((yyvsp[-6].sval));
        (yyval.stmt) = node;
    }
#line 5494 "build/parser.cpp"
    break;

  case 260: /* select_stmt: KW_SELECT SEMICOLON when_clauses other_clause KW_ENDSL SEMICOLON  */
#line 1594 "src/parser.y"
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
#line 5515 "build/parser.cpp"
    break;

  case 261: /* when_clauses: when_clause  */
#line 1613 "src/parser.y"
                {
        (yyval.when_list) = new std::vector<WhenData*>();
        (yyval.when_list)->push_back((yyvsp[0].when_data));
    }
#line 5524 "build/parser.cpp"
    break;

  case 262: /* when_clauses: when_clauses when_clause  */
#line 1617 "src/parser.y"
                               {
        (yyval.when_list) = (yyvsp[-1].when_list);
        (yyval.when_list)->push_back((yyvsp[0].when_data));
    }
#line 5533 "build/parser.cpp"
    break;

  case 263: /* when_clause: KW_WHEN expression SEMICOLON statement_list  */
#line 1624 "src/parser.y"
                                                {
        (yyval.when_data) = new WhenData();
        (yyval.when_data)->cond = (yyvsp[-2].expr);
        (yyval.when_data)->body = std::move((yyvsp[0].stmt_list)->stmts);
        delete (yyvsp[0].stmt_list);
    }
#line 5544 "build/parser.cpp"
    break;

  case 264: /* other_clause: %empty  */
#line 1633 "src/parser.y"
                { (yyval.stmt_list) = nullptr; }
#line 5550 "build/parser.cpp"
    break;

  case 265: /* other_clause: KW_OTHER SEMICOLON statement_list  */
#line 1634 "src/parser.y"
                                        {
        (yyval.stmt_list) = (yyvsp[0].stmt_list);
    }
#line 5558 "build/parser.cpp"
    break;

  case 266: /* iter_stmt: KW_ITER SEMICOLON  */
#line 1640 "src/parser.y"
                      { (yyval.stmt) = new rpg::IterStmt(); }
#line 5564 "build/parser.cpp"
    break;

  case 267: /* leave_stmt: KW_LEAVE SEMICOLON  */
#line 1644 "src/parser.y"
                       { (yyval.stmt) = new rpg::LeaveStmt(); }
#line 5570 "build/parser.cpp"
    break;

  case 268: /* expression: or_expr  */
#line 1650 "src/parser.y"
            { (yyval.expr) = (yyvsp[0].expr); }
#line 5576 "build/parser.cpp"
    break;

  case 269: /* or_expr: and_expr  */
#line 1654 "src/parser.y"
             { (yyval.expr) = (yyvsp[0].expr); }
#line 5582 "build/parser.cpp"
    break;

  case 270: /* or_expr: or_expr KW_OR and_expr  */
#line 1655 "src/parser.y"
                             {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::OR,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5592 "build/parser.cpp"
    break;

  case 271: /* and_expr: not_expr  */
#line 1663 "src/parser.y"
             { (yyval.expr) = (yyvsp[0].expr); }
#line 5598 "build/parser.cpp"
    break;

  case 272: /* and_expr: and_expr KW_AND not_expr  */
#line 1664 "src/parser.y"
                               {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::AND,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5608 "build/parser.cpp"
    break;

  case 273: /* not_expr: comparison_expr  */
#line 1672 "src/parser.y"
                    { (yyval.expr) = (yyvsp[0].expr); }
#line 5614 "build/parser.cpp"
    break;

  case 274: /* not_expr: KW_NOT comparison_expr  */
#line 1673 "src/parser.y"
                             {
        (yyval.expr) = new rpg::NotExpr(std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5622 "build/parser.cpp"
    break;

  case 275: /* comparison_expr: additive_expr  */
#line 1679 "src/parser.y"
                  { (yyval.expr) = (yyvsp[0].expr); }
#line 5628 "build/parser.cpp"
    break;

  case 276: /* comparison_expr: comparison_expr EQUALS additive_expr  */
#line 1680 "src/parser.y"
                                           {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::EQ,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5638 "build/parser.cpp"
    break;

  case 277: /* comparison_expr: comparison_expr NE additive_expr  */
#line 1685 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::NE,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5648 "build/parser.cpp"
    break;

  case 278: /* comparison_expr: comparison_expr LT additive_expr  */
#line 1690 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::LT,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5658 "build/parser.cpp"
    break;

  case 279: /* comparison_expr: comparison_expr GT additive_expr  */
#line 1695 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::GT,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5668 "build/parser.cpp"
    break;

  case 280: /* comparison_expr: comparison_expr LE additive_expr  */
#line 1700 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::LE,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5678 "build/parser.cpp"
    break;

  case 281: /* comparison_expr: comparison_expr GE additive_expr  */
#line 1705 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::GE,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5688 "build/parser.cpp"
    break;

  case 282: /* comparison_expr: additive_expr KW_IN additive_expr  */
#line 1710 "src/parser.y"
                                        {
        (yyval.expr) = new rpg::InExpr(
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5698 "build/parser.cpp"
    break;

  case 283: /* additive_expr: multiplicative_expr  */
#line 1718 "src/parser.y"
                        { (yyval.expr) = (yyvsp[0].expr); }
#line 5704 "build/parser.cpp"
    break;

  case 284: /* additive_expr: additive_expr PLUS multiplicative_expr  */
#line 1719 "src/parser.y"
                                             {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::ADD,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5714 "build/parser.cpp"
    break;

  case 285: /* additive_expr: additive_expr MINUS multiplicative_expr  */
#line 1724 "src/parser.y"
                                              {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::SUB,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5724 "build/parser.cpp"
    break;

  case 286: /* multiplicative_expr: power_expr  */
#line 1732 "src/parser.y"
               { (yyval.expr) = (yyvsp[0].expr); }
#line 5730 "build/parser.cpp"
    break;

  case 287: /* multiplicative_expr: multiplicative_expr STAR power_expr  */
#line 1733 "src/parser.y"
                                          {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::MUL,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5740 "build/parser.cpp"
    break;

  case 288: /* multiplicative_expr: multiplicative_expr SLASH power_expr  */
#line 1738 "src/parser.y"
                                           {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::DIV,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5750 "build/parser.cpp"
    break;

  case 289: /* power_expr: unary_expr  */
#line 1746 "src/parser.y"
               { (yyval.expr) = (yyvsp[0].expr); }
#line 5756 "build/parser.cpp"
    break;

  case 290: /* power_expr: unary_expr POWER power_expr  */
#line 1747 "src/parser.y"
                                  {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::POWER,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5766 "build/parser.cpp"
    break;

  case 291: /* unary_expr: postfix_expr  */
#line 1755 "src/parser.y"
                 { (yyval.expr) = (yyvsp[0].expr); }
#line 5772 "build/parser.cpp"
    break;

  case 292: /* unary_expr: MINUS postfix_expr  */
#line 1756 "src/parser.y"
                         {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::SUB,
            std::unique_ptr<rpg::Expression>(new rpg::IntLiteral(0)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5782 "build/parser.cpp"
    break;

  case 293: /* postfix_expr: primary_expr  */
#line 1764 "src/parser.y"
                 { (yyval.expr) = (yyvsp[0].expr); }
#line 5788 "build/parser.cpp"
    break;

  case 294: /* postfix_expr: postfix_expr DOT IDENTIFIER  */
#line 1765 "src/parser.y"
                                  {
        (yyval.expr) = new rpg::DotExpr(std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)), (yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 5797 "build/parser.cpp"
    break;

  case 295: /* ident: IDENTIFIER  */
#line 1772 "src/parser.y"
               { (yyval.sval) = (yyvsp[0].sval); }
#line 5803 "build/parser.cpp"
    break;

  case 296: /* ident: KW_UNS  */
#line 1773 "src/parser.y"
             { (yyval.sval) = strdup("UNS"); }
#line 5809 "build/parser.cpp"
    break;

  case 297: /* ident: KW_FLOAT_TYPE  */
#line 1774 "src/parser.y"
                    { (yyval.sval) = strdup("FLOAT"); }
#line 5815 "build/parser.cpp"
    break;

  case 298: /* ident: KW_GRAPH  */
#line 1775 "src/parser.y"
               { (yyval.sval) = strdup("GRAPH"); }
#line 5821 "build/parser.cpp"
    break;

  case 299: /* ident: KW_ASCEND  */
#line 1776 "src/parser.y"
                { (yyval.sval) = strdup("ASCEND"); }
#line 5827 "build/parser.cpp"
    break;

  case 300: /* ident: KW_DESCEND  */
#line 1777 "src/parser.y"
                 { (yyval.sval) = strdup("DESCEND"); }
#line 5833 "build/parser.cpp"
    break;

  case 301: /* ident: KW_IN  */
#line 1778 "src/parser.y"
            { (yyval.sval) = strdup("IN"); }
#line 5839 "build/parser.cpp"
    break;

  case 302: /* ident: KW_RTNPARM  */
#line 1779 "src/parser.y"
                 { (yyval.sval) = strdup("RTNPARM"); }
#line 5845 "build/parser.cpp"
    break;

  case 303: /* ident: KW_OPDESC  */
#line 1780 "src/parser.y"
                { (yyval.sval) = strdup("OPDESC"); }
#line 5851 "build/parser.cpp"
    break;

  case 304: /* ident: KW_NULLIND  */
#line 1781 "src/parser.y"
                 { (yyval.sval) = strdup("NULLIND"); }
#line 5857 "build/parser.cpp"
    break;

  case 305: /* ident: KW_DATFMT  */
#line 1782 "src/parser.y"
                { (yyval.sval) = strdup("DATFMT"); }
#line 5863 "build/parser.cpp"
    break;

  case 306: /* ident: KW_TIMFMT  */
#line 1783 "src/parser.y"
                { (yyval.sval) = strdup("TIMFMT"); }
#line 5869 "build/parser.cpp"
    break;

  case 307: /* ident: KW_EXTNAME  */
#line 1784 "src/parser.y"
                 { (yyval.sval) = strdup("EXTNAME"); }
#line 5875 "build/parser.cpp"
    break;

  case 308: /* ident: KW_OVERLAY  */
#line 1785 "src/parser.y"
                 { (yyval.sval) = strdup("OVERLAY"); }
#line 5881 "build/parser.cpp"
    break;

  case 309: /* ident: KW_POS  */
#line 1786 "src/parser.y"
             { (yyval.sval) = strdup("POS"); }
#line 5887 "build/parser.cpp"
    break;

  case 310: /* ident: KW_PREFIX  */
#line 1787 "src/parser.y"
                { (yyval.sval) = strdup("PREFIX"); }
#line 5893 "build/parser.cpp"
    break;

  case 311: /* primary_expr: IDENTIFIER  */
#line 1791 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier((yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 5902 "build/parser.cpp"
    break;

  case 312: /* primary_expr: KW_UNS  */
#line 1795 "src/parser.y"
             { (yyval.expr) = new rpg::Identifier("UNS"); }
#line 5908 "build/parser.cpp"
    break;

  case 313: /* primary_expr: KW_FLOAT_TYPE  */
#line 1796 "src/parser.y"
                    { (yyval.expr) = new rpg::Identifier("FLOAT"); }
#line 5914 "build/parser.cpp"
    break;

  case 314: /* primary_expr: KW_GRAPH  */
#line 1797 "src/parser.y"
               { (yyval.expr) = new rpg::Identifier("GRAPH"); }
#line 5920 "build/parser.cpp"
    break;

  case 315: /* primary_expr: KW_ASCEND  */
#line 1798 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("ASCEND"); }
#line 5926 "build/parser.cpp"
    break;

  case 316: /* primary_expr: KW_DESCEND  */
#line 1799 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("DESCEND"); }
#line 5932 "build/parser.cpp"
    break;

  case 317: /* primary_expr: KW_RTNPARM  */
#line 1800 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("RTNPARM"); }
#line 5938 "build/parser.cpp"
    break;

  case 318: /* primary_expr: KW_OPDESC  */
#line 1801 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("OPDESC"); }
#line 5944 "build/parser.cpp"
    break;

  case 319: /* primary_expr: KW_NULLIND  */
#line 1802 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("NULLIND"); }
#line 5950 "build/parser.cpp"
    break;

  case 320: /* primary_expr: KW_DATFMT  */
#line 1803 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("DATFMT"); }
#line 5956 "build/parser.cpp"
    break;

  case 321: /* primary_expr: KW_OVERLAY  */
#line 1804 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("OVERLAY"); }
#line 5962 "build/parser.cpp"
    break;

  case 322: /* primary_expr: KW_POS  */
#line 1805 "src/parser.y"
             { (yyval.expr) = new rpg::Identifier("POS"); }
#line 5968 "build/parser.cpp"
    break;

  case 323: /* primary_expr: KW_PREFIX  */
#line 1806 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("PREFIX"); }
#line 5974 "build/parser.cpp"
    break;

  case 324: /* primary_expr: KW_TIMFMT  */
#line 1807 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("TIMFMT"); }
#line 5980 "build/parser.cpp"
    break;

  case 325: /* primary_expr: KW_EXTNAME  */
#line 1808 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("EXTNAME"); }
#line 5986 "build/parser.cpp"
    break;

  case 326: /* primary_expr: INTEGER_LITERAL  */
#line 1809 "src/parser.y"
                      {
        (yyval.expr) = new rpg::IntLiteral((yyvsp[0].ival));
    }
#line 5994 "build/parser.cpp"
    break;

  case 327: /* primary_expr: FLOAT_LITERAL  */
#line 1812 "src/parser.y"
                    {
        (yyval.expr) = new rpg::FloatLiteral((yyvsp[0].fval));
    }
#line 6002 "build/parser.cpp"
    break;

  case 328: /* primary_expr: STRING_LITERAL  */
#line 1815 "src/parser.y"
                     {
        (yyval.expr) = new rpg::StringLiteral((yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 6011 "build/parser.cpp"
    break;

  case 329: /* primary_expr: IDENTIFIER LPAREN call_args_opt RPAREN  */
#line 1819 "src/parser.y"
                                             {
        (yyval.expr) = make_func((yyvsp[-3].sval), (yyvsp[-1].expr_list));
        free((yyvsp[-3].sval));
    }
#line 6020 "build/parser.cpp"
    break;

  case 330: /* primary_expr: BIF_CHAR LPAREN arg_list RPAREN  */
#line 1823 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("CHAR", (yyvsp[-1].expr_list));
    }
#line 6028 "build/parser.cpp"
    break;

  case 331: /* primary_expr: BIF_TRIM LPAREN arg_list RPAREN  */
#line 1826 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("TRIM", (yyvsp[-1].expr_list));
    }
#line 6036 "build/parser.cpp"
    break;

  case 332: /* primary_expr: BIF_TRIML LPAREN arg_list RPAREN  */
#line 1829 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("TRIML", (yyvsp[-1].expr_list));
    }
#line 6044 "build/parser.cpp"
    break;

  case 333: /* primary_expr: BIF_TRIMR LPAREN arg_list RPAREN  */
#line 1832 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("TRIMR", (yyvsp[-1].expr_list));
    }
#line 6052 "build/parser.cpp"
    break;

  case 334: /* primary_expr: BIF_LEN LPAREN arg_list RPAREN  */
#line 1835 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("LEN", (yyvsp[-1].expr_list));
    }
#line 6060 "build/parser.cpp"
    break;

  case 335: /* primary_expr: BIF_SUBST LPAREN arg_list RPAREN  */
#line 1838 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("SUBST", (yyvsp[-1].expr_list));
    }
#line 6068 "build/parser.cpp"
    break;

  case 336: /* primary_expr: BIF_SCAN LPAREN arg_list RPAREN  */
#line 1841 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("SCAN", (yyvsp[-1].expr_list));
    }
#line 6076 "build/parser.cpp"
    break;

  case 337: /* primary_expr: BIF_SCANRPL LPAREN arg_list RPAREN  */
#line 1844 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("SCANRPL", (yyvsp[-1].expr_list));
    }
#line 6084 "build/parser.cpp"
    break;

  case 338: /* primary_expr: BIF_XLATE LPAREN arg_list RPAREN  */
#line 1847 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("XLATE", (yyvsp[-1].expr_list));
    }
#line 6092 "build/parser.cpp"
    break;

  case 339: /* primary_expr: BIF_DEC LPAREN arg_list RPAREN  */
#line 1850 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("DEC", (yyvsp[-1].expr_list));
    }
#line 6100 "build/parser.cpp"
    break;

  case 340: /* primary_expr: BIF_INT LPAREN arg_list RPAREN  */
#line 1853 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("INT", (yyvsp[-1].expr_list));
    }
#line 6108 "build/parser.cpp"
    break;

  case 341: /* primary_expr: BIF_ELEM LPAREN arg_list RPAREN  */
#line 1856 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("ELEM", (yyvsp[-1].expr_list));
    }
#line 6116 "build/parser.cpp"
    break;

  case 342: /* primary_expr: BIF_PARMS LPAREN RPAREN  */
#line 1859 "src/parser.y"
                              {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("PARMS", empty);
    }
#line 6125 "build/parser.cpp"
    break;

  case 343: /* primary_expr: BIF_LOOKUP LPAREN arg_list RPAREN  */
#line 1863 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("LOOKUP", (yyvsp[-1].expr_list));
    }
#line 6133 "build/parser.cpp"
    break;

  case 344: /* primary_expr: BIF_EDITC LPAREN arg_list RPAREN  */
#line 1866 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("EDITC", (yyvsp[-1].expr_list));
    }
#line 6141 "build/parser.cpp"
    break;

  case 345: /* primary_expr: BIF_EDITW LPAREN arg_list RPAREN  */
#line 1869 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("EDITW", (yyvsp[-1].expr_list));
    }
#line 6149 "build/parser.cpp"
    break;

  case 346: /* primary_expr: BIF_REPLACE LPAREN arg_list RPAREN  */
#line 1872 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("REPLACE", (yyvsp[-1].expr_list));
    }
#line 6157 "build/parser.cpp"
    break;

  case 347: /* primary_expr: BIF_CHECK LPAREN arg_list RPAREN  */
#line 1875 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("CHECK", (yyvsp[-1].expr_list));
    }
#line 6165 "build/parser.cpp"
    break;

  case 348: /* primary_expr: BIF_CHECKR LPAREN arg_list RPAREN  */
#line 1878 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("CHECKR", (yyvsp[-1].expr_list));
    }
#line 6173 "build/parser.cpp"
    break;

  case 349: /* primary_expr: BIF_LOWER LPAREN arg_list RPAREN  */
#line 1881 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("LOWER", (yyvsp[-1].expr_list));
    }
#line 6181 "build/parser.cpp"
    break;

  case 350: /* primary_expr: BIF_UPPER LPAREN arg_list RPAREN  */
#line 1884 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("UPPER", (yyvsp[-1].expr_list));
    }
#line 6189 "build/parser.cpp"
    break;

  case 351: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_YEARS RPAREN  */
#line 1887 "src/parser.y"
                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("YEARS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6200 "build/parser.cpp"
    break;

  case 352: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_MONTHS RPAREN  */
#line 1893 "src/parser.y"
                                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MONTHS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6211 "build/parser.cpp"
    break;

  case 353: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_DAYS RPAREN  */
#line 1899 "src/parser.y"
                                                       {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("DAYS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6222 "build/parser.cpp"
    break;

  case 354: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_HOURS RPAREN  */
#line 1905 "src/parser.y"
                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("HOURS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6233 "build/parser.cpp"
    break;

  case 355: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_MINUTES RPAREN  */
#line 1911 "src/parser.y"
                                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MINUTES"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6244 "build/parser.cpp"
    break;

  case 356: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_SECONDS RPAREN  */
#line 1917 "src/parser.y"
                                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("SECONDS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6255 "build/parser.cpp"
    break;

  case 357: /* primary_expr: BIF_FLOAT LPAREN arg_list RPAREN  */
#line 1923 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("FLOAT", (yyvsp[-1].expr_list));
    }
#line 6263 "build/parser.cpp"
    break;

  case 358: /* primary_expr: BIF_SQRT LPAREN arg_list RPAREN  */
#line 1926 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("SQRT", (yyvsp[-1].expr_list));
    }
#line 6271 "build/parser.cpp"
    break;

  case 359: /* primary_expr: BIF_MAX LPAREN arg_list RPAREN  */
#line 1929 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("MAX", (yyvsp[-1].expr_list));
    }
#line 6279 "build/parser.cpp"
    break;

  case 360: /* primary_expr: BIF_MIN LPAREN arg_list RPAREN  */
#line 1932 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("MIN", (yyvsp[-1].expr_list));
    }
#line 6287 "build/parser.cpp"
    break;

  case 361: /* primary_expr: BIF_STATUS LPAREN RPAREN  */
#line 1935 "src/parser.y"
                               {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("STATUS", empty);
    }
#line 6296 "build/parser.cpp"
    break;

  case 362: /* primary_expr: BIF_ERROR LPAREN RPAREN  */
#line 1939 "src/parser.y"
                              {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("ERROR", empty);
    }
#line 6305 "build/parser.cpp"
    break;

  case 363: /* primary_expr: BIF_SIZE LPAREN arg_list RPAREN  */
#line 1943 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("SIZE", (yyvsp[-1].expr_list));
    }
#line 6313 "build/parser.cpp"
    break;

  case 364: /* primary_expr: BIF_ADDR LPAREN arg_list RPAREN  */
#line 1946 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("ADDR", (yyvsp[-1].expr_list));
    }
#line 6321 "build/parser.cpp"
    break;

  case 365: /* primary_expr: BIF_ABS LPAREN arg_list RPAREN  */
#line 1949 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("ABS", (yyvsp[-1].expr_list));
    }
#line 6329 "build/parser.cpp"
    break;

  case 366: /* primary_expr: BIF_DIV LPAREN arg_list RPAREN  */
#line 1952 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("DIV", (yyvsp[-1].expr_list));
    }
#line 6337 "build/parser.cpp"
    break;

  case 367: /* primary_expr: BIF_REM LPAREN arg_list RPAREN  */
#line 1955 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("REM", (yyvsp[-1].expr_list));
    }
#line 6345 "build/parser.cpp"
    break;

  case 368: /* primary_expr: BIF_DATE LPAREN arg_list RPAREN  */
#line 1958 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("DATE", (yyvsp[-1].expr_list));
    }
#line 6353 "build/parser.cpp"
    break;

  case 369: /* primary_expr: BIF_DATE LPAREN RPAREN  */
#line 1961 "src/parser.y"
                             {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("DATE", empty);
    }
#line 6362 "build/parser.cpp"
    break;

  case 370: /* primary_expr: BIF_TIME LPAREN arg_list RPAREN  */
#line 1965 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("TIME", (yyvsp[-1].expr_list));
    }
#line 6370 "build/parser.cpp"
    break;

  case 371: /* primary_expr: BIF_TIME LPAREN RPAREN  */
#line 1968 "src/parser.y"
                             {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("TIME", empty);
    }
#line 6379 "build/parser.cpp"
    break;

  case 372: /* primary_expr: BIF_TIMESTAMP LPAREN arg_list RPAREN  */
#line 1972 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TIMESTAMP", (yyvsp[-1].expr_list));
    }
#line 6387 "build/parser.cpp"
    break;

  case 373: /* primary_expr: BIF_TIMESTAMP LPAREN RPAREN  */
#line 1975 "src/parser.y"
                                  {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("TIMESTAMP", empty);
    }
#line 6396 "build/parser.cpp"
    break;

  case 374: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_DAYS RPAREN  */
#line 1979 "src/parser.y"
                                                                       {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("DAYS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 6408 "build/parser.cpp"
    break;

  case 375: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_MONTHS RPAREN  */
#line 1986 "src/parser.y"
                                                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MONTHS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 6420 "build/parser.cpp"
    break;

  case 376: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_YEARS RPAREN  */
#line 1993 "src/parser.y"
                                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("YEARS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 6432 "build/parser.cpp"
    break;

  case 377: /* primary_expr: BIF_DAYS LPAREN expression RPAREN  */
#line 2000 "src/parser.y"
                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("DAYS", args);
    }
#line 6442 "build/parser.cpp"
    break;

  case 378: /* primary_expr: BIF_MONTHS LPAREN expression RPAREN  */
#line 2005 "src/parser.y"
                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("MONTHS", args);
    }
#line 6452 "build/parser.cpp"
    break;

  case 379: /* primary_expr: BIF_YEARS LPAREN expression RPAREN  */
#line 2010 "src/parser.y"
                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("YEARS", args);
    }
#line 6462 "build/parser.cpp"
    break;

  case 380: /* primary_expr: BIF_FOUND LPAREN RPAREN  */
#line 2015 "src/parser.y"
                              {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("FOUND", empty);
    }
#line 6471 "build/parser.cpp"
    break;

  case 381: /* primary_expr: BIF_EOF LPAREN RPAREN  */
#line 2019 "src/parser.y"
                            {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("EOF", empty);
    }
#line 6480 "build/parser.cpp"
    break;

  case 382: /* primary_expr: BIF_ALLOC LPAREN arg_list RPAREN  */
#line 2023 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("ALLOC", (yyvsp[-1].expr_list));
    }
#line 6488 "build/parser.cpp"
    break;

  case 383: /* primary_expr: BIF_REALLOC LPAREN arg_list RPAREN  */
#line 2026 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("REALLOC", (yyvsp[-1].expr_list));
    }
#line 6496 "build/parser.cpp"
    break;

  case 384: /* primary_expr: BIF_XFOOT LPAREN arg_list RPAREN  */
#line 2029 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("XFOOT", (yyvsp[-1].expr_list));
    }
#line 6504 "build/parser.cpp"
    break;

  case 385: /* primary_expr: BIF_UNS LPAREN arg_list RPAREN  */
#line 2032 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("UNS", (yyvsp[-1].expr_list));
    }
#line 6512 "build/parser.cpp"
    break;

  case 386: /* primary_expr: BIF_INTH LPAREN arg_list RPAREN  */
#line 2035 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("INTH", (yyvsp[-1].expr_list));
    }
#line 6520 "build/parser.cpp"
    break;

  case 387: /* primary_expr: BIF_DECH LPAREN arg_list RPAREN  */
#line 2038 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("DECH", (yyvsp[-1].expr_list));
    }
#line 6528 "build/parser.cpp"
    break;

  case 388: /* primary_expr: BIF_DECPOS LPAREN arg_list RPAREN  */
#line 2041 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("DECPOS", (yyvsp[-1].expr_list));
    }
#line 6536 "build/parser.cpp"
    break;

  case 389: /* primary_expr: BIF_SPLIT LPAREN arg_list RPAREN  */
#line 2044 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("SPLIT", (yyvsp[-1].expr_list));
    }
#line 6544 "build/parser.cpp"
    break;

  case 390: /* primary_expr: BIF_CONCAT LPAREN arg_list RPAREN  */
#line 2047 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("CONCAT", (yyvsp[-1].expr_list));
    }
#line 6552 "build/parser.cpp"
    break;

  case 391: /* primary_expr: BIF_CONCATARR LPAREN arg_list RPAREN  */
#line 2050 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("CONCATARR", (yyvsp[-1].expr_list));
    }
#line 6560 "build/parser.cpp"
    break;

  case 392: /* primary_expr: BIF_LEFT LPAREN arg_list RPAREN  */
#line 2053 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("LEFT", (yyvsp[-1].expr_list));
    }
#line 6568 "build/parser.cpp"
    break;

  case 393: /* primary_expr: BIF_RIGHT LPAREN arg_list RPAREN  */
#line 2056 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("RIGHT", (yyvsp[-1].expr_list));
    }
#line 6576 "build/parser.cpp"
    break;

  case 394: /* primary_expr: BIF_STR LPAREN arg_list RPAREN  */
#line 2059 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("STR", (yyvsp[-1].expr_list));
    }
#line 6584 "build/parser.cpp"
    break;

  case 395: /* primary_expr: BIF_SUBARR LPAREN arg_list RPAREN  */
#line 2062 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("SUBARR", (yyvsp[-1].expr_list));
    }
#line 6592 "build/parser.cpp"
    break;

  case 396: /* primary_expr: BIF_MAXARR LPAREN arg_list RPAREN  */
#line 2065 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("MAXARR", (yyvsp[-1].expr_list));
    }
#line 6600 "build/parser.cpp"
    break;

  case 397: /* primary_expr: BIF_MINARR LPAREN arg_list RPAREN  */
#line 2068 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("MINARR", (yyvsp[-1].expr_list));
    }
#line 6608 "build/parser.cpp"
    break;

  case 398: /* primary_expr: BIF_LIST LPAREN arg_list RPAREN  */
#line 2071 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("LIST", (yyvsp[-1].expr_list));
    }
#line 6616 "build/parser.cpp"
    break;

  case 399: /* primary_expr: BIF_RANGE LPAREN arg_list RPAREN  */
#line 2074 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("RANGE", (yyvsp[-1].expr_list));
    }
#line 6624 "build/parser.cpp"
    break;

  case 400: /* primary_expr: BIF_LOOKUPLT LPAREN arg_list RPAREN  */
#line 2077 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPLT", (yyvsp[-1].expr_list));
    }
#line 6632 "build/parser.cpp"
    break;

  case 401: /* primary_expr: BIF_LOOKUPGE LPAREN arg_list RPAREN  */
#line 2080 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPGE", (yyvsp[-1].expr_list));
    }
#line 6640 "build/parser.cpp"
    break;

  case 402: /* primary_expr: BIF_LOOKUPLE LPAREN arg_list RPAREN  */
#line 2083 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPLE", (yyvsp[-1].expr_list));
    }
#line 6648 "build/parser.cpp"
    break;

  case 403: /* primary_expr: BIF_LOOKUPGT LPAREN arg_list RPAREN  */
#line 2086 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPGT", (yyvsp[-1].expr_list));
    }
#line 6656 "build/parser.cpp"
    break;

  case 404: /* primary_expr: BIF_TLOOKUP LPAREN arg_list RPAREN  */
#line 2089 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("TLOOKUP", (yyvsp[-1].expr_list));
    }
#line 6664 "build/parser.cpp"
    break;

  case 405: /* primary_expr: BIF_TLOOKUPLT LPAREN arg_list RPAREN  */
#line 2092 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TLOOKUPLT", (yyvsp[-1].expr_list));
    }
#line 6672 "build/parser.cpp"
    break;

  case 406: /* primary_expr: BIF_TLOOKUPGT LPAREN arg_list RPAREN  */
#line 2095 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TLOOKUPGT", (yyvsp[-1].expr_list));
    }
#line 6680 "build/parser.cpp"
    break;

  case 407: /* primary_expr: BIF_TLOOKUPLE LPAREN arg_list RPAREN  */
#line 2098 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TLOOKUPLE", (yyvsp[-1].expr_list));
    }
#line 6688 "build/parser.cpp"
    break;

  case 408: /* primary_expr: BIF_TLOOKUPGE LPAREN arg_list RPAREN  */
#line 2101 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TLOOKUPGE", (yyvsp[-1].expr_list));
    }
#line 6696 "build/parser.cpp"
    break;

  case 409: /* primary_expr: BIF_HOURS LPAREN expression RPAREN  */
#line 2104 "src/parser.y"
                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("HOURS", args);
    }
#line 6706 "build/parser.cpp"
    break;

  case 410: /* primary_expr: BIF_MINUTES LPAREN expression RPAREN  */
#line 2109 "src/parser.y"
                                           {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("MINUTES", args);
    }
#line 6716 "build/parser.cpp"
    break;

  case 411: /* primary_expr: BIF_SECONDS LPAREN expression RPAREN  */
#line 2114 "src/parser.y"
                                           {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("SECONDS", args);
    }
#line 6726 "build/parser.cpp"
    break;

  case 412: /* primary_expr: BIF_MSECONDS LPAREN expression RPAREN  */
#line 2119 "src/parser.y"
                                            {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("MSECONDS", args);
    }
#line 6736 "build/parser.cpp"
    break;

  case 413: /* primary_expr: BIF_PADDR LPAREN IDENTIFIER RPAREN  */
#line 2124 "src/parser.y"
                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::StringLiteral((yyvsp[-1].sval)));
        free((yyvsp[-1].sval));
        (yyval.expr) = make_bif("PADDR", args);
    }
#line 6747 "build/parser.cpp"
    break;

  case 414: /* primary_expr: BIF_PROC LPAREN RPAREN  */
#line 2130 "src/parser.y"
                             {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("PROC", empty);
    }
#line 6756 "build/parser.cpp"
    break;

  case 415: /* primary_expr: BIF_PROC  */
#line 2134 "src/parser.y"
               {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("PROC", empty);
    }
#line 6765 "build/parser.cpp"
    break;

  case 416: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_HOURS RPAREN  */
#line 2138 "src/parser.y"
                                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("HOURS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 6777 "build/parser.cpp"
    break;

  case 417: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_MINUTES RPAREN  */
#line 2145 "src/parser.y"
                                                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MINUTES"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 6789 "build/parser.cpp"
    break;

  case 418: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_SECONDS RPAREN  */
#line 2152 "src/parser.y"
                                                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("SECONDS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 6801 "build/parser.cpp"
    break;

  case 419: /* primary_expr: KW_ALL STRING_LITERAL  */
#line 2159 "src/parser.y"
                            {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::StringLiteral((yyvsp[0].sval)));
        free((yyvsp[0].sval));
        (yyval.expr) = make_bif("ALL", args);
    }
#line 6812 "build/parser.cpp"
    break;

  case 420: /* primary_expr: BIF_PASSED LPAREN ident RPAREN  */
#line 2165 "src/parser.y"
                                     {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::Identifier((yyvsp[-1].sval)));
        free((yyvsp[-1].sval));
        (yyval.expr) = make_bif("PASSED", args);
    }
#line 6823 "build/parser.cpp"
    break;

  case 421: /* primary_expr: BIF_OMITTED LPAREN ident RPAREN  */
#line 2171 "src/parser.y"
                                      {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::Identifier((yyvsp[-1].sval)));
        free((yyvsp[-1].sval));
        (yyval.expr) = make_bif("OMITTED", args);
    }
#line 6834 "build/parser.cpp"
    break;

  case 422: /* primary_expr: BIF_BITAND LPAREN arg_list RPAREN  */
#line 2177 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("BITAND", (yyvsp[-1].expr_list));
    }
#line 6842 "build/parser.cpp"
    break;

  case 423: /* primary_expr: BIF_BITNOT LPAREN arg_list RPAREN  */
#line 2180 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("BITNOT", (yyvsp[-1].expr_list));
    }
#line 6850 "build/parser.cpp"
    break;

  case 424: /* primary_expr: BIF_BITOR LPAREN arg_list RPAREN  */
#line 2183 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("BITOR", (yyvsp[-1].expr_list));
    }
#line 6858 "build/parser.cpp"
    break;

  case 425: /* primary_expr: BIF_BITXOR LPAREN arg_list RPAREN  */
#line 2186 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("BITXOR", (yyvsp[-1].expr_list));
    }
#line 6866 "build/parser.cpp"
    break;

  case 426: /* primary_expr: BIF_SCANR LPAREN arg_list RPAREN  */
#line 2189 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("SCANR", (yyvsp[-1].expr_list));
    }
#line 6874 "build/parser.cpp"
    break;

  case 427: /* primary_expr: BIF_EDITFLT LPAREN arg_list RPAREN  */
#line 2192 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("EDITFLT", (yyvsp[-1].expr_list));
    }
#line 6882 "build/parser.cpp"
    break;

  case 428: /* primary_expr: BIF_UNSH LPAREN arg_list RPAREN  */
#line 2195 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("UNSH", (yyvsp[-1].expr_list));
    }
#line 6890 "build/parser.cpp"
    break;

  case 429: /* primary_expr: BIF_PARMNUM LPAREN ident RPAREN  */
#line 2198 "src/parser.y"
                                      {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::Identifier((yyvsp[-1].sval)));
        free((yyvsp[-1].sval));
        (yyval.expr) = make_bif("PARMNUM", args);
    }
#line 6901 "build/parser.cpp"
    break;

  case 430: /* primary_expr: BIF_GETENV LPAREN arg_list RPAREN  */
#line 2204 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("GETENV", (yyvsp[-1].expr_list));
    }
#line 6909 "build/parser.cpp"
    break;

  case 431: /* primary_expr: INDICATOR  */
#line 2207 "src/parser.y"
                {
        (yyval.expr) = new rpg::IndicatorExpr((yyvsp[0].ival));
    }
#line 6917 "build/parser.cpp"
    break;

  case 432: /* primary_expr: KW_ON  */
#line 2210 "src/parser.y"
            {
        (yyval.expr) = new rpg::IntLiteral(1);  // *ON → true
    }
#line 6925 "build/parser.cpp"
    break;

  case 433: /* primary_expr: KW_OFF  */
#line 2213 "src/parser.y"
             {
        (yyval.expr) = new rpg::IntLiteral(0);  // *OFF → false
    }
#line 6933 "build/parser.cpp"
    break;

  case 434: /* primary_expr: KW_NULL  */
#line 2216 "src/parser.y"
              {
        (yyval.expr) = new rpg::Identifier("nullptr");
    }
#line 6941 "build/parser.cpp"
    break;

  case 435: /* primary_expr: KW_OMIT  */
#line 2219 "src/parser.y"
              {
        (yyval.expr) = new rpg::Identifier("nullptr");
    }
#line 6949 "build/parser.cpp"
    break;

  case 436: /* primary_expr: KW_BLANKS  */
#line 2222 "src/parser.y"
                {
        (yyval.expr) = new rpg::Identifier("RPG_BLANKS");
    }
#line 6957 "build/parser.cpp"
    break;

  case 437: /* primary_expr: KW_ZEROS  */
#line 2225 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier("RPG_ZEROS");
    }
#line 6965 "build/parser.cpp"
    break;

  case 438: /* primary_expr: KW_HIVAL  */
#line 2228 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier("RPG_HIVAL");
    }
#line 6973 "build/parser.cpp"
    break;

  case 439: /* primary_expr: KW_LOVAL  */
#line 2231 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier("RPG_LOVAL");
    }
#line 6981 "build/parser.cpp"
    break;

  case 440: /* primary_expr: LPAREN expression RPAREN  */
#line 2234 "src/parser.y"
                               {
        (yyval.expr) = (yyvsp[-1].expr);
    }
#line 6989 "build/parser.cpp"
    break;

  case 441: /* call_args_opt: %empty  */
#line 2241 "src/parser.y"
                { (yyval.expr_list) = nullptr; }
#line 6995 "build/parser.cpp"
    break;

  case 442: /* call_args_opt: call_arg_list  */
#line 2242 "src/parser.y"
                    { (yyval.expr_list) = (yyvsp[0].expr_list); }
#line 7001 "build/parser.cpp"
    break;

  case 443: /* call_arg_list: expression  */
#line 2246 "src/parser.y"
               {
        (yyval.expr_list) = new std::vector<rpg::Expression*>();
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 7010 "build/parser.cpp"
    break;

  case 444: /* call_arg_list: call_arg_list COLON expression  */
#line 2250 "src/parser.y"
                                     {
        (yyval.expr_list) = (yyvsp[-2].expr_list);
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 7019 "build/parser.cpp"
    break;

  case 445: /* arg_list: expression  */
#line 2258 "src/parser.y"
               {
        (yyval.expr_list) = new std::vector<rpg::Expression*>();
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 7028 "build/parser.cpp"
    break;

  case 446: /* arg_list: arg_list COLON expression  */
#line 2262 "src/parser.y"
                                {
        (yyval.expr_list) = (yyvsp[-2].expr_list);
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 7037 "build/parser.cpp"
    break;


#line 7041 "build/parser.cpp"

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

#line 2268 "src/parser.y"


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
