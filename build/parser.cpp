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
  YYSYMBOL_KW_RTNPARM = 207,               /* KW_RTNPARM  */
  YYSYMBOL_KW_OPDESC = 208,                /* KW_OPDESC  */
  YYSYMBOL_KW_ASCEND = 209,                /* KW_ASCEND  */
  YYSYMBOL_KW_DESCEND = 210,               /* KW_DESCEND  */
  YYSYMBOL_KW_NULLIND = 211,               /* KW_NULLIND  */
  YYSYMBOL_KW_VARSIZE = 212,               /* KW_VARSIZE  */
  YYSYMBOL_KW_STRING_OPT = 213,            /* KW_STRING_OPT  */
  YYSYMBOL_KW_TRIM_OPT = 214,              /* KW_TRIM_OPT  */
  YYSYMBOL_KW_DCL_ENUM = 215,              /* KW_DCL_ENUM  */
  YYSYMBOL_KW_END_ENUM = 216,              /* KW_END_ENUM  */
  YYSYMBOL_KW_BOOLEAN = 217,               /* KW_BOOLEAN  */
  YYSYMBOL_EXEC_SQL_TEXT = 218,            /* EXEC_SQL_TEXT  */
  YYSYMBOL_POWER = 219,                    /* POWER  */
  YYSYMBOL_KW_DIM_VAR = 220,               /* KW_DIM_VAR  */
  YYSYMBOL_KW_DIM_AUTO = 221,              /* KW_DIM_AUTO  */
  YYSYMBOL_KW_FOR_EACH = 222,              /* KW_FOR_EACH  */
  YYSYMBOL_KW_IN = 223,                    /* KW_IN  */
  YYSYMBOL_KW_XML_INTO = 224,              /* KW_XML_INTO  */
  YYSYMBOL_IDENTIFIER = 225,               /* IDENTIFIER  */
  YYSYMBOL_INTEGER_LITERAL = 226,          /* INTEGER_LITERAL  */
  YYSYMBOL_FLOAT_LITERAL = 227,            /* FLOAT_LITERAL  */
  YYSYMBOL_STRING_LITERAL = 228,           /* STRING_LITERAL  */
  YYSYMBOL_SEMICOLON = 229,                /* SEMICOLON  */
  YYSYMBOL_EQUALS = 230,                   /* EQUALS  */
  YYSYMBOL_LPAREN = 231,                   /* LPAREN  */
  YYSYMBOL_RPAREN = 232,                   /* RPAREN  */
  YYSYMBOL_COLON = 233,                    /* COLON  */
  YYSYMBOL_PLUS = 234,                     /* PLUS  */
  YYSYMBOL_MINUS = 235,                    /* MINUS  */
  YYSYMBOL_STAR = 236,                     /* STAR  */
  YYSYMBOL_SLASH = 237,                    /* SLASH  */
  YYSYMBOL_NE = 238,                       /* NE  */
  YYSYMBOL_LE = 239,                       /* LE  */
  YYSYMBOL_GE = 240,                       /* GE  */
  YYSYMBOL_LT = 241,                       /* LT  */
  YYSYMBOL_GT = 242,                       /* GT  */
  YYSYMBOL_YYACCEPT = 243,                 /* $accept  */
  YYSYMBOL_program = 244,                  /* program  */
  YYSYMBOL_statements_opt = 245,           /* statements_opt  */
  YYSYMBOL_statement_list = 246,           /* statement_list  */
  YYSYMBOL_statement = 247,                /* statement  */
  YYSYMBOL_dcl_f_stmt = 248,               /* dcl_f_stmt  */
  YYSYMBOL_dcl_s_stmt = 249,               /* dcl_s_stmt  */
  YYSYMBOL_dcl_s_keywords = 250,           /* dcl_s_keywords  */
  YYSYMBOL_dcl_c_stmt = 251,               /* dcl_c_stmt  */
  YYSYMBOL_eval_target = 252,              /* eval_target  */
  YYSYMBOL_eval_stmt = 253,                /* eval_stmt  */
  YYSYMBOL_eval_corr_stmt = 254,           /* eval_corr_stmt  */
  YYSYMBOL_xml_into_stmt = 255,            /* xml_into_stmt  */
  YYSYMBOL_evalr_stmt = 256,               /* evalr_stmt  */
  YYSYMBOL_callp_stmt = 257,               /* callp_stmt  */
  YYSYMBOL_leavesr_stmt = 258,             /* leavesr_stmt  */
  YYSYMBOL_dsply_stmt = 259,               /* dsply_stmt  */
  YYSYMBOL_inlr_stmt = 260,                /* inlr_stmt  */
  YYSYMBOL_return_stmt = 261,              /* return_stmt  */
  YYSYMBOL_expr_stmt = 262,                /* expr_stmt  */
  YYSYMBOL_dcl_pr_stmt = 263,              /* dcl_pr_stmt  */
  YYSYMBOL_dcl_proc_stmt = 264,            /* dcl_proc_stmt  */
  YYSYMBOL_proc_export = 265,              /* proc_export  */
  YYSYMBOL_pi_return_type = 266,           /* pi_return_type  */
  YYSYMBOL_pi_params = 267,                /* pi_params  */
  YYSYMBOL_pi_param = 268,                 /* pi_param  */
  YYSYMBOL_pr_params = 269,                /* pr_params  */
  YYSYMBOL_pr_param = 270,                 /* pr_param  */
  YYSYMBOL_monitor_stmt = 271,             /* monitor_stmt  */
  YYSYMBOL_begsr_stmt = 272,               /* begsr_stmt  */
  YYSYMBOL_exsr_stmt = 273,                /* exsr_stmt  */
  YYSYMBOL_sorta_stmt = 274,               /* sorta_stmt  */
  YYSYMBOL_reset_stmt = 275,               /* reset_stmt  */
  YYSYMBOL_clear_stmt = 276,               /* clear_stmt  */
  YYSYMBOL_dealloc_stmt = 277,             /* dealloc_stmt  */
  YYSYMBOL_test_stmt = 278,                /* test_stmt  */
  YYSYMBOL_exec_sql_stmt = 279,            /* exec_sql_stmt  */
  YYSYMBOL_dcl_enum_stmt = 280,            /* dcl_enum_stmt  */
  YYSYMBOL_enum_constants = 281,           /* enum_constants  */
  YYSYMBOL_enum_constant = 282,            /* enum_constant  */
  YYSYMBOL_dcl_ds_stmt = 283,              /* dcl_ds_stmt  */
  YYSYMBOL_ds_fields = 284,                /* ds_fields  */
  YYSYMBOL_ds_field = 285,                 /* ds_field  */
  YYSYMBOL_if_stmt = 286,                  /* if_stmt  */
  YYSYMBOL_elseif_clauses = 287,           /* elseif_clauses  */
  YYSYMBOL_elseif_clause = 288,            /* elseif_clause  */
  YYSYMBOL_else_clause = 289,              /* else_clause  */
  YYSYMBOL_dow_stmt = 290,                 /* dow_stmt  */
  YYSYMBOL_dou_stmt = 291,                 /* dou_stmt  */
  YYSYMBOL_for_stmt = 292,                 /* for_stmt  */
  YYSYMBOL_for_each_stmt = 293,            /* for_each_stmt  */
  YYSYMBOL_select_stmt = 294,              /* select_stmt  */
  YYSYMBOL_when_clauses = 295,             /* when_clauses  */
  YYSYMBOL_when_clause = 296,              /* when_clause  */
  YYSYMBOL_other_clause = 297,             /* other_clause  */
  YYSYMBOL_iter_stmt = 298,                /* iter_stmt  */
  YYSYMBOL_leave_stmt = 299,               /* leave_stmt  */
  YYSYMBOL_expression = 300,               /* expression  */
  YYSYMBOL_or_expr = 301,                  /* or_expr  */
  YYSYMBOL_and_expr = 302,                 /* and_expr  */
  YYSYMBOL_not_expr = 303,                 /* not_expr  */
  YYSYMBOL_comparison_expr = 304,          /* comparison_expr  */
  YYSYMBOL_additive_expr = 305,            /* additive_expr  */
  YYSYMBOL_multiplicative_expr = 306,      /* multiplicative_expr  */
  YYSYMBOL_power_expr = 307,               /* power_expr  */
  YYSYMBOL_unary_expr = 308,               /* unary_expr  */
  YYSYMBOL_postfix_expr = 309,             /* postfix_expr  */
  YYSYMBOL_ident = 310,                    /* ident  */
  YYSYMBOL_primary_expr = 311,             /* primary_expr  */
  YYSYMBOL_call_args_opt = 312,            /* call_args_opt  */
  YYSYMBOL_call_arg_list = 313,            /* call_arg_list  */
  YYSYMBOL_arg_list = 314                  /* arg_list  */
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
#define YYLAST   4889

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  243
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  72
/* YYNRULES -- Number of rules.  */
#define YYNRULES  451
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  1477

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   497


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
     235,   236,   237,   238,   239,   240,   241,   242
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   194,   194,   197,   202,   204,   209,   218,   221,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   242,   243,   244,   245,   246,   247,   248,   249,   250,
     251,   252,   253,   254,   255,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   269,   273,   277,   281,   289,   294,
     299,   304,   309,   314,   319,   324,   329,   334,   339,   344,
     350,   356,   362,   366,   370,   374,   378,   382,   386,   390,
     394,   398,   402,   408,   414,   420,   426,   433,   438,   444,
     449,   454,   459,   464,   469,   474,   479,   484,   489,   494,
     499,   507,   508,   509,   510,   511,   516,   523,   527,   528,
     529,   530,   531,   532,   533,   534,   535,   536,   537,   538,
     539,   540,   541,   544,   550,   554,   560,   566,   572,   581,
     589,   595,   604,   613,   619,   625,   631,   637,   640,   647,
     658,   675,   695,   710,   734,   759,   786,   816,   817,   822,
     823,   824,   825,   826,   831,   834,   842,   846,   850,   854,
     858,   862,   866,   870,   875,   879,   883,   887,   891,   895,
     899,   903,   907,   913,   918,   923,   928,   934,   939,   944,
     949,   955,   960,   965,   974,   977,   985,   989,   993,   997,
    1001,  1005,  1009,  1013,  1018,  1022,  1026,  1030,  1034,  1038,
    1042,  1046,  1050,  1056,  1061,  1066,  1071,  1077,  1082,  1087,
    1092,  1098,  1103,  1108,  1118,  1129,  1139,  1147,  1155,  1162,
    1170,  1178,  1189,  1199,  1207,  1218,  1221,  1229,  1237,  1252,
    1261,  1270,  1280,  1290,  1301,  1312,  1323,  1334,  1342,  1351,
    1361,  1372,  1383,  1395,  1398,  1406,  1410,  1414,  1418,  1423,
    1427,  1431,  1435,  1440,  1446,  1452,  1459,  1466,  1473,  1479,
    1487,  1493,  1504,  1527,  1528,  1536,  1545,  1546,  1552,  1561,
    1570,  1580,  1590,  1600,  1613,  1623,  1642,  1646,  1653,  1662,
    1663,  1669,  1673,  1679,  1683,  1684,  1692,  1693,  1701,  1702,
    1708,  1709,  1714,  1719,  1724,  1729,  1734,  1739,  1747,  1748,
    1753,  1761,  1762,  1767,  1775,  1776,  1784,  1785,  1793,  1794,
    1801,  1802,  1803,  1804,  1805,  1806,  1807,  1808,  1809,  1810,
    1811,  1812,  1813,  1814,  1815,  1816,  1820,  1824,  1825,  1826,
    1827,  1828,  1829,  1830,  1831,  1832,  1833,  1834,  1835,  1836,
    1837,  1838,  1841,  1844,  1848,  1852,  1855,  1858,  1861,  1864,
    1867,  1870,  1873,  1876,  1879,  1882,  1885,  1888,  1892,  1895,
    1898,  1901,  1904,  1907,  1910,  1913,  1916,  1922,  1928,  1934,
    1940,  1946,  1952,  1955,  1958,  1961,  1964,  1968,  1972,  1975,
    1978,  1981,  1984,  1987,  1990,  1994,  1997,  2001,  2004,  2008,
    2015,  2022,  2029,  2034,  2039,  2044,  2048,  2052,  2055,  2058,
    2061,  2064,  2067,  2070,  2073,  2076,  2079,  2082,  2085,  2088,
    2091,  2094,  2097,  2100,  2103,  2106,  2109,  2112,  2115,  2118,
    2121,  2124,  2127,  2130,  2133,  2138,  2143,  2148,  2153,  2159,
    2163,  2167,  2174,  2181,  2188,  2194,  2200,  2206,  2209,  2212,
    2215,  2218,  2221,  2224,  2227,  2233,  2236,  2239,  2242,  2245,
    2248,  2251,  2254,  2257,  2260,  2263,  2270,  2271,  2275,  2279,
    2287,  2291
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
  "KW_POS", "KW_PREFIX", "KW_DATFMT", "KW_TIMFMT", "KW_EXTNAME",
  "KW_RTNPARM", "KW_OPDESC", "KW_ASCEND", "KW_DESCEND", "KW_NULLIND",
  "KW_VARSIZE", "KW_STRING_OPT", "KW_TRIM_OPT", "KW_DCL_ENUM",
  "KW_END_ENUM", "KW_BOOLEAN", "EXEC_SQL_TEXT", "POWER", "KW_DIM_VAR",
  "KW_DIM_AUTO", "KW_FOR_EACH", "KW_IN", "KW_XML_INTO", "IDENTIFIER",
  "INTEGER_LITERAL", "FLOAT_LITERAL", "STRING_LITERAL", "SEMICOLON",
  "EQUALS", "LPAREN", "RPAREN", "COLON", "PLUS", "MINUS", "STAR", "SLASH",
  "NE", "LE", "GE", "LT", "GT", "$accept", "program", "statements_opt",
  "statement_list", "statement", "dcl_f_stmt", "dcl_s_stmt",
  "dcl_s_keywords", "dcl_c_stmt", "eval_target", "eval_stmt",
  "eval_corr_stmt", "xml_into_stmt", "evalr_stmt", "callp_stmt",
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

