Dado el siguiente árbol:

```
       5
      / \
     /   \
    /     \
   8       4
  / \     /
 3   6   1
          \
           2
```

a) Mostrar (sin desarrollar un programa):

1. el contenido de sus nodos según cada recorrido: preorden, inorden, postorden.

PREORDEN:  5 8 3 6 4 1 2
INORDEN:   3 8 6 5 1 2 4
POSTORDEN: 3 6 8 2 1 4 5

2. el contenido del nodo raíz, y para cada nodo indicar: grado, nivel, valor del padre y del hermano.

NODO RAIZ: 5


|Nodo    |Grado    |Nivel    |Padre    |Hermano|
|--------|---------|---------|---------|-------|
|5       | 2       | 1       | N/A     | N/A   |
|8       | 3       | 2       | 5       | 4     |
|4       | 2       | 2       | 5       | 8     |
|3       | 1       | 3       | 8       | 6     |
|6       | 1       | 3       | 8       | 3     |
|1       | 2       | 3       | 4       | N/A   |
|2       | 1       | 4       | 1       | N/A   |

b) Responder: ¿cuál es la profundidad del árbol?

PROFUNDIDAD: 3

