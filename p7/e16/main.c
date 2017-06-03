#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

/**
16. Implementar una función iterativa que inserte un elemento en un ABB.
*/

typedef char ArbolDato;

typedef struct ArbolNodo {
    ArbolDato dato;
    struct ArbolNodo* izq;
    struct ArbolNodo* der;
} ArbolNodo;

typedef ArbolNodo* Arbol;

int arbol_es_abb(Arbol arbol) {
    if (arbol) {
        if (arbol->izq)
            if (arbol->izq->dato >= arbol->dato)
                return 0;
        if (arbol->der)
            if (arbol->der->dato <= arbol->dato)
                return 0;
        return arbol_es_abb(arbol->izq) && arbol_es_abb(arbol->der);

    }
    return 1;
}
/*
void arbol_inserta(Arbol *arbol, ArbolDato dato) {
    if (!*arbol) {
        *arbol = (Arbol) malloc(sizeof(ArbolNodo));
        (*arbol)->dato = dato;
        (*arbol)->izq = NULL;
        (*arbol)->der = NULL;
    } else if (dato < (*arbol)->dato) {
        arbol_inserta(&((*arbol)->izq), dato);
    } else if (dato > (*arbol)->dato) {
        arbol_inserta(&((*arbol)->der), dato);
    }
}*/
void arbol_inserta(Arbol *arbol, ArbolDato dato) {
    Arbol pNodo = *arbol;
    while (pNodo) {
        if (dato < pNodo->dato) {
            *pNodo = pNodo->izq;
        } else if (dato > pNodo->dato) {
            *pNodo = pNodo->der;
        }
    }
    *arbol = (Arbol) malloc(sizeof(ArbolNodo));
    (*arbol)->dato = dato;
    (*arbol)->izq = NULL;
    (*arbol)->der = NULL;
}
int main()
{
    Arbol a = NULL;

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


    assert(arbol_es_abb(a) == 1);
    assert(a->dato == 'P');

    printf("Todos los tests pasaron");

    return 0;
}
