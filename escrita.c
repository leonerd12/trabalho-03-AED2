#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tad-aluno.h"
#include "tad-vetor.h"

int main(){
    FILE *arquivo;
    FILE *arquivoNomes;
    FILE *arquivoCursos;
    Aluno aluno;
    int matriculas[N_REGISTROS];
    int qtdNomes, qtdCursos;
    char nome[30], curso[30];
    char nomes[10000][30], cursos[100][30];

    // Abrir arquivos
    arquivo = fopen("registros", "wb+");
    arquivoNomes = fopen("nomes.txt", "r+");
    arquivoCursos = fopen("cursos.txt", "r+");

    qtdNomes = 0;
    while(fscanf(arquivoNomes, "%s", nome) != EOF) {
        strcpy(nomes[qtdNomes], nome);
        qtdNomes++;
    }

    qtdCursos = 0;
    while(fscanf(arquivoCursos, "%s", curso) != EOF) {
        strcpy(cursos[qtdCursos], curso);
        qtdCursos++;
    }

    // Gera matrículas e as embaralha.
    gerarMatriculas(matriculas, N_REGISTROS);
    embaralharVetor(matriculas, N_REGISTROS);

    // Atribui matrículas e coeficientes à alunos e os insere no arquivo.
    for (int i = 0; i < N_REGISTROS; i++) {
        aluno.matricula = matriculas[i];
        strcpy(aluno.nome, sorteiaString(nomes, qtdNomes));
        aluno.idade = rand() % (30 - 16) + 16;
        strcpy(aluno.curso, sorteiaString(cursos, qtdCursos));
        aluno.coeficiente = gerarCoeficiente();
        fwrite(&aluno, sizeof(Aluno), 1, arquivo);
    }

    printf(">> Um arquivo foi gerado com %d registros.\n", N_REGISTROS);

    // Fechar o arquivo.
    fclose(arquivo);
    return 0;
}
