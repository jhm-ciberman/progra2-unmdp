#include <stdio.h>
#include <stdlib.h>
#include "pilaestatica.h"
#include "piladinamica.h"


void archivo_lee_pila_dinamica(FILE *f) {
    Pilad pila;
    pilad_inicia(&pila);
    char c;
    while (!feof(f) && fscanf(f, "%c\n", &c)) {
        pilad_pone(&pila, c);
    }
    while (!pilad_vacia(pila)) {
        pilad_saca(&pila, &c);
        putc(c, stdout);
    }
}

void archivo_lee_pila_estatica(FILE *f) {
    Pilae pila;
    pilae_inicia(&pila);
    char c;
    while (!feof(f) && fscanf(f, "%c\n", &c)) {
        pilae_pone(&pila, c);
    }
    while (!pilae_vacia(pila)) {
        pilae_saca(&pila, &c);
        putc(c, stdout);
    }
}

void archivo_lee_pila_mantiene(FILE *f) {
    Pilad pila1, pila2;
    pilad_inicia(&pila1);
    pilad_inicia(&pila2);
    char c;
    while (!feof(f) && fscanf(f, "%c\n", &c)) {
        pilad_pone(&pila1, c);
    }
    while (!pilad_vacia(pila1)) {
        pilad_saca(&pila1, &c);
        pilad_pone(&pila2, &c);
        putc(c, stdout);
    }
    while (!pilad_vacia(pila2)) {
        pilad_saca(&pila2, &c);
        pilad_pone(&pila1, &c);
    }
}

int main()
{
    printf("Hello world!\n");
    FILE* f = fopen("texto.txt", "rt");
    if (f != NULL) {
        printf("Dinamica: \t");
        archivo_lee_pila_dinamica(f);

        fseek(f, 0, SEEK_SET);
        printf("\nEstatica: \t");
        archivo_lee_pila_estatica(f);

        fseek(f, 0, SEEK_SET);
        printf("\nManteniendo: \t");
        archivo_lee_pila_mantiene(f);

        printf("\n");
        fclose(f);
    } else {
        printf("Error abriendo archivo de texto");
    }

    return 0;
}

