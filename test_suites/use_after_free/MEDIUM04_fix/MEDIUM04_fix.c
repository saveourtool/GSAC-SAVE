/*
 * from juliet test suite, CWE416_Use_After_Free__malloc_free_struct_43
 */

#include <stdlib.h>
#include <time.h>
#include <wchar.h>

struct twoIntsStruct {
  int intOne;
  int intTwo;
};

static void badSource(struct twoIntsStruct **data_p) {
  struct twoIntsStruct *data = (struct twoIntsStruct *)malloc(100 * sizeof(struct twoIntsStruct));
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
  *data_p = data;
  free(*data_p);
  *data_p = NULL;
}

void bad() {
  struct twoIntsStruct *data;
  data = NULL;
  badSource(&data);
  if (data != NULL)
    data[0].intOne = -1;
}

int CWE416_Use_After_Free__malloc_free_struct_43() {
  srand((unsigned)time(NULL));
  bad();
  return 0;
}

int main() {
  CWE416_Use_After_Free__malloc_free_struct_43();
  return 0;
}
