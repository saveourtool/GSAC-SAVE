/*
 * Based on CVE-2022-24959 (fixed)
 */

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int foo(int n, const char *src) {
  char *dst;
  dst = malloc(n);
  memcpy(dst, src, n);
  if (dst == NULL) {
    return -1;
  }
  if (dst[2] != 'c' || dst[0] > 'a') {
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
