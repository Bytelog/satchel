#include "stack.h"
#include <assert.h>
#include <limits.h>
#include <stdint.h>

#define FROM_UINT void *)(uintptr_t
#define TO_UINT size_t)(uintptr_t const *
#define STRESS_VALUE USHRT_MAX

int main() {
  stack s;
  stack_init(&s);

  // Basic usage tests
  assert(stack_count(&s) == 0);

  stack_push(&s, (FROM_UINT) 10);
  assert((TO_UINT) stack_top(&s) == 10);
  assert(stack_count(&s) == 1);

  stack_pop(&s);
  assert(stack_count(&s) == 0);

  stack_free(&s);


  // Stress testing
  stack_init(&s);
  for (size_t i = 0; i < STRESS_VALUE; ++i)
    stack_push(&s, (FROM_UINT) i);

  for (size_t i = STRESS_VALUE - 1; 0 < i; --i) {
    assert((TO_UINT) stack_top(&s) == i);
    stack_pop(&s);
  }

  stack_free(&s);
}
