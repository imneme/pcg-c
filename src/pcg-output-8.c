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

/*
 * Rotate helper functions.
 */

extern inline uint8_t pcg_rotr_8(uint8_t value, unsigned int rot);

/*
 * Output functions.  These are the core of the PCG generation scheme.
 */

// XSH RS

extern inline uint8_t pcg_output_xsh_rs_16_8(uint16_t state);

// XSH RR

extern inline uint8_t pcg_output_xsh_rr_16_8(uint16_t state);

// RXS M XS

extern inline uint8_t pcg_output_rxs_m_xs_8_8(uint8_t state);

// XSL RR (only defined for >= 64 bits)

// XSL RR RR (only defined for >= 64 bits)

