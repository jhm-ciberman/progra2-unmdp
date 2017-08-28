#include <stdio.h>
#include <stdlib.h>

/*
5 - Desarrollar un programa que cree un arreglo estático de punteros a enteros, y luego cargue en
él N enteros (N y los enteros se encuentran en un archivo de texto). Mostrar aquellos que sean
positivos. Al finalizar, liberar la memoria solicitada en tiempo de ejecución.
*/
int main()
{
    int n, i;
    int* arr[20];
    FILE* f = fopen("numeros.txt", "rt");


    if (!f) {
        printf("Error al abrir el archivo de texto");
        return 0;
    }

    fscanf(f, "%d", &n);

    for (i = 0; i < n; i++) {
        arr[i] = (int*) malloc(sizeof(int));
        fscanf(f, "%d", arr[i]);
    }
    fclose(f);

    // ...

    printf("Numeros positivos: ");
    for (i = 0; i < n; i++) {
        if (*(arr[i]) > 0) {
            if (i != 0) {
                printf(", ");
            }
            printf("%d", *(arr[i]));
        }
    }
    printf("\n");

    // ...

    for (i = 0; i < n; i++) {
        free(arr[i]);
    }

    return 0;
}
