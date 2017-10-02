file (GLOB_RECURSE SRCS "*.cpp")
set (SRC ${SRCS} PARENT_SCOPE)

if (MSVC)
  add_compile_options(/W4)
else()
  add_compile_options (-Wall -Wextra -Wpedantic)
endif()
add_executable(${PROJECT_NAME} ${SRCS} ${INC})
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

if(ENABLE_COVERAGE)
	target_link_libraries(${PROJECT_NAME} --coverage)
endif()

