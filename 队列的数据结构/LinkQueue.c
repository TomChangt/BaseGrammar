//
// Created by Tom on 2024/1/29.
//


#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
#include "Queue.h"

struct LinkListNode {
    struct LinkListNode *next;
};
struct LList {
    struct LinkListNode lHead; //链表头节点
    int lSize;
    struct LinkListNode *lTail;
};


//初始化队列
Queue initQueue() {
    struct LList *myQueue = malloc(sizeof(struct LList));
    if (myQueue == NULL) {
        return NULL;
    }
    myQueue->lHead.next = NULL;
    myQueue->lSize = 0;
    myQueue->lTail = &(myQueue->lHead);

    return myQueue;
}

//入队 尾插
void pushQueue(Queue queue, void *data) {
    if (queue == NULL) {
        return;
    }
    if (data == NULL) {
        return;
    }
    struct LList *myQueue = queue;
    struct LinkListNode *myData = data;
    myQueue->lTail->next = myData;
    myData->next = NULL;
    myQueue->lTail = myData;
    myQueue->lSize++;
}

//出队列 头删
void popQueue(Queue queue) {
    if (queue == NULL) {
        return;
    }
    struct LList *myQueue = queue;
    if (myQueue->lSize == 0) {
        return;
    }

    if (myQueue->lSize == 1) {
        myQueue->lTail->next = NULL;
        myQueue->lTail = &(myQueue->lHead);
        myQueue->lSize = 0;
        return;
    }
    struct LinkListNode *firstData = myQueue->lHead.next;
    myQueue->lHead.next = firstData->next;
    myQueue->lSize--;

}

//返回队列头
void *fontQueue(Queue queue) {
    if (queue == NULL) {
        return NULL;
    }
    struct LList *myQueue = queue;
    if (myQueue->lSize == 0) {
        return NULL;
    }

    return myQueue->lHead.next;
}

//返回队尾部
void *backQueue(Queue queue) {
    if (queue == NULL) {
        return NULL;
    }
    struct LList *myQueue = queue;
    if (myQueue->lSize == 0) {
        return NULL;
    }
    return myQueue->lTail;
}

//返回队列大小
int sizeQueue(Queue queue) {
    if (queue == NULL) {
        return -1;
    }
    struct LList *myQueue = queue;
    return myQueue->lSize;
}

//判断队列是否为空
int isEmptyQueue(Queue queue) {
    if (queue == NULL) {
        return -1;
    }
    struct LList *myQueue = queue;
    return myQueue->lSize == 0;
}

//销毁释放
void destroyQueue(Queue queue){
    if (queue == NULL) {
        return;
    }
    free(queue);
    queue = NULL;
}

