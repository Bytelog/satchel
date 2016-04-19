#pragma once
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include "common.h"

#ifndef MAX_ITEMS
#define MAX_ITEMS 64
#endif

#define VACANCY_LIST_SIZE (MAX_ITEMS / sizeof(size_t)*CHAR_BIT

typedef struct list_item_t list_item;
typedef struct list_t list;
typedef struct list_it_t list_it;

struct list_item_t {
  void const *e;
  size_t next;
};

struct list_t {
  list_item *array;
  size_t *vacancy;
  size_t size;
};

void list_init(list *l, size_t max_items) {
  l->array = NULL;
  l->vacancy = NULL;
  l->size = 0;
}

static inline void *list_grow(list *l) {
  l->size = next_pow2(l->size + 1);
  // TODO: Broken
  l->vacancy |= l->size | l->size - 1;
  l->array = realloc(l->array, sizeof(list_item) * l->size);
  return l->array;
}

list_item const *list_next(list *l, list_item *pos) {
  return &l->array[pos->next];
}

bool list_insert(list *l, list_item *pos, void const *e) {
  if (!l->vacancy && !list_grow(l)) return false;

  // TODO: Broken
  size_t location = l->vacancy & -l->vacancy;
  list_item node = l->array[location];

  if (pos)
    node.next = pos - l->array;
  else
    node.next = 0;

  node.e = e;

  // TODO: Ensure working
  l->vacancy &= ~location;
  return true;
}

void list_free(list *l) { free(l->array); }
