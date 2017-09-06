#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "dupla.h"

/*
1 - Codificar un TDA para representar una "dupla". Una dupla es un conjunto ordenado de
tamaño fijo de 2 elementos. Para acotar la implementación se pide realizar una Dupla de dos
enteros (int). Con lo cual no será una Dupla genérica que pueda tener cualquier tipo de
elemento. Las operaciones que deberá soportar el TDA son:
    - crear(entero primero, entero segundo) retorna dupla.
    - primero(dupla d) retorna entero.
    - segundo(dupla d) retorna entero.
    - multiplicar(dupla d, entero múltiplo) retorna dupla. Genera una nueva dupla que es el
      resultado de multiplicar ambos elementos por el número múltiplo que se pasa como
      parámetro.
    - adicionar(dupla d, entero adición) retorna dupla. Genera una nueva dupla resultado de
    sumarle el parámetro adición a ambos elementos.
    - sumar(dupla a, dupla b) retorna dupla. Genera una nueva dupla resultado de la suma de
    las dos recibidas como parámetro.
    - restar(dupla a, dupla b) retorna dupla. Idem anterior, pero restando de a, los valores de
    la dupla b.
*/

int main()
{

    TDupla d, e;
    d = crear(1, 2);
    assert(primero(d) == 1);
    assert(segundo(d) == 2);

    e = multiplicar(d, 2);
    assert(primero(e) == 2);
    assert(segundo(e) == 4);

    e = adicionar(d, 5);
    assert(primero(e) == 6);
    assert(segundo(e) == 7);

    e = sumar(d, crear(10, 20));
    assert(primero(e) == 11);
    assert(segundo(e) == 22);

    e = restar(d, crear(10, 20));
    assert(primero(e) == -9);
    assert(segundo(e) == -18);

    printf("Todos los test pasaron.\n");
    return 0;
}
