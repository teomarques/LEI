#include <stdio.h>

void converter(int num){
    char dic[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char ndic[5];
    int resto = 0;
    int num2 = num;
    int c = 0;
    for(int i = 0; i < 5; i++){
            num2 = num2 / 10;
            c ++;
    }
    for(int i = 0; i < c; i++){
        resto = num % 10;
        num = num / 10;
        for(int j = 0; j <= 9; j++){
            if(resto == dic[j] - '0'){
                printf("%c", dic[j]);
                ndic[i] = dic[j];
            }
        }
    }
}

int main(){
    converter(4);
}
