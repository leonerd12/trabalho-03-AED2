#include <stdio.h>
#include <stdlib.h>
#include "tad-aluno.h"
#include "tad-arvore.h"
#include "tad-vetor.h"

int main(){
    //variáveis
    FILE *fp;
    Aluno aux;

    Arvore *arv = NULL, *res;
    // int matriculas[100];
    // float coeficientes[100];
    //

    fp = fopen("arq", "w+");

    // gerarMatriculas(matriculas, 100);
    // embaralharVetorInt(matriculas, 100);
    //
	// gerarCoeficientes(coeficientes, 100);
 // 	embaralharVetorFloat(coeficientes, 100);

    //inserir os registros no arquivo
    for(int i = 0; i < 100; i++){
        // aux.matricula = 21000000 + (rand()%1000000);
        // aux.coeficiente = (float) (rand() % 1000) / 100;
        fwrite(&aux, sizeof(Aluno), 1, fp);
    }

    //inserir os registros na árvore
    fseek(fp, 0, SEEK_SET);
    while(fread(&aux, sizeof(Aluno), 1, fp)){
        insereArvore(&arv, aux.matricula, (ftell(fp)/sizeof(Aluno)) - 1);
    }
    // arvoreCentral(arv);

    int busca;
    printf("Digite uma matrícula para buscar no sistema: ");
    scanf("%d", &busca);


    res = buscaArv(arv, busca);

    //puxar os dados do arquivo
    if(res){
        fseek(fp, 0, SEEK_SET);
        fseek(fp, res->ind_vet*sizeof(Aluno), SEEK_CUR);
        fread(&aux, sizeof(Aluno), 1, fp);

        printf("Matricula do aluno buscado: %d\n", aux.matricula);
        printf("Coeficiente do aluno buscado: %.2f\n", aux.coeficiente);
        //fechar o arquivo
        fclose(fp);
    }else{
        printf("Aluno não encontrado.\n");
    }

    return 0;
}
