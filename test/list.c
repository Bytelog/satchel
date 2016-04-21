#include "list.h"
#include <assert.h>
#include <limits.h>
#include <stdint.h>

#define FROM_UINT void *)(uintptr_t
#define TO_UINT size_t)(uintptr_t const *
#define STRESS_VALUE USHRT_MAX

#include <stdio.h>

int main(void) {
  
  // Basic usage tests
  list l;
  list_it it;

  list_init(&l);
  list_front(&l, &it);
  list_insert_after(&l, &it, (FROM_UINT) 1);
  printf("%p : %p\n", (void *) l.item, (void *) it.item);
  /** This is broken and needs fixing */
  /**
  assert((TO_UINT) list_get(&l, &it) == 1);

  printf("%p\n", (void *) &it);

  list_free(&l);**/
}
