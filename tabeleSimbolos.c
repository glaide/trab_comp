#include "tabelaSimbolos.h"

// funcao para criar uma nova tabela de simbolos
type_infos_tabela_simbolos cria_var_simples(char *identificador, int nivel_lexico, int deslocamento){
    type_infos_tabela_simbolos *infos = (type_infos_tabela_simbolos *)malloc(sizeof(type_infos_tabela_simbolos));
    infos->nivel_lexico = nivel_lexico;
    infos->deslocamento = deslocamento;
    infos->identificador = strdup(identificador);
    infos->categoria = variavel_simples;
    infos->type = desconhecido;
    infos->parametros_formais = NULL;
    infos->prox = NULL;
    return *infos;
}
