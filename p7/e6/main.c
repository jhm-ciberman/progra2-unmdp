#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

/**
6. Dado un árbol binario de cadenas de caracteres retornar el nivel en el que se encuentra la
cadena más larga que comienza con A
*/

typedef char ArbolDato[50];

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

void arbol_busca_nivel(Arbol arbol, char letra, int *longitud, int *nivel) {
    int longitud2, nivel2;
    if (!arbol) {
        *longitud = 0;
    } else {
        longitud2 = 0;
        nivel2 = *nivel + 1;
        if (arbol->dato[0] == letra) {
            longitud2 = strlen(arbol->dato);
            if (longitud2 > *longitud) {
                *longitud = longitud2;
                *nivel = nivel2;
            }
        }
        arbol_busca_nivel(arbol->izq, letra, &longitud2, &nivel2);
        if (longitud2 > *longitud) {
            *longitud = longitud2;
            *nivel = nivel2;
        }
        arbol_busca_nivel(arbol->der, letra, &longitud2, &nivel2);
        if (longitud2 > *longitud) {
            *longitud = longitud2;
            *nivel = nivel2;
        }
    }
}

int main()
{
    Arbol a = NULL;
    Arbol b = NULL; //Arbol vacio

    // REFERENCIA: http://web.eecs.utk.edu/~bvz/teaching/cs140Sp16/Notes/Trees/BST-5.jpg
    arbol_inserta(&a, "Binky");
    arbol_inserta(&a, "Fred");
    arbol_inserta(&a, "Daisy");
    arbol_inserta(&a, "Luther");
    arbol_inserta(&a, "Calista");
    arbol_inserta(&a, "Luigi");
    arbol_inserta(&a, "Waluigi");

    int longitud, nivel;
    printf("TEST: Debe poder buscar en un arbol vacio\n");
    longitud = 0;
    nivel = 0;
    arbol_busca_nivel(b, 'B', &longitud, &nivel); //Arbol vacio
    assert(longitud == 0);
    assert(nivel == 0);

    printf("TEST: Debe poder buscar en un arbol que no tenga dos strings con la misma letra\n");
    longitud = 0;
    nivel = 0;
    arbol_busca_nivel(a, 'B', &longitud, &nivel);
    assert(longitud == 5);
    assert(nivel == 1);

    printf("TEST: Debe poder buscar en un arbol que tenga dos strings con la misma letra\n");
    longitud = 0;
    nivel = 0;
    arbol_busca_nivel(a, 'L', &longitud, &nivel);
    assert(longitud == 6);
    assert(nivel == 3);


    printf("Todos los tests pasaron\n");

    return 0;
}
