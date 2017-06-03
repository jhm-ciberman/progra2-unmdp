#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*
4. Desarrollar un subprograma que reciba como parámetro una matriz de adyacencia que
representa un digrafo sin aristas ponderadas y retorne en la misma matriz el grafo subyacente.
*/

typedef int Matriz[4][4];

void digrafo_a_grafo(Matriz mat, int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < i; j++) {
            mat[i][j] = (mat[i][j] || mat[j][i]);
            mat[j][i] = mat[i][j];
        }
    }
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

int main()
{
    Matriz entrada = {
        {0, 1, 1, 0},
        {1, 1, 0, 0},
        {0, 0, 0, 1},
        {0, 1, 1, 0}
    };
    Matriz esperado = {
        {0, 1, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0}
    };

    digrafo_a_grafo(entrada, 4);
    //mostrar_matriz(entrada, 4);
    assert_matriz_igual(entrada, esperado, 4);
    //assert_matriz_igual(entrada, esperado, 4);

    printf("Hello world!\n");
    return 0;
}
