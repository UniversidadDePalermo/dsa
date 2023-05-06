#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista {
  int dni;
  char nombre[20];
  float saldo;
  struct lista * sig;
} Nodo;

void crear(Nodo* pt);
void mostrar(Nodo* pt);
void saldos_negativos(Nodo* registro, Nodo* negativos);
void saldos_negativos_recursi(Nodo* registro, Nodo* negativos);

int main() {
  Nodo* prin, * negativo;
  prin = (Nodo*) malloc(sizeof(Nodo));
  negativo = (Nodo*) malloc(sizeof(Nodo));

  crear(prin);
  mostrar(prin);

  printf("\nMostrar negativos\n");
  saldos_negativos(prin, negativo);
  mostrar(negativo);

  return 0;
}

void saldos_negativos(Nodo* lista, Nodo* negativos) {
  while (lista -> sig != NULL) {
    if (lista -> saldo < 0) {
      negativos -> saldo = lista -> saldo;
      negativos -> dni = lista -> dni;
      strcpy(negativos -> nombre, lista -> nombre); /*la unica diferencia es que se usa la lib string.h y debemos copiar con strcpy xq es un char[20]*/

      negativos -> sig = (Nodo*) malloc(sizeof(Nodo));
      negativos = negativos -> sig;
    }

    lista = lista -> sig;
  }

  // Se coloca el fin de la lista
  negativos -> sig = NULL;
}

void saldos_negativos_recursi(Nodo* registro, Nodo* negativos) {
  if (registro -> sig != NULL) {
    if (registro -> saldo < 0) {
      strcpy(negativos -> nombre, registro -> nombre);
      negativos -> dni = registro -> dni;
      negativos -> saldo = registro -> saldo;

      // Se aloja memoria para el siguiente nodo
      negativos -> sig = (Nodo*) malloc(sizeof(Nodo));

      // Avanzamos a la siguiente posición
      negativos = negativos -> sig;
    }
    saldos_negativos(registro -> sig, negativos);
  } else {
    negativos -> sig = NULL;
  }
}

void crear(Nodo* registro) {
  printf("Ingrese dni");
  scanf("%d", & registro -> dni);

  if (registro -> dni == 0) {
    registro -> sig = NULL;
  } else {
    printf("Ingrese nombre\n");
    // No se derreferencia porque un `string` es un `char[]`
    scanf("%s", registro -> nombre);
    printf("Ingrese saldo\n");
    // Derreferenciamos `&registro` porque tenemos un puntero a un `float`
    scanf("%f", & registro -> saldo);
    registro -> sig = (Nodo*) malloc(sizeof(Nodo));
    crear(registro -> sig);
  }

  return;
}

void mostrar(Nodo* registro) {
  if (registro -> sig != NULL) {
    printf("\n%s\t", registro -> nombre); /*%s xq es una cadena de char, s de string*/
    printf("%d\t", registro -> dni);
    printf("%f\n", registro -> saldo);
    mostrar(registro -> sig);
  }

  return;
}
