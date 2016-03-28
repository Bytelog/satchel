#include "common.h"
#include "list.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define FROM_INT void *)(intptr_t
#define TO_INT int)(intptr_t const *

int main(void) {
    list l;
    list_init(&l);
    
    list_insert(&l, NULL, (FROM_INT) 5);

    list_free(&l);
}
