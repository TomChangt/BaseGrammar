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

void foreachLinkList(struct LinkNode *pHead);

void insertLinkList(struct LinkNode *pHead,int oldVal,int newVal);

void deleteLinkList(struct LinkNode *pHead,int delVal);

void clearLinkList(struct LinkNode *pHead);

void destroyLinkList(struct LinkNode *pHead);

void reversedLinkList(struct LinkNode *pHead);

#endif //BASEGRAMMAR_LINKLIST_H
