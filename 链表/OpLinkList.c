//
// Created by Tom on 2024/1/20.
//


#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
#include "LinkList.c"

int main() {

    struct LinkNode *pHead = initLinkList();
    foreachLinkList(pHead);
//    insertLinkList(pHead,20,100);
//    insertLinkList(pHead,22,1000);
//    printf("插入新值以后重新遍历\n");
//    foreachLinkList(pHead);
//    deleteLinkList(pHead,30);
//    printf("删除值以后重新遍历\n");
//    foreachLinkList(pHead);
//    clearLinkList(pHead);
//    insertLinkList(pHead,111,111);
//    insertLinkList(pHead,222,222);
//    insertLinkList(pHead,333,333);
//    printf("清空值以后重新遍历\n");
//    foreachLinkList(pHead);
    reversedLinkList(pHead);
    printf("反转后重新遍历\n");
    foreachLinkList(pHead);
    destroyLinkList(pHead);
    pHead = NULL;
    return EXIT_SUCCESS;
}