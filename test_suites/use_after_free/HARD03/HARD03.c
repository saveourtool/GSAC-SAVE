#include "HARD03.h"
#include <stdlib.h>

struct listNode *root;

int accessByIDBad(struct listNode *node, int id) {
  while (node) {
    if (node->id == id)
      return *(node->data); // Use after free
    node = node->next;
  }
  return -1;
}

struct listNode *allocSite(int id) {
  struct listNode *node = (struct listNode *)malloc(sizeof(struct listNode));
  node->id = id;
  node->data = (char *)malloc(sizeof(char));
  node->next = NULL;
  return node;
}

void freeDataByID(struct listNode *node, int id) {
  while (node) {
    if (node->id == id)
      free(node->data); // Free node's data by using 'id' number
    node = node->next;
  }
}

void freeList(struct listNode *root) {
  while (root) {
    struct listNode *temp = root->next;
    free(root);
    root = temp;
  }
}

int main() {
  // Make list by allocating memory
  root = allocSite(0);
  root->next = allocSite(1);
  root->next->next = allocSite(2);
  freeDataByID(root, 1);  // Free 'Data' when 'id' is 1
  accessByIDBad(root, 1); // Access memory with according number of 'id'
  freeDataByID(root, 0);
  freeDataByID(root, 2);
  freeList(root);
  return 0;
}
