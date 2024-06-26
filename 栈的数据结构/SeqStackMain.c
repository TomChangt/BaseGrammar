//
// Created by Tom on 2024/1/26.
//


#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
#include "SeqStack.c"

struct Hero{
    char name[64];
    int age;
};


int main() {

    Stack  myStack = initStack();
    struct Hero h1 = {"张飞",18};
    struct Hero h2 = {"刘备",19};
    struct Hero h3 = {"关羽",20};
    struct Hero h4 = {"赵云",21};
    struct Hero h5 = {"诸葛亮",22};
    struct Hero h6 = {"黄忠",23};
    pushStack(myStack,&h1);
    pushStack(myStack,&h2);
    pushStack(myStack,&h3);
    pushStack(myStack,&h4);
    pushStack(myStack,&h5);
    pushStack(myStack,&h6);
    printf("栈 size = %d \n", sizeStack(myStack));
    while (!isEmptyStack(myStack)){
        void  *data = topStack(myStack);
        struct Hero *myData = data;
        printf("栈顶元素 Hero [name = %s] ------ [age = %d] \n",myData->name,myData->age);
        popSeqStack(myStack);
    }
    printf("栈 size = %d \n", sizeStack(myStack));
    destroyStack(myStack);
    return EXIT_SUCCESS;
}