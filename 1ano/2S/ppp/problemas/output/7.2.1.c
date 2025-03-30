#include <stdio.h>

typedef struct{
    int dia, mes, ano;
}Data;

int ord_data(int t, Data datas[t]){
    Data datas_ord[t];
    for(int i = 0; i < t-1; i++){
        if(datas[i+1].ano > datas[i].ano){
            datas_ord[i].ano = datas[i].ano;
            datas_ord[i+1].ano = datas[i+1].ano;
            printf("%d-", datas_ord[i].ano);
        }
        else{
            datas_ord[i].ano = datas[i+1].ano;
            datas_ord[i+1].ano = datas[i].ano;
            printf("%d-", datas_ord[i].ano);
        }
        if(datas[i+1].mes > datas[i].mes){
            datas_ord[i].mes = datas[i].mes;
            datas_ord[i+1].mes = datas[i+1].mes;
            printf("%d-", datas_ord[i].mes);
        }
        else{
            datas_ord[i].mes = datas[i+1].mes;
            datas_ord[i+1].mes = datas[i].mes;
            printf("%d-", datas_ord[i].mes);
        }
        if(datas[i+1].dia > datas[i].dia){
            datas_ord[i].dia = datas[i].dia;
            datas_ord[i+1].dia = datas[i+1].dia;
            printf("%d\n", datas_ord[i].dia);
        }
        else{
            datas_ord[i].dia = datas[i+1].dia;
            datas_ord[i+1].dia = datas[i].dia;
            printf("%d\n", datas_ord[i].dia);
        }
    }
    return 0;
}

int main(){
    int t;
    printf("Quantas datas? ");
    scanf("%d", &t);
    Data datas[t];
    for(int i = 0; i < t; i++){
        printf("Dia da data %d: ", i);
        scanf("%d", &datas[i].dia);
        printf("Mês da data %d: ", i);
        scanf("%d", &datas[i].mes);
        printf("Ano da data %d: ", i);
        scanf("%d", &datas[i].ano);
    }
    ord_data(t, datas);
}