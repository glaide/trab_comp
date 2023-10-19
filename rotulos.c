#include "rotulos.h"

void cria_pilha_rotulo(pilha_rotulo *pilha_rotulo)
{
    pilha_rotulo->tamanho = 0; // Inicializa o tamanho da pilha como 0
    pilha_rotulo->topo = NULL; // Inicializa o vetor de ponteiros como NULL (sem elementos ainda)
}

void push_tabela_rotulos(pilha_rotulo *pilha, tipo_rotulo *rotulo)
{
    rotulo->prox = pilha->topo;
    pilha->topo = rotulo;
    pilha->tamanho++;
}
