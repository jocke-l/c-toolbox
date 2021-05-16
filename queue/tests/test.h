#ifndef __TEST_H__
#define __TEST_H__

#include <stdio.h>

#define test_init() int test_failures, test_successes = 0

#define run_test_case(function) \
    do { \
        printf(#function "...\n"); \
        if (!function()) { \
            test_successes++; \
        } else { \
            test_failures++; \
        } \
    } while (0)

#define test_assert(expr) \
    do { \
        if (!(expr)) { \
            printf("Assertion failed: " #expr "\n"); \
            return 1; \
        } \
    } while (0)

#define test_summary() \
    printf( \
        "\nSummary: successes=%d failures=%d\n", \
        test_successes, \
        test_failures \
    ) && test_failures \


#endif
