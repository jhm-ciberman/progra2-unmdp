Diagramar el árbol correspondiente a las siguientes expresiones aritméticas y luego, sin
desarrollar un programa, recorrerlo en postorden mostrando su contenido.

a) 5 + 8 * 3 – 6 * 3
```
                 +
                / \
               5   -
                  / \
                 /   \
                *     *
               / \   / \
              8   3 6   3
```

- POSTORDEN: `5 8 3 * 6 3 * - +`


b) 6 * (5 + 2) / (6 - 2)
```
          *
         / \
        6  (/)
           / \
          /   \
         +     -
        / \   / \
       5   2 6   3
       
```       
- POSTORDEN: `6 5 2 + 6 3 - / *`

