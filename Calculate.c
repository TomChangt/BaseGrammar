//
// Created by Tom on 2023/12/27.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define FILEPATH "Calculate.txt"
#define MAXCOUNT 100
#define RANDNUM 10000

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

    int line = rand() % MAXCOUNT + 1;

    char buffer[128] = "";
    for (int i = 0; i < line; ++i) {
        char operator = '+';
        int a = rand() % RANDNUM + 1;
        int b = rand() % RANDNUM + 1;
        int c = rand() % 4;
        switch (c) {
            case 1:
                operator = '-';
                break;
            case 2:
                operator = '*';
                break;
            case 3:
                operator = '/';
                break;
        }
        sprintf(buffer,"%d %c %d =\n",a,operator,b);
        fputs(buffer, fileData);
    }
    fclose(fileData);

}


int main() {

    initData();

    return 0;
}