#define XX_PREDECLS

#define XX_INFO \
            "pcg16si_random_r:\n" \
            "      -  result:      16-bit unsigned int (uint16_t)\n" \
            "      -  period:      2^16\n" \
            "      -  state type:  pcg16si_random_t (%zu bytes)\n" \
            "      -  output func: RXS-M-XS\n" \
            "\n", sizeof(pcg16si_random_t)
            
#define XX_NUMBITS                  "  16bit:"
#define XX_NUMVALUES                10
#define XX_NUMWRAP                  10
#define XX_PRINT_RNGVAL(value)      printf(" 0x%04x", value)
#define XX_RAND_DECL                pcg16si_random_t rng;
#define XX_SEEDSDECL(seeds)         uint16_t seeds[1];
#define XX_SRANDOM_SEEDARGS(seeds)  seeds[0]
#define XX_SRANDOM_SEEDCONSTS       42u
#define XX_SRANDOM(...)             \
            pcg16si_srandom_r(&rng, __VA_ARGS__)
#define XX_RANDOM()                 \
            pcg16si_random_r(&rng)
#define XX_BOUNDEDRAND(bound)       \
            pcg16si_boundedrand_r(&rng, bound)
#define XX_ADVANCE(delta)           \
            pcg16si_advance_r(&rng, delta)

#include "pcg_variants.h"
#include "check-base.c"
