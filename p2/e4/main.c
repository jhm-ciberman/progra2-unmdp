#include <stdio.h>
#include <stdlib.h>


/*
4 - Desarrollar un programa que cree dinámicamente un arreglo de números reales que contenga
N elementos (N es ingresado por teclado). Ingresar sus elementos y mostrar aquellos que sean
positivos utilizando aritmética de punteros. Al finalizar, liberar la memoria solicitada en tiempo
de ejecución.
*/


int main()
{
    int n, i;
    int *arr;
    printf("Introduzca numero de elementos: ");
    scanf("%d", &n);

    arr = (int*) malloc(sizeof(int) * n);

    for (i = 0; i < n; i++) {
        printf("introduzca el elemento con indice %d: ", i);
        scanf("%d", &(arr[i]));
    }
    printf("\n");

    printf("Elementos positivos: ");
    for (i = 0; i < n; i++) {
        if (*(arr + i) > 0) {
            if (i != 0)
                printf(", ");
            printf("%d", *(arr + i));
        }
    }

    free(arr);
    return 0;
}
