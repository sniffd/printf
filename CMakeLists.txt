cmake_minimum_required(VERSION 3.13)
project(printf C)

set(CMAKE_C_STANDARD 99)

add_executable(printf main.c ft_printf.c)