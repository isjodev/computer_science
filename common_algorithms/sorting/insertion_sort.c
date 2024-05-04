/* insertion_sort.c */ 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../../include/array_util.h"

#define LEN 5

// Function prototypes
void insertion_sort(int *array, int len);

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

void insertion_sort(int *array, int len) {
  for (int i = 1; i < len; i++) {
    int key = array[i];
    int j = i - 1;
    while (j >= 0 && array[j] > key) {
      array[j + 1] = array[j];
      j = j - 1;
    }
    array[j + 1] = key;
  }
}

int main(int argc, char **argv) {
  int *array = allocate_array(LEN);
  populate_array(array, LEN);
  insertion_sort(array, LEN);
  print_array(array, LEN);
  free(array);

  return 0;
}
