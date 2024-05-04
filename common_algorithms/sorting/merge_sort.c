/* merge_sort.c
 * MERGE(A, p, q, r) Where A is an array, p, q, and r are indices into the
 * array such that a <= q < r
 * */
#include "../../include/array_util.h"
#include <math.h>

#define LEN 5

// Function prototypes
void merge_sort(int *, int, int);
void merge(int *, int, int, int);
int get_midpoint(int, int);

int main(int argc, char **argv) {
  int *array = allocate_array(LEN);
  populate_array(array, LEN);
  print_array(array, LEN);
  merge_sort(array, 0, LEN-1); 
  print_array(array, LEN);
  free(array);
  return 0;
}

int get_midpoint(int start, int end) {
  return floor(start + end) / 2; 
}

void merge(int* array, int start, int mid, int end)  {
  int len_left = mid - start + 1; 
  int len_right = end - mid; 

  int* left_subarray = malloc(sizeof(int) * len_left); 
  int* right_subarray = malloc(sizeof(int)* len_right); 

  for (int i = 0; i < len_left; i++) {
    left_subarray[i] = array[start + i]; 
  }

  for (int j = 0; j < len_right; j++) {
    right_subarray[j] = array[mid + j + 1]; 
  }

  int i = 0; 
  int j = 0; 
  int k = mid; 

  while (i < len_left && j < len_right) {
    if (left_subarray[i] <= right_subarray[j]) {
      array[k] = left_subarray[i]; 
      i++; 
    } else {
      array[k] = right_subarray[j]; 
      j++; 
    }
    k++; 
  }

  while (i < len_left) {
    array[k] = left_subarray[i]; 
    i++; 
    k++; 
  }

  while (j < len_right) {
    array[k] = right_subarray[j]; 
    j++; 
    k++; 
  }

  free(left_subarray); 
  free(right_subarray); 
}

void merge_sort(int* array, int start,  int end) {
  if (start >= end) {
    return; 
  }

  int mid = get_midpoint(start, end); 
  merge_sort(array, start, mid); 
  merge_sort(array, mid + 1, end); 
  merge(array, start, mid, end); 
}
