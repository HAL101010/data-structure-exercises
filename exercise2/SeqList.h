#ifndef __SEQLIST_H__
#define __SEQLIST_H__
#define MAXSIZE 100
typedef int ElemType;
typedef struct{
	ElemType elem[MAXSIZE];
	//ElemType *elem;
	int last;
}SeqList;

void InitList(SeqList *L)//��L��ʼ��Ϊ�ձ� 
{
	L->last=-1;
}

int ListLength(SeqList L)//���LΪ�ձ��򷵻�0�����򷵻ر���Ԫ�صĸ��� 
{
	return L.last+1;
}

void SetList(SeqList *L)//˳���ĸ�ֵ,�Ի��з���������־(�˴�Ĭ������Ϊ��������)
{
	int j=0;
	char t=1;
	printf("������˳�����Ԫ�ص�ֵ��\n");
	do
	{
		scanf("%d",&j);
		L->elem[L->last+1]=(ElemType)j;
		L->last++;
	}while(getchar()!='\n'&&L->last<MAXSIZE);//�������н��� 
	if(L->last==MAXSIZE)
	{
		printf("������\n");
	}
} 

void PutList(SeqList L)//˳��������и�Ԫ�ص�ֵ(�˴�Ĭ��Ϊ��������) 
{
	int i;
	printf("����Ԫ��Ϊ��\n");
	for(i=0;i<=L.last;i++)
	{
		printf("%d\t",L.elem[i]);
	}
	printf("\n");
}

ElemType GetData(SeqList L,int i)//˳�����Ų��ң��������� 
{
	if(i>L.last+1||i<1)
	{
		printf("Ԫ��λ��Խ�磡\n");
		return 0;
	}
	else return L.elem[i-1];
}

int Locate(SeqList L,ElemType e)//˳������ݲ��ң�����˳��ֵ 
{
	int i=0;
	while(i<=L.last&&L.elem[i]!=e) i++;
	if(i<=L.last)
	return i+1;
	else printf("δ�ҵ���Ԫ��\n");
	return 0;
}

int InsList(SeqList *L,int i,ElemType e)//��L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ���+1
{
	int k;
	if(i<1||i>L->last+2)
	{
		printf("����λ��iֵ���Ϸ�\n");
		return 0; 
	}
	if(L->last>=MAXSIZE-1)
	{
		printf("���������޷�����\n");
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

int DelList(SeqList *L,int i,ElemType *e)//ɾ��L�ĵ�i��Ԫ�أ�����e������ֵ��L�ĳ���-1 
{
	if(i<1||i>L->last+1)
	{
		printf("ɾ��λ�ò��Ϸ���\n");
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

void ReverseList(SeqList *L)//��˳������� 
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

void InsSort(SeqList *L)//ֱ�Ӳ�������
{
	int i=0,j=0;
	for(i=1;i<=L->last;i++)
	{
		ElemType temp=L->elem[i];//temp����Ϊ�����ڸڣ�����Ҫ������� 
		j=i-1;//j��Ҫ����Ԫ�ص�ǰһ��Ԫ�ؿ�ʼ 
		while(temp<L->elem[j])//�����Ԫ�ر�ǰһ��Ԫ��С����ǰһ��Ԫ�غ���һ��λ�� ,j����ǰ��һ��λ�� 
		{
			L->elem[j+1]=L->elem[j];
			j--;
		}//ѭ����ֹʱҪ����Ԫ�ر�jָ���Ԫ�ش󣬸�Ԫ�ط���j��һ��Ԫ�ص�λ�� 
		L->elem[j+1]=temp;
	}	
}

void BubbleSort(SeqList *L)//ð������
{
	int i=0,j=0,change=1;
	ElemType temp;
	for(change=1,i=1;i<=L->last&&change==1;i++)//���һ������û�з��������������ǰ���Ԫ�ض�������ģ�����Ҫ������ 
	{
		change=0;
		for(j=0;j<=L->last-i;j++)
		{
			if(L->elem[j]>L->elem[j+1])//����ѭ�����Ƚ��������Ĵ�С�󽻻�λ�� 
			{
				temp=L->elem[j];
				L->elem[j]=L->elem[j+1];
				L->elem[j+1]=temp;
				change=1;//����������change��1 
			}
		}
	}
} 

void SelectSort(SeqList *L)//��ѡ������
{
	int i=0,j=0,k=0; 
	ElemType min;
	for(i=0;i<L->last;i++)//�����������Ա�,iΪ��������СԪ�ص��±�ֵ,kΪδ����Ԫ�����ҵ�����СԪ���±�ֵ 
	{
		min=L->elem[i];
		for(k=i,j=i;j<=L->last;j++)
		{
			if(L->elem[j]<min)
			{
				min=L->elem[j];
				k=j;//�ڲ�ѭ�����һ���Ժ�min�м�Ϊδ����Ԫ������СԪ�ص��±�ֵ 
			}
		}
		if(k!=i)//���k��i����Ⱦͽ�������Ԫ�ص�ֵ 
		{
			min=L->elem[k];
			L->elem[k]=L->elem[i];
			L->elem[i]=min;
		}
	}
}	

void mergeList(SeqList *LA,SeqList *LB,SeqList *LC)//���Ա�ĺϲ����� (�����������Ա�)
{
	int i=0,j=0,k=0;
	while(i<=LA->last&&j<=LB->last)// ˭С�ȼ�˭ 
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
	while(i<=LA->last)//����LA��ʣ��Ԫ��ʱ����LA���µ�Ԫ�ؼӵ�LC�� 
	{
		LC->elem[k]=LA->elem[i];
		i++;k++;
	}
	while(j<=LB->last)//����LB��ʣ��Ԫ��ʱ����LB���µ�Ԫ�ؼӵ�LC�� 
	{
		LC->elem[k]=LB->elem[j];
		j++;k++;
	}
	LC->last=LA->last+LB->last+1;//��LC�ĳ��� 
}


#endif
