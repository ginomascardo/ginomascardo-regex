cmake_minimum_required(VERSION 3.0)
project(malloc)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wall -g")

set(SOURCE src/malloc.c src/morecore.c)

add_library(malloc ${SOURCE})
target_include_directories (malloc PUBLIC src)

include_directories(src)

add_library(c_unit test/c_unit.c test/replay.c)
target_include_directories (c_unit PUBLIC test)

include(CTest)

add_executable(test_basic_sanity test/test_basic_sanity.c)
add_executable(test_replay       test/test_replay.c)
target_link_libraries(test_basic_sanity LINK_PUBLIC malloc c_unit)
target_link_libraries(test_replay LINK_PUBLIC malloc c_unit)

enable_testing()

add_test(NAME test_basic_sanity
        COMMAND    valgrind --error-exitcode=1 --tool=memcheck --leak-check=full ./test_basic_sanity)
add_test(NAME test_replay_no_valgrind
        COMMAND    ./test_replay)
add_test(NAME test_replay
        COMMAND    valgrind --error-exitcode=1 --tool=memcheck --leak-check=full ./test_replay)
