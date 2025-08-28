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

#include "parser.tab.hh"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIER = 3,                 /* IDENTIFIER  */
  YYSYMBOL_STRING_LIT = 4,                 /* STRING_LIT  */
  YYSYMBOL_NUMBER = 5,                     /* NUMBER  */
  YYSYMBOL_TOKMAP = 6,                     /* TOKMAP  */
  YYSYMBOL_TOKSET = 7,                     /* TOKSET  */
  YYSYMBOL_LIST = 8,                       /* LIST  */
  YYSYMBOL_STRING_TYPE = 9,                /* STRING_TYPE  */
  YYSYMBOL_INT_TYPE = 10,                  /* INT_TYPE  */
  YYSYMBOL_PRECONDITION = 11,              /* PRECONDITION  */
  YYSYMBOL_POSTCONDITION = 12,             /* POSTCONDITION  */
  YYSYMBOL_OK = 13,                        /* OK  */
  YYSYMBOL_CREATED_201 = 14,               /* CREATED_201  */
  YYSYMBOL_BAD_REQUEST_400 = 15,           /* BAD_REQUEST_400  */
  YYSYMBOL_NIL = 16,                       /* NIL  */
  YYSYMBOL_ADMIN = 17,                     /* ADMIN  */
  YYSYMBOL_AND = 18,                       /* AND  */
  YYSYMBOL_OR = 19,                        /* OR  */
  YYSYMBOL_NOT = 20,                       /* NOT  */
  YYSYMBOL_IN = 21,                        /* IN  */
  YYSYMBOL_UNION = 22,                     /* UNION  */
  YYSYMBOL_COLON = 23,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 24,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 25,                     /* COMMA  */
  YYSYMBOL_LPAREN = 26,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 27,                    /* RPAREN  */
  YYSYMBOL_LBRACKET = 28,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 29,                  /* RBRACKET  */
  YYSYMBOL_LBRACE = 30,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 31,                    /* RBRACE  */
  YYSYMBOL_EQUALS = 32,                    /* EQUALS  */
  YYSYMBOL_IMPLIES = 33,                   /* IMPLIES  */
  YYSYMBOL_ARROW = 34,                     /* ARROW  */
  YYSYMBOL_PRIME = 35,                     /* PRIME  */
  YYSYMBOL_DOT = 36,                       /* DOT  */
  YYSYMBOL_STAR = 37,                      /* STAR  */
  YYSYMBOL_BACKSLASH = 38,                 /* BACKSLASH  */
  YYSYMBOL_YYACCEPT = 39,                  /* $accept  */
  YYSYMBOL_spec = 40,                      /* spec  */
  YYSYMBOL_items = 41,                     /* items  */
  YYSYMBOL_item = 42,                      /* item  */
  YYSYMBOL_global_declaration = 43,        /* global_declaration  */
  YYSYMBOL_initialization = 44,            /* initialization  */
  YYSYMBOL_function_declaration = 45,      /* function_declaration  */
  YYSYMBOL_param_list = 46,                /* param_list  */
  YYSYMBOL_return_types = 47,              /* return_types  */
  YYSYMBOL_api_block = 48,                 /* api_block  */
  YYSYMBOL_api_call = 49,                  /* api_call  */
  YYSYMBOL_argument_list = 50,             /* argument_list  */
  YYSYMBOL_type_expr = 51,                 /* type_expr  */
  YYSYMBOL_type_list = 52,                 /* type_list  */
  YYSYMBOL_expression = 53,                /* expression  */
  YYSYMBOL_primary_expr = 54,              /* primary_expr  */
  YYSYMBOL_expression_list = 55,           /* expression_list  */
  YYSYMBOL_http_code = 56                  /* http_code  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;



/* Unqualified %code blocks.  */
#line 14 "parser.yy"

  #include <iostream>
  #include <fstream>
  #include <utility>
  #include <unistd.h>

  extern int line_num;
  extern FILE* yyin;

  int yylex();
  void yyerror(const char* s);

  std::unique_ptr<Spec> parsed_spec;

  std::unique_ptr<Map> create_empty_map() {
      std::vector<std::pair<std::unique_ptr<Var>, std::unique_ptr<Expr>>> pairs;
      return std::unique_ptr<Map>(new Map(std::move(pairs)));
  }
  std::unique_ptr<Set> create_set(std::vector<std::unique_ptr<Expr>> elements) {
      return std::unique_ptr<Set>(new Set(std::move(elements)));
  }
  void ensure_spec() {
      if (!parsed_spec) {
          parsed_spec = std::make_unique<Spec>(
            std::vector<std::unique_ptr<Decl>>{},
            std::vector<std::unique_ptr<Init>>{},
            std::vector<std::unique_ptr<FuncDecl>>{},
            std::vector<std::unique_ptr<API>>{}
          );
      }
  }

