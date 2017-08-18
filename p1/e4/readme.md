4. Indicar los valores que almacenan las variables en las siguientes instrucciones de lectura:


a) 
```c
int a;
/* leer a = 3 */
scanf("%d", &a); // 3
scanf("%f", &a); // ERROR
scanf("%c", &a); // ERROR
```

b) 
```c
char x;
/* leer x = 3 */
scanf("%d", &x); // 3
scanf("%f", &x); // ERROR
scanf("%c", &x); // (ETX) codigo de control ascii
```
c) 

```c
char w;
/* leer w = 2.5 */
scanf("%d", &w); // ERROR
scanf("%f", &w); // 2.5
scanf("%c", &w); // ERROR
```