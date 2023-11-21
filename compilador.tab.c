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
#line 6 "compilador.y"

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "compilador.h"
#include "rotulos.h"
#include "tabelaSimbolos.h"


int num_vars = 0;
int novasVariaveis, deslocamento, nivel_lexico, esta_no_procedimento, qnt_var_parametro, qnt_novas_var_parametro;
int num_Rotulos=0;
TypeTabelaSimbolosPilha tabela_simbolos;
type_infos_tabela_simbolos *nova_entrada, *procedimento_atual, *destino, *carregada, *procedimento_atual;
char *rotuloAtual;
pilha_rotulo pilhaRotulo;
pilha_Tipo tabelaTipo;

char sinal_da_comparacao[10];


#line 94 "compilador.tab.c"

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

#include "compilador.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PROGRAM = 3,                    /* PROGRAM  */
  YYSYMBOL_ABRE_PARENTESES = 4,            /* ABRE_PARENTESES  */
  YYSYMBOL_FECHA_PARENTESES = 5,           /* FECHA_PARENTESES  */
  YYSYMBOL_VIRGULA = 6,                    /* VIRGULA  */
  YYSYMBOL_PONTO_E_VIRGULA = 7,            /* PONTO_E_VIRGULA  */
  YYSYMBOL_DOIS_PONTOS = 8,                /* DOIS_PONTOS  */
  YYSYMBOL_PONTO = 9,                      /* PONTO  */
  YYSYMBOL_T_BEGIN = 10,                   /* T_BEGIN  */
  YYSYMBOL_T_END = 11,                     /* T_END  */
  YYSYMBOL_VAR = 12,                       /* VAR  */
  YYSYMBOL_IDENT = 13,                     /* IDENT  */
  YYSYMBOL_ATRIBUICAO = 14,                /* ATRIBUICAO  */
  YYSYMBOL_NUMERO = 15,                    /* NUMERO  */
  YYSYMBOL_INTEGER = 16,                   /* INTEGER  */
  YYSYMBOL_PROCEDURE = 17,                 /* PROCEDURE  */
  YYSYMBOL_WHILE = 18,                     /* WHILE  */
  YYSYMBOL_DO = 19,                        /* DO  */
  YYSYMBOL_IF = 20,                        /* IF  */
  YYSYMBOL_THEN = 21,                      /* THEN  */
  YYSYMBOL_ELSE = 22,                      /* ELSE  */
  YYSYMBOL_IGUAL = 23,                     /* IGUAL  */
  YYSYMBOL_DIFERENTE = 24,                 /* DIFERENTE  */
  YYSYMBOL_MENOR = 25,                     /* MENOR  */
  YYSYMBOL_MENOR_IGUAL = 26,               /* MENOR_IGUAL  */
  YYSYMBOL_MAIOR_IGUAL = 27,               /* MAIOR_IGUAL  */
  YYSYMBOL_MAIOR = 28,                     /* MAIOR  */
  YYSYMBOL_SOMA = 29,                      /* SOMA  */
  YYSYMBOL_SUBTRACAO = 30,                 /* SUBTRACAO  */
  YYSYMBOL_MULTIPLICACAO = 31,             /* MULTIPLICACAO  */
  YYSYMBOL_DIVISAO = 32,                   /* DIVISAO  */
  YYSYMBOL_DIV = 33,                       /* DIV  */
  YYSYMBOL_AND = 34,                       /* AND  */
  YYSYMBOL_READ = 35,                      /* READ  */
  YYSYMBOL_WRITE = 36,                     /* WRITE  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_programa = 38,                  /* programa  */
  YYSYMBOL_39_1 = 39,                      /* $@1  */
  YYSYMBOL_parametros_ou_nada = 40,        /* parametros_ou_nada  */
  YYSYMBOL_parametros = 41,                /* parametros  */
  YYSYMBOL_nada = 42,                      /* nada  */
  YYSYMBOL_bloco = 43,                     /* bloco  */
  YYSYMBOL_44_2 = 44,                      /* $@2  */
  YYSYMBOL_45_3 = 45,                      /* $@3  */
  YYSYMBOL_parte_declara_vars = 46,        /* parte_declara_vars  */
  YYSYMBOL_var = 47,                       /* var  */
  YYSYMBOL_declara_vars = 48,              /* declara_vars  */
  YYSYMBOL_parte_declara_sub_rotinas = 49, /* parte_declara_sub_rotinas  */
  YYSYMBOL_50_4 = 50,                      /* $@4  */
  YYSYMBOL_regra_sub_rotina = 51,          /* regra_sub_rotina  */
  YYSYMBOL_declara_procedimento = 52,      /* declara_procedimento  */
  YYSYMBOL_53_5 = 53,                      /* $@5  */
  YYSYMBOL_parametros_formais_ou_nada = 54, /* parametros_formais_ou_nada  */
  YYSYMBOL_parametros_formais = 55,        /* parametros_formais  */
  YYSYMBOL_secao_parametros_formais = 56,  /* secao_parametros_formais  */
  YYSYMBOL_var_ou_nada = 57,               /* var_ou_nada  */
  YYSYMBOL_declara_var = 58,               /* declara_var  */
  YYSYMBOL_59_6 = 59,                      /* $@6  */
  YYSYMBOL_60_7 = 60,                      /* $@7  */
  YYSYMBOL_tipo = 61,                      /* tipo  */
  YYSYMBOL_lista_id_var = 62,              /* lista_id_var  */
  YYSYMBOL_lista_idents = 63,              /* lista_idents  */
  YYSYMBOL_comando_composto = 64,          /* comando_composto  */
  YYSYMBOL_comandos = 65,                  /* comandos  */
  YYSYMBOL_comando = 66,                   /* comando  */
  YYSYMBOL_67_8 = 67,                      /* $@8  */
  YYSYMBOL_numero_ou_nada = 68,            /* numero_ou_nada  */
  YYSYMBOL_69_9 = 69,                      /* $@9  */
  YYSYMBOL_comando_sem_rotulo = 70,        /* comando_sem_rotulo  */
  YYSYMBOL_read = 71,                      /* read  */
  YYSYMBOL_lista_leitura = 72,             /* lista_leitura  */
  YYSYMBOL_simbolo_leitura = 73,           /* simbolo_leitura  */
  YYSYMBOL_comando_atribuicao = 74,        /* comando_atribuicao  */
  YYSYMBOL_variavel = 75,                  /* variavel  */
  YYSYMBOL_numero = 76,                    /* numero  */
  YYSYMBOL_comando_while = 77,             /* comando_while  */
  YYSYMBOL_78_10 = 78,                     /* $@10  */
  YYSYMBOL_79_11 = 79,                     /* $@11  */
  YYSYMBOL_comando_if = 80,                /* comando_if  */
  YYSYMBOL_if_then = 81,                   /* if_then  */
  YYSYMBOL_82_12 = 82,                     /* $@12  */
  YYSYMBOL_83_13 = 83,                     /* $@13  */
  YYSYMBOL_84_14 = 84,                     /* $@14  */
  YYSYMBOL_cond_else = 85,                 /* cond_else  */
  YYSYMBOL_expressao = 86,                 /* expressao  */
  YYSYMBOL_relacao_expressao_simples = 87, /* relacao_expressao_simples  */
  YYSYMBOL_relacao = 88,                   /* relacao  */
  YYSYMBOL_expressao_simples = 89,         /* expressao_simples  */
  YYSYMBOL_90_15 = 90,                     /* $@15  */
  YYSYMBOL_mais_ou_menos = 91,             /* mais_ou_menos  */
  YYSYMBOL_termo = 92,                     /* termo  */
  YYSYMBOL_lista_fator = 93,               /* lista_fator  */
  YYSYMBOL_fator = 94,                     /* fator  */
  YYSYMBOL_expressao_mais_menos_termo = 95, /* expressao_mais_menos_termo  */
  YYSYMBOL_lista_e_termo = 96              /* lista_e_termo  */
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   133

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  60
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  146

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


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
      35,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    40,    40,    40,    55,    58,    62,    64,    70,    79,
      69,    90,   100,   101,   104,   105,   110,   110,   114,   116,
     116,   120,   119,   146,   146,   149,   149,   155,   157,   157,
     165,   170,   165,   180,   188,   199,   207,   209,   213,   215,
     216,   220,   220,   225,   225,   227,   232,   234,   235,   236,
     237,   239,   241,   244,   244,   247,   273,   291,   316,   328,
     341,   328,   364,   367,   367,   368,   367,   385,   396,   401,
     401,   408,   411,   414,   417,   420,   423,   430,   430,   434,
     434,   434,   440,   440,   445,   448,   451,   454,   459,   459,
     535,   535,   539,   542
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
  "\"end of file\"", "error", "\"invalid token\"", "PROGRAM",
  "ABRE_PARENTESES", "FECHA_PARENTESES", "VIRGULA", "PONTO_E_VIRGULA",
  "DOIS_PONTOS", "PONTO", "T_BEGIN", "T_END", "VAR", "IDENT", "ATRIBUICAO",
  "NUMERO", "INTEGER", "PROCEDURE", "WHILE", "DO", "IF", "THEN", "ELSE",
  "IGUAL", "DIFERENTE", "MENOR", "MENOR_IGUAL", "MAIOR_IGUAL", "MAIOR",
  "SOMA", "SUBTRACAO", "MULTIPLICACAO", "DIVISAO", "DIV", "AND", "READ",
  "WRITE", "$accept", "programa", "$@1", "parametros_ou_nada",
  "parametros", "nada", "bloco", "$@2", "$@3", "parte_declara_vars", "var",
  "declara_vars", "parte_declara_sub_rotinas", "$@4", "regra_sub_rotina",
  "declara_procedimento", "$@5", "parametros_formais_ou_nada",
  "parametros_formais", "secao_parametros_formais", "var_ou_nada",
  "declara_var", "$@6", "$@7", "tipo", "lista_id_var", "lista_idents",
  "comando_composto", "comandos", "comando", "$@8", "numero_ou_nada",
  "$@9", "comando_sem_rotulo", "read", "lista_leitura", "simbolo_leitura",
  "comando_atribuicao", "variavel", "numero", "comando_while", "$@10",
  "$@11", "comando_if", "if_then", "$@12", "$@13", "$@14", "cond_else",
  "expressao", "relacao_expressao_simples", "relacao", "expressao_simples",
  "$@15", "mais_ou_menos", "termo", "lista_fator", "fator",
  "expressao_mais_menos_termo", "lista_e_termo", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-92)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-31)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -92,     9,    28,   -92,    14,    43,    21,    42,   -92,   -92,
     -92,    11,    39,   -92,    40,   -92,    53,   -92,   -92,   -92,
      50,   -92,    52,   -92,   -92,   -92,   -92,     2,   -92,   -92,
      47,    54,    55,    56,    57,   -92,   -92,   -92,    58,   -92,
      59,   -92,   -92,   -92,    62,   -92,   -92,     7,   -92,   -92,
     -92,   -92,   -92,    58,   -92,    -7,    67,     3,   -92,   -92,
     -92,   -92,    66,   -92,   -92,   -92,   -92,   -92,    63,   -92,
     -92,    60,   -92,     3,   -92,    65,    69,   -92,   -92,    21,
      25,    25,    68,    25,   -92,   -92,   -92,    72,    39,    24,
     -92,   -92,   -92,    61,    -2,   -92,   -92,   -92,    51,   -92,
     -92,    71,   -92,    55,   -92,   -92,   -92,   -92,   -92,   -92,
     -92,   -92,   -92,    25,    30,   -92,   -92,    68,   -92,   -92,
      56,   -92,   -92,   -92,     4,   -92,    29,    70,   -92,   -92,
      30,    30,    30,    30,   -92,    30,    30,   -92,    -7,   -92,
     -92,   -92,   -92,     4,     4,   -92
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,     0,     7,     0,     0,     4,     5,
      37,     0,    30,     6,     0,    30,     0,     8,    11,    13,
       0,    36,    12,    15,     3,     7,    35,     0,    14,    18,
       9,     0,     0,     0,     7,    34,    33,    31,     7,    10,
       0,    20,    17,    19,     0,    58,    45,     0,    40,    41,
      43,    21,    32,     7,    38,     7,     0,     7,    39,    57,
      59,    63,     0,    51,    47,    42,    50,    46,     0,    49,
      48,     0,    44,     7,    28,    24,     0,    23,    26,     0,
       7,     7,     0,     7,    67,    62,    29,     0,    30,     0,
      79,    80,    81,     0,     7,    77,    64,    55,     0,    54,
      56,     7,    22,     0,    60,    71,    72,    73,    74,    76,
      75,    70,    68,     7,     0,    65,    52,     0,    25,    27,
       0,    69,    89,    88,    91,    83,    78,     0,    53,    61,
       0,     0,     0,     0,    82,     0,     0,    90,     7,    84,
      85,    86,    87,    92,    93,    66
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -92,   -92,   -92,   -92,   -92,    -5,    -4,   -92,   -92,   -92,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,    13,   -14,
     -92,   -10,   -92,   -92,   -13,   -92,    15,   -32,   -92,    44,
     -92,   -92,   -92,   -46,   -92,   -92,   -24,   -92,   -53,   -34,
     -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -92,   -37,
     -92,   -92,   -18,   -92,   -92,   -75,   -92,   -91,   -92,   -92
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     7,     8,    92,    16,    25,    33,    17,
      18,    22,    30,    34,    42,    43,    57,    76,    77,    78,
      79,    19,    20,    44,    37,    27,    11,    64,    47,    48,
      55,    49,    56,    65,    66,    98,    99,    67,   122,   123,
      69,    80,   120,    70,    71,    81,   115,   127,    85,    93,
     112,   113,    94,   114,    95,   124,   134,   125,   126,   137
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       9,    39,    68,    38,    50,    23,    59,    73,    31,     3,
      32,    60,    28,    61,    53,    74,    13,    14,    54,    50,
      29,   105,   106,   107,   108,   109,   110,     5,    62,    41,
      14,     4,   103,    46,    10,   130,   131,   132,   133,   139,
     140,   141,   142,    59,    96,    45,   100,     6,    46,    12,
      63,    15,    75,    21,    90,    91,   116,   117,   135,   136,
     143,   144,    24,    26,   -16,   -30,    38,    35,    86,    52,
      82,    36,    51,    45,    40,    72,    88,    83,   -29,   101,
     104,    97,    84,    74,   102,    68,    87,   118,   129,   111,
     119,   138,   145,   128,    89,   121,    86,    58,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    63
};

