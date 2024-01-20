cmake_minimum_required(VERSION 3.26)
project(BaseGrammar C)

set(CMAKE_C_STANDARD 11)

add_executable(BaseGrammar BaseGrammar.c
        TypingGame.c
        TypingGame.h
        FileCopy.c
        Calculate.c
        WordTranslator.c
        Selectsort.c
        TwoLevelPointer.c
        配置文件读写/Config.h
        配置文件读写/Config.c
        配置文件读写/ParsConfig.c
        链表/LinkList.h
        链表/LinkList.c
        链表/OpLinkList.c
)
