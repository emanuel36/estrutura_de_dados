#include <stdio.h>

int somar(int *vetor, int tamanho, int soma){
	if(tamanho < 0){
		return soma;
	}
	else {
		soma = soma + vetor[tamanho]; 
		tamanho--;
	}
	return (somar(vetor, tamanho, soma));
}