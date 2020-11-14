#include "skiplist.h"

#include <stddef.h>
#include <stdlib.h>

#define container_of(ptr, type, member) \
  (type *)((char *)(ptr)-offsetof(type, member))

#define LEVEL_PROB 0.25

static void skipnode_destroy(skipnode *node) { free(node); }
static int random_level() {
  int level = 1;
  while ((rand() & 0xFFFF) < (LEVEL_PROB * 0xFFFF)) level++;
  return level;
}

skiplist *skiplist_new() {
  skiplist *ret = malloc(sizeof(skiplist));
  if (ret) {
    ret->length = 0;
    ret->level = 1;
    for (int i = 0; i < sizeof(ret->entries) / sizeof(ret->entries[0]); i++) {
      ret->entries[i].prev = &ret->entries[i];
      ret->entries[i].next = &ret->entries[i];
    }
  }

  return ret;
}

void skiplist_destroy(skiplist *list) {
  skiplink *next;
  skiplink *pos = list->entries[0].next;
  skiplink *end = &list->entries[0];

  for (next = pos->next; pos != end; pos = next, next = next->next) {
    skipnode *node = container_of(pos, skipnode, levels[0]);
    skipnode_destroy(node);
  }
  free(list);
}

skipnode *skiplist_insert(skiplist *list, int k, int v) {
  int level = random_level();
  if (level > list->level) {
    list->level = level;
  }

  skipnode *ptr = malloc(sizeof(skipnode) + sizeof(skiplink) * level);
  if (ptr) {
    ptr->key = k;
    ptr->val = v;

    // top-down search
    for (int i = list->level - 1; i >= 0; i--) {
      skiplink *entry = list->entries[i].next;
      skiplink *right = &list->entries[i];

      while (entry != right) {
        skipnode *node = container_of(entry, skipnode, levels[i]);
        if (node->key < k) {
          entry = entry->next;
        } else {
          right = &node->levels[i];
          break;
        }
      }

      if (i < level) {
        skiplink *left = right->prev;
        ptr->levels[i].next = right;
        ptr->levels[i].prev = left;
        right->prev = &ptr->levels[i];
        left->next = &ptr->levels[i];
      }
    }
    list->length++;
  }
  return ptr;
}