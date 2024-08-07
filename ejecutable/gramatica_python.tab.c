/* A Bison parser, made by GNU Bison 2.4.2.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2006, 2009-2010 Free Software
   Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "../src/gramatica_python.y"


// ----------------------------- GLOSARIO DE IMPORTS -------------------------------------------
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "tabla_simbolos.h"
#include "AST_python.h"

// ----------------------------- DECLARACION DE VARIABLES Y ESTRUCTURAS -------------------------------------------

//Declaracion de variables "extern" sirve para declararlas como variables globales
FILE *yyout;
extern FILE* yyin;
extern int num_linea; //Almacena el numero de linea durante la ejecucion
extern tSimbolos tabla[256];
extern int indice; //Se almacena el índice de la tabla de tSimbolos
char* tipos[] = {"numero", "decimal", "texto", "boolean"}; //Para parsear el tipo que se detecta en flex al tipo del nodo
#define true 1
#define false 0




/* Line 189 of yacc.c  */
#line 99 "gramatica_python.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     FALSE = 258,
     NONE = 259,
     TRUE = 260,
     AND = 261,
     AS = 262,
     ASSERT = 263,
     ASYNC = 264,
     AWAIT = 265,
     BREAK = 266,
     CONTINUE = 267,
     CLASS = 268,
     DEF = 269,
     DEL = 270,
     ELIF = 271,
     ELSE = 272,
     EXCEPT = 273,
     FINALLY = 274,
     FOR = 275,
     FROM = 276,
     GLOBAL = 277,
     IF = 278,
     IMPORT = 279,
     IN = 280,
     IS = 281,
     LAMBDA = 282,
     NONLOCAL = 283,
     NOT = 284,
     OR = 285,
     PASS = 286,
     RAISE = 287,
     RETURN = 288,
     TRY = 289,
     WHILE = 290,
     WITH = 291,
     YIELD = 292,
     END = 293,
     IMPRIMIR = 294,
     CADENA = 295,
     VECTOR = 296,
     LISTA = 297,
     TUPLA = 298,
     SET = 299,
     DICT = 300,
     INT = 301,
     FLOAT = 302,
     COMPLEX = 303,
     BOOLEAN = 304,
     RANGE = 305,
     SUMA = 306,
     RESTA = 307,
     MULTIPLICACION = 308,
     DIVISION = 309,
     MODULO = 310,
     MENOR_QUE = 311,
     MAYOR_QUE = 312,
     AUMENTAR_VALOR = 313,
     IGUAL_QUE = 314,
     DISTINTO_QUE = 315,
     ASIGNACION = 316,
     PARENTESIS_IZQ = 317,
     PARENTESIS_DER = 318,
     DOS_PUNTOS = 319,
     MENOR_IGUAL_QUE = 320,
     MAYOR_IGUAL_QUE = 321,
     NUMERO = 322,
     DECIMAL = 323,
     VARIABLE = 324,
     STRING = 325
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 28 "../src/gramatica_python.y"

  int intVal;
  float realVal;
  char* strVal;
  struct atributos{
    int numero;
    float decimal;
    char* texto;
    int boolean;
    char* tipo;             //Define el tipo que se esta usando
    struct ast *n;          //Para almacenar los nodos del AST
  }tr;



