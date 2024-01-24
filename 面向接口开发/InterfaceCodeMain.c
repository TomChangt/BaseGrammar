//
// Created by Tom on 2024/1/24.
//


#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
#include <time.h>
#include "InterfaceCode.c"

//初始化游戏
typedef void(*INIT_GAME)(void **player, char *name);

//核心战斗
typedef int(*FIGHT_GAME)(void *player,int gameDiff);

//查看玩家信息
typedef void(*PRINT_GAME)(void *player);

//离开游戏
typedef void(*EXIT_GAME)(void *player);

void playGame(INIT_GAME initGame,FIGHT_GAME fightGame,PRINT_GAME printGame,EXIT_GAME exitGame){
    void *player = NULL;
    printf("------- 请输入玩家的姓名开始游戏 ---------\n");
    char name[1024];
    scanf("%s",name);
    initGame(&player,name);
    int diff = -1;
    int isContinue = 1;
    while (1){
        if(isContinue != 1){
            break;
        }
        getchar();
        system("clear");
        printf("你好，%s 请选择游戏难度: \n",name);
        printf("1、简单\n");
        printf("2、中等\n");
        printf("3、困难\n");
        scanf("%d",&diff);

        int ret = fightGame(player,diff);

        if(ret == 0){
            printf("抱歉此局失败，再接再厉\n");
        }else{
            printf("恭喜此局胜利！\n");
        }
        printGame(player);

        printf("你好，%s 是否选择继续游戏: \n",name);
        printf("0、退出游戏\n");
        printf("1、继续游戏\n");
        scanf("%d",&isContinue);
    }
    exitGame(player);

}

int main() {

    srand((unsigned int) time(NULL));
    playGame(INIT_GAME_COMPANY1,FIGHT_GAME_COMPANY1,
             PRINT_GAME_COMPANY1,EXIT_GAME_COMPANY1);

    return EXIT_SUCCESS;
}