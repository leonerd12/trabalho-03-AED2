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
        // printf("%d %s %.2f\n", aluno.matricula, aluno.nome, aluno.coeficiente);
    }

    //imprimeTabelaHash(tabelaHash, N_REGISTROS);


    int posicao = buscaHash(21092184, tabelaHash, N_REGISTROS);
    int linha = funcaoHash(21092184, N_REGISTROS);
    printf("Linha: %d\n", linha);
    imprimeLinhaHash(tabelaHash, N_REGISTROS, linha);

    Aluno alunox;
    alunox = buscaNoArquivoPorPosicao(arquivo, 8134);
    printf("%d %s %f\n", alunox.matricula, alunox.nome, alunox.coeficiente);

    alunox = buscaNoArquivoPorPosicao(arquivo, 2362);
    printf("%d %s %f\n", alunox.matricula, alunox.nome, alunox.coeficiente);


    // Fechar o arquivo.
    fclose(arquivo);
    return 0;
}
