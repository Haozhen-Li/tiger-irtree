/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "tiger.grm" /* yacc.c:339  */

#include <stdio.h>
#include "util.h"
#include "symbol.h" 
#include "errormsg.h"
#include "absyn.h"

int yylex(void); /* function prototype */

A_exp absyn_root;

void yyerror(char *s)
{
 EM_error(EM_tokPos, "%s", s);
}

#line 83 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ID = 258,
    STRING = 259,
    INT = 260,
    COMMA = 261,
    COLON = 262,
    SEMICOLON = 263,
    LPAREN = 264,
    RPAREN = 265,
    LBRACK = 266,
    RBRACK = 267,
    LBRACE = 268,
    RBRACE = 269,
    DOT = 270,
    PLUS = 271,
    MINUS = 272,
    TIMES = 273,
    DIVIDE = 274,
    EQ = 275,
    NEQ = 276,
    LT = 277,
    LE = 278,
    GT = 279,
    GE = 280,
    AND = 281,
    OR = 282,
    ASSIGN = 283,
    ARRAY = 284,
    IF = 285,
    THEN = 286,
    ELSE = 287,
    WHILE = 288,
    FOR = 289,
    TO = 290,
    DO = 291,
    LET = 292,
    IN = 293,
    END = 294,
    OF = 295,
    BREAK = 296,
    NIL = 297,
    FUNCTION = 298,
    VAR = 299,
    TYPE = 300
  };
#endif
/* Tokens.  */
#define ID 258
#define STRING 259
#define INT 260
#define COMMA 261
#define COLON 262
#define SEMICOLON 263
#define LPAREN 264
#define RPAREN 265
#define LBRACK 266
#define RBRACK 267
#define LBRACE 268
#define RBRACE 269
#define DOT 270
#define PLUS 271
#define MINUS 272
#define TIMES 273
#define DIVIDE 274
#define EQ 275
#define NEQ 276
#define LT 277
#define LE 278
#define GT 279
#define GE 280
#define AND 281
#define OR 282
#define ASSIGN 283
#define ARRAY 284
#define IF 285
#define THEN 286
#define ELSE 287
#define WHILE 288
#define FOR 289
#define TO 290
#define DO 291
#define LET 292
#define IN 293
#define END 294
#define OF 295
#define BREAK 296
#define NIL 297
#define FUNCTION 298
#define VAR 299
#define TYPE 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 19 "tiger.grm" /* yacc.c:355  */

	int pos;
	int ival;
	string sval;
	A_var var;
	A_exp exp;
  A_expList explist;
  A_efieldList efieldlist;
  A_decList declist;
  A_dec dec;
  A_ty ty;
  A_fieldList fieldlist;
  A_namety namety;
  A_fundec fundec;
  A_nametyList nametylist;
  A_fundecList fundeclist;
	

#line 232 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 249 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  41
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   458

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  74
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  158

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    76,    76,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   114,   115,   116,   117,
     118,   119,   120,   123,   124,   127,   128,   131,   132,   135,
     136,   138,   139,   142,   143,   144,   147,   150,   151,   154,
     155,   156,   158,   159,   160,   163,   164,   167,   168,   171,
     172,   175,   176,   177,   178
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ID", "STRING", "INT", "COMMA", "COLON",
  "SEMICOLON", "LPAREN", "RPAREN", "LBRACK", "RBRACK", "LBRACE", "RBRACE",
  "DOT", "PLUS", "MINUS", "TIMES", "DIVIDE", "EQ", "NEQ", "LT", "LE", "GT",
  "GE", "AND", "OR", "ASSIGN", "ARRAY", "IF", "THEN", "ELSE", "WHILE",
  "FOR", "TO", "DO", "LET", "IN", "END", "OF", "BREAK", "NIL", "FUNCTION",
  "VAR", "TYPE", "$accept", "program", "exp", "atom", "expseq", "fields",
  "args", "exps", "decs", "dec", "tydec", "tydecs", "ty", "tyfields",
  "vardec", "fundecs", "fundec", "lvalue", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300
};
# endif

