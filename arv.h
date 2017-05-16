#ifndef ARV_H
#define ARV_H

typedef struct arvore {
	int dado;
	struct arvore* esq;
	struct arvore* dir;
} Arvore;

Arvore* init();

#endif
