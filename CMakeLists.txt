cmake_minimum_required(VERSION 3.1)

set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/cmake/toolchain.cmake"
    CACHE FILEPATH
    "Toolchain to use for building this package and dependencies")

project(pcg VERSION 1.0.0)

include(CTest)

add_library(pcg_random
  "include/pcg_variants.h"
  "src/pcg-advance-128.c"
  "src/pcg-advance-16.c"
  "src/pcg-advance-32.c"
  "src/pcg-advance-64.c"
  "src/pcg-advance-8.c"
  "src/pcg-global-32.c"
  "src/pcg-global-64.c"
  "src/pcg-output-128.c"
  "src/pcg-output-16.c"
  "src/pcg-output-32.c"
  "src/pcg-output-64.c"
  "src/pcg-output-8.c"
  "src/pcg-rngs-128.c"
  "src/pcg-rngs-16.c"
  "src/pcg-rngs-32.c"
  "src/pcg-rngs-64.c"
  "src/pcg-rngs-8.c")
target_include_directories(pcg_random PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

if(BUILD_TESTING)
  add_library(extras
    "extras/entropy.c"
    "extras/entropy.h"
    "extras/pcg_spinlock.h")
  target_include_directories(extras PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/extras>)
  target_link_libraries(extras PUBLIC pcg_random)

  set(test_high_src
      "test-high/check-pcg64f.c"
      "test-high/check-pcg16i.c"
      "test-high/check-pcg64-global.c"
      "test-high/check-pcg128i.c"
      "test-high/check-pcg64i.c"
      "test-high/check-pcg64si.c"
      "test-high/check-pcg32i.c"
      "test-high/check-pcg32s.c"
      "test-high/check-pcg128si.c"
      "test-high/check-pcg8i.c"
      "test-high/check-pcg32-global.c"
      "test-high/check-pcg64.c"
      "test-high/check-pcg32.c"
      "test-high/check-pcg32f.c"
      "test-high/check-pcg8si.c"
      "test-high/check-pcg16si.c"
      "test-high/check-pcg64u.c"
      "test-high/check-pcg32u.c"
      "test-high/check-pcg32si.c"
      "test-high/check-pcg64s.c")
  foreach(test_case ${test_high_src})
    get_filename_component(test_name ${test_case} NAME_WE)
    add_executable(${test_name} ${test_case})
    target_link_libraries(${test_name} PUBLIC extras)
    if(test_name MATCHES "check-pcg(32|64)u")
      add_test(NAME ${test_name} COMMAND ${test_name})
    else()
      add_test(
        NAME ${test_name}
        COMMAND ${CMAKE_COMMAND}
        -Dtest_program=$<TARGET_FILE:${test_name}>
        -Dexpected_dir=${CMAKE_CURRENT_SOURCE_DIR}/test-high/expected
        -P ${CMAKE_CURRENT_SOURCE_DIR}/cmake/RunTest.cmake)
    endif()
  endforeach()

  set(test_low_src
      "test-low/check-mcg-128-xsh-rr-64.c"
      "test-low/check-mcg-128-xsh-rs-64.c"
      "test-low/check-mcg-128-xsl-rr-64.c"
      "test-low/check-mcg-16-xsh-rr-8.c"
      "test-low/check-mcg-16-xsh-rs-8.c"
      "test-low/check-mcg-32-xsh-rr-16.c"
      "test-low/check-mcg-32-xsh-rs-16.c"
      "test-low/check-mcg-64-xsh-rr-32.c"
      "test-low/check-mcg-64-xsh-rs-32.c"
      "test-low/check-mcg-64-xsl-rr-32.c"
      "test-low/check-oneseq-128-rxs-m-xs-128.c"
      "test-low/check-oneseq-128-xsh-rr-64.c"
      "test-low/check-oneseq-128-xsh-rs-64.c"
      "test-low/check-oneseq-128-xsl-rr-64.c"
      "test-low/check-oneseq-128-xsl-rr-rr-128.c"
      "test-low/check-oneseq-16-rxs-m-xs-16.c"
      "test-low/check-oneseq-16-xsh-rr-8.c"
      "test-low/check-oneseq-16-xsh-rs-8.c"
      "test-low/check-oneseq-32-rxs-m-xs-32.c"
      "test-low/check-oneseq-32-xsh-rr-16.c"
      "test-low/check-oneseq-32-xsh-rs-16.c"
      "test-low/check-oneseq-64-rxs-m-xs-64.c"
      "test-low/check-oneseq-64-xsh-rr-32.c"
      "test-low/check-oneseq-64-xsh-rs-32.c"
      "test-low/check-oneseq-64-xsl-rr-32.c"
      "test-low/check-oneseq-64-xsl-rr-rr-64.c"
      "test-low/check-oneseq-8-rxs-m-xs-8.c"
      "test-low/check-setseq-128-rxs-m-xs-128.c"
      "test-low/check-setseq-128-xsh-rr-64.c"
      "test-low/check-setseq-128-xsh-rs-64.c"
      "test-low/check-setseq-128-xsl-rr-64.c"
      "test-low/check-setseq-128-xsl-rr-rr-128.c"
      "test-low/check-setseq-16-rxs-m-xs-16.c"
      "test-low/check-setseq-16-xsh-rr-8.c"
      "test-low/check-setseq-16-xsh-rs-8.c"
      "test-low/check-setseq-32-rxs-m-xs-32.c"
      "test-low/check-setseq-32-xsh-rr-16.c"
      "test-low/check-setseq-32-xsh-rs-16.c"
      "test-low/check-setseq-64-rxs-m-xs-64.c"
      "test-low/check-setseq-64-xsh-rr-32.c"
      "test-low/check-setseq-64-xsh-rs-32.c"
      "test-low/check-setseq-64-xsl-rr-32.c"
      "test-low/check-setseq-64-xsl-rr-rr-64.c"
      "test-low/check-setseq-8-rxs-m-xs-8.c"
      "test-low/check-unique-128-rxs-m-xs-128.c"
      "test-low/check-unique-128-xsh-rr-64.c"
      "test-low/check-unique-128-xsh-rs-64.c"
      "test-low/check-unique-128-xsl-rr-64.c"
      "test-low/check-unique-128-xsl-rr-rr-128.c"
      "test-low/check-unique-16-rxs-m-xs-16.c"
      "test-low/check-unique-16-xsh-rr-8.c"
      "test-low/check-unique-16-xsh-rs-8.c"
      "test-low/check-unique-32-rxs-m-xs-32.c"
      "test-low/check-unique-32-xsh-rr-16.c"
      "test-low/check-unique-32-xsh-rs-16.c"
      "test-low/check-unique-64-rxs-m-xs-64.c"
      "test-low/check-unique-64-xsh-rr-32.c"
      "test-low/check-unique-64-xsh-rs-32.c"
      "test-low/check-unique-64-xsl-rr-32.c"
      "test-low/check-unique-64-xsl-rr-rr-64.c")
  foreach(test_case ${test_low_src})
    get_filename_component(test_name ${test_case} NAME_WE)
    add_executable(${test_name} ${test_case})
    target_link_libraries(${test_name} PUBLIC extras)
    if(test_name MATCHES "check-unique")
      add_test(NAME ${test_name} COMMAND ${test_name})
    else()
      add_test(
        NAME ${test_name}
        COMMAND ${CMAKE_COMMAND}
        -Dtest_program=$<TARGET_FILE:${test_name}>
        -Dexpected_dir=${CMAKE_CURRENT_SOURCE_DIR}/test-low/expected
        -P ${CMAKE_CURRENT_SOURCE_DIR}/cmake/RunTest.cmake)
    endif()
  endforeach()
endif()

# Installation (https://github.com/forexample/package-example)

# Layout. This works for all platforms:
#   * <prefix>/lib/cmake/<PROJECT-NAME>
#   * <prefix>/lib/
#   * <prefix>/include/
set(config_install_dir "lib/cmake/${PROJECT_NAME}")
set(include_install_dir "include")

set(generated_dir "${CMAKE_CURRENT_BINARY_DIR}/generated")

# Configuration
set(version_config "${generated_dir}/${PROJECT_NAME}ConfigVersion.cmake")
set(project_config "${generated_dir}/${PROJECT_NAME}Config.cmake")
set(TARGETS_EXPORT_NAME "${PROJECT_NAME}Targets")
set(namespace "${PROJECT_NAME}::")

# Include module with fuction 'write_basic_package_version_file'
include(CMakePackageConfigHelpers)

# Configure '<PROJECT-NAME>ConfigVersion.cmake'
# Use:
#   * PROJECT_VERSION
write_basic_package_version_file(
    "${version_config}" COMPATIBILITY SameMajorVersion
)

# Configure '<PROJECT-NAME>Config.cmake'
# Use variables:
#   * TARGETS_EXPORT_NAME
#   * PROJECT_NAME
configure_package_config_file(
    "cmake/Config.cmake.in"
    "${project_config}"
    INSTALL_DESTINATION "${config_install_dir}"
)

# Targets:
#   * <prefix>/lib/libpcg_random.a
#   * header location after install: <prefix>/include/pcg_variants.h
#   * headers can be included by C++ code `#include <pcg_variants.h>`
install(
    TARGETS pcg_random
    EXPORT "${TARGETS_EXPORT_NAME}"
    LIBRARY DESTINATION "lib"
    ARCHIVE DESTINATION "lib"
    RUNTIME DESTINATION "bin"
    INCLUDES DESTINATION "${include_install_dir}"
)

# Headers:
#   * pcg_variants.h -> <prefix>/include/pcg_variants.h
install(
    FILES "${CMAKE_CURRENT_SOURCE_DIR}/pcg_variants.h"
    DESTINATION "${include_install_dir}"
)

# Config
#   * <prefix>/lib/cmake/pcg/pcgConfig.cmake
#   * <prefix>/lib/cmake/pcg/pcgConfigVersion.cmake
install(
    FILES "${project_config}" "${version_config}"
    DESTINATION "${config_install_dir}"
)

# Config
#   * <prefix>/lib/cmake/pcg/pcgTargets.cmake
install(
    EXPORT "${TARGETS_EXPORT_NAME}"
    NAMESPACE "${namespace}"
    DESTINATION "${config_install_dir}"
)
