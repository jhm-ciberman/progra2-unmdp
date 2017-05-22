#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))

/**
8. El draw de un torneo de tenis se representa mediante un árbol binario invertido. Desarrollar
subprogramas que muestren:
a) el nombre del ganador.
b) los nombres de los 2 finalistas.
c) los nombres de los 4 semifinalistas.
d) los nombres de todos los competidores y la cantidad.
*/


typedef char ArbolDato[50];

typedef struct ArbolNodo {
    ArbolDato dato;
    struct ArbolNodo* izq;
    struct ArbolNodo* der;
} ArbolNodo;

typedef ArbolNodo* Arbol;

ArbolNodo* nodo_crea(ArbolDato x) {
    ArbolNodo *nodoNuevo = (ArbolNodo*) malloc (sizeof (struct ArbolNodo));
    strcpy(nodoNuevo->dato, x);
    nodoNuevo->der = NULL;
    nodoNuevo->izq = NULL;
    return nodoNuevo;
}

void torneo_ganador(Arbol arbol, ArbolDato* ganador) {
    strcpy(*ganador, arbol->dato);
}
void torneo_finalistas(Arbol arbol, ArbolDato array[]) {
    strcpy(array[0], arbol->izq->dato);
    strcpy(array[1], arbol->der->dato);
}
void torneo_semifinalistas(Arbol arbol, ArbolDato array[]) {
    strcpy(array[0], arbol->izq->izq->dato);
    strcpy(array[1], arbol->izq->der->dato);
    strcpy(array[2], arbol->der->izq->dato);
    strcpy(array[3], arbol->der->der->dato);
}

void torneo_jugadores(Arbol arbol, ArbolDato array[], int* n) {
    if (arbol) {
        if (arbol->izq) {
            torneo_jugadores(arbol->izq, array, n);
            if(arbol->der) {
                torneo_jugadores(arbol->der, array, n);
            }
        } else if(arbol->der) {
            torneo_jugadores(arbol->der, array, n);
        } else {
            strcpy(array[(*n)++], arbol->dato);
        }
    }
}

int main()
{
    Arbol a = NULL;

    /*
    -> Pablo (ganó)
        +-> (izq) Elena
        |   +-> (izq) Jorge
        |   |   + (izq) Jorge
        |   |   \ (der) Damian
        |   \-> (der) Elena (ganó)
        |       + (izq) George Bush
        |       \ (der) Elena
        \-> (der) Pablo (ganó)
            +-> (izq) Pablo (ganó)
            |   + (izq) Rigoberto
            |   \ (der) Pablo
            \-> (der) Anastasio
                + (izq) Anastasio
                \ (der) Anacleto
    */
    a = nodo_crea("Pablo");
    a->izq = nodo_crea("Elena");
    a->izq->izq = nodo_crea("Jorge");
    a->izq->izq->izq = nodo_crea("Jorge");
    a->izq->izq->der = nodo_crea("Damian");
    a->izq->der = nodo_crea("Elena");
    a->izq->der->izq = nodo_crea("George Bush");
    a->izq->der->der = nodo_crea("Elena");
    a->der = nodo_crea("Pablo");
    a->der->izq = nodo_crea("Pablo");
    a->der->izq->izq = nodo_crea("Rigoberto");
    a->der->izq->der = nodo_crea("Pablo");
    a->der->der = nodo_crea("Anastasio");
    a->der->der->izq = nodo_crea("Anastasio");
    a->der->der->der = nodo_crea("Anacleto");

    // Tests
    ArbolDato ganador, finalistas[2], semifinalistas[4], jugadores[10];
    int n = 0;

    torneo_ganador(a, &ganador);
    assert(strcmp(ganador, "Pablo") == 0);

    torneo_finalistas(a, finalistas);
    assert(strcmp(finalistas[0], "Elena") == 0);
    assert(strcmp(finalistas[1], "Pablo") == 0);

    torneo_semifinalistas(a, semifinalistas);
    assert(strcmp(semifinalistas[0], "Jorge") == 0);
    assert(strcmp(semifinalistas[1], "Elena") == 0);
    assert(strcmp(semifinalistas[2], "Pablo") == 0);
    assert(strcmp(semifinalistas[3], "Anastasio") == 0);


    torneo_jugadores(a, jugadores, &n);
    assert(n == 8);
    assert(strcmp(jugadores[0], "Jorge") == 0);
    assert(strcmp(jugadores[1], "Damian") == 0);
    assert(strcmp(jugadores[2], "George Bush") == 0);
    assert(strcmp(jugadores[3], "Elena") == 0);
    assert(strcmp(jugadores[4], "Rigoberto") == 0);
    assert(strcmp(jugadores[5], "Pablo") == 0);
    assert(strcmp(jugadores[6], "Anastasio") == 0);
    assert(strcmp(jugadores[7], "Anacleto") == 0);

    printf("Todos los tests pasaron");

    return 0;
}
