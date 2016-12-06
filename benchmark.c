#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <limits.h>
#include "clz.h"

#define CLOCK_ID CLOCK_MONOTONIC_RAW
#define ONE_SEC 1000000000.0

int main(int argc, char const *argv[])
{
    struct timespec start = {0, 0};
    struct timespec end = {0, 0};

    if (argc < 2) return -1;

    uint32_t N = atoi(argv[1]);
    uint32_t i;

    // recursive
    clock_gettime(CLOCK_ID, &start);
    for(i = 0; i < UINT_MAX; i++) {
        clz_recursive(N);
    }
    clock_gettime(CLOCK_ID, &end);
    printf("%lf,", (double) (end.tv_sec - start.tv_sec) +
           (end.tv_nsec - start.tv_nsec)/ONE_SEC);


    // binary recursive 
    clock_gettime(CLOCK_ID, &start);
    for(i = 0; i < UINT_MAX; i++) {
        clz_binary_recursive(N,16);
    }
    clock_gettime(CLOCK_ID, &end);
    printf("%lf,", (double) (end.tv_sec - start.tv_sec) +
           (end.tv_nsec - start.tv_nsec)/ONE_SEC);


    // iteration
    clock_gettime(CLOCK_ID, &start);
    for(i = 0; i < UINT_MAX; i++) {
        clz_iteration(N);
    }
    clock_gettime(CLOCK_ID, &end);
    printf("%lf,", (double) (end.tv_sec - start.tv_sec) +
           (end.tv_nsec - start.tv_nsec)/ONE_SEC);


    // binary iteration
    clock_gettime(CLOCK_ID, &start);
    for(i = 0; i < UINT_MAX; i++) {
        clz_binary_iteration(N);
    }
    clock_gettime(CLOCK_ID, &end);
    printf("%lf,", (double) (end.tv_sec - start.tv_sec) +
           (end.tv_nsec - start.tv_nsec)/ONE_SEC);


    // harley
    clock_gettime(CLOCK_ID, &start);
    for(i = 0; i < UINT_MAX; i++) {
        clz_harley(N);
    }
    clock_gettime(CLOCK_ID, &end);
    printf("%lf,", (double) (end.tv_sec - start.tv_sec) +
           (end.tv_nsec - start.tv_nsec)/ONE_SEC);
    
    // binary search
    clock_gettime(CLOCK_ID, &start);
    for(i = 0; i < UINT_MAX; i++) {
        clz_binary_search(N);
    }
    clock_gettime(CLOCK_ID, &end);
    printf("%lf,", (double) (end.tv_sec - start.tv_sec) +
           (end.tv_nsec - start.tv_nsec)/ONE_SEC);
    
    // byte shift
    clock_gettime(CLOCK_ID, &start);
    for(i = 0; i < UINT_MAX; i++) {
        clz_byte_shift(N);
    }
    clock_gettime(CLOCK_ID, &end);
    printf("%lf\n", (double) (end.tv_sec - start.tv_sec) +
           (end.tv_nsec - start.tv_nsec)/ONE_SEC);
    
    return 0;
}
