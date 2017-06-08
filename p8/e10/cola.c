#include "cola.h"
#include <stdlib.h>
#include <assert.h>

/*
|------------------------------------------------------
| IMPLEMENTACION
|------------------------------------------------------
*/

void cola_inicia(Cola* cola) {
    cola->primero = NULL;
    cola->ultimo = NULL;
}

void cola_pone(Cola* cola, ColaDato dato){
    ColaNodo* pNodo = (ColaNodo*) malloc(sizeof(ColaNodo));
    pNodo->dato = dato;
    pNodo->siguiente = NULL;

    if (cola->primero == NULL)
        cola->primero = pNodo;
    else
        cola->ultimo->siguiente = pNodo;

    cola->ultimo = pNodo;

}

void cola_saca(Cola* cola, ColaDato* dato) {
    ColaNodo* pNodo = cola->primero;
    if (pNodo != NULL) {
        *dato = pNodo->dato;
        cola->primero = pNodo->siguiente;
        free(pNodo);
    }

}

ColaDato cola_consulta(Cola cola) {
    return cola.primero->dato;
}

int cola_vacia(Cola cola) {
    return (cola.primero == NULL);
}

/*
|------------------------------------------------------
| TESTS
|------------------------------------------------------
*/



static void _test_vacia_debe_indicar_si_la_pila_esta_vacia() {
    Cola c;
    int d;
    cola_inicia(&c);

    assert(cola_vacia(c) == 1);
    cola_pone(&c, 10);
    assert(cola_vacia(c) == 0);
    cola_saca(&c, &d);
    assert(cola_vacia(c) == 1);

}

static void _test_pone_y_saca_deben_permitir_poner_y_sacar_elementos() {
    Cola c;
    int d1, d2, d3;
    cola_inicia(&c);

    cola_pone(&c, 10);
    cola_pone(&c, 11);
    cola_pone(&c, 12);

    cola_saca(&c, &d1);
    cola_saca(&c, &d2);
    cola_saca(&c, &d3);
    assert(d1 == 10);
    assert(d2 == 11);
    assert(d3 == 12);
    assert(cola_vacia(c) == 1);
}

static void _test_consulta_debe_permitir_consultar_un_elemento_sin_sacarlo() {

    Cola c;
    int d;
    cola_inicia(&c);

    cola_pone(&c, 10);
    cola_pone(&c, 12);
    assert(cola_consulta(c) == 10);
    cola_saca(&c, &d);
    assert(d == 10);
    cola_saca(&c, &d);
    assert(d == 12);
}


void cola_tests() {
    _test_vacia_debe_indicar_si_la_pila_esta_vacia();
    _test_pone_y_saca_deben_permitir_poner_y_sacar_elementos();
    _test_consulta_debe_permitir_consultar_un_elemento_sin_sacarlo();
}
