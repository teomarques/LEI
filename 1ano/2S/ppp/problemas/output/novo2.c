# include <stdio.h>
int main(){
    int idade;
    scanf("%d", &idade);
    if (idade<=12 || idade > 61){printf("isento de pagamento");}
    else if(idade > 12 && idade <= 24){printf("bilhete radical");}
    else if((idade > 24 && idade <= 36) || (idade > 48 && idade <= 60)){printf("bilhete light");}
    else{printf("bilhete normal");}
}