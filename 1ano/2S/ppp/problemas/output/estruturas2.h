#ifndef ESTRUTURAS_H
#define ESTRUTURAS_H

typedef struct q_node{
    double num;
    struct q_node *next;
}q_node_t;

typedef struct queue{
    q_node_t *first;
    q_node_t *last;
}queue_t;

#endif