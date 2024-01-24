//
// Created by Tom on 2024/1/24.
//


#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
#include "InterfaceCode.h"

//初始化游戏
void INIT_GAME_COMPANY1(void **p, char *name) {
    struct Player *player = malloc(sizeof(struct Player));
    if (player == NULL) {
        return;
    }
    *p = player;
    stpcpy(player->name, name);
    player->exp = 0;
    player->level = 0;
}

//核心战斗
int FIGHT_GAME_COMPANY1(void *p, int gameDiff) {
    struct Player *player = p;
    int addExp = 0;

    switch (gameDiff) {
        case 1:
            addExp = isWin(90, gameDiff);
            break;
        case 2:
            addExp = isWin(50, gameDiff);
            break;
        case 3:
            addExp = isWin(30, gameDiff);
            break;
    }
    player->exp += addExp;
    player->level = player->exp / 10;
    return addExp == 0 ? 0 : 1;

}

int isWin(int winRate, int diff) {
    int random = rand() % 100 + 1;
    printf("英雄战斗比分 [%d : %d] \n",winRate,random);
    return random <= winRate ? 10 * diff : 0;
}

//查看玩家信息
void PRINT_GAME_COMPANY1(void *p){

    struct Player *player = p;

    printf("--------- 玩家当前状态：姓名[%s] --------- 经验[%d] --------- 等级[%d] ---------\n",
           player->name,player->exp,player->level);
}

//离开游戏
void EXIT_GAME_COMPANY1(void *player){
    if(player == NULL){
        return;
    }
    free(player);
    player = NULL;
    printf("游戏结束--------------\n");
}
