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
    char patente[8]; // "12ABC34"
    int vel; // 80
    int velmax; // 120
    char fecha[11]; // "24/11/2017"
    char hora[9]; // "13:20:23"
} Registro;

/**
 * Escribe el archivo de datos del radar sacando los registros de registro.txt.
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
            escaneado = fscanf(f1, "%s %d %d %s %s", reg.patente, &(reg.vel), &(reg.velmax), reg.fecha, reg.hora);
            while (!feof(f1) && escaneado == 5) {
                if (reg.vel > reg.velmax * 1.2) { //Supera en 20%
                    fwrite(&reg, sizeof(reg), 1, f2);
                }
                escaneado = fscanf(f1, "%s %d %d %s %s", reg.patente, &(reg.vel), &(reg.velmax), reg.fecha, reg.hora);
            }
            fclose(f2);
            if (escaneado != 5) {
                printf("Error en el formato del archivo de texto");
            } else {
                codigo = 1;
            }
        }
        fclose(f1);
    }
    return codigo;
}

/**
 * Lee el archivo de datos del radar y muestra los datos en pantalla.
 * @return {int} 0 si hay error, 1 si no hay error.
 */
int archivoLee() {
    Registro reg;
    int codigo = 0;
    FILE * f = fopen("registro.bin", "rb");
    if (f == NULL) {
        printf("Error al abrir el archivo registro.bin");
    } else {
        fread(&reg, sizeof(reg), 1, f);
        printf("patente\tvel\tmax\tfecha\t\thora\n");
        while (!feof(f)) {
            printf("%s\t%d\t%d\t%s\t%s\n", reg.patente, reg.vel, reg.velmax, reg.fecha, reg.hora);
            fread(&reg, sizeof(reg), 1, f);
        }
        fclose(f);
        codigo = 1;
    }
    return codigo;
}

int main()
{
    printf("== VIGIA 3000 ==\n");
    printf("Sistema de control de radar vigia\n\n");

    if (!archivoEscribe()) {
        printf("Error escribiendo archivo");
    } else if (!archivoLee()) {
        printf("Error leyendo archivo");
    }


    return 0;
}
