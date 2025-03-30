#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct q_node_t{
    char s[50];
    struct q_node_t *next;
}q_node_t;

typedef struct queue_t{
    q_node_t *first;
    q_node_t *last;
}queue_t;

void init(queue_t *q){
    q -> first = NULL;
    q -> last = NULL;
}

int empty(queue_t *q){
    if(q -> first == NULL) return 1;
    return 0;
}

int push(queue_t *q, char str[50]){
    q_node_t *node = (q_node_t *)malloc(sizeof(q_node_t));
    if(node != NULL){
      //  node -> s = str;
        strcpy(node->s, str);
        node -> next = NULL;
        if(empty(q) != '\0'){
            q -> first = node;
        } else{
            q -> last -> next = node; // empurra o node anterior pra frente e realoca os ponteiros (first no anterior e last no atual)
        }
        q -> last = node;
    }
}

char *front(queue_t *q){
    if(empty(q)) return '\0';
    return q -> first -> s;
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

int main() {
  queue_t q;
  init(&q);
  char fim[50];
  int i; // Declare i

  do {
    printf("insira a palavra (\"FIM\" para terminar): ");
    fgets(fim, 50, stdin); // Read characters including spaces
    fim[strlen(fim)-1] = '\0';
    if(strcmp(fim, "FIM") != 0) push(&q, fim);
  } while (strcmp(fim, "FIM") != 0);

  while(!empty(&q)) {
    char *value = front(&q);
    printf("%s\n", value);
    pop(&q);
  }

    // for(int i = 0; i < 5; i++){
    //     printf("sjd");
    //     char * val = front(&q);
    //     printf("palavra: %s \n", val);
    //     pop(&q);
    // }

  clear(&q);
  return 0;
}