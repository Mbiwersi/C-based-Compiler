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
#line 1 "ExprEval.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SymTab.h"
#include "IOMngr.h"
#include "Semantics.h"
#include "CodeGen.h"

extern int yylex();	/* The next token function. */
extern char *yytext;   /* The matched token text.  */
extern int yyleng;      /* The token text length.   */
extern int yyparse();
void dumpTable();

extern SymTab *table;
extern SymTab *stringTable;
extern SymTab *arrayTable;



#line 93 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    Ident = 258,                   /* Ident  */
    IntLit = 259,                  /* IntLit  */
    Int = 260,                     /* Int  */
    BoolLit = 261,                 /* BoolLit  */
    Bool = 262,                    /* Bool  */
    Read = 263,                    /* Read  */
    Print = 264,                   /* Print  */
    Printlines = 265,              /* Printlines  */
    Printspaces = 266,             /* Printspaces  */
    PrintString = 267,             /* PrintString  */
    StringLit = 268,               /* StringLit  */
    IF = 269,                      /* IF  */
    ELSE = 270,                    /* ELSE  */
    WHILE = 271,                   /* WHILE  */
    AND = 272,                     /* AND  */
    OR = 273,                      /* OR  */
    EQ = 274,                      /* EQ  */
    NEQ = 275,                     /* NEQ  */
    NOT = 276,                     /* NOT  */
    LT = 277,                      /* LT  */
    LTE = 278,                     /* LTE  */
    GT = 279,                      /* GT  */
    GTE = 280                      /* GTE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define Ident 258
#define IntLit 259
#define Int 260
#define BoolLit 261
#define Bool 262
#define Read 263
#define Print 264
#define Printlines 265
#define Printspaces 266
#define PrintString 267
#define StringLit 268
#define IF 269
#define ELSE 270
#define WHILE 271
#define AND 272
#define OR 273
#define EQ 274
#define NEQ 275
#define NOT 276
#define LT 277
#define LTE 278
#define GT 279
#define GTE 280

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 24 "ExprEval.y"

  long val;
  char * string;
  struct ExprRes * ExprRes;
  struct ExprResList * ExprResList;
  struct InstrSeq * InstrSeq;
  struct IdList * IdList;

#line 205 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_Ident = 3,                      /* Ident  */
  YYSYMBOL_IntLit = 4,                     /* IntLit  */
  YYSYMBOL_Int = 5,                        /* Int  */
  YYSYMBOL_BoolLit = 6,                    /* BoolLit  */
  YYSYMBOL_Bool = 7,                       /* Bool  */
  YYSYMBOL_Read = 8,                       /* Read  */
  YYSYMBOL_Print = 9,                      /* Print  */
  YYSYMBOL_Printlines = 10,                /* Printlines  */
  YYSYMBOL_Printspaces = 11,               /* Printspaces  */
  YYSYMBOL_PrintString = 12,               /* PrintString  */
  YYSYMBOL_StringLit = 13,                 /* StringLit  */
  YYSYMBOL_IF = 14,                        /* IF  */
  YYSYMBOL_ELSE = 15,                      /* ELSE  */
  YYSYMBOL_WHILE = 16,                     /* WHILE  */
  YYSYMBOL_AND = 17,                       /* AND  */
  YYSYMBOL_OR = 18,                        /* OR  */
  YYSYMBOL_EQ = 19,                        /* EQ  */
  YYSYMBOL_NEQ = 20,                       /* NEQ  */
  YYSYMBOL_NOT = 21,                       /* NOT  */
  YYSYMBOL_LT = 22,                        /* LT  */
  YYSYMBOL_LTE = 23,                       /* LTE  */
  YYSYMBOL_GT = 24,                        /* GT  */
  YYSYMBOL_GTE = 25,                       /* GTE  */
  YYSYMBOL_26_ = 26,                       /* ';'  */
  YYSYMBOL_27_ = 27,                       /* '['  */
  YYSYMBOL_28_ = 28,                       /* ']'  */
  YYSYMBOL_29_ = 29,                       /* '('  */
  YYSYMBOL_30_ = 30,                       /* ')'  */
  YYSYMBOL_31_ = 31,                       /* '='  */
  YYSYMBOL_32_ = 32,                       /* '{'  */
  YYSYMBOL_33_ = 33,                       /* '}'  */
  YYSYMBOL_34_ = 34,                       /* ','  */
  YYSYMBOL_35_ = 35,                       /* '+'  */
  YYSYMBOL_36_ = 36,                       /* '-'  */
  YYSYMBOL_37_ = 37,                       /* '*'  */
  YYSYMBOL_38_ = 38,                       /* '/'  */
  YYSYMBOL_39_ = 39,                       /* '%'  */
  YYSYMBOL_40_ = 40,                       /* '^'  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_Prog = 42,                      /* Prog  */
  YYSYMBOL_Declarations = 43,              /* Declarations  */
  YYSYMBOL_Dec = 44,                       /* Dec  */
  YYSYMBOL_StmtSeq = 45,                   /* StmtSeq  */
  YYSYMBOL_Stmt = 46,                      /* Stmt  */
  YYSYMBOL_ExprList = 47,                  /* ExprList  */
  YYSYMBOL_BExpr = 48,                     /* BExpr  */
  YYSYMBOL_BExpr1 = 49,                    /* BExpr1  */
  YYSYMBOL_BExpr2 = 50,                    /* BExpr2  */
  YYSYMBOL_BExpr3 = 51,                    /* BExpr3  */
  YYSYMBOL_Expr = 52,                      /* Expr  */
  YYSYMBOL_Term = 53,                      /* Term  */
  YYSYMBOL_Term2 = 54,                     /* Term2  */
  YYSYMBOL_Factor = 55,                    /* Factor  */
  YYSYMBOL_IdentList = 56,                 /* IdentList  */
  YYSYMBOL_ArraySize = 57,                 /* ArraySize  */
  YYSYMBOL_Id = 58                         /* Id  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   157

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  57
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  141

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   280


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    39,     2,     2,
      29,    30,    37,    35,    34,    36,     2,    38,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    26,
       2,    31,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    27,     2,    28,    40,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    32,     2,    33,     2,     2,     2,     2,
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
      25
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    75,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,   127,   128,   129,   130
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
  "\"end of file\"", "error", "\"invalid token\"", "Ident", "IntLit",
  "Int", "BoolLit", "Bool", "Read", "Print", "Printlines", "Printspaces",
  "PrintString", "StringLit", "IF", "ELSE", "WHILE", "AND", "OR", "EQ",
  "NEQ", "NOT", "LT", "LTE", "GT", "GTE", "';'", "'['", "']'", "'('",
  "')'", "'='", "'{'", "'}'", "','", "'+'", "'-'", "'*'", "'/'", "'%'",
  "'^'", "$accept", "Prog", "Declarations", "Dec", "StmtSeq", "Stmt",
  "ExprList", "BExpr", "BExpr1", "BExpr2", "BExpr3", "Expr", "Term",
  "Term2", "Factor", "IdentList", "ArraySize", "Id", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-32)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      35,    18,    18,    24,    41,    35,   -32,    70,    19,   -32,
      48,    12,    52,    62,    85,    90,    92,   -32,    41,    71,
     -32,   -32,    63,   -32,    18,   -32,   -32,   -32,     7,     7,
       7,    28,    22,   -32,    87,    20,     7,     7,     7,     7,
       7,   -32,     7,     7,   -32,    98,    99,    94,   -32,   100,
     -12,   114,    83,    64,    74,   -32,   -32,     7,     7,     7,
       7,     7,     7,     7,    50,    57,    59,    -4,    16,    34,
       1,    86,   106,    18,   107,     7,     7,     7,     7,     7,
       7,     7,     7,     7,    22,    22,   -32,   -32,   -32,   -32,
      38,   108,   110,   111,   109,   112,    72,   -32,   -32,    63,
     -32,   -32,   -32,   114,   -32,    83,    64,    64,    64,    64,
      74,    74,   113,   -32,   -32,   -32,    41,    41,     7,     7,
     115,     7,   105,   116,    43,    47,   119,    40,   124,   -32,
     117,   -32,   -32,   -32,   118,     7,    41,    56,   120,   -32,
     -32
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     0,    10,     4,    57,     0,     0,     1,
       0,     0,     0,     0,     0,     0,     0,     2,    10,     0,
       3,     5,     0,     6,     0,    48,    49,    50,     0,     0,
       0,     0,    39,    43,    47,    51,     0,     0,     0,     0,
       0,     9,     0,     0,    56,     0,     0,    55,    45,     0,
      24,    26,    28,    33,    36,    44,    11,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    37,    38,    40,    41,    42,    46,
       0,     0,     0,     0,     0,     0,     0,    17,     7,     0,
      13,    54,    12,    25,    23,    27,    29,    30,    31,    32,
      34,    35,    52,    14,    15,    16,    10,    10,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    20,    22,
       0,    18,     8,    53,     0,     0,    10,     0,     0,    19,
      21
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -32,   -32,   137,   -32,   -16,   -32,    75,   -31,    77,    69,
      44,    -7,    60,   -23,   -32,    81,    58,    -1
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,    17,    18,    49,    50,    51,    52,
      53,    54,    32,    33,    34,    46,    45,    35
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       7,     8,    41,    19,    31,    48,    75,    55,    67,    68,
       6,    25,    70,    26,    75,     6,    25,    19,    26,    75,
      27,     6,    76,    47,     9,    27,    94,    97,    28,    64,
      65,    66,    90,    28,    75,    69,    86,    87,    88,    89,
       1,    29,     2,    30,     6,    23,    95,    63,    30,    10,
      11,    12,    13,    14,    56,    15,    75,    16,    75,    59,
      60,    61,    96,    57,    58,    75,   112,    44,   133,    57,
      58,   130,    47,   131,    75,   110,   111,    24,    57,    58,
      91,    36,   139,    82,    83,    57,    58,    92,   125,    93,
     127,    37,    57,    58,    57,    58,    21,    22,    42,   118,
     122,   123,    43,   119,   137,    78,    79,    80,    81,    57,
      58,   124,    98,    99,    38,    19,    19,    84,    85,    39,
     138,    40,   106,   107,   108,   109,    71,    62,    73,    72,
      74,    77,   100,   102,   113,    19,   114,   115,   128,   134,
     121,   116,    20,   126,   117,   132,   105,     0,   135,   129,
     136,   104,   103,   140,   101,     0,     0,   120
};

static const yytype_int16 yycheck[] =
{
       1,     2,    18,     4,    11,    28,    18,    30,    39,    40,
       3,     4,    43,     6,    18,     3,     4,    18,     6,    18,
      13,     3,    34,    24,     0,    13,    30,    26,    21,    36,
      37,    38,    63,    21,    18,    42,    59,    60,    61,    62,
       5,    29,     7,    36,     3,    26,    30,    27,    36,     8,
       9,    10,    11,    12,    26,    14,    18,    16,    18,    37,
      38,    39,    28,    35,    36,    18,    28,     4,    28,    35,
      36,    28,    73,    26,    18,    82,    83,    29,    35,    36,
      30,    29,    26,    19,    20,    35,    36,    30,   119,    30,
     121,    29,    35,    36,    35,    36,    26,    27,    27,    27,
     116,   117,    31,    31,   135,    22,    23,    24,    25,    35,
      36,   118,    26,    27,    29,   116,   117,    57,    58,    29,
     136,    29,    78,    79,    80,    81,    28,    40,    34,    30,
      30,    17,    26,    26,    26,   136,    26,    26,    33,    15,
      27,    32,     5,    28,    32,    26,    77,    -1,    31,    33,
      32,    76,    75,    33,    73,    -1,    -1,    99
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,     7,    42,    43,    44,     3,    58,    58,     0,
       8,     9,    10,    11,    12,    14,    16,    45,    46,    58,
      43,    26,    27,    26,    29,     4,     6,    13,    21,    29,
      36,    52,    53,    54,    55,    58,    29,    29,    29,    29,
      29,    45,    27,    31,     4,    57,    56,    58,    54,    47,
      48,    49,    50,    51,    52,    54,    26,    35,    36,    37,
      38,    39,    40,    27,    52,    52,    52,    48,    48,    52,
      48,    28,    30,    34,    30,    18,    34,    17,    22,    23,
      24,    25,    19,    20,    53,    53,    54,    54,    54,    54,
      48,    30,    30,    30,    30,    30,    28,    26,    26,    27,
      26,    56,    26,    49,    47,    50,    51,    51,    51,    51,
      52,    52,    28,    26,    26,    26,    32,    32,    27,    31,
      57,    27,    45,    45,    52,    48,    28,    48,    33,    33,
      28,    26,    26,    28,    15,    31,    32,    48,    45,    26,
      33
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    44,    44,    45,
      45,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      46,    46,    46,    47,    47,    48,    48,    49,    49,    50,
      50,    50,    50,    50,    51,    51,    51,    52,    52,    52,
      53,    53,    53,    53,    54,    54,    54,    54,    55,    55,
      55,    55,    55,    55,    56,    56,    57,    58
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     3,     3,     6,     9,     2,
       0,     3,     5,     5,     5,     5,     5,     4,     7,    10,
       7,    11,     7,     3,     1,     3,     1,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     1,     2,     2,     3,     1,     1,     1,
       1,     1,     4,     7,     3,     1,     1,     1
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
  case 2: /* Prog: Declarations StmtSeq  */
