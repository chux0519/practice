#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "skiplist.h"

int main() {
  skiplist *list = skiplist_new();
  for (int i = 1; i < 100; i++) {
    // int n = rand() & 0xFF;
    skiplist_insert(list, i, i);
  }

  for (int i = 1; i < 100; i++) {
    const skipnode *node = skiplist_find(list, i);
    assert(node != NULL);
    assert(node->key == i);
    assert(node->val == i);
  }
  printf("passed: insert and search\n");

  for (int i = 1; i < 100; i++) {
    skiplist_remove(list, i);
  }
  printf("passed: remove\n");
  for (int i = 1; i < 100; i++) {
    const skipnode *node = skiplist_find(list, i);
    assert(node == NULL);
  }
  assert(list->length == 0);
  assert(list->level == 1);

  skiplist_destroy(list);
  return 0;
}
