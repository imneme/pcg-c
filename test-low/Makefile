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

TARGETS =   check-mcg-128-rxs-m-64 check-mcg-128-xsh-rr-64             \
            check-mcg-128-xsh-rs-64 check-mcg-128-xsl-rr-64            \
            check-mcg-16-rxs-m-8 check-mcg-16-xsh-rr-8                 \
            check-mcg-16-xsh-rs-8 check-mcg-32-rxs-m-16                \
            check-mcg-32-xsh-rr-16 check-mcg-32-xsh-rs-16              \
            check-mcg-64-rxs-m-32 check-mcg-64-xsh-rr-32               \
            check-mcg-64-xsh-rs-32 check-mcg-64-xsl-rr-32              \
            check-oneseq-128-rxs-m-64 check-oneseq-128-rxs-m-xs-128    \
            check-oneseq-128-xsh-rr-64 check-oneseq-128-xsh-rs-64      \
            check-oneseq-128-xsl-rr-64 check-oneseq-128-xsl-rr-rr-128  \
            check-oneseq-16-rxs-m-8 check-oneseq-16-rxs-m-xs-16        \
            check-oneseq-16-xsh-rr-8 check-oneseq-16-xsh-rs-8          \
            check-oneseq-32-rxs-m-16 check-oneseq-32-rxs-m-xs-32       \
            check-oneseq-32-xsh-rr-16 check-oneseq-32-xsh-rs-16        \
            check-oneseq-64-rxs-m-32 check-oneseq-64-rxs-m-xs-64       \
            check-oneseq-64-xsh-rr-32 check-oneseq-64-xsh-rs-32        \
            check-oneseq-64-xsl-rr-32 check-oneseq-64-xsl-rr-rr-64     \
            check-oneseq-8-rxs-m-xs-8 check-setseq-128-rxs-m-64        \
            check-setseq-128-rxs-m-xs-128 check-setseq-128-xsh-rr-64   \
            check-setseq-128-xsh-rs-64 check-setseq-128-xsl-rr-64      \
            check-setseq-128-xsl-rr-rr-128 check-setseq-16-rxs-m-8     \
            check-setseq-16-rxs-m-xs-16 check-setseq-16-xsh-rr-8       \
            check-setseq-16-xsh-rs-8 check-setseq-32-rxs-m-16          \
            check-setseq-32-rxs-m-xs-32 check-setseq-32-xsh-rr-16      \
            check-setseq-32-xsh-rs-16 check-setseq-64-rxs-m-32         \
            check-setseq-64-rxs-m-xs-64 check-setseq-64-xsh-rr-32      \
            check-setseq-64-xsh-rs-32 check-setseq-64-xsl-rr-32        \
            check-setseq-64-xsl-rr-rr-64 check-setseq-8-rxs-m-xs-8     \
            check-unique-128-rxs-m-64 check-unique-128-rxs-m-xs-128    \
            check-unique-128-xsh-rr-64 check-unique-128-xsh-rs-64      \
            check-unique-128-xsl-rr-64 check-unique-128-xsl-rr-rr-128  \
            check-unique-16-rxs-m-8 check-unique-16-rxs-m-xs-16        \
            check-unique-16-xsh-rr-8 check-unique-16-xsh-rs-8          \
            check-unique-32-rxs-m-16 check-unique-32-rxs-m-xs-32       \
            check-unique-32-xsh-rr-16 check-unique-32-xsh-rs-16        \
            check-unique-64-rxs-m-32 check-unique-64-rxs-m-xs-64       \
            check-unique-64-xsh-rr-32 check-unique-64-xsh-rs-32        \
            check-unique-64-xsl-rr-32 check-unique-64-xsl-rr-rr-64

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


