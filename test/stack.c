#include "stack.h"
#include <assert.h>
#include <stdint.h>

#define FROM_UINT void *)(uintptr_t
#define TO_UINT size_t)(uintptr_t const *

int main() {
  stack s;
  stack_init(&s);

  for (size_t i = 0; i < 100; ++i) {
    stack_push(&s, (FROM_UINT)i);
    assert((TO_UINT)stack_top(&s) == i);
  }

  for (size_t i = 99; 0 != i; --i) {
    assert((TO_UINT)stack_top(&s) == i);
    stack_pop(&s);
  }

  stack_free(&s);
}
