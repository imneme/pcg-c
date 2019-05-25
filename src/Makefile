OBJS = pcg-advance-8.o pcg-advance-16.o pcg-advance-32.o pcg-advance-64.o \
       pcg-advance-128.o pcg-output-8.o pcg-output-16.o pcg-output-32.o   \
       pcg-output-64.o pcg-output-128.o pcg-rngs-8.o pcg-rngs-16.o        \
       pcg-rngs-32.o pcg-rngs-64.o pcg-rngs-128.o \
       pcg-global-32.o pcg-global-64.o

CPPFLAGS += -I../include
CFLAGS += -O3 -Wall
CFLAGS   += -std=c99

all: libpcg_random.a

clean:
	rm -f *.a *.o

libpcg_random.a: $(OBJS)
	ar rc $@ $^
	ranlib $@

# RNGs at different sizes

pcg-rngs-8.o: pcg-rngs-8.c ../include/pcg_variants.h
pcg-rngs-16.o: pcg-rngs-16.c ../include/pcg_variants.h
pcg-rngs-32.o: pcg-rngs-32.c ../include/pcg_variants.h
pcg-rngs-64.o: pcg-rngs-64.c ../include/pcg_variants.h
pcg-rngs-128.o: pcg-rngs-128.c ../include/pcg_variants.h

# Jump-ahead functions at different sizes

pcg-advance-8.o: pcg-advance-8.c ../include/pcg_variants.h
pcg-advance-16.o: pcg-advance-16.c ../include/pcg_variants.h
pcg-advance-32.o: pcg-advance-32.c ../include/pcg_variants.h
pcg-advance-64.o: pcg-advance-64.c ../include/pcg_variants.h
pcg-advance-128.o: pcg-advance-128.c ../include/pcg_variants.h

# Output functions at different sizes (usually inlined)

pcg-output-8.o: pcg-output-8.c ../include/pcg_variants.h
pcg-output-16.o: pcg-output-16.c ../include/pcg_variants.h
pcg-output-32.o: pcg-output-32.c ../include/pcg_variants.h
pcg-output-64.o: pcg-output-64.c ../include/pcg_variants.h
pcg-output-128.o: pcg-output-128.c ../include/pcg_variants.h

# Global RNGs

pcg-global-32.o: pcg-global-32.c ../include/pcg_variants.h
pcg-global-64.o: pcg-global-64.c ../include/pcg_variants.h

