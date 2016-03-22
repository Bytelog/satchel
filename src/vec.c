#include "vec.h"

void vec_init(vec *v) {
  v->array = NULL;
  v->size = 0;
  v->count = 0;
}

inline void const *vec_get(vec *v, size_t n) { return v->array[n]; }

void vec_push(vec *v, void const *e) {
  if (v->size == 0) {
    v->size = 1;
    v->array = malloc(sizeof(void *) * v->size);
  }

  if (v->size == v->count) {
    v->size *= 2;
    v->array = realloc(v->array, sizeof(void *) * v->size);
  }

  v->array[v->count] = e;
  v->count++;
}

void vec_free(vec *v) {
  free(v->array);
  v->array = NULL;
  v->size = 0;
  v->count = 0;
}

inline void vec_pop(vec *v) { v->count = MAX(v->count - 1, 0); }

void vec_insert(vec *v, size_t pos, void const *val) {
  if (v->size == v->count) {
    v->size *= 2;
    v->array = realloc(v->array, sizeof(void *) * v->size);
  }

  memmove(&v->array[pos + 1], &v->array[pos],
          sizeof(void *) * (v->count - pos));
  v->array[pos] = val;
  v->count++;
}

void vec_erase(vec *v, size_t pos) {
  v->count--;
  memmove(&v->array[pos], &v->array[pos + 1],
          sizeof(void *) * (v->count - pos));
}

inline void vec_clear(vec *v) { v->count = 0; }
