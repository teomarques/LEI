# include <stdio.h>

void inverte(int array[], int size){
    int array_inv[size];
    for (int i = 1; i <= size; i++){
        array_inv[i-1] = array[size-i];
        if(i == 1){printf("array invertido: [%d, ", array_inv[i-1]);}
        else if(i == size){printf("%d]", array_inv[i-1]);}
        else{printf("%d, ", array_inv[i-1]);}
    }
    return;
}
int main(){
    int size;
    int el;
    printf("Escreva o tamanho do array: ");
    scanf("%d", &size);
    int array[size];
    for (int i = 0; i < size; i++){
        printf("Escreva o elemento: ");
        scanf("%d", &el);
        array[i] = el;
    }
    inverte(array, size);
}