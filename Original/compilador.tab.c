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
#include "tabelaSimbolos.h"
#include "pilha.h"

int por_ref, numero_variaveis, numero_parametros, aux_var, novas_variaveis, novos_param, nivel_lexico, deslocamento,numero_parametros_chamada;
unsigned int temElse, it_temElse;
int entra_procedimento;
char chama_proc[100];
char *rotulo_fim_subr;
int rotulo_print = 0;
int subrt = 0;
char comparacao[100], *funcao_atual;
pilha_simbolos tabelaSimbolos;
type_info_tabela_simbolos *novaEntrada, *variavelDestino, *variavel_carregada, *procedimentoAtual;
tipo_pilha tabelaTipo;
pilha_rotulo pilha_rotulos;
pilha_no pilhano;





#line 99 "compilador.tab.c"

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
  YYSYMBOL_INTEGER = 15,                   /* INTEGER  */
  YYSYMBOL_WHILE = 16,                     /* WHILE  */
  YYSYMBOL_DO = 17,                        /* DO  */
  YYSYMBOL_IF = 18,                        /* IF  */
  YYSYMBOL_THEN = 19,                      /* THEN  */
  YYSYMBOL_ELSE = 20,                      /* ELSE  */
  YYSYMBOL_MAIOR = 21,                     /* MAIOR  */
  YYSYMBOL_MENOR = 22,                     /* MENOR  */
  YYSYMBOL_MAIOR_IGUAL = 23,               /* MAIOR_IGUAL  */
  YYSYMBOL_MENOR_IGUAL = 24,               /* MENOR_IGUAL  */
  YYSYMBOL_IGUAL = 25,                     /* IGUAL  */
  YYSYMBOL_DIFERENTE = 26,                 /* DIFERENTE  */
  YYSYMBOL_SOMA = 27,                      /* SOMA  */
  YYSYMBOL_SUBTRACAO = 28,                 /* SUBTRACAO  */
  YYSYMBOL_MULTIPLICACAO = 29,             /* MULTIPLICACAO  */
  YYSYMBOL_DIVISAO = 30,                   /* DIVISAO  */
  YYSYMBOL_DIV = 31,                       /* DIV  */
  YYSYMBOL_NUMERO = 32,                    /* NUMERO  */
  YYSYMBOL_READ = 33,                      /* READ  */
  YYSYMBOL_WRITE = 34,                     /* WRITE  */
  YYSYMBOL_OR = 35,                        /* OR  */
  YYSYMBOL_AND = 36,                       /* AND  */
  YYSYMBOL_NOT = 37,                       /* NOT  */
  YYSYMBOL_PROCEDURE = 38,                 /* PROCEDURE  */
  YYSYMBOL_FUNCTION = 39,                  /* FUNCTION  */
  YYSYMBOL_YYACCEPT = 40,                  /* $accept  */
  YYSYMBOL_programa = 41,                  /* programa  */
  YYSYMBOL_42_1 = 42,                      /* $@1  */
  YYSYMBOL_parametros_ou_vazio = 43,       /* parametros_ou_vazio  */
  YYSYMBOL_parametros = 44,                /* parametros  */
  YYSYMBOL_tipo = 45,                      /* tipo  */
  YYSYMBOL_bloco = 46,                     /* bloco  */
  YYSYMBOL_47_2 = 47,                      /* $@2  */
  YYSYMBOL_48_3 = 48,                      /* $@3  */
  YYSYMBOL_parte_declara_vars = 49,        /* parte_declara_vars  */
  YYSYMBOL_parte_declara_sub_rotinas = 50, /* parte_declara_sub_rotinas  */
  YYSYMBOL_51_4 = 51,                      /* $@4  */
  YYSYMBOL_opcoes_sub_rotinas = 52,        /* opcoes_sub_rotinas  */
  YYSYMBOL_53_5 = 53,                      /* $@5  */
  YYSYMBOL_54_6 = 54,                      /* $@6  */
  YYSYMBOL_var = 55,                       /* var  */
  YYSYMBOL_declara_vars = 56,              /* declara_vars  */
  YYSYMBOL_declara_var = 57,               /* declara_var  */
  YYSYMBOL_58_7 = 58,                      /* $@7  */
  YYSYMBOL_59_8 = 59,                      /* $@8  */
  YYSYMBOL_lista_id_var = 60,              /* lista_id_var  */
  YYSYMBOL_lista_idents = 61,              /* lista_idents  */
  YYSYMBOL_declaracao_procedimento = 62,   /* declaracao_procedimento  */
  YYSYMBOL_63_9 = 63,                      /* $@9  */
  YYSYMBOL_64_10 = 64,                     /* $@10  */
  YYSYMBOL_65_11 = 65,                     /* $@11  */
  YYSYMBOL_66_12 = 66,                     /* $@12  */
  YYSYMBOL_declaracao_funcao = 67,         /* declaracao_funcao  */
  YYSYMBOL_68_13 = 68,                     /* $@13  */
  YYSYMBOL_69_14 = 69,                     /* $@14  */
  YYSYMBOL_70_15 = 70,                     /* $@15  */
  YYSYMBOL_71_16 = 71,                     /* $@16  */
  YYSYMBOL_parametros_formais_vazio = 72,  /* parametros_formais_vazio  */
  YYSYMBOL_parametros_formais = 73,        /* parametros_formais  */
  YYSYMBOL_74_17 = 74,                     /* $@17  */
  YYSYMBOL_lista_parametros_formais = 75,  /* lista_parametros_formais  */
  YYSYMBOL_76_18 = 76,                     /* $@18  */
  YYSYMBOL_secao_parametros_formais = 77,  /* secao_parametros_formais  */
  YYSYMBOL_78_19 = 78,                     /* $@19  */
  YYSYMBOL_var_vazio = 79,                 /* var_vazio  */
  YYSYMBOL_comando_composto = 80,          /* comando_composto  */
  YYSYMBOL_comandos = 81,                  /* comandos  */
  YYSYMBOL_comando = 82,                   /* comando  */
  YYSYMBOL_numero_ou_vazio = 83,           /* numero_ou_vazio  */
  YYSYMBOL_comando_vazio = 84,             /* comando_vazio  */
  YYSYMBOL_comando_sem_rotulo = 85,        /* comando_sem_rotulo  */
  YYSYMBOL_desvio = 86,                    /* desvio  */
  YYSYMBOL_comando_condicional = 87,       /* comando_condicional  */
  YYSYMBOL_if_then = 88,                   /* if_then  */
  YYSYMBOL_89_20 = 89,                     /* $@20  */
  YYSYMBOL_cond_else = 90,                 /* cond_else  */
  YYSYMBOL_91_21 = 91,                     /* $@21  */
  YYSYMBOL_else_multiplo_unico = 92,       /* else_multiplo_unico  */
  YYSYMBOL_chama_procedimento = 93,        /* chama_procedimento  */
  YYSYMBOL_94_22 = 94,                     /* $@22  */
  YYSYMBOL_95_23 = 95,                     /* $@23  */
  YYSYMBOL_96_24 = 96,                     /* $@24  */
  YYSYMBOL_97_25 = 97,                     /* $@25  */
  YYSYMBOL_chama_funcao = 98,              /* chama_funcao  */
  YYSYMBOL_99_26 = 99,                     /* $@26  */
  YYSYMBOL_100_27 = 100,                   /* $@27  */
  YYSYMBOL_101_28 = 101,                   /* $@28  */
  YYSYMBOL_lista_expressoes_ou_vazio = 102, /* lista_expressoes_ou_vazio  */
  YYSYMBOL_comando_repetitivo = 103,       /* comando_repetitivo  */
  YYSYMBOL_104_29 = 104,                   /* $@29  */
  YYSYMBOL_105_30 = 105,                   /* $@30  */
  YYSYMBOL_lista_expressoes = 106,         /* lista_expressoes  */
  YYSYMBOL_107_31 = 107,                   /* $@31  */
  YYSYMBOL_expressao = 108,                /* expressao  */
  YYSYMBOL_109_32 = 109,                   /* $@32  */
  YYSYMBOL_relacao_exp_simples_ou_vazio = 110, /* relacao_exp_simples_ou_vazio  */
  YYSYMBOL_relacao = 111,                  /* relacao  */
  YYSYMBOL_expressao_simples = 112,        /* expressao_simples  */
  YYSYMBOL_soma_ou_vazio = 113,            /* soma_ou_vazio  */
  YYSYMBOL_expressao_lista_termo = 114,    /* expressao_lista_termo  */
  YYSYMBOL_lista_termo = 115,              /* lista_termo  */
  YYSYMBOL_termo = 116,                    /* termo  */
  YYSYMBOL_lista_fator = 117,              /* lista_fator  */
  YYSYMBOL_fator = 118,                    /* fator  */
  YYSYMBOL_119_33 = 119,                   /* $@33  */
  YYSYMBOL_atribuicao_procedimento = 120,  /* atribuicao_procedimento  */
  YYSYMBOL_atribuicao_funcao = 121,        /* atribuicao_funcao  */
  YYSYMBOL_atribuicao = 122,               /* atribuicao  */
  YYSYMBOL_variavel = 123,                 /* variavel  */
  YYSYMBOL_numero = 124,                   /* numero  */
  YYSYMBOL_leitura = 125,                  /* leitura  */
  YYSYMBOL_lista_leitura = 126,            /* lista_leitura  */
  YYSYMBOL_simbolo_leitura = 127,          /* simbolo_leitura  */
  YYSYMBOL_escrita = 128,                  /* escrita  */
  YYSYMBOL_lista_escrita = 129             /* lista_escrita  */
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
#define YYLAST   192

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  40
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  90
/* YYNRULES -- Number of rules.  */
#define YYNRULES  137
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  212

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   294


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
      35,    36,    37,    38,    39
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    48,    48,    48,    71,    72,    76,    80,    87,    93,
      86,   101,   110,   110,   111,   115,   115,   116,   116,   117,
     121,   122,   125,   126,   129,   134,   129,   141,   147,   155,
     161,   171,   173,   195,   196,   171,   238,   240,   263,   264,
     238,   304,   305,   309,   309,   320,   321,   321,   325,   325,
     329,   329,   333,   337,   338,   342,   346,   347,   350,   353,
     354,   355,   356,   357,   358,   359,   360,   364,   368,   378,
     377,   399,   398,   410,   414,   420,   428,   431,   420,   438,
     438,   453,   460,   463,   453,   472,   473,   479,   492,   478,
     514,   514,   514,   517,   517,   521,   527,   531,   532,   533,
     534,   535,   536,   540,   544,   544,   544,   548,   549,   553,
     556,   559,   565,   566,   570,   573,   576,   579,   585,   633,
     632,   657,   658,   659,   663,   664,   668,   668,   672,   686,
     707,   718,   722,   723,   727,   748,   752,   753
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
  "INTEGER", "WHILE", "DO", "IF", "THEN", "ELSE", "MAIOR", "MENOR",
  "MAIOR_IGUAL", "MENOR_IGUAL", "IGUAL", "DIFERENTE", "SOMA", "SUBTRACAO",
  "MULTIPLICACAO", "DIVISAO", "DIV", "NUMERO", "READ", "WRITE", "OR",
  "AND", "NOT", "PROCEDURE", "FUNCTION", "$accept", "programa", "$@1",
  "parametros_ou_vazio", "parametros", "tipo", "bloco", "$@2", "$@3",
  "parte_declara_vars", "parte_declara_sub_rotinas", "$@4",
  "opcoes_sub_rotinas", "$@5", "$@6", "var", "declara_vars", "declara_var",
  "$@7", "$@8", "lista_id_var", "lista_idents", "declaracao_procedimento",
  "$@9", "$@10", "$@11", "$@12", "declaracao_funcao", "$@13", "$@14",
  "$@15", "$@16", "parametros_formais_vazio", "parametros_formais", "$@17",
  "lista_parametros_formais", "$@18", "secao_parametros_formais", "$@19",
  "var_vazio", "comando_composto", "comandos", "comando",
  "numero_ou_vazio", "comando_vazio", "comando_sem_rotulo", "desvio",
  "comando_condicional", "if_then", "$@20", "cond_else", "$@21",
  "else_multiplo_unico", "chama_procedimento", "$@22", "$@23", "$@24",
  "$@25", "chama_funcao", "$@26", "$@27", "$@28",
  "lista_expressoes_ou_vazio", "comando_repetitivo", "$@29", "$@30",
  "lista_expressoes", "$@31", "expressao", "$@32",
  "relacao_exp_simples_ou_vazio", "relacao", "expressao_simples",
  "soma_ou_vazio", "expressao_lista_termo", "lista_termo", "termo",
  "lista_fator", "fator", "$@33", "atribuicao_procedimento",
  "atribuicao_funcao", "atribuicao", "variavel", "numero", "leitura",
  "lista_leitura", "simbolo_leitura", "escrita", "lista_escrita", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-183)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-92)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -183,    10,    76,  -183,    60,    78,    67,    77,  -183,  -183,
    -183,    29,    73,  -183,    74,  -183,    80,  -183,  -183,    79,
    -183,    81,  -183,    79,  -183,  -183,  -183,  -183,    61,    83,
    -183,    82,    71,    86,    25,  -183,  -183,  -183,    58,  -183,
    -183,  -183,  -183,  -183,  -183,  -183,    84,  -183,     7,  -183,
       3,  -183,    89,    85,    88,    92,    95,  -183,    58,  -183,
    -183,  -183,  -183,  -183,    99,   100,  -183,  -183,  -183,  -183,
      87,  -183,   101,  -183,  -183,  -183,     8,  -183,  -183,  -183,
    -183,  -183,  -183,  -183,  -183,  -183,    19,  -183,  -183,    93,
    -183,  -183,  -183,  -183,  -183,  -183,   104,  -183,  -183,  -183,
    -183,  -183,  -183,  -183,  -183,    36,    11,    94,    90,  -183,
      70,  -183,  -183,    72,     3,   109,  -183,   111,   111,  -183,
    -183,  -183,  -183,  -183,  -183,  -183,  -183,    19,  -183,    11,
      17,    20,  -183,   112,  -183,  -183,     3,  -183,    93,  -183,
    -183,  -183,  -183,  -183,   113,  -183,   114,   109,  -183,   110,
    -183,  -183,   115,  -183,   116,  -183,    11,    11,    11,  -183,
      11,    11,    11,    11,  -183,  -183,    86,  -183,  -183,  -183,
    -183,   118,   120,  -183,  -183,    71,  -183,    20,    20,    20,
    -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,    63,
     107,    73,   119,   122,  -183,  -183,  -183,   107,  -183,  -183,
    -183,  -183,  -183,  -183,  -183,  -183,    67,    73,    66,  -183,
      71,  -183
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     0,    58,     0,     0,     4,     5,
      30,     0,    24,     6,     0,    24,     0,     8,    11,    21,
      23,     0,    29,    20,     3,    58,    22,    28,     0,    12,
      14,     0,     0,     0,    58,    27,     7,    25,    58,    10,
      31,    36,    13,    15,    17,    19,     0,   130,     0,    54,
      67,    57,     0,     0,     0,     0,     0,    26,    58,    52,
     129,    93,    87,    93,     0,     0,    62,    55,    61,    63,
      58,   127,     0,    64,    60,   126,    79,    65,    66,    56,
      32,    37,    16,    18,    53,   128,    58,    93,    69,     0,
      93,    71,    73,    68,    82,   125,     0,    80,    59,   124,
      33,    38,   104,   105,   106,    58,     0,     0,     0,   134,
       0,   133,   137,     0,    67,    93,    76,    58,    58,   102,
      99,   101,   100,    97,    98,    96,    94,    58,    93,     0,
     103,   108,   113,   118,   121,    88,    67,   131,     0,   135,
      93,    74,    72,    86,     0,    85,    90,    93,    43,     0,
      41,    42,     0,    95,     0,   123,     0,     0,     0,   107,
       0,     0,     0,     0,   112,   119,     0,    70,   132,   136,
      83,     0,     0,    46,    34,     0,   122,   109,   110,   111,
     114,   115,   116,   117,    93,    89,    84,    93,    77,     0,
      58,    24,     0,     0,    92,    78,    44,    58,    50,    47,
      48,    51,    35,    39,   120,    45,     0,    24,     0,    40,
       0,    49
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -183,  -183,  -183,  -183,  -183,  -172,  -182,  -183,  -183,  -183,
    -183,  -183,  -183,  -183,  -183,  -183,   117,     9,  -183,  -183,
    -183,   -78,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,
    -183,  -183,    12,  -183,  -183,  -183,  -183,   -68,  -183,  -183,
     -32,  -183,    75,  -183,    -5,  -109,  -183,  -183,  -183,  -183,
    -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,  -183,
    -183,  -183,   -16,  -183,  -183,  -183,  -161,  -183,   -57,  -183,
    -183,  -183,    13,  -183,  -183,  -183,  -103,  -183,  -121,  -183,
    -183,  -183,    59,   -48,   -27,  -183,  -183,    -2,  -183,  -183
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     7,     8,    37,    16,    25,    33,    17,
      29,    34,    42,    55,    56,    18,    19,    20,    21,    46,
      28,    11,    43,    53,   100,   117,   191,    44,    54,   101,
     118,   207,   149,   150,   173,   189,   190,   199,   206,   200,
      66,    48,    49,    50,    51,    67,    68,    69,    70,   108,
      93,   114,   142,    95,    96,   147,   195,    97,    71,    72,
     115,   186,   144,    73,    87,   166,   145,   171,   146,    86,
     126,   127,   105,   106,   130,   159,   131,   164,   132,   184,
      98,    74,    75,   133,   134,    77,   110,   111,    78,   113
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       9,    39,    76,   192,    85,   141,    88,   -81,   155,   202,
       3,    52,   -75,    38,    58,   128,    60,    61,    59,    62,
      30,    63,    61,   193,    60,   209,   194,   167,    26,    45,
     107,    52,    26,   112,    13,    14,    64,    65,   211,   180,
     181,   182,   183,    47,   156,   157,   102,   103,   129,   160,
     161,   162,   158,   177,   178,   179,   163,   119,   120,   121,
     122,   123,   124,    40,    41,    92,    76,    31,   196,    32,
     197,   154,    14,     5,   210,   137,   138,   139,   140,     4,
      10,   104,     6,   169,    12,    15,    36,    22,    76,    24,
      47,    57,   -24,    -9,    27,    35,    38,    79,    80,    82,
     125,    81,    83,    89,    90,    94,   109,    91,   116,   136,
     143,   135,   151,   151,   -58,   148,   165,   174,   170,   198,
     -91,   176,   104,   175,   187,   188,   203,   204,   208,   205,
     152,   172,    23,    84,   185,    99,   168,     0,     0,     0,
     153,     0,   143,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   201,     0,     0,     0,     0,
       0,     0,   201
};

