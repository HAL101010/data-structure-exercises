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

void InitList(LinkList *L){//初始化一个带头结点的空链表
	*L=(LinkList)malloc(sizeof(Node));
	(*L)->next=NULL;
}

LinkList CreatFromHead(){//头插法建表,返回头指针 
	LinkList L=(LinkList)malloc(sizeof(Node));
	L->next=NULL;
	Node *s=0;//指向单链表的中结点的指针(指针域) 
	ElemType c;//数据域 
	printf("请输入链表元素：\n");
	do
	{
		scanf("%d",&c);//此处接收的数据根据定义类型灵活选择 
		s=(Node*)malloc(sizeof(Node));//待修改，当分配内存失败时应该报错 
		s->data=(ElemType)c;
		s->next=L->next;
		L->next=s;
	}while(getchar()!='\n');//循环条件 
	return L;
}

LinkList CreatFromTail(){//尾插法建表，返回头指针 
	LinkList L=(LinkList)malloc(sizeof(Node));
	Node *r=0,*s=0;//r指向链表的结尾 
	ElemType c;//数据域 
	L->next=NULL;
	r=L;
	printf("请输入链表元素：\n");
	do
	{
		scanf("%d",&c);
		s=(Node*)malloc(sizeof(Node));
		s->data=(ElemType)c;
		r->next=s;
		r=s;
	}while(getchar()!='\n');
	r->next=NULL;//尾插法建表注意最后要修改表尾 
	return L;
}

int ListLength(LinkList L){//求链表的长度，返回链表的长度 
	Node *p=L->next;//p指向首元节点 
	int count=0;
	while(p!=NULL)
	{
		count++;
		p=p->next;
	}
	return count;
}

Node* GetData1(LinkList L,ElemType e){//按元素查找，返回指向该元素结点的指针 
	Node *p=L->next;
	while(p)
	{
		if(p->data==e)
		{
			return p;
		}
		else p=p->next;
	}
	printf("未找到该元素！\n");
	return 0;
}

LinkList GetData2(LinkList L,int i){//按元素位置查找，返回指向该元素的指针
	Node *p=L->next;//从首元节点开始遍历 
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
		printf("元素位置越界！\n");
		return 0;
	}
}

int InsList(LinkList L,int i,ElemType e){//在L中第i个位置之前插入新的数据元素e(单链表插入新元素需修改两个指针域)
	Node *pre=L,*p=0;//pre保存p前一个元素结点 
	for(int j=1;j<i;j++)
	{
		pre=pre->next;
	}
	if(i<=0||pre==NULL)
	{
		printf("插入位置不合法！\n");//和删除操作不同，即使pre后面一位没有元素也可以进行插入 
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

int DelList(LinkList L,int i,ElemType *e){//删除L的第i个元素，并用e返回其值
	Node *pre=L,*p=0;//p用于释放待删除节点，pre用于修改被删除元素的前一个节点，pre从头结点开始遍历 
	for(int j=1;j<i;j++)
	{
		pre=pre->next;
	}
	if(pre->next==NULL)
	{
		printf("删除位置不合法！\n");//待删除元素是pre后的一个元素，所以要判断pre->next是否存在 
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

void PutList(LinkList L){//顺序输出链表中元素 
	Node *p=L->next;
	printf("链表中元素：\n");
	while(p)
	{
		printf("%d\t",p->data);
		p=p->next;
	}
	printf("\n");
}

void SelectSort(LinkList L){//单链表的简单选择排序
	Node *p=L->next,*s=p,*t=p,*q=p;//p为遍历整个链表的指针(也是指向要排序位置的指针)，q为内层循环指针，t为指向最小元素的指针 
	ElemType temp,min;
	while(p->next!=NULL)//外层循环遍历整个链表 
	{
		min=p->data;
		t=p;
		while(q!=NULL)//内层循环找到最小的数 
		{
			if(q->data<min)
			{
				min=q->data;
				t=q;//t指向最小元素的位置 
			}
			q=q->next;
		}
		if(p!=t)//如果两处指针指向不同的地方则交换两处指针数据域的值 
		{
			temp=p->data;
			p->data=t->data;
			t->data=temp;
		}
		p=p->next;
		q=p;
	}
}	

LinkList ReverseList(LinkList L){//实现带头结点的链表的逆置(迭代反转法),返回头指针 
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

void ReverseList2(LinkList L){//带头结点的链表的逆置(就地逆置) 
	Node *p=L->next,*q=0;//s为待处理结点，q为待处理结点的下一结点 
	L->next=NULL;//逆置单链表处理为空表 
	while(p)//当原链表未处理完 
	{
		q=p->next;
		p->next=L->next;//修改s结点的指针域，将其置于表头 
		L->next=p;
		p=q;
	}
}
void MergeLinkList(LinkList LA,LinkList LB){//合并两个有序的单链表，结果保存在链表LA中 
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

void deleteList(LinkList L){//删除链表 
	free(L);
}

#endif
