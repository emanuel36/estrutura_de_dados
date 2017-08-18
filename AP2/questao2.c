#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;

struct lista{
	int n;
	Lista* next;
};

Lista* insert(Lista* l, int n){
	Lista* new_list = (Lista*)malloc(sizeof(Lista));
	new_list->n = n;
	new_list->next = l;
	return new_list;
}

Lista* listaCres(Lista* l1, Lista* l2){
	Lista* l = NULL;
	int tamanho = 0, i, j;
	//INSERIR NA LISTA l
	while(l1 != NULL){
		l = insert(l, l1->n);
		l = insert(l, l2->n);
		l1 = l1->next;
		l2 = l2->next;
		tamanho++;
	}

	//ORDENAÇÃO
	int aux;
	tamanho *= 2;
	Lista* pList = l;

	for(i = 0; i < tamanho; i++){
		for(j = i + 1; j < tamanho; j++){
			if(pList->n > pList->next->n){
				aux = pList->n;
				pList->n = pList->next->n;
				pList->next->n = aux;
			}
			pList = pList->next;
		}
	}
	//RETORNO DA LISTA ORDENADA
	return l;
}

void printLista(Lista* l){
	Lista* pList = l;
	while(pList != NULL){
		printf("%d ", pList->n);
		pList = pList->next;
	}
}

int main(){
	Lista* lista;
	Lista* lista1 = NULL;
	Lista* lista2 = NULL;
	int i, n, tamanho;

	scanf("%d", &tamanho);

	for(i = 0; i < tamanho; i++){
		scanf("%d", &n);
		lista1 = insert(lista1, n);
	}
	
	for(i = 0; i < tamanho; i++){
		scanf("%d", &n);
		lista2 = insert(lista2, n);
	}

	lista = listaCres(lista1, lista2);

	printLista(lista);
}