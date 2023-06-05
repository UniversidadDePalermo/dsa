
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
  Node * p = NULL;

  for (i = 0; i < CANT; i++) {
    printf("Ingrese un numero \n");
    scanf("%d", & num);
    apilar(&p, crear_nodo(num));
  }

  printf("\nVamos a desapilar todo\n");

  while (p != NULL) {
    mostrar(desapilar(&p));
  }

  return 0;
}
