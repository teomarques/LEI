#include <stdio.h>
#include "procura.h"

void main(){
	
	int tab[30] = {3,6,12,14,19,21,25,28,32,33,37,39,40,43,47,49,50,52,59,65,77,79,81,84,88,89,91,93,99,100};
	
	
	int index_1 = procura(tab,0,29,25);
	
	int index_2 = procura(tab,0,29,80);

	int index_3 = procura(tab,0,29,100);
	
	printf("O valor 25 está na posição %d\n",index_1);
	
	printf("O valor 80 está na posição %d\n",index_2);

	printf("O valor 100 está na posição %d\n",index_3);
	
}