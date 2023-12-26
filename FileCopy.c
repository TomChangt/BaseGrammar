//
// Created by Tom on 2023/12/26.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void copyFile(const char *sourceFileName, const char *targetFileName) {
    FILE *sourceFile;
    FILE *targetFile;

    sourceFile = fopen(sourceFileName, "r");
    if (sourceFile == NULL) {
        perror("open source file error: ");
        exit(EXIT_FAILURE);
    }
    targetFile = fopen(targetFileName, "w");
    if (targetFile == NULL) {
        perror("open target file error: ");
        fclose(sourceFile);
        exit(EXIT_FAILURE);
    }
    char buffer[1024];

    while (fgets(buffer, sizeof(buffer), sourceFile) != NULL) {
        fputs(buffer, targetFile);
    }

    fclose(sourceFile);
    fclose(targetFile);
}

int main() {
    const char *sourceFileName = "CopySource.txt";
    const char *targetFileName = "CopyTarget.txt";

    copyFile(sourceFileName, targetFileName);

    return 0;
}