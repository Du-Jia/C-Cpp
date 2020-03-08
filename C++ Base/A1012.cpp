#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cstring>
#include<string>
#include<vector>

using namespace std;

enum Subject {A, C, M, E};

char subname[] = {'A', 'C', 'M', 'E'};

struct Stu{
    long id;
    int c, m, e, a;
    int best_rank[4];
    Subject best_sub;
};

vector<Stu> ranks;

bool cmpc(Stu a, Stu b){
    return a.c > b.c;
}

bool cmpm(Stu a, Stu b){
    return a.m > b.m;
}

bool cmpe(Stu a, Stu b){
    return a.e > b.e;
}

bool cmpa(Stu a, Stu b){
    return a.a > b.a;
}

bool cmpid(Stu a, Stu b){
    return a.id < b.id;
}

//return the index of the student, if there is the student.
//return -1, if the student is not the student.
int Stu_Search(long sid, vector<Stu> &stus, int low, int high){
    int mid = (low + high) / 2;

    if(low >= high && stus[mid].id != sid) return -1;
    //No the student

    if(stus[mid].id == sid) return mid;
    else if(stus[mid].id < sid){
        low = mid + 1;
        return Stu_Search(sid, stus, low, high);
    }
    else{
        high = mid - 1;
        return Stu_Search(sid, stus, low, high);
    }
}

int main(){
    int n, m;

    scanf("%d %d", &n, &m);

    while(n--){
        Stu temp;
        scanf("%ld %d %d %d", &temp.id, &temp.c, &temp.m, &temp.e);
        temp.a = (temp.c + temp.m + temp.e);
        ranks.push_back(temp);
    }

    //Test Code:
    /*
    for(int i = 0; i < ranks.size(); i++){
        cout << "Test: " << ranks[i].id << endl;
    }
    */

    //In default, the priority is : A > C > M > E, if the ranks are same.
    //For A:
    int r = 0, score = 301;
    sort(ranks.begin(), ranks.end(), cmpa);
    for(int i = 0; i < ranks.size(); i++){
        if(ranks[i].a != score) r = i;

        score = ranks[i].a;

        //init best rank
        ranks[i].best_rank[A] = r;
        ranks[i].best_sub = A;
    }

    for(int i = 0; i < ranks.size(); i++){
        cout << "Test Rank: " << ranks[i].best_rank << endl;
    }

    r = 0, score = 101;
    sort(ranks.begin(), ranks.end(), cmpc);

    for(int i = 0; i < ranks.size(); i++){
        //update best rank
        //如果当前学科的排名高于上一学科
        if(ranks[i].c != score) r = i;

        score = ranks[i].c;

        if(ranks[i].best_rank[C] > r){
            ranks[i].best_rank[C] = r;
            ranks[i].best_sub = C;
        }
    }

    r = 0, score = 101;
    sort(ranks.begin(), ranks.end(), cmpm);

    for(int i = 0; i < ranks.size(); i++){
        //update best rank
        //如果当前学科的排名高于上一学科
        if(ranks[i].m != score) r = i;
        score = ranks[i].m;

        if(ranks[i].best_rank[M] > r){
            ranks[i].best_rank[M] = r;
            ranks[i].best_sub = M;
        }
    }

    r = 0, score = 101;
    sort(ranks.begin(), ranks.end(), cmpe);

    for(int i = 0; i < ranks.size(); i++){
        //update best rank
        //如果当前学科的排名高于上一学科
        if(ranks[i].e != score) r = i;
        score = ranks[i].e;

        if(ranks[i].best_rank[E] > r){
            ranks[i].best_rank[E] = r;
            ranks[i].best_sub = E;
        }
    }

    //Now, we get all the best ranks of students and the name of the subject
    // Search record; Binary Search.
    sort(ranks.begin(), ranks.end(), cmpid);

    while(m--){
        int sid;
        scanf("%ld", &sid);

        int index = Stu_Search(sid, ranks, 0, ranks.size() - 1);

        if(index != -1){
            int k = 0;
            for(int i = 0; i < 4;i++){
                if(ranks[index].best_rank[i] < ranks[index].best_rank[k]){
                    k = i;
                }
            }
            printf("%ld %c\n", ranks[index].id, subname[k]);
        }
        else{
            printf("N/A\n");
        }
    }


    return 0;
}

/*
Answer:
*/

/*
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
const int maxn=2010;
struct student{
    int id;
    int grade[4];
};
char course[4]={'A','C','M','E'};
student stu[maxn];
int RANK[10000000][4]={0};
int now;//当前第几门课
bool cmp(student a,student b){
    return a.grade[now]>b.grade[now];
}
int main(){
    int N,M;
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++){
        scanf("%d%d%d%d",&stu[i].id,&stu[i].grade[1],&stu[i].grade[2],&stu[i].grade[3]);
        stu[i].grade[0]=round((stu[i].grade[1]+stu[i].grade[2]+stu[i].grade[3])/3.0)+0.5;
    }
    for(now=0;now<4;now++){
        sort(stu,stu+N,cmp);
        RANK[stu[0].id][now]=1;
        for(int i=1;i<N;i++){
            if(stu[i].grade[now]==stu[i-1].grade[now]){
                RANK[stu[i].id][now]=RANK[stu[i-1].id][now];
            }else{
                RANK[stu[i].id][now]=i+1;
            }
        }
    }
    int query;
    for(int i=0;i<M;i++){
        scanf("%d",&query);
        if(RANK[query][0]==0){
            printf("N/A\n");
        }else{
            int k=0;
            for(int j=0;j<4;j++){
                if(RANK[query][j]<RANK[query][k]){
                    k=j;
                }
            }
            printf("%d %c\n",RANK[query][k],course[k]);
        }
    }
    system("pause");
    return 0;

*/
