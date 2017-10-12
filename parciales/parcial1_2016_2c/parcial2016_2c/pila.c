// JAVIER MORA - pila.c
#include "pila.h"


void iniciaP(TPila * pPila) {
    pPila->tope = -1;
}

void poneP(TPila * pPila, TElementoP dato){
    if (pPila->tope < 50) {
        pPila->datos[++(pPila->tope)] = dato;
    }
}

void sacaP(TPila * pPila, TElementoP * pDato){
    if (pPila->tope >= 0) {
        *pDato = pPila->datos[(pPila->tope)--];
    }
}

TElementoP consultaP(TPila pila){
    TElementoP basura;
    if (pila.tope >= 0) {
        return pila.datos[pila.tope];
    } else {
        return basura;
    }
}

int vaciaP(TPila pila){
    return (pila.tope == -1);
}
