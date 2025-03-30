#include <stdio.h>
#include "novafuncao.h"

int novafuncao(int a, int b){
	
	int aux1 = 0;
	int aux2 = 0;
	
	for(int i = 0; i < b; i++){
		
		aux1 += b - a;
		
	}
	
	for(int i = 0; i < a; i++){
	
		aux2 += b + a;
	
	}
	
	int c = aux1 + aux2;
	return c;
	
}