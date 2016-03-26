#pragma once

#include "common.h"
#include <stdbool.h>

typedef struct queue_t queue;

struct queue_t {
  void **array;
  void **front;
  void **back;
  size_t size;
};

void *queue_front(queue *q);
size_t queue_length(queue *q);
void queue_init(queue *q);
bool queue_push(queue *q, void *e);
void queue_pop(queue *q);
void queue_free(queue *q);
