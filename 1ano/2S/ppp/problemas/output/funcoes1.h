#ifndef FUNCOES1_H
#define FUNCOES_H
#include "estruturas2.h"

void init(queue_t *q);
int empty(queue_t *q);
void push(queue_t *q, double num);
double front(queue_t *q);
void pop(queue_t *q);
void clear(queue_t *q);

#endif