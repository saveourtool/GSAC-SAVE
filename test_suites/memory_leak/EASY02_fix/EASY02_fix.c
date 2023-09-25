#include <stdlib.h>

struct char2 {
  char *a;
  char *b;
};

int main() {
  struct char2 *c2 = malloc(sizeof(struct char2));
  c2->a = (char *)malloc(sizeof(char));
  *c2->a = 'a';
  free(c2->a);
  free(c2);
  return 0;
}
