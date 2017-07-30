#pragma once
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

typedef struct svec svec;

struct svec {
  void **data;
  size_t size;
  size_t count;
};

void *svec_get(svec *, size_t);
size_t svec_count(svec *);
void svec_init(svec *);
bool svec_push(svec *, void *);
void svec_pop(svec *);
bool svec_insert(svec *, size_t, void *);
void svec_erase(svec *, size_t);
void svec_clear(svec *);
void svec_free(svec *);

void *svec_get(svec *v, size_t n) { return v->data[n]; }
size_t svec_count(svec *v) { return v->count; }

void svec_init(svec *v) {
  v->data = NULL;
  v->size = 0;
  v->count = 0;
}

static void *svec_grow(svec *v) {
  if (v->count == v->size) {
    v->size = next_pow2(v->size + 1);
    v->data = realloc(v->data, sizeof(void *) * v->size);
  }
  return v->data;
}

bool svec_push(svec *v, void *e) {
  if (unlikely(!svec_grow(v))) return false;
  svec_grow(v);
  v->data[v->count++] = e;
  return true;
}

void svec_pop(svec *v) { v->count--; }

bool svec_insert(svec *v, size_t pos, void *e) {
  if (unlikely(!svec_grow(v))) return false;
  memmove(&v->data[pos + 1], &v->data[pos],
          sizeof(void *) * (v->count - pos));
  v->data[pos] = e;
  v->count++;
  return true;
}

void svec_erase(svec *v, size_t pos) {
  v->count--;
  memmove(&v->data[pos], &v->data[pos + 1],
          sizeof(void *) * (v->count - pos));
}

void svec_clear(svec *v) { v->count = 0; }

void svec_free(svec *v) { free(v->data); }
