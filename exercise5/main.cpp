#include <iostream>
#include <stdio.h>
#include "SString.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int location,pos,temp1=1,temp2=1;
	char ch;
	SString str1,str2;//��������˳�򴮲����г�ʼ�� 
	StrClean(&str1);
	StrClean(&str2);
	
	printf("����������\n");
	GetSString(&str1);
	
	printf("������ģʽ��\n");//ģʽ������Ӧ�������� 
	while(temp1){
		temp1=0;
		GetSString(&str2);
		if(str2.len>str1.len){
			printf("ģʽ�����Ϸ�������������ģʽ����\n");
			temp1=1;
		}
	}
	
	printf("�����뿪ʼƥ��λ��\n");//ƥ��λ��Ӧ�������� 
	while(temp2){
		temp2=0;
		scanf("%d",&pos);
		if(pos<=0||pos>str1.len-str2.len+1){
			printf("��ʼƥ��λ�ò��Ϸ�������������\n");
			temp2=1;
		}
	}
	
	printf("��ģʽƥ������\n");
	location=Index(&str1,&str2,pos);
	if(location==0) printf("ƥ��ʧ��\n");
	else printf("ƥ��ɹ����Ӵ��������е���ʼλ��Ϊ%d\n",location);

	printf("KMPģʽƥ������\n");
	location=Index_KMP(&str1,&str2,pos);
	if(location==0) printf("ƥ��ʧ��\n");
	else printf("ƥ��ɹ����Ӵ��������е���ʼλ��Ϊ%d\n",location);
	
	return 0;
}
