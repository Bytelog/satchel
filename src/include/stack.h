#pragma once

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "vec.h"

typedef struct s_vec s_stack;

void const* s_stack_top(s_stack*);

size_t s_stack_count(s_stack*);

void s_stack_init(s_stack*);

bool s_stack_push(s_stack*, void* item);

void s_stack_pop(s_stack*);

void s_stack_free(s_stack*);
