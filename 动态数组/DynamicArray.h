//
// Created by Tom on 2024/1/24.
//

#ifndef BASEGRAMMAR_DYNAMICARRAY_H
#define BASEGRAMMAR_DYNAMICARRAY_H

struct DynamicArray {
    void **dArrayAdr; //数组真实内存地址
    int dCapacity; //数组容量
    int dSize; //数组元素个数
};

//初始化数组
struct DynamicArray *initDynamicArray(int capacity);
//插入元素
void insertDynamicArray(struct DynamicArray *arr,void *data,int pos);
//循环遍历动态数组
void foreachDynamicArray(struct DynamicArray *arr,void(*printData)(void *));
//按位置删除数组中元素
void delDynamicArrayByPos(struct DynamicArray *arr,int pos);
//按值删除数组中元素
void delDynamicArrayByValue(struct DynamicArray *arr,void *data,int(*compareFun)(void *, void *));
//销毁数组
void destroyDynamicArray(struct DynamicArray *arr);

#endif //BASEGRAMMAR_DYNAMICARRAY_H
