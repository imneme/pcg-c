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
 
/* This code provides a mechanism for getting external randomness for 
 * seeding purposes.  Usually, it's just a wrapper around reading
 * /dev/random.
 *
 * Alas, because not every system provides /dev/random, we need a fallback.
 * We also need to try to test whether or not to use the fallback.
 */

#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

#include "pcg_variants.h"
#include "pcg_spinlock.h"

#include "entropy.h"

#ifndef IS_UNIX
#if !defined(_WIN32) && (defined(__unix__)  || defined(__unix) \
                         || (defined(__APPLE__) && defined(__MACH__)))
    #define IS_UNIX 1
#else
    #define IS_UNIX 0
#endif
#endif

/* If HAVE_DEV_RANDOM is set, we use that value, otherwise we guess */
#ifndef HAVE_DEV_RANDOM
#define HAVE_DEV_RANDOM         IS_UNIX
#endif

#if HAVE_DEV_RANDOM
    #include <fcntl.h>
    #include <unistd.h>
#endif

#if HAVE_DEV_RANDOM 
/* entropy_getbytes(dest, size):
 *     Use /dev/urandom to get some external entropy for seeding purposes.
 *
 * Note:
 *     If reading /dev/urandom fails (which ought to never happen), it returns
 *     false, otherwise it returns true.  If it fails, you could instead call
 *     fallback_entropy_getbytes which always succeeds.
 */

bool entropy_getbytes(void* dest, size_t size)
{
    int fd = open("/dev/urandom", O_RDONLY);
    if (fd < 0)
        return false;
    ssize_t sz = read(fd, dest, size);
    return (close(fd) == 0) && (sz == (ssize_t) size);
}
#else
bool entropy_getbytes(void* dest, size_t size)
{
    fallback_entropy_getbytes(dest, size);
    return true;
}
#endif

/* fallback_entropy_getbytes(dest, size):
 *     Works like the /dev/random version above, but avoids using /dev/random.
 *     Instead, it uses a private RNG (so that repeated calls will return
 *     different seeds).  Makes no attempt at cryptographic security.
 */

void fallback_entropy_getbytes(void* dest, size_t size)
{
    /* Most modern OSs use address-space randomization, meaning that we can
       use the address of stack variables and system library code as
       initializers.  It's not as good as using /dev/random, but probably
       better than using the current time alone. */

    static PCG_SPINLOCK_DECLARE(mutex);
    PCG_SPINLOCK_LOCK(mutex);

    static int intitialized = 0;
    static pcg32_random_t entropy_rng;
    
    if (!intitialized) {
        int dummyvar;
        pcg32_srandom_r(&entropy_rng,
                        time(NULL) ^ (intptr_t)&fallback_entropy_getbytes, 
                        (intptr_t)&dummyvar);
        intitialized = 1;
    }
    
    char* dest_cp = (char*) dest;
    for (size_t i = 0; i < size; ++i) {
        dest_cp[i] = (char) pcg32_random_r(&entropy_rng);
    }

    PCG_SPINLOCK_UNLOCK(mutex);
}
