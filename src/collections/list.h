#pragma once
#include <stdbool.h>
#include <stdlib.h>
#include "common.h"

typedef struct list_node list_node;
typedef struct list list;
typedef struct list_it list_it;

struct list_node {
  void *data;
  list_node *next;
};

struct list {
  list_node *first;
};

struct list_it {
  list_node *item;
};

void list_front(list *l, list_it *it) { it->item = l->first; }
void *list_get(list *l, list_it *it) { return it->item; }
void list_advance(list *l, list_it *it) { it->item = it->item->next; }

bool list_init(list *l) {
  if (!(l->first = malloc(sizeof(list_node))))
    return false;

  l->first->data = NULL;
  l->first->next = NULL;
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
  tail->next = l->first;
  l->first = tail;
  return true;
}

void list_pop_front(list *l) {
  list_node *trash = l->first;
  free(trash);
}

void list_free(list *l) {
  list_it it;
  list_front(l, &it);
  while(l->first->next)
    list_erase_after(l, &it);
  free(l->first);
}
