# include <stdio.h>

int inverte(int n){
    int rem = 0;
    int i = 10;
    int new_n = n;
    int inv_n;
    while(new_n > 0){
        rem = new_n % i;
        inv_n = inv_n*10+rem;
        new_n /= i;
    }
    printf("%d\n", inv_n);
    return inv_n;
}

void compara(int n, int inv_n){
    if(n == inv_n){
        printf("é capicua\n");
    }
    else{
        printf("Não é capicua\n");
    }
}

int main(){
    int num;
    printf("Digite o número: ");
    scanf("%d", &num);
    int inv_n = inverte(num);
    printf("%d\n", inv_n);
    compara(num, inv_n);
}