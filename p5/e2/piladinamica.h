#ifndef PILADINAMICA_H_INCLUDED
#define PILADINAMICA_H_INCLUDED

typedef char PiladDato;

typedef struct PiladNodo{
    PiladDato dato;
    struct  PiladNodo* siguiente;
} PiladNodo;

typedef PiladNodo* Pilad;

void pilad_inicia(Pilad* pila);
void pilad_pone(Pilad* pila, PiladDato dato);
void pilad_saca(Pilad* pila, PiladDato* dato);
PiladDato pilad_consulta(Pilad pila);
int pilad_vacia(Pilad pila);


void pilad_tests();

#endif // PILADINAMICA_H_INCLUDED
