#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void sortO1(int arr[], int len) {
    for (int i = 0; i < len; ++i) {
        int min = i;
        for (int j = i + 1; j < len; ++j) {
            if(arr[min] > arr[j]){
                min = j;
            }
        }
        if(i != min){
//            arr[i] = arr[i]+arr[min];
//            arr[min] = arr[i]-arr[min];
//            arr[i] = arr[i]-arr[min];
            arr[i] = arr[i] ^ arr[min];
            arr[min] = arr[i] ^ arr[min];
            arr[i] = arr[i] ^ arr[min];
        }
    }
}


int main() {

    int arr[] = {3, 4, 1, 5, 2};
    int len = sizeof(arr) / sizeof(int);
    sortO1(arr, len);
    for (int i = 0; i < len; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

}