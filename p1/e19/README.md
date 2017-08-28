19. Responder, siendo x un arreglo de 10 enteros (int x[10]):
a) ¿Se puede determinar por la siguiente invocación funarr(x, n) si x es parámetro de entrada o
de salida?

No. Ya que los arreglos en C son punteros a la primera posición del arreglo. Por lo tanto,
*siempre* son parámetros de entrada-salida.

b) ¿Se puede acceder al contenido de x[10]? ¿Qué representa el valor obtenido?

Sí, pero el area de memoria no estaría dentro de lo definido por el arreglo. Por lo tanto, el valor almacenado no tendría ningun significado. En otras palabras, sería "Basura".
