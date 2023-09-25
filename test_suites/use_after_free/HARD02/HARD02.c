#include <stdlib.h>

struct char2 {
  char *a;
  char *b;
};

struct char2 *c2;

void bad() {
  *(c2->a) = 'a'; // Use after free
}

void allocSite() {
  c2 = (struct char2 *)malloc(sizeof(struct char2));
  c2->a = (char *)malloc(sizeof(char)); // Memory allocation
  c2->b = (char *)malloc(sizeof(char));
}

void freeC2aSite() {
  free(c2->a); // Free allocated memory for 'c2->a'
}
void freeC2bSite() { free(c2->b); }

int main() {
  allocSite(); // Memory allocation for struct pointer and pointer members
  freeC2aSite();
  bad();
  freeC2bSite();
  free(c2);
  return 0;
}
