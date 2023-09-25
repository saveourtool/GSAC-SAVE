#include <stdlib.h>

struct char2 {
  char *a;
  char *b;
};

void bad(struct char2 *in) {
  *(in->b) = 'b'; // Use after free
}

void good2bad(struct char2 *in) {
  struct char2 *local = in;
  *(local->a) = 'a';
  bad(local);
}

int main() {
  struct char2 *c2 = (struct char2 *)malloc(sizeof(struct char2));
  c2->a = (char *)malloc(sizeof(char));
  c2->b = (char *)malloc(sizeof(char)); // Memory allocation

  char **c2a = (char **)c2;
  char **c2b = ++c2a; // '*c2b' is a pointer to 'c2->b'

  free(*c2b); // Free allocated memory for 'c2->b'

  good2bad(c2);
  free(c2->a);
  free(c2);
  return 0;
}
