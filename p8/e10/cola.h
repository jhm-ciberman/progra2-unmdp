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
} Cola;

void cola_inicia(Cola* cola);
void cola_pone(Cola* cola, ColaDato dato);
void cola_saca(Cola* cola, ColaDato* dato);
ColaDato cola_consulta(Cola cola);
int cola_vacia(Cola cola);

void cola_tests();

#endif // COLADINAMICA_H_INCLUDED
