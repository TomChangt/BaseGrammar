//
// Created by Tom on 2024/1/31.
//


#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
#include <time.h>

enum SortWay {
    Asc = 1, //正序
    Desc //倒叙
};

void printArray(int array[], int size) {
    for (int i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void insertSortData(int array[], int size, enum SortWay sortWay) {
    for (int i = 1; i < size; ++i) {
        int v = array[i];
        int j = i - 1;
        switch (sortWay) {
            case Asc:
                for (; j >=0 && v < array[j] ; --j) {
                    array[j + 1] = array[j];
                }
                if(j + 1 != i){
                    array[j + 1] = v;
                }
                break;
            case Desc:
                for (; j >=0 && v > array[j] ; --j) {
                    array[j + 1] = array[j];
                }
                if(j + 1 != i){
                    array[j + 1] = v;
                }
                break;
        }


    }
}

int main() {
    srand((unsigned int) time(NULL));  // 初始化随机数生成器
    int size = 10;
    int array[size];
    for (int i = 0; i < size; ++i) {
        array[i] = rand() % 100;
    }
    printArray(array, size);
    printf("-----------------------------排序后数据-----------------------------------\n");
    insertSortData(array, size,Desc);
    printArray(array, size);
    return EXIT_SUCCESS;
}