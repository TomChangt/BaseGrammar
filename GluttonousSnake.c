//
// Created by 畅通 on 2024/1/3.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define WIDE 60
#define HIGH 20

void init_ui() {

    for (int i = 0; i < HIGH; ++i) {

        for (int j = 0; j < WIDE; ++j) {
            printf("#");
        }
        printf("\n");
    }

}

typedef struct SnakeBody {
    int x; //x轴
    int y; //y轴
} BODY;

typedef struct Snake {
    BODY body[WIDE * HIGH];
    int size;
} SNAKE;

int main() {

    init_ui();

    return 0;
}