cmake_minimum_required(VERSION 4.2)
project(C_Labs C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(MathApp MathCalculations.c my_lib.c)

add_executable(StringApp Strings.c my_lib.c)