check-mcg-128-rxs-m-64: check-mcg-128-rxs-m-64.o ../extras/entropy.o
check-mcg-128-xsh-rr-64: check-mcg-128-xsh-rr-64.o ../extras/entropy.o
check-mcg-128-xsh-rs-64: check-mcg-128-xsh-rs-64.o ../extras/entropy.o
check-mcg-128-xsl-rr-64: check-mcg-128-xsl-rr-64.o ../extras/entropy.o
check-mcg-16-rxs-m-8: check-mcg-16-rxs-m-8.o ../extras/entropy.o
check-mcg-16-xsh-rr-8: check-mcg-16-xsh-rr-8.o ../extras/entropy.o
check-mcg-16-xsh-rs-8: check-mcg-16-xsh-rs-8.o ../extras/entropy.o
check-mcg-32-rxs-m-16: check-mcg-32-rxs-m-16.o ../extras/entropy.o
check-mcg-32-xsh-rr-16: check-mcg-32-xsh-rr-16.o ../extras/entropy.o
check-mcg-32-xsh-rs-16: check-mcg-32-xsh-rs-16.o ../extras/entropy.o
check-mcg-64-rxs-m-32: check-mcg-64-rxs-m-32.o ../extras/entropy.o
check-mcg-64-xsh-rr-32: check-mcg-64-xsh-rr-32.o ../extras/entropy.o
check-mcg-64-xsh-rs-32: check-mcg-64-xsh-rs-32.o ../extras/entropy.o
check-mcg-64-xsl-rr-32: check-mcg-64-xsl-rr-32.o ../extras/entropy.o
check-oneseq-128-rxs-m-64: check-oneseq-128-rxs-m-64.o ../extras/entropy.o
check-oneseq-128-rxs-m-xs-128: check-oneseq-128-rxs-m-xs-128.o ../extras/entropy.o
check-oneseq-128-xsh-rr-64: check-oneseq-128-xsh-rr-64.o ../extras/entropy.o
check-oneseq-128-xsh-rs-64: check-oneseq-128-xsh-rs-64.o ../extras/entropy.o
check-oneseq-128-xsl-rr-64: check-oneseq-128-xsl-rr-64.o ../extras/entropy.o
check-oneseq-128-xsl-rr-rr-128: check-oneseq-128-xsl-rr-rr-128.o ../extras/entropy.o
check-oneseq-16-rxs-m-8: check-oneseq-16-rxs-m-8.o ../extras/entropy.o
check-oneseq-16-rxs-m-xs-16: check-oneseq-16-rxs-m-xs-16.o ../extras/entropy.o
check-oneseq-16-xsh-rr-8: check-oneseq-16-xsh-rr-8.o ../extras/entropy.o
check-oneseq-16-xsh-rs-8: check-oneseq-16-xsh-rs-8.o ../extras/entropy.o
check-oneseq-32-rxs-m-16: check-oneseq-32-rxs-m-16.o ../extras/entropy.o
check-oneseq-32-rxs-m-xs-32: check-oneseq-32-rxs-m-xs-32.o ../extras/entropy.o
check-oneseq-32-xsh-rr-16: check-oneseq-32-xsh-rr-16.o ../extras/entropy.o
check-oneseq-32-xsh-rs-16: check-oneseq-32-xsh-rs-16.o ../extras/entropy.o
check-oneseq-64-rxs-m-32: check-oneseq-64-rxs-m-32.o ../extras/entropy.o
check-oneseq-64-rxs-m-xs-64: check-oneseq-64-rxs-m-xs-64.o ../extras/entropy.o
check-oneseq-64-xsh-rr-32: check-oneseq-64-xsh-rr-32.o ../extras/entropy.o
check-oneseq-64-xsh-rs-32: check-oneseq-64-xsh-rs-32.o ../extras/entropy.o
check-oneseq-64-xsl-rr-32: check-oneseq-64-xsl-rr-32.o ../extras/entropy.o
check-oneseq-64-xsl-rr-rr-64: check-oneseq-64-xsl-rr-rr-64.o ../extras/entropy.o
check-oneseq-8-rxs-m-xs-8: check-oneseq-8-rxs-m-xs-8.o ../extras/entropy.o
check-setseq-128-rxs-m-64: check-setseq-128-rxs-m-64.o ../extras/entropy.o
check-setseq-128-rxs-m-xs-128: check-setseq-128-rxs-m-xs-128.o ../extras/entropy.o
check-setseq-128-xsh-rr-64: check-setseq-128-xsh-rr-64.o ../extras/entropy.o
check-setseq-128-xsh-rs-64: check-setseq-128-xsh-rs-64.o ../extras/entropy.o
check-setseq-128-xsl-rr-64: check-setseq-128-xsl-rr-64.o ../extras/entropy.o
check-setseq-128-xsl-rr-rr-128: check-setseq-128-xsl-rr-rr-128.o ../extras/entropy.o
check-setseq-16-rxs-m-8: check-setseq-16-rxs-m-8.o ../extras/entropy.o
check-setseq-16-rxs-m-xs-16: check-setseq-16-rxs-m-xs-16.o ../extras/entropy.o
check-setseq-16-xsh-rr-8: check-setseq-16-xsh-rr-8.o ../extras/entropy.o
check-setseq-16-xsh-rs-8: check-setseq-16-xsh-rs-8.o ../extras/entropy.o
check-setseq-32-rxs-m-16: check-setseq-32-rxs-m-16.o ../extras/entropy.o
check-setseq-32-rxs-m-xs-32: check-setseq-32-rxs-m-xs-32.o ../extras/entropy.o
check-setseq-32-xsh-rr-16: check-setseq-32-xsh-rr-16.o ../extras/entropy.o
check-setseq-32-xsh-rs-16: check-setseq-32-xsh-rs-16.o ../extras/entropy.o
check-setseq-64-rxs-m-32: check-setseq-64-rxs-m-32.o ../extras/entropy.o
check-setseq-64-rxs-m-xs-64: check-setseq-64-rxs-m-xs-64.o ../extras/entropy.o
check-setseq-64-xsh-rr-32: check-setseq-64-xsh-rr-32.o ../extras/entropy.o
check-setseq-64-xsh-rs-32: check-setseq-64-xsh-rs-32.o ../extras/entropy.o
check-setseq-64-xsl-rr-32: check-setseq-64-xsl-rr-32.o ../extras/entropy.o
check-setseq-64-xsl-rr-rr-64: check-setseq-64-xsl-rr-rr-64.o ../extras/entropy.o
check-setseq-8-rxs-m-xs-8: check-setseq-8-rxs-m-xs-8.o ../extras/entropy.o
check-unique-128-rxs-m-64: check-unique-128-rxs-m-64.o ../extras/entropy.o
check-unique-128-rxs-m-xs-128: check-unique-128-rxs-m-xs-128.o ../extras/entropy.o
check-unique-128-xsh-rr-64: check-unique-128-xsh-rr-64.o ../extras/entropy.o
check-unique-128-xsh-rs-64: check-unique-128-xsh-rs-64.o ../extras/entropy.o
check-unique-128-xsl-rr-64: check-unique-128-xsl-rr-64.o ../extras/entropy.o
check-unique-128-xsl-rr-rr-128: check-unique-128-xsl-rr-rr-128.o ../extras/entropy.o
check-unique-16-rxs-m-8: check-unique-16-rxs-m-8.o ../extras/entropy.o
check-unique-16-rxs-m-xs-16: check-unique-16-rxs-m-xs-16.o ../extras/entropy.o
check-unique-16-xsh-rr-8: check-unique-16-xsh-rr-8.o ../extras/entropy.o
check-unique-16-xsh-rs-8: check-unique-16-xsh-rs-8.o ../extras/entropy.o
check-unique-32-rxs-m-16: check-unique-32-rxs-m-16.o ../extras/entropy.o
check-unique-32-rxs-m-xs-32: check-unique-32-rxs-m-xs-32.o ../extras/entropy.o
check-unique-32-xsh-rr-16: check-unique-32-xsh-rr-16.o ../extras/entropy.o
check-unique-32-xsh-rs-16: check-unique-32-xsh-rs-16.o ../extras/entropy.o
check-unique-64-rxs-m-32: check-unique-64-rxs-m-32.o ../extras/entropy.o
check-unique-64-rxs-m-xs-64: check-unique-64-rxs-m-xs-64.o ../extras/entropy.o
check-unique-64-xsh-rr-32: check-unique-64-xsh-rr-32.o ../extras/entropy.o
check-unique-64-xsh-rs-32: check-unique-64-xsh-rs-32.o ../extras/entropy.o
check-unique-64-xsl-rr-32: check-unique-64-xsl-rr-32.o ../extras/entropy.o
check-unique-64-xsl-rr-rr-64: check-unique-64-xsl-rr-rr-64.o ../extras/entropy.o


