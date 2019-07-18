#define XX_PREDECLS

#define XX_INFO \
            "pcg_mcg_128_xsl_rr_64_random_r:\n" \
            "      -  result:      64-bit unsigned int (uint64_t)\n" \
            "      -  period:      2^126\n" \
            "      -  state type:  struct pcg_state_128 (%zu bytes)\n" \
            "      -  output func: XSL-RR\n" \
            "\n", sizeof(struct pcg_state_128)
            
#define XX_NUMBITS                  "  64bit:"
#define XX_NUMVALUES                6
#define XX_NUMWRAP                  3
#define XX_PRINT_RNGVAL(value)      printf(" 0x%016" PRIx64 "", value)
#define XX_RAND_DECL                struct pcg_state_128 rng;
#define XX_SEEDSDECL(seeds)         pcg128_t seeds[1];
#define XX_SRANDOM_SEEDARGS(seeds)  seeds[0]
#define XX_SRANDOM_SEEDCONSTS       42u
#define XX_SRANDOM(...)             \
            pcg_mcg_128_srandom_r(&rng, __VA_ARGS__)
#define XX_RANDOM()                 \
            pcg_mcg_128_xsl_rr_64_random_r(&rng)
#define XX_BOUNDEDRAND(bound)       \
            pcg_mcg_128_xsl_rr_64_boundedrand_r(&rng, bound)
#define XX_ADVANCE(delta)           \
            pcg_mcg_128_advance_r(&rng, delta)

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
