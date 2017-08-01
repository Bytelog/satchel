#pragma once
#include <stdbool.h>
#include <stdlib.h>
#include "common.h"

typedef struct s_dlist_node s_dlist_node;
typedef struct s_dlist s_dlist;
typedef struct s_dlist s_dlist_it;

struct s_dlist_node {
    void* data;
    s_dlist_node* prev;
    s_dlist_node* next;
};

struct s_dlist {
    s_dlist_node* front;
    s_dlist_node* back;
};
