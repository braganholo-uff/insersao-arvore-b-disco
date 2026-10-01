#ifndef INSERCAO_ARVORE_B_DISCO_LISTA_CLIENTES_H
#define INSERCAO_ARVORE_B_DISCO_LISTA_CLIENTES_H

#include "cliente.h"

/***
 * ESSE ARQUIVO EH USADO APENAS NOS TESTES AUTOMATIZADOS
 */

typedef struct ListaClientes {
    TCliente **lista;
    int qtd;
} TListaClientes;

void imprime_clientes(TListaClientes *lc);
TListaClientes *cria_clientes(int qtd, ...);
void salva_clientes(char *nome_arquivo, TListaClientes *lc);
TListaClientes *le_clientes(char *nome_arquivo);
void libera_clientes(TListaClientes *lc);

#endif //INSERCAO_ARVORE_B_DISCO_LISTA_CLIENTES_H
