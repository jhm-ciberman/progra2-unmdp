#include <stdio.h>
#include <stdlib.h>

#define N 3

int main()
{

    int n[N], i, menor;

    for (i = 0; i < N; i++) {
        printf("Ingrese el %der numero: ", i + 1);
        scanf("%d", &(n[i]));
    }

    // Busca el menor

    int cumple = 1;
    i = 0;
    while (cumple && i < N - 1) {
        cumple = (abs(n[i] - n[++i]) == 1);
    }

    printf("La lista %s esta ordenada", (cumple ? "SI" : "NO"));

    return 0;
}
