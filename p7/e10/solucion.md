Graficar la inserción de los siguientes valores, en el orden dado, en un ABB inicialmente vacío:
10, 8, 14, 24, 11, 1, 33, 40, 5, 32, 3, 7, 9 y 25. Eliminar 7, 24, 8, 10. 

___________________________________
Inserta 10:
```
             10
             
```             
___________________________________
Inserta 8:
```
            10
           /  
          8   
```               
___________________________________
Inserta 14:
```
            10
           /  \
          8    14
```          
___________________________________
Inserta 24:
```
            10
           /  \
          8    14
                 \
                  24
```                  
___________________________________
Inserta 11:
```
            10
           /  \
          8    14
              /  \
            11    24
```                              
___________________________________
Inserta 1:
```
            10
           /  \
          8    14
         /    /  \
        1    11   24
```        
___________________________________
Inserta 33:
```
            10
           /  \
          8    14
         /    /  \
        1    11   24
                    \
                     33
```                     
___________________________________
Inserta 40:
```
            10
           /  \
          8    14
         /    /  \
        1    11   24
                    \
                     33
                       \
                        40
```                        
___________________________________
Inserta 5:
```
            10
           /  \
          8    14
         /    /  \
        1    11   24
         \          \
          5          33
                       \
                        40
```
___________________________________
Inserta 32:
```
            10
           /  \
          8    14
         /    /  \
        1    11   24
         \          \
          5          33
                     /  \
                    32   40
```        
___________________________________
Inserta 3:
```
            10
           /  \
          8    14
         /    /  \
        1    11   24
         \          \
          5          33
         /          /  \
        3         32    40
```        
___________________________________
Inserta 7:
```
            10
           /  \
          8    14
         /    /  \
        1    11   24
         \          \
          5          33
         / \        /  \
        3   7      32    40
```
___________________________________
Inserta 9:
```
             10
            /  \
           /    \
          8      14
         / \    /  \
        1   9  11    24
         \            \
          5            33
         / \          /  \
        3   7        32    40
```        
___________________________________
Inserta 25:
```
             10
            /  \
           /    \
          8      14
         / \    /  \
        1   9  11    24
         \            \
          5            33
         / \          /  \
        3   7        32    40
                    /
                  25
```                  
#Remover
Eliminar 7, 24, 8, 10. 
___________________________________

Eliminar 7:

```
             10
            /  \
           /    \
          8      14
         / \    /  \
        1   9  11   24
         \            \
          5            33
         /            /  \
        3           32    40
                    /
                  25
```                  
___________________________________

Eliminar 24:
(Se promueve el 33)
```
             10
            /  \
           /    \
          8      14
         / \    /  \
        1   9 11    33
         \         /  \
          5       32  40
         /       /
        3       25    
```                
___________________________________

Eliminar 8:
(Se busca por la rama de la derecha (5) del hijo de la izquierda (1) 
del nodo a remover (8) un nodo que no tenga hijos a la derecha (5) y se copia 
su valor al valor del nodo a remover (valor de nodo 8 <- 5), y todo todo el 
subarbol izquierdo (3) del nodo encontrado (5) se promueve al lugar del nodo encontrado)
```
             10
            /  \
           /    \
          5      14
         / \    /  \
        1    9 11   33
         \         /  \
          3       32  40
                 /
                25    
```
___________________________________

Eliminar 10:
(Se busca por la rama de la derecha (9) del hijo de la izquierda (5) 
del nodo a remover (10) un nodo que no tenga hijos a la derecha (9) y se copia 
su valor al valor del nodo a remover (valor de nodo 10 <- 9), y todo todo el 
subarbol izquierdo (NULO) del nodo encontrado (9) se promueve al lugar del nodo encontrado)
```
              9
            /  \
           /    \
          5      14
         /      /  \
        1      11    33
         \         /  \
          3       32  40
                 /
                25   

```                
__________________________________