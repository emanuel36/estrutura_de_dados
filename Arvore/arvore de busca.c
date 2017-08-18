#include <stdio.h>
#include <stdlib.h>

typedef struct no No;
typedef struct arvore Arvore;

struct no{
	int inf;
	No* esq;
	No* dir;
};

struct arvore{
	No* raiz;
};

void insert(Arvore* arv, int n){
	No* novo = (No*) malloc(sizeof(No));
	novo->inf = n;
	novo->esq = NULL;
	novo->dir = NULL;
	if(arv->raiz == NULL){
		arv->raiz = novo;
	}else{
		No* atual = arv->raiz;
		No* ant = NULL;
		//procurar folha
		while(atual != NULL){
			ant = atual;
			if(n == atual->inf){
				free(novo);
				printf("\nNumero já existente na arvore\n");
				return;
			}
			else if(n > atual->inf){
				atual = atual->dir;
			}
			else{
				atual = atual->esq;
			}
		}
		//inserir na folha
		if(n > ant->inf){
			ant->dir = novo;
		}
		else{
			ant->esq = novo;
		}
	}
	printf("\nNumero Inserido\n");
}

int search(Arvore* arv, int n){
	No* p = arv->raiz;
	while(p != NULL){
		if(n == p->inf){
			return 1; //Achou
		}
		else if(n > p->inf){
			p = p->dir;
		}
		else{
			p = p->esq;
		}
	}
	return 0; //Não achou
}

No* remove_elemento(No* no){
	//No com um filho e No folha
	if(no->esq == NULL){
		No* temp = no->dir;
		free(no);
		return temp;
	}

	//No com 2 filhos
	No* temp1 = no;
	No* temp2 = no->esq;
	while(temp2->dir != NULL){
		temp1 = temp2;
		temp2 = temp2->dir;
	}
	if(temp1 != no){
		temp1->dir = temp2->esq;
		temp2->esq = no->esq;
	}
	temp2->dir = no->dir;
	free(no);
	return temp2;
}

int delete(Arvore* arv, int n){
	No* atual = arv->raiz;
	No* ant = NULL;
	while(atual != NULL){
		if(n == atual->inf){
			if(atual == arv->raiz){
				arv->raiz = remove_elemento(atual);
			}
			else if(atual == ant->dir){
				ant->dir = remove_elemento(atual);
			}
			else{
				ant->esq = remove_elemento(atual);
			}
		}
		ant = atual;
		if(n > atual->inf){
			atual = atual->dir;
		}
		else{
			atual = atual->esq;
		}
	}
	printf("\nNúmero deletado!\n");
}

int main(){
	Arvore* arv;
	arv->raiz = NULL;
	int n, caso = -1;

	while(caso != 0){
		printf("\n1- Insert; \n2- Search; \n3- Delete; \n0- Sair; \nOpção: ");
		scanf("%d", &caso);
		switch(caso){
			case 0:
			break; 

			case 1:
			scanf("%d", &n);
			insert(arv, n);
			break;

			case 2:
			scanf("%d", &n);
			if(search(arv, n) == 1){
				printf("\nNumero na árvore.\n");
			}
			else{
				printf("\nNumero não localizado.\n");
			}
			break;

			case 3:
			scanf("%d", &n);
			delete(arv, n);
			break;
		}
	}
}