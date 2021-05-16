#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stddef.h>

#define ERR_QUEUE_OOM 100;

typedef struct {
    size_t size;
    size_t capacity;
    size_t front;
    size_t rear;
    void **elements;
} Queue;

Queue *queue_create(size_t initial_capacity);
void queue_free(Queue *queue);
int queue_push(Queue *queue, void *element);
void *queue_pop(Queue *queue);

#endif
