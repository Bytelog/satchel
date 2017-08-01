#pragma once

#include <stdbool.h>

typedef struct s_list_node s_list_node;

typedef struct s_list s_list;

typedef struct s_list s_list_it;

struct s_list_node {
    void* data;
    s_list_node* next;
};

struct s_list {
    s_list_node* item;
};

void* list_front(s_list* l, list_it* it);

void* list_get(s_list* l, list_it* it);

void list_next(s_list* l, list_it* it);

void list_next_wrap(s_list* l, list_it* it);

bool list_init(s_list* l);

bool list_insert_after(s_list* l, list_it* it, void* item);

void list_erase_after(s_list* l, list_it* it);

bool list_push_front(s_list* l, void* item);

void list_pop_front(s_list* l);

void list_free(s_list* l);
