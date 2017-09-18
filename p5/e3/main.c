#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"
#include "cola.h"
/*
3. Ingresar los números de DNI de los votantes de una mesa a medida que van votando y mostrar
los últimos N (es dato) votantes
    a. en orden inverso, comenzando por el último votante.
    b. en el orden que sufragaron.
*/

typedef PilaDato TString;

void muestraOrdenInverso(TPila * pila, int n) {
    TString nombre;
    if (!vaciaP(*pila) && n > 0) {
        sacaP(pila, &nombre);
        printf("%s\n", nombre.str);
        muestraOrdenInverso(pila, n-1);
        poneP(pila, nombre);
    }
}
void muestraOrden(TPila * pila, int n) {
    TString nombre;
    if (!vaciaP(*pila) && n > 0) {
        sacaP(pila, &nombre);

        muestraOrden(pila, n-1);
        poneP(pila, nombre);
        printf("%s\n", nombre.str);
    }
}

int main()
{
    TString nombre;
    int n;
    TPila pila;
    iniciaP(&pila);
    printf("Ingrese el nombre de los votantes en el orden que van votando. \n");
    printf("Ingrese \"salir\" cuando quiera salir del proceso de ingreso de datos.\n");
    printf("Nombre del votante: ");
    fflush(stdin);
    scanf("%s", nombre.str);
    while (strcmp(strlwr(nombre.str), "salir") != 0) {

        poneP(&pila, nombre);

        printf("Nombre del votante: ");
        scanf("%s", nombre.str);
        //fflush(stdin);
        //scanf("%[^\n]", nombre);
    }
    printf("\n\nIngrese el numero de votantes a mostrar: ");
    scanf("%d", &n);

    printf("\n\nORDEN INVERSO: \n");
    muestraOrdenInverso(&pila, n);
    printf("\n\nORDEN NORMAL: \n");
    muestraOrden(&pila, n);

    return 0;
}


