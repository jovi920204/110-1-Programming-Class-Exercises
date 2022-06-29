#pragma warning(disable : 4996)
#pragma warning(disable : 6031)
#include <stdio.h>
#include <stdlib.h>                 
#include <string.h>
int main(void)
{
    int t;
    scanf("%d\n", &t);
    for (int i = 1; i <= t; i++) {
        int n = 0;
        char sentences[110][1100];
        while (1) {
            gets(sentences[n]);
            if (strlen(sentences[n]) == 0)
                break;
            n++;
        }
        printf("Case #%d:\n", i);
        for (int j = 0; j < n; j++) {
            int no = 1;
            int front = 0;
            int point = 0;
            int flag = 0; // 1代表這一個word輸出過了
            while (point < strlen(sentences[j])) {
                if (sentences[j][point] == ' ') {
                    flag = 0;
                    front = 0;
                }
                else {
                    front++;
                }
                if (front == no && flag == 0) {
                    printf("%c", sentences[j][point]);
                    no++;
                    flag = 1;
                }
                
                point++;
                //printf("point = %d, front = %d, no = %d\n", point, front, no);
            }
            printf("\n");
            //printf("point = %d, front = %d, no = %d\n", point, front, no);
        }
        printf("\n");
    }
    
    return 0;
}

/*
2

Hey          good      lawyer
as I previously previewed
yam does a soup

Hey             good lawyer
as Ir previously previewed
yam does a soup
as Ir previously previewed
yam does a soup

First I give money to Teresa
after I inform dad of
your horrible soup
*/