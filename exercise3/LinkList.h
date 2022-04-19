#ifndef __LINKLIST_H__
#define __LINKLIST_H__
#include <stdio.h>
#include <malloc.h>
typedef int ElemType;

typedef struct Node
{
	ElemType data;
	struct Node *next;
}Node,*LinkList;

void InitList(LinkList *L){//��ʼ��һ����ͷ���Ŀ�����
	*L=(LinkList)malloc(sizeof(Node));
	(*L)->next=NULL;
}

LinkList CreatFromHead(){//ͷ�巨����,����ͷָ�� 
	LinkList L=(LinkList)malloc(sizeof(Node));
	L->next=NULL;
	Node *s=0;//ָ��������н���ָ��(ָ����) 
	ElemType c;//������ 
	printf("����������Ԫ�أ�\n");
	do
	{
		scanf("%d",&c);//�˴����յ����ݸ��ݶ����������ѡ�� 
		s=(Node*)malloc(sizeof(Node));//���޸ģ��������ڴ�ʧ��ʱӦ�ñ��� 
		s->data=(ElemType)c;
		s->next=L->next;
		L->next=s;
	}while(getchar()!='\n');//ѭ������ 
	return L;
}

LinkList CreatFromTail(){//β�巨��������ͷָ�� 
	LinkList L=(LinkList)malloc(sizeof(Node));
	Node *r=0,*s=0;//rָ������Ľ�β 
	ElemType c;//������ 
	L->next=NULL;
	r=L;
	printf("����������Ԫ�أ�\n");
	do
	{
		scanf("%d",&c);
		s=(Node*)malloc(sizeof(Node));
		s->data=(ElemType)c;
		r->next=s;
		r=s;
	}while(getchar()!='\n');
	r->next=NULL;//β�巨����ע�����Ҫ�޸ı�β 
	return L;
}

int ListLength(LinkList L){//������ĳ��ȣ���������ĳ��� 
	Node *p=L->next;//pָ����Ԫ�ڵ� 
	int count=0;
	while(p!=NULL)
	{
		count++;
		p=p->next;
	}
	return count;
}

Node* GetData1(LinkList L,ElemType e){//��Ԫ�ز��ң�����ָ���Ԫ�ؽ���ָ�� 
	Node *p=L->next;
	while(p)
	{
		if(p->data==e)
		{
			return p;
		}
		else p=p->next;
	}
	printf("δ�ҵ���Ԫ�أ�\n");
	return 0;
}

LinkList GetData2(LinkList L,int i){//��Ԫ��λ�ò��ң�����ָ���Ԫ�ص�ָ��
	Node *p=L->next;//����Ԫ�ڵ㿪ʼ���� 
	int count=1;
	while(p!=NULL&&count!=i)
	{
		p=p->next;
		count++;
	}
	if(count==i)
	{
		return p;
	}
	else
	{
		printf("Ԫ��λ��Խ�磡\n");
		return 0;
	}
}

int InsList(LinkList L,int i,ElemType e){//��L�е�i��λ��֮ǰ�����µ�����Ԫ��e(�����������Ԫ�����޸�����ָ����)
	Node *pre=L,*p=0;//pre����pǰһ��Ԫ�ؽ�� 
	for(int j=1;j<i;j++)
	{
		pre=pre->next;
	}
	if(i<=0||pre==NULL)
	{
		printf("����λ�ò��Ϸ���\n");//��ɾ��������ͬ����ʹpre����һλû��Ԫ��Ҳ���Խ��в��� 
		return 0;
	}
	else
	{
		Node *s=(Node *)malloc(sizeof(Node));
		p=pre->next;
		s->data=e;
		s->next=p;
		pre->next=s;
	}
	return 1;
} 

int DelList(LinkList L,int i,ElemType *e){//ɾ��L�ĵ�i��Ԫ�أ�����e������ֵ
	Node *pre=L,*p=0;//p�����ͷŴ�ɾ���ڵ㣬pre�����޸ı�ɾ��Ԫ�ص�ǰһ���ڵ㣬pre��ͷ��㿪ʼ���� 
	for(int j=1;j<i;j++)
	{
		pre=pre->next;
	}
	if(pre->next==NULL)
	{
		printf("ɾ��λ�ò��Ϸ���\n");//��ɾ��Ԫ����pre���һ��Ԫ�أ�����Ҫ�ж�pre->next�Ƿ���� 
		return 0;
	}
	else
	{
		p=pre->next;
		*e=p->data;
		pre->next=p->next;
		free(p);
	}
	return 1;
}

void PutList(LinkList L){//˳�����������Ԫ�� 
	Node *p=L->next;
	printf("������Ԫ�أ�\n");
	while(p)
	{
		printf("%d\t",p->data);
		p=p->next;
	}
	printf("\n");
}

void SelectSort(LinkList L){//������ļ�ѡ������
	Node *p=L->next,*s=p,*t=p,*q=p;//pΪ�������������ָ��(Ҳ��ָ��Ҫ����λ�õ�ָ��)��qΪ�ڲ�ѭ��ָ�룬tΪָ����СԪ�ص�ָ�� 
	ElemType temp,min;
	while(p->next!=NULL)//���ѭ�������������� 
	{
		min=p->data;
		t=p;
		while(q!=NULL)//�ڲ�ѭ���ҵ���С���� 
		{
			if(q->data<min)
			{
				min=q->data;
				t=q;//tָ����СԪ�ص�λ�� 
			}
			q=q->next;
		}
		if(p!=t)//�������ָ��ָ��ͬ�ĵط��򽻻�����ָ���������ֵ 
		{
			temp=p->data;
			p->data=t->data;
			t->data=temp;
		}
		p=p->next;
		q=p;
	}
}	

LinkList ReverseList(LinkList L){//ʵ�ִ�ͷ�������������(������ת��),����ͷָ�� 
	ElemType temp;
	Node *p=L,*s=p->next,*r;
	p->next=NULL;
	while(s!=NULL)
	{
		temp=s->data;
		p->data=temp;
		r=s->next;
		s->next=p;
		p=s;
		s=r;
	}
	return p;
}

void ReverseList2(LinkList L){//��ͷ�������������(�͵�����) 
	Node *p=L->next,*q=0;//sΪ�������㣬qΪ�����������һ��� 
	L->next=NULL;//���õ�������Ϊ�ձ� 
	while(p)//��ԭ����δ������ 
	{
		q=p->next;
		p->next=L->next;//�޸�s����ָ���򣬽������ڱ�ͷ 
		L->next=p;
		p=q;
	}
}
void MergeLinkList(LinkList LA,LinkList LB){//�ϲ���������ĵ������������������LA�� 
	Node *pa=LA->next,*pb=LB->next,*r=LA;
	while(pa!=NULL&&pb!=NULL)
	{
		if(pa->data<pb->data)
		{
			r->next=pa;r=pa;pa=pa->next;
		}
		else
		{
			r->next=pb;r=pb;pb=pb->next;
		}
	}
	if(pa)
	{
		r->next=pa;
	}
	else r->next=pb;
	free(LB);
}

void deleteList(LinkList L){//ɾ������ 
	free(L);
}

#endif
