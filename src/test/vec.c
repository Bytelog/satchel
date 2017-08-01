#include "include/vec.h"
#include <assert.h>
#include <limits.h>
#include <stdint.h>

#define FROM_UINT void *)(uintptr_t
#define TO_UINT size_t)(uintptr_t const *
#define STRESS_VALUE USHRT_MAX

#include <time.h>
#include <stdio.h>

int main(void) {

    // Basic usage tests
    s_vec v;
    s_vec_init(&v);
    assert(s_vec_count(&v) == 0);

    s_vec_push(&v, (FROM_UINT) 10);
    assert((TO_UINT) s_vec_get(&v, 0) == 10);
    assert(s_vec_count(&v) == 1);

    s_vec_insert(&v, 0, (FROM_UINT) 5);
    assert((TO_UINT) s_vec_get(&v, 0) == 5);
    assert((TO_UINT) s_vec_get(&v, 1) == 10);
    assert(s_vec_count(&v) == 2);

    s_vec_erase(&v, 1);
    assert((TO_UINT) s_vec_get(&v, 0) == 5);
    assert(s_vec_count(&v) == 1);

    s_vec_pop(&v);
    assert(s_vec_count(&v) == 0);

    s_vec_push(&v, (FROM_UINT) 15);
    s_vec_push(&v, (FROM_UINT) 15);
    s_vec_push(&v, (FROM_UINT) 15);
    s_vec_clear(&v);
    assert(s_vec_count(&v) == 0);

    s_vec_free(&v);

    // Stress testing
    s_vec_init(&v);
    for (size_t i = 0; i < STRESS_VALUE; ++i)
        s_vec_push(&v, (FROM_UINT) i);

    for (size_t i = 0; i < STRESS_VALUE; ++i)
        assert((TO_UINT) s_vec_get(&v, i) == i);

    for (size_t i = 0; i < s_vec_count(&v); i += 1)
        s_vec_erase(&v, i);

    for (size_t i = 0; i < STRESS_VALUE; i += 2)
        s_vec_insert(&v, i, (FROM_UINT) i);

    for (size_t i = 0; i < STRESS_VALUE; ++i)
        assert((TO_UINT) s_vec_get(&v, i) == i);

    s_vec_free(&v);
}
