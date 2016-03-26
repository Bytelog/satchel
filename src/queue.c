#include "queue.h"

void *queue_front(queue *q) { return q->front; }
//size_t queue_length(queue *q) {  }

void queue_init(queue *q) {
  q->array = NULL;
  q->front = NULL;
  q->back = NULL;
  q->size = 0;
}

static inline void * queue_grow(queue *q) {
  q->size = next_pow2(q->size + 1);
  q->array = realloc(q->array, sizeof(void *) * q->size);
  return q->array;
}

static inline void * queue_next(queue *q, void **it) {
  if ((size_t) (it - q->array) == q->size)
    return q->array;
  return it + 1;
}

bool queue_push(queue *q, void *e) {
  if (q->front == q->back) {
    if (!queue_grow(q))
      return false;
    q->front = q->array;
    q->back = q->array + q->size - 1;
  }

  // Check for q->back + 1 = q->front. Means full
  
  // Otherwise, q->front++

  *(q->back) = e;
  return true;
}

void queue_pop(queue *q) {
  q->front = queue_next(q, q->front);
}

void queue_free(queue *q) { free(q->array); }
