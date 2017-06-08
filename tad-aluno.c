#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "tad-aluno.h"
#include "tad-vetor.h"

void mostrarAlunos(FILE *fp){
    Aluno aux;
    fseek(fp, 0,SEEK_END);
    int qtd = ftell(fp)/sizeof(Aluno);
    fseek(fp, 0, SEEK_SET);
    for(int a = 0; a < qtd; a++){
        fread(&aux, sizeof(Aluno), 1, fp);
        printf("Chave: %d\n", aux.matricula);
        // printf("Nome: %s\n", aux.nome);
        printf("Coeficiente: %f\n", aux.coeficiente);
        // printf("Data de Nascimento: %s\n", aux.dataNascimento);
        // printf("Data de Matrícula: %s\n", aux.dataMatricula);
        // printf("Período: %d\n", aux.periodo);
        printf("=============================\n");
    }
}

Aluno* buscaReg(FILE *fp, int mat){
    Aluno* aux;
    fseek(fp, 0, SEEK_END);
    int qtd = ftell(fp)/sizeof(Aluno);
    fseek(fp, 0, SEEK_SET);
    int a = 0;
    while(a < qtd){
        fread(aux, sizeof(Aluno), 1, fp);
        if(mat == aux->matricula){
            return aux;
        }
        a++;
    }
    return NULL;
}

void imprimirAlunosVetor(Aluno alunos[], int tam) {
    Aluno aluno;
    for (int i = 0; i < tam; i++) {
        aluno = alunos[i];
        printf("Matrícula: %d\n", aluno.matricula);
        // printf("Nome: %s\n", aux.nome);
        printf("Coeficiente: %.2f\n", aluno.coeficiente);
        // printf("Data de Nascimento: %s\n", aux.dataNascimento);
        // printf("Data de Matrícula: %s\n", aux.dataMatricula);
        // printf("Período: %d\n", aux.periodo);
        printf("=============================\n");
    }
}

void gerarMatriculas(int vet[], int tam) {
    int aux = 0;
    srand(time(NULL));
	for (int i = 0; i < tam; i++) {
        aux += rand() % 20;
		vet[i] = 21000000 + aux;
	}
}

float gerarCoeficiente() {
    return (rand() % 1000) / 100.0;
}

// void geraMatriculasBusca(int vet[], int tam) {
//     int i, max, min;
//     max = 21009400;
//     min = 21000000;
//
//     srand(time(NULL));
//     for (i = 20; i < tam; i++)
//         vet[i] = rand() % (max - min) + min;
// }

void selecionarChavesArquivo(int chaves[], int n, FILE *arquivo) {
    Aluno aluno;
    int i, posicao;
    int min = 21009400;
    int max = 21010000;
    for (i = 0; i < n / 2; i++) {
        posicao = rand() % N_REGISTROS; // Sorteia posição no intervalo 0 - tam
        fseek(arquivo, 0, SEEK_SET);
        fseek(arquivo, sizeof(Aluno) * posicao, SEEK_SET);
        fread(&aluno, sizeof(Aluno), 1, arquivo);
        chaves[i] = aluno.matricula;
    }
    for (i = i; i < n; i++) {
        chaves[i] = rand() % (max - min) + min;
    }
}

char* sorteiaString(char strings[][30], int qtdStrings) {
    int posicao = rand() % qtdStrings;
    return strings[posicao];
}

void selecionarCoeficientesArquivo(float chaves[], int n, FILE *arquivo) {
    Aluno aluno;
    int i, posicao;
    float min = 0.5;
    float max = 10;
    srand(time(NULL));
    for (i = 0; i < n / 2; i++) {
        posicao = rand() % N_REGISTROS; // Sorteia posição no intervalo 0 - tam
        fseek(arquivo, 0, SEEK_SET);
        fseek(arquivo, sizeof(Aluno) * posicao, SEEK_SET);
        fread(&aluno, sizeof(Aluno), 1, arquivo);
        chaves[i] = aluno.coeficiente;
    }
    for (i = i; i < n; i++) {
        chaves[i] = i;//rand() % (max - min) + min;
    }
}

Aluno* encontra(FILE *arquivo, int res){
    Aluno* aluno;

    if (res) {
        fseek(arquivo, 0, SEEK_SET);
        fseek(arquivo, res * sizeof(Aluno), SEEK_CUR);
        fread(&aluno, sizeof(Aluno), 1, arquivo);
    } else {
        printf("Aluno não encontrado.\n");
    }
    return aluno;
}

Aluno* buscaNoArquivoPorChave(FILE *arquivo, int chave) {
    Aluno aluno;
    Aluno *alunoPonteiro = (Aluno*) malloc(sizeof(Aluno));
    fseek(arquivo, 0, SEEK_SET);
    while (fread(&aluno, sizeof(Aluno), 1, arquivo)) {
        if (aluno.matricula == chave) {
            alunoPonteiro->matricula = aluno.matricula;
            alunoPonteiro->idade = aluno.idade;
            alunoPonteiro->coeficiente = aluno.coeficiente;
            strcpy(alunoPonteiro->nome, aluno.nome);
            strcpy(alunoPonteiro->curso, aluno.curso);

            printf("%d %s %.2f\n", aluno.matricula, aluno.nome, aluno.coeficiente);
            return alunoPonteiro;
        }
    }
    alunoPonteiro = NULL;
    return alunoPonteiro;
}

Aluno buscaNoArquivoPorPosicao(FILE *arquivo, int posicao) {
    Aluno aluno;
    fseek(arquivo, 0, SEEK_SET);
    fseek(arquivo, posicao * sizeof(Aluno), SEEK_CUR);
    fread(&aluno, sizeof(Aluno), 1, arquivo);
    return aluno;
}
