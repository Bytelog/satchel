#include <assert.h>
#include <stdio.h>
#include "vec.h"

int main(int argc, char **argv)
{
    vec v;
    vec_init(&v);
    vec_push(&v, 5);
    assert(vec_get(&v, 0) == 5);

    vec_insert(&v, 0, 0);
    assert(vec_get(&v, 0) == 0);

    vec_pop(&v);
    vec_push(&v, 1);
    assert(vec_get(&v, 1) == 1);

    vec_push(&v, 2);
    vec_push(&v, 3);
    vec_push(&v, 4);
    vec_push(&v, 4);
    vec_erase(&v, 4);

    assert(v.size == 8);
    assert(v.count == 5);

    for(int i=0; i < v.count; ++i) {
        assert(vec_get(&v, i) == i);
    }
}

