#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
3) Leer nombre y 3 notas de un conjunto de N alumnos, mostrar el nombre del alumno que obtuvo el
mejor promedio.
*/

int main()
{
    int n, i;
    char nombre[20], mejorNombre[20];
    int nota1, nota2, nota3;
    float prom, mejorProm;
    printf("Introduzca el numero de alumnos: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Nombre del Alumno %d: ", i+1);
        scanf("%s", nombre);
        printf("Las 3 notas de %s separadas por espacios: \n");
        scanf("%d %d %d", &nota1, &nota2, &nota3);
        prom = (nota1 + nota2 + nota3) / 3;
        if (prom > mejorProm) {
            mejorProm = prom;
            strcpy(mejorNombre, nombre);
        }

    }
    printf("\n\n=> El mejor promedio es de %s con promedio %.2f", mejorNombre, mejorProm);
    return 0;
}
