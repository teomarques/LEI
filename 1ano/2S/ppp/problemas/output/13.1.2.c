#include <stdio.h>
#include <stdlib.h>

typedef struct l_node{
    int num;
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

void print_list(list_t *list, int *maior, int *menor, double *media){
    l_node_t *node = list -> front;
    int index = 0;
    int soma = 0;
    int nxt = 0;
    if(node != NULL){
        *maior = node -> num;
        *menor = node -> num;
    }
    while(node != NULL){
        index++;
        soma += node -> num;
        printf("%d ", (node -> num));
        if(node -> num > *maior)
            *maior = node -> num;
        else if(node -> num < *menor)
            *menor = node -> num;
        node = node -> next;
    }
    *media = (double)soma / index;
    printf("média: %lf\n", *media);
    printf("maior: %d\n", *maior);
    printf("menor: %d\n", *menor);
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

void search(list_t *list, int val, l_node_t ** prev, l_node_t **cur){
    *prev = NULL;
    *cur = list -> front;
    while(*cur != NULL && (*cur) -> num < val){
        *prev = *cur;
        *cur = (*cur) -> next;
    }
}

void insert(list_t *list, int val){
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
        list -> num_elems++;
    }
}

int main(){
    int n = 0;
    int elem = 0;
    list_t list;
    init(&list);
    printf("quantos elementos? ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("elemento %d: ", i+1);
        scanf("%d", &elem);
        insert(&list, elem);
    }
    int maior = 0;
    int menor = 0;
    double media = 0;
    print_list(&list, &maior, &menor, &media);
    clear(&list);
}