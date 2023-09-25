#include <stdlib.h>

int main() {
  char *a = (char *)malloc(sizeof(char)); // Memory allocation
  if (a) {
    *a = 'a';
  }
  return 0; // Return without freeing 'a'
}
