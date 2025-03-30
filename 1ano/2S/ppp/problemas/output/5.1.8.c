# include <stdio.h>

void print_tab(int l, int c, int tab[l][c]){
    int i, j;
    for (i = 0; i < l; i++){
        for (j = 0; j < c; j++){
            printf("%6d", tab[i][j]);
        }
        printf("\n");
    }
}

void localizar(int tab[5][5]){
    int c1, c2;
    printf("Qual a cidade 1? ");
    scanf("%d", &c1);
    printf("Qual a cidade 2? ");
    scanf("%d", &c2);
    printf("%d\n", tab[c1-1][c2-1]);
    return;
}

#define LINHAS 5
#define COLUNAS 5

int main(){
    int tab[LINHAS][COLUNAS] = {{0, 20, 30, 40, 50},
                                {20, 0, 20, 30, 40},
                                {30, 20, 0, 20, 30},
                                {40, 30, 20, 0, 20},
                                {50, 40, 30, 20, 0}};
    print_tab(LINHAS, COLUNAS, tab);
    localizar(tab);
}