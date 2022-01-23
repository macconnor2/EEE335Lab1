cmake_minimum_required(VERSION 3.21)
project(Lab1 C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Lab1
        "File stuff.c"
        "File stuff.h")
