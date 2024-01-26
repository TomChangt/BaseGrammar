//
// Created by Tom on 2024/1/26.
//

#ifndef BASEGRAMMAR_LINKSTACK_H
#define BASEGRAMMAR_LINKSTACK_H

typedef void *Stack;

//初始化栈
Stack initStack();
//入栈
void pushStack(Stack stack,void *data);
//出栈
void popStack(Stack stack);
//返回栈顶
void *topStack(Stack stack);
//返回栈大小
int sizeStack(Stack stack);
//判断栈是否为空
int isEmptyStack(Stack stack);
//销毁释放
void destroyStack(Stack stack);



#endif //BASEGRAMMAR_LINKSTACK_H
