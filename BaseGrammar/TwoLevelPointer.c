//
// Created by Tom on 2024/1/16.
//
#include  <stdio.h>
#include  <string.h>
#include  <stdlib.h>

struct Teacher {
    char *name;
    char **students;
};

void allocatedSpace(struct Teacher ***teachers, int teacherCount,int studentCount) {
    if (teachers == NULL) {
        return;
    }
    struct Teacher **ts = malloc(sizeof(struct Teacher *) * teacherCount);
    for (int i = 0; i < teacherCount; ++i) {
        ts[i] = malloc(sizeof(struct Teacher));
        ts[i]->name = malloc(sizeof(char) * 64);
        sprintf(ts[i]->name, "Teacher_%d", i + 1);
        ts[i]->students = malloc(sizeof(char *) * studentCount);
        for (int j = 0; j < studentCount; ++j) {
            ts[i]->students[j] = malloc(sizeof(char) * 64);
            sprintf(ts[i]->students[j], "%s_student_%d", ts[i]->name, j + 1);
        }
    }
    *teachers = ts;
}

void printTeacher(struct Teacher **teachers, int teacherCount,int studentCount) {

    for (int i = 0; i < teacherCount; ++i) {
        printf("teacher name : %s\n",teachers[i]->name);
        for (int j = 0; j < studentCount; ++j) {
            printf("     %s 的学生:%s\n",teachers[i]->name,teachers[i]->students[j]);
        }
    }
}

void freeSpace(struct Teacher **teachers, int teacherCount,int studentCount) {

    if (teachers == NULL) {
        return;
    }
    for (int i = 0; i < teacherCount; ++i) {
        if(teachers[i]->name != NULL){
            free(teachers[i]->name);
            teachers[i]->name = NULL;
            for (int j = 0; j < studentCount; ++j) {
                if(teachers[i]->students[j] != NULL){
                    free(teachers[i]->students[j]);
                    teachers[i]->students[j] = NULL;
                }
            }
            free(teachers[i]->students);
            teachers[i]->students = NULL;
            free(teachers[i]);
            teachers[i] = NULL;
        }
    }
    free(teachers);
}

int main() {

    struct Teacher **teachers = NULL;
    allocatedSpace(&teachers, 3,5);
    printTeacher(teachers,3,5);
    freeSpace(teachers,3,5);
    teachers = NULL;
    return 0;
}