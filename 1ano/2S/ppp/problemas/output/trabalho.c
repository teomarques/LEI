/*
submissão: 
    pasta: projeto/
        bin/ -> executável
        docs/ -> documentação
        lib/ -> .h
        src/ -> .c
guardar os projetos:
    gcc -Wall -Wextra src/*.c
                        V
                busca tds os ficheiros .c
                e aloca em projeto/src/
    gcc -Wall -Wextra -o bin/proj -g
                           V       V
                guarda em proj-   roda e debuga
                eto/bin/proj,     o código
                sendo proj um 
                executável
valgrind --leak-check-full --track-origins-yes ./main
--> vai dizer o que o programa faz, e vai dizer se libertei a 
memória de todas as variáveis e onde estão os erros.
sempre libertar o mesmo tanto que foi feito malloc's

não utilizar scanf, usar o fgets e se quiser numero converter, 
sem utilizar o atoi()
cleanbuffer_removeline <- para remover \n e dps:
e colocar '\0'
Meter um ciclo até o input ser válido e uma mesagem caso seja inválido,
mas sem parar o projeto
usar fgets para ler input e verificar a não existência de elementos alheios, se verificar, devolver que o input não é válido.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "trab_estruturas.h"

// inicializar lista doentes como vazia

void init_doente(list_doente_t *list_doente){
    list_doente -> num_elems = 0;
    list_doente -> front = NULL;
}

// inicializar lista registros como vazia

void init_registro(list_registro_t *list_registro){
    list_registro -> num_elems = 0;
    list_registro -> front = NULL;
}

// anular o elemento do front de doentes

int empty_doente(list_doente_t *list_doente){
    return list_doente -> front == NULL;
}

// anular o elemento do front de registros

int empty_registro(list_registro_t *list_registro){
    return list_registro -> front == NULL;
}

// printar os elementos da lista doentes

void print_list_doente(list_doente_t *list_doente){
    doente_node_t *node = list_doente -> front;
    while(node != NULL){
        printf("%d\n%d\n", (node -> id; node -> tel));
        for(int i = 0; i < sizeof(node -> data_nascimento); i++) printf("%c", node -> data_nascimento[i]);
        for(int i = 0; i < sizeof(node -> nome); i++) printf("%c", node -> nome[i]);
        for(int i = 0; i < sizeof(node -> cc); i++) printf("%c", node -> cc[i]);
        for(int i = 0; i < sizeof(node -> email); i++) printf("%c", node -> email[i]);
        node = node -> next;
    }
}

// printar os elementos da lista registros

void print_list_registro(list_registro_t *list_registro){
    registro_node_t *node = node_registro -> front;
    while(node != NULL){
        printf("%d\n%d\n&d\n%d\n%d\n", (node -> id; node -> tmax; node -> tmin;
        node -> peso; node -> altura));
        for(int i = 0; i < sizeof(node -> data_registro); i++) printf("%c", node -> data_registro[i]);
        node = node -> next;
    }
}

// apagar (free) todos os nodes da lista doentes

void clear_doente(list_doente_t *list_doente){
    list_doente_t *node;
    while(list_doente -> front != NULL){
        node = list_doente -> front;
        list_doente -> front = list_doente -> front -> next;
        free(node);
    }
    init(list_doente);
}

// apagar (free) todos os nodes da lista doentes

void clear_registro(list_registro_t *list_registro){
    list_registro_t *node;
    while(list_registro -> front != NULL){
        node = list_registro -> front;
        list_registro -> front = list_registro -> front -> next;
        free(node);
    }
    init(list_registro);
}

// procurar valor na lista

void search_doente(list_doente_t *list_doente, char nome[TAMANHO], doente_node_t **prev, doente_node_t **cur){
    *prev = NULL;
    *cur = list_doente -> front;
    while(*cur != NULL && strcmp((*cur) -> nome, nome) < 0){
        *prev = *cur;
        *cur = (*cur) -> next;
    }
}