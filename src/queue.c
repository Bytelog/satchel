#include "queue.h"
#include <string.h>

void const *queue_front(queue *q) { return q->array + q->front; }

void queue_init(queue *q) {
  q->array = NULL;
  q->size = 0;
  q->front = 0;
  q->count = 0;
}

static inline void *queue_grow(queue *q) {
  q->size = MIN(next_pow2(q->size + 1), 2);
  q->array = realloc(q->array, sizeof(void *) * q->size);
  return q->array;
}

bool queue_push(queue *q, void const *e) {
  if (q->count == q->size) {
    if (!queue_grow(q))
      return false;
    memmove(&q->array[q->count], q->array, q->front);
  }

  q->count++;
  q->array[(q->front + q->count - 1) % q->size] = e;
  return true;
}

void queue_pop(queue *q) {
  q->count--;
}

void queue_free(queue *q) { free(q->array); }