#line 75 "ExprEval.y"
                                                     {Finish((yyvsp[0].InstrSeq));}
#line 1326 "y.tab.c"
    break;

  case 3: /* Declarations: Dec Declarations  */
#line 76 "ExprEval.y"
                                         { }
#line 1332 "y.tab.c"
    break;

  case 4: /* Declarations: %empty  */
#line 77 "ExprEval.y"
                { }
#line 1338 "y.tab.c"
    break;

  case 5: /* Dec: Int Id ';'  */
#line 78 "ExprEval.y"
                                           {enterInt((yyvsp[-1].string));}
#line 1344 "y.tab.c"
    break;

  case 6: /* Dec: Bool Id ';'  */
#line 79 "ExprEval.y"
                            {enterBool((yyvsp[-1].string));}
#line 1350 "y.tab.c"
    break;

  case 7: /* Dec: Int Id '[' ArraySize ']' ';'  */
#line 80 "ExprEval.y"
                                             {intArrayDec((yyvsp[-4].string), (yyvsp[-2].string));}
#line 1356 "y.tab.c"
    break;

  case 8: /* Dec: Int Id '[' ArraySize ']' '[' ArraySize ']' ';'  */
#line 81 "ExprEval.y"
                                                               {int2DArrayDec((yyvsp[-7].string), (yyvsp[-5].string), (yyvsp[-2].string));}
