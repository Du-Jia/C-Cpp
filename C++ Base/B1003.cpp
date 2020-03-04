#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
#include<set>

using namespace std;

std::set<char> pat;

bool isRight(string &temp){
    bool res = true;
    //If pat.count(ch) == 0, then ch is not an element of pat.
    int len = temp.size();

    for(int i = 0; i < len; i++){
        if(pat.count(temp[i]) == 0 && temp[i] != ''){
            res = false;
            break;
        }
    }


    if(res){//There is not other character in the string.
        //If there is "PAT" in the string, then return true.
        int index = 0;
        string p = "PAT";
        for(int i = 0; i < len; i++){
            bool flag = true;
            index = i;
            for(int j = 0; j < p.size();){
                if(temp[index] == p[j]){
                    index++;
                    j++;
                }
                else{
                    break;
                    flag = false;
                }
            }
            if(flag){
                break;
            }
        }

        if(flag){
            for(int i = 0; i < index; i++){

            }
        }
    }


    return res;
}

int main(){
    int n;
    cin >> n;

    pat.insert('P');
    pat.insert('A');
    pat.insert('T');



    while(n--){
        string temp;
        cin >> temp;


    }

    return 0;
}
