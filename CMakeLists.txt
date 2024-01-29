cmake_minimum_required(VERSION 3.26)
project(BaseGrammar C)

set(CMAKE_C_STANDARD 11)

add_executable(BaseGrammar
        动态数组/DynamicArray.h
        动态数组/DynamicArray.c
        队列的数据结构/Queue.h
        队列的数据结构/SeqQueue.c
        队列的数据结构/SeqQueueMain.c
        队列的数据结构/LinkQueue.c
        队列的数据结构/LinkQueueMain.c
)
