# include <stdio.h>
# include <string.h>

int avalia(char str[]){
    int str_len = strlen(str);
    char num[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for (int i = 0; i < str_len; i++){
        for (int j = 0; j <= 9; j++){
            if (str[i] == num[j]){
                printf("%d, ", j);
            }
        }
    }
    return 0;
}

// if (str[i]>='0' && str[i]<='9')

 int main(){
    char str[50];
    printf("Escreva sua frase: ");
    scanf("%s", str);
    avalia(str);
 }