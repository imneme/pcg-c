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

#ifndef ENTROPY_H_INCLUDED
#define ENTROPY_H_INCLUDED 1

#include <stdbool.h>

#if __cplusplus
extern "C" {
#endif

extern bool entropy_getbytes(void* dest, size_t size);
extern void fallback_entropy_getbytes(void* dest, size_t size);

#if __cplusplus
}
#endif

#endif // ENTROPY_H_INCLUDED
