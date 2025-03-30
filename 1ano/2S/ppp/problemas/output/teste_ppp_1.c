# include <stdio.h>
# include <string.h>

int soma(char cadeia[]){
    int t = strlen(cadeia);
    int mult = 1;
    int c = 0;
    int sum = 0;
    for(int i = 0; i < t; i++){
        if(cadeia[i] >= '0' && cadeia[i] <= '9'){
            c = c*mult+cadeia[i] - '0';
            mult *= 10;
        }
        else{
            sum +=c;
            mult = 1;
            c=0;
        }
    }
    printf("%d\n", sum);
    return 0;
}

int main(){
    char cadeia[20];
    printf("Escreva a frase: ");
    fgets(cadeia, 20, stdin);
    soma(cadeia);
}
