#include <stdio.h>

typedef struct{
    int dia, mes, ano;
}Data;

int comp_data(Data d1, Data d2){
    if(d1.ano < d2.ano){return -1;}
    else if(d1.ano > d2.ano){return 1;}
    if(d1.mes < d2.mes){return -1;}
    else if(d1.mes > d2.mes){return 1;}
    if(d1.dia < d2.dia){return -1;}
    else if(d1.dia > d2.dia){return 1;}
    return 0;
}
int main(){
    Data d1 = {24, 3, 2020};
    Data d2;
    scanf("%d/%d/%d", &d2.dia, &d2.mes, &d2.ano);
    int comp = comp_data(d1, d2);
    printf("%d\n", comp);
    return 0;
}