#define YYPACT_NINF (-811)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-271)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      65,  -811,    97,    73,   524,  -811,  -127,   -92,   260,   -81,
    4190,   142,   260,   142,  4190,   -67,   260,   -66,  -811,  3426,
     -62,  4190,  4190,  4190,   260,   -20,     0,    22,    58,    41,
     260,   260,   260,   260,  -811,    67,    69,    79,    59,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,    98,  -811,   260,   260,    13,  -811,  -811,
    -811,  -811,    96,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,   231,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,    28,  4190,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  4381,   107,   123,   135,   149,   163,   171,
     178,   182,   195,   202,   209,   222,   226,   229,   242,   245,
     253,   280,   290,   292,   323,   330,   350,   357,   366,   373,
     380,   396,   423,   463,   507,   514,   516,   527,   528,   529,
     530,   531,   533,   534,   535,   536,   537,   538,   539,   540,
     541,   542,   543,   544,   545,   546,   547,   548,   549,   557,
     560,   561,   562,   563,   564,   565,   566,   567,   568,   569,
     570,   573,   574,   575,   576,   577,   584,   586,   587,   589,
     597,   600,   602,   607,   608,   609,   611,   612,   613,   615,
     208,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,   616,  -811,  -811,  -811,  4190,
    4572,   213,   495,   504,  -811,   205,    14,  -172,  -811,   394,
     646,  -811,    32,   625,   628,   629,   631,  -811,   632,   260,
    -811,   633,   810,   635,   636,   637,   643,   796,  -811,  -811,
    -811,   642,   648,   650,   653,   655,   829,   379,    27,  4190,
     -24,   662,   694,   670,  4190,  4190,    -8,   658,   667,   669,
     674,   675,   676,   678,  -128,   -89,   681,   682,   684,   683,
     685,   686,   687,   690,   691,   695,   698,   700,   205,  4190,
    4190,  4190,  4190,  4190,  4190,  4190,  4190,  4190,  4190,  4190,
    4190,   693,   699,  4190,  4190,  4190,  4190,  4190,   701,   702,
     704,  4190,  4190,  4190,  3617,  3808,  3999,  4190,  4190,  4190,
    4190,  4190,  4190,  4190,  4190,  4190,  4190,  4190,  4190,  4190,
    4190,  4190,  4190,  4190,  4190,  4190,  4190,  4190,  4190,  4190,
    4190,  4190,  4190,  4190,  4190,  4190,  4190,  4190,  4190,  4190,
    4190,  4190,  4190,  4190,  4190,  4190,  4190,  4190,  4190,  4190,
    4190,  4190,   673,   705,   260,   260,  4190,  4190,  4190,  4190,
    4190,  4190,  4190,   260,  4190,  -811,  4190,   706,   646,  -811,
    4190,  4190,  4381,  4381,  4381,  4381,  4381,  4381,  4381,  4381,
    4381,  4381,  4381,  4381,   707,  4190,  4190,   260,  4190,  -811,
    -811,   708,  -811,   710,  -811,  -811,  -811,  4190,  4190,   111,
    -811,  1389,  -811,  -811,  -811,  -811,  -811,  -811,   712,   711,
     713,   716,   717,   719,     2,   -43,   720,   732,   733,  -811,
    -811,   109,   714,   742,  4190,   734,  -811,   736,   738,   697,
     743,   746,  -811,  -811,  -811,   745,   748,   752,   753,   754,
     750,  -811,   755,  -811,  -811,  -811,  -811,   757,   758,   759,
     761,   762,   763,   723,  -811,  -811,   124,   136,   140,   152,
     185,   206,   216,   277,   282,   287,   294,   303,  -811,  -811,
     305,   307,   309,   311,   313,  -811,  -811,  -811,   315,   317,
     320,  -811,   332,  -811,   334,  -811,   336,   760,   764,   765,
     767,   338,   340,   345,   347,   352,   360,   363,   768,   369,
     384,   387,   390,   392,   397,   399,   401,   403,   405,   407,
     410,   412,   414,   416,   418,   420,   424,   426,   428,   430,
     432,   434,   436,   438,   440,   442,   444,   446,   770,   771,
     773,   774,   776,  -811,   777,   778,   448,   450,   452,   454,
     456,   458,   460,   779,   464,  -811,   782,  -811,   504,  -811,
      12,    12,    12,    12,    12,    12,    12,  -172,  -172,  -811,
    -811,  -811,  -811,   736,   786,   788,   789,   260,  -811,   751,
    1604,  1671,   139,   801,   802,  -811,   910,   803,  -811,  1886,
     898,   766,   808,   809,   811,   772,   807,  -811,   816,   817,
    -811,   113,   769,   814,    16,  -811,  4190,   742,   469,  -129,
    -811,   820,  4190,   886,   821,  4190,  -811,   815,   822,   823,
     824,   819,   825,   828,   832,   827,   830,   831,   833,   834,
     835,   836,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  4190,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,   471,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,   839,   641,   841,   848,
    4190,  4190,  -811,  -811,   851,  -811,   852,     9,   850,   853,
     854,   855,   857,   859,    18,   204,   858,    36,   860,   861,
     863,   864,   470,   868,   865,   296,  -811,  -811,   -61,  -811,
    4190,   875,  -811,  -811,   472,   881,  -811,  -811,   874,   341,
     359,   374,   838,   883,   885,   888,   889,   275,   275,   275,
     275,   275,   894,   895,   897,   899,   900,   901,   903,   904,
    -811,  4190,   918,  -811,   999,  -811,  -811,   -32,   -31,   818,
    1953,  -811,  2168,  -811,   467,   919,  -811,  -811,  -811,   923,
     921,   920,   922,   902,   300,  -811,   927,   928,   930,   474,
     924,   929,   937,   962,   -28,   925,   938,  -811,   318,   935,
     936,   940,   942,   943,   939,   946,  -811,  2235,   947,  4190,
    -811,   944,  1148,   948,  -811,  -811,   953,  1155,  -811,   956,
     960,   963,  -811,   964,   967,  1169,   969,   971,  1173,   974,
     977,   975,   976,   980,   981,  -811,   982,   983,   984,   985,
     986,   987,   477,  -811,  -811,  -811,  -811,  -811,  -811,   988,
    -811,   989,  4190,  -811,  4190,  -811,   991,   992,  -811,   990,
    -811,   994,  -811,   494,   995,   996,   997,   998,  1000,  1004,
    1006,  1007,  1008,  1013,  -811,   993,  1001,  1011,  1021,  -811,
    -811,  1022,  1025,  1026,  1028,  1029,  1030,  1027,  1037,  1041,
    1042,  1044,  -811,  -811,  1043,  -811,  1034,  1038,  1045,  4190,
    1046,  1047,  1048,  -811,  4190,   211,  -811,  1049,  4190,  1050,
    1051,   230,  -811,   382,   275,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  1052,  1053,  1054,  1055,  1056,  1057,  1058,  -811,
    2450,  -811,  1062,  2517,  1063,  2732,  -811,  -811,    -5,  -811,
      25,  -811,  1064,  1065,  1066,  1067,  1068,  1073,  1074,  1077,
    1059,  1061,  1072,  -811,  -811,  1075,  1117,  1174,  -811,  1080,
      47,  1178,  1093,  1094,  1095,  1098,  1105,  1101,  1102,  1103,
    1104,  1106,  -811,  1110,  1111,  4190,  1109,  1112,  4190,  1113,
    1114,  1115,  1116,  1118,  4190,  1119,  1120,  4190,  1129,  1130,
    1132,  1249,  1134,  1135,  1138,  1139,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  1040,  -811,  1140,  -811,  1141,    17,  1142,
    1122,   351,  -811,  1143,    37,  1149,  1150,  1151,  1152,  1147,
    1154,  1156,  1158,  1157,  1153,  1170,    48,    68,  1171,  1175,
    1180,    71,  1179,  1181,  1185,  1183,  1186,  1194,  1184,  1197,
    -112,  1201,    31,  1176,  1202,  -811,  -811,  1200,  1204,  1205,
    1203,    60,  1207,  1211,  1212,  1213,  1214,  1215,  1216,  1217,
    1222,  1224,    76,  1225,  4190,  1227,  -811,  -811,  2799,  -811,
    3014,  -811,  1226,  -811,   520,  1229,  1230,  1231,  1236,  1238,
    -811,  1228,  1239,  1244,  1245,  1210,   -40,   -33,   -27,  1232,
    1251,  -811,  -811,  1252,  1253,  -811,  -811,  -811,  1255,  1256,
    -811,  -811,  1258,  1259,  1260,  1264,  1262,  1247,  1261,  -811,
    -811,  1263,  1265,  -811,  1266,  -811,  1268,  -811,  -811,  1270,
    1271,  1272,  -811,  -811,  1273,  1275,  -811,  1274,  -811,  -811,
    1279,  1277,  1278,  1282,  1283,  -811,  4190,  1281,  1286,  1285,
    1290,  -811,  1107,  1284,  1291,  1303,  1304,  1267,  1269,  1276,
    1295,  1311,  -811,   -44,   -42,   -41,  1312,  1308,   -38,  -811,
    1310,   -19,  -811,  1314,   -18,  -811,  1316,  -811,    74,    75,
    -811,  -811,    77,    78,    81,  -811,  -811,   110,  -811,  -811,
    -811,  1317,  -811,  1318,  1324,  1326,  1327,   -87,  -811,  -811,
    -811,  -811,  1313,  1323,  -811,  -811,  1325,  1328,  -811,  -811,
    1329,  1330,  1331,  -811,  -811,  1322,  1333,  1334,  1332,  1338,
    1339,  1340,  1335,  1336,  1337,  1341,  1343,  1342,  -811,  1344,
    -811,  1347,  -811,  1345,   664,  1348,  -811,   666,  1349,  -811,
     668,  1350,  -811,   -26,  1353,  1356,  1357,  1359,  1360,  1372,
    1373,   482,  1346,   484,  1371,  1375,  -811,  -811,  -811,  -811,
    -811,  1383,  -811,  -811,  1386,  1387,  -811,  -811,  1385,  1388,
    1390,  1391,   -25,   -15,   -14,  1392,  1394,  -811,  -811,  -811,
     -36,  1393,  1395,  1292,  1396,  1398,  1298,  1399,  1401,  1299,
    1397,   -17,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    1402,  1408,  1412,  1415,  1419,  1417,  1421,  -811,  -811,  -811,
    3081,   -35,   -34,   -30,  1422,  1418,   -12,  -811,  1420,   -11,
    -811,  1423,     6,  -811,  1425,  -811,  1424,  -811,  1459,  1429,
    1427,  1510,  1431,  1432,  1511,  1434,  1433,  1525,  1430,  -811,
    -811,  1438,  -811,  -811,  1439,  -811,  1441,  3296,  1452,  1453,
    -811,  1455,  -811,  1457,  -811,  1460,   679,  1462,  -811,   692,
    1464,  -811,   696,  1465,  -811,   -13,  -811,  1467,  -811,  1468,
    1476,  -811,  1471,  1479,  -811,  1483,  1481,  1528,  1485,  1486,
    1487,  1488,  -811,  -811,  -811,  -811,   -29,  1458,  1492,  1575,
    1493,  1495,  1577,  1497,  1496,  1581,  1489,     7,  -811,  1490,
    -811,  1502,  -811,  1503,  -811,  1508,  1506,  -811,  -811,  -811,
    -811,  1513,  -811,  1605,  1514,  1507,  1607,  1515,  1516,  1673,
    1520,  1519,  1680,  1509,  -811,  -811,  -811,  -811,  -811,  1524,
    -811,  1526,  -811,  1530,  1531,  -811,  1533,  1532,  -811,  1537,
    1535,  1716,  -811,  1540,  -811,  1541,  -811,  1542,  -811,  1543,
    1544,  -811,  -811,  -811,  -811,  1545,  -811
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int16 yydefact[] =
{
       4,     4,     0,     0,     0,     1,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     6,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   112,     0,     0,     0,     0,   101,
     102,   103,    99,    98,   100,   109,   110,   111,   106,   107,
     104,   105,   108,     0,   212,     0,     0,    97,     5,     9,
      10,    11,     0,    12,    13,    41,    35,    36,    37,    14,
      15,    16,    42,    26,    25,    29,    30,    31,    34,    32,
      33,    38,    39,    40,    28,    27,    17,    18,    19,    20,
      21,    22,    23,    24,    43,     0,   301,   302,   303,   313,
     314,   315,   310,   311,   312,   307,   308,   304,   305,   309,
     306,   300,     0,     0,   439,   440,   437,   441,   442,   443,
     444,   438,   436,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   420,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   317,   318,   319,   326,   327,   328,   325,   329,   330,
     322,   323,   320,   321,   324,   316,   331,   332,   333,     0,
       0,     0,   273,   274,   276,   278,   280,   288,   291,   294,
     296,   298,    97,     0,     0,     0,     0,   124,     0,     0,
     128,     0,     0,     0,     0,     0,     0,     0,   271,   272,
       7,     0,     0,     0,     0,     0,   137,   139,     0,     0,
       0,     0,     0,     0,   446,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   279,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   424,   446,     0,   297,   125,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   123,
     210,     0,   127,     0,     7,     7,     7,     0,     0,   269,
     266,     0,     7,   206,   208,   209,   207,   138,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   233,
     450,     0,     0,     0,     0,     0,   113,   448,     0,   447,
       0,     0,    44,    45,    46,     0,     0,     0,     0,     0,
       0,    64,     0,    65,    66,    62,    67,     0,     0,     0,
       0,     0,     0,     0,    63,    96,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   385,   386,
       0,     0,     0,     0,     0,   347,   366,   367,     0,     0,
       0,   374,     0,   376,     0,   378,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   419,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   448,     0,   445,   275,   277,
     281,   282,   285,   286,   283,   284,   287,   289,   290,   292,
     293,   295,   299,     0,     0,     0,     0,     0,   126,     0,
       0,     0,     0,     0,     0,   267,     0,     0,     8,     0,
       0,     0,     0,     0,     0,     0,     0,   174,     0,     0,
     233,     0,     0,     0,     0,   116,     0,     0,     0,     0,
     215,     0,     0,   114,     0,     0,   117,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   335,   336,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   370,   371,   372,   368,   369,   364,
     365,   348,   373,   375,   377,     0,   382,   383,   384,   349,
     350,   351,   352,   353,   354,   355,     0,   362,   363,   387,
     388,   389,   400,   394,   390,   391,   392,   393,   395,   396,
     397,   398,   399,   401,   402,   403,   404,   405,   406,   407,
     408,   409,   410,   411,   412,   413,   414,   415,   416,   417,
     418,   425,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   334,   118,   119,   122,     0,   256,     0,     0,
       0,     0,     7,     7,     0,     7,     0,   139,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   234,   451,     0,   217,
       0,     0,   216,     7,     0,     0,   129,   449,     0,    91,
      91,    91,     0,     0,     0,     0,     0,    91,    91,    91,
      91,    91,     0,     0,     0,     0,     0,     0,     0,     0,
     211,     0,     0,   254,     0,   258,   259,     0,     0,     0,
       0,   265,     0,   205,   139,     0,   141,   142,   140,     0,
       0,     0,     0,     0,     0,   175,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   220,     0,     0,
       0,     0,     0,     0,     0,     0,   214,     0,     0,     0,
     115,     0,     0,     0,    92,    93,     0,    94,    95,     0,
       0,     0,    94,     0,     0,     0,     0,     0,    94,     0,
       0,     0,     0,     0,     0,    76,     0,     0,     0,     0,
       0,     0,     0,   358,   357,   356,   359,   360,   361,     0,
       7,     0,     0,     7,     0,     7,     0,     0,   144,     0,
     174,     0,   130,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   219,     0,     0,     0,     0,   227,
     233,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   213,   218,     0,   121,     0,     0,     0,     0,
       0,     0,     0,    48,     0,     0,    49,     0,     0,     0,
       0,     0,    50,    91,    91,    89,    90,    77,    78,    79,
      80,    81,     0,     0,     0,     0,     0,     0,     0,     7,
       0,   252,     0,     0,     0,     0,   204,   144,     0,   143,
       0,   174,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   233,   233,     0,     0,     0,   233,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   264,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    82,   379,   380,   381,
     421,   422,   423,     0,     7,     0,     7,     0,     0,     0,
       0,     0,   145,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   120,    47,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    51,    52,     0,   260,
       0,   262,     0,     7,     0,     0,     0,     0,     0,     0,
     132,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   233,   233,     0,     0,   233,   233,   233,     0,     0,
     232,   233,     0,     0,     0,     0,     0,     0,     0,   236,
     237,     0,     0,   235,     0,   250,     0,    57,    84,     0,
       0,     0,    69,    59,     0,     0,    70,     0,    56,    83,
       0,     0,     0,     0,     0,    68,     0,     0,     0,     0,
       0,     7,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   131,     0,     0,     0,     0,     0,     0,   178,
       0,     0,   180,     0,     0,   176,     0,   192,     0,     0,
     222,   229,     0,     0,     0,   221,   228,     0,   240,   241,
     239,     0,   251,     0,     0,     0,     0,     0,    54,    61,
      87,    88,     0,     0,    53,    60,     0,     0,    85,    86,
       0,     0,     0,   261,   263,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   186,     0,
     188,     0,   184,     0,     0,     0,   179,     0,     0,   181,
       0,     0,   177,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   238,    74,    75,    72,
      73,     0,    58,    71,     0,     0,     7,   133,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   187,   189,   185,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   182,   224,   226,   231,   223,   225,   230,   242,
       0,     0,     0,     0,     0,     0,     0,    55,     7,   134,
       0,     0,     0,     0,     0,     0,     0,   148,     0,     0,
     150,     0,     0,   146,     0,   162,     0,   190,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   183,
     246,     0,   243,   248,     0,   244,     0,     0,     0,     0,
     156,     0,   158,     0,   154,     0,     0,     0,   149,     0,
       0,   151,     0,     0,   147,     0,   191,     0,   198,     0,
       0,   199,     0,     0,   197,     0,     0,     0,     0,     0,
       0,     0,   135,   157,   159,   155,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   152,     0,
     194,     0,   195,     0,   193,     0,     0,   247,   249,   245,
     136,     0,   160,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   153,   202,   203,   201,   200,     0,
     161,     0,   168,     0,     0,   169,     0,     0,   167,     0,
       0,     0,   196,     0,   164,     0,   165,     0,   163,     0,
       0,   172,   173,   171,   170,     0,   166
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -811,  -811,  1380,  -408,   740,  -811,  -811,  -686,  -811,    87,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  -651,   316,  -811,  -810,  -811,  -811,  -811,
    -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  1160,  -566,
    -811,  -609,  -811,  -811,  -811,  -811,  -811,  -811,  -811,  -811,
    -811,  -811,  -811,  1354,  -811,  -811,  -811,   -10,  -811,  1400,
    1384,  1655,    94,   354,  -148,  -811,  1549,     3,  -811,  1403,
    -811,  4505
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,   421,   598,    59,    60,   850,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,   428,   434,   968,  1042,   744,   815,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,   619,   620,
      85,   614,   756,    86,   727,   793,   794,    87,    88,    89,
      90,    91,   419,   420,   596,    92,    93,   440,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   112,   241,   448,
     449,   441
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     231,   747,   451,  1187,   246,  1255,   589,   590,   591,   251,
    1190,   253,   254,   255,   599,   244,  1193,  1310,  1335,   248,
     429,   430,   431,   432,  1258,  1261,  1358,   256,  1338,  1341,
    1416,  1377,  1380,   262,   263,   264,   265,   882,   884,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,  1383,
    1443,   606,  1247,   762,  1249,  1251,  1188,   608,   271,   272,
    1346,  1369,  1371,  1191,   401,   402,  1373,  1431,     1,  1194,
    1311,  1336,   908,    -3,     6,   442,   460,     7,     8,     9,
     970,  1339,  1342,  1417,   854,   860,   805,   761,  1039,  1137,
    1138,   866,   867,   868,   869,   870,   618,     5,   243,  1040,
     245,   461,    94,   297,    10,    11,    12,    13,    14,    15,
    1102,    16,    17,   812,   753,  1275,   462,  1139,   273,   754,
    1043,  1040,   813,    18,    19,    20,   435,   436,   437,   813,
     289,    21,  1111,    95,   820,    22,    23,   273,    24,   754,
     463,   813,  1276,    25,   113,  1063,  1123,    26,    27,    28,
     754,   754,    29,   887,    30,   834,    31,    32,    33,    34,
     609,  1044,   247,    35,   618,   249,  1124,    36,   252,  1128,
      37,   754,  1264,  1265,   754,  1266,  1267,   754,   754,  1268,
     754,   754,   418,   594,   754,  1248,   610,  1250,  1252,  1189,
      38,  1256,   762,  1347,  1370,  1372,  1192,   883,   885,  1374,
    1432,   909,  1195,  1312,  1337,   443,   730,   731,  1269,   257,
    1259,  1262,  1359,   754,  1340,  1343,  1418,  1378,  1381,   387,
    1041,   452,   290,   291,   292,   293,   294,   295,    34,   258,
     438,   607,  1141,  1142,   804,  1384,  1444,   398,   276,   277,
     278,   755,  1041,   814,   274,   296,   399,   400,   399,   400,
     814,   259,   411,   579,   580,   581,   439,  1024,  1025,    38,
    1143,   755,   814,   405,   447,   450,   261,    39,    40,  1150,
    1151,    41,   755,   755,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,  1163,  1164,   260,    53,  1152,
     269,    54,   266,   755,   267,    55,   755,    56,    57,   755,
     755,   990,   755,   755,   268,  1165,   755,   829,   830,   831,
     832,   894,   895,   896,   897,   844,   845,   507,   508,   509,
     510,   852,   848,   270,   799,   800,   275,   802,   518,   912,
     913,   914,   915,   748,   749,   755,    39,    40,   299,   750,
      41,   615,   616,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,   300,   837,   642,   616,   548,   549,
     550,   551,  1105,  1106,  1107,  1108,   301,   242,   643,   616,
     842,   843,   644,   616,  1056,  1057,   565,   554,   555,  1061,
     302,   844,   845,   846,   645,   616,   563,   847,   848,   851,
     429,   430,   431,   432,   303,   583,   584,   833,   586,   844,
     845,   898,   304,   855,   856,   852,   848,   592,   593,   305,
     585,  1021,  1022,   306,   844,   845,   857,   646,   616,   916,
     858,   848,   844,   845,   816,   817,   307,   433,   852,   848,
     818,  1011,  1012,   308,   621,   392,   385,  1013,   647,   616,
     309,   849,   389,   393,   394,   395,   396,   397,   648,   616,
    1018,  1019,  1109,   310,    96,    97,  1020,   311,    98,   853,
     312,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,   960,   313,   859,   963,   314,   965,   429,   430,
     431,   432,  1023,   110,   315,   111,   570,   571,   572,   573,
     574,   575,   576,   784,   785,   786,   787,   788,   789,   953,
     954,   955,   956,   957,   958,   972,   973,   974,   975,   649,
     616,   316,  1198,  1199,   650,   616,  1202,  1203,  1204,   651,
     616,   317,  1207,   318,    -2,     6,   652,   616,     7,     8,
       9,  1173,  1174,  1175,  1176,   653,   616,   654,   616,   655,
     616,   656,   616,   657,   616,   658,   616,   659,   616,   660,
     616,  1033,   661,   616,   319,    10,    11,    12,    13,    14,
      15,   320,    16,    17,   662,   616,   663,   616,   664,   616,
     669,   616,   670,   616,    18,    19,    20,   671,   616,   672,
     616,   321,    21,   390,   673,   616,    22,    23,   322,    24,
     726,   391,   674,   616,    25,   675,   616,   323,    26,    27,
      28,   677,   616,    29,   324,    30,   757,    31,    32,    33,
      34,   325,   764,   403,    35,   767,   678,   616,    36,   679,
     616,    37,   680,   616,   681,   616,  1098,   326,  1100,   682,
     616,   683,   616,   684,   616,   685,   616,   686,   616,   687,
     616,    38,   688,   616,   689,   616,   690,   616,   691,   616,
     692,   616,   693,   616,   327,   783,   694,   616,   695,   616,
     696,   616,   697,   616,   698,   616,   699,   616,   700,   616,
     701,   616,   702,   616,   703,   616,   704,   616,   705,   616,
     713,   616,   714,   616,   715,   616,   716,   616,   717,   616,
     718,   616,   719,   616,   328,  1172,   721,   616,   759,   760,
     791,   792,   825,   826,   838,   839,   902,   903,  1301,  1302,
    1304,  1305,  1307,  1308,  1320,  1321,  1323,  1324,    39,    40,
     797,   798,    41,  1407,  1408,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,  1410,  1411,   329,    53,
    1413,  1414,    54,    58,    58,   330,    55,   331,    56,    57,
     835,   404,     6,   577,   578,     7,     8,     9,   332,   333,
     334,   335,   336,  1235,   337,   338,   339,   340,   341,   342,
     343,   344,   345,   346,   347,   348,   349,   350,   351,   352,
     353,   879,    10,    11,    12,    13,    14,    15,   354,    16,
      17,   355,   356,   357,   358,   359,   360,   361,   362,   363,
     364,   365,    19,    20,   366,   367,   368,   369,   370,    21,
    -253,  -253,  -253,    22,    23,   371,    24,   372,   373,     6,
     374,    25,     7,     8,     9,    26,    27,    28,   375,   926,
      29,   376,    30,   377,    31,    32,    33,    34,   378,   379,
     380,    35,   381,   382,   383,    36,   384,   386,    37,    10,
      11,    12,    13,    14,    15,   406,    16,    17,   407,   408,
     409,   410,   412,   413,   414,   415,   416,   418,    38,    19,
      20,   422,   962,   417,   964,   427,    21,   423,  1330,   424,
      22,    23,   425,    24,   426,   444,   445,   453,    25,  -268,
    -268,  -268,    26,    27,    28,   446,   454,    29,   552,    30,
     455,    31,    32,    33,    34,   456,   457,   458,    35,   459,
     464,   465,    36,   466,   467,    37,   468,   469,   470,  1006,
    1367,   471,   472,   641,  1010,   488,   473,   474,  1015,   475,
     625,   489,   582,   495,   496,    38,   497,   553,   567,   588,
     587,   600,   601,   617,   602,    39,    40,   603,   604,    41,
     605,   611,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,   612,   613,   622,    53,   618,   623,    54,
     624,   628,   626,    55,   629,    56,    57,   627,   630,   631,
     632,   633,   635,   734,   636,   637,   634,   638,   639,   640,
     737,   765,   738,   665,   751,  1077,   666,   667,  1080,   668,
     742,   676,   706,   707,  1086,   708,   709,  1089,   710,   711,
     712,   720,    39,    40,   722,   723,    41,   724,   725,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
     732,   733,   735,    53,   739,   740,    54,   741,   743,   752,
      55,     6,    56,    57,     7,     8,     9,   745,   746,   763,
     766,   768,   772,   774,   769,   770,   771,   775,   773,   776,
     881,   907,   777,   778,   861,   779,   780,   781,   790,   782,
     795,    10,    11,    12,    13,    14,    15,   796,    16,    17,
     801,   803,   806,   819,  1167,   807,   808,   811,   809,   810,
     828,    19,    20,   821,   822,   823,   824,   827,    21,  -255,
    -255,  -255,    22,    23,   836,    24,   840,   841,     6,   862,
      25,     7,     8,     9,    26,    27,    28,   863,   865,    29,
     864,    30,   871,    31,    32,    33,    34,   893,   872,   873,
      35,   874,   875,   876,    36,   877,   878,    37,    10,    11,
      12,    13,    14,    15,  1236,    16,    17,   880,   888,   889,
     890,   892,   891,   904,   910,   905,  1230,    38,    19,    20,
     899,   900,   901,   906,   911,    21,   917,   918,   922,    22,
      23,   919,    24,   920,   921,   923,   925,    25,   928,   929,
     927,    26,    27,    28,   930,   931,    29,   932,    30,   933,
      31,    32,    33,    34,   934,   935,   936,    35,  1237,   937,
     938,    36,   939,   940,    37,   941,   942,   943,   944,   945,
     946,   947,   948,   949,   950,   951,  1059,   959,   961,   952,
     966,   967,   969,   971,    38,   986,   976,   977,   978,   979,
     981,   980,   982,   987,    39,    40,   983,   984,    41,   985,
     988,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,   989,   997,   991,    53,   992,   993,    54,   994,
     995,   996,    55,   998,    56,    57,  1003,   999,  1000,  1001,
    1004,  1007,  1002,  1060,  1009,  1016,  1005,  1064,  1008,  1093,
    1014,  1026,  1017,  1038,  1053,  1027,  1028,  1029,  1030,  1031,
    1032,  1034,  1036,  1054,  1049,  1045,  1046,  1047,  1048,  1050,
    1051,    39,    40,  1052,  1055,    41,  1062,  1058,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,  1065,
    1066,  1067,    53,     6,  1068,    54,     7,     8,     9,    55,
    1069,    56,    57,  1070,  1071,  1072,  1350,  1073,  1074,  1075,
    1076,  1078,  1353,  1356,  1079,  1081,  1082,  1104,  1083,  1084,
    1085,  1087,  1088,    10,    11,    12,    13,    14,    15,  1284,
      16,    17,  1090,  1091,  1092,  1094,  1095,  1096,  1097,  1099,
    1101,  1103,  1110,    19,    20,  1112,  1113,  1114,  1115,  1116,
      21,     4,  1121,     0,    22,    23,  1117,    24,  1118,  1120,
       6,  1119,    25,     7,     8,     9,    26,    27,    28,  1122,
    1125,    29,  1144,    30,  1126,    31,    32,    33,    34,  1127,
    1130,  1129,    35,  1285,  1131,  1132,    36,  1135,  1133,    37,
      10,    11,    12,    13,    14,    15,  1134,    16,    17,  1136,
    1140,  1145,  1146,  1147,  1148,  1149,  1153,  1154,  1155,    38,
      19,    20,  1156,  1186,  1158,  1159,  1157,    21,  1161,  1160,
    1162,    22,    23,  1168,    24,  1171,  1166,  1182,  1196,    25,
    1177,  1178,  1179,    26,    27,    28,   597,  1180,    29,  1181,
      30,  1183,    31,    32,    33,    34,  1184,  1185,  1213,    35,
    1197,  1200,  1201,    36,  1205,  1206,    37,  1208,  1209,  1210,
    1211,  1212,  1214,  1242,  1215,  1243,  1216,  1218,  1217,  1219,
    1220,  1221,  1244,  1224,  1387,  1222,    38,  1223,  1225,  1226,
    1227,  1228,  1229,  1231,  1233,  1238,    39,    40,  1232,  1234,
      41,  1245,  1239,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,  1240,  1241,  1246,    53,  1253,  1254,
      54,  1257,  1277,  1271,    55,  1260,    56,    57,  1263,  1270,
    1272,  1273,  1278,  1274,  1279,  1390,  1393,  1280,  1288,  1282,
    1283,  1281,  1286,  1287,  1289,  1290,  1291,  1292,  1293,  1294,
    1396,  1297,  1426,  1298,  1295,  1296,  1299,  1300,  1322,  1303,
    1306,  1309,  1313,    39,    40,  1314,  1315,    41,  1316,  1317,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,  1318,  1319,  1325,    53,     6,  1326,    54,     7,     8,
       9,    55,  1327,    56,    57,  1328,  1329,  1331,  1344,  1435,
    1332,  1438,  1333,  1345,  1334,  1441,  1348,  1349,  1357,  1351,
    1352,  1360,  1354,  1355,  1361,    10,    11,    12,    13,    14,
      15,  1362,    16,    17,  1363,  1364,  1365,  1366,  1375,  1376,
    1451,  1379,  1454,  1386,  1382,    19,    20,  1385,  1388,  1389,
    1391,  1397,    21,  1394,  1392,  1395,    22,    23,   728,    24,
    1398,  1399,     6,  1400,    25,     7,     8,     9,    26,    27,
      28,  1402,  1403,    29,  1404,    30,  1405,    31,    32,    33,
      34,  1433,  1406,  1409,    35,  1412,  1415,  1420,    36,  1419,
    1422,    37,    10,    11,    12,    13,    14,    15,  1421,    16,
      17,  1423,  1424,  1425,  1427,  1428,  1429,  1430,  1457,  1445,
    1442,    38,    19,    20,  1434,  1460,  1436,  1437,  1440,    21,
    1439,  1446,  1447,    22,    23,   729,    24,  1448,  1449,  1453,
    1461,    25,  1450,  1452,  1455,    26,    27,    28,  1456,  1458,
      29,  1459,    30,  1462,    31,    32,    33,    34,  1463,  1464,
    1470,    35,  1466,  1465,  1467,    36,  1468,  1469,    37,  1471,
    1472,  1473,  1474,   595,  1476,   569,  1475,   758,   298,   388,
       0,     0,     0,     0,     0,     0,     0,     0,    38,   566,
     568,     0,     0,     0,     0,     0,     0,     0,    39,    40,
       0,     0,    41,     0,     0,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,     0,     0,     0,    53,
       0,     0,    54,     0,     0,     0,    55,     0,    56,    57,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    39,    40,     0,     0,    41,
       0,     0,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,     0,     0,     0,    53,     6,     0,    54,
       7,     8,     9,    55,     0,    56,    57,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,    12,
      13,    14,    15,     0,    16,    17,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    19,    20,     0,
       0,     0,     0,     0,    21,     0,     0,     0,    22,    23,
       0,    24,     0,     0,     6,     0,    25,     7,     8,     9,
      26,    27,    28,     0,     0,    29,   736,    30,     0,    31,
      32,    33,    34,     0,     0,     0,    35,     0,     0,     0,
      36,     0,     0,    37,    10,    11,    12,    13,    14,    15,
       0,    16,    17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,    19,    20,     0,     0,     0,     0,
       0,    21,     0,     0,     0,    22,    23,     0,    24,     0,
       0,     0,     0,    25,     0,     0,  -270,    26,    27,    28,
       0,     0,    29,     0,    30,     0,    31,    32,    33,    34,
       0,     0,     0,    35,     0,     0,     0,    36,     0,     0,
      37,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      38,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      39,    40,     0,     0,    41,     0,     0,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,     0,     0,
       0,    53,     0,     0,    54,     0,     0,     0,    55,     0,
      56,    57,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    39,    40,     0,
       0,    41,     0,     0,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,     0,     0,     0,    53,     6,
       0,    54,     7,     8,     9,    55,     0,    56,    57,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    10,
      11,    12,    13,    14,    15,     0,    16,    17,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    19,
      20,     0,     0,     0,     0,     0,    21,     0,     0,     0,
      22,    23,     0,    24,     0,     0,     6,     0,    25,     7,
       8,     9,    26,    27,    28,     0,   886,    29,     0,    30,
       0,    31,    32,    33,    34,     0,     0,     0,    35,     0,
       0,     0,    36,     0,     0,    37,    10,    11,    12,    13,
      14,    15,     0,    16,    17,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,    19,    20,     0,     0,
       0,     0,     0,    21,     0,     0,     0,    22,    23,     0,
      24,   924,     0,     0,     0,    25,     0,     0,     0,    26,
      27,    28,     0,     0,    29,     0,    30,     0,    31,    32,
      33,    34,     0,     0,     0,    35,     0,     0,     0,    36,
       0,     0,    37,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    38,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    39,    40,     0,     0,    41,     0,     0,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
       0,     0,     0,    53,     0,     0,    54,     0,     0,     0,
      55,     0,    56,    57,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    39,
      40,     0,     0,    41,     0,     0,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,     0,     0,     0,
      53,     6,     0,    54,     7,     8,     9,    55,     0,    56,
      57,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    11,    12,    13,    14,    15,     0,    16,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    19,    20,     0,     0,     0,     0,     0,    21,     0,
       0,  -257,    22,    23,     0,    24,     0,     0,     6,     0,
      25,     7,     8,     9,    26,    27,    28,     0,     0,    29,
       0,    30,     0,    31,    32,    33,    34,     0,     0,     0,
      35,     0,     0,     0,    36,     0,     0,    37,    10,    11,
      12,    13,    14,    15,     0,    16,    17,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    38,    19,    20,
       0,     0,     0,     0,     0,    21,     0,     0,     0,    22,
      23,     0,    24,  1035,     0,     0,     0,    25,     0,     0,
       0,    26,    27,    28,     0,     0,    29,     0,    30,     0,
      31,    32,    33,    34,     0,     0,     0,    35,     0,     0,
       0,    36,     0,     0,    37,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    38,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    39,    40,     0,     0,    41,     0,
       0,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,     0,     0,     0,    53,     0,     0,    54,     0,
       0,     0,    55,     0,    56,    57,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    39,    40,     0,     0,    41,     0,     0,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,     0,
       0,     0,    53,     6,     0,    54,     7,     8,     9,    55,
       0,    56,    57,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    10,    11,    12,    13,    14,    15,     0,
      16,    17,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    19,    20,     0,     0,     0,     0,     0,
      21,     0,     0,     0,    22,    23,     0,    24,  1037,     0,
       6,     0,    25,     7,     8,     9,    26,    27,    28,     0,
       0,    29,     0,    30,     0,    31,    32,    33,    34,     0,
       0,     0,    35,     0,     0,     0,    36,     0,     0,    37,
      10,    11,    12,    13,    14,    15,     0,    16,    17,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    38,
      19,    20,     0,     0,     0,     0,     0,    21,     0,     0,
       0,    22,    23,     0,    24,  1169,     0,     0,     0,    25,
       0,     0,     0,    26,    27,    28,     0,     0,    29,     0,
      30,     0,    31,    32,    33,    34,     0,     0,     0,    35,
       0,     0,     0,    36,     0,     0,    37,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    39,    40,     0,     0,
      41,     0,     0,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,     0,     0,     0,    53,     0,     0,
      54,     0,     0,     0,    55,     0,    56,    57,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    39,    40,     0,     0,    41,     0,     0,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,     0,     0,     0,    53,     6,     0,    54,     7,     8,
       9,    55,     0,    56,    57,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    10,    11,    12,    13,    14,
      15,     0,    16,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    19,    20,     0,     0,     0,
       0,     0,    21,     0,     0,     0,    22,    23,     0,    24,
    1170,     0,     6,     0,    25,     7,     8,     9,    26,    27,
      28,     0,     0,    29,     0,    30,     0,    31,    32,    33,
      34,     0,     0,     0,    35,     0,     0,     0,    36,     0,
       0,    37,    10,    11,    12,    13,    14,    15,     0,    16,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    38,    19,    20,     0,     0,     0,     0,     0,    21,
       0,     0,     0,    22,    23,     0,    24,     0,     0,     0,
       0,    25,     0,     0,     0,    26,    27,    28,     0,     0,
      29,     0,    30,     0,    31,    32,    33,    34,     0,     0,
       0,    35,  1368,     0,     0,    36,     0,     0,    37,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    38,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    39,    40,
       0,     0,    41,     0,     0,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,     0,     0,     0,    53,
       0,     0,    54,     0,     0,     0,    55,     0,    56,    57,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    39,    40,     0,     0,    41,
       0,     0,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,     0,     0,     0,    53,     6,     0,    54,
       7,     8,     9,    55,     0,    56,    57,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    11,    12,
      13,    14,    15,     0,    16,    17,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    19,    20,     0,
       0,     0,     0,     0,    21,     0,     0,     0,    22,    23,
       0,    24,     0,     0,     0,     0,    25,     0,     0,     0,
      26,    27,    28,     0,     0,    29,     0,    30,     0,    31,
      32,    33,    34,     0,     0,     0,    35,  1401,     0,     0,
      36,     0,     0,    37,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    38,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   114,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   115,     0,     0,     0,     0,     0,     0,     0,   116,
     117,   118,   119,   120,     0,     0,     0,     0,     0,     0,
      39,    40,     0,     0,    41,     0,     0,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,   121,     0,
       0,    53,   122,     0,    54,   123,     0,     0,    55,     0,
      56,    57,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   193,   194,   195,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,     0,   210,
     211,   212,     0,     0,   213,     0,     0,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   114,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   225,   226,   227,   228,   250,     0,   229,     0,     0,
       0,   230,   115,     0,     0,     0,     0,     0,     0,     0,
     116,   117,   118,   119,   120,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   121,
       0,     0,     0,   122,     0,     0,   123,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   172,   173,   174,   175,   176,   177,   178,   179,   180,
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,     0,
     210,   211,   212,     0,     0,   213,     0,     0,   214,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   114,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   225,   226,   227,   228,     0,     0,   229,   501,
       0,     0,   230,   115,     0,     0,     0,     0,     0,     0,
       0,   116,   117,   118,   119,   120,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     121,     0,     0,     0,   122,     0,     0,   123,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   171,   172,   173,   174,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,   192,   193,   194,   195,   196,   197,   198,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
       0,   210,   211,   212,     0,     0,   213,     0,     0,   214,
     215,   216,   217,   218,   219,   220,   221,   222,   223,   224,
     114,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   225,   226,   227,   228,     0,     0,   229,
     503,     0,     0,   230,   115,     0,     0,     0,     0,     0,
       0,     0,   116,   117,   118,   119,   120,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   121,     0,     0,     0,   122,     0,     0,   123,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   176,   177,   178,
     179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
     199,   200,   201,   202,   203,   204,   205,   206,   207,   208,
     209,     0,   210,   211,   212,     0,     0,   213,     0,     0,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   114,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   225,   226,   227,   228,     0,     0,
     229,   505,     0,     0,   230,   115,     0,     0,     0,     0,
       0,     0,     0,   116,   117,   118,   119,   120,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   121,     0,     0,     0,   122,     0,     0,   123,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   124,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   135,   136,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   171,   172,   173,   174,   175,   176,   177,
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,   195,   196,   197,
     198,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,     0,   210,   211,   212,     0,     0,   213,     0,
       0,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   114,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   225,   226,   227,   228,     0,
       0,   229,     0,     0,     0,   230,   115,     0,     0,     0,
       0,     0,     0,     0,   116,   117,   118,   119,   120,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   121,     0,     0,     0,   122,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,   154,   155,   156,
     157,   158,   159,   160,   161,   162,   163,   164,   165,   166,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   176,
     177,   178,   179,   180,   181,   182,   183,   184,   185,   186,
     187,   188,   189,   190,   191,   192,   193,   194,   195,   196,
     197,   198,   199,   200,   201,   202,   203,   204,   205,   206,
     207,   208,   209,     0,   210,   211,   212,     0,     0,   213,
       0,     0,   214,   215,   216,   217,   218,   219,   220,   221,
     222,   223,   224,   114,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   225,   226,   227,   228,
       0,     0,   229,     0,     0,     0,   230,   115,     0,     0,
       0,     0,     0,     0,     0,   116,   117,   118,   119,   120,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   121,     0,     0,     0,   122,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   124,   125,
     126,   127,   128,   129,   130,   131,   132,   133,   134,   135,
     136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   195,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,     0,   210,   211,   212,     0,     0,
     213,     0,     0,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   225,   226,   227,
     228,     0,     0,   229,   476,   477,   478,   479,   480,   481,
     482,   483,   484,   485,   486,   487,     0,     0,   490,   491,
     492,   493,   494,     0,     0,     0,   498,   499,   500,   502,
     504,   506,     0,     0,     0,     0,   511,   512,   513,   514,
     515,   516,   517,     0,   519,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   531,   532,   533,   534,
     535,   536,   537,   538,   539,   540,   541,   542,   543,   544,
     545,   546,   547,     0,     0,     0,     0,     0,     0,     0,
       0,   556,   557,   558,   559,   560,   561,   562,     0,   564
};

