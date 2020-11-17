#ifndef _SKIPLIST_H
#define _SKIPLIST_H
#include <stddef.h>
#include <stdlib.h>

#define MAX_LEVEL 32
#define LEVEL_PROB 0.25
#define container_of(ptr, type, member) \
  (type *)((char *)(ptr)-offsetof(type, member))

typedef struct skiplink {
  struct skiplink *prev;
  struct skiplink *next;
} skiplink;

typedef struct skiplist {
  int level;
  int length;

  skiplink entries[MAX_LEVEL];
} skiplist;

typedef struct skipnode {
  int key;
  int val;
  skiplink levels[0];
} skipnode;

//////// static
static void skipnode_destroy(skipnode *node) { free(node); }

static int random_level() {
  int level = 1;
  while ((rand() & 0xFFFF) < (LEVEL_PROB * 0xFFFF)) level++;
  return level;
}

static void _skiplist_remove(skiplist *list, skipnode *node, int level) {
  for (int i = 0; i < level; i++) {
    // delete the link in level i of node
    skiplink *link = &node->levels[i];
    skiplink *prev = link->prev;
    skiplink *next = link->next;
    prev->next = next;
    next->prev = prev;
    link->prev = link;
    link->next = link;

    // check if the level changed
    if (list->entries[i].next == &list->entries[i] && list->level > 1)
      list->level--;
  }
  skipnode_destroy(node);
  list->length--;
}

/////// static end

skiplist *skiplist_new() {
  skiplist *ret = (skiplist *)malloc(sizeof(skiplist));
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

  skipnode *ptr =
      (skipnode *)malloc(sizeof(skipnode) + sizeof(skiplink) * level);
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

void skiplist_remove(skiplist *list, int k) {
  // very similar to insertion, need to add extra check for list's level
  // this will delete all node with key: k
  // from top to down
  for (int i = list->level - 1; i >= 0; i--) {
    skiplink *entry = list->entries[i].next;
    skiplink *right = &list->entries[i];
    while (entry != right) {
      skipnode *node = container_of(entry, skipnode, levels[i]);
      if (node->key == k) {
        entry = entry->next;
        _skiplist_remove(list, node, i + 1);
      } else if (node->key < k) {
        entry = entry->next;
      } else {
        right = &node->levels[i];
        break;
      }
    }
  }
}

const skipnode *skiplist_find(skiplist *list, int k) {
  // will return first found node with key: k
  for (int i = list->level - 1; i >= 0; i--) {
    skiplink *entry = list->entries[i].next;
    skiplink *right = &list->entries[i];
    while (entry != right) {
      skipnode *node = container_of(entry, skipnode, levels[i]);
      if (node->key == k) {
        return node;
      } else if (node->key < k) {
        entry = entry->next;
      } else {
        right = &node->levels[i];
        break;
      }
    }
  }
  return NULL;
}

#endif
