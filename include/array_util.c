#include "array_util.h"

void print_array(int *array, int len) {
  for (unsigned i = 0; i < len; i++) {
    printf("%d\n", *(array + i));
  }
}

int *allocate_array(int len) {
  int *array = malloc(sizeof(int) * len);
  return array;
}

void populate_array(int *array, int len) {
  srand(time(NULL));
  for (int i = 0; i < len; ++i) {
    int temp = rand();
    *(array + i) = temp;
  }
}
