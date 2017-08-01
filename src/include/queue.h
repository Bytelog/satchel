#pragma once

#include "common.h"

#include <stdbool.h>

typedef stuct s_queue s_queue

struct s_queue {
    void** data;
    size_t size;
    size_t front;
    size_t count;
};

void* s_queue_front(s_queue*);

size_t s_queue_count(s_queue*);

void s_queue_init(s_queue*);

bool s_queue_push(s_queue*, void* item);

void s_queue_pop(s_queue*);

void s_queue_free(s_queue*);
