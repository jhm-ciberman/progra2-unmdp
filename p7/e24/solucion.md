## TDA N-ario

- Vacio(A)
	Devuelve verdadero si A es árbol Vacío.
- Nulo(p)
	Devuelve verdadero si p es la posición Nula
- HijoMasIzq(p,A)
	Devuelve la posición del hijo más a la izquierda de p, si p es hoja devuelve una posición nula.
- HermanoDer(p,A)
	Devuelve la posición del hermano a la derecha de p (tiene el mismo padre de p), si p es el de la extrema derecha devuelve una posición nula.
- Info(p,A)
	Devuelve el dato del en la posición p en el árbol A.
- Raiz(A)
	Devuelve una posición que es la raíz del árbol A.
- Padre(p,A)
	Devuelve la posición del padre de la posición p en el árbol A, si p es la raíz devuelve una posición nula.

## Ejercicios

24. Dado un árbol N-ario de enteros, desarrollar funciones para:
a) retornar la cantidad de nodos que posee.

```C
int nodos(Arbol a, Posicion p) {
	if (!Nulo(p)) {
		return nodos(a, HijoMasIzq(a, p)) + nodos(a, HermanoDer(a, p));
	}
	return 0;
}
```

b) hallar el porcentaje de claves pares

```C
int pares(Arbol a, Posicion p) {
	if (!Nulo(p)) {
		return pares(a, HijoMasIzq(a, p)) + pares(a, HermanoDer(a, p)) + (Info(p, a) % 2 == 0);
	}
	return 0;
}
```

c) retornar su grado

```C
int grado(Arbol a, Posicion p) {
	Posicion c;
	int hijosNum = 0, gradoMax = 0, temp;
	if (!Nulo(p)) {
		c = HijoMasIzq(a, p);
		while (!Nulo(c)) {
			hijosNum++; 
			temp = grado(a, c);
			if (temp > gradoMax) gradoMax = temp;
			c = HermanoDer(a, c);
		}
	}
	return cont > gradoMax ? cont : gradoMax;
}
```

d) hallar la cantidad de nodos de grado impar que hay en niveles impares.

```C
int nodos_grado_impar_en_niveles_pares(Arbol a, Posicion p) {
	Posicion c, d;
	int hijosNum = 0, cont = 0;
	if (!Nulo(p)) {
		c = HijoMasIzq(a, p);
		while (!Nulo(c)) {
			hijosNum++; 
			d = HijoMasIzq(a, c);
			while (!Nulo(d)) {
				cont += nodos_grado_impar_en_niveles_pares(a, d);
				d = HermanoDer(a, d);
			}
			c = HermanoDer(a, c);
		}
		return (hijosNum % 2 == 0) + cont;
	}
	return 0;
}
```

e) verificar si cumple que para todas las claves salvo las de las hojas, su valor numérico es igual
a la cantidad de hijos. (función int y función void)

```C
int nodo_dato_igual_nro_hijos(Arbol a, Posicion p) {
	Posicion c;
	int hijosNum = 0, cumple = 1;
	if (!Nulo(p)) {
		c = HijoMasIzq(a, p);
		while (!Nulo(c) && cumple) {
			hijosNum++;
			cumple = cumple && nodo_dato_igual_nro_hijos(a, c);
			c = HermanoDer(a, c);
		}
		return cumple && (hijosNum == Info(p, a));
	}
	return 1;
}
```

```C
void nodo_dato_igual_nro_hijos(Arbol a, Posicion p, int *cumple) {
	Posicion c;
	int hijosNum = 0;
	if (!Nulo(p)) {
		c = HijoMasIzq(a, p);
		while (!Nulo(c) && *cumple) {
			hijosNum++;
			*cumple = *cumple && nodo_dato_igual_nro_hijos(a, c);
			c = HermanoDer(a, c);
		}
		*cumple = *cumple && (hijosNum == Info(p, a));
	}
}
```



f) obtener el promedio de las claves del nivel K (dato) 

No sé.