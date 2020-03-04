#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
using namespace std;

int main(){
    int n = 0;
    int a1 = 0, a2 = 0, a3 = 0, a5 = 0;
    int a1_cnt = 0, a2_cnt = 0, a3_cnt = 0, a4_cnt = 0, a5_cnt = 0;
    int a4 = 0;
    int tmp = 0;
    int flag = -1;

    cin >> n;

    while(n--){
        cin >> tmp;

        if(tmp % 5 == 0 && tmp % 2 == 0){
            a1 += tmp;
            a1_cnt++;
        }
        if(tmp % 5 == 1){
            flag *= -1;
            a2 += flag * tmp;
            a2_cnt ++;
        }
        if(tmp % 5 == 2){
            a3++;
            a3_cnt++;
        }
        if(tmp % 5 == 3){
            a4 += tmp;
            a4_cnt ++;
        }
        if(tmp % 5 == 4){
            if(a5 < tmp){
                a5 = tmp;
                a5_cnt++;
            }
        }

    }

    if(a1_cnt != 0){
        cout << a1 << " ";
    }
    else{
        cout << "N ";
    }

    if(a2_cnt != 0){
        cout << a2 << " ";
    }
    else{
        cout << "N ";
    }

    if(a3_cnt != 0){
        cout << a3 << " ";
    }
    else{
        cout << "N ";
    }

    if(a4_cnt == 0){
        cout << "N ";
    }
    else{
        printf("%.1f ", (double)a4/a4_cnt);

    }

    if(a5_cnt != 0){
        cout << a5 << endl;
    }
    else{
        cout << "N" << endl;
    }

    return 0;
}
