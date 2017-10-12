// JAVIER MORA - pila.h
#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

typedef char TStringDNI[9];

typedef struct {
    TStringDNI dni;
    float promedio;
} TElementoP;

typedef struct TPila {
    TElementoP datos[50];
    int tope;
} TPila;

void iniciaP(TPila * pPila);
void poneP(TPila * pPila, TElementoP dato);
void sacaP(TPila * pPila, TElementoP * pDato);
TElementoP consultaP(TPila pila);
int vaciaP(TPila pila);

#endif // PILA_H_INCLUDED
