#include <stdio.h>
#include <stdlib.h>
#include "ListaPessoas.h"

int main(){
    pessoa p1 = {"Ana", 30};
    pessoa p11 = {"Tiago", 20};
    pessoa p111 = {"Paulo", 10};
    pLista p;
    p = cria ();
    insere (p, p1);
    insere (p, p11);
    insere (p, p111);
    imprime (p);
    printf("--------------\n");
    pLista2 p2;
    p2 = cria2 ();
    pLista aux = p->prox; /* Salta o header */
    while (aux) {
        insere2(p2, aux);
        aux = aux->prox;
    }
    imprime2 (p2);
    destroi2 (p2);
    destroi(p);
    return 0;
}