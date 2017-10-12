#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "colas.h"

/*
nombre del sabor (cadena de 20 - ordenada por este criterio), gramos expendidos,
"fila" y "columna" (representa la celda que ocupa dicho sabor en la heladera de
expendio) y una cola con los baldes disponibles en el depósito para dicho sabor.
*/



//TIPOS
typedef char StringNombre[21];

typedef struct Sabor {
    StringNombre nombre;
    int gramos;
    int fila;
    int columna;
    TCola baldes;
    int baldesN;
    struct Sabor *sig;
} Sabor;

typedef Sabor* Sabores;

typedef struct BaldeDesechado{
    StringFecha fecha;
    StringNombre nombre;
    int fila;
    int columna;
    struct BaldeDesechado *sig;
} BaldeDesechado;

typedef BaldeDesechado* BaldesDesechados;


typedef struct BaldeHeladera {
    StringNombre nombre;
    int gramos;
} MatrizSabores[20][20];




/*nombre del sabor, gramos expendidos, fila, columna, cantidad de baldes, y la secuencia de fechas de producción*/
/* LIMON 1200 0 4 3 20170330 20170410 */

Sabor* sabor_crea(StringNombre nombre, int gramos, int fila, int columna, int baldesN, StringFecha fechas[]) {
    Sabor* sabor = (Sabor*) malloc(sizeof(Sabor));
    TElementoC balde;
    int i;
    strcpy(sabor->nombre, nombre);
    sabor->gramos = gramos;
    sabor->fila = fila;
    sabor->columna = columna;
    sabor->baldesN = baldesN;
    iniciaC(&(sabor->baldes));
    for (i = 0; i < baldesN; i++) {
        strcpy(balde.fecha, fechas[i]);
        poneC(&(sabor->baldes), balde);
    }
    return sabor;
}

void inserta_sabor(Sabores *sabores, Sabor *sabor) {
    Sabor *actual;
    if (*sabores == NULL || strcmp(sabor->nombre, (*sabores)->nombre) < 0 ) {
        sabor->sig = *sabores;
        *sabores = sabor;
    } else {
        actual = *sabores;
        while (actual->sig && strcmp(sabor->nombre, actual->sig->nombre) > 0) {
            actual = actual->sig;
        }
        sabor->sig = actual->sig;
        actual->sig = sabor;
    }

}

void carga_sabores(char archivo[], Sabores *sabores) {
    Sabor* sabor;
    StringNombre nombre;
    int gramos, fila, columna, baldesN;
    int i;
    StringFecha fechas[COLA_MAX];
    FILE* f = fopen(archivo, "rt");

    if (f == NULL) {
        printf("Error al abrir el archivo.\n");
        printf("Error: %s\n", strerror(errno));
    } else {
        fscanf(f, "%s%d%d%d%d", nombre, &gramos, &fila, &columna, &baldesN);
        while (!feof(f)) {
            for (i = 0; i < baldesN; i++)
                fscanf(f, "%s", fechas[i]);
            sabor = sabor_crea(nombre, gramos, fila, columna, baldesN, fechas);
            inserta_sabor(sabores, sabor);
            fscanf(f, "%s%d%d%d%d", nombre, &gramos, &fila, &columna, &baldesN);
        }
        fclose(f);
    }
}

void muestra_sabores(Sabores sabores) {
    TElementoC balde;
    int i;
    while (sabores) {
        printf("%s %d %d %d %d", sabores->nombre, sabores->gramos, sabores->fila, sabores->columna, sabores->baldesN);
        for (i = 0; i < sabores->baldesN; i++) {
            sacaC(&(sabores->baldes), &balde);
            printf(" %s", balde.fecha);
            poneC(&(sabores->baldes), balde);
        }
        printf("\n");
        sabores = sabores->sig;
    }
}

void lista_circular_inserta(BaldesDesechados *lista, BaldeDesechado *nodo) {
    BaldeDesechado *tmp = *lista;
    if (*lista == NULL) {
        nodo->sig = nodo;
        *lista = nodo;
    } else {
        while (tmp->sig != *lista)
            tmp = tmp->sig;
        tmp->sig = nodo;
        nodo->sig = *lista;
        *lista = nodo;
    }
}

void proceso_semanal(Sabores sabores, StringFecha fecha, MatrizSabores mat, int *n, int *m, BaldesDesechados *baldesDesechados) {
    TElementoC balde;
    TCola baldesNuevo;
    BaldeDesechado *baldeDesechado;
    iniciaC(&baldesNuevo);
    while (sabores) {
        TCola baldes = sabores->baldes;
        *n = sabores->fila > *n ? sabores->fila : *n;
        *m = sabores->columna > *m ? sabores->columna : *m;
        strcpy(mat[sabores->fila][sabores->columna].nombre, sabores->nombre);
        mat[sabores->fila][sabores->columna].gramos = sabores->gramos;
        while(!vaciaC(baldes)) {
            sacaC(&baldes, &balde);
            if (strcmp(fecha, balde.fecha) >= 0) {
                poneC(&baldesNuevo, balde);
            } else {
                // Pone en la lista circular
                baldeDesechado = (BaldeDesechado*) malloc(sizeof(BaldeDesechado));
                strcpy(baldeDesechado->nombre, sabores->nombre);
                strcpy(baldeDesechado->fecha, balde.fecha);
                baldeDesechado->fila = sabores->fila;
                baldeDesechado->columna = sabores->columna;
                lista_circular_inserta(baldesDesechados, baldeDesechado);
            }
        }
        sabores->baldes = baldesNuevo;
        sabores = sabores->sig;
    }
}