/* Line 214 of yacc.c  */
#line 221 "gramatica_python.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 233 "gramatica_python.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  26
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   181

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  71
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  12
/* YYNRULES -- Number of rules.  */
#define YYNRULES  34
/* YYNRULES -- Number of states.  */
#define YYNSTATES  75

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   325

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      65,    66,    67,    68,    69,    70
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    16,    18,
      20,    24,    30,    36,    41,    43,    49,    60,    64,    68,
      72,    76,    80,    84,    88,    92,    96,   100,   102,   104,
     106,   108,   110,   112,   114
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      72,     0,    -1,    73,    -1,    74,    -1,    73,    74,    -1,
      75,    -1,    82,    -1,    76,    -1,    78,    -1,    79,    -1,
      69,    61,    80,    -1,    23,    80,    64,    73,    77,    -1,
      16,    80,    64,    73,    77,    -1,    17,    64,    73,    77,
      -1,    38,    -1,    35,    80,    64,    73,    38,    -1,    20,
      69,    25,    50,    62,    80,    63,    64,    73,    38,    -1,
      80,    51,    81,    -1,    80,    52,    81,    -1,    80,    53,
      81,    -1,    80,    54,    81,    -1,    80,    59,    81,    -1,
      80,    60,    81,    -1,    80,    56,    81,    -1,    80,    65,
      81,    -1,    80,    57,    81,    -1,    80,    66,    81,    -1,
      81,    -1,    69,    -1,    67,    -1,    68,    -1,    70,    -1,
       5,    -1,     3,    -1,    39,    62,    80,    63,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    84,    84,    94,    95,   103,   104,   105,   106,   107,
     114,   176,   191,   201,   205,   213,   228,   241,   314,   370,
     426,   493,   560,   627,   694,   761,   829,   896,   907,   940,
     948,   956,   964,   971,   983
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FALSE", "NONE", "TRUE", "AND", "AS",
  "ASSERT", "ASYNC", "AWAIT", "BREAK", "CONTINUE", "CLASS", "DEF", "DEL",
  "ELIF", "ELSE", "EXCEPT", "FINALLY", "FOR", "FROM", "GLOBAL", "IF",
  "IMPORT", "IN", "IS", "LAMBDA", "NONLOCAL", "NOT", "OR", "PASS", "RAISE",
  "RETURN", "TRY", "WHILE", "WITH", "YIELD", "END", "IMPRIMIR", "CADENA",
  "VECTOR", "LISTA", "TUPLA", "SET", "DICT", "INT", "FLOAT", "COMPLEX",
  "BOOLEAN", "RANGE", "SUMA", "RESTA", "MULTIPLICACION", "DIVISION",
  "MODULO", "MENOR_QUE", "MAYOR_QUE", "AUMENTAR_VALOR", "IGUAL_QUE",
  "DISTINTO_QUE", "ASIGNACION", "PARENTESIS_IZQ", "PARENTESIS_DER",
  "DOS_PUNTOS", "MENOR_IGUAL_QUE", "MAYOR_IGUAL_QUE", "NUMERO", "DECIMAL",
  "VARIABLE", "STRING", "$accept", "codigo", "sentencias", "sentencia",
  "asignacion", "if", "rescursivo_if", "while", "for", "expresion",
  "tipos", "imprimir", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    71,    72,    73,    73,    74,    74,    74,    74,    74,
      75,    76,    77,    77,    77,    78,    79,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    81,    81,
      81,    81,    81,    81,    82
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     1,     1,     1,
       3,     5,     5,     4,     1,     5,    10,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       1,     1,     1,     1,     4
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     2,     3,     5,
       7,     8,     9,     6,     0,    33,    32,    29,    30,    28,
      31,     0,    27,     0,     0,     0,     1,     4,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    10,     0,    17,    18,    19,    20,    23,    25,
      21,    22,     0,    24,    26,     0,    34,     0,     0,     0,
      14,    11,    15,     0,     0,     0,     0,     0,     0,     0,
       0,    13,     0,    12,    16
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     6,     7,     8,     9,    10,    61,    11,    12,    21,
      22,    13
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -68
static const yytype_int8 yypact[] =
{
      21,   -64,    -3,    -3,   -56,   -51,    11,    21,   -68,   -68,
     -68,   -68,   -68,   -68,   -12,   -68,   -68,   -68,   -68,   -68,
     -68,    22,   -68,    40,    -3,    -3,   -68,   -68,   -34,    -3,
      -3,    -3,    -3,    -3,    -3,    -3,    -3,    21,    -3,    -3,
      21,    56,   104,   -44,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,    -8,   -68,   -68,    -6,   -68,    -3,    -3,   -43,
     -68,   -68,   -68,    72,    88,    21,   -41,    21,    -8,    21,
      -8,   -68,    15,   -68,   -68
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -68,   -68,   -18,     0,   -68,   -68,   -67,   -68,   -68,     1,
     142,   -68
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      15,    71,    16,    73,    23,    14,    24,    27,    58,    59,
      25,    26,     1,    28,     1,     2,    43,     2,    57,    52,
       0,    65,    55,    69,     0,    41,    42,     3,     0,     3,
      60,     4,    62,     4,     0,     1,     0,     0,     2,     0,
       0,     1,     0,     0,     2,     0,     0,    68,     0,    70,
       3,    72,    27,    74,     4,    27,     3,     0,    63,    64,
       4,     5,     0,     5,    17,    18,    19,    20,    27,     0,
      27,     0,    27,    29,    30,    31,    32,     0,    33,    34,
       0,    35,    36,     0,     5,     0,    37,    38,    39,     0,
       5,    29,    30,    31,    32,     0,    33,    34,     0,    35,
      36,     0,     0,     0,    40,    38,    39,    29,    30,    31,
      32,     0,    33,    34,     0,    35,    36,     0,     0,    56,
       0,    38,    39,    29,    30,    31,    32,     0,    33,    34,
       0,    35,    36,     0,     0,    66,     0,    38,    39,    29,
      30,    31,    32,     0,    33,    34,     0,    35,    36,     0,
       0,     0,    67,    38,    39,    29,    30,    31,    32,     0,
      33,    34,     0,    35,    36,     0,     0,     0,     0,    38,
      39,    44,    45,    46,    47,    48,    49,    50,    51,     0,
      53,    54
};

