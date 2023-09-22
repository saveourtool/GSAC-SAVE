#include "HARD02.h"
#include <stdlib.h>

struct char2 *c2;

void allocSite() {
  c2 = (struct char2 *)malloc(sizeof(struct char2));
  c2->a = (char *)malloc(sizeof(char));
  c2->b = (char *)malloc(sizeof(char)); // Memory allocation
}

void freeSite() { free(c2->a); }

int main() {
  allocSite();
  freeSite(); // Allocated memory for 'c2->a' is freed
  free(c2);   // Allocated memory for 'c2' is freed
  return 0;   // Return without freeing 'c2->b'
}
