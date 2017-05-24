#include <stdio.h>

/*
1. Corregir el siguiente programa para que los valores de las variables a y b resulten ordenados de
manera ascendente:

*/

void ordenadas(int *x, int *y){
    int aux;
    if(*x > *y) {
        aux = *x;
        *x = *y;
        *y = aux;
    }
}
int main(){
    int a = 30, b = 20;
    printf("Valor de a %d\tvalor de b %d\n", a, b);
    ordenadas(&a, &b);
    printf("Valor de a %d\tvalor de b %d\n", a, b);
    return 0;
}
