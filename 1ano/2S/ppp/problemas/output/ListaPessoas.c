#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ListaPessoas.h"

pLista cria (){
    pLista aux;
    struct pessoa p1 = {"", 0};
    aux = (pLista) malloc (sizeof (noLista));
    if (aux != NULL) {
        aux->pessoaLista = p1;
        aux->prox = NULL;
    }
    return aux;
}

int vazia (pLista lista) {
    if (lista->prox == NULL) return 1;
    else return 0;
}

pLista destroi (pLista lista){
    pLista temp_ptr;
    while (!vazia (lista)) {
        temp_ptr = lista;
        lista = lista->prox;
        free (temp_ptr);
    }
    free(lista);
    return NULL;
}

void procura (pLista lista, int chave, pLista *ant, pLista *actual){
    *ant = lista; *actual = lista->prox;
    while ((*actual) != NULL && (*actual)->pessoaLista.idade < chave) {
        *ant = *actual;
        *actual = (*actual)->prox;
    }
    if ((*actual) != NULL && (*actual)->pessoaLista.idade != chave)
        *actual = NULL;   /* elemento não encontrado*/
}

void insere (pLista lista, struct pessoa p1) {
    pLista no, ant, inutil;
    no = (pLista) malloc (sizeof (noLista));
    if (no != NULL) {
        no->pessoaLista = p1;
        procura (lista, p1.idade, &ant, &inutil);
        no->prox = ant->prox;
        ant->prox = no;
    }
}

void imprime (pLista lista){
    pLista aux = lista->prox; /* Salta o header */
    while (aux) {
        printf("%s %d\n", aux->pessoaLista.nome, aux->pessoaLista.idade);
        aux = aux->prox;
    }
}

pLista2 cria2 (){
    pLista2 aux;
    aux = (pLista2) malloc (sizeof (noLista2));
    if (aux != NULL) {
        aux->p = NULL;
        aux->prox = NULL;
    }
    return aux;
}

int vazia2 (pLista2 lista2) {
    if (lista2->prox == NULL) return 1;
    else return 0;
}

pLista2 destroi2 (pLista2 lista2){
    pLista2 temp_ptr;
    while (!vazia2 (lista2)) {
        temp_ptr = lista2;
        lista2 = lista2->prox;
        free (temp_ptr);
    }
    free(lista2);
    return NULL;
}

void procura2 (pLista2 lista2, char * chave, pLista2 *ant, pLista2 *actual){
    *ant = lista2; *actual = lista2->prox;
    while ((*actual) != NULL && strcmp((*actual)->p->pessoaLista.nome, chave) < 0) {
        *ant = *actual;
        *actual = (*actual)->prox;
    }
}

void insere2 (pLista2 lista2, pLista pont) {
    pLista2 no, ant, inutil;
    no = (pLista2) malloc (sizeof (noLista2));
    if (no != NULL) {
        procura2 (lista2, pont->pessoaLista.nome, &ant, &inutil);
        no->p = pont;
        no->prox = ant->prox;
        ant->prox = no;
    }
}

void imprime2 (pLista2 lista2){
    pLista2 aux = lista2->prox; /* Salta o header */
    while (aux) {
        printf("%s %d\n", aux->p->pessoaLista.nome, aux->p->pessoaLista.idade);
        aux = aux->prox;
    }
}
