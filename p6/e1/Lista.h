#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef int ListaDato;
typedef struct ListaNodo{
    ListaDato dato;
    struct ListaNodo *siguiente;
} ListaNodo;

typedef ListaNodo* Lista;

Lista lista_crea();
Lista lista_crea_desde_array(int datos[], int n);
void lista_prepone(Lista* lista, int dato);
int  lista_saca(Lista* lista);
void lista_destruye(Lista* lista);
void lista_invierte();

#ifdef NDEBUG
#define lista_tests() (void)0
#else
void lista_tests();
#endifdef

#endif // LISTA_H_INCLUDED
