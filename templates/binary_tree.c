#include <stdio.h>
#include <stdlib.h>

typedef struct IBTreeNode {
  struct IBTreeNode * izq;
  struct IBTreeNode * der;
  int dato;
} BTreeNode;

void crear(BTreeNode** hoja);
void insertar(BTreeNode** hoja, int elem);
void mostrar(BTreeNode* hoja);

int main() {
  printf("arboles\n");
  BTreeNode* arbol = NULL;

  crear(&arbol);
  mostrar(arbol);

  return 0;
}

void crear(BTreeNode** hoja) {
  int numero;

  printf("ingrese numero\n");
  scanf("%d", & numero);

  while (numero != -1) {
    insertar(&(*hoja), numero);
    printf("ingrese numero\n");
    scanf("%d", & numero);
  }
}

void insertar(BTreeNode** hoja, int elem) {
  int numero = elem;
  if (elem == -1) {
    return;
  }

  if (*hoja == NULL) {
    //creo la hoja vacia
    (*hoja) = (BTreeNode*) malloc(sizeof(BTreeNode));
    (*hoja) -> dato = elem;
    (*hoja) -> der = NULL;
    (*hoja) -> izq = NULL;
  } else {
    if (numero > (*hoja) -> dato) {
      insertar(&(*hoja) -> der, elem);
    } else {
      insertar(&(*hoja) -> izq, elem);
    }
  }

  return;
}

void mostrar(BTreeNode * hoja) {
  if (hoja != NULL) {
    mostrar(hoja -> izq);
    printf("%d ", hoja -> dato);
    mostrar(hoja -> der);
  }

  return;
}
