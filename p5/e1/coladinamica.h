#ifndef COLADINAMICA_H_INCLUDED
#define COLADINAMICA_H_INCLUDED

typedef int ColadDato;

typedef struct ColadNodo{
    ColadDato dato;
    struct ColadNodo* siguiente;
} ColadNodo;

typedef struct {
    ColadNodo* primero;
    ColadNodo* ultimo;
} Colad;

void colad_inicia(Colad* cola);
void colad_pone(Colad* cola, ColadDato dato);
void colad_saca(Colad* cola, ColadDato* dato);
ColadDato colad_consulta(Colad cola);
int colad_vacia(Colad cola);

void colad_tests();

#endif // COLADINAMICA_H_INCLUDED
