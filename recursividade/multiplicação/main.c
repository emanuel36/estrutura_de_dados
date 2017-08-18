#include <stdio.h>
#include "main.h"

int main(){
	int n1, n2, multipl = 0;

	printf("Numero 1: ");
	scanf("%d", &n1);

	printf("Numero 2: ");
	scanf("%d", &n2);

	multipl = multiplica(n1, n2, multipl);

	printf("Multiplicacao: %d\n", multipl);
}