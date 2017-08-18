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

//Imprime a list
void imprimeLista(Lista* l){
    while(l != NULL){
        printf("%d ", l->n);
        l = l->next;
    }
}


void divideLista(Lista *l, int n){
	Lista* pList = l;
	Lista* l1 = NULL;
	Lista* l2 = NULL;
    
    //Enquanto o elemento da lista for diferente de n, adiciona os elementos na lista1;
	while(pList->n != n){
	  	l1 = insert(l1, pList->n);
		pList = pList->next;
	}
    //Enquanto a lista não esvaziar, adiciona os elementos na lista2;
	while(pList != NULL){
		l2 = insert(l2, pList->n);
		pList = pList->next;
	}
		imprimeLista(l1);
}

int main(){
	Lista* lista = NULL;
	Lista* lista2;
	int i, n, tamanho;
    
    //Tamanho da lista
	scanf("%d", &tamanho);
    
    //Adiciona os elementos na lista
	for(i = 0; i < tamanho; i++){
		scanf("%d", &n);
		lista = insert(lista, n);
	}
	//Numero que vai dividiar a lista
	scanf("%d", &n);

	divideLista(lista, n);
}