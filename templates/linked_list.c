#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList {
  int val;
  struct LinkedList *next;
} Node;

void crear(Node* pt);
void mostrar(Node* pt);
Node* insertar1(Node*);
Node* eliminar1(Node*);
void insertar2(Node*);
void eliminar2(Node*);

int main() {

  Node* prin = NULL;
  prin = (Node* )malloc(sizeof(Node));
  crear(prin);
  mostrar(prin);
  prin = insertar1(prin);
  insertar2(prin);
  prin = eliminar1(prin);
  eliminar2(prin);
  mostrar(prin);

  return 0;
}

void crear(Node* reg) {

  scanf("%d", &reg->val);

  if (reg->val == 0)
    reg->next = NULL;
  else {
    reg->next = (Node* )malloc(sizeof(Node));
    crear(reg->next);
  }
  return;
}

void mostrar(Node* reg) {
  if (reg->next != NULL) {
    printf("%d\n", reg->val);
    mostrar(reg->next);
  }
  return;
}

Node* insertar1(Node* p) {
  Node* aux;
  if () // condicion de insercion
  {
    aux = (Node* )malloc(sizeof(Node));
    aux->val = 0; // valor a insertar
    aux->next = p;
    p = aux;
  }
  return p;
}

void insertar2(Node* p) {
  Node* aux;
  while (p->next != NULL) {
    if () // condicion de insercion
    {
      aux = (Node* )malloc(sizeof(Node));
      aux->val = 0; // valor a insertar
      aux->next = p->next;
      p->next = aux;
    }
    p = p->next;
  }
}

Node* eliminar1(Node* p) {
  Node* aux;
  while () // condicion de eliminacion
  {
    aux = p->next;
    free(p);
    p = aux;
  }
  return p;
}
void eliminar2(Node* p) {
  Node* aux;

  while (p->next != NULL && p->next->next != NULL) {
    if () // condicion de eliminacion
    {
      aux = p->next->next;
      free(p->next);
      p->next = aux;
    } else {
      p = p->next;
    }
  }
}
