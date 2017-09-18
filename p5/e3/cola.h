#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED

typedef int ColaDato;

typedef struct ColaNodo{
    ColaDato dato;
    struct ColaNodo* siguiente;
} ColaNodo;

typedef struct {
    ColaNodo* primero;
    ColaNodo* ultimo;
} TCola;

void iniciaC(TCola* cola);
void poneC(TCola* cola, ColaDato dato);
void sacaC(TCola* cola, ColaDato* dato);
ColaDato consultaC(TCola cola);
int vaciaC(TCola cola);

#endif // ColaINAMICA_H_INCLUDED
