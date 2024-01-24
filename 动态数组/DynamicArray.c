//
// Created by Tom on 2024/1/24.
//
#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
#include "DynamicArray.h"

//初始化数组
struct DynamicArray *initDynamicArray(int capacity) {

    if (capacity <= 0) {
        return NULL;
    }

    struct DynamicArray *arr = malloc(sizeof(struct DynamicArray));
    arr->dArrayAdr = malloc(sizeof(void *) * capacity);
    arr->dCapacity = capacity;
    arr->dSize = 0;
    return arr;
}

//插入元素
void insertDynamicArray(struct DynamicArray *arr, void *data, int pos) {
    if (arr == NULL) {
        return;
    }
    if (pos < 0 || pos > arr->dSize) {
        //尾插
        pos = arr->dSize;
    }

    if (arr->dSize == arr->dCapacity) {
        //申请更大容量
        int newCapacity = arr->dCapacity * 2;
        //重新开辟空间
        void **newSpace = malloc(sizeof(void *) * newCapacity);
        //将原空间拷贝
        memcpy(newSpace, arr->dArrayAdr, sizeof(void *) * arr->dCapacity);
        //释放原来空间
        free(arr->dArrayAdr);
        arr->dArrayAdr = newSpace;
        arr->dCapacity = newCapacity;
    }
    for (int i = arr->dSize - 1; i >= pos; --i) {
        //移动元素
        arr->dArrayAdr[i + 1] = arr->dArrayAdr[i];
    }
    arr->dArrayAdr[pos] = data;
    arr->dSize++;


}

//循环遍历动态数组
void foreachDynamicArray(struct DynamicArray *arr, void(*printData)(void *)) {
    if (arr == NULL) {
        return;
    }
    printf("---------- 开始进行动态数组遍历 -------------- \n");
    for (int i = 0; i < arr->dSize; ++i) {
        printData(arr->dArrayAdr[i]);
    }
}

//按位置删除数组中元素
void delDynamicArrayByPos(struct DynamicArray *arr, int pos) {
    if (arr == NULL) {
        return;
    }
    if (pos < 0 || pos > arr->dSize - 1) {
        return;
    }
    for (int i = pos; i < arr->dSize - 1; ++i) {
        arr->dArrayAdr[i] = arr->dArrayAdr[i + 1];
    }
    arr->dSize--;
}

//按值删除数组中元素
void delDynamicArrayByValue(struct DynamicArray *arr,void *data, int(*compareFun)(void *, void *)) {
    if (arr == NULL) {
        return;
    }
    for (int i = 0; i < arr->dSize; ++i) {
        if(compareFun(arr->dArrayAdr[i],data) == 0){
            delDynamicArrayByPos(arr,i);
            break;
        }
    }
}

//销毁数组
void destroyDynamicArray(struct DynamicArray *arr) {
    if (arr == NULL) {
        return;
    }

    if(arr->dArrayAdr != NULL){
        free(arr->dArrayAdr);
        arr->dArrayAdr = NULL;
    }

    free(arr);
    arr = NULL;
}