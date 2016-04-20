#pragma once
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

typedef struct vec vec;

struct vec {
  void const **data;
  size_t size;
  size_t count;
};

void const *vec_get(vec *v, size_t n) { return v->data[n]; }

void vec_init(vec *v) {
  v->data = NULL;
  v->size = 0;
  v->count = 0;
}

static inline void *vec_grow(vec *v) {
  if (v->count == v->size) {
    v->size = next_pow2(v->size + 1);
    v->data = realloc(v->data, sizeof(void *) * v->size);
  }
  return v->data;
}

bool vec_push(vec *v, void const *e) {
  if (!vec_grow(v)) return false;
  v->data[v->count++] = e;
  return true;
}

void vec_pop(vec *v) { v->count--; }

bool vec_insert(vec *v, size_t pos, void const *val) {
  if (!vec_grow(v)) return false;
  memmove(&v->data[pos + 1], &v->data[pos],
          sizeof(void *) * (v->count - pos));
  v->data[pos] = val;
  v->count++;
  return true;
}

void vec_erase(vec *v, size_t pos) {
  v->count--;
  memmove(&v->data[pos], &v->data[pos + 1],
          sizeof(void *) * (v->count - pos));
}

void vec_clear(vec *v) { v->count = 0; }

void vec_free(vec *v) { free(v->data); }
