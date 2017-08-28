21. Responder:
a) ¿Por qué no es correcta la siguiente sentencia: scanf(“%s”, &cad)?

Porque las cadenas son punteros al primer caracter de la cadena. Por lo tanto, &cad sería un puntero a otro puntero.

b) ¿Qué instrucción resulta conveniente para leer por teclado apellido y nombre de una
persona: gets o scanf? Justificar la elección.

scanf("%s %s", apellido, nombre);
Ya que permite lectura con formato.


c) ¿Qué representan los valores devueltos por la función strcmp?


```c
strcmp(const char * str1, const char * str2)
```

- `<0` El primer caracter que no coincide tiene un valor menor en str1 que en str2
- `0` El contenido de ambas cadenas es igual
- `>0` El primer caracter que no coincide tiene un valor mayor en str1 que en str2
