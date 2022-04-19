#ifndef __QUEUE_H__
#define __QUEUE_H__
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20

typedef struct{
	QElemType elem[MAXSIZE];
	int front;
	int rear;//rearָ���βԪ�ص���һλ�ã���ʱ��ӡ�����Ӧ����ӡ��������ƶ�ָ�� 
}SeqQueue;//ѭ������ 

void InitQueue(SeqQueue *Q){//��ʼ��һ���յ�ѭ������ 
	Q->front=Q->rear=0;
}

int EnterQueue(SeqQueue *Q,QElemType e){//��� 
	if((Q->rear+1)%MAXSIZE==Q->front)//ѭ�����е����� 
	return FALSE;
	Q->elem[Q->rear]=e;
	Q->rear=(Q->rear+1)%MAXSIZE;
	return TRUE;
}

int DeleteQueue(SeqQueue *Q,QElemType *e){//����
	if(Q->front==Q->rear) return FALSE;//�п�
	*e=Q->elem[Q->front];//��e���س��ӵ�Ԫ�� 
	Q->front=(Q->front+1)%MAXSIZE;
	return TRUE; 
}

int QueueLength(SeqQueue *Q){//�����Ԫ�ظ���
	return (Q->rear-Q->front+MAXSIZE)%MAXSIZE; 
}

int IsEmpty(SeqQueue *Q){//ѭ�������п�
	if(Q->front==Q->rear) return TRUE;
	else return FALSE; 
}

int IsFull(SeqQueue *Q){//ѭ����������
	if((Q->rear+1)%MAXSIZE==Q->front) return TRUE;
	else return FALSE; 
}

int GetFront(SeqQueue *Q,QElemType *e){//��ȡ��ͷԪ��
	if(Q->front==Q->rear) return FALSE;
	*e=Q->elem[Q->front];
	 return TRUE;
}

int GetRear(SeqQueue *Q,QElemType *e){//��ȡ��βԪ��
	 if(Q->front==Q->rear) return FALSE;
	 *e=Q->elem[Q->rear];
	 return TRUE;
}

void YangHuiTriangle(int N){//��ӡ������� 
	int i=0,n=0;
	QElemType t,x;
	SeqQueue Q;
	InitQueue(&Q);
	EnterQueue(&Q,1);//��һ��Ԫ����� 
	for(n=2;n<=N;n++){//�õ�n������n+1��Ԫ�ز���� 
		EnterQueue(&Q,1);
		for(i=1;i<=n-2;i++){
			DeleteQueue(&Q,&t);
			printf("%d ",t);
			GetFront(&Q,&x);
			t=t+x;
			EnterQueue(&Q,t);
		}
		DeleteQueue(&Q,&x);
		printf("%d\n",x);
		EnterQueue(&Q,1);
	}
}
#endif
