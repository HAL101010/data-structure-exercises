#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "SeqList.h"

void InitList(SeqList *L);//将L初始化为空表  
int ListLength(SeqList L);//如果L为空表则返回0，否则返回表中元素的个数 
void SetList(SeqList *L);//顺序表的赋值,以换行符做结束标志(此处默认输入为整型数据)
void PutList(SeqList L);//顺序输出表中各元素的值(此处默认为整型数据) 
ElemType GetData(SeqList L,int i);//顺序表按序号查找，返回内容 
int Locate(SeqList L,ElemType e);//顺序表按内容查找，返回顺序值 
int InsList(SeqList *L,int i,ElemType e);//在L中第i个位置之前插入新的数据元素e，L的长度+1
int DelList(SeqList *L,int i,ElemType *e);//删除L的第i个元素，并用e返回其值，L的长度-1 
void ReverseList(SeqList *L);//将顺序表逆置 
void InsSort(SeqList *L);//直接插入排序
void BubbleSort(SeqList *L);//冒泡排序
void SelectSort(SeqList *L);//简单选择排序
void mergeList(SeqList *LA,SeqList *LB,SeqList *LC);//线性表的合并运算 (两个有序线性表)

//测试用例 
void ceshi(SeqList *L)
{
	for(int i=0;i<=10;i++)
	{
		L->elem[i]=10-i;
	}
	L->last=10;
}

void choose2(SeqList *L)
{
	int i,k;
	printf("要查找顺序表中元素，请按1\n");
	printf("要在顺序表中插入新元素，请按2\n");
	printf("要删除顺序表中元素，请按3\n");
	printf("要将顺序表逆置，请按4\n");
	printf("要将顺序表进行从小到大排序，请按5\n");
	scanf("%d",&i);
	switch(i)
	{
		case 1:
			{
				printf("按序号查找，请按1;按内容查找在，请按2\n");
				scanf("%d",&i);
				if(i==1)
				{
					printf("请输入要查找的元素序号：\n");
					scanf("%d",&k);
					printf("该元素为%d\n",GetData((*L),k));
				}
				else if(i==2)
				{
					printf("请输入要查找的元素内容：\n");
					scanf("%d",&k);
					printf("该元素序号为%d",Locate((*L),k));
				}
				break;
			}
		case 2:
			{
				printf("请输入要插入的元素：\n");
				scanf("%d",&k); 
				printf("请输入要插入的位置：\n"); 
				scanf("%d",&i); 
				InsList(L,i,k);
				PutList((*L));
				break;
			}
		case 3:
			{
				ElemType e;
				printf("请输入要删除元素的位置：\n");
				scanf("%d",&i);
				DelList(L,i,&e);
				PutList((*L));
				printf("删除的元素为%d\n",e);
				break;
			}
		case 4:
			{
				ReverseList(L);
				PutList((*L));
				break;
			}
		case 5:
			{
				printf("1:冒泡排序\t2:直接插入排序\t3:简单选择排序\n");
				scanf("%d",&i);
				if(i==1)
				{
					BubbleSort(L);
					PutList((*L));
				}
				else if(i==2)
				{
					InsSort(L);
					PutList((*L));
				}
				else if(i==3)
				{
					SelectSort(L);
					PutList((*L));
				}
				break;
			}
	}
}

int main()
{
	int i;
	char str[10];
	SeqList list1,*p=&list1;
	SeqList list2,*q=&list2;
	InitList(p);//线性表的初始化 
	InitList(q);
	//list1.elem=(ElemType *)malloc(MAXSIZE*sizeof(ElemType));//动态长度的顺序表创建
		
	printf("使用测试用例，请输入1;自定义线性表元素，请按2\n");
	scanf("%d",&i);
	if(i==1)
	{
		ceshi(p);
		ceshi(q);
		PutList(list1);
		PutList(list2);
	}
	else if(i==2)
	{
		SetList(p);
		PutList(list1);
		SetList(q);
		PutList(list2);
	}
	
	printf("要排序并合并两个顺序表，请按1，要进行单个顺序表操作，请按2\n");
	scanf("%d",&i);
	if(i==1)
	{
		InsSort(p); 
		InsSort(q);
		SeqList list3,*r=&list3;
		mergeList(p,q,r);
		PutList(list3);
	}
	else if(i==2)
	{
		printf("下列操作将在一个顺序表中进行，若对表1进行操作请输入1，若对表2进行操作请输入2\n");
		scanf("%d",&i);
		if(i==1)
		{
			choose2(p);
		}
		else if(i==2)
		{
			choose2(q);
		}
	}
	
	
	return 0;
	//free(list1.elem);//动态长度顺序表的销毁 
} 
