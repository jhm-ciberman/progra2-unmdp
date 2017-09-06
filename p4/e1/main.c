#include <stdio.h>
#include <stdlib.h>

typedef int TMatriz[20][20];

//////////// EL PUNTO D NO ESTA HECHO

/*
1. Recodificar en el lenguaje C los siguientes ejercicios de Programación I desarrollados en Pascal:
    a) Sea V un arreglo de enteros, se pide:
        I. Calcular e informar la suma de sus elementos.
        II. Mostrar sus elementos.
        III. Mostrar sus elementos en orden inverso.
    b) Sea A un arreglo de reales y un valor X real ingresado por teclado, se pide determinar en
    que posición se encuentra la primera ocurrencia de X o 0 en caso de no encontrarlo.
    Implementar:
        I. Considerando el arreglo desordenado, una búsqueda lineal recursiva.
        II. Para un arreglo ordenado en forma ascendente, una búsqueda binaria recursiva.
    c) Crear una función recursiva que busque el elemento mínimo de una matriz cuadrada.
    d) Desarrollar un procedimiento recursivo que devuelva en un arreglo los máximos de cada fila
    de una matriz de MxN.
    e) Dado dos arreglos de enteros A y B ordenados ascendentemente, mezcle ambos arreglos en
    otro C manteniendo el orden pero sin pasar los elementos repetidos.
*/


int puntoA_suma(int a[], unsigned int n) {
    return n > 0 ? a[n] + puntoA_suma(a, n-1) : a[n];
}
void puntoA_muestra(int a[], unsigned int n) {
    printf("%d", a[0]);
    if (--n > 0)
        puntoA_muestra(a + 1, n);

}
void puntoA_muestra_inv(int a[], unsigned int n) {
    if (--n > 0)
        puntoA_muestra_inv(a + 1, n);
    printf("%d", a[0]);
}

int puntoB_desordenado(float a[], float busca, int i, int n) {
    if (a[i] == busca)
        return i;
    else
        return puntoB_desordenado(a, busca, ++i, n);
}

int puntoB_ordenado(float a[], float busca, int left, int right) {
    /*
    1 - Set L to 0 and R to n − 1.
    2 - If L > R, the search terminates as unsuccessful.
    3 - Set m (the position of the middle element) to the floor (the largest previous integer) of (L + R)/2.
    4 - If Am < T, set L to m + 1 and go to step 2.
    5 - If Am > T, set R to m − 1 and go to step 2.
    6 - Now Am = T, the search is done; return m.
    */
    int mid;
    if (left > right) {
        return -1;
    } else {
        mid = (left + right)/2;
        if (a[mid] < busca) {
            return puntoB_ordenado(a, busca, mid + 1, right);
        } else if (a[mid] > busca) {
            return puntoB_ordenado(a, busca, left, mid - 1);
        } else {
            return mid;
        }
    }
}

int puntoC(TMatriz mat, int ancho, int alto, int x, int y) {
    int min;
    if (x >= ancho) {
        if (y >= alto) {
            return mat[ancho-1][alto-1];
        } else {
            min = puntoC(mat, ancho, alto, 0, y+1);
        }
    } else {
        min = puntoC(mat, ancho, alto, x+1, y);
    }
    return mat[y][x] < min ? mat[y][x] : min;
}

void puntoD(TMatriz mat, int ancho, int alto, int x, int y, int maximos[]) {
    if (x == 0) {
        maximos[y] = mat[y][x];
    } else {
        maximos[y] =  mat[y][x] > maximos[y] ? mat[y][x] : maximos[y];
    }
    if (++x >= ancho) {
        if (++y < alto) {
            puntoD(mat, ancho, alto, 0, y, maximos);
        }
    } else {
        puntoD(mat, ancho, alto, x, y, maximos);
    }

}



int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8}, n = 8;

    printf("Suma: \t\t%d\n", puntoA_suma(a, n));

    printf("Muestra: \t");
    puntoA_muestra(a, n);
    printf("\n");

    printf("Muestra Inv: \t");
    puntoA_muestra_inv(a, n);
    printf("\n");

    float b_desordenado[] = {9.46, 12.15, 18.24, 22.00, 4.32, 8.23, 25.99, 2.56};
    float b_ordenado[]    = {2.56, 4.32, 8.23, 9.46, 12.15, 18.24, 22.00, 25.99};
    float busca = 22.00;

    printf("Busca Linear: \t%d\n", puntoB_desordenado(b_desordenado, busca, 0, n));
    printf("Busca Binario: \t%d\n", puntoB_ordenado(b_ordenado, busca, 0, n - 1));

    TMatriz mat = {
        {0, 1, 2, 30, 4, 5},
        {6, 1, 20, 3, 4, 5},
        {0, 10, 2, -10, 4, 5},
        {0, 1, 2, 3, 4, 50},
    };
    int maximos[4];

    printf("Minimo matriz: \t%d\n", puntoC(mat, 6, 4, 0, 0));
    puntoD(mat, 6, 4, 0, 0, maximos);
    printf("Maximos matriz: \t%d %d %d %d\n", maximos[0], maximos[1], maximos[2], maximos[3]);
    printf("\n");



    printf("\nHello world!\n");
    return 0;
}
