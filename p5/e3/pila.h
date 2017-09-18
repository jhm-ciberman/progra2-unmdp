#ifndef PILADINAMICA_H_INCLUDED
#define PILADINAMICA_H_INCLUDED

typedef struct PilaDato {char str[20];} PilaDato;

typedef struct PilaNodo{
    PilaDato dato;
    struct  PilaNodo* siguiente;
} PilaNodo;

typedef PilaNodo* TPila;

void IniciaP(TPila* pila);
void PoneP(TPila* pila, PilaDato dato);
void SacaP(TPila* pila, PilaDato* dato);
PilaDato ConsultaP(TPila pila);
int VaciaP(TPila pila);

#endif // PILADINAMICA_H_INCLUDED
