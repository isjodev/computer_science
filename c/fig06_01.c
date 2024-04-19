// Initializing the elements of an array to zeros.
#include <stdio.h>

int main(void) {
  // n is an array of five integers.
  int n[5];

  // Set elements of array n to 0
  for (size_t i = 0; i < 5; ++i) {
    n[i] = 0;
  }

  printf("%s%8s\n", "Element", "Value");

  for (size_t i = 0; i < 5; ++i) {
    printf("%7zu%8d\n", i, n[i]);
  }

  return 0;
}
