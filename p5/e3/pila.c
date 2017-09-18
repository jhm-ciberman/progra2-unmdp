#include "pila.h"
#include <stdlib.h>
#include <assert.h>

void iniciaP(TPila* pila) {
    *pila = NULL;
}

void poneP(TPila* pila, PilaDato dato){
    PilaNodo* pNodo = (PilaNodo*) malloc(sizeof(PilaNodo));
    pNodo->dato = dato;
    pNodo->siguiente = *pila;
    *pila = pNodo;
}

void sacaP(TPila* pila, PilaDato* dato) {
    if (pila != NULL) {
        PilaNodo* pSig = (*pila)->siguiente;
        *dato = (*pila)->dato;
        free(*pila);
        *pila = pSig;

    }

}

PilaDato consultaP(TPila pila) {
    return pila->dato;
}

int vaciaP(TPila pila) {
    return (pila == NULL);
}



