cmake_minimum_required(VERSION 3.26)
project(BaseGrammar C)

set(CMAKE_C_STANDARD 11)

add_executable(BaseGrammar BaseGrammar.c
        动态数组/DynamicArray.c
        动态数组/DynamicArray.h
        动态数组/DynamicArrayMain.c
)
