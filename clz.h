#ifndef _CLZ_H
#define _CLZ_H
#include <stdint.h>

uint8_t clz_recursive(uint32_t x);
uint8_t clz_binary_recursive(uint32_t x, int shift);
uint8_t clz_iteration(uint32_t x);
uint8_t clz_binary_iteration(uint32_t x);
uint8_t clz_harley(uint32_t x);
uint8_t clz_binary_search(uint32_t x);
uint8_t clz_byte_shift(uint32_t x);

#endif
