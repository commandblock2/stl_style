cmake_minimum_required(VERSION 3.0)

set(PROJECT_NAME_STR "stl_style")
project(stl_style LANGUAGES C)

add_subdirectory(src/)

enable_testing()
add_subdirectory(test/)
