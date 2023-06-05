#include <stdlib.h>
#include <stdio.h>

int main() {
  char c;
  printf("Ingrese la frase:\n");

  while (c != '.') {
    while(c == ' ') {
      // Estamos en presencia de un separador
      c = getchar();
      putchar(c);
    }

    while(c != ' ' && c != '.') {
      // Verifica si estamos en presencia de la palabra
      c = getchar();
      putchar(c);
    }
  }

  return 0;
}
