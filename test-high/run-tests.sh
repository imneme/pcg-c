#!/bin/sh
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

echo Performing a quick sanity check...

mkdir -p actual
rm -f actual/*

./check-pcg32-global > actual/check-pcg32-global.out
./check-pcg64-global > actual/check-pcg64-global.out

./check-pcg8i > actual/check-pcg8i.out
./check-pcg8si > actual/check-pcg8si.out

./check-pcg16i > actual/check-pcg16i.out
./check-pcg16si > actual/check-pcg16si.out

./check-pcg32si > actual/check-pcg32si.out
./check-pcg32i > actual/check-pcg32i.out

./check-pcg32 > actual/check-pcg32.out
./check-pcg32f > actual/check-pcg32f.out
./check-pcg32s > actual/check-pcg32s.out
./check-pcg32u > /dev/null

./check-pcg64si > actual/check-pcg64si.out
./check-pcg64i > actual/check-pcg64i.out

./check-pcg64 > actual/check-pcg64.out
./check-pcg64f > actual/check-pcg64f.out
./check-pcg64s > actual/check-pcg64s.out
./check-pcg64u > /dev/null

./check-pcg128i > actual/check-pcg128i.out
./check-pcg128si > actual/check-pcg128si.out

find actual -type f -size -64c -delete

if diff -x .gitignore -ru expected actual
then
    echo All tests succeeded.
else
    echo ''
    if diff -x "*-pcg64[fsu].out" -x "*-pcg64-global.out" -x "*-pcg64.out" \
            -x "*-pcg128*.out" -x .gitignore -ru expected actual > /dev/null
    then
        echo All tests except tests requiring 128-bit math succceed.
    else
        echo ERROR: Some tests failed.
    fi
fi
