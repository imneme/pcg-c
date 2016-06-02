set(EXPECTED_DIR ${CMAKE_CURRENT_SOURCE_DIR}/expected)


set(TEST_NAMES
check-pcg128i
check-pcg128si
check-pcg16i
check-pcg16si
check-pcg32-global
check-pcg32
check-pcg32f
check-pcg32i
check-pcg32s
check-pcg32si
check-pcg32u
check-pcg64-global
check-pcg64
check-pcg64f
check-pcg64i
check-pcg64s
check-pcg64si
check-pcg64u
check-pcg8i
check-pcg8si
)

foreach( TEST_NAME ${TEST_NAMES})
   add_executable( ${TEST_NAME} ${EXTRAS_SOURCES} ${TEST_NAME}.c )
   target_link_libraries( ${TEST_NAME} pcg_random_lib )
   add_compare_output_test( ${TEST_NAME} ${EXPECTED_DIR} )
endforeach( TEST_NAME )