static const yytype_int8 yycheck[] =
{
       3,    68,     5,    70,     3,    69,    62,     7,    16,    17,
      61,     0,    20,    25,    20,    23,    50,    23,    62,    37,
      -1,    64,    40,    64,    -1,    24,    25,    35,    -1,    35,
      38,    39,    38,    39,    -1,    20,    -1,    -1,    23,    -1,
      -1,    20,    -1,    -1,    23,    -1,    -1,    65,    -1,    67,
      35,    69,    52,    38,    39,    55,    35,    -1,    57,    58,
      39,    69,    -1,    69,    67,    68,    69,    70,    68,    -1,
      70,    -1,    72,    51,    52,    53,    54,    -1,    56,    57,
      -1,    59,    60,    -1,    69,    -1,    64,    65,    66,    -1,
      69,    51,    52,    53,    54,    -1,    56,    57,    -1,    59,
      60,    -1,    -1,    -1,    64,    65,    66,    51,    52,    53,
      54,    -1,    56,    57,    -1,    59,    60,    -1,    -1,    63,
      -1,    65,    66,    51,    52,    53,    54,    -1,    56,    57,
      -1,    59,    60,    -1,    -1,    63,    -1,    65,    66,    51,
      52,    53,    54,    -1,    56,    57,    -1,    59,    60,    -1,
      -1,    -1,    64,    65,    66,    51,    52,    53,    54,    -1,
      56,    57,    -1,    59,    60,    -1,    -1,    -1,    -1,    65,
      66,    29,    30,    31,    32,    33,    34,    35,    36,    -1,
      38,    39
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    23,    35,    39,    69,    72,    73,    74,    75,
      76,    78,    79,    82,    69,     3,     5,    67,    68,    69,
      70,    80,    81,    80,    62,    61,     0,    74,    25,    51,
      52,    53,    54,    56,    57,    59,    60,    64,    65,    66,
      64,    80,    80,    50,    81,    81,    81,    81,    81,    81,
      81,    81,    73,    81,    81,    73,    63,    62,    16,    17,
      38,    77,    38,    80,    80,    64,    63,    64,    73,    64,
      73,    77,    73,    77,    38
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1464 of yacc.c  */
#line 84 "../src/gramatica_python.y"
    {
        printf("\nLlamando a comprobarAST\n");
        comprobarAST((yyvsp[(1) - (1)].tr).n); 
        printf("\n[FINALIZADO]\n");     
    ;}
    break;

  case 3:

/* Line 1464 of yacc.c  */
#line 94 "../src/gramatica_python.y"
    { (yyval.tr) = (yyvsp[(1) - (1)].tr); ;}
    break;

  case 4:

/* Line 1464 of yacc.c  */
#line 95 "../src/gramatica_python.y"
    { //para hacerlo recursivo
        (yyval.tr).n = crearNodoNoTerminal((yyvsp[(1) - (2)].tr).n, (yyvsp[(2) - (2)].tr).n, 7);
    ;}
    break;

  case 10:

/* Line 1464 of yacc.c  */
#line 114 "../src/gramatica_python.y"
    {
        printf("> [SENTENCIA] - Asignacion\n");

        //Para crear un nuevo simbolo de tipo numero
        if(strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[0]) == 0){ //comprobacion si es numero
            printf("Asignado el valor %d a la variable\n",(yyvsp[(3) - (3)].tr).numero);

            tabla[indice].nombre = (yyvsp[(1) - (3)].strVal); 
            tabla[indice].tipo = tipos[0]; 
            tabla[indice].numero = (yyvsp[(3) - (3)].tr).numero; 
            tabla[indice].registro = (yyvsp[(3) - (3)].tr).n->resultado;

            indice++; //incrementamos el valor del indice para pasar a la siguiente posicion y dejar la anterior guardada
        }
        //Para crear un nuevo simbolo de tipo decimal
        else if(strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[1]) == 0){ //comprobacion si es decimal
            printf("Asignado el valor %d a la variable\n",(yyvsp[(3) - (3)].tr).decimal);

            tabla[indice].nombre = (yyvsp[(1) - (3)].strVal); 
            tabla[indice].tipo = tipos[1]; 
            tabla[indice].decimal = (yyvsp[(3) - (3)].tr).decimal; 
            tabla[indice].registro = (yyvsp[(3) - (3)].tr).n->resultado;

            indice++; //incrementamos el valor del indice para pasar a la siguiente posicion y dejar la anterior guardada
        }
        //Para crear un nuevo simbolo de tipo string
        else if(strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[2]) == 0){ //comprobacion si es string
            printf("Asignado el valor %s a la variable\n",(yyvsp[(3) - (3)].tr).texto);

            tabla[indice].nombre = (yyvsp[(1) - (3)].strVal); 
            tabla[indice].tipo = tipos[2]; 
            tabla[indice].texto = (yyvsp[(3) - (3)].tr).texto; 
            tabla[indice].registro = (yyvsp[(3) - (3)].tr).n->resultado;

            indice++; //incrementamos el valor del indice para pasar a la siguiente posicion y dejar la anterior guardada
        }
        //Para crear un nuevo simbolo de tipo boolean
        else if(strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[3]) == 0){ //comprobacion si es boolean
            printf("Asignado el valor %d a la variable\n",(yyvsp[(3) - (3)].tr).boolean);

            tabla[indice].nombre = (yyvsp[(1) - (3)].strVal); 
            tabla[indice].tipo = tipos[2]; 
            tabla[indice].boolean = (yyvsp[(3) - (3)].tr).boolean; 
            tabla[indice].registro = (yyvsp[(3) - (3)].tr).n->resultado;

            indice++; //incrementamos el valor del indice para pasar a la siguiente posicion y dejar la anterior guardada
        }

        // Control de errores
        else{
            yyerror("> [ERROR] - NO ES NINGUNO DE LOS TIPOS DEFINIDOS\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
            
        }

        (yyval.tr).n=crearNodoNoTerminal((yyvsp[(3) - (3)].tr).n, crearNodoVacio(), 15);
    ;}
    break;

  case 11:

