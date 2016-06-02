set( PUBLIC_HEADERS ../include/pcg_variants.h
   ) 
set(HEADERS
   )
set( SOURCES 
   pcg-advance-8.c pcg-advance-16.c pcg-advance-32.c pcg-advance-64.c
   pcg-advance-128.c pcg-output-8.c pcg-output-16.c pcg-output-32.c
   pcg-output-64.c pcg-output-128.c pcg-rngs-8.c pcg-rngs-16.c
   pcg-rngs-32.c pcg-rngs-64.c pcg-rngs-128.c
   pcg-global-32.c pcg-global-64.c 
   )

source_group( "api" FILES ${PUBLIC_HEADERS} ) 

if(MSVC)
# warning C4146: unary minus operator applied to unsigned type, result still unsigned
# warning C4244: 'function': conversion from 'uint64_t' to 'uint32_t', possible loss of data
# TODO remove 4244, not acceptable in 64 bits code!
# TODO pragma to silent 4146 as it is in header)
  add_definitions( /wd4146 /wd4244 )
endif(MSVC)

add_library( pcg_random_lib ${SOURCES} ${HEADERS} ${PUBLIC_HEADERS} )

set_target_properties(pcg_random_lib PROPERTIES OUTPUT_NAME pcg_random )

