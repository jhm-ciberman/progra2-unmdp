17. Enumerar los valores de todos los componentes de los siguientes arreglos. Especificar los
arreglos de caracteres que pueden ser utilizados correctamente como cadenas.


a) `int v1[4] = {0};`

```c
{0, 0, 0, 0}
```

No se puede usar de string (a menos que se quiera usar como 4 strings vacios)

b) `int v2[5] = {6};`

```c
{6, 6, 6, 6, 6}
```

c) `int v3[] = {2,4,6};`

```c
{2, 4, 6}
```

d) `char s1[4] = {‘h’,’o’,’y’};`

```c
{'h', 'o', 'y', '\0'}
```
Se puede usar como string.

e) `char s2[] = {‘h’,’o’,’y’};`

```c
{'h', 'o', 'y'}
```

No se puede usar como string.

f) `char s3[4]= {‘h’,’o’,’y’,’\0’};`

```c
{'h', 'o', 'y', '\0'}
```

Sí se puede usar como string.
