/* merge_sort.c */ 
#include "../../include/array_util.h"

#define LEN 5

// Function prototypes

int main(int argc, char **argv) {
  int *array = allocate_array(LEN);
  populate_array(array, LEN);
  print_array(array, LEN);
  free(array);
  return 0;
}
