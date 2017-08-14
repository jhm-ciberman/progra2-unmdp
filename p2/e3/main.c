#include <stdio.h>
#include <stdlib.h>


/*
3 - Implementar un programa que cree dinámicamente 3 variables enteras, muestre su suma y su
producto. Asegurarse de administrar correctamente la memoria e implementar funciones para
evitar duplicaciones de código.
*/

int* carga_numero() {
    int *a = (int*) malloc(sizeof(int));
    printf("Ingrese numero: ");
    scanf("%d", a);
    return a;
}

int main()
{
    int *a = carga_numero();
    int *b = carga_numero();
    int *c = carga_numero();

    int suma = *a + *b + *c;
    int producto = *a * *b * *c;

    printf("Suma: %d\n", suma);
    printf("Producto: %d\n", producto);
    return 0;
}
