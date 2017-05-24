#include <stdio.h>
#include <stdlib.h>

/*
2. Describir lo que imprime el siguiente fragmento de código:
*/
int main()
{
    int *p, a = 4, b = 5;
    p = &b;
    *p *= 2;
    printf("b=%d *p=%d\n", b, *p); // b=10 *p=10
    printf("&b=%p p=%p &p=%p\n", &b, p, &p); // &b=<DIRECCION_A> p=<DIRECCION_A> &p=<DIRECCION_B>
    b = *p *3;
    printf("b=%d *p=%d\n", b, *p); // b=30 *p=30
    printf("&b=%p p=%p\n", &b, p); // &b=<DIRECCION_A> p=<DIRECCION_A>
    a = b;
    p = &a;
    (*p)++;
    printf("b=%d a=%d *p=%d\n", b, a, *p); // b=30 a=31 *p=31
    printf("&b=%p &a=%p p=%p &p=%p\n", &b, &a, p, &p); // &b=<DIRECCCION_A> &a=<DIRECCION_C> p=<DIRECCION_C> &p=<DIRECCION_B>
    return 0;
}


