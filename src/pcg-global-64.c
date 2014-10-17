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
 *     http://www.pcg-random.org
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

uint64_t pcg64_random()
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
