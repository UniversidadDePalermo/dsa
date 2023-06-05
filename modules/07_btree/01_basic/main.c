#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct arbol {
  int dato;
  struct arbol *izq;
  struct arbol *der;
} treenode;

void crear(treenode **hoja);
void insertar(treenode **hoja, int elem);
void mostrar(treenode *hoja, int raiz, int *sumatoria, int *contadordemultiplos);

int main() {
  int raiz;
  int sumatoria = 0;
  int contadormultiplos = 0;
  treenode *arbol = NULL;

  crear(&arbol);

  printf("**************\n");
  printf("mostrar arbol\n");
  printf("***************\n");

  raiz = arbol->dato;

  mostrar(arbol, raiz, &sumatoria, &contadormultiplos);

  printf("\nEl promedio de los elementos multiplos de la raiz es de: %f", (float) (sumatoria/contadormultiplos));

  system("pause");

  return 0;
}

void crear(treenode **hoja) {
  int numero;

  printf("ingrese numero\n");
  scanf("%d", &numero);
  while (numero != -1) {
    insertar(&(*hoja), numero);
    printf("ingrese numero\n");
    scanf("%d", &numero);
  }
}

void insertar(treenode **hoja, int elem) {
  int numero = elem;

  if (elem == -1) {
    return;
  }

  if (*hoja == NULL) {
    //creo la hoja vacia
    (*hoja) = (treenode *)malloc(sizeof(treenode));
    (*hoja)->dato = elem;
    (*hoja)->der = NULL;
    (*hoja)->izq = NULL;
  } else {

    if (numero > (*hoja)->dato) {
      insertar(&(*hoja)->der, elem);
    } else {
      insertar(&(*hoja)->izq, elem);
    }
  }

  return;
}

void mostrar(treenode *hoja, int raiz, int *sumatoria, int *contadordemultiplos) {
  if (hoja != NULL) {
    mostrar(hoja->izq, raiz, sumatoria, contadordemultiplos);
    
    if (hoja->dato % raiz == 0 && hoja->dato != raiz) {
      *contadordemultiplos = *contadordemultiplos + 1;
      *sumatoria = *sumatoria + hoja->dato;
    }
    
    printf("%d ", hoja->dato);

    mostrar(hoja->der, raiz, sumatoria, contadordemultiplos);
  }

  return;
}
