#include <stdio.h>
#include <stdlib.h>


/*
25. Desarrollar un programa que lea y procese un archivo de texto generado por un radar vigía.
Cada línea contiene patente de un vehículo, velocidad registrada, velocidad máxima permitida,
fecha y hora de la medición. Cada dato está separado por un espacio. El programa debe
generar un archivo binario con los registros donde la velocidad registrada supere en más de un
20% a la velocidad máxima. Cada registro del archivo binario contiene los mismos datos que el
archivo de texto. Mostrar, al final del proceso, la cantidad de mediciones procesadas y la
cantidad de registros generados en el archivo binario.
*/


typedef struct Registro {
    char apellido[20]; // "Perez"
    char nombre[20]; // "Juan"
    char nacionalidad[4]; // "ARG"
    int puntaje; // 300
} Registro;

/**
 * Escribe el archivo de datos sacando los registros de registro.txt.
 * @return {int} 0 si hay error, 1 si no hay error.
 */
int archivoEscribe() {
    FILE * f1;
    FILE * f2;
    int escaneado;
    Registro reg;
    int codigo = 0;
    f1 = fopen("registro.txt", "rt");
    if (f1 == NULL) {
        printf("Error al abrir el archivo registro.txt");
    } else {
        f2 = fopen("registro.bin", "wb");
        if (f2 == NULL) {
            printf("Error al abrir el archivo registro.bin");
        } else {
            escaneado = fscanf(f1, "%s %s %s %d", reg.apellido, reg.nombre, reg.nacionalidad, &(reg.puntaje));
            while (!feof(f1) && escaneado == 4) {
                fwrite(&reg, sizeof(reg), 1, f2);
                escaneado = fscanf(f1, "%s %s %s %d", reg.apellido, reg.nombre, reg.nacionalidad, &(reg.puntaje));
            }
            fclose(f2);
            if (!feof(f1) && escaneado != 4) {
                printf("Error en el formato del archivo de texto\n");
                printf("%d\n",escaneado);
            } else {
                codigo = 1;
            }
        }
        fclose(f1);
    }
    return codigo;
}

/**
 * Lee el archivo de datos y muestra los datos en pantalla.
 * @param {int} pos Posicion del jugador en el archivo (empezando desde cero)
 * @return {int} 0 si hay error, 1 si no hay error.
 */
int archivoLee(int pos) {
    Registro reg;
    int codigo = 0;
    long posBytes;
    FILE * f = fopen("registro.bin", "rb");
    if (f == NULL) {
        printf("Error al abrir el archivo registro.bin");
        codigo = 0;
    } else {
        posBytes = pos * sizeof(reg);

        if (posBytes < ftell(f)) {
            fseek(f, posBytes, SEEK_SET);
            fread(&reg, sizeof(reg), 1, f);
            printf("Apellido\tNombre\tNac.\tPuntaje\n");
            printf("%s\t%s\t%s\t%d\n", reg.apellido, reg.nombre, reg.nacionalidad, reg.puntaje);
            fclose(f);
            codigo = 1;
        } else {
            printf("La posicion solicitada no existe en el archivo\n");
            codigo = 0;
        }

    }
    return codigo;
}

int main()
{
    int pos;
    printf("== Asociacion de tenistas: La raqueta de goma ==\n");
    printf("Sistema de control de Puntajes\n\n");

    if (!archivoEscribe()) {
        printf("Error escribiendo archivo");
    } else {
        printf("Posicion: ");
        scanf("%d", &pos);

        if (!archivoLee(pos + 1)) {
            printf("Error leyendo archivo");
        }
    }


    return 0;
}

