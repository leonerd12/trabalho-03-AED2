#include <stdio.h>
#include <stdlib.h>
#include "tad-arvore.h"
#include "tad-aluno.h" // tem que tirar isso daqui

Arvore* init() {
	return NULL;
}

void insereArvore(Arvore** arv, int chave, int indiceArq) {
	if (*arv == NULL) {
		*arv = (Arvore*) malloc(sizeof(Arvore));
		(*arv)->esq = NULL;
		(*arv)->dir = NULL;
		(*arv)->chave = chave;
		(*arv)->posicaoArquivo = indiceArq;
	}
	else {
		if (chave <= (*arv)->chave) {
			insereArvore(&(*arv)->esq, chave, indiceArq);
		}
		else {
			insereArvore(&(*arv)->dir, chave, indiceArq);
		}
	}
}

void insereArvoreFloat(ArvoreFloat** arv1, float chave, int indiceArq) {
	if (*arv1 == NULL) {
		*arv1 = (ArvoreFloat*) malloc(sizeof(ArvoreFloat));
		(*arv1)->esq = NULL;
		(*arv1)->dir = NULL;
		(*arv1)->chave = chave;
		(*arv1)->posicaoArquivo = indiceArq;
	}
	else {
		if (chave <= (*arv1)->chave) {
			insereArvoreFloat(&(*arv1)->esq, chave, indiceArq);
		}
		else {
			insereArvoreFloat(&(*arv1)->dir, chave, indiceArq);
		}
	}
}

void arvorePreFixada(Arvore* arv) {
	if (arv != NULL) {
		printf("%d ", arv->chave);
		arvorePreFixada(arv->esq);
		arvorePreFixada(arv->dir);
	}
}

void arvoreCentral(Arvore* arv) {
	if (arv != NULL) {
		arvoreCentral(arv->esq);
		printf("Chave: %d ", arv->chave);
		printf("Posição no arquivo: %d\n", arv->posicaoArquivo);
		arvoreCentral(arv->dir);
	}
}

void arvoreCentralCo(ArvoreFloat* arv) {
	if (arv != NULL) {
		arvoreCentralCo(arv->esq);
		printf("Chave: %f ", arv->chave);
		printf("Posição no arquivo: %d\n", arv->posicaoArquivo);
		arvoreCentralCo(arv->dir);
	}
}

void arvorePosFixada(Arvore* arv) {
	if (arv != NULL) {
		arvorePosFixada(arv->esq);
		arvorePosFixada(arv->dir);
		printf("%d ", arv->chave);
	}
}


Arvore* buscaArvore(Arvore* raiz, int chave){
	if (raiz != NULL) {
		if(raiz->chave == chave){
			return raiz;
		}else if(chave < raiz->chave){
			buscaArvore(raiz->esq, chave);
		}else if(chave > raiz->chave){
			buscaArvore(raiz->dir, chave);
		}
	}

	else {
		return NULL;
	}

}

ArvoreFloat* buscaArvoreFloat(ArvoreFloat* raiz, float chave){
	if (raiz != NULL) {
		if(raiz->chave == chave){
			return raiz;
		}else if(chave < raiz->chave){
			buscaArvoreFloat(raiz->esq, chave);
		}else if(chave > raiz->chave){
			buscaArvoreFloat(raiz->dir, chave);
		}
	}

	else {
		return NULL;
	}

}

//void menoresQue(Ar)
