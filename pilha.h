#ifndef __PILHA_H__
#define __PILHA_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum tipo_pascal
{
    integer,
    desconhecido
} tipo_pascal;

typedef struct tipo_no
{
    tipo_pascal tipo;
    struct tipo_no *prox;
} tipo_no;

typedef struct tipo_pilha
{
    int tamanho;
    tipo_no *topo;
} tipo_pilha;

typedef struct no_rotulo
{
    char *rot;
    struct no_rotulo *prox;
} no_rotulo;

typedef struct pilha_rotulo
{
    int tamanho;
    no_rotulo *topo;
} pilha_rotulo;

// parte relacionada a pilha de tipos
void cria_pilha_tipo(tipo_pilha *tabela_tipos);

void push_pilha_tipo(tipo_pilha *tabela_tipos, tipo_pascal tipo);

tipo_pascal pop_pilha_tipo(tipo_pilha *tabela_tipos);

char *seta_tipo(tipo_pascal tipo);

void verifica_tipo(tipo_pilha *tabela_tipos, char *operation);

void imprime_tabela_simbolo(tipo_pilha *tabela_tipos);

// parte relacionada a pilha de rotulos
char *cria_rotulo(int rotId);

char *pega_rotulo(pilha_rotulo *pilha_rot, int n);

void cria_pilha_rotulo(pilha_rotulo *pilha_rot);

void pop_pilha_rotulo(pilha_rotulo *pilha_rot, int n);

void push_pilha_rotulo(pilha_rotulo *pilha_rot, char *novo_rotulo);

#endif
