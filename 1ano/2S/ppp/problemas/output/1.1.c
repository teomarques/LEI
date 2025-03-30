# include <stdio.h>;

typedef struct q_node{
    double num;
    struct q_node * next;
}q_node_t;

typedef struct queue{
    q_node_t * first;
    q_node_t * last;
}queue_t;

void init(queue_t * q){
    q -> first = NULL;
    q -> last = NULL;
}

int empty(queue_t * q){
    if(q -> first == NULL){
        return 1;
    }
    return 0;
}

void push(queue_t * q, double num){
    q_node_t * node = (q_node_t *)malloc(sizeof(q_node_t));
    if(node != NULL){
        node -> num = num;
        node -> next = NULL;
    }

}
