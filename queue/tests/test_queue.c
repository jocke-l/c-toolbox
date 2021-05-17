#include <stdio.h>

#include <test.h>

#include "../queue.h"

int test_dynamic_queue_capacity() {
    Queue *queue = queue_create(1);

    char *elements = "abc";

    queue_push(queue, &elements[0]);
    test_assert(queue->size == 1);
    test_assert(queue->capacity == 1);
    test_assert(*((char *) queue->elements[0]) == elements[0]);

    queue_push(queue, &elements[1]);
    queue_push(queue, &elements[2]);
    test_assert(queue->size == 3);
    test_assert(queue->capacity == 4);

    char *a = (char *) queue_pop(queue);
    char *b = (char *) queue_pop(queue);
    char *c = (char *) queue_pop(queue);
    test_assert(*a == elements[0]);
    test_assert(*b == elements[1]);
    test_assert(*c == elements[2]);

    test_assert(queue->size == 0);

    return 0;
}

int test_pop_empty() {
    Queue *queue = queue_create(1);
    void *element = queue_pop(queue);
    test_assert(element == NULL);

    return 0;
}

int main() {
    test_init();
    
    run_test_case(test_dynamic_queue_capacity);
    run_test_case(test_pop_empty);

    return test_summary();
}
