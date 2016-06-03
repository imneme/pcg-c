
set(EXPECTED_DIR ${CMAKE_CURRENT_SOURCE_DIR}/expected)

set(TEST_NAMES
check-mcg-16-xsh-rr-8
check-mcg-16-xsh-rs-8
check-mcg-32-xsh-rr-16
check-mcg-32-xsh-rs-16
check-mcg-64-xsh-rr-32
check-mcg-64-xsh-rs-32
check-mcg-64-xsl-rr-32
check-oneseq-16-rxs-m-xs-16
check-oneseq-16-xsh-rr-8
check-oneseq-16-xsh-rs-8
check-oneseq-32-rxs-m-xs-32
check-oneseq-32-xsh-rr-16
check-oneseq-32-xsh-rs-16
check-oneseq-64-rxs-m-xs-64
check-oneseq-64-xsh-rr-32
check-oneseq-64-xsh-rs-32
check-oneseq-64-xsl-rr-32
check-oneseq-64-xsl-rr-rr-64
check-oneseq-8-rxs-m-xs-8
check-setseq-16-rxs-m-xs-16
check-setseq-16-xsh-rr-8
check-setseq-16-xsh-rs-8
check-setseq-32-rxs-m-xs-32
check-setseq-32-xsh-rr-16
check-setseq-32-xsh-rs-16
check-setseq-64-rxs-m-xs-64
check-setseq-64-xsh-rr-32
check-setseq-64-xsh-rs-32
check-setseq-64-xsl-rr-32
check-setseq-64-xsl-rr-rr-64
check-setseq-8-rxs-m-xs-8
)

if(PCG_HAS_128BIT_OPS)
set(TEST_NAMES ${TEST_NAMES}
check-mcg-128-xsh-rr-64
check-mcg-128-xsh-rs-64
check-mcg-128-xsl-rr-64
check-oneseq-128-rxs-m-xs-128
check-oneseq-128-xsh-rr-64
check-oneseq-128-xsh-rs-64
check-oneseq-128-xsl-rr-64
check-oneseq-128-xsl-rr-rr-128
check-setseq-128-rxs-m-xs-128
check-setseq-128-xsh-rr-64
check-setseq-128-xsh-rs-64
check-setseq-128-xsl-rr-64
check-setseq-128-xsl-rr-rr-128
)
endif(PCG_HAS_128BIT_OPS)

# tests that generate different outputs on each run
set(TEST_UNIQUE_NAMES
check-unique-16-rxs-m-xs-16
check-unique-16-xsh-rr-8
check-unique-16-xsh-rs-8
check-unique-32-rxs-m-xs-32
check-unique-32-xsh-rr-16
check-unique-32-xsh-rs-16
check-unique-64-rxs-m-xs-64
check-unique-64-xsh-rr-32
check-unique-64-xsh-rs-32
check-unique-64-xsl-rr-32
check-unique-64-xsl-rr-rr-64
)

if(PCG_HAS_128BIT_OPS)
set(TEST_UNIQUE_NAMES ${TEST_UNIQUE_NAMES}
check-unique-128-rxs-m-xs-128
check-unique-128-xsh-rr-64
check-unique-128-xsh-rs-64
check-unique-128-xsl-rr-64
check-unique-128-xsl-rr-rr-128
)
endif(PCG_HAS_128BIT_OPS)

macro (add_unique_test target)
# Notes: could use ${CMAKE_COMMAND} -E compare_files for file comparison, but it does not provide diff on failure :/
   set(ACTUAL_PATH ${target}-actual.txt)
   add_test( NAME ${target} COMMAND $<TARGET_FILE:${target}> --redirect-output ${ACTUAL_PATH} )
endmacro (add_unique_test)


foreach( TEST_NAME ${TEST_NAMES})
   add_executable( ${TEST_NAME} ${EXTRAS_SOURCES} ${TEST_NAME}.c )
   target_link_libraries( ${TEST_NAME} pcg_random_lib )
   add_compare_output_test( ${TEST_NAME} ${EXPECTED_DIR} )
endforeach( TEST_NAME )

foreach( TEST_NAME ${TEST_UNIQUE_NAMES})
   add_executable( ${TEST_NAME} ${EXTRAS_SOURCES} ${TEST_NAME}.c )
   target_link_libraries( ${TEST_NAME} pcg_random_lib )
   add_unique_test( ${TEST_NAME} ${EXPECTED_DIR} )
endforeach( TEST_NAME )
