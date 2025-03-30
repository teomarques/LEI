#include <stdio.h>
#include <string.h>

// Declaração da função Assembly
extern void codifica_string(char *frase);

int main() {
    // String a ser codificada
    char frase[] = "hello world";
    
    // Exibe a string original
    printf("String original: %s\n", frase);
    
    // Chama a função Assembly para codificar a string
    codifica_string(frase);
    
    // Exibe a string codificada
    printf("String codificada: %s\n", frase);
    
    return 0;
}

