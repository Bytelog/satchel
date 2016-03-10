#pragma once

typedef struct vec_iterator_t vec_iterator;
typedef struct vec_t vec;

struct vec_iterator_t
{
    void **array;
};

struct vec_t
{
    void **array;
    size_t size;
    size_t count;
};

void * vec_get(vec *v, size_t n);

void vec_init(vec *v);
void vec_push(vec *v, void *e);
void vec_pop(vec *v);
void vec_insert(vec *v, vec_iterator *it, const void *e);
void vec_erase(vec *v, vec_iterator *it);
void vec_clear(vec *v);
void vec_free(vec *v);
