#include "queue.h"

void *queue_front(queue *q) { return q->front; }
size_t queue_length(queue *q) { return q->size - q->front + q->back - 1; }

void queue_init(queue *q) {
  vec v;
  vec_init(&v);

  q->v = &v;
  q->array = NULL;
  q->front = NULL;
  q->back = NULL;
  q->size = 0;
}

void queue_push(queue *q, void *e) {
    if (q->size == 0) {
        q->size = 1;
        q->array = malloc(sizeof(void *));
        q->front = q->array;
        q->back = q->array;
    }
    
    // needs work. q->front++ needs conditions/wrapping
    if (q->size == queue_length(q)) {
        q->size *= 2;
        q->array = realloc(q->array, sizeof(void *) * q->size);
        q->front++;
    }
    
    *(q->front) = e;
}

void queue_pop(queue *q) {
    // todo: check length
    q->back++;
}

void queue_free(queue *q) { vec_free(q->v); }
