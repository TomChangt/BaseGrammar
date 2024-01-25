//
// Created by Tom on 2024/1/25.
//


#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>

struct Hero {
    char name[64];
    int age;
};


struct LinkListNode {
    void *data;
    struct LinkListNode *next;
};

struct LList {
    struct LinkListNode lHead; //链表头节点
    int lSize;
};

typedef void *LinkList;

//初始化节点
LinkList initList() {
    struct LList *myList = malloc(sizeof(struct LList));
    if (myList == NULL) {
        return NULL;
    }
    myList->lHead.data = NULL;
    myList->lHead.next = NULL;
    myList->lSize = 0;
    return myList;
}

//插入数据
void insertList(LinkList myList, int pos, void *data) {
    if (myList == NULL) {
        return;
    }

    struct LList *linkList = myList;
    if (pos < 0 || pos > linkList->lSize) {
        //尾插
        pos = linkList->lSize;
    }
    struct LinkListNode *lCurrent = &(linkList->lHead);
    for (int i = 0; i < pos; ++i) {
        lCurrent = lCurrent->next;
    }

    //创建新节点
    struct LinkListNode *newNode = malloc(sizeof(struct LinkListNode));
    newNode->data = data;
    newNode->next = lCurrent->next;
    lCurrent->next = newNode;
    linkList->lSize++;
}

//删除节点
void delLinkListByPos(LinkList myList, int pos) {
    if (myList == NULL) {
        return;
    }
    struct LList *linkList = myList;
    if (pos < 0 || pos > linkList->lSize) {
        //无效位置
        return;
    }
    struct LinkListNode *lCurrent = &(linkList->lHead);

    for (int i = 0; i < pos; ++i) {
        lCurrent = lCurrent->next;
    }
    //删除节点
    struct LinkListNode *delNode = lCurrent->next;
    lCurrent->next = delNode->next;
    free(delNode);
    delNode = NULL;
    linkList->lSize--;
}

void delLinkListByData(LinkList myList, void *data, int(*myCompare)(void *, void *)) {
    if (myList == NULL) {
        return;
    }
    struct LList *linkList = myList;
    struct LinkListNode *lPrev = &(linkList->lHead);
    struct LinkListNode *lCurrent = lPrev->next;
    for (int i = 0; i < linkList->lSize; ++i) {
        if (myCompare(lCurrent->data, data) == 0) {
            lPrev->next = lCurrent->next;
            free(lCurrent);
            lCurrent = NULL;
            linkList->lSize--;
            break;
        }
        lPrev = lCurrent;
        lCurrent = lCurrent->next;
    }
}

//遍历链表
void foreachList(LinkList myList, void(*printData)(void *)) {
    if (myList == NULL) {
        return;
    }
    struct LList *linkList = myList;
    struct LinkListNode *lCurrent = linkList->lHead.next;
    for (int i = 0; i < linkList->lSize; ++i) {
        printData(lCurrent->data);
        lCurrent = lCurrent->next;
    }
}

void destroyLinkList(LinkList myList){
    if (myList == NULL) {
        return;
    }
    struct LList *linkList = myList;
    struct LinkListNode *lCurrent = linkList->lHead.next;
    for (int i = 0; i < linkList->lSize; ++i) {
        struct LinkListNode *lNext = lCurrent->next;
        free(lCurrent);
        lCurrent = lNext;
    }
    free(myList);
    myList = NULL;
}

void printData(void *data) {
    struct Hero *h = data;
    printf("英雄名称[%s]------英雄年纪[%d]\n", h->name, h->age);
}

int compareData(void *data, void *data2) {
    struct Hero *h1 = data;
    struct Hero *h2 = data2;
    return strcmp(h1->name, h2->name);
}


int main() {
    LinkList myList = initList();
    struct Hero h1 = {"张飞", 18};
    struct Hero h2 = {"刘备", 19};
    struct Hero h3 = {"关羽", 20};
    struct Hero h4 = {"赵云", 21};
    struct Hero h5 = {"诸葛亮", 22};
    struct Hero h6 = {"黄忠", 23};
    insertList(myList, -1, &h1);
    insertList(myList, -1, &h2);
    insertList(myList, -1, &h3);
    insertList(myList, -1, &h4);
    insertList(myList, -1, &h5);
    insertList(myList, -1, &h6);
    printf("----------插入数据后遍历链表----------\n");
    foreachList(myList, printData);
    printf("----------删除数据后遍历链表----------\n");
    delLinkListByPos(myList, 3);
    foreachList(myList, printData);
    printf("----------删除数据后遍历链表----------\n");
    delLinkListByData(myList, &h6,compareData);
    foreachList(myList, printData);

    destroyLinkList(myList);
    myList = NULL;
    return EXIT_SUCCESS;
}