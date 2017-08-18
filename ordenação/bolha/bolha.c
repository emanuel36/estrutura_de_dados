#include <stdio.h>
#include "main.h"

void ordena(int *vetor, int tamanho){
	int fim, i, j;

	for(fim = tamanho - 1; fim > 0; fim--){
		
		for(i = 0; i < fim; i++){
			
			if(vetor[i] > vetor[i + 1]){
				swap(&vetor[i], &vetor[i + 1]);	
			}
			printf("\n-------------\n");
			for(j = 0; j < tamanho; j++){
			printf("%d ", vetor[j]);	
			}
		}
	}
}
