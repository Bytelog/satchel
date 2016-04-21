#include "vec.h"
#include <assert.h>
#include <limits.h>
#include <stdint.h>

#define FROM_UINT void *)(uintptr_t
#define TO_UINT size_t)(uintptr_t const *
#define STRESS_VALUE USHRT_MAX

int main(void) {
  
  // Basic usage tests
  vec v;
  vec_init(&v);
  assert(vec_count(&v) == 0);

  vec_push(&v, (FROM_UINT) 10);
  assert((TO_UINT) vec_get(&v, 0) == 10);
  assert(vec_count(&v) == 1);

  vec_insert(&v, 0, (FROM_UINT) 5);
  assert((TO_UINT) vec_get(&v, 0) == 5);
  assert((TO_UINT) vec_get(&v, 1) == 10);
  assert(vec_count(&v) == 2);

  vec_erase(&v, 1);
  assert((TO_UINT) vec_get(&v, 0) == 5);
  assert(vec_count(&v) == 1);

  vec_pop(&v);
  assert(vec_count(&v) == 0);

  vec_push(&v, (FROM_UINT) 15);
  vec_push(&v, (FROM_UINT) 15);
  vec_push(&v, (FROM_UINT) 15);
  vec_clear(&v);
  assert(vec_count(&v) == 0);

  vec_free(&v);

  // Stress testing
  vec_init(&v);
  for (size_t i = 0; i < STRESS_VALUE; ++i)
    vec_push(&v, (FROM_UINT) i);

  for (size_t i = 0; i < STRESS_VALUE; ++i)
    assert((TO_UINT) vec_get(&v, i) == i);

  for (size_t i = 0; i < vec_count(&v); i += 1)
    vec_erase(&v, i);

  for (size_t i = 0; i < STRESS_VALUE; i += 2)
    vec_insert(&v, i, (FROM_UINT) i);

  for (size_t i = 0; i < STRESS_VALUE; ++i)
    assert((TO_UINT) vec_get(&v, i) == i);
  
  vec_free(&v);
}
