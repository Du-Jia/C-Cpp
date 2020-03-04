#include<iostream>

using namespace std;

int main(){
    int n = 0;

    cin >> n;

    int a1, a2, b1, b2;
    int a_num = 0;
    int b_num = 0;

    while(n--){
        cin >> a1 >> a2 >> b1 >> b2;
        if(a2 == a1 + b1 && b2 != a1 + b1){
            b_num += 1;
        }

        if(b2 == a1 + b1 && a2 != a1 + b1 ){
            a_num += 1;
        }
    }

    cout << a_num << " " << b_num << endl;
}
