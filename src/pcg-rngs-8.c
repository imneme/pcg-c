/*
 * PCG Random Number Generation for C.
 *
 * Copyright 2014 Melissa O'Neill <oneill@pcg-random.org>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * For additional information about the PCG random number generation scheme,
 * including its license and other licensing options, visit
 *
 *       http://www.pcg-random.org
 */
 
/* 
 * This code is derived from the canonical C++ PCG implementation, which
 * has many additional features and is preferable if you can use C++ in
 * your project.
 *
 * The contents of this file were mechanically derived from pcg_variants.h
 * (every inline function defined there gets an exern declaration here).
 */

#include "pcg_variants.h"

/* Functions to advance the underlying LCG, one version for each size and
 * each style.  These functions are considered semi-private.  There is rarely
 * a good reason to call them directly.
 */

extern inline void pcg_oneseq_8_step_r(struct pcg_state_8* rng);

extern inline void pcg_oneseq_8_advance_r(struct pcg_state_8* rng,
                                          uint8_t delta);

extern inline void pcg_mcg_8_step_r(struct pcg_state_8* rng);

extern inline void pcg_mcg_8_advance_r(struct pcg_state_8* rng, uint8_t delta);

extern inline void pcg_unique_8_step_r(struct pcg_state_8* rng);

extern inline void pcg_unique_8_advance_r(struct pcg_state_8* rng,
                                          uint8_t delta);

extern inline void pcg_setseq_8_step_r(struct pcg_state_setseq_8* rng);

extern inline void pcg_setseq_8_advance_r(struct pcg_state_setseq_8* rng,
                                          uint8_t delta);

/* Functions to seed the RNG state, one version for each size and each
 * style.  Unlike the step functions, regular users can and should call
 * these functions.
 */

extern inline void pcg_oneseq_8_srandom_r(struct pcg_state_8* rng,
                                          uint8_t initstate);

extern inline void pcg_mcg_8_srandom_r(struct pcg_state_8* rng,
                                       uint8_t initstate);

extern inline void pcg_unique_8_srandom_r(struct pcg_state_8* rng,
                                          uint8_t initstate);

extern inline void pcg_setseq_8_srandom_r(struct pcg_state_setseq_8* rng,
                                          uint8_t initstate, uint8_t initseq);

/* Now, finally we create each of the individual generators. We provide
 * a random_r function that provides a random number of the appropriate
 * type (using the full range of the type) and a boundedrand_r version
 * that provides
 *
 * Implementation notes for boundedrand_r:
 *
 *     To avoid bias, we need to make the range of the RNG a multiple of
 *     bound, which we do by dropping output less than a threshold.
 *     Let's consider a 32-bit case...  A naive scheme to calculate the
 *     threshold would be to do
 *
 *         uint32_t threshold = 0x100000000ull % bound;
 *
 *     but 64-bit div/mod is slower than 32-bit div/mod (especially on
 *     32-bit platforms).  In essence, we do
 *
 *         uint32_t threshold = (0x100000000ull-bound) % bound;
 *
 *     because this version will calculate the same modulus, but the LHS
 *     value is less than 2^32.
 *
 *     (Note that using modulo is only wise for good RNGs, poorer RNGs
 *     such as raw LCGs do better using a technique based on division.)
 *     Empricical tests show that division is preferable to modulus for
 *     reducting the range of an RNG.  It's faster, and sometimes it can
 *     even be statistically prefereable.
 */

/* Generation functions for XSH RS */

/* Generation functions for XSH RR */

/* Generation functions for RXS M XS (no MCG versions because they
 * don't make sense when you want to use the entire state)
 */

extern inline uint8_t pcg_oneseq_8_rxs_m_xs_8_random_r(struct pcg_state_8* rng);

extern inline uint8_t
pcg_oneseq_8_rxs_m_xs_8_boundedrand_r(struct pcg_state_8* rng, uint8_t bound);

extern inline uint8_t
pcg_setseq_8_rxs_m_xs_8_random_r(struct pcg_state_setseq_8* rng);

extern inline uint8_t
pcg_setseq_8_rxs_m_xs_8_boundedrand_r(struct pcg_state_setseq_8* rng,
                                      uint8_t bound);

/* Generation functions for XSL RR (only defined for "large" types) */

/* Generation functions for XSL RR RR (only defined for "large" types) */

