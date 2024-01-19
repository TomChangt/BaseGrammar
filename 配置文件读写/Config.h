#ifndef BASEGRAMMAR_CONFIG_H
#define BASEGRAMMAR_CONFIG_H

#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>
struct ConfigInfo {
    char key[64];
    char value[128];
};
int isValidLine(char *str);

int getFileLine(char *fileName);

void parseFile(char *filePath, int lines, struct ConfigInfo **configInfo);

char *getInfoByKey(char *key, struct ConfigInfo *configInfo, int lines);

void freeSpace(struct ConfigInfo *configInfo);


#endif //BASEGRAMMAR_CONFIG_H
