//
// Created by Tom on 2024/1/20.
//

#include "LinkList.h"


struct LinkNode *initLinkList() {

    struct LinkNode *pHead = malloc(sizeof(struct LinkNode));

    if (pHead == NULL) {
        return NULL;
    }
    //初始化头节点
    pHead->num = -1;
    pHead->next = NULL;
    struct LinkNode *pTail = pHead;
    int val = -1;
    while (1) {
        printf("输入节点数据插入节点，-1代表退出\n");
        scanf("%d", &val);
        if (val == -1) {
            break;
        }
        struct LinkNode *node = malloc(sizeof(struct LinkNode));
        node->num = val;
        node->next = NULL;

        //更新节点指向
        pTail->next = node;
        pTail = node;

    }
    return pHead;
}

void foreachLinkList(struct LinkNode *pHead) {

    if (pHead == NULL) {
        return;
    }
    struct LinkNode *current = pHead->next;
    while (current != NULL) {

        printf("遍历节点数据为 : %d \n", current->num);
        current = current->next;
    }
}

void insertLinkList(struct LinkNode *pHead, int oldVal, int newVal) {

    if (pHead == NULL) {
        return;
    }

    struct LinkNode *pPrev = pHead;
    struct LinkNode *pCurrent = pHead->next;

    while (pCurrent != NULL) {
        if (pCurrent->num == oldVal) {
            break;
        }
        pPrev = pCurrent;
        pCurrent = pCurrent->next;
    }

    struct LinkNode *node = malloc(sizeof(struct LinkNode));
    node->num = newVal;
    node->next = pCurrent;
    pPrev->next = node;

}

void deleteLinkList(struct LinkNode *pHead, int delVal) {
    if (pHead == NULL) {
        return;
    }
    struct LinkNode *pPrev = pHead;
    struct LinkNode *pCurrent = pHead->next;

    while (pCurrent != NULL) {
        if (pCurrent->num == delVal) {
            break;
        }
        pPrev = pCurrent;
        pCurrent = pCurrent->next;
    }
    if (pCurrent != NULL) {
        pPrev->next = pCurrent->next;
        free(pCurrent);
    }

}

void clearLinkList(struct LinkNode *pHead) {
    if (pHead == NULL) {
        return;
    }
    struct LinkNode *pCurrent = pHead->next;
    while (pCurrent != NULL) {
        struct LinkNode *next = pCurrent->next;
        free(pCurrent);
        pCurrent = next;
    }
    pHead->next = NULL;
}

void destroyLinkList(struct LinkNode *pHead) {
    if (pHead == NULL) {
        return;
    }
    clearLinkList(pHead);
    pHead = NULL;
}

void reversedLinkList(struct LinkNode *pHead) {
    if (pHead == NULL) {
        return;
    }
    struct LinkNode *pCurrent = pHead->next;
    struct LinkNode *pNext = NULL;
    struct LinkNode *pPrev = NULL;
    while (pCurrent != NULL) {
        pNext = pCurrent->next;
        pCurrent->next = pPrev;
        pPrev = pCurrent;
        pCurrent = pNext;
    }

    pHead->next = pPrev;
}
