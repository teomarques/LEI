# include <stdio.h>

void print_tab(int m, int n, int tab[m][n]);
void transposta(int m, int n, int mx[m][n], int mt[n][m]){
    int i, j;
    for (i = 0; i < m; i++){
        for (j = 0; j < n; j++){
            mt[j][i] = mx[i][j];
        }
    }
}

#define ROWS 2
#define COLS 3

int main(){
    int tab[ROWS][COLS] = { {1, 2, 3}, {4, 5, 6} };
    int transp[COLS][ROWS];
    print_tab(ROWS, COLS, tab);
    printf("-----------------------------------\n");
    transposta(ROWS, COLS, tab, transp);
    print_tab(COLS, ROWS, transp);
    return 0;
}

void print_tab(int m, int n, int tab[m][n]){
    int i, j;
    for(i = 0; i < m; i ++){
        for (j = 0; j < n; j++)
            printf("%6d", tab[i][j]);
        printf("\n");
    }
}