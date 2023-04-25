/**
 * C implementation for bit rotating:
 * see https://en.wikipedia.org/wiki/Circular_shift#Implementing_circular_shifts
 */


/*
 * Shift operations in C are only defined for shift values which are
 * not negative and smaller than sizeof(value) * CHAR_BIT.
 * The mask, used with bitwise-and (&), prevents undefined behaviour
 * when the shift count is 0 or >= the width of unsigned int.
 */

#include <stdint.h>  // for uint32_t, to get 32-bit-wide rotates, regardless of the size of int.
#include <limits.h>  // for CHAR_BIT

uint32_t rotl32 (uint32_t value, unsigned int count) {
    const unsigned int mask = CHAR_BIT * sizeof(value) - 1;
    count &= mask;
    return (value << count) | (value >> (-count & mask));
}

uint32_t rotr32 (uint32_t value, unsigned int count) {
    const unsigned int mask = CHAR_BIT * sizeof(value) - 1;
    count &= mask;
    return (value >> count) | (value << (-count & mask));
}

uint32_t main(int* argc, char** argv) {
    if (argc < 3) {
        printf("give two integers as argument!\n");
        return 1;
    }
    uint32_t x;
    uint32_t shift_width;
    sscanf(argv[1], "%d", &x);
    sscanf(argv[2], "%d", &shift_width);
    printf("shift width:\t%d\n", shift_width);
    uint32_t rotr = rotr32(x, shift_width);
    uint32_t rotl = rotl32(x, shift_width);
    printf("original: 0b%032b | 0x%08x | %u\n", x, x, x, x);
    printf("rshifted: 0b%032b | 0x%08x | %u\n", rotr, rotr, rotr, rotr);
    printf("lshifted: 0b%032b | 0x%08x | %u\n", rotl, rotl, rotl, rotl);
}
