//
// Created by Tom on 2024/1/20.
//

#ifndef BASEGRAMMAR_LINKLIST_H
#define BASEGRAMMAR_LINKLIST_H

#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>

struct LinkNode {
    int num;
    struct LinkNode *next;
};

struct LinkNode *initLinkList();

void foreachListList(struct LinkNode *pHead);

void insertListList(struct LinkNode *pHead,int oldVal,int newVal);

void deleteListList(struct LinkNode *pHead,int delVal);

void clearListList(struct LinkNode *pHead);

void destroyListList(struct LinkNode *pHead);


#endif //BASEGRAMMAR_LINKLIST_H
