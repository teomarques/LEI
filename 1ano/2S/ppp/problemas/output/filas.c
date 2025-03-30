#include <stdio.h>
#include <stdlib.h>

typedef struct q_node{
    double num;
    struct q_node * next;
}q_node_t;

typedef struct queue{
    q_node_t * first;
    q_node_t * last;
}queue_t;

void init(queue_t * q){
    q -> first = NULL; // (*q).first = NULL;
    q -> last = NULL;
}

int empty(queue_t * q){
    if(q -> first == NULL)
        return 1;
    return 0;
}

void push(queue_t * q, double num){
    q_node_t * node = (q_node_t *)malloc(sizeof(q_node_t));
    if(node != NULL){
        node -> num = num;
        node -> next = NULL;
        if(empty(q)){
            q -> first = node;
        }else{
            q -> last -> next = node;
        }
        q -> last = node;
    }
}

double front(queue_t * q){
    if(empty(q))
        return -1;
    return q -> first -> num;
}

void pop(queue_t * q){
    q_node_t * node;
    if(!empty(q)){
        node = q -> first;
        q -> first = q -> first -> next;
        if(empty(q))
            q -> last = NULL;
        free(node);
    }
}

void clear(queue_t * q){
    while(!empty(q))
        pop(q);
}

int main(){
    queue_t q;
    double array[] = {1, 2, 3};
    init(&q);
    for(size_t i = 0; i < 3; i++)
        push(&q, array[i]);
    while(!empty(&q)){
        printf("%lf\n", front(&q));
        pop(&q);
    }
    clear(&q);
    return 0;
}