#line 193 "parser.tab.cc"

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
typedef yytype_int8 yy_state_t;

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

#if 1

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
#endif /* 1 */

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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   189

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  58
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  118

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   293


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
      35,    36,    37,    38
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   106,   106,   107,   111,   112,   116,   117,   118,   119,
     124,   132,   140,   148,   152,   159,   163,   171,   176,   184,
     190,   200,   205,   210,   216,   217,   218,   219,   222,   225,
     228,   235,   239,   246,   247,   253,   259,   264,   270,   276,
     283,   288,   294,   300,   306,   312,   313,   314,   315,   319,
     320,   321,   324,   328,   332,   336,   342,   343,   344
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IDENTIFIER",
  "STRING_LIT", "NUMBER", "TOKMAP", "TOKSET", "LIST", "STRING_TYPE",
  "INT_TYPE", "PRECONDITION", "POSTCONDITION", "OK", "CREATED_201",
  "BAD_REQUEST_400", "NIL", "ADMIN", "AND", "OR", "NOT", "IN", "UNION",
  "COLON", "SEMICOLON", "COMMA", "LPAREN", "RPAREN", "LBRACKET",
  "RBRACKET", "LBRACE", "RBRACE", "EQUALS", "IMPLIES", "ARROW", "PRIME",
  "DOT", "STAR", "BACKSLASH", "$accept", "spec", "items", "item",
  "global_declaration", "initialization", "function_declaration",
  "param_list", "return_types", "api_block", "api_call", "argument_list",
  "type_expr", "type_list", "expression", "primary_expr",
  "expression_list", "http_code", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-24)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-14)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       6,    32,   -13,    20,     6,   -24,   -24,   -24,   -24,   -24,
       5,    87,    87,   -24,   -24,   -24,    -6,   -24,   -24,    13,
      92,    92,     0,    -5,    39,   -24,   -24,   -24,   -24,    87,
      87,    68,   138,   -24,    25,    92,    87,    -4,    16,    56,
      92,    92,   -24,    87,   151,   112,   -24,   138,    80,    87,
      87,    87,    87,    87,   -24,    59,    87,    48,    67,     4,
      25,    92,    92,   -24,    46,    16,    16,    29,   -24,    87,
     -24,   151,   133,    40,    91,    31,   -24,   -23,    83,    73,
     -24,    85,    -3,    16,    92,   -24,   138,   -24,    87,    98,
      81,    87,   101,   109,    16,   117,    92,   125,    99,   138,
      87,   -24,   -24,    16,   111,   115,   138,    92,    36,    16,
     -24,   -24,   -24,    89,   134,   -24,   116,   -24
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     0,     3,     4,     6,     7,     8,     9,
       0,     0,     0,     1,     5,    26,     0,    24,    25,     0,
       0,     0,     0,    10,    45,    47,    46,    48,    49,     0,
       0,    55,    11,    33,     0,     0,     0,     0,    31,     0,
       0,     0,    28,    55,    36,     0,    50,    53,     0,     0,
       0,     0,     0,     0,    40,     0,     0,     0,     0,     0,
       0,     0,     0,    30,    12,    15,    14,     0,    52,     0,
      51,    34,    35,    37,     0,    41,    42,    43,    23,     0,
      29,     0,     0,    32,     0,    44,    54,    38,     0,     0,
       0,     0,     0,     0,    16,     0,     0,     0,     0,    18,
       0,    27,    39,    21,     0,     0,    17,     0,     0,    22,
      56,    57,    58,     0,     0,    19,     0,    20
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -24,   -24,   -24,   154,   -24,   -24,   -24,   -24,   -24,   -24,
      82,   -24,   -14,   -24,   -11,   -24,   119,   -24
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     3,     4,     5,     6,     7,     8,    22,    64,     9,
      58,    90,    23,    39,    47,    33,    48,   113
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      32,    34,    42,    42,    42,    52,    37,    38,    15,     1,
      12,    42,    54,    16,    17,    18,    19,     2,    44,    45,
      13,    59,    35,    42,    93,    60,    65,    66,    57,   -13,
      61,    20,   -13,    80,    40,    21,    36,    41,    71,    72,
      73,    74,    75,    49,    50,    77,    51,    82,    83,   110,
     111,   112,    51,    52,    69,    10,    85,    53,    86,    52,
      54,    55,    76,    56,    11,    43,    54,    55,    52,    56,
      94,    24,    25,    26,    78,    54,    55,    95,    56,    79,
      99,    62,   103,    84,    27,    28,    89,    63,    29,   106,
      24,    25,    26,   109,    30,    15,    91,    92,    31,    46,
      16,    17,    18,    27,    28,    69,    97,    29,    98,    49,
      50,    70,    51,    30,   114,   101,   115,    31,    20,    52,
      87,    96,    21,    53,   100,    88,    54,    55,   104,    56,
      49,    50,   105,    51,   107,    49,    50,   116,    51,    68,
      52,   108,    81,   117,    53,    52,   102,    54,    55,    53,
      56,    49,    54,    55,    51,    56,    49,    50,    14,    51,
       0,    52,    67,     0,     0,    53,    52,     0,    54,    55,
      53,    56,    51,    54,    55,     0,    56,     0,     0,    52,
       0,     0,     0,    53,     0,     0,    54,    55,     0,    56
};

