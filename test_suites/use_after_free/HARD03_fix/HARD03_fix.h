#ifndef HARD03_FIX_H
#define HARD03_FIX_H

struct listNode {
  int id;
  char *data;
  struct listNode *next;
};

int accessByIDGood(struct listNode *node, int id);
struct listNode *allocSite(int id);
void freeDataByID(struct listNode *node, int id);
void freeList(struct listNode *root);

#endif