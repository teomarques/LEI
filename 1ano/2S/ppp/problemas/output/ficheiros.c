#include <stdio.h>

int main(){
    FILE *f = foppen("file.txt", "r");
    // f ou é null ou tem um endereço
    printf("%d", x); /* ---> */ fprintf(f, "%d", x); // ou ao invés de f, escrever stdout, escreve na consola
    fputs("string", f); // só escreve strings no ficheiro
    scanf("%d", &x); /* ---> */ fscanf(f, "%d", &x); // lê do ficheiro ao invés da consola, linha a linha
    char str[100];
    fgets(str, 100, f); // adiciona à string o conteúdo do ficheiro, linha a linha

    if(str[strlen(str) - 1] == '\n') str[strlen(str) - 1] = '\0';
    else while((ch = getchar()) != EOF && ch != '\n');
    fclose(f);
    // pode retornar 0 (fechou) ou EoF (End of File, chegou ao fim mas não conseguiu fechar)
}