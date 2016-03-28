#pragma once

#include "common.h"
#include <stdbool.h>

typedef struct list_item_t list_item;
typedef struct forward_list_item_t forward_list_item;
typedef struct circular_list_item_t circular_list_item;

typedef struct list_t list;
typedef struct forward_list_t forward_list;
typedef struct circular_list_t circular_list;

typedef struct list_it_t list_it;
typedef struct forward_list_it_t forward_list_it;
typedef struct circular_list_it_t circular_list_it;

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

/*
void const *queue_front(queue *q);
void queue_init(queue *q);
bool queue_push(queue *q, void const *e);
void queue_pop(queue *q);
void queue_free(queue *q);
*/