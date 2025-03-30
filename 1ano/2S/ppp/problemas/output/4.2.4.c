# include <stdio.h>

int primo(int n){
    int num_div = 0;
    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            num_div ++;
        }
    }
    if(num_div == 2){
        printf("O número é primo\n");
    }
    else{
        printf("não é primo\n");
    }
    return 0;
}

int main(){
    int x;
    printf("Digite um número: ");
    scanf("%d", &x);
    primo(x);
}