cmake_policy(SET CMP0007 NEW)

get_filename_component(test_name ${test_program} NAME_WE)
execute_process(
	COMMAND ${test_program}
	OUTPUT_FILE ${test_name}.out)
file(STRINGS ${test_name}.out actual_lines)
file(STRINGS ${expected_dir}/${test_name}.out expected_lines)
list(LENGTH actual_lines num_actual_lines)
list(LENGTH expected_lines num_expected_lines)
if(num_actual_lines LESS num_expected_lines)
	set(num_lines ${num_actual_lines})
else()
	set(num_lines ${num_expected_lines})
endif()
math(EXPR num_lines "${num_lines} - 1")
foreach(index RANGE ${num_lines})
	list(GET actual_lines "${index}" actual_line)
	list(GET expected_lines "${index}" expected_line)
	if(NOT actual_line STREQUAL expected_line)
		message(FATAL_ERROR
			      "Actual: ${actual_line}\n"
						"Expected: ${expected_line}")
	endif()
endforeach()

if(NOT num_actual_lines EQUAL num_expected_lines)
	message(FATAL_ERROR "Number of lines are not the same\n"
		"Actual: ${num_actual_lines}\n"
		"Expected: ${num_expected_lines}")
endif()
