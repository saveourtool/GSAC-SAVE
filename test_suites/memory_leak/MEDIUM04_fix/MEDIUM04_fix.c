/*
 * Based on CVE-2023-2700
 */

#include <malloc.h>

struct virPCIVirtualFunction {
  char *ifname;
  int *addr;
};

struct _virPCIVirtualFunctionList {
  struct virPCIVirtualFunction *functions;
  size_t nfunctions;
  size_t maxfunctions;
};

typedef struct _virPCIVirtualFunctionList virPCIVirtualFunctionList;
void virPCIVirtualFunctionListFree(virPCIVirtualFunctionList *list) {
  size_t i;

  if (!list)
    return;

  free(list->functions->ifname);
  free(list->functions->addr);
  free(list->functions);
  free(list);
}

int main() {

  virPCIVirtualFunctionList *list =
      (virPCIVirtualFunctionList *)malloc(sizeof(virPCIVirtualFunctionList));
  list->functions = (struct virPCIVirtualFunction *)malloc(sizeof(struct virPCIVirtualFunction));
  list->functions->ifname = (char *)malloc(sizeof(char));
  list->functions->addr = (int *)malloc(sizeof(int));
  virPCIVirtualFunctionListFree(list);

  return 0;
}
