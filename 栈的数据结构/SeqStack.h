//
// Created by Tom on 2024/1/26.
//

#ifndef BASEGRAMMAR_SEQSTACK_H
#define BASEGRAMMAR_SEQSTACK_H

typedef void * SeqStack;

//初始化栈
SeqStack initSeqStack();
//入栈
void pushSeqStack(SeqStack stack,void *data);
//出栈
void popSeqStack(SeqStack stack);
//返回栈顶
void *topSeqStack(SeqStack stack);
//返回栈大小
int sizeSeqStack(SeqStack stack);
//判断栈是否为空
int isEmptySeqStack(SeqStack stack);
//销毁释放
void destroySeqStack(SeqStack stack);


#endif //BASEGRAMMAR_SEQSTACK_H