void genera_estadistica(MatrizSabores mat, int ancho, int alto, StringNombre sabores[], int columna, int i, int gramosMax, int *suma, int *cuenta) {
    struct BaldeHeladera b;
    if (columna < ancho) {
        if (i < alto) {
            b = mat[i][columna];
            if (b.gramos > 0) {
                if (b.gramos > gramosMax){
                    gramosMax = b.gramos;
                    strcpy(sabores[columna], b.nombre);
                }
                *suma += b.gramos;
                (*cuenta)++;
            }
            i++;
        } else {
            i = 0;
            columna++;
            gramosMax = 0;
        }
        genera_estadistica(mat, ancho, alto, sabores, columna, i, gramosMax, suma, cuenta);
    }
}

void inicia_matriz(MatrizSabores mat, int ancho, int alto) {
    int i, j;
    for (i = 0; i < alto; i++) {
        for (j = 0; j < ancho; j++) {
            strcpy(mat[i][j].nombre, "");
            mat[i][j].gramos = 0;
        }
    }
}

void muestra_matriz(MatrizSabores mat, int ancho, int alto) {
    int i, j;
    printf("|");
    for (j = 0; j < ancho; j++) {
        printf("-----|");
    }
    for (i = 0; i < alto; i++) {
        printf("\n|");
        for (j = 0; j < ancho; j++) {
            if (mat[i][j].gramos == 0) {
                printf(" \\/  |");
            } else {
                printf("%.5s|", mat[i][j].nombre);
            }

        }
        printf("\n|");
        for (j = 0; j < ancho; j++) {
            if (mat[i][j].gramos == 0) {
                printf(" /\\  |");
            } else {
                printf("%.4d |", mat[i][j].gramos);
            }

        }

        printf("\n|");
        for (j = 0; j < ancho; j++) {
            printf("-----|");
        }
    }
    printf("\n");
}

void muestra_array(StringNombre arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf(" + [%.2d] %s\n", i, arr[i]);
    }
}

void muestra_lista_circ(BaldesDesechados b) {
    BaldeDesechado *pri = b;
    if (b != NULL) {
        printf("%s %.5s %d\n", b->fecha, b->nombre, b->fila);
        while (b->sig != pri) {
            printf("%s %.5s %d\n", b->fecha, b->nombre, b->fila);
            b = b->sig;
        }
    }

}

void elimina_baldes_fila(BaldesDesechados *b, int X, int *count) {
    BaldeDesechado *pri = *b, *tmp = *b, *prev = *b;
    if (tmp) {
        while (tmp->sig != pri) {

            if (tmp->fila == X) {
                if (tmp == *b) {
                    *b = tmp->sig;
                } else {
                    prev->sig = tmp->sig;
                }
                free(tmp);
                (*count)++;
            } else {
                prev = tmp;
            }
            tmp = tmp->sig;
        }
        tmp->sig = *b;
    }

}

int main() {
    Sabores sabores = NULL;
    BaldesDesechados baldesDesechados = NULL;
    MatrizSabores mat;
    int n, m;
    StringFecha fecha = "20170210";
    float prom;
    StringNombre saboresMasConsumidos[20];
    int suma = 0, cuenta = 0;


    carga_sabores("HELADERA.txt", &sabores);
    printf("ARCHIVO CARGADO: \n");
    muestra_sabores(sabores);
    printf("\n\n");
    inicia_matriz(mat, 20, 20);
    proceso_semanal(sabores, fecha, mat, &n, &m, &baldesDesechados);

    printf("Baldes que quedaron despues del proceso semanal:");
    muestra_lista_circ(baldesDesechados);

    printf("\n\n");
    printf("Heladera\n ANCHO: %d\n ALTO:%d\n\n", m, n);
    muestra_matriz(mat, m, n);

    genera_estadistica(mat, m, n, saboresMasConsumidos, 0, 0, 0, &suma, &cuenta);

    printf("SABORES mas consumidos: \n");
    muestra_array(saboresMasConsumidos, m);

    if (cuenta != 0) {
        prom = suma/cuenta;
        printf("Promedio %.2f\n", prom);
    } else {
        printf("No hay ningun balde en la heladera.\n");
    }
    cuenta = 0;
    elimina_baldes_fila(&baldesDesechados, 10, &cuenta);

    printf("Baldes que quedaron despues de borrar por fila: (Fila 10)\n");
    muestra_lista_circ(baldesDesechados);

    printf("Baldes eliminados: %d", cuenta);
    return 0;
}
