#include <stdlib.h>

struct char2 {
  char *a;
  char *b;
};

struct char2 *c2;

void freeC2B() {
  if (c2 != NULL && c2->b != NULL) {
    free(c2->b);
    c2->b = NULL;
  }
}

void freeC2A() {
  if (c2 != NULL && c2->a != NULL) {
    free(c2->a);
    c2->a = NULL;
  }
}

void setC2A() {
  if (c2->a) {
    *(c2->a) = 'a';
  }
}

int main() {
  c2 = (struct char2 *)malloc(sizeof(struct char2));
  c2->a = (char *)malloc(sizeof(char));
  c2->b = (char *)malloc(sizeof(char));

  setC2A();
  freeC2B();
  freeC2A();
  free(c2);

  return 0;
}
