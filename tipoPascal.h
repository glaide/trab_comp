#ifndef __TIPOPASCAL_H__
#define __TIPOPASCAL_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum tipo_Pascal {
	integer,
	boolean,
    outro
} tipo_Pascal;

typedef struct no_Tipo {
	tipoPascal tipo;
	struct no_Tipo *prox;
} no_Tipo;

typedef struct pilha_Tipo {
	int tamanho;
	no_Tipo *topo;
} pilha_Tipo;


void cria_pilha_Tipo(pilha_Tipo *tabela_tipo);
void push_pilha_Tipo(pilha_Tipo *tabela_tipo, tipo_Pascal tipo,no_Tipo *no_Adicionar );
void verifica_tipo(pilhaTipo *tabela_tipo, char* operation);

tipo_Pascal pop_pilha_Tipo(pilha_Tipo *tabela_tipo);
#endif