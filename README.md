# PCG Random Number Generation, C Edition

[PCG-Random website]: http://www.pcg-random.org

This code provides an implementation of the PCG family of random number
generators, which are fast, statistically excellent, and offer a number of
useful features.

Full details can be found at the [PCG-Random website].  This version
of the code provides many family members -- if you just want one
simple generator, you may prefer the minimal version of the library.

There are two APIs, a low-level one which explicitly names the output
functions, and a higher-level one (which maps directly to the low-level
code).  Generally, you should use the high-level API.

## Documentation and Examples

Visit [PCG-Random website] for information on how to use this library, or look
at the sample code in the `sample` directory -- hopefully it should be fairly
self explanatory.

## Building

The code is written in C99-style C with no significant platform dependencies.
On a Unix-style system (e.g., Linux, Mac OS X) you should be able to just
type

    make

Almost all the real code is in `include/pcg_variants.h`.  Because the
individual RNGs have a very small amount of code, they are provided as
inline functions to allow the compiler the option of inlining them.
But because C requires there to also be an external definition, the
`src` directory contains code to build `libpcg_random.a` which provides
non-inline definitions for all the PCG generators.

On other systems, it should be straightforward to build a library by
compiling the files in the src directory.  Or, write your own file giving
an `extern` declaration for every function you actually use.

## Testing

Run

    make test

## Directory Structure

The directories are arranged as follows:

* `include` -- contains `pcg_variants.h`
* `src` -- code to define external versions of the inline functions from
  `pcg_variants.h` plus all the `_advance_r` functions.
* `test-low` -- test code for the low-level API where the functions have long
  scary-looking names
* `test-high` -- test code for the high-level API where the functions have
  shorter, less scary-looking names.
* `extras` -- other useful code, such as code to read /dev/random
* `sample` -- sample code, similar to the code in `test-high` but more human
  readable
  
## 128-bit Math

On systems that support it (64-bit systems using GCC or Clang), the library
provides RNGs that use 128-bit integer math. These generators produce 64-bit
output (or more) and have a period of 2^128.

If you don't have 128-bit support on your system, you aren't losing that much.
Thanks to the 2^63 random streams/sequences, you can gang together multiple
32-bit generators.  (Note: This approach *would not work* well with generators
that only have a single stream/sequence).  Example code is provided in
`sample/pcg32x2-demo.c`.

The C++ implementation provides 128-bit integers even on systems that don't
natively support it, but doing so would be too much trouble in C.