check-base.o: check-base.c ../extras/entropy.h
check-mcg-128-rxs-m-64.o: check-mcg-128-rxs-m-64.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-mcg-128-xsh-rr-64.o: check-mcg-128-xsh-rr-64.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-mcg-128-xsh-rs-64.o: check-mcg-128-xsh-rs-64.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-mcg-128-xsl-rr-64.o: check-mcg-128-xsl-rr-64.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-mcg-16-rxs-m-8.o: check-mcg-16-rxs-m-8.c ../include/pcg_variants.h \
  check-base.c ../extras/entropy.h
check-mcg-16-xsh-rr-8.o: check-mcg-16-xsh-rr-8.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-mcg-16-xsh-rs-8.o: check-mcg-16-xsh-rs-8.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-mcg-32-rxs-m-16.o: check-mcg-32-rxs-m-16.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-mcg-32-xsh-rr-16.o: check-mcg-32-xsh-rr-16.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-mcg-32-xsh-rs-16.o: check-mcg-32-xsh-rs-16.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-mcg-64-rxs-m-32.o: check-mcg-64-rxs-m-32.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-mcg-64-xsh-rr-32.o: check-mcg-64-xsh-rr-32.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-mcg-64-xsh-rs-32.o: check-mcg-64-xsh-rs-32.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-mcg-64-xsl-rr-32.o: check-mcg-64-xsl-rr-32.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-oneseq-128-rxs-m-64.o: check-oneseq-128-rxs-m-64.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-oneseq-128-rxs-m-xs-128.o: check-oneseq-128-rxs-m-xs-128.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-oneseq-128-xsh-rr-64.o: check-oneseq-128-xsh-rr-64.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-oneseq-128-xsh-rs-64.o: check-oneseq-128-xsh-rs-64.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-oneseq-128-xsl-rr-64.o: check-oneseq-128-xsl-rr-64.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-oneseq-128-xsl-rr-rr-128.o: check-oneseq-128-xsl-rr-rr-128.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-oneseq-16-rxs-m-8.o: check-oneseq-16-rxs-m-8.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-oneseq-16-rxs-m-xs-16.o: check-oneseq-16-rxs-m-xs-16.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-oneseq-16-xsh-rr-8.o: check-oneseq-16-xsh-rr-8.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-oneseq-16-xsh-rs-8.o: check-oneseq-16-xsh-rs-8.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-oneseq-32-rxs-m-16.o: check-oneseq-32-rxs-m-16.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-oneseq-32-rxs-m-xs-32.o: check-oneseq-32-rxs-m-xs-32.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-oneseq-32-xsh-rr-16.o: check-oneseq-32-xsh-rr-16.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-oneseq-32-xsh-rs-16.o: check-oneseq-32-xsh-rs-16.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-oneseq-64-rxs-m-32.o: check-oneseq-64-rxs-m-32.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-oneseq-64-rxs-m-xs-64.o: check-oneseq-64-rxs-m-xs-64.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-oneseq-64-xsh-rr-32.o: check-oneseq-64-xsh-rr-32.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-oneseq-64-xsh-rs-32.o: check-oneseq-64-xsh-rs-32.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-oneseq-64-xsl-rr-32.o: check-oneseq-64-xsl-rr-32.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-oneseq-64-xsl-rr-rr-64.o: check-oneseq-64-xsl-rr-rr-64.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-oneseq-8-rxs-m-xs-8.o: check-oneseq-8-rxs-m-xs-8.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-setseq-128-rxs-m-64.o: check-setseq-128-rxs-m-64.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-setseq-128-rxs-m-xs-128.o: check-setseq-128-rxs-m-xs-128.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-setseq-128-xsh-rr-64.o: check-setseq-128-xsh-rr-64.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-setseq-128-xsh-rs-64.o: check-setseq-128-xsh-rs-64.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-setseq-128-xsl-rr-64.o: check-setseq-128-xsl-rr-64.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-setseq-128-xsl-rr-rr-128.o: check-setseq-128-xsl-rr-rr-128.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-setseq-16-rxs-m-8.o: check-setseq-16-rxs-m-8.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-setseq-16-rxs-m-xs-16.o: check-setseq-16-rxs-m-xs-16.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-setseq-16-xsh-rr-8.o: check-setseq-16-xsh-rr-8.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-setseq-16-xsh-rs-8.o: check-setseq-16-xsh-rs-8.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-setseq-32-rxs-m-16.o: check-setseq-32-rxs-m-16.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-setseq-32-rxs-m-xs-32.o: check-setseq-32-rxs-m-xs-32.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-setseq-32-xsh-rr-16.o: check-setseq-32-xsh-rr-16.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-setseq-32-xsh-rs-16.o: check-setseq-32-xsh-rs-16.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-setseq-64-rxs-m-32.o: check-setseq-64-rxs-m-32.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-setseq-64-rxs-m-xs-64.o: check-setseq-64-rxs-m-xs-64.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-setseq-64-xsh-rr-32.o: check-setseq-64-xsh-rr-32.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-setseq-64-xsh-rs-32.o: check-setseq-64-xsh-rs-32.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-setseq-64-xsl-rr-32.o: check-setseq-64-xsl-rr-32.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-setseq-64-xsl-rr-rr-64.o: check-setseq-64-xsl-rr-rr-64.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-setseq-8-rxs-m-xs-8.o: check-setseq-8-rxs-m-xs-8.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-unique-128-rxs-m-64.o: check-unique-128-rxs-m-64.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-unique-128-rxs-m-xs-128.o: check-unique-128-rxs-m-xs-128.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-unique-128-xsh-rr-64.o: check-unique-128-xsh-rr-64.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-unique-128-xsh-rs-64.o: check-unique-128-xsh-rs-64.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-unique-128-xsl-rr-64.o: check-unique-128-xsl-rr-64.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-unique-128-xsl-rr-rr-128.o: check-unique-128-xsl-rr-rr-128.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-unique-16-rxs-m-8.o: check-unique-16-rxs-m-8.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-unique-16-rxs-m-xs-16.o: check-unique-16-rxs-m-xs-16.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-unique-16-xsh-rr-8.o: check-unique-16-xsh-rr-8.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-unique-16-xsh-rs-8.o: check-unique-16-xsh-rs-8.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-unique-32-rxs-m-16.o: check-unique-32-rxs-m-16.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-unique-32-rxs-m-xs-32.o: check-unique-32-rxs-m-xs-32.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-unique-32-xsh-rr-16.o: check-unique-32-xsh-rr-16.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-unique-32-xsh-rs-16.o: check-unique-32-xsh-rs-16.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-unique-64-rxs-m-32.o: check-unique-64-rxs-m-32.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-unique-64-rxs-m-xs-64.o: check-unique-64-rxs-m-xs-64.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-unique-64-xsh-rr-32.o: check-unique-64-xsh-rr-32.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-unique-64-xsh-rs-32.o: check-unique-64-xsh-rs-32.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-unique-64-xsl-rr-32.o: check-unique-64-xsl-rr-32.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
check-unique-64-xsl-rr-rr-64.o: check-unique-64-xsl-rr-rr-64.c \
  ../include/pcg_variants.h check-base.c ../extras/entropy.h
