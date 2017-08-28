22. Corregir el siguiente código para que asigne el contenido de la cadena cad1 a cad3, solamente
si cad1 y cad2 son distintas.

```c
char cad1[20], cad2[20], cad3[20];
gets(cad1); gets(cad2);
if(cad1 != cad2)
 cad3 = cad1;
```

Corregido:

```c
char cad1[20], cad2[20], cad3[20];
gets(cad1);
gets(cad2);
if(strcmp(cad1, cad2) == 0)
  strcpy(cad3, cad1);
```
