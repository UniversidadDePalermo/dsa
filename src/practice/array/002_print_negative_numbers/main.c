// Write a C program to input elements in array and print all negative elements.
// How to display all negative elements in array using loop in C program. Logic to
// display all negative elements in a given array in C programming.
//
// https://codeforwin.org/c-programming/c-program-to-print-all-negative-elements-in-array

#include <stdio.h>

int main() {
  int size = 0;

  printf("Ingrese el tamaño del array: ");
  scanf("%d", &size);

  int elements[size];

  for (int i = 0; i < size; i++) {
    int element = 0;

    printf("Ingrese un valor para la índice (%d/%d): ", i, size - 1);
    scanf("%d", &element);

    elements[i] = element;
  }

  printf("Elementos negativos ingresados: \n");

  for (int i = 0; i < size; i++) {
    if (elements[i] < 0) {
      printf("%d\n", elements[i]);
    }
  }
}
