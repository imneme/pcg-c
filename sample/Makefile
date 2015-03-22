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

TARGETS = pcg32-demo pcg32-global-demo pcg32x2-demo pcg64-demo

LDFLAGS  += -L../src
LDLIBS   += -lpcg_random
CPPFLAGS += -I../include -I../extras
CFLAGS   += -std=c99

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
