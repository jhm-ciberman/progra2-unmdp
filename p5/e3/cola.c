#include "cola.h"
#include <stdlib.h>
#include <assert.h>

/*
|------------------------------------------------------
| IMPLEMENTACION
|------------------------------------------------------
*/

void colad_inicia(TCola* cola) {
    cola->primero = NULL;
    cola->ultimo = NULL;
}

void colad_pone(TCola* cola, ColaDato dato){
    ColaNodo* pNodo = (ColaNodo*) malloc(sizeof(ColaNodo));
    pNodo->dato = dato;
    pNodo->siguiente = NULL;

    if (cola->primero == NULL)
        cola->primero = pNodo;
    else
        cola->ultimo->siguiente = pNodo;

    cola->ultimo = pNodo;

}

void colad_saca(TCola* cola, ColaDato* dato) {
    ColaNodo* pNodo = cola->primero;
    if (pNodo != NULL) {
        *dato = pNodo->dato;
        cola->primero = pNodo->siguiente;
        free(pNodo);
    }

}

ColaDato colad_consulta(TCola cola) {
    return cola.primero->dato;
}

int colad_vacia(TCola cola) {
    return (cola.primero == NULL);
}