#line 1362 "y.tab.c"
    break;

  case 9: /* StmtSeq: Stmt StmtSeq  */
#line 82 "ExprEval.y"
                                             {(yyval.InstrSeq) = AppendSeq((yyvsp[-1].InstrSeq), (yyvsp[0].InstrSeq));}
#line 1368 "y.tab.c"
    break;

  case 10: /* StmtSeq: %empty  */
#line 83 "ExprEval.y"
                {(yyval.InstrSeq) = NULL;}
#line 1374 "y.tab.c"
    break;

  case 11: /* Stmt: Print Expr ';'  */
#line 84 "ExprEval.y"
                                               {(yyval.InstrSeq) = doPrint((yyvsp[-1].ExprRes), "_nl");}
#line 1380 "y.tab.c"
    break;

  case 12: /* Stmt: Print '(' ExprList ')' ';'  */
#line 85 "ExprEval.y"
                                           {(yyval.InstrSeq) = doPrintList((yyvsp[-2].ExprResList));}
#line 1386 "y.tab.c"
    break;

  case 13: /* Stmt: Read '(' IdentList ')' ';'  */
#line 86 "ExprEval.y"
                                           {(yyval.InstrSeq) = doRead((yyvsp[-2].IdList));}
#line 1392 "y.tab.c"
    break;

  case 14: /* Stmt: Printlines '(' Expr ')' ';'  */
