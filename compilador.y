
// Testar se funciona corretamente o empilhamento de par�metros
// passagemados por VALOR ou por refer�ncia.


%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "compilador.h"
#include "pilha.h"
#include "tabelaSimbolos.h"


int numero_variaveis, numero_parametros, nivel_lexico, deslocamento;
int entra_procedimento,aux_var, novas_variaveis, novos_param,por_ref;
char *rotulo_fim_subr;
int rotulo_print = 0;

int num_params_chamada;
char comparacao[100], rotuloPrint[100], *funcao_atual;

pilha_simbolos tabelaSimbolos;
type_info_tabela_simbolos *novaEntrada, *destino, *carregada, *procedimento_atual;
tipo_pilha tabelaTipo;
pilha_rotulo pilha_rotulos;
pilha_no tabelaNode;

%}

%token PROGRAM ABRE_PARENTESES FECHA_PARENTESES
%token VIRGULA PONTO_E_VIRGULA DOIS_PONTOS PONTO
%token T_BEGIN T_END VAR IDENT ATRIBUICAO
%token INTEGER
%token WHILE DO IF THEN ELSE
%token MAIOR MENOR MAIOR_IGUAL MENOR_IGUAL IGUAL DIFERENTE
%token SOMA SUBTRACAO MULTIPLICACAO DIVISAO DIV
%token NUMERO READ WRITE
%token PROCEDURE FUNCTION


%%

programa    :{
             	geraCodigo (NULL, "INPP");
             	char * RotInicioSubrotina = cria_rotulo(rotulo_print);
				rotulo_print++;
				push_pilha_rotulo(&pilha_rotulos, RotInicioSubrotina);
				procedimento_atual = cria_variavel_procedure("main", RotInicioSubrotina, 0, 0);
				push(&tabelaSimbolos, procedimento_atual);
				push_pilha_no(&tabelaNode, procedimento_atual);
			}
            PROGRAM IDENT parametros_nada PONTO_E_VIRGULA
            bloco PONTO {
				procedimento_atual = pop_pilha_no(&tabelaNode);
            	pop(&tabelaSimbolos, procedimento_atual->numero_variaveis + procedimento_atual->numero_procedimentos);
            	char dmem[1000];

            	sprintf(dmem, "DMEM %d", procedimento_atual->numero_variaveis);
               	geraCodigo(NULL, dmem);
               	geraCodigo (NULL, "PARA");
            }
;

parametros_nada:parametros | nada;

parametros:
	ABRE_PARENTESES lista_idents FECHA_PARENTESES
;

tipo:
	INTEGER {
		seta_tipos(&tabelaSimbolos, integer, novas_variaveis);
	}
;



bloco:
     		parte_declara_vars
				{
					// faz o desvio pro rotulo
					char rotsaida[100];
      				sprintf(rotsaida, "DSVS %s", pega_rotulo(&pilha_rotulos,0));
					geraCodigo(NULL, rotsaida);
				}
			parte_declara_sub_rotinas
			  {
				char rotsaida[100];
     			sprintf(rotsaida, "%s", pega_rotulo(&pilha_rotulos,0));
     			geraCodigo(rotsaida, "NADA");
				}
        	comando_composto
;

parte_declara_vars:  var {
    	char amem[100];
		sprintf(amem, "AMEM %d", numero_variaveis);
		atualiza_num_variaveis(&tabelaSimbolos, numero_variaveis, nivel_lexico);
		geraCodigo(NULL, amem);
}
;

parte_declara_sub_rotinas: parte_declara_sub_rotinas regra_subrotina | nada
;

regra_subrotina:
	declaracao_procedimento {
		atualiza_num_procedimentos(&tabelaSimbolos, nivel_lexico);
	} PONTO_E_VIRGULA
	| declaracao_funcao {
		atualiza_num_procedimentos(&tabelaSimbolos, nivel_lexico);
	} PONTO_E_VIRGULA
	| nada;


var         : VAR declara_vars | declara_vars;

