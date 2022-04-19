#include <iostream>
#include <stdio.h>
#include <string.h>
typedef int QElemType;
#include "Queue.h"
typedef char SElemType;
#include "Stack.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char** argv) {
	///////////////////////////////////////////////////////匹配括号表达式	
	char str[100];
	printf("请输入括号表达式：\n");
	gets(str);	
	BracketMatch(str);
///////////////////////////////////////////////////////打印杨辉三角 
	printf("请输入要打印的杨辉三角的行数\n");
	int N=0;
	scanf("%d",&N); 
	YangHuiTriangle(N+1);
	return 0;
}
