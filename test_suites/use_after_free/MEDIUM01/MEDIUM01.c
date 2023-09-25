#include <stdlib.h>

struct char2 {
  char *a;
  char *b;
};

void badSink(struct char2 *in) {
  *(in->a) = 'a'; // Use after free
}

void good2bad(struct char2 *in) {
  struct char2 *local = in;
  badSink(local);
}

int main() {
  struct char2 *c2_alias;
  struct char2 *c2 = (struct char2 *)malloc(sizeof(struct char2));
  c2->a = (char *)malloc(sizeof(char)); // Memory allocation
  c2_alias = c2;

  free(c2->a); // Free memory which was allocated in 18-th line

  good2bad(c2_alias);
  free(c2);
  return 0;
}
