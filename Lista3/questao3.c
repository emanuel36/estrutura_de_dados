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


Lista* buscaNumero(Lista* l, int num){
	Lista* pList = l;
	Lista* anterior = NULL;

	for( ; pList != NULL; pList = pList->next){
		anterior = pList;

		if(pList->n == num){
			printf("\nNumero: %d", pList->n);
		}
		anterior->next = pList->next;
		free(pList);
	}
	return l;
}

int main(){
	Lista* lista = NULL;
	int num, op = -1;

	while(op != 0){
		printf("\n1- Adicionar;\n");
		printf("2- Print maiores;\n");
		printf("3- Imprimir lista\n");

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

			lista = buscaNumero(lista, num);
			break;

			case 3: 
			print(lista);
		}
	}
}