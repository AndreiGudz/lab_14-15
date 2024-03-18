cmake_minimum_required(VERSION 3.25)
project(Pr14 C)

set(CMAKE_C_STANDARD 11)

add_executable(Pr14 main.c StudentStruct.h StudentStruct.c CreateLoadStudents.c CreateLoadStudents.h ListStruct.c ListStruct.h)
