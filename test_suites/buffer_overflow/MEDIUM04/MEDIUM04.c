/*
 * Based on CVE-2023-38559
 */
#include <stdlib.h>

void devn_pcx_write_rle(const char *from, const char *end, int step) {
  while (from < end) {
    char data = *from;

    from += step;
    // Access to 'from' is out of range
    if (data != *from || from == end) { // buffer-overflow
      return;
    }
    from += step;
  }
}

int main() {
  char *a = malloc(sizeof(char));
  a[0] = 'a';
  devn_pcx_write_rle(a, a + 4, 4);
}
