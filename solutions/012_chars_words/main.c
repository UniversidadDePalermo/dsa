// Leer un texto carácter a carácter, terminado en PUNTO.
// Mostrar cuántas palabras tienen más de 3 letras.

#include <stdlib.h>
#include <stdio.h>

int main() {
  char c;
  int char_count = 0;
  int more_than_3 = 0;
  printf("Ingrese la frase:\n");

  while (c != '.') {
    while(c == ' ') {
      if (char_count > 3) {
        more_than_3++;
      }

      char_count = 0;
      c = getchar();
      putchar(c);
    }

    while(c != ' ' && c != '.') {
      char_count++;
      c = getchar();
      putchar(c);
    }
  }

  printf("\nLa cantidad de palabras con más de 3 caracteres es: %d", more_than_3);

  return 0;
}
