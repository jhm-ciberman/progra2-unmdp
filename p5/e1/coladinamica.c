#include "coladinamica.h"
#include <stdlib.h>
#include <assert.h>

/*
|------------------------------------------------------
| IMPLEMENTACION
|------------------------------------------------------
*/

void colad_inicia(Colad* cola) {
    cola->primero = NULL;
    cola->ultimo = NULL;
}

void colad_pone(Colad* cola, ColadDato dato){
    ColadNodo* pNodo = (ColadNodo*) malloc(sizeof(ColadNodo));
    pNodo->dato = dato;
    pNodo->siguiente = NULL;

    if (cola->primero == NULL)
        cola->primero = pNodo;
    else
        cola->ultimo->siguiente = pNodo;

    cola->ultimo = pNodo;

}

void colad_saca(Colad* cola, ColadDato* dato) {
    ColadNodo* pNodo = cola->primero;
    if (pNodo != NULL) {
        *dato = pNodo->dato;
        cola->primero = pNodo->siguiente;
        free(pNodo);
    }

}

ColadDato colad_consulta(Colad cola) {
    return cola.primero->dato;
}

int colad_vacia(Colad cola) {
    return (cola.primero == NULL);
}

/*
|------------------------------------------------------
| TESTS
|------------------------------------------------------
*/



static void _test_vacia_debe_indicar_si_la_pila_esta_vacia() {
    Colad c;
    int d;
    colad_inicia(&c);

    assert(colad_vacia(c) == 1);
    colad_pone(&c, 10);
    assert(colad_vacia(c) == 0);
    colad_saca(&c, &d);
    assert(colad_vacia(c) == 1);

}

static void _test_pone_y_saca_deben_permitir_poner_y_sacar_elementos() {
    Colad c;
    int d1, d2, d3;
    colad_inicia(&c);

    colad_pone(&c, 10);
    colad_pone(&c, 11);
    colad_pone(&c, 12);

    colad_saca(&c, &d1);
    colad_saca(&c, &d2);
    colad_saca(&c, &d3);
    assert(d1 == 10);
    assert(d2 == 11);
    assert(d3 == 12);
    assert(colad_vacia(c) == 1);
}

static void _test_consulta_debe_permitir_consultar_un_elemento_sin_sacarlo() {

    Colad c;
    int d;
    colad_inicia(&c);

    colad_pone(&c, 10);
    colad_pone(&c, 12);
    assert(colad_consulta(c) == 10);
    colad_saca(&c, &d);
    assert(d == 10);
    colad_saca(&c, &d);
    assert(d == 12);
}


void colad_tests() {
    _test_vacia_debe_indicar_si_la_pila_esta_vacia();
    _test_pone_y_saca_deben_permitir_poner_y_sacar_elementos();
    _test_consulta_debe_permitir_consultar_un_elemento_sin_sacarlo();
}
