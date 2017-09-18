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

void IniciaC(TCola* cola);
void PoneC(TCola* cola, ColaDato dato);
void SacaC(TCola* cola, ColaDato* dato);
ColaDato ConsultaC(TCola cola);
int VaciaC(TCola cola);

#endif // ColaINAMICA_H_INCLUDED
