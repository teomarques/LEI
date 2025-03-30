#include <stdio.h>
#include <limits.h>

typedef struct stack{ // nodes
    int num;
    struct stack *next;
}stack_t;

int empty(stack_t **s){ // verifica se a pilha está vazia
    if(*s == NULL) return 1;
    return 0;
    // **s indica duplo ponteiro, ponteiro que aponta para o endereço de memória do ponteiro associado ao elemento
}

void pop(stack_t **s){ // passa o ponteiro para o node seguinte e elimina o anterior
    stack_t *node;
    if(!empty(s)){
        node = *s;
        *s = (*s) -> next;
        free(node);
    }
}

void clear(stack_t **s){ // limpa a pilha
    while(!empty(s)) pop(s);
}

void push(stack_t **s, int num){
    stack_t *node = (stack_t*)malloc(sizeof(stack_t));
    if(node != NULL){
        node -> num = num;
        node -> next = *s;
        *s = node;
    }
}

int front(stack_t **s){ // disposição da informação; INT_MIN é 2^(-36), para indicar que a pilha está vazia
    if(empty(s)) return INT_MIN;
    return (*s) -> num;
}

int main(){
    stack_t *s = NULL;
    int array[] = {1, 2, 3};
    if(size_t i = 0; i < 3; i++) push(&s, array[i]);
    while (!empty(&s)){
        printf("%d\n", front(&s));
        pop(&s);
    }
    clear(&s);
}