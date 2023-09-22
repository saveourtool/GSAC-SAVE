/*
 * Based on CVE-2022-24959
 */

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int foo(int n, const char *src) {
  char *dst;
  dst = malloc(n); // Memory allocation
  memcpy(dst, src, n);
  if (dst == NULL) {
    return -1;
  }
  if (dst[2] != 'c')
    return -1; // Return without freeing 'dst'
  if (dst[0] > 'a') {
    free(dst);
    return -1;
  }
  free(dst);
  return 0;
}

int main() {
  const char *s = "asd";
  foo(3, s);
}