static const yytype_int8 yycheck[] =
{
      11,    12,     7,     7,     7,    28,    20,    21,     3,     3,
      23,     7,    35,     8,     9,    10,    11,    11,    29,    30,
       0,    35,    28,     7,    27,    36,    40,    41,     3,    34,
      34,    26,    37,    29,    34,    30,    23,    37,    49,    50,
      51,    52,    53,    18,    19,    56,    21,    61,    62,    13,
      14,    15,    21,    28,    25,    23,    27,    32,    69,    28,
      35,    36,     3,    38,    32,    26,    35,    36,    28,    38,
      84,     3,     4,     5,    26,    35,    36,    88,    38,    12,
      91,    25,    96,    37,    16,    17,     3,    31,    20,   100,
       3,     4,     5,   107,    26,     3,    23,    12,    30,    31,
       8,     9,    10,    16,    17,    25,    25,    20,    27,    18,
      19,    31,    21,    26,    25,     6,    27,    30,    26,    28,
      29,    23,    30,    32,    23,    34,    35,    36,     3,    38,
      18,    19,    33,    21,    23,    18,    19,     3,    21,    27,
      28,    26,    60,    27,    32,    28,    29,    35,    36,    32,
      38,    18,    35,    36,    21,    38,    18,    19,     4,    21,
      -1,    28,    43,    -1,    -1,    32,    28,    -1,    35,    36,
      32,    38,    21,    35,    36,    -1,    38,    -1,    -1,    28,
      -1,    -1,    -1,    32,    -1,    -1,    35,    36,    -1,    38
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    11,    40,    41,    42,    43,    44,    45,    48,
      23,    32,    23,     0,    42,     3,     8,     9,    10,    11,
      26,    30,    46,    51,     3,     4,     5,    16,    17,    20,
      26,    30,    53,    54,    53,    28,    23,    51,    51,    52,
      34,    37,     7,    26,    53,    53,    31,    53,    55,    18,
      19,    21,    28,    32,    35,    36,    38,     3,    49,    51,
      53,    34,    25,    31,    47,    51,    51,    55,    27,    25,
      31,    53,    53,    53,    53,    53,     3,    53,    26,    12,
      29,    49,    51,    51,    37,    27,    53,    29,    34,     3,
      50,    23,    12,    27,    51,    53,    23,    25,    27,    53,
      23,     6,    29,    51,     3,    33,    53,    23,    26,    51,
      13,    14,    15,    56,    25,    27,     3,    27
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    40,    41,    41,    42,    42,    42,    42,
      43,    44,    45,    46,    46,    47,    47,    48,    48,    49,
      49,    50,    50,    50,    51,    51,    51,    51,    51,    51,
      51,    52,    52,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    54,    54,    54,    54,    54,
      54,    54,    54,    55,    55,    55,    56,    56,    56
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     1,     1,     1,     1,
       3,     3,     5,     1,     3,     1,     3,     9,     7,     8,
      10,     3,     5,     0,     1,     1,     1,     6,     2,     4,
       3,     1,     3,     1,     3,     3,     2,     3,     4,     6,
       2,     3,     3,     3,     4,     1,     1,     1,     1,     1,
       2,     3,     3,     1,     3,     0,     1,     1,     1
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
  case 2: /* spec: %empty  */
#line 106 "parser.yy"
                  { ensure_spec(); (yyval.spec_val) = parsed_spec.get(); }
#line 1502 "parser.tab.cc"
    break;

  case 3: /* spec: items  */
#line 107 "parser.yy"
                 { ensure_spec(); (yyval.spec_val) = parsed_spec.get(); }
#line 1508 "parser.tab.cc"
    break;

  case 6: /* item: global_declaration  */
#line 116 "parser.yy"
                         { ensure_spec(); parsed_spec->globals.push_back(std::unique_ptr<Decl>((yyvsp[0].decl_val))); }
#line 1514 "parser.tab.cc"
    break;

  case 7: /* item: initialization  */
#line 117 "parser.yy"
                         { ensure_spec(); parsed_spec->init.push_back(std::unique_ptr<Init>((yyvsp[0].init_val))); }
#line 1520 "parser.tab.cc"
    break;

  case 8: /* item: function_declaration  */
#line 118 "parser.yy"
                           { ensure_spec(); parsed_spec->functions.push_back(std::unique_ptr<FuncDecl>((yyvsp[0].func_decl_val))); }
#line 1526 "parser.tab.cc"
    break;

  case 9: /* item: api_block  */
#line 119 "parser.yy"
                           { ensure_spec(); parsed_spec->blocks.push_back(std::unique_ptr<API>((yyvsp[0].api_val))); }
#line 1532 "parser.tab.cc"
    break;

  case 10: /* global_declaration: IDENTIFIER COLON type_expr  */
#line 124 "parser.yy"
                               {
        (yyval.decl_val) = new Decl(*(yyvsp[-2].str_val), std::unique_ptr<TypeExpr>((yyvsp[0].type_val)));
        delete (yyvsp[-2].str_val);
    }
#line 1541 "parser.tab.cc"
    break;

  case 11: /* initialization: IDENTIFIER EQUALS expression  */
#line 132 "parser.yy"
                                 {
        (yyval.init_val) = new Init(*(yyvsp[-2].str_val), std::unique_ptr<Expr>((yyvsp[0].expr_val)));
        delete (yyvsp[-2].str_val);
    }
#line 1550 "parser.tab.cc"
    break;

  case 12: /* function_declaration: IDENTIFIER COLON param_list ARROW return_types  */
#line 140 "parser.yy"
                                                   {
        (yyval.func_decl_val) = new FuncDecl(*(yyvsp[-4].str_val), std::move(*(yyvsp[-2].type_list_val)),
                          std::make_pair(HTTPResponseCode::OK_200, std::move(*(yyvsp[0].type_list_val))));
        delete (yyvsp[-4].str_val); delete (yyvsp[-2].type_list_val); delete (yyvsp[0].type_list_val);
    }
#line 1560 "parser.tab.cc"
    break;

  case 13: /* param_list: type_expr  */
#line 148 "parser.yy"
                {
        (yyval.type_list_val) = new std::vector<std::unique_ptr<TypeExpr>>();
        (yyval.type_list_val)->push_back(std::unique_ptr<TypeExpr>((yyvsp[0].type_val)));
      }
#line 1569 "parser.tab.cc"
    break;

  case 14: /* param_list: param_list STAR type_expr  */
#line 152 "parser.yy"
                                {
        (yyvsp[-2].type_list_val)->push_back(std::unique_ptr<TypeExpr>((yyvsp[0].type_val)));
        (yyval.type_list_val) = (yyvsp[-2].type_list_val);
      }
#line 1578 "parser.tab.cc"
    break;

  case 15: /* return_types: type_expr  */
#line 159 "parser.yy"
                {
        (yyval.type_list_val) = new std::vector<std::unique_ptr<TypeExpr>>();
        (yyval.type_list_val)->push_back(std::unique_ptr<TypeExpr>((yyvsp[0].type_val)));
      }
#line 1587 "parser.tab.cc"
    break;

  case 16: /* return_types: return_types STAR type_expr  */
#line 163 "parser.yy"
                                  {
        (yyvsp[-2].type_list_val)->push_back(std::unique_ptr<TypeExpr>((yyvsp[0].type_val)));
        (yyval.type_list_val) = (yyvsp[-2].type_list_val);
      }
#line 1596 "parser.tab.cc"
    break;

  case 17: /* api_block: IDENTIFIER COLON PRECONDITION COLON expression api_call POSTCONDITION COLON expression  */
#line 171 "parser.yy"
                                                                                             {
        Response response(HTTPResponseCode::OK_200, std::unique_ptr<Expr>((yyvsp[0].expr_val)));
        (yyval.api_val) = new API(std::unique_ptr<Expr>((yyvsp[-4].expr_val)), std::unique_ptr<APIcall>((yyvsp[-3].api_call_val)), std::move(response));
        delete (yyvsp[-8].str_val);
      }
#line 1606 "parser.tab.cc"
    break;

  case 18: /* api_block: PRECONDITION COLON expression api_call POSTCONDITION COLON expression  */
#line 176 "parser.yy"
                                                                            {
        Response response(HTTPResponseCode::OK_200, std::unique_ptr<Expr>((yyvsp[0].expr_val)));
        (yyval.api_val) = new API(std::unique_ptr<Expr>((yyvsp[-4].expr_val)), std::unique_ptr<APIcall>((yyvsp[-3].api_call_val)), std::move(response));
      }
#line 1615 "parser.tab.cc"
    break;

  case 19: /* api_call: IDENTIFIER LPAREN argument_list RPAREN IMPLIES LPAREN http_code RPAREN  */
#line 184 "parser.yy"
                                                                             {
        auto func_call = std::make_unique<FuncCall>(*(yyvsp[-7].str_val), std::move(*(yyvsp[-5].expr_list_val)));
        Response response((yyvsp[-1].http_code_val), nullptr);
        (yyval.api_call_val) = new APIcall(std::move(func_call), std::move(response));
        delete (yyvsp[-7].str_val); delete (yyvsp[-5].expr_list_val);
      }
#line 1626 "parser.tab.cc"
    break;

  case 20: /* api_call: IDENTIFIER LPAREN argument_list RPAREN IMPLIES LPAREN http_code COMMA IDENTIFIER RPAREN  */
#line 190 "parser.yy"
                                                                                              {
        auto func_call = std::make_unique<FuncCall>(*(yyvsp[-9].str_val), std::move(*(yyvsp[-7].expr_list_val)));
        Response response((yyvsp[-3].http_code_val), std::make_unique<Var>(*(yyvsp[-1].str_val)));
        (yyval.api_call_val) = new APIcall(std::move(func_call), std::move(response));
        delete (yyvsp[-9].str_val); delete (yyvsp[-7].expr_list_val); delete (yyvsp[-1].str_val);
      }
#line 1637 "parser.tab.cc"
    break;

  case 21: /* argument_list: IDENTIFIER COLON type_expr  */
#line 200 "parser.yy"
                                 {
        (yyval.expr_list_val) = new std::vector<std::unique_ptr<Expr>>();
        (yyval.expr_list_val)->push_back(std::make_unique<Var>(*(yyvsp[-2].str_val)));
        delete (yyvsp[-2].str_val); delete (yyvsp[0].type_val);
      }
#line 1647 "parser.tab.cc"
    break;

  case 22: /* argument_list: argument_list COMMA IDENTIFIER COLON type_expr  */
#line 205 "parser.yy"
                                                     {
        (yyvsp[-4].expr_list_val)->push_back(std::make_unique<Var>(*(yyvsp[-2].str_val)));
        (yyval.expr_list_val) = (yyvsp[-4].expr_list_val);
        delete (yyvsp[-2].str_val); delete (yyvsp[0].type_val);
      }
#line 1657 "parser.tab.cc"
    break;

  case 23: /* argument_list: %empty  */
#line 210 "parser.yy"
                  {
        (yyval.expr_list_val) = new std::vector<std::unique_ptr<Expr>>();
      }
#line 1665 "parser.tab.cc"
    break;

  case 24: /* type_expr: STRING_TYPE  */
#line 216 "parser.yy"
                  { (yyval.type_val) = new TypeConst("string"); }
#line 1671 "parser.tab.cc"
    break;

  case 25: /* type_expr: INT_TYPE  */
#line 217 "parser.yy"
                  { (yyval.type_val) = new TypeConst("int"); }
#line 1677 "parser.tab.cc"
    break;

  case 26: /* type_expr: IDENTIFIER  */
#line 218 "parser.yy"
                  { (yyval.type_val) = new TypeConst(*(yyvsp[0].str_val)); delete (yyvsp[0].str_val); }
#line 1683 "parser.tab.cc"
    break;

  case 27: /* type_expr: LPAREN type_expr ARROW type_expr RPAREN TOKMAP  */
#line 219 "parser.yy"
                                                     {
        (yyval.type_val) = new MapType(std::unique_ptr<TypeExpr>((yyvsp[-4].type_val)), std::unique_ptr<TypeExpr>((yyvsp[-2].type_val)));
      }
#line 1691 "parser.tab.cc"
    break;

  case 28: /* type_expr: type_expr TOKSET  */
#line 222 "parser.yy"
                       {
        (yyval.type_val) = new SetType(std::unique_ptr<TypeExpr>((yyvsp[-1].type_val)));
      }
#line 1699 "parser.tab.cc"
    break;

  case 29: /* type_expr: LIST LBRACKET type_expr RBRACKET  */
#line 225 "parser.yy"
                                       {
        (yyval.type_val) = new SetType(std::unique_ptr<TypeExpr>((yyvsp[-1].type_val))); /* map List[T] -> Set[T] */
      }
#line 1707 "parser.tab.cc"
    break;

  case 30: /* type_expr: LBRACE type_list RBRACE  */
#line 228 "parser.yy"
                              {
        (yyval.type_val) = new TupleType(std::move(*(yyvsp[-1].type_list_val)));
        delete (yyvsp[-1].type_list_val);
      }
#line 1716 "parser.tab.cc"
    break;

  case 31: /* type_list: type_expr  */
#line 235 "parser.yy"
                {
        (yyval.type_list_val) = new std::vector<std::unique_ptr<TypeExpr>>();
        (yyval.type_list_val)->push_back(std::unique_ptr<TypeExpr>((yyvsp[0].type_val)));
      }
#line 1725 "parser.tab.cc"
    break;

  case 32: /* type_list: type_list COMMA type_expr  */
#line 239 "parser.yy"
                                {
        (yyvsp[-2].type_list_val)->push_back(std::unique_ptr<TypeExpr>((yyvsp[0].type_val)));
        (yyval.type_list_val) = (yyvsp[-2].type_list_val);
      }
#line 1734 "parser.tab.cc"
    break;

  case 33: /* expression: primary_expr  */
#line 246 "parser.yy"
                                    { (yyval.expr_val) = (yyvsp[0].expr_val); }
#line 1740 "parser.tab.cc"
    break;

  case 34: /* expression: expression AND expression  */
#line 247 "parser.yy"
                                    {
        auto args = new std::vector<std::unique_ptr<Expr>>();
        args->push_back(std::unique_ptr<Expr>((yyvsp[-2].expr_val)));
        args->push_back(std::unique_ptr<Expr>((yyvsp[0].expr_val)));
        (yyval.expr_val) = new FuncCall("AND", std::move(*args)); delete args;
      }
#line 1751 "parser.tab.cc"
    break;

  case 35: /* expression: expression OR expression  */
#line 253 "parser.yy"
                                    {
        auto args = new std::vector<std::unique_ptr<Expr>>();
        args->push_back(std::unique_ptr<Expr>((yyvsp[-2].expr_val)));
        args->push_back(std::unique_ptr<Expr>((yyvsp[0].expr_val)));
        (yyval.expr_val) = new FuncCall("OR", std::move(*args)); delete args;
      }
#line 1762 "parser.tab.cc"
    break;

  case 36: /* expression: NOT expression  */
#line 259 "parser.yy"
                                    {
        auto args = new std::vector<std::unique_ptr<Expr>>();
        args->push_back(std::unique_ptr<Expr>((yyvsp[0].expr_val)));
        (yyval.expr_val) = new FuncCall("NOT", std::move(*args)); delete args;
      }
#line 1772 "parser.tab.cc"
    break;

  case 37: /* expression: expression IN expression  */
#line 264 "parser.yy"
                                    {
        auto args = new std::vector<std::unique_ptr<Expr>>();
        args->push_back(std::unique_ptr<Expr>((yyvsp[-2].expr_val)));
        args->push_back(std::unique_ptr<Expr>((yyvsp[0].expr_val)));
        (yyval.expr_val) = new FuncCall("inMapVerify", std::move(*args)); delete args;
      }
#line 1783 "parser.tab.cc"
    break;

  case 38: /* expression: expression LBRACKET expression RBRACKET  */
#line 270 "parser.yy"
                                              {
        auto args = new std::vector<std::unique_ptr<Expr>>();
        args->push_back(std::unique_ptr<Expr>((yyvsp[-3].expr_val)));
        args->push_back(std::unique_ptr<Expr>((yyvsp[-1].expr_val)));
        (yyval.expr_val) = new FuncCall("[]", std::move(*args)); delete args;
      }
#line 1794 "parser.tab.cc"
    break;

  case 39: /* expression: expression LBRACKET expression ARROW expression RBRACKET  */
#line 276 "parser.yy"
                                                               {
        auto args = new std::vector<std::unique_ptr<Expr>>();
        args->push_back(std::unique_ptr<Expr>((yyvsp[-5].expr_val)));
        args->push_back(std::unique_ptr<Expr>((yyvsp[-3].expr_val)));
        args->push_back(std::unique_ptr<Expr>((yyvsp[-1].expr_val)));
        (yyval.expr_val) = new FuncCall("mapupdate", std::move(*args)); delete args;
      }
#line 1806 "parser.tab.cc"
    break;

  case 40: /* expression: expression PRIME  */
#line 283 "parser.yy"
                                    {
        auto args = new std::vector<std::unique_ptr<Expr>>();
        args->push_back(std::unique_ptr<Expr>((yyvsp[-1].expr_val)));
        (yyval.expr_val) = new FuncCall("'", std::move(*args)); delete args;
      }
#line 1816 "parser.tab.cc"
    break;

  case 41: /* expression: expression EQUALS expression  */
#line 288 "parser.yy"
                                    {
        auto args = new std::vector<std::unique_ptr<Expr>>();
        args->push_back(std::unique_ptr<Expr>((yyvsp[-2].expr_val)));
        args->push_back(std::unique_ptr<Expr>((yyvsp[0].expr_val)));
        (yyval.expr_val) = new FuncCall("=", std::move(*args)); delete args;
      }
#line 1827 "parser.tab.cc"
    break;

  case 42: /* expression: expression DOT IDENTIFIER  */
#line 294 "parser.yy"
                                    {
        auto args = new std::vector<std::unique_ptr<Expr>>();
        args->push_back(std::unique_ptr<Expr>((yyvsp[-2].expr_val)));
        args->push_back(std::make_unique<String>(*(yyvsp[0].str_val)));
        (yyval.expr_val) = new FuncCall("field", std::move(*args)); delete args; delete (yyvsp[0].str_val);
      }
#line 1838 "parser.tab.cc"
    break;

  case 43: /* expression: expression BACKSLASH expression  */
#line 300 "parser.yy"
                                      {
        auto args = new std::vector<std::unique_ptr<Expr>>();
        args->push_back(std::unique_ptr<Expr>((yyvsp[-2].expr_val)));
        args->push_back(std::unique_ptr<Expr>((yyvsp[0].expr_val)));
        (yyval.expr_val) = new FuncCall("\\", std::move(*args)); delete args;
      }
#line 1849 "parser.tab.cc"
    break;

  case 44: /* expression: IDENTIFIER LPAREN expression_list RPAREN  */
#line 306 "parser.yy"
                                               {
        (yyval.expr_val) = new FuncCall(*(yyvsp[-3].str_val), std::move(*(yyvsp[-1].expr_list_val))); delete (yyvsp[-3].str_val); delete (yyvsp[-1].expr_list_val);
      }
#line 1857 "parser.tab.cc"
    break;

  case 45: /* primary_expr: IDENTIFIER  */
#line 312 "parser.yy"
                   { (yyval.expr_val) = new Var(*(yyvsp[0].str_val)); delete (yyvsp[0].str_val); }
#line 1863 "parser.tab.cc"
    break;

  case 46: /* primary_expr: NUMBER  */
#line 313 "parser.yy"
                   { (yyval.expr_val) = new Num((yyvsp[0].int_val)); }
#line 1869 "parser.tab.cc"
    break;

  case 47: /* primary_expr: STRING_LIT  */
#line 314 "parser.yy"
                   { (yyval.expr_val) = new String(*(yyvsp[0].str_val)); delete (yyvsp[0].str_val); }
#line 1875 "parser.tab.cc"
    break;

  case 48: /* primary_expr: NIL  */
#line 315 "parser.yy"
                   {
        auto args = new std::vector<std::unique_ptr<Expr>>();
        (yyval.expr_val) = new FuncCall("NIL", std::move(*args)); delete args;
      }
#line 1884 "parser.tab.cc"
    break;

  case 49: /* primary_expr: ADMIN  */
#line 319 "parser.yy"
                   { (yyval.expr_val) = new Var("ADMIN"); }
#line 1890 "parser.tab.cc"
    break;

  case 50: /* primary_expr: LBRACE RBRACE  */
#line 320 "parser.yy"
                    { (yyval.expr_val) = create_empty_map().release(); }
#line 1896 "parser.tab.cc"
    break;

  case 51: /* primary_expr: LBRACE expression_list RBRACE  */
#line 321 "parser.yy"
                                    {
        (yyval.expr_val) = create_set(std::move(*(yyvsp[-1].expr_list_val))).release(); delete (yyvsp[-1].expr_list_val);
      }
#line 1904 "parser.tab.cc"
    break;

  case 52: /* primary_expr: LPAREN expression RPAREN  */
#line 324 "parser.yy"
                               { (yyval.expr_val) = (yyvsp[-1].expr_val); }
#line 1910 "parser.tab.cc"
    break;

  case 53: /* expression_list: expression  */
#line 328 "parser.yy"
                 {
        (yyval.expr_list_val) = new std::vector<std::unique_ptr<Expr>>();
        (yyval.expr_list_val)->push_back(std::unique_ptr<Expr>((yyvsp[0].expr_val)));
      }
#line 1919 "parser.tab.cc"
    break;

  case 54: /* expression_list: expression_list COMMA expression  */
#line 332 "parser.yy"
                                       {
        (yyvsp[-2].expr_list_val)->push_back(std::unique_ptr<Expr>((yyvsp[0].expr_val)));
        (yyval.expr_list_val) = (yyvsp[-2].expr_list_val);
      }
#line 1928 "parser.tab.cc"
    break;

  case 55: /* expression_list: %empty  */
#line 336 "parser.yy"
                  {
        (yyval.expr_list_val) = new std::vector<std::unique_ptr<Expr>>();
      }
#line 1936 "parser.tab.cc"
    break;

  case 56: /* http_code: OK  */
#line 342 "parser.yy"
                      { (yyval.http_code_val) = HTTPResponseCode::OK_200; }
#line 1942 "parser.tab.cc"
    break;

  case 57: /* http_code: CREATED_201  */
#line 343 "parser.yy"
                      { (yyval.http_code_val) = HTTPResponseCode::CREATED_201; }
#line 1948 "parser.tab.cc"
    break;

  case 58: /* http_code: BAD_REQUEST_400  */
#line 344 "parser.yy"
                      { (yyval.http_code_val) = HTTPResponseCode::BAD_REQUEST_400; }
#line 1954 "parser.tab.cc"
    break;


#line 1958 "parser.tab.cc"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 347 "parser.yy"


void yyerror(const char* s) {
    std::cerr << "Parse error at line " << line_num << ": " << s << std::endl;
}

std::unique_ptr<Spec> parse_spec(std::istream& in) {
    parsed_spec.reset();

    std::string temp_filename = "/tmp/spec_input.txt";
    std::ofstream temp_file(temp_filename);
    std::string line;
    while (std::getline(in, line)) temp_file << line << '\n';
    temp_file.close();

    yyin = fopen(temp_filename.c_str(), "r");
    if (!yyin) {
        std::cerr << "Failed to open temporary file" << std::endl;
        return nullptr;
    }

    int result = yyparse();
    fclose(yyin);
    unlink(temp_filename.c_str());

    if (result == 0 && parsed_spec) return std::move(parsed_spec);
    std::cerr << "Parse failed" << std::endl;
    return nullptr;
}
