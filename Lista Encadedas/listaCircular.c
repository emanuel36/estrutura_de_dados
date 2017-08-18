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
	if(l == NULL){
		new_list->next = new_list;
	}
	else{
		Lista* ant = NULL;
		Lista* aux = l;
		while(aux != NULL){
			ant = aux;
			aux = aux->next;
		}
		ant->next = new_list;
	}
	return new_list;
}

Lista* imprime(Lista* l){
	printf("%d ", l->n);
	return l->next;
}

int main(){
	Lista* lista = NULL;
	int n, caso = -1;

	while(caso != 0){
		printf("Caso: ");
		scanf("%d", &caso);
		
		switch(caso){
			case 1:
			printf("Insert: ");
			scanf("%d", &n);
			lista = insert(lista, n);
			break;

			case 2:
			lista = imprime(lista);
			break;
		}
	}
}