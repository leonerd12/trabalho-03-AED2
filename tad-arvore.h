#ifndef TADARVORE_H
#define TADARVORE_H

typedef struct arvore {
	int chave;
	int posicaoArquivo;
	struct arvore* esq;
	struct arvore* dir;
} Arvore;

typedef struct arvoreFloat {
	float chave;
	int posicaoArquivo;
	struct arvoreFloat* esq;
	struct arvoreFloat* dir;
} ArvoreFloat;

Arvore* init();
void insereArvore(Arvore** arv, int chave, int indiceArq);
void insereArvoreFloat(ArvoreFloat** arv, float chave, int indiceArq);
void arvorePreFixada(Arvore* arv);
void arvoreCentral(Arvore* arv);
void arvoreCentralCo(ArvoreFloat* arv);
void arvorePosFixada(Arvore* arv);
Arvore* buscaArvore(Arvore* arv, int chave);
ArvoreFloat* buscaArvoreFloat(ArvoreFloat* raiz, float chave);

#endif
