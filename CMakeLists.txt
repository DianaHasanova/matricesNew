cmake_minimum_required(VERSION 3.20)
project(matricesNew C)

set(CMAKE_C_STANDARD 11)

add_executable(matricesNew main.c libs/data_structures/matrix/matrix.c libs/data_structures/matrix/matrix.h)

add_subdirectory(libs)

target_link_libraries(matricesNew data_structures)