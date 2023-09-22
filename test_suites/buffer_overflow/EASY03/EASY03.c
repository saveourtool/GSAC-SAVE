#include <stdlib.h>

int main() {
  int *data;
  int size = 5;
  data = malloc(size * sizeof(int)); // Memory allocation
  for (int i = 0; i <= size; i++) {  // Last iteration of this cycle is (size + 1)_th
    // In the last iteration access is out of bounds
    data[i] = i; // buffer-overflow
  }
  free(data);
}
