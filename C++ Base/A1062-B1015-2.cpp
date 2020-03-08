#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

struct Stu{
    long id;
    int cai, de, sum;
};

bool compare(Stu &s1, Stu &s2){
    int flag = false;
    if(s1.sum != s2.sum) return s1.sum > s2.sum;
    else if(s1.de != s2.de) return s1.de > s2.de;
    else return s1.id < s2.id;

    return flag;
}

int main(){
    int m, l, h;
    vector<Stu> stus[4];

    cin >> m >> l >> h;

    int n = 0;

    while(m--){
        Stu student;
        scanf("%ld %d %d", &student.id, &student.de, &student.cai);
//        cin >> student.id;
//        cin >> student.de;
//        cin >> student.cai;
        student.sum = student.de + student.cai;

        if(student.de < l || student.cai < l){
            continue;
        }
        else if(student.de >= h && student.cai >= h){
            stus[0].push_back(student);
            n++;
        }
        else if(student.de >= h && student.cai <h){
            stus[1].push_back(student);
            n++;
        }
        else{
            if(student.de >= student.cai)
                stus[2].push_back(student);
            else{
                stus[3].push_back(student);
            }
            n++;
        }
    }

    cout << n << endl;

    for(int i = 0; i < 4; i++){
        sort(stus[i].begin(), stus[i].end(), compare);
    }

    for( int i = 0; i < 4; i++){
        for(int j = 0; j < stus[i].size(); j++){
            printf("%ld %d %d\n",  stus[i][j].id, stus[i][j].de, stus[i][j].cai);
//            cout << stus[i][j].id << " "
//            << stus[i][j].de << " "
//            << stus[i][j].cai << endl;
        }
    }


    return 0;
}