#line 87 "ExprEval.y"
                                            {(yyval.InstrSeq) = doPrintLines((yyvsp[-2].ExprRes));}
#line 1398 "y.tab.c"
    break;

  case 15: /* Stmt: Printspaces '(' Expr ')' ';'  */
#line 88 "ExprEval.y"
                                             {(yyval.InstrSeq) = doPrintSpaces((yyvsp[-2].ExprRes));}
#line 1404 "y.tab.c"
    break;

  case 16: /* Stmt: PrintString '(' Expr ')' ';'  */
#line 89 "ExprEval.y"
                                              {(yyval.InstrSeq) = doPrintString();}
#line 1410 "y.tab.c"
    break;

  case 17: /* Stmt: Id '=' BExpr ';'  */
#line 90 "ExprEval.y"
                                        {(yyval.InstrSeq) = doAssign((yyvsp[-3].string), (yyvsp[-1].ExprRes));}
#line 1416 "y.tab.c"
    break;

  case 18: /* Stmt: Id '[' Expr ']' '=' BExpr ';'  */
#line 91 "ExprEval.y"
                                              {(yyval.InstrSeq) = doArrayAssign((yyvsp[-6].string), (yyvsp[-4].ExprRes), (yyvsp[-1].ExprRes));}
#line 1422 "y.tab.c"
    break;

  case 19: /* Stmt: Id '[' Expr ']' '[' Expr ']' '=' BExpr ';'  */
