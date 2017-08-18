11. Desarrollar una macro que devuelva cada uno de los siguientes resultados:

a) Máximo de 2 números 
b) Caracter es alfabético
Implementar un programa que utilice las macros desarrolladas. 


```c
#include <stdio.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
#define es_alfa(c) (((c) >= 'A' && (c) <= 'Z') || ((c) >= 'a' && (c) <= 'z'))
int main() {
  printf("El maximo entre 2 y 3 es %d", max(2, 3));
  printf("El maximo entre 30 y -2 es %d", max(30, -2));


  printf("El caracter '5' %s es alfabetico", es_alfa('5') ? "" : "no");
  printf("El caracter 'F' %s es alfabetico", es_alfa('F') ? "" : "no");
  return 0;
}

```
