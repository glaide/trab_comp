
/* -------------------------------------------------------------------
 *            Arquivo: compilador.l
 * -------------------------------------------------------------------
 *              Autor: Bruno Muller Junior
 *               Data: 08/2007
 *      Atualizado em: [09/08/2020, 19h:01m]
 *
 * -------------------------------------------------------------------
 *
 * Tipos, protótipos e variáveis globais do compilador (via extern)
 *
 * ------------------------------------------------------------------- */

%{


#include<stdio.h>
#include<string.h>

#include "compilador.h"
#include "compilador.tab.h"

//#define IMPRIME(STR) {};
#define IMPRIME(STR) printf("%s    # %s \n", STR, token);

int nl = 1;

%}

pulo_linha [\n]

descarte [\t ]+

ident [a-zA-Z][a-zA-Z0-9]*

numero [0-9]+

comentario "(*".*"*)"

%%

{pulo_linha} {nl++;}

{descarte}

{comentario}

program { simbolo  = simb_program;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("program ");
          return PROGRAM;
 }

var      { simbolo = simb_var;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("var  ");
          return VAR;
 }

begin { simbolo = simb_begin;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("begin ");
          return T_BEGIN;
 }

end { simbolo = simb_end;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME("end  ");
          return T_END;
 }

:= { simbolo = simb_atribuicao;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" atribuicao  ");
          return ATRIBUICAO;
 }

\; { simbolo = simb_ponto_e_virgula;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" pt_virgula  ");
          return PONTO_E_VIRGULA;
 }

\: { simbolo = simb_dois_pontos;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" dois pontos ");
          return DOIS_PONTOS;
 }

\, { simbolo = simb_virgula;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" virgula  ");
          return VIRGULA;
 }


\. { simbolo = simb_ponto;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" ponto  ");
          return PONTO;
    }

\(  { simbolo = simb_abre_parenteses;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" abre_parenteses  ");
          return ABRE_PARENTESES;
    }

\)  { simbolo = simb_fecha_parenteses;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" fecha_parenteses ");
          return FECHA_PARENTESES;
 }

\+ { simbolo = simb_soma;
        strncpy (token, yytext, TAM_TOKEN);
        IMPRIME("soma");
        return SOMA;
}

\- { simbolo = simb_subtracao;
        strncpy (token, yytext, TAM_TOKEN);
        IMPRIME("subtracao");
        return SUBTRACAO;
}

\= { simbolo = simb_igual;
        strncpy (token, yytext, TAM_TOKEN);
        IMPRIME("igual");
        return IGUAL;
}

\<> { simbolo = simb_diferente;
        strncpy (token, yytext, TAM_TOKEN);
        IMPRIME("diferente");
        return DIFERENTE;
}

\< { simbolo = simb_menor;
        strncpy (token, yytext, TAM_TOKEN);
        IMPRIME("menor");
        return MENOR;
}

\<= { simbolo = simb_menor_igual;
        strncpy (token, yytext, TAM_TOKEN);
        IMPRIME("menor_igual");
        return MENOR_IGUAL;
}

\>= { simbolo = simb_maior_igual;
        strncpy (token, yytext, TAM_TOKEN);
        IMPRIME("maior_igual");
        return MAIOR_IGUAL;
}

\> { simbolo = simb_maior;
        strncpy (token, yytext, TAM_TOKEN);
        IMPRIME("maior");
        return MAIOR;
}

















while { simbolo = simb_while;
        strncpy (token, yytext, TAM_TOKEN);
        IMPRIME("while");
        return WHILE;
}

do { simbolo = simb_do;
       strncpy (token, yytext, TAM_TOKEN);
       IMPRIME("do");
       return DO;
}

integer { simbolo = simb_integer;
           strncpy (token, yytext, TAM_TOKEN);
           IMPRIME(" integer ");
           return INTEGER;
}
\* { simbolo = simb_multiplicacao;
        strncpy (token, yytext, TAM_TOKEN);
        IMPRIME("multiplicacao ");
        return MULTIPLICACAO;
}

\/ { simbolo = simb_divisao;
        strncpy (token, yytext, TAM_TOKEN);
        IMPRIME("divisao");
        return DIVISAO;
}

div { simbolo = simb_div;
        strncpy (token, yytext, TAM_TOKEN);
        IMPRIME("div");
        return DIV;
}

and { simbolo = simb_and;
        strncpy (token, yytext, TAM_TOKEN);
        IMPRIME("e");
        return AND;
}

read { simbolo = simb_read;
              strncpy (token, yytext, TAM_TOKEN);
              IMPRIME("read");
              return READ;
}

write { simbolo = simb_write;
              strncpy (token, yytext, TAM_TOKEN);
              IMPRIME("write");
              return WRITE;
}

{numero} { simbolo = simb_numero;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" numero  ");
          return NUMERO;
          }

{ident} { simbolo = simb_identificador;
          strncpy (token, yytext, TAM_TOKEN);
          IMPRIME(" ident  ");
          return IDENT;
        }

%%
// procedure { simbolo = simb_procedimento;
//            strncpy (token, yytext, TAM_TOKEN);
//            IMPRIME("procedure");
//            return PROCEDURE;
//}
//%%


