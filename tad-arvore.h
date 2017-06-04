#ifndef TADARVORE_H
#define TADARVORE_H

typedef struct arvore {
	int chave;
	int ind_vet;
	struct arvore* esq;
	struct arvore* dir;
} Arvore;

Arvore* init();
void insereArvore(Arvore** arv, int chave, int indiceArq);
void arvorePreFixada(Arvore* arv);
void arvoreCentral(Arvore* arv);
void arvorePosFixada(Arvore* arv);
Arvore* buscaArv(Arvore* arv, int chave);

#endif
