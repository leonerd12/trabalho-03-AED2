#include <stdio.h>
#include <stdlib.h>
#include "tad-arvore.h"

Arvore* init() {
	return NULL;
}

void insereArvore(Arvore** arv, int chave, int indiceArq) {
	if (*arv == NULL) {
		*arv = (Arvore*) malloc(sizeof(Arvore));
		(*arv)->esq = NULL;
		(*arv)->dir = NULL;
		(*arv)->chave = chave;
		(*arv)->ind_vet = indiceArq;
	}
	else {
		if (chave < (*arv)->chave) {
			insereArvore(&(*arv)->esq, chave, indiceArq);
		}
		else {
			insereArvore(&(*arv)->dir, chave, indiceArq);
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
		printf("Posição no arquivo: %d\n", arv->ind_vet);
		arvoreCentral(arv->dir);
	}
}

void arvorePosFixada(Arvore* arv) {
	if (arv != NULL) {
		arvorePosFixada(arv->esq);
		arvorePosFixada(arv->dir);
		printf("%d ", arv->chave);
	}
}


Arvore* buscaArv(Arvore* raiz, int chave){
	if (raiz != NULL) {
		if(raiz->chave == chave){
			return raiz;
		}else if(chave < raiz->chave){
			buscaArv(raiz->esq, chave);
		}else if(chave > raiz->chave){
			buscaArv(raiz->dir, chave);
		}
	}

	else {
		return NULL;
	}

}
