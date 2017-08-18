#include <stdio.h>
#include "funções.h"

int main(){
	int opcao;
	float n1, n2, operacao, fat = 1.0;

	printf("\n-----Calculadora-----\n");

	printf("Numero 1: ");
	scanf("%f", &n1);

	printf("Numero 2: ");
	scanf("%f", &n2);

	printMenu();

	printf("\nOPERACAO: ");
	scanf("%d", &opcao);

	if(opcao == 1){
		soma(&n1, &n2, &operacao);
		printf("Resultado: %f", operacao);
	}
	else if(opcao == 2){
		subtracao(&n1, &n2, &operacao);
		printf("Resultado: %f", operacao);
	}
	else if(opcao == 3){
		multiplicacao(&n1, &n2, &operacao);
		printf("Resultado: %f", operacao);
	}
	else if(opcao == 4){
		divisao(&n1, &n2, &operacao);
		printf("Resultado: %f", operacao);
	}
	else if(opcao == 5){
		fatorial(&n1, &fat);
		printf("Resultado: %f", fat);
	}else{
		printf("\nOPCAO INVALIDA");
	}
}