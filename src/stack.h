#pragma once
#include "vec.h"

typedef struct vec_t stack;

inline void const *stack_top(stack *s) { return vec_get(s, s->count - 1); }
inline void stack_init(stack *s) { vec_init(s); }
inline bool stack_push(stack *s, void const *e) { return vec_push(s, e); }
inline void stack_pop(stack *s) { vec_pop(s); }
inline void stack_free(stack *s) { vec_free(s); }