#line 92 "ExprEval.y"
                                                           {(yyval.InstrSeq) = do2DArrayAssign((yyvsp[-9].string), (yyvsp[-7].ExprRes), (yyvsp[-4].ExprRes), (yyvsp[-1].ExprRes));}
#line 1428 "y.tab.c"
    break;

  case 20: /* Stmt: IF '(' BExpr ')' '{' StmtSeq '}'  */
#line 93 "ExprEval.y"
                                                 {(yyval.InstrSeq) = doIf((yyvsp[-4].ExprRes), (yyvsp[-1].InstrSeq));}
#line 1434 "y.tab.c"
    break;

  case 21: /* Stmt: IF '(' BExpr ')' '{' StmtSeq '}' ELSE '{' StmtSeq '}'  */
#line 94 "ExprEval.y"
                                                                      {(yyval.InstrSeq) = doIfElse((yyvsp[-8].ExprRes), (yyvsp[-5].InstrSeq), (yyvsp[-1].InstrSeq));}
#line 1440 "y.tab.c"
    break;

  case 22: /* Stmt: WHILE '(' BExpr ')' '{' StmtSeq '}'  */
#line 95 "ExprEval.y"
                                                    {(yyval.InstrSeq) = doWhile((yyvsp[-4].ExprRes), (yyvsp[-1].InstrSeq));}
#line 1446 "y.tab.c"
    break;

  case 23: /* ExprList: BExpr ',' ExprList  */
#line 96 "ExprEval.y"
                                   {(yyval.ExprResList) = appendExprNode((yyvsp[-2].ExprRes), (yyvsp[0].ExprResList));}
#line 1452 "y.tab.c"
    break;

  case 24: /* ExprList: BExpr  */
#line 97 "ExprEval.y"
                      {(yyval.ExprResList) = createExprNode((yyvsp[0].ExprRes));}
#line 1458 "y.tab.c"
    break;

  case 25: /* BExpr: BExpr OR BExpr1  */
#line 98 "ExprEval.y"
                                {(yyval.ExprRes) = doOr((yyvsp[-2].ExprRes), (yyvsp[0].ExprRes));}
#line 1464 "y.tab.c"
    break;

  case 26: /* BExpr: BExpr1  */
