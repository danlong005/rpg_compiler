/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_BUILD_PARSER_H_INCLUDED
# define YY_YY_BUILD_PARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "src/parser.y"

#include <memory>
#include <vector>
#include <string>
#include "ast.h"

struct StmtList {
    std::vector<rpg::Statement*> stmts;
};

struct ElseIfData {
    rpg::Expression* cond;
    std::vector<rpg::Statement*> body;
};

struct WhenData {
    rpg::Expression* cond;
    std::vector<rpg::Statement*> body;
};

struct ParamList {
    std::vector<rpg::ParamDecl> params;
};

struct DSFieldList {
    std::vector<rpg::DSField> fields;
};

#line 78 "build/parser.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    KW_FREE = 258,                 /* KW_FREE  */
    KW_DCL_S = 259,                /* KW_DCL_S  */
    KW_DCL_C = 260,                /* KW_DCL_C  */
    KW_CHAR = 261,                 /* KW_CHAR  */
    KW_VARCHAR = 262,              /* KW_VARCHAR  */
    KW_INT = 263,                  /* KW_INT  */
    KW_PACKED = 264,               /* KW_PACKED  */
    KW_ZONED = 265,                /* KW_ZONED  */
    KW_DATE = 266,                 /* KW_DATE  */
    KW_TIME = 267,                 /* KW_TIME  */
    KW_TIMESTAMP = 268,            /* KW_TIMESTAMP  */
    KW_DAYS = 269,                 /* KW_DAYS  */
    KW_MONTHS = 270,               /* KW_MONTHS  */
    KW_YEARS = 271,                /* KW_YEARS  */
    KW_CONST = 272,                /* KW_CONST  */
    KW_INZ = 273,                  /* KW_INZ  */
    KW_DSPLY = 274,                /* KW_DSPLY  */
    KW_EVAL = 275,                 /* KW_EVAL  */
    KW_RETURN = 276,               /* KW_RETURN  */
    KW_INLR = 277,                 /* KW_INLR  */
    KW_ON = 278,                   /* KW_ON  */
    KW_IF = 279,                   /* KW_IF  */
    KW_ELSEIF = 280,               /* KW_ELSEIF  */
    KW_ELSE = 281,                 /* KW_ELSE  */
    KW_ENDIF = 282,                /* KW_ENDIF  */
    KW_DOW = 283,                  /* KW_DOW  */
    KW_DOU = 284,                  /* KW_DOU  */
    KW_ENDDO = 285,                /* KW_ENDDO  */
    KW_FOR = 286,                  /* KW_FOR  */
    KW_ENDFOR = 287,               /* KW_ENDFOR  */
    KW_TO = 288,                   /* KW_TO  */
    KW_DOWNTO = 289,               /* KW_DOWNTO  */
    KW_BY = 290,                   /* KW_BY  */
    KW_SELECT = 291,               /* KW_SELECT  */
    KW_WHEN = 292,                 /* KW_WHEN  */
    KW_OTHER = 293,                /* KW_OTHER  */
    KW_ENDSL = 294,                /* KW_ENDSL  */
    KW_ITER = 295,                 /* KW_ITER  */
    KW_LEAVE = 296,                /* KW_LEAVE  */
    KW_MONITOR = 297,              /* KW_MONITOR  */
    KW_ON_ERROR = 298,             /* KW_ON_ERROR  */
    KW_ENDMON = 299,               /* KW_ENDMON  */
    KW_BEGSR = 300,                /* KW_BEGSR  */
    KW_ENDSR = 301,                /* KW_ENDSR  */
    KW_EXSR = 302,                 /* KW_EXSR  */
    KW_OFF = 303,                  /* KW_OFF  */
    INDICATOR = 304,               /* INDICATOR  */
    KW_AND = 305,                  /* KW_AND  */
    KW_OR = 306,                   /* KW_OR  */
    KW_NOT = 307,                  /* KW_NOT  */
    KW_DCL_PROC = 308,             /* KW_DCL_PROC  */
    KW_END_PROC = 309,             /* KW_END_PROC  */
    KW_DCL_PI = 310,               /* KW_DCL_PI  */
    KW_END_PI = 311,               /* KW_END_PI  */
    KW_DCL_PR = 312,               /* KW_DCL_PR  */
    KW_END_PR = 313,               /* KW_END_PR  */
    KW_VALUE = 314,                /* KW_VALUE  */
    KW_DCL_DS = 315,               /* KW_DCL_DS  */
    KW_END_DS = 316,               /* KW_END_DS  */
    KW_QUALIFIED = 317,            /* KW_QUALIFIED  */
    KW_DIM = 318,                  /* KW_DIM  */
    KW_LIKEDS = 319,               /* KW_LIKEDS  */
    DOT = 320,                     /* DOT  */
    BIF_CHAR = 321,                /* BIF_CHAR  */
    BIF_TRIM = 322,                /* BIF_TRIM  */
    BIF_TRIML = 323,               /* BIF_TRIML  */
    BIF_TRIMR = 324,               /* BIF_TRIMR  */
    BIF_LEN = 325,                 /* BIF_LEN  */
    BIF_SUBST = 326,               /* BIF_SUBST  */
    BIF_SCAN = 327,                /* BIF_SCAN  */
    BIF_SCANRPL = 328,             /* BIF_SCANRPL  */
    BIF_XLATE = 329,               /* BIF_XLATE  */
    BIF_DEC = 330,                 /* BIF_DEC  */
    BIF_INT = 331,                 /* BIF_INT  */
    BIF_ELEM = 332,                /* BIF_ELEM  */
    BIF_FOUND = 333,               /* BIF_FOUND  */
    BIF_EOF = 334,                 /* BIF_EOF  */
    BIF_DATE = 335,                /* BIF_DATE  */
    BIF_TIME = 336,                /* BIF_TIME  */
    BIF_TIMESTAMP = 337,           /* BIF_TIMESTAMP  */
    BIF_DIFF = 338,                /* BIF_DIFF  */
    BIF_DAYS = 339,                /* BIF_DAYS  */
    BIF_MONTHS = 340,              /* BIF_MONTHS  */
    BIF_YEARS = 341,               /* BIF_YEARS  */
    IDENTIFIER = 342,              /* IDENTIFIER  */
    INTEGER_LITERAL = 343,         /* INTEGER_LITERAL  */
    FLOAT_LITERAL = 344,           /* FLOAT_LITERAL  */
    STRING_LITERAL = 345,          /* STRING_LITERAL  */
    SEMICOLON = 346,               /* SEMICOLON  */
    EQUALS = 347,                  /* EQUALS  */
    LPAREN = 348,                  /* LPAREN  */
    RPAREN = 349,                  /* RPAREN  */
    COLON = 350,                   /* COLON  */
    PLUS = 351,                    /* PLUS  */
    MINUS = 352,                   /* MINUS  */
    STAR = 353,                    /* STAR  */
    SLASH = 354,                   /* SLASH  */
    NE = 355,                      /* NE  */
    LE = 356,                      /* LE  */
    GE = 357,                      /* GE  */
    LT = 358,                      /* LT  */
    GT = 359                       /* GT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 74 "src/parser.y"

    int ival;
    double fval;
    char* sval;
    rpg::Expression* expr;
    rpg::Statement* stmt;
    rpg::Program* program;
    std::vector<rpg::Expression*>* expr_list;
    StmtList* stmt_list;
    std::vector<ElseIfData*>* elseif_list;
    ElseIfData* elseif_data;
    std::vector<WhenData*>* when_list;
    WhenData* when_data;
    ParamList* param_list;
    rpg::ParamDecl* param_decl;
    DSFieldList* ds_field_list;
    rpg::DSField* ds_field;

#line 218 "build/parser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_BUILD_PARSER_H_INCLUDED  */
