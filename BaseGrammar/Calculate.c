//
// Created by Tom on 2023/12/27.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define FILE_PATH "Calculate.txt"
#define MAX_LINE 20
#define RAND_NUM 1000

FILE *operation_file(char *mode) {
    FILE *fileData = fopen(FILE_PATH, mode);
    if (fileData == NULL) {
        perror("open source file error: ");
        exit(EXIT_FAILURE);
    }
    return fileData;
}

float calculateResult(float a, float b, char c) {
    float rs;
    switch (c) {
        case '+':
            rs = a + b;
            break;
        case '-':
            rs = a - b;
            break;
        case '*':
            rs = a * b;
            break;
        default:
            rs = a / b;
            break;
    }
    return rs;
}


void initData() {
    srand((unsigned int) time(NULL)); // 初始化随机数生成器
    FILE *fileData = operation_file("w");
    if (fileData == NULL) {
        perror("open file error: ");
        exit(EXIT_FAILURE);
    }

    char buffer[128] = "";
    for (int i = 0; i < MAX_LINE; ++i) {
        char operator = '+';
        int a = rand() % RAND_NUM + 1;
        int b = rand() % RAND_NUM + 1;
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
        sprintf(buffer, "%d %c %d =\n", a, operator, b);
        fputs(buffer, fileData);
    }
    fclose(fileData);
}

void calculateData() {
    //解析文件取出数据
    FILE *fileData = operation_file("r");
    if (fileData == NULL) {
        perror("open file error: ");
        exit(EXIT_FAILURE);
    }
    char buffer[128];
    int i = 0;
    char data[MAX_LINE][128] = {0};
    while (fgets(buffer, sizeof(buffer), fileData) != NULL) {
        float a = 0;
        float b = 0;
        char c = 0;
        sscanf(buffer, "%f %c %f =\n", &a, &c, &b);
        //计算数据
        float rs = calculateResult(a, b, c);
        sprintf(data[i++], "%.0f %c %.0f = %.2f\n", a, c, b, rs);
    }

    fclose(fileData);
    FILE *writeFile = operation_file("w");
    for (int j = 0; j < MAX_LINE; ++j) {
        //保存进文件
        fputs(data[j], writeFile);
    }
    fclose(writeFile);
}


int main() {

    initData();

    calculateData();

    return 0;
}