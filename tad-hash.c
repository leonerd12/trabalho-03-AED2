#include <stdio.h>
#include <stdlib.h>
#include "tad-hash.h"

void inicializaTabelaHash(Hash *tabelaHash[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        tabelaHash[i] = NULL;
    }
}

int funcaoHash(int chave, int tamanho) {
    return chave % tamanho;
}

void insereHash(int chave, int posicaoArquivo, Hash *tabelaHash[], int tamanho) {
    Hash *novoHash;
    int indiceHash = funcaoHash(chave, tamanho);
    if (indiceHash >= 0 && indiceHash < tamanho) {
        novoHash = (Hash*) malloc(sizeof(Hash));
        novoHash->chave = chave;
        novoHash->posicaoArquivo = posicaoArquivo;
        novoHash->prox = tabelaHash[indiceHash];
        tabelaHash[indiceHash] = novoHash;
    } else {
        printf(">> O registro de chave %d não pode ser adicionado à tabela Hash.\n", chave);
    }
}

int buscaHash(int chave, Hash *tabelaHash[], int tamanho) {
    Hash *percorre;
    int indiceHash = funcaoHash(chave, tamanho);
    if (indiceHash >= 0 && indiceHash < tamanho) {
        percorre = tabelaHash[indiceHash];
        while (percorre != NULL) {
            if (percorre->chave == chave) {
                return percorre->posicaoArquivo;
            }
            percorre = percorre->prox;
        }
        printf(">> A chave %d não foi encontrada na tabela Hash.\n", chave);
    } else {
        printf(">> A chave do registro não é contemplada na tabela Hash.\n");
    }
}

void imprimeTabelaHash(Hash *tabelaHash[], int tamanho) {
    Hash *percorre;
    printf(">> Tabela Hash:\n");
    for (int i = 0; i < tamanho; i++) {
        percorre = tabelaHash[i];
        printf("[%d]: ", i);
        while (percorre != NULL) {
            printf("%d ", percorre->chave);
            percorre = percorre->prox;
        }
        printf("\n");
    }
}
