#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(char* str1, char* str2) {
    int count = 0;
    int i = 0, j = 0;
    while (i < strlen(str1) && count != strlen(str2)) { // 讀完str1或是有找到相同子字串就跳出
        //printf("%d %d\n", i, j);
        count = 0;
        if (str1[i] == str2[j]) {
            for (int temp = i, j = 0; j < strlen(str2); j++, temp++) {
                if (str1[temp] == str2[j]) count++;
                else break;
            }
        }
        if (count == strlen(str2)) break;
        i++;
    }
    if (count == strlen(str2)) return (i - j); // 代表有，直接回傳位址
    else return -1; // 代表沒有
}
void replace(char* str1, char* str2, char* str3, int loc) {
    // 先刪掉
    char new[110] = { 0 };
    char temp[110] = { 0 };
    int times = loc;
    for (int i = 0; i < loc; i++) {
        temp[i] = str1[i];
    }
    for (int i = loc + strlen(str2), j = loc; i < strlen(str1); i++, j++) {
        temp[j] = str1[i];
    }
    for (int i = 0; i < strlen(temp); i++) {
        str1[i] = temp[i];
    }
    str1[strlen(temp)] = '\0';
    //printf("str1 = %s\n", str1);
    // 插入
    for (int i = 0; i < loc; i++) {
        new[i] = str1[i];
    }
    for (int i = loc, j = 0; j < strlen(str3); i++, j++) {
        new[i] = str3[j];
    }
    for (int i = loc + strlen(str3), j = loc; j < strlen(str1); j++, i++) {
        new[i] = str1[j];
    }
    for (int i = 0; i < strlen(new); i++) {
        str1[i] = new[i];
    }
    str1[strlen(new)] = '\0';
    //puts(str1);
}
int main()
{
    char original[110], target[110], replacement[110];
    gets(original);
    gets(target);
    gets(replacement);
    //printf("%d\n",compare(original, target));
    int location = compare(original, target);
    while (location != -1) {
        //printf("location = %d\n", location);
        replace(original, target, replacement, location);
        //printf("location = %d, original = %s\n", location, original);
        location = compare(original, target);
    }
    puts(original);

    return 0;
}

// 
//
/*
Hello WorldW!World!
World
C Programming
*/
/*
Hello C Programming!World!
World
C Programming
*/
//
//
