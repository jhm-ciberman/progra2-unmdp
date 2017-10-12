// JAVIER MORA - MAIN.c

#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <string.h>

typedef char TStringNombre[21];
typedef char TStringDNI[9];

//
typedef TElementoP TTitulo;
typedef TPila TTitulos;
//

typedef struct TFacultad {
    TStringNombre nombre;
    TTitulos titulos;
    struct TFacultad * sig;
} TFacultad;

typedef TFacultad * TFacultades;

//



typedef struct TEntrega {
    int orden; //Autoincrementa
    float promedio;
    TStringDNI dni;
    TStringNombre nombre;
    struct TEntrega * sig;
} TEntrega;

typedef TEntrega * TEntregas;

void muestraTitulos(TTitulos * pTitulos) {
    TTitulo titulo;
    if (!vaciaP(*pTitulos)) {
        sacaP(pTitulos, &titulo);
        printf("[%s %.2f]", titulo.dni, titulo.promedio);
        muestraTitulos(pTitulos);
        poneP(pTitulos, titulo);
    }
}

void muestraFacultades(TFacultades facultades) {
    int i = 0; // Prevenir loops
    while (facultades && i<100) {
        printf("%-15s ", facultades->nombre);
        muestraTitulos(&(facultades->titulos));
        printf("\n\n");
        facultades = facultades->sig;
        i++;
    }
    printf("\n");
}



void creaFacultad(TFacultad ** ppFacultad, TStringNombre nombre) {
    *ppFacultad = (TFacultad*) malloc(sizeof(TFacultad));
    strcpy((*ppFacultad)->nombre, nombre);
    iniciaP(&((*ppFacultad)->titulos));
    (*ppFacultad)->sig = NULL;
}

void insertaFacultadOrdenada(TFacultades * pFacultades, TFacultad ** ppFacultad, TStringNombre nombre) {
    TFacultad * temp;
    //nombre = strlwr(nombre);
    if (*pFacultades == NULL || strcmp((*pFacultades)->nombre, nombre) > 0) {
        creaFacultad(ppFacultad, nombre);
        (*ppFacultad)->sig = *pFacultades;
        *pFacultades = *ppFacultad;
    } else {
        temp = *pFacultades;
        while (temp->sig && strcmp(temp->sig->nombre, nombre) <= 0) {
            temp = temp->sig;
        }
        if (strcmp(temp->nombre, nombre) == 0) {
            (*ppFacultad) = temp;

        } else {
            creaFacultad(ppFacultad, nombre);
            (*ppFacultad)->sig = temp->sig;
            temp->sig = (*ppFacultad);
        }
    }
}

/**
 * a) Generar la lista simple ordenada a partir del archivo de texto TITULOS.TXT provisto por la cátedra, que
 * posee un título a entregar por línea (facultad, DNI y promedio del graduado) separado cada campo con
 * un espacio. Ej: CS.ECONOMICAS 12345 8.88. El archivo no se encuentra ordenado por ningún criterio. La
 * lista se encuentra inicialmente vacía.
 */
void cargaArchivo(TFacultades * pFacultades) {
    FILE * f;
    TStringNombre nombre;
    TTitulo titulo;
    TFacultad * facultad = NULL;

    f = fopen("TITULOS.txt", "rt");
    *pFacultades = NULL;
    if (!f) {
        printf("Error abriendo el archivo");
    } else {
        fscanf(f, "%s %s %f", nombre, titulo.dni, &(titulo.promedio));
        while (!feof(f)) {
            insertaFacultadOrdenada(pFacultades, &facultad, nombre);
            poneP(&(facultad->titulos), titulo);
            fscanf(f, "%s %s %f", nombre, titulo.dni, &(titulo.promedio));
        }
    }

}

TFacultad * buscaFacultad(TFacultades facultades, TStringNombre nombre) {
    TFacultad * pFacultad = facultades;
    while(pFacultad && strcmp(pFacultad->nombre, nombre) < 0) {
        pFacultad = pFacultad->sig;
    }
    return pFacultad;
}

void sacaTitulo(TTitulos * pTitulos, TStringDNI dni, TTitulo * pTitulo) {
    TTitulo titulo;
    if (!vaciaP(*pTitulos)) {
        sacaP(pTitulos, &titulo);
        if (strcmp(titulo.dni, dni) != 0) {
            sacaTitulo(pTitulos, dni, pTitulo);
            poneP(pTitulos, titulo);
        } else {
            *pTitulo = titulo;
        }
    }
}

