//
// Created by Tom on 2024/1/19.
//

#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
#include "Config.c"


int main() {
    char * filePath = "./配置文件读写/config.txt";
    int lines = getFileLine(filePath);
    printf("配置文件行数:%d\n",lines);
    struct ConfigInfo *configInfoArray = NULL;
    parseFile(filePath,lines,&configInfoArray);
    printf("heroId = %s\n", getInfoByKey("heroId", configInfoArray, lines));
    printf("heroName = %s\n", getInfoByKey("heroName", configInfoArray, lines));
    printf("heroAtk = %s\n", getInfoByKey("heroAtk", configInfoArray, lines));
    printf("heroDef = %s\n", getInfoByKey("heroDef", configInfoArray, lines));
    printf("heroInfo = %s\n", getInfoByKey("heroInfo", configInfoArray, lines));
    freeSpace(configInfoArray);
    configInfoArray = NULL;
    return EXIT_SUCCESS;
}