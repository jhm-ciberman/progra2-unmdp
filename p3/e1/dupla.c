#include "dupla.h"

TDupla crear(int primero, int segundo) {
    TDupla d;
    d.a = primero;
    d.b = segundo;
    return d;
}

int primero(TDupla d) {
    return d.a;
}

int segundo(TDupla d) {
    return d.b;
}

TDupla multiplicar(TDupla d, int multiplo) {
    return crear(d.a * multiplo, d.b * multiplo);
}

TDupla adicionar(TDupla d, int adicion) {
   return crear(d.a + adicion, d.b + adicion);
}

TDupla sumar(TDupla a, TDupla b) {
    return crear(a.a + b.a, a.b + b.b);
}

TDupla restar(TDupla a, TDupla b) {
    return crear(a.a - b.a, a.b - b.b);
}
