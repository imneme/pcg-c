# 
# PCG Random Number Generation for C.
# 
# Copyright 2014 Melissa O'Neill <oneill@pcg-random.org>
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
# 
#     http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
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
