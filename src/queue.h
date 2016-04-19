#pragma once
#include <stdbool.h>
#include <string.h>
#include "common.h"

typedef struct queue_t queue;

struct queue_t {
  void const **array;
  size_t size;
  size_t front;
  size_t count;
};

void const *queue_front(queue *q) { return q->array[q->front]; }

void queue_init(queue *q) {
  q->array = NULL;
  q->size = 0;
  q->front = 0;
  q->count = 0;
}

static inline void *queue_grow(queue *q) {
  q->size = MAX(next_pow2(q->size + 1), 2);
  q->array = realloc(q->array, sizeof(void *) * q->size);
  return q->array;
}

bool queue_push(queue *q, void const *e) {
  if (q->count == q->size) {
    if (!queue_grow(q)) return false;
    memmove(&q->array[q->count], q->array, q->front);
  }

  q->count++;
  q->array[(q->front + q->count - 1) % q->size] = e;
  return true;
}

void queue_pop(queue *q) {
  q->count--;
  q->front = (q->front + 1) % q->size;
}

void queue_free(queue *q) { free(q->array); }
