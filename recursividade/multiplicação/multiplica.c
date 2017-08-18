#include <stdio.h>

int multiplica(int n1, int n2, int multipl){
	if(n1 == 0){
		return multipl;
	}
	else{
		multipl = multipl + n2;
		n1--;
	}
	return multiplica(n1, n2, multipl);
}