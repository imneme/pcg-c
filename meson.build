project('pcg-c', 'c'
	  , default_options : ['optimization=3', 'b_lto=true'])
add_project_arguments('-Wall', '-Wpedantic', language : 'c')

include_include	= include_directories('include')
include_extras	= include_directories('extras')

subdir('include')
subdir('extras')
subdir('src')
subdir('test-high')
subdir('test-low')
subdir('sample')
