#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CANT 10

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

void acolar(Node** p, Node** u, Node* q) {
  printf("acolar_nodo\n");
  if (*p == NULL) {
    *p = * u = q;
  } else {
    (*u) -> siguiente = q;
    (*u) = q;
  }

  printf("%02d p=%X u=%X\n", q -> dato, * p, * u);
}

Node desacolar(Node** inicio) {
  Node* aux;
  Node datos;

  datos = **inicio;

  aux = *inicio;

  *inicio = (*inicio) -> siguiente;
  free(aux);

  return datos;
}

int main() {
  int i, num;
  Node* p = NULL;
  Node* u = NULL;

  for (i = 0; i < CANT; i++) {
    printf("Ingrese un numero");
    scanf("%d", & num);
    acolar( & p, & u, crear_nodo(num));

  }

  printf("\nVamos a desacolar todo\n");

  while (p != NULL) {
    mostrar(desacolar( & p));
  }

  return 0;
}
