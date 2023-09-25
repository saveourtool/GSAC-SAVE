#include <stdlib.h>

int main() {
  char *a = (char *)malloc(sizeof(char)); // Memory allocation
  free(a);                                // Free allocated memory
  *a = 'a';                               // Use after free
  return 0;
}
