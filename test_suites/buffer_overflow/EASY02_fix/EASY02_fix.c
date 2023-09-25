#include <stdlib.h>

int main() {
  int size = 10;
  int *arr = malloc(size * sizeof(int));
  arr[size - 1] = 4;
  free(arr);
}