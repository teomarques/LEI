#include "estruturas.h"
#include "pontos.h"

int compara_pontos(Resultados r[3]){
    Ordenados r2[3];
    int extra;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(r[i].golos1 >= r2[j].golos){
                r2[j+1].golos = r[i].golos1;
            }
            else{
                extra = r2[j].golos;
                r2[j].golos = r[i].golos1;
                r2[j+1].golos = extra;
            }
            if(r[i].golos2 >= r2[j].golos){
                r2[j+1].golos = r[i].golos2;
            }
            else{
                extra = r2[j].golos;
                r2[j].golos = r[i].golos2;
                r2[j+1].golos = extra;
            }
        }
    }
    for(int i = 0; i < 3; i++){
        printf("%d\n", r2[i]);
    }
    return 0;
}


int pontos(Resultados r[], Dados d[]){
    for(int i = 0; i < 20; i++){
        if(r[i].golos1 > r[i].golos2){
            for(int j = 0; j < 20; j++){
                if(d[j].nome == r[i].nome1){
                    d[j].pontos += 2;
                }
            }
        }
        else if(r[i].golos1 == r[i].golos2){
            for(int j = 0; j < 20; j++){
                if(d[j].nome == r[i].nome1){
                    d[j].pontos ++;
                }
                if(d[j].nome == r[i].nome2){
                    d[j].pontos ++;
                }
            }
        }
        else{
            for(int j = 0; j < 20; j++){
                if(d[j].nome == r[i].nome2){
                    d[j].pontos += 2;
                }
            }
        }
    }
    return 0;
}
