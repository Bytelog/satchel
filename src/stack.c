#include "include/common.h"
#include "include/stack.h"

void const *s_stack_top(s_stack *s) {
    return s_vec_get(s, s_vec_count(s) - 1);
}

size_t s_stack_count(s_stack *s) {
    return s_vec_count(s);
}

void s_stack_init(s_stack *s) {
    s_vec_init(s);
}

bool s_stack_push(s_stack *s, void* item) {
    return s_vec_push(s, item);
}

void s_stack_pop(s_stack *s) {
    s_vec_pop(s);
}

void s_stack_free(s_stack *s) {
    s_vec_free(s);
}
