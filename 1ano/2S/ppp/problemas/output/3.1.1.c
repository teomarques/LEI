# include <stdio.h>
int main(){
    int lim;
    printf("limite: ");
    scanf("%d", &lim);
    for(int num = 1; num <= lim; num += 1){
        printf("%d, ", num);
    }
}
