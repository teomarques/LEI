#include <stdio.h>
#include <stdlib.h>

typedef struct l_node{
    double num;
    struct l_node *next;
}l_node_t;

typedef struct list{
    size_t num_elems;
    l_node_t *front;
}list_t;

void init(list_t *list){
    list -> num_elems = 0;
    list -> front = NULL;
}

int empty(list_t *list){
    return list -> front == NULL;
}

void print_list(list_t *list){
    l_node_t *node = list -> front;
    while(node != NULL){
        printf("qualquer coisa");
        node = node -> next;
    }
}

void clear(list_t *list){
    l_node_t *node;
    while(list -> front != NULL){
        node = list -> front;
        list -> front = list -> front -> next;
        free(node);
    }
    init(list);
}

void search(list_t *list, double val, l_node_t ** prev, l_node_t **cur){
    *prev = NULL;
    *cur = list -> front;
    while(*cur != NULL && (*cur) -> num < val){
        *prev = *cur;
        *cur = (*cur) -> next;
    }
}

void insert(list_t *list, double val){
    l_node_t *node = (l_node_t*)malloc(sizeof(l_node_t));
    l_node_t *prev, *cur;
    if(node != NULL){
        node -> num = val;
        search(list, val, &prev, &cur);
        if(prev != NULL){
            prev -> next = node;
            node -> next = cur;
        } else {
            list -> front = node;
            node -> next = cur;
        }
        list -> num_elems++
    }
}


// eliminar o primeiro elemento: list -> front = cur -> next; #o list -> front é sempre o primeiri elemento da lista
// eliminar um elemento no meio da lista: prev -> next = cur -> next;

void remove_node(list_t *list, double val){
    l_node_t *prev, *cur;
    search(list, val, &prev, &cur);
    if(cur != NULL && cur -> num == val){
        if(prev != NULL) prev -> next = cur -> next;
        else list -> front = cur -> next;
        free(cur);
        list -> num_elems --;
    }
}

int main(){}