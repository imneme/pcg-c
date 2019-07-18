#define XX_PREDECLS

#define XX_INFO \
            "pcg_setseq_64_xsl_rr_rr_64_random_r:\n" \
            "      -  result:      64-bit unsigned int (uint64_t)\n" \
            "      -  period:      2^64   (* 2^63 streams)\n" \
            "      -  state type:  struct pcg_state_setseq_64 (%zu bytes)\n" \
            "      -  output func: XSL-RR-RR\n" \
            "\n", sizeof(struct pcg_state_setseq_64)
            
#define XX_NUMBITS                  "  64bit:"
#define XX_NUMVALUES                6
#define XX_NUMWRAP                  3
#define XX_PRINT_RNGVAL(value)      printf(" 0x%016" PRIx64 "", value)
#define XX_RAND_DECL                struct pcg_state_setseq_64 rng;
#define XX_SEEDSDECL(seeds)         uint64_t seeds[2];
#define XX_SRANDOM_SEEDARGS(seeds)  seeds[0], seeds[1]
#define XX_SRANDOM_SEEDCONSTS       42u, 54u
#define XX_SRANDOM(...)             \
            pcg_setseq_64_srandom_r(&rng, __VA_ARGS__)
#define XX_RANDOM()                 \
            pcg_setseq_64_xsl_rr_rr_64_random_r(&rng)
#define XX_BOUNDEDRAND(bound)       \
            pcg_setseq_64_xsl_rr_rr_64_boundedrand_r(&rng, bound)
#define XX_ADVANCE(delta)           \
            pcg_setseq_64_advance_r(&rng, delta)

#include "pcg_variants.h"
#include "check-base.c"
