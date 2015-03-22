#!/bin/sh
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
