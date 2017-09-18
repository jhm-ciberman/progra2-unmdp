#ifndef PILADINAMICA_H_INCLUDED
#define PILADINAMICA_H_INCLUDED

typedef struct PilaDato {char str[20];} PilaDato;

typedef struct PilaNodo{
    PilaDato dato;
    struct  PilaNodo* siguiente;
} PilaNodo;

typedef PilaNodo* TPila;

void iniciaP(TPila* pila);
void poneP(TPila* pila, PilaDato dato);
void sacaP(TPila* pila, PilaDato* dato);
PilaDato consultaP(TPila pila);
int vaciaP(TPila pila);

#endif // PILADINAMICA_H_INCLUDED
