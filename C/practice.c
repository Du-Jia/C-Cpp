#include<stdio.h>
#include<stdlib.h>
/*����ʹ��β�ӷ���ʵ����ʽ����Ҫ�õ��ķ�����Find, Insert, Delete, FindPrevious*/ 

typedef int ElemType;
struct Node;
typedef struct Node{
	ElemType data;
	struct Node *next;
}Node, *List;

typedef  
