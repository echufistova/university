cmake_minimum_required(VERSION 3.12)
project(os2 C)

set(CMAKE_C_STANDARD 99)

add_executable(os2 main.c get_CPU_time.c)