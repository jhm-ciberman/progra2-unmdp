6. Convertir las siguientes expresiones lógicas en Pascal al lenguaje C:
a) ( z < 5 ) AND ( ( a < = 5 ) OR ( c > 0 ) )

```c
(z < 5 && ( a <= 5 || c > 0))
```

b) ( z = CHR( 0 ) ) OR NOT( total = 0 ) 

```c
(z == 0 || total != 0)
```

