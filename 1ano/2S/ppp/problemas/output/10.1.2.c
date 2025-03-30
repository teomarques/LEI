#include "stdio.h"
#include "stdlib.h"

int main(){
    #include "funcoes1.h"
    #include "estruturas2.h"
    queue_t q;
    char fim;
    char array[50];
    int n = 0;
    do{
        printf("insira a palavra (\"FIM\" para terminar): ")
        fgets(fim, 20, &array[i]);
        n += 1;
    }while(fim != "FIM");
    init(&q);
    for(int i = 0; i < n; i++){
        printf("número %d: ", i+1);
        scanf("%c\n", &array[i]);
        push(&q, array[i]);
    }
    while(!empty(&q)){
        printf("%lf\n", front(&q));
        pop(&q);
    }
    clear(&q);
    return 0;
}