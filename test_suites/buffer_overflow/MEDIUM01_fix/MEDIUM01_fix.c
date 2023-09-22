/*
 * Based on CVE-2022-0185 (fixed)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAGE_SHIFT 12
#define PAGE_SIZE (1ULL << PAGE_SHIFT)

int foo(unsigned int size, const char *key) {
  size_t len = 3;

  if (size + len + 2 > PAGE_SIZE) {
    printf("Too large\n");
    return -1;
  }

  len = strlen(key);
  return len;
}

int main() {
  unsigned int size = 4294967295;
  char *key = malloc(10);
  memcpy(key, "asddds432", 10);

  foo(size, key);

  free(key);
}
