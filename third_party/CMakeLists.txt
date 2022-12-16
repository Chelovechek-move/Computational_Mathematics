cmake_minimum_required(VERSION 3.16)
project(project_ballistics)
set(CMAKE_CXX_STANDARD 17)

add_library(Eigen INTERFACE)
target_include_directories(Eigen INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})