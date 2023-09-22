#ifndef HARD03_H
#define HARD03_H

struct listNode {
  int id;
  char *data;
  struct listNode *next;
};

int accessByIDBad(struct listNode *node, int id);
struct listNode *allocSite(int id);
void freeDataByID(struct listNode *node, int id);
void freeList(struct listNode *root);

#endif // HARD03_H