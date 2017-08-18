#include <stdio.h>
#include "testar_ordenacao.h"

int main(){
	int vetor[5];
	int crescente = 1, decrescente = 1, i = 0;

	for(i = 0; i < 5; i++){
		printf("Elemento Vetor[%d]: ", i);
		scanf("%d", &vetor[i]);
	}
	testar_ordenacao(&vetor, &crescente, &decrescente);

	if(crescente == 1){ 
		printf("\nVetor ordenado crecentemente!\n");
	}
	else if(decrescente == 1){
		printf("\nVetor ordenado decrescentemente!\n");	
	} 
	else{
		printf("\nVetor não ordenado!\n");
	}
}