static const yytype_int16 yycheck[] =
{
      10,   610,    10,    43,    14,    43,   414,   415,   416,    19,
      43,    21,    22,    23,   422,    12,    43,    43,    43,    16,
      11,    12,    13,    14,    43,    43,    43,    24,    43,    43,
      43,    43,    43,    30,    31,    32,    33,    69,    69,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    43,
      43,    49,    96,   619,    96,    96,    96,   100,    55,    56,
      96,    96,    96,    96,   236,   237,    96,    96,     3,    96,
      96,    96,   100,     0,     1,    99,   204,     4,     5,     6,
     890,    96,    96,    96,   770,   771,   737,   216,    93,   201,
     202,   777,   778,   779,   780,   781,   225,     0,    11,   104,
      13,   229,   229,   113,    31,    32,    33,    34,    35,    36,
      93,    38,    39,    95,    98,   202,   205,   229,   105,   103,
      95,   104,   104,    50,    51,    52,    99,   100,   101,   104,
     102,    58,    95,   225,    98,    62,    63,   105,    65,   103,
     229,   104,   229,    70,   225,    98,    98,    74,    75,    76,
     103,   103,    79,   804,    81,   216,    83,    84,    85,    86,
     203,   971,   229,    90,   225,   231,    98,    94,   230,    98,
      97,   103,    98,    98,   103,    98,    98,   103,   103,    98,
     103,   103,    71,    72,   103,   229,   229,   229,   229,   229,
     117,   229,   758,   229,   229,   229,   229,   229,   229,   229,
     229,   229,   229,   229,   229,   229,    67,    68,    98,   229,
     229,   229,   229,   103,   229,   229,   229,   229,   229,   229,
     225,   229,   194,   195,   196,   197,   198,   199,    86,   229,
     203,   229,   201,   202,   225,   229,   229,   223,     7,     8,
       9,   225,   225,   225,   231,   217,   234,   235,   234,   235,
     225,   229,   249,   401,   402,   403,   229,   943,   944,   117,
     229,   225,   225,   231,   274,   275,   225,   194,   195,   209,
     210,   198,   225,   225,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   209,   210,   229,   215,   229,
     231,   218,   225,   225,   225,   222,   225,   224,   225,   225,
     225,   910,   225,   225,   225,   229,   225,    11,    12,    13,
      14,    11,    12,    13,    14,    40,    41,   327,   328,   329,
     330,    46,    47,   225,   732,   733,   230,   735,   338,    11,
      12,    13,    14,   220,   221,   225,   194,   195,   231,   226,
     198,   232,   233,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   231,   763,   232,   233,   368,   369,
     370,   371,    11,    12,    13,    14,   231,   225,   232,   233,
      29,    30,   232,   233,   983,   984,   386,   374,   375,   988,
     231,    40,    41,    42,   232,   233,   383,    46,    47,    30,
      11,    12,    13,    14,   231,   405,   406,   101,   408,    40,
      41,   101,   231,    29,    30,    46,    47,   417,   418,   231,
     407,    29,    30,   231,    40,    41,    42,   232,   233,   101,
      46,    47,    40,    41,   220,   221,   231,    48,    46,    47,
     226,   220,   221,   231,   444,   230,   228,   226,   232,   233,
     231,   100,   229,   238,   239,   240,   241,   242,   232,   233,
     220,   221,   101,   231,   194,   195,   226,   231,   198,   100,
     231,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   880,   231,   100,   883,   231,   885,    11,    12,
      13,    14,   100,   223,   231,   225,   392,   393,   394,   395,
     396,   397,   398,    22,    23,    24,    25,    26,    27,    22,
      23,    24,    25,    26,    27,    11,    12,    13,    14,   232,
     233,   231,  1121,  1122,   232,   233,  1125,  1126,  1127,   232,
     233,   231,  1131,   231,     0,     1,   232,   233,     4,     5,
       6,    11,    12,    13,    14,   232,   233,   232,   233,   232,
     233,   232,   233,   232,   233,   232,   233,   232,   233,   232,
     233,   959,   232,   233,   231,    31,    32,    33,    34,    35,
      36,   231,    38,    39,   232,   233,   232,   233,   232,   233,
     232,   233,   232,   233,    50,    51,    52,   232,   233,   232,
     233,   231,    58,    88,   232,   233,    62,    63,   231,    65,
     587,    87,   232,   233,    70,   232,   233,   231,    74,    75,
      76,   232,   233,    79,   231,    81,   616,    83,    84,    85,
      86,   231,   622,   219,    90,   625,   232,   233,    94,   232,
     233,    97,   232,   233,   232,   233,  1034,   231,  1036,   232,
     233,   232,   233,   232,   233,   232,   233,   232,   233,   232,
     233,   117,   232,   233,   232,   233,   232,   233,   232,   233,
     232,   233,   232,   233,   231,   665,   232,   233,   232,   233,
     232,   233,   232,   233,   232,   233,   232,   233,   232,   233,
     232,   233,   232,   233,   232,   233,   232,   233,   232,   233,
     232,   233,   232,   233,   232,   233,   232,   233,   232,   233,
     232,   233,   232,   233,   231,  1103,   232,   233,   229,   230,
      59,    60,   232,   233,   232,   233,   232,   233,    44,    45,
      44,    45,    44,    45,   232,   233,   232,   233,   194,   195,
     730,   731,   198,    44,    45,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,    44,    45,   231,   215,
      44,    45,   218,     3,     4,   231,   222,   231,   224,   225,
     760,   105,     1,   399,   400,     4,     5,     6,   231,   231,
     231,   231,   231,  1171,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   791,    31,    32,    33,    34,    35,    36,   231,    38,
      39,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,    51,    52,   231,   231,   231,   231,   231,    58,
      59,    60,    61,    62,    63,   231,    65,   231,   231,     1,
     231,    70,     4,     5,     6,    74,    75,    76,   231,   839,
      79,   231,    81,   231,    83,    84,    85,    86,   231,   231,
     231,    90,   231,   231,   231,    94,   231,   231,    97,    31,
      32,    33,    34,    35,    36,   230,    38,    39,   230,   230,
     229,   229,   229,    53,   229,   229,   229,    71,   117,    51,
      52,   229,   882,   230,   884,    46,    58,   229,  1286,   229,
      62,    63,   229,    65,   229,   223,   192,   229,    70,    71,
      72,    73,    74,    75,    76,   225,   229,    79,   225,    81,
     231,    83,    84,    85,    86,   231,   231,   231,    90,   231,
     229,   229,    94,   229,   231,    97,   231,   231,   231,   929,
    1328,   231,   231,   200,   934,   232,   231,   229,   938,   229,
     233,   232,   225,   232,   232,   117,   232,   232,   232,   229,
     232,   229,   231,   229,   231,   194,   195,   231,   231,   198,
     231,   231,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   231,   231,   231,   215,   225,   232,   218,
     232,   226,   229,   222,   226,   224,   225,   231,   226,   226,
     226,   231,   225,    73,   226,   226,   231,   226,   226,   226,
      92,   105,   226,   233,   225,  1005,   232,   232,  1008,   232,
     228,   233,   232,   232,  1014,   232,   232,  1017,   232,   232,
     232,   232,   194,   195,   232,   229,   198,   229,   229,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     229,   229,   229,   215,   226,   226,   218,   226,   231,   225,
     222,     1,   224,   225,     4,     5,     6,   231,   231,   229,
     229,   236,   233,   225,   232,   232,   232,   225,   233,   232,
      61,    99,   232,   232,   226,   232,   232,   232,   229,   233,
     229,    31,    32,    33,    34,    35,    36,   229,    38,    39,
     229,   229,   232,   225,  1094,   232,   232,   228,   233,   232,
     225,    51,    52,   233,   233,   232,   232,   229,    58,    59,
      60,    61,    62,    63,   229,    65,   225,   233,     1,   226,
      70,     4,     5,     6,    74,    75,    76,   232,   229,    79,
     232,    81,   228,    83,    84,    85,    86,   225,   233,   232,
      90,   232,   232,   232,    94,   232,   232,    97,    31,    32,
      33,    34,    35,    36,    37,    38,    39,   229,   229,   226,
     229,   229,   232,   229,   229,   226,  1166,   117,    51,    52,
     233,   233,   232,   226,   226,    58,   231,   231,   229,    62,
      63,   231,    65,   231,   231,   229,   229,    70,    30,   231,
     236,    74,    75,    76,   231,    30,    79,   231,    81,   229,
      83,    84,    85,    86,   231,   231,   229,    90,    91,    30,
     231,    94,   231,    30,    97,   231,   229,   232,   232,   229,
     229,   229,   229,   229,   229,   229,    99,   229,   229,   232,
     229,   229,   232,   229,   117,   232,   231,   231,   231,   231,
     226,   231,   226,   232,   194,   195,   229,   229,   198,   226,
     229,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   231,   226,   232,   215,   231,   231,   218,   231,
     231,   231,   222,   226,   224,   225,   232,   226,   226,   225,
     232,   225,   229,    99,   226,   225,   231,    99,   231,    30,
     231,   229,   231,   967,   225,   232,   232,   232,   232,   232,
     232,   229,   229,   232,   226,   231,   231,   231,   231,   226,
     226,   194,   195,   226,   232,   198,   226,   232,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   226,
     226,   226,   215,     1,   226,   218,     4,     5,     6,   222,
     225,   224,   225,   232,   232,   232,    44,   233,   232,   229,
     229,   232,    44,    44,   232,   232,   232,   225,   233,   233,
     232,   232,   232,    31,    32,    33,    34,    35,    36,    37,
      38,    39,   233,   233,   232,   231,   231,   229,   229,   229,
     229,   229,   229,    51,    52,   226,   226,   226,   226,   232,
      58,     1,   229,    -1,    62,    63,   232,    65,   232,   232,
       1,   233,    70,     4,     5,     6,    74,    75,    76,   229,
     229,    79,   226,    81,   229,    83,    84,    85,    86,   229,
     229,   232,    90,    91,   229,   232,    94,   233,   232,    97,
      31,    32,    33,    34,    35,    36,   232,    38,    39,   232,
     229,   229,   232,   229,   229,   232,   229,   226,   226,   117,
      51,    52,   229,   233,   229,   229,   232,    58,   226,   232,
     226,    62,    63,   226,    65,   229,   231,   229,   226,    70,
     231,   231,   231,    74,    75,    76,    77,   231,    79,   231,
      81,   232,    83,    84,    85,    86,   232,   232,   231,    90,
     229,   229,   229,    94,   229,   229,    97,   229,   229,   229,
     226,   229,   231,   226,   231,   226,   231,   229,   232,   229,
     229,   229,   226,   229,    45,   232,   117,   232,   229,   232,
     232,   229,   229,   232,   229,   231,   194,   195,   232,   229,
     198,   226,   231,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,   231,   231,   225,   215,   226,   231,
     218,   231,   229,   225,   222,   231,   224,   225,   232,   232,
     226,   225,   229,   226,   229,    45,    45,   229,   226,   229,
     229,   232,   229,   229,   226,   226,   226,   232,   232,   232,
      45,   229,    44,   229,   233,   232,   229,   232,   232,   231,
     231,   231,   229,   194,   195,   229,   229,   198,   229,   229,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   229,   229,   232,   215,     1,   231,   218,     4,     5,
       6,   222,   229,   224,   225,   229,   229,   232,   226,    44,
     232,    44,   232,   229,   233,    44,   233,   232,   231,   233,
     232,   229,   233,   232,   226,    31,    32,    33,    34,    35,
      36,   229,    38,    39,   229,   226,   229,   226,   226,   231,
      45,   231,    45,   229,   231,    51,    52,   232,   229,   232,
     229,   231,    58,   229,   232,   232,    62,    63,    64,    65,
     232,   232,     1,   232,    70,     4,     5,     6,    74,    75,
      76,   229,   229,    79,   229,    81,   229,    83,    84,    85,
      86,   233,   232,   231,    90,   231,   231,   229,    94,   232,
     229,    97,    31,    32,    33,    34,    35,    36,   232,    38,
      39,   232,   229,   232,   229,   229,   229,   229,    45,   229,
     231,   117,    51,    52,   232,    45,   233,   232,   232,    58,
     233,   229,   229,    62,    63,    64,    65,   229,   232,   232,
     231,    70,   229,   229,   229,    74,    75,    76,   232,   229,
      79,   232,    81,   229,    83,    84,    85,    86,   232,   229,
      44,    90,   229,   232,   232,    94,   229,   232,    97,   229,
     229,   229,   229,   419,   229,   391,   232,   617,   123,   230,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,   386,
     390,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,   195,
      -1,    -1,   198,    -1,    -1,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,    -1,    -1,    -1,   215,
      -1,    -1,   218,    -1,    -1,    -1,   222,    -1,   224,   225,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   194,   195,    -1,    -1,   198,
      -1,    -1,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,    -1,    -1,    -1,   215,     1,    -1,   218,
       4,     5,     6,   222,    -1,   224,   225,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,    -1,    38,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    -1,
      -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,    62,    63,
      -1,    65,    -1,    -1,     1,    -1,    70,     4,     5,     6,
      74,    75,    76,    -1,    -1,    79,    80,    81,    -1,    83,
      84,    85,    86,    -1,    -1,    -1,    90,    -1,    -1,    -1,
      94,    -1,    -1,    97,    31,    32,    33,    34,    35,    36,
      -1,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   117,    51,    52,    -1,    -1,    -1,    -1,
      -1,    58,    -1,    -1,    -1,    62,    63,    -1,    65,    -1,
      -1,    -1,    -1,    70,    -1,    -1,    73,    74,    75,    76,
      -1,    -1,    79,    -1,    81,    -1,    83,    84,    85,    86,
      -1,    -1,    -1,    90,    -1,    -1,    -1,    94,    -1,    -1,
      97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     194,   195,    -1,    -1,   198,    -1,    -1,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,    -1,    -1,
      -1,   215,    -1,    -1,   218,    -1,    -1,    -1,   222,    -1,
     224,   225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,   195,    -1,
      -1,   198,    -1,    -1,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,    -1,    -1,    -1,   215,     1,
      -1,   218,     4,     5,     6,   222,    -1,   224,   225,    -1,
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
      -1,    -1,    -1,    -1,    -1,   117,    51,    52,    -1,    -1,
      -1,    -1,    -1,    58,    -1,    -1,    -1,    62,    63,    -1,
      65,    66,    -1,    -1,    -1,    70,    -1,    -1,    -1,    74,
      75,    76,    -1,    -1,    79,    -1,    81,    -1,    83,    84,
      85,    86,    -1,    -1,    -1,    90,    -1,    -1,    -1,    94,
      -1,    -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   194,   195,    -1,    -1,   198,    -1,    -1,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
      -1,    -1,    -1,   215,    -1,    -1,   218,    -1,    -1,    -1,
     222,    -1,   224,   225,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,
     195,    -1,    -1,   198,    -1,    -1,   201,   202,   203,   204,
     205,   206,   207,   208,   209,   210,   211,    -1,    -1,    -1,
     215,     1,    -1,   218,     4,     5,     6,   222,    -1,   224,
     225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    31,    32,    33,    34,    35,    36,    -1,    38,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    52,    -1,    -1,    -1,    -1,    -1,    58,    -1,
      -1,    61,    62,    63,    -1,    65,    -1,    -1,     1,    -1,
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
      -1,    -1,    -1,    -1,   194,   195,    -1,    -1,   198,    -1,
      -1,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,    -1,    -1,    -1,   215,    -1,    -1,   218,    -1,
      -1,    -1,   222,    -1,   224,   225,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   194,   195,    -1,    -1,   198,    -1,    -1,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,    -1,
      -1,    -1,   215,     1,    -1,   218,     4,     5,     6,   222,
      -1,   224,   225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    -1,
      38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    51,    52,    -1,    -1,    -1,    -1,    -1,
      58,    -1,    -1,    -1,    62,    63,    -1,    65,    66,    -1,
       1,    -1,    70,     4,     5,     6,    74,    75,    76,    -1,
      -1,    79,    -1,    81,    -1,    83,    84,    85,    86,    -1,
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
     198,    -1,    -1,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,    -1,    -1,    -1,   215,    -1,    -1,
     218,    -1,    -1,    -1,   222,    -1,   224,   225,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   194,   195,    -1,    -1,   198,    -1,    -1,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,    -1,    -1,    -1,   215,     1,    -1,   218,     4,     5,
       6,   222,    -1,   224,   225,    -1,    -1,    -1,    -1,    -1,
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
      -1,   117,    51,    52,    -1,    -1,    -1,    -1,    -1,    58,
      -1,    -1,    -1,    62,    63,    -1,    65,    -1,    -1,    -1,
      -1,    70,    -1,    -1,    -1,    74,    75,    76,    -1,    -1,
      79,    -1,    81,    -1,    83,    84,    85,    86,    -1,    -1,
      -1,    90,    91,    -1,    -1,    94,    -1,    -1,    97,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   117,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   194,   195,
      -1,    -1,   198,    -1,    -1,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,    -1,    -1,    -1,   215,
      -1,    -1,   218,    -1,    -1,    -1,   222,    -1,   224,   225,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   194,   195,    -1,    -1,   198,
      -1,    -1,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,    -1,    -1,    -1,   215,     1,    -1,   218,
       4,     5,     6,   222,    -1,   224,   225,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,    -1,    38,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    52,    -1,
      -1,    -1,    -1,    -1,    58,    -1,    -1,    -1,    62,    63,
      -1,    65,    -1,    -1,    -1,    -1,    70,    -1,    -1,    -1,
      74,    75,    76,    -1,    -1,    79,    -1,    81,    -1,    83,
      84,    85,    86,    -1,    -1,    -1,    90,    91,    -1,    -1,
      94,    -1,    -1,    97,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   117,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      54,    55,    56,    57,    -1,    -1,    -1,    -1,    -1,    -1,
     194,   195,    -1,    -1,   198,    -1,    -1,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,    82,    -1,
      -1,   215,    86,    -1,   218,    89,    -1,    -1,   222,    -1,
     224,   225,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,   187,   188,   189,   190,   191,    -1,   193,
     194,   195,    -1,    -1,   198,    -1,    -1,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   210,   211,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   225,   226,   227,   228,   229,    -1,   231,    -1,    -1,
      -1,   235,    45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
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
     173,   174,   175,   176,   177,   178,   179,   180,   181,   182,
     183,   184,   185,   186,   187,   188,   189,   190,   191,    -1,
     193,   194,   195,    -1,    -1,   198,    -1,    -1,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,    21,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   225,   226,   227,   228,    -1,    -1,   231,   232,
      -1,    -1,   235,    45,    -1,    -1,    -1,    -1,    -1,    -1,
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
      -1,   193,   194,   195,    -1,    -1,   198,    -1,    -1,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   225,   226,   227,   228,    -1,    -1,   231,
     232,    -1,    -1,   235,    45,    -1,    -1,    -1,    -1,    -1,
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
     181,   182,   183,   184,   185,   186,   187,   188,   189,   190,
     191,    -1,   193,   194,   195,    -1,    -1,   198,    -1,    -1,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   225,   226,   227,   228,    -1,    -1,
     231,   232,    -1,    -1,   235,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    54,    55,    56,    57,    -1,    -1,
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
     180,   181,   182,   183,   184,   185,   186,   187,   188,   189,
     190,   191,    -1,   193,   194,   195,    -1,    -1,   198,    -1,
      -1,   201,   202,   203,   204,   205,   206,   207,   208,   209,
     210,   211,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,    -1,
      -1,   231,    -1,    -1,    -1,   235,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    53,    54,    55,    56,    57,    -1,
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
      -1,    -1,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,   228,
      -1,    -1,   231,    -1,    -1,    -1,   235,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    53,    54,    55,    56,    57,
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
     178,   179,   180,   181,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,    -1,   193,   194,   195,    -1,    -1,
     198,    -1,    -1,   201,   202,   203,   204,   205,   206,   207,
     208,   209,   210,   211,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   225,   226,   227,
     228,    -1,    -1,   231,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,    -1,    -1,   313,   314,
     315,   316,   317,    -1,    -1,    -1,   321,   322,   323,   324,
     325,   326,    -1,    -1,    -1,    -1,   331,   332,   333,   334,
     335,   336,   337,    -1,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   376,   377,   378,   379,   380,   381,   382,    -1,   384
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int16 yystos[] =
{
       0,     3,   244,   245,   245,     0,     1,     4,     5,     6,
      31,    32,    33,    34,    35,    36,    38,    39,    50,    51,
      52,    58,    62,    63,    65,    70,    74,    75,    76,    79,
      81,    83,    84,    85,    86,    90,    94,    97,   117,   194,
     195,   198,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,   215,   218,   222,   224,   225,   247,   248,
     249,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     260,   261,   262,   263,   264,   271,   272,   273,   274,   275,
     276,   277,   278,   279,   280,   283,   286,   290,   291,   292,
     293,   294,   298,   299,   229,   225,   194,   195,   198,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     223,   225,   310,   225,    21,    45,    53,    54,    55,    56,
      57,    82,    86,    89,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     193,   194,   195,   198,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   225,   226,   227,   228,   231,
     235,   300,   301,   302,   303,   304,   305,   306,   307,   308,
     309,   311,   225,   252,   310,   252,   300,   229,   310,   231,
     229,   300,   230,   300,   300,   300,   310,   229,   229,   229,
     229,   225,   310,   310,   310,   310,   225,   225,   225,   231,
     225,   310,   310,   105,   231,   230,     7,     8,     9,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,   102,
     194,   195,   196,   197,   198,   199,   217,   300,   304,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   231,   231,   231,   231,   231,
     231,   231,   231,   231,   231,   228,   231,   300,   309,   229,
      88,    87,   230,   238,   239,   240,   241,   242,   223,   234,
     235,   236,   237,   219,   105,   231,   230,   230,   230,   229,
     229,   310,   229,    53,   229,   229,   229,   230,    71,   295,
     296,   246,   229,   229,   229,   229,   229,    46,   265,    11,
      12,    13,    14,    48,   266,    99,   100,   101,   203,   229,
     300,   314,    99,   229,   223,   192,   225,   300,   312,   313,
     300,    10,   229,   229,   229,   231,   231,   231,   231,   231,
     204,   229,   205,   229,   229,   229,   229,   231,   231,   231,
     231,   231,   231,   231,   229,   229,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   232,   232,
     314,   314,   314,   314,   314,   232,   232,   232,   314,   314,
     314,   232,   314,   232,   314,   232,   314,   300,   300,   300,
     300,   314,   314,   314,   314,   314,   314,   314,   300,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   314,   314,
     314,   314,   314,   314,   314,   314,   314,   314,   300,   300,
     300,   300,   225,   232,   310,   310,   314,   314,   314,   314,
     314,   314,   314,   310,   314,   300,   312,   232,   302,   303,
     305,   305,   305,   305,   305,   305,   305,   306,   306,   307,
     307,   307,   225,   300,   300,   310,   300,   232,   229,   246,
     246,   246,   300,   300,    72,   296,   297,    77,   247,   246,
     229,   231,   231,   231,   231,   231,    49,   229,   100,   203,
     229,   231,   231,   231,   284,   232,   233,   229,   225,   281,
     282,   300,   231,   232,   232,   233,   229,   231,   226,   226,
     226,   226,   226,   231,   231,   225,   226,   226,   226,   226,
     226,   200,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   233,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   233,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   232,   232,   232,   232,   232,   232,   232,
     232,   232,   232,   229,   229,   229,   310,   287,    64,    64,
      67,    68,   229,   229,    73,   229,    80,    92,   226,   226,
     226,   226,   228,   231,   269,   231,   231,   284,   220,   221,
     226,   225,   225,    98,   103,   225,   285,   300,   281,   229,
     230,   216,   282,   229,   300,   105,   229,   300,   236,   232,
     232,   232,   233,   233,   225,   225,   232,   232,   232,   232,
     232,   232,   233,   300,    22,    23,    24,    25,    26,    27,
     229,    59,    60,   288,   289,   229,   229,   300,   300,   246,
     246,   229,   246,   229,   225,   266,   232,   232,   232,   233,
     232,   228,    95,   104,   225,   270,   220,   221,   226,   225,
      98,   233,   233,   232,   232,   232,   233,   229,   225,    11,
      12,    13,    14,   101,   216,   300,   229,   246,   232,   233,
     225,   233,    29,    30,    40,    41,    42,    46,    47,   100,
     250,    30,    46,   100,   250,    29,    30,    42,    46,   100,
     250,   226,   226,   232,   232,   229,   250,   250,   250,   250,
     250,   228,   233,   232,   232,   232,   232,   232,   232,   300,
     229,    61,    69,   229,    69,   229,    78,   266,   229,   226,
     229,   232,   229,   225,    11,    12,    13,    14,   101,   233,
     233,   232,   232,   233,   229,   226,   226,    99,   100,   229,
     229,   226,    11,    12,    13,    14,   101,   231,   231,   231,
     231,   231,   229,   229,    66,   229,   300,   236,    30,   231,
     231,    30,   231,   229,   231,   231,   229,    30,   231,   231,
      30,   231,   229,   232,   232,   229,   229,   229,   229,   229,
     229,   229,   232,    22,    23,    24,    25,    26,    27,   229,
     246,   229,   300,   246,   300,   246,   229,   229,   267,   232,
     269,   229,    11,    12,    13,    14,   231,   231,   231,   231,
     231,   226,   226,   229,   229,   226,   232,   232,   229,   231,
     284,   232,   231,   231,   231,   231,   231,   226,   226,   226,
     226,   225,   229,   232,   232,   231,   300,   225,   231,   226,
     300,   220,   221,   226,   231,   300,   225,   231,   220,   221,
     226,    29,    30,   100,   250,   250,   229,   232,   232,   232,
     232,   232,   232,   246,   229,    66,   229,    66,   267,    93,
     104,   225,   268,    95,   269,   231,   231,   231,   231,   226,
     226,   226,   226,   225,   232,   232,   284,   284,   232,    99,
      99,   284,   226,    98,    99,   226,   226,   226,   226,   225,
     232,   232,   232,   233,   232,   229,   229,   300,   232,   232,
     300,   232,   232,   233,   233,   232,   300,   232,   232,   300,
     233,   233,   232,    30,   231,   231,   229,   229,   246,   229,
     246,   229,    93,   229,   225,    11,    12,    13,    14,   101,
     229,    95,   226,   226,   226,   226,   232,   232,   232,   233,
     232,   229,   229,    98,    98,   229,   229,   229,    98,   232,
     229,   229,   232,   232,   232,   233,   232,   201,   202,   229,
     229,   201,   202,   229,   226,   229,   232,   229,   229,   232,
     209,   210,   229,   229,   226,   226,   229,   232,   229,   229,
     232,   226,   226,   209,   210,   229,   231,   300,   226,    66,
      66,   229,   246,    11,    12,    13,    14,   231,   231,   231,
     231,   231,   229,   232,   232,   232,   233,    43,    96,   229,
      43,    96,   229,    43,    96,   229,   226,   229,   284,   284,
     229,   229,   284,   284,   284,   229,   229,   284,   229,   229,
     229,   226,   229,   231,   231,   231,   231,   232,   229,   229,
     229,   229,   232,   232,   229,   229,   232,   232,   229,   229,
     300,   232,   232,   229,   229,   246,    37,    91,   231,   231,
     231,   231,   226,   226,   226,   226,   225,    96,   229,    96,
     229,    96,   229,   226,   231,    43,   229,   231,    43,   229,
     231,    43,   229,   232,    98,    98,    98,    98,    98,    98,
     232,   225,   226,   225,   226,   202,   229,   229,   229,   229,
     229,   232,   229,   229,    37,    91,   229,   229,   226,   226,
     226,   226,   232,   232,   232,   233,   232,   229,   229,   229,
     232,    44,    45,   231,    44,    45,   231,    44,    45,   231,
      43,    96,   229,   229,   229,   229,   229,   229,   229,   229,
     232,   233,   232,   232,   233,   232,   231,   229,   229,   229,
     246,   232,   232,   232,   233,    43,    96,   229,    43,    96,
     229,    43,    96,   229,   226,   229,    96,   229,   233,   232,
      44,   233,   232,    44,   233,   232,    44,   231,    43,   229,
     229,   226,   229,   229,   226,   229,   226,   246,    91,    96,
     229,    96,   229,    96,   229,   226,   231,    43,   229,   231,
      43,   229,   231,    43,   229,   232,   229,    45,   229,   232,
      45,   229,   232,    45,   229,   232,    45,   231,   232,   232,
     232,    91,   229,   229,   229,   229,   232,    44,    45,   231,
      44,    45,   231,    44,    45,   231,    43,    96,   229,   232,
     229,   232,   229,   232,   229,   232,    44,   229,   229,   229,
     229,    96,   229,   233,   232,    44,   233,   232,    44,   233,
     232,    44,   231,    43,   229,   229,   229,   229,   229,   232,
     229,    45,   229,   232,    45,   229,   232,    45,   229,   232,
      45,   231,   229,   232,   229,   232,   229,   232,   229,   232,
      44,   229,   229,   229,   229,   232,   229
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int16 yyr1[] =
{
       0,   243,   244,   244,   245,   245,   245,   246,   246,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   247,   247,   247,   247,   247,   247,
     247,   247,   247,   247,   248,   248,   248,   248,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   249,   249,   249,   249,   249,   249,   249,   249,
     249,   250,   250,   250,   250,   250,   251,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   252,   252,   252,
     252,   252,   252,   252,   252,   252,   252,   253,   253,   254,
     255,   255,   256,   257,   258,   259,   260,   261,   261,   262,
     263,   263,   263,   264,   264,   264,   264,   265,   265,   266,
     266,   266,   266,   266,   267,   267,   268,   268,   268,   268,
     268,   268,   268,   268,   268,   268,   268,   268,   268,   268,
     268,   268,   268,   268,   268,   268,   268,   268,   268,   268,
     268,   268,   268,   268,   269,   269,   270,   270,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   270,   270,   270,   270,   270,   270,   270,   270,   270,
     270,   270,   270,   270,   271,   272,   273,   274,   275,   276,
     277,   278,   279,   280,   280,   281,   281,   282,   282,   283,
     283,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,   283,   284,   284,   285,   285,   285,   285,   285,
     285,   285,   285,   285,   285,   285,   285,   285,   285,   285,
     285,   285,   286,   287,   287,   288,   289,   289,   290,   291,
     292,   292,   292,   292,   293,   294,   295,   295,   296,   297,
     297,   298,   299,   300,   301,   301,   302,   302,   303,   303,
     304,   304,   304,   304,   304,   304,   304,   304,   305,   305,
     305,   306,   306,   306,   307,   307,   308,   308,   309,   309,
     310,   310,   310,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   310,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   311,   311,   311,   311,
     311,   311,   311,   311,   311,   311,   312,   312,   313,   313,
     314,   314
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     0,     2,     2,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     4,     4,     4,    10,     8,     8,
       8,    10,    10,    12,    12,    14,    11,    11,    13,    11,
      12,    12,     4,     4,     4,     4,     4,     4,    11,    11,
      11,    13,    13,    13,    13,    13,     7,     8,     8,     8,
       8,     8,     9,    11,    11,    12,    12,    12,    12,     8,
       8,     0,     1,     1,     1,     1,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     4,     6,     4,     4,     5,     5,
       9,     7,     5,     3,     2,     3,     4,     3,     2,     5,
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
      13,    13,    10,     0,     2,     6,     6,     6,     8,     7,
       7,     7,     9,    10,    10,    12,    10,    12,    10,    12,
       6,     7,     8,     0,     2,     4,     0,     3,     6,     6,
      10,    12,    10,    12,     8,     6,     1,     2,     4,     0,
       3,     2,     2,     1,     1,     3,     1,     3,     1,     2,
       1,     3,     3,     3,     3,     3,     3,     3,     1,     3,
       3,     1,     3,     3,     1,     3,     1,     2,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
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
       4,     4,     4,     4,     4,     4,     4,     4,     4,     3,
       1,     8,     8,     8,     2,     4,     4,     4,     4,     4,
       4,     4,     4,     4,     4,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     0,     1,     1,     3,
       1,     3
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
#line 3061 "build/parser.cpp"
    break;

  case 3: /* program: statements_opt  */
#line 197 "src/parser.y"
                     {
        (yyval.program) = g_program;
    }
#line 3069 "build/parser.cpp"
    break;

  case 5: /* statements_opt: statements_opt statement  */
#line 204 "src/parser.y"
                               {
        if ((yyvsp[0].stmt)) {
            g_program->statements.emplace_back((yyvsp[0].stmt));
        }
    }
#line 3079 "build/parser.cpp"
    break;

  case 6: /* statements_opt: statements_opt KW_CTLOPT  */
#line 209 "src/parser.y"
                               {
        if (ctlopt_nomain) g_program->nomain = true;
        if (ctlopt_main_proc[0]) g_program->main_proc = ctlopt_main_proc;
        if (ctlopt_datfmt[0]) g_program->datfmt = ctlopt_datfmt;
        if (ctlopt_timfmt[0]) g_program->timfmt = ctlopt_timfmt;
    }
#line 3090 "build/parser.cpp"
    break;

  case 7: /* statement_list: %empty  */
#line 218 "src/parser.y"
                {
        (yyval.stmt_list) = new StmtList();
    }
#line 3098 "build/parser.cpp"
    break;

  case 8: /* statement_list: statement_list statement  */
#line 221 "src/parser.y"
                               {
        (yyval.stmt_list) = (yyvsp[-1].stmt_list);
        if ((yyvsp[0].stmt)) {
            (yyval.stmt_list)->stmts.push_back((yyvsp[0].stmt));
        }
    }
#line 3109 "build/parser.cpp"
    break;

  case 9: /* statement: dcl_f_stmt  */
#line 230 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3115 "build/parser.cpp"
    break;

  case 10: /* statement: dcl_s_stmt  */
#line 231 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3121 "build/parser.cpp"
    break;

  case 11: /* statement: dcl_c_stmt  */
#line 232 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3127 "build/parser.cpp"
    break;

  case 12: /* statement: eval_stmt  */
#line 233 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3133 "build/parser.cpp"
    break;

  case 13: /* statement: eval_corr_stmt  */
#line 234 "src/parser.y"
                     { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3139 "build/parser.cpp"
    break;

  case 14: /* statement: dsply_stmt  */
#line 235 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3145 "build/parser.cpp"
    break;

  case 15: /* statement: inlr_stmt  */
#line 236 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3151 "build/parser.cpp"
    break;

  case 16: /* statement: return_stmt  */
#line 237 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3157 "build/parser.cpp"
    break;

  case 17: /* statement: if_stmt  */
#line 238 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3163 "build/parser.cpp"
    break;

  case 18: /* statement: dow_stmt  */
#line 239 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3169 "build/parser.cpp"
    break;

  case 19: /* statement: dou_stmt  */
#line 240 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3175 "build/parser.cpp"
    break;

  case 20: /* statement: for_stmt  */
#line 241 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3181 "build/parser.cpp"
    break;

  case 21: /* statement: for_each_stmt  */
#line 242 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3187 "build/parser.cpp"
    break;

  case 22: /* statement: select_stmt  */
#line 243 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3193 "build/parser.cpp"
    break;

  case 23: /* statement: iter_stmt  */
#line 244 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3199 "build/parser.cpp"
    break;

  case 24: /* statement: leave_stmt  */
#line 245 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3205 "build/parser.cpp"
    break;

  case 25: /* statement: dcl_proc_stmt  */
#line 246 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3211 "build/parser.cpp"
    break;

  case 26: /* statement: dcl_pr_stmt  */
#line 247 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3217 "build/parser.cpp"
    break;

  case 27: /* statement: dcl_ds_stmt  */
#line 248 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3223 "build/parser.cpp"
    break;

  case 28: /* statement: dcl_enum_stmt  */
#line 249 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3229 "build/parser.cpp"
    break;

  case 29: /* statement: monitor_stmt  */
#line 250 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3235 "build/parser.cpp"
    break;

  case 30: /* statement: begsr_stmt  */
#line 251 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3241 "build/parser.cpp"
    break;

  case 31: /* statement: exsr_stmt  */
#line 252 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3247 "build/parser.cpp"
    break;

  case 32: /* statement: reset_stmt  */
#line 253 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3253 "build/parser.cpp"
    break;

  case 33: /* statement: clear_stmt  */
#line 254 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3259 "build/parser.cpp"
    break;

  case 34: /* statement: sorta_stmt  */
#line 255 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3265 "build/parser.cpp"
    break;

  case 35: /* statement: evalr_stmt  */
#line 256 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3271 "build/parser.cpp"
    break;

  case 36: /* statement: callp_stmt  */
#line 257 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3277 "build/parser.cpp"
    break;

  case 37: /* statement: leavesr_stmt  */
#line 258 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3283 "build/parser.cpp"
    break;

  case 38: /* statement: dealloc_stmt  */
#line 259 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3289 "build/parser.cpp"
    break;

  case 39: /* statement: test_stmt  */
#line 260 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3295 "build/parser.cpp"
    break;

  case 40: /* statement: exec_sql_stmt  */
#line 261 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3301 "build/parser.cpp"
    break;

  case 41: /* statement: xml_into_stmt  */
#line 262 "src/parser.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3307 "build/parser.cpp"
    break;

  case 42: /* statement: expr_stmt  */
#line 263 "src/parser.y"
                  { (yyval.stmt) = (yyvsp[0].stmt); SET_LINE((yyval.stmt)); }
#line 3313 "build/parser.cpp"
    break;

  case 43: /* statement: error SEMICOLON  */
#line 264 "src/parser.y"
                      { (yyval.stmt) = nullptr; yyerrok; }
#line 3319 "build/parser.cpp"
    break;

  case 44: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_DISK SEMICOLON  */
#line 269 "src/parser.y"
                                          {
        (yyval.stmt) = new rpg::DclF((yyvsp[-2].sval), "DISK");
        free((yyvsp[-2].sval));
    }
#line 3328 "build/parser.cpp"
    break;

  case 45: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_PRINTER SEMICOLON  */
#line 273 "src/parser.y"
                                               {
        (yyval.stmt) = new rpg::DclF((yyvsp[-2].sval), "PRINTER");
        free((yyvsp[-2].sval));
    }
#line 3337 "build/parser.cpp"
    break;

  case 46: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_WORKSTN SEMICOLON  */
#line 277 "src/parser.y"
                                               {
        (yyval.stmt) = new rpg::DclF((yyvsp[-2].sval), "WORKSTN");
        free((yyvsp[-2].sval));
    }
#line 3346 "build/parser.cpp"
    break;

  case 47: /* dcl_f_stmt: KW_DCL_F IDENTIFIER KW_DISK KW_USAGE LPAREN STAR COLON STAR RPAREN SEMICOLON  */
#line 281 "src/parser.y"
                                                                                   {
        (yyval.stmt) = new rpg::DclF((yyvsp[-8].sval), "DISK");
        free((yyvsp[-8].sval));
    }
#line 3355 "build/parser.cpp"
    break;

  case 48: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 289 "src/parser.y"
                                                                                  {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3365 "build/parser.cpp"
    break;

  case 49: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 294 "src/parser.y"
                                                                                       {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3375 "build/parser.cpp"
    break;

  case 50: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 299 "src/parser.y"
                                                                                   {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::INT10, 0);
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3385 "build/parser.cpp"
    break;

  case 51: /* dcl_s_stmt: KW_DCL_S ident KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 304 "src/parser.y"
                                                                                                            {
        auto* n = new rpg::DclS((yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-8].sval));
    }
#line 3395 "build/parser.cpp"
    break;

  case 52: /* dcl_s_stmt: KW_DCL_S ident KW_ZONED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 309 "src/parser.y"
                                                                                                           {
        auto* n = new rpg::DclS((yyvsp[-8].sval), rpg::RPGType::ZONED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-8].sval));
    }
#line 3405 "build/parser.cpp"
    break;

  case 53: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_CONST KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 314 "src/parser.y"
                                                                                                             {
        (yyval.stmt) = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, true,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-10].sval));
    }
#line 3415 "build/parser.cpp"
    break;

  case 54: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_CONST KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 319 "src/parser.y"
                                                                                                              {
        (yyval.stmt) = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, true,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-10].sval));
    }
#line 3425 "build/parser.cpp"
    break;

  case 55: /* dcl_s_stmt: KW_DCL_S ident KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_CONST KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 324 "src/parser.y"
                                                                                                                                      {
        (yyval.stmt) = new rpg::DclS((yyvsp[-12].sval), rpg::RPGType::PACKED, 0, (yyvsp[-9].ival), (yyvsp[-7].ival), true,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-12].sval));
    }
#line 3435 "build/parser.cpp"
    break;

  case 56: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 329 "src/parser.y"
                                                                                                    {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-9].sval));
    }
#line 3445 "build/parser.cpp"
    break;

  case 57: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 334 "src/parser.y"
                                                                                                     {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-9].sval));
    }
#line 3455 "build/parser.cpp"
    break;

  case 58: /* dcl_s_stmt: KW_DCL_S ident KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 339 "src/parser.y"
                                                                                                                             {
        (yyval.stmt) = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-11].sval));
    }
#line 3465 "build/parser.cpp"
    break;

  case 59: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 344 "src/parser.y"
                                                                                                        {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-9].sval));
    }
#line 3475 "build/parser.cpp"
    break;

  case 60: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_EXPORT KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 350 "src/parser.y"
                                                                                                              {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        n->is_export = true;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3486 "build/parser.cpp"
    break;

  case 61: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_EXPORT KW_INZ LPAREN expression RPAREN SEMICOLON  */
#line 356 "src/parser.y"
                                                                                                               {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, false,
                           std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        n->is_export = true;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3497 "build/parser.cpp"
    break;

  case 62: /* dcl_s_stmt: KW_DCL_S ident KW_IND SEMICOLON  */
#line 362 "src/parser.y"
                                      {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::IND, 0);
        free((yyvsp[-2].sval));
    }
#line 3506 "build/parser.cpp"
    break;

  case 63: /* dcl_s_stmt: KW_DCL_S ident KW_BOOLEAN SEMICOLON  */
#line 366 "src/parser.y"
                                          {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::IND, 0);
        free((yyvsp[-2].sval));
    }
#line 3515 "build/parser.cpp"
    break;

  case 64: /* dcl_s_stmt: KW_DCL_S ident KW_DATE SEMICOLON  */
#line 370 "src/parser.y"
                                       {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::DATE, 0);
        free((yyvsp[-2].sval));
    }
#line 3524 "build/parser.cpp"
    break;

  case 65: /* dcl_s_stmt: KW_DCL_S ident KW_TIME SEMICOLON  */
#line 374 "src/parser.y"
                                       {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::TIME, 0);
        free((yyvsp[-2].sval));
    }
#line 3533 "build/parser.cpp"
    break;

  case 66: /* dcl_s_stmt: KW_DCL_S ident KW_TIMESTAMP SEMICOLON  */
#line 378 "src/parser.y"
                                            {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::TIMESTAMP, 0);
        free((yyvsp[-2].sval));
    }
#line 3542 "build/parser.cpp"
    break;

  case 67: /* dcl_s_stmt: KW_DCL_S ident KW_POINTER SEMICOLON  */
#line 382 "src/parser.y"
                                          {
        (yyval.stmt) = new rpg::DclS((yyvsp[-2].sval), rpg::RPGType::POINTER, 0);
        free((yyvsp[-2].sval));
    }
#line 3551 "build/parser.cpp"
    break;

  case 68: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 386 "src/parser.y"
                                                                                                         {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-9].sval));
    }
