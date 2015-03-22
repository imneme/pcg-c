# 
# PCG Random Number Generation for C.
# 
# Copyright 2014 Melissa O'Neill <oneill@pcg-random.org>
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
# 
# For additional information about the PCG random number generation scheme,
# including its license and other licensing options, visit
# 
#     http://www.pcg-random.org
#

TARGETS = check-pcg128i check-pcg128si check-pcg16i check-pcg16si check-pcg32 \
          check-pcg32f check-pcg32i check-pcg32s check-pcg32si check-pcg32u   \
          check-pcg64 check-pcg64f check-pcg64i check-pcg64s check-pcg64si    \
          check-pcg64u check-pcg8i check-pcg8si \
          check-pcg32-global check-pcg64-global

LDFLAGS  += -L../src
LDLIBS   += -lpcg_random
CPPFLAGS += -I../include -I../extras
CFLAGS   += -std=c99

all: $(TARGETS)

clean:
	rm -f *.o $(TARGETS)
	rm -rf actual

test: $(TARGETS)
	sh run-tests.sh

../extras/entropy.o: ../extras/entropy.c ../include/pcg_variants.h \
  ../extras/pcg_spinlock.h ../extras/entropy.h


check-pcg128i: check-pcg128i.o ../extras/entropy.o
check-pcg128si: check-pcg128si.o ../extras/entropy.o
check-pcg16i: check-pcg16i.o ../extras/entropy.o
check-pcg16si: check-pcg16si.o ../extras/entropy.o
check-pcg32: check-pcg32.o ../extras/entropy.o
check-pcg32f: check-pcg32f.o ../extras/entropy.o
check-pcg32i: check-pcg32i.o ../extras/entropy.o
check-pcg32s: check-pcg32s.o ../extras/entropy.o
check-pcg32si: check-pcg32si.o ../extras/entropy.o
check-pcg32u: check-pcg32u.o ../extras/entropy.o
check-pcg64: check-pcg64.o ../extras/entropy.o
check-pcg64f: check-pcg64f.o ../extras/entropy.o
check-pcg64i: check-pcg64i.o ../extras/entropy.o
check-pcg64s: check-pcg64s.o ../extras/entropy.o
check-pcg64si: check-pcg64si.o ../extras/entropy.o
check-pcg64u: check-pcg64u.o ../extras/entropy.o
check-pcg8i: check-pcg8i.o ../extras/entropy.o
check-pcg8si: check-pcg8si.o ../extras/entropy.o

check-pcg32-global: check-pcg32-global.o ../extras/entropy.o
check-pcg64-global: check-pcg64-global.o ../extras/entropy.o


check-pcg128i.o: check-pcg128i.c ../include/pcg_variants.h check-base.c \
  ../extras/entropy.h
check-pcg128si.o: check-pcg128si.c ../include/pcg_variants.h check-base.c \
  ../extras/entropy.h
check-pcg16i.o: check-pcg16i.c ../include/pcg_variants.h check-base.c \
  ../extras/entropy.h
check-pcg16si.o: check-pcg16si.c ../include/pcg_variants.h check-base.c \
  ../extras/entropy.h
check-pcg32.o: check-pcg32.c ../include/pcg_variants.h check-base.c \
  ../extras/entropy.h
check-pcg32f.o: check-pcg32f.c ../include/pcg_variants.h check-base.c \
  ../extras/entropy.h
check-pcg32i.o: check-pcg32i.c ../include/pcg_variants.h check-base.c \
  ../extras/entropy.h
check-pcg32s.o: check-pcg32s.c ../include/pcg_variants.h check-base.c \
  ../extras/entropy.h
check-pcg32si.o: check-pcg32si.c ../include/pcg_variants.h check-base.c \
  ../extras/entropy.h
check-pcg32u.o: check-pcg32u.c ../include/pcg_variants.h check-base.c \
  ../extras/entropy.h
check-pcg64.o: check-pcg64.c ../include/pcg_variants.h check-base.c \
  ../extras/entropy.h
check-pcg64f.o: check-pcg64f.c ../include/pcg_variants.h check-base.c \
  ../extras/entropy.h
check-pcg64i.o: check-pcg64i.c ../include/pcg_variants.h check-base.c \
  ../extras/entropy.h
check-pcg64s.o: check-pcg64s.c ../include/pcg_variants.h check-base.c \
  ../extras/entropy.h
check-pcg64si.o: check-pcg64si.c ../include/pcg_variants.h check-base.c \
  ../extras/entropy.h
check-pcg64u.o: check-pcg64u.c ../include/pcg_variants.h check-base.c \
  ../extras/entropy.h
check-pcg8i.o: check-pcg8i.c ../include/pcg_variants.h check-base.c \
  ../extras/entropy.h
check-pcg8si.o: check-pcg8si.c ../include/pcg_variants.h check-base.c \
  ../extras/entropy.h

check-pcg32-global.o: check-pcg32-global.c ../include/pcg_variants.h \
  check-base.c ../extras/entropy.h
check-pcg64-global.o: check-pcg64-global.c ../include/pcg_variants.h \
  check-base.c ../extras/entropy.h
