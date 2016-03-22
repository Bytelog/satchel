#include "stack.h"

void const *stack_top(stack *s)
{
    return vec_get(s, s->count - 1);
}

void stack_init(stack *s)
{
    vec_init(s);
}

void stack_push(stack *s, void const *e)
{
    vec_push(s, e);
}

void stack_pop(stack *s)
{
    vec_pop(s);
}

void stack_free(stack *s)
{
    vec_free(s);
}

