5. Completar el resultado que muestran los siguientes programas:

a) 
```c
#include <stdio.h>
int main(){
 int a, b, c = 3, d = 2;
 a = 8 - 5 * 3 + 2;
 b = 7 % 3 + 4 * 2;
 printf(" valor de a %d\tvalor de b %d\n", a ,b); // valor de a -5	valor de b 9
 b %= a;
 printf(" valor de b %d\t\n", b); // valor de b 4	
 b =(-4) % 3;
 printf(" valor de b %d\t\n", b); // valor de b -1
 if(d = a)
 printf(" d y a son iguales ");
 else printf(" d y a son distintos ");
 return 0; // d y a son iguales 
} 
 
```

b) 
```c
#include <stdio.h>
int main(){
 int c=3, d=2;
 c -= d++ * 3;
 printf(" valor de c %d\tvalor de d %d\n", c, d); // valor de c -3 	vañpr de d 3
 return 0;
}
```
c) 
```c
#include <stdio.h>
int main() {
 int c = 3, l;
 c = (c * 2 - (l = 4, -- l));
 printf(" valor de c %d\t valor de l %d\n", c, l); // valor de c 3	 valor de l 3
 getch();
 return 0;
}```