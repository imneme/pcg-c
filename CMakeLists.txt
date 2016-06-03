cmake_minimum_required(VERSION 2.8)

PROJECT(PCG_c)

enable_testing()

include(CheckCSourceCompiles) 

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

macro(use_c99)
  if (CMAKE_VERSION VERSION_LESS "3.1")
    if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
      set (CMAKE_C_FLAGS "--std=c99 ${CMAKE_C_FLAGS}")
    endif ()
  else ()
    set (CMAKE_C_STANDARD 99)
  endif ()
endmacro(use_c99)

use_c99()

# Notes: could use ${CMAKE_COMMAND} -E compare_files for file comparison, but it does not provide diff on failure :/
set(DIFF_CMD fc.exe)

macro (add_compare_output_test target expected_dir)
   set(ACTUAL_PATH ${target}-actual.txt)
   set(EXPECTED_PATH ${expected_dir}/${target}.out)
   add_test( NAME ${target} COMMAND $<TARGET_FILE:${target}> --redirect-output ${ACTUAL_PATH} )
   add_test( NAME ${target}-compare COMMAND ${DIFF_CMD} ${ACTUAL_PATH} ${EXPECTED_PATH} )
   set_tests_properties( ${target}-compare PROPERTIES DEPENDS ${target})
endmacro (add_compare_output_test)

# Detect if compiler support non-standard __uint128_t type
CHECK_C_SOURCE_COMPILES(
"
#include <pcg_variants.h>
int main(void) {
#ifdef PCG_HAS_128BIT_OPS
return 0;
#else
pgc_128bit_not_supported; /* cause syntax error */
#endif
}
" 
PCG_HAS_128BIT_OPS) 

message(STATUS "PCG_HAS_128BIT_OPS=${PCG_HAS_128BIT_OPS}")

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
