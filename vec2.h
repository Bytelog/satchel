#pragma once
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

#define sv_t(type) struct {													\
	size_t size, count;														\
	type *data;																\
}

#define sv_init(v) do {														\
	(v).size = 0;															\
	(v).count = 0;															\
	(v).data = NULL;														\
} while(0)

#define sv_get(v, i) do {													\
	(v).data[(i)];															\
} while(0)

#define sv_count(v) do {													\
	(v).count;																\
} while(0)

#define _sv_grow(type, v) do {												\
	if ((v).count == (v).size) {											\
		(v).size = next_pow2((v).size + 1);									\
		(v).data = realloc((v).data, sizeof(type) * (v).size);				\
	}																		\
	(v).data;																\
} while(0)

// TODO: Figure out how to return bools
#define sv_push(type, v, e) do {											\
	if (unlikely(_sv_grow(v))) break;										\
	(v).data[(v).count++] = e;												\																		\
	true;																	\
} while(0)

void vec_pop(vec *);
bool vec_insert(vec *, size_t, void *);
void vec_erase(vec *, size_t);
void vec_clear(vec *);
void vec_free(vec *);


bool vec_push(vec *v, void *e) {
	if (unlikely(!vec_grow(v))) return false;
	vec_grow(v);
	v->data[v->count++] = e;
	return true;
}

void vec_pop(vec *v) { v->count--; }

bool vec_insert(vec *v, size_t pos, void *e) {
	if (unlikely(!vec_grow(v))) return false;
	memmove(&v->data[pos + 1], &v->data[pos],
					sizeof(void *) * (v->count - pos));
	v->data[pos] = e;
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
