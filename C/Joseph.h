//#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "CreatList.h"
void Joseph(Node *head, int n, int m)  //nΪ������mΪ���е����֣�����ͷ�ڵ�
{
	int i, j;
	Node *p, *q;
	p = head;
	for (j = 1; j <= n; j++)//���ɾ����㣬ֱ��ȫ������
	{
//		for (i = 1; i < m; i++)
//		{
//			p = p->next;        //�ҵ�Ӧ���е���
//		}
//		for(i = 1; i < m - 1; i++){
		if(j > 1) i = 0;
		else i = 1;
		for(; i < m - 1; i++){
			p = p->next;		//�ҵ�Ӧ�ó��е��˵� ǰһ���� 
		}
		printf("code: %d\n", p->next->pass);
		printf("\tnumber: %d\n", p->next->data); //��������˵����
//		p->data = p->next->data; //ɾ��p��ָ��Ľ�㣬
		m = p->next->pass;
		q = p->next;
		p->next = p->next->next;//���ӱ�ɾ���ǰ���������㣬�γ��µ�ѭ������
		free(q);   //�ͷ�ָ��q��ָ�����Ĵ洢�ռ�
	}
}
