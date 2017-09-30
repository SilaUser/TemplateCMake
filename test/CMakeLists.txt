cmake_minimum_required(VERSION 3.2)
find_package(GTest)
find_package(Threads REQUIRED)

if(NOT GTEST_FOUND)
  message(FATAL_ERROR "Google Test was not found!")
else()
  message("-- Starting tests!")
endif()

include_directories(${GTEST_INCLUDE_DIRS})

set(GMOCK_LIBRARIES "gmock")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -W -Wshadow -Wunused-variable -Wunused-parameter -Wunused-function -Wunused -Wno-system-headers -Wno-deprecated -Woverloaded-virtual") # various warning flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0") # debug, no optimisation
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage") # enabling coverage

file (GLOB_RECURSE SRC_TESTS "*.cpp")

# Because of global globbing, the program main routine has to be removed from the tests objects
set(PROGRAM_SRC ${SRC})
get_filename_component(full_path_main ${CMAKE_SOURCE_DIR}/src/main.cpp ABSOLUTE)
list(REMOVE_ITEM PROGRAM_SRC "${full_path_main}")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(tests ${SRC_TESTS} ${PROGRAM_SRC})

target_link_libraries(tests ${GTEST_BOTH_LIBRARIES})
target_link_libraries(tests ${GMOCK_LIBRARIES})
target_link_libraries(tests ${CMAKE_THREAD_LIBS_INIT})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../inc/)
target_link_libraries(tests --coverage)
add_test(AllTests tests)

