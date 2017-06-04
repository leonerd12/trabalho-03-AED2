#include <stdio.h>
#include <stdlib.h>
#include "tad-aluno.h"
#include "tad-vetor.h"

int main(){
    FILE *arquivo;
    Aluno aluno;
    int matriculas[N_REGISTROS];
    float coeficientes[N_REGISTROS];

    // Abrir arquivo para escrita
    arquivo = fopen("registros", "wb+");

    // Gera matrículas e as embaralha.
    gerarMatriculas(matriculas, N_REGISTROS);
    embaralharVetorInt(matriculas, N_REGISTROS);

    // Gera coeficientes e os embaralha.
  	gerarCoeficientes(coeficientes, N_REGISTROS);
  	embaralharVetorFloat(coeficientes, N_REGISTROS);

    // Atribui matrículas e coeficientes à alunos e os insere no arquivo.
    for (int i = 0; i < N_REGISTROS; i++) {
        aluno.matricula = matriculas[i];
        aluno.coeficiente = coeficientes[i];
        fwrite(&aluno, sizeof(Aluno), 1, arquivo);
    }

    printf(">> Um arquivo foi gerado com %d registros.\n", N_REGISTROS);

    // Fechar o arquivo.
    fclose(arquivo);
    return 0;
}
