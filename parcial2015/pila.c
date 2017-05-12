#include "pila.h"
#include <assert.h>

void iniciaP(Pila* pila) {
    pila->tope = -1;
}
void poneP(Pila* pila, PilaDato dato) {
    if (pila->tope < PILA_MAX_TOPE) {
        pila->datos[++pila->tope] = dato;
    }
}

void sacaP(Pila* pila, PilaDato* dato) {
    if (pila->tope >= 0) {
        *dato = pila->datos[pila->tope--];
    } else {
        *dato = 0; //Basura consistente
    }
}

PilaDato consultaP(Pila pila) {
    return pila.datos[pila.tope];
}

int vaciaP(Pila pila) {
    return (pila.tope < 0);
}

void pila_tests() {
    Pila p;
    iniciaP(&p);
    assert(vaciaP(p) == 1);

    poneP(&p, 1);
    poneP(&p, 2);
    poneP(&p, 3);

    int d1, d2, d3;

    assert(consultaP(p) == 3);
    sacaP(&p, &d1);
    assert(consultaP(p) == 2);
    sacaP(&p, &d2);
    assert(consultaP(p) == 1);
    sacaP(&p, &d3);

    assert(d1 == 3);
    assert(d2 == 2);
    assert(d3 == 1);
}
