# RNGs at different sizes

src_pcg_rngs_8_file			=	files('pcg-rngs-8.c')
src_pcg_rngs_16_file		=	files('pcg-rngs-16.c')
src_pcg_rngs_32_file		=	files('pcg-rngs-32.c')
src_pcg_rngs_64_file		=	files('pcg-rngs-64.c')
src_pcg_rngs_128_file		=	files('pcg-rngs-128.c')

# Jump-ahead functions at different sizes

src_pcg_advance_8_file		=	files('pcg-advance-8.c')
src_pcg_advance_16_file		=	files('pcg-advance-16.c')
src_pcg_advance_32_file		=	files('pcg-advance-32.c')
src_pcg_advance_64_file		=	files('pcg-advance-64.c')
src_pcg_advance_128_file	=	files('pcg-advance-128.c')

# Output functions at different sizes (usually inlined)

src_pcg_output_8_file		=	files('pcg-output-8.c')
src_pcg_output_16_file		=	files('pcg-output-16.c')
src_pcg_output_32_file		=	files('pcg-output-32.c')
src_pcg_output_64_file		=	files('pcg-output-64.c')
src_pcg_output_128_file		=	files('pcg-output-128.c')

# Global RNGs

src_pcg_global_32_file		=	files('pcg-global-32.c')
src_pcg_global_64_file		=	files('pcg-global-64.c')


src_pcg_global_32_file		=	files('pcg-global-32.c')
src_pcg_global_64_file		=	files('pcg-global-64.c')

src_pcg_random_files		=	[src_pcg_rngs_8_file, src_pcg_rngs_16_file
						  		, src_pcg_rngs_32_file, src_pcg_rngs_64_file
						  		, src_pcg_rngs_128_file
						  		, src_pcg_advance_8_file, src_pcg_advance_16_file
						  		, src_pcg_advance_32_file, src_pcg_advance_64_file
						  		, src_pcg_advance_128_file
						  		, src_pcg_output_8_file, src_pcg_output_16_file
						  		, src_pcg_output_32_file, src_pcg_output_64_file
						  		, src_pcg_output_128_file
						  		, src_pcg_global_32_file, src_pcg_global_64_file]

src_pcg_random_alib	= static_library('pcg_random', src_pcg_random_files
								, include_directories : include_include
								, install : true)
