cmake_minimum_required (VERSION 3.2)

project (TestCMake)

file (GLOB_RECURSE SRC "src/*.cpp")
file (GLOB_RECURSE INC "inc/*.h")
include_directories ("inc")

if (MSVC)
  add_compile_options(/W4)
else()
  include(CTest)
  enable_testing()
  set(CMAKE_CXX_COMPILER "g++")
  add_compile_options (-Wall -Wextra -Wpedantic)
  add_subdirectory(test)
endif()

if (CMAKE_COMPILER_IS_GNUCC)
  option(ENABLE_COVERAGE "Enable coverage reporting for gcc/clang" FALSE)

  if (ENABLE_COVERAGE)
    add_compile_options(--coverage -O0)
  endif()
endif()

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} ${SRC})
target_link_libraries(${PROJECT_NAME} --coverage)

