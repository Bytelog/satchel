#include "stack.h"
#include <assert.h>
#include <stdint.h>

#define FROM_INT void *)(intptr_t
#define TO_INT int)(intptr_t const *

int main() {
  stack s;
  stack_init(&s);

  for (int i = 0; i < 100; ++i) {
    stack_push(&s, (FROM_INT)i);
    assert((TO_INT)stack_top(&s) == i);
  }

  for (int i = 99; 0 <= i; --i) {
    assert((TO_INT)stack_top(&s) == i);
    stack_pop(&s);
  }

  stack_free(&s);
}
