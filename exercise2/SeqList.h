#ifndef __SEQLIST_H__
#define __SEQLIST_H__
#define MAXSIZE 100
typedef int ElemType;
typedef struct{
	ElemType elem[MAXSIZE];
	//ElemType *elem;
	int last;
}SeqList;

void InitList(SeqList *L)//将L初始化为空表 
{
	L->last=-1;
}

int ListLength(SeqList L)//如果L为空表则返回0，否则返回表中元素的个数 
{
	return L.last+1;
}

void SetList(SeqList *L)//顺序表的赋值,以换行符做结束标志(此处默认输入为整型数据)
{
	int j=0;
	char t=1;
	printf("请输入顺序表中元素的值：\n");
	do
	{
		scanf("%d",&j);
		L->elem[L->last+1]=(ElemType)j;
		L->last++;
	}while(getchar()!='\n'&&L->last<MAXSIZE);//读到换行结束 
	if(L->last==MAXSIZE)
	{
		printf("表已满\n");
	}
} 

void PutList(SeqList L)//顺序输出表中各元素的值(此处默认为整型数据) 
{
	int i;
	printf("表中元素为：\n");
	for(i=0;i<=L.last;i++)
	{
		printf("%d\t",L.elem[i]);
	}
	printf("\n");
}

ElemType GetData(SeqList L,int i)//顺序表按序号查找，返回内容 
{
	if(i>L.last+1||i<1)
	{
		printf("元素位置越界！\n");
		return 0;
	}
	else return L.elem[i-1];
}

int Locate(SeqList L,ElemType e)//顺序表按内容查找，返回顺序值 
{
	int i=0;
	while(i<=L.last&&L.elem[i]!=e) i++;
	if(i<=L.last)
	return i+1;
	else printf("未找到该元素\n");
	return 0;
}

int InsList(SeqList *L,int i,ElemType e)//在L中第i个位置之前插入新的数据元素e，L的长度+1
{
	int k;
	if(i<1||i>L->last+2)
	{
		printf("插入位置i值不合法\n");
		return 0; 
	}
	if(L->last>=MAXSIZE-1)
	{
		printf("表已满，无法插入\n");
		return 0;
	}
	for(k=L->last;k>=i-1;k--)
	{
		L->elem[k+1]=L->elem[k];
	}
	L->elem[i-1]=e;
	L->last++;
	return 1;
}

int DelList(SeqList *L,int i,ElemType *e)//删除L的第i个元素，并用e返回其值，L的长度-1 
{
	if(i<1||i>L->last+1)
	{
		printf("删除位置不合法！\n");
		return 0;
	}
	*e=L->elem[i-1];
	for(;i<=L->last;i++)
	{
		L->elem[i-1]=L->elem[i];
	}
	L->last--;
	return 1;
}

void ReverseList(SeqList *L)//将顺序表逆置 
{
	int i=0,j=L->last;
	ElemType t;
	for(;i<=j;i++,j--)
	{
		t=L->elem[i];
		L->elem[i]=L->elem[j];
		L->elem[j]=t;
	}
}

void InsSort(SeqList *L)//直接插入排序
{
	int i=0,j=0;
	for(i=1;i<=L->last;i++)
	{
		ElemType temp=L->elem[i];//temp设置为监视哨岗，保存要排序的数 
		j=i-1;//j从要排序元素的前一个元素开始 
		while(temp<L->elem[j])//如果该元素比前一个元素小，则前一个元素后移一个位置 ,j再向前移一个位置 
		{
			L->elem[j+1]=L->elem[j];
			j--;
		}//循环终止时要排序元素比j指向的元素大，该元素放在j后一个元素的位置 
		L->elem[j+1]=temp;
	}	
}

void BubbleSort(SeqList *L)//冒泡排序
{
	int i=0,j=0,change=1;
	ElemType temp;
	for(change=1,i=1;i<=L->last&&change==1;i++)//如果一趟排序没有发生交换，则表明前面的元素都是有序的，不需要再排序 
	{
		change=0;
		for(j=0;j<=L->last-i;j++)
		{
			if(L->elem[j]>L->elem[j+1])//两层循环，比较两个数的大小后交换位置 
			{
				temp=L->elem[j];
				L->elem[j]=L->elem[j+1];
				L->elem[j+1]=temp;
				change=1;//发生交换则change置1 
			}
		}
	}
} 

void SelectSort(SeqList *L)//简单选择排序
{
	int i=0,j=0,k=0; 
	ElemType min;
	for(i=0;i<L->last;i++)//遍历整个线性表,i为待放入最小元素的下标值,k为未排序元素中找到的最小元素下标值 
	{
		min=L->elem[i];
		for(k=i,j=i;j<=L->last;j++)
		{
			if(L->elem[j]<min)
			{
				min=L->elem[j];
				k=j;//内层循环完成一次以后min中即为未排序元素中最小元素的下标值 
			}
		}
		if(k!=i)//如果k和i不相等就交换两处元素的值 
		{
			min=L->elem[k];
			L->elem[k]=L->elem[i];
			L->elem[i]=min;
		}
	}
}	

void mergeList(SeqList *LA,SeqList *LB,SeqList *LC)//线性表的合并运算 (两个有序线性表)
{
	int i=0,j=0,k=0;
	while(i<=LA->last&&j<=LB->last)// 谁小先加谁 
	{
		if(LA->elem[i]<=LB->elem[j])
		{
			LC->elem[k]=LA->elem[i];
			i++;k++;
		}
		else
		{
			LC->elem[k]=LB->elem[j];
			j++;k++;
		}
	}
	while(i<=LA->last)//当表LA有剩余元素时，将LA余下的元素加到LC中 
	{
		LC->elem[k]=LA->elem[i];
		i++;k++;
	}
	while(j<=LB->last)//当表LB有剩余元素时，将LB余下的元素加到LC中 
	{
		LC->elem[k]=LB->elem[j];
		j++;k++;
	}
	LC->last=LA->last+LB->last+1;//表LC的长度 
}


#endif
