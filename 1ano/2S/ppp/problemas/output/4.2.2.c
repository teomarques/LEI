# include <stdio.h>

int p(int n, int k){
    int prod = n-k;
    printf("%d x ", n-k);
    for(int i = n-k+1; i <= n; i++){
        prod *= i;
        printf("%d", i);
        if(i != n){
            printf(" x ");
        }
        else{
            printf(" = %d", prod);
        }
    }
    return 0;
}

int main(){
    int x;
    int k;
    printf("Digite um número: ");
    scanf("%d", &x);
    printf("Digite um número de raio: ");
    scanf("%d", &k);
    p(x, k);
}