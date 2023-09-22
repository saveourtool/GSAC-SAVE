/*
 * Based on CVE-2022-0185
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PAGE_SHIFT 12
#define PAGE_SIZE (1ULL << PAGE_SHIFT)

int foo(unsigned int size, const char *key) {
  size_t len = 3;

  if (len > PAGE_SIZE - 2 - size) {
    printf("Too large\n");
    return -1;
  }

  // 'strlen' can't find '\0'
  len = strlen(key); // buffer-overflow
  return len;
}

int main() {
  unsigned int size = 4294967295;
  char *key = malloc(10);
  // After 'memcpy()' 'key' doesn't have a '\0' symbol
  memcpy(key, "asddds4323", 10);

  foo(size, key);

  free(key);
}
