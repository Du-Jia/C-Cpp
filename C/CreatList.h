// #pragma once
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{//����ṹ�壬������Ա����
	int data;
	int pass;			//what's pass?
	struct Node *next;
}Node;

void printAll(Node *list);

Node *CreatList(int n, int pass[])    //����һ����n���˵�ѭ������
{
	int i;
	Node *head, *p, *q;
	head = (Node*)malloc(sizeof(Node));
	head->data = 1;
	head->pass = pass[0];

	p = head;
	p->pass = pass[0];
	for (i = 2; i <= n; i++)    //����β�巨��������Ϊn�������������˳��������˳��һ��
	{
		q = (Node*)malloc(sizeof(Node));//����ռ�
		p->next = q;

		q->data = i;
		q->pass = pass[i - 1];
		p = p->next;
	}
	p->next = head;       //��β��ӹ���ѭ������
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
