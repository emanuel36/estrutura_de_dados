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

void push(Pilha* p, int n){
	Lista* new_pilha = (Lista*)malloc(sizeof(Lista));

	new_pilha->n = n;
	new_pilha->next = p->topo;
	p->topo = new_pilha;
	printf("NUMERO ADICIONADO");
}

void pop(Pilha *p){
	if(p->topo == NULL){
		printf("Lista Vazia!");
	}else{
		Lista* l = p->topo;
		printf("NUMERO: %d", l->n);
		p->topo = l->next;
		free(l);
	}
}

int main(){
	Pilha* pilha;	pilha->topo = NULL;
	int n, op = -1;

	while(op != 0){
		printf("\n1- PUSH;\n");
		printf("2- POP\n");

		printf("OPCAO: ");
		scanf("%d", &op);

		switch(op){
			case 1:
			printf("NUMERO: ");
			scanf("%d", &n);
			push(pilha, n);		
			break;

			case 2:
			pop(pilha);
			break;
		}
	}
}