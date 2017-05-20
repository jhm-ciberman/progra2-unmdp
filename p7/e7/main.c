#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


/**
Desarrollar una función que retorne la suma del contenido de aquellos nodos de un árbol
binario que tengan grado 1 y se encuentren en un nivel X que es dato.
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

int arbol_suma_busqueda(Arbol arbol, int grado, int nivel) {
    if (!arbol || nivel < 1) return 0;
    if (nivel == 1 && (!!arbol->izq) + (!!arbol->der) == grado) {
        return arbol->dato + arbol_suma_busqueda(arbol, grado, nivel-1);
    }
    return arbol_suma_busqueda(arbol->izq, grado, nivel-1) + arbol_suma_busqueda(arbol->der, grado, nivel-1);
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

    // Punto A:
    assert(arbol_suma_busqueda(a, 0, 3) == 13);
    assert(arbol_suma_busqueda(a, 2, 2) == 2);
    assert(arbol_suma_busqueda(a, 1, 2) == 8);
    assert(arbol_suma_busqueda(b, 0, 1) == 0); // arbol b

    printf("Todos los tests pasaron");

    return 0;
}
