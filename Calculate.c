//
// Created by Tom on 2023/12/27.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define FILEPATH "calculate.txt"

FILE *operationFile(char *mode) {
    FILE *fileData = fopen(FILEPATH, mode);
    if (fileData == NULL) {
        perror("open source file error: ");
        exit(EXIT_FAILURE);
    }
    return fileData;
}

void initData() {
    srand((unsigned int) time(NULL)); // 初始化随机数生成器

    FILE *fileData = operationFile("w+");

    if (fileData == NULL) {
        perror("open file error: ");
        exit(EXIT_FAILURE);
    }



}


int main() {

    printf("hello world");

    return 0;
}