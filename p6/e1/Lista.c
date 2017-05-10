
#include "Lista.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/*
|---------------------------------------------------
| Implementacion
|---------------------------------------------------
*/

Lista lista_crea() {
    return NULL;
}
Lista lista_crea_desde_array(int datos[], int n) {
    Lista lista = NULL;
    int i;
    //int n = sizeof(datos)/sizeof(int);
    for(i = n - 1; i >= 0; i--)
        lista_prepone(&lista, datos[i]);
    return lista;
}
void lista_prepone(Lista* pLista, int dato) {
    Lista pNodo = (Lista) malloc(sizeof(ListaNodo));
    pNodo->dato = dato;
    pNodo->siguiente = *pLista;
    *pLista = pNodo;
}
int lista_saca(Lista* lista) {
    ListaNodo* pNodo = *lista;
    if (*lista != NULL) {
        ListaNodo* pNodoSig = pNodo->siguiente;
        int dato = pNodo->dato;
        free(pNodo);
        *lista = pNodoSig;
        return dato;
    }
    return 0;
}
void lista_destruye(Lista* pLista) {
    while (*pLista != NULL)
        lista_saca(pLista);
}
void lista_printf(FILE* file, Lista* lista, char* sep) {

}
void lista_invierte(Lista* lista) {

    ListaNodo* pNodo = *lista;
    ListaNodo* pNodoPrev = NULL;
    ListaNodo* pNodoSig = NULL;
    while(pNodo != NULL) {
        pNodoSig = pNodo->siguiente;
        pNodo->siguiente = pNodoPrev;
        pNodoPrev = pNodo;
        pNodo = pNodoSig;
    }
    *lista = pNodoPrev;
}

/*
|---------------------------------------------------
| TESTS
|---------------------------------------------------
*/


static void _test_crea_debe_devolver_NULL() {
    assert(lista_crea() == NULL);
}
static void _test_prepone_debe_agregar_un_elemento_en_una_lista() {
    Lista lista = lista_crea();
    lista_prepone(&lista, 5);
    lista_prepone(&lista, 6);
    assert(lista != NULL);
    assert(lista->dato == 6);
    assert(lista->siguiente != NULL);
    assert(lista->siguiente->dato == 5);
    assert(0);
    lista_destruye(&lista);
}
static void _test_crea_desde_array_debe_devolver_una_lista_con_los_valores_del_array_pasado() {
    int arr[] = {1, 2, 3, 4};
    Lista lista = lista_crea_desde_array(arr, 4);
    assert(lista->dato == 1);
    assert(lista->siguiente->dato == 2);
    assert(lista->siguiente->siguiente->dato == 3);
    assert(lista->siguiente->siguiente->siguiente->dato == 4);
    lista_destruye(&lista);
}
static void _test_invierte_debe_invertir_una_lista() {
    int arr[] = {1, 2, 3, 4};
    Lista lista = lista_crea_desde_array(arr, 4);
    lista_invierte(&lista);
    assert(lista->dato == 4);
    assert(lista->siguiente->dato == 3);
    assert(lista->siguiente->siguiente->dato == 2);
    assert(lista->siguiente->siguiente->siguiente->dato == 1);
    lista_destruye(&lista);
}
void lista_tests() {

    _test_crea_debe_devolver_NULL();
    _test_prepone_debe_agregar_un_elemento_en_una_lista();
    _test_crea_desde_array_debe_devolver_una_lista_con_los_valores_del_array_pasado();
    _test_invierte_debe_invertir_una_lista();
}


