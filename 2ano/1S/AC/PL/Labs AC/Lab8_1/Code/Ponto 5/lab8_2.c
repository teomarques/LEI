#include <stdio.h>

int max (int *v, int numValues);

int min (int *v, int numValues);

int main ()
{
	int a1, a2;
	int vMax,vMin;
	
	printf ("Introduza o numero de elementos:\n");
	scanf ("%d", &a1);
	
	int v[a1];
	
	int i;
	for(i = 0; i < a1; i++){
		printf("Introduza o numero:\n");
		scanf ("%d", &v[i]);
	}

	vMax = max (v, a1);
	vMin = min (v, a1);
	
	printf ("O valor maximo: %d\n",vMax);
	printf ("O valor minimo: %d\n",vMin);
	
	return 0;
}
