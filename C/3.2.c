#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct Node{
	ElemType data;
	Node* next;
} Node;

int main(){
	Node node;

	node.data = 0;
	node.next = NULL;

	printf("Info:\nNode: 1\nData: %d\nnode.data\nNext: NULL", node.data);
	getchar();
	return 0;
}