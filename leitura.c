#include <stdio.h>
#include <stdlib.h>
#include "tad-aluno.h"
#include "tad-vetor.h"
#include "tad-hash.h"

int main(){
    FILE *arquivo;
    Aluno alunos[N_REGISTROS], aluno;
    int contRegistros;
    Hash *tabelaHash[N_REGISTROS];

    // Abrir arquivo para leitura
    arquivo = fopen("registros", "rb");

    // Inicializa a tabela Hash
    inicializaTabelaHash(tabelaHash, N_REGISTROS);

    // Carregando registros no vetor de Alunos
    int i = 0;
    // printf(">> Lendo registros do arquivo...\n");
    while (fread(&aluno, sizeof(Aluno), 1, arquivo)) {
        i = ftell(arquivo) / sizeof(Aluno) - 1;
        insereHash(aluno.matricula, i, tabelaHash, N_REGISTROS);
    }

    imprimeTabelaHash(tabelaHash, N_REGISTROS);


    int posicao = buscaHash(21018495, tabelaHash, N_REGISTROS);
    printf("21018495 na posição %d\n", posicao);


    // Fechar o arquivo.
    fclose(arquivo);
    return 0;
}
