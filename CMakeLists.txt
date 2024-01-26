cmake_minimum_required(VERSION 3.26)
project(BaseGrammar C)

set(CMAKE_C_STANDARD 11)

add_executable(BaseGrammar
        栈的数据结构/Stack.h
        栈的数据结构/LinkStack.c
        栈的数据结构/LinkStackMain.c
)
