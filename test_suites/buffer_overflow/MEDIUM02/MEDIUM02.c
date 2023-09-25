/*
 * Based on CVE-2022-3077
 */

#include <stdlib.h>
#include <string.h>

void foo(int *data) {
  unsigned char buffer[32 + 16];
  // Access to 'data' + 4 + 'data[0]' is out of bounds
  memcpy(&buffer[1], &data[1], data[0]); // buffer-overflow
}

int main() {
  int *data = (int *)malloc(4 * sizeof(int));
  data[0] = 13;
  data[1] = 2;
  data[2] = 3;
  data[3] = 5;

  foo(data);

  free(data);
}
