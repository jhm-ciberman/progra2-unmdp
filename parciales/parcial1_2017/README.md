## Primer parcial - 12 de mayo de 2017

Una heladeria representa la disposición de los sabores de su heladera de expendio mediante una lista donde
en cada nodo se almacena un registro por cada sabor, que contiene: nombre del sabor (cadena de 20 -
ordenada por este criterio), gramos expendidos, "fila" y "columna" (representa la celda que ocupa dicho 
sabor en la heladera de expendio) y una cola con los baldes disponibles en el depósito para dicho sabo. 
Para cada balde se registra la fecha de producción en formato aaaammdd (cadena de 8). Cada sabor no 
tendrá más de 30 baldes disponibles.

Semanalmente se realiza un proceso que desecha los baldes cuya fecha de producción es anterior a una 
fecha dada. En el mismo proceso se carga en una matriz de N x M, parte de la información contenida en la 
lista: en cada celda se colocan sabor y gramos expendidos. El valor de N surge del máximo valor en el campo
fila de los nodos de la lista, y el de M del máximo valor de columna. [Tanto N como M serán menores a 20].

A partir de la matriz se genera una estadística que obtiene los sabores más consumidos por cada "columna"
de la heladera, además del consumo promedio.

Desarrollar un programa que implemente los siguientes requerimientos, mediante un subprograma por cada item.

1 - Cargar la lista (inicialmente vacía) a partir del archivo de texto HELADERA.TXT provisto por la cátedra,
que posee un sabor por línea separando cada campo con un espacio. Los campos son: nombre del
sabor, gramos expendidos, fila, columna, cantidad de baldes, y la secuencia de fechas de producción. Ej: 
`LIMON 1200 0 4 3 20170330 20170410`. El archivo no está ordenado por ningun criterio. 

2 - Implementar el proceso semanal a partir del recorrido de la lista, solicitando al operador la fecha
parámetro. Los baldes desechados se deben almacenar en una lista circular, siempre al final de la misma.
Cada nodo de la lista circular contiene: fila, columna, sabor y fecha de producción.
Observación: Antes de ejecutar el proceso debe inicializarse la matriz, ya que pueden quedar celdas vacías.

3 - Generar la estadistica indicada, a partir de un recorrido recursivo de la matriz generada en el inciso 2

4 - Dada una fila X (dato), eliminar de la lista circular todos los baldes desechados correspondientes a dicha
fila informando al final la cantidad de baldes eliminados.

*NOTAS*

- Utilizar TDACOLA estática, definiendo el tipo, completando las cebeceras faltantes y desarrollando los 
operadores faltantes `IniciaC` y `PoneC` en los archivos provistos por la cátedra. 

- Si en la solución del inciso 3 se incluye algun ciclo, el mismo tendrá puntaje 0. 


___________________________

En cada uno de los 3 archivos a entregar (.h y .c del TDA y resolución del ej.) añadir una primera linea con nombre
del archiv, apellido y nombre.

Serán considerados al calificar este examen la eficiencia de las soluciones y el uso de las características del lenguaje 
C y la programación estructurada. 

Para aprobar es necesario obtener al menos 5 puntos entre los incisos 1, 2, 3 y 4. 

*Incisos/Puntaje:*

- Inciso 1: 2 puntos
- Inciso 2: 2,5 puntos
- Inciso 3: 2,5 puntos
- Inciso 4: 2 puntos
- TDA Cola y General: 1 pnto
 