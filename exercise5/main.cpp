#include <iostream>
#include <stdio.h>
#include "SString.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int location,pos,temp1=1,temp2=1;
	char ch;
	SString str1,str2;//创建两个顺序串并进行初始化 
	StrClean(&str1);
	StrClean(&str2);
	
	printf("请输入主串\n");
	GetSString(&str1);
	
	printf("请输入模式串\n");//模式串串长应加以限制 
	while(temp1){
		temp1=0;
		GetSString(&str2);
		if(str2.len>str1.len){
			printf("模式串不合法！请重新输入模式串：\n");
			temp1=1;
		}
	}
	
	printf("请输入开始匹配位置\n");//匹配位置应加以限制 
	while(temp2){
		temp2=0;
		scanf("%d",&pos);
		if(pos<=0||pos>str1.len-str2.len+1){
			printf("开始匹配位置不合法，请重新输入\n");
			temp2=1;
		}
	}
	
	printf("简单模式匹配结果：\n");
	location=Index(&str1,&str2,pos);
	if(location==0) printf("匹配失败\n");
	else printf("匹配成功，子串在主串中的起始位置为%d\n",location);

	printf("KMP模式匹配结果：\n");
	location=Index_KMP(&str1,&str2,pos);
	if(location==0) printf("匹配失败\n");
	else printf("匹配成功，子串在主串中的起始位置为%d\n",location);
	
	return 0;
}
