//
// Created by Tom on 2024/1/19.
//
#include "Config.h"

int isValidLine(char *str) {
    if (str[0] == ' ' || str[0] == '\0' || strchr(str, ':') == NULL) {
        return 0;
    }
    return 1;
}

int getFileLine(char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (file == NULL) {
        perror("open source file error: ");
        exit(EXIT_FAILURE);
    }
    char buff[1024] = {0};
    int lines = 0;
    while (fgets(buff, 1024, file) != NULL) {
        if (isValidLine(buff)) {
            lines++;
        }
        memset(buff, 0, 1024);
    }
    fclose(file);
    return lines;
}

void parseFile(char *filePath, int lines, struct ConfigInfo **configInfo) {

    struct ConfigInfo *info = malloc(sizeof(struct ConfigInfo) * lines);

    if (info == NULL) {
        return;
    }

    FILE *file = fopen(filePath, "r");
    if (file == NULL) {
        perror("open source file error: ");
        exit(EXIT_FAILURE);
    }
    char buff[1024] = {0};
    int index = 0;
    while (fgets(buff, 1024, file) != NULL) {
        if (isValidLine(buff)) {
            memset(info[index].key, 0, 64);
            memset(info[index].value, 0, 128);
            char *pos = strchr(buff, ':');
            strncpy(info[index].key, buff, pos - buff);
            strncpy(info[index].value, pos + 1, strlen(pos + 1) - 1);
            //printf("key = %s and value = %s \n",info[index].key,info[index].value);
            index ++;
        }
        memset(buff, 0, 1024);
    }
    fclose(file);
    *configInfo = info;
}

char *getInfoByKey(char *key, struct ConfigInfo *configInfo, int lines){
    for (int i = 0; i < lines; ++i) {
        if ( strcmp (key, configInfo[i].key) == 0){
            return configInfo[i].value;
        }
    }
    return NULL;
}

void freeSpace(struct ConfigInfo * configInfo){
    if (configInfo != NULL){
        free(configInfo);
        configInfo = NULL;
    }
}


