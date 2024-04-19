// Computing the sum of the elements in an array.
#include <stdio.h>
#define SIZE 5

// Function main begins program execution.
int main(void) {
  int a[SIZE] = {1, 2, 3, 4, 5};
  int total = 0;

  // Sum contents of array a
  for (size_t i = 0; i < SIZE; ++i) {
    total += a[i];
  }

  printf("The total of a's values is %d\n", total);
  return 0;
}
