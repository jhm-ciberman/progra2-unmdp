#include "pilaestatica.h"
#include <assert.h>

/*
|------------------------------------------------------
| IMPLEMENTACION
|------------------------------------------------------
*/

void pilae_inicia(Pilae* pila) {
    pila->elementos = 0;
}

void pilae_pone(Pilae* pila, PilaeDato dato){
    if (pila->elementos <= PILAE_MAX)
        pila->datos[pila->elementos++] = dato;
}

void pilae_saca(Pilae* pila, PilaeDato* dato) {
    if (pila->elementos != 0)
        *dato = pila->datos[--pila->elementos];

}

PilaeDato pilae_consulta(Pilae pila) {
    return pila.datos[pila.elementos - 1];
}

int pilae_vacia(Pilae pila) {
    return (pila.elementos == 0);
}

/*
|------------------------------------------------------
| TESTS
|------------------------------------------------------
*/

static void _test_vacia_debe_indicar_si_la_pila_esta_vacia() {
    Pilae p;
    int d;
    pilae_inicia(&p);

    assert(pilae_vacia(p) == 1);
    pilae_pone(&p, 10);
    assert(pilae_vacia(p) == 0);
    pilae_saca(&p, &d);
    assert(pilae_vacia(p) == 1);

}

static void _test_pone_y_saca_deben_permitir_poner_y_sacar_elementos_de_la_pila() {
    Pilae p;
    int d1, d2, d3;
    pilae_inicia(&p);

    pilae_pone(&p, 10);
    pilae_pone(&p, 11);
    pilae_pone(&p, 12);

    pilae_saca(&p, &d1);
    pilae_saca(&p, &d2);
    pilae_saca(&p, &d3);
    assert(d1 == 12);
    assert(d2 == 11);
    assert(d3 == 10);
    assert(pilae_vacia(p) == 1);
}

static void _test_consulta_debe_permitir_consultar_un_elemento_sin_sacarlo() {

    Pilae p;
    int d;
    pilae_inicia(&p);

    pilae_pone(&p, 10);
    pilae_pone(&p, 12);
    assert(pilae_consulta(p) == 12);
    pilae_saca(&p, &d);
    assert(d == 12);
    pilae_saca(&p, &d);
    assert(d == 10);
}


void pilae_tests() {
    _test_vacia_debe_indicar_si_la_pila_esta_vacia();
    _test_pone_y_saca_deben_permitir_poner_y_sacar_elementos_de_la_pila();
    _test_consulta_debe_permitir_consultar_un_elemento_sin_sacarlo();
}
