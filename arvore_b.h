#ifndef INSERCAO_ARVORE_B_DISCO_ARVORE_B_H
#define INSERCAO_ARVORE_B_DISCO_ARVORE_B_H

#include <stdio.h>
#include "metadados.h"
#include "lista_nos.h"

#define NOME_ARQUIVO_DADOS "clientes.dat"
#define NOME_ARQUIVO_METADADOS "metadados.dat"
#define D 2

TNo *le_no_pos(FILE *arq, int d, int pt);
void salva_no_pos(FILE *arq, int d, int pt, TNo *no);
int aloca_no(TMetadados *md, int d);
void atualiza_pai(FILE *arq, int d, int ptFilho, int ptPai);
int posicao(int chave, TNo *no);
int busca(FILE *arq, int d, int ptNo, int chave);
void insere_no(FILE *arq, TMetadados *md, int d, int ptNo, TNo *no, int pos, TCliente *cli, int pt);
void particiona(FILE *arq, TMetadados *md, int d, int ptP, TNo *P, int pos, TCliente *cli, int pt);
int insere(int cod_cli, char *nome_cli, char *nome_arquivo_metadados, char *nome_arquivo_dados, int d);

#endif //INSERCAO_ARVORE_B_DISCO_ARVORE_B_H
