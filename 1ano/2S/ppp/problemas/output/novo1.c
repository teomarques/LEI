# include <stdio.h>
int main(){
    int x;
    int y;
    int z;
    printf("Insira número x:");
    scanf("%d", &x);
    printf("Insira numero y:");
    scanf("%d", &y);
    printf("Insira número z:");
    scanf ("%d", &z);
    if(x > y && x > z){
        printf("%d\n",x);
    }
    else if(y > x && y > z){
        printf("%d\n",y);
    }
    else{
        printf("%d\n",z);
    }
}