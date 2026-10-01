#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "arvore_b.h"

/*
 * Le o nó que está na posição pt do arquivo de dados
 */
TNo *le_no_pos(FILE *arq, int d, int pt) {
    fseek(arq, pt, SEEK_SET);
    return le_no(d, arq);
}

/*
 * Grava o nó na posição pt do arquivo de dados
 */
void salva_no_pos(FILE *arq, int d, int pt, TNo *no) {
    fseek(arq, pt, SEEK_SET);
    salva_no(d, no, arq);
}

/*
 * Reserva espaço para um novo nó no final do arquivo de dados
 * Retorna a posição reservada e atualiza o ponteiro para o próximo nó livre
 */
int aloca_no(TMetadados *md, int d) {
    int pt = md->pont_prox_no_livre;
    md->pont_prox_no_livre += tamanho_no(d);
    return pt;
}

/*
 * Atualiza o ponteiro para o pai do nó que está na posição ptFilho
 * Se ptFilho for -1 (filho nulo), não faz nada
 */
void atualiza_pai(FILE *arq, int d, int ptFilho, int ptPai) {
    if (ptFilho != -1) {
        TNo *filho = le_no_pos(arq, d, ptFilho);
        filho->pont_pai = ptPai;
        salva_no_pos(arq, d, ptFilho, filho);
        libera_no(d, filho);
    }
}

/*
 * Busca binária da posição em que a chave deveria estar dentro do nó.
 */
int posicao(int chave, TNo *no) {
    int inicio = 0;
    int fim = no->m;
    int pos = (fim + inicio) / 2;
    while (pos != no->m && chave != no->clientes[pos]->cod_cliente && inicio < fim) {
        if (chave > no->clientes[pos]->cod_cliente) {
            inicio = pos + 1;
        } else {
            fim = pos;
        }
        pos = (fim + inicio) / 2;
    }
    return pos;
}

/*
 * Busca retorna a posição (no arquivo de dados) do nó onde a chave está, ou onde ela deveria estar
 * (se chegar numa folha e não encontrar a chave)
 */
int busca(FILE *arq, int d, int ptNo, int chave) {
    TNo *no = le_no_pos(arq, d, ptNo);
    int pos = posicao(chave, no);
    int resultado;
    if (no->p[pos] == -1 || (pos < no->m && chave == no->clientes[pos]->cod_cliente)) {
        resultado = ptNo;
    } else {
        resultado = busca(arq, d, no->p[pos], chave);
    }
    libera_no(d, no);
    return resultado;
}

/*
 * Insere o cliente e o seu repectivo ponteiro da direita (pt) numa posição específica do nó no,
 * que está gravado na posição ptNo do arquivo de dados
 * d é a ordem da arvore
 * Caso a posição não seja informada (-1) o algoritmo busca pela posição correta
 * O nó é gravado no arquivo ao final da inserção. Uma cópia do cliente é armazenada no nó
 */
void insere_no(FILE *arq, TMetadados *md, int d, int ptNo, TNo *no, int pos, TCliente *cli, int pt) {
    //TODO: Implementar essa funcao
}

/*
 * Particiona o nó P (gravado na posição ptP) para adicionar o cliente e o ponteiro pt
 * Após o final da execução dessa função, o cliente terá sido inserido no local correto
 * e um novo nó Q terá sido criado no final do arquivo como resultado do particionamento
 * Uma nova raiz W pode ser criada, se a raiz atual estiver sendo particionada
 */
void particiona(FILE *arq, TMetadados *md, int d, int ptP, TNo *P, int pos, TCliente *cli, int pt) {
    //TODO: Implementar essa funcao
}

/*
 * Insere o cliente numa folha da árvore armazenada em disco
 * d é a ordem da arvore
 * Retorna a posição da raiz da árvore no arquivo de dados após a inserção,
 * ou -1 caso a chave já exista na árvore
 */
int insere(int cod_cli, char *nome_cli, char *nome_arquivo_metadados, char *nome_arquivo_dados, int d) {
    //TODO: Implementar essa funcao
    return INT_MAX;
}

int main () {
    /* Essa função gera a saída que é usada nos testes. Ela NÃO DEVE SER MODIFICADA */

    /* Le do teclado dados a serem inseridos */
    int cod;
    char nome[TAM_NOME] = "";

    scanf("%d", &cod);
    scanf("%s", nome);

    //Chama função a ser testada
    int pont = insere(cod, nome, NOME_ARQUIVO_METADADOS, NOME_ARQUIVO_DADOS, D);

    //Imprime resultado da função
    printf("PONT %d\n", pont);

    //Imprime arquivo de metadados
    printf("ARQUIVO DE METADADOS:\n");
    TMetadados *tabMetadadosSaida = le_arq_metadados(NOME_ARQUIVO_METADADOS);
    imprime_metadados(tabMetadadosSaida);

    //Imprime arquivo de dados
    printf("ARQUIVO DE DADOS:\n");
    TListaNos *tabDadosSaida = le_nos(D, NOME_ARQUIVO_DADOS);
    imprime_nos(D, tabDadosSaida);
}
