#pragma once
#include <stdbool.h>
#include <stdlib.h>
#include "common.h"

typedef struct forward_list_item forward_list_item;
typedef struct forward_list forward_list;
typedef struct forward_list_it forward_list_it;

struct forward_list_item {
  void const *e;
  forward_list_item
};

struct forward_list {
  forward_list_item *array;
  size_t *vacancy;
  size_t size;
};

void forward_list_init(forward_list *l, size_t max_items) {
  l->array = NULL;
  l->vacancy = NULL;
  l->size = 0;
}

static inline void *forward_list_grow(forward_list *l) {
  l->size = next_pow2(l->size + 1);
  // TODO: Broken
  l->vacancy |= l->size | l->size - 1;
  l->array = realloc(l->array, sizeof(forward_list_item) * l->size);
  return l->array;
}

forward_list_item const *forward_list_next(forward_list *l, forward_list_item *pos) {
  return &l->array[pos->next];
}

bool forward_list_insert(forward_list *l, forward_list_item *pos, void const *e) {
  if (!l->vacancy && !forward_list_grow(l)) return false;

  // TODO: Broken
  size_t location = l->vacancy & -l->vacancy;
  forward_list_item node = l->array[location];

  if (pos)
    node.next = pos - l->array;
  else
    node.next = 0;

  node.e = e;

  // TODO: Ensure working
  l->vacancy &= ~location;
  return true;
}

void forward_list_free(forward_list *l) { free(l->array); }
