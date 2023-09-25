/*
 * Based on CVE-2022-3077 (fixed)
 */

#include <stdlib.h>
#include <string.h>

void foo(int *data) {
  unsigned char buffer[32 + 16];
  if (data[0] > 12)
    return;

  memcpy(&buffer[1], &data[1], data[0]);
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
