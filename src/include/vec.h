#pragma once

#include "common.h"

#include <stdbool.h>
#include <stdlib.h>

typedef struct s_vec s_vec;

struct s_vec {
    void** data;
    size_t size;
    size_t count;
};

void* s_vec_get(s_vec*, size_t);

size_t s_vec_count(s_vec*);

void s_vec_init(s_vec*);

bool s_vec_push(s_vec*, void* item);

void s_vec_pop(s_vec*);

bool s_vec_insert(s_vec*, size_t, void* item);

void s_vec_erase(s_vec*, size_t);

void s_vec_clear(s_vec*);

void s_vec_free(s_vec*);
