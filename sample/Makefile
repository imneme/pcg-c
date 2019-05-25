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

TARGETS = pcg32-demo pcg32-global-demo pcg32x2-demo pcg64-demo

LDFLAGS  += -L../src
LDLIBS   += -lpcg_random
CPPFLAGS += -I../include -I../extras
CFLAGS   += -std=c99 -Wall

all: $(TARGETS)

clean:
	rm -f *.o $(TARGETS)
	rm -rf actual

../extras/entropy.o: ../extras/entropy.c ../include/pcg_variants.h \
  ../extras/pcg_spinlock.h ../extras/entropy.h

pcg32-demo: pcg32-demo.o ../extras/entropy.o
pcg32-global-demo: pcg32-global-demo.o ../extras/entropy.o
pcg32x2-demo: pcg32x2-demo.o ../extras/entropy.o
pcg64-demo: pcg64-demo.o ../extras/entropy.o

pcg32-demo.o: pcg32-demo.c ../include/pcg_variants.h ../extras/entropy.h
pcg32-global-demo.o: pcg32-global-demo.c ../include/pcg_variants.h \
  ../extras/entropy.h
pcg32x2-demo.o: pcg32x2-demo.c ../include/pcg_variants.h ../extras/entropy.h
pcg64-demo.o: pcg64-demo.c ../include/pcg_variants.h ../extras/entropy.h
