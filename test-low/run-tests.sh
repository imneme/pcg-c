#!/bin/sh
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

echo Performing a quick sanity check...

mkdir -p actual
rm -f actual/*

# Setseq

./check-setseq-8-rxs-m-xs-8 > actual/check-setseq-8-rxs-m-xs-8.out
./check-setseq-16-xsh-rr-8 > actual/check-setseq-16-xsh-rr-8.out
./check-setseq-16-xsh-rs-8 > actual/check-setseq-16-xsh-rs-8.out
./check-setseq-16-rxs-m-xs-16 > actual/check-setseq-16-rxs-m-xs-16.out
./check-setseq-32-xsh-rr-16 > actual/check-setseq-32-xsh-rr-16.out
./check-setseq-32-xsh-rs-16 > actual/check-setseq-32-xsh-rs-16.out
./check-setseq-32-rxs-m-xs-32 > actual/check-setseq-32-rxs-m-xs-32.out
./check-setseq-64-xsh-rr-32 > actual/check-setseq-64-xsh-rr-32.out
./check-setseq-64-xsh-rs-32 > actual/check-setseq-64-xsh-rs-32.out
./check-setseq-64-xsl-rr-32 > actual/check-setseq-64-xsl-rr-32.out
./check-setseq-64-rxs-m-xs-64 > actual/check-setseq-64-rxs-m-xs-64.out
./check-setseq-64-xsl-rr-rr-64 > actual/check-setseq-64-xsl-rr-rr-64.out
./check-setseq-128-xsh-rr-64 > actual/check-setseq-128-xsh-rr-64.out
./check-setseq-128-xsh-rs-64 > actual/check-setseq-128-xsh-rs-64.out
./check-setseq-128-xsl-rr-64 > actual/check-setseq-128-xsl-rr-64.out
./check-setseq-128-rxs-m-xs-128 > actual/check-setseq-128-rxs-m-xs-128.out
./check-setseq-128-xsl-rr-rr-128 > actual/check-setseq-128-xsl-rr-rr-128.out

# Oneseq

./check-oneseq-8-rxs-m-xs-8 > actual/check-oneseq-8-rxs-m-xs-8.out
./check-oneseq-16-xsh-rr-8 > actual/check-oneseq-16-xsh-rr-8.out
./check-oneseq-16-xsh-rs-8 > actual/check-oneseq-16-xsh-rs-8.out
./check-oneseq-16-rxs-m-xs-16 > actual/check-oneseq-16-rxs-m-xs-16.out
./check-oneseq-32-xsh-rr-16 > actual/check-oneseq-32-xsh-rr-16.out
./check-oneseq-32-xsh-rs-16 > actual/check-oneseq-32-xsh-rs-16.out
./check-oneseq-32-rxs-m-xs-32 > actual/check-oneseq-32-rxs-m-xs-32.out
./check-oneseq-64-xsh-rr-32 > actual/check-oneseq-64-xsh-rr-32.out
./check-oneseq-64-xsh-rs-32 > actual/check-oneseq-64-xsh-rs-32.out
./check-oneseq-64-xsl-rr-32 > actual/check-oneseq-64-xsl-rr-32.out
./check-oneseq-64-rxs-m-xs-64 > actual/check-oneseq-64-rxs-m-xs-64.out
./check-oneseq-64-xsl-rr-rr-64 > actual/check-oneseq-64-xsl-rr-rr-64.out
./check-oneseq-128-xsh-rr-64 > actual/check-oneseq-128-xsh-rr-64.out
./check-oneseq-128-xsh-rs-64 > actual/check-oneseq-128-xsh-rs-64.out
./check-oneseq-128-xsl-rr-64 > actual/check-oneseq-128-xsl-rr-64.out
./check-oneseq-128-rxs-m-xs-128 > actual/check-oneseq-128-rxs-m-xs-128.out
./check-oneseq-128-xsl-rr-rr-128 > actual/check-oneseq-128-xsl-rr-rr-128.out

# MCG

./check-mcg-16-xsh-rr-8 > actual/check-mcg-16-xsh-rr-8.out
./check-mcg-16-xsh-rs-8 > actual/check-mcg-16-xsh-rs-8.out
./check-mcg-32-xsh-rr-16 > actual/check-mcg-32-xsh-rr-16.out
./check-mcg-32-xsh-rs-16 > actual/check-mcg-32-xsh-rs-16.out
./check-mcg-64-xsh-rr-32 > actual/check-mcg-64-xsh-rr-32.out
./check-mcg-64-xsh-rs-32 > actual/check-mcg-64-xsh-rs-32.out
./check-mcg-64-xsl-rr-32 > actual/check-mcg-64-xsl-rr-32.out
./check-mcg-128-xsh-rr-64 > actual/check-mcg-128-xsh-rr-64.out
./check-mcg-128-xsh-rs-64 > actual/check-mcg-128-xsh-rs-64.out
./check-mcg-128-xsl-rr-64 > actual/check-mcg-128-xsl-rr-64.out

# Unique

# The unique versions produce different outputs every run, so cannot be
# checked this way
# ./check-unique-16-xsh-rr-8 > actual/check-unique-16-xsh-rr-8.out
# ./check-unique-16-xsh-rs-8 > actual/check-unique-16-xsh-rs-8.out
# ./check-unique-16-rxs-m-xs-16 > actual/check-unique-16-rxs-m-xs-16.out
# ./check-unique-32-xsh-rr-16 > actual/check-unique-32-xsh-rr-16.out
# ./check-unique-32-xsh-rs-16 > actual/check-unique-32-xsh-rs-16.out
# ./check-unique-32-rxs-m-xs-32 > actual/check-unique-32-rxs-m-xs-32.out
# ./check-unique-64-xsh-rr-32 > actual/check-unique-64-xsh-rr-32.out
# ./check-unique-64-xsh-rs-32 > actual/check-unique-64-xsh-rs-32.out
# ./check-unique-64-xsl-rr-32 > actual/check-unique-64-xsl-rr-32.out
# ./check-unique-64-rxs-m-xs-64 > actual/check-unique-64-rxs-m-xs-64.out
# ./check-unique-64-xsl-rr-rr-64 > actual/check-unique-64-xsl-rr-rr-64.out
# ./check-unique-128-xsh-rr-64 > actual/check-unique-128-xsh-rr-64.out
# ./check-unique-128-xsh-rs-64 > actual/check-unique-128-xsh-rs-64.out
# ./check-unique-128-xsl-rr-64 > actual/check-unique-128-xsl-rr-64.out
# ./check-unique-128-rxs-m-xs-128 > actual/check-unique-128-rxs-m-xs-128.out
# ./check-unique-128-xsl-rr-rr-128 > actual/check-unique-128-xsl-rr-rr-128.out

./check-unique-16-xsh-rr-8       > /dev/null
./check-unique-16-xsh-rs-8       > /dev/null
./check-unique-16-rxs-m-xs-16    > /dev/null
./check-unique-32-xsh-rr-16      > /dev/null
./check-unique-32-xsh-rs-16      > /dev/null
./check-unique-32-rxs-m-xs-32    > /dev/null
./check-unique-64-xsh-rr-32      > /dev/null
./check-unique-64-xsh-rs-32      > /dev/null
./check-unique-64-xsl-rr-32      > /dev/null
./check-unique-64-rxs-m-xs-64    > /dev/null
./check-unique-64-xsl-rr-rr-64   > /dev/null
./check-unique-128-xsh-rr-64     > /dev/null
./check-unique-128-xsh-rs-64     > /dev/null
./check-unique-128-xsl-rr-64     > /dev/null
./check-unique-128-rxs-m-xs-128  > /dev/null
./check-unique-128-xsl-rr-rr-128 > /dev/null

find actual -type f -size -64c -delete

if diff -x .gitignore -ru expected actual
then
    echo All tests succeeded.
else
    echo ''
    if diff -x "*-128-*" -x .gitignore -ru expected actual > /dev/null
    then
        echo All tests except 128-bit tests succceed.
    else
        echo ERROR: Some tests failed.
    fi
fi
