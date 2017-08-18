3. Describir lo que imprimen los siguientes fragmentos de código (justificar si no imprimen nada):

a) 
```c
char A;
A = 'a';
printf(" %c ", A); // a
printf(" %d ", A); // 97
A = 'a' + 10;
printf(" %c ", A); // k
printf(" %d ", A); // 107
```
b) 

```c
int B;
B = 5;
printf(" %d ", B); // 5
printf(" %c ", B); // Ningun caracter visible en pantalla (ENQ)
B = 5 + 'A';
printf(" %d ", B); // 70
printf(" %c ", B); // F

```
c) 

```c
#define num 15
printf(" %d ", num); // 15
printf(" %c ", num); // Ningun caracter visible en pantalla (SI)
```

d) 

```c
#define num 15
num = 5 + 'A';
printf(" %d ", num); // ERROR*
printf(" %c ", num); // ERROR*

/*
error: lvalue required as left operand of assignment
num = 5 + 'A';

Explicacion: El preprocesador reemplaza num por 15 y luego se compila el código:
15 = 5 + 'A'
el cual es inválido ya que 15 es una constante que no puede ser reasignada
*/

```