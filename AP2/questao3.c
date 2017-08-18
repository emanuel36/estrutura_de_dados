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

Pilha* iniciaPilha(){
	Pilha* new_pilha = (Pilha*)malloc(sizeof(Pilha));
	new_pilha->topo = NULL;
	return new_pilha;
}

void push(Pilha* p, int n){
	Lista* new_pilha = (Lista*)malloc(sizeof(Lista));

	new_pilha->n = n;
	new_pilha->next = p->topo;
	p->topo = new_pilha;
}

int pop(Pilha *p){
	if(p->topo == NULL){
		//vazia
	}else{
		Lista* l = p->topo;
		int n = l->n;
		p->topo = l->next;
		free(l);
		return n;
	}
}

void printPilha(Pilha* p){
	Pilha* aux = p;
	while(aux->topo != NULL){
		printf("%d ", aux->topo->n);
		aux->topo = aux->topo->next;
	}
}

Pilha* mergePilha(Pilha *p1, Pilha *p2){
 	Pilha* p = iniciaPilha();
 	while(p1->topo != NULL){
 		push(p, pop(p1));
 		push(p, pop(p2));
 	}
 	return p;
}

int main(){
	Pilha* pilha1 = iniciaPilha();
	Pilha* pilha2 = iniciaPilha();
	Pilha* pilha;
	int i, n, tamanho;

	scanf("%d", &tamanho);

	for(i = 0; i < tamanho; i++){
		scanf("%d", &n);
		push(pilha1, n);
	}

	for(i = 0; i < tamanho; i++){
		scanf("%d", &n);
		push(pilha2, n);
	}

	pilha = mergePilha(pilha1, pilha2);
	printPilha(pilha);

	return(0);
}