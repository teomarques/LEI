# include <stdio.h>

void print_troca(int ant, int seg, int act, int tab[]){
    printf("[...%d, ", ant);
    printf("%d, ", tab[act]);
    printf("%d, ...] *TROCA* ", seg);
    printf("[...%d, ", tab[act-1]);
    printf("%d, ", tab[act]);
    printf("%d, ...]\n", tab[act+1]);
    return;
}

void print_Ntroca(int act, int tab[]){
    printf("[...%d, ", tab[act-1]);
    printf("%d, ", tab[act]);
    printf("%d, ...] *não troca* ", tab[act+1]);
    printf("[...%d, ", tab[act-1]);
    printf("%d, ", tab[act]);
    printf("%d, ...]\n", tab[act+1]);
    return;
}

int trocar(int l, int tab[]){
    int seg;
    int ant;
    for (int m = 1; m < l - 1; m++){
        if (tab[m+1] < tab[m] && tab[m-1] > tab[m]){
            seg = tab[m+1];
            ant = tab[m-1];
            tab[m+1] = ant;
            tab[m-1] = seg;
            print_troca(ant, seg, m, tab);
        }
        else{
            print_Ntroca(m, tab);
        }
    }
    return 0;
}

int main(){
    int N;
    printf("Quantos componentes tem a tabela? ");
    scanf("%d", &N);
    int tab[N];
    int elem;
    for (int i = 0; i < N; i++){
        printf("Elemento %d: ", i+1);
        scanf("%d", &elem);
        tab[i] = elem;
    }
    trocar(N, tab);
}