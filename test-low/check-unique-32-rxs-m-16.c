#define XX_PREDECLS

#define XX_INFO \
            "pcg_unique_32_rxs_m_16_random_r:\n" \
            "      -  result:      16-bit unsigned int (uint16_t)\n" \
            "      -  period:      2^32   (* #rngs  [unique stream per rng])\n" \
            "      -  state type:  struct pcg_state_32 (%zu bytes)\n" \
            "      -  output func: RXS-M\n" \
            "\n", sizeof(struct pcg_state_32)
            
#define XX_NUMBITS                  "  16bit:"
#define XX_NUMVALUES                10
#define XX_NUMWRAP                  10
#define XX_PRINT_RNGVAL(value)      printf(" 0x%04x", value)
#define XX_RAND_DECL                struct pcg_state_32 rng;
#define XX_SEEDSDECL(seeds)         uint32_t seeds[1];
#define XX_SRANDOM_SEEDARGS(seeds)  seeds[0]
#define XX_SRANDOM_SEEDCONSTS       42u
#define XX_SRANDOM(...)             \
            pcg_unique_32_srandom_r(&rng, __VA_ARGS__)
#define XX_RANDOM()                 \
            pcg_unique_32_rxs_m_16_random_r(&rng)
#define XX_BOUNDEDRAND(bound)       \
            pcg_unique_32_rxs_m_16_boundedrand_r(&rng, bound)
#define XX_ADVANCE(delta)           \
            pcg_unique_32_advance_r(&rng, delta)

#include "pcg_variants.h"
#include "check-base.c"
