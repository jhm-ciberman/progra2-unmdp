1. Dados los siguientes tipos de datos del lenguaje Pascal: char, integer, longint, word, real y
double; obtener el tipo equivalente en el lenguaje C especificando la cantidad de bytes que
ocupa y su cadena de formato. 

```
PASCAL:  Char
C:       char
Formato: "%c"
Bytes:   1 byte
``` 


```
PASCAL:  Integer
C:       int
Formato: "%d"
Bytes:   2 o 4 bytes
``` 

```
PASCAL:  Longint
C:       long
Formato: "%d"
Bytes:   2 o 4 bytes
``` 

```
PASCAL:  Word
C:       unsigned short
Formato: "%d"
Bytes:   2 o 4 bytes
``` 

```
PASCAL:  Real
C:       float
Formato: "%f" o "%g", etc.
Bytes:   4 bytes
``` 

```
PASCAL:  Double
C:       double
Formato: "%f" o "%g", etc.
Bytes:   8 bytes
``` 