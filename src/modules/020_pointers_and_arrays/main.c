// Escribir un programa efectúe las siguientes operaciones
//
// a) Declarar un arreglo de quince posiciones de tipo float. Cargar sus
// elementos y mostrarlo.
// b) Declarar un puntero a float.
// c) Asignar al puntero la dirección del arreglo
// d) Recorrer con el puntero el arreglo, mostrando la dirección y el contenido de cada
// posición.
//
// Output:
//
// Ingrese un valor real: 10.55
// Ingrese un valor real: 25.3
// Ingrese un valor real: 0.1
// 10.55 25.30 0.10

// Valor: 10.55  Pos: 6dde334c
// Valor: 25.30  Pos: 6dde3350
// Valor: 0.10 Pos: 6dde3354

#include <stdio.h>

#define FLOAT_ARR_LEN 3

int main() {
  // Declarar un arreglo de quince posiciones de tipo float.
  float reales[FLOAT_ARR_LEN];

  // Cargar sus elementos
  for (int i = 0; i < FLOAT_ARR_LEN; i++) {
    float num = 0;

    printf("Ingrese un valor real: ");
    scanf("%f", &num);

    reales[i] = num;
  }

  // Mostrarlo
  for (int i = 0; i < FLOAT_ARR_LEN; i++) {
    printf("%.2f\t", reales[i]);

    if (i == FLOAT_ARR_LEN - 1) {
      printf("\n\n");
    }
  }

  // Declarar un puntero a float
  float* reales_ptr;

  // Asignar al puntero la dirección del arreglo
  reales_ptr = &reales;

  // Recorrer con el puntero el arreglo, mostrando la dirección y el contenido
  // de cada posición.
  for (int i = 0; i < FLOAT_ARR_LEN; i++) {
    printf("Valor: %.2f\tPos: %x\n", *(reales_ptr + i), (reales_ptr + i));
  }
}
