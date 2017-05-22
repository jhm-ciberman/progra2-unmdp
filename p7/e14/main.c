#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

/**
14. Generar un arreglo de caracteres con el contenido de las claves de un ABB. Los elementos del
arreglo deben quedar ordenados descendentemente.
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

void arbol_datos(Arbol arbol, char array[], int* n) {
    if (arbol) {
        arbol_datos(arbol->der, array, n);
        array[(*n)++] = arbol->dato;
        arbol_datos(arbol->izq, array, n);
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
    arbol_datos(a, arr, &n);
    assert(n == 11);
    arr[n] = '\0';
    assert(strcmp(arr, "ZYWTSRPHGFB") == 0);

    n = 0;
    arbol_datos(b, arr, &n);
    assert(n == 0);

    printf("Todos los tests pasaron");

    return 0;
}
