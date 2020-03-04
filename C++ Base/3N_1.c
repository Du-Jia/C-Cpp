#include<stdio.h>

int main(){
    int n = 0;
    scanf("%d", &n);

    int step = 0;
    while(n > 1){
        if( n % 2 == 0){
            step++;
            n /= 2;
        }
        else{
            step++;
            n = (3*n+1)/2;
        }
    }
    printf("%d\n", step);
}
