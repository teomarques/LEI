#include <stdio.h>
#include "soma.h"

void main(){
	
	int val = soma(10);
	
	printf("A soma dos 10 primeiros números inteiros é igual a %d (devia ser 55)\n",val);
	
	val = soma(33);
	
	printf("A soma dos 33 primeiros números inteiros é igual a %d (devia ser 561)\n",val);
}