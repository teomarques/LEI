#include "estruturas2.h"
#include "funcoes1.h"
#include "stdio.h"
#include "stdlib.h"

void init(queue_t *q){
    q -> first = NULL;
    q -> last = NULL;
}

int empty(queue_t *q){
    if(q -> first == NULL) return 1;
    return 0;
}

int push(queue_t *q, double num){
    q_node_t *node = (q_node_t *)malloc(sizeof(q_node_t));
    if(node != NULL){
        node -> num = num;
        node -> next = NULL;
        if(empty(q)){
            q -> first = node;
        } else{
            q -> last -> next = node; // empurra o node anterior pra frente e realoca os ponteiros (first no anterior e last no atual)
        }
        q -> last = node;
    }
}

double front(queue_t *q){
    if(empty(q)) return -1;
    return q -> first -> num;
}

void pop(queue_t *q){
    q_node_t *node;
    if(!empty(q)){
        node = q -> first;
        q -> first = q -> first -> next;
        if(empty(q)) q -> last = NULL;
        free(node);
    }
}

void clear(queue_t *q){
    while(!empty(q)) pop(q);
}