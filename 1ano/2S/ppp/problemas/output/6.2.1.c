#include <stdio.h>
#include <string.h>
#include <ctype.h>

void cod_str(char str[], char conv[], char orig[]){
    int len = strlen(str);
    int len_orig = strlen(orig);
    for (int i = 0; i < len; i++){
        if (str[i] != ' '){
            for (int j = 0; j < len_orig; j++){
                if (toupper(str[i]) == orig[j]){
                    str[i] = conv[j];
                    printf("%c\n", conv[j]);
                    break;
                }
            }
        }
    }
    printf("%s", str);
    return;

}

int main(){
    char str[40];
    char conv[30] = "DEIABCFGHJKLZYXWVUTSRQPONM";
    char orig[30] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    printf("Indique a frase: ");
    fgets(str, 40, stdin);
    cod_str(str, conv, orig);
}