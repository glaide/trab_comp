
// Testar se funciona corretamente o empilhamento de par�metros
// passados por valor ou por refer�ncia.


%{
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

%}

%token PROGRAM ABRE_PARENTESES FECHA_PARENTESES
%token VIRGULA PONTO_E_VIRGULA DOIS_PONTOS PONTO
%token T_BEGIN T_END VAR IDENT ATRIBUICAO
%token NUMERO INTEGER PROCEDURE WHILE DO
%token IF THEN ELSE
%token IGUAL DIFERENTE MENOR MENOR_IGUAL MAIOR_IGUAL MAIOR
%token SOMA SUBTRACAO MULTIPLICACAO DIVISAO DIV AND
%token READ WRITE

%%
/* regra 1 */
programa    :{ //TODO: rever todo esse bloco
             geraCodigo (NULL, "INPP");
             char * RotInicioSubrotina = cria_rotulo(num_Rotulos);
						 num_Rotulos++;
						 push_tabela_rotulos(&pilhaRotulo, RotInicioSubrotina);
             }
             PROGRAM IDENT parametros_ou_nada PONTO_E_VIRGULA
             bloco PONTO {
               char dmem[1000];
               sprintf(dmem, "DMEM %d", num_vars);
               geraCodigo(NULL, dmem);
               geraCodigo (NULL, "PARA");
             }
;

parametros_ou_nada: parametros {

}
                  | nada {

                  };

parametros: ABRE_PARENTESES lista_idents FECHA_PARENTESES;

nada: {

};
/* regra 2 */
bloco       : //TODO: rever todo esse bloco
              parte_declara_vars
              {
               // momento em que é feita a parte do desvio
               // cria um novo rotulo
               char rotuloPrint[100];
               rotuloAtual = pega_rotulo(&pilhaRotulo,0);
               sprintf(rotuloPrint, "DSVS %s", rotuloAtual);
               geraCodigo(NULL, rotuloPrint);
              }
              parte_declara_sub_rotinas
              {
               char rotuloPrint[100];
               rotuloAtual = pega_rotulo(&pilhaRotulo,0);
               sprintf(rotuloPrint, "%s", rotuloAtual);
               geraCodigo(rotuloPrint, "NADA");
              }
              comando_composto;



/* regra 8 */
parte_declara_vars:  var {
      char amem[100];
		sprintf(amem, "AMEM %d", num_vars);
		atualizaNumeroVariaveis(&tabela_simbolos, num_vars, nivel_lexico);
		geraCodigo(NULL, amem);
}

;


var         :  VAR declara_vars
            | declara_var
;

declara_vars: declara_vars declara_var
            | declara_var
;

/* regra 11 */
/* pode ter mais de uma subrotila */
parte_declara_sub_rotinas: parte_declara_sub_rotinas {


}
regra_sub_rotina | nada;

regra_sub_rotina:  declara_procedimento  | nada; //TODO: implementar

/* regra 12 */
declara_procedimento: PROCEDURE IDENT
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

} parametros_formais_ou_nada PONTO_E_VIRGULA bloco;

parametros_formais_ou_nada: parametros_formais | nada;

/* regra 14 */
parametros_formais: ABRE_PARENTESES parametros_formais PONTO_E_VIRGULA secao_parametros_formais | secao_parametros_formais;

/* regra 15 */
/* <seção de parâmetros formais> =::
[var] <lista de identificadores>: <identificador>
*/
secao_parametros_formais: var_ou_nada lista_idents DOIS_PONTOS tipo;

var_ou_nada: VAR | nada;

/* complementar */
/* TODO: implementar */
/* declara_funcao: nada; */


/* regra 9 */
declara_var : {
   novasVariaveis= 0;
}
              lista_id_var DOIS_PONTOS
              tipo
              { /* AMEM */
               // atualiza quantas variaveis tem
               num_vars+=novasVariaveis;

               //para usar amem tem que saber qual deslocamento
               //TODO: implementar
              }
              PONTO_E_VIRGULA
;

tipo        : INTEGER {

   setaTipo(&tabela_simbolos, integer, novasVariaveis);
}
/* TODO: colocar o tipo que será salvo na tabela de simbolos */
;

