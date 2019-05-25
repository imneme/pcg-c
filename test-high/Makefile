# 
# PCG Random Number Generation for C.
# 
# Copyright 2014-2017 Melissa O'Neill <oneill@pcg-random.org>,
#                     and the PCG Project contributors.
#
# SPDX-License-Identifier: (Apache-2.0 OR MIT)
#
# Licensed under the Apache License, Version 2.0 (provided in
# LICENSE-APACHE.txt and at http://www.apache.org/licenses/LICENSE-2.0)
# or under the MIT license (provided in LICENSE-MIT.txt and at
# http://opensource.org/licenses/MIT), at your option. This file may not
# be copied, modified, or distributed except according to those terms.
#
# Distributed on an "AS IS" BASIS, WITHOUT WARRANTY OF ANY KIND, either
# express or implied.  See your chosen license for details.
#
# For additional information about the PCG random number generation scheme,
# visit http://www.pcg-random.org/.
#

TARGETS = check-pcg128i check-pcg128si check-pcg16i check-pcg16si check-pcg32 \
          check-pcg32f check-pcg32i check-pcg32s check-pcg32si check-pcg32u   \
          check-pcg64 check-pcg64f check-pcg64i check-pcg64s check-pcg64si    \
          check-pcg64u check-pcg8i check-pcg8si \
          check-pcg32-global check-pcg64-global

LDFLAGS  += -L../src
LDLIBS   += -lpcg_random
CPPFLAGS += -I../include -I../extras
CFLAGS   += -std=c99 -Wall

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
