#include "vec.h"
#include <assert.h>
#include <stdint.h>

#define FROM_INT void *)(intptr_t
#define TO_INT int)(intptr_t const *

int main(void) {
  vec v;
  vec_init(&v);
  vec_push(&v, (FROM_INT)5);
  assert((TO_INT)vec_get(&v, 0) == 5);

  vec_insert(&v, 0, (FROM_INT)0);
  assert((TO_INT)vec_get(&v, 0) == 0);

  vec_pop(&v);
  vec_push(&v, (FROM_INT)1);
  assert((TO_INT)vec_get(&v, 1) == 1);

  vec_push(&v, (FROM_INT)2);
  vec_push(&v, (FROM_INT)3);
  vec_push(&v, (FROM_INT)4);
  vec_push(&v, (FROM_INT)4);
  vec_erase(&v, 4);

  assert(v.size == 8);
  assert(v.count == 5);

  for (size_t i = 0; i < v.count; ++i) {
    assert((TO_INT)vec_get(&v, i) == (int)i);
  }

  vec_free(&v);
}
