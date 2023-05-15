// Dada una lista simplemente enlazada donde sus nodos responden a la
// estructura:
//
// Num: Int
// Sig: Node*
//
// (a) Crear y mostrar la lista. La carga finaliza con -1
//
// (b) Calcular y Mostrar
//     - Promedio
//     - Máximo Número Impar
//
// (c) Luego de haber calculado el máximo, buscar en la lista si el valor
// del nodo es menor que el máximo número impar de la lista para eliminar
// dicho nodo.
//
// Ejemplo: 
// Lista original:
// 5 -> 8 -> 0 -> 2 -> 7 -> 16 -> 1 -> 3
//
// El máximo número impar es: 7
//
// Lista después de eliminar: 
// 8 -> 7 -> 16
//
// (d) Insertar después de cada número un 0.
// Lista después de insertar (continúa del ejemplo anterior):
// 8 -> 0 -> 7 -> 0 -> 16 -> 0

#include <stdio.h>
#include <stdlib.h>

#define CORTE_DE_INSERCION -1

typedef struct Lista {
  int num;
  struct Lista* sig;
} Nodo;

void crear(Nodo*);
void mostrar(Nodo*);
int promedio(Nodo*);
int maximo_impar(Nodo*);
void eliminar_menores(Nodo*, int);
void insertar_ceros(Nodo*);

int main() {
  Nodo* head;
  head = (Nodo*) malloc(sizeof(Nodo));

  // (a) Crear y mostrar la lista. La carga finaliza con -1
  crear(head);
  printf("Lista original: \n");
  mostrar(head);

  // (b) Calcular y Mostrar
  //     - Promedio
  //     - Máximo Número Impar
  int avg = promedio(head);
  printf("Promedio: %d\n", avg);

  int max_odd = maximo_impar(head);
  printf("Máximo Número Impar: %d\n", max_odd);

  // (c) Luego de haber calculado el máximo, buscar en la lista si el valor
  // del nodo es menor que el máximo número impar de la lista para eliminar
  // dicho nodo.
  //
  // Ejemplo: 
  // Lista original:
  // 5 -> 8 -> 0 -> 2 -> 7 -> 16 -> 1 -> 3
  //
  // El máximo número impar es: 7
  //
  // Lista después de eliminar: 
  // 8 -> 7 -> 16
  printf("Lista después de eliminar:\n");
  eliminar_menores(head, max_odd);
  mostrar(head);

  // (d) Insertar después de cada número un 0.
  // Lista después de insertar (continúa del ejemplo anterior):
  // 8 -> 0 -> 7 -> 0 -> 16 -> 0
  printf("Lista después de insertar:\n");
  insertar_ceros(head);
  mostrar(head);

  // Liberamos el espacio de memoria para la lista
  free(head);

  return 0;
}

void crear(Nodo* registro) {
  int valor = 0;

  printf("Ingrese un valor. La carga finaliza con -1: ");
  scanf("%d", &valor);

  if (valor == CORTE_DE_INSERCION) {
    registro -> sig = NULL;
    printf("\nFinaliza entrada de datos\n");
  } else {
    registro -> num = valor;
    registro -> sig = (Nodo*) malloc(sizeof(Nodo));
    crear(registro -> sig);
  }

  return;
}

void mostrar(Nodo* registro) {
  if (registro -> sig != NULL) {
    // El registro actual
    printf("%d", registro -> num);

    if (registro -> sig -> sig != NULL) {
      // Existe un registro después de este
      printf(" -> ");
    }

    mostrar(registro -> sig);
  }

  if (registro -> sig == NULL) {
    // Último registro a mostrar
    printf("\n\n");
  }

  return;
}

int promedio(Nodo* registro) {
  int total = 0;
  int accum = 0;

  while (registro -> sig != NULL) {
    total++;
    accum += registro -> num;
    registro = registro -> sig;
  }

  return accum / total;
}

int maximo_impar(Nodo* registro) {
  // El valor `-1` nunca estará presente y es impar
  int max = -1;

  // Si el primer número es impar, lo colocamos como el máximo
  if (registro -> num % 2 != 0) {
    max = registro -> num;
  }

  // Avanzamos una posición
  registro = registro -> sig;

  while (registro != NULL && registro -> sig != NULL) {
    if (registro -> num % 2 != 0 && registro -> num > max) {
      max = registro -> num;
    }

    registro = registro -> sig;
  }

  return max;
}

void eliminar_menores(Nodo* registro, int max) {
  Nodo* aux;

  while (registro -> sig != NULL && registro -> sig -> sig != NULL) {
    if (registro -> sig -> num < max) {
      aux = registro -> sig -> sig;
      free(registro -> sig);
      registro -> sig = aux;
    } else {
      registro = registro -> sig;
    }
  }
}

void insertar_ceros(Nodo* registro) {
  Nodo* aux;

  while (registro -> sig != NULL) {
    aux = (Nodo*) malloc(sizeof(Nodo));
    aux -> num = 0;
    aux -> sig = registro -> sig;
    registro -> sig = aux;
    registro = registro -> sig -> sig;
  }
}
