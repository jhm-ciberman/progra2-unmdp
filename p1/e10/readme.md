10. Reescribir cada una de las siguientes porciones de código en una sola sentencia mediante el uso
del operador condicional:
a) 

```c
if(a < b)
 c = a;
else c = b;
```

```c
c = (a < b) ? a : b;
```

b) 

```c
if(a < b && b < c)
 printf(“ordenados”);
else printf(“desordenados”);

```
ç

```c
printf((a < b && b < c) ? “ordenados” : “desordenados”);

```
