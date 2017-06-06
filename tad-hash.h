#ifndef TADHASH_H
#define TADHASH_H

typedef struct Hash {
    int chave;
    int posicaoArquivo;
    struct Hash *prox;
} Hash;

void inicializaTabelaHash(Hash *tabelaHash[], int tamanho);

int funcaoHash(int chave, int tamanho);

void insereHash(int chave, int posicaoArquivo, Hash *tabelaHash[], int tamanho);

int buscaHash(int chave, Hash *tabelaHash[], int tamanho);

void imprimeTabelaHash(Hash *tabelaHash[], int tamanho);

#endif
