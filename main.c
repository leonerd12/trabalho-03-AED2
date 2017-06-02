#include <stdio.h>
#include <stdlib.h>
#include "tad-aluno.h"
#include "tad-arvore.h"
#include "tad-vetor.h"


int main(){
    //variáveis
    FILE *fp;
    Aluno aux, *res;
    Arvore* arv = NULL;

    int matriculas[100];
    float coeficientes[100];

    //abrir arquivo
    fp = fopen("arq", "w+");

    gerarMatriculas(matriculas, 100);
    embaralharVetorInt(matriculas, 100);

  	gerarCoeficientes(coeficientes, 100);
  	embaralharVetorFloat(coeficientes, 100);

    //inserir os registros no arquivo
    for(int i = 0; i < 100; i++){
        aux.matricula = matriculas[i];
        aux.coeficiente = coeficientes[i];
        //Wildes fez essa parte
        fwrite(&aux, sizeof(Aluno), 1, fp);
    }

    //mostrar os registros
    // mostrarAlunos(fp);

    //busca um registro no arquivo
    // res = buscaReg(fp, 144);
    // if(res != NULL){
    //     printf("(%.2f)\n", res->coef);
    // }else{
    //     printf("Aluno não encontrado.\n");
    // }

    //inserir os registros na árvore
    fseek(fp, 0, SEEK_SET);
    while(fread(&aux, sizeof(Aluno), 1, fp)){
        insereArvore(&arv, aux.matricula, (ftell(fp)/sizeof(Aluno)) - 1);
    }

    //mostrar os registros na árvore
    // printf("caminhar na arvore\n");
    arvoreCentral(arv);
    // printf("%d\n", arv->chave);

    //fechar o arquivo
    fclose(fp);
    return 0;
}
