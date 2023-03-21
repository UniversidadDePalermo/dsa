#include <stdio.h>
#include <stdlib.h>

int main() {
  char c;
  int spaces = 0;
  int starts_with_char_u = 0;

  printf("Ingrese una frase: ");
  c = getchar();
  putchar(c);

  while (c != '.') {
    while(c == ' ') {
      spaces += 1;

      c = getchar();
      putchar(c);
    }

    if (c == 'u' || c == 'U') {
      starts_with_char_u += 1;
    }

    while(c != ' ' && c != '.') {
      c = getchar();
      putchar(c);
    }
  }

  printf("\nEspacios: %d\n", spaces);
  printf("Empieza con \"U\": %d\n", starts_with_char_u);
}