declara_vars: declara_vars declara_var| declara_var;

declara_var : {
              novas_variaveis = 0;
}
              lista_id_var DOIS_PONTOS tipo
              {
                numero_variaveis += novas_variaveis;

              }
              PONTO_E_VIRGULA
;


lista_id_var: lista_id_var VIRGULA IDENT
              { /* insere �ltima vars na tabela de s�mbolos */
                novas_variaveis++;
                novaEntrada = cria_variavel_simples(token, nivel_lexico, deslocamento);
                push(&tabelaSimbolos, novaEntrada);
                deslocamento++;}
            | IDENT { /* insere vars na tabela de s�mbolos */
                novas_variaveis++;
                novaEntrada = cria_variavel_simples(token, nivel_lexico, deslocamento);
                push(&tabelaSimbolos, novaEntrada);
                deslocamento++;
                }
;

lista_idents: lista_idents VIRGULA IDENT{
		novas_variaveis++;
		numero_parametros++;
		novaEntrada = cria_variavel_formal(token, nivel_lexico, 1, por_ref ? REFERENCIA : VALOR);
		push(&tabelaSimbolos, novaEntrada);
	}
   	| IDENT
	{
		novas_variaveis++;
		numero_parametros++;
		novaEntrada = cria_variavel_formal(token, nivel_lexico, 1, por_ref ? REFERENCIA : VALOR);
		push(&tabelaSimbolos, novaEntrada);
	}
;


comando_while:
	WHILE
	{
		// cria os rotulos de entrada e saida
		char *inicio_while = cria_rotulo(rotulo_print);
		rotulo_print++;
		char *fim_while = cria_rotulo(rotulo_print);
		rotulo_print++;
		// insere os rotulos na pilha de rotulos
		push_pilha_rotulo(&pilha_rotulos, inicio_while);
		push_pilha_rotulo(&pilha_rotulos, fim_while);

		char rot[100];
		geraCodigo(pega_rotulo(&pilha_rotulos, 2), "NADA");
	}
	expressao DO
	{
		char dsvf[100];
		// verificar desvio
		sprintf(dsvf, "DSVF %s", pega_rotulo(&pilha_rotulos, 1));
		geraCodigo(NULL, dsvf);
	}
	comando_composto
	{
		char dsvs[100];
		sprintf(dsvs, "DSVS %s", pega_rotulo(&pilha_rotulos, 2));
		geraCodigo(NULL, dsvs);

		char rot[100];
		sprintf(rot, "%s", pega_rotulo(&pilha_rotulos, 1));
		geraCodigo(rot, "NADA");

		pop_pilha_rotulo(&pilha_rotulos, 2);
	}
;


comando_if:
	if else
	{
		char rot[100];
		geraCodigo(pega_rotulo(&pilha_rotulos, 2), "NADA");
		pop_pilha_rotulo(&pilha_rotulos, 2);
	}
;

if:
	IF  expressao
	{
		inicia_else(); //testar se tem else
		// Gera rotulos de entrada e saida do if
		char *RotIfInicio = cria_rotulo(rotulo_print);
		rotulo_print++;
		char *RotIfFim = cria_rotulo(rotulo_print);
		rotulo_print++;

		push_pilha_rotulo(&pilha_rotulos, RotIfInicio);
		push_pilha_rotulo(&pilha_rotulos, RotIfFim);

		// imprime rotulo de entrada do if
		char rot[100];
		sprintf(rot, "DSVF %s", pega_rotulo(&pilha_rotulos, 1));
		geraCodigo(NULL, rot);
	} THEN comando_sem_rotulo
;

else:
	ELSE
	{
		seta_else();//seta que ta no else

		char rot[100];
		sprintf(rot, "DSVS %s", pega_rotulo(&pilha_rotulos, 2));
		geraCodigo(NULL, rot);

		// imprime rotulo de entrada no fim do if
		geraCodigo(pega_rotulo(&pilha_rotulos, 1), "NADA");
	}
	else_multiplo_unico| nada;

