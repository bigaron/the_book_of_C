cmake_minimum_required(VERSION 3.10)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(ENV{CMAKE_GENERATOR} Ninja)

project(Book C)

add_executable(Book task2_8.c)