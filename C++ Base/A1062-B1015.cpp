#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

struct Student{
    long id;
    int dei;
    int cai;
    int sum;
    int flag;
};

void div_class(Student &s, int h, int l){
    if(s.dei < l || s.cai < l){
        s.flag = 5;
    }
    else if(s.dei >= h && s.cai >= h){
        s.flag = 1;
    }
    else if(s.dei >=h && s.cai < h){
        s.flag = 2;
    }
    else if(s.dei >= s.cai){
        s.flag = 3;
    }
    else{
        s.flag = 4;
    }
}

/*
if s1 > s2 return true;
if s1 < s2 return false;
*/
bool compare(Student &s1, Student &s2){
    int flag = false;
    if(s1.flag != s2.flag) return s1.flag < s2.flag;
    else if(s1.sum != s2.sum) return s1.sum > s2.sum;
    else if(s1.dei != s2.dei) return s1.dei > s2.dei;
    else return s1.id < s2.id;

    return flag;
}

//冒泡排序 会超时
//void sort(Student students[], int m){
//    //基于比较的排序,这里最好用交换
//    for(int i = 0; i < m; i++){
//        for(int j = 0; j < m - i - 1; j++){
//            if(compare(students[j], students[j+1]) == -1){
//                //降序排列
//                Student s;
//                s.cai = students[j].cai;
//                s.dei = students[j].dei;
//                s.sum = students[j].sum;
//                s.flag = students[j].flag;
//                s.id = students[j].id;
//                students[j].cai = students[j+1].cai;
//                students[j].dei = students[j+1].dei;
//                students[j].sum = students[j+1].sum;
//                students[j].id = students[j+1].id;
//                students[j].flag = students[j+1].flag;
//                students[j+1] = s;
//            }
//        }
//    }
//}

void quick_sort(Student students[], int start, int ends){
    if(start < ends){
        int low = start, high = ends;
        Student tmp = students[low];
        while(low < high){//把数组分成两个部分：应该排在tmp前面的和后面的
            while(low < high && compare(tmp, students[high]) == true){
                //如果tudents[high]排在tmo的后面
                high--;
            }
            students[low] = students[high];
            while(low < high && compare(tmp, students[low]) == false){
                low++;
            }
            students[high] = students[low];
        }
        students[low] = tmp;
        quick_sort(students, start, low-1);
        quick_sort(students, low+1, ends);
    }
}


int main(){
    int m, h, l;
    int n = 0;
    Student students[100000];
    cin >> m >> l >> h;

    for(int i = 0; i < m; i++){
        cin >> students[i].id;
        cin >> students[i].dei;
        cin >> students[i].cai;
        students[i].sum = students[i].cai + students[i].dei;
        if(students[i].dei < l || students[i].cai < l){
            students[i].flag = 5;
        }
        else if(students[i].dei >= h && students[i].cai >= h){
            students[i].flag = 1;
        }
        else if(students[i].dei >=h && students[i].cai < h){
            students[i].flag = 2;
        }
        else if(students[i].dei >= students[i].cai){
            students[i].flag = 3;
        }
        else{
            students[i].flag = 4;
        }

        if(students[i].flag != 5)
            n++;
    }

    cout << n << endl;

//    sort(students, students + m, compare);
    quick_sort(students, 0, m-1);

    for(int i = 0; i < n; i++){
        cout << students[i].id << " "
        << students[i].dei << " "
        << students[i].cai << endl;
    }

    return 0;
}