#line 3560 "build/parser.cpp"
    break;

  case 69: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 390 "src/parser.y"
                                                                                                          {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-9].sval));
    }
#line 3569 "build/parser.cpp"
    break;

  case 70: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 394 "src/parser.y"
                                                                                                             {
        (yyval.stmt) = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-9].sval));
    }
#line 3578 "build/parser.cpp"
    break;

  case 71: /* dcl_s_stmt: KW_DCL_S ident KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 398 "src/parser.y"
                                                                                                                                  {
        (yyval.stmt) = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false, nullptr, (yyvsp[-2].ival));
        free((yyvsp[-11].sval));
    }
#line 3587 "build/parser.cpp"
    break;

  case 72: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN KW_DIM_VAR COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 402 "src/parser.y"
                                                                                                                          {
        auto* node = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-2].ival));
        node->dim_type = 1;
        free((yyvsp[-11].sval));
        (yyval.stmt) = node;
    }
#line 3598 "build/parser.cpp"
    break;

  case 73: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN KW_DIM_AUTO COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 408 "src/parser.y"
                                                                                                                           {
        auto* node = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-2].ival));
        node->dim_type = 2;
        free((yyvsp[-11].sval));
        (yyval.stmt) = node;
    }
#line 3609 "build/parser.cpp"
    break;

  case 74: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN KW_DIM_VAR COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 414 "src/parser.y"
                                                                                                                              {
        auto* node = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::VARCHAR, (yyvsp[-8].ival), 0, 0, false, nullptr, (yyvsp[-2].ival));
        node->dim_type = 1;
        free((yyvsp[-11].sval));
        (yyval.stmt) = node;
    }
#line 3620 "build/parser.cpp"
    break;

  case 75: /* dcl_s_stmt: KW_DCL_S ident KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN KW_DIM_AUTO COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 420 "src/parser.y"
                                                                                                                               {
        auto* node = new rpg::DclS((yyvsp[-11].sval), rpg::RPGType::VARCHAR, (yyvsp[-8].ival), 0, 0, false, nullptr, (yyvsp[-2].ival));
        node->dim_type = 2;
        free((yyvsp[-11].sval));
        (yyval.stmt) = node;
    }
#line 3631 "build/parser.cpp"
    break;

  case 76: /* dcl_s_stmt: KW_DCL_S ident KW_LIKE LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 426 "src/parser.y"
                                                                {
        auto* node = new rpg::DclS((yyvsp[-5].sval), rpg::RPGType::INT10, 0);
        node->like_var = (yyvsp[-2].sval);
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
        (yyval.stmt) = node;
    }
#line 3643 "build/parser.cpp"
    break;

  case 77: /* dcl_s_stmt: KW_DCL_S ident KW_UNS LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 433 "src/parser.y"
                                                                                   {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::UNS, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3653 "build/parser.cpp"
    break;

  case 78: /* dcl_s_stmt: KW_DCL_S ident KW_FLOAT_TYPE LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 438 "src/parser.y"
                                                                                          {
        auto type = ((yyvsp[-3].ival) <= 4) ? rpg::RPGType::FLOAT4 : rpg::RPGType::FLOAT8;
        auto* n = new rpg::DclS((yyvsp[-6].sval), type, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3664 "build/parser.cpp"
    break;

  case 79: /* dcl_s_stmt: KW_DCL_S ident KW_BINDEC LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 444 "src/parser.y"
                                                                                      {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::BINDEC, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3674 "build/parser.cpp"
    break;

  case 80: /* dcl_s_stmt: KW_DCL_S ident KW_UCS2 LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 449 "src/parser.y"
                                                                                    {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::UCS2, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3684 "build/parser.cpp"
    break;

  case 81: /* dcl_s_stmt: KW_DCL_S ident KW_GRAPH LPAREN INTEGER_LITERAL RPAREN dcl_s_keywords SEMICOLON  */
