/*
 * Based on CVE-2022-33105 (fixed)
 */

#include <limits.h>
#include <stdlib.h>

typedef unsigned long int uint64_t;
typedef unsigned int uint32_t;

typedef struct raxIterator {
  unsigned char *key;
} raxIterator;

typedef struct raxStack {
  void **stack;
} raxStack;

typedef struct streamIterator {
  raxIterator ri;
  raxStack stack;
  int id;
} streamIterator;

void streamIteratorStart(streamIterator *si) {
  si->ri.key = malloc(sizeof(unsigned char));
  si->stack.stack = malloc(sizeof(void *));
  si->id = 0;
}

int streamIteratorGetID(streamIterator *si, int id) {
  int ans = 0;
  if (id == si->id)
    ++ans;
  return ans;
}

void streamIteratorStop(streamIterator *si) {
  free(si->ri.key);
  free(si->stack.stack);
}

void streamGetEdgeID(int *edge_id, int first) {
  streamIterator si;
  streamIteratorStart(&si);
  int found = streamIteratorGetID(&si, *edge_id);
  if (!found) {
    int min_id = 0, max_id = INT_MAX;
    *edge_id = first ? max_id : min_id;
  }
  streamIteratorStop(&si);
}

int main() {
  int edge_id = 3;
  streamGetEdgeID(&edge_id, 6);
}
