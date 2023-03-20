#include <stdlib.h>
#include <stdio.h>

int is_ascii_uppercase(char v) {
  if ((int) v >= 65 && (int) v <= 90) {
    return 1;
  }

  return 0;
}

int is_ascii_lowercase(char v) {
  if ((int) v >= 97 && (int) v <= 122) {
    return 1;
  }

  return 0;
}

int main() {
  char c;

  printf("Ingrese un caracter: ");
  c = getchar();

  int is_ascii_upper = is_ascii_uppercase(c);
  int is_ascii_lower = is_ascii_lowercase(c);

  if (is_ascii_upper == 1) {
    printf("El char: %c corresponde a un ASCII en mayúsculas\n", c);
  } else {
    printf("El char: %c no corresponde a un ASCII en mayúsculas\n", c);
  }

  if (is_ascii_lower == 1) {
    printf("El char: %c corresponde a un ASCII en minúsculas\n", c);
  } else {
    printf("El char: %c no corresponde a un ASCII en minúsculas\n", c);
  }

  if (is_ascii_lower == 0 && is_ascii_upper == 0) {
    printf("El char: %c no corresponde a un caractér alfabético. Puede ser un símbolo o un número.\n", c);
  }
}
