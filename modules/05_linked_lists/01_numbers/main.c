// 1) Calcular y mostrar el promedio de los números ingresados a la lista.
// Luego, si el valor del nodo es mayor que el promedio de la lista, eliminar
// dicho nodo.
//
// Ejemplo:
//
// Lista original:
//
// 6 -> 3 -> 8 -> -2 -> 5 -> 4 -> 3 -> 7
//
// El promedio es de 4
//
// Lista después de eliminar:
//
// 3 -> -2 -> 4 -> 3 
//
// 2) Insertar después de cada posición par (o bien cada dos nodos) la mitad
// del número del nodo anterior.
//
// Lista después de insertar (continúa del ejemplo anterior):
//
// 3 -> -2 -> -1 -> 4 -> 3 -> 1

#include <stdio.h>
#include <stdlib.h>

typedef struct List {
  int value;
  struct List* next;
} Node;

Node* fillup();
void debug(Node*);
void display(Node*);
void show(Node*);
int sum(Node*);
int len(Node*);
void delete_gt(Node* p, int gt);

int main() {
  Node* list = fillup();

  display(list);

  int count = sum(list);
  int total = len(list);
  int avg = count / total;

  printf("\nAvg: %d\nSum: %d\nLen: %d\n", avg, count, total);

  delete_gt(list, avg);
  display(list);

  return 0;
}

/**
 * Llenar la lista obteniendo valores de la entrada de texto
 * hasta que se coloque `-1`
 */
Node* fillup() {
  int value = 0;

  printf("Ingrese un valor (-1 para deterner):");
  scanf("%d", &value);

  if (value == -1) {
    return NULL;
  }

  Node* head = malloc(sizeof(Node));
  head -> value = value;

  printf("Ingrese un valor (-1 para deterner):");
  scanf("%d", &value);

  if (value == -1) {
    return head;
  }

  Node* curr = head;
  Node* aux;

  while(value != -1) {
    aux = (Node*) malloc(sizeof(Node));
    aux -> value = value;
    aux -> next = curr -> next;
    curr -> next = aux;
    curr = curr -> next;

    printf("Ingrese un valor (-1 para deterner):");
    scanf("%d", &value);
  }

  return head;
}

void show(Node* node) {
  printf("[%d@{%p}->:@{%p}]\n", node -> value, node, node -> next);
}

void debug(Node* node) {
  Node* cursor = node;
  show(cursor);

  if (cursor -> next != NULL) {
    debug(cursor -> next);
  } else {
    printf("\n");
  }
}

void display(Node* node) {
  Node* cursor = node;
  printf("%d", node -> value);

  if (cursor -> next != NULL) {
    printf(" -> ");
    display(cursor -> next);
  } else {
    printf("\n");
  }
}

int sum(Node* node) {
  if (node -> next != NULL) {
    return node -> value + sum(node -> next);
  } else {
    return node -> value;
  }
}

int len(Node* node) {
  if (node -> next != NULL) {
    return 1 + len(node -> next);
  } else {
    return 1;
  }
}

void delete_gt(Node* p, int gt) {
  Node *aux;

  while (p != NULL) {
    if (p -> value > gt) {
      aux = p -> next;
      free(p);
      p = aux;
    } else {
      p = p -> next;
    }
  }
}
