#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#define PILA_MAX_TOPE 99

typedef int PilaDato;

typedef struct Pila{
    PilaDato datos[PILA_MAX_TOPE + 1];
    int tope;
} Pila;

void iniciaP(Pila* pila);
void poneP(Pila* pila, PilaDato dato);
void sacaP(Pila* pila, PilaDato* dato);
PilaDato consultaP(Pila pila);
int vaciaP(Pila pila);
void pila_tests();
#endif // PILA_H_INCLUDED
