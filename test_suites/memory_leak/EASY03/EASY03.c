/*
 * Based on CVE-2019-19062
 */

#include <stdlib.h>
#include <string.h>
#include <time.h>

struct sk_buff {
  int dev_scratch;
};

static int crypto_report_alg() {
  srand(time(NULL));
  return rand();
}

static int crypto_report() {
  struct sk_buff *skb;
  int err = 0;
  skb = malloc(sizeof(struct sk_buff)); // Memory allocation
  if (!skb)
    goto drop_alg;
  err = crypto_report_alg() % 3;
drop_alg:
  if (err) {
    return err; // Return without freeing 'skb'
  }

  int ret = skb->dev_scratch;
  free(skb);
  return ret;
}

int main() { crypto_report(); }