#line 454 "src/parser.y"
                                                                                     {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::UCS2, (yyvsp[-3].ival));
        n->is_static = ((yyvsp[-1].ival) & 1); n->is_template = ((yyvsp[-1].ival) & 2); n->is_export = ((yyvsp[-1].ival) & 4); n->is_import = ((yyvsp[-1].ival) & 8);
        (yyval.stmt) = n; free((yyvsp[-6].sval));
    }
#line 3694 "build/parser.cpp"
    break;

  case 82: /* dcl_s_stmt: KW_DCL_S ident KW_OBJECT LPAREN KW_JAVA COLON STRING_LITERAL RPAREN SEMICOLON  */
#line 459 "src/parser.y"
                                                                                    {
        auto* n = new rpg::DclS((yyvsp[-7].sval), rpg::RPGType::OBJECT, 0);
        n->java_class = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-7].sval)); free((yyvsp[-2].sval));
    }
#line 3704 "build/parser.cpp"
    break;

  case 83: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_BASED LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 464 "src/parser.y"
                                                                                                      {
        auto* n = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::INT10, 0);
        n->based_ptr = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
    }
#line 3714 "build/parser.cpp"
    break;

  case 84: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_BASED LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 469 "src/parser.y"
                                                                                                       {
        auto* n = new rpg::DclS((yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival));
        n->based_ptr = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
    }
#line 3724 "build/parser.cpp"
    break;

  case 85: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_ASCEND SEMICOLON  */
#line 474 "src/parser.y"
                                                                                                                   {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = 1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3734 "build/parser.cpp"
    break;

  case 86: /* dcl_s_stmt: KW_DCL_S ident KW_INT LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_DESCEND SEMICOLON  */
#line 479 "src/parser.y"
                                                                                                                    {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = -1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3744 "build/parser.cpp"
    break;

  case 87: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_ASCEND SEMICOLON  */
#line 484 "src/parser.y"
                                                                                                                    {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = 1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3754 "build/parser.cpp"
    break;

  case 88: /* dcl_s_stmt: KW_DCL_S ident KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_DESCEND SEMICOLON  */
#line 489 "src/parser.y"
                                                                                                                     {
        auto* n = new rpg::DclS((yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, false, nullptr, (yyvsp[-3].ival));
        n->sort_order = -1;
        (yyval.stmt) = n; free((yyvsp[-10].sval));
    }
#line 3764 "build/parser.cpp"
    break;

  case 89: /* dcl_s_stmt: KW_DCL_S ident KW_DATE KW_DATFMT LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 494 "src/parser.y"
                                                                          {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::DATE, 0);
        n->datfmt = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-6].sval)); free((yyvsp[-2].sval));
    }
#line 3774 "build/parser.cpp"
    break;

  case 90: /* dcl_s_stmt: KW_DCL_S ident KW_TIME KW_TIMFMT LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 499 "src/parser.y"
                                                                          {
        auto* n = new rpg::DclS((yyvsp[-6].sval), rpg::RPGType::TIME, 0);
        n->timfmt = (yyvsp[-2].sval);
        (yyval.stmt) = n; free((yyvsp[-6].sval)); free((yyvsp[-2].sval));
    }
#line 3784 "build/parser.cpp"
    break;

  case 91: /* dcl_s_keywords: %empty  */
#line 507 "src/parser.y"
                  { (yyval.ival) = 0; }
#line 3790 "build/parser.cpp"
    break;

  case 92: /* dcl_s_keywords: KW_STATIC  */
#line 508 "src/parser.y"
                  { (yyval.ival) = 1; }
#line 3796 "build/parser.cpp"
    break;

  case 93: /* dcl_s_keywords: KW_TEMPLATE  */
#line 509 "src/parser.y"
                  { (yyval.ival) = 2; }
#line 3802 "build/parser.cpp"
    break;

  case 94: /* dcl_s_keywords: KW_EXPORT  */
#line 510 "src/parser.y"
                  { (yyval.ival) = 4; }
#line 3808 "build/parser.cpp"
    break;

  case 95: /* dcl_s_keywords: KW_IMPORT  */
#line 511 "src/parser.y"
                  { (yyval.ival) = 8; }
#line 3814 "build/parser.cpp"
    break;

  case 96: /* dcl_c_stmt: KW_DCL_C IDENTIFIER expression SEMICOLON  */
#line 516 "src/parser.y"
                                             {
        (yyval.stmt) = new rpg::DclC((yyvsp[-2].sval), std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
        free((yyvsp[-2].sval));
    }
#line 3823 "build/parser.cpp"
    break;

  case 97: /* eval_target: IDENTIFIER  */
#line 523 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier((yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 3832 "build/parser.cpp"
    break;

  case 98: /* eval_target: KW_POS  */
#line 527 "src/parser.y"
             { (yyval.expr) = new rpg::Identifier("POS"); }
#line 3838 "build/parser.cpp"
    break;

  case 99: /* eval_target: KW_OVERLAY  */
#line 528 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("OVERLAY"); }
#line 3844 "build/parser.cpp"
    break;

  case 100: /* eval_target: KW_PREFIX  */
#line 529 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("PREFIX"); }
#line 3850 "build/parser.cpp"
    break;

  case 101: /* eval_target: KW_UNS  */
#line 530 "src/parser.y"
             { (yyval.expr) = new rpg::Identifier("UNS"); }
#line 3856 "build/parser.cpp"
    break;

  case 102: /* eval_target: KW_FLOAT_TYPE  */
#line 531 "src/parser.y"
                    { (yyval.expr) = new rpg::Identifier("FLOAT"); }
#line 3862 "build/parser.cpp"
    break;

  case 103: /* eval_target: KW_GRAPH  */
#line 532 "src/parser.y"
               { (yyval.expr) = new rpg::Identifier("GRAPH"); }
#line 3868 "build/parser.cpp"
    break;

  case 104: /* eval_target: KW_ASCEND  */
#line 533 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("ASCEND"); }
#line 3874 "build/parser.cpp"
    break;

  case 105: /* eval_target: KW_DESCEND  */
#line 534 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("DESCEND"); }
#line 3880 "build/parser.cpp"
    break;

  case 106: /* eval_target: KW_RTNPARM  */
#line 535 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("RTNPARM"); }
#line 3886 "build/parser.cpp"
    break;

  case 107: /* eval_target: KW_OPDESC  */
#line 536 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("OPDESC"); }
#line 3892 "build/parser.cpp"
    break;

  case 108: /* eval_target: KW_NULLIND  */
#line 537 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("NULLIND"); }
#line 3898 "build/parser.cpp"
    break;

  case 109: /* eval_target: KW_DATFMT  */
#line 538 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("DATFMT"); }
#line 3904 "build/parser.cpp"
    break;

  case 110: /* eval_target: KW_TIMFMT  */
#line 539 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("TIMFMT"); }
#line 3910 "build/parser.cpp"
    break;

  case 111: /* eval_target: KW_EXTNAME  */
#line 540 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("EXTNAME"); }
#line 3916 "build/parser.cpp"
    break;

  case 112: /* eval_target: INDICATOR  */
#line 541 "src/parser.y"
                {
        (yyval.expr) = new rpg::IndicatorExpr((yyvsp[0].ival));
    }
#line 3924 "build/parser.cpp"
    break;

  case 113: /* eval_target: IDENTIFIER DOT IDENTIFIER  */
#line 544 "src/parser.y"
                                {
        auto obj = std::unique_ptr<rpg::Expression>(new rpg::Identifier((yyvsp[-2].sval)));
        (yyval.expr) = new rpg::DotExpr(std::move(obj), (yyvsp[0].sval));
        free((yyvsp[-2].sval));
        free((yyvsp[0].sval));
    }
#line 3935 "build/parser.cpp"
    break;

  case 114: /* eval_target: IDENTIFIER LPAREN expression RPAREN  */
#line 550 "src/parser.y"
                                          {
        (yyval.expr) = new rpg::ArrayAccess((yyvsp[-3].sval), std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
        free((yyvsp[-3].sval));
    }
#line 3944 "build/parser.cpp"
    break;

  case 115: /* eval_target: IDENTIFIER LPAREN expression RPAREN DOT IDENTIFIER  */
#line 554 "src/parser.y"
                                                         {
        auto* arr = new rpg::ArrayAccess((yyvsp[-5].sval), std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)));
        (yyval.expr) = new rpg::DotExpr(std::unique_ptr<rpg::Expression>(arr), (yyvsp[0].sval));
        free((yyvsp[-5].sval));
        free((yyvsp[0].sval));
    }
#line 3955 "build/parser.cpp"
    break;

  case 116: /* eval_target: BIF_ELEM LPAREN arg_list RPAREN  */
#line 560 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("ELEM", (yyvsp[-1].expr_list));
    }
#line 3963 "build/parser.cpp"
    break;

  case 117: /* eval_stmt: eval_target EQUALS expression SEMICOLON  */
#line 566 "src/parser.y"
                                            {
        (yyval.stmt) = new rpg::EvalStmt(
            std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-1].expr))
        );
    }
#line 3974 "build/parser.cpp"
    break;

  case 118: /* eval_stmt: KW_EVAL eval_target EQUALS expression SEMICOLON  */
#line 572 "src/parser.y"
                                                      {
        (yyval.stmt) = new rpg::EvalStmt(
            std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-1].expr))
        );
    }
#line 3985 "build/parser.cpp"
    break;

  case 119: /* eval_corr_stmt: KW_EVAL_CORR ident EQUALS ident SEMICOLON  */
#line 581 "src/parser.y"
                                              {
        (yyval.stmt) = new rpg::EvalCorrStmt(std::string((yyvsp[-3].sval)), std::string((yyvsp[-1].sval)));
        free((yyvsp[-3].sval));
        free((yyvsp[-1].sval));
    }
#line 3995 "build/parser.cpp"
    break;

  case 120: /* xml_into_stmt: KW_XML_INTO ident BIF_XML LPAREN expression COLON expression RPAREN SEMICOLON  */
#line 589 "src/parser.y"
                                                                                  {
        (yyval.stmt) = new rpg::XmlIntoStmt(std::string((yyvsp[-7].sval)),
            std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)));
        free((yyvsp[-7].sval));
    }
#line 4006 "build/parser.cpp"
    break;

  case 121: /* xml_into_stmt: KW_XML_INTO ident BIF_XML LPAREN expression RPAREN SEMICOLON  */
#line 595 "src/parser.y"
                                                                   {
        (yyval.stmt) = new rpg::XmlIntoStmt(std::string((yyvsp[-5].sval)),
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            nullptr);
        free((yyvsp[-5].sval));
    }
#line 4017 "build/parser.cpp"
    break;

  case 122: /* evalr_stmt: KW_EVALR eval_target EQUALS expression SEMICOLON  */
#line 604 "src/parser.y"
                                                     {
        (yyval.stmt) = new rpg::EvalRStmt(
            std::unique_ptr<rpg::Expression>((yyvsp[-3].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[-1].expr))
        );
    }
#line 4028 "build/parser.cpp"
    break;

  case 123: /* callp_stmt: KW_CALLP expression SEMICOLON  */
