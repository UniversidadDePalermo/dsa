#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/**
 * Aloja una matrix en memoria con valores fijos de tipo `int` y devuelve el
 * puntero hacia la misma.
 *
 * # Ejemplo de la Matriz Resultante
 *
 * ```
 *  +----+----+----+
 *  | 8  | -5 | 1  |
 *  +----+----+----+
 *  | 24 |  6 | 10 |
 *  +----+----+----+
 *  |  7 | 12 | 39 |
 *  +----+----+----+
 * ```
 *
 */
int* matrix_new() {
  int (*mtx)[3][3] = malloc(sizeof *mtx);

  (*mtx)[0][0] = 8;
  (*mtx)[0][1] = -5;
  (*mtx)[0][2] = 1;

  (*mtx)[1][0] = 24;
  (*mtx)[1][1] = 6;
  (*mtx)[1][2] = 10;

  (*mtx)[2][0] = 7;
  (*mtx)[2][1] = 12;
  (*mtx)[2][2] = 39;

  return mtx;
}

/**
 * Recorre la matriz de 3x3 mostrando en el stdout cada elemento de forma
 * detallada
 */
void matrix_debug(int mtx[3][3]) {
  int row, col;

  for (row = 0; row < 3; row++) {
    printf("\033[4mRow\033[0m: %d\n", row);
    for (col = 0; col < 3; col++) {
      printf("Col: \e[1m%d\e[m\t Val: \e[1m%d\e[m\n", col, mtx[row][col]);
    }

    printf("\n\n");
  }
}

/**
 * Recorre la matriz de 3x3 mostrando en el stdout cada elemento
 */
void matrix_print(int mtx[3][3]) {
  int row, col;

  printf("\n----------------------\n");
  for (row = 0; row < 3; row++) {
    for (col = 0; col < 3; col++) {
      printf("%d\t", mtx[row][col]);
    }
    printf("\n");
  }
  printf("----------------------\n");
}

int main() {
  int* matrix = matrix_new();

  matrix_print(matrix);

  free(matrix);
}
