#pragma once

#include "common.h"
#include <stdbool.h>

typedef struct list_item_t list_item;
typedef struct list_t list;
typedef struct list_it_t list_it;

struct list_item_t {
  void const *e;
  size_t next;
};

struct list_t {
  list_item *array;
  size_t size;
  size_t vacancy;
};

void list_init(list *l);
bool list_append(list *l, list_item *pos, void const *e);
void list_free(list *l);
