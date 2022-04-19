#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "SeqList.h"

void InitList(SeqList *L);//��L��ʼ��Ϊ�ձ�  
int ListLength(SeqList L);//���LΪ�ձ��򷵻�0�����򷵻ر���Ԫ�صĸ��� 
void SetList(SeqList *L);//˳���ĸ�ֵ,�Ի��з���������־(�˴�Ĭ������Ϊ��������)
void PutList(SeqList L);//˳��������и�Ԫ�ص�ֵ(�˴�Ĭ��Ϊ��������) 
ElemType GetData(SeqList L,int i);//˳�����Ų��ң��������� 
int Locate(SeqList L,ElemType e);//˳������ݲ��ң�����˳��ֵ 
int InsList(SeqList *L,int i,ElemType e);//��L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ���+1
int DelList(SeqList *L,int i,ElemType *e);//ɾ��L�ĵ�i��Ԫ�أ�����e������ֵ��L�ĳ���-1 
void ReverseList(SeqList *L);//��˳������� 
void InsSort(SeqList *L);//ֱ�Ӳ�������
void BubbleSort(SeqList *L);//ð������
void SelectSort(SeqList *L);//��ѡ������
void mergeList(SeqList *LA,SeqList *LB,SeqList *LC);//���Ա�ĺϲ����� (�����������Ա�)

//�������� 
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
	printf("Ҫ����˳�����Ԫ�أ��밴1\n");
	printf("Ҫ��˳����в�����Ԫ�أ��밴2\n");
	printf("Ҫɾ��˳�����Ԫ�أ��밴3\n");
	printf("Ҫ��˳������ã��밴4\n");
	printf("Ҫ��˳�����д�С���������밴5\n");
	scanf("%d",&i);
	switch(i)
	{
		case 1:
			{
				printf("����Ų��ң��밴1;�����ݲ����ڣ��밴2\n");
				scanf("%d",&i);
				if(i==1)
				{
					printf("������Ҫ���ҵ�Ԫ����ţ�\n");
					scanf("%d",&k);
					printf("��Ԫ��Ϊ%d\n",GetData((*L),k));
				}
				else if(i==2)
				{
					printf("������Ҫ���ҵ�Ԫ�����ݣ�\n");
					scanf("%d",&k);
					printf("��Ԫ�����Ϊ%d",Locate((*L),k));
				}
				break;
			}
		case 2:
			{
				printf("������Ҫ�����Ԫ�أ�\n");
				scanf("%d",&k); 
				printf("������Ҫ�����λ�ã�\n"); 
				scanf("%d",&i); 
				InsList(L,i,k);
				PutList((*L));
				break;
			}
		case 3:
			{
				ElemType e;
				printf("������Ҫɾ��Ԫ�ص�λ�ã�\n");
				scanf("%d",&i);
				DelList(L,i,&e);
				PutList((*L));
				printf("ɾ����Ԫ��Ϊ%d\n",e);
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
				printf("1:ð������\t2:ֱ�Ӳ�������\t3:��ѡ������\n");
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
	InitList(p);//���Ա�ĳ�ʼ�� 
	InitList(q);
	//list1.elem=(ElemType *)malloc(MAXSIZE*sizeof(ElemType));//��̬���ȵ�˳�����
		
	printf("ʹ�ò���������������1;�Զ������Ա�Ԫ�أ��밴2\n");
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
	
	printf("Ҫ���򲢺ϲ�����˳����밴1��Ҫ���е���˳���������밴2\n");
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
		printf("���в�������һ��˳����н��У����Ա�1���в���������1�����Ա�2���в���������2\n");
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
	//free(list1.elem);//��̬����˳�������� 
} 
