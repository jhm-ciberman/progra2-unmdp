#include "colaestatica.h"
#include <assert.h>

/*
|------------------------------------------------------
| IMPLEMENTACION
|------------------------------------------------------
*/

void colae_inicia(Colae* cola) {
    cola->primero = -1;
    cola->ultimo = -1;
}

void colae_pone(Colae* cola, ColaeDato dato){
    if (cola->ultimo <= COLAE_MAX) {
        cola->datos[++(cola->ultimo)] = dato;
        if (cola->primero == -1)
            cola->primero = 0;
    }

}

void colae_saca(Colae* cola, ColaeDato* dato) {
    if (cola->primero != -1) {
        *dato = cola->datos[cola->primero++];
        if (cola->primero > cola->ultimo) {
            cola->primero = -1;
            cola->ultimo = -1;
        }
    }

}

ColaeDato colae_consulta(Colae cola) {
    if (cola.primero != -1)
        return cola.datos[cola.primero];
}

int colae_vacia(Colae cola) {
    return (cola.primero == -1);
}

/*
|------------------------------------------------------
| TESTS
|------------------------------------------------------
*/




static void _test_vacia_debe_indicar_si_la_pila_esta_vacia() {
    Colae c;
    int d;
    colae_inicia(&c);

    assert(colae_vacia(c) == 1);
    colae_pone(&c, 10);
    assert(colae_vacia(c) == 0);
    colae_saca(&c, &d);
    assert(colae_vacia(c) == 1);

}

static void _test_pone_y_saca_deben_permitir_poner_y_sacar_elementos() {
    Colae c;
    int d1, d2, d3;
    colae_inicia(&c);

    colae_pone(&c, 10);
    colae_pone(&c, 11);
    colae_pone(&c, 12);

    colae_saca(&c, &d1);
    colae_saca(&c, &d2);
    colae_saca(&c, &d3);
    assert(d1 == 10);
    assert(d2 == 11);
    assert(d3 == 12);
    assert(colae_vacia(c) == 1);
}

static void _test_consulta_debe_permitir_consultar_un_elemento_sin_sacarlo() {

    Colae c;
    int d;
    colae_inicia(&c);

    colae_pone(&c, 10);
    colae_pone(&c, 12);
    assert(colae_consulta(c) == 10);
    colae_saca(&c, &d);
    assert(d == 10);
    colae_saca(&c, &d);
    assert(d == 12);
}


void colae_tests() {
    _test_vacia_debe_indicar_si_la_pila_esta_vacia();
    _test_pone_y_saca_deben_permitir_poner_y_sacar_elementos();
    _test_consulta_debe_permitir_consultar_un_elemento_sin_sacarlo();
}
