/*
 * Based on CVE-2023-34095
 */

#include <stdio.h>

int main() {
  char ptr[2];
  scanf("%1s", ptr);
}
