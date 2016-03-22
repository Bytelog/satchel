#pragma once
#include "common.h"
#include "vec.h"

typedef struct vec_t stack;

void const *stack_top(stack *s);

void stack_init(stack *s);
void stack_push(stack *s, void const *e);
void stack_pop(stack *s);
void stack_free(stack *s);
