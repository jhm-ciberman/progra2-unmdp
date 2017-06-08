#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "pila.h"
#include "cola.h"

#define NODOS_MAX (20)

typedef int Matriz[NODOS_MAX][NODOS_MAX];

typedef int Arreglo[NODOS_MAX];

/**
10. Para un grafo almacenado en una matriz de adyacencia, desarrollar funciones para:
a) mostrar todos sus vértices mediante recorrido en profundidad (PILA)
b) mostrar todos sus vértices mediante recorrido en amplitud (COLA)
c) devolver la cantidad de componentes conexas (PILA/cola vacia)

*/

/// PUNTO A:
void _grafo_profundidad_rec(Matriz mat, Arreglo recorrido, Arreglo visitados, int vertice, int *i, int n) {
    int ady;
    recorrido[(*i)++] = vertice;
    visitados[vertice] = 1;
    ady = 0;
    while (*i < n && ady < n) {
        if (!visitados[ady] && mat[vertice][ady]) {
            _grafo_profundidad_rec(mat, recorrido, visitados, ady, i, n);
        }
        ady++;
    }
}
void grafo_profundidad_rec(Matriz mat, Arreglo recorrido, Arreglo visitados, int vertice, int n) {
    int i, ady, compcon = 0;
    for (i = 0; i < n; i++) {
        recorrido[i] = 0;
        visitados[i] = 0;
    }
    i = 0;

    _grafo_profundidad_rec(mat, recorrido, visitados, vertice, &i, n);

}


/// PUNTO B:
void grafo_profundidad(Matriz mat, Arreglo recorrido, Arreglo visitados, int vertice, int n) {
    int i, ady;
    for (i = 0; i < n; i++) {
        recorrido[i] = 0;
        visitados[i] = 0;
    }
    i = 0;
    Pila pila;
    pila_inicia(&pila);
    pila_pone(&pila, vertice);

    while (!pila_vacia(pila)) {
        pila_saca(&pila, &vertice);
        if (!visitados[vertice]) {
            visitados[vertice] = 1;
            recorrido[i++] = vertice;
            for (ady = n - 1; ady >= 0 ; ady--) { //Reverse
                if (mat[vertice][ady]) {
                    pila_pone(&pila, ady);
                }
            }
        }
    }
}



void assert_arreglos_eq(Arreglo esperado, Arreglo actual, int n) {
    int i;
    for (i = 0; i < n; i++) {
        assert(esperado[i] == actual[i]);
    }
}

int test_punto_A_rec(Matriz grafo_mat, Matriz grafo_no_conexo_mat, int n) {
    // TEST 1:
    // Debe funcionar empezando del primer vertice
    Arreglo rec1, vcc1, rec1_esp = {0,1,2,3,4,5,6}, vcc1_esp  = {1,1,1,1,1,1,1};
    grafo_profundidad_rec(grafo_mat, rec1, vcc1, 0, n);
    assert_arreglos_eq(rec1, rec1_esp, n);
    assert_arreglos_eq(vcc1, vcc1_esp, n);

    // TEST 2:
    // Debe funcionar empezando de un vertice cualquiera
    Arreglo rec2, vcc2, rec2_esp = {4,2,0,1,3,5,6}, vcc2_esp = {1,1,1,1,1,1,1};
    grafo_profundidad_rec(grafo_mat, rec2, vcc2, 4, n);
    assert_arreglos_eq(rec2, rec2_esp, n);
    assert_arreglos_eq(vcc2, vcc2_esp, n);

    // TEST 3:
    // Debe funcionar para componentes no conexas
    /*Arreglo rec3, vcc3, rec3_esp = {4,5,6,0,1,2,3}, vcc3_esp = {1,1,1,2,2,2,2};
    grafo_profundidad_rec(grafo_no_conexo_mat, rec3, vcc3, 4, n);
    assert_arreglos_eq(rec3, rec3_esp, n);
    assert_arreglos_eq(vcc3, vcc3_esp, n);*/
}

int test_punto_A(Matriz grafo_mat, Matriz grafo_no_conexo_mat, int n) {
    // TEST 1:
    // Debe funcionar empezando del primer vertice
    Arreglo rec1, vcc1, rec1_esp  = {0,1,2,3,4,5,6}, vcc1_esp  = {1,1,1,1,1,1,1};
    grafo_profundidad(grafo_mat, rec1, vcc1, 0, n);
    assert_arreglos_eq(rec1, rec1_esp, n);
    assert_arreglos_eq(vcc1, vcc1_esp, n);

    // TEST 2:
    // Debe funcionar empezando de un vertice cualquiera
    Arreglo rec2, vcc2, rec2_esp  = {4,2,0,1,3,5,6}, vcc2_esp  = {1,1,1,1,1,1,1};
    grafo_profundidad(grafo_mat, rec2, vcc2, 4, n);
    assert_arreglos_eq(rec2, rec2_esp, n);
    assert_arreglos_eq(vcc2, vcc2_esp, n);
}

int main() {

    /* PUNTO A */

    int n = 7;
    // Referencia: grafo del punto 9.
    Matriz grafo_mat = {
        {0, 3, 1, 0, 0, 0, 0},
        {3, 0, 2, 4, 0, 0, 0},
        {1, 2, 0, 1, 3, 0, 0},
        {0, 4, 1, 0, 2, 0, 0},
        {0, 0, 3, 2, 0, 1, 4},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 4, 0, 0},
    };
    // Referencia: grafo del punto 9 pero sin la union {3,5} y {4,5}
    Matriz grafo_no_conexo_mat = {
        {0, 3, 1, 0, 0, 0, 0},
        {3, 0, 2, 4, 0, 0, 0},
        {1, 2, 0, 1, 0, 0, 0},
        {0, 4, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 4},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 4, 0, 0},
    };


    test_punto_A_rec(grafo_mat, grafo_no_conexo_mat, n);
    test_punto_A(grafo_mat, grafo_no_conexo_mat, n);



    printf("Todos los tests pasaron!\n");
    return 0;
}
