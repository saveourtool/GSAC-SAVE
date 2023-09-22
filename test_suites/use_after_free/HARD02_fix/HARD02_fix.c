#include <stdlib.h>

struct char2 {
  char *a;
  char *b;
};

struct char2 *c2;

void bad() {
  if (c2->a != NULL) {
    *(c2->a) = 'a';
  }
}

void allocSite() {
  c2 = (struct char2 *)malloc(sizeof(struct char2));
  c2->a = (char *)malloc(sizeof(char));
  c2->b = (char *)malloc(sizeof(char));
}

void freeC2aSite() {
  free(c2->a);
  c2->a = NULL;
}
void freeC2bSite() {
  free(c2->b);
  c2->b = NULL;
}

int main() {
  allocSite();
  freeC2aSite();
  bad();
  freeC2bSite();
  free(c2);
  return 0;
}
