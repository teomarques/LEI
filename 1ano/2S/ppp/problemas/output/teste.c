# include <stdio.h>


void soma(int num1, int num2, int *num3) {
    num3 = num1 + num2;
}

int main() {
    int num1 = 2;
    int num2 = 1;
    int num3 = soma(num1, num2);

    printf("MAIN: sum1=%d     num2=%d     num3=%d\n", num1, num2, num3);
}
