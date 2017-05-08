#ifndef PILAESTATICA_H_INCLUDED
#define PILAESTATICA_H_INCLUDED

#define PILAE_MAX 50
typedef int PilaeDato;

typedef struct PilaeNodo{
    PilaeDato datos[PILAE_MAX];
    int elementos;
} Pilae;

void pilae_inicia(Pilae* pila);
void pilae_pone(Pilae* pila, PilaeDato dato);
void pilae_saca(Pilae* pila, PilaeDato* dato);
PilaeDato pilae_consulta(Pilae pila);
int pilae_vacia(Pilae pila);


void pilae_tests();


#endif // PILAESTATICA_H_INCLUDED
