#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "tad-aluno.h"
#include "tad-vetor.h"

Aluno insereReg(Aluno reg, Aluno aux){
    reg.matricula = aux.matricula;
    // strcpy(reg.nome, aux.nome);
    reg.coeficiente = aux.coeficiente;
    // strcpy(reg.dataNascimento, aux.dataNascimento);
    // strcpy(reg.dataMatricula, aux.dataMatricula);
    // reg.periodo = aux.periodo;
    return reg;
}

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
    fseek(fp, 0,SEEK_END);
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