#line 99 "ExprEval.y"
                       {(yyval.ExprRes) = (yyvsp[0].ExprRes);}
#line 1470 "y.tab.c"
    break;

  case 27: /* BExpr1: BExpr1 AND BExpr2  */
#line 100 "ExprEval.y"
                                  {(yyval.ExprRes) = doAnd((yyvsp[-2].ExprRes), (yyvsp[0].ExprRes));}
#line 1476 "y.tab.c"
    break;

  case 28: /* BExpr1: BExpr2  */
#line 101 "ExprEval.y"
                       {(yyval.ExprRes) = (yyvsp[0].ExprRes);}
#line 1482 "y.tab.c"
    break;

  case 29: /* BExpr2: BExpr2 LT BExpr3  */
#line 102 "ExprEval.y"
                                       {(yyval.ExprRes) = doLT((yyvsp[-2].ExprRes), (yyvsp[0].ExprRes));}
#line 1488 "y.tab.c"
    break;

  case 30: /* BExpr2: BExpr2 LTE BExpr3  */
#line 103 "ExprEval.y"
                                  {(yyval.ExprRes) = doLTE((yyvsp[-2].ExprRes), (yyvsp[0].ExprRes));}
#line 1494 "y.tab.c"
    break;

  case 31: /* BExpr2: BExpr2 GT BExpr3  */
#line 104 "ExprEval.y"
                                 {(yyval.ExprRes) = doGT((yyvsp[-2].ExprRes), (yyvsp[0].ExprRes));}
#line 1500 "y.tab.c"
    break;

  case 32: /* BExpr2: BExpr2 GTE BExpr3  */
#line 105 "ExprEval.y"
                                  {(yyval.ExprRes) = doGTE((yyvsp[-2].ExprRes), (yyvsp[0].ExprRes));}
#line 1506 "y.tab.c"
    break;

  case 33: /* BExpr2: BExpr3  */
#line 106 "ExprEval.y"
                       {(yyval.ExprRes) = (yyvsp[0].ExprRes);}
#line 1512 "y.tab.c"
    break;

  case 34: /* BExpr3: BExpr3 EQ Expr  */
#line 107 "ExprEval.y"
                               {(yyval.ExprRes) = doEq((yyvsp[-2].ExprRes), (yyvsp[0].ExprRes));}
#line 1518 "y.tab.c"
    break;

  case 35: /* BExpr3: BExpr3 NEQ Expr  */
#line 108 "ExprEval.y"
                                {(yyval.ExprRes) = doNotEq((yyvsp[-2].ExprRes), (yyvsp[0].ExprRes));}
#line 1524 "y.tab.c"
    break;

  case 36: /* BExpr3: Expr  */
#line 109 "ExprEval.y"
                     {(yyval.ExprRes) = (yyvsp[0].ExprRes);}
#line 1530 "y.tab.c"
    break;

  case 37: /* Expr: Expr '+' Term  */
#line 110 "ExprEval.y"
                                              {(yyval.ExprRes) = doAdd((yyvsp[-2].ExprRes), (yyvsp[0].ExprRes));}
#line 1536 "y.tab.c"
    break;

  case 38: /* Expr: Expr '-' Term  */
#line 111 "ExprEval.y"
                              {(yyval.ExprRes) = doSub((yyvsp[-2].ExprRes), (yyvsp[0].ExprRes));}
#line 1542 "y.tab.c"
    break;

  case 39: /* Expr: Term  */
#line 112 "ExprEval.y"
                     {(yyval.ExprRes) = (yyvsp[0].ExprRes);}
#line 1548 "y.tab.c"
    break;

  case 40: /* Term: Term '*' Term2  */
#line 113 "ExprEval.y"
                                        {(yyval.ExprRes) = doMult((yyvsp[-2].ExprRes), (yyvsp[0].ExprRes));}
#line 1554 "y.tab.c"
    break;

  case 41: /* Term: Term '/' Term2  */
