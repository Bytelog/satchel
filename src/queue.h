#pragma once

#include "common.h"
#include <stdbool.h>

typedef struct queue_t queue;

struct queue_t {
  void const **array;
  size_t size;
  size_t front;
  size_t count;
};

void const *queue_front(queue *q);
void queue_init(queue *q);
bool queue_push(queue *q, void const *e);
void queue_pop(queue *q);
void queue_free(queue *q);
