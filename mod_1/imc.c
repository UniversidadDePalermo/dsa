// Calcular el índice de masa corporal ingresando el peso de una persona en
// kilos y su estatura en metros.
//
// Este índice se obtiene realizando el cociente entre el peso y el cuadrado de
// la estatura.

#include <stdio.h>

int main(int args, const char *argv[]) {
  float height = 0;
  float weight = 0;

  printf("Ingrese su estatura (mt): ");
  scanf("%f", &height);

  printf("Ingrese su peso (kg): ");
  scanf("%f", &weight);

  printf("Su índice de masa corporal es de %.2f", weight / (height * height));

  return 0;
}
