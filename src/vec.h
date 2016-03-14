#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

typedef struct vec_t vec;

struct vec_t
{
    int *array;
    size_t size;
    size_t count;
};

int vec_get(vec *v, size_t n);

void vec_init(vec *v);
void vec_push(vec *v, int e);
void vec_pop(vec *v);
void vec_insert(vec *v, size_t pos, int e);
void vec_erase(vec *v, size_t pos);
void vec_clear(vec *v);
void vec_free(vec *v);
