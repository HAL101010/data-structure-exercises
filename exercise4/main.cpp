#include <iostream>
#include <stdio.h>
#include <string.h>
typedef int QElemType;
#include "Queue.h"
typedef char SElemType;
#include "Stack.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char** argv) {
	///////////////////////////////////////////////////////ƥ�����ű��ʽ	
	char str[100];
	printf("���������ű��ʽ��\n");
	gets(str);	
	BracketMatch(str);
///////////////////////////////////////////////////////��ӡ������� 
	printf("������Ҫ��ӡ��������ǵ�����\n");
	int N=0;
	scanf("%d",&N); 
	YangHuiTriangle(N+1);
	return 0;
}
