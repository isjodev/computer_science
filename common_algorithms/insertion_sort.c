#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void insertion_sort(int *array, int len);
void print_array(int *array, int len);

int main(int argc, char **argv) {
  int len = 0;
  printf("Enter len: \n");
  scanf("%d", &len);

  // Heap allocation.
  int *array = malloc(sizeof(int) * len);

  // Read values from stdin into array.
  printf("Enter values: \n"); 
  for (int i = 0; i < len; ++i) {
    int temp;
    scanf("%d\n", &temp);
    *(array + i) = temp;
  }

  print_array(array, len);

  free(array);
  return 0;
}

void print_array(int *array, int len) {
  for (unsigned i = 0; i < len; i++) {
    printf("%d ", *(array + i));
  }
}

void insertion_sort(int* array, int len) {

}
