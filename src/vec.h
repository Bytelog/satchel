#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

typedef struct vec_t vec;

struct vec_t
{
    void const **array;
    size_t size;
    size_t count;
};

void const *vec_get(vec *v, size_t n);

void vec_init(vec *v);
void vec_push(vec *v, void const *);
void vec_pop(vec *v);
void vec_insert(vec *v, size_t pos, void const *);
void vec_erase(vec *v, size_t pos);
void vec_clear(vec *v);
void vec_free(vec *v);
