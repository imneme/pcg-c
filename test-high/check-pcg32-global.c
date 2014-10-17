#define XX_PREDECLS

#define XX_INFO \
            "pcg32_random:\n" \
            "      -  result:      32-bit unsigned int (uint32_t)\n" \
            "      -  period:      2^64   * (2^63 streams)\n" \
            "      -  state type:  N/A (private global)\n" \
            "      -  output func: XSH-RR\n" \
            "\n"
            
#define XX_NUMBITS                  "  32bit:"
#define XX_NUMVALUES                6
#define XX_NUMWRAP                  6
#define XX_PRINT_RNGVAL(value)      printf(" 0x%08x", value)
#define XX_RAND_DECL                
#define XX_SEEDSDECL(seeds)         uint64_t seeds[2];
#define XX_SRANDOM_SEEDARGS(seeds)  seeds[0], seeds[1]
#define XX_SRANDOM_SEEDCONSTS       42u, 54u
#define XX_SRANDOM(...)             \
            pcg32_srandom(__VA_ARGS__)
#define XX_RANDOM()                 \
            pcg32_random()
#define XX_BOUNDEDRAND(bound)       \
            pcg32_boundedrand(bound)
#define XX_ADVANCE(delta)           \
            pcg32_advance(delta)

#include "pcg_variants.h"
#include "check-base.c"