#define YYPACT_NINF -126

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-126)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     166,    46,  -126,  -126,    71,    16,   166,   166,    11,    25,
    -126,  -126,    18,   410,     2,    86,   166,     8,  -126,   249,
       5,    49,  -126,  -126,   131,  -126,  -126,    50,   350,   207,
       1,    59,    60,    63,    40,    25,    34,  -126,  -126,  -126,
      39,  -126,   166,   166,   166,   166,   166,   166,   166,   166,
     166,   166,   166,   166,   166,    80,   166,  -126,   168,    74,
     366,    65,  -126,    72,   166,  -126,  -126,   166,  -126,   269,
      77,   166,   166,   166,    83,    -2,    73,   121,  -126,  -126,
    -126,   -10,   -10,  -126,  -126,    15,    15,    15,    15,    15,
      15,   433,   422,   382,  -126,   410,   166,  -126,    54,   166,
    -126,   289,  -126,   398,  -126,  -126,   333,   410,   301,    94,
      95,   166,    -1,  -126,   321,    61,  -126,  -126,   166,   195,
    -126,   166,   166,    99,    92,    79,   410,  -126,    94,    69,
    -126,   166,  -126,   410,   107,   410,   228,   111,     3,   166,
     101,   114,  -126,  -126,   166,   123,   129,   166,   410,  -126,
    -126,   410,    94,   113,   410,  -126,   166,   410
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    71,     8,     7,     0,     0,     0,     0,     0,    51,
      35,     4,     0,     2,     3,     0,     0,     0,     6,     0,
       0,    71,    41,    40,     0,    37,     9,    36,     0,     0,
       0,     0,     0,     0,     0,    51,    57,    53,    54,    55,
      67,     1,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    10,    47,     0,
       0,     0,    24,     0,     0,    34,     5,     0,    39,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    52,    58,
      68,    12,    13,    14,    15,    16,    17,    18,    20,    19,
      21,    22,    23,     0,    72,    27,     0,    11,    74,     0,
      25,    49,    50,     0,    42,    38,    29,    30,     0,    62,
       0,     0,     0,    32,    43,     0,    73,    48,     0,    45,
      74,     0,     0,     0,     0,     0,    65,    59,    62,     0,
      56,     0,    33,    26,     0,    28,     0,     0,     0,     0,
       0,     0,    44,    46,     0,    63,     0,     0,    66,    60,
      61,    31,    62,     0,    69,    64,     0,    70
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -126,  -126,     0,  -126,     6,     9,    53,   -23,   110,  -126,
    -126,   106,  -126,  -125,  -126,   112,  -126,   141
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    12,    58,    26,   115,    63,    59,    20,    34,    35,
      36,    37,   130,   124,    38,    39,    40,    14
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      13,    70,   127,   140,    19,   110,    28,    29,    44,    45,
     146,    61,   128,    54,    30,    66,    60,    55,    41,    21,
      22,    23,    62,   147,    69,    24,   111,   155,   129,    73,
      56,    42,    43,    44,    45,    -1,    -1,    -1,    -1,    -1,
      -1,   102,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    15,    95,    16,    25,    17,
      67,    54,    74,    75,   101,    55,    76,   103,    31,    32,
      33,   106,   107,   108,     1,     2,     3,   114,    77,    33,
       4,    18,    31,    94,    97,    99,   100,   105,     5,     1,
       2,     3,   109,   112,   118,     4,    57,   123,   125,   119,
     132,     6,   138,     5,     7,     8,   137,   139,     9,   141,
      61,   126,    10,    11,   145,   149,     6,   150,   133,     7,
       8,   135,   136,     9,     1,     2,     3,    10,    11,   152,
       4,   114,   153,   156,     1,     2,     3,   142,     5,   148,
       4,    68,    79,   143,   151,    78,    27,   154,     5,   117,
       0,     6,    80,     0,     7,     8,   157,     0,     9,     0,
     113,     6,    10,    11,     7,     8,     0,     0,     9,     1,
       2,     3,    10,    11,    96,     4,     0,     0,     0,     0,
       0,     0,     0,     5,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,     6,     0,     0,     7,
       8,   134,     0,     9,     0,     0,     0,    10,    11,     0,
       0,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,     0,     0,     0,     0,     0,
       0,     0,     0,    72,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,     0,    64,     0,    65,
       0,     0,     0,     0,   144,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    64,     0,   104,
       0,     0,     0,     0,     0,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    64,     0,     0,
       0,     0,     0,     0,     0,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,   131,
       0,     0,     0,     0,     0,     0,   122,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,     0,     0,     0,     0,   121,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    98,     0,
       0,    71,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,   116,     0,     0,     0,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    53,
     120,     0,     0,     0,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51
};