#line 613 "src/parser.y"
                                  {
        (yyval.stmt) = new rpg::ExprStmt(std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
    }
#line 4036 "build/parser.cpp"
    break;

  case 124: /* leavesr_stmt: KW_LEAVESR SEMICOLON  */
#line 619 "src/parser.y"
                         {
        (yyval.stmt) = new rpg::LeaveSRStmt();
    }
#line 4044 "build/parser.cpp"
    break;

  case 125: /* dsply_stmt: KW_DSPLY expression SEMICOLON  */
#line 625 "src/parser.y"
                                  {
        (yyval.stmt) = new rpg::DsplyStmt(std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
    }
#line 4052 "build/parser.cpp"
    break;

  case 126: /* inlr_stmt: KW_INLR EQUALS KW_ON SEMICOLON  */
#line 631 "src/parser.y"
                                   {
        (yyval.stmt) = new rpg::ReturnStmt(0);
    }
#line 4060 "build/parser.cpp"
    break;

  case 127: /* return_stmt: KW_RETURN expression SEMICOLON  */
#line 637 "src/parser.y"
                                   {
        (yyval.stmt) = new rpg::ReturnStmt(std::unique_ptr<rpg::Expression>((yyvsp[-1].expr)));
    }
#line 4068 "build/parser.cpp"
    break;

  case 128: /* return_stmt: KW_RETURN SEMICOLON  */
#line 640 "src/parser.y"
                          {
        (yyval.stmt) = new rpg::ReturnStmt(0);
    }
#line 4076 "build/parser.cpp"
    break;

  case 129: /* expr_stmt: IDENTIFIER LPAREN call_args_opt RPAREN SEMICOLON  */
#line 647 "src/parser.y"
                                                     {
        auto* fc = make_func((yyvsp[-4].sval), (yyvsp[-2].expr_list));
        free((yyvsp[-4].sval));
        (yyval.stmt) = new rpg::ExprStmt(std::unique_ptr<rpg::Expression>(fc));
    }
#line 4086 "build/parser.cpp"
    break;

  case 130: /* dcl_pr_stmt: KW_DCL_PR IDENTIFIER pi_return_type SEMICOLON pr_params KW_END_PR SEMICOLON  */
#line 658 "src/parser.y"
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
#line 4107 "build/parser.cpp"
    break;

  case 131: /* dcl_pr_stmt: KW_DCL_PR IDENTIFIER pi_return_type KW_EXTPROC LPAREN STRING_LITERAL RPAREN SEMICOLON pr_params KW_END_PR SEMICOLON  */
#line 675 "src/parser.y"
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
#line 4131 "build/parser.cpp"
    break;

  case 132: /* dcl_pr_stmt: KW_DCL_PR IDENTIFIER KW_EXTPGM LPAREN STRING_LITERAL RPAREN SEMICOLON pr_params KW_END_PR SEMICOLON  */
#line 695 "src/parser.y"
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
#line 4147 "build/parser.cpp"
    break;

  case 133: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER proc_export SEMICOLON KW_DCL_PI pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 713 "src/parser.y"
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
#line 4172 "build/parser.cpp"
    break;

  case 134: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER proc_export SEMICOLON KW_DCL_PI IDENTIFIER pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 737 "src/parser.y"
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
#line 4198 "build/parser.cpp"
    break;

  case 135: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER proc_export SEMICOLON KW_DCL_PI pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_ON_EXIT SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 763 "src/parser.y"
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
#line 4225 "build/parser.cpp"
    break;

  case 136: /* dcl_proc_stmt: KW_DCL_PROC IDENTIFIER proc_export SEMICOLON KW_DCL_PI IDENTIFIER pi_return_type SEMICOLON pi_params KW_END_PI SEMICOLON statement_list KW_ON_EXIT SEMICOLON statement_list KW_END_PROC SEMICOLON  */
#line 790 "src/parser.y"
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
#line 4253 "build/parser.cpp"
    break;

  case 137: /* proc_export: %empty  */
#line 816 "src/parser.y"
                { (yyval.ival) = 0; }
#line 4259 "build/parser.cpp"
    break;

  case 138: /* proc_export: KW_EXPORT  */
#line 817 "src/parser.y"
                { (yyval.ival) = 1; }
#line 4265 "build/parser.cpp"
    break;

  case 139: /* pi_return_type: %empty  */
#line 822 "src/parser.y"
               { (yyval.ival) = -1; }
#line 4271 "build/parser.cpp"
    break;

  case 140: /* pi_return_type: KW_INT LPAREN INTEGER_LITERAL RPAREN  */
#line 823 "src/parser.y"
                                           { (yyval.ival) = (int)rpg::RPGType::INT10; }
#line 4277 "build/parser.cpp"
    break;

  case 141: /* pi_return_type: KW_CHAR LPAREN INTEGER_LITERAL RPAREN  */
#line 824 "src/parser.y"
                                            { (yyval.ival) = (int)rpg::RPGType::CHAR; }
#line 4283 "build/parser.cpp"
    break;

  case 142: /* pi_return_type: KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN  */
#line 825 "src/parser.y"
                                               { (yyval.ival) = (int)rpg::RPGType::VARCHAR; }
#line 4289 "build/parser.cpp"
    break;

  case 143: /* pi_return_type: KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN  */
#line 826 "src/parser.y"
                                                                    { (yyval.ival) = (int)rpg::RPGType::PACKED; }
#line 4295 "build/parser.cpp"
    break;

  case 144: /* pi_params: %empty  */
#line 831 "src/parser.y"
                {
        (yyval.param_list) = new ParamList();
    }
#line 4303 "build/parser.cpp"
    break;

  case 145: /* pi_params: pi_params pi_param  */
#line 834 "src/parser.y"
                         {
        (yyval.param_list) = (yyvsp[-1].param_list);
        (yyval.param_list)->params.push_back(*(yyvsp[0].param_decl));
        delete (yyvsp[0].param_decl);
    }
#line 4313 "build/parser.cpp"
    break;

  case 146: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 842 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4322 "build/parser.cpp"
    break;

  case 147: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 846 "src/parser.y"
                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4331 "build/parser.cpp"
    break;

  case 148: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 850 "src/parser.y"
                                                                 {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4340 "build/parser.cpp"
    break;

  case 149: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 854 "src/parser.y"
                                                                          {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4349 "build/parser.cpp"
    break;

  case 150: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 858 "src/parser.y"
                                                                    {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4358 "build/parser.cpp"
    break;

  case 151: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 862 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4367 "build/parser.cpp"
    break;

  case 152: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 866 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 4376 "build/parser.cpp"
    break;

  case 153: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 870 "src/parser.y"
                                                                                                  {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 4385 "build/parser.cpp"
    break;

  case 154: /* pi_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 875 "src/parser.y"
                                                                            {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4394 "build/parser.cpp"
    break;

  case 155: /* pi_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 879 "src/parser.y"
                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4403 "build/parser.cpp"
    break;

  case 156: /* pi_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 883 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4412 "build/parser.cpp"
    break;

  case 157: /* pi_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 887 "src/parser.y"
                                                                                      {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4421 "build/parser.cpp"
    break;

  case 158: /* pi_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 891 "src/parser.y"
                                                                                {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4430 "build/parser.cpp"
    break;

  case 159: /* pi_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 895 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4439 "build/parser.cpp"
    break;

  case 160: /* pi_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 899 "src/parser.y"
                                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 4448 "build/parser.cpp"
    break;

  case 161: /* pi_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 903 "src/parser.y"
                                                                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 4457 "build/parser.cpp"
    break;

  case 162: /* pi_param: IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 907 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, 0, 0, 0, false, std::string((yyvsp[-2].sval))};
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
    }
#line 4467 "build/parser.cpp"
    break;

  case 163: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 913 "src/parser.y"
                                                                                                            {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4477 "build/parser.cpp"
    break;

  case 164: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 918 "src/parser.y"
                                                                                                             {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4487 "build/parser.cpp"
    break;

  case 165: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 923 "src/parser.y"
                                                                                                                {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::VARCHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4497 "build/parser.cpp"
    break;

  case 166: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 928 "src/parser.y"
                                                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-12].sval), rpg::RPGType::PACKED, 0, (yyvsp[-9].ival), (yyvsp[-7].ival), true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-12].sval));
    }
#line 4507 "build/parser.cpp"
    break;

  case 167: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 934 "src/parser.y"
                                                                                                 {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4517 "build/parser.cpp"
    break;

  case 168: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 939 "src/parser.y"
                                                                                                  {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4527 "build/parser.cpp"
    break;

  case 169: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 944 "src/parser.y"
                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4537 "build/parser.cpp"
    break;

  case 170: /* pi_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 949 "src/parser.y"
                                                                                                                          {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4547 "build/parser.cpp"
    break;

  case 171: /* pi_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 955 "src/parser.y"
                                                                                                                 {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4557 "build/parser.cpp"
    break;

  case 172: /* pi_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 960 "src/parser.y"
                                                                                                                  {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::CHAR, (yyvsp[-8].ival), 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4567 "build/parser.cpp"
    break;

  case 173: /* pi_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 965 "src/parser.y"
                                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::VARCHAR, (yyvsp[-8].ival), 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4577 "build/parser.cpp"
    break;

  case 174: /* pr_params: %empty  */
#line 974 "src/parser.y"
                {
        (yyval.param_list) = new ParamList();
    }
#line 4585 "build/parser.cpp"
    break;

  case 175: /* pr_params: pr_params pr_param  */
#line 977 "src/parser.y"
                         {
        (yyval.param_list) = (yyvsp[-1].param_list);
        (yyval.param_list)->params.push_back(*(yyvsp[0].param_decl));
        delete (yyvsp[0].param_decl);
    }
#line 4595 "build/parser.cpp"
    break;

  case 176: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 985 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4604 "build/parser.cpp"
    break;

  case 177: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 989 "src/parser.y"
                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4613 "build/parser.cpp"
    break;

  case 178: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 993 "src/parser.y"
                                                                 {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4622 "build/parser.cpp"
    break;

  case 179: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 997 "src/parser.y"
                                                                          {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4631 "build/parser.cpp"
    break;

  case 180: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1001 "src/parser.y"
                                                                    {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4640 "build/parser.cpp"
    break;

  case 181: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1005 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4649 "build/parser.cpp"
    break;

  case 182: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1009 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 4658 "build/parser.cpp"
    break;

  case 183: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1013 "src/parser.y"
                                                                                                  {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 4667 "build/parser.cpp"
    break;

  case 184: /* pr_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1018 "src/parser.y"
                                                                            {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4676 "build/parser.cpp"
    break;

  case 185: /* pr_param: KW_DCL_PARM IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1022 "src/parser.y"
                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4685 "build/parser.cpp"
    break;

  case 186: /* pr_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1026 "src/parser.y"
                                                                             {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4694 "build/parser.cpp"
    break;

  case 187: /* pr_param: KW_DCL_PARM IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1030 "src/parser.y"
                                                                                      {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::CHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4703 "build/parser.cpp"
    break;

  case 188: /* pr_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1034 "src/parser.y"
                                                                                {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0, false};
        free((yyvsp[-5].sval));
    }
#line 4712 "build/parser.cpp"
    break;

  case 189: /* pr_param: KW_DCL_PARM IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1038 "src/parser.y"
                                                                                         {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-6].sval), rpg::RPGType::VARCHAR, (yyvsp[-3].ival), 0, 0, true};
        free((yyvsp[-6].sval));
    }
#line 4721 "build/parser.cpp"
    break;

  case 190: /* pr_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1042 "src/parser.y"
                                                                                                     {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival), false};
        free((yyvsp[-7].sval));
    }
#line 4730 "build/parser.cpp"
    break;

  case 191: /* pr_param: KW_DCL_PARM IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE SEMICOLON  */
#line 1046 "src/parser.y"
                                                                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-8].sval), rpg::RPGType::PACKED, 0, (yyvsp[-5].ival), (yyvsp[-3].ival), true};
        free((yyvsp[-8].sval));
    }
#line 4739 "build/parser.cpp"
    break;

  case 192: /* pr_param: IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1050 "src/parser.y"
                                                              {
        (yyval.param_decl) = new rpg::ParamDecl{(yyvsp[-5].sval), rpg::RPGType::CHAR, 0, 0, 0, false, std::string((yyvsp[-2].sval))};
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
    }
#line 4749 "build/parser.cpp"
    break;

  case 193: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1056 "src/parser.y"
                                                                                                            {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::INT10, 0, 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4759 "build/parser.cpp"
    break;

  case 194: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1061 "src/parser.y"
                                                                                                             {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::CHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4769 "build/parser.cpp"
    break;

  case 195: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1066 "src/parser.y"
                                                                                                                {
        auto* p = new rpg::ParamDecl{(yyvsp[-10].sval), rpg::RPGType::VARCHAR, (yyvsp[-7].ival), 0, 0, true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-10].sval));
    }
#line 4779 "build/parser.cpp"
    break;

  case 196: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_VALUE KW_OPTIONS LPAREN KW_NOPASS RPAREN SEMICOLON  */
#line 1071 "src/parser.y"
                                                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-12].sval), rpg::RPGType::PACKED, 0, (yyvsp[-9].ival), (yyvsp[-7].ival), true};
        p->nopass = true;
        (yyval.param_decl) = p; free((yyvsp[-12].sval));
    }
#line 4789 "build/parser.cpp"
    break;

  case 197: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1077 "src/parser.y"
                                                                                                 {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4799 "build/parser.cpp"
    break;

  case 198: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1082 "src/parser.y"
                                                                                                  {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4809 "build/parser.cpp"
    break;

  case 199: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1087 "src/parser.y"
                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-9].sval), rpg::RPGType::VARCHAR, (yyvsp[-6].ival), 0, 0, false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-9].sval));
    }
#line 4819 "build/parser.cpp"
    break;

  case 200: /* pr_param: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_OMIT RPAREN SEMICOLON  */
#line 1092 "src/parser.y"
                                                                                                                          {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival), false};
        p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4829 "build/parser.cpp"
    break;

  case 201: /* pr_param: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 1098 "src/parser.y"
                                                                                                                 {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4839 "build/parser.cpp"
    break;

  case 202: /* pr_param: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 1103 "src/parser.y"
                                                                                                                  {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::CHAR, (yyvsp[-8].ival), 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4849 "build/parser.cpp"
    break;

  case 203: /* pr_param: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN KW_OPTIONS LPAREN KW_NOPASS COLON KW_OMIT RPAREN SEMICOLON  */
#line 1108 "src/parser.y"
                                                                                                                     {
        auto* p = new rpg::ParamDecl{(yyvsp[-11].sval), rpg::RPGType::VARCHAR, (yyvsp[-8].ival), 0, 0, false};
        p->nopass = true; p->omit = true;
        (yyval.param_decl) = p; free((yyvsp[-11].sval));
    }
#line 4859 "build/parser.cpp"
    break;

  case 204: /* monitor_stmt: KW_MONITOR SEMICOLON statement_list KW_ON_ERROR SEMICOLON statement_list KW_ENDMON SEMICOLON  */
#line 1118 "src/parser.y"
                                                                                                 {
        auto* node = new rpg::MonitorStmt();
        for (auto* s : (yyvsp[-5].stmt_list)->stmts) node->try_body.emplace_back(s);
        delete (yyvsp[-5].stmt_list);
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->on_error_body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        (yyval.stmt) = node;
    }
#line 4872 "build/parser.cpp"
    break;

  case 205: /* begsr_stmt: KW_BEGSR IDENTIFIER SEMICOLON statement_list KW_ENDSR SEMICOLON  */
#line 1129 "src/parser.y"
                                                                    {
        auto* node = new rpg::BegSR((yyvsp[-4].sval));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        free((yyvsp[-4].sval));
        (yyval.stmt) = node;
    }
#line 4884 "build/parser.cpp"
    break;

  case 206: /* exsr_stmt: KW_EXSR ident SEMICOLON  */
#line 1139 "src/parser.y"
                            {
        (yyval.stmt) = new rpg::ExSR((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4893 "build/parser.cpp"
    break;

  case 207: /* sorta_stmt: KW_SORTA ident SEMICOLON  */
#line 1147 "src/parser.y"
                             {
        (yyval.stmt) = new rpg::SortAStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4902 "build/parser.cpp"
    break;

  case 208: /* reset_stmt: KW_RESET ident SEMICOLON  */
#line 1155 "src/parser.y"
                             {
        (yyval.stmt) = new rpg::ResetStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4911 "build/parser.cpp"
    break;

  case 209: /* clear_stmt: KW_CLEAR ident SEMICOLON  */
#line 1162 "src/parser.y"
                             {
        (yyval.stmt) = new rpg::ClearStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4920 "build/parser.cpp"
    break;

  case 210: /* dealloc_stmt: KW_DEALLOC ident SEMICOLON  */
#line 1170 "src/parser.y"
                               {
        (yyval.stmt) = new rpg::DeallocStmt((yyvsp[-1].sval));
        free((yyvsp[-1].sval));
    }
#line 4929 "build/parser.cpp"
    break;

  case 211: /* test_stmt: KW_TEST LPAREN ident RPAREN ident SEMICOLON  */
#line 1178 "src/parser.y"
                                                {
        char type = toupper((yyvsp[-3].sval)[0]);
        (yyval.stmt) = new rpg::TestStmt(type, std::string((yyvsp[-1].sval)));
        free((yyvsp[-3].sval));
        free((yyvsp[-1].sval));
    }
#line 4940 "build/parser.cpp"
    break;

  case 212: /* exec_sql_stmt: EXEC_SQL_TEXT  */
#line 1189 "src/parser.y"
                  {
        rpg::SqlStmtKind kind = rpg::classifySqlStmt((yyvsp[0].sval));
        (yyval.stmt) = new rpg::ExecSqlStmt(std::string((yyvsp[0].sval)), kind);
        free((yyvsp[0].sval));
    }
#line 4950 "build/parser.cpp"
    break;

  case 213: /* dcl_enum_stmt: KW_DCL_ENUM IDENTIFIER KW_QUALIFIED SEMICOLON enum_constants KW_END_ENUM SEMICOLON  */
#line 1199 "src/parser.y"
                                                                                       {
        auto* e = new rpg::DclEnum((yyvsp[-5].sval));
        e->qualified = true;
        e->constants = std::move(*(yyvsp[-2].enum_const_list));
        delete (yyvsp[-2].enum_const_list);
        free((yyvsp[-5].sval));
        (yyval.stmt) = e;
    }
#line 4963 "build/parser.cpp"
    break;

  case 214: /* dcl_enum_stmt: KW_DCL_ENUM IDENTIFIER SEMICOLON enum_constants KW_END_ENUM SEMICOLON  */
#line 1207 "src/parser.y"
                                                                            {
        auto* e = new rpg::DclEnum((yyvsp[-4].sval));
        e->qualified = false;
        e->constants = std::move(*(yyvsp[-2].enum_const_list));
        delete (yyvsp[-2].enum_const_list);
        free((yyvsp[-4].sval));
        (yyval.stmt) = e;
    }
#line 4976 "build/parser.cpp"
    break;

  case 215: /* enum_constants: enum_constant  */
#line 1218 "src/parser.y"
                  {
        (yyval.enum_const_list) = (yyvsp[0].enum_const_list);
    }
#line 4984 "build/parser.cpp"
    break;

  case 216: /* enum_constants: enum_constants enum_constant  */
#line 1221 "src/parser.y"
                                   {
        (yyvsp[-1].enum_const_list)->insert((yyvsp[-1].enum_const_list)->end(), std::make_move_iterator((yyvsp[0].enum_const_list)->begin()), std::make_move_iterator((yyvsp[0].enum_const_list)->end()));
        delete (yyvsp[0].enum_const_list);
        (yyval.enum_const_list) = (yyvsp[-1].enum_const_list);
    }
#line 4994 "build/parser.cpp"
    break;

  case 217: /* enum_constant: IDENTIFIER SEMICOLON  */
#line 1229 "src/parser.y"
                         {
        auto* v = new std::vector<rpg::EnumConstant>();
        rpg::EnumConstant ec;
        ec.name = (yyvsp[-1].sval);
        free((yyvsp[-1].sval));
        v->push_back(std::move(ec));
        (yyval.enum_const_list) = v;
    }
#line 5007 "build/parser.cpp"
    break;

  case 218: /* enum_constant: IDENTIFIER EQUALS expression SEMICOLON  */
#line 1237 "src/parser.y"
                                             {
        auto* v = new std::vector<rpg::EnumConstant>();
        rpg::EnumConstant ec;
        ec.name = (yyvsp[-3].sval);
        ec.value.reset((yyvsp[-1].expr));
        free((yyvsp[-3].sval));
        v->push_back(std::move(ec));
        (yyval.enum_const_list) = v;
    }
#line 5021 "build/parser.cpp"
    break;

  case 219: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1252 "src/parser.y"
                                                                              {
        auto* ds = new rpg::DclDS((yyvsp[-5].sval));
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-5].sval));
        (yyval.stmt) = ds;
    }
#line 5034 "build/parser.cpp"
    break;

  case 220: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1261 "src/parser.y"
                                                                   {
        auto* ds = new rpg::DclDS((yyvsp[-4].sval));
        ds->qualified = false;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-4].sval));
        (yyval.stmt) = ds;
    }
#line 5047 "build/parser.cpp"
    break;

  case 221: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_DIM LPAREN INTEGER_LITERAL RPAREN KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1270 "src/parser.y"
                                                                                                                     {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->dim = (yyvsp[-6].ival);
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-9].sval));
        (yyval.stmt) = ds;
    }
#line 5061 "build/parser.cpp"
    break;

  case 222: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1280 "src/parser.y"
                                                                                                                     {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->dim = (yyvsp[-5].ival);
        ds->qualified = true;
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-9].sval));
        (yyval.stmt) = ds;
    }
#line 5075 "build/parser.cpp"
    break;

  case 223: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_DIM LPAREN KW_DIM_VAR COLON INTEGER_LITERAL RPAREN KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1290 "src/parser.y"
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
#line 5090 "build/parser.cpp"
    break;

  case 224: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_DIM LPAREN KW_DIM_VAR COLON INTEGER_LITERAL RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1301 "src/parser.y"
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
#line 5105 "build/parser.cpp"
    break;

  case 225: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_DIM LPAREN KW_DIM_AUTO COLON INTEGER_LITERAL RPAREN KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1312 "src/parser.y"
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
#line 5120 "build/parser.cpp"
    break;

  case 226: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_DIM LPAREN KW_DIM_AUTO COLON INTEGER_LITERAL RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1323 "src/parser.y"
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
#line 5135 "build/parser.cpp"
    break;

  case 227: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1334 "src/parser.y"
                                                                        {
        auto* ds = new rpg::DclDS((yyvsp[-5].sval));
        ds->like_ds = (yyvsp[-2].sval);
        free((yyvsp[-5].sval));
        free((yyvsp[-2].sval));
        (yyval.stmt) = ds;
    }
#line 5147 "build/parser.cpp"
    break;

  case 228: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN KW_DIM LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1342 "src/parser.y"
                                                                                                             {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->like_ds = (yyvsp[-6].sval);
        ds->dim = (yyvsp[-2].ival);
        free((yyvsp[-9].sval));
        free((yyvsp[-6].sval));
        (yyval.stmt) = ds;
    }
#line 5160 "build/parser.cpp"
    break;

  case 229: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_PREFIX LPAREN IDENTIFIER RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1351 "src/parser.y"
                                                                                                                   {
        auto* ds = new rpg::DclDS((yyvsp[-9].sval));
        ds->qualified = true;
        ds->prefix = (yyvsp[-5].sval);
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-9].sval)); free((yyvsp[-5].sval));
        (yyval.stmt) = ds;
    }
#line 5174 "build/parser.cpp"
    break;

  case 230: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_PREFIX LPAREN IDENTIFIER COLON INTEGER_LITERAL RPAREN KW_QUALIFIED SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1361 "src/parser.y"
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
#line 5189 "build/parser.cpp"
    break;

  case 231: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_QUALIFIED KW_PREFIX LPAREN IDENTIFIER COLON INTEGER_LITERAL RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1372 "src/parser.y"
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
#line 5204 "build/parser.cpp"
    break;

  case 232: /* dcl_ds_stmt: KW_DCL_DS IDENTIFIER KW_PREFIX LPAREN IDENTIFIER RPAREN SEMICOLON ds_fields KW_END_DS SEMICOLON  */
#line 1383 "src/parser.y"
                                                                                                      {
        auto* ds = new rpg::DclDS((yyvsp[-8].sval));
        ds->qualified = false;
        ds->prefix = (yyvsp[-5].sval);
        ds->fields = std::move((yyvsp[-2].ds_field_list)->fields);
        delete (yyvsp[-2].ds_field_list);
        free((yyvsp[-8].sval)); free((yyvsp[-5].sval));
        (yyval.stmt) = ds;
    }
#line 5218 "build/parser.cpp"
    break;

  case 233: /* ds_fields: %empty  */
#line 1395 "src/parser.y"
                {
        (yyval.ds_field_list) = new DSFieldList();
    }
#line 5226 "build/parser.cpp"
    break;

  case 234: /* ds_fields: ds_fields ds_field  */
#line 1398 "src/parser.y"
                         {
        (yyval.ds_field_list) = (yyvsp[-1].ds_field_list);
        (yyval.ds_field_list)->fields.push_back(*(yyvsp[0].ds_field));
        delete (yyvsp[0].ds_field);
    }
#line 5236 "build/parser.cpp"
    break;

  case 235: /* ds_field: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1406 "src/parser.y"
                                                              {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5245 "build/parser.cpp"
    break;

  case 236: /* ds_field: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1410 "src/parser.y"
                                                                 {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5254 "build/parser.cpp"
    break;

  case 237: /* ds_field: IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1414 "src/parser.y"
                                                                    {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5263 "build/parser.cpp"
    break;

  case 238: /* ds_field: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1418 "src/parser.y"
                                                                                         {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival)};
        free((yyvsp[-7].sval));
    }
#line 5272 "build/parser.cpp"
    break;

  case 239: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1423 "src/parser.y"
                                                                            {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::INT10, 0, 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5281 "build/parser.cpp"
    break;

  case 240: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1427 "src/parser.y"
                                                                             {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::CHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5290 "build/parser.cpp"
    break;

  case 241: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_VARCHAR LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1431 "src/parser.y"
                                                                                {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::VARCHAR, (yyvsp[-2].ival), 0, 0};
        free((yyvsp[-5].sval));
    }
#line 5299 "build/parser.cpp"
    break;

  case 242: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1435 "src/parser.y"
                                                                                                     {
        (yyval.ds_field) = new rpg::DSField{(yyvsp[-7].sval), rpg::RPGType::PACKED, 0, (yyvsp[-4].ival), (yyvsp[-2].ival)};
        free((yyvsp[-7].sval));
    }
#line 5308 "build/parser.cpp"
    break;

  case 243: /* ds_field: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_POS LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1440 "src/parser.y"
                                                                                                      {
        auto* f = new rpg::DSField{(yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0};
        f->pos = (yyvsp[-2].ival);
        free((yyvsp[-9].sval));
        (yyval.ds_field) = f;
    }
#line 5319 "build/parser.cpp"
    break;

  case 244: /* ds_field: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_POS LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1446 "src/parser.y"
                                                                                                     {
        auto* f = new rpg::DSField{(yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0};
        f->pos = (yyvsp[-2].ival);
        free((yyvsp[-9].sval));
        (yyval.ds_field) = f;
    }
#line 5330 "build/parser.cpp"
    break;

  case 245: /* ds_field: IDENTIFIER KW_PACKED LPAREN INTEGER_LITERAL COLON INTEGER_LITERAL RPAREN KW_POS LPAREN INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1452 "src/parser.y"
                                                                                                                              {
        auto* f = new rpg::DSField{(yyvsp[-11].sval), rpg::RPGType::PACKED, 0, (yyvsp[-8].ival), (yyvsp[-6].ival)};
        f->pos = (yyvsp[-2].ival);
        free((yyvsp[-11].sval));
        (yyval.ds_field) = f;
    }
#line 5341 "build/parser.cpp"
    break;

  case 246: /* ds_field: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OVERLAY LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1459 "src/parser.y"
                                                                                                     {
        auto* f = new rpg::DSField{(yyvsp[-9].sval), rpg::RPGType::CHAR, (yyvsp[-6].ival), 0, 0};
        f->overlay_field = (yyvsp[-2].sval);
        free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
        (yyval.ds_field) = f;
    }
#line 5352 "build/parser.cpp"
    break;

  case 247: /* ds_field: IDENTIFIER KW_CHAR LPAREN INTEGER_LITERAL RPAREN KW_OVERLAY LPAREN IDENTIFIER COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1466 "src/parser.y"
                                                                                                                           {
        auto* f = new rpg::DSField{(yyvsp[-11].sval), rpg::RPGType::CHAR, (yyvsp[-8].ival), 0, 0};
        f->overlay_field = (yyvsp[-4].sval);
        f->overlay_pos = (yyvsp[-2].ival);
        free((yyvsp[-11].sval)); free((yyvsp[-4].sval));
        (yyval.ds_field) = f;
    }
#line 5364 "build/parser.cpp"
    break;

  case 248: /* ds_field: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OVERLAY LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1473 "src/parser.y"
                                                                                                    {
        auto* f = new rpg::DSField{(yyvsp[-9].sval), rpg::RPGType::INT10, 0, 0, 0};
        f->overlay_field = (yyvsp[-2].sval);
        free((yyvsp[-9].sval)); free((yyvsp[-2].sval));
        (yyval.ds_field) = f;
    }
#line 5375 "build/parser.cpp"
    break;

  case 249: /* ds_field: IDENTIFIER KW_INT LPAREN INTEGER_LITERAL RPAREN KW_OVERLAY LPAREN IDENTIFIER COLON INTEGER_LITERAL RPAREN SEMICOLON  */
