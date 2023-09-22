/*
 * from juliet test suite, CWE416_Use_After_Free__malloc_free_struct_18
 */

#include <stdlib.h>
#include <time.h>
#include <wchar.h>

struct twoIntsStruct {
  int intOne;
  int intTwo;
};

void CWE416_Use_After_Free__malloc_free_struct_18_bad() {
  struct twoIntsStruct *data;
  data = NULL;
  goto source;
source:
  data = (struct twoIntsStruct *)malloc(100 * sizeof(struct twoIntsStruct));
  if (data == NULL) {
    exit(-1);
  }
  {
    size_t i;
    for (i = 0; i < 100; i++) {
      data[i].intOne = 1;
      data[i].intTwo = 2;
    }
  }
  free(data);
  data = NULL;
  goto sink;
sink:
  if (data != NULL)
    data[99].intOne = -1;
}

int main(int argc, char *argv[]) {
  srand((unsigned)time(NULL));
  CWE416_Use_After_Free__malloc_free_struct_18_bad();
  return 0;
}
