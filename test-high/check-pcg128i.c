#define XX_PREDECLS                                                            \
    void print128(pcg128_t value)                                              \
    {                                                                          \
        printf(" 0x%016" PRIx64 "%016" PRIx64 "", (uint64_t)(value >> 64), (uint64_t)value); \
    }

#define XX_INFO \
            "pcg128i_random_r:\n" \
            "      -  result:      128-bit unsigned int (pcg128_t)\n" \
            "      -  period:      2^128   (* 2^127 streams)\n" \
            "      -  state type:  pcg128i_random_t (%zu bytes)\n" \
            "      -  output func: RXS-M-XS\n" \
            "\n", sizeof(pcg128i_random_t)
            
#define XX_NUMBITS                  " 128bit:"
#define XX_NUMVALUES                6
#define XX_NUMWRAP                  2
#define XX_PRINT_RNGVAL(value)      print128( value)
#define XX_RAND_DECL                pcg128i_random_t rng;
#define XX_SEEDSDECL(seeds)         pcg128_t seeds[2];
#define XX_SRANDOM_SEEDARGS(seeds)  seeds[0], seeds[1]
#define XX_SRANDOM_SEEDCONSTS       42u, 54u
#define XX_SRANDOM(...)             \
            pcg128i_srandom_r(&rng, __VA_ARGS__)
#define XX_RANDOM()                 \
            pcg128i_random_r(&rng)
#define XX_BOUNDEDRAND(bound)       \
            pcg128i_boundedrand_r(&rng, bound)
#define XX_ADVANCE(delta)           \
            pcg128i_advance_r(&rng, delta)

#include "pcg_variants.h"
#if PCG_HAS_128BIT_OPS
    #include "check-base.c"
#else
    #include <stdio.h>
    int main()
    {
        printf("This platform does not support 128-bit integers.\n");
        return 1;
    }
#endif
