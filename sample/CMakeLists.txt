set(DEMO_NAMES
pcg32-demo
pcg32-global-demo
pcg32x2-demo
)

if(PCG_HAS_128BIT_OPS)
    set(DEMO_NAMES ${DEMO_NAMES}
        pcg64-demo
    )
endif(PCG_HAS_128BIT_OPS)

foreach( DEMO_NAME ${DEMO_NAMES})
   add_executable( ${DEMO_NAME} ${EXTRAS_SOURCES} ${DEMO_NAME}.c )
   target_link_libraries( ${DEMO_NAME} pcg_random_lib )
endforeach( DEMO_NAME )
