//
// Created by Tom on 2024/1/29.
//


#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
#include "Queue.h"
#include "../动态数组/DynamicArray.c"

#define MAX 1024


//初始化队列
Queue initQueue() {
    return initDynamicArray(MAX);
}

//入队
void pushQueue(Queue queue, void *data) {

    if (queue == NULL) {
        return;
    }
    if (data == NULL) {
        return;
    }
    struct DynamicArray *myQueue = queue;
    if (myQueue->dSize == MAX) {
        return;
    }
    insertDynamicArray(myQueue, data, myQueue->dSize);
}

//出队列
void popQueue(Queue queue) {
    if (queue == NULL) {
        return;
    }
    struct DynamicArray *myQueue = queue;
    if (myQueue->dSize == 0) {
        return;
    }
    delDynamicArrayByPos(myQueue, 0);
}

//返回队列头
void *fontQueue(Queue queue) {
    if (queue == NULL) {
        return NULL;
    }
    struct DynamicArray *myQueue = queue;
    if (myQueue->dSize == 0) {
        return NULL;
    }
    return myQueue->dArrayAdr[0];
}

//返回队尾部
void *backQueue(Queue queue) {
    if (queue == NULL) {
        return NULL;
    }
    struct DynamicArray *myQueue = queue;
    if (myQueue->dSize == 0) {
        return NULL;
    }
    return myQueue->dArrayAdr[myQueue->dSize - 1];
}

//返回队列大小
int sizeQueue(Queue queue) {
    if (queue == NULL) {
        return -1;
    }
    struct DynamicArray *myQueue = queue;
    return myQueue->dSize;
}

//判断队列是否为空
int isEmptyQueue(Queue queue) {
    if (queue == NULL) {
        return -1;
    }
    struct DynamicArray *myQueue = queue;
    return myQueue->dSize == 0;
}

//销毁释放
void destroyQueue(Queue queue){
    if(queue == NULL){
        return;
    }
    destroyDynamicArray(queue);
}

