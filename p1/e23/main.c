#include <stdio.h>
#include <stdlib.h>


/*
23. Rehacer el ejercicio 12 suponiendo que los números se encuentran en un archivo de texto,
todos en la misma línea. ¿Como modificaría la lectura, si hubiera un valor por línea?


RESPUESTA: No lo cambiaria de ninguna forma. Ya que la función fscanf con el formato "%d" lee
un número entero hasta que encuentre un caracter en blanco (saltos de linea, retornos de carro, espacios, tabulaciones) y
consume estos caracteres. Devuelve 1 en caso de éxito, y 0 en caso de haber algun error en la lectura (la lectura no cumplía
con el formato especificado)

*/
int main()
{
    int n, suma = 0, result;
    FILE* f;
    f = fopen("numeros.txt", "rt");
    if (f == NULL) {
        printf("Error abriendo archivo");
        return 1;
    } else {
        result = fscanf(f, "%d", &n);
        while (n != 0 && result && !feof(f)) {
            suma += n;
            result = fscanf(f, "%d", &n);
        }
        fclose(f);

        printf("La suma es: %d", suma); //Debería ser 147

        return 0;
    }
}
