include_directories( ../extras )

set( EXTRAS_DIR ../extras )
set( EXTRAS_SOURCES 
     ${EXTRAS_DIR}/entropy.c
     ${EXTRAS_DIR}/entropy.h
     ${EXTRAS_DIR}/pcg_spinlock.h )

if(MSVC)
# warning C4146: unary minus operator applied to unsigned type, result still unsigned
# warning C4244: 'function': conversion from 'uint64_t' to 'uint32_t', possible loss of data
# TODO remove 4244, not acceptable in 64 bits code!
# TODO pragma to silent 4146 as it is in header)
  add_definitions( /wd4146 /wd4244 )
  add_definitions( -D_CRT_SECURE_NO_WARNINGS )
endif(MSVC)

#add_executable( check-mcg-16-xsh-rr-8 ${EXTRAS_SOURCES}  check-mcg-16-xsh-rr-8.c )
#target_link_libraries( check-mcg-16-xsh-rr-8 pcg_random_lib )

set(EXPECTED_DIR ${CMAKE_CURRENT_SOURCE_DIR}/expected)

macro (add_compare_output_test target expected_dir)
   set(DIFF_CMD fc.exe)
   set(ACTUAL_PATH ${target}-actual.txt)
   set(EXPECTED_PATH ${expected_dir}/${target}.out)
#  add_test (NAME ${target} COMMAND $<TARGET_FILE:${target}>)
   add_test( NAME ${target} COMMAND $<TARGET_FILE:${target}> --redirect-output ${ACTUAL_PATH} )
#add_test( NAME check-mcg-16-xsh-rr-8-output COMMAND ${CMAKE_COMMAND} -E compare_files output.txt ${EXPECTED_DIR}/check-mcg-16-xsh-rr-8.out )
   add_test( NAME ${target}-compare COMMAND ${DIFF_CMD} ${ACTUAL_PATH} ${EXPECTED_PATH} )
   set_tests_properties( ${target}-compare PROPERTIES DEPENDS ${target})
endmacro (add_compare_output_test)


set(TEST_NAMES
check-mcg-128-xsh-rr-64
check-mcg-128-xsh-rs-64
check-mcg-128-xsl-rr-64
check-mcg-16-xsh-rr-8
check-mcg-16-xsh-rs-8
check-mcg-32-xsh-rr-16
check-mcg-32-xsh-rs-16
check-mcg-64-xsh-rr-32
check-mcg-64-xsh-rs-32
check-mcg-64-xsl-rr-32
check-oneseq-128-rxs-m-xs-128
check-oneseq-128-xsh-rr-64
check-oneseq-128-xsh-rs-64
check-oneseq-128-xsl-rr-64
check-oneseq-128-xsl-rr-rr-128
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
check-setseq-128-rxs-m-xs-128
check-setseq-128-xsh-rr-64
check-setseq-128-xsh-rs-64
check-setseq-128-xsl-rr-64
check-setseq-128-xsl-rr-rr-128
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
check-unique-128-rxs-m-xs-128
check-unique-128-xsh-rr-64
check-unique-128-xsh-rs-64
check-unique-128-xsl-rr-64
check-unique-128-xsl-rr-rr-128
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

foreach( TEST_NAME ${TEST_NAMES})
   add_executable( ${TEST_NAME} ${EXTRAS_SOURCES} ${TEST_NAME}.c )
   target_link_libraries( ${TEST_NAME} pcg_random_lib )
    add_compare_output_test( ${TEST_NAME} ${EXPECTED_DIR} )
endforeach( TEST_NAME )

# add_compare_output_test( check-mcg-16-xsh-rr-8 ${EXPECTED_DIR} )

#add_test( NAME check-mcg-16-xsh-rr-8 COMMAND $<TARGET_FILE:check-mcg-16-xsh-rr-8> --redirect-output output.txt )
##add_test( NAME check-mcg-16-xsh-rr-8-output COMMAND ${CMAKE_COMMAND} -E compare_files output.txt ${EXPECTED_DIR}/check-mcg-16-xsh-rr-8.out )
#add_test( NAME check-mcg-16-xsh-rr-8-output COMMAND fc.exe output.txt ${EXPECTED_DIR}/check-mcg-16-xsh-rr-8.out )
#set_tests_properties( check-mcg-16-xsh-rr-8-output PROPERTIES DEPENDS check-mcg-16-xsh-rr-8)
