#include <stdio.h>
#include <stdlib.h>

typedef struct fila Fila;
typedef struct lista Lista;

struct fila{
	Lista* inicio;
	Lista* fim;
};

struct lista{
	int n;
	Lista* next;
};

Fila* iniciaFila(){
	Fila* n = (Fila*)malloc(sizeof(Fila));
	n->inicio = NULL;
	n->fim = NULL;
	return n;
}

void push(Fila* f, int n){
	Lista* new_fila = (Lista*)malloc(sizeof(Lista));
	new_fila->n = n;
	new_fila->next = NULL;
	if(f->fim != NULL){
		f->fim->next = new_fila;
		printf("NUMERO ADICIONADO!");
	}else{
		f->inicio = new_fila;
	}
	f->fim = new_fila;
}

void pop(Fila* f){
	if(f->inicio == NULL){
		printf("Fila Vazia!");
	}else{
		Lista* aux = f->inicio;
		printf("NUMERO: %d", aux->n);
		f->inicio = aux->next;
		free(aux);
	}
	if(f->inicio == NULL){
		f->fim = NULL;
	}
}

void separaFilas(Fila* f, Fila* fP, Fila* fI){
	Lista* aux = f->inicio;
	
	while(f->inicio->n != NULL){
		if((aux->n % 2) == 0){
			push(fP, aux->n);
		}else{
			push(fI, aux->n);
		}
		f->inicio = f->inicio->next;
	}
}

int main(){
	Fila* fila;
	Fila* filaP;
	Fila* filaI;
	int op = -1, n;

	fila = iniciaFila();
	filaP = iniciaFila();
	filaI = iniciaFila();

	while(op != 0){
		printf("\n1- PUSH;\n");
		printf("2- SEPARA;\n");
		printf("3- POP PAR;\n");
		printf("4- POP IMPAR;\n");

		printf("\nOPCAO: ");
		scanf("%d", &op);

		switch(op){
			case 1:
			printf("NUMERO: ");
			scanf("%d", &n);
			push(fila, n);
			break;

			case 2:
			separaFilas(fila, filaP, filaI);
			break;

			case 3:
			pop(filaP);
			break;

			case 4:
			pop(filaI);
			break;
		}
	}
}