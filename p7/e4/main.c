#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


/**
Corregir los errores en la siguiente función void, la cual genera un arreglo de caracteres con los
nodos de grado 2 de un árbol binario.

void arrgrado2(arbol a, char v[N], int dimv) {
    if (a != NULL) {
        if(a->izq != NULL && a->der == NULL) { // grado 2
            (*dimv)++;
            v[dimv] = a->dato;
        } else
        arrgrado2(a->izq, v[], dimv);
        arrgrado2(a->der, v[], dimv);

    }
}
*/

typedef char ArbolDato;

typedef struct ArbolNodo {
    ArbolDato dato;
    struct ArbolNodo* izq;
    struct ArbolNodo* der;
} ArbolNodo;

typedef ArbolNodo* Arbol;

void arbol_inserta(Arbol *arbol, ArbolDato x) {
    if (*arbol == NULL) {
        *arbol = (Arbol) malloc (sizeof (struct ArbolNodo));
        (*arbol)->dato = x;
        (*arbol)->der = NULL;
        (*arbol)->izq = NULL;
    } else if (x > (*arbol)->dato) {
        arbol_inserta(&((*arbol)->der), x);
    } else {
        arbol_inserta(&((*arbol)->izq), x);
    }
}

void arrgrado2(Arbol a, char v[], int* dimv) {
    if (a != NULL) {
        if(a->izq != NULL && a->der != NULL) { // grado 2
            v[(*dimv)++] = a->dato;
        }
        arrgrado2(a->izq, v, dimv);
        arrgrado2(a->der, v, dimv);
    }
}

int main()
{
    Arbol a = NULL;
    Arbol b = NULL; //Arbol vacio
    int n = 0;
    char arr[20];

    // REFERENCIA: https://www.programacion.com.py/wp-content/uploads/2013/04/a71.jpg
    arbol_inserta(&a, 'P');
    arbol_inserta(&a, 'F');
    arbol_inserta(&a, 'S');
    arbol_inserta(&a, 'B');
    arbol_inserta(&a, 'H');
    arbol_inserta(&a, 'R');
    arbol_inserta(&a, 'Y');
    arbol_inserta(&a, 'G');
    arbol_inserta(&a, 'T');
    arbol_inserta(&a, 'Z');
    arbol_inserta(&a, 'W');


    n = 0;
    arrgrado2(a, arr, &n);
    assert(n == 4);
    assert(arr[0] == 'P');
    assert(arr[1] == 'F');
    assert(arr[2] == 'S');
    assert(arr[3] == 'Y');

    n = 0;
    arrgrado2(b, arr, &n);
    assert(n == 0);

    printf("Todos los tests pasaron");

    return 0;
}
