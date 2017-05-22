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

int main()
{
    Arbol a = NULL;
    Arbol b = NULL; //Arbol vacio

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


    assert(arbol_es_abb(b) == 1); //Arbol vacio ES un ABB
    assert(arbol_es_abb(a) == 1);

    a->der->dato = 'Z'; // Volver el arbol en un arbol que no es ABB
    assert(arbol_es_abb(a) == 0);


    printf("Todos los tests pasaron");

    return 0;
}
