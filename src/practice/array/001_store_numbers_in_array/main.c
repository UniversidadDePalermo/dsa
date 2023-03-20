// Write a C program to declare, initialize, input elements in array and print
// array. How to input and display elements in an array using for loop in C
// programming. C program to input and print array elements using loop. (No recursion)
// https://codeforwin.org/c-programming/c-program-to-read-and-print-elements-in-array

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

  printf("Elementos ingresados: \n");

  for (int i = 0; i < size; i++) {
    printf("%d\n", elements[i]);
  }
}
