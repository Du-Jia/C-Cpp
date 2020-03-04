#include<stdio.h>

// Éú³ÉPa
long A_to_PA(long a, long da){
    long pa = 0;
    while(a > 0){
        if( a%10 == da){
            pa = pa * 10 + da;
        }//end if
        a /= 10;
    }

    return pa;
}

int main(){
    long a = 0, da = 0, b = 0, db = 0;
    long pa = 0, pb = 0;

    scanf("%ld%ld%ld%ld", &a, &da, &b, &db);

    pa = A_to_PA(a, da);
    pb = A_to_PA(b, db);

    printf("%ld\n", pa + pb);

    return 0;
}
