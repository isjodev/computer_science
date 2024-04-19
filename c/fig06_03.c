// Initializing the elements of the array s to the even integers from 2 to 10.
#include <stdio.h>
#define SIZE 5

// Main
int main(void) {
  int s[SIZE] = {0};

  for (size_t j = 0; j < SIZE; ++j) {
    s[j] = 2 + 2 * j;
  }

  printf("%s%8s\n", "Element", "Value");

  for (size_t j = 0; j < SIZE; ++j) {
    printf("%7zu%8d\n", j, s[j]);
  }
  return 0;
}