else_multiplo_unico: comando_sem_rotulo;

declaracao_procedimento:
	PROCEDURE
	IDENT
	{

		// gera rotulos de entrada e saida
		char *RotInicioSubrotina = cria_rotulo(rotulo_print);
		rotulo_print++;

		rotulo_fim_subr = cria_rotulo(rotulo_print);
		rotulo_print++;
		push_pilha_rotulo(&pilha_rotulos, RotInicioSubrotina);
		push_pilha_rotulo(&pilha_rotulos, rotulo_fim_subr);
		nivel_lexico++;

		// imprime rotulo de entrada da subrotina
		char rotentrada[100];
		sprintf(rotentrada, "ENPR %d", nivel_lexico);
		geraCodigo(pega_rotulo(&pilha_rotulos, 2), rotentrada);

		novaEntrada = cria_variavel_procedure(token, RotInicioSubrotina, nivel_lexico, 0);
		push(&tabelaSimbolos, novaEntrada);
		// Insere na pilha de nos
		push_pilha_no(&tabelaNode,  novaEntrada);
		procedimento_atual = novaEntrada;
	}
	{ novos_param = 0; } parametros_formais_vazio PONTO_E_VIRGULA
	{
		// Zera para ser utilizado na subrotina e salva para ser recuperado
		aux_var = numero_variaveis;
		numero_variaveis = 0;
		deslocamento = 0;
	}
	bloco
	{

		procedimento_atual = (type_info_tabela_simbolos*) pop_pilha_no(&tabelaNode);
		pop(&tabelaSimbolos, procedimento_atual->numero_procedimentos); // tira procedure de simbolos

		// DMEM nas variaveis do procedimento
		pop(&tabelaSimbolos, procedimento_atual->numero_variaveis);
		char dmem[100];
		sprintf(dmem, "DMEM %d", procedimento_atual->numero_variaveis);
		geraCodigo(NULL, dmem);
		pop(&tabelaSimbolos, procedimento_atual->numero_parametros); // tira parametros de simbolos


		destino = pega_topo(&tabelaSimbolos);
		if(destino == NULL) {
			printf("Tabela de simbolos: procedimento nao encontrado!\n");
			exit(1);
		}
		char command[100];
		sprintf(command, "RTPR %d, %d", nivel_lexico, procedimento_atual->numero_parametros);
		geraCodigo(NULL, command);

		novos_param = 0;
		nivel_lexico--;

		destino = NULL;
		numero_variaveis = aux_var;
		pop_pilha_rotulo(&pilha_rotulos, 2);

	}
;

declaracao_funcao:
  FUNCTION
  IDENT
  {


	char *RotInicioSubrotina = cria_rotulo(rotulo_print);
	rotulo_print++;

	rotulo_fim_subr = cria_rotulo(rotulo_print);
	rotulo_print++;
	push_pilha_rotulo(&pilha_rotulos, RotInicioSubrotina);
	push_pilha_rotulo(&pilha_rotulos, rotulo_fim_subr);
	nivel_lexico++;


	char rotentrada[100];
	sprintf(rotentrada, "ENPR %d", nivel_lexico);
	geraCodigo(pega_rotulo(&pilha_rotulos, 2), rotentrada);


	if (funcao_atual != NULL) {
		strcpy(funcao_atual, token);
		novaEntrada = cria_variavel_funcao(token, RotInicioSubrotina, nivel_lexico, 0, integer);
		push(&tabelaSimbolos, novaEntrada);
		push_pilha_no(&tabelaNode,  novaEntrada);
		procedimento_atual = novaEntrada;
	}
novos_param = 0;
  } parametros_formais_vazio DOIS_PONTOS tipo PONTO_E_VIRGULA
  {

    aux_var = numero_variaveis;
    numero_variaveis = 0;
    deslocamento = 0;
  }
  bloco
  {
	procedimento_atual = (type_info_tabela_simbolos*) pop_pilha_no(&tabelaNode);
	pop(&tabelaSimbolos, procedimento_atual->numero_procedimentos);


	pop(&tabelaSimbolos, procedimento_atual->numero_variaveis);
	char dmem[100];
	sprintf(dmem, "DMEM %d", procedimento_atual->numero_variaveis);
	geraCodigo(NULL, dmem);

	pop(&tabelaSimbolos, procedimento_atual->numero_parametros);


	destino = pega_topo(&tabelaSimbolos);
	if (destino == NULL) {
		printf("Tabela de simbolos: rocedimento não encontrado!\n");
		exit(1);
	}

	char command[100];
	sprintf(command, "RTPR %d, %d", nivel_lexico, numero_parametros);
	geraCodigo(NULL, command);

	novos_param = 0;
	nivel_lexico--;

	destino = NULL; // Libera variável destino
	numero_variaveis = aux_var;    // Restabelece número de variáveis no nível léxico



    pop_pilha_rotulo(&pilha_rotulos, 2);
  }
