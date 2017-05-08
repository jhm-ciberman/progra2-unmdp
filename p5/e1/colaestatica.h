#ifndef COLAESTATICA_H_INCLUDED
#define COLAESTATICA_H_INCLUDED

#define COLAE_MAX 50

typedef int ColaeDato;
typedef struct Colae{
    int primero;
    int ultimo;
    ColaeDato datos[COLAE_MAX];
} Colae;

void colae_inicia(Colae* cola);
void colae_pone(Colae* cola, ColaeDato dato);
void colae_saca(Colae* cola, ColaeDato* dato);
ColaeDato colae_consulta(Colae cola);
int colae_vacia(Colae cola);

void colae_tests();

#endif // COLAESTATICA_H_INCLUDED
