#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tad-aluno.h"
#include "tad-arvore.h"
#include "tad-hash.h"
#include "tad-vetor.h" // Precisa disso?

int main(){
    FILE *arquivo;
    Aluno aluno;
    Aluno *alunoPonteiro;
    Arvore *arvoreMatricula, *arvoreResposta; // Atualizar o res p/ arvoreResposta
    ArvoreFloat *arvoreCoeficiente, *arvoreCoeficienteResposta; // Atualizar Arvore1 p ArvoreFloat e resco p arvoreCoeficienteResposta
    Hash *tabelaHash[N_REGISTROS];
    int matriculasBusca[30];
    float coeficientesBusca[30];
    double tempoMatriculas = 0, mediaMatriculas = 0;
    double mediaMatriculasArquivo = 0;
    double mediaMatriculasArvore = 0;
    double mediaMatriculasHash = 0;
    double tempoCoeficientes = 0, mediaCoeficientes = 0;
    clock_t start;
    int i, posicaoArquivo;

    // Abrir arquivo p/ leitura
    arquivo = fopen("registros", "rb");

    // Inicializa as estruturas de dados
    arvoreMatricula = NULL;
    arvoreCoeficiente = NULL;
    inicializaTabelaHash(tabelaHash, N_REGISTROS);

    // Instancia a arvore de Matriculas, a arvore de Coeficientes e a Tabela Hash
    // Alem das chaves, salva a posicao dos registros nas estruturas.
    while (fread(&aluno, sizeof(Aluno), 1, arquivo)) {
        posicaoArquivo = ftell(arquivo) /sizeof(Aluno) - 1;
        insereArvore(&arvoreMatricula, aluno.matricula, posicaoArquivo);
        insereArvoreCo(&arvoreCoeficiente, aluno.coeficiente, posicaoArquivo); // mudar Co p COeficiente
        insereHash(aluno.matricula, posicaoArquivo, tabelaHash, N_REGISTROS);
    }


    printf(">> EXPERIMENTO 1 --- COMPARAR BUSCAS POR MATRICULAS\n\n");

    //printf("\n----------------------------------------------------------------------\n");
    int trava;
    //printf("----------------------------------------------------------------------\n");

    // Seleciona 30 chaves de Matricula do arquivo para os testes.
    selecionarChavesArquivo(matriculasBusca, 30, arquivo); // Dar uma atualizada nessa funcao...

    for (i = 0; i < 30; i++) {

        printf(">> Caso de Teste %d\n", i + 1);
        printf(">> Matricula: %d\n\n", matriculasBusca[i]);

        // BUSCA NO ARQUIVO
        printf(">> Busca no Arquivo por Matrícula\n");
        start = clock();

        alunoPonteiro = buscaNoArquivoPorChave(arquivo, matriculasBusca[i]);

        tempoMatriculas = (clock() - start) / (double) CLOCKS_PER_SEC;
        mediaMatriculasArquivo += tempoMatriculas;
        if (alunoPonteiro != NULL) {
            printf(">> Encontrei a chave %d em %.10lf segundos\n", matriculasBusca[i], tempoMatriculas);
            //printf(">> Dados:\nMatricula: %d\nNome: %s\nCoeficiente: %.2f\n\n",
              //  alunoPonteiro->matricula, alunoPonteiro->nome, alunoPonteiro->coeficiente);
            printf(">> COEFICIENTE: %.2f\n", alunoPonteiro->coeficiente);
        }

        else {
            printf(">> Não foi encontrado nenhum aluno de matrícula %d.\n", matriculasBusca[i]);
            printf(">> Tempo: %.10lf\n\n", tempoMatriculas);
        }


        // BUSCA NA ARVORE
        printf(">> Busca na Árvore de Matrículas\n");
        start = clock();

        arvoreResposta = buscaArv(arvoreMatricula, matriculasBusca[i]); // Atualizar buscaArv p buscaArvore
        aluno = buscaNoArquivoPorPosicao(arquivo, arvoreResposta->posicaoArquivo);

        tempoMatriculas = (clock() - start) / (double) CLOCKS_PER_SEC;
        mediaMatriculas += tempoMatriculas;
        if (arvoreResposta != NULL) {
            printf(">> Encontrei a chave %d em %.10lf segundos\n", matriculasBusca[i], tempoMatriculas);
            printf(">> Dados:\nMatricula: %d\nNome: %s\nCoeficiente: %.2f\n\n",
                aluno.matricula, aluno.nome, aluno.coeficiente);
        }

        else {
            printf(">> Não foi encontrado nenhum aluno de matrícula %d.\n", matriculasBusca[i]);
            printf(">> Tempo: %.10lf\n\n", tempoMatriculas);
        }

        // BUSCA NA TABELA HASH
        printf(">> Busca na Tabela Hash de Matriculas\n");
        start = clock();

        posicaoArquivo = buscaHash(matriculasBusca[i], tabelaHash, N_REGISTROS);
        aluno = buscaNoArquivoPorPosicao(arquivo, posicaoArquivo);

        tempoMatriculas = (clock() - start) / (double) CLOCKS_PER_SEC;
        mediaMatriculas += tempoMatriculas;
        if (arvoreResposta != NULL) {
            printf(">> Encontrei a chave %d em %.10lf segundos\n", matriculasBusca[i], tempoMatriculas);
            printf(">> Dados:\nMatricula: %d\nNome: %s\nCoeficiente: %.2f\n\n",
                aluno.matricula, aluno.nome, aluno.coeficiente);
        }

        else {
            printf(">> Não foi encontrado nenhum aluno de matrícula %d.\n", matriculasBusca[i]);
            printf(">> Tempo: %.10lf\n\n", tempoMatriculas);
        }

        scanf("%d", &trava);
    }
/*
    mediaMatriculas = mediaMatriculas/30;

    printf(">> Média do tempo de busca na árvore de Matrículas: %.10lf\n", mediaMatriculas);

    printf("\n----------------------------------------------------------------------\n");
    printf("Busca na Árvore de Coeficientes\n");
    printf("----------------------------------------------------------------------\n");

    selecionarCoeficientesArquivo(coeficientesBusca, 30, arquivo);
    int trava;
    for (i = 0; i < 30; i++) {
        start = clock();
        resco = buscaArvCo(arvoreco, coeficientesBusca[i]);
        olhando = encontra(arquivo, resco->ind_vet);
        tempoMatriculas = (clock() - start) / (double) CLOCKS_PER_SEC;
        mediaMatriculas += tempoMatriculas;
        if (res != NULL) {
            printf(">> Encontrei a chave %.3f em %.10lf segundos\n", coeficientesBusca[i], tempoCoeficientes);
        }

        else {
            printf(">> Não foi encontrado nenhum aluno de coeficiente %.3f.\n", coeficientesBusca[i]);
            printf(">> Tempo: %.10lf\n", tempoCoeficientes);
        }

        scanf("%d",&trava );
    }

    mediaCoeficientes = mediaCoeficientes/30;

    printf(">> Média do tempo de busca na árvore de Coeficientes: %.10lf\n", mediaCoeficientes);

    // // Requisita uma chave de busca (matrícula)
    // int busca;
    // printf(">> Digite uma matrícula para buscar no sistema: ");
    // scanf("%d", &busca);
    //
    // // Resgata o elemento da árvore pela chave de busca
    //
    //
    // // Resgata os dados pela posição da chave no arquivo.
    //
    //*/
    // //fechar o arquivo
    fclose(arquivo);

    return 0;
}
