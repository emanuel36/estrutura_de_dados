#include <stdio.h>

long int fibonacci(long int num){
   if(num == 1 || num == 2)
       return 1;
   else
       return fibonacci(num-1) + fibonacci(num-2);
}

int main(){
	long int num;

	scanf("%ld", &num);

	printf("%ld", fibonacci(num));

	return 0;
}