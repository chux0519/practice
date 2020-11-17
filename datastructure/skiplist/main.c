#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "skiplist.h"

int main() {
  skiplist *list = skiplist_new();
  for (int i = 1; i < 100; i++) {
    // int n = rand() & 0xFF;
    int n = i;
    skiplist_insert(list, i, n);
  }

  for (int i = 1; i < 100; i++) {
    const skipnode *node = skiplist_find(list, i);
    assert(node != NULL);
    assert(node->key == i);
    assert(node->val == i);
    printf("found node: (%d, %d)\n", node->key, node->val);
  }
  skiplist_destroy(list);
  return 0;
}
