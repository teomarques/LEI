#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *f = fopen("file.txt", "r");
    char str[100], maior[100];
    size_t len_maior = 0;
    if(f == NULL) return -1;
    while(fgets(str, 100, f) != NULL){ // ou fscanf(f, "%s", str) != EOF
        if(len_maior < strlen(str)){
            len_maior = strlen(str):
            strcpy(maior, str);
        }
    }
    printf("%s\n", str);
    if(fclose(f) == EOF) return -1;
}