#line 1479 "src/parser.y"
                                                                                                                          {
        auto* f = new rpg::DSField{(yyvsp[-11].sval), rpg::RPGType::INT10, 0, 0, 0};
        f->overlay_field = (yyvsp[-4].sval);
        f->overlay_pos = (yyvsp[-2].ival);
        free((yyvsp[-11].sval)); free((yyvsp[-4].sval));
        (yyval.ds_field) = f;
    }
#line 5387 "build/parser.cpp"
    break;

  case 250: /* ds_field: IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1487 "src/parser.y"
                                                              {
        auto* f = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::CHAR, 0, 0, 0};
        f->likeds = (yyvsp[-2].sval);
        free((yyvsp[-5].sval)); free((yyvsp[-2].sval));
        (yyval.ds_field) = f;
    }
#line 5398 "build/parser.cpp"
    break;

  case 251: /* ds_field: KW_DCL_SUBF IDENTIFIER KW_LIKEDS LPAREN IDENTIFIER RPAREN SEMICOLON  */
#line 1493 "src/parser.y"
                                                                          {
        auto* f = new rpg::DSField{(yyvsp[-5].sval), rpg::RPGType::CHAR, 0, 0, 0};
        f->likeds = (yyvsp[-2].sval);
        free((yyvsp[-5].sval)); free((yyvsp[-2].sval));
        (yyval.ds_field) = f;
    }
#line 5409 "build/parser.cpp"
    break;

  case 252: /* if_stmt: KW_IF expression SEMICOLON statement_list elseif_clauses else_clause KW_ENDIF SEMICOLON  */
#line 1504 "src/parser.y"
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
#line 5434 "build/parser.cpp"
    break;

  case 253: /* elseif_clauses: %empty  */
#line 1527 "src/parser.y"
                { (yyval.elseif_list) = nullptr; }
#line 5440 "build/parser.cpp"
    break;

  case 254: /* elseif_clauses: elseif_clauses elseif_clause  */
#line 1528 "src/parser.y"
                                   {
        if (!(yyvsp[-1].elseif_list)) (yyvsp[-1].elseif_list) = new std::vector<ElseIfData*>();
        (yyval.elseif_list) = (yyvsp[-1].elseif_list);
        (yyval.elseif_list)->push_back((yyvsp[0].elseif_data));
    }
#line 5450 "build/parser.cpp"
    break;

  case 255: /* elseif_clause: KW_ELSEIF expression SEMICOLON statement_list  */
#line 1536 "src/parser.y"
                                                  {
        (yyval.elseif_data) = new ElseIfData();
        (yyval.elseif_data)->cond = (yyvsp[-2].expr);
        (yyval.elseif_data)->body = std::move((yyvsp[0].stmt_list)->stmts);
        delete (yyvsp[0].stmt_list);
    }
#line 5461 "build/parser.cpp"
    break;

  case 256: /* else_clause: %empty  */
#line 1545 "src/parser.y"
                { (yyval.stmt_list) = nullptr; }
#line 5467 "build/parser.cpp"
    break;

  case 257: /* else_clause: KW_ELSE SEMICOLON statement_list  */
#line 1546 "src/parser.y"
                                       {
        (yyval.stmt_list) = (yyvsp[0].stmt_list);
    }
#line 5475 "build/parser.cpp"
    break;

  case 258: /* dow_stmt: KW_DOW expression SEMICOLON statement_list KW_ENDDO SEMICOLON  */
#line 1552 "src/parser.y"
                                                                  {
        auto* node = new rpg::DowStmt(std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        (yyval.stmt) = node;
    }
#line 5486 "build/parser.cpp"
    break;

  case 259: /* dou_stmt: KW_DOU expression SEMICOLON statement_list KW_ENDDO SEMICOLON  */
#line 1561 "src/parser.y"
                                                                  {
        auto* node = new rpg::DouStmt(std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        (yyval.stmt) = node;
    }
#line 5497 "build/parser.cpp"
    break;

  case 260: /* for_stmt: KW_FOR ident EQUALS expression KW_TO expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1570 "src/parser.y"
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
#line 5512 "build/parser.cpp"
    break;

  case 261: /* for_stmt: KW_FOR ident EQUALS expression KW_TO expression KW_BY expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1580 "src/parser.y"
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
#line 5527 "build/parser.cpp"
    break;

  case 262: /* for_stmt: KW_FOR ident EQUALS expression KW_DOWNTO expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1590 "src/parser.y"
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
#line 5542 "build/parser.cpp"
    break;

  case 263: /* for_stmt: KW_FOR ident EQUALS expression KW_DOWNTO expression KW_BY expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1600 "src/parser.y"
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
#line 5557 "build/parser.cpp"
    break;

  case 264: /* for_each_stmt: KW_FOR_EACH ident KW_IN expression SEMICOLON statement_list KW_ENDFOR SEMICOLON  */
#line 1613 "src/parser.y"
                                                                                    {
        auto* node = new rpg::ForEachStmt((yyvsp[-6].sval), std::unique_ptr<rpg::Expression>((yyvsp[-4].expr)));
        for (auto* s : (yyvsp[-2].stmt_list)->stmts) node->body.emplace_back(s);
        delete (yyvsp[-2].stmt_list);
        free((yyvsp[-6].sval));
        (yyval.stmt) = node;
    }
#line 5569 "build/parser.cpp"
    break;

  case 265: /* select_stmt: KW_SELECT SEMICOLON when_clauses other_clause KW_ENDSL SEMICOLON  */
#line 1623 "src/parser.y"
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
#line 5590 "build/parser.cpp"
    break;

  case 266: /* when_clauses: when_clause  */
#line 1642 "src/parser.y"
                {
        (yyval.when_list) = new std::vector<WhenData*>();
        (yyval.when_list)->push_back((yyvsp[0].when_data));
    }
#line 5599 "build/parser.cpp"
    break;

  case 267: /* when_clauses: when_clauses when_clause  */
#line 1646 "src/parser.y"
                               {
        (yyval.when_list) = (yyvsp[-1].when_list);
        (yyval.when_list)->push_back((yyvsp[0].when_data));
    }
#line 5608 "build/parser.cpp"
    break;

  case 268: /* when_clause: KW_WHEN expression SEMICOLON statement_list  */
#line 1653 "src/parser.y"
                                                {
        (yyval.when_data) = new WhenData();
        (yyval.when_data)->cond = (yyvsp[-2].expr);
        (yyval.when_data)->body = std::move((yyvsp[0].stmt_list)->stmts);
        delete (yyvsp[0].stmt_list);
    }
#line 5619 "build/parser.cpp"
    break;

  case 269: /* other_clause: %empty  */
#line 1662 "src/parser.y"
                { (yyval.stmt_list) = nullptr; }
#line 5625 "build/parser.cpp"
    break;

  case 270: /* other_clause: KW_OTHER SEMICOLON statement_list  */
#line 1663 "src/parser.y"
                                        {
        (yyval.stmt_list) = (yyvsp[0].stmt_list);
    }
#line 5633 "build/parser.cpp"
    break;

  case 271: /* iter_stmt: KW_ITER SEMICOLON  */
#line 1669 "src/parser.y"
                      { (yyval.stmt) = new rpg::IterStmt(); }
#line 5639 "build/parser.cpp"
    break;

  case 272: /* leave_stmt: KW_LEAVE SEMICOLON  */
#line 1673 "src/parser.y"
                       { (yyval.stmt) = new rpg::LeaveStmt(); }
#line 5645 "build/parser.cpp"
    break;

  case 273: /* expression: or_expr  */
#line 1679 "src/parser.y"
            { (yyval.expr) = (yyvsp[0].expr); }
#line 5651 "build/parser.cpp"
    break;

  case 274: /* or_expr: and_expr  */
#line 1683 "src/parser.y"
             { (yyval.expr) = (yyvsp[0].expr); }
#line 5657 "build/parser.cpp"
    break;

  case 275: /* or_expr: or_expr KW_OR and_expr  */
#line 1684 "src/parser.y"
                             {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::OR,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5667 "build/parser.cpp"
    break;

  case 276: /* and_expr: not_expr  */
#line 1692 "src/parser.y"
             { (yyval.expr) = (yyvsp[0].expr); }
#line 5673 "build/parser.cpp"
    break;

  case 277: /* and_expr: and_expr KW_AND not_expr  */
#line 1693 "src/parser.y"
                               {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::AND,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5683 "build/parser.cpp"
    break;

  case 278: /* not_expr: comparison_expr  */
#line 1701 "src/parser.y"
                    { (yyval.expr) = (yyvsp[0].expr); }
#line 5689 "build/parser.cpp"
    break;

  case 279: /* not_expr: KW_NOT comparison_expr  */
#line 1702 "src/parser.y"
                             {
        (yyval.expr) = new rpg::NotExpr(std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5697 "build/parser.cpp"
    break;

  case 280: /* comparison_expr: additive_expr  */
#line 1708 "src/parser.y"
                  { (yyval.expr) = (yyvsp[0].expr); }
#line 5703 "build/parser.cpp"
    break;

  case 281: /* comparison_expr: comparison_expr EQUALS additive_expr  */
#line 1709 "src/parser.y"
                                           {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::EQ,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5713 "build/parser.cpp"
    break;

  case 282: /* comparison_expr: comparison_expr NE additive_expr  */
#line 1714 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::NE,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5723 "build/parser.cpp"
    break;

  case 283: /* comparison_expr: comparison_expr LT additive_expr  */
#line 1719 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::LT,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5733 "build/parser.cpp"
    break;

  case 284: /* comparison_expr: comparison_expr GT additive_expr  */
#line 1724 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::GT,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5743 "build/parser.cpp"
    break;

  case 285: /* comparison_expr: comparison_expr LE additive_expr  */
#line 1729 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::LE,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5753 "build/parser.cpp"
    break;

  case 286: /* comparison_expr: comparison_expr GE additive_expr  */
#line 1734 "src/parser.y"
                                       {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::GE,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5763 "build/parser.cpp"
    break;

  case 287: /* comparison_expr: additive_expr KW_IN additive_expr  */
#line 1739 "src/parser.y"
                                        {
        (yyval.expr) = new rpg::InExpr(
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5773 "build/parser.cpp"
    break;

  case 288: /* additive_expr: multiplicative_expr  */
#line 1747 "src/parser.y"
                        { (yyval.expr) = (yyvsp[0].expr); }
#line 5779 "build/parser.cpp"
    break;

  case 289: /* additive_expr: additive_expr PLUS multiplicative_expr  */
#line 1748 "src/parser.y"
                                             {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::ADD,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5789 "build/parser.cpp"
    break;

  case 290: /* additive_expr: additive_expr MINUS multiplicative_expr  */
#line 1753 "src/parser.y"
                                              {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::SUB,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5799 "build/parser.cpp"
    break;

  case 291: /* multiplicative_expr: power_expr  */
#line 1761 "src/parser.y"
               { (yyval.expr) = (yyvsp[0].expr); }
#line 5805 "build/parser.cpp"
    break;

  case 292: /* multiplicative_expr: multiplicative_expr STAR power_expr  */
#line 1762 "src/parser.y"
                                          {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::MUL,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5815 "build/parser.cpp"
    break;

  case 293: /* multiplicative_expr: multiplicative_expr SLASH power_expr  */
#line 1767 "src/parser.y"
                                           {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::DIV,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5825 "build/parser.cpp"
    break;

  case 294: /* power_expr: unary_expr  */
#line 1775 "src/parser.y"
               { (yyval.expr) = (yyvsp[0].expr); }
#line 5831 "build/parser.cpp"
    break;

  case 295: /* power_expr: unary_expr POWER power_expr  */
#line 1776 "src/parser.y"
                                  {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::POWER,
            std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5841 "build/parser.cpp"
    break;

  case 296: /* unary_expr: postfix_expr  */
#line 1784 "src/parser.y"
                 { (yyval.expr) = (yyvsp[0].expr); }
#line 5847 "build/parser.cpp"
    break;

  case 297: /* unary_expr: MINUS postfix_expr  */
#line 1785 "src/parser.y"
                         {
        (yyval.expr) = new rpg::BinaryExpr(rpg::BinOp::SUB,
            std::unique_ptr<rpg::Expression>(new rpg::IntLiteral(0)),
            std::unique_ptr<rpg::Expression>((yyvsp[0].expr)));
    }
#line 5857 "build/parser.cpp"
    break;

  case 298: /* postfix_expr: primary_expr  */
#line 1793 "src/parser.y"
                 { (yyval.expr) = (yyvsp[0].expr); }
#line 5863 "build/parser.cpp"
    break;

  case 299: /* postfix_expr: postfix_expr DOT IDENTIFIER  */
#line 1794 "src/parser.y"
                                  {
        (yyval.expr) = new rpg::DotExpr(std::unique_ptr<rpg::Expression>((yyvsp[-2].expr)), (yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 5872 "build/parser.cpp"
    break;

  case 300: /* ident: IDENTIFIER  */
#line 1801 "src/parser.y"
               { (yyval.sval) = (yyvsp[0].sval); }
#line 5878 "build/parser.cpp"
    break;

  case 301: /* ident: KW_UNS  */
#line 1802 "src/parser.y"
             { (yyval.sval) = strdup("UNS"); }
#line 5884 "build/parser.cpp"
    break;

  case 302: /* ident: KW_FLOAT_TYPE  */
#line 1803 "src/parser.y"
                    { (yyval.sval) = strdup("FLOAT"); }
#line 5890 "build/parser.cpp"
    break;

  case 303: /* ident: KW_GRAPH  */
#line 1804 "src/parser.y"
               { (yyval.sval) = strdup("GRAPH"); }
#line 5896 "build/parser.cpp"
    break;

  case 304: /* ident: KW_ASCEND  */
#line 1805 "src/parser.y"
                { (yyval.sval) = strdup("ASCEND"); }
#line 5902 "build/parser.cpp"
    break;

  case 305: /* ident: KW_DESCEND  */
#line 1806 "src/parser.y"
                 { (yyval.sval) = strdup("DESCEND"); }
#line 5908 "build/parser.cpp"
    break;

  case 306: /* ident: KW_IN  */
#line 1807 "src/parser.y"
            { (yyval.sval) = strdup("IN"); }
#line 5914 "build/parser.cpp"
    break;

  case 307: /* ident: KW_RTNPARM  */
#line 1808 "src/parser.y"
                 { (yyval.sval) = strdup("RTNPARM"); }
#line 5920 "build/parser.cpp"
    break;

  case 308: /* ident: KW_OPDESC  */
#line 1809 "src/parser.y"
                { (yyval.sval) = strdup("OPDESC"); }
#line 5926 "build/parser.cpp"
    break;

  case 309: /* ident: KW_NULLIND  */
#line 1810 "src/parser.y"
                 { (yyval.sval) = strdup("NULLIND"); }
#line 5932 "build/parser.cpp"
    break;

  case 310: /* ident: KW_DATFMT  */
#line 1811 "src/parser.y"
                { (yyval.sval) = strdup("DATFMT"); }
#line 5938 "build/parser.cpp"
    break;

  case 311: /* ident: KW_TIMFMT  */
#line 1812 "src/parser.y"
                { (yyval.sval) = strdup("TIMFMT"); }
#line 5944 "build/parser.cpp"
    break;

  case 312: /* ident: KW_EXTNAME  */
#line 1813 "src/parser.y"
                 { (yyval.sval) = strdup("EXTNAME"); }
#line 5950 "build/parser.cpp"
    break;

  case 313: /* ident: KW_OVERLAY  */
#line 1814 "src/parser.y"
                 { (yyval.sval) = strdup("OVERLAY"); }
#line 5956 "build/parser.cpp"
    break;

  case 314: /* ident: KW_POS  */
#line 1815 "src/parser.y"
             { (yyval.sval) = strdup("POS"); }
#line 5962 "build/parser.cpp"
    break;

  case 315: /* ident: KW_PREFIX  */
#line 1816 "src/parser.y"
                { (yyval.sval) = strdup("PREFIX"); }
#line 5968 "build/parser.cpp"
    break;

  case 316: /* primary_expr: IDENTIFIER  */
#line 1820 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier((yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 5977 "build/parser.cpp"
    break;

  case 317: /* primary_expr: KW_UNS  */
#line 1824 "src/parser.y"
             { (yyval.expr) = new rpg::Identifier("UNS"); }
#line 5983 "build/parser.cpp"
    break;

  case 318: /* primary_expr: KW_FLOAT_TYPE  */
#line 1825 "src/parser.y"
                    { (yyval.expr) = new rpg::Identifier("FLOAT"); }
#line 5989 "build/parser.cpp"
    break;

  case 319: /* primary_expr: KW_GRAPH  */
#line 1826 "src/parser.y"
               { (yyval.expr) = new rpg::Identifier("GRAPH"); }
#line 5995 "build/parser.cpp"
    break;

  case 320: /* primary_expr: KW_ASCEND  */
#line 1827 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("ASCEND"); }
#line 6001 "build/parser.cpp"
    break;

  case 321: /* primary_expr: KW_DESCEND  */
#line 1828 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("DESCEND"); }
#line 6007 "build/parser.cpp"
    break;

  case 322: /* primary_expr: KW_RTNPARM  */
#line 1829 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("RTNPARM"); }
#line 6013 "build/parser.cpp"
    break;

  case 323: /* primary_expr: KW_OPDESC  */
#line 1830 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("OPDESC"); }
#line 6019 "build/parser.cpp"
    break;

  case 324: /* primary_expr: KW_NULLIND  */
#line 1831 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("NULLIND"); }
#line 6025 "build/parser.cpp"
    break;

  case 325: /* primary_expr: KW_DATFMT  */
#line 1832 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("DATFMT"); }
#line 6031 "build/parser.cpp"
    break;

  case 326: /* primary_expr: KW_OVERLAY  */
#line 1833 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("OVERLAY"); }
#line 6037 "build/parser.cpp"
    break;

  case 327: /* primary_expr: KW_POS  */
#line 1834 "src/parser.y"
             { (yyval.expr) = new rpg::Identifier("POS"); }
#line 6043 "build/parser.cpp"
    break;

  case 328: /* primary_expr: KW_PREFIX  */
#line 1835 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("PREFIX"); }
#line 6049 "build/parser.cpp"
    break;

  case 329: /* primary_expr: KW_TIMFMT  */
#line 1836 "src/parser.y"
                { (yyval.expr) = new rpg::Identifier("TIMFMT"); }
#line 6055 "build/parser.cpp"
    break;

  case 330: /* primary_expr: KW_EXTNAME  */
#line 1837 "src/parser.y"
                 { (yyval.expr) = new rpg::Identifier("EXTNAME"); }
#line 6061 "build/parser.cpp"
    break;

  case 331: /* primary_expr: INTEGER_LITERAL  */
#line 1838 "src/parser.y"
                      {
        (yyval.expr) = new rpg::IntLiteral((yyvsp[0].ival));
    }
#line 6069 "build/parser.cpp"
    break;

  case 332: /* primary_expr: FLOAT_LITERAL  */
#line 1841 "src/parser.y"
                    {
        (yyval.expr) = new rpg::FloatLiteral((yyvsp[0].fval));
    }
#line 6077 "build/parser.cpp"
    break;

  case 333: /* primary_expr: STRING_LITERAL  */
#line 1844 "src/parser.y"
                     {
        (yyval.expr) = new rpg::StringLiteral((yyvsp[0].sval));
        free((yyvsp[0].sval));
    }
#line 6086 "build/parser.cpp"
    break;

  case 334: /* primary_expr: IDENTIFIER LPAREN call_args_opt RPAREN  */
#line 1848 "src/parser.y"
                                             {
        (yyval.expr) = make_func((yyvsp[-3].sval), (yyvsp[-1].expr_list));
        free((yyvsp[-3].sval));
    }
#line 6095 "build/parser.cpp"
    break;

  case 335: /* primary_expr: BIF_CHAR LPAREN arg_list RPAREN  */
#line 1852 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("CHAR", (yyvsp[-1].expr_list));
    }
#line 6103 "build/parser.cpp"
    break;

  case 336: /* primary_expr: BIF_TRIM LPAREN arg_list RPAREN  */
#line 1855 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("TRIM", (yyvsp[-1].expr_list));
    }
#line 6111 "build/parser.cpp"
    break;

  case 337: /* primary_expr: BIF_TRIML LPAREN arg_list RPAREN  */
#line 1858 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("TRIML", (yyvsp[-1].expr_list));
    }
#line 6119 "build/parser.cpp"
    break;

  case 338: /* primary_expr: BIF_TRIMR LPAREN arg_list RPAREN  */
#line 1861 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("TRIMR", (yyvsp[-1].expr_list));
    }
#line 6127 "build/parser.cpp"
    break;

  case 339: /* primary_expr: BIF_LEN LPAREN arg_list RPAREN  */
#line 1864 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("LEN", (yyvsp[-1].expr_list));
    }
#line 6135 "build/parser.cpp"
    break;

  case 340: /* primary_expr: BIF_SUBST LPAREN arg_list RPAREN  */
#line 1867 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("SUBST", (yyvsp[-1].expr_list));
    }
#line 6143 "build/parser.cpp"
    break;

  case 341: /* primary_expr: BIF_SCAN LPAREN arg_list RPAREN  */
#line 1870 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("SCAN", (yyvsp[-1].expr_list));
    }
#line 6151 "build/parser.cpp"
    break;

  case 342: /* primary_expr: BIF_SCANRPL LPAREN arg_list RPAREN  */
#line 1873 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("SCANRPL", (yyvsp[-1].expr_list));
    }
#line 6159 "build/parser.cpp"
    break;

  case 343: /* primary_expr: BIF_XLATE LPAREN arg_list RPAREN  */
#line 1876 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("XLATE", (yyvsp[-1].expr_list));
    }
#line 6167 "build/parser.cpp"
    break;

  case 344: /* primary_expr: BIF_DEC LPAREN arg_list RPAREN  */
#line 1879 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("DEC", (yyvsp[-1].expr_list));
    }
#line 6175 "build/parser.cpp"
    break;

  case 345: /* primary_expr: BIF_INT LPAREN arg_list RPAREN  */
#line 1882 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("INT", (yyvsp[-1].expr_list));
    }
#line 6183 "build/parser.cpp"
    break;

  case 346: /* primary_expr: BIF_ELEM LPAREN arg_list RPAREN  */
#line 1885 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("ELEM", (yyvsp[-1].expr_list));
    }
#line 6191 "build/parser.cpp"
    break;

  case 347: /* primary_expr: BIF_PARMS LPAREN RPAREN  */
#line 1888 "src/parser.y"
                              {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("PARMS", empty);
    }
#line 6200 "build/parser.cpp"
    break;

  case 348: /* primary_expr: BIF_LOOKUP LPAREN arg_list RPAREN  */
#line 1892 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("LOOKUP", (yyvsp[-1].expr_list));
    }
#line 6208 "build/parser.cpp"
    break;

  case 349: /* primary_expr: BIF_EDITC LPAREN arg_list RPAREN  */
#line 1895 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("EDITC", (yyvsp[-1].expr_list));
    }
#line 6216 "build/parser.cpp"
    break;

  case 350: /* primary_expr: BIF_EDITW LPAREN arg_list RPAREN  */
#line 1898 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("EDITW", (yyvsp[-1].expr_list));
    }
#line 6224 "build/parser.cpp"
    break;

  case 351: /* primary_expr: BIF_REPLACE LPAREN arg_list RPAREN  */
#line 1901 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("REPLACE", (yyvsp[-1].expr_list));
    }
#line 6232 "build/parser.cpp"
    break;

  case 352: /* primary_expr: BIF_CHECK LPAREN arg_list RPAREN  */
#line 1904 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("CHECK", (yyvsp[-1].expr_list));
    }
#line 6240 "build/parser.cpp"
    break;

  case 353: /* primary_expr: BIF_CHECKR LPAREN arg_list RPAREN  */
#line 1907 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("CHECKR", (yyvsp[-1].expr_list));
    }
