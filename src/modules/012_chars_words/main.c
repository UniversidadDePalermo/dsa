// Leer un texto carácter a carácter, terminado en PUNTO.
// Mostrar cuántas palabras tienen más de 3 letras.

#include <stdlib.h>
#include <stdio.h>

int main() {
  char c;
  printf("Ingrese la frase:\n");

  c = getchar();
  putchar(c);

  while (c != '.') {
    c = getchar();
    putchar(c);
  }

  return 0;
}
