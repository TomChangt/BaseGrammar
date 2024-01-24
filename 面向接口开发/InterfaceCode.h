//
// Created by Tom on 2024/1/24.
//

#ifndef BASEGRAMMAR_INTERFACECODE_H
#define BASEGRAMMAR_INTERFACECODE_H

struct Player{
    char name[64];
    int level;
    int exp;
};
//初始化游戏
void INIT_GAME_COMPANY1(void **player, char *name);

//核心战斗
int FIGHT_GAME_COMPANY1(void *player,int gameDiff);

//查看玩家信息
void PRINT_GAME_COMPANY1(void *player);

//离开游戏
void EXIT_GAME_COMPANY1(void *player);

int isWin(int winRate,int diff);


#endif //BASEGRAMMAR_INTERFACECODE_H
