#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


/**
Desarrollar funciones para:
c) devolver la suma de los elementos múltiplos de 3 de un árbol binario.
d) retornar la cantidad de hojas de un árbol binario.
e) informar si un valor recibido como parámetro se encuentra en un árbol binario.
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

int arbol_suma(Arbol arbol, int x) {
    return (arbol)
        ?(arbol->dato % x == 0) * arbol->dato + arbol_suma(arbol->izq, x) + arbol_suma(arbol->der, x)
        : 0;
}

int arbol_cuenta_hojas(Arbol arbol) {
    return (arbol) ?
        (arbol->izq || arbol->der)
            ? arbol_cuenta_hojas(arbol->izq) + arbol_cuenta_hojas(arbol->der)
            : 1
        : 0;
}

int arbol_busca(Arbol arbol, ArbolDato x) {
    return (arbol)
        ? (arbol->dato == x) || arbol_busca(arbol->izq, x) || arbol_busca(arbol->der, x)
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

    // Punto A:
    assert(arbol_suma(a, 3) == 12);
    assert(arbol_suma(a, 2) == 14);
    assert(arbol_suma(b, 3) == 0); // arbol b

    // Punto B:
    assert(arbol_cuenta_hojas(a) == 3);
    assert(arbol_cuenta_hojas(b) == 0);  // arbol b

    // Punto C:
    assert(arbol_busca(a, 4) == 1);
    assert(arbol_busca(a, 3) == 1);
    assert(arbol_busca(a, 32) == 0);
    assert(arbol_busca(b, 3) == 0);  // arbol b

    printf("Todos los tests pasaron");

    return 0;
}
