# include <stdio.h>

int verifica(int N, int valor[]){
    int novo_valor[N];
    for (int i = 1; i < N; i++){
        for (int j = i-1; j >= 0; j--){
            if (valor[j] == valor[i]){
                novo_valor[i] = valor[i];
                printf("%d, ", novo_valor[i]);
            }
            else{
                novo_valor[i-1] = valor[i];
                printf("%d", novo_valor[i]);
            }
        }
    }
    return 0;
}

int main(){
    int N;
    printf("Quantos valores? ");
    scanf("%d", &N);
    int valor[N];
    for (int i = 0; i < N; i++){
        printf("Valor %d: ", i+1);
        scanf("%d", &valor[i]);
    }
    verifica(N, valor);
}