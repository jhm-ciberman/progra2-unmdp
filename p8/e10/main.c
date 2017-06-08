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
int arr_busca(Arreglo arr, int n, int x) {
    int i;
    for (i = 0; i < n; i++) {
        if (arr[i] == x)
            return i;
    }
    return -1;
}
void arr_muestra(Arreglo arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int arr_eq(Arreglo esperado, Arreglo actual, int n) {
    int i;
    for (i = 0; i < n; i++) {
        if (esperado[i] != actual[i]) {
            return 0;
        }
    }
    return 1;
}

/// PUNTO A:
void _grafo_profundidad_rec(Matriz mat, Arreglo recorrido, Arreglo visitados, int vertice, int *i, int cc, int n) {
    int ady;
    recorrido[(*i)++] = vertice;
    visitados[vertice] = cc;
    ady = 0;
    while (*i < n && ady < n) {
        if (!visitados[ady] && mat[vertice][ady]) {
            _grafo_profundidad_rec(mat, recorrido, visitados, ady, i, cc, n);
        }
        ady++;
    }
}

void grafo_profundidad_rec(Matriz mat, Arreglo recorrido, Arreglo visitados, int vertice, int n) {
    int i, ncc = 0;
    for (i = 0; i < n; i++) {
        recorrido[i] = 0;
        visitados[i] = 0;
    }
    i = 0;
    do {
        ncc++;
        _grafo_profundidad_rec(mat, recorrido, visitados, vertice, &i, ncc, n);
        vertice = arr_busca(visitados, n, 0);
    } while (vertice != -1);
}


/// PUNTO A iterativo:
void grafo_profundidad(Matriz mat, Arreglo recorrido, Arreglo visitados, int vertice, int n) {
    int i, ady, ncc = 0;
    for (i = 0; i < n; i++) {
        recorrido[i] = 0;
        visitados[i] = 0;
    }
    i = 0;
    Pila pila;
    pila_inicia(&pila);

    while (vertice!= -1 && i < n) {
        ncc++;
        pila_pone(&pila, vertice);
        while (!pila_vacia(pila)) {
            pila_saca(&pila, &vertice);
            if (!visitados[vertice]) {
                visitados[vertice] = ncc;
                recorrido[i++] = vertice;
                for (ady = n - 1; ady >= 0 ; ady--) { //Reverse
                    if (mat[vertice][ady]) {
                        pila_pone(&pila, ady);
                    }
                }
            }
        }
        vertice = arr_busca(visitados, n, 0);
    }

}

/// PUNTO B iterativo:
void grafo_anchura(Matriz mat, Arreglo recorrido, Arreglo visitados, int vertice, int n) {
    int i, ady, ncc = 0;
    for (i = 0; i < n; i++) {
        recorrido[i] = 0;
        visitados[i] = 0;
    }
    i = 0;
    Cola cola;
    cola_inicia(&cola);

    while (vertice!= -1 && i < n) {
        ncc++;
        cola_pone(&cola, vertice);
        while (!cola_vacia(cola)) {
            cola_saca(&cola, &vertice);
            if (!visitados[vertice]) {
                visitados[vertice] = ncc;
                recorrido[i++] = vertice;
                for (ady = 0; ady < n; ady++) { //Reverse
                    if (mat[vertice][ady]) {
                        cola_pone(&cola, ady);
                    }
                }
            }
        }
        vertice = arr_busca(visitados, n, 0);
    }

}




void test_punto_A_rec(Matriz grafo_mat, Matriz grafo_no_conexo_mat, int n) {
    // TEST 1:
    // Debe funcionar empezando del primer vertice
    Arreglo rec1, vcc1, rec1_esp = {0,1,2,3,4,5,6}, vcc1_esp  = {1,1,1,1,1,1,1};
    grafo_profundidad_rec(grafo_mat, rec1, vcc1, 0, n);
    assert(arr_eq(rec1, rec1_esp, n));
    assert(arr_eq(vcc1, vcc1_esp, n));

    // TEST 2:
    // Debe funcionar empezando de un vertice cualquiera
    Arreglo rec2, vcc2, rec2_esp = {4,2,0,1,3,5,6}, vcc2_esp = {1,1,1,1,1,1,1};
    grafo_profundidad_rec(grafo_mat, rec2, vcc2, 4, n);
    assert(arr_eq(rec2, rec2_esp, n));
    assert(arr_eq(vcc2, vcc2_esp, n));

    // TEST 3:
    // Debe funcionar para componentes no conexas
    Arreglo rec3, vcc3, rec3_esp = {4,5,6,0,1,2,3}, vcc3_esp = {2,2,2,2,1,1,1};
    grafo_profundidad_rec(grafo_no_conexo_mat, rec3, vcc3, 4, n);
    assert(arr_eq(rec3, rec3_esp, n));
    assert(arr_eq(vcc3, vcc3_esp, n));
}

void test_punto_A(Matriz grafo_mat, Matriz grafo_no_conexo_mat, int n) {
    // TEST 1:
    // Debe funcionar empezando del primer vertice
    Arreglo rec1, vcc1, rec1_esp  = {0,1,2,3,4,5,6}, vcc1_esp  = {1,1,1,1,1,1,1};
    grafo_profundidad(grafo_mat, rec1, vcc1, 0, n);
    assert(arr_eq(rec1, rec1_esp, n));
    assert(arr_eq(vcc1, vcc1_esp, n));

    // TEST 2:
    // Debe funcionar empezando de un vertice cualquiera
    Arreglo rec2, vcc2, rec2_esp  = {4,2,0,1,3,5,6}, vcc2_esp  = {1,1,1,1,1,1,1};
    grafo_profundidad(grafo_mat, rec2, vcc2, 4, n);
    assert(arr_eq(rec2, rec2_esp, n));
    assert(arr_eq(vcc2, vcc2_esp, n));

    // TEST 3:
    // Debe funcionar para componentes no conexas
    Arreglo rec3, vcc3, rec3_esp = {4,5,6,0,1,2,3}, vcc3_esp = {2,2,2,2,1,1,1};
    grafo_profundidad(grafo_no_conexo_mat, rec3, vcc3, 4, n);
    assert(arr_eq(rec3, rec3_esp, n));
    assert(arr_eq(vcc3, vcc3_esp, n));
}

void test_punto_B(Matriz grafo_mat, Matriz grafo_no_conexo_mat, int n) {
    // TEST 1:
    // Debe funcionar empezando del primer vertice
    Arreglo rec1, vcc1, rec1_esp  = {0,1,2,3,4,5,6}, vcc1_esp  = {1,1,1,1,1,1,1};
    grafo_anchura(grafo_mat, rec1, vcc1, 0, n);
    assert(arr_eq(rec1, rec1_esp, n));
    assert(arr_eq(vcc1, vcc1_esp, n));

    // TEST 2:
    // Debe funcionar empezando de un vertice cualquiera
    Arreglo rec2, vcc2, rec2_esp  = {4,2,3,5,6,0,1}, vcc2_esp  = {1,1,1,1,1,1,1};
    grafo_anchura(grafo_mat, rec2, vcc2, 4, n);
    assert(arr_eq(rec2, rec2_esp, n));
    assert(arr_eq(vcc2, vcc2_esp, n));

    // TEST 3:
    // Debe funcionar para componentes no conexas
    Arreglo rec3, vcc3, rec3_esp =  {4,5,6,0,1,2,3}, vcc3_esp = {2,2,2,2,1,1,1};
    grafo_anchura(grafo_no_conexo_mat, rec3, vcc3, 4, n);
    assert(arr_eq(rec3, rec3_esp, n));
    assert(arr_eq(vcc3, vcc3_esp, n));
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
    test_punto_B(grafo_mat, grafo_no_conexo_mat, n);



    printf("Todos los tests pasaron!\n");
    return 0;
}
