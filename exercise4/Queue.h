#ifndef __QUEUE_H__
#define __QUEUE_H__
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20

typedef struct{
	QElemType elem[MAXSIZE];
	int front;
	int rear;//rear指向队尾元素的下一位置，此时入队、出队应先入队、出队再移动指针 
}SeqQueue;//循环队列 

void InitQueue(SeqQueue *Q){//初始化一个空的循环队列 
	Q->front=Q->rear=0;
}

int EnterQueue(SeqQueue *Q,QElemType e){//入队 
	if((Q->rear+1)%MAXSIZE==Q->front)//循环队列的判满 
	return FALSE;
	Q->elem[Q->rear]=e;
	Q->rear=(Q->rear+1)%MAXSIZE;
	return TRUE;
}

int DeleteQueue(SeqQueue *Q,QElemType *e){//出队
	if(Q->front==Q->rear) return FALSE;//判空
	*e=Q->elem[Q->front];//用e带回出队的元素 
	Q->front=(Q->front+1)%MAXSIZE;
	return TRUE; 
}

int QueueLength(SeqQueue *Q){//求队列元素个数
	return (Q->rear-Q->front+MAXSIZE)%MAXSIZE; 
}

int IsEmpty(SeqQueue *Q){//循环队列判空
	if(Q->front==Q->rear) return TRUE;
	else return FALSE; 
}

int IsFull(SeqQueue *Q){//循环队列判满
	if((Q->rear+1)%MAXSIZE==Q->front) return TRUE;
	else return FALSE; 
}

int GetFront(SeqQueue *Q,QElemType *e){//读取队头元素
	if(Q->front==Q->rear) return FALSE;
	*e=Q->elem[Q->front];
	 return TRUE;
}

int GetRear(SeqQueue *Q,QElemType *e){//读取队尾元素
	 if(Q->front==Q->rear) return FALSE;
	 *e=Q->elem[Q->rear];
	 return TRUE;
}

void YangHuiTriangle(int N){//打印杨辉三角 
	int i=0,n=0;
	QElemType t,x;
	SeqQueue Q;
	InitQueue(&Q);
	EnterQueue(&Q,1);//第一行元素入队 
	for(n=2;n<=N;n++){//用第n行生成n+1行元素并入队 
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
