#include "piladinamica.h"
#include <stdlib.h>
#include <assert.h>

/*
|------------------------------------------------------
| IMPLEMENTACION
|------------------------------------------------------
*/

void pilad_inicia(Pilad* pila) {
    *pila = NULL;
}

void pilad_pone(Pilad* pila, PiladDato dato){
    PiladNodo* pNodo = (PiladNodo*) malloc(sizeof(PiladNodo));
    pNodo->dato = dato;
    pNodo->siguiente = *pila;
    *pila = pNodo;
}

void pilad_saca(Pilad* pila, PiladDato* dato) {
    if (pila != NULL) {
        PiladNodo* pSig = (*pila)->siguiente;
        *dato = (*pila)->dato;
        free(*pila);
        *pila = pSig;

    }

}

PiladDato pilad_consulta(Pilad pila) {
    return pila->dato;
}

int pilad_vacia(Pilad pila) {
    return (pila == NULL);
}

/*
|------------------------------------------------------
| TESTS
|------------------------------------------------------
*/

static void _test_vacia_debe_indicar_si_la_pila_esta_vacia() {
    Pilad p;
    int d;
    pilad_inicia(&p);

    assert(pilad_vacia(p) == 1);
    pilad_pone(&p, 10);
    assert(pilad_vacia(p) == 0);
    pilad_saca(&p, &d);
    assert(pilad_vacia(p) == 1);

}

static void _test_pone_y_saca_deben_permitir_poner_y_sacar_elementos_de_la_pila() {
    Pilad p;
    int d1, d2, d3;
    pilad_inicia(&p);

    pilad_pone(&p, 10);
    pilad_pone(&p, 11);
    pilad_pone(&p, 12);

    pilad_saca(&p, &d1);
    pilad_saca(&p, &d2);
    pilad_saca(&p, &d3);
    assert(d1 == 12);
    assert(d2 == 11);
    assert(d3 == 10);
    assert(pilad_vacia(p) == 1);
}

static void _test_consulta_debe_permitir_consultar_un_elemento_sin_sacarlo() {

    Pilad p;
    int d;
    pilad_inicia(&p);

    pilad_pone(&p, 10);
    pilad_pone(&p, 12);
    assert(pilad_consulta(p) == 12);
    pilad_saca(&p, &d);
    assert(d == 12);
    pilad_saca(&p, &d);
    assert(d == 10);
}


void pilad_tests() {
    _test_vacia_debe_indicar_si_la_pila_esta_vacia();
    _test_pone_y_saca_deben_permitir_poner_y_sacar_elementos_de_la_pila();
    _test_consulta_debe_permitir_consultar_un_elemento_sin_sacarlo();
}


