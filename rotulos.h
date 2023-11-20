#ifndef __ROTULOS_H__
#define __ROTULOS_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tipo_rotulo
{
	char *nome_rotulo;
	struct tipo_rotulo *prox;
} tipo_rotulo;

typedef struct pilha_rotulo
{
	int tamanho;
	tipo_rotulo *topo;
} pilha_rotulo;

/*Operações padroẽs de pilha*/
void cria_pilha_rotulo(pilha_rotulo *pilha_rotulo);
void push_tabela_rotulos(pilha_rotulo *pilha, char *rotulo);
void pop_tabela_rotulos(pilha_rotulo *pilha, int tam_remover);

/*Cria rotulo, recebe o numero em que esta o rotulo atual e cria ele*/
char *cria_rotulo(int rotulo_atual);
char *pega_rotulo_atual(pilha_rotulo *pilha);
char *pega_rotulo(pilha_rotulo *pilha, int n);

#endif
