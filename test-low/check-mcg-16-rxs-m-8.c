#define XX_PREDECLS

#define XX_INFO \
            "pcg_mcg_16_rxs_m_8_random_r:\n" \
            "      -  result:      8-bit unsigned int (uint8_t)\n" \
            "      -  period:      2^14\n" \
            "      -  state type:  struct pcg_state_16 (%zu bytes)\n" \
            "      -  output func: RXS-M\n" \
            "\n", sizeof(struct pcg_state_16)
            
#define XX_NUMBITS                  "   8bit:"
#define XX_NUMVALUES                14
#define XX_NUMWRAP                  14
#define XX_PRINT_RNGVAL(value)      printf(" 0x%02x", value)
#define XX_RAND_DECL                struct pcg_state_16 rng;
#define XX_SEEDSDECL(seeds)         uint16_t seeds[1];
#define XX_SRANDOM_SEEDARGS(seeds)  seeds[0]
#define XX_SRANDOM_SEEDCONSTS       42u
#define XX_SRANDOM(...)             \
            pcg_mcg_16_srandom_r(&rng, __VA_ARGS__)
#define XX_RANDOM()                 \
            pcg_mcg_16_rxs_m_8_random_r(&rng)
#define XX_BOUNDEDRAND(bound)       \
            pcg_mcg_16_rxs_m_8_boundedrand_r(&rng, bound)
#define XX_ADVANCE(delta)           \
            pcg_mcg_16_advance_r(&rng, delta)

#include "pcg_variants.h"
#include "check-base.c"
