#pragma once
#include <stdbool.h>
#include <stdlib.h>
#include "common.h"

typedef struct list_node list_node;
typedef struct list list;

struct list_node {
  void *data;
  list_node *next;
};

struct list {
  list_node *first;
  list_node *last;
};

void *list_front(list *l) { return l->first->data; }
void *list_back(list *l) { return l->last->data; }
void *list_get(list_node *n) { return n->data; }
size_t list_count(list *l) { return (l->last - l->first) + 1; }

bool list_init(list *l) {
  if (!(l->first = malloc(sizeof(list_node))))
    return false;

  l->last = l->first;
  l->first->data = NULL;
  l->first->next = NULL;
  return true;
}

list_node *list_node_next(list_node *n) { return n->next; }

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

bool list_insert_after(list_node *n, void *e) {
  list_node *head;
  if (!(head = malloc(sizeof(list_node))))
    return false;

  head->data = e;
  head->next = n->next;
  return true;
}

void list_erase_after(list_node *n) {
  if (!n->next)
    return;

  list_node *trash = n->next;
  n->next = n->next->next;
  free(trash);
}

void list_free(list *l) {
  while(l->first->next)
    list_erase_after(l->first);
  free(l->first);
}
