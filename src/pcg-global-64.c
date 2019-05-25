/*
 * PCG Random Number Generation for C.
 *
 * Copyright 2014-2017 Melissa O'Neill <oneill@pcg-random.org>,
 *                     and the PCG Project contributors.
 *
 * SPDX-License-Identifier: (Apache-2.0 OR MIT)
 *
 * Licensed under the Apache License, Version 2.0 (provided in
 * LICENSE-APACHE.txt and at http://www.apache.org/licenses/LICENSE-2.0)
 * or under the MIT license (provided in LICENSE-MIT.txt and at
 * http://opensource.org/licenses/MIT), at your option. This file may not
 * be copied, modified, or distributed except according to those terms.
 *
 * Distributed on an "AS IS" BASIS, WITHOUT WARRANTY OF ANY KIND, either
 * express or implied.  See your chosen license for details.
 *
 * For additional information about the PCG random number generation scheme,
 * visit http://www.pcg-random.org/.
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

#if PCG_HAS_128BIT_OPS

static pcg64_random_t pcg64_global = PCG64_INITIALIZER;

uint64_t pcg64_random(void)
{
    return pcg64_random_r(&pcg64_global);
}

uint64_t pcg64_boundedrand(uint64_t bound)
{
    return pcg64_boundedrand_r(&pcg64_global, bound);
}

void pcg64_srandom(pcg128_t seed, pcg128_t seq)
{
    pcg64_srandom_r(&pcg64_global, seed, seq);
}

void pcg64_advance(pcg128_t delta)
{
    pcg64_advance_r(&pcg64_global, delta);
}

#endif
