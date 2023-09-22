#include <stdlib.h>

int main() {
  int size = 10;
  int *arr = malloc(size * sizeof(int)); // Memory allocation
  // Access is out of bounds
  arr[size] = 4; // buffer-overflow
  free(arr);
}