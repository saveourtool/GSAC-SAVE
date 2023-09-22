#include <stdlib.h>

int main() {
  char *a = (char *)malloc(sizeof(char));
  if (a) {
    *a = 'a';
  }
  free(a);
  return 0;
}
