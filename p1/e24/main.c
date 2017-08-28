#include <stdio.h>
#include <stdlib.h>

/*
24. Un sensor de temperatura realiza mediciones periódicas (una cada 5 seg.). Las mismas son
registradas en un archivo binario, donde cada elemento es de tipo float. Implementar un
programa que genere dicho archivo y, otro programa que lo lea y muestre por pantalla
temperatura promedio, máxima y mínima.

*/

int archivoLee();
int archivoGenera();

int main()
{
    char accion;

    printf("Ingrese la letra de la operación que desea efectuar:\n");
    printf("\t[G] Generar archivo\n");
    printf("\t[L] Leer archivo\n");
    printf("\t[S] Salir\n");
    printf("\n\nAccion: ");
    scanf("%c", &accion);

    switch (accion) {
        case 'G':
        case 'g':
            printf("Ingrese las temperaturas para grabar en el archivo. Ingrese 0 para salir.\n\n");
            printf("Temperatura: ");
            if (!archivoGenera()) {
                printf("Error al generar el archivo");
                return 0;
            } else {
                printf("Archivo generado");
            }
            break;
        case 'L':
        case 'l':
            if (!archivoLee()) {
                printf("Error al leer el archivo");
                return 0;
            }
        default:
            return 1;
    }
    return 0;
}


/**
 * Genera el archivo de temperaturas, preguntando al usuario las temperaturas a ingresar por teclado
 * @return {int} 0 si hay algun error, 1 si no hubo error
 */
int archivoGenera() {
    int escaneado;
    float temperatura;
    FILE * f;

    f = fopen("temperaturas.bin", "wb");

    if (f == NULL) {
        return 0;
    } else {
        escaneado = scanf("%f", &temperatura);
        while (temperatura != 0 && escaneado) {
            fwrite(&temperatura, sizeof(float), 1, f);
            printf("Temperatura: ");
            escaneado = scanf("%f", &temperatura);
        }
        fclose(f);
        return 1;
    }
}

/**
 * Lee el archivo de temperaturas
 * @return {int} 0 si hay algun error, 1 si no hay error
 */
int archivoLee() {
    float temperatura, suma = 0, maxima = -9999999, minima = 99999999, prom;
    int contador = 0;
    FILE * f;
    f = fopen("temperaturas.bin", "rb");

    if (f == NULL) {
        return 0;
    } else {
        fread(&temperatura, sizeof(float), 1, f);
        while (!feof(f)) {
            suma += temperatura;
            contador++;
            maxima = temperatura > maxima ? temperatura : maxima;
            minima = temperatura < minima ? temperatura : minima;

            fread(&temperatura, sizeof(float), 1, f);
        }
        fclose(f);

        prom = (suma / contador);

        printf("Promedio: %f\n", (float) prom);
        printf("Maxima: %f\n", (float) maxima);
        printf("Minima: %f\n", (float) minima);

        return 1;
    }
}

