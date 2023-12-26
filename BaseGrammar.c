#include <stdio.h>
#include <string.h>

/***
 * 查询 src中出现dest字符串的个数
 * @param src
 * @param dest
 * @return
 */
int get_count(char *src, char *dest) {
    int i = 0;
    int count = 0;
    int dest_len = strlen(dest);
    do {
        if (src[i] == dest[0] && 0 == strncmp(src + i, dest, dest_len))
            count++;
    } while (src[i++] != 0);
    return count;
}

/***
 * 查询 src中出现dest字符串的个数
 * @param src
 * @param dest
 * @return
 */
int get_count2(char *src, char *dest) {
    char *p = src;
    int count = 0;
    int dest_len = strlen(dest);
    do {
        p = strstr(p, dest);
        if (p != NULL) {
            count++;
            p = p + dest_len;
        }
    } while (p != NULL);
    return count;
}

/**
 * 返回指定字符串取出首尾空格后的字符串
 * @param str
 * @return
 */
char *str_strip(char *str) {
    int start = 0;
    int end = strlen(str) == 0 ? 0 : strlen(str) - 1;
    while ((start < end) && (str[start] == ' ' || str[end] == ' ')) {
        if (str[start] == ' ') {
            start++;
        }
        if (str[end] == ' ') {
            end--;
        }
    }
    int len = end - start + 1;
    char d[len + 1];
    strncpy(d,str + start, len);
    d[len] = '\0';
    return d;
}

int main() {
    //查询 src中出现dest字符串的个数
    /* char src[] = "hdaabcdhaodabcahdaabchdoahdoaabcjdahfaabc";
     char dest[] = "abc";
     printf(" abc count = %d \n",get_count2(src,dest)) ;*/
    //返回指定字符串取出首尾空格后的字符串
    char buf[] = "    ChangTong very good     ";
    printf("%s \n", str_strip(buf));


    return 0;
}
