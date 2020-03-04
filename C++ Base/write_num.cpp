#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

void print_pinyin(int n){
    switch(n){
        case 0: cout << "ling"; break;
        case 1: cout << "yi"; break;
        case 2: cout << "er"; break;
        case 3: cout << "san"; break;
        case 4: cout << "si"; break;
        case 5: cout << "wu"; break;
        case 6: cout << "liu"; break;
        case 7: cout << "qi"; break;
        case 8: cout << "ba"; break;
        case 9: cout << "jiu"; break;
        default: break;
    }
}

int reverse_num(int n){
    int temp;
    int res = 0;
    while(n > 0){
        temp = n % 10;
        n /= 10;
        res = res * 10 + temp;
    }

    return res;
}

int main(){
    int sum = 0;
    char temp[100];
    scanf("%s", temp);
    int len = strlen(temp);
    while(len--){
        sum += temp[len] - '0';
    }
    char res[100];
    snprintf(res, sizeof(res), "%d", sum);

    len = strlen(res);

    int i = 0;

    while(len--){
        print_pinyin(res[i++] - '0');
        if(len >= 1) printf(" ");
    }
    printf("\n");
}
