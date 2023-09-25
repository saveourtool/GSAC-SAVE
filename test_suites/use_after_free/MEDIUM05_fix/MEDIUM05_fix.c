#include <stdlib.h>

struct char2 {
  char *a;
  char *b;
};

void bad(struct char2 *in) {
  if (in->b) {
    *(in->b) = 'b';
  }
}

void good2bad(struct char2 *in) {
  struct char2 *local = in;
  if (local->a)
    *(local->a) = 'a';
  bad(local);
}

int main() {
  struct char2 *c2 = (struct char2 *)malloc(sizeof(struct char2));
  c2->a = (char *)malloc(sizeof(char));
  c2->b = (char *)malloc(sizeof(char));

  char **c2a = (char **)c2;
  char **c2b = ++c2a;

  free(*c2b);
  *c2b = NULL;

  good2bad(c2);
  free(c2->a);
  free(c2);
  return 0;
}