#line 114 "ExprEval.y"
                               {(yyval.ExprRes) = doDiv((yyvsp[-2].ExprRes), (yyvsp[0].ExprRes));}
#line 1560 "y.tab.c"
    break;

  case 42: /* Term: Term '%' Term2  */
#line 115 "ExprEval.y"
                               {(yyval.ExprRes) = doMod((yyvsp[-2].ExprRes), (yyvsp[0].ExprRes));}
#line 1566 "y.tab.c"
    break;

  case 43: /* Term: Term2  */
#line 116 "ExprEval.y"
                      { (yyval.ExprRes) = (yyvsp[0].ExprRes); }
#line 1572 "y.tab.c"
    break;

  case 44: /* Term2: '-' Term2  */
#line 117 "ExprEval.y"
                          {(yyval.ExprRes) = doUnaryMin((yyvsp[0].ExprRes));}
#line 1578 "y.tab.c"
    break;

  case 45: /* Term2: NOT Term2  */
#line 118 "ExprEval.y"
                          {(yyval.ExprRes) = doNot((yyvsp[0].ExprRes));}
#line 1584 "y.tab.c"
    break;

  case 46: /* Term2: Factor '^' Term2  */
#line 119 "ExprEval.y"
                                 {(yyval.ExprRes) = doExponent((yyvsp[-2].ExprRes), (yyvsp[0].ExprRes));}
#line 1590 "y.tab.c"
    break;

  case 47: /* Term2: Factor  */
#line 120 "ExprEval.y"
                       {(yyval.ExprRes) = (yyvsp[0].ExprRes);}
#line 1596 "y.tab.c"
    break;

  case 48: /* Factor: IntLit  */
#line 121 "ExprEval.y"
                               {(yyval.ExprRes) = doIntLit(yytext);}
#line 1602 "y.tab.c"
    break;

  case 49: /* Factor: BoolLit  */
#line 122 "ExprEval.y"
                        {(yyval.ExprRes) = doBoolLit(yytext);}
#line 1608 "y.tab.c"
    break;

  case 50: /* Factor: StringLit  */
#line 123 "ExprEval.y"
                          {doStringLit(yytext);}
#line 1614 "y.tab.c"
    break;

  case 51: /* Factor: Id  */
#line 124 "ExprEval.y"
                   {(yyval.ExprRes) = doRval((yyvsp[0].string)); }
#line 1620 "y.tab.c"
    break;

  case 52: /* Factor: Id '[' BExpr ']'  */
#line 125 "ExprEval.y"
                                 {(yyval.ExprRes) = doArrayVal((yyvsp[-3].string), (yyvsp[-1].ExprRes));}
#line 1626 "y.tab.c"
    break;

  case 53: /* Factor: Id '[' BExpr ']' '[' BExpr ']'  */
#line 126 "ExprEval.y"
                                               {(yyval.ExprRes) = do2DarrayVal((yyvsp[-6].string), (yyvsp[-4].ExprRes), (yyvsp[-1].ExprRes));}
#line 1632 "y.tab.c"
    break;

  case 54: /* IdentList: Id ',' IdentList  */
#line 127 "ExprEval.y"
                                 {(yyval.IdList) = appendIdNode((yyvsp[0].IdList), (yyvsp[-2].string));}
#line 1638 "y.tab.c"
    break;

  case 55: /* IdentList: Id  */
#line 128 "ExprEval.y"
                   {(yyval.IdList) = createIdNode((yyvsp[0].string));}
#line 1644 "y.tab.c"
    break;

  case 56: /* ArraySize: IntLit  */
#line 129 "ExprEval.y"
                       {(yyval.string) = strdup(yytext);}
#line 1650 "y.tab.c"
    break;

  case 57: /* Id: Ident  */
#line 130 "ExprEval.y"
                                      {(yyval.string) = strdup(yytext);}
#line 1656 "y.tab.c"
    break;


#line 1660 "y.tab.c"

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

#line 132 "ExprEval.y"


int yyerror(char *s)  {
  writeIndicator(getCurrentColumnNum());
  writeMessage("Illegal Character in YACC");
}
