#include <stdio.h>
#include <stdlib.h>
#include "tad-aluno.h"
#include "tad-arvore.h"
#include "tad-vetor.h"

int main(){
    //variáveis
    FILE *arquivo;
    Aluno aluno;
    Arvore *arvore = NULL, *res;

    arquivo = fopen("registros", "rb");

    // Insere a matrícula (chave) e a posição dos registros na árvore.
    while (fread(&aluno, sizeof(Aluno), 1, arquivo)) {
        insereArvore(&arvore, aluno.matricula, (ftell(arquivo)/sizeof(Aluno)) - 1);
    }

    // arvoreCentral(arvore);

    // Requisita uma chave de busca (matrícula)
    int busca;
    printf(">> Digite uma matrícula para buscar no sistema: ");
    scanf("%d", &busca);

    // Resgata o elemento da árvore pela chave de busca
    res = buscaArv(arvore, busca);

    // Resgata os dados pela posição da chave no arquivo.
    if (res) {
        fseek(arquivo, 0, SEEK_SET);
        fseek(arquivo, res->ind_vet * sizeof(Aluno), SEEK_CUR);
        fread(&aluno, sizeof(Aluno), 1, arquivo);

        printf(">> Matricula do aluno buscado: %d\n", aluno.matricula);
        printf(">> Coeficiente do aluno buscado: %.2f\n", aluno.coeficiente);

    } else {
        printf("Aluno não encontrado.\n");
    }

    //fechar o arquivo
    fclose(arquivo);

    return 0;
}
