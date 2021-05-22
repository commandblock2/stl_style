cmake_minimum_required(VERSION 3.0)

project(stl_style LANGUAGES C)

add_executable(stl_style main.c)

install(TARGETS stl_style RUNTIME DESTINATION bin)
