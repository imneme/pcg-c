#define XX_PREDECLS

#define XX_INFO \
            "pcg32s_random_r:\n" \
            "      -  result:      32-bit unsigned int (uint32_t)\n" \
            "      -  period:      2^64\n" \
            "      -  state type:  pcg32s_random_t (%zu bytes)\n" \
            "      -  output func: XSH-RR\n" \
            "\n", sizeof(pcg32s_random_t)
            
#define XX_NUMBITS                  "  32bit:"
#define XX_NUMVALUES                6
#define XX_NUMWRAP                  6
#define XX_PRINT_RNGVAL(value)      printf(" 0x%08x", value)
#define XX_RAND_DECL                pcg32s_random_t rng;
#define XX_SEEDSDECL(seeds)         uint64_t seeds[1];
#define XX_SRANDOM_SEEDARGS(seeds)  seeds[0]
#define XX_SRANDOM_SEEDCONSTS       42u
#define XX_SRANDOM(...)             \
            pcg32s_srandom_r(&rng, __VA_ARGS__)
#define XX_RANDOM()                 \
            pcg32s_random_r(&rng)
#define XX_BOUNDEDRAND(bound)       \
            pcg32s_boundedrand_r(&rng, bound)
#define XX_ADVANCE(delta)           \
            pcg32s_advance_r(&rng, delta)

#include "pcg_variants.h"
#include "check-base.c"
