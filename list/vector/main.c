#include <stdio.h>
#include <stdlib.h>
#include "vec.h"

void vec_init(vec *v)
{
    v->array = NULL;
    v->size = 0;
    v->count = 0;
}

void * vec_get(vec *v, size_t n)
{
    return v->array[n];
}

void vec_push(vec *v, void *e)
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


int main()
{   
    vec v;
    vec_init(&v);
    vec_push(&v, (void *) 6);
    vec_push(&v, (void *) 20);
    vec_push(&v, (void *) 120);
    printf("Vector Entry: %i; Size: %i\n", (int) vec_get(&v, 0), (int) v.size);
}
