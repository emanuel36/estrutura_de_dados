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

int verificaLista(Lista* l){
	if(l == NULL){
		return 1;
	}else{
		return 0;
	}
}

void buscaUltimo(Lista* l){
	Lista* pList = l;
	Lista* anterior;

	if(verificaLista(l) == 1){
		printf("Lista vazia!!!");
		exit(0);
	}

	for(; pList != NULL; pList = pList->next){
		anterior = pList;
	}
	printf("ULTIMO: %d", anterior->n);
}

int main(){
	Lista* lista = NULL;
	int num, op = -1;

	while(op != 0){
		printf("\n1- Adicionar;\n");
		printf("2- Print ultimo;\n");

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
			buscaUltimo(lista);
			break;
		}
	}
}