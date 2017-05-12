#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "pila.h"



/*
|----------------------------------------------------------------------
| PUNTO A
|----------------------------------------------------------------------
| Desarrollar un subprograma recursivo que elimine todos los datos de una pila que
| sean iguales a un valor recibido por parámetro. La pila debe mantener su orden original y el
| subprograma debe retornar la cantidad de elementos eliminados.
| => Implementar con TDA pila estática definiendo el tipo y desarrollando los operadores
| faltantes poneP y vaciaP del archivo provisto por la cátedra
|
*/
int eliminaTodosP(Pila* p, int x) {
    int tmp, d;

    if (!vaciaP(*p)) {
        sacaP(p, &tmp);
        d = eliminaTodosP(p, x) + (tmp == x);
        if (tmp != x)
            poneP(p, tmp);
        return d;
    }
    return 0;
}

void puntoA_test_debe_eliminar_todos_los_elementos_de_x() {
    int eliminados, datos[5];
    Pila p;
    iniciaP(&p);

    poneP(&p, -1);
    poneP(&p, 1);
    poneP(&p, 0);
    poneP(&p, -1);
    poneP(&p, 2);
    poneP(&p, 5);
    poneP(&p, -1);

    eliminados = eliminaTodosP(&p, -1);
    printf("%d", eliminados);
    assert(eliminados == 3);

    sacaP(&p, &datos[0]);
    sacaP(&p, &datos[1]);
    sacaP(&p, &datos[2]);
    sacaP(&p, &datos[3]);

    assert(datos[0] == 5);
    assert(datos[1] == 2);
    assert(datos[2] == 0);
    assert(datos[3] == 1);

    assert(vaciaP(p) == 1);

}
void puntoA_test_debe_devolver_cero_si_la_pila_esta_vacia() {
    int eliminados;
    Pila p;
    iniciaP(&p);
    assert(eliminaTodosP(&p, -1) == 0);
    assert(vaciaP(p) == 1);
}






int main()
{
    pila_tests();
    puntoA_test_debe_devolver_cero_si_la_pila_esta_vacia();
    puntoA_test_debe_eliminar_todos_los_elementos_de_x();

    printf("Hello world!\n");
    return 0;
}




