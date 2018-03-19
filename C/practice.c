#include<stdio.h>
#include<stdlib.h>
/*尝试使用尾接法来实现链式表，主要用到的方法有Find, Insert, Delete, FindPrevious*/ 

typedef int ElemType;
struct Node;
typedef struct Node{
	ElemType data;
	struct Node *next;
}Node, *List;

typedef  
