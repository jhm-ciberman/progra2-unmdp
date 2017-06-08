#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

typedef int PilaDato;

typedef struct PilaNodo{
    PilaDato dato;
    struct  PilaNodo* siguiente;
} PilaNodo;

typedef PilaNodo* Pila;

void pila_inicia(Pila* pila);
void pila_pone(Pila* pila, PilaDato dato);
void pila_saca(Pila* pila, PilaDato* dato);
PilaDato pila_consulta(Pila pila);
int pila_vacia(Pila pila);


void pila_tests();

#endif // PILADINAMICA_H_INCLUDED
