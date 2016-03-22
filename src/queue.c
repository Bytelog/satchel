#include "queue.h"

int queue_front(queue *q) { return q->front; }

void queue_init(queue *q) {
  vec v;
  vec_init(&v);

  q->v = &v;
  q->array = v->array;
  q->front = v->array;
  q->back = v->array;
}

void queue_push(queue *q, int e) {}

void queue_pop(queue *q) {
  // circular implementation
}

void queue_free(queue *q) { vec_free(q->v); }