/* regra 10 conta quantas variaveis tem */
lista_id_var: lista_id_var VIRGULA IDENT
              { /* insere ultima vars na tabela de s�mbolos */
               novasVariaveis++;
               //  add na tabela de simbolos
               nova_entrada = criaVariavelSimples(token,nivel_lexico,deslocamento);
               push_tabela_simbolos(&tabela_simbolos, nova_entrada);
               deslocamento++;


               //  no futuro setar o valor de deslocamento tb
                }
            | IDENT { /* insere vars na tabela de s�mbolos */
               novasVariaveis++;
               nova_entrada = criaVariavelSimples(token,nivel_lexico,deslocamento);
               push_tabela_simbolos(&tabela_simbolos, nova_entrada);
               deslocamento++;
               }
;

lista_idents: lista_idents VIRGULA IDENT
//aqui entram os parametros formais
            | IDENT
;

/* regra 16 */
comando_composto: T_BEGIN  comandos  T_END
comandos:
	comandos PONTO_E_VIRGULA comando
	| comando
;

/* regra 17 */
comando: numero_ou_nada{

} comando_sem_rotulo;

/* regra 32 */
numero_ou_nada: numero {

} DOIS_PONTOS | nada {

} ;

/* regra 18 */
comando_sem_rotulo: comando_atribuicao
                  /* | comando_chama_procedimento */
                  | comando_composto
                  | comando_if
                  | comando_while
                  | read
                  /* | write */
                  | nada;

read: READ ABRE_PARENTESES lista_leitura FECHA_PARENTESES;

lista_leitura:
   	lista_leitura VIRGULA simbolo_leitura | simbolo_leitura;

simbolo_leitura:
	IDENT
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
;

/* write:
   	WRITE ABRE_PARENTESES lista_escrita FECHA_PARENTESES
; */

lista_escrita:
	lista_escrita VIRGULA expressao
   { geraCodigo (NULL, "IMPR"); }
	| expressao { geraCodigo (NULL, "IMPR"); }
;
/* regra 19 */
comando_atribuicao: variavel ATRIBUICAO expressao
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
	};

/* regra 30 */

