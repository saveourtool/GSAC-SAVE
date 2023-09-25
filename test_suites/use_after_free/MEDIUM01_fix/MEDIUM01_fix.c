#include <stdlib.h>

struct char2 {
  char *a;
  char *b;
};

void goodSink(struct char2 *in) {
  if (in->a)
    *(in->a) = 'a';
}

void good2bad(struct char2 *in) {
  struct char2 *local = in;
  goodSink(local);
}

int main() {
  struct char2 *c2_alias;
  struct char2 *c2 = (struct char2 *)malloc(sizeof(struct char2));
  c2->a = (char *)malloc(sizeof(char));
  c2_alias = c2;

  free(c2->a);
  c2->a = NULL;

  good2bad(c2_alias);
  free(c2);
  c2 = NULL;
  return 0;
}