static const yytype_int16 yycheck[] =
{
       5,    33,    55,    10,    38,    15,    13,     4,     6,     0,
       8,    18,    22,    20,     7,    12,     5,     6,    11,    53,
      25,    23,    24,    25,    26,    27,    28,    13,    35,    34,
       6,     3,     8,    38,    13,    31,    32,    33,    34,   130,
     131,   132,   133,    13,    81,    15,    83,     4,    53,     7,
      55,    12,    57,    13,    29,    30,     5,     6,    29,    30,
     135,   136,     9,    13,    17,    13,    10,    13,    73,     7,
       4,    16,    13,    15,    17,     8,     7,    14,    13,     7,
      19,    13,    22,    12,    88,   138,    73,   101,   120,    94,
     103,    21,   138,   117,    79,   113,   101,    53,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   138
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    38,    39,     0,     3,    13,     4,    40,    41,    42,
      13,    63,     7,     5,     6,    12,    43,    46,    47,    58,
      59,    13,    48,    58,     9,    44,    13,    62,    58,    42,
      49,     6,     8,    45,    50,    13,    16,    61,    10,    64,
      17,    42,    51,    52,    60,    15,    42,    65,    66,    68,
      76,    13,     7,     7,    11,    67,    69,    53,    66,    13,
      18,    20,    35,    42,    64,    70,    71,    74,    75,    77,
      80,    81,     8,     4,    12,    42,    54,    55,    56,    57,
      78,    82,     4,    14,    22,    85,    42,    55,     7,    63,
      29,    30,    42,    86,    89,    91,    86,    13,    72,    73,
      86,     7,    43,     8,    19,    23,    24,    25,    26,    27,
      28,    42,    87,    88,    90,    83,     5,     6,    56,    61,
      79,    89,    75,    76,    92,    94,    95,    84,    73,    64,
      31,    32,    33,    34,    93,    29,    30,    96,    21,    94,
      94,    94,    94,    92,    92,    70
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    39,    38,    40,    40,    41,    42,    44,    45,
      43,    46,    47,    47,    48,    48,    50,    49,    49,    51,
      51,    53,    52,    54,    54,    55,    55,    56,    57,    57,
      59,    60,    58,    61,    62,    62,    63,    63,    64,    65,
      65,    67,    66,    69,    68,    68,    70,    70,    70,    70,
      70,    70,    71,    72,    72,    73,    74,    75,    76,    78,
      79,    77,    80,    82,    83,    84,    81,    85,    86,    87,
      87,    88,    88,    88,    88,    88,    88,    90,    89,    91,
      91,    91,    92,    92,    93,    93,    93,    93,    94,    94,
      95,    95,    96,    96
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     7,     1,     1,     3,     0,     0,     0,
       5,     1,     2,     1,     2,     1,     0,     3,     1,     1,
       1,     0,     6,     1,     1,     4,     1,     4,     1,     1,
       0,     0,     6,     1,     3,     1,     3,     1,     3,     3,
       1,     0,     3,     0,     3,     1,     1,     1,     1,     1,
       1,     1,     4,     3,     1,     1,     3,     1,     1,     0,
       0,     6,     2,     0,     0,     0,     7,     1,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     0,     3,     1,
       1,     1,     2,     1,     2,     2,     2,     2,     1,     1,
       2,     1,     2,     2
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
  case 2: /* $@1: %empty  */
#line 40 "compilador.y"
             { //TODO: rever todo esse bloco
             geraCodigo (NULL, "INPP");
             char * RotInicioSubrotina = cria_rotulo(num_Rotulos);
						 num_Rotulos++;
						 push_tabela_rotulos(&pilhaRotulo, RotInicioSubrotina);
             }
#line 1294 "compilador.tab.c"
    break;

  case 3: /* programa: $@1 PROGRAM IDENT parametros_ou_nada PONTO_E_VIRGULA bloco PONTO  */
#line 47 "compilador.y"
                         {
               char dmem[1000];
               sprintf(dmem, "DMEM %d", num_vars);
               geraCodigo(NULL, dmem);
               geraCodigo (NULL, "PARA");
             }
#line 1305 "compilador.tab.c"
    break;

  case 4: /* parametros_ou_nada: parametros  */
#line 55 "compilador.y"
                               {

}
#line 1313 "compilador.tab.c"
    break;

  case 5: /* parametros_ou_nada: nada  */
#line 58 "compilador.y"
                         {

                  }
#line 1321 "compilador.tab.c"
    break;

  case 7: /* nada: %empty  */
#line 64 "compilador.y"
      {

}
#line 1329 "compilador.tab.c"
    break;

  case 8: /* $@2: %empty  */
#line 70 "compilador.y"
              {
               // momento em que é feita a parte do desvio
               // cria um novo rotulo
               char rotuloPrint[100];
               rotuloAtual = pega_rotulo(&pilhaRotulo,0);
               sprintf(rotuloPrint, "DSVS %s", rotuloAtual);
               geraCodigo(NULL, rotuloPrint);
              }
#line 1342 "compilador.tab.c"
    break;

  case 9: /* $@3: %empty  */
#line 79 "compilador.y"
              {
               char rotuloPrint[100];
               rotuloAtual = pega_rotulo(&pilhaRotulo,0);
               sprintf(rotuloPrint, "%s", rotuloAtual);
               geraCodigo(rotuloPrint, "NADA");
              }
#line 1353 "compilador.tab.c"
    break;

  case 11: /* parte_declara_vars: var  */
#line 90 "compilador.y"
                         {
      char amem[100];
		sprintf(amem, "AMEM %d", num_vars);
		atualizaNumeroVariaveis(&tabela_simbolos, num_vars, nivel_lexico);
		geraCodigo(NULL, amem);
}
#line 1364 "compilador.tab.c"
    break;

  case 16: /* $@4: %empty  */
#line 110 "compilador.y"
                                                     {


}
#line 1373 "compilador.tab.c"
    break;

  case 21: /* $@5: %empty  */
#line 120 "compilador.y"
{

//TODO: implementar
   nivel_lexico++;
   // cria os rotulos de entrada e saida do procedimento, e add eles na pilha de rotulos
   char *entraProcedimento = cria_rotulo(num_Rotulos);
   num_Rotulos++;
   push_tabela_rotulos(&pilhaRotulo, entraProcedimento);

   char *saiProcedimento = cria_rotulo(num_Rotulos);
   num_Rotulos++;
   push_tabela_rotulos(&pilhaRotulo, saiProcedimento);

   //faz a impressao do mepa
   char printRotuloEntrada[100];
   sprintf(printRotuloEntrada, "ENPR %d", nivel_lexico);
	geraCodigo(pega_rotulo(&pilhaRotulo, 2), printRotuloEntrada);
   // TODO: criar tipo de variavel para procedimento e add na tabela de simbolos
   nova_entrada=criaVariavelSimplesProcedimento(token,nivel_lexico, 0, entraProcedimento);
   push_tabela_simbolos(&tabela_simbolos, nova_entrada);


   procedimento_atual = nova_entrada;

}
#line 1403 "compilador.tab.c"
    break;

  case 30: /* $@6: %empty  */
#line 165 "compilador.y"
              {
   novasVariaveis= 0;
}
#line 1411 "compilador.tab.c"
    break;

  case 31: /* $@7: %empty  */
#line 170 "compilador.y"
              { /* AMEM */
               // atualiza quantas variaveis tem
               num_vars+=novasVariaveis;

               //para usar amem tem que saber qual deslocamento
               //TODO: implementar
              }
#line 1423 "compilador.tab.c"
    break;

  case 33: /* tipo: INTEGER  */
#line 180 "compilador.y"
                      {

   setaTipo(&tabela_simbolos, integer, novasVariaveis);
}
#line 1432 "compilador.tab.c"
    break;

  case 34: /* lista_id_var: lista_id_var VIRGULA IDENT  */
#line 189 "compilador.y"
              { /* insere ultima vars na tabela de s�mbolos */
               novasVariaveis++;
               //  add na tabela de simbolos
               nova_entrada = criaVariavelSimples(token,nivel_lexico,deslocamento);
               push_tabela_simbolos(&tabela_simbolos, nova_entrada);
               deslocamento++;


               //  no futuro setar o valor de deslocamento tb
                }
#line 1447 "compilador.tab.c"
    break;

  case 35: /* lista_id_var: IDENT  */
#line 199 "compilador.y"
                    { /* insere vars na tabela de s�mbolos */
               novasVariaveis++;
               nova_entrada = criaVariavelSimples(token,nivel_lexico,deslocamento);
               push_tabela_simbolos(&tabela_simbolos, nova_entrada);
               deslocamento++;
               }
#line 1458 "compilador.tab.c"
    break;

  case 41: /* $@8: %empty  */
#line 220 "compilador.y"
                       {

}
#line 1466 "compilador.tab.c"
    break;

  case 43: /* $@9: %empty  */
#line 225 "compilador.y"
                       {

}
#line 1474 "compilador.tab.c"
    break;

  case 45: /* numero_ou_nada: nada  */
#line 227 "compilador.y"
                     {

}
#line 1482 "compilador.tab.c"
    break;

  case 55: /* simbolo_leitura: IDENT  */
#line 248 "compilador.y"
        {
		geraCodigo(NULL, "LEIT");
		destino = busca_tabela_simbolos(&tabela_simbolos, token);
		if(destino == NULL) {
			printf("Variavel nao encontrada.\n");
			exit(1);
		}

      char print[1000];
		sprintf(print, "ARMZ %d, %d", destino->nivel_lexico, destino->deslocamento);
		geraCodigo(NULL, print);
		destino = NULL;
	}
#line 1500 "compilador.tab.c"
    break;

  case 56: /* comando_atribuicao: variavel ATRIBUICAO expressao  */
#line 274 "compilador.y"
{


		verifica_tipo(&tabelaTipo, "atribuicao");
		char printARM[100];
      // verifica o tipo de passagem de parametro
      printf("passagem de parametro %d\n", destino->passagem_parametro);
		if (destino->passagem_parametro == VALOR)
			sprintf(printARM, "ARMZ %d, %d", destino->nivel_lexico, destino->deslocamento);
		else
			sprintf(printARM, "ARMI %d, %d", destino->nivel_lexico, destino->deslocamento);
		geraCodigo(NULL, printARM);
		destino = NULL;
	}
#line 1519 "compilador.tab.c"
    break;

  case 57: /* variavel: IDENT  */
#line 291 "compilador.y"
                {
   if (destino == NULL) {
         printf("Variavel nao declarada: %s\n", token);
         destino = busca_tabela_simbolos(&tabela_simbolos, token);

         if (destino == NULL) {
            printf("Variavel nao declarada: %s\n", token);
            exit(1);
         }

         push_pilha_Tipo(&tabelaTipo, destino->type);

   }
   else
    {
         printf("Variavel entrou em carregada: %s\n", token);

      carregada = busca_tabela_simbolos(&tabela_simbolos, token);
      if (carregada == NULL) {

         exit(1);
      }
      push_pilha_Tipo(&tabelaTipo, carregada->type);
   }
}
#line 1549 "compilador.tab.c"
    break;

  case 58: /* numero: NUMERO  */
#line 316 "compilador.y"
               {
	//TODO: add na tabela de tipos

		push_pilha_Tipo(&tabelaTipo, integer);

	    char totalVars[100];
		sprintf(totalVars, "CRCT %s", token);
		geraCodigo(NULL, totalVars);
}
#line 1563 "compilador.tab.c"
    break;

  case 59: /* $@10: %empty  */
#line 328 "compilador.y"
                     {
   //Cria rotulos do inicio e fim do While e adiciona eles na pilha de rotulos
      char *inicio_while = cria_rotulo(num_Rotulos);
      num_Rotulos++;
      char *fim_while = cria_rotulo(num_Rotulos);
      num_Rotulos++;

      push_tabela_rotulos(&pilhaRotulo, inicio_while);
      push_tabela_rotulos(&pilhaRotulo, fim_while);
      rotuloAtual = pega_rotulo(&pilhaRotulo, 2);
      geraCodigo(rotuloAtual, "NADA");

   }
#line 1581 "compilador.tab.c"
    break;

  case 60: /* $@11: %empty  */
#line 341 "compilador.y"
   {
      char dsvf[100];
      rotuloAtual = pega_rotulo(&pilhaRotulo, 1);
		sprintf(dsvf, "DSVF %s", rotuloAtual);
		geraCodigo(NULL, dsvf);
   }
#line 1592 "compilador.tab.c"
    break;

  case 61: /* comando_while: WHILE $@10 expressao DO $@11 comando_composto  */
#line 346 "compilador.y"
                      {

      char dsvs[100];
      rotuloAtual = pega_rotulo(&pilhaRotulo, 2);
		sprintf(dsvs, "DSVS %s",rotuloAtual);
		geraCodigo(NULL, dsvs);

		char rot[100];
      rotuloAtual = pega_rotulo(&pilhaRotulo, 1);
		sprintf(rot, "%s", rotuloAtual);
		geraCodigo(rot, "NADA");

		pop_tabela_rotulos(&pilhaRotulo, 2);
   }
#line 1611 "compilador.tab.c"
    break;

  case 62: /* comando_if: if_then cond_else  */
#line 364 "compilador.y"
                        {

       }
#line 1619 "compilador.tab.c"
    break;

  case 63: /* $@12: %empty  */
#line 367 "compilador.y"
           {}
#line 1625 "compilador.tab.c"
    break;

  case 64: /* $@13: %empty  */
#line 367 "compilador.y"
                       {}
#line 1631 "compilador.tab.c"
    break;

  case 65: /* $@14: %empty  */
#line 368 "compilador.y"
      {
      char *inicio_If = cria_rotulo(num_Rotulos);
      num_Rotulos++;
		char *fim_If = cria_rotulo(num_Rotulos);
		num_Rotulos++;

		push_tabela_rotulos(&pilhaRotulo, inicio_If);
		push_tabela_rotulos(&pilhaRotulo, fim_If);

		char rot[100];
		sprintf(rot, "DSVF %s", pega_rotulo(&pilhaRotulo, 1));
		geraCodigo(NULL, rot);

      }
#line 1650 "compilador.tab.c"
    break;

  case 67: /* cond_else: ELSE  */
#line 385 "compilador.y"
          {
         char rot[100];
         rotuloAtual = pega_rotulo(&pilhaRotulo, 2);
		   sprintf(rot, "DSVS %s", rotuloAtual);
		   geraCodigo(NULL, rot);

         rotuloAtual = pega_rotulo(&pilhaRotulo, 1);
		   geraCodigo(rotuloAtual, "NADA");
      }
#line 1664 "compilador.tab.c"
    break;

  case 68: /* expressao: expressao_simples relacao_expressao_simples  */
#line 396 "compilador.y"
                                                       {

}
#line 1672 "compilador.tab.c"
    break;

  case 70: /* relacao_expressao_simples: nada  */
#line 402 "compilador.y"
{

}
#line 1680 "compilador.tab.c"
    break;

  case 71: /* relacao: IGUAL  */
#line 408 "compilador.y"
              {
      strcpy(sinal_da_comparacao,"CMIG");
   }
#line 1688 "compilador.tab.c"
    break;

  case 72: /* relacao: DIFERENTE  */
#line 411 "compilador.y"
                    {
      strcpy(sinal_da_comparacao,"CMDG");
   }
#line 1696 "compilador.tab.c"
    break;

  case 73: /* relacao: MENOR  */
#line 414 "compilador.y"
                {
      strcpy(sinal_da_comparacao,"CMME");
   }
#line 1704 "compilador.tab.c"
    break;

  case 74: /* relacao: MENOR_IGUAL  */
#line 417 "compilador.y"
                      {
      strcpy(sinal_da_comparacao,"CMEG");
   }
#line 1712 "compilador.tab.c"
    break;

  case 75: /* relacao: MAIOR  */
#line 420 "compilador.y"
           {
      strcpy(sinal_da_comparacao,"CMMA");
   }
#line 1720 "compilador.tab.c"
    break;

  case 76: /* relacao: MAIOR_IGUAL  */
#line 423 "compilador.y"
                      {
      strcpy(sinal_da_comparacao,"CMAG");
   }
#line 1728 "compilador.tab.c"
    break;

  case 77: /* $@15: %empty  */
#line 430 "compilador.y"
                                 {

}
#line 1736 "compilador.tab.c"
    break;

  case 81: /* mais_ou_menos: nada  */
#line 434 "compilador.y"
                                       {

}
#line 1744 "compilador.tab.c"
    break;

  case 83: /* termo: fator  */
#line 440 "compilador.y"
                                {

}
#line 1752 "compilador.tab.c"
    break;

  case 84: /* lista_fator: MULTIPLICACAO fator  */
#line 445 "compilador.y"
                            {
		verifica_tipo(&tabelaTipo, "multiplicacao");
		geraCodigo(NULL, "MULT");}
#line 1760 "compilador.tab.c"
    break;

  case 85: /* lista_fator: DIVISAO fator  */
#line 448 "compilador.y"
                        {
		verifica_tipo(&tabelaTipo, "divisao");
		geraCodigo(NULL, "DIVI"); }
#line 1768 "compilador.tab.c"
    break;

  case 86: /* lista_fator: DIV fator  */
#line 451 "compilador.y"
                    {
		verifica_tipo(&tabelaTipo, "div");
		geraCodigo(NULL, "DIVI"); }
#line 1776 "compilador.tab.c"
    break;

  case 87: /* lista_fator: AND fator  */
#line 454 "compilador.y"
                    {
		verifica_tipo(&tabelaTipo, "and");
		geraCodigo(NULL, "CONJ"); }
#line 1784 "compilador.tab.c"
    break;

  case 89: /* fator: variavel  */
#line 459 "compilador.y"
                         {
      if(carregada != NULL) {
			printf("variavel carregada: %s\n", carregada->rotulo);
         // verifica se é funcao
			if(carregada->categoria == funcao) {
				char chamaProcedure[100];
				sprintf(chamaProcedure, "CHPR %s, %d", carregada->rotulo, nivel_lexico);
				geraCodigo(NULL, chamaProcedure);

			}
         // se nao é funcao, faz CRVL, CRVI ou CREN
			else {
			char comando[100];
         int numero_parametros, passagem_parametro, eh_ref_carregada;

         if (esta_no_procedimento == 2) {
            numero_parametros = procedimento_atual->numero_parametros - qnt_var_parametro + 1;
         } else {
            numero_parametros = qnt_novas_var_parametro;
         }

         if (esta_no_procedimento == 0) {
            passagem_parametro = carregada->passagem_parametro;
         } else {
            passagem_parametro = procedimento_atual->parametros[procedimento_atual->numero_parametros - numero_parametros].tipo_passado;
         }

         eh_ref_carregada = (passagem_parametro == REFERENCIA && esta_no_procedimento == 1 && carregada->passagem_parametro == REFERENCIA);

         if (passagem_parametro == VALOR || eh_ref_carregada) {
            sprintf(comando, "CRVL %d, %d", carregada->nivel_lexico, carregada->deslocamento);
         } else if (esta_no_procedimento >= 1 && passagem_parametro == REFERENCIA) {
            sprintf(comando, "CREN %d, %d", carregada->nivel_lexico, carregada->deslocamento);
         } else {
            sprintf(comando, "CRVI %d, %d", carregada->nivel_lexico, carregada->deslocamento);
         }

         carregada = NULL;
         geraCodigo(NULL, comando);

			}
      }
      else {

			if(destino->categoria == funcao) {
				char chamaProcedure[100];
				sprintf(chamaProcedure, "CHPR %s, %d", destino->rotulo, nivel_lexico);
				geraCodigo(NULL, chamaProcedure);
			}
			else {
            char comando[100];
            int passagem_parametro, eh_ref;

            if (esta_no_procedimento == 0) {
               passagem_parametro = destino->passagem_parametro;
            } else {
               passagem_parametro = procedimento_atual->parametros[procedimento_atual->numero_parametros - qnt_novas_var_parametro].tipo_passado;
            }

            eh_ref = (passagem_parametro == REFERENCIA && esta_no_procedimento == 1 && destino->passagem_parametro == REFERENCIA);

            if (passagem_parametro == VALOR || eh_ref) {
               sprintf(comando, "CRVL %d, %d", destino->nivel_lexico, destino->deslocamento);
            } else if (esta_no_procedimento == 1 && passagem_parametro == REFERENCIA) {
               sprintf(comando, "CREN %d, %d", destino->nivel_lexico, destino->deslocamento);
            } else {
               sprintf(comando, "CRVI %d, %d", destino->nivel_lexico, destino->deslocamento);
            }

            destino = NULL;
            geraCodigo(NULL, comando);

			}
		}
}
#line 1864 "compilador.tab.c"
    break;

  case 92: /* lista_e_termo: SOMA termo  */
#line 539 "compilador.y"
                   {
		verifica_tipo(&tabelaTipo, "soma");
		geraCodigo(NULL, "SOMA");}
#line 1872 "compilador.tab.c"
    break;

  case 93: /* lista_e_termo: SUBTRACAO termo  */
#line 542 "compilador.y"
                          {
		verifica_tipo(&tabelaTipo, "subtracao");
		geraCodigo(NULL, "SUBT");}
#line 1880 "compilador.tab.c"
    break;


#line 1884 "compilador.tab.c"

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

#line 548 "compilador.y"


int main (int argc, char** argv) {
   FILE* fp;
   extern FILE* yyin;

   if (argc<2 || argc>2) {
         printf("usage compilador <arq>a %d\n", argc);
         return(-1);
      }

   fp=fopen (argv[1], "r");
   if (fp == NULL) {
      printf("usage compilador <arq>b\n");
      return(-1);
   }


/* -------------------------------------------------------------------
 *  Inicia a Tabela de S�mbolos
 * ------------------------------------------------------------------- */

   yyin=fp;
   yyparse();
   criar_tabela_simbolos(&tabela_simbolos);
   cria_pilha_rotulo(&pilhaRotulo);
   cria_pilha_Tipo(&tabelaTipo);

   return 0;
}
