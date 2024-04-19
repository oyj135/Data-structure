cmake_minimum_required(VERSION 3.27)
project(Data_structure)

set(CMAKE_CXX_STANDARD 17)

add_executable(Data_structure
        chapter_two/linear_list/Initial_insert.cpp
)

add_executable(operate chapter_two/Single_linked_lists/operate.cpp
        chapter_two/Single_linked_lists/test_2019_41.cpp)
add_executable(reverse other/test/reverse.cpp)
add_executable(ex_10 other/test/ex_10.cpp)
add_executable(type other/prictice/one_day/type.cpp)
add_executable(sturct_test other/prictice/one_day/sturct_test.cpp
        other/prictice/one_day/ex_5.cpp
)
add_executable(ex_12 other/test/ex_12.cpp)
add_executable(ex_7 other/test/ex_7.cpp)
add_executable(pra other/prictice/three_day/pra.cpp)
add_executable(tree chapter_five/tree.cpp)
add_executable(chapter_five chapter_five/tree.cpp chapter_five/tree.h chapter_five/three_queue.cpp)
add_executable(graph chapter_six/graph/graph.cpp)
add_executable(string chapter_four/string.cpp)