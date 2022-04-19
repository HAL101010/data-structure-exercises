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
	printf("1、头插法建表\t2、尾插法建表\n"); 
	scanf("%d",&m);
	LinkList L=0,LB=0;
	Node *p=0;
	if(m==1) L=CreatFromHead();
	else L=CreatFromTail();
	PutList(L);
	printf("1、排序\t2、逆置\t3、链表长度\n4、插入新元素\t5、删除元素\t6、按值查找\t7、按位置查找\n8、合并有序链表\n");
	scanf("%d",&m);
	switch(m)
	{
		case 1:SelectSort(L);PutList(L);break;
		case 2:ReverseList2(L);PutList(L);break;
		case 3:printf("链表的长度为%d\n",ListLength(L));break;
		case 4:
			printf("请输入要插入元素及插入位置：\n");
			scanf("%d%d",&a,&b);
			InsList(L,b,a);
			PutList(L);
			break;
		case 5:
			printf("请输入要删除元素的位置：\n");
			scanf("%d",&a);
			DelList(L,a,&e);
			PutList(L);
			break;
		case 6:
			printf("请输入待查找元素的值：\n");
			scanf("%d",&a);
			p=GetData1(L,a);
			printf("该元素为%d\n",p->data);
			break;
		case 7:
			printf("请输入待查找位置：\n");
			scanf("%d",&a);
			p=GetData2(L,a);
			printf("该元素为%d\n",p->data);
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
