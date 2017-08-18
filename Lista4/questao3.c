#include <stdio.h>
#include <stdlib.h>

typedef struct fila Fila;

struct fila{
	int* vetor;
	int capacidade;
	int inicio;
	int fim;
	int tamanho;
};

void criaFila(Fila* f, int capacidade){
	f->capacidade = capacidade;
	f->vetor = (int*)malloc(f->capacidade*sizeof(int));
	f->inicio = 0;
	f->fim = -1;
	f->tamanho = 0;
}

void push(Fila* f, int n){
	if(f->tamanho == f->capacidade){
		printf("FILA CHEIA!");
	}else{
		f->fim++;
		f->vetor[f->fim] = n;
		f->tamanho++;
		printf("NUMERO ADICIONADO!");
	}
}

void pop(Fila* f){
	if(f->tamanho == 0){
		printf("FILA VAZIA!");
	}else{
		printf("NUMERO: %d", f->vetor[f->inicio]);
		f->inicio++;
		f->tamanho--;
	}
}

int main(){
	Fila fila;
	int n, op, capacidade;

	printf("CAPACIDADE DA FILA: ");
	scanf("%d", &capacidade);
	criaFila(&fila, capacidade);

	while(1){
		printf("\n1- PUSH;\n2- POP\n OPCAO: ");
		scanf("%d", &op);

		switch(op){
			case 1:
			printf("NUMERO: ");
			scanf("%d", &n);
			push(&fila, n);
			break;

			case 2:
			pop(&fila);
		}
	}
}