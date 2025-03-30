# include <stdio.h>
int main(){
    int n;
    int num;
    int min;
    int num_ant;
    printf("Número de números: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("Número %d: ", (i+1));
        scanf("%d", &num);
        if(i==0){
            num_ant = num;
        }
        else{
            if(num < num_ant){
                min = num;
            }
        }
    }
    printf("\nMenor número: %d\n", min);
}