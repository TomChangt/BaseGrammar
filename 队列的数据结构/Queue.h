//
// Created by Tom on 2024/1/29.
//

#ifndef BASEGRAMMAR_QUEUE_H
#define BASEGRAMMAR_QUEUE_H

typedef void *Queue;

//初始化队列
Queue initQueue();
//入队
void pushQueue(Queue queue,void *data);
//出队列
void popQueue(Queue queue);
//返回队列头
void *fontQueue(Queue queue);
//返回队尾部
void *backQueue(Queue queue);
//返回队列大小
int sizeQueue(Queue queue);
//判断队列是否为空
int isEmptyQueue(Queue queue);
//销毁释放
void destroyQueue(Queue queue);


#endif //BASEGRAMMAR_QUEUE_H
