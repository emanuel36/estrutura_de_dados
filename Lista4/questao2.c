#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;
typedef struct pilha Pilha;

struct pilha{
	Lista* topo;
};

struct lista{
	int n;
	Lista* next;
};

Pilha   *initPilha(){
    printf("creating pilha...");
    Pilha *p =  (Pilha *) malloc(sizeof(Pilha));
    p->topo = NULL;
    printf("OK\n");

    return (p);
}

void push(Pilha* p, int n){
	Lista* new_lista = (Lista*)malloc(sizeof(Lista));
	new_lista->n = n;
	new_lista->next = p->topo;
	p->topo = new_lista;
	printf("NUMERO ADICIONADO\n");
}

void pop(Pilha* p){
	if(p->topo == NULL){
		printf("LISTA VAZIA\n");
	}else{
		printf("NUMERO: %d", p->topo->n);
		Lista* aux = p->topo;
		p->topo = aux->next;
		free(aux);
	}
}

void copiaPilha(Pilha* p, Pilha* copia){
	Lista* pPilha = p->topo;
	while(pPilha != NULL){
		push(copia, pPilha->n);
		pPilha = pPilha->next;
	}
}

int main(){
	Pilha* pilha;	
	Pilha* copia;	
	int n, op = -1;

    pilha = initPilha();
    copia = initPilha();

	while(op != 0){
		printf("\n1- PUSH NA ORIGINAL;\n");
		printf("2- POP NA COPIA\n");
		printf("3- COPIA\n");

		printf("OPCAO: ");
		scanf("%d", &op);

		switch(op){
			case 1:
			printf("NUMERO: ");
			scanf("%d", &n);
			push(pilha, n);		
			break;

			case 2:
			pop(copia);
			break;

			case 3:
			copiaPilha(pilha, copia);
			break;
		}
	}
}
