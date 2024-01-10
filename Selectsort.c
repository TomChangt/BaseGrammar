#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void sortO1(int arr[], int len) {
    for (int i = 0; i < len; ++i) {
        int min = i;
        for (int j = i + 1; j < len; ++j) {
            if (arr[min] > arr[j]) {
                min = j;
            }
        }
        if (i != min) {
//            arr[i] = arr[i]+arr[min];
//            arr[min] = arr[i]-arr[min];
//            arr[i] = arr[i]-arr[min];
            arr[i] = arr[i] ^ arr[min];
            arr[min] = arr[i] ^ arr[min];
            arr[i] = arr[i] ^ arr[min];
        }
    }
}

void swap(char **a,char **b){
    char *temp = *a;
    *a = *b;
    *b = temp;
}

void selectSort(char *arr[], int len) {

    for (int i = 0; i < len; ++i) {
        int max = i;
        for (int j = i + 1; j < len; ++j) {
            if (strcmp(arr[max],arr[j]) < 0) {
                max = j;
            }
        }
        if (i != max) {
            swap(&arr[max],&arr[i]);
        }
    }


}

int main() {

//    int arr[] = {3, 4, 1, 5, 2};
//    int len = sizeof(arr) / sizeof(int);
//    sortO1(arr, len);
//    for (int i = 0; i < len; ++i) {
//        printf("%d ", arr[i]);
//    }
//    printf("\n");

    char *arrays[] = {"aaa", "ccc", "bbb", "eee", "ddd"};
    int length = sizeof(arrays) / sizeof(char *);
    selectSort(arrays, length);
    for (int i = 0; i < length; ++i) {
        printf("%s ",arrays[i]);
    }
    printf("\n");
    return 0;

}