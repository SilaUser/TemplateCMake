cmake_minimum_required(VERSION 3.2)
find_package(GTest)
find_package(Threads REQUIRED)

set(TestName "UnitTests")

if(NOT GTEST_FOUND)
  message(FATAL_ERROR "Google Test was not found!")
else()
  message("-- Testing activated!")
endif()

include_directories(${GTEST_INCLUDE_DIRS})

set(GMOCK_LIBRARIES "gmock")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -W -Wshadow -Wunused-variable -Wunused-parameter -Wunused-function -Wunused -Wno-system-headers -Wno-deprecated -Woverloaded-virtual") # various warning flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0") # debug, no optimisation
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage") # enabling coverage

file (GLOB_RECURSE SRC_TESTS "*.cpp")

# Because of global globbing, the program main routine has to be removed from the ${TestName}s objects
set(PROGRAM_SRC ${SRC})
get_filename_component(full_path_main ${CMAKE_SOURCE_DIR}/src/main.cpp ABSOLUTE)

list(REMOVE_ITEM PROGRAM_SRC "${full_path_main}")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${TestName} ${SRC_TESTS} ${PROGRAM_SRC})
set_target_properties(${TestName} PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(${TestName} ${GTEST_BOTH_LIBRARIES})
target_link_libraries(${TestName} ${GMOCK_LIBRARIES})
target_link_libraries(${TestName} ${CMAKE_THREAD_LIBS_INIT})

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../inc/)
target_link_libraries(${TestName} --coverage)
target_link_libraries(${TestName} testmath)
add_test(AllTests ${TestName})

add_custom_target(gtest COMMAND ./${TestName})