#line 6248 "build/parser.cpp"
    break;

  case 354: /* primary_expr: BIF_LOWER LPAREN arg_list RPAREN  */
#line 1910 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("LOWER", (yyvsp[-1].expr_list));
    }
#line 6256 "build/parser.cpp"
    break;

  case 355: /* primary_expr: BIF_UPPER LPAREN arg_list RPAREN  */
#line 1913 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("UPPER", (yyvsp[-1].expr_list));
    }
#line 6264 "build/parser.cpp"
    break;

  case 356: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_YEARS RPAREN  */
#line 1916 "src/parser.y"
                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("YEARS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6275 "build/parser.cpp"
    break;

  case 357: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_MONTHS RPAREN  */
#line 1922 "src/parser.y"
                                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MONTHS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6286 "build/parser.cpp"
    break;

  case 358: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_DAYS RPAREN  */
#line 1928 "src/parser.y"
                                                       {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("DAYS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6297 "build/parser.cpp"
    break;

  case 359: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_HOURS RPAREN  */
#line 1934 "src/parser.y"
                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("HOURS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6308 "build/parser.cpp"
    break;

  case 360: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_MINUTES RPAREN  */
#line 1940 "src/parser.y"
                                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MINUTES"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6319 "build/parser.cpp"
    break;

  case 361: /* primary_expr: BIF_SUBDT LPAREN expression COLON KW_SECONDS RPAREN  */
#line 1946 "src/parser.y"
                                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("SECONDS"));
        (yyval.expr) = make_bif("SUBDT", args);
    }
#line 6330 "build/parser.cpp"
    break;

  case 362: /* primary_expr: BIF_FLOAT LPAREN arg_list RPAREN  */
#line 1952 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("FLOAT", (yyvsp[-1].expr_list));
    }
#line 6338 "build/parser.cpp"
    break;

  case 363: /* primary_expr: BIF_SQRT LPAREN arg_list RPAREN  */
#line 1955 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("SQRT", (yyvsp[-1].expr_list));
    }
#line 6346 "build/parser.cpp"
    break;

  case 364: /* primary_expr: BIF_MAX LPAREN arg_list RPAREN  */
#line 1958 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("MAX", (yyvsp[-1].expr_list));
    }
#line 6354 "build/parser.cpp"
    break;

  case 365: /* primary_expr: BIF_MIN LPAREN arg_list RPAREN  */
#line 1961 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("MIN", (yyvsp[-1].expr_list));
    }
#line 6362 "build/parser.cpp"
    break;

  case 366: /* primary_expr: BIF_STATUS LPAREN RPAREN  */
#line 1964 "src/parser.y"
                               {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("STATUS", empty);
    }
#line 6371 "build/parser.cpp"
    break;

  case 367: /* primary_expr: BIF_ERROR LPAREN RPAREN  */
#line 1968 "src/parser.y"
                              {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("ERROR", empty);
    }
#line 6380 "build/parser.cpp"
    break;

  case 368: /* primary_expr: BIF_SIZE LPAREN arg_list RPAREN  */
#line 1972 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("SIZE", (yyvsp[-1].expr_list));
    }
#line 6388 "build/parser.cpp"
    break;

  case 369: /* primary_expr: BIF_ADDR LPAREN arg_list RPAREN  */
#line 1975 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("ADDR", (yyvsp[-1].expr_list));
    }
#line 6396 "build/parser.cpp"
    break;

  case 370: /* primary_expr: BIF_ABS LPAREN arg_list RPAREN  */
#line 1978 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("ABS", (yyvsp[-1].expr_list));
    }
#line 6404 "build/parser.cpp"
    break;

  case 371: /* primary_expr: BIF_DIV LPAREN arg_list RPAREN  */
#line 1981 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("DIV", (yyvsp[-1].expr_list));
    }
#line 6412 "build/parser.cpp"
    break;

  case 372: /* primary_expr: BIF_REM LPAREN arg_list RPAREN  */
#line 1984 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("REM", (yyvsp[-1].expr_list));
    }
#line 6420 "build/parser.cpp"
    break;

  case 373: /* primary_expr: BIF_DATE LPAREN arg_list RPAREN  */
#line 1987 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("DATE", (yyvsp[-1].expr_list));
    }
#line 6428 "build/parser.cpp"
    break;

  case 374: /* primary_expr: BIF_DATE LPAREN RPAREN  */
#line 1990 "src/parser.y"
                             {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("DATE", empty);
    }
#line 6437 "build/parser.cpp"
    break;

  case 375: /* primary_expr: BIF_TIME LPAREN arg_list RPAREN  */
#line 1994 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("TIME", (yyvsp[-1].expr_list));
    }
#line 6445 "build/parser.cpp"
    break;

  case 376: /* primary_expr: BIF_TIME LPAREN RPAREN  */
#line 1997 "src/parser.y"
                             {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("TIME", empty);
    }
#line 6454 "build/parser.cpp"
    break;

  case 377: /* primary_expr: BIF_TIMESTAMP LPAREN arg_list RPAREN  */
#line 2001 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TIMESTAMP", (yyvsp[-1].expr_list));
    }
#line 6462 "build/parser.cpp"
    break;

  case 378: /* primary_expr: BIF_TIMESTAMP LPAREN RPAREN  */
#line 2004 "src/parser.y"
                                  {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("TIMESTAMP", empty);
    }
#line 6471 "build/parser.cpp"
    break;

  case 379: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_DAYS RPAREN  */
#line 2008 "src/parser.y"
                                                                       {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("DAYS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 6483 "build/parser.cpp"
    break;

  case 380: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_MONTHS RPAREN  */
#line 2015 "src/parser.y"
                                                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MONTHS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 6495 "build/parser.cpp"
    break;

  case 381: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_YEARS RPAREN  */
#line 2022 "src/parser.y"
                                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("YEARS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 6507 "build/parser.cpp"
    break;

  case 382: /* primary_expr: BIF_DAYS LPAREN expression RPAREN  */
#line 2029 "src/parser.y"
                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("DAYS", args);
    }
#line 6517 "build/parser.cpp"
    break;

  case 383: /* primary_expr: BIF_MONTHS LPAREN expression RPAREN  */
#line 2034 "src/parser.y"
                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("MONTHS", args);
    }
#line 6527 "build/parser.cpp"
    break;

  case 384: /* primary_expr: BIF_YEARS LPAREN expression RPAREN  */
#line 2039 "src/parser.y"
                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("YEARS", args);
    }
#line 6537 "build/parser.cpp"
    break;

  case 385: /* primary_expr: BIF_FOUND LPAREN RPAREN  */
#line 2044 "src/parser.y"
                              {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("FOUND", empty);
    }
#line 6546 "build/parser.cpp"
    break;

  case 386: /* primary_expr: BIF_EOF LPAREN RPAREN  */
#line 2048 "src/parser.y"
                            {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("EOF", empty);
    }
#line 6555 "build/parser.cpp"
    break;

  case 387: /* primary_expr: BIF_ALLOC LPAREN arg_list RPAREN  */
#line 2052 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("ALLOC", (yyvsp[-1].expr_list));
    }
#line 6563 "build/parser.cpp"
    break;

  case 388: /* primary_expr: BIF_REALLOC LPAREN arg_list RPAREN  */
#line 2055 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("REALLOC", (yyvsp[-1].expr_list));
    }
#line 6571 "build/parser.cpp"
    break;

  case 389: /* primary_expr: BIF_XFOOT LPAREN arg_list RPAREN  */
#line 2058 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("XFOOT", (yyvsp[-1].expr_list));
    }
#line 6579 "build/parser.cpp"
    break;

  case 390: /* primary_expr: BIF_UNS LPAREN arg_list RPAREN  */
#line 2061 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("UNS", (yyvsp[-1].expr_list));
    }
#line 6587 "build/parser.cpp"
    break;

  case 391: /* primary_expr: BIF_INTH LPAREN arg_list RPAREN  */
#line 2064 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("INTH", (yyvsp[-1].expr_list));
    }
#line 6595 "build/parser.cpp"
    break;

  case 392: /* primary_expr: BIF_DECH LPAREN arg_list RPAREN  */
#line 2067 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("DECH", (yyvsp[-1].expr_list));
    }
#line 6603 "build/parser.cpp"
    break;

  case 393: /* primary_expr: BIF_DECPOS LPAREN arg_list RPAREN  */
#line 2070 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("DECPOS", (yyvsp[-1].expr_list));
    }
#line 6611 "build/parser.cpp"
    break;

  case 394: /* primary_expr: BIF_SPLIT LPAREN arg_list RPAREN  */
#line 2073 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("SPLIT", (yyvsp[-1].expr_list));
    }
#line 6619 "build/parser.cpp"
    break;

  case 395: /* primary_expr: BIF_CONCAT LPAREN arg_list RPAREN  */
#line 2076 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("CONCAT", (yyvsp[-1].expr_list));
    }
#line 6627 "build/parser.cpp"
    break;

  case 396: /* primary_expr: BIF_CONCATARR LPAREN arg_list RPAREN  */
#line 2079 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("CONCATARR", (yyvsp[-1].expr_list));
    }
#line 6635 "build/parser.cpp"
    break;

  case 397: /* primary_expr: BIF_LEFT LPAREN arg_list RPAREN  */
#line 2082 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("LEFT", (yyvsp[-1].expr_list));
    }
#line 6643 "build/parser.cpp"
    break;

  case 398: /* primary_expr: BIF_RIGHT LPAREN arg_list RPAREN  */
#line 2085 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("RIGHT", (yyvsp[-1].expr_list));
    }
#line 6651 "build/parser.cpp"
    break;

  case 399: /* primary_expr: BIF_STR LPAREN arg_list RPAREN  */
#line 2088 "src/parser.y"
                                     {
        (yyval.expr) = make_bif("STR", (yyvsp[-1].expr_list));
    }
#line 6659 "build/parser.cpp"
    break;

  case 400: /* primary_expr: BIF_SUBARR LPAREN arg_list RPAREN  */
#line 2091 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("SUBARR", (yyvsp[-1].expr_list));
    }
#line 6667 "build/parser.cpp"
    break;

  case 401: /* primary_expr: BIF_MAXARR LPAREN arg_list RPAREN  */
#line 2094 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("MAXARR", (yyvsp[-1].expr_list));
    }
#line 6675 "build/parser.cpp"
    break;

  case 402: /* primary_expr: BIF_MINARR LPAREN arg_list RPAREN  */
#line 2097 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("MINARR", (yyvsp[-1].expr_list));
    }
#line 6683 "build/parser.cpp"
    break;

  case 403: /* primary_expr: BIF_LIST LPAREN arg_list RPAREN  */
#line 2100 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("LIST", (yyvsp[-1].expr_list));
    }
#line 6691 "build/parser.cpp"
    break;

  case 404: /* primary_expr: BIF_RANGE LPAREN arg_list RPAREN  */
#line 2103 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("RANGE", (yyvsp[-1].expr_list));
    }
#line 6699 "build/parser.cpp"
    break;

  case 405: /* primary_expr: BIF_LOOKUPLT LPAREN arg_list RPAREN  */
#line 2106 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPLT", (yyvsp[-1].expr_list));
    }
#line 6707 "build/parser.cpp"
    break;

  case 406: /* primary_expr: BIF_LOOKUPGE LPAREN arg_list RPAREN  */
#line 2109 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPGE", (yyvsp[-1].expr_list));
    }
#line 6715 "build/parser.cpp"
    break;

  case 407: /* primary_expr: BIF_LOOKUPLE LPAREN arg_list RPAREN  */
#line 2112 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPLE", (yyvsp[-1].expr_list));
    }
#line 6723 "build/parser.cpp"
    break;

  case 408: /* primary_expr: BIF_LOOKUPGT LPAREN arg_list RPAREN  */
#line 2115 "src/parser.y"
                                          {
        (yyval.expr) = make_bif("LOOKUPGT", (yyvsp[-1].expr_list));
    }
#line 6731 "build/parser.cpp"
    break;

  case 409: /* primary_expr: BIF_TLOOKUP LPAREN arg_list RPAREN  */
#line 2118 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("TLOOKUP", (yyvsp[-1].expr_list));
    }
#line 6739 "build/parser.cpp"
    break;

  case 410: /* primary_expr: BIF_TLOOKUPLT LPAREN arg_list RPAREN  */
#line 2121 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TLOOKUPLT", (yyvsp[-1].expr_list));
    }
#line 6747 "build/parser.cpp"
    break;

  case 411: /* primary_expr: BIF_TLOOKUPGT LPAREN arg_list RPAREN  */
#line 2124 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TLOOKUPGT", (yyvsp[-1].expr_list));
    }
#line 6755 "build/parser.cpp"
    break;

  case 412: /* primary_expr: BIF_TLOOKUPLE LPAREN arg_list RPAREN  */
#line 2127 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TLOOKUPLE", (yyvsp[-1].expr_list));
    }
#line 6763 "build/parser.cpp"
    break;

  case 413: /* primary_expr: BIF_TLOOKUPGE LPAREN arg_list RPAREN  */
#line 2130 "src/parser.y"
                                           {
        (yyval.expr) = make_bif("TLOOKUPGE", (yyvsp[-1].expr_list));
    }
#line 6771 "build/parser.cpp"
    break;

  case 414: /* primary_expr: BIF_HOURS LPAREN expression RPAREN  */
#line 2133 "src/parser.y"
                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("HOURS", args);
    }
#line 6781 "build/parser.cpp"
    break;

  case 415: /* primary_expr: BIF_MINUTES LPAREN expression RPAREN  */
#line 2138 "src/parser.y"
                                           {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("MINUTES", args);
    }
#line 6791 "build/parser.cpp"
    break;

  case 416: /* primary_expr: BIF_SECONDS LPAREN expression RPAREN  */
#line 2143 "src/parser.y"
                                           {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("SECONDS", args);
    }
#line 6801 "build/parser.cpp"
    break;

  case 417: /* primary_expr: BIF_MSECONDS LPAREN expression RPAREN  */
#line 2148 "src/parser.y"
                                            {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-1].expr));
        (yyval.expr) = make_bif("MSECONDS", args);
    }
#line 6811 "build/parser.cpp"
    break;

  case 418: /* primary_expr: BIF_PADDR LPAREN IDENTIFIER RPAREN  */
#line 2153 "src/parser.y"
                                         {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::StringLiteral((yyvsp[-1].sval)));
        free((yyvsp[-1].sval));
        (yyval.expr) = make_bif("PADDR", args);
    }
#line 6822 "build/parser.cpp"
    break;

  case 419: /* primary_expr: BIF_PROC LPAREN RPAREN  */
#line 2159 "src/parser.y"
                             {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("PROC", empty);
    }
#line 6831 "build/parser.cpp"
    break;

  case 420: /* primary_expr: BIF_PROC  */
#line 2163 "src/parser.y"
               {
        auto* empty = new std::vector<rpg::Expression*>();
        (yyval.expr) = make_bif("PROC", empty);
    }
#line 6840 "build/parser.cpp"
    break;

  case 421: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_HOURS RPAREN  */
#line 2167 "src/parser.y"
                                                                        {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("HOURS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 6852 "build/parser.cpp"
    break;

  case 422: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_MINUTES RPAREN  */
#line 2174 "src/parser.y"
                                                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("MINUTES"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 6864 "build/parser.cpp"
    break;

  case 423: /* primary_expr: BIF_DIFF LPAREN expression COLON expression COLON KW_SECONDS RPAREN  */
#line 2181 "src/parser.y"
                                                                          {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back((yyvsp[-5].expr));
        args->push_back((yyvsp[-3].expr));
        args->push_back(new rpg::StringLiteral("SECONDS"));
        (yyval.expr) = make_bif("DIFF", args);
    }
#line 6876 "build/parser.cpp"
    break;

  case 424: /* primary_expr: KW_ALL STRING_LITERAL  */
#line 2188 "src/parser.y"
                            {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::StringLiteral((yyvsp[0].sval)));
        free((yyvsp[0].sval));
        (yyval.expr) = make_bif("ALL", args);
    }
#line 6887 "build/parser.cpp"
    break;

  case 425: /* primary_expr: BIF_PASSED LPAREN ident RPAREN  */
#line 2194 "src/parser.y"
                                     {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::Identifier((yyvsp[-1].sval)));
        free((yyvsp[-1].sval));
        (yyval.expr) = make_bif("PASSED", args);
    }
#line 6898 "build/parser.cpp"
    break;

  case 426: /* primary_expr: BIF_OMITTED LPAREN ident RPAREN  */
#line 2200 "src/parser.y"
                                      {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::Identifier((yyvsp[-1].sval)));
        free((yyvsp[-1].sval));
        (yyval.expr) = make_bif("OMITTED", args);
    }
#line 6909 "build/parser.cpp"
    break;

  case 427: /* primary_expr: BIF_BITAND LPAREN arg_list RPAREN  */
#line 2206 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("BITAND", (yyvsp[-1].expr_list));
    }
#line 6917 "build/parser.cpp"
    break;

  case 428: /* primary_expr: BIF_BITNOT LPAREN arg_list RPAREN  */
#line 2209 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("BITNOT", (yyvsp[-1].expr_list));
    }
#line 6925 "build/parser.cpp"
    break;

  case 429: /* primary_expr: BIF_BITOR LPAREN arg_list RPAREN  */
#line 2212 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("BITOR", (yyvsp[-1].expr_list));
    }
#line 6933 "build/parser.cpp"
    break;

  case 430: /* primary_expr: BIF_BITXOR LPAREN arg_list RPAREN  */
#line 2215 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("BITXOR", (yyvsp[-1].expr_list));
    }
#line 6941 "build/parser.cpp"
    break;

  case 431: /* primary_expr: BIF_SCANR LPAREN arg_list RPAREN  */
#line 2218 "src/parser.y"
                                       {
        (yyval.expr) = make_bif("SCANR", (yyvsp[-1].expr_list));
    }
#line 6949 "build/parser.cpp"
    break;

  case 432: /* primary_expr: BIF_EDITFLT LPAREN arg_list RPAREN  */
#line 2221 "src/parser.y"
                                         {
        (yyval.expr) = make_bif("EDITFLT", (yyvsp[-1].expr_list));
    }
#line 6957 "build/parser.cpp"
    break;

  case 433: /* primary_expr: BIF_UNSH LPAREN arg_list RPAREN  */
#line 2224 "src/parser.y"
                                      {
        (yyval.expr) = make_bif("UNSH", (yyvsp[-1].expr_list));
    }
#line 6965 "build/parser.cpp"
    break;

  case 434: /* primary_expr: BIF_PARMNUM LPAREN ident RPAREN  */
#line 2227 "src/parser.y"
                                      {
        auto* args = new std::vector<rpg::Expression*>();
        args->push_back(new rpg::Identifier((yyvsp[-1].sval)));
        free((yyvsp[-1].sval));
        (yyval.expr) = make_bif("PARMNUM", args);
    }
#line 6976 "build/parser.cpp"
    break;

  case 435: /* primary_expr: BIF_GETENV LPAREN arg_list RPAREN  */
#line 2233 "src/parser.y"
                                        {
        (yyval.expr) = make_bif("GETENV", (yyvsp[-1].expr_list));
    }
#line 6984 "build/parser.cpp"
    break;

  case 436: /* primary_expr: INDICATOR  */
#line 2236 "src/parser.y"
                {
        (yyval.expr) = new rpg::IndicatorExpr((yyvsp[0].ival));
    }
#line 6992 "build/parser.cpp"
    break;

  case 437: /* primary_expr: KW_ON  */
#line 2239 "src/parser.y"
            {
        (yyval.expr) = new rpg::IntLiteral(1);  // *ON → true
    }
#line 7000 "build/parser.cpp"
    break;

  case 438: /* primary_expr: KW_OFF  */
#line 2242 "src/parser.y"
             {
        (yyval.expr) = new rpg::IntLiteral(0);  // *OFF → false
    }
#line 7008 "build/parser.cpp"
    break;

  case 439: /* primary_expr: KW_NULL  */
#line 2245 "src/parser.y"
              {
        (yyval.expr) = new rpg::Identifier("nullptr");
    }
#line 7016 "build/parser.cpp"
    break;

  case 440: /* primary_expr: KW_OMIT  */
#line 2248 "src/parser.y"
              {
        (yyval.expr) = new rpg::Identifier("nullptr");
    }
#line 7024 "build/parser.cpp"
    break;

  case 441: /* primary_expr: KW_BLANKS  */
#line 2251 "src/parser.y"
                {
        (yyval.expr) = new rpg::Identifier("RPG_BLANKS");
    }
#line 7032 "build/parser.cpp"
    break;

  case 442: /* primary_expr: KW_ZEROS  */
#line 2254 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier("RPG_ZEROS");
    }
#line 7040 "build/parser.cpp"
    break;

  case 443: /* primary_expr: KW_HIVAL  */
#line 2257 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier("RPG_HIVAL");
    }
#line 7048 "build/parser.cpp"
    break;

  case 444: /* primary_expr: KW_LOVAL  */
#line 2260 "src/parser.y"
               {
        (yyval.expr) = new rpg::Identifier("RPG_LOVAL");
    }
#line 7056 "build/parser.cpp"
    break;

  case 445: /* primary_expr: LPAREN expression RPAREN  */
#line 2263 "src/parser.y"
                               {
        (yyval.expr) = (yyvsp[-1].expr);
    }
#line 7064 "build/parser.cpp"
    break;

  case 446: /* call_args_opt: %empty  */
#line 2270 "src/parser.y"
                { (yyval.expr_list) = nullptr; }
#line 7070 "build/parser.cpp"
    break;

  case 447: /* call_args_opt: call_arg_list  */
#line 2271 "src/parser.y"
                    { (yyval.expr_list) = (yyvsp[0].expr_list); }
#line 7076 "build/parser.cpp"
    break;

  case 448: /* call_arg_list: expression  */
#line 2275 "src/parser.y"
               {
        (yyval.expr_list) = new std::vector<rpg::Expression*>();
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 7085 "build/parser.cpp"
    break;

  case 449: /* call_arg_list: call_arg_list COLON expression  */
#line 2279 "src/parser.y"
                                     {
        (yyval.expr_list) = (yyvsp[-2].expr_list);
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 7094 "build/parser.cpp"
    break;

  case 450: /* arg_list: expression  */
#line 2287 "src/parser.y"
               {
        (yyval.expr_list) = new std::vector<rpg::Expression*>();
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 7103 "build/parser.cpp"
    break;

  case 451: /* arg_list: arg_list COLON expression  */
#line 2291 "src/parser.y"
                                {
        (yyval.expr_list) = (yyvsp[-2].expr_list);
        (yyval.expr_list)->push_back((yyvsp[0].expr));
    }
#line 7112 "build/parser.cpp"
    break;


#line 7116 "build/parser.cpp"

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

#line 2297 "src/parser.y"


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