/* Line 1464 of yacc.c  */
#line 176 "../src/gramatica_python.y"
    {
        if(strcmp((yyvsp[(2) - (5)].tr).tipo, tipos[3]) == 0){ //comprobacion si es boolean
            printf("> [IF] - ESTAMOS COMPARANDO\n");
            (yyval.tr).n=crearNodoNoTerminalIf((yyvsp[(2) - (5)].tr).n, (yyvsp[(4) - (5)].tr).n, (yyvsp[(5) - (5)].tr).n, 12);
        }
        else{
            yyerror("> [ERROR] - SE ESPERABA UN BOOLEAN\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }
    ;}
    break;

  case 12:

/* Line 1464 of yacc.c  */
#line 191 "../src/gramatica_python.y"
    {
        if(strcmp((yyvsp[(2) - (5)].tr).tipo, tipos[3]) == 0){ //comprobacion si es boolean
            printf("> [ELIF] - ESTAMOS COMPARANDO\n");
            (yyval.tr).n=crearNodoNoTerminalIf((yyvsp[(2) - (5)].tr).n, (yyvsp[(4) - (5)].tr).n, (yyvsp[(5) - (5)].tr).n, 13);
        }
        else{
            yyerror("> [ERROR] - SE ESPERABA UN BOOLEAN\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }
    ;}
    break;

  case 13:

/* Line 1464 of yacc.c  */
#line 201 "../src/gramatica_python.y"
    {
        printf("> [ELSE] - SI NO\n");
        (yyval.tr).n=crearNodoNoTerminal((yyvsp[(3) - (4)].tr).n, (yyvsp[(4) - (4)].tr).n, 14);
    ;}
    break;

  case 14:

/* Line 1464 of yacc.c  */
#line 205 "../src/gramatica_python.y"
    {
        (yyval.tr).n = crearNodoEnd(23);
    ;}
    break;

  case 15:

/* Line 1464 of yacc.c  */
#line 213 "../src/gramatica_python.y"
    {
        if(strcmp((yyvsp[(2) - (5)].tr).tipo, tipos[3]) == 0){ //comprobacion si es boolean
            printf("> [WHILE] - ESTAMOS EN UN BUCLE\n");
            (yyval.tr).n=crearNodoNoTerminal((yyvsp[(2) - (5)].tr).n, (yyvsp[(4) - (5)].tr).n, 11);
        }
        else{
            yyerror("> [ERROR] - SE ESPERABA UN BOOLEAN\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }
    ;}
    break;

  case 16:

/* Line 1464 of yacc.c  */
#line 228 "../src/gramatica_python.y"
    {
        printf("> [FOR] - ESTAMOS EN UN BUCLE\n");
        (yyval.tr).n = crearNodoNoTerminal((yyvsp[(6) - (10)].tr).n, (yyvsp[(9) - (10)].tr).n, 25);
    ;}
    break;

  case 17:

/* Line 1464 of yacc.c  */
#line 241 "../src/gramatica_python.y"
    {

        //SUMA de numero + numero
        if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[0]) == 0) { //comprobacion del tipo
            printf("> [OPERACION] - SUMA {numero / numero}\n");

            (yyval.tr).n = crearNodoNoTerminal((yyvsp[(1) - (3)].tr).n, (yyvsp[(3) - (3)].tr).n, 2);
            (yyval.tr).tipo = tipos[0]; 
            (yyval.tr).numero = (yyvsp[(1) - (3)].tr).numero + (yyvsp[(3) - (3)].tr).numero;
        }

        //SUMA de decimal + decimal
        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[1]) == 0){  //comprobacion del tipo
            printf("> [OPERACION] - SUMA {decimal / decimal}\n");

            (yyval.tr).n = crearNodoNoTerminal((yyvsp[(1) - (3)].tr).n, (yyvsp[(3) - (3)].tr).n, 2);
            (yyval.tr).tipo = tipos[1]; 
            (yyval.tr).decimal = (yyvsp[(1) - (3)].tr).decimal + (yyvsp[(3) - (3)].tr).decimal;
        }

        //SUMA de str + str
        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[2]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[2]) == 0){  //comprobacion del tipo
            printf("> [OPERACION] - SUMA {texto / texto}\n");

            (yyval.tr).n = crearNodoNoTerminal((yyvsp[(1) - (3)].tr).n, (yyvsp[(3) - (3)].tr).n, 2);
            (yyval.tr).tipo = tipos[2];
            (yyval.tr).texto = (char*)malloc(strlen((yyvsp[(1) - (3)].tr).texto) + strlen((yyvsp[(3) - (3)].tr).texto) + 1);
            if ((yyval.tr).texto != NULL) {
                // Concatenar las cadenas
                strcpy((yyval.tr).texto, (yyvsp[(1) - (3)].tr).texto);
                strcat((yyval.tr).texto, (yyvsp[(3) - (3)].tr).texto);
            }
            else {
                yyerror("Error al asignar memoria para la concatenacion de cadenas.\n");
            }
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[1]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - SUMA {numero / decimal}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[2]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - SUMA {numero / string}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[0]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - SUMA {decimal / numero}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[2]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - SUMA {decimal / string}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[2]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[0]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - SUMA {string / numero}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[2]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[1]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - SUMA {string / decimal}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else{
            yyerror("> [ERROR] - SUMA\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }
    ;}
    break;

  case 18:

/* Line 1464 of yacc.c  */
#line 314 "../src/gramatica_python.y"
    {
        
        //RESTA de numero - numero
        if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[0]) == 0) {  //comprobacion del tipo
            printf("> [OPERACION] - RESTA {numero / numero}\n");

            (yyval.tr).n = crearNodoNoTerminal((yyvsp[(1) - (3)].tr).n, (yyvsp[(3) - (3)].tr).n, 3);
            (yyval.tr).tipo = tipos[0]; 
            (yyval.tr).numero = (yyvsp[(1) - (3)].tr).numero + (yyvsp[(3) - (3)].tr).numero;
        }

        //RESTA de decimal - decimal
        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[1]) == 0){  //comprobacion del tipo
            printf("> [OPERACION] - RESTA {decimal / decimal}\n");

            (yyval.tr).n = crearNodoNoTerminal((yyvsp[(1) - (3)].tr).n, (yyvsp[(3) - (3)].tr).n, 3);
            (yyval.tr).tipo = tipos[1]; 
            (yyval.tr).decimal = (yyvsp[(1) - (3)].tr).decimal + (yyvsp[(3) - (3)].tr).decimal;
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[1]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - RESTA {numero / decimal}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[2]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - RESTA {numero / string}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[0]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - RESTA {decimal / numero}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[2]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - RESTA {decimal / string}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[2]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[0]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - RESTA {string / numero}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[2]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[1]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - RESTA {string / decimal}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else{
            yyerror("> [ERROR] - RESTA\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }
    ;}
    break;

  case 19:

/* Line 1464 of yacc.c  */
#line 370 "../src/gramatica_python.y"
    {
        
        //MULTIPLICACION de numero * numero
        if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[0]) == 0) {  //comprobacion del tipo
            printf("> [OPERACION] - MULTIPLICACION {numero / numero}\n");

            (yyval.tr).n = crearNodoNoTerminal((yyvsp[(1) - (3)].tr).n, (yyvsp[(3) - (3)].tr).n, 4);
            (yyval.tr).tipo = tipos[0]; 
            (yyval.tr).numero = (yyvsp[(1) - (3)].tr).numero * (yyvsp[(3) - (3)].tr).numero;
        }

        //MULTIPLICACION de decimal * decimal
        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[1]) == 0){  //comprobacion del tipo
            printf("> [OPERACION] - MULTIPLICACION {decimal / decimal}\n");

            (yyval.tr).n = crearNodoNoTerminal((yyvsp[(1) - (3)].tr).n, (yyvsp[(3) - (3)].tr).n, 4);
            (yyval.tr).tipo = tipos[1]; 
            (yyval.tr).decimal = (yyvsp[(1) - (3)].tr).decimal * (yyvsp[(3) - (3)].tr).decimal;
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[1]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MULTIPLICACION {numero / decimal}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[2]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MULTIPLICACION {numero / string}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[0]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MULTIPLICACION {decimal / numero}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[2]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MULTIPLICACION {decimal / string}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[2]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[0]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MULTIPLICACION {string / numero}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[2]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[1]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MULTIPLICACION {string / decimal}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else{
            yyerror("> [ERROR] - MULTIPLICACION\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }
    ;}
    break;

  case 20:

/* Line 1464 of yacc.c  */
#line 426 "../src/gramatica_python.y"
    {
        
        //DIVISION de numero / numero
        if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[0]) == 0) {  //comprobacion del tipo
            if ((yyvsp[(3) - (3)].tr).numero == 0.0) {
                yyerror("> [ERROR] - DIVISION {numero / 0}\n");
                printf("ERROR EN LA LINEA %d\n", num_linea);
            }
            else {
                printf("> [OPERACION] - DIVISION {numero / numero}\n");

                (yyval.tr).n = crearNodoNoTerminal((yyvsp[(1) - (3)].tr).n, (yyvsp[(3) - (3)].tr).n, 5);
                (yyval.tr).tipo = tipos[0]; 
                (yyval.tr).numero = (yyvsp[(1) - (3)].tr).numero / (yyvsp[(3) - (3)].tr).numero;
            }  
        }

        //DIVISION de decimal / decimal
        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[1]) == 0){  //comprobacion del tipo
            if ((yyvsp[(3) - (3)].tr).numero == 0.0) {
                yyerror("> [ERROR] - DIVISION {numero / 0}\n");
                printf("ERROR EN LA LINEA %d\n", num_linea);
            }
            else {
                printf("> [OPERACION] - DIVISION {decimal / decimal}\n");
                (yyval.tr).n = crearNodoNoTerminal((yyvsp[(1) - (3)].tr).n, (yyvsp[(3) - (3)].tr).n, 5);
                (yyval.tr).tipo = tipos[1]; 
                (yyval.tr).decimal = (yyvsp[(1) - (3)].tr).decimal / (yyvsp[(3) - (3)].tr).decimal;
            }
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[1]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - DIVISION {numero / decimal}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[2]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - DIVISION {numero / string}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[0]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - DIVISION {decimal / numero}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[2]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - DIVISION {decimal / string}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[2]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[0]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - DIVISION {string / numero}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[2]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[1]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - DIVISION {string / decimal}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else{
            yyerror("> [ERROR] - DIVISION\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }
    ;}
    break;

  case 21:

/* Line 1464 of yacc.c  */
#line 493 "../src/gramatica_python.y"
    {
        
        //IGUAL_QUE de numero / numero
        if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[0]) == 0) {  //comprobacion del tipo
            printf("> [COMPARACION] - IGUAL_QUE {numero / numero}\n");
            (yyval.tr).n = crearNodoNoTerminal((yyvsp[(1) - (3)].tr).n, (yyvsp[(3) - (3)].tr).n, 17);
            (yyval.tr).tipo = tipos[3]; 
            if ((yyvsp[(1) - (3)].tr).numero == (yyvsp[(3) - (3)].tr).numero) {
                printf("Verdadero %d es igual que %d\n", (yyvsp[(1) - (3)].tr), (yyvsp[(3) - (3)].tr));
                (yyval.tr).boolean = 1; // Verdadero
            }
            else {
                printf("Falso %d no es igual que %d\n", (yyvsp[(1) - (3)].tr), (yyvsp[(3) - (3)].tr));
                (yyval.tr).boolean = 0;
            }
        }
        //IGUAL_QUE de decimal / decimal
        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[1]) == 0){  //comprobacion del tipo
            printf("> [COMPARACION] - IGUAL_QUE {decimal / decimal}\n");
            (yyval.tr).n = crearNodoNoTerminal((yyvsp[(1) - (3)].tr).n, (yyvsp[(3) - (3)].tr).n, 17);
            (yyval.tr).tipo = tipos[3]; 
            if ((yyvsp[(1) - (3)].tr).decimal == (yyvsp[(3) - (3)].tr).decimal) {
                printf("Verdadero %d es igual que %d\n", (yyvsp[(1) - (3)].tr), (yyvsp[(3) - (3)].tr));
                (yyval.tr).boolean = 1; // Verdadero
            }
            else {
                printf("Falso %d no es igual que %d\n", (yyvsp[(1) - (3)].tr), (yyvsp[(3) - (3)].tr));
                (yyval.tr).boolean = 0;
            }
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[1]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - IGUAL_QUE {numero / decimal}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[2]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - IGUAL_QUE {numero / string}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[0]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - IGUAL_QUE {decimal / numero}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[2]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - IGUAL_QUE {decimal / string}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[2]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[0]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - IGUAL_QUE {string / numero}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[2]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[1]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - IGUAL_QUE {string / decimal}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else{
            yyerror("> [ERROR] - IGUAL_QUE\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }
    ;}
    break;

  case 22:

/* Line 1464 of yacc.c  */
#line 560 "../src/gramatica_python.y"
    {
        
        //DISTINTO_QUE de numero / numero
        if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[0]) == 0) {  //comprobacion del tipo
            printf("> [COMPARACION] - DISTINTO_QUE {numero / numero}\n");
            (yyval.tr).n = crearNodoNoTerminal((yyvsp[(1) - (3)].tr).n, (yyvsp[(3) - (3)].tr).n, 18); 
            (yyval.tr).tipo = tipos[3]; 
            if ((yyvsp[(1) - (3)].tr).numero != (yyvsp[(3) - (3)].tr).numero) {
                printf("Verdadero %d es distinto que %d\n", (yyvsp[(1) - (3)].tr), (yyvsp[(3) - (3)].tr));
                (yyval.tr).boolean = 1; // Verdadero
            }
            else {
                printf("Falso %d no es distinto que %d\n", (yyvsp[(1) - (3)].tr), (yyvsp[(3) - (3)].tr));
                (yyval.tr).boolean = 0;
            }
        }
        //DISTINTO_QUE de decimal / decimal
        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[1]) == 0){  //comprobacion del tipo
            printf("> [COMPARACION] - DISTINTO_QUE {decimal / decimal}\n");
            (yyval.tr).n = crearNodoNoTerminal((yyvsp[(1) - (3)].tr).n, (yyvsp[(3) - (3)].tr).n, 18);
            (yyval.tr).tipo = tipos[3]; 
            if ((yyvsp[(1) - (3)].tr).decimal != (yyvsp[(3) - (3)].tr).decimal) {
                printf("Verdadero %d es distinto que %d\n", (yyvsp[(1) - (3)].tr), (yyvsp[(3) - (3)].tr));
                (yyval.tr).boolean = 1; // Verdadero
            }
            else {
                printf("Falso %d no es distinto que %d\n", (yyvsp[(1) - (3)].tr), (yyvsp[(3) - (3)].tr));
                (yyval.tr).boolean = 0;
            }
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[1]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - DISTINTO_QUE {numero / decimal}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[2]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - DISTINTO_QUE {numero / string}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[0]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - DISTINTO_QUE {decimal / numero}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[2]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - DISTINTO_QUE {decimal / string}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[2]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[0]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - DISTINTO_QUE {string / numero}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[2]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[1]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - DISTINTO_QUE {string / decimal}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else{
            yyerror("> [ERROR] - DISTINTO_QUE\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }
    ;}
    break;

  case 23:

/* Line 1464 of yacc.c  */
#line 627 "../src/gramatica_python.y"
    {
        
        //MENOR_QUE de numero / numero
        if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[0]) == 0) {  //comprobacion del tipo
            printf("> [COMPARACION] - MENOR_QUE {numero / numero}\n");
            (yyval.tr).n = crearNodoNoTerminal((yyvsp[(1) - (3)].tr).n, (yyvsp[(3) - (3)].tr).n, 19);
            (yyval.tr).tipo = tipos[3]; 
            if ((yyvsp[(1) - (3)].tr).numero < (yyvsp[(3) - (3)].tr).numero) {
                printf("Verdadero %d es menor que %d\n", (yyvsp[(1) - (3)].tr), (yyvsp[(3) - (3)].tr));
                (yyval.tr).boolean = 1; // Verdadero
            }
            else {
                printf("Falso %d no es menor que %d\n", (yyvsp[(1) - (3)].tr), (yyvsp[(3) - (3)].tr));
                (yyval.tr).boolean = 0;
            }
        }
        //MENOR_QUE de decimal / decimal
        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[1]) == 0){  //comprobacion del tipo
            printf("> [COMPARACION] - MENOR_QUE {decimal / decimal}\n");
            (yyval.tr).n = crearNodoNoTerminal((yyvsp[(1) - (3)].tr).n, (yyvsp[(3) - (3)].tr).n, 19);
            (yyval.tr).tipo = tipos[3]; 
            if ((yyvsp[(1) - (3)].tr).decimal < (yyvsp[(3) - (3)].tr).decimal) {
                printf("Verdadero %d es menor que %d\n", (yyvsp[(1) - (3)].tr), (yyvsp[(3) - (3)].tr));
                (yyval.tr).boolean = 1; // Verdadero
            }
            else {
                printf("Falso %d no es menor que %d\n", (yyvsp[(1) - (3)].tr), (yyvsp[(3) - (3)].tr));
                (yyval.tr).boolean = 0;
            }
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[1]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MENOR_QUE {numero / decimal}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[2]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MENOR_QUE {numero / string}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[0]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MENOR_QUE {decimal / numero}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[2]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MENOR_QUE {decimal / string}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[2]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[0]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MENOR_QUE {string / numero}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[2]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[1]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MENOR_QUE {string / decimal}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else{
            yyerror("> [ERROR] - MENOR_QUE\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }
    ;}
    break;

  case 24:

/* Line 1464 of yacc.c  */
#line 694 "../src/gramatica_python.y"
    {
        
        //MENOR_IGUAL_QUE de numero / numero
        if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[0]) == 0) {  //comprobacion del tipo
            printf("> [COMPARACION] - MENOR_IGUAL_QUE {numero / numero}\n");
            (yyval.tr).n = crearNodoNoTerminal((yyvsp[(1) - (3)].tr).n, (yyvsp[(3) - (3)].tr).n, 20);
            (yyval.tr).tipo = tipos[3]; 
            if ((yyvsp[(1) - (3)].tr).numero < (yyvsp[(3) - (3)].tr).numero || (yyvsp[(1) - (3)].tr).numero == (yyvsp[(3) - (3)].tr).numero) {
                printf("Verdadero %d es menor o igual que %d\n", (yyvsp[(1) - (3)].tr), (yyvsp[(3) - (3)].tr));
                (yyval.tr).boolean = 1; // Verdadero
            }
            else {
                printf("Falso %d no es menor o igual que %d\n", (yyvsp[(1) - (3)].tr), (yyvsp[(3) - (3)].tr));
                (yyval.tr).boolean = 0;
            }
        }
        //MENOR_IGUAL_QUE de decimal / decimal
        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[1]) == 0){  //comprobacion del tipo
            printf("> [COMPARACION] - MENOR_IGUAL_QUE {decimal / decimal}\n");
            (yyval.tr).n = crearNodoNoTerminal((yyvsp[(1) - (3)].tr).n, (yyvsp[(3) - (3)].tr).n, 20);
            (yyval.tr).tipo = tipos[3]; 
            if ((yyvsp[(1) - (3)].tr).decimal < (yyvsp[(3) - (3)].tr).decimal || (yyvsp[(1) - (3)].tr).decimal == (yyvsp[(3) - (3)].tr).decimal) {
                printf("Verdadero %d es menor o igual que %d\n", (yyvsp[(1) - (3)].tr), (yyvsp[(3) - (3)].tr));
                (yyval.tr).boolean = 1; // Verdadero
            }
            else {
                printf("Falso %d no es menor o igual que %d\n", (yyvsp[(1) - (3)].tr), (yyvsp[(3) - (3)].tr));
                (yyval.tr).boolean = 0;
            }
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[1]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MENOR_IGUAL_QUE {numero / decimal}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[2]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MENOR_IGUAL_QUE {numero / string}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[0]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MENOR_IGUAL_QUE {decimal / numero}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[2]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MENOR_IGUAL_QUE {decimal / string}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[2]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[0]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MENOR_IGUAL_QUE {string / numero}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[2]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[1]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MENOR_IGUAL_QUE {string / decimal}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else{
            yyerror("> [ERROR] - MENOR_IGUAL_QUE\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }
    ;}
    break;

  case 25:

/* Line 1464 of yacc.c  */
#line 761 "../src/gramatica_python.y"
    {
        
        //MAYOR_QUE de numero / numero
        if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[0]) == 0) {  //comprobacion del tipo
            printf("> [COMPARACION] - MAYOR_QUE {numero / numero}\n");

            (yyval.tr).n = crearNodoNoTerminal((yyvsp[(1) - (3)].tr).n, (yyvsp[(3) - (3)].tr).n, 21);
            (yyval.tr).tipo = tipos[3]; 
            if ((yyvsp[(1) - (3)].tr).numero > (yyvsp[(3) - (3)].tr).numero) {
                printf("Verdadero %d es mayor que %d\n", (yyvsp[(1) - (3)].tr), (yyvsp[(3) - (3)].tr));
                (yyval.tr).boolean = 1; // Verdadero
            }
            else {
                printf("Falso %d no es mayor que %d\n", (yyvsp[(1) - (3)].tr), (yyvsp[(3) - (3)].tr));
                (yyval.tr).boolean = 0;
            }
        }
        //MAYOR_QUE de decimal / decimal
        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[1]) == 0){  //comprobacion del tipo
            printf("> [COMPARACION] - MAYOR_QUE {decimal / decimal}\n");
            (yyval.tr).n = crearNodoNoTerminal((yyvsp[(1) - (3)].tr).n, (yyvsp[(3) - (3)].tr).n, 21);
            (yyval.tr).tipo = tipos[3]; 
            if ((yyvsp[(1) - (3)].tr).decimal > (yyvsp[(3) - (3)].tr).decimal) {
                printf("Verdadero %d es mayor que %d\n", (yyvsp[(1) - (3)].tr), (yyvsp[(3) - (3)].tr));
                (yyval.tr).boolean = 1; // Verdadero
            }
            else {
                printf("Falso %d no es mayor que %d\n", (yyvsp[(1) - (3)].tr), (yyvsp[(3) - (3)].tr));
                (yyval.tr).boolean = 0;
            }
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[1]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MAYOR_QUE {numero / decimal}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[2]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MAYOR_QUE {numero / string}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[0]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MAYOR_QUE {decimal / numero}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[2]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MAYOR_QUE {decimal / string}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[2]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[0]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MAYOR_QUE {string / numero}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[2]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[1]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MAYOR_QUE {string / decimal}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else{
            yyerror("> [ERROR] - MAYOR_QUE\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }
    ;}
    break;

  case 26:

/* Line 1464 of yacc.c  */
#line 829 "../src/gramatica_python.y"
    {
        
        //MAYOR_IGUAL_QUE de numero / numero
        if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[0]) == 0) {  //comprobacion del tipo
            printf("> [COMPARACION] - MAYOR_IGUAL_QUE {numero / numero}\n");
            (yyval.tr).n = crearNodoNoTerminal((yyvsp[(1) - (3)].tr).n, (yyvsp[(3) - (3)].tr).n, 22);
            (yyval.tr).tipo = tipos[3]; 
            if ((yyvsp[(1) - (3)].tr).numero > (yyvsp[(3) - (3)].tr).numero || (yyvsp[(1) - (3)].tr).numero == (yyvsp[(3) - (3)].tr).numero) {
                printf("Verdadero %d es mayor o igual que %d\n", (yyvsp[(1) - (3)].tr), (yyvsp[(3) - (3)].tr));
                (yyval.tr).boolean = 1; // Verdadero
            }
            else {
                printf("Falso %d no es mayor o igual que %d\n", (yyvsp[(1) - (3)].tr), (yyvsp[(3) - (3)].tr));
                (yyval.tr).boolean = 0;
            }
        }

        //MAYOR_IGUAL_QUE de decimal / decimal
        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[1]) == 0){  //comprobacion del tipo
            printf("> [COMPARACION] - MAYOR_IGUAL_QUE {decimal / decimal}\n");
            (yyval.tr).n = crearNodoNoTerminal((yyvsp[(1) - (3)].tr).n, (yyvsp[(3) - (3)].tr).n, 22);
            (yyval.tr).tipo = tipos[3]; 
            if ((yyvsp[(1) - (3)].tr).decimal > (yyvsp[(3) - (3)].tr).decimal || (yyvsp[(1) - (3)].tr).decimal == (yyvsp[(3) - (3)].tr).decimal) {
                printf("Verdadero %d es mayor o igual que %d\n", (yyvsp[(1) - (3)].tr), (yyvsp[(3) - (3)].tr));
                (yyval.tr).boolean = 1; // Verdadero
            }
            else {
                printf("Falso %d no es mayor o igual que %d\n", (yyvsp[(1) - (3)].tr), (yyvsp[(3) - (3)].tr));
                (yyval.tr).boolean = 0;
            }
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[1]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MAYOR_IGUAL_QUE {numero / decimal}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[0]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[2]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MAYOR_IGUAL_QUE {numero / string}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[0]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MAYOR_IGUAL_QUE {decimal / numero}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[1]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[2]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MAYOR_IGUAL_QUE {decimal / string}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[2]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[0]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MAYOR_IGUAL_QUE {string / numero}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else if (strcmp((yyvsp[(1) - (3)].tr).tipo, tipos[2]) == 0 && strcmp((yyvsp[(3) - (3)].tr).tipo, tipos[1]) == 0){  //comprobacion del tipo
            yyerror("> [ERROR] - MAYOR_IGUAL_QUE {string / decimal}\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }

        else{
            yyerror("> [ERROR] - MAYOR_IGUAL_QUE\n");
            printf("ERROR EN LA LINEA %d\n", num_linea);
        }
    ;}
    break;

  case 27:

/* Line 1464 of yacc.c  */
#line 896 "../src/gramatica_python.y"
    {(yyval.tr) = (yyvsp[(1) - (1)].tr);;}
    break;

  case 28:

/* Line 1464 of yacc.c  */
#line 907 "../src/gramatica_python.y"
    {
        printf(" VARIABLE %s\n",(yyvsp[(1) - (1)].strVal));
        //Buscamos en la tabla el VARIABLE
        if(buscarTabla(indice, (yyvsp[(1) - (1)].strVal), tabla) != -1){     //En este IF entra si buscarTabla devuelve la posicion
            int pos = buscarTabla(indice, (yyvsp[(1) - (1)].strVal), tabla);
            //Para si es de tipo numero
            if(tabla[pos].tipo==tipos[0]){
                (yyval.tr).tipo = tabla[pos].tipo; 
                (yyval.tr).numero=tabla[pos].numero; 
                (yyval.tr).n = crearVariableTerminalInt(tabla[pos].numero, tabla[pos].registro);  //Creamos un nodo terminal con los numeros   
            }
            //Para si es de tipo decimal
            else if(tabla[pos].tipo==tipos[1]){
                (yyval.tr).tipo = tabla[pos].tipo; 
                (yyval.tr).decimal=tabla[pos].decimal;
                (yyval.tr).n = crearVariableTerminalDouble(tabla[pos].decimal, tabla[pos].registro); //Creamos un nodo terminal con los numeros        
            }
            //Para si es de tipo texto
            else if(tabla[pos].tipo==tipos[2]){
                (yyval.tr).tipo = tabla[pos].tipo; 
                (yyval.tr).texto=tabla[pos].texto;
                (yyval.tr).n = crearVariableTerminalString(tabla[pos].texto, tabla[pos].registro); //Creamos un nodo terminal con el texto        
            }
            //Para si es de tipo boolean
            else if(tabla[pos].tipo==tipos[3]){
                (yyval.tr).tipo = tabla[pos].tipo; 
                (yyval.tr).texto=tabla[pos].boolean;
                (yyval.tr).n = crearVariableTerminalBoolean(tabla[pos].boolean, tabla[pos].registro); //Creamos un nodo terminal con el boolean        
            }
        }
    ;}
    break;

  case 29:

/* Line 1464 of yacc.c  */
#line 940 "../src/gramatica_python.y"
    {
        (yyval.tr).numero = (yyvsp[(1) - (1)].intVal);
        printf("\n> [TIPO] - Numero Positivo: %ld\n", (yyval.tr).numero);
        (yyval.tr).tipo = tipos[0]; 
        (yyval.tr).n = crearNodoTerminalInt((yyvsp[(1) - (1)].intVal)); 
    ;}
    break;

  case 30:

/* Line 1464 of yacc.c  */
#line 948 "../src/gramatica_python.y"
    {
        (yyval.tr).decimal = (yyvsp[(1) - (1)].realVal);
        printf("\n> [TIPO] - Decimal: %.3f\n", (yyval.tr).decimal); 
        (yyval.tr).tipo = tipos[1];  
        (yyval.tr).n = crearNodoTerminalDouble((yyvsp[(1) - (1)].realVal));
    ;}
    break;

  case 31:

/* Line 1464 of yacc.c  */
#line 956 "../src/gramatica_python.y"
    {
        (yyval.tr).texto = (yyvsp[(1) - (1)].strVal);
        printf("\n> [TIPO] - Texto: %s\n", (yyval.tr).texto);
        (yyval.tr).tipo = tipos[2];
        (yyval.tr).n = crearNodoTerminalString((yyvsp[(1) - (1)].strVal)); 
    ;}
    break;

  case 32:

/* Line 1464 of yacc.c  */
#line 964 "../src/gramatica_python.y"
    {
        (yyval.tr).boolean = 1;
        printf("\n> [TIPO] - Boleano True: %d\n", (yyval.tr).boolean); 
        (yyval.tr).tipo = tipos[3];
        (yyval.tr).n = crearNodoTerminalBoolean((yyval.tr).boolean);
    ;}
    break;

  case 33:

/* Line 1464 of yacc.c  */
#line 971 "../src/gramatica_python.y"
    {
        (yyval.tr).boolean = 0;
        printf("\n> [TIPO] - Boleano False: %d\n", (yyval.tr).boolean); 
        (yyval.tr).tipo = tipos[3];
        (yyval.tr).n = crearNodoTerminalBoolean((yyval.tr).boolean);
    ;}
    break;

  case 34:

/* Line 1464 of yacc.c  */
#line 983 "../src/gramatica_python.y"
    { 
        printf("> [SENTENCIA] - Imprimir\n");
        (yyval.tr).n = crearNodoNoTerminal((yyvsp[(3) - (4)].tr).n, crearNodoVacio(), 16); 
    ;}
    break;



/* Line 1464 of yacc.c  */
#line 2513 "gramatica_python.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1684 of yacc.c  */
#line 989 "../src/gramatica_python.y"
 

//--------------------------------------------------- METODO MAIN -----------------------------------------------
int main(int argc, char** argv) {
    yyin = fopen(argv[1], "rt");            //Apertura del archivo test.py
    yyout = fopen( "./python.asm", "wt" );
    if (yyout == NULL) {
        perror("Error abriendo el archivo de salida");
        return 1;
    }
    printf("Archivo de salida abierto correctamente.\n");  //Para el archivo .ASM con nombre "python.asm"
	yyparse();
    fclose(yyin);
    return 0;
}

//Metodo yyerror, generado por defecto
void yyerror(const char* s) {
    fprintf(stderr, "----- ERROR EN LA LINEA %d: %s -----", num_linea, s);
}
