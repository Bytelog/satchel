#include "include/vec.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static void* s_vec_grow(s_vec*);

void* s_vec_get(s_vec* v, size_t n) {
    return v->data[n];
}

size_t s_vec_count(s_vec* v) {
    return v->count;
}

void s_vec_init(s_vec* v) {
    v->data = NULL;
    v->size = 0;
    v->count = 0;
}

bool s_vec_push(s_vec* v, void* item) {
    if (!s_vec_grow(v)) {
        return false;
    }
    v->data[v->count++] = item;
    return true;
}

void s_vec_pop(s_vec* v) {
    --(v->count);
}

bool s_vec_insert(s_vec* v, size_t pos, void* item) {
    if (!s_vec_grow(v)) {
        return false;
    }
    memmove(&v->data[pos + 1], &v->data[pos], sizeof(void*) * (v->count - pos));
    v->data[pos] = item;
    ++(v->count);
    return true;
}

void s_vec_erase(s_vec* v, size_t pos) {
    v->count--;
    memmove(&v->data[pos], &v->data[pos + 1], sizeof(void*) * (v->count - pos));
}

void s_vec_clear(s_vec* v) { v->count = 0; }

void s_vec_free(s_vec* v) { free(v->data); }

static void* s_vec_grow(s_vec* v) {
    if (v->count == v->size) {
        v->size = next_pow2(v->size + 1);
        v->data = realloc(v->data, sizeof(void*) * v->size);
    }
    return v->data;
}
