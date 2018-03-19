// #pragma once
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{//定义结构体，声明成员变量
	int data;
	int pass;			//what's pass?
	struct Node *next;
}Node;

void printAll(Node *list);

Node *CreatList(int n, int pass[])    //创建一个含n个人的循环链表
{
	int i;
	Node *head, *p, *q;
	head = (Node*)malloc(sizeof(Node));
	head->data = 1;
	head->pass = pass[0];

	p = head;
	p->pass = pass[0];
	for (i = 2; i <= n; i++)    //利用尾插法构建长度为n的链表，否则输出顺序与输入顺序不一致
	{
		q = (Node*)malloc(sizeof(Node));//分配空间
		p->next = q;

		q->data = i;
		q->pass = pass[i - 1];
		p = p->next;
	}
	p->next = head;       //首尾相接构建循环链表
	printAll(head);
	return(head);
}

//function for testing 
void printAll(Node *list){
	Node* p = list;
	while(p->next != list){
		printf("%d \n", p->pass);
		p = p->next;
	}
	printf("%d \n", p->pass);
}
