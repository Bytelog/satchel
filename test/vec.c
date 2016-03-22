#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include "vec.h"

#define INT int)(intptr_t const *

int main(void)
{
    vec v;
    vec_init(&v);
    vec_push(&v, (void *) 5);
    assert((INT) vec_get(&v, 0) == 5);
    
    vec_insert(&v, 0, (void *) 0);
    assert((INT) vec_get(&v, 0) == 0);

    vec_pop(&v);
    vec_push(&v, (void *) 1);
    assert((INT) vec_get(&v, 1) == 1);

    vec_push(&v, (void *) 2);
    vec_push(&v, (void *) 3);
    vec_push(&v, (void *) 4);
    vec_push(&v, (void *) 4);
    vec_erase(&v, 4);

    assert(v.size == 8);
    assert(v.count == 5);

    for(size_t i=0; i < v.count; ++i) {
        assert((INT) vec_get(&v, i) == (int) i);
    }
    
    vec_free(&v);
}

