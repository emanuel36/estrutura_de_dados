#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;

struct lista{
	int n;
	Lista* next;
};

Lista* insert(Lista* l, int n){
	Lista* new_elemento = (Lista*)malloc(sizeof(Lista));

	new_elemento->n = n;
	new_elemento->next = l;
	printf("ADICIONADO!\n");

	return new_elemento;
}

void buscaMaiores(Lista* l, int num){
	Lista* pList = l;

	for( ; pList != NULL; pList = pList->next){
		if(pList->n > num){
			printf("\nMAIOR: %d", pList->n);
		}
	}
}

int main(){
	Lista* lista = NULL;
	int num, op = -1;

	while(op != 0){
		printf("\n1- Adicionar;\n");
		printf("2- Print maiores;\n");

		printf("OPCAO: \n");
		scanf("%d", &op);

		switch(op){

			case 0:
			printf("PROGRAMA ENCERRADO!\n");
			break;

			case 1:
			printf("Numero: \n");
			scanf("%d", &num);

			lista = insert(lista, num);
			break;

			case 2:
			printf("Numero: \n");
			scanf("%d", &num);

			buscaMaiores(lista, num);
			break;
		}
	}
}