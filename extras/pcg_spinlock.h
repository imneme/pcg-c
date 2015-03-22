/*
 * PCG Random Number Generation for C.
 *
 * Copyright 2014 Melissa O'Neill <oneill@pcg-random.org>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 *
 * For additional information about the PCG random number generation scheme,
 * including its license and other licensing options, visit
 *
 *     http://www.pcg-random.org
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
