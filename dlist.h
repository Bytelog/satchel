#pragma once
#include <stdbool.h>
#include <stdlib.h>
#include "common.h"

typedef struct dlist_node dlist_node;
typedef struct dlist dlist;
typedef struct dlist dlist_it;

struct dlist_node {
  void *data;
  dlist_node *prev;
  dlist_node *next;
};

struct dlist {
  dlist_node *front;
  dlist_node *back;
};