// Initializing the elements of an array with an initializer list.
#include <stdio.h>

int main(void) {
  int n[5] = {32, 27, 64, 18, 95};

  printf("%s%8s\n", "Element", "Value");

  // Output contents of array in tabular format.
  for (size_t i = 0; i < 5; ++i) {
    printf("%7zu%8d\n", i, n[i]);
  }

  return 0;
}
