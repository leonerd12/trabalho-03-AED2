#ifndef ARQUIVO_H
#define ARQUIVO_H

typedef struct{
    int chave;
    char nome[50];
    float preco;
    char vendedor[30];
    char dataVenda[10];
}Registro;

Registro insereReg(Registro reg, int chave, char nome[50], float preco, char vendedor[30], char dataVenda[10]);

void mostrarRegistros(FILE *fp);

Registro buscaReg(FILE *fp, int chave);

#endif
