#include "tabelaSimbolos.h"

// funcao para criar uma nova tabela de simbolos
void *criar_tabela_simbolos(TypeTabelaSimbolosPilha *tabelaSimbolos)
{
    // PRECISA DESSE MALLOC?
    TypeTabelaSimbolosPilha *tabela = (TypeTabelaSimbolosPilha *)malloc(sizeof(TypeTabelaSimbolosPilha));
    tabela->tamanho_pilha = 0; // Inicializa o tamanho da pilha como 0
    tabela->infos = NULL;      // Inicializa o vetor de ponteiros como NULL (sem elementos ainda)

    return tabela;
}
// preenche os valores da varialvel simples e retorna o "No" com as informações, após ele chama a pushPilha
type_infos_tabela_simbolos *criaVariavelSimples(char *identificador, int nivelLexico, int deslocamento)
{
    // aloca espaço para infosVariavel
    type_infos_tabela_simbolos *infosVariavel = (type_infos_tabela_simbolos *)malloc(sizeof(type_infos_tabela_simbolos));

    // aloca espaço para a string Identificador e copia ela para InfosVariavel
    infosVariavel->identificador = (char *)malloc((strlen(identificador) + 1) * sizeof(char));
    strcpy(infosVariavel->identificador, identificador);

    // atribuições normais
    infosVariavel->nivel_lexico = nivelLexico;
    infosVariavel->deslocamento = deslocamento;
    infosVariavel->type = desconhecido;
    infosVariavel->categoria = variavel_simples;
    infosVariavel->prox = NULL;

    return infosVariavel;
}

type_infos_tabela_simbolos *criaVariavelSimplesProcedimento(char *identificador, int nivelLexico, int totalParametros, char *rotulo)
{
    // aloca espaço para infosVariavel
    type_infos_tabela_simbolos *infosVariavel = (type_infos_tabela_simbolos *)malloc(sizeof(type_infos_tabela_simbolos));

    // aloca espaço para a string Identificador e copia ela para InfosVariavel
    infosVariavel->identificador = (char *)malloc((strlen(identificador) + 1) * sizeof(char));
    strcpy(infosVariavel->identificador, identificador);
    infosVariavel->nivel_lexico = nivelLexico;
    infosVariavel->categoria = procedimento;
    infosVariavel->rotulo = (char *)malloc(strlen(rotulo) * sizeof(char));
    strcpy(infosVariavel->rotulo, rotulo);
    infosVariavel->numero_parametros = totalParametros;

    infosVariavel->prox = NULL;
    infosVariavel->numero_funcoes = 0;
    infosVariavel->numero_procedimentos = 0;
    infosVariavel->parametros_formais = NULL;
    infosVariavel->type = desconhecido;
    infosVariavel->deslocamento = 0;

    return infosVariavel;
}
// Push normal, o info->prox recebe o topo e o topo vira o novo "No", aumenta tamanho da pilha
void push_tabela_simbolos(TypeTabelaSimbolosPilha *pilha, type_infos_tabela_simbolos *infos)
{
    infos->prox = pilha->topo;
    pilha->topo = infos;
    pilha->tamanho_pilha++;
    printf("simbolo inserido %s", infos->identificador);
    printf("Tamanho atual da pilha: %d", pilha->tamanho_pilha);
}

void imprime_tabela_simbolos(TypeTabelaSimbolosPilha *pilha)
{
    type_infos_tabela_simbolos *aux = pilha->topo;
    while (aux != NULL)
    {
        printf("Identificador: %s\n", aux->identificador);
        printf("Nivel Lexico: %d\n", aux->nivel_lexico);
        printf("Deslocamento: %d\n", aux->deslocamento);
        printf("Categoria: %d\n", aux->categoria);
        printf("Tipo: %d\n", aux->type);
        printf("Prox: %p\n", aux->prox);
        printf("\n");
        aux = aux->prox;
    }
}
