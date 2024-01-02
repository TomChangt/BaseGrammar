cmake_minimum_required(VERSION 3.26)
project(BaseGrammar C)

set(CMAKE_C_STANDARD 11)

add_executable(BaseGrammar BaseGrammar.c
        TypingGame.c
        TypingGame.h
        FileCopy.c
        Calculate.c
        WordTranslator.c)
