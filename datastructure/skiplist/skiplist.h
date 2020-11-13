#ifndef _SKIPLIST_H
#define _SKIPLIST_H

#define MAX_LEVEL 32

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

skiplist *skiplist_new();
void skiplist_destroy(skiplist *list);
skipnode *skiplist_insert(skiplist *list, int k, int v);
void skiplist_remove(skiplist *list, int k);

#endif
