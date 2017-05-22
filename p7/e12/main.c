#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


/**
12. Retornar el valor mínimo de un ABB.
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

int arbol_minimo(Arbol arbol) {
    return (arbol)
        ? (arbol->izq)
            ? arbol_minimo(arbol->izq)
            : arbol->dato
        : 0;
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

    assert(arbol_minimo(a) == 1);
    assert(arbol_minimo(b) == 0); //Arbol vacio

    printf("Todos los tests pasaron");

    return 0;
}
