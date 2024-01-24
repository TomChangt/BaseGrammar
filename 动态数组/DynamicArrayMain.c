//
// Created by Tom on 2024/1/24.
//


#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
#include "DynamicArray.c"

struct Hero{
    char name[64];
    int age;
};

void printData(void *data){
    struct Hero *h = data;
    printf("英雄名称[%s]------英雄年纪[%d]\n",h->name,h->age);
}

int compareData(void *data,void *data2){
    struct Hero *h1 = data;
    struct Hero *h2 = data2;
    return strcmp(h1->name,h2->name);
}

int main() {
    struct DynamicArray *arr = initDynamicArray(5);
    struct Hero h1 = {"张飞",18};
    struct Hero h2 = {"刘备",19};
    struct Hero h3 = {"关羽",20};
    struct Hero h4 = {"赵云",21};
    struct Hero h5 = {"诸葛亮",22};
    struct Hero h6 = {"黄忠",23};
    printf("数组大小 size = %d , capacity = %d\n",arr->dSize,arr->dCapacity);
    insertDynamicArray(arr,&h1,-1);
    insertDynamicArray(arr,&h2,-1);
    insertDynamicArray(arr,&h3,-1);
    insertDynamicArray(arr,&h4,-1);
    insertDynamicArray(arr,&h5,-1);
    printf("数组大小 size = %d , capacity = %d\n",arr->dSize,arr->dCapacity);
    insertDynamicArray(arr,&h6,-1);
    printf("数组大小 size = %d , capacity = %d\n",arr->dSize,arr->dCapacity);
    foreachDynamicArray(arr,printData);
    delDynamicArrayByPos(arr,2);
    foreachDynamicArray(arr,printData);
    printf("数组大小 size = %d , capacity = %d\n",arr->dSize,arr->dCapacity);
    struct Hero h7 = {"赵云",21};
    delDynamicArrayByValue(arr,&h7,compareData);
    foreachDynamicArray(arr,printData);
    printf("数组大小 size = %d , capacity = %d\n",arr->dSize,arr->dCapacity);

    destroyDynamicArray(arr);
    arr = NULL;
    return EXIT_SUCCESS;
}