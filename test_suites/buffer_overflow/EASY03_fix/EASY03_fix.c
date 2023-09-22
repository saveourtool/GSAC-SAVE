#include <stdlib.h>

int main() {
  int *data;
  int size = 5;
  data = malloc(size * sizeof(int));
  for (int i = 0; i < size; i++) {
    data[i] = i;
  }
  free(data);
}
