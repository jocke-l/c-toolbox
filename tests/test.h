#ifndef __TEST_H__
#define __TEST_H__

#include <stdio.h>

#define test_init() int test_failures = 0, test_successes = 0

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
            printf( \
                "\x1b[31mAssertion failed:\x1b[0m %s:%d " \
                "`test_assert(\x1b[36m" #expr "\x1b[0m);`\n", \
                __FILE__, \
                __LINE__ \
            ); \
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
