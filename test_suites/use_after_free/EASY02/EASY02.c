#include <stdlib.h>
#include <time.h>

int main() {
  char *a = (char *)malloc(sizeof(char)); // Memory allocation
  char *b = a;
  if (a != NULL) {
    free(a); // Free allocated memory
  }
  *b = 'b'; // Use after free
  return 0;
}
