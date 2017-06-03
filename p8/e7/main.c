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
7. Desarrollar una función que obtenga el grado de un vértice (dato) de un grafo almacenado en:
a) una matriz de adyacencia
b) una lista de adyacencia
c) media matriz (triángulo superior)
*/

int grafo_grado_mat(Matriz mat, int numero, int n) {
    int i;
    int suma = 0;
    for (i = 0; i < n; i++) {
        suma += (mat[numero][i] > 0);
    }
    return suma;
}

int grafo_grado_tri(Matriz mat, int numero, int n) {
    int i;
    int suma = 0;
    for (i = numero; i < n; i++) {
        suma += (mat[numero][i] > 0);
    }
    for (i = 0; i < numero; i++) {
        suma += (mat[i][numero] > 0);
    }
    return suma;
}

int digrafo_entrada_lista(Grafo grafo, int numero, int n) {
    Lista lista;
    int i;
    int grado_entrada = 0;
    for (i = 0; i < n; i++) {
        lista = grafo[i].lista;
        while (lista) {
            grado_entrada += (lista->dato == numero);
            lista = lista->sig;
        }
    }
    return grado_entrada;
}

//arg n es mantenido para conservar la misma interfaz que en el ejercicio 5.
int digrafo_salida_lista(Grafo grafo, int numero, int n) {
    Lista lista = grafo[numero].lista;
    int grado = 0;
    while (lista) {
        grado++;
        lista = lista->sig;
    }
    return grado;
}

int digrafo_bucle_lista(Grafo grafo, int numero, int n) {
    Lista lista = grafo[numero].lista;
    int bucle = 0;
    while (lista && !bucle) {
        bucle = (lista->dato == numero);
        lista = lista->sig;
    }
    return bucle;
}

int digrafo_grado_lista(Grafo grafo, int numero, int n) {

    return
        digrafo_entrada_lista(grafo, numero, n)
        + digrafo_salida_lista(grafo, numero, n)
        - digrafo_bucle_lista(grafo, numero, n);
}


void matriz_a_grafo(Matriz m, int n, Grafo grafo) {
    int i, j;
    for (i = 0; i < n; i++) {
        grafo[i].lista = NULL;
        for (j = 0; j <= i; j++) {
            if (m[i][j]) {
                ListaNodo* pNodo = (ListaNodo*) malloc(sizeof(ListaNodo));
                pNodo->sig = grafo[i].lista;
                pNodo->dato = j;
                grafo[i].lista = pNodo;
            }
        }
    }
}

int main() {
    Matriz grafo_mat = {
        {0, 1, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0}
    };

    assert(grafo_grado_mat(grafo_mat, 0, 4) == 2);
    assert(grafo_grado_mat(grafo_mat, 1, 4) == 3);
    assert(grafo_grado_mat(grafo_mat, 2, 4) == 2);
    assert(grafo_grado_mat(grafo_mat, 3, 4) == 2);

    // -----------------------

    Grafo grafo_lis;
    matriz_a_grafo(grafo_mat, 4, grafo_lis);

    assert(digrafo_grado_lista(grafo_lis, 0, 4) == 2);
    assert(digrafo_grado_lista(grafo_lis, 1, 4) == 3);
    assert(digrafo_grado_lista(grafo_lis, 2, 4) == 2);
    assert(digrafo_grado_lista(grafo_lis, 3, 4) == 2);

    // -----------------------

    Matriz grafo_tri = {
        {0, 1, 1, 0},
        {0, 1, 0, 1},
        {0, 0, 0, 1},
        {0, 0, 0, 0}
    };

    assert(grafo_grado_tri(grafo_tri, 0, 4) == 2);
    assert(grafo_grado_tri(grafo_tri, 1, 4) == 3);
    assert(grafo_grado_tri(grafo_tri, 2, 4) == 2);
    assert(grafo_grado_tri(grafo_tri, 3, 4) == 2);

    // -----------------------

    printf("Todos los tests pasaron!\n");
    return 0;
}

