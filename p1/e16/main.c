#include <stdio.h>
#include <stdlib.h>

/*
16. Desarrollar un subprograma que reciba una cantidad de segundos y devuelva su equivalente en
el formato horas:minutos:segundos
*/

void formato_hora(int *horas, int *minutos, int *segundos) {
    *horas   = *segundos / 3600;
    *minutos = (*segundos / 60) % 60;
    *segundos = *segundos % 60;
}

int main()
{
    int hh, mm, ss;

    printf("Ingrese segundos: ");
    scanf("%d", &ss);

    formato_hora(&hh, &mm, &ss);

    printf("\nHora: %.2d:%.2d:%.2d\n", hh, mm, ss);
    return 0;
}
