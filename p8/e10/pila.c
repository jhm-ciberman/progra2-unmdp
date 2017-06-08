#include "pila.h"
#include <stdlib.h>
#include <assert.h>

/*
|------------------------------------------------------
| IMPLEMENTACION
|------------------------------------------------------
*/

void pila_inicia(Pila* pila) {
    *pila = NULL;
}

void pila_pone(Pila* pila, PilaDato dato){
    PilaNodo* pNodo = (PilaNodo*) malloc(sizeof(PilaNodo));
    pNodo->dato = dato;
    pNodo->siguiente = *pila;
    *pila = pNodo;
}

void pila_saca(Pila* pila, PilaDato* dato) {
    if (pila != NULL) {
        PilaNodo* pSig = (*pila)->siguiente;
        *dato = (*pila)->dato;
        free(*pila);
        *pila = pSig;

    }

}

PilaDato pila_consulta(Pila pila) {
    return pila->dato;
}

int pila_vacia(Pila pila) {
    return (pila == NULL);
}

/*
|------------------------------------------------------
| TESTS
|------------------------------------------------------
*/

static void _test_vacia_debe_indicar_si_la_pila_esta_vacia() {
    Pila p;
    int d;
    pila_inicia(&p);

    assert(pila_vacia(p) == 1);
    pila_pone(&p, 10);
    assert(pila_vacia(p) == 0);
    pila_saca(&p, &d);
    assert(pila_vacia(p) == 1);

}

static void _test_pone_y_saca_deben_permitir_poner_y_sacar_elementos_de_la_pila() {
    Pila p;
    int d1, d2, d3;
    pila_inicia(&p);

    pila_pone(&p, 10);
    pila_pone(&p, 11);
    pila_pone(&p, 12);

    pila_saca(&p, &d1);
    pila_saca(&p, &d2);
    pila_saca(&p, &d3);
    assert(d1 == 12);
    assert(d2 == 11);
    assert(d3 == 10);
    assert(pila_vacia(p) == 1);
}

static void _test_consulta_debe_permitir_consultar_un_elemento_sin_sacarlo() {

    Pila p;
    int d;
    pila_inicia(&p);

    pila_pone(&p, 10);
    pila_pone(&p, 12);
    assert(pila_consulta(p) == 12);
    pila_saca(&p, &d);
    assert(d == 12);
    pila_saca(&p, &d);
    assert(d == 10);
}


void pila_tests() {
    _test_vacia_debe_indicar_si_la_pila_esta_vacia();
    _test_pone_y_saca_deben_permitir_poner_y_sacar_elementos_de_la_pila();
    _test_consulta_debe_permitir_consultar_un_elemento_sin_sacarlo();
}

