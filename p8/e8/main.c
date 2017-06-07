#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define NODOS_MAX (20)

typedef int Matriz[NODOS_MAX][NODOS_MAX];

typedef int Arreglo[NODOS_MAX];

/*
8. Desarrollar funciones recursivas para:
a) generar un arreglo con el grado de cada vértice de un grafo almacenado en una matriz de
adyacencia.
b) hallar el vértice con el mayor grado de entrada, en un digrafo representado por una matriz
de adyacencia.
c) determinar si todos los vértices de un grafo almacenado en media matriz de adyacencia
(triángulo superior) tienen al menos un vértice adyacente con costo mayor a X (dato).
d) generar un arreglo con el grado de cada vértice (siempre que sea mayor a 3) de un grafo
almacenado en una matriz de adyacencia.
*/

void grafo_grados_mat(Matriz mat, Arreglo grados, int vertice, int i, int n) {
    if (vertice < n) {
        if (i < n) {
            grafo_grados_mat(mat, grados, vertice, i + 1, n);
            grados[vertice] += (mat[vertice][i] > 0);
        } else {
            grafo_grados_mat(mat, grados, vertice + 1, 0, n);
        }
    }
}

void digrafo_mayor_grado_entrada(Matriz mat, int vertice, int i, int n, int cont, int *maxgr, int *maxvert) {
    if (vertice < n) {
        if (i < n) {
            cont += (mat[i][vertice] > 0);
            digrafo_mayor_grado_entrada(mat, vertice, i + 1, n, cont, maxgr, maxvert);
        } else {
            if (cont > *maxgr) {
                *maxgr = cont;
                *maxvert = vertice;
            }
            digrafo_mayor_grado_entrada(mat, vertice + 1, 0, n, 0, maxgr, maxvert);
        }
    }
}


void digrafo_costo_mayor(Matriz mat, int x, int vertice, int i, int n, int *cumple) {
    int peso;
    if (vertice < n) {
        if (i < n) {
            peso = (i < vertice ? mat[i][vertice] : mat[vertice][i]);
            *cumple = *cumple || (peso > x);
            digrafo_costo_mayor(mat, x, vertice, i + 1, n, cumple);
        } else if (*cumple) {
            *cumple = 0;
            digrafo_costo_mayor(mat, x, vertice + 1, 0, n, cumple);
        }
    } else {
        *cumple = 1;
    }
}

void grafo_grados_mayor_que_3_mat(Matriz mat, Arreglo grados, int vertice, int i, int n) {
    if (vertice < n) {
        if (i < n) {
            grados[vertice] += (mat[vertice][i] > 0);
            grafo_grados_mayor_que_3_mat(mat, grados, vertice, i + 1, n);
        } else {
            if (grados[vertice] <= 3)
                grados[vertice] = 0;
            grafo_grados_mayor_que_3_mat(mat, grados, vertice + 1, 0, n);


        }
    }
}


int main() {
    // -----------------------

    /* PUNTO A */

    Matriz grafo_mat = {
        {0, 1, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0}
    };

    Arreglo arr = {0,0,0,0};
    grafo_grados_mat(grafo_mat, arr, 0, 0, 4);

    assert(arr[0] == 2);
    assert(arr[1] == 3);
    assert(arr[2] == 2);
    assert(arr[3] == 2);

    // -----------------------

    /* PUNTO B */

    Matriz digrafo_mat = {
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 0},
        {1, 0, 1, 0, 1, 1},
        {0, 0, 1, 0, 1, 0},
        {0, 0, 0, 1, 1, 0},
        {0, 0, 0, 0, 1, 0},
    };
    int maxgr = -1, maxvert = -1;
    digrafo_mayor_grado_entrada(digrafo_mat, 0, 0, 6, 0, &maxgr, &maxvert);

    assert(maxvert == 4);
    assert(maxgr == 5);


    // -----------------------

    /* PUNTO C */

    Matriz grafo_peso_mat = {
        {8, 1, 0, 0, 0, 0},
        {0, 0, 5, 7, 4, 2},
        {0, 0, 0, 0, 3, 1},
        {0, 0, 0, 0, 6, 0},
        {0, 0, 0, 0, 0, 9},
        {0, 0, 0, 0, 0, 0},
    };
    int cumple;

    cumple = 0;
    digrafo_costo_mayor(grafo_peso_mat, 10, 0, 0, 6, &cumple);
    assert(cumple == 0);

    cumple = 0;
    digrafo_costo_mayor(grafo_peso_mat, 1, 0, 0, 6, &cumple);
    assert(cumple == 1);

    // -----------------------

    /* PUNTO D */

    Matriz grafo_punto_d_mat = {
        {1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 0, 0},
        {1, 1, 1, 0, 0, 0},
        {1, 0, 0, 0, 0, 0},
        {1, 1, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 0},
    };

    Arreglo arr2 = {0,0,0,0,0,0};
    grafo_grados_mayor_que_3_mat(grafo_punto_d_mat, arr2, 0, 0, 6);

    assert(arr2[0] == 6);
    assert(arr2[1] == 4);
    assert(arr2[2] == 0);
    assert(arr2[3] == 0);
    assert(arr2[4] == 0);
    assert(arr2[5] == 5);

    // -----------------------

    printf("Todos los tests pasaron!\n");
    return 0;
}


