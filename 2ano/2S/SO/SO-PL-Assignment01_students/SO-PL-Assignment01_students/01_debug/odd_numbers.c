#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50		//Error #2: 2 may not be sufficient!

int odd(int k) {
	return k%2;
}

int main(int argc, char* argv[]) {
  int i,n;
  int numbers[SIZE];
  int is_odd[SIZE];
  char c[]="Odd numbers:";

	printf("Number of args# = %d\n",argc);
	for(i = 0; i < argc - 1; i++){	//Error #1: should be argc-1 CORRECTED
		n=atoi(argv[i+1]);
		printf("%d\n",n);
		numbers[i] = n;
		is_odd[i] = odd(n);
	}

	printf("%s\n",c);
	for(i = 0; i < argc-1; i++){
		if(is_odd[i]==1) printf("%d ",numbers[i]);
	}
	printf("\n");
	return 0;
}
