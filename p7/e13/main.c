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

int arbol_cuenta_rango(Arbol arbol, int a, int b) {
    if (!arbol) return 0;
    if (b < a) return 0;

    if (arbol->dato <= a)
        return (arbol->der) ? arbol_cuenta_rango(arbol->der, a, b) : 0;

    if (arbol->dato >= b)
        return (arbol->izq) ? arbol_cuenta_rango(arbol->izq, a, b) : 0;

    return 1 + arbol_cuenta_rango(arbol->izq, a, b) + arbol_cuenta_rango(arbol->der, a, b);

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

    assert(arbol_cuenta_rango(b, 0, 10000) == 0); //Arbol vacio
    assert(arbol_cuenta_rango(a, 2, 0) == 0); // b < a

    assert(arbol_cuenta_rango(a, 7, 10) == 2); // 8, 9
    assert(arbol_cuenta_rango(a, 0, 10) == 6); // 1, 2, 3, 4, 8, 9
    assert(arbol_cuenta_rango(a, 1, 3) == 1); // 1



    printf("Todos los tests pasaron");

    return 0;
}
