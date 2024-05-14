/* insertion_sort.c */ 
#include <stdio.h>
#include <stdlib.h>
#include "../../include/array_util.h"

#define LEN 10

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

void reverse_insertion_sort(int *array, int len) {
  for (int i = 1; i < len; i++) {
    int key = array[i];
    int j = i - 1;
    while (j >= 0 && array[j] < key) {
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

  populate_array(array, LEN);
  reverse_insertion_sort(array, LEN);
  print_array(array, LEN);
  free(array);

  return 0;
}
