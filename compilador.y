
// Testar se funciona corretamente o empilhamento de par�metros
// passados por valor ou por refer�ncia.


%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "compilador.h"

int num_vars, novasVariaveis, deslocamento;

%}

%token PROGRAM ABRE_PARENTESES FECHA_PARENTESES
%token VIRGULA PONTO_E_VIRGULA DOIS_PONTOS PONTO
%token T_BEGIN T_END VAR IDENT ATRIBUICAO

%%
/* regra 1 */
programa    :{
             geraCodigo (NULL, "INPP");
             }
             PROGRAM IDENT
             ABRE_PARENTESES lista_idents FECHA_PARENTESES PONTO_E_VIRGULA
             bloco PONTO {
             geraCodigo (NULL, "PARA");
             }
;
/* regra 2 */
bloco       :
              parte_declara_vars
              {
              }

              comando_composto
              ;



/* regra 8 */
parte_declara_vars:  var
;


var         : { } VAR declara_vars
            | declara_var
;

declara_vars: declara_vars declara_var
            | declara_var
;

/* regra 9 */
declara_var : {
   novasVariaveis= 0;
}
              lista_id_var DOIS_PONTOS
              tipo
              { /* AMEM */
               // atualiza quantas variaveis tem
               num_vars+=novasVariaveis;
               printf("num de variaveis %d\n", num_vars);
               //para usar amem tem que saber qual deslocamento

              }
              PONTO_E_VIRGULA
;

tipo        : IDENT
/* TODO: colocar o tipo que será salvo na tabela de simbolos */
;

/* regra 10 conta quantas variaveis tem */
lista_id_var: lista_id_var VIRGULA IDENT
              { /* insere ultima vars na tabela de s�mbolos */
                novasVariaveis++;
                deslocamento++;
               //  add na tabela de simbolos
               // criar uma funcao para criar variavel simples
               //  no futuro setar o valor de deslocamento tb
                }
            | IDENT { /* insere vars na tabela de s�mbolos */
              novasVariaveis++;
               //  no futuro setar o valor de deslocamento tb
               }
;

lista_idents: lista_idents VIRGULA IDENT
            | IDENT
;


comando_composto: T_BEGIN comandos T_END

comandos:
;


%%

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

   return 0;
}
