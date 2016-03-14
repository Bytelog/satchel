#pragma once

#include "vec.h"
#include "common.h"

typedef struct vec_t stack;

int stack_top(stack *s);

void stack_init(stack *s);
void stack_push(stack *s, int e);
void stack_pop(stack *s);
void stack_free(stack *s);