variavel: IDENT {
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
numero: NUMERO {
	//TODO: add na tabela de tipos

		push_pilha_Tipo(&tabelaTipo, integer);

	    char totalVars[100];
		sprintf(totalVars, "CRCT %s", token);
		geraCodigo(NULL, totalVars);
}


/* regra 23 */
comando_while: WHILE {
   //Cria rotulos do inicio e fim do While e adiciona eles na pilha de rotulos
      char *inicio_while = cria_rotulo(num_Rotulos);
      num_Rotulos++;
      char *fim_while = cria_rotulo(num_Rotulos);
      num_Rotulos++;

      push_tabela_rotulos(&pilhaRotulo, inicio_while);
      push_tabela_rotulos(&pilhaRotulo, fim_while);
      rotuloAtual = pega_rotulo(&pilhaRotulo, 2);
      geraCodigo(rotuloAtual, "NADA");

   } expressao DO
   {
      char dsvf[100];
      rotuloAtual = pega_rotulo(&pilhaRotulo, 1);
		sprintf(dsvf, "DSVF %s", rotuloAtual);
		geraCodigo(NULL, dsvf);
   } comando_composto {

      char dsvs[100];
      rotuloAtual = pega_rotulo(&pilhaRotulo, 2);
		sprintf(dsvs, "DSVS %s",rotuloAtual);
		geraCodigo(NULL, dsvs);

		char rot[100];
      rotuloAtual = pega_rotulo(&pilhaRotulo, 1);
		sprintf(rot, "%s", rotuloAtual);
		geraCodigo(rot, "NADA");

		pop_tabela_rotulos(&pilhaRotulo, 2);
   };



comando_if:
       if_then cond_else{

       }
if_then: IF{} expressao{}
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
       THEN comando_sem_rotulo

cond_else:
      ELSE{
         char rot[100];
         rotuloAtual = pega_rotulo(&pilhaRotulo, 2);
		   sprintf(rot, "DSVS %s", rotuloAtual);
		   geraCodigo(NULL, rot);

         rotuloAtual = pega_rotulo(&pilhaRotulo, 1);
		   geraCodigo(rotuloAtual, "NADA");
      }

/* regra 25 */
expressao: expressao_simples relacao_expressao_simples {

};


relacao_expressao_simples: relacao expressao_simples | nada
{

};

/* regra 26 */
relacao:
	IGUAL {
      strcpy(sinal_da_comparacao,"CMIG");
   }
	| DIFERENTE {
      strcpy(sinal_da_comparacao,"CMDG");
   }
	| MENOR {
      strcpy(sinal_da_comparacao,"CMME");
   }
	| MENOR_IGUAL {
      strcpy(sinal_da_comparacao,"CMEG");
   }
   | MAIOR {
      strcpy(sinal_da_comparacao,"CMMA");
   }
	| MAIOR_IGUAL {
      strcpy(sinal_da_comparacao,"CMAG");
   }

;

/* regra 27 */
expressao_simples: mais_ou_menos {

} expressao_mais_menos_termo;

mais_ou_menos: SOMA | SUBTRACAO | nada {

}  ;

/* regra 28 */
/* <fator> {(*|div|and) <fator> } */
termo: termo lista_fator| fator {

};

lista_fator:
	MULTIPLICACAO fator {
		verifica_tipo(&tabelaTipo, "multiplicacao");
		geraCodigo(NULL, "MULT");}
	| DIVISAO fator {
		verifica_tipo(&tabelaTipo, "divisao");
		geraCodigo(NULL, "DIVI"); }
	| DIV fator {
		verifica_tipo(&tabelaTipo, "div");
		geraCodigo(NULL, "DIVI"); }
	| AND fator {
		verifica_tipo(&tabelaTipo, "and");
		geraCodigo(NULL, "CONJ"); }
;
/* regra 29 */
fator: numero | variavel {
      if(carregada != NULL) {
			printf("variavel carregada: %s\n", carregada->rotulo);
			if(carregada->categoria == funcao) {
				char chamaProcedure[100];
				sprintf(chamaProcedure, "CHPR %s, %d", carregada->rotulo, nivel_lexico);
				geraCodigo(NULL, chamaProcedure);

			}
			else {
				char comando[100];
				int numero_parametros = esta_no_procedimento == 2 ?
												(procedimento_atual->numero_parametros - qnt_var_parametro + 1) : qnt_novas_var_parametro;
				int passagem_parametro = esta_no_procedimento == 0 ? carregada->passagem_parametro :
																				 procedimento_atual->parametros[procedimento_atual->numero_parametros - numero_parametros].tipo_passado;
            int eh_ref_carregada= (passagem_parametro == REFERENCIA && esta_no_procedimento == 1 && carregada->passagem_parametro == REFERENCIA);
				if (passagem_parametro == VALOR || eh_ref_carregada)
					sprintf(comando, "CRVL %d, %d", carregada->nivel_lexico, carregada->deslocamento);

				else if (esta_no_procedimento >= 1 && passagem_parametro == REFERENCIA)
            sprintf(comando, "CREN %d, %d", carregada->nivel_lexico, carregada->deslocamento);
				else
					sprintf(comando, "CRVI %d, %d", carregada->nivel_lexico, carregada->deslocamento);
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
				int passagem_parametro = esta_no_procedimento == 0 ? destino->passagem_parametro :
									procedimento_atual->parametros[procedimento_atual->numero_parametros - qnt_novas_var_parametro].tipo_passado;
            int eh_ref =(passagem_parametro == REFERENCIA && esta_no_procedimento == 1 && destino->passagem_parametro == REFERENCIA);
				if (passagem_parametro == VALOR || eh_ref)
					sprintf(comando, "CRVL %d, %d", destino->nivel_lexico, destino->deslocamento);
				else if (esta_no_procedimento == 1 && passagem_parametro == REFERENCIA)
					sprintf(comando, "CREN %d, %d", destino->nivel_lexico, destino->deslocamento);
				else
					sprintf(comando, "CRVI %d, %d", destino->nivel_lexico, destino->deslocamento);
				destino = NULL;
				geraCodigo(NULL, comando);
			}
		}
};

expressao_mais_menos_termo:expressao_mais_menos_termo lista_e_termo | termo ; //TODO: implementar

lista_e_termo:

	SOMA termo {
		verifica_tipo(&tabelaTipo, "soma");
		geraCodigo(NULL, "SOMA");}
	| SUBTRACAO termo {
		verifica_tipo(&tabelaTipo, "subtracao");
		geraCodigo(NULL, "SUBT");}

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
   criar_tabela_simbolos(&tabela_simbolos);
   cria_pilha_rotulo(&pilhaRotulo);
   cria_pilha_Tipo(&tabelaTipo);

   return 0;
}
