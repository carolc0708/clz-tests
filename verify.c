#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <limits.h>
#include "clz.h"


int main()
{
    for(int i=1; i<UINT_MAX; i++)
    {
        uint8_t ans = __builtin_clz(i);
        printf("clz: %d\n",ans);
        assert(clz_recursive(i) == ans);
        assert(clz_binary_recursive(i,16) == ans);
        assert(clz_iteration(i) == ans);
        assert(clz_binary_iteration(i) == ans);
        assert(clz_harley(i) == ans);
        assert(clz_binary_search(i) == ans);
        assert(clz_byte_shift(i) == ans);
    }

    return 0;
}
