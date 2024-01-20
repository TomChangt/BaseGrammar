//
// Created by Tom on 2024/1/20.
//


#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
#include "LinkList.c"

int main() {

    struct LinkNode *pHead = initLinkList();
    foreachListList(pHead);
    insertListList(pHead,20,100);
    insertListList(pHead,22,1000);
    printf("插入新值以后重新遍历\n");
    foreachListList(pHead);
    deleteListList(pHead,30);
    printf("删除值以后重新遍历\n");
    foreachListList(pHead);
    clearListList(pHead);
    insertListList(pHead,111,111);
    insertListList(pHead,222,222);
    insertListList(pHead,333,333);
    printf("清空值以后重新遍历\n");
    foreachListList(pHead);
    destroyListList(pHead);
    pHead = NULL;
    return EXIT_SUCCESS;
}