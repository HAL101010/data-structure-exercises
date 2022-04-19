#ifndef __STACK_H__
#define __STACK_H__
#include <stdio.h>
#define Stack_Size 10
#define FALSE 0
#define TRUE 1

typedef struct{//˳��ջ�ṹ 
	SElemType elem[Stack_Size];
	int top;
}SeqStack;

void InitStack(SeqStack *s){//˳��ջ�ĳ�ʼ�� 
	s->top=-1;
}

int IsEmpty(SeqStack *s){//˳��ջ���п� 
	if(s->top==-1) return 1;
	else return 0;
}

int IsFull(SeqStack *s){//˳��ջ������ 
	if(s->top==Stack_Size-1) return 1;
	else return 0;
}

int Push(SeqStack *s,SElemType *e){//��ջ 
	if(s->top==Stack_Size-1) return FALSE;
	s->top++;
	s->elem[s->top]=*e;
	return TRUE; 
}

int Pop(SeqStack *s,SElemType *e){//��ջ 
	if(s->top==-1) return FALSE;
	*e=s->elem[s->top];
	s->top--;
	return TRUE;
}

 int GetTop(SeqStack *s,SElemType *e){//��ȡջ��Ԫ�� 
 	if(s->top==-1) return FALSE;
 	*e=s->elem[s->top];
 	return TRUE;
 }
 
int BracketMatch(char *str){
 	int i=0;
 	char a='1';
 	SeqStack stack1,*s=&stack1;
 	SElemType *ch=0,*temp=&a;//�˴�ָ��ָ������� 
 	InitStack(s);
 	do{
		ch=&str[i];
		if(*ch=='{'||*ch=='('||*ch=='[')//�����������ѹ��ջ�� 
		{
			Push(s,ch);
		}
		else if(*ch=='}'||*ch==')'||*ch==']')//�����������������ջ��Ԫ�ؽ���ƥ��
		{
			GetTop(s,temp);
			switch(*ch)
			{
				case '}': if(*temp=='{'){
						  Pop(s,temp);//ƥ��ɹ�����ջ��break����switch��䣬������һ��ѭ�� 
						  break;
						  }
						  else printf("�ⲻ��һ�����������ű��ʽ\n");
						  return FALSE;//ƥ��ʧ�ܣ������ű��ʽ������ȫƥ�䣬ֱ��return FALSE
				case ')': if(*temp=='('){
						  Pop(s,temp);
						  break;
						  }
						  else printf("�ⲻ��һ�����������ű��ʽ\n");
						  return FALSE;
				case ']': if(*temp=='['){
						  Pop(s,temp);
						  break;
						  }
						  else printf("�ⲻ��һ�����������ű��ʽ\n");
						  return FALSE;
			}
		} 
		i++;
	}while(str[i]!='\0');
	if(IsEmpty(s)){
		printf("����һ�����������ű��ʽ\n");
	}
	else printf("�ⲻ��һ�����������ű��ʽ\n");
	return 0;
 }
 
#endif
