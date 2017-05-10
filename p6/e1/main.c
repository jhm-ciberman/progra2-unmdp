// Queremos que los tests se muestren :)


#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"


/*
|------------------------------------------------------------------
|  GUIA 6 - Ejercicio 1
|------------------------------------------------------------------
| Generar una lista simplemente enlazada con el contenido de un arreglo de N enteros
| desordenados:
| a) invirtiendo el orden de sus elementos (no recorrer el arreglo comenzando por el último
| elemento)
| ESTA EN Listas.c > _test_invierte_debe_invertir_una_lista();
| b) manteniendo el orden de sus elementos.
| ESTA EN Listas.c > _test_crea_desde_array_debe_devolver_una_lista_con_los_valores_del_array_pasado();
| c) de forma ordenada
| NO LO HICE (pero el simplemente ir buscando el menor del array en cada iteración, o aplicar un quick sort al array y despues copiarlo a la lista)
*/

int main()
{
    printf("Iniciando tests..\n");
    lista_tests();
    printf("Todos los tests pasaron\n");
    /*
    int arr[] = {10, 15, 4, 18, 43, 2, 16};

    //TODO: preguntar si se puede hacer esto para obtener
    // la cantidad de elementos de un array:
    int n = sizeof(arr)/sizeof(int);
    printf("Longitud del array: %d\n", n);

    Lista lista = lista_crea();
    lista_pone_array(&lista, arr, 7);


    lista_destruye(&lista);
    */


    printf("Hello world!\n");
    return 0;
}
