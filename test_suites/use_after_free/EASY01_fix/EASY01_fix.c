#include <stdlib.h>

int main() {
  char *a = (char *)malloc(sizeof(char));
  *a = 'a';
  free(a);
  a = NULL;
  return 0;
}
