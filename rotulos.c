#include "rotulos.h"

void cria_pilha_rotulo(pilha_rotulo *pilha_rotulo)
{
    pilha_rotulo->tamanho = 0; // Inicializa o tamanho da pilha como 0
    pilha_rotulo->topo = NULL; // Inicializa o vetor de ponteiros como NULL (sem elementos ainda)
}

void push_tabela_rotulos(pilha_rotulo *pilha, char *rotulo)
{

    // cria um novo rotulo
    tipo_rotulo *novo_rotulo = (tipo_rotulo *)malloc(sizeof(tipo_rotulo));
    novo_rotulo->nome_rotulo = (char *)malloc(strlen(rotulo) * sizeof(char));
    strcpy(novo_rotulo->nome_rotulo, rotulo);
    // insere o novo rotulo no topo da pilha
    novo_rotulo->prox = pilha->topo;
    pilha->topo = novo_rotulo;
    // incrementa o tamanho da pilha
    pilha->tamanho++;
}

void pop_tabela_rotulos(pilha_rotulo *pilha, int tam_remover)
{
    if (pilha->tamanho == 0)
    {
        printf("Pilha de rotulos vazia\n");
        exit(1);
    }
    tipo_rotulo *aux = pilha->topo;
    int i = 0;
    while (i < tam_remover)
    {
        aux = pilha->topo;
        pilha->topo = aux->prox;
        free(aux);
        pilha->tamanho--;
        i++;
    }
}

char *cria_rotulo(int rotulo_atual)
{
    char *rotulo = (char *)malloc(5 * sizeof(char));
    sprintf(rotulo, "R%02d", rotulo_atual);
    return rotulo;
}

char *pega_rotulo(pilha_rotulo *pilha, int n)
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
