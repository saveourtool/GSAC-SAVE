/*
 * Based on CVE-2023-34095
 */

#include <stdio.h>

int main() {
  char ptr[2];
  // Tried to write string into char's array.
  // Note that scanf also read the end of the line and the null symbol
  scanf("%s", ptr); // buffer-overflow
}
