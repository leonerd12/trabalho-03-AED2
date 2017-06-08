#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tad-aluno.h"
#include "tad-arvore.h"
#include "tad-hash.h"

void buscaIntervalo(int inicio, int fim, int opcao_sinal){
    clock_t start;
    double tempo = 0;
    for(int i = inicio; i < fim; i++){
        start = clock();
        buscaIntervalo();
        tempo = (clock() - start) / (double) CLOCKS_PER_SEC;
        tempoSoma += tempo;
    }
    return tempoSoma;
}

int main(){
    FILE *arquivo;
    Aluno aluno, *alunoPonteiro;
    Arvore *arvoreMatricula, *arvoreResposta;
    ArvoreFloat *arvoreCoeficiente, *arvoreCoeficienteResposta;
    Hash *tabelaHash[N_REGISTROS];
    int matriculasBusca[30];
    float coeficientesBusca[30];
    double tempoMatriculas = 0;
    double mediaMatriculasArquivo = 0;
    double mediaMatriculasArvore = 0;
    double mediaMatriculasHash = 0;
    double tempoCoeficientes = 0, mediaCoeficientes = 0; // sumir com esses caras tbm
    int i, posicaoArquivo;
    clock_t start;

    // Abrir arquivo p/ leitura
    arquivo = fopen("registros", "rb");

    // Inicializa as estruturas de dados
    arvoreMatricula = NULL;
    arvoreCoeficiente = NULL;
    inicializaTabelaHash(tabelaHash, N_REGISTROS);

    // Instancia a árvore de Matrículas, a arvore de Coeficientes e a Tabela Hash
    // Alem das chaves, salva a posicao dos registros nas estruturas.
    while (fread(&aluno, sizeof(Aluno), 1, arquivo)) {
        posicaoArquivo = ftell(arquivo) /sizeof(Aluno) - 1;
        insereArvore(&arvoreMatricula, aluno.matricula, posicaoArquivo);
        insereArvoreFloat(&arvoreCoeficiente, aluno.coeficiente, posicaoArquivo);
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
            printf(">> Dados:\nMatricula: %d\nNome: %s\nCoeficiente: %.2f\n\n",
               alunoPonteiro->matricula, alunoPonteiro->nome, alunoPonteiro->coeficiente);
        }

        else {
            printf(">> Não foi encontrado nenhum aluno de matrícula %d.\n", matriculasBusca[i]);
            printf(">> Tempo: %.10lf\n\n", tempoMatriculas);
        }

        // BUSCA NA ARVORE
        printf(">> Busca na Árvore de Matrículas\n");
        start = clock();
        arvoreResposta = buscaArvore(arvoreMatricula, matriculasBusca[i]); // Atualizar buscaArv p buscaArvore
        if (arvoreResposta != NULL) {
            aluno = buscaNoArquivoPorPosicao(arquivo, arvoreResposta->posicaoArquivo);
            tempoMatriculas = (clock() - start) / (double) CLOCKS_PER_SEC;
            mediaMatriculasArvore += tempoMatriculas;
            printf(">> Encontrei a chave %d em %.10lf segundos\n", matriculasBusca[i], tempoMatriculas);
            printf(">> Dados:\nMatricula: %d\nNome: %s\nCoeficiente: %.2f\n\n",
                aluno.matricula, aluno.nome, aluno.coeficiente);
        }
        else {
            tempoMatriculas = (clock() - start) / (double) CLOCKS_PER_SEC;
            mediaMatriculasArvore += tempoMatriculas;
            printf(">> Não foi encontrado nenhum aluno de matrícula %d.\n", matriculasBusca[i]);
            printf(">> Tempo: %.10lf\n\n", tempoMatriculas);
        }

        // BUSCA NA TABELA HASH
        printf(">> Busca na Tabela Hash de Matriculas\n");
        start = clock();
        posicaoArquivo = buscaHash(matriculasBusca[i], tabelaHash, N_REGISTROS);
        if (posicaoArquivo >= 0) {
            aluno = buscaNoArquivoPorPosicao(arquivo, posicaoArquivo);
            tempoMatriculas = (clock() - start) / (double) CLOCKS_PER_SEC;
            mediaMatriculasHash += tempoMatriculas;
            printf(">> Encontrei a chave %d em %.10lf segundos\n", matriculasBusca[i], tempoMatriculas);
            printf(">> Dados:\nMatricula: %d\nNome: %s\nCoeficiente: %.2f\n\n",
                aluno.matricula, aluno.nome, aluno.coeficiente);
        }
        else {
            tempoMatriculas = (clock() - start) / (double) CLOCKS_PER_SEC;
            mediaMatriculasHash += tempoMatriculas;
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

    // Buscas com intervalos
    double tempoDeIntervalos = 0;
    double tempoMenor, tempoMenorQue, tempoMaiorQue, tempoMaior, mediaIntervalos;

    tempoMenor = buscaIntervalo(0,8,1);
    tempoMenorQue = buscaIntervalo(8,16,2);
    tempoMaiorQue = buscaIntervalo(16,23,3);
    tempoMaior = buscaIntervalo(23,30,4);

    tempoDeIntervalos = tempoMenor + tempoMenorQue + tempoMaiorQue + tempoMaior;

    mediaIntervalos = (double) tempoDeIntervalos / 30;
    // //fechar o arquivo
    fclose(arquivo);

    return 0;
}
