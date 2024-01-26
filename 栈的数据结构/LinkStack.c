//
// Created by Tom on 2024/1/26.
//


#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
#include "Stack.h"

struct LStackNode {
    struct LStackNode *next;
};
struct LStack {
    struct LStackNode lHead; //链表头节点
    int lSize;
};

//初始化栈
Stack initStack() {
    struct LStack *myStack = malloc(sizeof(struct LStack));
    if (myStack == NULL) {
        return NULL;
    }
    myStack->lHead.next = NULL;
    myStack->lSize = 0;
    return myStack;
}

//入栈
void pushStack(Stack stack, void *data) {
    if (stack == NULL) {
        return;
    }
    if (data == NULL) {
        return;
    }
    struct LStack *myStack = stack;
    struct LStackNode *myData = data;
    //本质头插
    myData->next = myStack->lHead.next;
    myStack->lHead.next = myData;
    myStack->lSize++;
}

//出栈
void popSeqStack(Stack stack) {
    if (stack == NULL) {
        return;
    }
    struct LStack *myStack = stack;
    //本质头删
    if (myStack->lSize == 0) {
        return;
    }
    struct LStackNode *lFirst = myStack->lHead.next;

    myStack->lHead.next = lFirst->next;

    myStack->lSize--;
}

//返回栈顶
void *topStack(Stack stack){
    if (stack == NULL) {
        return NULL;
    }
    struct LStack *myStack = stack;
    if (myStack->lSize == 0) {
        return NULL;
    }
    return myStack->lHead.next;
}
//返回栈大小
int sizeStack(Stack stack){
    if (stack == NULL) {
        return -1;
    }
    struct LStack *myStack = stack;
    return myStack->lSize;
}
//判断栈是否为空
int isEmptyStack(Stack stack){
    if (stack == NULL) {
        return -1;
    }
    struct LStack *myStack = stack;
    return  myStack->lSize == 0;
}
//销毁释放
void destroyStack(Stack stack){
    if (stack == NULL) {
        return;
    }
    free(stack);
    stack = NULL;
}

