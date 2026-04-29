cmake_minimum_required(VERSION 3.20)
project(BracketWalk_PC2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")
set(CMAKE_CXX_FLAGS_DEBUG   "-O0 -g")

add_library(bw_lib src/bracket_walk.cpp)
target_include_directories(bw_lib PUBLIC include)

add_executable(bracket_walk src/main.cpp)
target_link_libraries(bracket_walk PRIVATE bw_lib)



enable_testing()
add_executable(tests tests/test_bracket_walk.cpp)
target_link_libraries(tests PRIVATE bw_lib)
add_test(NAME tests COMMAND tests)