;

parametros_formais_vazio: parametros_formais| nada;

parametros_formais:
ABRE_PARENTESES { numero_parametros = 0; }
	lista_parametros_formais
	FECHA_PARENTESES
	{
		atualiza_parametros(pega_posicao(&tabelaSimbolos, numero_parametros),
								&tabelaSimbolos, numero_parametros);
	}
;

lista_parametros_formais:
	lista_parametros_formais PONTO_E_VIRGULA secao_parametros_formais
	| { novos_param++; } secao_parametros_formais
;

secao_parametros_formais:
  var_vazio { novas_variaveis = 0; } lista_idents DOIS_PONTOS tipo
;

var_vazio:
	VAR {por_ref = 1; } | nada {por_ref = 0; }
;

comando_composto:
   T_BEGIN comandos T_END
;

comandos:
	comandos PONTO_E_VIRGULA comando
	| comando
;

comando:
   	nunero_nada comando_sem_rotulo
;

nunero_nada:
	numero DOIS_PONTOS | nada
;

nada:;

comando_sem_rotulo:
	variavel atribuicao_procedimento
	| atribuicao_funcao
	| comando_composto
	| comando_if
	| comando_while
	| leitura
	| escrita
;



chama_procedimento:
    {
		entra_procedimento = 1;
		// Imprime rotulo de entrada da subrotina
		procedimento_atual = destino;
		sprintf(rotuloPrint, "CHPR %s, %d", destino->rotulo, nivel_lexico);
		entra_procedimento = 1;

   	}
	ABRE_PARENTESES {
		 novos_param = 0;
	}
	lista_expressoes_ou_vazio
	FECHA_PARENTESES
	{
		entra_procedimento = 0;
		geraCodigo(NULL, rotuloPrint);

	}
	{ destino = NULL; }
	|
	{

		entra_procedimento = 1;
		procedimento_atual = destino;
		// Imprime rotulo de entrada da subrotina
		char rotuloPrint[100];
		sprintf(rotuloPrint, "CHPR %s, %d", destino->rotulo, nivel_lexico);
		geraCodigo(NULL, rotuloPrint);
		destino = NULL;
		entra_procedimento = 0;
	}

;

chama_funcao:
    {
    entra_procedimento = 1;
    // Imprime rotulo de entrada da subrotina
    procedimento_atual = destino;
    sprintf(rotuloPrint, "CHPR %s, %d", destino->rotulo, nivel_lexico);
    geraCodigo(NULL, "AMEM 1"); // making up space for the function return
    }
  ABRE_PARENTESES { ; novos_param = 0; }
  lista_expressoes_ou_vazio
  FECHA_PARENTESES
  {
    entra_procedimento = 0;
    geraCodigo(NULL, rotuloPrint);

  }
  { destino = NULL; }
;

lista_expressoes_ou_vazio:
	lista_expressoes
	| nada
;







lista_expressoes: expressao | expressao {num_params_chamada++;} VIRGULA lista_expressoes;

