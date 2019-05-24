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
 
/* This code provides a minimal spinlock implementation.  It's only used
 * in supporting fallback_entropy_getbytes.
 */

#ifndef PCG_SPINLOCK_H_INCLUDED
#define PCG_SPINLOCK_H_INCLUDED 1

#ifndef __has_include
    #define INCLUDE_OKAY(x) 1
#else
    #define INCLUDE_OKAY(x) __has_include(x)
#endif

#if __STDC_VERSION__ >= 201112L && !__STDC_NO_ATOMICS__ \
        && INCLUDE_OKAY(<stdatomic.h>)
    #include <stdatomic.h>
    #define PCG_SPINLOCK_DECLARE(mutex) atomic_flag mutex = ATOMIC_FLAG_INIT
    #define PCG_SPINLOCK_LOCK(mutex)    do {} \
                                        while (atomic_flag_test_and_set(&mutex))
    #define PCG_SPINLOCK_UNLOCK(mutex)  atomic_flag_clear(&mutex)
#elif __GNUC__
    #define PCG_SPINLOCK_DECLARE(mutex) volatile int mutex = 0
    #define PCG_SPINLOCK_LOCK(mutex)    \
                do {} while(__sync_lock_test_and_set(&mutex, 1))
    #define PCG_SPINLOCK_UNLOCK(mutex)  __sync_lock_release(&mutex)
#else
    #warning No implementation of spinlocks provided.  No thread safety.
    #define PCG_SPINLOCK_DECLARE(mutex) volatile int mutex = 0
    #define PCG_SPINLOCK_LOCK(mutex)    \
                do { while(mutex == 1){} mutex = 1; } while(0)
    #define PCG_SPINLOCK_UNLOCK(mutex)  mutex = 0;
#endif

#endif // PCG_SPINLOCK_H_INCLUDED
