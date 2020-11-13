#include <stdlib.h>

#include "skiplist.h"

int main() {
  skiplist *list = skiplist_new();
  for (int i = 0; i < 100; i++) {
    int n = rand() & 0xFF;
    skiplist_insert(list, i, n);
  }
  skiplist_destroy(list);
  return 0;
}
