18. Desarrollar un subprograma que duplique los elementos de un vector ubicados en las
posiciones pares. Implementar 3 veces utilizando for, while y do while.


```c
int a[] = {0, 4, 6, 21, 51}, n = 5, i; 

for (i = 0; i < n; i+=2) {
    a[i] *= 2;
}

i = 0;
while (i < n) {
  a[i] *= 2;
  i += 2;
}


if (n > 0) {
  i = 0;
  do {
    a[i] *= 2;
    i += 2;
  } while (i < n)
}

```
