#include "tabelaSimbolos.h"
unsigned int temElse, it_temElse;

void seta_else()
{
    if (!(temElse & (1 << it_temElse)))
    {
        temElse = temElse | (1 << it_temElse);
    }
}

void inicia_else()
{
    if (!(temElse & 1))
    {
        temElse = 1;
        it_temElse = 0;
    }
    it_temElse++;
}

void cria_pilha(pilha_simbolos *tabela_de_simbolos)
{
    tabela_de_simbolos->topo = NULL;
    tabela_de_simbolos->tamanho = 0;
}

void push(pilha_simbolos *tabela_de_simbolos, type_info_tabela_simbolos *novo_simb)
{
    novo_simb->prox = tabela_de_simbolos->topo;
    tabela_de_simbolos->topo = novo_simb;
    tabela_de_simbolos->tamanho++;
}
type_info_tabela_simbolos *pega_topo(pilha_simbolos *tabela_de_simbolos)
{
    if (tabela_de_simbolos->tamanho == 0)
    {
        printf("Pilha vazia!");
        return NULL;
    }
    return tabela_de_simbolos->topo;
}
type_info_tabela_simbolos *pega_posicao(pilha_simbolos *tabela_de_simbolos, int n)
{
    if (tabela_de_simbolos->tamanho == 0)
    {
        printf("Pilha vazia!");
        return NULL;
    }
    type_info_tabela_simbolos *aux = tabela_de_simbolos->topo;

    while (n > 0)
    {
        aux = aux->prox;
        n--;
    }
    return aux;
}
type_info_tabela_simbolos *busca_pilha_simbolos(pilha_simbolos *tabela_de_simbolos, char *identificador)
{
    type_info_tabela_simbolos *aux = tabela_de_simbolos->topo;
    while (aux != NULL)
    {
        if (strcmp(aux->identificador, identificador) == 0)
        {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}

void pop(pilha_simbolos *tabela_de_simbolos, int n)
{
    if (tabela_de_simbolos->tamanho == 0)
    {
        printf("Pilha vazia!");
        exit(1);
    }
    type_info_tabela_simbolos *aux;

    while (n > 0)
    {
        aux = tabela_de_simbolos->topo;
        tabela_de_simbolos->topo = aux->prox;
        free(aux);
        tabela_de_simbolos->tamanho--;
        n--;
    }
}
type_info_tabela_simbolos *cria_variavel_simples(char *identificador, int nivel_lexico, int deslocamento)
{
    type_info_tabela_simbolos *novo_no = (type_info_tabela_simbolos *)malloc(sizeof(type_info_tabela_simbolos));

    novo_no->identificador = (char *)malloc((strlen(identificador) + 1) * sizeof(char));
    strcpy(novo_no->identificador, identificador);

    novo_no->categoria = var_simples;
    novo_no->nivel_lexico = nivel_lexico;
    novo_no->deslocamento = deslocamento;

    novo_no->tipo = desconhecido;

    return novo_no;
}

type_info_tabela_simbolos *cria_variavel_funcao(char *identificador, char *rotulo, int nivel_lexico, int numero_parametros, tipo_pascal tipo_retorno)
{
    type_info_tabela_simbolos *novo_no = (type_info_tabela_simbolos *)malloc(sizeof(type_info_tabela_simbolos));

    novo_no->identificador = (char *)malloc((strlen(identificador) + 1) * sizeof(char));
    strcpy(novo_no->identificador, identificador);

    novo_no->categoria = funcao;
    novo_no->nivel_lexico = nivel_lexico;
    novo_no->deslocamento = -4 - numero_parametros;
    novo_no->numero_parametros = numero_parametros;
    novo_no->tipo = tipo_retorno;
    novo_no->rotulo = (char *)malloc(strlen(rotulo) * sizeof(char));
    strcpy(novo_no->rotulo, rotulo);
    novo_no->params = NULL;
    novo_no->numero_procedimentos = 0;
    novo_no->numero_variaveis = 0;

    return novo_no;
}
type_info_tabela_simbolos *cria_variavel_procedure(char *identificador, char *rotulo, int nivel_lexico, int numero_parametros)
{
    type_info_tabela_simbolos *novo_no = (type_info_tabela_simbolos *)malloc(sizeof(type_info_tabela_simbolos));

    novo_no->identificador = (char *)malloc((strlen(identificador) + 1) * sizeof(char));
    strcpy(novo_no->identificador, identificador);

    novo_no->categoria = procedimento;
    novo_no->nivel_lexico = nivel_lexico;
    novo_no->numero_parametros = numero_parametros;
    novo_no->rotulo = (char *)malloc(strlen(rotulo) * sizeof(char));
    strcpy(novo_no->rotulo, rotulo);
    novo_no->params = NULL;
    novo_no->numero_variaveis = 0;
    novo_no->numero_procedimentos = 0;

    return novo_no;
}
type_info_tabela_simbolos *cria_variavel_formal(char *identificador, int nivel_lexico, int deslocamento, tipo_passagem passagem)
{
    type_info_tabela_simbolos *novo_no = (type_info_tabela_simbolos *)malloc(sizeof(type_info_tabela_simbolos));

    novo_no->identificador = (char *)malloc(strlen(identificador) * sizeof(char));
    strcpy(novo_no->identificador, identificador);

    novo_no->categoria = param_formal;
    novo_no->deslocamento = deslocamento;
    novo_no->nivel_lexico = nivel_lexico;
    novo_no->passagem = passagem;
    novo_no->tipo = desconhecido;

    return novo_no;
}
void seta_tipos(pilha_simbolos *tabela_de_simbolos, tipo_pascal tipo, int n)
{
    if (tabela_de_simbolos->tamanho == 0)
    {
        printf("Pilha vazia!");
        exit(1);
    }
    int i = 0;
    type_info_tabela_simbolos *aux = tabela_de_simbolos->topo;
    while ((i < n) && (aux != NULL))
    {
        aux->tipo = tipo;
        aux = aux->prox;
        i++;
    }
}

void imprime_tabela(pilha_simbolos *tabela_de_simbolos)
{
    type_info_tabela_simbolos *aux = tabela_de_simbolos->topo;
    while (aux != NULL)
    {
        printf("Identificador: %s\n", aux->identificador);
        printf("Nivel Lexico: %d\n", aux->nivel_lexico);
        printf("Deslocamento: %d\n", aux->deslocamento);
        printf("Categoria: %d\n", aux->categoria);
        printf("Tipo: %d\n", aux->tipo);
        printf("Prox: %p\n", aux->prox);
        printf("\n");
        aux = aux->prox;
    }
    printf("\n");
}
void atualiza_num_variaveis(pilha_simbolos *p, int vars, int nivel_lexico)
{
    type_info_tabela_simbolos *aux = p->topo;
    while (aux->nivel_lexico != nivel_lexico)
        aux = aux->prox;
    while (aux->categoria != funcao && aux->categoria != procedimento)
    {
        aux = aux->prox;
    }

    aux->numero_variaveis = vars;
}

void atualiza_parametros(type_info_tabela_simbolos *tab_simb, pilha_simbolos *tabela_de_simbolos, int parametros_total)
{
    if (tabela_de_simbolos->tamanho < parametros_total)
        puts("Pilha não tem elementos o suficiente");
    tab_simb->numero_parametros = parametros_total;
    tab_simb->params = (parametro_nao_conhecido *)malloc(parametros_total * sizeof(parametro_nao_conhecido));
    type_info_tabela_simbolos *aux = tabela_de_simbolos->topo;
    for (int i = 0; i < parametros_total; i++)
    {
        tab_simb->params[i].identificador = (char *)malloc((strlen(aux->identificador) + 1) * sizeof(char));
        strcpy(tab_simb->params[i].identificador, aux->identificador);
        tab_simb->params[i].tipo = aux->tipo;
        tab_simb->params[i].passagem = aux->passagem;
        aux->deslocamento = -4 - i;
        aux = aux->prox;
    }
    if (tab_simb->categoria == funcao)
        aux->deslocamento -= 2;
    aux->numero_parametros = parametros_total;
}

void atualiza_num_procedimentos(pilha_simbolos *p, int nivel_lexico)
{
    type_info_tabela_simbolos *aux = p->topo;
    while (aux->nivel_lexico != nivel_lexico)
        aux = aux->prox;
    while (aux->categoria != funcao && aux->categoria != procedimento)
        aux = aux->prox;
    aux->numero_procedimentos++;
}

void cria_pilha_no(pilha_no *p_no)
{
    p_no->max = 8;
    p_no->p = malloc(sizeof(type_info_tabela_simbolos *) * p_no->max);
    p_no->topo = 0;
}
void push_pilha_no(pilha_no *p_no, type_info_tabela_simbolos *infos)
{
    if (p_no->topo == p_no->max - 1)
    {
        p_no->max *= 2;
        p_no->p = realloc(p_no->p, sizeof(type_info_tabela_simbolos *) * p_no->max);
    }
    p_no->topo++;
    p_no->p[p_no->topo] = infos;
}

void *pop_pilha_no(pilha_no *p_no)
{
    p_no->topo--;
    return (p_no->p[p_no->topo + 1]);
}
