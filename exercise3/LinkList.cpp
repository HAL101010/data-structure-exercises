#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "LinkList.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{
	int m=0;
	int a,b;
	ElemType e;
	printf("1��ͷ�巨����\t2��β�巨����\n"); 
	scanf("%d",&m);
	LinkList L=0,LB=0;
	Node *p=0;
	if(m==1) L=CreatFromHead();
	else L=CreatFromTail();
	PutList(L);
	printf("1������\t2������\t3��������\n4��������Ԫ��\t5��ɾ��Ԫ��\t6����ֵ����\t7����λ�ò���\n8���ϲ���������\n");
	scanf("%d",&m);
	switch(m)
	{
		case 1:SelectSort(L);PutList(L);break;
		case 2:ReverseList2(L);PutList(L);break;
		case 3:printf("����ĳ���Ϊ%d\n",ListLength(L));break;
		case 4:
			printf("������Ҫ����Ԫ�ؼ�����λ�ã�\n");
			scanf("%d%d",&a,&b);
			InsList(L,b,a);
			PutList(L);
			break;
		case 5:
			printf("������Ҫɾ��Ԫ�ص�λ�ã�\n");
			scanf("%d",&a);
			DelList(L,a,&e);
			PutList(L);
			break;
		case 6:
			printf("�����������Ԫ�ص�ֵ��\n");
			scanf("%d",&a);
			p=GetData1(L,a);
			printf("��Ԫ��Ϊ%d\n",p->data);
			break;
		case 7:
			printf("�����������λ�ã�\n");
			scanf("%d",&a);
			p=GetData2(L,a);
			printf("��Ԫ��Ϊ%d\n",p->data);
			break;
		case 8:
			LB=CreatFromTail();
			SelectSort(L);
			SelectSort(LB);
			MergeLinkList(L,LB);
			PutList(L);
			break;
	}
	return 0;
}
