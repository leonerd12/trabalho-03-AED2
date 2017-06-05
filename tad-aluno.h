#ifndef ARQUIVO_H
#define ARQUIVO_H
#define N_REGISTROS 1000

typedef struct Aluno {
    int matricula;
    float coeficiente;
} Aluno;

Aluno insereReg(Aluno reg, Aluno aux);

void mostrarAlunos(FILE *fp);

Aluno* buscaReg(FILE *fp, int chave);

void gerarMatriculas(int vet[], int tam);

float gerarCoeficiente();

void geraMatriculasBusca(int vet[], int tam);

#endif
