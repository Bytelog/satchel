#pragma once
#include <stdbool.h>
#include <stdlib.h>
#include "common.h"

typedef struct list_node list_node;
typedef struct list list;
typedef struct list list_it;

struct list_node {
  void *data;
  list_node *next;
};

struct list {
  list_node *item;
};

void list_front(list *l, list_it *it) { it = l; }
void *list_get(list *l, list_it *it) { return it->item; }
void list_next(list *l, list_it *it) { it->item = it->item->next; }

void list_next_wrap(list *l, list_it *it) {
  it->item = it->item->next;
  if (!it->item) it->item = l->item;
}

bool list_init(list *l) {
  if (!(l->item = malloc(sizeof(list_node))))
    return false;

  l->item->data = NULL;
  l->item->next = NULL;
  return true;
}

bool list_insert_after(list *l, list_it *it, void *e) {
  list_node *head;
  if (!(head = malloc(sizeof(list_node))))
    return false;

  head->data = e;
  head->next = it->item->next;
  return true;
}

void list_erase_after(list *l, list_it *it) {
  if (!it->item->next)
    return;

  list_node *trash = it->item->next;
  it->item->next = it->item->next->next;
  free(trash);
}

bool list_push_front(list *l, void *e) {
  list_node *tail;
  if (!(tail = malloc(sizeof(list_node))))
    return false;

  tail->data = e;
  tail->next = l->item;
  l->item = tail;
  return true;
}

void list_pop_front(list *l) {
  list_node *trash = l->item;
  free(trash);
}
 
void list_free(list *l) {
  while(l->item->next)
    list_erase_after(l, l);
  free(l->item);
}
