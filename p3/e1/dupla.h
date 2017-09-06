#ifndef DUPLA_H_INCLUDED
#define DUPLA_H_INCLUDED

typedef struct TDupla {
    int a, b;
} TDupla;

/**
 * Crea una nueva dupla
 */
TDupla crear(int primero, int segundo);

/**
 * \brief Obtiene el primer valor de la dupla
 */
int primero(TDupla d);

/**
 * \brief Obtiene el segundo valor de la dupla
 */
int segundo(TDupla d);

/**
 * \brief Genera una nueva dupla que es el resultado de multiplicar ambos elementos por el número múltiplo que se pasa como parámetro.
 */
TDupla multiplicar(TDupla d, int multiplo);

/**
 * \brief Genera una nueva dupla resultado de sumarle el parámetro adición a ambos elementos.
 */
TDupla adicionar(TDupla d, int adicion);

/**
 * \brief Genera una nueva dupla resultado de la suma de las dos recibidas como parámetro.
 */
TDupla sumar(TDupla a, TDupla b);

/**
 * \brief Genera una nueva dupla resultado de la resta de las dos recibidas como parámetro.
 */
TDupla restar(TDupla a, TDupla b);

#endif // DUPLA_H_INCLUDED
