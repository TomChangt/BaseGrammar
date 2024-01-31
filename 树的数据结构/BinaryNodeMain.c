//
// Created by Tom on 2024/1/31.
//


#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
#include "../栈的数据结构/SeqStack.c"

struct BinaryNode {
    char value;
    struct BinaryNode *lChild;
    struct BinaryNode *rChild;
    int flag;
};
enum Each {
    DLR = 1, //前序遍历
    LDR,//中序遍历
    LRD//后序遍历
};

struct BinaryNode *copyTree(struct BinaryNode *node) {
    if (node == NULL) {
        return NULL;
    }
    //先拷左子树
    struct BinaryNode *lNode = copyTree(node->lChild);
    //再拷右子树
    struct BinaryNode *rNode = copyTree(node->rChild);
    //创建新节点
    struct BinaryNode *newNode = malloc(sizeof(struct BinaryNode));
    newNode->value = node->value;
    newNode->lChild = lNode;
    newNode->rChild = rNode;
    newNode->flag = node->flag;
    //返回结果
    return newNode;
}

struct BinaryNode *init() {

    struct BinaryNode nodeA = {'A', NULL, NULL, 0};
    struct BinaryNode nodeB = {'B', NULL, NULL, 0};
    struct BinaryNode nodeC = {'C', NULL, NULL, 0};
    struct BinaryNode nodeD = {'D', NULL, NULL, 0};
    struct BinaryNode nodeE = {'E', NULL, NULL, 0};
    struct BinaryNode nodeF = {'F', NULL, NULL, 0};
    struct BinaryNode nodeG = {'G', NULL, NULL, 0};
    struct BinaryNode nodeH = {'H', NULL, NULL, 0};

    nodeA.lChild = &nodeB;
    nodeA.rChild = &nodeF;
    nodeB.rChild = &nodeC;
    nodeF.rChild = &nodeG;
    nodeC.lChild = &nodeD;
    nodeC.rChild = &nodeE;
    nodeG.lChild = &nodeH;

    return copyTree(&nodeA);
}

//遍历树
void recursion(struct BinaryNode *node, enum Each eachWay) {
    if (node == NULL) {
        return;
    }
    switch (eachWay) {
        case DLR:
            printf("%c\n", node->value);
            recursion(node->lChild, eachWay);
            recursion(node->rChild, eachWay);
            break;
        case LDR:
            recursion(node->lChild, eachWay);
            printf("%c\n", node->value);
            recursion(node->rChild, eachWay);
            break;
        case LRD:
            recursion(node->lChild, eachWay);
            recursion(node->rChild, eachWay);
            printf("%c\n", node->value);
            break;
    }
}

void nonRecursion(struct BinaryNode *node, enum Each eachWay) {
    Stack stack = initStack();
    pushStack(stack, node);
    while (sizeStack(stack) > 0) {
        struct BinaryNode *rootNode = topStack(stack);
        popSeqStack(stack);
        if (rootNode->flag == 1) {
            printf("%c\n", rootNode->value);
            continue;
        }
        switch (eachWay) {
            case DLR:
                if (rootNode->rChild != NULL) {
                    pushStack(stack, rootNode->rChild);
                }
                if (rootNode->lChild != NULL) {
                    pushStack(stack, rootNode->lChild);
                }
                rootNode->flag = 1;
                pushStack(stack, rootNode);
                break;
            case LDR:
                if (rootNode->rChild != NULL) {
                    pushStack(stack, rootNode->rChild);
                }
                rootNode->flag = 1;
                pushStack(stack, rootNode);
                if (rootNode->lChild != NULL) {
                    pushStack(stack, rootNode->lChild);
                }
                break;
            case LRD:
                rootNode->flag = 1;
                pushStack(stack, rootNode);
                if (rootNode->rChild != NULL) {
                    pushStack(stack, rootNode->rChild);
                }
                if (rootNode->lChild != NULL) {
                    pushStack(stack, rootNode->lChild);
                }
                break;
        }
    }
    destroyStack(stack);
}

void calculateLeafCount(struct BinaryNode *node, int *count) {
    if (node == NULL) {
        return;
    }
    if (node->lChild == NULL && node->rChild == NULL) {
        (*count)++;
    }
    calculateLeafCount(node->lChild, count);
    calculateLeafCount(node->rChild, count);
}

int getLeafHeight(struct BinaryNode *node) {
    if (node == NULL) {
        return 0;
    }
    int leftHeight = getLeafHeight(node->lChild);
    int rightHeight = getLeafHeight(node->rChild);
    return leftHeight >= rightHeight ? leftHeight + 1 : rightHeight + 1;
}

void freeTree(struct BinaryNode *node) {
    if (node == NULL) {
        return;
    }
    //先释放左子树
    freeTree(node->lChild);
    //再释放右子树
    freeTree(node->rChild);

    printf("%c 节点被释放了 \n", node->value);
    free(node);
    node = NULL;
}


int main() {

    struct BinaryNode *rootNode = init();

    printf("recursion -------------------------\n");
    recursion(rootNode, LRD);
    printf("nonRecursion ----------------------\n");
    nonRecursion(rootNode, LRD);
    int leafCount = 0;
    calculateLeafCount(rootNode, &leafCount);
    printf("叶子数量为 : %d\n", leafCount);
    int leafHeight = getLeafHeight(rootNode);
    printf("树的深度为 : %d\n", leafHeight);

    freeTree(rootNode);
    return EXIT_SUCCESS;
}