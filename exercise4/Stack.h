#ifndef __STACK_H__
#define __STACK_H__
#include <stdio.h>
#define Stack_Size 10
#define FALSE 0
#define TRUE 1

typedef struct{//顺序栈结构 
	SElemType elem[Stack_Size];
	int top;
}SeqStack;

void InitStack(SeqStack *s){//顺序栈的初始化 
	s->top=-1;
}

int IsEmpty(SeqStack *s){//顺序栈的判空 
	if(s->top==-1) return 1;
	else return 0;
}

int IsFull(SeqStack *s){//顺序栈的判满 
	if(s->top==Stack_Size-1) return 1;
	else return 0;
}

int Push(SeqStack *s,SElemType *e){//入栈 
	if(s->top==Stack_Size-1) return FALSE;
	s->top++;
	s->elem[s->top]=*e;
	return TRUE; 
}

int Pop(SeqStack *s,SElemType *e){//出栈 
	if(s->top==-1) return FALSE;
	*e=s->elem[s->top];
	s->top--;
	return TRUE;
}

 int GetTop(SeqStack *s,SElemType *e){//读取栈顶元素 
 	if(s->top==-1) return FALSE;
 	*e=s->elem[s->top];
 	return TRUE;
 }
 
int BracketMatch(char *str){
 	int i=0;
 	char a='1';
 	SeqStack stack1,*s=&stack1;
 	SElemType *ch=0,*temp=&a;//此处指针指向待完善 
 	InitStack(s);
 	do{
		ch=&str[i];
		if(*ch=='{'||*ch=='('||*ch=='[')//如果是左括号压入栈内 
		{
			Push(s,ch);
		}
		else if(*ch=='}'||*ch==')'||*ch==']')//如果是右括号立刻与栈顶元素进行匹配
		{
			GetTop(s,temp);
			switch(*ch)
			{
				case '}': if(*temp=='{'){
						  Pop(s,temp);//匹配成功，出栈，break跳出switch语句，继续下一轮循环 
						  break;
						  }
						  else printf("这不是一个完整的括号表达式\n");
						  return FALSE;//匹配失败，则括号表达式不能完全匹配，直接return FALSE
				case ')': if(*temp=='('){
						  Pop(s,temp);
						  break;
						  }
						  else printf("这不是一个完整的括号表达式\n");
						  return FALSE;
				case ']': if(*temp=='['){
						  Pop(s,temp);
						  break;
						  }
						  else printf("这不是一个完整的括号表达式\n");
						  return FALSE;
			}
		} 
		i++;
	}while(str[i]!='\0');
	if(IsEmpty(s)){
		printf("这是一个完整的括号表达式\n");
	}
	else printf("这不是一个完整的括号表达式\n");
	return 0;
 }
 
#endif
