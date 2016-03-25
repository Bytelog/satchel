#include "vec.h"
#include "common.h"
#include <stdlib.h>
#include <string.h>

void vec_init(vec *v) {
  v->array = NULL;
  v->size = 0;
  v->count = 0;
}

static inline void vec_grow(vec *v) {
  if (v->count == v->size) {
    v->size = next_pow2(v->size + 1);
    v->array = realloc(v->array, sizeof(void *) * v->size);
  }
}

void const *vec_get(vec *v, size_t n) { return v->array[n]; }

bool vec_push(vec *v, void const *e) {
  vec_grow(v);
  if (!v->array)
    return false;
  v->array[v->count] = e;
  v->count++;
  return true;
}

void vec_pop(vec *v) { v->count--; }

bool vec_insert(vec *v, size_t pos, void const *val) {
  vec_grow(v)
  if (!v->array)
    return false;
  memmove(&v->array[pos + 1], &v->array[pos],
          sizeof(void *) * (v->count - pos));
  v->array[pos] = val;
  v->count++;
  return true;
}

void vec_erase(vec *v, size_t pos) {
  v->count--;
  memmove(&v->array[pos], &v->array[pos + 1],
          sizeof(void *) * (v->count - pos));
}

void vec_clear(vec *v) { v->count = 0; }

void vec_free(vec *v) {
  free(v->array);
  v->array = NULL;
}
