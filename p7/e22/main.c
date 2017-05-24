#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

/**
22. Dado un árbol binario proveniente de la conversión de un árbol general, determinar el grado de
este último.


*/

typedef char ArbolDato;

typedef struct ArbolNodo {
    ArbolDato dato;
    struct ArbolNodo* izq;
    struct ArbolNodo* der;
} ArbolNodo;

typedef ArbolNodo* Arbol;

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
}

int arbol_grado(Arbol arbol) {
    int izq, der;
    if (arbol) {
        izq = arbol_grado(arbol->izq);
        der = arbol_grado(arbol->der) + 1;
        return (izq > der ? izq : der);
    }
    return 0;
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

    assert(arbol_grado(NULL) == 0);
    assert(arbol_grado(a) == 4);
    assert(arbol_grado(a->izq) == 2);

    printf("Todos los tests pasaron");

    return 0;
}
