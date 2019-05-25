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

all:
	cd src; $(MAKE)
	cd test-low; $(MAKE)
	cd test-high; $(MAKE)
	cd sample; $(MAKE)

PREFIX = /usr/local

install: all
	install src/libpcg_random.a $(PREFIX)/lib
	install -m 0644 include/pcg_variants.h $(PREFIX)/include

test:   all
	cd test-low; $(MAKE) test
	cd test-high; $(MAKE) test

clean:
	cd src; $(MAKE) clean
	cd test-low; $(MAKE) clean
	cd test-high; $(MAKE) clean
	cd sample; $(MAKE) clean
	rm -f extras/*.o
