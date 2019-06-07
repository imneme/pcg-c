sample_pcg32_demo_file				  = files('pcg32-demo.c')
sample_pcg32_global_demo_file		  = files('pcg32-global-demo.c')
sample_pcg32x2_demo_file			  = files('pcg32x2-demo.c')
sample_pcg64_demo_file				  = files('pcg64-demo.c')

sample_pcg32_demo_exe				  =	executable('pcg32-demo', [sample_pcg32_demo_exe, extras_entropy_file]
												  , include_directories : [include_include, include_extras]
												  , c_args : '-Wall -pedantic'
												  , link_width : [libpcg_random_a])
sample_pcg32_global_demo_exe		  =	executable('pcg32-global-demo', [sample_pcg32_global_demo_exe, extras_entropy_file])
												  , include_directories : [include_include, include_extras]
												  , c_args : '-Wall -pedantic'
												  , link_width : [libpcg_random_a])
sample_pcg32x2_demo_exe				  =	executable('pcg32x2-demo', [sample_pcg32x2_demo_exe, extras_entropy_file])
												  , include_directories : [include_include, include_extras]
												  , c_args : '-Wall -pedantic'
												  , link_width : [libpcg_random_a])
sample_pcg64_demo_exe				  =	executable('pcg64-demo', [sample_pcg64_demo_exe, extras_entropy_file])
												  , include_directories : [include_include, include_extras]
												  , c_args : '-Wall -pedantic'
												  , link_width : [libpcg_random_a])

