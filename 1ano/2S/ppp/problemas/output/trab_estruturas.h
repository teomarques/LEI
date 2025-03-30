#ifndef TRAB_ESTRUTURAS_H
#define TRAB_ESTRUTURAS_H

#define TAMANHO 40

typedef struct doente_node{
    int id, tel;
    char nome[TAMANHO], data_nascimento[TAMANHO], cc[TAMANHO], email[TAMANHO];
}doente_node_t;

typedef struct registro_node{
    int tmax, tmin, peso, altura, dia_registro, mes_registro, ano_registro;
}registros_node_t;

typedef struct list_doente{
    size_t num_elems;
    doente_node_t *front;
    list_registro_t *registro_doente;
}list_doente_t;

typedef struct list_registro{
    size_t num_elems;
    registros_node_t *front;
}list_registro_t;

#endif