expressao:
   	{ novos_param++; } expressao_simples  relacao_exp_simples_ou_vazio
;

relacao_exp_simples_ou_vazio:
	relacao expressao_simples
	/* {

		verifica_tipo(&tabelaTipo, "relacional");
		geraCodigo(NULL, comparacao);
	} */
	| nada
{
   printf("entrou nesse nada\n");
};

relacao:
	IGUAL {
		strcpy(comparacao, "CMIG");
	}
	| DIFERENTE {
		strcpy(comparacao, "CMDG");
	}
	| MENOR {
		strcpy(comparacao, "CMME");
	}
	| MENOR_IGUAL {
		strcpy(comparacao, "CMEG");
	}
	| MAIOR_IGUAL {
		strcpy(comparacao, "CMAG");
	}
	| MAIOR {
		strcpy(comparacao, "CMMA");
	}
;

expressao_simples:
   	soma_ou_vazio expressao_lista_termo
;

soma_ou_vazio:
	SOMA {
		printf("soma ou vazio\n");
	}
		| SUBTRACAO | nada

;

expressao_lista_termo:
	expressao_lista_termo lista_termo
	| termo
;

lista_termo:
	{
		printf("Lista termo\n");
	}
	SOMA {
		printf("soma\n");
	} termo {
		verifica_tipo(&tabelaTipo, "soma");
		geraCodigo(NULL, "SOMA");}
	| SUBTRACAO termo {
		verifica_tipo(&tabelaTipo, "subtracao");
		geraCodigo(NULL, "SUBT");
		}
;

termo:
	termo lista_fator
	| fator {
		printf("saiu de fator\n");
	}
;

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
;

