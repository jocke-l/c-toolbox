#include <stdlib.h>
#include <string.h>

#include "queue.h"

Queue *queue_create(size_t initial_capacity) {
    Queue *queue;

    if ((queue = malloc(sizeof(Queue))) == NULL) {
        return NULL;
    }

    queue->size = 0;
    queue->capacity = initial_capacity;
    if ((queue->elements = malloc(sizeof(void *) * queue->capacity)) == NULL) {
        return NULL;
    }
    queue->front = 0;
    queue->rear = 0;

    return queue;
}

void queue_free(Queue *queue) {
    free(queue->elements);
    free(queue);
}

int queue_push(Queue *queue, void *element) {
    if (queue->size + 1 > queue->capacity) {
        queue->capacity *= 2;
        queue->elements = realloc(queue->elements, sizeof(void *) * queue->capacity);
        if (queue->elements == NULL) {
            return ERR_QUEUE_OOM;
        }
    }

    queue->elements[queue->rear] = element;
    queue->rear++;
    queue->size++;
    if (queue->rear > queue->capacity) {
        queue->rear = 0;
    }

    return 0;
}

void *queue_pop(Queue *queue) {
    if (queue->size == 0) {
        return NULL;
    }

    void *element = queue->elements[queue->front];
    queue->front++;
    queue->size--;

    if (queue->size == 0) {
        queue->rear = queue->front = 0;
    }
    if (queue->front > queue->capacity) {
        queue->front = 0;
    }

    return element;
}
