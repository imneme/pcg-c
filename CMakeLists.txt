cmake_minimum_required(VERSION 2.8)

PROJECT(PCG_c)

enable_testing()

# Output all libraries and executables in the same directory
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin
    CACHE PATH "Single directory for all libraries.")
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin
    CACHE PATH "Single directory for all executables.")
mark_as_advanced( LIBRARY_OUTPUT_PATH EXECUTABLE_OUTPUT_PATH )

include_directories( include )
include_directories( extras )

set( EXTRAS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/extras )
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


# Notes: could use ${CMAKE_COMMAND} -E compare_files for file comparison, but it does not provide diff on failure :/
set(DIFF_CMD fc.exe)

macro (add_compare_output_test target expected_dir)
   set(ACTUAL_PATH ${target}-actual.txt)
   set(EXPECTED_PATH ${expected_dir}/${target}.out)
   add_test( NAME ${target} COMMAND $<TARGET_FILE:${target}> --redirect-output ${ACTUAL_PATH} )
   add_test( NAME ${target}-compare COMMAND ${DIFF_CMD} ${ACTUAL_PATH} ${EXPECTED_PATH} )
   set_tests_properties( ${target}-compare PROPERTIES DEPENDS ${target})
endmacro (add_compare_output_test)



add_subdirectory( src/ )
add_subdirectory( test-low/ )
add_subdirectory( test-high/ )

# only way to "always" get failure detail by default
if (CMAKE_CONFIGURATION_TYPES)
    add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} 
        --force-new-ctest-process --output-on-failure 
        --build-config "$<CONFIGURATION>")
else()
    add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} 
        --force-new-ctest-process --output-on-failure)
endif()
