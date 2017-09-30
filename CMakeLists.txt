cmake_minimum_required (VERSION 2.6)
project (TestCMake)

set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_definitions (-std=c++14 -Wall -Wextra)

file (GLOB_RECURSE SRC "src/*.cpp")
file (GLOB_RECURSE INC "inc/*.h")

include_directories ("inc")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../bin")

# Only for Vim YouCompleteMe Plugin necessary
add_custom_target(VimYouCompleteMeDB COMMAND cp *.json ..)

# Reformats the source code in ./inc and ./src
add_custom_target(ClangFormat ALL COMMAND clang-format -style=file -i ${SRC} ${INC})

add_executable(${PROJECT_NAME} ${SRC})

