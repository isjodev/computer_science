// fig06_01.c
// Initializing the elements of an array to zeroes.
#include <stdio.h>

// Function main begins program execution.
int main(void) {
  // An array of 5 integers.
  int n[5];

  for (size_t i = 0; i < 5; ++i) {
    n[i] = 0;
  }

  printf("%s%8s\n", "Element", "Value");

  // Output contents of array n in tabular format.
  for (size_t i = 0; i < 5; ++i) {
    printf("%7zu%8d\n", i, n[i]);
  }
}
