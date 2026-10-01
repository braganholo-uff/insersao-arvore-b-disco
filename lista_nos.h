#ifndef INSERCAO_ARVORE_B_DISCO_LISTA_NOS_H
#define INSERCAO_ARVORE_B_DISCO_LISTA_NOS_H

#include "no.h"

/***
 * ESSE ARQUIVO EH USADO APENAS NOS TESTES AUTOMATIZADOS
 */

typedef struct ListaNos {
    TNo **lista;
    int qtd;
} TListaNos;

void imprime_nos(int d, TListaNos *lc);
TListaNos *cria_nos(int d, int qtd, ...);
void salva_nos(int d, char *nome_arquivo, TListaNos *lc);
TListaNos *le_nos(int d, char *nome_arquivo);
void libera_nos(int d, TListaNos *lc);

#endif //INSERCAO_ARVORE_B_DISCO_LISTA_NOS_H
