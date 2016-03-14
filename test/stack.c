#include <assert.h>
#include "stack.h"

int main(int argc, char **argv)
{
    stack s;
    stack_init(&s);

    for(int i=0; i < 100; ++i) {
        stack_push(&s, i);
        assert(stack_top(&s) == i);
    }
    
    for(int i=99; 0 <= i; --i) {
        assert(stack_top(&s) == i);
        stack_pop(&s);
    }

    stack_free(&s);
}

