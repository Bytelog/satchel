#pragma once

#include "common.h"

typedef struct queue_t queue;

struct queue_t {
  void **array;
  int *front;
  int *back;
  size_t size;
};

void *queue_front(queue *q);
void queue_init(queue *q);
void queue_push(queue *q, void *e);
void queue_pop(queue *q);
void queue_free(queue *q);