static const yytype_int16 yycheck[] =
{
       0,    24,     3,   128,     4,     7,     6,     7,    18,    19,
       7,     3,    13,    11,     3,    10,    16,    15,     0,     3,
       4,     5,    14,    20,    24,     9,    28,   152,    29,    28,
      28,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    64,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,     9,    56,    11,    42,    13,
      11,    11,     3,     3,    64,    15,     3,    67,    43,    44,
      45,    71,    72,    73,     3,     4,     5,    77,    38,    45,
       9,    10,    43,     3,    10,    20,    14,    10,    17,     3,
       4,     5,     9,    20,    40,     9,    10,     3,     3,    99,
      39,    30,    10,    17,    33,    34,     7,    28,    37,    40,
       3,   111,    41,    42,     3,    14,    30,     3,   118,    33,
      34,   121,   122,    37,     3,     4,     5,    41,    42,     6,
       9,   131,     3,    20,     3,     4,     5,   131,    17,   139,
       9,    10,    36,   134,   144,    35,     5,   147,    17,    96,
      -1,    30,    40,    -1,    33,    34,   156,    -1,    37,    -1,
      39,    30,    41,    42,    33,    34,    -1,    -1,    37,     3,
       4,     5,    41,    42,     6,     9,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    17,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    30,    -1,    -1,    33,
      34,     6,    -1,    37,    -1,    -1,    -1,    41,    42,    -1,
      -1,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    -1,     8,    -1,    10,
      -1,    -1,    -1,    -1,    36,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,     8,    -1,    10,
      -1,    -1,    -1,    -1,    -1,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,     8,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     8,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    -1,    -1,    -1,    32,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    12,    -1,
      -1,    31,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    12,    -1,    -1,    -1,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      12,    -1,    -1,    -1,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     9,    17,    30,    33,    34,    37,
      41,    42,    47,    48,    63,     9,    11,    13,    10,    48,
      53,     3,     4,     5,     9,    42,    49,    63,    48,    48,
       3,    43,    44,    45,    54,    55,    56,    57,    60,    61,
      62,     0,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    11,    15,    28,    10,    48,    52,
      48,     3,    14,    51,     8,    10,    10,    11,    10,    48,
      53,    31,    36,    28,     3,     3,     3,    38,    54,    57,
      61,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,     3,    48,     6,    10,    12,    20,
      14,    48,    53,    48,    10,    10,    48,    48,    48,     9,
       7,    28,    20,    39,    48,    50,    12,    52,    40,    48,
      12,    32,    35,     3,    59,     3,    48,     3,    13,    29,
      58,     8,    39,    48,     6,    48,    48,     7,    10,    28,
      59,    40,    50,    51,    36,     3,     7,    20,    48,    14,
       3,    48,     6,     3,    48,    59,    20,    48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    48,    48,    49,    49,    49,    49,
      49,    49,    49,    50,    50,    51,    51,    52,    52,    53,
      53,    54,    54,    55,    55,    55,    56,    57,    57,    58,
      58,    58,    59,    59,    59,    60,    60,    61,    61,    62,
      62,    63,    63,    63,    63
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     2,     1,     1,     2,
       3,     4,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     4,     6,     3,     6,     4,
       4,     8,     4,     5,     3,     1,     1,     1,     3,     2,
       1,     1,     3,     1,     3,     3,     5,     1,     3,     3,
       3,     0,     2,     1,     1,     1,     4,     1,     2,     1,
       3,     3,     0,     3,     5,     4,     6,     1,     2,     7,
       9,     1,     3,     4,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
        case 2:
#line 76 "tiger.grm" /* yacc.c:1646  */
    {absyn_root=(yyvsp[0].exp);}
#line 1487 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 79 "tiger.grm" /* yacc.c:1646  */
    {(yyval.exp)=A_VarExp(EM_tokPos, (yyvsp[0].var));}
#line 1493 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 80 "tiger.grm" /* yacc.c:1646  */
    {(yyval.exp)=A_NilExp(EM_tokPos);}
#line 1499 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 81 "tiger.grm" /* yacc.c:1646  */
    {(yyval.exp)=A_SeqExp(EM_tokPos, (yyvsp[-1].explist));}
#line 1505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 82 "tiger.grm" /* yacc.c:1646  */
    {(yyval.exp)=A_SeqExp(EM_tokPos, NULL);}
#line 1511 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 83 "tiger.grm" /* yacc.c:1646  */
    {(yyval.exp)=A_IntExp(EM_tokPos, (yyvsp[0].ival));}
#line 1517 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 84 "tiger.grm" /* yacc.c:1646  */
    {(yyval.exp)=A_StringExp(EM_tokPos, (yyvsp[0].sval));}
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 85 "tiger.grm" /* yacc.c:1646  */
    {(yyval.exp)=A_OpExp(EM_tokPos, A_minusOp, A_IntExp(EM_tokPos, 0), (yyvsp[0].exp));}
#line 1529 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 86 "tiger.grm" /* yacc.c:1646  */
    {(yyval.exp)=A_CallExp(EM_tokPos, S_Symbol((yyvsp[-2].sval)), NULL);}
#line 1535 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 87 "tiger.grm" /* yacc.c:1646  */
    {(yyval.exp)=A_CallExp(EM_tokPos, S_Symbol((yyvsp[-3].sval)), (yyvsp[-1].explist));}
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 88 "tiger.grm" /* yacc.c:1646  */
    {(yyval.exp)=A_OpExp(EM_tokPos, A_plusOp, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1547 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 89 "tiger.grm" /* yacc.c:1646  */
    {(yyval.exp)=A_OpExp(EM_tokPos, A_minusOp, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 90 "tiger.grm" /* yacc.c:1646  */
    {(yyval.exp)=A_OpExp(EM_tokPos, A_timesOp, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1559 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 91 "tiger.grm" /* yacc.c:1646  */
    {(yyval.exp)=A_OpExp(EM_tokPos, A_divideOp, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 92 "tiger.grm" /* yacc.c:1646  */
    {(yyval.exp)=A_OpExp(EM_tokPos, A_eqOp, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1571 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 93 "tiger.grm" /* yacc.c:1646  */
    {(yyval.exp)=A_OpExp(EM_tokPos, A_neqOp, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1577 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 94 "tiger.grm" /* yacc.c:1646  */
    {(yyval.exp)=A_OpExp(EM_tokPos, A_ltOp, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 95 "tiger.grm" /* yacc.c:1646  */
    {(yyval.exp)=A_OpExp(EM_tokPos, A_gtOp, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 96 "tiger.grm" /* yacc.c:1646  */
    {(yyval.exp)=A_OpExp(EM_tokPos, A_leOp, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1595 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 97 "tiger.grm" /* yacc.c:1646  */
    {(yyval.exp)=A_OpExp(EM_tokPos, A_geOp, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1601 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 98 "tiger.grm" /* yacc.c:1646  */
    {(yyval.exp)=A_IfExp(EM_tokPos, (yyvsp[-2].exp), (yyvsp[0].exp), A_IntExp(EM_tokPos, 0));}
#line 1607 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 99 "tiger.grm" /* yacc.c:1646  */
    {(yyval.exp)=A_IfExp(EM_tokPos, (yyvsp[-2].exp), A_IntExp(EM_tokPos, 1), (yyvsp[0].exp));}
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 100 "tiger.grm" /* yacc.c:1646  */
    {(yyval.exp)=A_RecordExp(EM_tokPos, S_Symbol((yyvsp[-2].sval)), NULL);}
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 101 "tiger.grm" /* yacc.c:1646  */
    {(yyval.exp)=A_RecordExp(EM_tokPos, S_Symbol((yyvsp[-3].sval)), (yyvsp[-1].efieldlist));}
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 102 "tiger.grm" /* yacc.c:1646  */
    {(yyval.exp)=A_ArrayExp(EM_tokPos, S_Symbol((yyvsp[-5].sval)), (yyvsp[-3].exp), (yyvsp[0].exp));}
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 103 "tiger.grm" /* yacc.c:1646  */
    {(yyval.exp)=A_AssignExp(EM_tokPos, (yyvsp[-2].var), (yyvsp[0].exp));}
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 104 "tiger.grm" /* yacc.c:1646  */
    {(yyval.exp)=A_IfExp(EM_tokPos, (yyvsp[-4].exp), (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 105 "tiger.grm" /* yacc.c:1646  */
    {(yyval.exp)=A_IfExp(EM_tokPos, (yyvsp[-2].exp), (yyvsp[0].exp), A_SeqExp(EM_tokPos, NULL));}
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 106 "tiger.grm" /* yacc.c:1646  */
    {(yyval.exp)=A_WhileExp(EM_tokPos, (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 107 "tiger.grm" /* yacc.c:1646  */
    {(yyval.exp)=A_ForExp(EM_tokPos, S_Symbol((yyvsp[-6].sval)), (yyvsp[-4].exp), (yyvsp[-2].exp), (yyvsp[0].exp));}
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 108 "tiger.grm" /* yacc.c:1646  */
    {(yyval.exp)=A_LetExp(EM_tokPos, (yyvsp[-2].declist), NULL);}
#line 1667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 109 "tiger.grm" /* yacc.c:1646  */
    {(yyval.exp)=A_LetExp(EM_tokPos, (yyvsp[-3].declist), A_SeqExp(EM_tokPos, (yyvsp[-1].explist)));}
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 110 "tiger.grm" /* yacc.c:1646  */
    {(yyval.exp)=(yyvsp[-1].exp);}
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 111 "tiger.grm" /* yacc.c:1646  */
    {(yyval.exp)=A_BreakExp(EM_tokPos);}
#line 1685 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 114 "tiger.grm" /* yacc.c:1646  */
    {(yyval.exp)=A_VarExp(EM_tokPos, (yyvsp[0].var));}
#line 1691 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 115 "tiger.grm" /* yacc.c:1646  */
    {(yyval.exp)=A_NilExp(EM_tokPos);}
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 116 "tiger.grm" /* yacc.c:1646  */
    {(yyval.exp)=A_SeqExp(EM_tokPos, (yyvsp[-1].explist));}
#line 1703 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 117 "tiger.grm" /* yacc.c:1646  */
    {(yyval.exp)=NULL;}
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 118 "tiger.grm" /* yacc.c:1646  */
    {(yyval.exp)=A_IntExp(EM_tokPos, (yyvsp[0].ival));}
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 119 "tiger.grm" /* yacc.c:1646  */
    {(yyval.exp)=A_StringExp(EM_tokPos, (yyvsp[0].sval));}
#line 1721 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 120 "tiger.grm" /* yacc.c:1646  */
    {(yyval.exp)=(yyvsp[-1].exp);}
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 123 "tiger.grm" /* yacc.c:1646  */
    {(yyval.explist)=A_ExpList((yyvsp[0].exp), NULL);}
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 124 "tiger.grm" /* yacc.c:1646  */
    {(yyval.explist)=A_ExpList((yyvsp[-2].exp), (yyvsp[0].explist));}
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 127 "tiger.grm" /* yacc.c:1646  */
    {(yyval.efieldlist)=A_EfieldList(A_Efield(S_Symbol((yyvsp[-2].sval)), (yyvsp[0].exp)), NULL);}
#line 1745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 128 "tiger.grm" /* yacc.c:1646  */
    {(yyval.efieldlist)=A_EfieldList(A_Efield(S_Symbol((yyvsp[-4].sval)), (yyvsp[-2].exp)), (yyvsp[0].efieldlist));}
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 131 "tiger.grm" /* yacc.c:1646  */
    {(yyval.explist)=A_ExpList((yyvsp[0].exp), NULL);}
#line 1757 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 132 "tiger.grm" /* yacc.c:1646  */
    {(yyval.explist)=A_ExpList((yyvsp[-2].exp), (yyvsp[0].explist));}
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 135 "tiger.grm" /* yacc.c:1646  */
    {(yyval.explist)=A_ExpList((yyvsp[-2].exp), A_ExpList((yyvsp[0].exp), NULL));}
#line 1769 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 136 "tiger.grm" /* yacc.c:1646  */
    {(yyval.explist)=A_ExpList((yyvsp[-2].exp), (yyvsp[0].explist));}
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 138 "tiger.grm" /* yacc.c:1646  */
    {(yyval.declist)=NULL;}
#line 1781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 139 "tiger.grm" /* yacc.c:1646  */
    {(yyval.declist)=A_DecList((yyvsp[-1].dec), (yyvsp[0].declist));}
#line 1787 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 142 "tiger.grm" /* yacc.c:1646  */
    {(yyval.dec)=A_TypeDec(EM_tokPos, (yyvsp[0].nametylist));}
#line 1793 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 143 "tiger.grm" /* yacc.c:1646  */
    {(yyval.dec)=(yyvsp[0].dec);}
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 144 "tiger.grm" /* yacc.c:1646  */
    {(yyval.dec)=A_FunctionDec(EM_tokPos, (yyvsp[0].fundeclist));}
#line 1805 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 147 "tiger.grm" /* yacc.c:1646  */
    {(yyval.namety)=A_Namety(S_Symbol((yyvsp[-2].sval)), (yyvsp[0].ty));}
#line 1811 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 150 "tiger.grm" /* yacc.c:1646  */
    {(yyval.nametylist)=A_NametyList((yyvsp[0].namety), NULL);}
#line 1817 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 151 "tiger.grm" /* yacc.c:1646  */
    {(yyval.nametylist)=A_NametyList((yyvsp[-1].namety), (yyvsp[0].nametylist));}
#line 1823 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 154 "tiger.grm" /* yacc.c:1646  */
    {(yyval.ty)=A_NameTy(EM_tokPos, S_Symbol((yyvsp[0].sval)));}
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 155 "tiger.grm" /* yacc.c:1646  */
    {(yyval.ty)=A_RecordTy(EM_tokPos, (yyvsp[-1].fieldlist));}
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 156 "tiger.grm" /* yacc.c:1646  */
    {(yyval.ty)=A_ArrayTy(EM_tokPos, S_Symbol((yyvsp[0].sval)));}
#line 1841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 158 "tiger.grm" /* yacc.c:1646  */
    {(yyval.fieldlist)=NULL;}
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 159 "tiger.grm" /* yacc.c:1646  */
    {(yyval.fieldlist)=A_FieldList(A_Field(EM_tokPos, S_Symbol((yyvsp[-2].sval)), S_Symbol((yyvsp[0].sval))), NULL);}
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 160 "tiger.grm" /* yacc.c:1646  */
    {(yyval.fieldlist)=A_FieldList(A_Field(EM_tokPos, S_Symbol((yyvsp[-4].sval)), S_Symbol((yyvsp[-2].sval))), (yyvsp[0].fieldlist));}
#line 1859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 163 "tiger.grm" /* yacc.c:1646  */
    {(yyval.dec)=A_VarDec(EM_tokPos, S_Symbol((yyvsp[-2].sval)), NULL, (yyvsp[0].exp));}
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 164 "tiger.grm" /* yacc.c:1646  */
    {(yyval.dec)=A_VarDec(EM_tokPos, S_Symbol((yyvsp[-4].sval)), S_Symbol((yyvsp[-2].sval)), (yyvsp[0].exp));}
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 167 "tiger.grm" /* yacc.c:1646  */
    {(yyval.fundeclist)=A_FundecList((yyvsp[0].fundec), NULL);}
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 168 "tiger.grm" /* yacc.c:1646  */
    {(yyval.fundeclist)=A_FundecList((yyvsp[-1].fundec), (yyvsp[0].fundeclist));}
#line 1883 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 171 "tiger.grm" /* yacc.c:1646  */
    {(yyval.fundec)=A_Fundec(EM_tokPos, S_Symbol((yyvsp[-5].sval)), (yyvsp[-3].fieldlist), NULL, (yyvsp[0].exp));}
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 172 "tiger.grm" /* yacc.c:1646  */
    {(yyval.fundec)=A_Fundec(EM_tokPos, S_Symbol((yyvsp[-7].sval)), (yyvsp[-5].fieldlist), S_Symbol((yyvsp[-2].sval)), (yyvsp[0].exp));}
#line 1895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 175 "tiger.grm" /* yacc.c:1646  */
    {(yyval.var)=A_SimpleVar(EM_tokPos,S_Symbol((yyvsp[0].sval)));}
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 176 "tiger.grm" /* yacc.c:1646  */
    {(yyval.var)=A_FieldVar(EM_tokPos, (yyvsp[-2].var), S_Symbol((yyvsp[0].sval)));}
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 177 "tiger.grm" /* yacc.c:1646  */
    {(yyval.var)=A_SubscriptVar(EM_tokPos, (yyvsp[-3].var), (yyvsp[-1].exp));}
#line 1913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 178 "tiger.grm" /* yacc.c:1646  */
    {(yyval.var)=A_SubscriptVar(EM_tokPos, A_SimpleVar(EM_tokPos, S_Symbol((yyvsp[-3].sval))), (yyvsp[-1].exp));}
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1923 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
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
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
