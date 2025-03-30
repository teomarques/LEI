#include <stdio.h>

int compara(int peso){
    if(peso % 2 == 0){
        for(int i = 0; i < peso; i++){
            if(i % 2 == 0 && peso - i == 0){
                printf("YES");
                return 0;
            }
        }
        printf("NO");
        return 0;
    }
    else{
        printf("NO");
        return 0;
    }
}

int main(){
    int peso;
    printf("Qual o peso? (entre 0 e 100): ");
    scanf("%d", &peso);
    compara(peso);
}