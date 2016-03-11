#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "vec.h"

void vec_init(vec *v)
{
    v->array = NULL;
    v->size = 0;
    v->count = 0;
}

int vec_get(vec *v, size_t n)
{
    return v->array[n];
}

void vec_push(vec *v, int e)
{
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

void vec_free(vec *v)
{
    free(v->array);
    v->array = NULL;
    v->size = 0;
    v->count = 0;
}


int main()
{   
    vec v;
    vec_init(&v);

    for(int i=0; i < 100; ++i) {
        vec_push(&v, i);
    }

    for(size_t i=0; i < 100; ++i) {
        printf("%i\n", vec_get(&v, i));
    }

    vec_free(&v);
}
