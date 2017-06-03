#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int Matriz[4][4];

/**
5. Dado un vértice determinado de un digrafo representado en una matriz de adyacencia,
implementar funciones que devuelvan:
a) su grado de entrada
b) su grado de salida
c) el grado de dicho vértice
*/


int digrafo_entrada(Matriz mat, int numero, int n) {
    int i;
    int suma = 0;
    for (i = 0; i < n; i++) {
        suma += (mat[i][numero] > 0);
    }
    return suma;
}

int digrafo_salida(Matriz mat, int numero, int n) {
    int i;
    int suma = 0;
    for (i = 0; i < n; i++) {
        suma += (mat[numero][i] > 0);
    }
    return suma;
}

int digrafo_grado(Matriz mat, int numero, int n) {
    int i;
    int suma = 0;
    for (i = 0; i < n; i++) {
        suma += (mat[numero][i] > 0) + (mat[i][numero] > 0);
    }
    return suma - (mat[numero][numero] > 0);
}

void assert_matriz_igual(Matriz m1, Matriz m2, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            assert(m1[i][j] == m2[i][j]);
        }
    }
}

void mostrar_matriz(Matriz m,  int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Matriz mat = {
        {0, 1, 1, 0},
        {1, 1, 0, 0},
        {0, 0, 0, 1},
        {0, 1, 1, 0}
    };

    assert(digrafo_salida(mat, 0, 4) == 2);
    assert(digrafo_salida(mat, 1, 4) == 2);
    assert(digrafo_salida(mat, 2, 4) == 1);
    assert(digrafo_salida(mat, 3, 4) == 2);

    assert(digrafo_entrada(mat, 0, 4) == 1);
    assert(digrafo_entrada(mat, 1, 4) == 3);
    assert(digrafo_entrada(mat, 2, 4) == 2);
    assert(digrafo_entrada(mat, 3, 4) == 1);

    assert(digrafo_grado(mat, 0, 4) == 3);
    assert(digrafo_grado(mat, 1, 4) == 4);
    assert(digrafo_grado(mat, 2, 4) == 3);
    assert(digrafo_grado(mat, 3, 4) == 3);

    printf("Todos los tests pasaron!\n");
    return 0;
}
