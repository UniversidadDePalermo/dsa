/**
  Para los siguientes ejercicios crear una pila con la siguiente información:
    A: entero.
    SIG: puntero al próximo elemento de la pila

  1) La cantidad de números múltiplos de 3.
  2) El promedio de aquellos números divisores de 4.
  3) La sumatoria de aquellos números múltiplos del primer elemento ingresado a la pila.
  4) El número máximo y su posición en la pila.
  5) El número mínimo y su posición en la pila.
  6) Ingresar un numero por teclado y calcular la sumatoria de aquellos números
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CANT 4

typedef struct INode {
  int dato;
  struct INode* siguiente;
} Node;

void mostrar(Node aux) {
  printf("%d \n", aux.dato);
}

Node* crear_nodo(int dato) {
  Node* u;
  u = (Node*) malloc(sizeof(Node));
  u -> dato = dato;
  u -> siguiente = NULL;

  return u;
}

void apilar(Node** p, Node* u) {
  printf("apilar_nodo\n");
  u -> siguiente = * p;
  printf("%02d p=%X u=%X\n", u -> dato, *p, u);
  *p = u;
}

Node desapilar(Node** p) {
  Node* aux;
  Node datos;

  datos = ** p;
  aux = *p;
  *p = (*p) -> siguiente;
  free(aux);

  return datos;
}

int main() {
  int i, num;
  int values[CANT] = {1, 2, 3, 4};
  Node * p = NULL;

  for (i = 0; i < CANT; i++) {
    apilar(&p, crear_nodo(values[i]));
  }

  while (p != NULL) {
    mostrar(desapilar(&p));
  }

  return 0;
}
