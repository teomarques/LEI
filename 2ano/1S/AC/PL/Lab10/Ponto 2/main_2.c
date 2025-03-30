#include <stdio.h>
#include "potencia.h"

void main(){
	
	int val = potencia(2,8);
	
	printf("2^8 é igual a %d (devia ser 256)\n",val);
	
	val = potencia(5,6);
	
	printf("5^6 é igual a %d (devia ser 15625)\n",val);
	
	val = potencia(31,3);
	
	printf("31^3 é igual a %d (devia ser 29791)\n",val);
}