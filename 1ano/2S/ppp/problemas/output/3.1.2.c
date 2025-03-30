# include <stdio.h>
int main(){
    int lim;
    printf("limite: ");
    scanf("%d", &lim);
    int soma = 1;
    int ant = 1;
    int ant2 = 0;
    while(soma <= lim){
        printf("%d, ", soma);
        ant2 = ant;
        ant = soma;
        soma = ant + ant2;
    }
}