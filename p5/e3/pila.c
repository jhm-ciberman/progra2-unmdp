#include "pila.h"
#include <stdlib.h>
#include <assert.h>

void IniciaP(TPila* pila) {
    *pila = NULL;
}

void PoneP(TPila* pila, PilaDato dato){
    PilaNodo* pNodo = (PilaNodo*) malloc(sizeof(PilaNodo));
    pNodo->dato = dato;
    pNodo->siguiente = *pila;
    *pila = pNodo;
}

void SacaP(TPila* pila, PilaDato* dato) {
    if (pila != NULL) {
        PilaNodo* pSig = (*pila)->siguiente;
        *dato = (*pila)->dato;
        free(*pila);
        *pila = pSig;

    }

}

PilaDato ConsultaP(TPila pila) {
    return pila->dato;
}

int VaciaP(TPila pila) {
    return (pila == NULL);
}



