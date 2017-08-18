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

void print(Lista *l){
	Lista* printL = l;

	if(printL == NULL){
		printf("\n\n---FIM DA LISTA---\n");
	}else{
		printf("\nNumero: %d\n", printL->n);

		print(printL->next);
	}
}

Lista* merge(Lista* l1, Lista* l2){
	Lista* pList = l1;
	Lista* anterior;
	
	for(; pList != NULL; pList = pList->next){
		anterior = pList;
	}
	anterior->next = l2;
	printf("LISTAS CONCATENADAS!\n");
	return l1;
}

int main(){
	Lista* lista1 = NULL;
	Lista* lista2 = NULL;
	int num, op = -1;

	while(op != 0){
		printf("\n1- Adicionar na lista 1;\n");
		printf("2- Adicionar na lista 2;\n");
		printf("3- Concatenar Listas;\n");
		printf("4- Imprimir lista 1;\n");

		printf("OPCAO: \n");
		scanf("%d", &op);

		switch(op){

			case 0:
			printf("PROGRAMA ENCERRADO!\n");
			break;

			case 1:
			printf("Numero: \n");
			scanf("%d", &num);

			lista1 = insert(lista1, num);
			break;

			case 2:
			printf("Numero: \n");
			scanf("%d", &num);

			lista2 = insert(lista2, num);
			break;

			case 3:
			merge(lista1, lista2);
			break;

			case 4:
			print(lista1);
		}
	}
}