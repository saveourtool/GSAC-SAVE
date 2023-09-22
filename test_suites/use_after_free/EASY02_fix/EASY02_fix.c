#include <stdlib.h>
#include <time.h>

int main() {
  char *a = (char *)malloc(sizeof(char));
  char *b = a;
  *b = 'b';
  if (a != NULL) {
    free(a);
  }
  return 0;
}
