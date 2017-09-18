#include "cola.h"
#include <stdlib.h>
#include <assert.h>

/*
|------------------------------------------------------
| IMPLEMENTACION
|------------------------------------------------------
*/

void iniciaC(TCola* cola) {
    cola->primero = NULL;
    cola->ultimo = NULL;
}

void poneC(TCola* cola, ColaDato dato){
    ColaNodo* pNodo = (ColaNodo*) malloc(sizeof(ColaNodo));
    pNodo->dato = dato;
    pNodo->siguiente = NULL;

    if (cola->primero == NULL)
        cola->primero = pNodo;
    else
        cola->ultimo->siguiente = pNodo;

    cola->ultimo = pNodo;

}

void sacaC(TCola* cola, ColaDato* dato) {
    ColaNodo* pNodo = cola->primero;
    if (pNodo != NULL) {
        *dato = pNodo->dato;
        cola->primero = pNodo->siguiente;
        free(pNodo);
    }

}

ColaDato consultaC(TCola cola) {
    return cola.primero->dato;
}

int vaciaC(TCola cola) {
    return (cola.primero == NULL);
}