void creaEntrega(TEntrega ** ppEntrega, TStringNombre nombre, TStringDNI dni, float promedio, int orden) {
    *ppEntrega = (TEntrega*) malloc(sizeof(TEntrega));
    strcpy((*ppEntrega)->nombre, nombre);
    strcpy((*ppEntrega)->dni, dni);
    (*ppEntrega)->promedio = promedio;
    (*ppEntrega)->orden = orden;
}

void retirarTitulo(TFacultades * pFacultades, TEntregas * pEntregas, TStringNombre nombre, TStringDNI dni) {
    TFacultad * pFacultad;
    TTitulo titulo;
    strcpy(titulo.dni, "XXXXXXXX");

    TEntrega * pEntrega;
    int ordenMax = (*pEntregas) ? (*pEntregas)->orden : 0;

    pFacultad = buscaFacultad(*pFacultades, nombre);
    if (!pFacultad) {
        printf("No se encontró la facultad %s", nombre);
    } else {
        sacaTitulo(&(pFacultad->titulos), dni, &titulo);
        if (strcmp(titulo.dni, "XXXXXXXX") == 0) {
            printf("No se encontro el DNI: %s (Facultad: %s)\n", dni, nombre);
        } else {
            creaEntrega(&pEntrega, nombre, dni, titulo.promedio, ordenMax + 1);
            if (*pEntregas == NULL) {
                pEntrega->sig = pEntrega;
            } else {
                pEntrega->sig = (*pEntregas)->sig;
                (*pEntregas)->sig = pEntrega;
            }
            printf("Entrega completada\n");
            *pEntregas = pEntrega;
        }
    }
}

void listarEntregas(TEntregas entregas) {
    TEntrega * pEntrega;
    TEntrega * pMejorProm;
    if (entregas == NULL) {
        printf("No hay entregas para mostrar");
    } else {
        pEntrega = entregas->sig;
        pMejorProm = entregas->sig;
        do  {
            printf("Titulo: DNI=%-8s\tPROM=%.2f\n", pEntrega->dni, pEntrega->promedio);
            if (pEntrega->promedio > pMejorProm->promedio) {
                pMejorProm = pEntrega;
            }
            pEntrega = pEntrega->sig;

        } while (pEntrega != entregas->sig);

        printf("\nMejor promedio: \n");
        printf("Titulo: DNI=%-8s\tPROM=%.2f\tFACULT=%-15sORDEN=%d\n",
               pMejorProm->dni, pMejorProm->promedio, pMejorProm->nombre, pMejorProm->orden);
    }

}

void eliminaEntrega(TEntregas * entregas, TStringDNI dni) {
    TEntrega * pEntrega;
    TEntrega * pAnt;
    if (*entregas == NULL) {
        printf("No hay entregas");
    } else {

        pEntrega = (*entregas)->sig;
        pAnt = (*entregas);
        while (pEntrega != *entregas && strcmp(pEntrega->dni, dni) != 0) {
            pAnt = pEntrega;
            pEntrega = pEntrega->sig;
        }
        if (strcmp(pEntrega->dni, dni) == 0) {
            if (pEntrega == *entregas) {
                *entregas = NULL;
            } else {
                pAnt->sig = pEntrega->sig;
            }
            printf("El orden del graduado era ORDEN=%d", pEntrega->orden);
        } else {
            printf("No se encontro el graduado");
        }
    }
}

int main()
{
    TFacultades facultades = NULL;
    TEntregas entregas = NULL;
    cargaArchivo(&facultades);

    muestraFacultades(facultades);

    retirarTitulo(&facultades, &entregas, "CS_Agrarias", "56654527");
    retirarTitulo(&facultades, &entregas, "Ingenieria", "92182345");
    retirarTitulo(&facultades, &entregas, "Derecho", "83563681");
    retirarTitulo(&facultades, &entregas, "Humanidades", "56222674");

    listarEntregas(entregas);

    eliminaEntrega(&entregas, "83563681");
    eliminaEntrega(&entregas, "92182345");
    eliminaEntrega(&entregas, "56654527");
    eliminaEntrega(&entregas, "56222674");

    printf("\nHello world!\n");
    return 0;
}
