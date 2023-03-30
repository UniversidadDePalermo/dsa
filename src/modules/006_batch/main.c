//Ingresar números hasta que dicho número sea negativo. Por cada número leído,ingresar esa cantidad de números y obtener:
//a) El promedio de cada lote leído.
//b) Contar la cantidad de números pares de todos los números leídos.

#include <stdio.h>

int main() {

  int size, numero, suma = 0, i, cant_pares = 0;
  float prom;
  
  printf("Ingresar numeros hasta que uno sea negativo. Ese sera el tamaño del lote: ");
  scanf("%d", &size);

  int lote[size];

  while (size>0){

    for (i=0; i<size; i++){
      printf("Ingrese un numero dentro del lote: ");
      scanf("%d", &numero);
      lote[i] = numero;
      suma+=numero;
      if (numero%2==0){
        cant_pares++;
      }
    }
    for (i=0; i<size; i++){

      printf("[%d]", lote[i]);
    }

    prom = (float) suma/size;

    printf("\nEl promedio del lote es de %.2f", prom);
    
    int lote[size];

    printf("\nSe genera un nuevo lote");
    printf("\nIngresar numeros hasta que uno sea negativo. Ese sera el tamaño del lote: ");
    scanf("%d", &size);  
    suma = 0;
  }
  printf("la cantidad de numeros pares totales es de %d", cant_pares);
  return 0;
}