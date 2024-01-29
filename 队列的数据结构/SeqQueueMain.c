//
// Created by Tom on 2024/1/29.
//


#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
#include "SeqQueue.c"

struct Hero{
    char name[64];
    int age;
};


int main() {
    Queue myQueue = initQueue();
    struct Hero h1 = {"张飞",18};
    struct Hero h2 = {"刘备",19};
    struct Hero h3 = {"关羽",20};
    struct Hero h4 = {"赵云",21};
    struct Hero h5 = {"诸葛亮",22};
    struct Hero h6 = {"黄忠",23};
    pushQueue(myQueue,&h1);
    pushQueue(myQueue,&h2);
    pushQueue(myQueue,&h3);
    pushQueue(myQueue,&h4);
    pushQueue(myQueue,&h5);
    pushQueue(myQueue,&h6);
    printf("队列大小 : %d\n",sizeQueue(myQueue));
    while (!isEmptyQueue(myQueue)){
        struct Hero *font = fontQueue(myQueue);
        printf("队列头元素-------[name=%s]------[age=%d] \n",font->name,font->age);
        struct Hero *back = backQueue(myQueue);
        printf("队列尾元素-------[name=%s]------[age=%d] \n",back->name,back->age);
        popQueue(myQueue);
    }
    printf("队列大小 : %d\n",sizeQueue(myQueue));
    destroyQueue(myQueue);
    myQueue = NULL;
    return EXIT_SUCCESS;
}