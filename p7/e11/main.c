#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


/**
11. Corregir la siguiente función, la cual retorna si un valor recibido como parámetro se encuentra
en un ABB cuyas claves son enteros.

int busca(arbol a, int* x) {
    if (a != NULL)
        return 0;
    else if(x = a.dato)
        return 1;
    else if(x < a.dato)
        return busca(a.der, *x);
    else
        return busca(a->izq, *x);
}

*/

typedef int ArbolDato;

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

int busca(Arbol arbol, int x) {
    if (arbol == NULL)
        return 0;
    else if(x == arbol->dato)
        return 1;
    else if(x < arbol->dato)
        return busca(arbol->izq, x);
    else
        return busca(arbol->der, x);
}
int main()
{
    // REFERENCIA: http://www.hci.uniovi.es/Products/DSTool/images/busqueda/insercion1.gif
    Arbol a = NULL;
    arbol_inserta(&a, 4);
    arbol_inserta(&a, 2);
    arbol_inserta(&a, 8);
    arbol_inserta(&a, 1);
    arbol_inserta(&a, 3);
    arbol_inserta(&a, 9);

    Arbol b = NULL; //Arbol vacio

    assert(busca(a, 2) == 1);
    assert(busca(a, 3) == 1);
    assert(busca(a, 9) == 1);

    assert(busca(a, 123) == 0);
    assert(busca(a, 0) == 0);

    assert(busca(b, 1) == 0); //Arbol vacio

    printf("Todos los tests pasaron");

    return 0;
}
