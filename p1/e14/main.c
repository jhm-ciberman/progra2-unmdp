#include <stdio.h>
#include <stdlib.h>

/*
14. Desarrollar un subprograma que muestre un cuadrado con bordes de N numerales (N es
parámetro de entrada)
*/

void imprime_cuadrado(int ancho, int alto);

int main()
{
    int ancho, alto;
    printf("Ancho: ");
    scanf("%d", &ancho);
    printf("Alto: ");
    scanf("%d", &alto);
    imprime_cuadrado(ancho, alto);

    return 0;
}


void imprime_cuadrado(int ancho, int alto) {

    int x, y;

    for (x = 0; x < ancho; x++) {
        for (y = 0; y < alto; y++) {
            if (x == 0 || x == ancho - 1) {
                if (y == 0 || y == alto -1) {
                    printf("+");
                } else {
                    printf("-");
                }
            } else {
                if (y == 0 || y == alto - 1) {
                    printf("|");
                } else {
                    printf(" ");
                }

            }
        }
        printf("\n");
    }

}
