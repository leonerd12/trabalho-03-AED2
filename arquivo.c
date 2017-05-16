#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arquivo.h"

Registro insereReg(Registro reg, int chave, char nome[50], float preco, char vendedor[30], char dataVenda[10]){
    reg.chave = chave;
    strcpy(reg.nome, nome);
    reg.preco = rand() % 307;
    strcpy(reg.vendedor, vendedor);
    strcpy(reg.dataVenda, dataVenda);
    return reg;
}

void mostrarRegistros(FILE *fp){
    Registro aux;
    fseek(fp, 0,SEEK_END);
    int qtd = ftell(fp)/sizeof(Registro);
    fseek(fp, 0, SEEK_SET);
    for(int a = 0; a < qtd; a++){
        fread(&aux, sizeof(Registro), 1, fp);
        printf("Chave: %d\n", aux.chave);
        printf("Nome: %s\n", aux.nome);
        printf("Preço: %f\n", aux.preco);
        printf("Vendedor: %s\n", aux.vendedor);
        printf("Data: %s\n", aux.dataVenda);
        printf("=============================\n");
    }
}

Registro buscaReg(FILE *fp){
    Registro aux;
    fseek(fp, 0,SEEK_END);
    int qtd = ftell(fp)/sizeof(Registro);
    fseek(fp, 0, SEEK_SET);
    int a = 0;
    fread(&aux, sizeof(Registro), 1, fp);
    while(a < qtd && chave != aux.chave){
        fread(&aux, sizeof(Registro), 1, fp);
        a++;
    }
    return aux;
}
