//#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "CreatList.h"
void Joseph(Node *head, int n, int m)  //n为总人数m为出列的数字，定义头节点
{
	int i, j;
	Node *p, *q;
	p = head;
	for (j = 1; j <= n; j++)//逐个删除结点，直至全部出列
	{
//		for (i = 1; i < m; i++)
//		{
//			p = p->next;        //找到应出列的人
//		}
//		for(i = 1; i < m - 1; i++){
		if(j > 1) i = 0;
		else i = 1;
		for(; i < m - 1; i++){
			p = p->next;		//找到应该出列的人的 前一个人 
		}
		printf("code: %d\n", p->next->pass);
		printf("\tnumber: %d\n", p->next->data); //输出出列人的序号
//		p->data = p->next->data; //删除p所指向的结点，
		m = p->next->pass;
		q = p->next;
		p->next = p->next->next;//链接被删结点前后的两个结点，形成新的循环链表
		free(q);   //释放指针q所指变量的存储空间
	}
}
