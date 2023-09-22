/*
 * Based on CVE-2022-26878
 */

#include <stdlib.h>

void virtbt_rx_handle(int pkt_type, char *skb) {
  switch (pkt_type) {
  case 1:
  case 2:
  case 3:
  case 4:
    free(skb);
    break;
  }
}

int main() {
  char *buffer = (char *)malloc(40); // Memory allocation

  virtbt_rx_handle(5, buffer);
} // Allocated memory for 'buffer' is not freed
