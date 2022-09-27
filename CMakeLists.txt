cmake_minimum_required(VERSION 3.16)
project(project_ballistics)
set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)

enable_testing()
add_subdirectory(Tests)
