#pragma once

#include "common.h"
#include "vec.h"

typedef struct queue_t queue;

struct queue_t {
  vec *v;
  int *array;
  int *front;
  int *back;
  size_t size;
};

int queue_front(queue *q);

void queue_init(queue *q);
void queue_push(queue *q, int e);
void queue_pop(queue *q);
void queue_free(queue *q);
