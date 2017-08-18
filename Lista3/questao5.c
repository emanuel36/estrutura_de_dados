#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista Lista;

struct lista{
	char n[10];
	Lista* next;
};

Lista* insert(Lista* l, char *n){
	Lista* new_list = (Lista*)malloc(sizeof(Lista));
	strcpy(new_list->n, n);
	new_list->next = l;
	return new_list;
}

int iguais(Lista *l1, Lista *l2){
	Lista* pList1 = l1;
	Lista* pList2 = l2;
	while(pList1 != NULL && pList2 != NULL){
		if(strcmp(pList1->n, pList2->n) != 0){
			return 0;
		}
		pList1 = pList1->next;
		pList2 = pList2->next;
	}
	return 1;
}

int main(){
	Lista* lista1 = NULL;
	Lista* lista2 = NULL;
	char n[10];
	
	insert(lista1, "emanuel");
	insert(lista1, "angelim");
	insert(lista2, "emanuel");
	insert(lista2, "angelim");

	printf("%s", lista1->n);

	//printf("%d", iguais(lista1, lista2));
}