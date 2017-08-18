#include <stdio.h>

int escolher(int n, int k){
	if(n == 0 || k == 1){
		return n;
	}else{
		return escolher(n-1, k-1) + escolher(n-1, k);
	}
}

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	printf("%d", escolher(n, k));
}