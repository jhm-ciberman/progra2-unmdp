#include <stdio.h>
#include <stdlib.h>

/*
12. Desarrollar un programa que muestre la suma de un conjunto de números naturales ingresados
por teclado. La serie finaliza al ingresar el número 0.
*/

int main()
{
    int n, suma = 0;
    printf("Ingrese una lista de numeros naturales presionando enter entre cada numero. \n");
    printf("Para terminar la lista ingrese un cero. \n");
    printf("\n");
    printf("Numero: ");
    scanf("%d", &n);

    while (n != 0) {
        suma += n;
        printf("Numero: ");
        scanf("%d", &n);
    }
    printf("La suma es: %d", suma);
    return 0;
}
