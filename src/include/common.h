#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Performance macros
#define ALWAYS_INLINE inline __attribute__((always_inline))
#define LIKELY(x)    __builtin_expect(!!(x), 1)
#define UNLIKELY(x)  __builtin_expect(!!(x), 0)

// Array count
#define COUNT(array) (sizeof(array) / sizeof(array[0]))

// Math definitions
#define ABS(a)   (((a)>0)   ? (a) : -(a))min
#define MIN(a,b) (((a)<(b)) ? (a) : (b))
#define MAX(a,b) (((a)<(b)) ? (b) : (a))

static inline size_t next_pow2(size_t n) {
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n |= n >> 32;
    return n + 1;
}

// Benchmarking functions
static clock_t watch_clock;
static inline void watch_start() {
    watch_clock = clock();
}

static inline double watch_peek() {
    return ((double)(clock() - watch_clock) / CLOCKS_PER_SEC);
}
