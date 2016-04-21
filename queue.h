#pragma once
#include <stdbool.h>
#include <string.h>
#include "common.h"

typedef struct {
  void **data;
  size_t size;
  size_t front;
  size_t count;
} queue;

void *queue_front(queue *q) { return q->data[q->front]; }
size_t queue_count(queue *q) { return q->count; }

void queue_init(queue *q) {
  q->data = NULL;
  q->size = 0;
  q->front = 0;
  q->count = 0;
}

void *queue_grow(queue *q) {
  q->size = MAX(next_pow2(q->size + 1), 2);
  q->data = realloc(q->data, sizeof(void *) * q->size);
  return q->data;
}

bool queue_push(queue *q, void *e) {
  if (q->count == q->size) {
    if (!queue_grow(q)) return false;
    memmove(&q->data[q->count], q->data, q->front);
  }

  q->count++;
  q->data[(q->front + q->count - 1) % q->size] = e;
  return true;
}

void queue_pop(queue *q) {
  q->count--;
  q->front = (q->front + 1) % q->size;
}

void queue_free(queue *q) { free(q->data); }
