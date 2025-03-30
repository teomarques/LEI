#include <stdio.h>

int max (int *tabela, int numValores);

int min (int *tabela, int numValores);

int main ()
{
	int a1, a2, a3, a4;
	int vMax,vMin;
	
	printf ("Introduza o primeiro valor:\n");
	scanf ("%d", &a1);
	printf ("Introduza o segundo valor:\n");
	scanf ("%d", &a2);
	printf ("Introduza o terceiro valor:\n");
	scanf ("%d", &a3);
	printf ("Introduza o quarto valor:\n");
	scanf ("%d", &a4);
	
	int tabela[] = {a1, a2, a3, a4};
	
	vMax = max (tabela, 4);
	vMin = min (tabela, 4);
	
	printf ("O valor maximo: %d\n",vMax);
	printf ("O valor minimo: %d\n",vMin);
	
	return 0;
}
