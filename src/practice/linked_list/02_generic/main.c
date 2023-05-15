#include <stdlib.h>
#include <stdio.h>

typedef struct {
  void* next;
  int value;
} Node;

typedef struct {
  Node* head;
} LinkedList;

/**
 * Creates a new LinkedList and returns a pointer to it
 */
LinkedList* new_linked_list() {
  LinkedList* list;
  list = (LinkedList*) malloc(sizeof(LinkedList));

  return list;
}

Node* new_node(int value) {
  Node* node;
  node = (Node*) malloc(sizeof(Node));
  node -> value = value;

  return node;
}

/**
 * Prints Node Details to stdout
 */
void node_debug(Node* node) {
  printf("[Node]\nAddress: %p\nValue: %d\nNext: %p\n", node, node -> value, node -> next);
}

/**
 * Recursively walks through a Linked List by checking on each Node relative
 * (next) and printing to stdout using `node_debug`.
 */
void node_walk_and_debug(Node* node) {
  node_debug(node);
  printf("\n\n"); // To reduce read complexity

  if (node -> next != NULL) {
    node_walk_and_debug(node -> next);
    return;
  }
}

/**
 * Walks through the LinkedList and retrieves it's tail
 */
Node* linked_list_retrieve_tail(LinkedList* list) {
  Node* current = list -> head;

  while (current -> next != NULL) {
    current = current -> next;
  }

  return current;
}

void linked_list_append_node(LinkedList* list, int value) {
  Node* node = new_node(value);

  if (list -> head == NULL) {
    list -> head = node;
    return;
  }

  Node* tail = linked_list_retrieve_tail(list);

  tail -> next = node;
}

int main() {
  LinkedList* list = new_linked_list();
  linked_list_append_node(list, 1);
  linked_list_append_node(list, 2);
  linked_list_append_node(list, 3);

  Node* head = list -> head;

  node_walk_and_debug(head);

  free(list);
}
