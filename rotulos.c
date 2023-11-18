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
char *cria_rotulo(int rotulo_atual)
{
    char *rotulo = (char *)malloc(5 * sizeof(char));
    sprintf(rotulo, "R%02d", rotulo_atual);
    return rotulo;
}

char *pega_Rotulo(pilha_rotulo *pilha, int n)
{
    if (pilha->tamanho == 0)
    {
        printf("Pilha de Rotulos vazia!");
        exit(1);
    }
    tipo_rotulo *aux = pilha->topo;
    if (!n)
    {
        n++;
    }
    while (--n)
    {
        aux = aux->prox;
    }
    return aux->nome_rotulo;
}
