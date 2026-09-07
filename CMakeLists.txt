cmake_minimum_required(VERSION 4.2)
project(C_Labs C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(C_Labs
        MathCalculations.c)
