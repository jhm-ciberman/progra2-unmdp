#include <stdio.h>
#include <stdlib.h>

/*
1) Leer un número y obtener y mostrar su factorial.
*/

int main()
{
    int n, r;
    printf("Numero: ");
    scanf("%d", &n);
    r = n;
    while (n > 1) {
        r *= (--n);
    }
    printf("Factorial: %d", r);

    return 0;
}