fator:
	variavel
	{
		if(carregada != NULL) {
			printf("variavel carregada: %s\n", carregada->rotulo);
			if(carregada->categoria == funcao) {
				char chamaProcedure[100];
				sprintf(chamaProcedure, "CHPR %s, %d", carregada->rotulo, nivel_lexico);
				geraCodigo(NULL, chamaProcedure);

			}
			else {
				char comando[100];
				int cur_params, passagem;

				if (entra_procedimento == 2) {
					cur_params = procedimento_atual->numero_parametros - num_params_chamada + 1;
				} else {
					cur_params = novos_param;
				}

				if (entra_procedimento == 0) {
					passagem = carregada->passagem;
				} else {
					passagem = procedimento_atual->params[procedimento_atual->numero_parametros - cur_params].passagem;
				}

				if (passagem == VALOR || (passagem == REFERENCIA && entra_procedimento == 1 && carregada->passagem == REFERENCIA)) {
					sprintf(comando, "CRVL %d, %d", carregada->nivel_lexico, carregada->deslocamento);
				} else if (entra_procedimento >= 1 && passagem == REFERENCIA) {
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
				int passagem;

				if (entra_procedimento == 0) {
					passagem = destino->passagem;
				} else {
					passagem = procedimento_atual->params[procedimento_atual->numero_parametros - novos_param].passagem;
				}

				if (passagem == VALOR || (passagem == REFERENCIA && entra_procedimento == 1 && destino->passagem == REFERENCIA)) {
					sprintf(comando, "CRVL %d, %d", destino->nivel_lexico, destino->deslocamento);
				} else if (entra_procedimento == 1 && passagem == REFERENCIA) {
					sprintf(comando, "CREN %d, %d", destino->nivel_lexico, destino->deslocamento);
				} else {
					sprintf(comando, "CRVI %d, %d", destino->nivel_lexico, destino->deslocamento);
				}

				destino = NULL;
				geraCodigo(NULL, comando);

			}
		}
	}
	| variavel {
		printf("saiu de variave 2l\n");
	}
	ABRE_PARENTESES
	{
		entra_procedimento = 2;
		num_params_chamada = 0;

		if(carregada != NULL) {
			if(carregada->categoria == funcao) {
				procedimento_atual = carregada;
			}
		}
		else {
			if(destino->categoria == funcao) {
				procedimento_atual = destino;
			}
		}
		geraCodigo(NULL, "AMEM 1");

	}
	lista_expressoes FECHA_PARENTESES
	{
		entra_procedimento = 0;
		num_params_chamada = 0;
		char chamaProcedure[100];
		sprintf(chamaProcedure, "CHPR %s, %d", procedimento_atual->rotulo, nivel_lexico);
		geraCodigo(NULL, chamaProcedure);
	}
	| numero
	| ABRE_PARENTESES expressao FECHA_PARENTESES
;

atribuicao_procedimento:
	atribuicao
	| chama_procedimento
;

atribuicao_funcao:
	atribuicao | chama_funcao
;

atribuicao:
	ATRIBUICAO expressao
	{
      printf("entrou em comando_atribuicao\n");

		verifica_tipo(&tabelaTipo, "atribuicao");
		char varLexDisp[100];
		if (destino->passagem == VALOR)

		{
			printf("entrou em VALOR\n");
				sprintf(varLexDisp, "ARMZ %d, %d", destino->nivel_lexico, destino->deslocamento);}
		else
		{
			printf("entrou em REFERENCIA\n");
				sprintf(varLexDisp, "ARMI %d, %d", destino->nivel_lexico, destino->deslocamento);}
		geraCodigo(NULL, varLexDisp);
		destino = NULL;
	}
;

variavel:
   	IDENT {
		if(destino == NULL) {
         printf("Variavel nao declarada: %s\n", token);

			destino = busca_pilha_simbolos(&tabelaSimbolos, token);
         printf("destino->torulo: %s\n", destino->rotulo) ;

			if(destino == NULL) {
				printf("Variavel %s nao encontrada.\n", token);
				exit(1);
			}
			printf("foi no tipo 1\n");
			push_pilha_tipo(&tabelaTipo, destino->tipo);
		}
		else {
			printf("variavel carregada desse aqui: %s\n", token);
			carregada = busca_pilha_simbolos(&tabelaSimbolos, token);
			if(carregada == NULL) {
				printf("Variavel %s nao encontrada.\n", token);
				exit(1);
			}

			push_pilha_tipo(&tabelaTipo, carregada->tipo);
		}
   	}
;

numero:
	NUMERO
	{

		push_pilha_tipo(&tabelaTipo, integer);
        char totalVars[100];
		sprintf(totalVars, "CRCT %s", token);
		geraCodigo(NULL, totalVars);
		printf("numero\n");
	}
;

// Comandos sem regra --> leitura e escrita
leitura:
  	READ ABRE_PARENTESES lista_leitura FECHA_PARENTESES
;

lista_leitura:
   	lista_leitura VIRGULA simbolo_leitura
   	| simbolo_leitura
;

simbolo_leitura:
	IDENT
	{
		// Codigo leitura
		geraCodigo(NULL, "LEIT");

		// Procura por variavel na tabela de simbolos
		destino = busca_pilha_simbolos(&tabelaSimbolos, token);
		if(destino == NULL) {
			printf("Variavel nao encontrada.\n");
			exit(1);
		}

		// Armazena na variavel destino
    char varLexDisp[1000];
		sprintf(varLexDisp, "ARMZ %d, %d ", destino->nivel_lexico, destino->deslocamento);
		geraCodigo(NULL, varLexDisp);
		destino = NULL;
	}
;

escrita:
   	WRITE ABRE_PARENTESES lista_escrita FECHA_PARENTESES
;

lista_escrita:
	lista_escrita VIRGULA expressao { geraCodigo (NULL, "IMPR"); }
	| expressao { geraCodigo (NULL, "IMPR"); }
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
   cria_pilha(&tabelaSimbolos);
   cria_pilha_tipo(&tabelaTipo);
   cria_pilha_rotulo(&pilha_rotulos);
   cria_pilha_no(&tabelaNode);

   funcao_atual = malloc(100);
   por_ref = 0;
   yyin=fp;
   yyparse();

   return 0;
}
