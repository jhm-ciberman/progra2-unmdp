#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

/**
5. Desarrollar funciones para:
a) calcular la profundidad de un árbol binario.
b) retornar la longitud de la cadena más larga de un árbol binario de cadenas.
c) devolver la cantidad de hijos derechos que contiene un árbol binario
*/

typedef int ArbolDato[50];

typedef struct ArbolNodo {
    ArbolDato dato;
    struct ArbolNodo* izq;
    struct ArbolNodo* der;
} ArbolNodo;

typedef ArbolNodo* Arbol;

void arbol_inserta(Arbol *arbol, ArbolDato x) {
    if (*arbol == NULL) {
        *arbol = (Arbol) malloc (sizeof (struct ArbolNodo));
        strcpy((*arbol)->dato, x);
        (*arbol)->der = NULL;
        (*arbol)->izq = NULL;
    } else if (strcmp(x, (*arbol)->dato) > 0) {
        arbol_inserta(&((*arbol)->der), x);
    } else {
        arbol_inserta(&((*arbol)->izq), x);
    }
}

int arbol_profundidad(Arbol arbol) {
    int a, b;
    if (!arbol) return 0;

    // Guardo en variables para prevenir la doble evaluación
    a = arbol_profundidad(arbol->izq);
    b = arbol_profundidad(arbol->der);
    return max(a, b) + 1;
}

int arbol_longitud_maxima(Arbol arbol) {
    int a, b, c, m;
    if (!arbol) return 0;
    a = arbol_longitud_maxima(arbol->izq);
    b = arbol_longitud_maxima(arbol->der);
    c = strlen(arbol->dato);
    m = max(a, b); // Prevenir doble evaluación
    return max(c, m);
}

int arbol_hijos_derechos(Arbol arbol) {
    return (!arbol) ? 0 : arbol_hijos_derechos(arbol->der) + arbol_hijos_derechos(arbol->izq) + (!!arbol->der);
}

int main()
{
    Arbol a = NULL;
    Arbol b = NULL; //Arbol vacio

    // REFERENCIA: https://www.programacion.com.py/wp-content/uploads/2013/04/a71.jpg
    arbol_inserta(&a, "P_aaaaa");
    arbol_inserta(&a, "F_aaaaaaaa");
    arbol_inserta(&a, "S_a");
    arbol_inserta(&a, "B_aaaaaa");
    arbol_inserta(&a, "H_a");
    arbol_inserta(&a, "R_a");
    arbol_inserta(&a, "Y_aaaaaaaaaaaaaaaaa");
    arbol_inserta(&a, "G_a");
    arbol_inserta(&a, "T_a");
    arbol_inserta(&a, "Z_a");
    arbol_inserta(&a, "W_a");

    assert(arbol_profundidad(a) == 5);
    assert(arbol_profundidad(b) == 0);

    assert(arbol_longitud_maxima(a) == strlen("Y_aaaaaaaaaaaaaaaaa"));
    assert(arbol_longitud_maxima(b) == 0);

    assert(arbol_hijos_derechos(a) == 5);
    assert(arbol_hijos_derechos(b) == 0);

    printf("Todos los tests pasaron");

    return 0;
}
