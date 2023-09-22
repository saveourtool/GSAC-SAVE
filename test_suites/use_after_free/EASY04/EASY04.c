#include <stdlib.h>
#include <time.h>

struct char2 {
  char *a;
  char *b;
};

int main() {
  struct char2 *c2_alias;
  struct char2 *c2 = (struct char2 *)malloc(sizeof(struct char2));
  c2->a = (char *)malloc(sizeof(char)); // Memory allocation
  c2_alias = c2;
  time_t seconds = time(NULL);
  free(c2->a); // Free memory which was allocated in 'c2->a'
  if (seconds >= 0)
    *(c2_alias->a) = 'a'; // Use after free
  if (seconds < 0)
    *(c2_alias->b) = 'b';
  free(c2);
  return 0;
}
