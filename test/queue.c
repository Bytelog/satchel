#include "queue.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define FROM_INT void *)(intptr_t
#define TO_INT int)(intptr_t const *

int main(void) {
    queue q;
    queue_init(&q);
    
    for (int i = 0; i < 1000; ++i) {
        queue_push(&q, (FROM_INT) i);
    }
    
    for (int i = 0; i < 1000; ++i) {
        assert((TO_INT) queue_front(&q) == i);
        queue_pop(&q);
    }

    queue_free(&q);
}
