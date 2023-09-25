#include "HARD03_fix.h"
#include <stdlib.h>

struct listNode *root;

int accessByIDGood(struct listNode *node, int id) {
  while (node) {
    if (node->id == id && node->data != NULL)
      return *(node->data);
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
    if (node->id == id) {
      free(node->data);
      node->data = NULL;
    }
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
  root = allocSite(0);
  root->next = allocSite(1);
  root->next->next = allocSite(2);
  freeDataByID(root, 1);
  accessByIDGood(root, 1);
  freeDataByID(root, 0);
  freeDataByID(root, 2);
  freeList(root);
  return 0;
}
