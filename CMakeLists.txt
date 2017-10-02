cmake_minimum_required (VERSION 3.2)

project (TestCMake)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories ("inc")

add_subdirectory(inc)
add_subdirectory(lib)
add_subdirectory(src)

if (MSVC)
	message("Testing currently disabled for MSVC!")
else()
  include(CTest)
  enable_testing()
  add_subdirectory(test)
endif()

if (CMAKE_COMPILER_IS_GNUCC)
  option(ENABLE_COVERAGE "Enable coverage reporting for gcc/clang" FALSE)

  if (ENABLE_COVERAGE)
    add_compile_options(--coverage -O0)
  endif()
endif()

