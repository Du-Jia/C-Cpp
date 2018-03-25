## 求集合的众数和重数
1. 方法一： 暴力求解，直接遍历存储，取最大
```
#include<iostream>

using namespace std;

const int MAX_SIZE = 100;
void get_most_and_times(int set[], int n, int *most, int *times) {
	int tmp[MAX_SIZE][2];
	int i = 0, j = 0;
	
	for (; i < n; i++) {
		tmp[i][0] = set[i];
		tmp[i][1] = 0;
		for (j = 0; j < n; j++) {
			if (set[j] == tmp[i][0]) {
				tmp[i][1]++;
			}
		}
	}

	*most = 0, *times = 0;

	for (i = 0; i < n; i++) {
		if (tmp[i][1] > *times) {
			*most = tmp[i][0];
			*times = tmp[i][1];
		}
	}
}


int main() {
	int n;
	int set[MAX_SIZE];
	int i;

	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> set[i];
	}

	int most, times;

	get_most_and_times(set, n, &most, &times);

	cout << most << ' ' << times << endl;
	return 0;
}


```

2. 方法二： 先使用归并排序，在使用分治法递归求解
```
#include<iostream>
#include<climits>
#include<cstdlib>

using namespace std;
void sort(int array[]);

struct Mode{
	int mode;
	int times;
};

Mode get_mode(int set[], int low, int high);
void Merge(int array[], int tmp[], int left, int right, int right_end);
void Msort(int array[], int tmp[], int left, int right);
void Mergesort(int array[], int n);

int main(){
	int n;
	int i;

	cin >> n;
	int set[n];
	
	for(i = 0; i < n; i++){
		cin >> set[i];
	}
	
	Mergesort(set, n);
	for(i = 0 ; i < n; i++){
		cout << set[i] << ' ';
	}
/*随机数测试*/
/* 
	int set[100];
	for(n = 1; n < 100; n++){
		srand(n);
		cout << "\nN = " << n << " : "<< endl;
		cout << "\nBefore sorting:\n "<< endl;
		for(i = 0; i < n; i++){
			set[i] = rand() % 1000;
			cout << set[i] << " ";
		}
		
		Mergesort(set, n);
		
		cout << "\nAfter sorting:\n" << endl;
		for(i = 0 ; i < n; i++){
			cout << set[i] << " ";
		}
		
		Mode m = get_mode(set, 0, n-1);
		cout << "The Mode and time: \nmode: " << m.mode
		<< "\ntimes: " << m.times << endl;
//		cout << m.mode << ' ' << m.times << endl;
	}
*/

	//输入排序后的数组求解 
	Mode m = get_mode(set, 0, n-1);
	cout << "\n"<< m.mode << ' ' << m.times << endl;
	return 0;
}

//经过测试  
Mode get_mode(int set[], int left, int right){
	//传入的集合为经过排序的有序数组
	//1. 求取数组的中间值及中间值的边界
	int mid = (left + right) / 2;
	int i = mid, j = mid;

	while(set[i--] == set[mid]);
	while(set[j++] == set[mid]);
	
	//移动i, j, 使之刚好回到边界上 
	i += 2;
	j -= 2;

	//2. 计算中间值次数，与左右两端数字比较，看是否终止递归
	Mode  m = {set[mid], j - i + 1};
	if(m.times > i - left && m.times > right - j)
		return m;

	Mode m_left = get_mode(set, left, i - 1);
	Mode m_right = get_mode(set, j + 1, right);

	if(m.times >= m_left.times && m.times >= m_right.times)
		return m;
	else if(m_left.times > m.times && m_left.times > m_right.times)
		return m_left;
	else
		return m_right;
}

//get_mode_1.1
////每次返回两个参数mode,times 
//int get_mode(int set[], int low, int high, int* mode, int* times){
//	//暂存mode, times
//	int mid_times, left_times, right_times;
//	int mid_mode, left_mode, right_mode;
//	
//	//找出中间值
//	int i, j, mid = (high - low) / 2;
//	i = j = mid;
//	mid_mode = set[mid];
//	
//	//找出中间值的边界 
//	while(set[--i] == set[mid]);
//	while(set[++j] == set[mid]); 
//	
//	//计算中间值的个数，及左右数字的个数 
//	mid_times = j - i + 1;
//	left_times = i - low;
//	right_times = high - j;
//	     
//	if(mid_times >= left_times){
//		*mode = set[i]; 
//		*times = mid_times;
//		return 0;
//	}
//	if(mid_times >= right_times){
//		*mode = set[i];
//		*times = right_times;
//		return 0;
//	}		
//	
//	get_mode(set, low, i, &left_mode, &left_times);
//	get_mode(set, j, high, &right_mode, &right_times);
//	
//	*times = max(max(left_times, mid_times), max(right_times, mid_times));
//	if(mid_times == *times) *mode = mid_mode;
//	else if(left_times == *times) *mode = left_mode;
//	else *mode == right_mode;
//	
//	return 0;
//}

void Mergesort(int array[], int n){
	//采用归并排序
	int *tmp = (int*)malloc(n * sizeof(int));
	
	if(tmp != NULL){
		Msort(array, tmp, 0, n-1);
		free(tmp);
	}
	else{
		cout << "No Space! Error!" << endl;
		exit(-1);
	}
}

void Msort(int array[], int tmp[], int left, int right){
	int mid = (left + right) / 2;
	if(left < right){
		Msort(array, tmp, left, mid);
		Msort(array, tmp, mid + 1, right);
		Merge(array, tmp, left, mid + 1, right);
	} 
}

void Merge(int array[], int tmp[], int left, int right, int right_end){

	int i, left_end , num, tmp_pos;
	
	left_end = right - 1;
	tmp_pos = left;
	num = right_end - left + 1;
	
	while(left <= left_end && right <= right_end){
		if(array[left] <= array[right])
			tmp[tmp_pos++] = array[left++];
		else
		    tmp[tmp_pos++] = array[right++];
	}
	while(left <= left_end) tmp[tmp_pos++] = array[left++];
	while(right <= right_end) tmp[tmp_pos++] = array[right++];
	
	for( i =0; i < num; i++, right_end--){
		array[right_end] = tmp[right_end];
	}
}


```
