/*
 * CVE-2023-34095
 */

#include <stdio.h>

int main() {
  char ptr[2];
  // ;warn:9: scanf should be used properly
  scanf("%s", ptr);
}
