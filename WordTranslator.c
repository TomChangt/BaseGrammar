//
// Created by Tom on 2024/1/2.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FILE_PATH "dict.txt"
typedef struct DictData {
    char *key;
    char *content;
} DICT;


FILE *open_file() {
    FILE *fileData = fopen(FILE_PATH, "r");
    if (fileData == NULL) {
        perror("open source file error: ");
        exit(EXIT_FAILURE);
    }
    return fileData;
}

int get_dict_count() {
    FILE *fp = open_file();
    char buffer[1024] = "";
    int i = 0, line = 0;
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        if (++line % 2 == 0) {
            i++;
        }
    }
    return i;
}

void filter_buffer(char *buffer) {
    int n = strlen(buffer) - 1;
    while (buffer[n] == ' ' || buffer[n] == '\n' || buffer[n] == '\r' || buffer[n] == '\t')
        n--;
    buffer[n + 1] = 0;
}


void init_dict(DICT **temp, int count) {

    DICT *p = malloc(sizeof(DICT) * count);
    FILE *fp = open_file();
    char buffer[1024] = "";
    int i = 0, line = 0;

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        filter_buffer(buffer); //过滤隐藏字符
        if (++line % 2 == 1) {
            //奇数行
            p[i].key = malloc(strlen(buffer) + 1);
            strcpy(p[i].key, buffer + 1); //去掉#号
        } else {
            //偶数行
            p[i].content = malloc(strlen(buffer) + 1);
            strcpy(p[i].content, buffer + 6); //去掉Trans:
            i++;
        }
    }
    fclose(fp);
    *temp = p;
}

int search_dict(char *cmd, DICT *dict, int n, char *content) {

    for (int i = 0; i < n; ++i) {
        if (strcmp(cmd, dict[i].key) == 0) {
            strcpy(content, dict[i].content);
            return 1;
        }
    }
    return 0;

}

int main() {
    DICT *dict = NULL;
    int dict_count = get_dict_count();
    init_dict(&dict, dict_count);
    char cmd[256] = "";
    char content[256] = "";
    int rs = 0;
    while (1) {
        printf("请输入需要翻译的单词:");
        fgets(cmd, sizeof(cmd), stdin);
        cmd[strlen(cmd) - 1] = 0; //将最后一个\n去掉
        rs = search_dict(cmd, dict, dict_count, content);
        if (rs == 0) {
            printf("no trans \n");
        } else {
            printf("翻译为：%s \n", content);
        }
    }

}