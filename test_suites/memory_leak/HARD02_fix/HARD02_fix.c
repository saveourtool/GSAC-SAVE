#include "HARD02_fix.h"
#include <stdlib.h>

struct char2 *c2;

void allocSite() {
  c2 = (struct char2 *)malloc(sizeof(struct char2));
  c2->a = (char *)malloc(sizeof(char));
  c2->b = (char *)malloc(sizeof(char));
}

void freeSite() {
  free(c2->a);
  free(c2->b);
}

int main() {
  allocSite();
  freeSite();
  free(c2);
  return 0;
}