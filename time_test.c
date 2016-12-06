#include <stdint.h>
#include <stdio.h>
#include "clz.h"

int main(int argc, char const *argv[])
{
    __attribute__((unused)) uint32_t N = 0xFFFFFF;
    __attribute__((unused)) uint32_t i = 0x0;


#if defined(RECURSIVE)
    for(i=0 ; i<N; i++)
        clz_recursive(i);
#endif

#if defined(BRECURSIVE)
    for(i=0; i<N; i++)
         clz_binary_recursive(i,16);
#endif

#if defined(ITERATION)
    for(i=0; i<N; i++)
        clz_iteration(i);
#endif

#if defined(BITERATION)
    for(i=0; i<N; i++)
        clz_binary_iteration(i);
#endif

#if defined(HARLEY)
    for(i=0; i<N; i++)
        clz_harley(i);
#endif

#if defined(BSEARCH)
    for(i=0; i<N; i++)
        clz_binary_search(i);
#endif

#if defined(BYTESHIFT)
    for(i=0; i<N; i++)
         clz_byte_shift(i);
#endif

    return 0;
}
