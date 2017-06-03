#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define NODOS_MAX (20)

typedef struct ListaNodo {
    int dato;
    struct ListaNodo* sig;
} ListaNodo;

typedef ListaNodo* Lista;

typedef struct GrafoNodo {
    Lista lista;
} GrafoNodo;

typedef GrafoNodo Grafo[NODOS_MAX];

typedef int Matriz[NODOS_MAX][NODOS_MAX];

/**
6. Resolver el ejercicio anterior suponiendo que el digrafo está almacenado en una lista de
adyacencia.
EJERCICIO ANTERIOR:
5. Dado un vértice determinado de un digrafo representado en una matriz de adyacencia,
implementar funciones que devuelvan:
a) su grado de entrada
b) su grado de salida
c) el grado de dicho vértice

*/



int digrafo_entrada(Grafo grafo, int numero, int n) {
    Lista lista;
    int i;
    int grado = 0;
    for (i = 0; i < n; i++) {
        lista = grafo[i].lista;
        while (lista) {
            grado += (lista->dato == numero);
            lista = lista->sig;
        }
    }
    return grado;
}

//arg n es mantenido para conservar la misma interfaz que en el ejercicio 5.
int digrafo_salida(Grafo grafo, int numero, int n) {
    Lista lista = grafo[numero].lista;
    int grado = 0;
    while (lista) {
        grado++;
        lista = lista->sig;
    }
    return grado;
}

int digrafo_bucle(Grafo grafo, int numero, int n) {
    Lista lista = grafo[numero].lista;
    int bucle = 0;
    while (lista && !bucle) {
        bucle = (lista->dato == numero);
        lista = lista->sig;
    }
    return bucle;
}

int digrafo_grado(Grafo grafo, int numero, int n) {

    return
        digrafo_entrada(grafo, numero, n)
        + digrafo_salida(grafo, numero, n)
        - digrafo_bucle(grafo, numero, n);
}


void matriz_a_digrafo(Matriz m, int ancho, int alto, Grafo grafo) {
    int i, j;
    for (i = 0; i < alto; i++) {
        grafo[i].lista = NULL;
        for (j = 0; j < ancho; j++) {
            if (m[i][j]) {
                ListaNodo* pNodo = (ListaNodo*) malloc(sizeof(ListaNodo));
                pNodo->sig = grafo[i].lista;
                pNodo->dato = j;
                grafo[i].lista = pNodo;
            }
        }
    }
}

int main()
{
    Matriz mat = {
        {0, 1, 1, 0},
        {1, 1, 0, 0},
        {0, 0, 0, 1},
        {0, 1, 1, 0}
    };
    Grafo g;
    matriz_a_digrafo(mat, 4, 4, g);

    assert(digrafo_entrada(g, 0, 4) == 1);
    assert(digrafo_entrada(g, 1, 4) == 3);
    assert(digrafo_entrada(g, 2, 4) == 2);
    assert(digrafo_entrada(g, 3, 4) == 1);


    assert(digrafo_salida(g, 0, 4) == 2);
    assert(digrafo_salida(g, 1, 4) == 2);
    assert(digrafo_salida(g, 2, 4) == 1);
    assert(digrafo_salida(g, 3, 4) == 2);


    assert(digrafo_grado(g, 0, 4) == 3);
    assert(digrafo_grado(g, 1, 4) == 4);
    assert(digrafo_grado(g, 2, 4) == 3);
    assert(digrafo_grado(g, 3, 4) == 3);


    printf("Todos los test pasaron!\n");
    return 0;
}
