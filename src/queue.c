#include "include/common.h"
#include "include/queue.h"

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static void* s_queue_grow(s_queue*);

void* s_queue_front(s_queue* q) {
    return q->data[q->front];
}

size_t s_queue_count(s_queue* q) {
    return q->count;
}

void s_queue_init(s_queue* q) {
    q->data = NULL;
    q->size = 0;
    q->front = 0;
    q->count = 0;
}

bool s_queue_push(s_queue* q, void* item) {
    if (q->count == q->size) {
        if (!s_queue_grow(q)) {
            return false;
        }
        memmove(&q->data[q->count], q->data, q->front);
    }

    q->data[(q->front + (++q->count) - 1) % q->size] = item;
    return true;
}

void s_queue_pop(s_queue* q) {
    --(q->count);
    q->front = (q->front + 1) % q->size;
}

void s_queue_free(s_queue* q) { free(q->data); }

static void* s_queue_grow(s_queue* q) {
    q->size = MAX(next_pow2(q->size + 1), 2);
    q->data = realloc(q->data, sizeof(void*) * q->size);
    return q->data;
}
