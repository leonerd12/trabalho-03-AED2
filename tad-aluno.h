#ifndef ARQUIVO_H
#define ARQUIVO_H
#define N_REGISTROS 10000

typedef struct Aluno {
    int matricula;
    char nome[30];
    int idade;
    char curso[30];
    float coeficiente;
} Aluno;


Aluno insereReg(Aluno reg, Aluno aux);

void mostrarAlunos(FILE *fp);

Aluno* buscaReg(FILE *fp, int chave);

void gerarMatriculas(int vet[], int tam);

float gerarCoeficiente();

// void geraMatriculasBusca(int vet[], int tam);

void selecionarChavesArquivo(int chaves[], int n, FILE *arquivo);

char* sorteiaString(char nomes[][30], int qtdNomes);

void selecionarCoeficientesArquivo(float chaves[], int n, FILE *arquivo);

Aluno* encontra(FILE *arquivo, int res);

Aluno* buscaNoArquivoPorChave(FILE *arquivo, int chave);

Aluno buscaNoArquivoPorPosicao(FILE *arquivo, int posicao);

#endif
