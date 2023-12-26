//
// Created by Tom on 2023/12/20.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "TypingGame.h"

#define MAX_WORD_LENGTH 20

/**
 * 游戏说明菜单
 */
void printHelp() {
    printf("\n*****************************************");
    printf("\n* 按任意键开始测试,按下首字母时则开始计时! *");
    printf("\n**************************************\n");
}

char *generateRandomWord() {
    // 示例单词列表
    const char *wordList[] = {"apple", "banana", "orange", "grape", "strawberry", "watermelon", "pineapple", "kiwi",
                              "blueberry", "cherry"};

    // 计算单词列表长度
    int wordCount = sizeof(wordList) / sizeof(wordList[0]);

    // 生成随机索引
    int randomIndex = rand() % wordCount;

    // 复制并返回随机单词
    return strdup(wordList[randomIndex]);
}


int main() {
    srand((unsigned int) time(NULL)); // 初始化随机数生成器

    printHelp();

    int score = 0;
    clock_t startTime, endTime;
    double totalTime;

    while (1) {
        // 生成随机单词
        char *targetWord = generateRandomWord();
        printf("Type this word: %s\n", targetWord);

        // 记录开始时间
        startTime = clock();

        // 获取用户输入
        char userInput[MAX_WORD_LENGTH];
        scanf("%s", userInput);

        // 记录结束时间
        endTime = clock();

        // 计算时间和得分
        totalTime = ((double) (endTime - startTime)) / CLOCKS_PER_SEC;
        if (strcmp(userInput, targetWord) == 0) {
            printf("Correct! Time: %.2fs\n", totalTime);
            score++;
        } else {
            printf("Incorrect. Game Over! Your Score: %d\n", score);
            free(targetWord);
            break;
        }

        // 释放动态分配的内存
        free(targetWord);
    }

    return 0;
}
