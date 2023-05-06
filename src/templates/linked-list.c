#include <stdio.h>
#include <stdlib.h>

typedef struct Lista {
  int num;
  struct Lista * sig;
} Nodo;

void crear(Nodo* pt);
void mostrar(Nodo* pt);
Nodo * insertar(Nodo*);
Nodo * eliminar(Nodo*);
void insertar_while(Nodo*);
void eliminar_while(Nodo*);

int main() {
  Nodo * prin = NULL;
  prin = (Nodo*) malloc(sizeof(Nodo));

  crear(prin);
  mostrar(prin);

  prin = insertar1(prin);

  insertar2(prin);

  prin = eliminar1(prin);

  eliminar2(prin);
  mostrar(prin);

  return 0;
}

void crear(Nodo * registro) {
  scanf("%d", & registro -> num);

  if (registro -> num == 0)
    registro -> sig = NULL;
  else {
    registro -> sig = (Nodo*) malloc(sizeof(Nodo));
    crear(registro -> sig);
  }

  return;
}

void mostrar(Nodo * registro) {
  if (registro -> sig != NULL) {
    printf("%d\n", registro -> num);
    mostrar(registro -> sig);
  }

  return;
}

Nodo* insertar(Nodo* ptr) {
  Nodo* aux;

  if (/* Condicion de Inserción */) {
    aux = (Nodo*) malloc(sizeof(Nodo));
    aux -> num = 0; //valor a insertar
    aux -> sig = p;
    p = aux;
  }

  return p;
}

void insertar_while(Nodo* ptr) {
  Nodo * aux;

  while (p -> sig != NULL) {
    if (/* Condicion de Inserción */) {
      aux = (Nodo * ) malloc(sizeof(Nodo));
      aux -> num = 0; //valor a insertar
      aux -> sig = p -> sig;
      p -> sig = aux;

    }

    p = p -> sig;
  }
}

void eliminar(Nodo* ptr) {
  Nodo* aux;

  while (p -> sig != NULL && p -> sig -> sig != NULL) {
    if (/* Condicion de Eliminacion */)
    {
      aux = p -> sig -> sig;
      free(p -> sig);
      p -> sig = aux;
    } else {
      p = p -> sig;
    }
  }
}

Nodo* eliminar_while(Nodo * p) {
  Nodo* aux;

  while (/* Condicion de Eliminacion */) {
    aux = p -> sig;
    free(p);
    p = aux;
  }

  return p;
}
