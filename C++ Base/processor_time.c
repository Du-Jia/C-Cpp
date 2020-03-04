#include<stdio.h>

#define CLK_TCK 100

int main(){
    int start, end;

    scanf("%d%d", &start, &end);

    int t = end - start;

    if(t % CLK_TCK >= 50) t = t / CLK_TCK + 1;
    else t = t / CLK_TCK;

    int h = t / 3600;
    t %= 3600;
    int m = t / 60;
    t %= 60;
    int s = t;

    printf("%02d:%02d:%02d\n", h, m, s);
}
