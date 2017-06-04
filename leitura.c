#include <stdio.h>
#include <stdlib.h>
#include "tad-aluno.h"
#include "tad-vetor.h"

int main(){
    FILE *arquivo;
    Aluno alunos[N_REGISTROS], aluno;
    int contRegistros;

    // Abrir arquivo para leitura
    arquivo = fopen("registros", "rb");

    // Carregando registros no vetor de Alunos
    int i = 0;
    printf(">> Lendo registros do arquivo...\n");
    while (fread(&aluno, sizeof(Aluno), 1, arquivo)) {
        alunos[i] = aluno;
        i++;
    }
    contRegistros = i;
    printf(">> %d registros foram carregados.", contRegistros);

    // Gerar chaves Hash
    int hash, hashs[contRegistros];
    int matriculas[contRegistros];
    for (i = 0; i < contRegistros; i++) {
        matriculas[i] = alunos[i].matricula;
        hash = alunos[i].matricula % 1000;
        // printf("Índice Hash: %d\n", hash);
        hashs[i] = hash;
    }

    // quickSort(matriculas, contRegistros);
    // imprimeVetor(matriculas, contRegistros);
    quickSort(hashs, contRegistros);
    imprimeVetor(hashs, contRegistros);
    // imprimeVetor(hashs, contRegistros);

    // int chave, hash;
    // while (1) {
    //     scanf("%d", &chave);
    //     hash = chave % 1000;
    //     printf("Indice hash: %d\n", hash);
    //     tabelaHash[hash].chave =
    // }

    // imprimirAlunosVetor(alunos, contRegistros);


    // Fechar o arquivo.
    fclose(arquivo);
    return 0;
}
