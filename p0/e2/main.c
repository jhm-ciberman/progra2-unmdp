#include <stdio.h>
#include <stdlib.h>


/*
2) Leer un conjunto de números positivos y mostrar el factorial de cada uno de ellos.
*/
int main()
{

    int n, r;
    printf("Ingrese numeros. Ingrese 0 para salir.\n");

    printf("\nNumero: ");
    scanf("%d", &n);

    while (n != 0) {
        r = n;
        while (n > 1) {
            r *= (--n);
        }
        printf("Factorial: %d", r);
        printf("\nNumero: ");
        scanf("%d", &n);
    }

    printf("Chau!");

    return 0;
}
