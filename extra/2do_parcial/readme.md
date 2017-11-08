## Ejercicios adicionales 2do parcial

- Dado un árbol binario que proviene de la transformación de un árbol general, desarrollar una función int que verifique si en el árbol general existía algún nodo de grado 2 tal que las claves de sus hijos eran iguales u opuestas.

```c
// Declara TArbol ... 

int verifica(TArbol a) {
    int temp1, temp2, cumple = 0; 
    // Si es de grado 2 
    if (a && a->der && !(a->der->der)) {
        cumple = (a->dato * a->dato == a->der->dato * a->der->dato);
    }
    // intera por cada primer hijo de cada hermano del nodo actual
    while (a && !cumple)
        cumple = verifica(a->izq);
        a = a->der; 
    }
    return cumple; 
}

int main() {
    TArbol a; 
    // crea el arbol
    int cumple = verifica(a); 
    return 0; 
}
```

- Dado un grafo almacenado en media matriz de adyacencia (triángulo inferior) generar, mediante una función void recursiva, un arreglo con el grado de cada uno de sus vértices.

```c
// Declara TMatriz ...

void grados(TMatriz g, int n, int * arr, int i, int j) {
    arr[i] += g[i][j];
    arr[j] += g[i][j];
    if (i < n - 1) {
        if (j < n - 2) {
            grados(g, n, arr, i + 1, j);
        }
    } else {
        grados(g, n, arr, j + 2, j + 1);
    }
}

/*
Ejemplo: 
 - - - -   
 1 - - -   
 1 0 - -   
 0 1 1 -   

 A--B
 |  |
 C--D
*/

int main() {
    TMatriz mat; 
    int arr[4];
    // Inicia la matriz de arriba...

    // Se debe iniciar con i=1, j=0.
    grados(mat, 4, arr, 1, 0); 

    return 0; 
}
```

- Dado un árbol N-ario determinar cuántas nodos no hoja cumplen que su valor numérico es igual a su grado.


```c
int determina(TArbol a, TPosicion p) {
    int grado = 0;
    int cumplenNro = 0; 
    TPosicion c;
    if (!Nulo(p)) {
        c = HijoMasIzq(p, a);
        while (c) {
            cumplenNro += determina(a, c); 
            grado++; 
            c = HermanoDer(c, a);
        }
        return cumplenNro + (grado != 0 && Info(p) == grado);
    } else {
        return 0; 
    }
}

int main() {
    TArbol a; 
    int n; 
    n = cuenta(a, Raiz(a));
    return 0; 
}
```

