//
// Created by Tom on 2024/1/26.
//


#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
#include "SeqStack.h"
#define MAX 1024

struct SStack{
    void *data[MAX];
    int sSize;
};

//初始化栈
SeqStack initSeqStack() {
    struct SStack *myStack = malloc(sizeof(struct SStack));
    if (myStack == NULL) {
        return NULL;
    }
    memset(myStack->data, 0, sizeof(void *) * MAX);
    myStack->sSize = 0;

    return myStack;
}

//入栈
void pushSeqStack(SeqStack stack, void *data){
    if(stack == NULL){
        return;
    }
    if(data == NULL){
        return;
    }
    struct SStack *myStack = stack;

    if(myStack->sSize == MAX){
        return;
    }
    myStack->data[myStack->sSize] = data;
    myStack->sSize++;
}

//出栈
void popSeqStack(SeqStack stack){
    if(stack == NULL){
        return;
    }
    struct SStack *myStack = stack;
    if(myStack->sSize == 0){
        return;
    }
    myStack->data[myStack->sSize - 1] = NULL;
    myStack->sSize--;
}

//返回栈顶
void *topSeqStack(SeqStack stack){
    if(stack == NULL ){
        return NULL;
    }
    struct SStack *myStack = stack;
    if(myStack->sSize == 0){
        return NULL;
    }
    return myStack->data[myStack->sSize - 1];
}

//返回栈大小
int sizeSeqStack(SeqStack stack){
    if(stack == NULL ){
        return -1;
    }
    struct SStack *myStack = stack;
    return myStack->sSize;
}

//判断栈是否为空
int isEmptySeqStack(SeqStack stack){
    if(stack == NULL ){
        return -1;
    }
    struct SStack *myStack = stack;
    return  myStack->sSize == 0;
}

//销毁释放
void destroySeqStack(SeqStack stack){
    if(stack == NULL ){
        return ;
    }
    free(stack);
    stack = NULL;
}

