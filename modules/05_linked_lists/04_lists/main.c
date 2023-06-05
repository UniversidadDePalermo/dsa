// (a) Crear y mostrar una lista donde cada nodo tiene dos números enteros
// (termina con -1).

// (b) Insertar el consecutivo de cada nodo si la suma de sus elementos es mayor
// a 10.
//
// (c) Eliminar aquelos nodos donde ambos números son pares.
// Generar una lista con la suma de los elementos de cada nodo.

#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList {
  struct LinkedList* next;
  int value_a;
  int value_b;
} Node;

// Carga la lista con 2 valores enteros por nodo.
// Finaliza la carga cuando el usuario ingresa el valor `-1`
void load(Node* node);

// Camina la lista nodo por nodo mostando el nodo y sus valores
void show(Node* node);

// Inserta un nodo consecutivo a la suma de sus valores si es mayor a 10
void insert_consecutives(Node* node);

// Elimina los nodos donde ambos valores son pares
void delete_even_pairs(Node* node);

int main() {
  Node* list = malloc(sizeof(Node));

  printf("Cargar y Mostrar:\n");
  load(list);
  show(list); // (a)

  printf("Inserta consecutivos:\n");
  insert_consecutives(list); // (b)
  show(list);

  printf("Remueve nodos con ambos valores par:\n");
  delete_even_pairs(list); // (c)
  show(list);

  free(list);
}

void load(Node* node) {
  Node* aux;
  int value_a = 0;
  int value_b = 0;

  printf("Ingrese el primer valor: ");
  scanf("%d", &value_a);

  printf("Ingrese el segundo valor: ");
  scanf("%d", &value_b);

  while (value_a != -1 && value_b != -1) {
    node -> value_a = value_a;
    node -> value_b = value_b;

    printf("Ingrese el primer valor: ");
    scanf("%d", &value_a);

    printf("Ingrese el segundo valor: ");
    scanf("%d", &value_b);

    if (value_a != -1 && value_b != -1) {
      aux = (Node*) malloc(sizeof(Node));
      node -> next = aux;
      node = aux;
    }
  }
}

void show(Node* node) {
  while (node != NULL) {
    printf("[%d, %d]\n", node -> value_a, node -> value_b);
    node = node -> next;
  }
}

void insert_consecutives(Node* node) {
  Node* aux;

  while(node -> next != NULL) {
    if (node -> value_a + node -> value_b > 10) {
      aux = (Node*) malloc(sizeof(Node));

      // Valores consecutivos
      aux -> value_a = node -> value_a + 1;
      aux -> value_b = node -> value_b + 1;

      // Colocar en el medio
      aux -> next = node -> next;
      node -> next = aux;
      node = node -> next -> next;
    } else {
      node = node -> next;
    }
  }
}

void delete_even_pairs(Node* node) {
  Node* aux;

  while(node -> next != NULL && node -> next -> next != NULL) {
    if (node -> next -> value_a % 2 == 0 && node -> next -> value_b % 2 == 0) {
      aux = node -> next;
      node -> next = node -> next -> next;
      free(aux);
    } else {
      node = node -> next;
    }
  }
}
