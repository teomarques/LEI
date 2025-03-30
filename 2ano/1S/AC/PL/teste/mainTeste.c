#include <stdio.h>

extern int my_atoi(char *str, int *tab);

int main(){
	char str[] = "23 -87 67";
	int tab[20], n;

	n = my_atoi(str, tab);

	printf("Tabela tab de inteiros:\n");
	int i = 0;
	 for(i = 0; i < 20; i++){
		printf("índice i = %d valor: %d\n", i, tab[i]);
	}

	printf("valor devolvido: %d\n", n);

	return 0;
}