static const yytype_int16 yycheck[] =
{
       5,    33,    50,   175,    61,   114,    63,     4,   129,   191,
       0,    38,     4,    10,     7,     4,    13,    14,    11,    16,
      25,    18,    14,   184,    13,   207,   187,   136,    19,    34,
      87,    58,    23,    90,     5,     6,    33,    34,   210,   160,
     161,   162,   163,    32,    27,    28,    27,    28,    37,    29,
      30,    31,    35,   156,   157,   158,    36,    21,    22,    23,
      24,    25,    26,    38,    39,    70,   114,     6,     5,     8,
       7,   128,     6,    13,     8,     5,     6,     5,     6,     3,
      13,    86,     4,   140,     7,    12,    15,    13,   136,     9,
      32,     7,    13,    10,    13,    13,    10,     8,    13,     7,
     105,    13,     7,     4,     4,     4,    13,    20,     4,    19,
     115,    17,   117,   118,     5,     4,     4,     7,     5,    12,
       6,     5,   127,     8,     6,     5,     7,     5,   206,   197,
     118,   147,    15,    58,   166,    76,   138,    -1,    -1,    -1,
     127,    -1,   147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   190,    -1,    -1,    -1,    -1,
      -1,    -1,   197
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    41,    42,     0,     3,    13,     4,    43,    44,    84,
      13,    61,     7,     5,     6,    12,    46,    49,    55,    56,
      57,    58,    13,    56,     9,    47,    57,    13,    60,    50,
      84,     6,     8,    48,    51,    13,    15,    45,    10,    80,
      38,    39,    52,    62,    67,    84,    59,    32,    81,    82,
      83,    84,   124,    63,    68,    53,    54,     7,     7,    11,
      13,    14,    16,    18,    33,    34,    80,    85,    86,    87,
      88,    98,    99,   103,   121,   122,   123,   125,   128,     8,
      13,    13,     7,     7,    82,   108,   109,   104,   108,     4,
       4,    20,    84,    90,     4,    93,    94,    97,   120,   122,
      64,    69,    27,    28,    84,   112,   113,   108,    89,    13,
     126,   127,   108,   129,    91,   100,     4,    65,    70,    21,
      22,    23,    24,    25,    26,    84,   110,   111,     4,    37,
     114,   116,   118,   123,   124,    17,    19,     5,     6,     5,
       6,    85,    92,    84,   102,   106,   108,    95,     4,    72,
      73,    84,    72,   112,   108,   118,    27,    28,    35,   115,
      29,    30,    31,    36,   117,     4,   105,    85,   127,   108,
       5,   107,   102,    74,     7,     8,     5,   116,   116,   116,
     118,   118,   118,   118,   119,    80,   101,     6,     5,    75,
      76,    66,    45,   106,   106,    96,     5,     7,    12,    77,
      79,    84,    46,     7,     5,    77,    78,    71,    61,    46,
       8,    45
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    40,    42,    41,    43,    43,    44,    45,    47,    48,
      46,    49,    51,    50,    50,    53,    52,    54,    52,    52,
      55,    55,    56,    56,    58,    59,    57,    60,    60,    61,
      61,    63,    64,    65,    66,    62,    68,    69,    70,    71,
      67,    72,    72,    74,    73,    75,    76,    75,    78,    77,
      79,    79,    80,    81,    81,    82,    83,    83,    84,    85,
      85,    85,    85,    85,    85,    85,    85,    86,    87,    89,
      88,    91,    90,    90,    92,    94,    95,    96,    93,    97,
      93,    99,   100,   101,    98,   102,   102,   104,   105,   103,
     106,   107,   106,   109,   108,   110,   110,   111,   111,   111,
     111,   111,   111,   112,   113,   113,   113,   114,   114,   115,
     115,   115,   116,   116,   117,   117,   117,   117,   118,   119,
     118,   118,   118,   118,   120,   120,   121,   121,   122,   123,
     124,   125,   126,   126,   127,   128,   129,   129
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     7,     1,     1,     3,     1,     0,     0,
       5,     1,     0,     3,     1,     0,     3,     0,     3,     1,
       2,     1,     2,     1,     0,     0,     6,     3,     1,     3,
       1,     0,     0,     0,     0,     9,     0,     0,     0,     0,
      11,     1,     1,     0,     4,     3,     0,     2,     0,     5,
       1,     1,     3,     3,     1,     2,     2,     1,     0,     2,
       1,     1,     1,     1,     1,     1,     1,     0,     2,     0,
       5,     0,     3,     1,     1,     0,     0,     0,     6,     0,
       1,     0,     0,     0,     6,     1,     1,     0,     0,     6,
       1,     0,     4,     0,     3,     2,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     2,     1,     2,
       2,     2,     2,     1,     2,     2,     2,     2,     1,     0,
       5,     1,     3,     2,     1,     1,     1,     1,     2,     1,
       1,     4,     3,     1,     1,     4,     3,     1
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
#line 48 "compilador.y"
             {
             geraCodigo (NULL, "INPP");
             char * RotInicioSubrotina = cria_rotulo(rotulo_print);
						 rotulo_print++;
						 push_pilha_rotulo(&pilha_rotulos, RotInicioSubrotina);
						 procedimentoAtual = cria_variavel_procedure("main", RotInicioSubrotina, 0, 0);
						 push(&tabelaSimbolos, procedimentoAtual);
						 push_pilha_no(&pilhano, procedimentoAtual);
						}
#line 1393 "compilador.tab.c"
    break;

  case 3: /* programa: $@1 PROGRAM IDENT parametros_ou_vazio PONTO_E_VIRGULA bloco PONTO  */
#line 59 "compilador.y"
                         {
							 procedimentoAtual = pop_pilha_no(&pilhano);
               pop(&tabelaSimbolos, procedimentoAtual->numero_variaveis + procedimentoAtual->numero_procedimentos);
               char dmem[1000];

               sprintf(dmem, "DMEM %d", procedimentoAtual->numero_variaveis);
               geraCodigo(NULL, dmem);
               geraCodigo (NULL, "PARA");
             }
#line 1407 "compilador.tab.c"
    break;

  case 7: /* tipo: INTEGER  */
#line 80 "compilador.y"
                { seta_tipos(&tabelaSimbolos, integer, novas_variaveis); }
#line 1413 "compilador.tab.c"
    break;

  case 8: /* $@2: %empty  */
#line 87 "compilador.y"
                                {
					char rotsaida[100];
      		sprintf(rotsaida, "DSVS %s", pega_rotulo(&pilha_rotulos,0));
					geraCodigo(NULL, rotsaida);
				}
#line 1423 "compilador.tab.c"
    break;

  case 9: /* $@3: %empty  */
#line 93 "compilador.y"
                          {
				char rotsaida[100];
     		sprintf(rotsaida, "%s", pega_rotulo(&pilha_rotulos,0));
     		geraCodigo(rotsaida, "NADA");
				}
#line 1433 "compilador.tab.c"
    break;

  case 11: /* parte_declara_vars: var  */
#line 101 "compilador.y"
                         {
    char amem[100];
		sprintf(amem, "AMEM %d", numero_variaveis);
		atualiza_num_variaveis(&tabelaSimbolos, numero_variaveis, nivel_lexico);
		geraCodigo(NULL, amem);
}
#line 1444 "compilador.tab.c"
    break;

  case 12: /* $@4: %empty  */
#line 110 "compilador.y"
                                  {}
#line 1450 "compilador.tab.c"
    break;

  case 15: /* $@5: %empty  */
#line 115 "compilador.y"
                                {atualiza_num_procedimentos(&tabelaSimbolos, nivel_lexico);}
#line 1456 "compilador.tab.c"
    break;

  case 17: /* $@6: %empty  */
#line 116 "compilador.y"
                            {atualiza_num_procedimentos(&tabelaSimbolos, nivel_lexico);}
#line 1462 "compilador.tab.c"
    break;

  case 24: /* $@7: %empty  */
#line 129 "compilador.y"
              {
              novas_variaveis = 0;
}
#line 1470 "compilador.tab.c"
    break;

  case 25: /* $@8: %empty  */
#line 134 "compilador.y"
              {
                numero_variaveis += novas_variaveis;
              }
#line 1478 "compilador.tab.c"
    break;

  case 27: /* lista_id_var: lista_id_var VIRGULA IDENT  */
#line 142 "compilador.y"
              { /* insere �ltima vars na tabela de s�mbolos */
                novas_variaveis++;
                novaEntrada = cria_variavel_simples(token, nivel_lexico, deslocamento);
                push(&tabelaSimbolos, novaEntrada);
                deslocamento++;}
#line 1488 "compilador.tab.c"
    break;

  case 28: /* lista_id_var: IDENT  */
#line 147 "compilador.y"
                    { /* insere vars na tabela de s�mbolos */
                novas_variaveis++;
                novaEntrada = cria_variavel_simples(token, nivel_lexico, deslocamento);
                push(&tabelaSimbolos, novaEntrada);
                deslocamento++;
                }
#line 1499 "compilador.tab.c"
    break;

  case 29: /* lista_idents: lista_idents VIRGULA IDENT  */
#line 155 "compilador.y"
                                        {
		novas_variaveis++;
		numero_parametros++;
		novaEntrada = cria_variavel_formal(token, nivel_lexico, 1, por_ref ? REFERENCIA : VALOR);
		push(&tabelaSimbolos, novaEntrada);
	}
#line 1510 "compilador.tab.c"
    break;

  case 30: /* lista_idents: IDENT  */
#line 162 "compilador.y"
        {
		novas_variaveis++;
		numero_parametros++;
		novaEntrada = cria_variavel_formal(token, nivel_lexico, 1, por_ref ? REFERENCIA : VALOR);
		push(&tabelaSimbolos, novaEntrada);
	}
#line 1521 "compilador.tab.c"
    break;

  case 31: /* $@9: %empty  */
#line 171 "compilador.y"
                  { subrt = 1; }
#line 1527 "compilador.tab.c"
    break;

  case 32: /* $@10: %empty  */
#line 173 "compilador.y"
        {

		// Gera rotulos de entrada e saida
		char *RotInicioSubrotina = cria_rotulo(rotulo_print);
		rotulo_print++;

		rotulo_fim_subr = cria_rotulo(rotulo_print);
		rotulo_print++;
		push_pilha_rotulo(&pilha_rotulos, RotInicioSubrotina);
		push_pilha_rotulo(&pilha_rotulos, rotulo_fim_subr);
		nivel_lexico++;

		// Imprime rotulo de entrada da subrotina
		char rotentrada[100];
		sprintf(rotentrada, "ENPR %d", nivel_lexico);
		geraCodigo(pega_rotulo(&pilha_rotulos, 2), rotentrada);

		novaEntrada = cria_variavel_procedure(token, RotInicioSubrotina, nivel_lexico, 0);
		push(&tabelaSimbolos, novaEntrada);
		push_pilha_no(&pilhano,  novaEntrada);
		procedimentoAtual = novaEntrada;
	}
#line 1554 "compilador.tab.c"
    break;

  case 33: /* $@11: %empty  */
#line 195 "compilador.y"
        { novos_param = 0; }
#line 1560 "compilador.tab.c"
    break;

  case 34: /* $@12: %empty  */
#line 196 "compilador.y"
        {
		// Zera para ser utilizado na subrotina
		// Mas salva VALOR para ser recuperado
		aux_var = numero_variaveis;
		numero_variaveis = 0;
		deslocamento = 0;
	}
#line 1572 "compilador.tab.c"
    break;

  case 35: /* declaracao_procedimento: PROCEDURE $@9 IDENT $@10 $@11 parametros_formais_vazio PONTO_E_VIRGULA $@12 bloco  */
#line 204 "compilador.y"
        {
		procedimentoAtual = (type_info_tabela_simbolos*) pop_pilha_no(&pilhano);
		pop(&tabelaSimbolos, procedimentoAtual->numero_procedimentos); // Remove procedimentos da tabela de simbolos

		// DMEM nas variaveis do procedimento
		pop(&tabelaSimbolos, procedimentoAtual->numero_variaveis);
		char dmem[100];
		sprintf(dmem, "DMEM %d", procedimentoAtual->numero_variaveis);
		geraCodigo(NULL, dmem);
		pop(&tabelaSimbolos, procedimentoAtual->numero_parametros); // Remove parametros da tabela de simbolos

		// Pega procedimento para printar infos da saida dele
		variavelDestino = pega_topo(&tabelaSimbolos);
		if(variavelDestino == NULL) {
			printf("Procedimento nao encontrado na tabela de simbolos.\n");
			exit(1);
		}
		char command[100];
		sprintf(command, "RTPR %d, %d", nivel_lexico, procedimentoAtual->numero_parametros);
		geraCodigo(NULL, command);

		novos_param = 0;
		nivel_lexico--;

		variavelDestino = NULL; // Libera variavel destino
		numero_variaveis = aux_var;    // Restabelece numero de variaveis no nivel lexico
		subrt = 0;
		pop_pilha_rotulo(&pilha_rotulos, 2);


	}
#line 1608 "compilador.tab.c"
    break;

  case 36: /* $@13: %empty  */
#line 238 "compilador.y"
          { subrt = 1; }
#line 1614 "compilador.tab.c"
    break;

  case 37: /* $@14: %empty  */
#line 240 "compilador.y"
  {

    // Gera rotulos de entrada e saida
    char *RotInicioSubrotina = cria_rotulo(rotulo_print);
    rotulo_print++;

    rotulo_fim_subr = cria_rotulo(rotulo_print);
    rotulo_print++;
    push_pilha_rotulo(&pilha_rotulos, RotInicioSubrotina);
    push_pilha_rotulo(&pilha_rotulos, rotulo_fim_subr);
    nivel_lexico++;

    // Imprime rotulo de entrada da subrotina
    char rotentrada[100];
    sprintf(rotentrada, "ENPR %d", nivel_lexico);
    geraCodigo(pega_rotulo(&pilha_rotulos, 2), rotentrada);

		sprintf(funcao_atual, "%s", token);
    novaEntrada = cria_variavel_funcao(token, RotInicioSubrotina, nivel_lexico, 0, integer);
    push(&tabelaSimbolos, novaEntrada);
    push_pilha_no(&pilhano,  novaEntrada);
    procedimentoAtual = novaEntrada;
  }
#line 1642 "compilador.tab.c"
    break;

  case 38: /* $@15: %empty  */
#line 263 "compilador.y"
  { novos_param = 0; }
#line 1648 "compilador.tab.c"
    break;

  case 39: /* $@16: %empty  */
#line 264 "compilador.y"
  {
    // Zera para ser utilizado na subrotina
    // Mas salva VALOR para ser recuperado
    aux_var = numero_variaveis;
    numero_variaveis = 0;
    deslocamento = 0;
  }
#line 1660 "compilador.tab.c"
    break;

  case 40: /* declaracao_funcao: FUNCTION $@13 IDENT $@14 $@15 parametros_formais_vazio DOIS_PONTOS tipo PONTO_E_VIRGULA $@16 bloco  */
#line 272 "compilador.y"
  {
    procedimentoAtual = (type_info_tabela_simbolos*)pop_pilha_no(&pilhano);
    pop(&tabelaSimbolos, procedimentoAtual->numero_procedimentos); // Remove procedimentos da tabela de simbolos

    // DMEM nas variaveis do procedimento
    pop(&tabelaSimbolos, procedimentoAtual->numero_variaveis);
    char dmem[100];
    sprintf(dmem, "DMEM %d", procedimentoAtual->numero_variaveis);
    geraCodigo(NULL, dmem);
    pop(&tabelaSimbolos, procedimentoAtual->numero_parametros); // Remove parametros da tabela de simbolos

    // Pega procedimento para printar infos da saida dele
    variavelDestino = pega_topo(&tabelaSimbolos);
    if(variavelDestino == NULL) {
      printf("Procedimento nao encontrado na tabela de simbolos.\n");
      exit(1);
    }
    char command[100];
    sprintf(command, "RTPR %d, %d", nivel_lexico, numero_parametros);
    geraCodigo(NULL, command);

    novos_param = 0;
    nivel_lexico--;

    variavelDestino = NULL; // Libera variavel destino
    numero_variaveis = aux_var;    // Restabelece numero de variaveis no nivel lexico
    subrt = 0;
    pop_pilha_rotulo(&pilha_rotulos, 2);
  }
#line 1694 "compilador.tab.c"
    break;

  case 43: /* $@17: %empty  */
#line 309 "compilador.y"
                { numero_parametros = 0; }
#line 1700 "compilador.tab.c"
    break;

  case 44: /* parametros_formais: ABRE_PARENTESES $@17 lista_parametros_formais FECHA_PARENTESES  */
#line 312 "compilador.y"
        {

		atualiza_parametros(pega_posicao(&tabelaSimbolos, numero_parametros),
								&tabelaSimbolos, numero_parametros);
	}
#line 1710 "compilador.tab.c"
    break;

  case 46: /* $@18: %empty  */
#line 321 "compilador.y"
          { novos_param++; }
#line 1716 "compilador.tab.c"
    break;

  case 48: /* $@19: %empty  */
#line 325 "compilador.y"
            { novas_variaveis = 0; }
#line 1722 "compilador.tab.c"
    break;

  case 50: /* var_vazio: VAR  */
#line 329 "compilador.y"
            {por_ref = 1; }
#line 1728 "compilador.tab.c"
    break;

  case 51: /* var_vazio: comando_vazio  */
#line 329 "compilador.y"
                                            {por_ref = 0; }
#line 1734 "compilador.tab.c"
    break;

  case 67: /* desvio: %empty  */
#line 364 "compilador.y"
   { }
#line 1740 "compilador.tab.c"
    break;

  case 68: /* comando_condicional: if_then cond_else  */
#line 369 "compilador.y"
        {
		char rot[100];
		geraCodigo(pega_rotulo(&pilha_rotulos, 2), "NADA");
		pop_pilha_rotulo(&pilha_rotulos, 2);
	}
#line 1750 "compilador.tab.c"
    break;

  case 69: /* $@20: %empty  */
#line 378 "compilador.y"
        {
		inicia_else(); //inicializa se necessario, incrementa o iterador
		// Gera rotulos de entrada e saida do IF
		char *RotIfInicio = cria_rotulo(rotulo_print);
		rotulo_print++;
		char *RotIfFim = cria_rotulo(rotulo_print);
		rotulo_print++;

		push_pilha_rotulo(&pilha_rotulos, RotIfInicio);
		push_pilha_rotulo(&pilha_rotulos, RotIfFim);
		//push_pilha_rotulo(&pilha_rotulos, RotIfInicio);

		// Imprime rotulo de entrada no inicio do if
		char rot[100];
		sprintf(rot, "DSVF %s", pega_rotulo(&pilha_rotulos, 1));
		geraCodigo(NULL, rot);
	}
#line 1772 "compilador.tab.c"
    break;

  case 71: /* $@21: %empty  */
#line 399 "compilador.y"
        {
		seta_else(); //marca pro iterador que a iésima cláusula tem else
		// Imprime rotulo de entrada no inicio do if
		char rot[100];
		sprintf(rot, "DSVS %s", pega_rotulo(&pilha_rotulos, 2));
		geraCodigo(NULL, rot);

		// Imprime rotulo de entrada no fim do if
		geraCodigo(pega_rotulo(&pilha_rotulos, 1), "NADA");
	}
#line 1787 "compilador.tab.c"
    break;

  case 75: /* $@22: %empty  */
#line 420 "compilador.y"
    {
		entra_procedimento = 1;
		// Imprime rotulo de entrada da subrotina
		procedimentoAtual = variavelDestino;
		sprintf(chama_proc, "CHPR %s, %d", variavelDestino->rotulo, nivel_lexico);
		entra_procedimento = 1;
		//geraCodigo(NULL, chama_proc);
   	}
#line 1800 "compilador.tab.c"
    break;

  case 76: /* $@23: %empty  */
#line 428 "compilador.y"
                        {   novos_param = 0; }
#line 1806 "compilador.tab.c"
    break;

  case 77: /* $@24: %empty  */
#line 431 "compilador.y"
        {
		entra_procedimento = 0;
		geraCodigo(NULL, chama_proc);

	}
#line 1816 "compilador.tab.c"
    break;

  case 78: /* chama_procedimento: $@22 ABRE_PARENTESES $@23 lista_expressoes_ou_vazio FECHA_PARENTESES $@24  */
#line 436 "compilador.y"
        { variavelDestino = NULL; }
#line 1822 "compilador.tab.c"
    break;

  case 79: /* $@25: %empty  */
#line 438 "compilador.y"
        {
		entra_procedimento = 1;
		procedimentoAtual = variavelDestino;
		// Imprime rotulo de entrada da subrotina
		char chama_proc[100];
		sprintf(chama_proc, "CHPR %s, %d", variavelDestino->rotulo, nivel_lexico);
		geraCodigo(NULL, chama_proc);
		variavelDestino = NULL;
	}
#line 1836 "compilador.tab.c"
    break;

  case 80: /* chama_procedimento: $@25  */
#line 447 "compilador.y"
        {
		entra_procedimento = 0;
	}
#line 1844 "compilador.tab.c"
    break;

  case 81: /* $@26: %empty  */
#line 453 "compilador.y"
    {
    entra_procedimento = 1;
    // Imprime rotulo de entrada da subrotina
    procedimentoAtual = variavelDestino;
    sprintf(chama_proc, "CHPR %s, %d", variavelDestino->rotulo, nivel_lexico);
    geraCodigo(NULL, "AMEM 1"); // making up space for the function return
    }
#line 1856 "compilador.tab.c"
    break;

  case 82: /* $@27: %empty  */
#line 460 "compilador.y"
                  {   novos_param = 0; }
#line 1862 "compilador.tab.c"
    break;

  case 83: /* $@28: %empty  */
#line 463 "compilador.y"
  {
    entra_procedimento = 0;
    geraCodigo(NULL, chama_proc);

  }
#line 1872 "compilador.tab.c"
    break;

  case 84: /* chama_funcao: $@26 ABRE_PARENTESES $@27 lista_expressoes_ou_vazio FECHA_PARENTESES $@28  */
#line 468 "compilador.y"
  { variavelDestino = NULL; }
#line 1878 "compilador.tab.c"
    break;

  case 87: /* $@29: %empty  */
#line 479 "compilador.y"
        {
		char *RotWhileInicio = cria_rotulo(rotulo_print);
		rotulo_print++;
		char *RotWhileFim = cria_rotulo(rotulo_print);
		rotulo_print++;

		push_pilha_rotulo(&pilha_rotulos, RotWhileInicio);
		push_pilha_rotulo(&pilha_rotulos, RotWhileFim);

		char rot[100];
		geraCodigo(pega_rotulo(&pilha_rotulos, 2), "NADA");
	}
#line 1895 "compilador.tab.c"
    break;

  case 88: /* $@30: %empty  */
#line 492 "compilador.y"
        {
		char dsvf[100];
		sprintf(dsvf, "DSVF %s", pega_rotulo(&pilha_rotulos, 1));
		geraCodigo(NULL, dsvf);
	}
#line 1905 "compilador.tab.c"
    break;

  case 89: /* comando_repetitivo: WHILE $@29 expressao DO $@30 comando_composto  */
#line 498 "compilador.y"
        {
		char dsvs[100];
		sprintf(dsvs, "DSVS %s", pega_rotulo(&pilha_rotulos, 2));
		geraCodigo(NULL, dsvs);

		char rot[100];
		sprintf(rot, "%s", pega_rotulo(&pilha_rotulos, 1));
		geraCodigo(rot, "NADA");

		pop_pilha_rotulo(&pilha_rotulos, 2);
	}
#line 1921 "compilador.tab.c"
    break;

  case 91: /* $@31: %empty  */
#line 514 "compilador.y"
                                        {numero_parametros_chamada++;}
#line 1927 "compilador.tab.c"
    break;

  case 93: /* $@32: %empty  */
#line 517 "compilador.y"
        { novos_param++; }
#line 1933 "compilador.tab.c"
    break;

  case 95: /* relacao_exp_simples_ou_vazio: relacao expressao_simples  */
#line 522 "compilador.y"
        {

		verifica_tipo(&tabelaTipo, "relacional");
		geraCodigo(NULL, comparacao);
	}
#line 1943 "compilador.tab.c"
    break;

  case 97: /* relacao: IGUAL  */
#line 531 "compilador.y"
              { strcpy(comparacao, "CMIG"); }
#line 1949 "compilador.tab.c"
    break;

  case 98: /* relacao: DIFERENTE  */
#line 532 "compilador.y"
                    { strcpy(comparacao, "CMDG"); }
#line 1955 "compilador.tab.c"
    break;

  case 99: /* relacao: MENOR  */
#line 533 "compilador.y"
                { strcpy(comparacao, "CMME"); }
#line 1961 "compilador.tab.c"
    break;

  case 100: /* relacao: MENOR_IGUAL  */
#line 534 "compilador.y"
                      { strcpy(comparacao, "CMEG"); }
#line 1967 "compilador.tab.c"
    break;

  case 101: /* relacao: MAIOR_IGUAL  */
#line 535 "compilador.y"
                      { strcpy(comparacao, "CMAG"); }
#line 1973 "compilador.tab.c"
    break;

  case 102: /* relacao: MAIOR  */
#line 536 "compilador.y"
                { strcpy(comparacao, "CMMA"); }
#line 1979 "compilador.tab.c"
    break;

  case 109: /* lista_termo: SOMA termo  */
#line 553 "compilador.y"
                   {
		verifica_tipo(&tabelaTipo, "soma");
		geraCodigo(NULL, "SOMA");}
#line 1987 "compilador.tab.c"
    break;

  case 110: /* lista_termo: SUBTRACAO termo  */
#line 556 "compilador.y"
                          {
		verifica_tipo(&tabelaTipo, "subtracao");
		geraCodigo(NULL, "SUBT");}
#line 1995 "compilador.tab.c"
    break;

  case 111: /* lista_termo: OR termo  */
#line 559 "compilador.y"
                   {
		verifica_tipo(&tabelaTipo, "or");
		geraCodigo(NULL, "DISJ");}
#line 2003 "compilador.tab.c"
    break;

  case 114: /* lista_fator: MULTIPLICACAO fator  */
#line 570 "compilador.y"
                            {
		verifica_tipo(&tabelaTipo, "multiplicacao");
		geraCodigo(NULL, "MULT");}
#line 2011 "compilador.tab.c"
    break;

  case 115: /* lista_fator: DIVISAO fator  */
#line 573 "compilador.y"
                        {
		verifica_tipo(&tabelaTipo, "divisao");
		geraCodigo(NULL, "DIVI"); }
#line 2019 "compilador.tab.c"
    break;

  case 116: /* lista_fator: DIV fator  */
#line 576 "compilador.y"
                    {
		verifica_tipo(&tabelaTipo, "div");
		geraCodigo(NULL, "DIVI"); }
#line 2027 "compilador.tab.c"
    break;

  case 117: /* lista_fator: AND fator  */
#line 579 "compilador.y"
                    {
		verifica_tipo(&tabelaTipo, "and");
		geraCodigo(NULL, "CONJ"); }
#line 2035 "compilador.tab.c"
    break;

  case 118: /* fator: variavel  */
#line 586 "compilador.y"
        {
		if(variavel_carregada != NULL) {
			if(variavel_carregada->categoria == funcao) {
				char chamaProcedure[100];
				sprintf(chamaProcedure, "CHPR %s, %d", variavel_carregada->rotulo, nivel_lexico);
				geraCodigo(NULL, chamaProcedure);

			}
			else {
				char comando[100];
				int cur_params = entra_procedimento == 2 ?
												(procedimentoAtual->numero_parametros - numero_parametros_chamada + 1) : novos_param;
				int passagem = entra_procedimento == 0 ? variavel_carregada->passagem :
																				 procedimentoAtual->params[procedimentoAtual->numero_parametros - cur_params].passagem;

				if (passagem == VALOR || (passagem == REFERENCIA && entra_procedimento == 1 && variavel_carregada->passagem == REFERENCIA))
					sprintf(comando, "CRVL %d, %d", variavel_carregada->nivel_lexico, variavel_carregada->deslocamento);
				else if (entra_procedimento >= 1 && passagem == REFERENCIA)
          sprintf(comando, "CREN %d, %d", variavel_carregada->nivel_lexico, variavel_carregada->deslocamento);
				else
					sprintf(comando, "CRVI %d, %d", variavel_carregada->nivel_lexico, variavel_carregada->deslocamento);
				variavel_carregada = NULL;
				geraCodigo(NULL, comando);
			}
		}
		else {
			if(variavelDestino->categoria == funcao) {
				char chamaProcedure[100];
				sprintf(chamaProcedure, "CHPR %s, %d", variavelDestino->rotulo, nivel_lexico);
				geraCodigo(NULL, chamaProcedure);
			}
			else {
				char comando[100];
				int passagem = entra_procedimento == 0 ? variavelDestino->passagem :
									procedimentoAtual->params[procedimentoAtual->numero_parametros - novos_param].passagem;
				if (passagem == VALOR || (passagem == REFERENCIA && entra_procedimento == 1 && variavelDestino->passagem == REFERENCIA))
					sprintf(comando, "CRVL %d, %d", variavelDestino->nivel_lexico, variavelDestino->deslocamento);
				else if (entra_procedimento == 1 && passagem == REFERENCIA)
					sprintf(comando, "CREN %d, %d", variavelDestino->nivel_lexico, variavelDestino->deslocamento);
				else
					sprintf(comando, "CRVI %d, %d", variavelDestino->nivel_lexico, variavelDestino->deslocamento);
				variavelDestino = NULL;
				geraCodigo(NULL, comando);
			}
		}
	}
#line 2086 "compilador.tab.c"
    break;

  case 119: /* $@33: %empty  */
#line 633 "compilador.y"
        {
		entra_procedimento = 2;
		numero_parametros_chamada = 0;
		if(variavel_carregada != NULL) {
			if(variavel_carregada->categoria == funcao) {
				procedimentoAtual = variavel_carregada;
			}
		}
		else {
			if(variavelDestino->categoria == funcao) {
				procedimentoAtual = variavelDestino;
			}
		}
		geraCodigo(NULL, "AMEM 1");

	}
#line 2107 "compilador.tab.c"
    break;

  case 120: /* fator: variavel ABRE_PARENTESES $@33 lista_expressoes FECHA_PARENTESES  */
#line 650 "compilador.y"
        {
		entra_procedimento = 0;
		numero_parametros_chamada = 0;
		char chamaProcedure[100];
		sprintf(chamaProcedure, "CHPR %s, %d", procedimentoAtual->rotulo, nivel_lexico);
		geraCodigo(NULL, chamaProcedure);
	}
#line 2119 "compilador.tab.c"
    break;

  case 128: /* atribuicao: ATRIBUICAO expressao  */
#line 673 "compilador.y"
        {
		verifica_tipo(&tabelaTipo, "atribuicao");
		char varLexDisp[100];
		if (variavelDestino->passagem == VALOR)
			sprintf(varLexDisp, "ARMZ %d, %d", variavelDestino->nivel_lexico, variavelDestino->deslocamento);
		else
			sprintf(varLexDisp, "ARMI %d, %d", variavelDestino->nivel_lexico, variavelDestino->deslocamento);
		geraCodigo(NULL, varLexDisp);
		variavelDestino = NULL;
	}
#line 2134 "compilador.tab.c"
    break;

  case 129: /* variavel: IDENT  */
#line 686 "compilador.y"
              {
		if(variavelDestino == NULL) {
			variavelDestino = busca_pilha_simbolos(&tabelaSimbolos, token);
			if(variavelDestino == NULL) {
				printf("Variavel %s nao encontrada.\n", token);
				exit(1);
			}
			push_pilha_tipo(&tabelaTipo, variavelDestino->tipo);
		}
		else {
			variavel_carregada = busca_pilha_simbolos(&tabelaSimbolos, token);
			if(variavel_carregada == NULL) {
				printf("Variavel %s nao encontrada.\n", token);
				exit(1);
			}
			push_pilha_tipo(&tabelaTipo, variavel_carregada->tipo);
		}
   	}
#line 2157 "compilador.tab.c"
    break;

  case 130: /* numero: NUMERO  */
#line 708 "compilador.y"
        {
		push_pilha_tipo(&tabelaTipo, integer);
        char totalVars[100];
		sprintf(totalVars, "CRCT %s", token);
		geraCodigo(NULL, totalVars);
	}
#line 2168 "compilador.tab.c"
    break;

  case 134: /* simbolo_leitura: IDENT  */
#line 728 "compilador.y"
        {
		// Codigo leitura
		geraCodigo(NULL, "LEIT");

		// Procura por variavel na tabela de simbolos
		variavelDestino = busca_pilha_simbolos(&tabelaSimbolos, token);
		if(variavelDestino == NULL) {
			printf("Variavel nao encontrada.\n");
			exit(1);
		}

		// Armazena na variavel destino
    char varLexDisp[1000];
		sprintf(varLexDisp, "ARMZ %d, %d ", variavelDestino->nivel_lexico, variavelDestino->deslocamento);
		geraCodigo(NULL, varLexDisp);
		variavelDestino = NULL;
	}
#line 2190 "compilador.tab.c"
    break;

  case 136: /* lista_escrita: lista_escrita VIRGULA expressao  */
#line 752 "compilador.y"
                                        { geraCodigo (NULL, "IMPR"); }
#line 2196 "compilador.tab.c"
    break;

  case 137: /* lista_escrita: expressao  */
#line 753 "compilador.y"
                    { geraCodigo (NULL, "IMPR"); }
#line 2202 "compilador.tab.c"
    break;


#line 2206 "compilador.tab.c"

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

#line 756 "compilador.y"


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
   cria_pilha(&tabelaSimbolos);
   cria_pilha_tipo(&tabelaTipo);
   cria_pilha_rotulo(&pilha_rotulos);
   cria_pilha_no(&pilhano);

   funcao_atual = malloc(100);
   por_ref = 0;
   yyin=fp;
   yyparse();

   return 0;
}
